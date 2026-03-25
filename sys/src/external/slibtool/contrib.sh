#!/bin/sh

# init vars
commit=$1; [ -z "$commit" ] && commit='HEAD'
blank=
bline=
fname=

# source.patch
git format-patch -1 $commit --stdout > source.patch	|| exit 2
cat contrib.msg >> source.patch				|| exit 2

# source.patch without the (noisy) first line
tail -n +2 source.patch > contrib.patch 		|| exit 2

# contrib.patch: first blank line
blank=`grep -n ^$ contrib.patch | head -n1`
[ -z "$blank" ] && exit 2

bline=`echo $blank | cut -f1 -d':'`
[ -z "$bline" ] && exit 2

# use sha256sum of the above for patch file name
fname=`sha256sum contrib.patch | cut -f1 -d' '`		|| exit 2
[ -z "$fname" ] && exit 2

# prepare for submission, sign the patch
mv   contrib.patch $fname.patch				|| exit 2
head -n$bline $fname.patch > $fname.sig			|| exit 2

[ -z "$PAGER" ] && PAGER='less'
$PAGER $fname.patch					|| exit 2
cat contrib.msg						|| exit 2

echo
echo 'press <enter> to continue, <ctrl-c> to abort>'
echo

read enter

gpg  --armor --detach-sign $fname.patch			|| exit 2
cat  $fname.patch.asc >> $fname.sig			|| exit 2

# verify
gpg --verify $fname.sig $fname.patch			|| exit 2

# clean up
rm source.patch
rm $fname.patch.asc

# info
echo
echo "commit $commit was successfully prepared for submission."
echo "$fname.patch: a patch file that can be imported by git-am."
echo "$fname.sig:   a gpg signature file of the above patch."
echo

# all done
exit 0
