;;;; breadth-first.scm


(include "QUEUE")


(functor (breadth-first (Q QUEUE)) (search)
  (import scheme (chicken base) Q)
  
  (define (enqlist q xs)
    (foldl (lambda (q x) (enqueue q x)) q xs))

  (define (search next x)
    (define (bfs q)
      (if (empty? q)
	  '()
	  (let ((y (head q)))
	    (cons y (lambda () (bfs (enqlist (dequeue q) (next y))))))))
    (bfs (enqueue empty-queue x))) )
