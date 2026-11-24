// UNSUPPORTED: the `accessor` field modifier (TypeScript 4.9), which lowers
// to a getter/setter pair over a private field. Not erasure, and rare in
// application code; write the accessor pair by hand.
class A {
  accessor x = 1;
}
if (new A().x !== 1) throw new Error("accessor");
console.log("ok");
