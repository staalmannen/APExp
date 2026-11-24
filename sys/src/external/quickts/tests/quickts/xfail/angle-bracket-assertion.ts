// GAP: the legacy `<T>value` assertion form. Unsupported on purpose -- it is
// unparseable alongside JSX, which FrameOS scene apps use, and `as` covers
// the same ground. tsc rejects it in .tsx files for the same reason.
const value: unknown = 1;
const n = <number>value;
if (n !== 1) throw new Error("angle bracket assertion");
console.log("ok");
