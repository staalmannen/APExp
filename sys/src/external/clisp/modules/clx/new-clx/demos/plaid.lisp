;;;; Plaid

;;; Adapted from http://www.cs.cmu.edu/afs/cs/project/ai-repository/ai/lang/lisp/gui/clx/clx_demo.cl by...
;;; Copyright (C) 2007-2008 Sam Steingold <sds@gnu.org>
;;; GPL2 is applicable

(in-package :clx-demos)

(defmacro rect-x (rects n)
  `(svref ,rects (ash ,n 2)))
(defmacro rect-y (rects n)
  `(svref ,rects (+ (ash ,n 2) 1)))
(defmacro rect-width (rects n)
  `(svref ,rects (+ (ash ,n 2) 2)))
(defmacro rect-height (rects n)
  `(svref ,rects (+ (ash ,n 2) 3)))

(defun plaid (&key (num-iterations 10000) (num-rectangles 10) (sleep 0.1)
              (x 10) (y 10) (width 101) (height 201))
  "Translated from the X11 Plaid Demo written in C by Christopher Hoover."
  (xlib:with-open-display (dpy)
    (let* ((screen (xlib:display-default-screen dpy))
           (root (xlib:screen-root screen))
           (white-pixel (xlib:screen-white-pixel screen))
           (black-pixel (xlib:screen-black-pixel screen))
           (window (xlib:create-window
                    :parent root :width width :height height :x x :y y
                    :event-mask '(:exposure :button-press :button-release
                                  :key-press :key-release)
                    :background white-pixel))
           (gcontext (xlib:create-gcontext :drawable window
                                           :function boole-c2
                                           :plane-mask (logxor white-pixel
                                                               black-pixel)
                                           :background white-pixel
                                           :foreground black-pixel
                                           :fill-style :solid))
           (rectangles (make-array (* 4 num-rectangles) :initial-element 0))
           (center-x (ash width -1))
           (center-y (ash height -1))
           (niter (truncate num-iterations num-rectangles))
           (x-dir -2)
           (y-dir -2)
           (x-off 2)
           (y-off 2))
      (format t "~&Relax for ~:D second~:P and enjoy...~%"
              (round (* sleep niter)))
      (xlib:map-window window)
      (xlib:display-finish-output dpy)
      (dotimes (iter niter)
        (dotimes (i num-rectangles)
          (setf (rect-x rectangles i) (- center-x x-off))
          (setf (rect-y rectangles i) (- center-y y-off))
          (setf (rect-width rectangles i) (ash x-off 1))
          (setf (rect-height rectangles i) (ash y-off 1))
          (incf x-off x-dir)
          (incf y-off y-dir)
          (when (or (<= x-off 0) (>= x-off center-x))
            (decf x-off (ash x-dir 1))
            (setf x-dir (- x-dir)))
          (when (or (<= y-off 0) (>= y-off center-y))
            (decf y-off (ash y-dir 1))
            (setf y-dir (- y-dir))))
        (xlib:draw-rectangles window gcontext rectangles t)
        (xlib:display-force-output dpy)
        (sleep sleep))
      (xlib:free-gcontext gcontext)
      (xlib:unmap-window window)
      (xlib:display-finish-output dpy))))

(provide "plaid")
