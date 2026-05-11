;;;; pp-test.scm

(import (only chicken.pretty-print pp)
        (only chicken.port with-output-to-string)
	(only (chicken memory representation) block-ref))

(define (pp->string thing)
  (with-output-to-string (cut pp thing)))

(define-syntax test 
  (syntax-rules ()
    ((_ result exp)
     (assert (equal? result exp)))))

(test "\"\\\"foo\\\"\"\n" (pp->string "\"foo\""))
(test "\"\\\\\\\"\"\n" (pp->string "\\\""))
(test "\"\\\\\\\\\\\\\\\"\"\n" (pp->string "\\\\\\\""))
(test "\"\\\"\\\"\\\"\"\n" (pp->string "\"\"\""))
(test "\"\\n\\t\\r\\b\\a\\v\\f\"\n" (pp->string "\n\t\r\b\a\v\f"))
(test "\\" "\\")                        ; XXX?
(test "#<unbound value>\n" (pp->string (block-ref 'aardvark 0))) ;; Shouldn't crash
