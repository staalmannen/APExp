// Type-only declarations must disappear entirely.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

interface Point {
  x: number;
  y?: number;
  readonly z: number;
  method(a: string): void;
  new (a: number): Point;
  [key: string]: unknown;
}

interface Generic<T extends { id: string }> extends Point {
  items: T[];
}

type Alias = Point | Generic<{ id: string }>;
type Mapped<T> = { [K in keyof T]?: T[K] };
type Deep = Mapped<Record<string, Array<Map<string, number>>>>;

declare const ambient: number;
declare function ambientFn(a: string): void;
declare class AmbientClass { x: number }
declare global {
  interface Window { frameos: unknown }
}

namespace Types {
  export interface Inner { a: number }
}

// `type` and `interface` are contextual: still usable as plain identifiers.
const type = 5;
assert(type === 5, "`type` as an identifier");
const obj = { type: "x", interface: "y", declare: 1, namespace: 2 };
assert(obj.type === "x" && obj.interface === "y", "reserved-ish object keys");
let typeAlias = 1;
typeAlias = typeAlias + 1;
assert(typeAlias === 2, "`type` prefixed identifier");

// A statement that merely starts with `type` and is not a type alias.
type;
assert(true, "bare identifier statement");

console.log("ok");
