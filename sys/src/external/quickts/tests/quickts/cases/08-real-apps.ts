// Three real FrameOS scene apps (tests/quickts/samples), the largest of which
// is the 36 KB module whose on-device transpile motivated quickts. Parsed and
// evaluated straight from .ts.
import * as panel from "../samples/weather_panel.ts";
import * as icons from "../samples/weather_icons.ts";
import * as sheet from "../samples/icon_sheet.ts";

if (typeof panel.get !== "function") throw new Error("weather_panel.get");
if (typeof icons.get !== "function") throw new Error("weather_icons.get");
if (typeof sheet.get !== "function") throw new Error("icon_sheet.get");
console.log("ok");
