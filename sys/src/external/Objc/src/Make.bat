@echo off
rem Portable Object Compiler (c) 1997,1998,1999
rem $Id: Make.bat,v 1.1.1.1 2000/06/07 21:09:23 stes Exp $

rem Substitute for UNIX top level makefile, with Windows/DOS
rem style CD commands, so that it can be executed in topdir
rem with a simple "make".
rem Other possibilities: "make clean", "make bootstrap" etc.

set CD=cd

@echo on

%CD%   src\objcrt
%MAKE% %1
%CD%   ..\objpak
%MAKE% %1
%CD%   ..\oclib
%MAKE% %1
%CD%   ..\objc
%MAKE% %1

%CD%   ..\..

