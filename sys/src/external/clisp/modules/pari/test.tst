;; -*- Lisp -*- vim:filetype=lisp
;; some tests for GP/PARI CALCULATOR
;; clisp -E 1:1 -q -norc -i ../tests/tests -x '(run-test "pari/test")'

(list (require "pari")) (#-PARI T #+PARI NIL)
(listp (show (multiple-value-list (ext:module-info "pari" t)) :pretty t)) t

(format t "~&Version: ~S~%" pari:pari-version) NIL

(progn
  (defparameter *pari-to-lisp* (make-hash-table))
  (defparameter *lisp-to-pari* (make-hash-table))
  (setq *trace-output* (make-broadcast-stream)) ; suppress TRACE output
  (trace (pari::convert-from-pari
          :pre (incf (gethash (pari::pari-type-raw (car ext:*trace-args*))
                              *pari-to-lisp* 0))))
  ;; this is not good enough because it captures only the top-level calls to
  ;; `pari-to-lisp', not the internal calls to `convert-from-pari'.
  ;; (defmethod pari::pari-to-lisp :before ((x pari::pari-object-internal))
  ;;   (incf (gethash (pari::pari-type-raw (pari::pari-object-internal-pointer
  ;;                                        x)) *pari-to-lisp* 0)))
  (defmethod pari::convert-to-pari :around ((x t))
    (let ((ptr (call-next-method)))
      (when ptr (incf (gethash (pari::pari-type-raw ptr) *lisp-to-pari* 0)))
      ptr))
  t) T

;; integer conversion
(defun roundtrip1 (x)
  (pari:pari-to-lisp (read-from-string (format nil "#Z\"~D\"" x))))
ROUNDTRIP1
(defun roundtrip2 (x)
  (read-from-string (pari::%write-to-string (pari::convert-to-pari x))))
ROUNDTRIP2
(defun get-x-ash (i) (random (ash 1 i))) GET-X-ASH
(defun get-x-ash-neg (i) (- (random (ash 1 i)))) GET-X-ASH-NEG
(defun check-roundtrip (limit get-x roundtrip)
  (loop :for i :from 1 :to limit :for x = (funcall get-x i)
    :for px = (funcall roundtrip x)
    :unless (= x px) :collect (cons x px)))
CHECK-ROUNDTRIP
(check-roundtrip 1000 #'get-x-ash #'roundtrip1) ()
(check-roundtrip 1000 #'get-x-ash-neg #'roundtrip1) ()
(check-roundtrip 1000 #'get-x-ash #'roundtrip2) ()
(check-roundtrip 1000 #'get-x-ash-neg #'roundtrip2) ()

(defparameter id (pari:identity-matrix 3)) ID
(pari:equal? id #Z"[1,0,0;0,1,0;0,0,1]") T
(pari:matrix-rank id) 3
(pari:equal? id (pari:matrix-transpose id)) T
(pari:equal? id (pari:adjoint-matrix id)) T
(pari:equal? (pari:matrix-kernel id) #Z"[;]") T
(pari:equal? id (pari:matrix-image id)) T
(pari:equal? id (pari:norm id)) T
(pari:equal? (pari:matrix-image-complement id) #Z"[]") T
(pari:equal? id (pari:matrix-supplement id)) T
(pari:equal? id (pari:matrix-eigenvectors id)) T
(pari:equal? id (pari:matrix-to-hessenberg-form id)) T
(pari:one? (pari:matrix-determinant id)) T
(pari:equal? (pari:l2-norm id) #Z"3") T
(pari:equal? (pari:pari-trace id) #Z"3") T
(pari:equal? (pari:pari-concatenate 1 2) #Z"[1,2]") T
(pari:equal? (pari:vector-extract id 1) #Z"[1;0;0]") T
(pari:equal? (pari:matrix-extract id 7 7) id) T
(pari:equal? (pari:matrix-extract id #(1 2 3) #(1 2 3)) id) T
(pari:equal? (pari:matrix-solve id #Z"[1;2;3]") #Z"[1;2;3]") T
(pari:equal? (pari:matrix-solve #Z"[1,1,1;0,1,1;0,0,1]" #Z"[1;2;3]")
             #Z"[-1;-1;3]") T
(pari:equal? (pari:characteristic-polynomial id) #Z"x^3-3*x^2+3*x-1") T
(pari:equal? id (pari:symmetric-matrix-sqred id)) T
(pari:equal? (pari:symmetric-matrix-signature id) #Z"[3,0]") T
(pari:equal? (pari:symmetric-matrix-sqred #Z"[2,1;1,2]") #Z"[2,1/2;0,3/2]") T
(pari:equal? (pari:matrix-indexrank #Z"[2,1;1,2]") #Z"[[1,2],[1,2]]") T
(pari:equal? (pari:symmetric-matrix-perfection id) #Z"3") T
(pari:pari-to-lisp (pari:matrix-determinant #2A((1 2) (3 4)))) -2
(pari:pari-to-lisp (pari:matrix-solve #2A((1 2) (3 4)) nil))
#2A((-2 1) (3/2 -1/2))
(pari:pari-to-lisp (pari:pari* #2A((1 2) (3 4)) #(:COL 1 2))) #(:COL 5 11)
(pari:pari-to-lisp (pari:matrix-solve #2A((1 2) (3 4)) #(:COL 5 11)))#(:COL 1 2)
(pari:pari-to-lisp (pari:square #2A((2 1) (1 2)))) #2A((5 4) (4 5))
(pari:pari-to-lisp (pari:pari/ #2A((5 4) (4 5)) #2A((2 1) (1 2))))
#2A((2 1) (1 2))

(pari:pari-to-lisp (pari:matrix-indexrank id))
#(:ROW #(:ROW 1 2 3) #(:ROW 1 2 3))
(pari:pari-to-lisp (pari:matrix-indexrank #2A((1 2) (2 4))))
#(:ROW #(:ROW 1) #(:ROW 1))
(let* ((mx #2A((1 2 3) (2 4 6) (1 2 8)))
       (ir (pari:pari-to-lisp (pari:matrix-indexrank mx))))
  (list ir (pari:pari-to-lisp (pari:matrix-extract
                               mx (aref ir 1) (aref ir 2)))))
(#(:ROW #(:ROW 1 3) #(:ROW 1 3)) #2A((1 3) (1 8)))

(pari:pari-to-lisp (pari:square (pari:pari-sqrt #C(0 1))))  #C(0 1)
(pari:pari-to-lisp (pari:pari-sqrt #C(1 2)))
#C(1.2720196495140689642L0 0.78615137775742328604L0)
(pari:pari-to-lisp (pari:pari-sqrt #C(1 1)))
#C(1.0986841134678099661L0 0.45508986056222734128L0)
(pari:pari-to-lisp (pari:pari-sqrt #C(0 1)))
#C(0.7071067811865475244L0 0.7071067811865475244L0)

(pari:equal? (pari:pari-isqrt #Z"4") #Z"2") T
(pari:equal? (pari:pari-isqrt #Z"10") #Z"3") T
(pari:equal? (pari:factorial-integer 10) #Z"3628800") T
(pari:pari-to-lisp (pari:gamma 10)) 362880.0L0
(pari:pari-to-lisp (pari:gamma-shift-1/2 9.5)) 362880.0L0

(pari:equal? (pari:best-rational-approximation (pari:pari-pi) #Z"100")
             #Z"22/7") T
(pari:equal? (pari:continued-fraction #Z"22/7") #Z"[3,7]") T
(pari:equal? (pari:best-rational-approximation (pari:pari-pi) #Z"10000")
             #Z"355/113") T
(pari:equal? (pari:continued-fraction #Z"355/113") #Z"[3,7,16]") T
(pari:pari-to-lisp (pari:continued-fraction (pari:pari-pi)))
#(:ROW 3 7 15 1 292 1 1 1 2 1 3 1 14 2 1 1 2 2)
(pari:pari-to-lisp (pari:continued-fraction (pari:euler)))
#(:ROW 0 1 1 2 1 2 1 4 3 13 5 1 1 8 1 2 4 1 1 41)
(pari:pari-to-lisp (pari:continued-fraction (exp 1l0)))
#(:ROW 2 1 2 1 1 4 1 1 6 1 1 8 1 1 10 1 1 12 1 1 14 2)

(pari:equal? (pari:fibonacci 10) #Z"55") T
(pari:pari-to-lisp (pari:fibonacci 100))  354224848179261915075
(pari:pari-to-lisp (pari:fibonacci 120))  5358359254990966640871840
(pari:equal? (pari:next-prime #Z"11") #Z"11") T
(pari:equal? (pari:next-prime #Z"15") #Z"17") T
(pari:equal? (pari:next-prime #Z"150") #Z"151") T
(pari:pari-to-lisp (pari:next-prime 1000)) 1009
(pari:pari-to-lisp (pari:next-prime 10000)) 10007
(pari:pari-to-lisp (pari:next-prime 100000)) 100003
(pari:pari-to-lisp (pari:next-prime (ash 1 70)))  1180591620717411303449
(pari:equal? (pari:nth-prime 100) #Z"541") T
(pari:equal? (pari:nth-prime 1000) #Z"7919") T
(pari:equal? (pari:nth-prime 10000) #Z"104729") T

(pari:equal? (pari:euler-phi #Z"6") #Z"2") T
(pari:equal? (pari:euler-phi #Z"13") #Z"12") T
(pari:pari-to-lisp (pari:euler-phi 28)) 12
(pari:pari-to-lisp (pari:euler-phi 130)) 48

(pari:equal? (pari:sum-divisors #Z"6") #Z"12") T
(pari:pari-to-lisp (pari:sum-divisors 28)) 56
(pari:pari-to-lisp (pari:factor #Z"120"))  #2A((2 3) (3 1) (5 1))
(pari:pari-to-lisp (pari:factor #Z"144"))  #2A((2 4) (3 2))
(pari:prime? 139 0) T
(pari:pseudo-prime? 140 0) NIL
(pari:bigomega 12) 3
(pari:omega 12) 2
(pari:bigomega 144) 6
(pari:omega 144) 2

(pari:pari-to-lisp (pari:resultant-vector 40 60)) #(:ROW 1/40 0 1)

(pari:equal? (pari:primitive-root #Z"7") #Z"Mod(3,7)") T
(pari:equal? (pari:primitive-root #Z"104729") #Z"Mod(12,104729)") T
(pari:pari-to-lisp (pari:primitive-root 100003))
#S(PARI:pari-integermod :MODULUS 100003 :REP 2)
(pari:pari-to-lisp (pari:primitive-root 1180591620717411303449))
#S(PARI:pari-integermod :MODULUS 1180591620717411303449 :REP 3)
(pari:pari-to-lisp (pari:primitive-root 3))
#S(PARI:pari-integermod :MODULUS 3 :REP 2)
(pari:pari-to-lisp (pari:primitive-root 7))
#S(PARI:pari-integermod :MODULUS 7 :REP 3)

(loop :repeat 5000 :with max
  :for prime = 2 :then (pari:pari-to-lisp (pari:next-prime (1+ prime)))
  :for primitive-root = (pari:pari-to-lisp (pari:primitive-root prime))
  :for primitive = (pari:pari-integermod-rep primitive-root)
  :do (assert (= prime (pari:pari-integermod-modulus primitive-root)))
  (unless (and max (>= (pari:pari-integermod-rep (car max)) primitive))
    (push primitive-root max))
  :finally (return (nreverse max)))
(#S(PARI:pari-integermod :MODULUS 2 :REP 1)
 #S(PARI:pari-integermod :MODULUS 3 :REP 2)
 #S(PARI:pari-integermod :MODULUS 7 :REP 3)
 #S(PARI:pari-integermod :MODULUS 23 :REP 5)
 #S(PARI:pari-integermod :MODULUS 41 :REP 6)
 #S(PARI:pari-integermod :MODULUS 71 :REP 7)
 #S(PARI:pari-integermod :MODULUS 191 :REP 19)
 #S(PARI:pari-integermod :MODULUS 409 :REP 21)
 #S(PARI:pari-integermod :MODULUS 2161 :REP 23)
 #S(PARI:pari-integermod :MODULUS 5881 :REP 31)
 #S(PARI:pari-integermod :MODULUS 36721 :REP 37))

(pari:equal? (pari:structure-of-z/n* #Z"7") #Z"[6, [6], [Mod(3, 7)]]") T
(pari:equal? (pari:structure-of-z/n* #Z"10") #Z"[4, [4], [Mod(7, 10)]]") T
(pari:pari-to-lisp (pari:structure-of-z/n* 12))
#(:ROW 4 #(:ROW 2 2)
  #(:ROW #S(PARI:pari-integermod :MODULUS 12 :REP 7)
    #S(PARI:pari-integermod :MODULUS 12 :REP 5)))
(pari:pari-to-lisp (pari:structure-of-z/n* 24))
#(:ROW 8 #(:ROW 2 2 2)
  #(:ROW #S(PARI:pari-integermod :MODULUS 24 :REP 13)
    #S(PARI:pari-integermod :MODULUS 24 :REP 19)
    #S(PARI:pari-integermod :MODULUS 24 :REP 17)))

(pari:pari-to-lisp (pari:chinese-lift
                    #S(PARI:pari-integermod :MODULUS 10 :REP 7)
                    #S(PARI:pari-integermod :MODULUS 12 :REP 5)))
#S(PARI:pari-integermod :MODULUS 60 :REP 17)
(pari:pari-to-lisp (pari:chinese-lift
                    #S(PARI:pari-integermod :MODULUS 10 :REP 7)
                    #S(PARI:pari-integermod :MODULUS 3 :REP 4)))
#S(PARI:pari-integermod :MODULUS 30 :REP 7)

(pari:pari-to-lisp (pari:discriminant #Z"x^2-1")) 4
(pari:pari-to-lisp (pari:resultant #Z"x^2-1" #Z"x^3")) -1

(pari:pari-to-lisp (pari:divisors #Z"121")) #(:ROW 1 11 121)
(pari:pari-to-lisp (pari:divisors #Z"122")) #(:ROW 1 2 61 122)
(pari:pari-to-lisp (pari:divisors #Z"120"))
#(:ROW 1 2 3 4 5 6 8 10 12 15 20 24 30 40 60 120)
(pari:pari-to-lisp (pari:divisors #Z"144"))
#(:ROW 1 2 3 4 6 8 9 12 16 18 24 36 48 72 144)

(pari:pari-to-lisp #Z"104")  104
(pari:pari-to-lisp #Z"[1,0,0;0,1,0;0,0,1]")
#2A((1 0 0) (0 1 0) (0 0 1))

(pari:pari-to-lisp (pari:pari-gcd 35 49))  7
(pari:pari-to-lisp (pari:pari-xgcd 35 49)) #(:ROW 3 -2 7)
(pari:pari-to-lisp (pari:pari-lcm 35 49))  245

(pari:pari-to-lisp (pari:binomial-coefficient 3 1)) 3
(pari:pari-to-lisp (pari:binomial-coefficient 30 10)) 30045015
(pari:pari-to-lisp (pari:binomial-coefficient 300 10)) 1398320233241701770

(pari:equal? (pari:legendre-polynomial 0) #Z"1") T
(pari:equal? (pari:legendre-polynomial 1) #Z"x") T
(pari:equal? (pari:legendre-polynomial 2) #Z"3/2*x^2 - 1/2") T
(pari:equal? (pari:legendre-polynomial 3) #Z"5/2*x^3 - 3/2*x") T
(pari:equal? (pari:legendre-polynomial 4) #Z"35/8*x^4 - 15/4*x^2 + 3/8") T
(pari:equal? (pari:legendre-polynomial 5) #Z"63/8*x^5 - 35/4*x^3 + 15/8*x") T
(let ((legendre6 (pari:legendre-polynomial 6)))
  (multiple-value-bind (primpart content)
      (pari:primitive-part legendre6)
    (list (pari:equal? (pari:pari* primpart content) legendre6)
          (pari:equal? primpart (pari:primpart legendre6))
          (pari:pari-to-lisp content))))
(T T 1/16)
(pari:pari-to-lisp (pari:content (pari:legendre-polynomial 7)))  1/16
(pari:pari-to-lisp (pari:content (pari:legendre-polynomial 8)))  1/128
(pari:pari-to-lisp (pari:content (pari:legendre-polynomial 9)))  1/128
(pari:pari-to-lisp (pari:content (pari:legendre-polynomial 10)))  1/256

(pari:equal? (pari:tchebychev-polynomial 0) #Z"1") T
(pari:equal? (pari:tchebychev-polynomial 1) #Z"x") T
(pari:equal? (pari:tchebychev-polynomial 2) #Z"2*x^2 - 1") T
(pari:equal? (pari:tchebychev-polynomial 3) #Z"4*x^3 - 3*x") T
(pari:equal? (pari:tchebychev-polynomial 4) #Z"8*x^4 - 8*x^2 + 1") T
(pari:equal? (pari:tchebychev-polynomial 5) #Z"16*x^5 - 20*x^3 + 5*x") T
(let ((tchebychev6 (pari:tchebychev-polynomial 6)))
  (multiple-value-bind (primpart content) (pari:primitive-part tchebychev6)
    (list (pari:equal? primpart tchebychev6)
          (pari:equal? primpart (pari:primpart tchebychev6))
          (pari:pari-to-lisp content))))
(T T NIL)                       ; NIL means 1
(pari:pari-to-lisp (pari:content (pari:tchebychev-polynomial 7)))  1
(pari:pari-to-lisp (pari:content (pari:tchebychev-polynomial 8)))  1
(pari:pari-to-lisp (pari:content (pari:tchebychev-polynomial 9)))  1
(pari:pari-to-lisp (pari:content (pari:tchebychev-polynomial 10))) 1
(pari:irreducible? (pari:tchebychev-polynomial 8))  T
(pari:irreducible? (pari:tchebychev-polynomial 16)) T
(pari:irreducible? (pari:tchebychev-polynomial 32)) T
(pari:irreducible? (pari:tchebychev-polynomial 64)) T

(pari:pari-to-lisp (pari:factor #z"x^3"))
#2A((#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(0 1)) 3))
(pari:pari-to-lisp (pari:factor (pari:tchebychev-polynomial 11)))
#2A((#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(0 1)) 1)
    (#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS
        #(-11 0 220 0 -1232 0 2816 0 -2816 0 1024)) 1))

(pari:pari-to-lisp (pari:hilbert-matrix 4))
#2A((1 1/2 1/3 1/4) (1/2 1/3 1/4 1/5) (1/3 1/4 1/5 1/6) (1/4 1/5 1/6 1/7))
(pari:pari-to-lisp (pari:hilbert-matrix 7))
#2A((1 1/2 1/3 1/4 1/5 1/6 1/7)
    (1/2 1/3 1/4 1/5 1/6 1/7 1/8)
    (1/3 1/4 1/5 1/6 1/7 1/8 1/9)
    (1/4 1/5 1/6 1/7 1/8 1/9 1/10)
    (1/5 1/6 1/7 1/8 1/9 1/10 1/11)
    (1/6 1/7 1/8 1/9 1/10 1/11 1/12)
    (1/7 1/8 1/9 1/10 1/11 1/12 1/13))

(pari:pari-to-lisp (pari:pascal-triangle 10 nil))
#2A((1 0 0 0 0 0 0 0 0 0 0)
    (1 1 0 0 0 0 0 0 0 0 0)
    (1 2 1 0 0 0 0 0 0 0 0)
    (1 3 3 1 0 0 0 0 0 0 0)
    (1 4 6 4 1 0 0 0 0 0 0)
    (1 5 10 10 5 1 0 0 0 0 0)
    (1 6 15 20 15 6 1 0 0 0 0)
    (1 7 21 35 35 21 7 1 0 0 0)
    (1 8 28 56 70 56 28 8 1 0 0)
    (1 9 36 84 126 126 84 36 9 1 0)
    (1 10 45 120 210 252 210 120 45 10 1))
(pari:pari-to-lisp (pari:pascal-triangle 10 2))
#2A((1 0 0 0 0 0 0 0 0 0 0)
    (1 1 0 0 0 0 0 0 0 0 0)
    (1 3 1 0 0 0 0 0 0 0 0)
    (1 7 7 1 0 0 0 0 0 0 0)
    (1 15 35 15 1 0 0 0 0 0 0)
    (1 31 155 155 31 1 0 0 0 0 0)
    (1 63 651 1395 651 63 1 0 0 0 0)
    (1 127 2667 11811 11811 2667 127 1 0 0 0)
    (1 255 10795 97155 200787 97155 10795 255 1 0 0)
    (1 511 43435 788035 3309747 3309747 788035 43435 511 1 0)
    (1 1023 174251 6347715 53743987 109221651 53743987 6347715 174251 1023 1))
(pari:pari-to-lisp (pari:pascal-triangle 7 3))
#2A((1 0 0 0 0 0 0 0)
    (1 1 0 0 0 0 0 0)
    (1 4 1 0 0 0 0 0)
    (1 13 13 1 0 0 0 0)
    (1 40 130 40 1 0 0 0)
    (1 121 1210 1210 121 1 0 0)
    (1 364 11011 33880 11011 364 1 0)
    (1 1093 99463 925771 925771 99463 1093 1))

(pari:pari-to-lisp (pari:permutation 10 3)) #(:ROW 10 9 8 7 6 5 4 1 3 2)
(pari:pari-to-lisp (pari:permutation-number #(:ROW 10 9 8 7 6 5 4 1 3 2))) 3
(pari:pari-to-lisp (pari:permutation 9 30)) #(:ROW 9 8 7 6 3 5 4 2 1)
(pari:pari-to-lisp (pari:permutation-number #(:ROW 9 8 7 6 3 5 4 2 1))) 30

(pari:set-random-seed 10) 10
(pari:get-random-seed) 10

(integerp (show (pari:getstack))) T
(integerp (show (pari:gettime))) T
(svref (show (pari:pari-to-lisp (pari:getheap))) 0) :ROW

(integerp (show (pari:maxprime))) T

(pari:pari-to-lisp (pari:tchebychev-polynomial 4))
#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 0 -8 0 8))

(pari:pari-to-lisp (pari:tchebychev-polynomial 40))
#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS
   #(1 0 -800 0 106400 0 -5617920 0 156900480 0 -2677768192 0 30429184000
     0 -243433472000 0 1424085811200 0 -6254808268800 0 21002987765760 0
     -54553214976000 0 110292369408000 0 -173752901959680 0 212364657950720
     0 -199183403319296 0 140552804761600 0 -72155450572800 0 25426206392320
     0 -5497558138880 0 549755813888))

(pari:pari-to-lisp (pari:complex-roots #z"x^2+1"))
#(:COL #C(0 1.0L0) #C(0 -1.0L0))
(pari:pari-to-lisp (pari:symmetric-powers #z"x^2+1" 4))
#(:COL 2 0 -2 0 2)
(pari:pari-to-lisp (pari:symmetric-powers (pari:tchebychev-polynomial 30) 30))
#(:COL 30 0 15 0 45/4 0 75/8 0 525/64 0 945/128 0 3465/512 0 6435/1024 0
  96525/16384 0 182325/32768 0 692835/131072 0 1322685/262144 0
  10140585/2097152 0 19501125/4194304 0 75218625/16777216 0 145422675/33554432)
(pari:pari-to-lisp (pari:symmetric-powers (pari:legendre-polynomial 12) 12))
#(:COL 12 0 132/23 0 15444/3703 0 5477076/1618211 0 12809498724/4429043507 0
  259405490124/101868000661 0 9262490692392036/4050984782285987)

(let ((order (pari:variable-order #())))
  (list (pari:pari-to-lisp order) (princ-to-string order)))
(#(:ROW #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(0 1))) "#Z\"[x]\"")

(pari:pari-to-lisp (pari:bernoulli-vector 9))
#(:ROW 1 1/6 -1/30 1/42 -1/30 5/66 -691/2730 7/6 -3617/510 43867/798)

(pari:pari-sign 2) 1
(pari:pari-sign -10) -1
(pari:pari-sign 0) 0
(pari:pari-sign 0l0) 0
(pari:pari-sign 1f0) 1
(pari:pari-sign -1d0) -1

(pari:pari-to-lisp (pari:vector-index-sort #(10 40 30 20))) #(:ROW 1 4 3 2)
(pari:pari-to-lisp (pari:vector-sort #(10 40 30 20))) #(:ROW 10 20 30 40)
(pari:pari-to-lisp (pari:vector-sort-key #(#(1 10) #(2 40) #(3 30) #(4 20)) 2))
#(:ROW #(:ROW 1 10) #(:ROW 4 20) #(:ROW 3 30) #(:ROW 2 40))

pari:pari-real-precision  19
(length (prin1-to-string (pari:pari-to-lisp (pari:pari-pi))))  23
(length (prin1-to-string (pari:pari-to-lisp (pari:pari-pi :prec 38)))) 41
(loop :for n :from 3 :to 50
  :unless (= (- n 2) (length (pari::pari-mantissa (pari::%pari-pi n))))
  :collect n)
()
(loop :for n :from 3 :to 50
  :for mypi0 = (pari:pari-to-lisp (pari:pari-pi :prec n))
  :for mypi1 = (pari::convert-from-pari (pari::convert-to-pari mypi0))
  :unless (= mypi0 mypi1) :collect (list n mypi0 mypi1))
()
(= pi (pari:pari-to-lisp (pari:pari-pi))) T

(pari:pari-to-lisp #Z"(1-x)^2/(1+x)^2")
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 -2 1))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 2 1)))
(pari:pari-to-lisp (pari:derivative #Z"(1-x)^2/(1+x)^2"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-4 4))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 3 3 1)))
(pari:pari-to-lisp (pari:derivative #Z"1/(1+x)"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-1))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 2 1)))
(pari:pari-to-lisp (pari:derivative #Z"-1/(x^2 + 2*x + 1)"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(2))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 3 3 1)))
(pari:pari-to-lisp (pari:derivative #Z"2/(x^3 + 3*x^2 + 3*x + 1)"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-6))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 4 6 4 1)))
(pari:pari-to-lisp (pari:derivative #Z"-6/(x^4 + 4*x^3 + 6*x^2 + 4*x + 1)"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(24))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 5 10 10 5 1)))
(pari:pari-to-lisp (pari:integral #Z"-6/(x^4 + 4*x^3 + 6*x^2 + 4*x + 1)"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(2))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 3 3 1)))
(pari:pari-to-lisp (pari:integral #Z"2/(x^3 + 3*x^2 + 3*x + 1)"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-1))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 2 1)))
(pari:pari-to-lisp (pari:integral #Z"-1/(x^2 + 2*x + 1)"))
#S(PARI:pari-ratfun :NUMER #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1))
   :DENOM #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(1 1)))

(pari:pari-to-lisp (pari:taylor-expansion #Z"1/(1+x)^2" :precdl 7))
#S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 0 :COEFFS #(1 -2 3 -4 5 -6 7))
(pari:pari-to-lisp (pari:taylor-expansion #Z"(1-x)^2/(1+x)^2" :precdl 7))
#S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 0 :COEFFS #(1 -4 8 -12 16 -20 24))
(pari:pari-to-lisp (pari:pws-reverse #S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 1 :COEFFS #(1 -4 8 -12 16 -20 24))))
#S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 1 :COEFFS #(1 4 24 172 1360 11444 100520))
(pari:pari-to-lisp (pari:taylor-expansion #Z"x/(1+x)^2" :precdl 7))
#S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 1 :COEFFS #(1 -2 3 -4 5 -6))
(pari:pari-to-lisp (pari:pws-reverse (pari:taylor-expansion #Z"x/(1+x)^3" :precdl 7)))
#S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 1 :COEFFS #(1 3 12 55 273 1428))
(pari:pari-to-lisp (pari:pari* #Z"1+x" (pari:taylor-expansion #Z"1/(1+x)" :precdl 7)))
#S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 0 :COEFFS #(1 0 0 0 0 0 0))
(pari:pari-to-lisp (pari:pws-reverse #Z"sin(x)"))
#S(PARI:pari-pws :S 1 :VARNO 0 :EXPO 1 :COEFFS
   #(1 0 1/6 0 3/40 0 5/112 0 35/1152 0 63/2816 0 231/13312 0 143/10240 0))

(pari:pari-to-lisp (pari:quadratic-unit 17))
#S(PARI:pari-quadratic :POLY #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-4 -1 1))
   :REALPART 3 :IMAGPART 2)
(pari:pari-to-lisp (pari:quadratic-unit 512))
#S(PARI:pari-quadratic :REALPART 577 :IMAGPART 51
   :POLY #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-128 0 1)))
(pari:pari-to-lisp (pari:quadratic-unit 513))
#S(PARI:pari-quadratic :REALPART 13163331 :IMAGPART 1216040
   :POLY #S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-128 -1 1)))
(pari:pari-to-lisp (pari:quadratic-regulator 5)) 0.4812118250596034475L0
(pari:pari-to-lisp (pari:quadratic-regulator 512)) 7.0509886961563442015L0
(pari:pari-to-lisp (pari:quad-minimal-polynomial 513))
#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-128 -1 1))
(pari:pari-to-lisp (pari:quad-minimal-polynomial 512))
#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-128 0 1))
(pari:pari-to-lisp (pari:quad-minimal-polynomial 5))
#S(PARI:pari-poly :S 1 :VARNO 0 :COEFFS #(-1 -1 1))
(pari:pari-to-lisp (pari:quad-discriminant 5)) 5
(pari:pari-to-lisp (pari:quad-discriminant 512)) 8
(pari:pari-to-lisp (pari:quad-discriminant 513)) 57

(defparameter qfi (show (pari:pari-to-lisp (pari:make-imag-qf 1 2 3)))) QFI
(pari:pari-to-lisp (pari:qfi-composition qfi))
#S(PARI:pari-imag-qf :A 1 :B 0 :C 2)
(pari:pari-to-lisp (pari:reduce-imag-qf qfi))
#S(PARI:pari-imag-qf :A 1 :B 0 :C 2)
(pari:square? qfi) T
(defparameter qfr (show (pari:pari-to-lisp (pari:make-real-qf 1 2 3 0.0)))) QFR
;; PARI stack overflows (pari:pari-to-lisp (pari:qfr-composition qfr))
;; PARI stack overflows (pari:pari-to-lisp (pari:reduce-real-qf qfr))
;; PARI stack overflows (pari:pari-to-lisp (pari:reduce-real-qf-one-step qfr))
(pari:square? qfr) T

;; done, print type conversion statistics
(let ((alist (sort (ext:with-collect (co)
                     (with-hash-table-iterator
                         (iter (get 'pari:pari-typecode 'ffi:def-c-enum))
                       (loop (multiple-value-bind (re kk vv) (iter)
                               (unless re (return))
                               (co (cons kk vv))))))
                   #'< :key #'car)))
  (flet ((show-coverage (title table)
           (format t "~A:~%" title)
           (dolist (pair alist)
             (format t " ~3D ~8A   ~:D~%" (car pair) (cdr pair)
                     (gethash (car pair) table)))))
    (format t "~&Type Conversion Coverage~%")
    (show-coverage "LISP --> PARI" *lisp-to-pari*)
    (show-coverage "PARI --> LISP" *pari-to-lisp*)))
NIL
