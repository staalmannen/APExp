#!/bin/sh
# Differential bytecode test.
#
# Compile each plain-JavaScript file twice with qjsc -- both passes off, then
# TypeScript *and* JSX forced on via QJSC_TYPESCRIPT / QJSC_JSX -- and diff
# the emitted bytecode. Any difference means a hook fired on JavaScript.
#
# Usage: sh tests/quickts/bytecode_diff.sh [file.js ...]
# With no arguments, QuickJS's own tests and examples are used.
root=$(cd "$(dirname "$0")/../.." && pwd)
qjsc="$root/qjsc"
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

if [ $# -eq 0 ]; then
  set -- "$root"/tests/*.js "$root"/examples/*.js "$root"/repl.js
fi

total=0
same=0
differ=0
skipped=0
for f in "$@"; do
  total=$((total + 1))
  if ! "$qjsc" -c -o "$tmp/a.c" -N a "$f" >/dev/null 2>&1; then
    skipped=$((skipped + 1))
    continue
  fi
  if ! QJSC_TYPESCRIPT=1 QJSC_JSX=1 "$qjsc" -c -o "$tmp/b.c" -N a "$f" >/dev/null 2>&1; then
    echo "  FAILS WITH THE PASSES ON  $f"
    differ=$((differ + 1))
    continue
  fi
  if cmp -s "$tmp/a.c" "$tmp/b.c"; then
    same=$((same + 1))
  else
    echo "  BYTECODE DIFFERS  $f"
    differ=$((differ + 1))
  fi
done

echo "bytecode diff: $total files, $same identical, $differ differing, $skipped not compilable by qjsc"
[ "$differ" -eq 0 ]
