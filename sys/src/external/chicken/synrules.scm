;; Copyright (c) 1993-2001 by Richard Kelsey and Jonathan Rees.
;; All rights reserved.

;; Redistribution and use in source and binary forms, with or without
;; modification, are permitted provided that the following conditions
;; are met:
;; 1. Redistributions of source code must retain the above copyright
;;    notice, this list of conditions and the following disclaimer.
;; 2. Redistributions in binary form must reproduce the above copyright
;;    notice, this list of conditions and the following disclaimer in the
;;    documentation and/or other materials provided with the distribution.
;; 3. The name of the authors may not be used to endorse or promote products
;;    derived from this software without specific prior written permission.

;; THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
;; IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
;; OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
;; IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,
;; INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
;; NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
;; DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
;; THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

; The syntax-rules macro (new in R5RS)

;;; [Hacked slightly by Taylor R. Campbell to make it work in his
;;; macro expander `riaxpander'.]

;; [Hacked even more by Felix L. Winkelmann to make it work in his
;; Hi-Lo expander]

; Example:
;
; (define-syntax or
;   (syntax-rules ()
;     ((or)          #f)
;     ((or e)        e)
;     ((or e1 e ...) (let ((temp e1))
;		       (if temp temp (or e ...))))))

(##sys#extend-macro-environment
 'syntax-rules
 '()
 (##sys#er-transformer
  (lambda (exp r c)
    (##sys#check-syntax 'syntax-rules exp '#(_ 2))
    (let ((subkeywords (cadr exp))
	  (rules (cddr exp))
	  (ellipsis '...))
      (when (symbol? subkeywords)
	(##sys#check-syntax 'syntax-rules exp '(_ _ list . #(_ 0)))
	(set! ellipsis subkeywords)
	(set! subkeywords (car rules))
	(set! rules (cdr rules)))
      (chicken.internal.syntax-rules#process-syntax-rules
       ellipsis rules subkeywords r c)))))


;; Runtime internal support module exclusively for syntax-rules
(module chicken.internal.syntax-rules
    (drop-right take-right syntax-rules-mismatch)

(import scheme)

(define (syntax-rules-mismatch input)
  (##sys#syntax-error-hook "no rule matches form" input))

(define (drop-right input temp)
  ;;XXX use unsafe accessors
  (let loop ((len (length input))
	     (input input))
    (cond
     ((> len temp)
      (cons (car input)
	    (loop (- len 1) (cdr input))))
     (else '()))))

(define (take-right input temp)
  ;;XXX use unsafe accessors
  (let loop ((len (length input))
	     (input input))
    (cond
     ((> len temp)
      (loop (- len 1) (cdr input)))
     (else input))))

(define (process-syntax-rules ellipsis rules subkeywords r c)

  (define %append '##sys#append)
  (define %apply '##sys#apply)
  (define %and (r 'and))
  (define %car '##sys#car)
  (define %cdr '##sys#cdr)
  (define %length '##sys#length)
  (define %vector? '##sys#vector?)
  (define %vector-length '##sys#vector-length)
  (define %vector-ref '##sys#vector-ref)
  (define %vector->list '##sys#vector->list)
  (define %list->vector '##sys#list->vector)
  (define %>= '##sys#>=)
  (define %= '##sys#=)
  (define %+ '##sys#+)
  (define %compare (r 'compare))
  (define %cond (r 'cond))
  (define %cons '##sys#cons)
  (define %else (r 'else))
  (define %eq? '##sys#eq?)
  (define %equal? '##sys#equal?)
  (define %input (r 'input))
  (define %l (r 'l))
  (define %len (r 'len))
  (define %lambda (r 'lambda))
  (define %let (r 'let))
  (define %let* (r 'let*))
  (define %list? '##sys#list?)
  (define %loop (r 'loop))
  (define %map1 '##sys#map)
  (define %map '##sys#map-n)
  (define %null? '##sys#null?)
  (define %or (r 'or))
  (define %pair? '##sys#pair?)
  (define %quote (r 'quote))
  (define %rename (r 'rename))
  (define %tail (r 'tail))
  (define %temp (r 'temp))
  (define %syntax-error '##sys#syntax-error-hook)
  (define %ellipsis (r ellipsis))
  (define %take-right (r 'chicken.internal.syntax-rules#take-right))
  (define %drop-right (r 'chicken.internal.syntax-rules#drop-right))
  (define %syntax-rules-mismatch
    (r 'chicken.internal.syntax-rules#syntax-rules-mismatch))

  (define (ellipsis? x)
    (c x %ellipsis))

  (define (make-transformer rules)
    `(##sys#er-transformer
      (,%lambda (,%input ,%rename ,%compare)
	(,%let ((,%tail (,%cdr ,%input)))
	  (,%cond ,@(map process-rule rules)
		  (,%else (,%syntax-rules-mismatch ,%input)))))))

  (define (process-rule rule)
    (if (and (pair? rule)
	     (pair? (cdr rule))
	     (null? (cddr rule)))
	(let ((pattern (cdar rule))
	      (template (cadr rule)))
	  `((,%and ,@(process-match %tail pattern #f))
	    (,%let* ,(process-pattern pattern
				      %tail
				      (lambda (x) x) #f)
		    ,(process-template template
				       0
				       (meta-variables pattern 0 '() #f)))))
	(##sys#syntax-error-hook "ill-formed syntax rule" rule)))

  ;; Generate code to test whether input expression matches pattern

  (define (process-match input pattern seen-segment?)
    (cond ((symbol? pattern)
	   (if (memq pattern subkeywords)
	       `((,%compare ,input (,%rename (##core#syntax ,pattern))))
	       `()))
	  ((segment-pattern? pattern seen-segment?)
	   (process-segment-match input pattern))
	  ((pair? pattern)
	   `((,%let ((,%temp ,input))
               (,%and (,%pair? ,%temp)
                      ,@(process-match `(,%car ,%temp) (car pattern) #f)
                      ,@(process-match `(,%cdr ,%temp) (cdr pattern) #f)))))
	  ((vector? pattern)
           `((,%let ((,%temp ,input))
              (,%and (,%vector? ,%temp)
                     ,@(process-match `(,%vector->list ,%temp)
                                      (vector->list pattern) #f)))))
	  ((or (null? pattern) (boolean? pattern) (char? pattern))
	   `((,%eq? ,input ',pattern)))
	  (else
	   `((,%equal? ,input ',pattern)))))

  (define (process-segment-match input pattern)
    (let ((conjuncts (process-match `(,%car ,%l) (car pattern) #f)))
      `((,%and (,%list? ,input) ; Can't ask for its length if not a proper list
               (,%let ((,%len (,%length ,input)))
                 (,%and (,%>= ,%len ,(length (cddr pattern)))
                        (,%let ,%loop ((,%l ,input)
                                       (,%len ,%len))
                           (,%cond
                             ((,%= ,%len ,(length (cddr pattern)))
                              ,@(process-match %l (cddr pattern) #t))
                             (,%else
                              (,%and ,@conjuncts
                                     (,%loop (,%cdr ,%l) (,%+ ,%len -1))))))))))))

  ;; Generate code to take apart the input expression
  ;; This is pretty bad, but it seems to work (can't say why).

  (define (process-pattern pattern path mapit seen-segment?)
    (cond ((symbol? pattern)
	   (if (memq pattern subkeywords)
	       '()
	       (list (list pattern (mapit path)))))
	  ((segment-pattern? pattern seen-segment?)
           (let* ((tail-length (length (cddr pattern)))
                  (%match (if (zero? tail-length) ; Simple segment?
                              path  ; No list traversing overhead at runtime!
                              `(,%drop-right ,path ,tail-length))))
             (append
              (process-pattern (car pattern)
                               %temp
                               (lambda (x) ;temp is free in x
                                 (mapit
                                  (if (eq? %temp x)
                                      %match ; Optimization: no map+lambda
                                      `(,%map1 (,%lambda (,%temp) ,x) ,%match))))
                               #f)
              (process-pattern (cddr pattern)
                               `(,%take-right ,path ,tail-length) mapit #t))))
	  ((pair? pattern)
	   (append (process-pattern (car pattern) `(,%car ,path) mapit #f)
		   (process-pattern (cdr pattern) `(,%cdr ,path) mapit #f)))
          ((vector? pattern)
           (process-pattern (vector->list pattern)
                            `(,%vector->list ,path) mapit #f))
	  (else '())))

  ;; Generate code to compose the output expression according to template

  (define (process-template template dim env)
    (cond ((symbol? template)
	   (let ((probe (assq template env)))
	     (if probe
		 (if (<= (cdr probe) dim)
		     template
		     (##sys#syntax-error-hook "template dimension error (too few ellipses?)"
					      template))
		 `(,%rename (##core#syntax ,template)))))
	  ((segment-template? template)
	   (let* ((depth (segment-depth template))
		  (seg-dim (+ dim depth))
		  (vars
		   (free-meta-variables (car template) seg-dim env '())))
	     (if (null? vars)
		 (##sys#syntax-error-hook "too many ellipses" template)
		 (let* ((x (process-template (car template)
					     seg-dim
					     env))
			(gen (if (and (pair? vars)
				      (null? (cdr vars))
				      (symbol? x)
				      (eq? x (car vars)))
				 x	;+++
				 `(,%map (,%lambda ,vars ,x)
					 ,@vars)))
			(gen (do ((d depth (- d 1))
				  (gen gen `(,%apply ,%append ,gen)))
				 ((= d 1)
				  gen))))
		   (if (null? (segment-tail template))
		       gen		;+++
		       `(,%append ,gen ,(process-template (segment-tail template)
							  dim env)))))))
	  ((pair? template)
	   `(,%cons ,(process-template (car template) dim env)
		    ,(process-template (cdr template) dim env)))
	  ((vector? template)
	   `(,%list->vector
	     ,(process-template (vector->list template) dim env)))
	  (else
	   `(,%quote ,template))))

  ;; Return an association list of (var . dim)

  (define (meta-variables pattern dim vars seen-segment?)
    (cond ((symbol? pattern)
	   (if (memq pattern subkeywords)
	       vars
	       (cons (cons pattern dim) vars)))
	  ((segment-pattern? pattern seen-segment?)
	   (meta-variables (car pattern) (+ dim 1)
                           (meta-variables (cddr pattern) dim vars #t) #f))
	  ((pair? pattern)
	   (meta-variables (car pattern) dim
			   (meta-variables (cdr pattern) dim vars #f) #f))
	  ((vector? pattern)
	   (meta-variables (vector->list pattern) dim vars #f))
	  (else vars)))

  ;; Return a list of meta-variables of given higher dim

  (define (free-meta-variables template dim env free)
    (cond ((symbol? template)
	   (if (and (not (memq template free))
		    (let ((probe (assq template env)))
		      (and probe (>= (cdr probe) dim))))
	       (cons template free)
	       free))
	  ((segment-template? template)
	   (free-meta-variables (car template)
				dim env
				(free-meta-variables (cddr template)
						     dim env free)))
	  ((pair? template)
	   (free-meta-variables (car template)
				dim env
				(free-meta-variables (cdr template)
						     dim env free)))
	  ((vector? template)
	   (free-meta-variables (vector->list template) dim env free))
	  (else free)))

  (define (segment-pattern? p seen-segment?)
    (and (segment-template? p)
         (cond
          (seen-segment?
           (##sys#syntax-error-hook "Only one segment per level is allowed" p))
          ((not (list? p))              ; Improper list
           (##sys#syntax-error-hook "Cannot combine dotted tail and ellipsis" p))
          (else #t))))

  (define (segment-template? pattern)
    (and (pair? pattern)
	 (pair? (cdr pattern))
	 (ellipsis? (cadr pattern))))

  ;; Count the number of `...'s in PATTERN.

  (define (segment-depth pattern)
    (if (segment-template? pattern)
	(+ 1 (segment-depth (cdr pattern)))
	0))

  ;; Get whatever is after the `...'s in PATTERN.

  (define (segment-tail pattern)
    (let loop ((pattern (cdr pattern)))
      (if (and (pair? pattern)
	       (ellipsis? (car pattern)))
	  (loop (cdr pattern))
	  pattern)))

  (make-transformer rules))

) ; chicken.internal.syntax-rules
