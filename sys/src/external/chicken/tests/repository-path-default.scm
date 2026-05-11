(import (chicken platform))

(include "test.scm")

(print (repository-path))
(test-assert "(repository-path) contains something by default"
  (= 1 (length (repository-path))))

(test-exit)
