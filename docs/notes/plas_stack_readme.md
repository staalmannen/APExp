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
