(module sample-module (foo)
(import scheme)
(import (srfi 9))  ; ensure builtin feature doesn't appear in .link file
(define foo 42))
