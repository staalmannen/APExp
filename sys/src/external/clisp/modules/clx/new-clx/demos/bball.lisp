;;;; Bball demo
;;; Ported to CLX by Blaine Burks

;;; Adapted from http://www.cs.cmu.edu/afs/cs/project/ai-repository/ai/lang/lisp/gui/clx/clx_demo.cl by...
;;; Copyright (C) 2007-2008 Sam Steingold <sds@gnu.org>
;;; GPL2 is applicable

(in-package :clx-demos)

(defconstant +bball-bitmap+
  '(#*000000000000000000000000000000000000
    #*000000000000000000000000000000000000
    #*000000000000000000001000000010000000
    #*000000000000000000000000000100000000
    #*000000000000000000000100001000000000
    #*000000000000000010000000010000000000
    #*000000000000000000100010000000000000
    #*000000000000000000001000000000000000
    #*000000000001111100000000000101010000
    #*000000000010000011000111000000000000
    #*000000000100000000111000000000000000
    #*000000000100000000000000000100000000
    #*000000000100000000001000100010000000
    #*000000111111100000010000000001000000
    #*000000111111100000100000100000100000
    #*000011111111111000000000000000000000
    #*001111111111111110000000100000000000
    #*001111111111111110000000000000000000
    #*011111111111111111000000000000000000
    #*011111111111111111000000000000000000
    #*111111111111110111100000000000000000
    #*111111111111111111100000000000000000
    #*111111111111111101100000000000000000
    #*111111111111111101100000000000000000
    #*111111111111111101100000000000000000
    #*111111111111111111100000000000000000
    #*111111111111110111100000000000000000
    #*011111111111111111000000000000000000
    #*011111111111011111000000000000000000
    #*001111111111111110000000000000000000
    #*001111111111111110000000000000000000
    #*000011111111111000000000000000000000
    #*000000111111100000000000000000000000
    #*000000000000000000000000000000000000))

(defconstant +bball-size-x+ (length (first +bball-bitmap+)))
(defconstant +bball-size-y+ (length +bball-bitmap+))

(defmacro xor-ball (pixmap window gcontext x y)
  `(xlib:copy-area ,pixmap ,gcontext 0 0 +bball-size-x+ +bball-size-y+
                   ,window ,x ,y))

(defvar *bball-gravity* 1)
(defvar *bball-maximum-x-drift* 7)

(defvar *bball-max-x* 700)
(defvar *bball-max-y* 500)

(defstruct ball
  (x (random (- *bball-max-x* +bball-size-x+)))
  (y (random (- *bball-max-y* +bball-size-y+)))
  (dx (if (zerop (random 2)) (random *bball-maximum-x-drift*)
          (- (random *bball-maximum-x-drift*))))
  (dy 0))

(defconstant +bball-image+ (apply #'xlib:bitmap-image +bball-bitmap+)
  "Returns the pixmap to be bounced around the screen.")

(defun bounce-1-ball (pixmap window gcontext ball)
  (let ((x (ball-x ball))
        (y (ball-y ball))
        (dx (ball-dx ball))
        (dy (ball-dy ball)))
    (xor-ball pixmap window gcontext x y)
    (setq x (+ x dx))
    (setq y (+ y dy))
    (if (or (< x 0) (> x (- *bball-max-x* +bball-size-x+)))
        (setq x (- x dx)
              dx (- dx)))
    (if (> y (- *bball-max-y* +bball-size-y+))
        (setq y (- y dy)
              dy (- dy)))
    (setq dy (+ dy *bball-gravity*))
    (setf (ball-x ball) x)
    (setf (ball-y ball) y)
    (setf (ball-dx ball) dx)
    (setf (ball-dy ball) dy)
    (xor-ball pixmap window gcontext x y)))

(defun bball (&key (nballs 5) (duration 500) (x 10) (y 10) (sleep 0.01)
              ((:gravity *bball-gravity*) *bball-gravity*)
              ((:maximum-x-drift *bball-maximum-x-drift*)
               *bball-maximum-x-drift*)
              ((:width *bball-max-x*) *bball-max-x*)
              ((:height *bball-max-y*) *bball-max-y*))
  "Bouncing balls."
  (xlib:with-open-display (dpy)
    (let* ((screen (xlib:display-default-screen dpy))
           (root (xlib:screen-root screen))
           (white-pixel (xlib:screen-white-pixel screen))
           (black-pixel (xlib:screen-black-pixel screen))
           (window (xlib:create-window
                    :parent root :width *bball-max-x* :height *bball-max-y*
                    :event-mask '(:exposure :button-press :button-release
                                  :key-press :key-release)
                    :x x :y y :background white-pixel))
           (gcontext (xlib:create-gcontext :drawable window
                                           :foreground white-pixel
                                           :background black-pixel
                                           :function boole-xor
                                           :exposures :off))
           (bounce-pixmap (xlib:create-pixmap
                           :width +bball-size-x+ :height +bball-size-y+
                           :drawable window))
           (pixmap-gc (xlib:create-gcontext :drawable bounce-pixmap
                                            :foreground white-pixel
                                            :background black-pixel))
           (balls (loop :repeat nballs :collect (make-ball))))
      (xlib:map-window window)
      (xlib:display-finish-output dpy)
      (xlib:put-image bounce-pixmap pixmap-gc +bball-image+
                      :x 0 :y 0 :width +bball-size-x+ :height +bball-size-y+)
      (xlib:free-gcontext pixmap-gc)
      (dolist (ball balls)
        (xor-ball bounce-pixmap window gcontext (ball-x ball) (ball-y ball)))
      (xlib:display-force-output dpy)
      (dotimes (i duration)
        (dolist (ball balls)
          (bounce-1-ball bounce-pixmap window gcontext ball))
        (xlib:display-force-output dpy)
        (sleep sleep))
      (xlib:free-pixmap bounce-pixmap)
      (xlib:free-gcontext gcontext)
      (xlib:unmap-window window)
      (xlib:display-finish-output dpy))))

(provide "bball")
