// Type parameters at declarations and call sites.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

function identity<T>(value: T): T {
  return value;
}
assert(identity<number>(5) === 5, "explicit call type argument");
assert(identity(5) === 5, "inferred call");

function pair<A, B extends keyof any>(a: A, b: B): [A, B] {
  return [a, b];
}
assert(pair<number, string>(1, "x")[1] === "x", "two type arguments");
assert(identity<Map<string, Array<number>>>(new Map()).size === 0, "nested type arguments");

const arrow = <T>(value: T): T => value;
assert(arrow(7) === 7, "generic arrow");
const arrow2 = <T, U>(a: T, b: U): U => b;
assert(arrow2(1, "b") === "b", "generic arrow, two params");

class Box<T> {
  value: T;
  constructor(value: T) {
    this.value = value;
  }
  map<U>(fn: (v: T) => U): Box<U> {
    return new Box<U>(fn(this.value));
  }
}
assert(new Box<number>(3).map<string>((v) => String(v)).value === "3", "generic class");

interface Shape { area(): number }
class Square extends Box<number> implements Shape {
  area(): number {
    return this.value * this.value;
  }
}
assert(new Square(4).area() === 16, "extends generic, implements");

// Tagged template with type arguments.
function tag<T>(strings: TemplateStringsArray, ...values: T[]): string {
  return strings.join("|") + values.length;
}
assert(tag<number>`a${1}b` === "a|b1", "generic tagged template");

console.log("ok");
