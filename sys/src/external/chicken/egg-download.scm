;;;; egg download
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


(define +default-tcp-connect-timeout+ 30000) ; 30 seconds
(define +default-tcp-read/write-timeout+ 30000) ; 30 seconds
(define +url-regex+ "(http://)?([^/:]+)(:([^:/]+))?(/.*)?")
(define +max-redirects+ 3)

(tcp-connect-timeout +default-tcp-connect-timeout+)
(tcp-read-timeout +default-tcp-read/write-timeout+)
(tcp-write-timeout +default-tcp-read/write-timeout+)

(define user-agent (conc "chicken-install " (chicken-version)))

(define (deconstruct-url url)
  (let ((m (irregex-match +url-regex+ url)))
    (values
     (if m (irregex-match-substring m 2) url)
     (if (and m (irregex-match-substring m 3))
         (let ((port (irregex-match-substring m 4)))
           (or (string->number port)
	       (error "not a valid port" port)))
	 80)
     (or (and m (irregex-match-substring m 5))
         "/"))))

(define (http-fetch host port locn dest proxy-host proxy-port proxy-user-pass)
  (let-values (((in out _)
    	         (http-connect host port locn proxy-host proxy-port
                               proxy-user-pass)))
    (http-retrieve-files in out dest)))

(define (http-query host port locn proxy-host proxy-port proxy-user-pass)
  (let-values (((in out len)
    	         (http-connect host port locn proxy-host proxy-port
                               proxy-user-pass)))
    (close-output-port out)
    (http-retrieve-response in len)))

(define (http-connect host port locn proxy-host proxy-port proxy-user-pass)
  (let next-req ((redirects 0)
		 (host host)
		 (port port)
		 (locn locn)
		 (req (make-HTTP-GET/1.1
		       locn user-agent host
		       port: port accept: "*/*"
		       proxy-host: proxy-host proxy-port: proxy-port)))

    (when (= redirects +max-redirects+)
      (network-failure "too many redirects" redirects))

    (d "connecting to host ~s, port ~a ~a...~%" host port
       (if proxy-host
           (sprintf "(via ~a:~a) " proxy-host proxy-port)
           ""))

    (let-values (((in out)
                  (tcp-connect (or proxy-host host) (or proxy-port port))))
      (d "requesting ~s ...~%" locn)
      (display req out)
      (flush-output out)
      (d "reading response ...~%")
      (let* ((chunked #f)
             (datalen #f)
             (h1 (read-line in))
             (response-match (match-http-response h1)))

	(define (process-headers)
	  (let ((ln (read-line in)))
	    (unless (equal? ln "")
	      (cond ((match-chunked-transfer-encoding ln)
                     (set! chunked #t))
                    ((match-content-length ln) =>
                     (lambda (sz) (set! datalen sz)))
		    ((match-location ln) =>
                     (lambda (new-locn)
		       (set!-values (host port locn)
				    (deconstruct-url new-locn)))))
	      (d "~a~%" ln)
	      (process-headers) ) ) )

	(d "~a~%" h1)

	(cond
	 ((response-match-code? response-match 407)
	  (close-input-port in)
	  (close-output-port out)

	  (d "retrying with proxy auth ~a~%" locn)
	  (next-req redirects host port locn
		    (make-HTTP-GET/1.1
		     locn user-agent host port: port
		     accept: "*/*"
		     proxy-host: proxy-host proxy-port: proxy-port
		     proxy-user-pass: proxy-user-pass)))

	 ((or (response-match-code? response-match 301)
	      (response-match-code? response-match 302))
	  (process-headers)
	  (close-input-port in)
	  (close-output-port out)

	  (d "redirected to ~a~%" locn)
	  (next-req (add1 redirects) host port locn
		    (make-HTTP-GET/1.1
		     locn user-agent host
		     port: port accept: "*/*"
		     proxy-host: proxy-host proxy-port: proxy-port)))

	 ((response-match-code? response-match 200)
	  (process-headers)
	  (when chunked
	    (d "reading chunks ")
	    (let ((data (read-chunks in)))
	      (close-input-port in)
	      (set! in (open-input-string data))) )
	  (values in out datalen))
	 (else (network-failure "invalid response from server" h1)))))))

(define (http-retrieve-files in out dest)
  (d "reading files ...~%")
  (let ((version #f))
    (define (skip)
      (let ((ln (read-line in)))
        (cond ((or (eof-object? ln)
   	           (irregex-match " *#!eof *" ln))
	        (open-input-string ""))
	       ((irregex-match " *#\\|-+ +([^| ]*) *\\|#.*" ln) =>
	         (lambda (m)
		   (let ((v (irregex-match-substring m 1)))
		     (cond ((or (string=? "" v) (string=? "#f" v)))
			   ((and version (not (string=? v version)))
			    (warning "files versions are not identical" 
                              ln version)     
			    (set! version #f))
			   (else
			    (set! version v)))
		     (open-input-string ln))))
	       ((irregex-match "^[ ]*\\(error .*\\)[ ]*$" ln)
		 (open-input-string ln)) ; get-files deals with errors
	       ((irregex-match '(* ("\x09\x0a\x0b\x0c\x0d\x20\xa0")) ln)
		 (skip)) ; Blank line.
	       (else
		 (error "unrecognized file-information - possibly corrupt transmission" 
			ln)))))
    (let get-files ((files '()))
      (let* ((ins (skip))
             (name (read ins)))
        (cond ((and (pair? name) (eq? 'error (car name)))
            	   (server-error (cadr name) (cddr name)))
	      ((or (eof-object? name) (not name))
	        (close-input-port in)
	        (close-output-port out)
	        version)
	      ((not (string? name))
	        (error "invalid file name - possibly corrupt transmission" 
                       name) )         
	      ((string-suffix? "/" name)
	        (d "  ~a~%" name)
	        (create-directory (make-pathname dest name))
	        (get-files files) )
	      (else
	        (d "  ~a~%" name)
	        (let* ((size (read ins))
	      	       (data (read-string size in)) )
		  (with-output-to-file (make-pathname dest name)
                    (cut display data) #:binary ) )
		(get-files (cons name files)) ) ) ) ) ))

(define (http-retrieve-response in len)
  (d "reading response ...~%")
  (let ((data (read-string len in)))
    (close-input-port in)
    data))

(define (server-error msg args)
  (abort
     (make-composite-condition
      (make-property-condition
       'exn
       'message (string-append "[Server] " msg)
       'arguments args)
      (make-property-condition 'setup-download-error))))

(define (read-chunks in)
  (let get-chunks ((data '()))
    (let* ((line (read-line in))
           (size (and (not (eof-object? line))
                      (string->number line 16))))
      (cond ((not size)
	       (error "invalid response from server - please try again"))
            ((zero? size)
               (d "~%")
	       (string-intersperse (reverse data) ""))
	    (else
	       (let ((chunk (read-string size in)))
		 (d ".")
		 (read-line in)
		 (get-chunks (cons chunk data)) ) ) ) ) ))

(define (match-http-response rsp)
  (and (string? rsp)
       (irregex-match "HTTP/[0-9.]+\\s+([0-9]+)\\s+.*" rsp)) )

(define (response-match-code? mrsp code)
  (and mrsp (string=? (number->string code) 
                      (irregex-match-substring mrsp 1))) )

(define (match-chunked-transfer-encoding ln)
  (irregex-match "[Tt]ransfer-[Ee]ncoding:\\s*chunked.*" ln) )

(define (match-location ln)
  (let ((m (irregex-match "[Ll]ocation:\\s*(.+)\\s*" ln)))
    (and m (irregex-match-substring m 1))))

(define (match-content-length ln)
  (let ((m (irregex-match "[Cc]ontent-[Ll]ength:\\s*([0-9]+).*" ln)))
    (and m (string->number (irregex-match-substring m 1)))))

(define (make-HTTP-GET/1.1 location user-agent host
                           #!key
                           (port 80)
                           (connection "close")
                           (accept "*")
                           (content-length 0)
                     	     proxy-host proxy-port proxy-user-pass)
  (conc
     "GET " 
     (if proxy-host 
	 (string-append "http://" host location)
	 location)
     " HTTP/1.1" "\r\n"
     "Connection: " connection "\r\n"
     "User-Agent: " user-agent "\r\n"
     "Accept: " accept "\r\n"
     "Host: " host #\: port "\r\n"
     (if proxy-user-pass
         (string-append "Proxy-Authorization: Basic " proxy-user-pass "\r\n")
         "")
     "Content-length: " content-length "\r\n"
     "\r\n") )

(define (network-failure msg . args)
  (signal
     (make-composite-condition
      (make-property-condition
       'exn
       'message "invalid response from server"
       'arguments args)
      (make-property-condition 'http-fetch))) )


;; entry points

(define (list-versions egg url)
  (receive (host port locn) (deconstruct-url url)
    (let ((locn (conc locn
                      "?name=" egg
                      "&release=" major-version
                      "&mode=default"
                      "&listversions=1")))
      (let ((data	(http-query host port locn proxy-host
                              proxy-port proxy-user-pass)))
        (string-split data)))))

(define (try-list-versions name url #!key
                           proxy-host proxy-port proxy-user-pass)
  (d "listing versions for ~a: ~a~%" name url)
  (condition-case (list-versions name url)
    ((exn net)
       (print "TCP connect timeout")
       #f)
    ((exn http-fetch)
       (print "HTTP protocol error")
       #f)
    (e (exn setup-download-error)
	 (print "Server error:")
	 (print-error-message e) 
	 #f)
    (e () (abort e) )))

(define (download-egg egg url #!key version destination tests
                      proxy-host proxy-port proxy-user-pass)
  (receive (host port locn) (deconstruct-url url)
    (let* ((locn (conc locn
                       "?name=" egg
                       "&release=" major-version
                       (if version (string-append "&version=" version) "")
                       "&mode=default"
                       (if tests "&tests=yes" "")))
	   (eggdir destination))
        (let ((fversion	(http-fetch host port locn eggdir proxy-host
                                    proxy-port proxy-user-pass)))
	  ;; If we get here then version of egg exists
	  (values eggdir (or fversion version "")) )) ) )

(define (try-download name url #!key version destination tests 
                      proxy-host proxy-port proxy-user-pass)
  (d "downloading ~a: ~a~%" name url)
  (condition-case
     (download-egg
         name url
         version: version
         destination: destination
         tests: tests
 	 proxy-host: proxy-host
	 proxy-port: proxy-port
	 proxy-user-pass: proxy-user-pass)
    ((exn net)
       (print "TCP connect timeout")
       (values #f "") )
    ((exn http-fetch)
       (print "HTTP protocol error")
       (values #f "") )
    (e (exn setup-download-error)
	 (print "Server error:")
	 (print-error-message e) 
	 (values #f ""))
    (e () (abort e) )))
