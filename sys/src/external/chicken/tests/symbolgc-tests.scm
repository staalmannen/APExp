;;;; symbolgc-tests.scm

(import (chicken gc) (chicken format) (chicken keyword))

;; Ensure counts are defined before creating the disposable symbols.
;; This way, this program can also be run in interpreted mode.
(define *count-before* #f)
(define *count-after* #f)

;; Force major GC to ensure there are no collectible symbols left
;; before we start, otherwise the GC might clean these up and we'd end
;; up with less symbols than we started with!
(gc #t)

(set! *count-before* (vector-ref (##sys#symbol-table-info) 2))

(print "starting with " *count-before* " symbols")

(print "interning 10000 symbols ...")

(do ((i 10000 (sub1 i)))
    ((zero? i))
  (string->symbol (sprintf "%%%~a%%%" i)))

(print "recovering ...")

;; Force major GC, which should reclaim every last symbol we just
;; created, as well as "i", the loop counter.
(gc #t)

;; Don't use LET, which would introduce a fresh identifier, which is a
;; new symbol (at least, in interpreted mode)
(set! *count-after* (vector-ref (##sys#symbol-table-info) 2))
(print (- *count-after* *count-before*) " newly interned symbols left")
(unless (= *count-after* *count-before*)
  (error "unable to reclaim all symbols"))

(print "interning 10000 keywords ...")

(do ((i 10000 (sub1 i)))
    ((zero? i))
  (string->keyword (sprintf "kw-%%%~a%%%" i)))

(print "recovering ...")
(gc #t)
(set! *count-after* (vector-ref (##sys#symbol-table-info) 2))
(print* (- *count-after* *count-before*) " newly interned leywords left")
(unless (= *count-after* *count-before*)
  (error "unable to reclaim all keywords"))

(print "\ndone.")
