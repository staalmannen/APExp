;;;; gobble.scm
;
; usage: csi -s gobble.scm [COUNT]


(define (run n)
  (print "allocating " n " bytes ...")
  (let loop ((k 0))
    (when (< k n)
      (let ((x (make-string 1000)))
	(when (and (zero? (modulo k 100000)) (##sys#debug-mode?))
	  (print* "."))
	(loop (+ k 1000))))))

(run (string->number (optional (command-line-arguments) "1000000000")))
(newline)


; time csi -s gobble.scm 1000000000
;   5 secs
;
; csc goobble.scm -o a.out -O4 -b -d0
; time a.out 1000000000
;   3 secs
;
; (x86, Core2 Duo, 2.4Ghz, 2GB RAM)
