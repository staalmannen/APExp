#=============================================================
#
#	UNARJ.MAK - Makefile for project D:\ARJSRC\UNARJ\UNARJ.PRJ
#		Created on 01/21/94 at 12:55
#
#=============================================================

.AUTODEPEND

#=============================================================
#		Translator Definitions
#=============================================================
CC = bcc +UNARJ.CFG
TASM = tasm.exe
TLIB = tlib.exe
TLINK = tlink
RC = brcc.exe
RB = rc.exe
LIBPATH = F:\BCOS2\LIB
INCLUDEPATH = F:\BCOS2\INCLUDE


#=============================================================
#		Implicit Rules
#=============================================================
.c.obj:
  $(CC) -c {$< }

.cpp.obj:
  $(CC) -c {$< }

.asm.obj:
  $(TASM) -Mx $*.asm,$*.obj

.rc.res:
  $(RC) -r $*.rc

#=============================================================
#		List Macros
#=============================================================


EXE_DEPENDENCIES =  \
 environ.obj \
 decode.obj \
 unarj.obj

#=============================================================
#		Explicit Rules
#=============================================================
unarj.exe: unarj.cfg $(EXE_DEPENDENCIES)
  $(TLINK) /Toe /ap /L$(LIBPATH) @&&|
F:\BCOS2\LIB\C02.OBJ+
environ.obj+
decode.obj+
unarj.obj
unarj,unarj
F:\BCOS2\LIB\C2.LIB+
F:\BCOS2\LIB\OS2.LIB

|


#=============================================================
#		Individual File Dependencies
#=============================================================
ENVIRON.obj: unarj.cfg ENVIRON.C 

DECODE.obj: unarj.cfg DECODE.C 

UNARJ.obj: unarj.cfg UNARJ.C 

#=============================================================
#		Compiler Configuration File
#=============================================================
unarj.cfg: unarj.mak
  copy &&|
-L$(LIBPATH)
-I$(INCLUDEPATH)
-vi-
| unarj.cfg


