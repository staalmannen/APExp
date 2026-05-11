;;;; make-wrapper.scm - generate "trampoline" script for program
;
; usage: csi -s make-wrapper.scm NAME BINPATH

(import (chicken pathname))

(let* ((args (command-line-arguments))
       (name (car args))
       (prefix (cadr args)))
  (with-output-to-file (make-pathname prefix name)
    (lambda ()
      (display #<#EOF
##!/bin/sh

if test -d .chicken; then
  exec .chicken/bin/"#{name}" "$@"
else
  exec "#{prefix}"/"#{name}" "$@"
fi

EOF
))))
