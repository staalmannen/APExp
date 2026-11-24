// GAP: decorators. Not TypeScript-specific any more (they are a stage-3
// proposal QuickJS 2026-06-04 does not implement), so this one is a QuickJS
// feature request rather than a quickts one.
function log(target: unknown, ctx: unknown): void {}

class Service {
  @log
  run(): number {
    return 1;
  }
}
if (new Service().run() !== 1) throw new Error("decorators");
console.log("ok");
