@echo off
rem Portable Object Compiler (c) 1997,1998
rem $Id: Setup.bat,v 1.1.1.1 2000/06/07 21:09:23 stes Exp $

if "%1"==""    goto bad
if "%1"=="lcc" goto lcc
if "%1"=="wmk" goto wmk
if "%1"=="nmk" goto nmk
if "%1"=="vac" goto vac
goto bad

:lcc
set MAKE=make
goto copy

:wmk
set MAKE=wmake
goto copy

:nmk
set MAKE=nmake
goto copy

:vac
set MAKE=nmake
goto copy

:copy
copy util\config.%1 src\objcrt\config.h
copy util\config.%1 src\objpak\config.h
copy util\config.%1 src\oclib\config.h
copy util\config.%1 src\objc\config.h
copy util\config.%1 src\cakit\config.h

copy src\objc\objc.%1 src\objc\objc.m

copy src\objcrt\Makefile.%1 src\objcrt\Makefile
copy src\objpak\Makefile.%1 src\objpak\Makefile
copy src\oclib\Makefile.%1 src\oclib\Makefile
copy src\objc\Makefile.%1 src\objc\Makefile
copy src\cakit\Makefile.%1 src\cakit\Makefile
copy words\Makefile.%1 words\Makefile

goto done

:bad
echo.
echo Usage: setup lcc,nmk,wmk,vac
echo        lcc to use lcc-win32 makefiles
echo        nmk to use Microsoft Visual C++ makefiles
echo        wmk to use WATCOM makefiles
echo        vac to use IBM Visual Age makefiles
echo.

:done

