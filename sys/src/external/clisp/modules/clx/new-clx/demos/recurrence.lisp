;;;; Recurrence Demo

;;; Copyright (C) 1988 Michael O. Newton (newton@csvax.caltech.edu)
;;; Permission is granted to any individual or institution to use, copy,
;;; modify, and distribute this software, provided that this complete
;;; copyright and permission notice is maintained, intact, in all copies and
;;; supporting documentation.
;;; The author provides this software "as is" without express or
;;; implied warranty.

;;; Adapted from http://www.cs.cmu.edu/afs/cs/project/ai-repository/ai/lang/lisp/gui/clx/clx_demo.cl by...
;;; Copyright (C) 2007-2008 Sam Steingold <sds@gnu.org>
;;; GPL2 is applicable

(in-package :clx-demos)

;;; Draw points.  X assumes points are in the range of width x height,
;;; with 0,0 being upper left and 0,H being lower left.
;;; hw and hh are half-width and half-height of screen

(defun draw-ppict (win gc count x y hw hh)
  "Recursively draw pretty picture"
  (declare (compile))           ; to avoid stack overflow
  (unless (zerop count)
    (let ((xf (floor (* (+ 1.0 x) hw ))) ;These lines center the picture
          (yf (floor (* (+ 0.7 y) hh ))))
      (xlib:draw-point win gc xf yf)
      (draw-ppict win gc (1- count)
                  (- (* y (1+ (sin (* 0.7 x)))) (* 1.2 (sqrt (abs x))))
                  (- 0.21 x)
                  hw
                  hh))))

(defun recurrence (&key (point-count 10000) (sleep 4)
                   (x 10) (y 10) (width 700) (height 700))
  "Plot the recurrence
      x <- y(1+sin(0.7x)) - 1.2(|x|)^.5
      y <- .21 - x
As described in a ?? 1983 issue of the Mathematical Intelligencer."
  (xlib:with-open-display (dpy)
    (let* ((screen (xlib:display-default-screen dpy))
           (root (xlib:screen-root screen))
           (white-pixel (xlib:screen-white-pixel screen))
           (black-pixel (xlib:screen-black-pixel screen))
           (win (xlib:create-window
                 :parent root :x x :y y :width width :height height
                 :event-mask '(:exposure :button-press :button-release
                               :key-press :key-release)
                 :background white-pixel))
           (gc (xlib:create-gcontext :drawable win
                                     :background white-pixel
                                     :foreground black-pixel)))
      (xlib:map-window win)
      (draw-ppict win gc point-count 0.0 0.0 (* width 0.5) (* height 0.5))
      (xlib:display-force-output dpy)
      (sleep sleep)
      (xlib:free-gcontext gc)
      (xlib:unmap-window win)
      (xlib:display-finish-output dpy))))

(provide "recurrence")
