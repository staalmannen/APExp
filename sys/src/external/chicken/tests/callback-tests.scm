;;;; callback-tests.scm

(import (only (chicken process-context) command-line-arguments))

(define k1)

(define-external (foo) void
  (call/cc
   (lambda (k) (set! k1 k)))
  (print "hi!"))

#>
extern void foo();
static void bar() { foo(); }
<#

(print "callbacks ...")
((foreign-safe-lambda void "bar"))

(when (member "twice" (command-line-arguments))
  (k1 #f))
