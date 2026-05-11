;; This test walks the types.db file and checks that symbols are what they are supposed to be.

(import
  (chicken base)
  (chicken bitwise)
  (chicken continuation)
  (chicken read-syntax)
  (chicken irregex)
  (chicken memory)
  (chicken port)
  (chicken format)
  (chicken process-context)
  (chicken process-context posix)
  (chicken tcp)
  srfi-4)

(define ignored-symbols
  '(;; internal procedures
    chicken.irregex#irregex-dfa
    chicken.irregex#irregex-dfa/search
    chicken.irregex#irregex-nfa
    chicken.irregex#irregex-flags
    chicken.irregex#irregex-lengths
    chicken.irregex#irregex-reset-matches!
    chicken.irregex#irregex-new-matches
    chicken.irregex#irregex-apply-match
    chicken.irregex#irregex-search/matches))

(define *error-code* 0)

(define (warn msg . args)
  (apply fprintf (current-error-port)
         msg args)
  (set! *error-code* 1))

(define (deep o)
  (cond ((pair? o)
         (deep (car o)))
        ((vector? o)
         (deep (vector-ref o 0)))
        (else o)))

(define ((unknown sym) obj)
  (warn "Unknown type '~a' for object: ~a~%"
        sym obj))

(define (symbol->predicate sym)
  (case sym
    ((procedure forall) procedure?)
    ((fixnum) fixnum?)
    ((float) flonum?)
    ((list-of) list?)
    ((symbol) symbol?)
    ((input-port) input-port?)
    ((output-port) output-port?)
    ((deprecated) (constantly #t))
    (else (unknown sym))))

(define (run-checks file checker)
  (with-input-from-file file
    (lambda ()
      (port-for-each checker read))))

(define (simple-checker entry)
  (let* ((symbol (car entry))
         (value (##sys#slot symbol 0))
         (type (deep (cadr entry)))
         (pred (symbol->predicate type)))
    (unless (or (member symbol ignored-symbols)
                (pred value))
      (warn "Mismatch for ~a '~a': ~a~%"
            type symbol value))))

(run-checks (car (command-line-arguments))
            simple-checker)
(exit *error-code*)
