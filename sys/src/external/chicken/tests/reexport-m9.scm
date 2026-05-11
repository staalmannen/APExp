(module reexport-m9 (define)
  (import (only scheme define-syntax syntax-rules) (only (chicken base) error))
  (define-syntax define
    (syntax-rules ()
      ((_ a b)
       (error "wrong define!")))))
