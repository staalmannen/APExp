(module
 inline-me
 (foreign-foo external-foo)
 (import scheme (chicken base))
 (import (only (chicken foreign) foreign-lambda*))

 (define foreign-foo (foreign-lambda* int ((int x)) "C_return ( x + 1 );"))

 (define (external-foo x y) (display x y))

)
