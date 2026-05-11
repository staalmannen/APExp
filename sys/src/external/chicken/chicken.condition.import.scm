;;;; chicken.condition.import.scm - import library for "chicken.condition" module
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
 'chicken.condition
 'chicken.condition ; mapped to distinct run/compile-time requirements in eval unit
 '((abort . chicken.condition#abort)
   (signal . chicken.condition#signal)
   (current-exception-handler . chicken.condition#current-exception-handler)
   (print-error-message . chicken.condition#print-error-message)
   (with-exception-handler . chicken.condition#with-exception-handler)
   (make-property-condition . chicken.condition#make-property-condition)
   (make-composite-condition . chicken.condition#make-composite-condition)
   (condition . chicken.condition#condition)
   (condition? . chicken.condition#condition?)
   (condition->list . chicken.condition#condition->list)
   (condition-predicate . chicken.condition#condition-predicate)
   (condition-property-accessor . chicken.condition#condition-property-accessor)
   (get-condition-property . chicken.condition#get-condition-property))
 ##sys#chicken.condition-macro-environment)
