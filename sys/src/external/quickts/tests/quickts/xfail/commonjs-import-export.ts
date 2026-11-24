// UNSUPPORTED: the CommonJS-flavoured `import x = require("m")` and
// `export = x`. quickts only knows ES modules, which is all QuickJS itself
// loads. Use `import x from "m"` / `export default x`.
import fs = require("fs");
export = fs;
