;;; GREYNETIC displays random sized and shaded boxes in a window.

;;; Adapted from http://www.cs.cmu.edu/afs/cs/project/ai-repository/ai/lang/lisp/gui/clx/clx_demo.cl by...
;;; Copyright (C) 2007-2008 Sam Steingold <sds@gnu.org>
;;; GPL2 is applicable

(in-package :clx-demos)

(defvar *greynetic-pixmap-array*
  (make-array '(32 32) :initial-element 0 :element-type 'xlib:pixel))

(defun greynetic-pixmapper ()
  (let ((pixmap-data *greynetic-pixmap-array*))
    (dotimes (i 4)
      (declare (fixnum i))
      (let ((nibble (random 16)))
        (setf nibble (logior nibble (ash nibble 4))
              nibble (logior nibble (ash nibble 8))
              nibble (logior nibble (ash nibble 12))
              nibble (logior nibble (ash nibble 16)))
        (dotimes (j 32)
          (let ((bit (if (logbitp j nibble) 1 0)))
            (setf (aref pixmap-data i j) bit
                  (aref pixmap-data (+ 4 i) j) bit
                  (aref pixmap-data (+ 8 i) j) bit
                  (aref pixmap-data (+ 12 i) j) bit
                  (aref pixmap-data (+ 16 i) j) bit
                  (aref pixmap-data (+ 20 i) j) bit
                  (aref pixmap-data (+ 24 i) j) bit
                  (aref pixmap-data (+ 28 i) j) bit)))))
    pixmap-data))

(defun greynetic (&key (duration 100) (width 600) (height 600) (x 10) (y 10))
  "Display random sized and shaded boxes in a window."
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
           (pixmap (xlib:create-pixmap :width 32 :height 32 :drawable window))
           (gcontext (xlib:create-gcontext
                      :drawable window :tile pixmap :fill-style :tiled
                      :foreground black-pixel :background white-pixel)))
      (xlib:map-window window)
      (xlib:display-finish-output dpy)
      (dotimes (i duration)
        (let* ((pixmap-data (greynetic-pixmapper))
               (image (xlib:create-image :width 32 :height 32
                                         :data pixmap-data)))
          (xlib:put-image pixmap gcontext image :x 0 :y 0 :width 32 :height 32)
          (xlib:draw-rectangle window gcontext
                               (- (random width) 5)
                               (- (random height) 5)
                               (+ 4 (random (truncate width 3)))
                               (+ 4 (random (truncate height 3)))
                               t))
        (xlib:display-force-output dpy))
      (xlib:free-gcontext gcontext)
      (xlib:free-pixmap pixmap)
      (xlib:unmap-window window)
      (xlib:display-finish-output dpy))))

(provide "greynetic")
