;;;; test-queue.scm


(include "QUEUE")


(functor (test-queue (Q QUEUE)) *
  (import scheme (chicken base) Q)
  
  (define (list->queue lst)
    (foldl (lambda (q x) (enqueue q x)) empty-queue lst))

  (define (queue->list q)
    (if (empty? q)
	'()
	(cons (head q) (queue->list (dequeue q))))) )
