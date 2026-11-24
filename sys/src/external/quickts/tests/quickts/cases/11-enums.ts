// TypeScript enums. Not erasure: an object with a reverse mapping, plus a
// block scope so a later member can refer to an earlier one by name.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

enum Color {
  Red,
  Green = 4,
  Blue,
}
assert(Color.Red === 0, "implicit first value");
assert(Color.Green === 4, "explicit value");
assert(Color.Blue === 5, "auto-increment after an explicit value");
assert(Color[0] === "Red" && Color[4] === "Green" && Color[5] === "Blue", "reverse mapping");
assert(typeof Color === "object", "the enum is an object");
assert(Object.keys(Color).length === 6, "three forward and three reverse keys");

enum Named {
  A = "a",
  B = "b",
}
assert(Named.A === "a" && Named.B === "b", "string enum");
assert(Named["a"] === undefined, "string members get no reverse mapping");
assert(Object.keys(Named).length === 2, "string enum has two keys");

// A member can reference an earlier one by bare name; tsc resolves that to
// `E.A`, quickts binds each member as a const in a block scope.
enum Flags {
  None = 0,
  Read = 1,
  Write = Read << 1,
  All = Read | Write,
}
assert(Flags.Write === 2 && Flags.All === 3, "computed members");
assert(Flags[2] === "Write", "reverse mapping for computed members");

// The counter survives a non-constant member by reading the value back.
const four = 2 + 2;
enum Mixed {
  A = four,
  B,
  C,
}
assert(Mixed.A === 4 && Mixed.B === 5 && Mixed.C === 6, "auto-increment after an expression");

// Names that are not identifiers, and keywords.
enum Odd {
  "with dash" = 1,
  default = 2,
  "3d" = 3,
}
assert(Odd["with dash"] === 1, "string member name");
assert(Odd.default === 2, "keyword member name");
assert(Odd[3] === "3d", "reverse mapping for a string name");

// `const enum` is treated as an ordinary enum (no inlining at use sites).
const enum Small {
  X = 7,
}
assert(Small.X === 7, "const enum");

// Trailing comma, single member, empty body.
enum One {
  Only,
}
enum Empty {}
assert(One.Only === 0, "single member");
assert(Object.keys(Empty).length === 0, "empty enum");

// The member consts do not leak into the enclosing scope.
assert(typeof globalThis["Red"] === "undefined", "member names stay scoped");

// `enum` is a reserved word, so it cannot collide with a variable name.
declare enum Ambient {
  Q = 1,
}

console.log("ok");
