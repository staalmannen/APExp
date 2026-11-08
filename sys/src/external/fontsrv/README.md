# fontsrv

`fontsrv` is a Plan 9 / Inferno-style **9P file server** that provides **filesystem access to scalable fonts** (via FreeType), exposing them in the standard Plan 9 font + subfont format.

By default it mounts a virtual font tree at `/mnt/font` and posts itself as the `font` service.

## What it serves

The exported filesystem is a two-level hierarchy:

- `/mnt/font/<fontname>/`
  - `<size>` directories for monochrome bitmaps (e.g. `13`)
  - `<size>a` directories for anti-aliased greyscale (e.g. `13a`)
    - `font` – a Plan 9 `font` file describing height/ascent and listing available subfonts
    - `x000000.bit`, `x000100.bit`, ... – subfont pages covering Unicode ranges

Sizes can be synthesized on demand: walking to (for example) `19a` will generate that size if possible.

## Usage

```sh
fontsrv [-m mtpt] [-s srvname]
```

- `-m mtpt` mountpoint (default: `/mnt/font`)
- `-s srvname` posted service name (default: `font`)

### Examples

List available fonts:

```sh
% fontsrv
% ls /mnt/font/
```

Run `acme` using Monaco as fixed-width font:

```sh
% acme -F /mnt/font/Monaco/13a/font
```

Run `sam` using the same font:

```sh
% font=/mnt/font/Monaco/13a/font sam
```

## Configuration: `/sys/lib/fontsrv.map`

`fontsrv` reads font definitions from:

- `/sys/lib/fontsrv.map`

The file is line-oriented. It supports either:

- `path/to/fontfile.ttf`
- `FontName path/to/fontfile.ttf`

Lines may include comments (`# ...`) when the `#` is at the start of the line or preceded by whitespace.

This repo includes an example map file at `lib/fontsrv`, and the top-level `mkfile` installs it as `/sys/lib/fontsrv.map`.

## Build (Plan 9 mk)

This repository is set up for Plan 9's `mk` build system.

Key files:

- `mkfile` – builds the `fontsrv` binary and the bundled FreeType library
- `libfreetype/` – vendored FreeType sources + `mkfile`

To build:

```sh
% mk
```

To install the binary, map file, and manpage:

```sh
% mk install
```

Installation copies:
- `lib/fontsrv` → `/sys/lib/fontsrv.map`
- `man/4/fontsrv.4` → `/sys/man/4/fontsrv.4`

## Implementation notes

- The 9P server is implemented in `fontsrv.c` (using `lib9p`), with a synthetic tree of Qids encoding:
  - which font
  - which point size
  - mono vs anti-aliased
  - which Unicode "page"
- FreeType rendering is handled in `freetype.c`, which:
  - discovers fonts from `/sys/lib/fontsrv.map`
  - lazily loads faces
  - renders glyph pages into `Memsubfont` objects on demand
- Subfont pages are served as `.bit` files named `x%06x.bit`, where the hex value is the start rune for that page.

## Limitations

- Bitmap-only fonts are not supported (the server requires scalable faces).
- Subpixel rendering is not available.
- Hinting heuristics may not always pick the best appearance for every font/size (see the manpage).

## See also

- `man/4/fontsrv.4`
- Plan 9 font format documentation (`font(7)`)
