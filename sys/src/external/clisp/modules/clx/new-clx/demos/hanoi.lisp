;;;; Hanoi.

;;; Adapted from http://www.cs.cmu.edu/afs/cs/project/ai-repository/ai/lang/lisp/gui/clx/clx_demo.cl by...
;;; Copyright (C) 2007-2008 Sam Steingold <sds@gnu.org>
;;; GPL2 is applicable

(in-package :clx-demos)

;;; Random parameters:

(defparameter disk-thickness 15 "The thickness of a disk in pixels.")
(defparameter disk-spacing (+ disk-thickness 3)
  "The amount of vertical space used by a disk on a needle.")
(defvar *horizontal-velocity* 1 "The speed at which disks slide sideways.")
(defvar *vertical-velocity* 1 "The speed at which disks move up and down.")

;;; These variables are bound by the main function.

(defvar *hanoi-display* () "The display that Hanoi is happening on.")
(defvar *hanoi-window* () "The window that Hanoi is happening on.")
(defvar *hanoi-window-height* () "The height of the viewport Hanoi is happening on.")
(defvar *transfer-height* () "The height at which disks are transferred.")
(defvar *hanoi-gcontext* () "The graphics context for Hanoi under X11.")

;;; Needle Functions

(defstruct disk
  size)

(defstruct needle
  position
  disk-stack)

;;; Needle-Top-Height returns the height of the top disk on NEEDLE.

(defun needle-top-height (needle)
  (- *hanoi-window-height*
     (* disk-spacing (length (the list (needle-disk-stack needle))))))

;;; Graphic interface abstraction:

;;; Invert-Rectangle calls the CLX function draw-rectangle with "fill-p"
;;; set to T.  Update-Screen forces the display output.
;;;
(defmacro invert-rectangle (x y height width)
  `(xlib:draw-rectangle *hanoi-window* *hanoi-gcontext*
                        ,x ,y ,width ,height t))

(defmacro update-screen ()
  `(xlib:display-force-output *hanoi-display*))

;;;; Moving disks up and down

;;; Slide-Up slides the image of a disk up from the coordinates X,
;;; START-Y to the point X, END-Y.  DISK-SIZE is the size of the disk to
;;; move.  START-Y must be greater than END-Y

(defun slide-up (start-y end-y x disk-size)
  (multiple-value-bind (number-moves pixels-left)
      (truncate (- start-y end-y) *vertical-velocity*)
    (do ((x (- x disk-size))
         (width (* disk-size 2))
         (old-y start-y (- old-y *vertical-velocity*))
         (new-y (- start-y *vertical-velocity*) (- new-y *vertical-velocity*))
         (number-moves number-moves (1- number-moves)))
        ((zerop number-moves)
         (when (plusp pixels-left)
           (invert-rectangle x (- old-y pixels-left) disk-thickness width)
           (invert-rectangle x old-y disk-thickness width)
           (update-screen)))
      ;; Loop body writes disk at new height & erases at old height.
      (invert-rectangle x old-y disk-thickness width)
      (invert-rectangle x new-y disk-thickness width)
      (update-screen))))

;;; Slide-Down slides the image of a disk down from the coordinates X,
;;; START-Y to the point X, END-Y.  DISK-SIZE is the size of the disk to
;;; move.  START-Y must be less than END-Y.

(defun slide-down (start-y end-y x disk-size)
  (multiple-value-bind (number-moves pixels-left)
      (truncate (- end-y start-y) *vertical-velocity*)
    (do ((x (- x disk-size))
         (width (* disk-size 2))
         (old-y start-y (+ old-y *vertical-velocity*))
         (new-y (+ start-y *vertical-velocity*) (+ new-y *vertical-velocity*))
         (number-moves number-moves (1- number-moves)))
        ((zerop number-moves)
         (when (plusp pixels-left)
           (invert-rectangle x (+ old-y pixels-left) disk-thickness width)
           (invert-rectangle x old-y disk-thickness width)
           (update-screen)))
      ;; Loop body writes disk at new height & erases at old height.
      (invert-rectangle X old-y disk-thickness width)
      (invert-rectangle X new-y disk-thickness width)
      (update-screen))))

;;;; Lifting and Droping Disks

;;; Lift-disk pops the top disk off of needle and raises it up to the
;;; transfer height.  The disk is returned.

(defun lift-disk (needle)
  "Pops the top disk off of NEEDLE, Lifts it above the needle, & returns it."
  (let* ((height (needle-top-height needle))
         (disk (pop (needle-disk-stack needle))))
    (slide-up height
              *transfer-height*
              (needle-position needle)
              (disk-size disk))
    disk))

;;; Drop-disk drops a disk positioned over needle at the transfer height
;;; onto needle.  The disk is pushed onto needle.

(defun drop-disk (disk needle)
  "DISK must be positioned above NEEDLE.  It is dropped onto NEEDLE."
  (push disk (needle-disk-stack needle))
  (slide-down *transfer-height*
              (needle-top-height needle)
              (needle-position needle)
              (disk-size disk))
  t)

;;; Drop-initial-disk is the same as drop-disk except that the disk is
;;; drawn once before dropping.

(defun drop-initial-disk (disk needle)
  "DISK must be positioned above NEEDLE.  It is dropped onto NEEDLE."
  (let* ((size (disk-size disk))
         (lx (- (needle-position needle) size)))
    (invert-rectangle lx *transfer-height* disk-thickness (* size 2))
    (push disk (needle-disk-stack needle))
    (slide-down *transfer-height*
                (needle-top-height needle)
                (needle-position needle)
                (disk-size disk))
    t))

;;;; Sliding Disks Right and Left

;;; Slide-Right slides the image of a disk located at START-X, Y to the
;;; position END-X, Y.  DISK-SIZE is the size of the disk.  START-X is
;;; less than END-X.

(defun slide-right (start-x end-x Y disk-size)
  (multiple-value-bind (number-moves pixels-left)
      (truncate (- end-x start-x) *horizontal-velocity*)
    (do ((right-x (+ start-x disk-size) (+ right-x *horizontal-velocity*))
         (left-x  (- start-x disk-size) (+ left-x  *horizontal-velocity*))
         (number-moves number-moves (1- number-moves)))
        ((zerop number-moves)
         (when (plusp pixels-left)
           (invert-rectangle right-x Y disk-thickness pixels-left)
           (invert-rectangle left-x  Y disk-thickness pixels-left)
           (update-screen)))
      ;; Loop body adds chunk *horizontal-velocity* pixels wide to right
      ;; side of disk, then chops off left side.
      (invert-rectangle right-x Y disk-thickness *horizontal-velocity*)
      (invert-rectangle left-x Y disk-thickness *horizontal-velocity*)
      (update-screen))))

;;; Slide-Left is the same as Slide-Right except that START-X is greater
;;; than END-X.

(defun slide-left (start-x end-x Y disk-size)
  (multiple-value-bind (number-moves pixels-left)
      (truncate (- start-x end-x) *horizontal-velocity*)
    (do ((right-x (- (+ start-x disk-size) *horizontal-velocity*)
                  (- right-x *horizontal-velocity*))
         (left-x  (- (- start-x disk-size) *horizontal-velocity*)
                  (- left-x  *horizontal-velocity*))
         (number-moves number-moves (1- number-moves)))
        ((zerop number-moves)
         (when (plusp pixels-left)
           (setq left-x  (- (+ left-x  *horizontal-velocity*) pixels-left))
           (setq right-x (- (+ right-x *horizontal-velocity*) pixels-left))
           (invert-rectangle left-x  Y disk-thickness pixels-left)
           (invert-rectangle right-x Y disk-thickness pixels-left)
           (update-screen)))
      ;; Loop body adds chunk *horizontal-velocity* pixels wide to left
      ;; side of disk, then chops off right side.
      (invert-rectangle left-x  Y disk-thickness *horizontal-velocity*)
      (invert-rectangle right-x Y disk-thickness *horizontal-velocity*)
      (update-screen))))

;;;; Transferring Disks

;;; Transfer disk slides a disk at the transfer height from a position
;;; over START-NEEDLE to a position over END-NEEDLE.  Modified disk is
;;; returned.

(defun transfer-disk (disk start-needle end-needle)
  "Moves DISK from a position over START-NEEDLE to a position over END-NEEDLE."
  (let ((start (needle-position start-needle))
        (end (needle-position end-needle)))
    (if (< start end)
        (slide-right start end *transfer-height* (disk-size disk))
        (slide-left start end *transfer-height* (disk-size disk)))
    disk))


;;; Move-One-Disk moves the top disk from START-NEEDLE to END-NEEDLE.

(defun move-one-disk (start-needle end-needle)
  "Moves the disk on top of START-NEEDLE to the top of END-NEEDLE."
  (drop-disk (transfer-disk (lift-disk start-needle)
                            start-needle
                            end-needle)
             end-needle)
  t)

;;; Move-N-Disks moves the top N disks from START-NEEDLE to END-NEEDLE
;;; obeying the rules of the towers of hannoi problem.  To move the
;;; disks, a third needle, TEMP-NEEDLE, is needed for temporary storage.

(defun move-n-disks (n start-needle end-needle temp-needle)
  "Moves the top N disks from START-NEEDLE to END-NEEDLE.
   Uses TEMP-NEEDLE for temporary storage."
  (cond ((= n 1)
         (move-one-disk start-needle end-needle))
        (t
         (move-n-disks (1- n) start-needle temp-needle end-needle)
         (move-one-disk start-needle end-needle)
         (move-n-disks (1- n) temp-needle end-needle start-needle)))
  t)

;;;; Hanoi itself.

(defun hanoi (&key (disks 10) (x 10) (y 10) (width 768)
              ((:horizontal-velocity *horizontal-velocity*)
               *horizontal-velocity*)
              ((:vertical-velocity *vertical-velocity*) *vertical-velocity*)
              ((:height *hanoi-window-height*) 300))
  "Towers of Hanoi."
  (xlib:with-open-display (*hanoi-display*)
    (let* ((screen (xlib:display-default-screen *hanoi-display*))
           (root (xlib:screen-root screen))
           (white-pixel (xlib:screen-white-pixel screen))
           (black-pixel (xlib:screen-black-pixel screen))
           (*hanoi-window*
            (xlib:create-window
             :parent root :x x :y y :width width :height *hanoi-window-height*
             :event-mask '(:exposure :button-press :button-release
                           :key-press :key-release)
             :background white-pixel))
           (*transfer-height* (- *hanoi-window-height* (* disk-spacing disks)))
           (*hanoi-gcontext* (xlib:create-gcontext :drawable *hanoi-window*
                                                   :foreground white-pixel
                                                   :background black-pixel
                                                   :fill-style :solid
                                                   :function boole-c2))
           (needle-1 (make-needle :position 184))
           (needle-2 (make-needle :position 382))
           (needle-3 (make-needle :position 584)))
      (xlib:map-window *hanoi-window*)
      (xlib:display-force-output *hanoi-display*)
      (dotimes (i disks)
        (drop-initial-disk (make-disk :size (* 10 (- disks i))) needle-1))
      (move-n-disks disks needle-1 needle-3 needle-2)
      (xlib:free-gcontext *hanoi-gcontext*)
      (xlib:unmap-window *hanoi-window*)
      (xlib:display-finish-output *hanoi-display*))))

(provide "hanoi")
