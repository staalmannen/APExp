(module reverser *
  (import scheme (chicken base))
  (define rev-version 1.1)

  (define (string-reverse s)
    (let* ((len (string-length s))
	   (ans (make-string len)))
      (do ((i 0 (+ i 1))
	   (j (- len 1) (- j 1)))
	  ((< j 0))
	(string-set! ans j (string-ref s i)))
      ans))

  (define (rev x)
    (cond ((string? x) (string-reverse x))
	  ((symbol? x) (string->symbol (rev (symbol->string x))))
	  ((list? x) (reverse x))
	  ((vector? x) (list->vector (rev (vector->list x))))
	  (else (error "can't reverse" x)))))
