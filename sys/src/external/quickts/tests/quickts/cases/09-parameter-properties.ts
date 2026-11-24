// Constructor parameter properties: the one construct here that emits code
// instead of erasing it. Assignments land at the top of a base-class
// constructor and immediately after `super(...)` in a derived one.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

class Point {
  constructor(
    public x: number,
    private readonly y: number = 2,
    protected z?: number,
  ) {}
  sum(): number {
    return this.x + this.y + (this.z ?? 0);
  }
}
assert(new Point(1).sum() === 3, "base class parameter properties");
assert(new Point(1, 2, 3).sum() === 6, "all three given");
assert(new Point(1).x === 1, "public parameter property is a real field");
// `length` counts parameters before the first default, exactly as it would
// for the plain-JavaScript constructor tsc emits.
assert(Point.length === 1, "arity unchanged");

class Base3 {
  constructor(public base: string) {}
}
class Derived3 extends Base3 {
  constructor(
    base: string,
    public readonly extra: number,
  ) {
    super(base);
  }
}
const d = new Derived3("b", 7);
assert(d.base === "b" && d.extra === 7, "derived class, assignments after super()");

// Ordinary parameters mixed in, and modifier words used as parameter names.
class Mixed {
  value: number;
  constructor(
    plain: number,
    public tagged: number,
    { from }: { from: number },
  ) {
    this.value = plain + from;
  }
}
const m = new Mixed(1, 2, { from: 3 });
assert(m.value === 4 && m.tagged === 2, "mixed parameter list");

class NamedLikeModifiers {
  constructor(
    readonly: number,
    priv: number,
  ) {
    this.total = readonly + priv;
  }
  total: number;
}
assert(new NamedLikeModifiers(1, 2).total === 3, "`readonly` as a parameter name");

console.log("ok");
