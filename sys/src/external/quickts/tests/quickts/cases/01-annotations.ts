// Type annotations in every binding position.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

const answer: number = 42;
let name: string = "frameos", count: number = 3;
let missing: number | undefined;
var legacy: Array<Record<string, number[]>> = [];
let definite!: string;
definite = "set";

assert(answer === 42, "const annotation");
assert(name === "frameos" && count === 3, "multiple declarators");
assert(missing === undefined, "annotation without initializer");
assert(legacy.length === 0, "generic annotation");
assert(definite === "set", "definite assignment");

function add(a: number, b: number = 2, ...rest: number[]): number {
  return a + b + rest.length;
}
assert(add(1) === 3, "default after annotation");
assert(add(1, 1, 9, 9) === 4, "rest annotation");

function optional(a: number, b?: string): number {
  return b === undefined ? a : a + b.length;
}
assert(optional(1) === 1, "optional parameter");
assert(optional(1, "xx") === 3, "optional parameter given");

const destructured = ({ count, label = "x" }: { count: number; label?: string }): string =>
  label + count;
assert(destructured({ count: 2 }) === "x2", "annotated destructured parameter");

const [first, second]: number[] = [10, 20];
assert(first + second === 30, "annotated array pattern");
const { a, b }: { a: number; b: number } = { a: 1, b: 2 };
assert(a + b === 3, "annotated object pattern");

// `this` parameter is type-only and must not become an argument.
function withThis(this: { v: number }, extra: number): number {
  return this.v + extra;
}
assert(withThis.length === 1, "this parameter is not an argument");
assert(withThis.call({ v: 1 }, 2) === 3, "this parameter call");

// Function types, unions, conditionals, keyof, tuples, template literal types.
type Handler = (event: { kind: "tick" | "tock" }, n?: number) => void;
type Keys = keyof { a: 1; b: 2 };
type Cond<T> = T extends string ? number : boolean;
type Tuple = [name: string, value?: number, ...rest: boolean[]];
type Tmpl = `on${Capitalize<string>}`;
type Nested = Map<string, Array<Record<string, Set<number>>>>;
type Fn = <T>(x: T) => T;
type Ctor = new (x: number) => object;
type Idx = Nested["size"];
const noop: Handler = () => {};
noop({ kind: "tick" });

console.log("ok");
