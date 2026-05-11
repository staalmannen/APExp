;;; Tests linking with core units & extensions ("csc -link ...")

(import (chicken irregex)
	(reverser))

(unless (irregex-match '(: #\1 (+ any) #\9) (rev "987654321"))
  (error "weird"))
