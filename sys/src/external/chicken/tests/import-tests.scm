;;;; import-tests.scm

(module m1 ()
(import scheme (only srfi-4 u8vector?)) u8vector?)

(print "expect warning ...")
(assert
 (handle-exceptions ex #t
   (eval '
(module m2 ()
(import scheme (only (srfi 4) u8vector?))
s8vector?)) #f))

(module m3 ()
(import scheme (rename (srfi 4) (u8vector? u8v?))) 
u8v?)

(module m4 ()
(import scheme (chicken base))
(require-extension (prefix (srfi 4) s4:))
s4:f32vector)
