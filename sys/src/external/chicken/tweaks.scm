;;;; tweaks.scm - Some inline-routines and declarations for the compiler 
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
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


;; This file contains some stuff to speed up basic node accessors, and also
;; contains common declarations.


(cond-expand
  ((not debugbuild)
   (declare
     (disable-interrupts)
     (no-bound-checks)
     (no-procedure-checks)
     (no-argc-checks)))
  (else))

(define-inline (node? x) (##sys#structure? x 'chicken.compiler.support#node))
(define-inline (make-node c p s) (##sys#make-structure 'chicken.compiler.support#node c p s))

(cond-expand
  ((not debugbuild)
   (define-inline (node-class n) (##sys#slot n 1))
   (define-inline (node-parameters n) (##sys#slot n 2))
   (define-inline (node-subexpressions n) (##sys#slot n 3)))
  (else))

(define-inline (intrinsic? sym) (##sys#get sym '##compiler#intrinsic))

(define-inline (namespaced-symbol? sym)
  (##core#inline "C_u_i_namespaced_symbolp" sym))

(define-inline (mark-variable var mark #!optional (val #t))
  (##sys#put! var mark val) )

(define-inline (variable-mark var mark)
  (##sys#get var mark) )
