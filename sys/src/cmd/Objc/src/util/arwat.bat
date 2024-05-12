@echo off
rem Wrapper around the watcom wlib tool
rem to make it behave like a UNIX 'ar'.
rem Specifically, this script deals with the '+-'
rem in between archive and object file.

rem -q quiet
rem -c case sensitive
rem -n new lib
rem -b no backup

wlib -q -c -b %1 +- %2

