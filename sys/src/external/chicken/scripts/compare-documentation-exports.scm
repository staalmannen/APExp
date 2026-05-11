;; This script takes a filename as its first argument, which should be a file
;; consisting of multiple lists in this format: ((module name) exported-symbol ...)
;; It imports the specified module and checks that the export list of the module matches
;; with the one supplied in the file.
;; This is useful to check that the documentation and module exports are synchronized.

;; TODO make the script read svn-wiki syntax directly

(import chicken.sort srfi-1)

(define *exit-code* 0)

(define (warn msg . args)
  (apply fprintf (current-error-port)
         msg args)
  (set! *exit-code* 1))

(define (module-exports mod)
  (receive (_ ve se) (##sys#module-exports mod)
    (sort (append (map car ve) (map car se)) symbol<?)))

(define (symbol<? s1 s2)
  (string<? (symbol->string s1)
            (symbol->string s2)))

(define (check-module name exports)
  (eval `(import ,name))
  (let* ((exports (sort exports symbol<?))
         (canonical-name
          (string->symbol
            (string-intersperse (map ->string name) ".")))
         (mod (##sys#find-module canonical-name))
         (mod-exports (module-exports mod))
         (diff (lset-difference eqv? exports mod-exports)))
    (unless (null? diff)
      (warn "Mismatch is ~a: ~a~%"
            name diff))))

(define (run-checks filename)
  (with-input-from-file filename
    (lambda ()
      (port-for-each check read))))

(define (check desc)
  (check-module (car desc) (cdr desc)))

(run-checks (car (command-line-arguments)))

(exit *exit-code*)
