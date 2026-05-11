;; both arms of if branches are dropped

(let ((a "yep")) (if (string? a) 'ok 'no))
(let ((a 'nope)) (if (string? a) 'ok 'no))

;; bidirectional ports are specialized

(let ((p (open-input-string "foo")))
  (when (output-port? p) ; indicates `p' is bidirectional
     (if (input-port? p) 'ok 'no)
     (if (output-port? p) 'ok 'no)))
