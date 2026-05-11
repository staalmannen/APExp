(import (chicken platform)
        (chicken process-context)
        (chicken condition))

(include "test.scm")

(test-equal "find-file on #f"
  (chicken.load#find-file "repository-path.scm" #f)
  #f)

(test-equal "find-file on string"
  (chicken.load#find-file "repository-path.scm" ".")
  "./repository-path.scm")

(test-equal "find-file on list"
  (chicken.load#find-file "repository-path.scm" '(".." "."))
  "./repository-path.scm")

(test-equal "(repository-path) is populated by CHICKEN_REPOSITORY_PATH"
  (repository-path)
  (command-line-arguments))

(repository-path
  (cons (get-environment-variable "CHICKEN_INSTALL_REPOSITORY")
        (repository-path)))

(test-assert "setting (repository-path) and loading a library"
  (handle-exceptions exn #f (begin (require-library sample-module) #t)))

(test-error "Putting garbage in (repository-path)"
  (repository-path '(foo)))

(test-exit)
