;;; environment settings for egg compilation
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


(foreign-declare #<<EOF
#ifndef STATICBUILD
# define STATIC_CHICKEN 0
#else
# define STATIC_CHICKEN 1
#endif
#ifndef DEBUGBUILD
# define DEBUG_CHICKEN 0
#else
# define DEBUG_CHICKEN 1
#endif
EOF
)

(define staticbuild (foreign-value "STATIC_CHICKEN" bool))
(define debugbuild (foreign-value "DEBUG_CHICKEN" bool))
(define cross-chicken (feature? #:cross-chicken))
(define binary-version (foreign-value "C_BINARY_VERSION" int))
(define major-version (foreign-value "C_MAJOR_VERSION" int))
(define chicken-install-program (foreign-value "C_CHICKEN_INSTALL_PROGRAM" c-string))

(define default-cc (foreign-value "C_TARGET_CC" c-string))
(define default-cxx (foreign-value "C_TARGET_CXX" c-string))
(define default-install-program (foreign-value "C_TARGET_INSTALL_PROGRAM" c-string))
(define default-cflags (foreign-value "C_TARGET_CFLAGS" c-string))
(define default-ldflags (foreign-value "C_TARGET_LDFLAGS" c-string))
(define default-install-program-executable-flags (foreign-value "C_TARGET_INSTALL_PROGRAM_EXECUTABLE_OPTIONS" c-string))
(define default-install-program-data-flags (foreign-value "C_TARGET_INSTALL_PROGRAM_FILE_OPTIONS" c-string))
(define default-libs (foreign-value "C_TARGET_MORE_LIBS" c-string))
(define default-libdir (foreign-value "C_TARGET_LIB_HOME" c-string))
(define default-runlibdir (foreign-value "C_TARGET_RUN_LIB_HOME" c-string))
(define default-slibdir (foreign-value "C_TARGET_STATIC_LIB_HOME" c-string))
(define default-incdir (foreign-value "C_TARGET_INCLUDE_HOME" c-string))
(define default-bindir (foreign-value "C_TARGET_BIN_HOME" c-string))
(define default-sharedir (foreign-value "C_TARGET_SHARE_HOME" c-string))

(define default-platform
  (if (eq? (software-type) 'windows)
      (foreign-value "C_WINDOWS_SHELL" bool)
      'unix))

(define default-prefix (foreign-value "C_INSTALL_PREFIX" c-string))
(define default-bindir (foreign-value "C_INSTALL_BIN_HOME" c-string))

(define default-csc 
  (string-append default-bindir "/" (foreign-value "C_CSC_PROGRAM" c-string)))

(define default-csi 
  (string-append default-bindir "/" (foreign-value "C_CSI_PROGRAM" c-string)))

(define default-builder 
  (make-pathname default-bindir (foreign-value "C_CHICKEN_DO_PROGRAM" c-string)))

(define target-librarian (foreign-value "C_TARGET_LIBRARIAN" c-string))
(define target-librarian-options (foreign-value "C_TARGET_LIBRARIAN_FLAGS" c-string))

(define host-prefix (foreign-value "C_INSTALL_PREFIX" c-string))
(define host-repo (foreign-value "C_INSTALL_EGG_HOME" c-string))
(define host-libdir (foreign-value "C_INSTALL_LIB_HOME" c-string))
(define host-bindir (foreign-value "C_INSTALL_BIN_HOME" c-string))
(define host-incdir (foreign-value "C_INSTALL_INCLUDE_HOME" c-string))
(define host-sharedir (foreign-value "C_INSTALL_SHARE_HOME" c-string))
(define host-libs (foreign-value "C_INSTALL_MORE_LIBS" c-string))
(define host-cflags (foreign-value "C_INSTALL_CFLAGS" c-string))
(define host-ldflags (foreign-value "C_INSTALL_LDFLAGS" c-string))
(define host-cc (foreign-value "C_INSTALL_CC" c-string))
(define host-cxx (foreign-value "C_INSTALL_CXX" c-string))

(define target-repo
  (string-append default-libdir "/chicken/" (number->string binary-version)))

(define target-run-repo
  (string-append default-runlibdir "/chicken/" (number->string binary-version)))

(define +egg-info-extension+ "egg-info")
(define +egg-extension+ "egg")

(define (validate-environment)
  (let ((var1 (get-environment-variable "CHICKEN_INSTALL_REPOSITORY"))
        (var2 (get-environment-variable "CHICKEN_INSTALL_PREFIX")))
    (unless (or (not var1) (absolute-pathname? var1))
      (error "CHICKEN_INSTALL_REPOSITORY must be an absolute pathname" var1))
    (unless (or (not var2) (absolute-pathname? var2))
      (error "CHICKEN_INSTALL_PREFIX must be an absolute pathname" var2))))

(define (destination-repository mode #!optional run)
  (if (eq? 'target mode)
      (if run target-run-repo target-repo)
      (or (get-environment-variable "CHICKEN_INSTALL_REPOSITORY")
          host-repo)))

(define (probe-dir dir)           
  (and dir (directory-exists? dir) dir))

(define cache-directory
  (or (get-environment-variable "CHICKEN_EGG_CACHE")
      (make-pathname (or (system-cache-directory)
                         (current-directory))
                     chicken-install-program)))

(define cache-metadata-directory
  ;; Directory where the VERSION, TIMESTAMP and STATUS files are
  ;; stored (under their corresponding egg directory).
  (make-pathname cache-directory ".cache-metadata"))

(define +version-file+ "VERSION")
(define +timestamp-file+ "TIMESTAMP")
(define +status-file+ "STATUS")
