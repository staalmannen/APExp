;;; loading and accessing egg-information
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


;;; load egg-info from file and perform validation

(define (locate-egg-file fname)
  (let ((fname* (make-pathname (make-pathname (pathname-directory fname)
                                              "chicken")
                               (pathname-file fname) 
                               (pathname-extension fname))))
    (if (file-exists? fname*) fname* fname)))

(define (load-egg-info fname)
  (let* ((fname (locate-egg-file fname))
         (info (with-input-from-file fname read)))
    (if (eof-object? info)
        (error "empty egg-info file, possibly due to an aborted egg-install - please remove the file and reinstall the corresponding egg" fname)
        info)))


;;; lookup specific toplevel properties of egg-information

(define (get-egg-property info prop #!optional default)
  (let ((p (assq prop info)))
    (or (and p (cadr p)) default)))

(define (get-egg-property* info prop #!optional (default '()))
  (let ((p (assq prop info)))
    (or (and p (cdr p)) default)))


;;; lookup specific properties for specific extensions

(define (get-extension-property/internal info ext prop get default host)
  (define (find-prop exp)
    (and (not (null? exp))
         (case (caar exp)
           ((target) 
            (or (and (not host) (find-prop (cdar exp)))
                (find-prop (cdr exp))))
           ((host)
            (or (and host (find-prop (cdar exp)))
                (find-prop (cdr exp))))
           (else (if (eq? prop (caar exp))
                     (car exp)
                     (find-prop (cdr exp)))))))
  (or (let walk ((p (cdr (assq 'components info))))
        (and (not (null? p))
             (case (caar p)
               ((target) 
                (or (and (not host) (walk (cdar p)))
                    (walk (cdr p))))
               ((host)
                (or (and host (walk (cdar p)))
                    (walk (cdr p))))
               ((extension)
                (and (eq? ext (cadar p)) 
                     (let ((p (find-prop (caddr p))))
                       (and p (get p)))))
               (else (walk (cdr p))))))
      default))

(define (get-extension-property info ext prop #!optional default host)
  (get-extension-property/internal info ext prop cadr default host))
  
(define (get-extension-property* info ext prop #!optional default host)
  (get-extension-property/internal info ext prop cdr default host))
