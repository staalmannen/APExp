/* stdio.c — intentionally empty.
 *
 * stdin, stdout, stderr are defined in stdin.c, stdout.c, stderr.c
 * (the musl-derived separate-file layout).  This file previously held
 * duplicate definitions with .buf = NULL which caused a null-pointer
 * dereference in __towrite() on the first write to stdout/stderr.
 */
