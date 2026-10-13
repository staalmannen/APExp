#!/bin/sh
# Usage: utils/fix-perms.sh
# fixes the permissions of the files in the build tree
#
# To verify:   find . -type f -perm +111 -print

root=${1:-.}

echo "fixing permissions under [${root}]"

find ${root} -type f -follow -perm +111 '(' \
     -name '*.in' \
  -o -name '*.xml' \
  -o -name '*.xsl' \
  -o -name '*.css' \
  -o -name '*.html' \
  -o -name '*.png' \
  -o -name '*.xsl' \
  -o -name '*.m4' \
  -o -name '*.h' \
  -o -name '*.c' \
  -o -name '*.d' \
  -o -name '*.lisp' \
  -o -name '*.tst' \
  -o -name '*.bat' \
  -o -name 'link.sh' \
  -o -name '.cvsignore' \
  -o -name 'Makefile*' \
  -o -name 'README' \
  ')' \
  -exec chmod -c a-x '{}' ';'

find ${root} -name configure -exec chmod -c +x '{}' ';'
