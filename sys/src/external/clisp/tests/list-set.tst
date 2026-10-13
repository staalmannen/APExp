;; -*- Lisp -*- vim:filetype=lisp

(set-difference '(a b c) '(a))
(b c)

(set-difference (loop :for i :from 1 :to 100 :collect i)
                (loop :for i :from 1 :to 99 :collect i)
                :test 'equalp)
(100)

(intersection '(1 2 3) '(a b c)) ()
(intersection '(1 2 3) '(2 3 4)) (2 3)

(union '(1 2 3) '(a b c))  (1 2 3 A B C)
(union '(1 2 3) '(2 3 4))  (1 2 3 4)

(set-exclusive-or (loop :for i :from 1 :to 100 :collect i)
                  (loop :for i :from 2 :to 99 :collect i))
(1 100)
(set-exclusive-or (loop :for i :from 1 :to 100 :collect (princ-to-string i))
                  (loop :for i :from 2 :to 99 :collect (princ-to-string i))
                  :test #'equalp)
("1" "100")

(subsetp (loop :for i :from 1 :to 100 :collect i)
         (loop :for i :from 1 :to 99 :collect i))
NIL
(subsetp (loop :for i :from 1 :to 99 :collect i)
         (loop :for i :from 1 :to 100 :collect i))
T
