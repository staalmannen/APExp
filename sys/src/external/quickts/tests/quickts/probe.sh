#!/bin/sh
# One-liner probes: each snippet is written to a .ts/.tsx file and run.
# Prints ok/FAIL per snippet. Used while reviewing grammar coverage.
root=$(cd "$(dirname "$0")/../.." && pwd)
qjs="$root/qjs"
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT
n=0
probe() {
  ext=$1; shift
  n=$((n + 1))
  {
    if [ "$ext" = tsx ]; then
      echo 'const __frameosFragment = Symbol("f"); const __frameosJsx = (t: any, p: any, ...c: any[]) => ({ t, p, c });'
    fi
    printf '%s\n' "$1"
  } > "$tmp/p$n.$ext"
  if out=$("$qjs" "$tmp/p$n.$ext" 2>&1); then
    printf '  ok    %s\n' "$1" | head -1
  else
    printf '  FAIL  %s\n        %s\n' "$1" "$(printf '%s' "$out" | head -1)"
  fi
}
probe ts 'export default abstract class A { abstract f(): void }'
probe ts 'class P { constructor(private x = 1, public y?: number) {} } if (new P().x !== 1) throw 1'
probe ts 'const m = new Map<string, number>; if (m.size !== 0) throw 1'
probe ts 'function g<T>(x: T) { return x } const f = g<string>; if (f("a") !== "a") throw 1'
probe ts 'class A { accessor x = 1 } if (new A().x !== 1) throw 1'
probe ts 'let x: number = 1; x!++; if (x !== 2) throw 1'
probe ts 'const o = { a: 1 }; (o as any).b = 2; if ((o as any).b !== 2) throw 1'
probe ts 'async function f() { const x = await Promise.resolve(1) as number; return x } f()'
probe ts 'const a = [1] as const; const b = a[0] satisfies 1;'
probe ts 'let v = 1 as unknown as string as any;'
probe ts 'function f(this: void, ...args: [a: number, b?: string]): void {} f(1)'
probe ts 'type A = { [K in "a" | "b" as `get${Capitalize<K>}`]: () => number }; const x: A = { getA: () => 1, getB: () => 2 };'
probe ts 'type Fn = new (...args: any[]) => object; abstract class B {} type C = abstract new () => B;'
probe ts 'let x: typeof globalThis.Math.PI = 3;'
probe ts 'declare module "foo"; declare module "bar" { export const x: number }'
printf 'export const C = 1;\n' > "$tmp/x.ts"
probe ts 'export {}; import { type A as B, C as D } from "./x.ts"; if (D !== 1) throw 1'
probe ts 'class A { static #count: number = 0; static inc(): number { return ++A.#count } } if (A.inc() !== 1) throw 1'
probe ts 'enum E { A = 1 << 0, B = 1 << 1, AB = A | B } if (E.AB !== 3 || E[3] !== "AB") throw 1'
probe ts 'const enum E { A = "a" } if (E.A !== "a") throw 1'
probe ts 'enum E { A = -1, B } if (E.B !== 0) throw 1'
probe ts 'label: for (;;) { break label }'
probe ts 'const type = 1, of = 2; for (const x of [type, of]) {}'
probe ts 'if (1 < 2 && 3 > 2) {} else throw 1'
probe ts 'const s = `a${1 < 2 ? "<" : ">"}b`; if (s !== "a<b") throw 1'
probe ts 'let a = 1; let b = a < 2 ? 3 : 4; if (b !== 3) throw 1'
probe ts 'function f(cb: (err: Error | null, v?: number) => void) { cb(null, 1) } f((e, v) => {})'
probe ts 'const fn = function <T>(x: T): T { return x }; if (fn(1) !== 1) throw 1'
probe ts 'const o = { f<T>(x: T): T { return x }, async g<T>(x: T) { return x }, *h<T>() {} }; if (o.f(1) !== 1) throw 1'
probe ts 'class A { f = <T,>(x: T): T => x } if (new A().f(1) !== 1) throw 1'
probe ts 'let x: string | undefined; x ??= "d"; if (x !== "d") throw 1'
probe ts 'const x = (1 as number)!'
probe tsx 'const a = <div>{1 < 2 ? "y" : "n"}</div>;'
probe tsx 'const f = <T,>(x: T) => <div>{String(x)}</div>;'
probe tsx 'const a = <a href="http://x">x</a>;'
probe tsx 'const a = <div data-x={`t${1}`} />;'
probe tsx 'const a = <div>{[1,2].map((n) => <b key={n}>{n}</b>)}</div>;'
probe tsx 'const a = <div title={"a" + "b"} {...{}} />;'
probe tsx 'const a = (<>
  <b />
  text {1}
</>);'
probe ts 'export = 1;'
probe ts 'import x = require("y");'
probe ts 'class A { @dec f() {} }'
probe ts 'let x = <number>1;'
