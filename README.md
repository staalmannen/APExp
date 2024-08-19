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
messier (and some would say uglier) with the purpose of an as complete POSIX
compatibility as possible. Ideally will any (C and possibly transpiled-to-C) 
program built for UNIX be a simple configure/make away from being built on 
9front with APExp.


**Fighting the Knights that say NIH**


The Not-invented-here (NIH) attitude is common in fringe hobbyist/research
software communities. This attitude has a certain virtue to it, because it
"forces" a development model to adapt to the unique features and advantages
of the alternative operating system. In many ways, this kind of elitism does
serve a purpose - especially to keep the base system clean and philosophically
coherent. As with any ideology or virtue, however, it can easily be perverted
when applied *in absurdum*. As an opposing ideology stands the pragmatic
live-and-let-live "*do as Þou wilt*", where enabling people to do anything with
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


***Starting material :*** Imported the latest 9front APE sources from git [x] (date: 2024-04-24)
In addition, several patches from @lufia [x1, x2] to build libressl and curl
(introduces pthread, include_next cpp support, etc) and @jamoson (bitfield support in kencc) [x3] has been applied to the
sources. This served as a base to add ports of third party libraries and utilities to enhance compatibility.


Install paths have been modified so that libraries and binaries are installed in the local directory structure of APExp. A bind script (apexp.rc) in the root of APExp can be used to overlay APExp over the native APE.


***Libraries and headers***


- wchar.h/wctype.h provided by the thin "libwtf", integrated in libutf
- curses.h, term.h, panel.h provided by PDCursesMod (built with wchar)
- regex.h provided by pcre2 (pcre2posix, version 10.432024-02-16)
- iconv.h provided by minimal iconv from OpenWrt
- gettext utilities + libintl provided by gettext-tiny from OpenWrt
- OpenBSD sys/queue.h copied from suckless sbase
- getopt.h with gnu getopt_long from NetBSD, imported to libbsd
- strings.h shim pointing to bsd.h
- stdio.h : added fmemopen from tuxpaint, getdelim/getline from gnulib


***Utilities***


- APE make has been replaced by a port of GNU make (version 3.82)
- APE sed has been replaced by a port of GNU sed (version 4.2.1)
- APE grep has been replaced by pcre2grep (version 10.432024-02-16 )
- system awk has been replaced by GNU awk (version 4.0.0) as ape/awk
- system yacc has been replaced by byacc (version 20240109) as ape/yacc
- system lex has been replaced by flex (version 2.6.4) as ape/lex
- the utilities "cut", "ls", "true", "tsort", "xargs" and "yes" have been built from suckless sbase under ape
- steve's mkmk (/n/sources/contrib) imported to APExp

- copied the remove-bitfields script from lufia's port of git to plan9
- copied "head", "which", and "printenv" rc scripts from steve (/n/sources/contrib)
- copied and modified "config" rc script from fgb (/n/sources/contrib)

Many of these are old ports and will hopefully be replaced by more up-to-date ports soon.

***Transpilers***


C transpilers is a fun little proof-of-concept and also opens up for more languages.

- copied the last (version 3.03) plan9 cfront (c++) port from steve (/n/sources/contrib)


**References**

[1] https://9p.io/wiki/plan9/porting_alien_software_to_plan_9/index.html

[2] https://git.sr.ht/~ft/npe

[3] https://wiki.9front.org/porting

[4] https://www.youtube.com/watch?v=zPd20UMOL7g

[5] https://hv.diva-portal.org/smash/get/diva2:1821484/FULLTEXT01.pdf

[6] https://github.com/netsurf-plan9

[x] git://git.9front.org/plan9front/plan9front

[x1] https://inbox.vuxu.org/9front/0e170f2c1818fb21b795c2151e52adaf.squirrel@mx.sdf.org/

[x2] https://github.com/lufia/plan9/pulls

[x3] https://webbkurs.ei.hv.se/~imjam/pub/kenccbitfield/



***Post scriptum***

The unofficial mascot of the project is the [Rabbit of Caerbannog](https://en.wikipedia.org/wiki/Rabbit_of_Caerbannog),
which fits both with the bunny theme of Glenda and the Monty Python Holy Grail reference and "killing knights".

