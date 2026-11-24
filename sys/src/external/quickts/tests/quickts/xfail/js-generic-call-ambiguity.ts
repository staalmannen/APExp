// DIVERGENCE (not a bug): with TypeScript syntax enabled, `f < a > (b)` is
// the generic call `f<a>(b)`, so this file throws. tsc behaves identically;
// it is the one place where valid JavaScript changes meaning under a TS
// parser. It matters here because FrameOS scene apps are JavaScript that
// merely *may* be TypeScript -- see README.md, "What is not supported".
function f(x) {
  return 99;
}
const a = 1, b = 2;
// As JavaScript: (f < a) > b  ->  false > 2  ->  false.
// As TypeScript: f<a>(b)      ->  99.
const result = f < a > (b);
if (result !== false) throw new Error("read as a generic call: " + result);
console.log("ok");
