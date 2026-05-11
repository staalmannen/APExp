(import chicken.irregex chicken.platform chicken.keyword chicken.string)

(let* ((version-tokens (string-split (chicken-version) "."))
       (major (string->number (car version-tokens)))
       (minor (string->number (cadr version-tokens))))

  (display "Checking major and minor version numbers against chicken-version... ")
  (assert (= (foreign-value "C_MAJOR_VERSION" int) major))
  (assert (= (foreign-value "C_MINOR_VERSION" int) minor))
  (print "ok")

  (display "Checking the registered feature chicken-<major>.<minor>... ")
  (let loop ((features (features)))
    (if (null? features)
        (error "Could not find feature chicken-<major>.<minor>")
        (let ((feature (keyword->string (car features))))
          (cond ((irregex-match "chicken-(\\d+)\\.(\\d+)" feature)
                 => (lambda (match)
                      (assert (= (string->number
                                  (irregex-match-substring match 1))
                                 major))
                      (assert (= (string->number
                                  (irregex-match-substring match 2))
                                 minor))))
                (else (loop (cdr features)))))))

  (display "Checking the registered feature chicken-<major>... ")
  (let loop ((features (features)))
    (if (null? features)
        (error "Could not find feature chicken-<major>")
        (let ((feature (keyword->string (car features))))
          (cond ((irregex-match "chicken-(\\d+)" feature)
                 => (lambda (match)
                      (assert (= (string->number
                                  (irregex-match-substring match 1))
                                 major))))
                (else (loop (cdr features)))))))
  (print "ok"))
