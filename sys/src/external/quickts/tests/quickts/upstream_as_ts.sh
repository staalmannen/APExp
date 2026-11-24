#!/bin/sh
# Run QuickJS's own test suite through the TypeScript and JSX passes.
#
# Every file is plain JavaScript, so neither pass may change a single result:
# this is the regression proof that the hooks are inert on JavaScript.
# `.ts` turns on TypeScript erasure, `.tsx` turns on TypeScript and JSX.
root=$(cd "$(dirname "$0")/../.." && pwd)
qjs="$root/qjs"
src="$root/tests"
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

cp "$src"/assert.js "$tmp"/assert.js
fail=0
for ext in ts tsx; do
  for f in test_closure test_language test_builtin test_loop test_bigint; do
    cp "$src/$f.js" "$tmp/$f.$ext"
    if "$qjs" --std "$tmp/$f.$ext" >"$tmp/$f.out" 2>&1; then
      echo "  ok    $f.js (as .$ext)"
    else
      echo "  FAIL  $f.js (as .$ext)"
      head -5 "$tmp/$f.out" | sed 's/^/        /'
      fail=1
    fi
  done
done
exit $fail
