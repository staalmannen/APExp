
# The PLAS stack: Plan 9, Listener, SQLite, PHP

A web stack with no dynamic linker, no package manager and no database
server — PHP and SQLite on 9front, served by Plan 9's own listener.

**STATUS: PART MEASURED, PART NOT, AND ONE PART IS KNOWN BROKEN.** The
architecture below is attractive and most of it is reachable. It does
not work today, and this file says which pieces are which, because a
guide that reads as instructions when it is a plan wastes the reader's
afternoon. Every claim marked **measured** was run; every one marked
**unmeasured** is a prediction with the command that would settle it.

| piece | state |
|---|---|
| PHP 8.5.12 CLI binary | **measured**: builds, installs, runs, `php -v` exits 0 |
| SQLite 3.53.4 as `libsqlite.a` | **measured**: builds, in the default build |
| PHP *bound to* SQLite (PDO / sqlite3) | **absent**: no extension is compiled in |
| DOM, SimpleXML, ZIP | **absent**: same reason |
| POSIX file locking under SQLite | **BROKEN**: `fcntl` answers `EINVAL` |
| rc-httpd / listener wiring | **unmeasured** |
| per-request namespace isolation | **overstated** — see §4 |

---

## 1. What exists today

`php -v` on 9front:

```
PHP 8.5.12 (cli) (built: Nov  5 2026 16:46:25) (NTS)
Copyright (c) The PHP Group
Zend Engine v4.5.12, Copyright (c) Zend Technologies
```

That is a real interpreter: 515 translation units, the Zend engine,
opcache, pcre2, the standard library, date, hash, json, lexbor,
random, reflection, spl and uri. It is built `--disable-all`, which in
PHP 8.5 still leaves eleven extensions because they are
unconditional.

**What `--disable-all` leaves out is everything this stack needs.**
Running the Phoronix Test Suite under it says so in its own words:

```
MISSING DOM        REQUIRED - The Document Object Model is required for XML operations.
MISSING ZIP        REQUIRED - ZIP support is required for file (de)compression.
MISSING SimpleXML  REQUIRED - SimpleXML is required for XML operations.
```

So *the binary is finished and the build is not*. There is no `PDO`,
no `sqlite3` driver, and `new PDO('sqlite:...')` in a script would
throw before touching a database.

### The good news: the libraries are already here

`sys/src/ape/lib` already carries ports of everything the missing
extensions link against, which is the hard half:

| extension | library it needs | in this tree? |
|---|---|---|
| `sqlite3`, `pdo_sqlite` | SQLite 3.53.4 | **yes** — `lib/sqlite`, and a `cmd/sqlite` shell |
| `dom`, `simplexml`, `xml` | libxml2 | **yes** — `lib/xml2` |
| `zip` | libzip + zlib | **yes** — `lib/zip`, `lib/z` |
| `curl` | libcurl | **yes** — `lib/curl` |
| `openssl` | LibreSSL | **yes** — `lib/libressl` |
| `mbstring` | oniguruma | **yes** — `lib/onig` |

Adding one is three edits to `sys/src/ape/cmd/php/mkfile` and its
`cfg/`: the extension's objects into `OFILES`, its `phpext_*_ptr` into
`internal_functions_cli.c`, and `HAVE_*` into `cfg/main/php_config.h`.
*It has not been done, so none of it is measured.*

---

## 2. The database layer has a blocker underneath it

***THE DOCUMENT THIS REPLACES CLAIMED THE OPPOSITE OF THE TRUTH HERE,
AND IT IS THE CLAIM MOST WORTH GETTING RIGHT***, because believing it
is how someone ends up with a corrupted database rather than an error
message.

The claim was: *"SQLite is traditionally bound to local contexts due to
POSIX network file-locking vulnerabilities. Plan 9's native 9P protocol
guarantees coherent file locking and atomic transactions, allowing
multiple terminal nodes to safely write to a single centralized
.sqlite file."*

**9P has no byte-range locking, and APExp has none either.**
`sys/src/ape/lib/ap/fcntl/fcntl.c:180` is:

```c
case F_GETLK:
case F_SETLK:
case F_SETLKW:
        err = EINVAL;
        break;
```

SQLite's default unix VFS takes a SHARED lock to read and escalates
through RESERVED to EXCLUSIVE to write, **all with `fcntl` byte-range
locks**, on every transaction. With `EINVAL` coming back, those calls
fail. Plan 9's own exclusive-use bit (`DMEXCL`) is whole-file and is
not what SQLite asks for.

*Answering `EINVAL` is the right answer* — a lock stub that returned
success would let two writers both believe they held the file, which
is the corruption the original text promised to prevent. But it means
the question is not "can several machines share a database over 9P",
it is **"does a single process get a write transaction at all"**, and
that has never been run.

**The measurement is one command** and needs nothing built:

```rc
sqlite3 /tmp/t.db 'create table t(a); insert into t values(1); select * from t;'
```

- prints `1` → the write path works, and the open question is only
  concurrency.
- an `SQLITE_IOERR`/`disk I/O error` → locking is the blocker, as
  predicted here.

**If it is the blocker, the remedy is known and is a build flag, not
new code.** SQLite ships alternative locking styles — dot-file locking
in particular, which needs only `create`/`remove` and therefore works
over 9P. They are compiled only under `SQLITE_ENABLE_LOCKING_STYLE`,
and the amalgamation in this tree has it at **0**
(`sys/src/external/sqlite/sqlite3.c:169`), while
`lib/sqlite/mkfile` passes no `-DSQLITE_*` at all. Turning it on and
opening with the `unix-dotfile` VFS is the first thing to try; a
Plan 9 VFS under `SQLITE_OS_OTHER` is the thorough version.

---

## 3. What "statically linked" does and does not buy

The stack is statically linked, and **that is not a property of this
port — Plan 9 has no dynamic linker at all.** Every Plan 9 binary is
static. So:

- The "no `glibc`/`musl` disparity, no shared-library conflicts" point
  is true, and it is true of every program on the system.
- The same fact removes capability. **PHP cannot load an extension at
  run time here**: `dl()` and `extension=` in `php.ini` do nothing,
  because `zend_portability.h:200` sets `ZEND_EXTENSIONS_SUPPORT` to 0
  when there is no `dlopen`. Every extension must be compiled in.
- *That same line caused the first crash this port had*: opcache's
  module shutdown destroyed globals whose constructor — reached only
  through the zend-extension startup that is compiled out — had never
  run. See `docs/notes/php.md`.

"Deployment is copying two files" is fair, with the caveat that the
binary is around the size of everything it statically contains.

---

## 4. The namespace claim, narrowed

The original said Plan 9 "forks a localized namespace for incoming
requests", so a compromised application is "isolated within a
transient, severely restricted process space".

**A new namespace is not a restricted one.** `rfork n` gives the child
a *copy* of the parent's namespace — the same files, now privately
mutable. It becomes a sandbox only when the service script then does
the restricting itself: unmounting what it does not need, binding a
subtree over `/`, dropping the network directory. Plan 9 makes that
unusually easy and unusually cheap, and it is a genuine advantage over
a Unix CGI — but it is work the handler script has to do, and none of
the scripts below do it.

The honest version: *Plan 9 gives you the cheapest per-request sandbox
of any system here, and you still have to build it.*

---

## 5. Serving it — unverified, and flagged as such

I have not run a web server on this system, and the 9front specifics
below are the part of this document I am least able to check from the
source tree. Treat §5 as a sketch to verify, not a recipe.

**What I can state:**

- APExp **does not install into `/`**. `mk install` puts binaries in
  `$APEXPROOT/$objtype/bin/ape`, and `apexp-sh` union-mounts them over
  `/bin`. So `cp /sys/src/cmd/php/php ...` is wrong; inside `apexp-sh`
  the binary is just `php`, and outside it the path is
  `<repo>/amd64/bin/ape/php`.
- **This build has no CGI SAPI.** It is configured `--disable-cgi`, so
  there is no `php-cgi` binary. Under the **CLI** SAPI `header()` is a
  no-op: PHP does not emit HTTP headers, so a CGI bridge must print
  the status line and headers itself before running the script — which
  is what the wrapper below does, and why the example scripts in §6
  must not rely on `header()`.
- `aux/listen1 tcp!*!8080 <prog>` hands the program a *raw connection*
  on its standard input and output. It does not set the CGI
  environment, so a program behind `listen1` has to read and parse the
  HTTP request itself. Using rc-httpd instead is what gets you CGI
  variables.
- **Which 9front HTTP server and how it is configured, I did not
  verify.** 9front ships `rc-httpd`, a set of rc scripts, and it is
  configured by editing its own handler-selection script rather than
  by an `httpd.conf`; the `cgi .php ...` line and `ip/httpd -h` in the
  original look like the older Plan 9 `ip/httpd`, and may not apply.
  **Check `/rc/bin/rc-httpd/` on the machine before copying anything
  from here.**

A CLI-SAPI bridge, written to the constraints above:

```rc
#!/bin/rc
# php-cgi -- run a .php file under the CLI SAPI and supply the headers
# ourselves, because the CLI SAPI emits none.

if(! test -f $PATH_TRANSLATED){
	echo 'Status: 404 Not Found'
	echo 'Content-Type: text/plain'
	echo
	echo 'not found'
	exit
}
echo 'Content-Type: text/html; charset=utf-8'
echo
exec php -f $PATH_TRANSLATED
```

*`rc` note*: `echo` with no argument prints the blank line that ends
the headers. Do not write `key=value` arguments anywhere in an rc
script — `=` is a syntax character and is legal only as a leading
assignment.

---

## 6. The example scripts, corrected

### 6.1 Reading Plan 9's synthetic files — the part that already works

This is the genuinely interesting half, it needs **no extension at
all**, and every function in it is in the build we have.

```php
<?php
$out = ['stack' => 'PLAS', 'metrics' => []];

if (is_readable('/dev/sysstat')) {
    $out['metrics']['sysstat'] = preg_split('/\s+/', trim(file_get_contents('/dev/sysstat')));
}

$conns = [];
foreach (glob('/net/tcp/[0-9]*') as $dir) {
    $status = @file_get_contents($dir . '/status');
    if ($status !== false && trim($status) !== '') {
        $conns[] = ['id' => basename($dir), 'status' => trim($status)];
    }
}
$out['tcp'] = ['count' => count($conns), 'connections' => $conns];

echo json_encode($out, JSON_PRETTY_PRINT), "\n";
```

Changed from the original: `glob('/net/tcp/[0-9]*')` rather than `*`,
because `/net/tcp` also holds `clone` and `stats`, which are not
connection directories; `is_readable` rather than `file_exists`,
because a synthetic file can exist and refuse to be read; and no
`header()`, which does nothing under the CLI SAPI.

**Note for anyone extending this**: reading files under `/net` and
`/proc` is the whole appeal of the idea, and it is also where a long
run will meet Plan 9's `warning: process exceeds 100 file descriptors`
— seen already in the Phoronix run. Close what you open.

### 6.2 The SQLite script — does not run yet

The original's `new PDO('sqlite:...')` needs `pdo_sqlite`, which is
not compiled in (§1), and would then need write locking, which is
`EINVAL` (§2). It is kept here as the target rather than as an
instruction, and it is worth attempting only after both of those are
dealt with, in that order.

---

## 7. The shortest path from here

1. `sqlite3 /tmp/t.db 'create table t(a);'` — does the database layer
   work at all? One command, nothing to build. **Do this first**: if it
   fails, everything downstream is blocked on one build flag.
2. Add `ext/sqlite3` and `ext/pdo_sqlite` to `cmd/php/mkfile` against
   the `libsqlite.a` already in the tree.
3. Add `ext/dom`, `ext/simplexml` and `ext/zip` against `libxml2` and
   `libzip` — which is also what makes Phoronix runnable, and would
   make it a real test of the port rather than of its extension list.
4. Only then the server wiring, and verify §5 against the machine
   rather than against this file.

*The order matters: steps 2 and 3 are mkfile work with known inputs,
and step 1 can invalidate step 2 before it is started.*
=======
# The PLAS Stack: Plan 9, Listen/Rc-httpd, Apache-less, SQLite, PHP
A Theoretical Architecture and Setup Guide for Statically Linked Web Environments on 9front.

---

## 1. Architectural Overview
The **PLAS Stack** represents a radical departure from conventional web infrastructure. By coupling the distributed, file-centric philosophy of **9front (Plan 9)** with a completely self-contained, statically compiled **PHP binary containing an embedded SQLite engine**, this stack eliminates the need for dynamic linker dependencies, complex package managers, heavy relational database servers, and multi-layered container runtimes.

```
                  +-----------------------------------------+
                  |         Incoming HTTP Request           |
                  +-----------------------------------------+
                                       |
                                       v
                  +-----------------------------------------+
                  |    Plan 9 Native Listener (rc-httpd)    |
                  +-----------------------------------------+
                                       | (Forks transient namespace)
                                       v
                  +-----------------------------------------+
                  |     Statically Linked PHP Binary        |
                  |     (Embedded SQLite Engine / PDO)       |
                  +-----------------------------------------+
                     /                 |                 \
                    v                  v                  v
         +--------------------+ +-------------+ +--------------------+
         | local .sqlite file | | /net/tcp    | | /dev/sensors       |
         | (Shared via 9P)    | | (Plan 9 IP) | | (Synthetic files)  |
         +--------------------+ +-------------+ +--------------------+
```

### Core Advantages:
1. **The Ultimate Edge "Un-Appliance":** Deployment is reduced to copying exactly two elements: a single executable file and a flat data file. There are no shared library conflicts (`glibc`/`musl` disparities), zero system drift, and a tiny overall storage footprint.
2. **Namespace Sandbox Isolation:** Plan 9 forks a localized namespace for incoming requests. If a PHP application is compromised, the attacker is isolated within a transient, severely restricted process space.
3. **9P-Native Integration:** PHP can interact directly with synthetic filesystems (like `/net`, `/proc`, and `/dev`), enabling the web interface to read hardware metrics or manage networking interfaces naturally via standard file I/O operations.
4. **Distributed 9P DB Locks:** SQLite is traditionally bound to local contexts due to POSIX network file-locking vulnerabilities (e.g., NFS). Plan 9's native **9P protocol** guarantees coherent file locking and atomic transactions, allowing multiple terminal nodes to safely write to a single centralized `.sqlite` file hosted on a file server (`cwfs` or `hjfs`).

---

## 2. Theoretical Configuration & Deployment Guide

This section outlines a theoretical methodology to hook your statically compiled PHP binary into Plan 9's native networking and web hosting layers.

### Phase A: Organizing the Web Directory structure
In Plan 9, the standard web root is traditionally served from `/usr/web`. We will configure a dedicated workspace for our PLAS applications.

```rc
# Create our application and data directories inside the web root
mkdir -p /usr/web/plas/bin
mkdir -p /usr/web/plas/db
mkdir -p /usr/web/plas/htdocs

# Move your static PHP binary into place and make it executable
cp /sys/src/cmd/php/php /usr/web/plas/bin/php
chmod +x /usr/web/plas/bin/php

# Pre-initialize an empty SQLite tracking database file
touch /usr/web/plas/db/app.sqlite
```

### Phase B: Hooking into `rc-httpd` via CGI
Plan 9’s `rc-httpd` maps specific directories or extensions to executable command scripts using a simple configuration style. To pass incoming scripts to your static binary, create a handling gateway wrapper script.

Create the wrapper script at `/usr/web/plas/bin/php-cgi`:

```rc
#!/bin/rc
# php-cgi - A simple bridge passing CGI parameters into our static PHP binary

# Read standard CGI environment variables passed down by rc-httpd
# Plan 9 populates execution environments under /env/

if(! test -f $PATH_TRANSLATED){
    echo 'Status: 404 Not Found'
    echo 'Content-Type: text/html'
    echo ''
    echo '<h1>404 File Not Found</h1>'
    exit
}

# Execute the static binary in CGI mode, parsing the target script
exec /usr/web/plas/bin/php -c /usr/web/plas/bin/php.ini -f $PATH_TRANSLATED
```
Ensure the script is given execution permissions:
```rc
chmod +x /usr/web/plas/bin/php-cgi
```

Next, append a routing rule to your `/sys/lib/httpd.conf` config file so files ending in `.php` are piped into your wrapper:
```
# /sys/lib/httpd.conf addition
# Direct requests targeting .php scripts to our compiled binary bridge
cgi .php /usr/web/plas/bin/php-cgi
```

### Phase C: Initializing the Web Daemon
To fire up the listening service on standard HTTP port 80, invoke the network listener application:
```rc
# Run the native Plan 9 HTTP daemon
ip/httpd -h /usr/web
```

Alternatively, if you want an isolated server instance bound specifically to your directory without messing with the global system configuration, use `aux/listen1`:
```rc
# Instantly stream incoming TCP traffic on port 8080 directly through the CGI wrapper
aux/listen1 -v tcp!*!8080 /usr/web/plas/bin/php-cgi
```

---

## 3. Practical Integration Scripts

### Script 1: Interacting with SQLite database
Save this script as `/usr/web/plas/htdocs/index.php`. It demonstrates how the statically compiled engine processes structural queries internally on a local file resource.

```php
<?php
header('Content-Type: text/html; charset=utf-8');

try {
    // Open connection to the flat file database managed over 9P namespaces
    $db = new PDO('sqlite:/usr/web/plas/db/app.sqlite');
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    // Create a demo table structure if initialization is fresh
    $db->exec("CREATE TABLE IF NOT EXISTS system_logs (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
        event TEXT,
        details TEXT
    )");
    
    // Log the current hit event
    $stmt = $db->prepare("INSERT INTO system_logs (event, details) VALUES (:event, :details)");
    $stmt->execute([
        ':event' => 'HTTP_REQUEST',
        ':details' => 'Client accessed endpoint via user-agent: ' . ($_SERVER['HTTP_USER_AGENT'] ?? 'Unknown')
    ]);
    
    // Query historical entry points
    $results = $db->query("SELECT * FROM system_logs ORDER BY id DESC LIMIT 5");
    
    echo "<h1>PLAS Stack Deployment Status: Operational</h1>";
    echo "<h3>Recent Database Entries (SQLite Embedded Engine):</h3>";
    echo "<ul>";
    foreach ($results as $row) {
        echo "<li>[" . htmlspecialchars($row['timestamp']) . "] " . htmlspecialchars($row['event']) . " - " . htmlspecialchars($row['details']) . "</li>";
    }
    echo "</ul>";
    
} catch (PDOException $e) {
    echo "<h2>Database Error: " . htmlspecialchars($e->getMessage()) . "</h2>";
}
?>
```

### Script 2: Exposing Plan 9 System/Network States as JSON
Because Plan 9 presents kernel states as accessible flat text structures, your static PHP application can read core metrics directly without invoking external shell scripts. Save this example as `/usr/web/plas/htdocs/sysstat.php`.

```php
<?php
header('Content-Type: application/json');

$response = [
    'stack' => 'PLAS (Plan 9, Listen, SQLite, PHP)',
    'status' => 'healthy',
    'system_metrics' => []
];

// 1. Read System Uptime and CPU utilization metrics out of /dev/sysstat
if (file_exists('/dev/sysstat')) {
    $sysstat = file_get_contents('/dev/sysstat');
    $metrics = preg_split('/\s+/', trim($sysstat));
    $response['system_metrics']['raw_sysstat'] = $metrics;
}

// 2. Read Active TCP Network connections straight out of Plan 9 synthetic networking stack
if (file_exists('/net/tcp')) {
    $tcp_connections = [];
    $connections = glob('/net/tcp/*');
    foreach ($connections as $conn) {
        if (is_dir($conn) && file_exists($conn . '/status')) {
            $status = trim(file_get_contents($conn . '/status'));
            if (!empty($status)) {
                $tcp_connections[] = [
                    'connection_id' => basename($conn),
                    'status' => $status
                ];
            }
        }
    }
    $response['network_state'] = [
        'active_tcp_directories' => count($connections),
        'connections' => $tcp_connections
    ];
}

echo json_encode($response, JSON_PRETTY_PRINT);
?>
```

