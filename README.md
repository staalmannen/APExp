IMPORTANT NOTE
There is no guarantee that APExp builds from scratch in between releases.
Many (temporarily) breaking changes can occur between releases. 
The best option is probably to download the latest release.

# APExp
Plan9 (9front) APE with experimental patches (a.k.a APExp)

**Abstract**


With the advent of NPE as a superior compatibility layer using system libraries
and a thin shim, the need for the traditional APE will become less critical
for building the base system in the future. Instead of this becoming the 
death of APE, I would argue that it frees up alternative use cases for it 
when APE stops being an integral part of the base 9front system: NPE
aims to be as small, neat and native as possible, only aiming to build some
alien software. In contrast, I aim to make this free APE something bigger, 
messier (and some would say uglier) with the purpose of an as complete GNU / POSIX
compatibility as possible. Ideally will any (C and possibly transpiled-to-C) 
program built for UNIX be a simple configure/make away from being built on 
Plan9 with APExp.


**Fighting the Knights that say NIH**


The Not-invented-here (NIH) attitude is common in fringe hobbyist/research
software communities. This attitude has a certain virtue to it, because it
"forces" a development model to adapt to the unique features and advantages
of the alternative operating system. In many ways, this kind of elitism does
serve a purpose - especially to keep the base system clean and philosophically
coherent. As with any ideology or virtue, however, it can easily be perverted
when applied *in absurdum*. As an opposing ideology stands the pragmatic
live-and-let-live "*do what Þou wilt ...*", where enabling people to do anything with
their system is seen as a good thing.


APE (Ansi Posix Environment) has historically been a compatibility layer to
build or port legacy UNIX applications to Plan9 [1]. Recently, an interesting
alternative to APE has been developed on 9front (the most actively developed
fork of Plan9) - NPE, which aims to fill a similar niche but with a much more
limited scope [2,3,4]. There is however definitely also a need for a more
complete, messier and complex compatibility layer even if it is not included
in the base system. A small community will never be able to produce and
maintain software on par with what is available in the wider open source
ecosystem. One nice example of this is the Netsurf port [5,6], which by far is
the most capable web browser available on Plan9.


**Modifications made to APE**


***Starting material :*** 

Imported the latest 9front APE sources from git [7] (date: 2024-04-24; rebased 2026-01-29, which included the bitfield patch from @jamoson (bitfield support in kencc) [8]).
In addition, several patches from @lufia [9, 10] to build libressl and curl
(introduces pthread, include_next cpp support, etc) has been applied to the
sources. To get more C99 compatibility, vibe-coded (claude.ai) patches have been introduced (VLA, hex float support, complex support, compound literals, division by 0, dropping keywords, etc). C99 support is *pretty much complete* by now, and we have even started adding some C11/C23 features to the compiler. This served as a base to add ports of third party libraries and utilities to enhance compatibility.


Install paths have been modified so that libraries and binaries are installed in the local directory structure of APExp. A bind script (apexp-sh) in the root of APExp can be used to overlay APExp over the native APE.


***Headers***
- err.h provided by libnbcompat (NetBSD) [11]
- regex.h provided by musl libc
- iconv.h provided by musl libc
- libintl.h provided by musl libc
- OpenBSD sys/queue.h copied from suckless sbase
- getopt.h gnu getopt_long from musl libc
- strings.h shim pointing to bsd.h
- stdio.h : added fmemopen, getdelim/getline from musl libc
- wchar.h/wctype.h provided by the thin "libwtf" [12]
- readline.h provided by libedit
- curses.h, term.h, panel.h provided by PDCursesMod

***Libraries***

**new libap**
- libap, lib9, libbsd, libpthreads, libutf, libfmt, libv, libmp and libnet are merged
- 3rd party libc functions primarily from musl libc, but also some from NetBSD (fts-standalone, libnbcompat)
- sys/src/ape/lib/ap has been reorganized like the musl src directory
- imported fenv, math, complex, regex, search and other functions from musl libc
- migrated from APE stdio to musl stdio (with some major porting, using pthreads)
- fchown/fchmod stubs introduced

**3rd party**
- libcurses : PDCursesMod (check out 2026-04-08; built with utf8/wchar)
- libedit (version 3.1 2025-10-16)
- libpcre2 (version 10.47)
- liblzma (from xz version 5.8.3)
- libz (version 1.3.2)
- libbz2 (version 1.0.8)


***Utilities***

- The shell is still the original APE pdksh
- -> TODO: replace with GNU bash (version 5.3)
- APE make has been replaced by a port of GNU make (version 4.4.1)
- APE sed has been replaced by a port of GNU sed (version 4.9)
- APE grep has been replaced by pcre2grep (version 10.47 ). 
- -> TODO: replace with GNU grep (version 3.12)
- GNU awk (version 5.4.0). Since native awk is sometimes needed, GNU awk is installed as gawk
- GNU m4 (version 1.4.21) has been added
- gettext utilities from Sabotage Linux "gettext-tiny" [14]
- A "musl" iconv utility has been added from Alpine Linux.
- system yacc has been replaced by byacc (version 20240109) as yacc. 
- -> TODO: replace with Bison (version 3.8) and keep native yacc as "yacc" because it is sometimes needed
- system lex has been replaced by flex (version 2.6.4) as lex
- vibe-coded (claude.ai) GAS-compatible "as" front end to native $Oa assemblers.
- the utilities like "cut", "ls", "true", "tsort", "xargs" and "yes" *et al.* have been built from suckless sbase [15]
- steve's mkmk (/n/sources/contrib) imported to APExp
- copied "which", and "printenv" rc scripts from steve (/n/sources/contrib)


***Languages***


- Lua (5.5.0) is included by default in APExp


***Transpilers***


C transpilers is a fun little proof-of-concept and also opens up for more languages. Many will only have very little practical use, however.

- The pascal-to-C transpiler p2c (2.01) is included in APExp
- The fortran-to-C transpiler f2c (20250303) is included in APExp
- The ObjC-to-C transpiler (3.4.8, bootstrap, TODO: build 3.4.13 with the bootstrapped compiler) is included in APExp


***(un)archivers***

Many (old) sources are still distributed as compressed archives, and the ability to unpack those
sources could be a barrier. Because of this, APExp package several (un)archivers by default:

- minigzip (from zlib)
- bzip2 utilities (from libbz2)
- unarj (2.65)
- unrar (2.71 ; can handle old rar archives. More recent versions written in c++)
- unace (2.7)
- clzip (1.14)
- xz (5.8.3)


***BLOAT!!!1!!!***

Yes, the default build is "bloated" because I enable everything that I believe will build out of the box. That way, I can identify bugs early on. As an end-user, it is *very* easy to make a minimal build: just comment out the sub-directories you don't want to build in the mkfiles. In general, libraries (in sys/src/ape/lib) and utilities (in sys/src/ape/cmd) relating to non-C languages, transpilers or archivers should be safe to disable. You might even be able to disable other stuff as well and get a working build.



**References**

[1] https://9p.io/wiki/plan9/porting_alien_software_to_plan_9/index.html

[2] https://git.sr.ht/~ft/npe

[3] https://wiki.9front.org/porting

[4] https://www.youtube.com/watch?v=zPd20UMOL7g

[5] https://hv.diva-portal.org/smash/get/diva2:1821484/FULLTEXT01.pdf

[6] https://github.com/netsurf-plan9

[7] git://git.9front.org/plan9front/plan9front

[8] https://webbkurs.ei.hv.se/~imjam/pub/kenccbitfield/

[9] https://github.com/lufia/plan9/pulls

[10] https://inbox.vuxu.org/9front/0e170f2c1818fb21b795c2151e52adaf.squirrel@mx.sdf.org/

[11] https://github.com/archiecobbs/libnbcompat

[12] https://github.com/staalmannen/libwtf

[13] https://github.com/cheusov/nbase

[14] https://github.com/sabotage-linux/gettext-tiny

[15] https://core.suckless.org/sbase/



***Post scriptum***

The unofficial mascot of the project are the rabbit knights riding snails in medieval art.
![a jousting rabbit riding a snail with a human head](rabbit_riding_snail.jpg)

It would be fun to have a Glenda-themed variant of this.

