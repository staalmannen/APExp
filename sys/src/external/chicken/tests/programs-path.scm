(define (executable-path exe)
  (string-append "../"
                 (or (get-environment-variable "PROGRAM_PREFIX") "")
                 exe
                 (or (get-environment-variable "PROGRAM_SUFFIX") "")))

(define chicken-path (executable-path "chicken"))
(define csc-path (executable-path "csc"))
(define csi-path (executable-path "csi"))
