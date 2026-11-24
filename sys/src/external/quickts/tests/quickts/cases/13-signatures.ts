// Bodiless declarations: overload signatures, abstract members, `declare`
// fields. All of them are erased whole.
export {};
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

function pick(a: string): string;
function pick(a: number): number;
function pick(a: string | number): string | number {
  return a;
}
assert(pick(1) === 1 && pick("x") === "x", "function overloads");

export function exported(a: string): void;
export function exported(a: number): void;
export function exported(a: unknown): void {}
assert(typeof exported === "function", "exported overloads");

async function later(a: string): Promise<string>;
async function later(a: number): Promise<number>;
async function later(a: any): Promise<any> {
  return a;
}
assert(later(1) instanceof Promise, "async overloads");

// Overloads without semicolons, relying on the newline.
function noSemi(a: string): string
function noSemi(a: number): number
function noSemi(a: any) {
  return a;
}
assert(noSemi(2) === 2, "overloads without semicolons");

// Nested in a block, and inside another function.
function outer() {
  function inner(a: string): string;
  function inner(a: any): any {
    return a;
  }
  return inner("i");
}
assert(outer() === "i", "nested overloads");

class Repo {
  constructor(id: string);
  constructor(id: number);
  constructor(public id: string | number) {}

  find(id: string): string;
  find(id: number): string;
  find(id: string | number): string {
    return String(id);
  }

  static make(a: string): Repo;
  static make(a: number): Repo;
  static make(a: any): Repo {
    return new Repo(a);
  }

  async load(a: string): Promise<string>;
  async load(a: any): Promise<any> {
    return a;
  }

  get size(): number {
    return 1;
  }

  [Symbol.iterator](): Iterator<number>;
  *[Symbol.iterator](): Iterator<number> {
    yield 1;
  }

  // methods whose names are the accessor/async words themselves
  get(): string {
    return "get";
  }
  set(v: string): void {}
  async(): number {
    return 3;
  }
  private get secret(): number {
    return 9;
  }
}
const repo = new Repo(2);
assert(repo.find(2) === "2" && Repo.make("a").id === "a", "method overloads");
assert(repo.size === 1 && [...repo][0] === 1, "accessor and iterator signatures");
assert(repo.get() === "get" && repo.async() === 3, "get/async as method names");
assert(Object.getOwnPropertyNames(Repo.prototype).length === 8, "no phantom members");

abstract class Shape {
  abstract area(): number;
  abstract readonly kind: string;
  abstract get label(): string;
  declare cached: number;
  protected abstract describe(this: Shape): string
  describeTwice(): string {
    return this.describe() + this.describe();
  }
}
class Square extends Shape {
  readonly kind = "square";
  get label() {
    return "sq";
  }
  area() {
    return 4;
  }
  protected describe() {
    return this.kind;
  }
}
const sq = new Square();
assert(sq.area() === 4 && sq.describeTwice() === "squaresquare", "abstract methods erased");
assert(sq.label === "sq", "abstract accessor does not shadow the subclass getter");
assert(!Object.prototype.hasOwnProperty.call(sq, "cached"), "declare field defines nothing");
assert(!Object.prototype.hasOwnProperty.call(sq, "label"), "abstract field defines nothing");

console.log("ok");
