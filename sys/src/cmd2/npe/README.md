# npe

"Native Porting Environment" for 9front, pronounced "nope".

The project tries to provide a minimalistic (and mostly
non-conformant) POSIX environment with several additional libraries to
ease up porting of software to 9front.  The goal is to be able to
build and run non-native GUI software with very minimal changes, if
any.

Unlike APE, NPE is fully native and is not trying to hide any of the
native Plan 9 APIs.

## Status

* Some POSIX stuff is available
* SDL2 basics (video, audio, input, events)
* pthread basics

## Using NPE

Clone, run `mk install`.

Create a `mkfile` for the software to be built, and set `CFLAGS`:

	CFLAGS=$CFLAGS -p -I/sys/include/npe -D__plan9__ -D__${objtype}__

By default npe will override the `main` function with its own
`threadmain`.  If that behaviour isn't desired, add
`-D__plan9_keep_main__` to `CFLAGS`.

Stack size is set to 256k.

[General porting guide](http://docs.9front.org/porting).

## Helping out

Patches and bug reports are always welcome.

	g FIXME
