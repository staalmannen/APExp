;;;; scrutinizer-tests in "strict-types" mode


;;; #896: internal error due to missing resolution of type-variables
;;;       in "initial-argument-types" (scrutinizer.scm)
;;;       (reported by Moritz)

(define-record bar foo)

(define-type bar
  (struct bar))

;; This breaks with csc -strict-types
(: foo (forall (x string) (x -> bar)))

;; Using this declaration instead of the above makes it work
;; (: foo (string -> bar))

;; Alternatively, removing this declaration makes it work, too
(: make-bar (string -> bar))

(define (foo x) (make-bar x))

