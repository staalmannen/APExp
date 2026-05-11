(module reexport-m7
    (reexported-reverse (reexported-local-reverse my-reverse))

  (import scheme (chicken syntax))

  (define (my-reverse lis)
    (reverse lis))

  (define-syntax reexported-local-reverse
    (syntax-rules ()
      ((_ lis)
       (my-reverse lis))))

  (define-syntax reexported-reverse
    (syntax-rules ()
      ((_ lis)
       (reverse lis)))))
