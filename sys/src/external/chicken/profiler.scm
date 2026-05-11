;;;; profiler.scm - Support code for profiling applications
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


(declare
  (unit profiler)
  (hide ##sys#profile-name ##sys#profile-vector-list cpu-ms empty-file?)
  (unsafe)
  (disable-interrupts))

(import chicken.base chicken.fixnum scheme)

(include "common-declarations.scm")

(define-foreign-variable profile-id int "C_getpid()")

(define-constant profile-info-entry-size 5)

(define empty-file?
  (foreign-lambda* bool ((scheme-object p))
    "C_return(ftell(C_port_file(p)) == 0);"))


;;; Globals:

(define ##sys#profile-vector-list '())
(define ##sys#profile-name #f)
(define ##sys#profile-append-mode #f)


;;; Initialize profile counter vector:

(define ##sys#register-profile-info
  (lambda (size filename)
    (when filename
      (set! ##sys#profile-name 
	(if (string? filename)
	    filename
	    (string-append "PROFILE." (number->string profile-id))))
      (let ((oldeh (exit-handler))
	    (oldieh (implicit-exit-handler)))
	(exit-handler
	 (lambda args
	   (##sys#finish-profile)
	   (apply oldeh args) ) )
	(implicit-exit-handler
	 (lambda ()
	   (##sys#finish-profile)
	   (oldieh) ) ) ) )
    ;; entry: [name, count, time0, total, pending]
    (let ((vec (make-vector (fx* size profile-info-entry-size) 0)))
      (set! ##sys#profile-vector-list (cons vec ##sys#profile-vector-list))
      vec) ) )

(define (##sys#set-profile-info-vector! vec i x)
  (##sys#setslot vec (fx* i profile-info-entry-size) x) )


;;; Entry and exit into/out of profiled lambda:

(define cpu-ms (foreign-lambda unsigned-integer64 "C_cpu_milliseconds"))

(define ##sys#profile-entry 
  (let ((maxfix most-positive-fixnum))
    (lambda (index vec)
      (let* ([i (fx* index profile-info-entry-size)]
	     [ic (fx+ i 1)]
	     [count (##sys#slot vec ic)]
	     [it0 (fx+ i 2)] 
	     [ip (fx+ i 4)] 
	     [ipc (##sys#slot vec ip)] )
	(##sys#setislot 
	 vec ic
	 (cond ((not count) #f)
	       ((eq? maxfix count) #f)
	       (else (fx+ count 1))))
	(when (eq? 0 ipc)
	  (##sys#setslot vec it0 (cpu-ms)))
	(##sys#setislot vec ip (fx+ ipc 1)) ) ) ) )

(define (##sys#profile-exit index vec)
  (let* ([i (fx* index profile-info-entry-size)]
	 [it0 (fx+ i 2)] 
	 [it (fx+ i 3)] 
	 [ip (fx+ i 4)] 
	 [ipc (fx- (##sys#slot vec ip) 1)] )
    (##sys#setislot vec ip ipc)
    (when (eq? 0 ipc)
      (let ((t (##sys#slot vec it)))
	(##sys#setslot
	 vec it 
	 (+ (if (eq? t 0) 0 t)
	    (- (cpu-ms) (##sys#slot vec it0))))))))


;;; Generate profile:

(define ##sys#finish-profile 
  (let ([with-output-to-file with-output-to-file]
	[write-char write-char]
	[write write] )
    (lambda ()
      (when (##sys#debug-mode?)
	(##sys#print "[debug] writing profile...\n" #f ##sys#standard-error) )
      (apply
       with-output-to-file ##sys#profile-name
       (lambda ()
	 (when (empty-file? (current-output-port)) ; header needed?
	   (write 'instrumented)
	   (write-char #\newline))
	 (for-each
	  (lambda (vec)
	    (let ([len (##sys#size vec)])
	      (do ([i 0 (fx+ i profile-info-entry-size)])
		  ((fx>= i len))
		(write-char #\()
		(write (##sys#slot vec i))
		(write-char #\space)
		(write (##sys#slot vec (fx+ i 1)))
		(write-char #\space)
		(write (##sys#slot vec (fx+ i 3)))
		(write-char #\))
		(write-char #\newline) ) ) ) 
	  ##sys#profile-vector-list) )
       (if ##sys#profile-append-mode
	   '(#:append)
	   '() ) ) ) ) )
