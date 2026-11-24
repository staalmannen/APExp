#!/bin/sh
# Date's local time zone in both getTimezoneOffset() branches: libc's
# tm_gmtoff, and the one for a libc without it (CONFIG_NO_TM_GMTOFF, what
# newlib gets on its own), plus JS_SetTimezoneOffsetFunc. See test_tz.c.
set -e
cd "$(dirname "$0")/../.."
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT
CC=${CC:-cc}
flags="-O0 -D_GNU_SOURCE -DCONFIG_VERSION=\"$(cat VERSION)\" -funsigned-char -fwrapv -w -I."
$CC $flags -c tests/quickts/test_tz.c -o "$tmp/test_tz.o"
for src in dtoa libregexp libunicode cutils; do
    $CC $flags -c $src.c -o "$tmp/$src.o"
done
for variant in libc no_tm_gmtoff; do
    extra=""
    if [ "$variant" = no_tm_gmtoff ]; then extra="-DCONFIG_NO_TM_GMTOFF"; fi
    $CC $flags $extra -c quickjs.c -o "$tmp/quickjs_$variant.o"
    $CC "$tmp/test_tz.o" "$tmp/quickjs_$variant.o" "$tmp/dtoa.o" "$tmp/libregexp.o" \
        "$tmp/libunicode.o" "$tmp/cutils.o" -lm -lpthread -o "$tmp/test_tz_$variant"
    "$tmp/test_tz_$variant" "$variant"
done
