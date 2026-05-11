
;;;; test-glob.scm

;; test glob-pattern -> regex translation

(import (chicken irregex))

(assert (irregex-match (glob->sre "foo.bar") "foo.bar"))
(assert (irregex-match (glob->sre "foo*") "foo.bar"))
(assert (irregex-match (glob->sre "foo/*") "foo/bar"))
(assert (not (irregex-match (glob->sre "foo/*") "foo/bar/baz")))
(assert (irregex-match (glob->sre "foo/*/*") "foo/bar/baz"))
(assert (not (irregex-match (glob->sre "foo/*") "foo/.bar")))
(assert (irregex-match (glob->sre "*foo") "xyzfoo"))
(assert (not (irregex-match (glob->sre "*foo") ".foo")))
(assert (not (irregex-match (glob->sre "*foo*") "a.fooxxx/yyy")))
(assert (irregex-match (glob->sre "*foo*") "fooxxx"))
(assert (irregex-match (glob->sre "main.[ch]") "main.c"))
(assert (irregex-match (glob->sre "main.[ch]") "main.h"))
(assert (not (irregex-match (glob->sre "main.[ch]") "main.cpp")))
(assert (irregex-match (glob->sre "main.[-c]") "main.h"))
(assert (not (irregex-match (glob->sre "main.[-h]") "main.h")))

;; test file globbing

(import (chicken file))

(assert (pair? (glob "../tests")))
(assert (pair? (glob "../tests/*")))
(assert (null? (glob "../nowhere")))
(assert (null? (glob "../nowhere/*")))
