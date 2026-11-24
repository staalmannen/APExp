#!/usr/bin/env python3
"""quickts test runner.

Every case is a self-checking file executed by `qjs`:

  cases/*.ts, *.tsx   TypeScript / TSX. Must run to completion and print `ok`.
  cases/*.js          Plain JavaScript run once as-is and once renamed to
                      .tsx (both erasure passes on), to prove the passes
                      never change JavaScript semantics.
  xfail/*.ts          Known, documented gaps. Must fail; the runner says if
                      one quietly starts passing.

    python3 tests/quickts/run.py [path/to/qjs]
"""

import os
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
QJS = sys.argv[1] if len(sys.argv) > 1 else os.path.join(HERE, "..", "..", "qjs")


def run(path):
    p = subprocess.run([QJS, path], capture_output=True, text=True, timeout=30)
    return p.returncode, (p.stdout + p.stderr).strip()


def main():
    cases = os.path.join(HERE, "cases")
    xfail = os.path.join(HERE, "xfail")
    passed = failed = 0
    failures = []

    for name in sorted(os.listdir(cases)):
        path = os.path.join(cases, name)
        if name.endswith(".js"):
            code_js, out_js = run(path)
            tmp = os.path.join(tempfile.mkdtemp(), name[:-3] + ".tsx")
            shutil.copyfile(path, tmp)
            code_ts, out_ts = run(tmp)
            if code_js == 0 and code_ts == 0 and out_js == out_ts == "ok":
                passed += 1
            else:
                failed += 1
                failures.append((name, "js=%r tsx=%r" % (out_js, out_ts)))
            continue
        if not (name.endswith(".ts") or name.endswith(".tsx") or name.endswith(".jsx")):
            continue
        code, out = run(path)
        if code == 0 and out == "ok":
            passed += 1
        else:
            failed += 1
            failures.append((name, out))

    print("quickts cases: %d passed, %d failed" % (passed, failed))
    for name, out in failures:
        print("  FAIL %s\n       %s" % (name, out.replace("\n", "\n       ")))

    if os.path.isdir(xfail):
        for name in sorted(os.listdir(xfail)):
            if not (name.endswith(".ts") or name.endswith(".tsx")):
                continue
            code, out = run(os.path.join(xfail, name))
            state = "still unsupported" if code != 0 or out != "ok" else "NOW PASSES -- move it to cases/"
            print("  xfail %-32s %s" % (name, state))
            if code == 0 and out == "ok":
                failed += 1

    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
