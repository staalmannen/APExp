hell: kill autotools
================================================
autotools fucking sucks!

look, here's what our friends at gnu have to say about it, on their very own autotools faq:
```
https://www.gnu.org/software/automake/faq/autotools-faq.html#Why-is-everything-so-complicated_003f

1.7 Why is everything so complicated?

TODO 
```
hell replaces all of this with two small C programs that parse the same inputs,
probe in parallel without a shell script, emits ninja files directly, and builds everything statically.

hell was created for [dérive linux](https://derivelinux.org). it is used as the main inplementation of autotools in the [dérive ports tree](https://codeberg.org/derivelinux/derive) if you want to see some examples of building real projects with it.

currently hell is tested and builds libexpat, libarchive, and file succesfully, without any configuration.

with some manual configuration, it can build the tinyx X11 server, the kbd keymap manager, and the eiwd wifi daemon. 

with manual configuration, it is theoretically possible to build 90% of autotools project with hell. however, some more complex automake syntax is not supported. this can usually be fixed by patching some sections of the Makefile.am, but feel free to report an issue, i will try and make the syntax parsing as catch-all as possible.

hell contains two tools:

- demiurge: configure.ac scanner that produces config inputs for satan
- satan:    automake-to-ninja compiler with install and clean targets

how we replace
--------------
- autoconf: demiurge prepares inputs for satan by extracting and resolving
  `@VAR@`, `CHECK_*`, and `COND_*` inputs into a `.demiurge` file.
- automake: satan replaces `automake` + `makefile.in` by parsing `makefile.am`
  and emitting `build.ninja` plus install targets.
- libtool: satan does static only builds by converting `.la` to `.a` and
  dropping shared/libtool flags during ninja generation, dynamic linking considered harmful

build
-----
to build and install hell, you will need a `yacc` and a `lex`

the `byacc` and `reflex` implementations of said programs are tested.

then run:

```
make
make install
sudo satan configure
```

once built, you can test hell by building hell with hell [you can replace samu with ninja if you so desire]:

```
demiurge
satan gen
samu
sudo samu install
```

use
---
how to build a autotools project with hell:

- `sudo satan configure`
  - detects toolchain and writes /etc/satan.conf, you only need to do this once after install
- `demiurge/demiurge [project_root]`
  - parses `configure.ac` (or `configure.in`)
  - scans `Makefile.am` and `*.in` for `@VAR@` substitutions
  - writes `.demiurge` with resolved `@VAR@` values plus `CHECK_*` and `COND_*`
- `satan/satan gen [-c] [-j N] [-Dkey=val] [PREFIX=val] [DESTDIR=val] [project_root]`
  - reads `/etc/satan.conf` and optional `.satan` in the project root
  - `-Dkey=val` entries act like extra `.satan` lines. 
  - `PREFIX` and `DESTDIR` override install paths for generated install targets
  - `-c` runs a fast autoconf-only pass (config headers + `Makefile.in`/`*.in` @VAR@ substitutions) without generating `build.ninja`
  - runs probes, like ./configure in real autotools, but parralel
  - parses `Makefile.am` and `SUBDIRS`
  - writes `build.ninja` in each directory
  - `-j` overrides probe parallelism, defaults nproc
- `cd [project_root] && ninja && sudo ninja install`
  - builds everything with ninja
- `satan clean [project_root]`
  - runs `ninja -t clean` in each directory with a `build.ninja`
  - removes generated `build.ninja`, `config.h`, `*.h` from `.h.in`, `.ninja_*`, and `.demiurge`

if this does not work, attempt to edit unresolved variables in [projectroot]/.satan, or pass -D flags.

config
------

`/etc/satan.conf` is `key=value` per line, `#` comments allowed.

keys:

- `CC`, `CXX`, `AR`, `RANLIB`, `PKGCONF`, `NINJA`
- `STATIC=1`, `FULLY_STATIC=1`
- `PREFIX`, `BINDIR`, `SBINDIR`, `LIBDIR`, `INCLUDEDIR`, `MANDIR`, `PKGCONFIGDIR`
- `CFLAGS`, `CXXFLAGS`, `CPPFLAGS`, `CXXCPPFLAGS`, `ASFLAGS`, `LDFLAGS`

per project override
--------------------

create a `.satan` file in the project root to override config keys per project
usually satan will create one after `satan gen` 
If `.demiurge` exists, it is loaded first, then `.satan` overrides it.

optional keys:

- `EXTRA_PKG` (space-separated pkgconf packages; adds cflags/libs)
- `EXTRA_CPPFLAGS`, `EXTRA_CFLAGS`, `EXTRA_ASFLAGS`, `EXTRA_LDFLAGS`, `EXTRA_LDLIBS`
- `DEF_FOO` (emit `#define FOO <value>` in config headers; value is used verbatim)
- `UNDEF_FOO=1` (force `FOO` to remain undefined in config headers)
- `CHECK_PKG` (space-separated pkgconf packages; defines `HAVE_PKG_*`)
- `CHECK_HEADER`, `CHECK_FUNC`, `CHECK_LIB` (space-separated probes; defines `HAVE_*`)
- `CHECK_DECL` (space-separated symbols; defines `HAVE_DECL_*`)
- `COND_FOO=0|1` (defines Automake condition `FOO`)
- `LTLIBOBJS`, `LIBOBJS` (space-separated replacement objects, e.g. `fmtcheck.lo`)
- `PERMISSIVE=1` (ignore unknown `@VAR@` substitutions)
- `PROBE_JOBS` (override probe parallelism)

if `satan/satan gen` hits unknown conditionals and no `.satan` exists, it writes a
stub `.satan` with `COND_*` keys set to `0`, this is likely to almost always happen. sometimes it affects builds,
if it does, set the value to something reasonable. 

unknown `@VAR@` substitutions default to empty values and are written to
`.satan` for review/fixing. this is a limitation of satan.

supported automake
------------------
this is not comprehensive or complete, but it gives you a general idea.
   
inputs:

- `SUBDIRS`
- `bin_PROGRAMS`, `sbin_PROGRAMS`, `noinst_PROGRAMS`
- `lib_LIBRARIES`, `noinst_LIBRARIES`
- `lib_LTLIBRARIES`, `noinst_LTLIBRARIES` (converted to `.a`)
- `*_SOURCES`
- `AM_CPPFLAGS`, `*_CPPFLAGS`
- `AM_CFLAGS`, `*_CFLAGS`
- `AM_ASFLAGS`, `*_ASFLAGS`
- `AM_LDFLAGS`, `*_LDFLAGS`
- `LDADD`, `*_LDADD`
- `include_HEADERS`, `nobase_include_HEADERS`
- `pkgdata_DATA`, `data_DATA`, `sysconf_DATA`, `pkgconfig_DATA`, `pkgconfigexec_DATA`
- `BUILT_SOURCES`
- `if/else/endif`, `include`/`-include`, line continuations

gen rules:

- `target: deps` rules with tab-indented commands are translated to `rule gen`.
- `$@` and `$^` are supported in rule commands.
- `$(VAR)` and `@VAR@` expansion is supported (limited to config/toolchain vars).

hellfile extensions
-------------------

in hell, `Makefile.am` supports extra `hell.` commands for installs that are annoying
to express explicitly. satan also accepts `hellfile`/`Hellfile` in place of
`Makefile.am` and parses it the same way. this is useful for using hell as a custom build system for your project.

commands:

- `hell.install <src> <dest>`
  - if `<src>` is a directory: recursive install, preserving subpaths under `<dest>`
  - if `<src>` contains wildcards: glob install, `<dest>` is treated as a directory
  - otherwise installs a single file
- `hell.install_dir <dir> <dest>` (explicit directory install)
- `hell.install_glob <pattern> <dest>` (explicit glob install)

`<src>` paths are relative to the `Makefile.am` directory. `<dest>` should use an
install prefix like `$INCLUDEDIR`, `$LIBDIR`, `$DATADIR`, etc. for single-file
installs, use a trailing `/` on `<dest>` to install by basename; for directory
installs, `<dest>` is treated as a path prefix.

limitations
-----------

- c, c++, and assembly sources (.c, .cc, .cpp, .cxx, .s, .S)
- does not support full automake syntax
- `@VAR@` substitutions are limited to toolchain and prefix keys
- manual configuration is tedious 
