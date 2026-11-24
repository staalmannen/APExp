#!/bin/sh
# Parse a corpus of TypeScript / TSX files and report what fails.
#
# qjsc resolves imports after parsing, so "could not load module" is a
# *successful* parse of a file whose dependencies are not on disk; only a
# SyntaxError counts as a failure. Point it at any project:
#
#   sh tests/quickts/corpus_parse.sh $(git -C ~/src/app ls-files '*.ts' '*.tsx')
root=$(cd "$(dirname "$0")/../.." && pwd)
qjsc="$root/qjsc"
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

if [ $# -eq 0 ]; then
  set -- "$root"/tests/quickts/samples/*.ts
fi

total=0
ok=0
for f in "$@"; do
  total=$((total + 1))
  if "$qjsc" -c -m -o "$tmp/out.c" -N a "$f" >"$tmp/err" 2>&1; then
    ok=$((ok + 1))
  elif ! grep -q '^SyntaxError' "$tmp/err"; then
    ok=$((ok + 1))
  else
    printf '%s\t%s\n' "$f" "$(grep -m1 '^SyntaxError' "$tmp/err")" >>"$tmp/failures"
  fi
done

echo "corpus: $total files, $ok parsed, $((total - ok)) syntax errors"
if [ -f "$tmp/failures" ]; then
  echo
  echo "syntax errors by message:"
  cut -f2 "$tmp/failures" | sort | uniq -c | sort -rn
  echo
  echo "failing files:"
  cut -f1 "$tmp/failures" | sed 's/^/  /' | head -40
  exit 1
fi
