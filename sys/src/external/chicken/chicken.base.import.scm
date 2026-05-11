;;;; chicken.base.import.scm - import library for "chicken.base" module
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

(##sys#register-core-module
 'chicken.base
 'library
 '((add1 . chicken.base#add1)
   (alist-ref . chicken.base#alist-ref)
   (alist-update . chicken.base#alist-update)
   (alist-update! . chicken.base#alist-update!)
   (atom? . chicken.base#atom?)
   (bignum? . chicken.base#bignum?)
   (bwp-object? . chicken.base#bwp-object?)
   (butlast . chicken.base#butlast)
   (call/cc . chicken.base#call/cc)
   (case-sensitive . chicken.base#case-sensitive)
   (char-name . chicken.base#char-name)
   (chop . chicken.base#chop)
   (complement . chicken.base#complement)
   (compose . chicken.base#compose)
   (compress . chicken.base#compress)
   (conjoin . chicken.base#conjoin)
   (constantly . chicken.base#constantly)
   (cplxnum? . chicken.base#cplxnum?)
   (current-error-port . chicken.base#current-error-port)
   (disjoin . chicken.base#disjoin)
   (each . chicken.base#each)
   (emergency-exit . chicken.base#emergency-exit)
   (enable-warnings . chicken.base#enable-warnings)
   (equal=? . chicken.base#equal=?)
   (error . chicken.base#error)
   (exact-integer? . chicken.base#exact-integer?)
   (exact-integer-nth-root . chicken.base#exact-integer-nth-root)
   (exact-integer-sqrt . chicken.base#exact-integer-sqrt)
   (exit . chicken.base#exit)
   (exit-handler . chicken.base#exit-handler)
   (finite? . chicken.base#finite?)
   (fixnum? . chicken.base#fixnum?)
   (flatten . chicken.base#flatten)
   (flip . chicken.base#flip)
   (flonum? . chicken.base#flonum?)
   (flush-output . chicken.base#flush-output)
   (foldl . chicken.base#foldl)
   (foldr . chicken.base#foldr)
   (gensym . chicken.base#gensym)
   (get-call-chain . chicken.base#get-call-chain)
   (get-output-string . chicken.base#get-output-string)
   (getter-with-setter . chicken.base#getter-with-setter)
   (identity . chicken.base#identity)
   (implicit-exit-handler . chicken.base#implicit-exit-handler)
   (infinite? . chicken.base#infinite?)
   (input-port-open? . chicken.base#input-port-open?)
   (intersperse . chicken.base#intersperse)
   (join . chicken.base#join)
   (keyword-style . chicken.base#keyword-style)
   (list-of? . chicken.base#list-of?)
   (make-parameter . chicken.base#make-parameter)
   (make-promise . chicken.base#make-promise)
   (nan? . chicken.base#nan?)
   (notice . chicken.base#notice)
   (o . chicken.base#o)
   (on-exit . chicken.base#on-exit)
   (open-input-string . chicken.base#open-input-string)
   (open-output-string . chicken.base#open-output-string)
   (output-port-open? . chicken.base#output-port-open?)
   (parentheses-synonyms . chicken.base#parentheses-synonyms)
   (port? . chicken.base#port?)
   (port-closed? . chicken.base#port-closed?)
   (print-call-chain . chicken.base#print-call-chain)
   (print . chicken.base#print)
   (print* . chicken.base#print*)
   (procedure-information . chicken.base#procedure-information)
   (promise? . chicken.base#promise?)
   (quotient&modulo . chicken.base#quotient&modulo)
   (quotient&remainder . chicken.base#quotient&remainder)
   (rassoc . chicken.base#rassoc)
   (ratnum? . chicken.base#ratnum?)
   (record-printer . chicken.base#record-printer)
   (set-record-printer! . chicken.base#set-record-printer!)
   (setter . chicken.base#setter)
   (signum . chicken.base#signum)
   (sleep . chicken.base#sleep)
   (string->uninterned-symbol . chicken.base#string->uninterned-symbol)
   (sub1 . chicken.base#sub1)
   (subvector . chicken.base#subvector)
   (symbol-append . chicken.base#symbol-append)
   (symbol-escape . chicken.base#symbol-escape)
   (tail? . chicken.base#tail?)
   (vector-copy! . chicken.base#vector-copy!)
   (vector-resize . chicken.base#vector-resize)
   (void . chicken.base#void)
   (warning . chicken.base#warning)
   (weak-cons . chicken.base#weak-cons)
   (weak-pair? . chicken.base#weak-pair?))
 ##sys#chicken.base-macro-environment)
