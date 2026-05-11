(import (chicken compiler support))

(define +invalid-ids+
  '("-foo"
    "foo?"
    "7foo"
    "foo-bar"
    "ba!r"
    "foo$"))

(for-each
  (lambda (x)
    (assert (not (valid-c-identifier? x)) "invalid C identifier" x))
  +invalid-ids+)
