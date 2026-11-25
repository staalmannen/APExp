/*
 * _cxxinit -- the no-op every C program links.
 *
 * `plan9/callmain.c' calls this between setting up the privates and
 * calling `main', so that a C++ program can run its static
 * constructors there.  See the comment at the call site for why the
 * hook exists at all.
 *
 * ***IT IS ALONE IN THIS FILE AND THAT IS THE WHOLE POINT.***  A
 * symbol `_apemain' references is in every APE binary, and so is the
 * WHOLE OBJECT that defines it -- which is how libap's allocator
 * once ended up linked into f2c, whose own `malloc' then collided.
 * An archive member is pulled only to satisfy something still
 * undefined, so when `eccp' puts its generated munch object on the
 * link line this file is never pulled at all; when nothing does,
 * one empty function is the entire cost.  *Define nothing else
 * here*: anything added becomes unreplaceable in every C program in
 * the tree, and silently absent from every C++ one.
 */

void
_cxxinit(void)
{
}
