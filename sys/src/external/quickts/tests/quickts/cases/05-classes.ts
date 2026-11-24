// Class members: modifiers, optional/definite markers, index signatures.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

interface Named { readonly label: string }

abstract class Base<T> implements Named {
  public readonly label: string = "base";
  protected value?: T;
  private secret!: number;
  static count: number = 0;
  static readonly kind: string = "base";
  declare marker: symbol;
  #hidden: number = 1;
  [key: string]: unknown;

  constructor(value?: T) {
    this.value = value;
    this.secret = 1;
    Base.count++;
  }

  protected get current(): T | undefined {
    return this.value;
  }
  protected set current(v: T | undefined) {
    this.value = v;
  }

  public describe<U extends string>(prefix: U): string {
    return prefix + this.label + this.#hidden;
  }

  static make<T>(v: T): Base<T> {
    return new Derived<T>(v);
  }
}

class Derived<T> extends Base<T> {
  override readonly label: string = "derived";
  override describe(prefix: string): string {
    return "d:" + super.describe(prefix);
  }
}

const d = new Derived<number>(5);
assert(d.label === "derived", "override field");
assert(d.describe("x") === "d:xderived1", "override method + private field");
assert(Base.count === 1, "static field");
assert(Base.kind === "base", "static readonly");
assert((Base.make<number>(2) as Derived<number>).label === "derived", "static generic method");

// `public` / `private` / `readonly` are still legal member names.
class Names {
  public = 1;
  private = 2;
  readonly = 3;
  declare = 4;
  static = 5;
  abstract = 6;
  override() {
    return 7;
  }
  type = 8;
}
const names = new Names();
assert(names.public + names.private + names.readonly === 6, "modifier words as fields");
assert(names.declare + names.static + names.abstract === 15, "more modifier words");
assert(names.override() === 7, "modifier word as method");
assert(names.type === 8, "type as field");

// Class expressions and accessors keep working.
const Anon = class<T> {
  x: T;
  constructor(x: T) {
    this.x = x;
  }
};
assert(new Anon<number>(9).x === 9, "generic class expression");

console.log("ok");
