// JSX lowering. The factory names and semantics are FrameOS's own
// __frameosJsx / __frameosFragment (js_runtime/runtime.nim), reproduced here
// so the test checks the same shape the scene runtime consumes.
function assert(cond: boolean, msg: string): void {
  if (!cond) throw new Error(msg);
}

const __frameosFragment = Symbol("fragment");
const __frameosNormalizeChildren = (children: unknown[]) => {
  if (children.length === 0) return undefined;
  if (children.length === 1) return children[0];
  return children;
};
const __frameosJsx = (type: unknown, props: any, ...children: unknown[]) => {
  const nextProps = props ? { ...props } : {};
  const explicitChildren = __frameosNormalizeChildren(children);
  const propChildren = Object.prototype.hasOwnProperty.call(nextProps, "children")
    ? nextProps.children
    : undefined;
  if (Object.prototype.hasOwnProperty.call(nextProps, "children")) {
    delete nextProps.children;
  }
  const normalizedChildren = explicitChildren ?? propChildren;
  if (type === __frameosFragment) {
    return normalizedChildren ?? null;
  }
  if (normalizedChildren !== undefined) {
    nextProps.children = normalizedChildren;
  }
  return { type, props: nextProps };
};

// --- lower-case tags become strings, capitalised ones stay expressions -----
const plain = <image />;
assert(plain.type === "image", "lower-case tag is a string");
assert(Object.keys(plain.props).length === 0, "no props");

const Card = (props: any) => ({ card: props });
const component = <Card width={3} />;
assert(component.type === Card, "capitalised tag is an expression");
assert(component.props.width === 3, "expression prop");

const Ns = { Inner: (p: any) => p };
const dotted = <Ns.Inner a={1} />;
assert(dotted.type === Ns.Inner, "dotted tag name");

const dashed = <my-widget />;
assert(dashed.type === "my-widget", "dashed tag is a string");
const colon = <svg:rect />;
assert(colon.type === "svg:rect", "namespaced tag is a string");

// --- props ----------------------------------------------------------------
const input = 5;
const props = <box active={input > 0} label="hi" flag stringy={"s"} n={1 + 1} />;
assert(props.props.active === true, "expression prop");
assert(props.props.label === "hi", "string prop");
assert(props.props.flag === true, "bare prop");
assert(props.props.stringy === "s", "string expression prop");
assert(props.props.n === 2, "computed prop");

const extra = { a: 1, b: 2 };
const spread = <box {...extra} c={3} />;
assert(spread.props.a === 1 && spread.props.b === 2 && spread.props.c === 3, "spread props");
const overridden = <box a={9} {...extra} />;
assert(overridden.props.a === 1, "later spread wins");

const dashedProp = <box data-id="x" aria-label="y" xlink:href="z" />;
assert(dashedProp.props["data-id"] === "x", "dashed prop name");
assert(dashedProp.props["aria-label"] === "y", "another dashed prop");
assert(dashedProp.props["xlink:href"] === "z", "namespaced prop name");

const nestedAttr = <box icon=<i /> />;
assert(nestedAttr.props.icon.type === "i", "element-valued attribute");

// --- children -------------------------------------------------------------
const one = <box>{input}</box>;
assert(one.props.children === 5, "single expression child");

const text = <box>hello world</box>;
assert(text.props.children === "hello world", "text child");

const multiline = (
  <box>
    first
    second
  </box>
);
assert(multiline.props.children === "first second", "multiline text is joined");

// Whitespace, as TypeScript and Babel read it: only what touches a line break
// goes; a run with no break keeps its edges.
const after = <box>{input} items</box>;
assert(after.props.children[1] === " items", "space after an expression is kept");
const before = <box>items {input}</box>;
assert(before.props.children[0] === "items ", "space before an expression is kept");
const between = <box><a /> <b /></box>;
assert(between.props.children.length === 3 && between.props.children[1] === " ",
  "space between two elements on a line is kept");
const afterElement = <box><b>bold</b> text</box>;
assert(afterElement.props.children[1] === " text", "space after an element is kept");
const padded = <box> x </box>;
assert(padded.props.children === " x ", "a single-line run keeps its edges");
const lines = (
  <box>
    a {input}
    b
  </box>
);
assert(lines.props.children[0] === "a " && lines.props.children[2] === "b",
  "whitespace touching a line break goes");
const firstLine = <box>  first
  second</box>;
assert(firstLine.props.children === "  first second", "the first line keeps its leading whitespace");
const lastLine = <box>
  last  </box>;
assert(lastLine.props.children === "last  ", "the last line keeps its trailing whitespace");
const stacked = (
  <box>
    <a />
    <b />
  </box>
);
assert(stacked.props.children.length === 2, "indentation between lines is not a child");

const mixed = <box>a{input}b</box>;
assert(mixed.props.children.length === 3, "three children");
assert(mixed.props.children[0] === "a" && mixed.props.children[1] === 5, "child order");

const nested = (
  <outer>
    <inner x={1} />
    <inner x={2} />
  </outer>
);
assert(nested.props.children.length === 2, "two element children");
assert(nested.props.children[1].props.x === 2, "nested element props");

const empty = <box>{}</box>;
assert(empty.props.children === undefined, "empty expression child is dropped");

const blank = <box>{/* just a comment */}</box>;
assert(blank.props.children === undefined, "comment-only child is dropped");

// --- fragments ------------------------------------------------------------
const frag = <>{input}</>;
assert(frag === 5, "fragment with one child");
const frag2 = (
  <>
    <a />
    <b />
  </>
);
assert(frag2.length === 2, "fragment with two children");

// --- entities -------------------------------------------------------------
const entities = <box title="Tom &amp; Jerry">A &lt; B &amp; C&#33;</box>;
assert(entities.props.title === "Tom & Jerry", "entity in an attribute");
assert(entities.props.children === "A < B & C!", "entities in text");
const unicode = <box>{"x"}&#x2713;</box>;
assert(unicode.props.children[1] === "✓", "hex entity");

// --- JSX inside ordinary JavaScript ---------------------------------------
function render(n: number) {
  if (n > 1) return <big value={n} />;
  return <small value={n} />;
}
assert(render(2).type === "big" && render(0).props.value === 0, "JSX in a function");

const list = [1, 2].map((n) => <li key={n}>{n}</li>);
assert(list.length === 2 && list[1].props.children === 2, "JSX in a callback");

const ternary = input > 0 ? <yes /> : <no />;
assert(ternary.type === "yes", "JSX in a ternary");

const inObject = { node: <box />, n: 1 };
assert(inObject.node.type === "box", "JSX as an object value");

// A comparison must still be a comparison in a .tsx file.
const a = 1, b = 2;
assert((a < b) === true, "less-than still works");

console.log("ok");
