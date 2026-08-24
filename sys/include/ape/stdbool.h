#ifndef __STDBOOL_H__
#define __STDBOOL_H__

/*
 * pcc/kencc treats both `_Bool` (C99) and `bool` (C23) as built-in
 * type keywords mapped to unsigned char — see sys/src/cmd/cc/lex.c.
 * So this header does NOT need to '#define bool _Bool': doing so
 * would introduce a token-substitution round where a cast like
 * '(bool)expr' turned into '(_Bool)expr' after expansion. In some
 * macro contexts (e.g. gnulib's ckd_mul, which is
 * '((bool) _GL_INT_MULTIPLY_WRAPV(...))'), pcc then emitted _Bool
 * as an external symbol reference from the .o file, causing a
 * link-time 'undefined: _Bool' error. Using pcc's own `bool`
 * keyword directly avoids the round-trip.
 */

#define true  1
#define false 0
#define __bool_true_false_are_defined 1

#endif
