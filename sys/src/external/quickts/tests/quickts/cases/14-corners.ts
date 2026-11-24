// The corners found while reviewing the erasure hooks against the TypeScript
// grammar: statements that carry annotations in places the first pass did
// not look, and the arrow/conditional ambiguity rules.
export {};
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

// --- annotations in statement positions --------------------------------
try {
  throw new Error("x");
} catch (e: unknown) {
  assert((e as Error).message === "x", "typed catch binding");
}
try {
  throw { code: 1 };
} catch ({ code }: any) {
  assert(code === 1, "typed destructured catch binding");
}

let total = 0;
for (const n: number of [1, 2, 3]) total += n;
assert(total === 6, "typed for-of binding");
for (const k: string in { a: 1 }) total += k.length;
assert(total === 7, "typed for-in binding");
for (let i: number = 0, j: number = 2; i < 2; i++) total += j;
assert(total === 11, "typed for(;;) bindings");
for (const [a, b]: [number, number] of [[1, 2]]) total += a + b;
assert(total === 14, "typed destructured for-of binding");

// --- the arrow / conditional rules --------------------------------------
const flag = true;
const a = 1, b = 2, c = 3;

// Every one of these is what tsc makes of it (checked with tsc 5.x).
const r1 = flag ? (a) : (x: number) => x + 1;
assert(r1 === 1, "conditional with an arrow in the else branch");
const r2 = !flag ? (a) : (x: number) => x + 1;
assert(typeof r2 === "function" && r2(1) === 2, "same conditional, other branch");
const r3 = flag ? (a) : c => c;
assert(r3 === 1, "bare-parameter arrow in the else branch");

// A return-typed arrow in the `?` branch: an arrow, because the
// conditional's ':' still follows its body.
const r4 = flag ? (x: number): number => x * 2 : a;
assert(typeof r4 === "function" && r4(2) === 4, "return-typed arrow in the ? branch");
const r4b = flag ? (x: number): void => {
  total += x;
} : undefined;
assert(typeof r4b === "function", "block-bodied return-typed arrow in the ? branch");
const r4c = flag ? (x: number): number => x ? 1 : 2 : a;
assert(typeof r4c === "function" && r4c(0) === 2, "arrow body with its own conditional");
const r4d = flag ? (x: number): number => x : a;
assert(r4d(7) === 7, "arrow with an identifier body");

// ... and in the else branch and in parentheses.
const r5 = !flag ? a : (x: number): number => x * 3;
assert(typeof r5 === "function" && r5(2) === 6, "return-typed arrow in the else branch");
const r5b = flag ? ((x: number): number => x * 3) : a;
assert(typeof r5b === "function" && r5b(2) === 6, "parenthesised return-typed arrow in the ? branch");
const r6 = flag ? [(x: number): number => x] : [];
assert(typeof r6[0] === "function", "return-typed arrow inside an array in the ? branch");

// Nested conditionals.
const r7 = flag ? (flag ? (b) : (y: number) => y) : c;
assert(r7 === 2, "nested conditional");
const r8 = flag ? (b) : c ? a : b;
assert(r8 === 2, "conditional whose else branch is a conditional");
const r9 = flag ? (b) : { x: 1 };
assert(r9 === 2, "conditional whose else branch is an object literal");

// Return types on every arrow shape.
const t1 = (): void => {};
const t2 = (x: number): number => x;
const t3 = async (x: number): Promise<number> => x;
const t4 = async <T>(x: T): Promise<T> => x;
const t5 = <T,>(x: T): T => x;
const t6 = async ({ v }: { v: number }): Promise<number> => v;
const t7 = (x: number): { y: number } => ({ y: x });
const t8 = (x: number): ((n: number) => number) => (n) => n + x;
const t9 = (f: (n: number) => number): number => f(1);
assert(t2(1) === 1 && t5(2) === 2 && t7(3).y === 3, "arrow return types");
assert(t3(1) instanceof Promise && t4(1) instanceof Promise && t6({ v: 1 }) instanceof Promise, "async arrows");
assert(t8(1)(2) === 3 && t9((n) => n + 1) === 2, "function-typed returns and params");
t1();

// Arrows as arguments, with and without types, inside generic calls.
const mapped = [1, 2].map((n: number): string => String(n));
const mapped2 = [1, 2].map<string>((n) => String(n));
assert(mapped[1] === "2" && mapped2[0] === "1", "typed arrows as arguments");

// Optional parameters in arrows, `this` parameter in functions.
const opt = (x?: number, ...rest: number[]): number => (x ?? 0) + rest.length;
assert(opt() === 0 && opt(1, 2, 3) === 3, "optional and rest in arrows");
function withThis(this: { n: number }): number {
  return this.n;
}
assert(withThis.call({ n: 5 }) === 5, "this parameter");

// --- type-only module syntax -------------------------------------------
export type * from "./nowhere.ts";
export type * as NS from "./nowhere.ts";
export type { Foo } from "./nowhere.ts";
import type Def from "../helpers/exports.ts";
import { type Named, other } from "../helpers/exports.ts";
export const useOther = other;

// --- expressions ---------------------------------------------------------
const nn: { v?: number[] } = { v: [1] };
assert(nn.v![0]! + 1 === 2, "non-null on member and element");
assert((nn as { v: number[] }).v.length === 1, "as on a parenthesised object");
const tpl = `${a as number}` satisfies string;
assert(tpl === "1", "as inside a template literal, satisfies on the result");
const generic = new Map<string, Array<Map<number, string>>>();
assert(generic.size === 0, "nested type arguments with merged >> tokens");
const noParens = new Map<string, number>;
assert(noParens.size === 0, "new with type arguments and no parentheses");
function ident<T>(x: T): T {
  return x;
}
const instantiated = ident<string>;
assert(instantiated("i") === "i", "instantiation expression");
const inst2 = [ident<number>, ident<boolean>];
assert(inst2[1](true) === true, "instantiation expressions in a list");
const literalMethods = {
  f<T>(x: T): T {
    return x;
  },
  async g<T>(x: T): Promise<T> {
    return x;
  },
  *h<T>(x: T): Generator<T> {
    yield x;
  },
  get v(): number {
    return 1;
  },
};
assert(literalMethods.f(1) === 1 && literalMethods.h(2).next().value === 2, "generic object literal methods");
assert(literalMethods.g(3) instanceof Promise && literalMethods.v === 1, "async generic and typed getter in a literal");
const shifted = a << b >> 1;
assert(shifted === 2, "shift operators still parse");
const cmp = a < b && b > a && a <= b && b >= a;
assert(cmp, "comparisons still parse");

// Words that are keywords only in types, used as values.
const keyof = 1, infer = 2, is = 3, asserts = 4, unique = 5, readonly = 6;
assert(keyof + infer + is + asserts + unique + readonly === 21, "type-only words as identifiers");
const obj = { keyof, is, get: 1, set: 2, async: 3, type: 4, as: 5 };
assert(obj.get + obj.set + obj.async + obj.type + obj.as === 15, "type-only words as keys");

// Labels and object literals still own the ':' in their positions.
outer: for (const _ of [1]) {
  break outer;
}
const lit = { a: 1, b: { c: 2 } };
assert(lit.b.c === 2, "object literal");

// Class expressions, getters with types, computed and numeric members.
const K = class<T> implements Iterable<T> {
  static count: number = 0;
  0: string = "zero";
  "quoted-name": number = 1;
  [Symbol.iterator](): Iterator<T> {
    return [][Symbol.iterator]();
  }
  get value(): T | undefined {
    return undefined;
  }
  set value(v: T | undefined) {}
};
const k = new K<number>();
assert(k[0] === "zero" && k["quoted-name"] === 1, "odd member names");
assert(k.value === undefined, "typed accessor pair");

console.log("ok");
