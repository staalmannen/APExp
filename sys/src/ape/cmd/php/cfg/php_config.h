/*
 * php_config.h -- the SHORT spelling.
 *
 * ***THE SAME FILE IS INCLUDED TWO WAYS AND BOTH HAVE TO WORK.***
 * `TSRM/TSRM.h:20' says `#include <main/php_config.h>' while
 * `Zend/zend_frameless_function.h' and `ext/opcache/zend_shared_alloc.c'
 * say `#include <php_config.h>'.  Upstream both resolve against the
 * php root, where the generated config really does live at
 * `main/php_config.h'.
 *
 * So the answers live in `cfg/main/php_config.h' and this is a
 * redirect, rather than a second copy that could drift from the
 * first.  *Two hand-maintained files that must agree are one file
 * too many* -- the same reason perl's `Config.pm' and its `config.h'
 * are called out in CLAUDE.md as a pair to keep in step.
 */
#include <main/php_config.h>
