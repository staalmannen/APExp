// A .tsx scene app: TypeScript and JSX in one file, exported as an ES
// module, the shape app_runtime.nim feeds to evalModuleNamespace.
export {};

const __frameosFragment = Symbol("fragment");
const __frameosJsx = (type: unknown, props: any, ...children: unknown[]) => {
  const nextProps = props ? { ...props } : {};
  if (children.length === 1) nextProps.children = children[0];
  else if (children.length > 1) nextProps.children = children;
  if (type === __frameosFragment) return nextProps.children ?? null;
  return { type, props: nextProps };
};

interface FrameOSApp {
  config: { width: number; height: number; label?: string };
}

type Point = { x: number; y: number };

enum Align {
  Left,
  Center,
  Right,
}

const OFFSETS: Record<string, number> = { left: 0, center: 1, right: 2 };

function place(p: Point, align: Align = Align.Center): Point {
  return { x: p.x + align, y: p.y } satisfies Point;
}

class Layout {
  constructor(
    public readonly width: number,
    private readonly height: number,
  ) {}
  box<T extends { x: number }>(item: T): T {
    return item;
  }
  get area(): number {
    return this.width * this.height;
  }
}

const Row = ({ label, value }: { label: string; value: number }) => (
  <g class="row">
    <text x={0}>{label}</text>
    <text x={100}>{String(value)}</text>
  </g>
);

export function get(app: FrameOSApp, context?: unknown) {
  const layout = new Layout(app.config.width, app.config.height);
  const p = place({ x: 1, y: 2 }, Align.Right);
  return (
    <svg width={layout.width} height={app.config.height}>
      <>
        <Row label={app.config.label ?? "none"} value={p.x} />
        {[1, 2].map((n) => (
          <Row key={n} label={`row ${n}`} value={n} />
        ))}
      </>
      {layout.area > 0 ? <rect fill="#fff" /> : null}
    </svg>
  );
}

const out = get({ config: { width: 4, height: 5, label: "hi" } }) as any;
if (out.type !== "svg") throw new Error("root tag");
if (out.props.width !== 4 || out.props.height !== 5) throw new Error("root props");
const [fragment, rect] = out.props.children;
if (fragment.length !== 2) throw new Error("fragment children");
if (fragment[0].type !== Row) throw new Error("component child");
if (fragment[0].props.value !== 3) throw new Error("enum value through place()");
if (fragment[1].length !== 2) throw new Error("mapped children");
if (fragment[1][1].props.label !== "row 2") throw new Error("template literal prop");
if (rect.type !== "rect" || rect.props.fill !== "#fff") throw new Error("ternary child");
if (OFFSETS.center !== 1) throw new Error("record annotation");
if (Align[2] !== "Right") throw new Error("enum reverse mapping");

console.log("ok");
