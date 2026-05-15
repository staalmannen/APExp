#ifndef __STDBOOL_H__
#define __STDBOOL_H__

/* _Bool is a built-in keyword in kencc (Plan9) and all C99 compilers.
 * No typedef needed — defining it would be a syntax error for kencc. */
#define bool _Bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#endif
