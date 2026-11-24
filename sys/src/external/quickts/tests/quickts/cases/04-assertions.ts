// as / satisfies / non-null assertions.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

const n = 1 as number;
assert(n === 1, "as");
const u = "x" as unknown as { length: number };
assert(u.length === 1, "chained as");
const s = { a: 1 } satisfies { a: number };
assert(s.a === 1, "satisfies");
const c = 1 as const;
assert(c === 1, "as const");
const arr = [1, 2, 3] as ReadonlyArray<number>;
assert(arr.length === 3, "as with type arguments");
const fn = ((x: number) => x) as (x: number) => number;
assert(fn(2) === 2, "as function type");

// `as` binds tighter than the logical operators and looser than `+`.
assert(((1 + 1) as number) === 2, "as precedence");
assert((1 as number) + 1 === 2, "as then plus");
assert(((false as boolean) || true) === true, "as then or");

const maybe: { v?: { w: number } } = { v: { w: 5 } };
assert(maybe.v!.w === 5, "non-null assertion");
assert(maybe!.v!.w === 5, "repeated non-null assertion");
const list: number[] | undefined = [1];
assert(list![0] === 1, "non-null before index");

// `as` and `satisfies` are still ordinary identifiers.
const as = 3;
const satisfies = 4;
assert(as + satisfies === 7, "as/satisfies as identifiers");
const keyed = { as: 1, satisfies: 2 };
assert(keyed.as === 1 && keyed.satisfies === 2, "as/satisfies as keys");

console.log("ok");
