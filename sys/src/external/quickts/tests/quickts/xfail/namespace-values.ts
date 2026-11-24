// GAP: a namespace that declares values lowers to an IIFE plus a merged
// object, which quickts does not build. It is *rejected* rather than erased,
// so this file fails to compile instead of silently losing Util.VERSION --
// a wrong answer on a frame is worse than a failed deploy. A type-only or
// `declare` namespace still erases cleanly (cases/02-type-decls.ts).
namespace Util {
  export const VERSION = 1;
  export function twice(n: number): number {
    return n * 2;
  }
}
if (Util.VERSION !== 1 || Util.twice(2) !== 4) throw new Error("namespace values");
console.log("ok");
