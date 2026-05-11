;;;; record-printer-test.scm

(import (chicken format)
	(chicken string))

(define-record kons x y)

;; no printer to start out

(assert (not (record-printer kons)))
(assert (equal? "#<kons>" (conc (make-kons 1 2))))

;; custom printer

(set-record-printer! kons
 (lambda (k p)
   (fprintf p "#<kons ~a ~a>" (kons-x k) (kons-y k))))

(assert (equal? "#<kons 1 2>" (conc (make-kons 1 2))))

;; srfi-17 style assignment

(assert (procedure? (setter record-printer)))

(set! (record-printer kons)
  (lambda (k p)
    (fprintf p "#[~a . ~a]" (kons-x k) (kons-y k))))

(assert (equal? "#[1 . 2]" (conc (make-kons 1 2))))
