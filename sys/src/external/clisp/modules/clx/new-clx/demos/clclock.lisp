;;; Adapted from http://common-lisp.net/~crhodes/clx by...
;;; Copyright (C) 2007-2008 Sam Steingold <sds@gnu.org>
;;; GPL2 is applicable

(in-package :clx-demos)

(defun required-size (font &optional (extra-width 0) (extra-height 0))
  (multiple-value-bind (width-R ascent-R)
      (xlib:text-extents font "XVIIII XXXVIIII XXXVIIII")
    (multiple-value-bind (width-I ascent-I)
        (xlib:text-extents font "WWWW-WW-WW WW:WW:WW")
      (values (+ extra-width (max width-R width-I))
              (+ extra-height (max ascent-R ascent-I))))))

(defun romanize (arg)
  (if (zerop arg)
      "O"
      (format nil "~@R" arg)))

(defun roman-time-string ()
  (multiple-value-bind (s m h) (decode-universal-time (get-universal-time))
    (format nil "~a ~a ~a" (romanize h) (romanize m) (romanize s))))

(defun iso-time-string ()
  (multiple-value-bind (se mi ho da mo ye)
      (decode-universal-time (get-universal-time))
    (format nil "~d-~2,'0d-~2,'0dT~2,'0d:~2,'0d:~2,'0d" ye mo da ho mi se)))

(defun clclock (&key (font "fixed") (duration 100) (time-string :roman)
                (background "midnightblue") (foreground "yellow")
                (x 10) (y 10) (extra-width 20) (extra-height 20))
  "Show a digital clock."
  (xlib:with-open-display (dpy)
    (let* ((screen (xlib:display-default-screen dpy))
           (white-pixel (xlib:screen-white-pixel screen))
           (colormap (xlib:screen-default-colormap screen))
           (bg (xlib:alloc-color colormap
                                 (xlib:lookup-color colormap background)))
           (fg (xlib:alloc-color colormap
                                 (xlib:lookup-color colormap foreground)))
           (font-o (xlib:open-font dpy font))
           (time-string-f (ecase time-string
                            (:roman #'roman-time-string)
                            (:iso #'iso-time-string))))
      (multiple-value-bind (width height)
          (required-size font-o extra-width extra-height)
        (let* ((window (xlib:create-window
                        :parent (xlib:screen-root screen) :x x :y y
                        :width width :height height :background bg))
               (gcontext (xlib:create-gcontext
                          :drawable window :fill-style :solid
                          :background white-pixel
                          :foreground fg :font font-o))
               (background (xlib:create-gcontext
                            :drawable window :fill-style :solid
                            :background white-pixel
                            :foreground bg :font font-o)))
          (xlib:map-window window)
          (loop :for count :upfrom 0 :until (and duration (= count duration))
            :for t-string = (funcall time-string-f)
            :for string-width = (xlib:text-width gcontext t-string)
            :do (xlib:draw-rectangle window background 0 0 width height :fill-p)
            (xlib:draw-glyphs window gcontext
                              (ash (- width string-width extra-width) -1)
                              (- height (ash extra-height -1))
                              t-string)
            (xlib:display-force-output dpy)
            (sleep 1))
          (xlib:free-colors colormap (list fg bg))
          (xlib:close-font font-o)
          (xlib:free-gcontext background)
          (xlib:free-gcontext gcontext)
          (xlib:unmap-window window)
          (xlib:display-force-output dpy))))))
