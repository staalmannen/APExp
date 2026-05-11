;;;; test-finalizers-2.scm - test finalizers + GC roots

(import (chicken gc) (chicken fixnum))

(define (list-tabulate n proc)
  (let loop ((i 0))
    (if (fx>= i n)
	'()
	(cons (proc i) (loop (fx+ i 1))))))

(define *n* 1000)
(define *count* 0)

#>
static void *
makef(int f, C_word x)
{
  void *r = f ? CHICKEN_new_finalizable_gc_root() : CHICKEN_new_gc_root();

  CHICKEN_gc_root_set(r, x);
  return r;
}

static void
freef(void *r)
{
  CHICKEN_delete_gc_root(r);
}
<#


(define makef (foreign-lambda c-pointer "makef" bool scheme-object))
(define freef (foreign-lambda void "freef" c-pointer))

(define ((fin f e) x)
  (set! *count* (add1 *count*))
  (assert ((if e even? odd?) (car x)))
  (when e (freef f)))

(print "creating gc roots")

(let* ((x (list-tabulate *n* list))
       (fs (list-tabulate *n* (lambda (x) (zero? (modulo x 2)))))
       (rs (map makef fs x)))
  (for-each 
   (lambda (x f e)
     (set-finalizer! x (fin f e)))
   x rs fs)
  (print "forcing finalizers")
  (##sys#force-finalizers)
  (assert (zero? *count*))
  (print "dropping data")
  (set! x #f)
  (print "forcing finalizables")
  (##sys#force-finalizers)
  (print *count*)
  (assert (= (quotient *n* 2) *count*))
  (print "releasing non-finalizable gc roots")
  (for-each 
   (lambda (f e)
     (unless e (freef f)))
   rs fs)
  (print "forcing remaining")
  (##sys#force-finalizers)
  (assert (= *n* *count*)))

;;; new finalizer API

(define c1 (list *count*))
(define f1 (make-finalizer c1))
(add-to-finalizer f1 (make-vector 10))
(define f2 (make-finalizer f1))
(gc #t)
(assert (vector? (f1)))
(assert (not (f1)))
(set! c1 #f)
(gc #t)
(assert (equal? (f1) (list *count*)))
(assert (not (f1)))
(set! f1 #f)
(gc #t)
(assert (procedure? (f2)))
(assert (not (f2)))
