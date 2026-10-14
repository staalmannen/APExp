;;;; Bounce window.

;;; Adapted from http://www.cs.cmu.edu/afs/cs/project/ai-repository/ai/lang/lisp/gui/clx/clx_demo.cl by...
;;; Copyright (C) 2007-2008 Sam Steingold <sds@gnu.org>
;;; GPL2 is applicable

(in-package :clx-demos)

(defun bwindow (&key (x-velocity 3) (elasticity 0.85) (gravity 2)
                (x 10) (y 10) (width 300) (height 300))
  "BOUNCE-WINDOW seemingly drops a window to the bottom of the screen.
Optionally, the window can have an initial x velocity,
screen border elasticity, and gravity value."
  ;; The outer loop is entered the first time with the window at its initial
  ;; height, but each iteration after this, the loop starts with the window
  ;; at the bottom of the screen heading upward.
  ;; The inner loop, except for the first execution, carries the window up
  ;; until the negative velocity becomes positive, carrying the window down
  ;; to bottom when the velocity is positive.
  ;; Due to number lossage, ROUND'ing and TRUNC'ing when the velocity gets
  ;; so small will cause the window to head upward with the same velocity
  ;; over two iterations which will cause the window to bounce forever,
  ;; so we have prev-neg-velocity and number-problems to check for this.
  ;; This is not crucial with the x velocity since the loop terminates
  ;; as a function of the y velocity.
  (assert (< 0 elasticity 1) (elasticity)
          "Elasticity must be between 0 and 1, got ~S" elasticity)
  (assert (plusp gravity) (gravity)
          "Gravity must be positive, got ~S" gravity)
  (xlib:with-open-display (dpy)
    (let* ((screen (xlib:display-default-screen dpy))
           (root (xlib:screen-root screen))
           (white-pixel (xlib:screen-white-pixel screen))
           ;; (black-pixel (xlib:screen-black-pixel screen))
           (window (xlib:create-window
                    :parent root :width width :height height
                    :event-mask '(:exposure :button-press :button-release
                                  :key-press :key-release)
                    :x x :y y :background white-pixel))
           (top-of-window-at-bottom (- (xlib:drawable-height root) height))
           (left-of-window-at-right (- (xlib:drawable-width root) width))
           (y-velocity 0)
           (prev-neg-velocity most-negative-fixnum)
           (number-problems nil))
      (declare (fixnum top-of-window-at-bottom left-of-window-at-right
                       y-velocity))
      (xlib:map-window window)
      (xlib:display-finish-output dpy)
      (loop (when (= prev-neg-velocity 0) (return t))
        (let ((negative-velocity (minusp y-velocity)))
          (loop
            (let ((next-y (+ y y-velocity))
                  (next-y-velocity (+ y-velocity gravity)))
              (declare (fixnum next-y next-y-velocity))
              (when (> next-y top-of-window-at-bottom)
                (cond
                  (number-problems
                   (setf y-velocity (incf prev-neg-velocity)))
                  (t
                   (setq y-velocity
                         (- (truncate (* elasticity y-velocity))))
                   (when (= y-velocity prev-neg-velocity)
                     (incf y-velocity)
                     (setf number-problems t))
                   (setf prev-neg-velocity y-velocity)))
                (setf y top-of-window-at-bottom)
                (setf (xlib:drawable-x window) x
                      (xlib:drawable-y window) y)
                (xlib:display-force-output dpy)
                (return))
              (setq y-velocity next-y-velocity)
              (setq y next-y))
            (when (and negative-velocity (>= y-velocity 0))
              (setf negative-velocity nil))
            (let ((next-x (+ x x-velocity)))
              (declare (fixnum next-x))
              (when (or (> next-x left-of-window-at-right)
                        (< next-x 0))
                (setq x-velocity (- (truncate (* elasticity x-velocity)))))
              (setq x next-x))
            (setf (xlib:drawable-x window) x
                  (xlib:drawable-y window) y)
            (xlib:display-force-output dpy))))
      (xlib:unmap-window window)
      (xlib:display-finish-output dpy))))

(provide "bwindow")
