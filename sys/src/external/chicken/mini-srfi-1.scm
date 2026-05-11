;;;; minimal implementation of SRFI-1 primitives
;
;
; Copyright (c) 2015-2022, The CHICKEN Team
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
; conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
;     disclaimer.
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
;     disclaimer in the documentation and/or other materials provided with the distribution.
;   Neither the name of the author nor the names of its contributors may be used to endorse or promote
;     products derived from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.


(declare 
  (unused take span drop partition split-at append-map every any cons* concatenate
	  first second third fourth alist-cons fifth remove
	  filter filter-map unzip1 last list-index lset-adjoin/eq? lset-difference/eq?
	  lset-union/eq? lset-intersection/eq? list-tabulate lset<=/eq? lset=/eq? length+
	  find find-tail iota make-list posq posv)
  (hide take span drop partition split-at append-map every any cons* concatenate delete
	first second third fourth alist-cons delete-duplicates fifth remove
	filter filter-map unzip1 last list-index lset-adjoin/eq? lset-difference/eq?
	lset-union/eq? lset-intersection/eq? list-tabulate lset<=/eq? lset=/eq? length+
	find find-tail iota make-list posq posv))


(define (partition pred lst)
  (let loop ((yes '()) (no '()) (lst lst))
    (cond ((null? lst) (values (reverse yes) (reverse no)))
	  ((pred (car lst)) (loop (cons (car lst) yes) no (cdr lst)))
	  (else (loop yes (cons (car lst) no) (cdr lst))))))

(define (span pred lst)
  (let loop ((lst lst) (head '()))
    (cond ((null? lst) (values (reverse head) lst))
	  ((pred (car lst)) (loop (cdr lst) (cons (car lst) head)))
	  (else (values (reverse head) lst)))))

(define (take lst n)
  (if (fx<= n 0)
      '()
      (cons (car lst) (take (cdr lst) (fx- n 1)))))

(define (drop lst n)
  (let loop ((lst lst) (n n))
    (if (fx<= n 0)
	lst
	(loop (cdr lst) (fx- n 1)))))

(define (split-at lst n)
  (let loop ((n n) (prev '()) (node lst))
    (if (fx<= n 0)
	(values (reverse prev) node)
	(loop (fx- n 1) (cons (car node) prev) (cdr node)))))

(define (append-map proc lst1 . lsts)
  (if (null? lsts)
      (foldr (lambda (x r) (append (proc x) r)) '() lst1)
      (let loop ((lsts (cons lst1 lsts)))
	(if (any null? lsts)
	    '()
	    (append (apply proc (map (lambda (x) (car x)) lsts))
		    (loop (map (lambda (x) (cdr x)) lsts)))))))

(define (every pred lst)
  (let loop ((lst lst))
    (cond ((null? lst))
	  ((not (pred (car lst))) #f)
	  (else (loop (cdr lst))))))

(define (any pred lst)
  (let loop ((lst lst))
    (cond ((null? lst) #f)
	  ((pred (car lst)))
	  (else (loop (cdr lst))))))

(define (cons* x1 . xs)
  (let loop ((x x1) (rest xs))
    (if (null? rest)
	x
	(cons x (loop (car rest) (cdr rest))))))

(define (concatenate lst)
  (let loop ((lst lst))
    (if (null? lst) 
	'()
	(append (car lst) (loop (cdr lst))))))

(define (delete x lst test)
  (let loop ((lst lst))
    (cond ((null? lst) lst)
	  ((test x (car lst))
	   (loop (cdr lst)))
	  (else
	   (cons (car lst) (loop (cdr lst)))))))

(define (first x) (car x))
(define (second x) (cadr x))
(define (third x) (caddr x))
(define (fourth x) (cadddr x))
(define (fifth x) (car (cddddr x)))

(define (delete-duplicates lst test)
  (let loop ((lst lst))
    (if (null? lst)
	lst
	(let* ((x (car lst))
	       (tail (cdr lst))
	       (new-tail (loop (delete x tail test))))
	  (if (equal? tail new-tail) 
	      lst
	      (cons x new-tail))))))

(define (alist-cons x y z) (cons (cons x y) z))

(define (filter pred lst)
  (foldr (lambda (x r) (if (pred x) (cons x r) r)) '() lst))

(define (filter-map pred lst)
  (foldr (lambda (x r) 
	   (cond ((pred x) => (lambda (y) (cons y r)))
		 (else r)))
	 '()
	 lst))

(define (remove pred lst)
  (filter (lambda (x) (not (pred x))) lst))

(define (unzip1 lst) (map (lambda (x) (car x)) lst))

(define (last lst)
  (let loop ((lst lst))
    (if (null? (cdr lst))
	(car lst)
	(loop (cdr lst)))))

(define (list-index pred lst)
  (let loop ((i 0) (lst lst))
    (cond ((null? lst) #f)
	  ((pred (car lst)) i)
	  (else (loop (fx+ i 1) (cdr lst))))))

(define (lset-adjoin/eq? lst . vals)
  (let loop ((vals vals) (lst lst))
    (cond ((null? vals) lst)
	  ((memq (car vals) lst) (loop (cdr vals) lst))
	  (else (loop (cdr vals) (cons (car vals) lst))))))

(define (lset-difference/eq? ls . lss)
  (foldl
   (lambda (ls lst)
     (filter (lambda (x) (not (memq x lst))) ls))
   ls
   lss))

(define (lset-union/eq? ls . lss)
  (foldl
   (lambda (ls lst)
     (foldl
      (lambda (ls x)
	(if (any (lambda (y) (eq? y x)) ls)
	    ls
	    (cons x ls)))
      ls lst))
   ls lss))

(define (lset-intersection/eq? ls1 . lss)
  (filter (lambda (x)
	    (every (lambda (lis) (memq x lis)) lss))
	  ls1))
  
(define (list-tabulate n proc)
  (let loop ((i 0))
    (if (fx>= i n)
	'()
	(cons (proc i) (loop (fx+ i 1))))))

(define (lset<=/eq? s1 s2)
  (every (lambda (s) (memq s s2)) s1))

(define (lset=/eq? s1 s2)
  (and (eq? (length s1) (length s2))
       (every (lambda (s) (memq s s2)) s1)))

;; from SRFI-1 ref. impl.
(define (length+ x)			; Returns #f if X is circular.
  (let lp ((x x) (lag x) (len 0))
    (if (pair? x)
	(let ((x (cdr x))
	      (len (fx+ len 1)))
	  (if (pair? x)
	      (let ((x   (cdr x))
		    (lag (cdr lag))
		    (len (fx+ len 1)))
		(and (not (eq? x lag)) (lp x lag len)))
	      len))
	len)))

(define (find pred lst)
  (let loop ((lst lst))
    (cond ((null? lst) #f)
	  ((pred (car lst)) (car lst))
	  (else (loop (cdr lst))))))

(define (find-tail pred ls)
  (let lp ((ls ls))
    (cond ((null? ls) #f)
	  ((pred (car ls)) ls)
	  (else (lp (cdr ls))))))

(define (iota n) (list-tabulate n (lambda (i) i)))

(define (make-list n #!optional x)
  (list-tabulate n (lambda _ x)))

(define (posq x lst)
  (let loop ((i 0) (lst lst))
    (cond ((null? lst) #f)
	  ((eq? (car lst) x) i)
	  (else (loop (fx+ i 1) (cdr lst))))))

(define (posv x lst)
  (let loop ((i 0) (lst lst))
    (cond ((null? lst) #f)
	  ((eqv? (car lst) x) i)
	  (else (loop (fx+ i 1) (cdr lst))))))

