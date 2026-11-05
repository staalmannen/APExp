# The PLAS stack: Plan 9, Listener, SQLite, PHP

A web stack on 9front with no dynamic linker, no package manager and no
database server: PHP 8.5 and SQLite 3.53 as static binaries, served
either by PHP's own built-in HTTP server or by Plan 9's listener.

This is a guide to trying it, and a description of what the platform
does and does not give you. **Each claim carries its state**: *measured*
means it was run and the output is quoted; *unmeasured* means it follows
from the source but nobody has run it, and the command that would settle
it is given. The distinction is the useful part of this document — a
stack guide that reads as instructions when it is a plan costs you an
afternoon.

| piece | state |
|---|---|
| PHP 8.5.12 CLI, 23 extensions | **measured** — builds, installs, runs |
| SQLite 3.53.4 (`libsqlite.a` + `sqlite3` shell) | **measured** — builds, in the default build |
| `SQLite3` class in PHP | **measured on the build host**, not yet on 9front |
| file-backed SQLite **writes** | **unmeasured, and the one likely blocker** — see §3 |
| `php -S` built-in HTTP server | **unmeasured** — compiled in, see §4 |
| rc-httpd / `listen1` wiring | **unmeasured** — see §4 |
| reading `/net` and `/proc` from PHP | **measured** — see §5 |
| `disk_free_space()` | **known limitation** — see §6 |
| PDO | **not built** — use the `SQLite3` class |

---

## 1. Getting it

APExp does not install into `/`. `mk install` writes into the repository
(`$objtype/bin/ape`, `$objtype/lib/ape`), and `apexp-sh` union-mounts
those over `/bin` at run time. So everything below is run **inside
`apexp-sh`**, where the binaries are plain names on `$PATH`.

```rc
cd /path/to/APExp
mk install
./apexp-sh
```

Then:

```
php -v
```

```
PHP 8.5.12 (cli) (built: Nov  5 2026 16:46:25) (NTS)
Copyright (c) The PHP Group
Zend Engine v4.5.12, Copyright (c) Zend Technologies
```

Outside `apexp-sh` the binary is `<repo>/amd64/bin/ape/php`.

## 2. What is in the build

Twenty-three extensions are registered (`php -m` also shows `Core`, and
prints opcache as `Zend OPcache` under a separate heading):

```
date pcre hash json lexbor opcache random reflection standard spl uri
libxml dom simplexml zlib
posix pcntl bz2 readline openssl curl sqlite3 zip
```

The first line is what PHP 8.5 builds unconditionally — `--disable-all`
does not mean a small build. The second and third are APExp's, and they
link against libraries this tree already builds: `lib/xml2`, `lib/z`,
`lib/sqlite`, `lib/libressl`, `lib/curl`, `lib/zip`, `lib/bz2`,
`lib/readline`. Each is pulled in by `#pragma lib` in its own header,
the Plan 9 way, so `cmd/php/mkfile` names no libraries at all.

**Everything must be compiled in.** Plan 9 has no `dlopen`, so
`extension=` in `php.ini` and `dl()` do nothing:
`zend_portability.h:200` sets `ZEND_EXTENSIONS_SUPPORT` to 0 when
dynamic loading is absent. Adding an extension is three edits —
objects into `OFILES`, the `phpext_*_ptr` into
`internal_functions_cli.c`, the `HAVE_*` into `cfg/main/php_config.h` —
and a rebuild.

**Not built**: PDO and `pdo_sqlite` (use the `SQLite3` class instead),
mbstring, GD (there is no libgd in the tree), and `ext/sockets` (which
needs `struct cmsghdr` and a real `recvmsg` in libap).

To check the build on the machine:

```rc
php /path/to/APExp/sys/lib/tests/php-smoke.php
```

Its Section 8 exercises each extension *through its library* — bz2 and
zlib round-trip bytes, sqlite3 creates and queries, openssl digests, zip
writes and reads an archive — rather than only asking
`extension_loaded()`. It exits with the failure count. **0 failures on
host PHP 8.3.6; not yet run on 9front.**

---

## 3. The database layer: test this before building anything on it

SQLite works in memory today. What is unproven is a **file-backed
database being written to**, and there is a specific reason to doubt it.

### The mechanism

SQLite's default unix VFS takes a SHARED lock to read and escalates
through RESERVED to EXCLUSIVE to write, all with **`fcntl` byte-range
locks**, on every transaction. APExp's `fcntl` answers `EINVAL` to all
three lock operations (`lib/ap/fcntl/fcntl.c:180`), because **9P has no
byte-range locking** — Plan 9's own exclusive-use bit (`DMEXCL`) is
whole-file and is not what SQLite asks for.

`EINVAL` is the right answer. A lock stub that returned success would
let two writers each believe they held the file, which is the corruption
the locks exist to prevent. But it means a file-backed write is expected
to fail with `disk I/O error` (`SQLITE_IOERR_LOCK`).

### The test — two commands, nothing to build

```rc
sqlite3 /tmp/t.db 'create table t(a); insert into t values(1); select * from t;'
```

- prints `1` → the write path works and only concurrency is open.
- `disk I/O error` → locking is the blocker, as predicted.

If it is the blocker, try the alternative locking style immediately:

```rc
sqlite3 -vfs unix-dotfile /tmp/t2.db 'create table t(a); insert into t values(1); select * from t;'
```

### Why dotfile locking should work here

`unix-dotfile` uses **`mkdir()` as its atomic primitive** —
`dotlockLock()` calls `osMkdir(zLockFile, 0777)` and `dotlockUnlock()`
calls `osRmdir()`. `mkdir` on an existing directory fails, which makes
it a genuine test-and-set, and it is an ordinary 9P operation. No
`fcntl` is involved.

**`unix-dotfile` and `unix-none` are registered unconditionally** —
only `unix-flock`, `unix-posix` and the Apple VFSes sit behind
`SQLITE_ENABLE_LOCKING_STYLE` (which is 0 in this amalgamation). So the
VFS is already in the `libsqlite.a` you have; nothing needs rebuilding
to try it.

### Making it the default, for PHP

PHP cannot select a VFS from a script — `SQLite3::__construct` has no
VFS parameter and `sqlite3_open_v2` is called with a NULL VFS name
(`ext/sqlite3/sqlite3.c:143`), so PHP always gets the default. The knob
is a compile-time define in `sys/src/ape/lib/sqlite/mkfile`:

```
CFLAGS=-c -I$SQSOURCE -DSQLITE_DEFAULT_UNIX_VFS='"unix-dotfile"'
```

**Precedent**: the amalgamation already does exactly this for WASI
(`sqlite3.c:40394`), which is also a platform without POSIX locking.

**This change has not been made and must not be made blind** — it
changes locking for every SQLite consumer in the tree, and dotfile
locking has a real cost: a crash leaves the lock *directory* behind and
the next opener blocks until it is removed by hand. Run the two shell
commands above first; they tell you whether it is needed and whether it
works.

---

## 4. Serving it

Two routes. Neither has been run on 9front.

### 4.1 PHP's built-in server — the one to try first

`sapi/cli/php_cli_server.c` and `php_http_parser.c` **are compiled into
this binary**, so `php -S` is available:

```rc
php -S '*:8080' -t /usr/glenda/www
```

This is worth trying before any Plan 9 web server because it removes
every other variable. It is single-process by default — it forks only
when `PHP_CLI_SERVER_WORKERS` is set, which you should leave unset — and
needs only `socket`, `bind`, `listen`, `accept` and `select`, all of
which libap has.

**Under `php -S`, `header()` works.** The built-in server is its own
SAPI (`cli-server`) with its own header handler
(`php_cli_server.c:552`). This is the opposite of the plain CLI SAPI —
see §4.3.

### 4.2 rc-httpd, and a caution

9front ships `rc-httpd`, a set of rc scripts configured by editing its
own handler-selection script rather than an `httpd.conf`. **Read
`/rc/bin/rc-httpd/` on the machine before copying anything**; recipes
that mention `ip/httpd -h` and a `cgi .php` line are for the older
Plan 9 `ip/httpd` and may not apply.

`aux/listen1 tcp!*!8080 <prog>` is the lower-level option. It hands the
program a **raw connection** on standard input and output and sets no
CGI environment, so a program behind `listen1` must parse the HTTP
request itself. rc-httpd is what gets you CGI variables.

### 4.3 If you use CGI, the CLI SAPI emits no headers

**There is no CGI SAPI in this build** (`--disable-cgi`, so no
`php-cgi`). Under the plain CLI SAPI — `php -f script.php` — `header()`
is a no-op, so a CGI bridge must print the status line and headers
itself:

```rc
#!/bin/rc
# php-cgi -- run a .php file under the CLI SAPI, supplying the headers
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

*rc notes*: `echo` with no argument prints the blank line that ends the
headers; and `=` is a syntax character in rc, legal only as a leading
assignment, so never write `key=value` as an argument to a command.

---

## 5. The part that is genuinely Plan 9: reading the namespace

This needs **no extension at all** and every function in it is in the
build. It is also the most interesting thing the stack can do, because
on Plan 9 the kernel, the network stack and every process are files.

```php
<?php
$out = ['stack' => 'PLAS', 'metrics' => []];

if (is_readable('/dev/sysstat')) {
    $out['metrics']['sysstat'] =
        preg_split('/\s+/', trim(file_get_contents('/dev/sysstat')));
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

Three things in that script are load-bearing:

* **`glob('/net/tcp/[0-9]*')`, not `*`.** `/net/tcp` also contains
  `clone` and `stats`, which are not connection directories.
* **`is_readable`, not `file_exists`.** A synthetic file can exist and
  refuse to be read.
* **No `header()`** — it does nothing under `php -f` (§4.3).

`/net/tcp/stats` is **measured**: `php-smoke.php` reads it as 404 bytes
on 9front.

**Close what you open.** A long-running script walking `/net` or `/proc`
will meet the kernel's `warning: process exceeds 100 file descriptors`;
it is an advisory rather than a limit, but a climbing count is a leak.

### Per-request namespaces: real, but you have to build it

Plan 9 gives the cheapest per-request sandbox of any system here, and it
is not automatic. **`rfork n` gives the child a *copy* of the parent's
namespace — the same files, now privately mutable.** It becomes a
sandbox only when the handler then does the restricting itself:
unmounting what it does not need, binding a subtree over `/`, dropping
the network directory. None of the scripts in this document do that.

---

## 6. Platform limits worth knowing before you start

* **No dynamic loading.** Every Plan 9 binary is static; this is not a
  property of the port. "Deployment is copying a file" is fair, with the
  caveat that the file contains everything it uses.
* **No byte-range file locking** — §3.
* **`disk_free_space()` and `disk_total_space()` return `false`** with
  `Function not implemented`. **9P2000 has no `Tstatfs`**: the protocol's
  entire message set has no filesystem-level space query, so libap's
  `statvfs` fails rather than reporting zeros, which would read as an
  empty disk. A 9front file server will tell you on its own console
  (`echo df >>/srv/cwfs.cmd`), but that is per-server and not reachable
  from a libc call. Applications that check free space before writing —
  the Phoronix Test Suite is one — will report a full disk.
* **Whole-second file timestamps**, no symlinks, no hard links, no
  `/dev/fd`, no `mkfifo`.
* **No job control**, so anything expecting process groups will not get
  them.

---

## 7. A suggested order

1. `php -v`, then `php sys/lib/tests/php-smoke.php`. Confirms the
   interpreter and all 23 extensions on the machine, in one command.
2. The two `sqlite3` commands in §3. **Do this before designing
   anything around a database** — it is the one piece with a known
   mechanism pointing at failure, and it needs no build.
3. `php -S '*:8080'` with a one-line `<?php phpinfo();` and a browser or
   `hget`. Confirms the serving path with the fewest moving parts.
4. The namespace script in §5, which is the part that is worth doing on
   this platform rather than on Linux.
5. Only then rc-httpd, and verify §4.2 against the machine.

Steps 1, 2 and 3 are each one command and each can invalidate the work
after it.
