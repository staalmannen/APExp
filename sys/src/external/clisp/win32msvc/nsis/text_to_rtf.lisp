;; convert plain text to RTF
;; this is geared for the CLISP COPYRIGHT file, specifically:
;;  - add {\b @NAME@ @VERSION@} in the beginning
;;  - use "Courier New" (fixed width) font to preserve formatting
;;  - convert UTF-8 to RTF Unicode escapes
;;  - mark lines with text in the first column as bold
;;
;; Copyright (C) Elliott Slaughter 2007
;; Copyright (C) Sam Steingold 2007
;; Released under the GNU GPLv2+

(defun write-string-rtf (string out)
  ;; unicode chars are represented as \u<decimal>.
  ;; alas, CHARSET:JAVA uses \u<hexadecimal> so it is of no help.
  ;; non-unicode RTF viewers will display "?"
  (let ((plain (or (string= "" string)
                   (char= #\Space (char string 0)))))
    (unless plain (write-string "{\\b " out))
    (loop :with start = 0
      :for pos = (position 128 string :start start :key #'char-code :test #'<=)
      :if pos :do
      (write-string string out :start start :end pos)
      (format out "\\u~D?" (char-code (char string pos)))
      (setq start (1+ pos))
      :else :do (write-string string out :start start)
      (loop-finish))
    (unless plain (write-string "}" out))
    (write-line "\\line" out)))

(defun text2rtf (input output)
  (with-open-file (in input :direction :input :external-format charset:utf-8)
    (format t "~&Reading ~:D byte~:P from [~A]~%"
            (file-length in) (truename in))
    (with-open-file (out (or output (make-pathname :type "rtf" :defaults in))
                         :direction :output :if-exists :supersede
                         ;; use ASCII to get an error if we miss something
                         :external-format charset:ascii)
      (write-line "{\\rtf1\\ansi\\ansicpg1252\\deff0{\\fonttbl{\\f0\\fswiss\\fprq2\\fcharset0 Courier New;}{\\f1\\fswiss\\fcharset0 Courier New;}}\\line
\\viewkind4\\uc1\\pard\\lang1033\\f0\\fs18                               {\\b @NAME@ @VERSION@}\\line" out)
      (loop :for line = (read-line in nil nil) :while line
        :unless (search "-*-" line) ; strip emace cookies
        :do (write-string-rtf line out))
      (write-line "}" out)
      (format t "~&Wrote ~:D byte~:P to [~A]~%"
              (file-length out) (truename out)))))

(text2rtf (first *args*) (second *args*))
