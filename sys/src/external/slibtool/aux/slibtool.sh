#!/bin/sh

#####################################################################
##  slibtool: a strong libtool implementation, written in C        ##
##  Copyright (C) 2016--2025  SysDeer Technologies, LLC            ##
##  Released under the Standard MIT License; see COPYING.SLIBTOOL. ##
#####################################################################

#####################################################################
## slibtool.sh: a backward compatible slibtool wrapper script      ##
## ----------------------------------------------------------      ##
## This script only exists to satisfy build-time requirements in   ##
## projects that directly invoke the generated libtool script at   ##
## configure time (bad practice to begin with, should never be     ##
## necessary in the first place).                                  ##
##                                                                 ##
## By default, slibtool.sh is _NOT_ copied to a project's build    ##
## directory. If found by configure, however (either as a symlink  ##
## to the system installed slibtool.sh or as a physical copy of    ##
## the above, configure shall create ``libtool'' as a symlink to   ##
## this script.                                                    ##
#####################################################################

set -eu

mb_escaped_arg=
mb_escaped_args=
mb_escaped_space=

for arg ; do
	mb_escaped_arg=\'$(printf '%s\n' "$arg" | sed -e "s/'/'\\\\''/g")\'
	mb_escaped_arg="$mb_escaped_space$mb_escaped_arg"
	mb_escaped_args="$mb_escaped_args$mb_escaped_arg"
	mb_escaped_space=' '
done

eval ${SLIBTOOL:-slibtool} "$mb_escaped_args"
