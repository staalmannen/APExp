// Type-only imports and exports, plus the shapes a FrameOS app module uses.
// Run as a module by QuickJS (JS_DetectModule sees the `export`).
import type { Something } from "./nowhere.ts";
import type Default from "./nowhere.ts";
import type * as Ns from "./nowhere.ts";

export type Exported = { a: number };
export interface ExportedIface {
  b: string;
}
export declare const ambient: number;

type Local = number;
export type { Local };

export const value: Local = 1;
export function get(app: { config: { n: number } }, context?: unknown): number {
  return app.config.n;
}
export default function main<T>(x: T): T {
  return x;
}
export const arrow = <T,>(x: T): T => x;
export class Widget<T> {
  constructor() {}
  render(): string {
    return "w";
  }
}

if (value !== 1) throw new Error("value");
if (get({ config: { n: 2 } }) !== 2) throw new Error("get");
if (main(3) !== 3) throw new Error("default export");
if (arrow(4) !== 4) throw new Error("exported generic arrow");
if (new Widget<number>().render() !== "w") throw new Error("exported generic class");
console.log("ok");
