// Plain JavaScript whose meaning must not change under the TS parser.
// The runner executes this file twice: once as .js (no TS flag) and once
// renamed to .ts (TS flag on). Both must print `ok`.
function assert(cond, msg) {
  if (!cond) throw new Error(msg);
}

// '<' and '>' as comparisons, including the shapes a naive type-argument
// scanner turns into generics.
var a = 1, b = 2, c = 3;
assert((a < b) === true, "less than");
assert((a < b > c) === false, "a < b > c");
assert(a < b === true, "chained comparison");
var f = function (x) { return x; };
assert((f < a) === false, "identifier < identifier");
assert((a < b, c) === 3, "comma after comparison");

// NOTE: `f < a > (b)` is *not* here. Under the TS parser it reads as the
// generic call `f<a>(b)` -- see xfail/js-generic-call-ambiguity.ts. tsc does
// the same thing, so this is a TypeScript divergence from JavaScript, not a
// quickts bug.

// Conditional expressions whose branches are parenthesised, with and
// without an arrow after them.
var cond = true;
assert((cond ? (a) : (b)) === 1, "ternary with parenthesised branches");
var h = cond ? (a) : (x) => x;
assert(h === 1, "ternary whose else branch is an arrow");
var k = !cond ? (a) : (x) => x + 1;
assert(k(1) === 2, "ternary taking the arrow branch");

// Arrow functions of every shape.
assert(((x) => x)(1) === 1, "paren arrow");
assert((x => x)(1) === 1, "bare arrow");
assert((() => 5)() === 5, "empty arrow");
assert((({ x }) => x)({ x: 2 }) === 2, "destructured arrow");
assert((([x, y]) => x + y)([1, 2]) === 3, "array pattern arrow");
assert((async (x) => x)(1) instanceof Promise, "async arrow");
assert(((x = 1) => x)() === 1, "arrow with default");

// Non-null-ish '!' must still be logical not.
assert(!a === false, "logical not");
assert(a != b, "not equal");
assert(a !== b, "strict not equal");
var m = { v: 1 };
assert(!m.v === false, "not on member");

// Regex literals containing angle brackets and colons.
assert(String("a<b>c").replace(/[<>]/g, "") === "abc", "regex with angle brackets");
assert(/a:b/.test("a:b"), "regex with colon");
assert((a / b / c) > 0, "division chain");

// Labels, object literals and `case` all use ':'.
outer: for (var i = 0; i < 2; i++) {
  for (var j = 0; j < 2; j++) {
    if (j === 1) continue outer;
  }
}
var obj = { a: 1, "b": 2, 3: 4, [`c`]: 5, get d() { return 6; } };
assert(obj.a + obj.b + obj[3] + obj.c + obj.d === 18, "object literal colons");
switch (a) {
  case 1:
    break;
  default:
    throw new Error("switch");
}

// Words quickts treats as contextual keywords, used as plain identifiers.
var type = 1, as = 2, is = 3, keyof = 4, infer = 5, declare = 6, namespace = 7;
var satisfies = 8, readonly = 9, override = 10, abstract = 11, module = 12;
assert(type + as + is + keyof + infer + declare + namespace === 28, "contextual words");
assert(satisfies + readonly + override + abstract + module === 50, "more contextual words");
var iface = { type: 1, as: 2, satisfies: 3, declare: 4 };
assert(iface.type + iface.as + iface.satisfies + iface.declare === 10, "as object keys");
assert(type < as, "contextual word comparison");

// A statement starting with a contextual keyword.
type = 2;
assert(type === 2, "assignment to `type`");
declare
assert(declare === 6, "bare `declare` statement");

// Optional chaining and nullish, which share '?' and '!' territory.
var opt = { x: { y: 1 } };
assert(opt?.x?.y === 1, "optional chaining");
assert(opt?.z?.y === undefined, "optional chaining miss");
assert((opt.z ?? 7) === 7, "nullish coalescing");
assert((cond ? 1 : 2) === 1, "plain ternary");

// Template literals with holes that contain colons and angle brackets.
var t = `x${cond ? "a:b" : "c"}${a < b ? "<" : ">"}`;
assert(t === "xa:b<", "template literal");

// Generators, async, classes, getters, computed members.
function* gen() { yield 1; }
assert(gen().next().value === 1, "generator");
class C {
  static s = 1;
  #p = 2;
  get v() { return this.#p; }
  static { C.s = 3; }
}
assert(new C().v === 2 && C.s === 3, "class features");

console.log("ok");
