;;;; module registrations for all core modules
;
; Copyright (c) 2017-2022, The CHICKEN Team
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
  (unit eval-modules)
  (uses eval))

(include "common-declarations.scm")

(define-syntax put!
  (syntax-rules ()
    ((_ sym prop val)
     (##core#inline_allocate ("C_a_i_putprop" 8) sym prop val))))

(define-syntax get
  (syntax-rules ()
    ((_ sym prop)
     (##core#inline "C_i_getprop" sym prop #f))))

(define-syntax defmod
  (er-macro-transformer
    (lambda (x r c)
      (let ((name (cadr x))
            (%lambda (r 'lambda))
            (%quote (r 'quote))
            (%include (r 'include))
            (%put! (r 'put!)))
        `(,%put! (,%quote ,name)
                 (,%quote ##sys#import)
                 (,%lambda ()
                   (,%include ,(string-append (symbol->string name)
                                              ".import.scm"))))))))

(defmod chicken.bitwise)
(defmod chicken.blob)
(defmod chicken.foreign)
(defmod chicken.fixnum)
(defmod chicken.keyword)
(defmod chicken.internal)
(defmod chicken.platform)
(defmod chicken.errno)
(defmod chicken.condition)
(defmod chicken.string)
(defmod chicken.irregex)
(defmod chicken.pathname)
(defmod chicken.io)
(defmod chicken.port)
(defmod chicken.time)
(defmod chicken.memory)
(defmod chicken.file.posix)
(defmod chicken.flonum)
(defmod chicken.format)
(defmod chicken.gc)
(defmod chicken.eval)
(defmod chicken.load)
(defmod chicken.locative)
(defmod chicken.memory.representation)
(defmod chicken.plist)
(defmod chicken.pretty-print)
(defmod chicken.process)
(defmod chicken.process.signal)
(defmod chicken.process-context)
(defmod chicken.process-context.posix)
(defmod chicken.random)
(defmod chicken.sort)
(defmod chicken.time.posix)
(defmod chicken.continuation)
(defmod chicken.file)
(defmod chicken.read-syntax)
(defmod chicken.repl)
(defmod chicken.tcp)
(defmod srfi-4)

(set! ##sys#import-library-hook
  (let ((hook ##sys#import-library-hook))
    (lambda (mname)
      (cond ((get mname '##sys#import) => (lambda (il) (il)))
	    (else (hook mname)) ) ) ) )
