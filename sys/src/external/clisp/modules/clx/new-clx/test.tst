;; -*- Lisp -*- vim:filetype=lisp
;; some tests for clx/new-clx
;; clisp -E 1:1 -q -norc -i ../tests/tests -x '(run-test "clx/new-clx/test")'

(list (require "clx")) (#-CLX T #+CLX NIL)
(listp (show (multiple-value-list (ext:module-info "clx" t)) :pretty t)) T

(defparameter *dpy* (show (xlib:open-default-display))) *dpy*

(xlib:closed-display-p *dpy*) NIL
(stringp (show (xlib:display-authorization-data *dpy*))) T
(stringp (show (xlib:display-authorization-name *dpy*))) T
(listp (show (multiple-value-list (xlib:display-authorization *dpy*)))) T
(integerp (show (xlib:display-protocol-major-version *dpy*))) T
(integerp (show (xlib:display-protocol-minor-version *dpy*))) T
(listp (show (multiple-value-list (xlib:display-protocol-version *dpy*)))) T
(format t "~29b" (xlib:display-resource-id-base *dpy*)) NIL
(format t "~29b" (xlib:display-resource-id-mask *dpy*)) NIL
(xlib:no-operation *dpy*) NIL
(listp (show (xlib:display-roots *dpy*))) T
(listp (show (multiple-value-list (xlib:display-vendor *dpy*)))) T
(stringp (show (xlib:display-vendor-name *dpy*))) T
(integerp (show (xlib:display-release-number *dpy*))) T
(listp (show (xlib:display-plist *dpy*))) T
(stringp (show (xlib:display-host *dpy*))) T
(listp (show (multiple-value-list (xlib:pointer-control *dpy*)))) T
(listp (show (xlib:pointer-mapping *dpy*) :pretty t)) T
(listp (show (xlib:font-path *dpy*) :pretty t)) T
;; (defparameter *font-count*
;;   (let ((font-names (xlib:list-font-names *dpy* "*")))
;;     (ext:times (map-into font-names (lambda (n) (xlib:open-font *dpy* n))
;;                          font-names))
;;     (mapc #'xlib:close-font font-names)
;;     (show (length font-names)))) *FONT-COUNT*
;; (let ((fonts (ext:times (xlib:list-fonts *dpy* "*"))))
;;   (mapc #'xlib:close-font fonts)
;;   (= *font-count* (length fonts))) T

(dotimes (i 8) (show (xlib:cut-buffer *dpy* :buffer i))) NIL
(loop :with max :for i :from 1 :to 1000
  :always (handler-case
              (prog1 (= i (xlib:find-atom *dpy* (xlib:atom-name *dpy* i)))
                (setq max i))
            (xlib:atom-error (c) (= i (xlib::atom-error-atom-id c))))
  :finally (show max))
T
(block xlib:atom-name
  (handler-bind ((error (lambda (c)
                          (princ-error c)
                          (return-from xlib:atom-name 42))))
    (xlib:atom-name *dpy* 0)))
42                              ; no atom 0!

(multiple-value-bind (kc% b% bp bd lm gar arm) (xlib:keyboard-control *dpy*)
  (show (list kc% b% bp bd lm gar arm) :pretty t)
  (xlib:change-keyboard-control
   *dpy* :KEY-CLICK-PERCENT kc%
   :BELL-PERCENT b% :BELL-PITCH bp :BELL-DURATION bd
   :KEY 80 :AUTO-REPEAT-MODE (if (plusp (aref arm 80)) :on :off)))
NIL

(vectorp (show (xlib:query-keymap *dpy*))) T
(listp (show (multiple-value-list (xlib:display-keycode-range *dpy*)))) T
(integerp (show (xlib:display-max-request-length *dpy*))) T
(integerp (show (xlib::display-extended-max-request-length *dpy*))) T
(let ((r (show (xlib:display-resource-manager-string *dpy*))))
  (or (null r)
      (with-input-from-string (s r)
        (loop :for r = (read-line s nil nil) :while r
          :always (or (find #\* r)
                      (let* ((dot (position #\. r))
                             (colon (position #\: r))
                             (program (subseq r 0 dot))
                             (option (subseq r (1+ dot) colon))
                             (value (subseq r (+ 2 colon)))
                             (default (xlib:display-get-default
                                       *dpy* program option)))
                        (or (string= default value)
                            (print (list r program option value default)))))))))
  T
(integerp (show (xlib:display-motion-buffer-size *dpy*))) T
(listp (show (xlib:display-pixmap-formats *dpy*) :pretty t)) T
(xlib:bitmap-format-p (show (xlib:display-bitmap-format *dpy*))) T
(symbolp (show (xlib:display-byte-order *dpy*))) T
(listp (show (multiple-value-list (xlib:display-protocol-version *dpy*)))) T
(listp (show (multiple-value-list (xlib:display-vendor *dpy*)))) T
(listp (show (multiple-value-list (xlib:global-pointer-position *dpy*)))) T
(integerp (show (xlib:display-nscreens *dpy*))) T

(defparameter *screen* (show (xlib:display-default-screen *dpy*))) *SCREEN*

(let ((n (show (setf (xlib:display-default-screen *dpy*) *screen*))))
  (list (equalp (slot-value *screen* 'xlib::ptr)
                (slot-value (nth n (xlib:display-roots *dpy*)) 'xlib::ptr))
        (= (setf (xlib:display-default-screen *dpy*) n) n)
        (equalp (slot-value *screen* 'xlib::ptr)
                (slot-value (nth n (xlib:display-roots *dpy*)) 'xlib::ptr))))
(T T T)
(let ((r (show (xlib:screen-resource-string *screen*))))
  (or (null r) (stringp r))) T
(integerp (show (xlib:screen-black-pixel *screen*))) T
(integerp (show (xlib:screen-white-pixel *screen*))) T
(integerp (show (xlib:screen-event-mask-at-open *screen*))) T
(integerp (show (xlib:screen-height *screen*))) T
(integerp (show (xlib:screen-height-in-millimeters *screen*))) T
(integerp (show (xlib:screen-width *screen*))) T
(integerp (show (xlib:screen-width-in-millimeters *screen*))) T
(integerp (show (xlib:screen-max-installed-maps *screen*))) T
(integerp (show (xlib:screen-min-installed-maps *screen*))) T
(integerp (show (xlib:screen-root-depth *screen*))) T
(xlib:visual-info-p (show (xlib:screen-root-visual-info *screen*) :pretty t)) T
(typep (show (xlib:screen-save-unders-p *screen*)) 'boolean) T
(symbolp (show (xlib:screen-backing-stores *screen*))) T
(listp (show (xlib:screen-depths *screen*) :pretty t)) T

(defparameter *visual* (show (xlib:screen-root-visual *screen*))) *VISUAL*

(listp (show (xlib:screen-plist *screen*))) T
(xlib:visual-info-p (show (xlib:visual-info *dpy* *visual*) :pretty t)) T

(defparameter *root* (show (xlib:screen-root *screen*))) *ROOT*
(listp (show (xlib:list-properties *root*) :pretty t)) T

(defparameter *colormap* (show (xlib:screen-default-colormap *screen*)))
*COLORMAP*
(defparameter *color*
  (show (multiple-value-list (xlib:lookup-color *colormap* "red"))))
*COLOR*
(multiple-value-bind (pixel screen-color exact-color)
    (xlib:alloc-color *colormap* (first *color*))
  (show (list pixel screen-color exact-color))
  (assert (eq exact-color (first *color*)))
  (show (xlib:query-colors *colormap* (list pixel)))
  (xlib:free-colors *colormap* (list pixel)))
NIL
(every #'xlib:color-p
       (show (ext:appease-cerrors
              (xlib:query-colors *colormap*
                                 (loop :with max = (ash 1 32) :repeat 100
                                   :collect (random max))))
             :pretty t))
T

(defparameter *font* (show (xlib:open-font *dpy* "fixed"))) *FONT*
(listp (show (multiple-value-list (xlib:text-extents *font* "abcd")))) T
(listp (show (xlib:font-properties *font*) :pretty t)) T
(xlib:font-name *font*) "fixed"
(xlib:font-direction *font*) :LEFT-TO-RIGHT
(xlib:font-all-chars-exist-p *font*) NIL
(integerp (show (xlib:min-char-width *font*))) T
(integerp (show (xlib:max-char-width *font*))) T

(defparameter *window*
  (multiple-value-bind (window revert) (xlib:input-focus *dpy*)
    (show (list :window window :revert revert) :pretty t)
    window))
*WINDOW*
(listp (show (xlib:list-properties *window*) :pretty t)) T
(listp (show (xlib:window-plist *window*) :pretty t)) T
(xlib:window-equal *window* *window*) T
(xlib:window-equal *window* *root*) NIL
(typep (show (xlib:window-bit-gravity *window*)) 'xlib:bit-gravity) T
(typep (show (xlib:window-gravity *window*)) 'xlib:win-gravity) T
(integerp (show (xlib:window-id *window*))) T
(xlib:window-p (show (xlib:drawable-root *window*))) T
(listp (show (multiple-value-list (xlib:query-tree *window*)) :pretty t)) T
(length (show (multiple-value-list (xlib:query-pointer *window*)) :pretty t)) 8
(listp (show (xlib:motion-events *window*))) T
(defparameter *window-position*
  (show (multiple-value-list (xlib:pointer-position *window*))))
*WINDOW-POSITION*
(xlib:warp-pointer *window* 10 10) NIL
(xlib:warp-pointer-relative *dpy* 10 10) NIL
(xlib:warp-pointer *window* (first *window-position*)
                   (second *window-position*))
NIL
(equal (show *window-position*)
       (show (multiple-value-list (xlib:pointer-position *window*))))
T
(dolist (selection '("PRIMARY" "SECONDARY" "CLIPBOARD"))
  (let ((w (xlib:selection-owner *dpy* selection)))
    (or (null w) (xlib:window-p w) (error "~S is not a window" w))))
NIL

(defun check-query-best (f &optional (w *window*))
  (let ((l (show (multiple-value-list (funcall f 10 10 w)))))
    (list (length l) (every #'integerp l))))
CHECK-QUERY-BEST
(check-query-best #'xlib:query-best-stipple) (2 T)
(check-query-best #'xlib:query-best-tile) (2 T)
(check-query-best #'xlib:query-best-cursor) (2 T)

(defparameter *gcontext*
  (xlib:create-gcontext :drawable *window* :font *font*))
*GCONTEXT*
(< (show (xlib:text-width *gcontext* "abazonk" :start 1 :end 6))
   (show (xlib:text-width *gcontext* "abazonk"))) T

(xlib:free-gcontext *gcontext*) NIL
(xlib:close-font *font*) NIL

(let ((modifiers (multiple-value-list (xlib:modifier-mapping *dpy*))))
  (apply #'xlib:set-modifier-mapping *dpy*
         (show (mapcan #'list '(:SHIFT :LOCK :CONTROL
                                :MOD1 :MOD2 :MOD3 :MOD4 :MOD5)
                       modifiers)
               :pretty t)))
:SUCCESS

(let ((map (show (xlib:keyboard-mapping *dpy*) :pretty t)))
  (show (array-dimensions map))
  (list (eq map (xlib:keyboard-mapping *dpy* :data map))
        (xlib:change-keyboard-mapping
         *dpy* map :first-keycode (xlib:display-min-keycode *dpy*))
        (equalp map (xlib:keyboard-mapping *dpy*))))
(T NIL T)

(multiple-value-list (xlib:keysym->keycodes *dpy* 65)) (38)
(multiple-value-list (xlib:keysym->keycodes *dpy* #xFF52)) (98) ; Up
(xlib:keysym "Up") #xFF52

(xlib:keysym->character *dpy* 97)    #\a
(xlib:keysym->character *dpy* 97 4)  #\a ; 4 is <ctrl>
(xlib:keysym->character *dpy* 97 8)  #\a ; 8 is <meta>
(xlib:keysym->character *dpy* 65)    #\A
(xlib:keysym->character *dpy* 65 4)  #\A
(xlib:keysym->character *dpy* 65 8)  #\A
;; for McCLIM:
(xlib:keysym->character *dpy* #xFF08) #\BackSpace
(xlib:keysym->character *dpy* #xFF09) #\Tab
(xlib:keysym->character *dpy* #xFF0A) #\Linefeed
(xlib:keysym->character *dpy* #xFF0D) #\Return
(xlib:keysym->character *dpy* #xFF1B) #\Escape
(xlib:keysym->character *dpy* #xFFFF) #\Delete

(listp (show (loop :for i :from 0 :to 255
               :collect (xlib:keycode->character *dpy* i 0))
             :pretty t))
T

(defun c2s (index)
  (loop :for keycode :from 0 :to 255
    :collect (xlib:keycode->keysym *dpy* keycode index)))
C2S

(let ((l-255 (show (c2s 255) :pretty t)))
  (loop :for index :from 0 :to 254 :for l = (c2s index)
    :unless (equal l-255 l)
    :do (show (list index (diff-seq l-255 l)) :pretty t)))
NIL

(xlib:keysym-name (show (xlib:keysym "Down"))) "Down"

(let ((access (show (xlib:access-control *dpy*))))
  (assert (eq access (setf (xlib:access-control *dpy*) access)))
  t) T

(defparameter *access-hosts* (show (xlib:access-hosts *dpy*) :pretty t))
*ACCESS-HOSTS*
(xlib:add-access-host *dpy* "localhost") NIL
(every (lambda (x)
         (or (posix:hostent-p x)
             (and (listp x) (eq (car x) :SERVER-INTERPRETED))))
       (show (xlib:access-hosts *dpy*) :pretty t)) T
(xlib:remove-access-host *dpy* "localhost") NIL
(equalp *access-hosts* (show (xlib:access-hosts *dpy*) :pretty t)) T

(xlib:activate-screen-saver *dpy*) NIL
(xlib:reset-screen-saver *dpy*) NIL
(listp (show (multiple-value-list (xlib:screen-saver *dpy*)))) T
(dolist (ext (xlib:list-extensions *dpy*))
  (show (cons ext (multiple-value-list (xlib:query-extension *dpy* ext)))))
NIL

;; <http://article.gmane.org/gmane.lisp.clisp.devel/19241>
(defparameter *window*
  (xlib:create-window :parent (xlib:screen-root *screen*)
                      :x 0 :y 0 :width 100 :height 100
                      :background (xlib:screen-white-pixel *screen*)))
*WINDOW*
(defun check-wm-class (&rest strings)
  (xlib:change-property
   *window* :WM_CLASS (apply #'concatenate '(vector xlib:card8)
                             (mapcar (lambda (s)
                                       (etypecase s
                                         (string
                                          (map #1='(vector xlib:card8)
                                               #'xlib:char->card8 s))
                                         (vector (coerce s #1#))))
                                     strings))
   :string 8)
  (multiple-value-list (xlib:get-wm-class *window*)))
CHECK-WM-CLASS
(check-wm-class "string 1" #(0) "string 2" #(0))
("string 1" "string 2")
(check-wm-class "Manifold X" #(0) "Powercoupling Y" #(0) "Magistrate Z" #(0))
("Manifold X" "Powercoupling Y")
(check-wm-class #(0))
(NIL NIL)
(check-wm-class)
(NIL NIL)
(check-wm-class #(0) "checkity checkfoo")
(NIL "checkity checkfoo")
(check-wm-class "ohh bother" #(0) "Magic Fudge")
("ohh bother" "Magic Fudge")
(check-wm-class "You Gellin?" #(0))
("You Gellin?" NIL)
(check-wm-class "Blinky The Cloon")
("Blinky The Cloon" NIL)

(xlib:iconify-window *window* *screen*) NIL
(xlib:withdraw-window *window* *screen*) NIL

(defparameter *rdb-tmp* (show (xlib:make-resource-database))) *RDB-TMP*
;; (stringp (show (xlib:resource-database-locale *rdb-tmp*))) T
(xlib:add-resource *rdb-tmp* '("Foo" "Bar" "Baz") "ZoT") "ZoT"
;; (xlib:resource-database-to-string *rdb-tmp*) "Foo.Bar.Baz:	ZoT
;; "
(xlib:get-resource *rdb-tmp* "Baz" "*" '("Foo" "Bar") '("*" "*")) "ZoT"
(xlib:delete-resource *rdb-tmp* '("Foo" "Bar" "Baz")) T
;; (xlib:resource-database-to-string *rdb-tmp*) ""

;; (defparameter *rdb-dpy* (show (xlib:display-xdefaults *dpy*))) *RDB-DPY*
;; (string= (show (xlib::display-resource-manager-string *dpy*))
;;          (show (xlib:resource-database-to-string *rdb-dpy*))) T

;; https://sourceforge.net/tracker/?func=detail&atid=351355&aid=2202304&group_id=1355
(defparameter *white-color* (show (xlib:make-color :red 1 :green 1 :blue 1)))
*WHITE-COLOR*
(defparameter *black-color* (show (xlib:make-color :red 0 :green 0 :blue 0)))
*BLACK-COLOR*
(defparameter *font* (show (xlib:open-font *dpy* "cursor"))) *FONT*

(defun create-font-cursor (shape)
  (xlib:create-glyph-cursor :source-font *font*
                            :source-char shape
                            :mask-font *font*
                            :mask-char (1+ shape)
                            :foreground *white-color*
                            :background *black-color*))
CREATE-FONT-CURSOR

(format t "~&==== move mouse off of windows and watch it morph! ===~%") NIL
(loop :for shape :from 0 :to 150 :for cursor = (create-font-cursor shape) :do
  (format t "~&~:D ~S~%" shape cursor)
  (setf (xlib:window-cursor *root*) cursor)
  (xlib:display-finish-output *dpy*)
  (sleep 0.1) (xlib:free-cursor cursor))
NIL

(let ((cursor (create-font-cursor 68))) ; default
  (setf (xlib:window-cursor *root*) cursor)
  (xlib:display-finish-output *dpy*)
  (xlib:free-cursor cursor))
NIL

(xlib:close-font *font*) NIL

(xlib:bell *dpy* 50) NIL        ; signal that we are almost done

(xlib:display-force-output *dpy*) NIL
(xlib:display-finish-output *dpy*) NIL
(xlib:display-p (show (xlib:close-display *dpy*))) T

(defun map-windows (f)
  (xlib:with-open-display (dpy)
    (ext:appease-cerrors
     (dolist (screen (xlib:display-roots dpy))
       (dolist (window (xlib:query-tree (xlib:screen-root screen)))
         (funcall f window))))))
MAP-WINDOWS

(defun iter-windows (getter &optional setter (name getter))
  (let ((window-count 0) (value-count 0))
    (map-windows (lambda (window)
                   (let ((value (funcall getter window)))
                     (incf window-count)
                     (when value
                       (incf value-count)
                       (show (list window-count value-count window value)
                             :pretty t)
                       (when setter
                         (funcall setter window value))))))
    (length (show (list 'window-count window-count name value-count)))))
ITER-WINDOWS

(iter-windows 'xlib:wm-hints (lambda (window hints)
                               (setf (xlib:wm-hints window) hints)))
4

;; <http://thread.gmane.org/gmane.lisp.clisp.devel/20745>
(iter-windows 'xlib:wm-normal-hints
              (lambda (window hints)
                (setf (xlib:wm-normal-hints window) hints)))
4

(iter-windows (lambda (window)
                (multiple-value-bind (name class) (xlib:get-wm-class window)
                  (when name (list name class))))
              (lambda (window name-class)
                (apply #'xlib:set-wm-class window name-class))
              'get-wm-class)
4

(iter-windows 'xlib:wm-command) 4

(iter-windows 'xlib:wm-protocols
              (lambda (window protocols)
                (setf (xlib:wm-protocols window) protocols)))
4

(xlib:with-open-display (dpy)
  (let* ((win (xlib:create-window
               :parent (xlib:screen-root (first (xlib:display-roots dpy)))
               :x 0 :y 0 :width 50 :height 50))
         (pm (xlib:create-pixmap :width (random 100) :height (random 100)
                                 :depth 8 :drawable win)))
    (setf (xlib:wm-hints win)
          (xlib:make-wm-hints :icon-pixmap pm))
    (xlib:display-finish-output dpy)
    (eq pm (xlib:wm-hints-icon-pixmap (xlib:wm-hints win)))))
T

(handler-case
    (xlib:with-open-display (dpy)
      (let ((s (first (xlib:display-roots dpy))))
        (xlib:create-window
         :window s :parent (xlib:screen-root s)
         :x 0 :y 0 :width 50 :height 50)))
  (xlib::x-type-error (c)
    (list (xlib::x-error-caller c)
          (type-of (type-error-datum c))
          (type-error-expected-type c)
          (xlib::x-type-error-type-string c))))
(XLIB:CREATE-WINDOW XLIB:SCREEN XLIB:WINDOW NIL)

;; <http://article.gmane.org/gmane.lisp.clisp.devel/18431>
;; From: "Shawn Betts" <sabetts@vcn.bc.ca>
(labels ((parent (dpy) (xlib:screen-root (first (xlib:display-roots dpy))))
         (make-win (dpy)
           (xlib:create-window :parent (parent dpy)
                               :x 0 :y 0 :width 50 :height 50))
         (make-pixmap (window)
           (xlib:create-pixmap :width (random 100) :height (random 100)
                               :depth 8 :drawable window))
         (window-list (dpy) (xlib:query-tree (parent dpy)))
         (first-pass (dpy)
           ;; Open a fresh connection. Create a window and a pixmap.
           (xlib:with-open-display (dpy2)
             (let* ((window (make-win dpy2)) (wid (xlib:window-id window))
                    (pixmap (make-pixmap window)))
               ;; make the pixmap the window's icon pixmap hint.
               (setf (xlib:wm-hints window)
                     (xlib:make-wm-hints :icon-pixmap pixmap))
               (format t "Window ID: ~8x pixmap ID: ~8x~%"
                       wid (xlib:pixmap-id pixmap))
               (xlib:display-finish-output dpy2)
               (format t " --> ~S~%"
                       (xlib:wm-hints-icon-pixmap (xlib:wm-hints window)))
               ;; On the old connection, list the root window children
               ;; and the icon pixmap hint to cache their XIDs.
               (dolist (w (window-list dpy))
                 (let ((id (xlib:window-id w)) (hints (xlib:wm-hints w)))
                   (when hints
                     (let ((pm (xlib:wm-hints-icon-pixmap hints)))
                       (when pm
                         (format t " W: ~8x -> ~s~%" id pm)))))))))
         (second-pass (dpy)
           ;; Open a fresh connection and create 2 windows.
           (xlib:with-open-display (dpy2)
             (let* ((window1 (make-win dpy2)) (id1 (xlib:window-id window1))
                    (window2 (make-win dpy2)) (id2 (xlib:window-id window2)))
               (format t "Window#1 ID: ~8x Window#2 ID: ~8x~%" id1 id2)
               (xlib:display-finish-output dpy2)
               ;; On the old connection, list the root window children
               ;; and note the second window is erroneously a pixmap
               ;; due to too agressive caching in clx.
               (dolist (w (window-list dpy))
                 (let ((id (xlib:window-id w)))
                   (cond ((= id1 id) (princ "1 "))
                         ((= id2 id) (princ "2 "))
                         (t (princ "  "))))
                 (format t "window: ~s~%" w)
                 (assert (xlib:window-p w)))))))
  (handler-bind ((xlib:lookup-error (lambda (c)
                                      (princ-error c)
                                      (let ((r (find-restart :all c)))
                                        (if r (invoke-restart r) (error c))))))
    (ext:appease-cerrors
     (xlib:with-open-display (dpy)
       (first-pass dpy)
       (second-pass dpy)))))
NIL

;; https://sourceforge.net/tracker2/?func=detail&atid=101355&aid=2164603&group_id=1355
(xlib:with-open-display (dpy)
  (let* ((top-win (xlib:create-window
                   :parent (xlib:screen-root (first (xlib:display-roots dpy)))
                   :x 100 :y 100 :width 250 :height 250
                   :bit-gravity :north-west :background 11111111))
         (gc (xlib:create-gcontext
              :drawable top-win :foreground 0 :line-width 2))
         (my-back-store (xlib:create-pixmap
                         :drawable top-win :width 10 :height 10)))
    (show (list top-win my-back-store) :pretty t)
    (xlib:map-window top-win)
    (xlib:draw-line top-win gc 3 3 20 20)
    (xlib:display-force-output dpy)
    (xlib:copy-area top-win gc 5 5 10 10 my-back-store 0 0)
    (xlib:process-event dpy :handler
                        (lambda (&rest event-data &key display
                                 event-key send-event-p &allow-other-keys)
                          (show (list event-data display event-key
                                      send-event-p)
                                :pretty t))
                        :timeout 1 :discard-p t))
  t) T

;; https://sourceforge.net/tracker/?func=detail&atid=101355&aid=2188102&group_id=1355
(defun check-timeout (timeout)
  (xlib:with-open-display (dpy)
    (let* ((itups (float internal-time-units-per-second 0d0))
           (start (/ (get-internal-real-time) itups)))
      (xlib:process-event dpy :handler
                          (lambda (&rest event-data &key display
                                   event-key send-event-p &allow-other-keys)
                            (show (list event-data display event-key
                                        send-event-p)
                                  :pretty t))
                          :timeout timeout :discard-p t)
      (<= (/ timeout 2)
          (show (- (/ (get-internal-real-time) itups) start))
          (* timeout 2)))))
CHECK-TIMEOUT
(check-timeout 0.01) T
(check-timeout 0.1) T
(check-timeout 1) T

;; https://sourceforge.net/tracker2/?func=detail&atid=101355&aid=2159172&group_id=1355
(xlib:with-open-display (dpy)
  (let* ((top-win (xlib:create-window
                   :parent (xlib:screen-root (first (xlib:display-roots dpy)))
                   :x 300 :y 300 :width 300 :height 70
                   :bit-gravity :north-west :background 1617116666
                   :event-mask (xlib:make-event-mask :exposure)))
         (font (xlib:open-font dpy "fixed"))
         (timeout 0.1) (start 0) (end 1)
         (message "these three lines should grow together in sync")
         (m1 (make-array (length message) :element-type 'character
                         :displaced-to (ext:string-concat #1="abazonk" message)
                         :displaced-index-offset (length #1#))))
    (assert (string= message m1))
    (flet ((events (&rest event-data
                    &key display event-key send-event-p window
                    &allow-other-keys)
             (when (eq event-key :exposure)
               (let ((gc (xlib:create-gcontext
                          :drawable window :foreground 0 :font font)))
                 (xlib:draw-glyphs window gc 10 10
                                   (subseq message start end))
                 (xlib:draw-glyphs window gc 10 30
                                   message :start start :end end)
                 (xlib:draw-glyphs window gc 10 50
                                   m1 :start start :end end)
                 ))))
      (xlib:map-window top-win)
      (xlib:display-force-output dpy)
      (loop
        (xlib:process-event dpy :handler #'events :timeout timeout :discard-p t)
        (incf end)
        (if (> end (length message)) (return))
        (xlib:clear-area top-win :exposures-p t))))) NIL

(xlib:with-open-display (dpy)
  (let* ((top-win (xlib:screen-root (first (xlib:display-roots dpy))))
         (gc1 (xlib:create-gcontext :drawable top-win :foreground 0
                                    :line-width 1))
         (gc2 (xlib:create-gcontext :drawable top-win :foreground 1
                                    :line-width 2)))
    (list (list (xlib:gcontext-foreground gc1) (xlib:gcontext-line-width gc1)
                (xlib:gcontext-foreground gc2) (xlib:gcontext-line-width gc2))
          (xlib:copy-gcontext-components gc1 gc2)
          (list (xlib:gcontext-foreground gc1) (xlib:gcontext-line-width gc1)
                (xlib:gcontext-foreground gc2) (xlib:gcontext-line-width gc2))
          (xlib:copy-gcontext-components gc1 gc2 :font :foreground)
          (list (xlib:gcontext-foreground gc1) (xlib:gcontext-line-width gc1)
                (xlib:gcontext-foreground gc2) (xlib:gcontext-line-width gc2))
          (xlib:copy-gcontext-components gc1 gc2 :font :foreground :line-width)
          (list (xlib:gcontext-foreground gc1) (xlib:gcontext-line-width gc1)
                (xlib:gcontext-foreground gc2) (xlib:gcontext-line-width gc2))
          )))
((0 1 1 2) NIL (0 1 1 2) NIL (0 1 0 2) NIL (0 1 0 1))

(xlib:display-p (xlib:close-display (xlib:open-display nil))) T

;; <http://article.gmane.org/gmane.lisp.clisp.devel/19459>
(xlib:with-open-display (dpy)
  (let* ((screen (first (xlib:display-roots dpy)))
         (root (xlib:screen-root screen))
         (window (xlib:create-window
                  :parent root :x 0 :y 0 :width 200 :height 200
                  :border-width 1 :event-mask '(:button-press)))
         (events (xlib:events-queued dpy)))
    (loop :repeat events :do (xlib:discard-current-event dpy))
    (format t "~&Discarded ~:D event~:P~&" events)
    (xlib:send-event window :button-press 0 :x -9999)
    (format t "~&Sent event, queue is now: ~:D~%" (xlib:events-queued dpy))
    ;; expect that the sent event is in the top ten events in the queue.
    (loop :repeat 10 :do
      (xlib:process-event
       dpy :handler (lambda (&rest data &key event-key x &allow-other-keys)
                      (show data :pretty t)
                      (when (and (eql event-key :button-press) (= x -9999))
                        (return t)))
       :timeout 0.1))))
T

(xlib:with-open-display (dpy)
  (let* ((screen (first (xlib:display-roots dpy)))
	 (root (xlib:screen-root screen))
	 (events (xlib:events-queued dpy))
	 acc)
    (loop :repeat events :do (xlib:discard-current-event dpy))
    (format t "~&Discarded ~:D event~:P~&" events)
    (xlib:queue-event dpy :button-press :x -66)
    (xlib:queue-event dpy :button-press :x -77)
    (xlib:queue-event dpy :button-press :x -88)
    (xlib:queue-event dpy :button-press :x -99)
    (format t "~&Queue event, queue is now: ~:D~%" (xlib:events-queued dpy))
    ;; expect that queued events are in the top ten events in the queue.
    (loop :repeat 10 :do
      (xlib:process-event
       dpy :handler (lambda (&rest data &key event-key x send-event-p
                             &allow-other-keys)
                      (show data :pretty t)
                      (when (eql event-key :button-press)
                        (push `(,x ,send-event-p) acc)))
       :timeout 0.1))
    (nreverse acc)))
((-99 NIL) (-88 NIL) (-77 NIL) (-66 NIL))

(xlib:with-open-display (dpy)
  (let* ((screen (first (xlib:display-roots dpy)))
	 (root (xlib:screen-root screen))
	 (events (xlib:events-queued dpy))
	 acc)
    (loop :repeat events :do (xlib:discard-current-event dpy))
    (format t "~&Discarded ~:D event~:P~&" events)
    (xlib:queue-event dpy :button-press :x -66 :append-p t :send-event-p t)
    (xlib:queue-event dpy :button-press :x -77 :append-p t :send-event-p t)
    (xlib:queue-event dpy :button-press :x -88 :append-p t :send-event-p t)
    (xlib:queue-event dpy :button-press :x -99 :append-p t :send-event-p t)
    (format t "~&Queue event, queue is now: ~:D~%" (xlib:events-queued dpy))
    ;; expect that queued events are in the top ten events in the queue.
    (loop :repeat 10 :do
      (xlib:process-event
       dpy :handler (lambda (&rest data &key event-key x send-event-p
                             &allow-other-keys)
                      (show data :pretty t)
                      (when (eql event-key :button-press)
                        (push `(,x ,send-event-p) acc)))
       :timeout 0.1))
    (nreverse acc)))
((-66 T) (-77 T) (-88 T) (-99 T))

;; http://article.gmane.org/gmane.lisp.clisp.devel:19745
(xlib:with-open-display (dpy)
  (let* ((screen (first (xlib:display-roots dpy)))
         (root (xlib:screen-root screen))
         (font (xlib:open-font dpy "fixed"))
         (colormap (xlib:screen-default-colormap screen))
         (black (xlib:alloc-color colormap "black"))
         (white (xlib:alloc-color colormap "white"))
         (height 600) (width 800)
         (window (xlib:create-window
                  :parent root :x 100 :y 100 :width width :height height
                  :background black :colormap colormap))
         (gcontext (xlib:create-gcontext :drawable window :font font
                                         :background black :foreground white))
         (colors (map 'vector (lambda (c) (xlib:alloc-color colormap c))
                      #("red" "green" "blue" "Darkgreen" "yellow"
                        "lightblue" "Cyan" "Magenta"))))
    (xlib:map-window window)
    (xlib:display-force-output dpy)
    (dotimes (i 10000)
      (xlib:with-gcontext (gcontext :foreground (aref colors (random 8)))
        (xlib:draw-glyphs window gcontext (random width) (random height) "*"))
      (xlib:display-force-output dpy))))
NIL

;; cleanup
(progn
  (symbol-cleanup '*dpy*)
  (symbol-cleanup '*font-count*)
  (symbol-cleanup '*screen*)
  (symbol-cleanup '*visual*)
  (symbol-cleanup '*root*)
  (symbol-cleanup '*colormap*)
  (symbol-cleanup '*color*)
  (symbol-cleanup '*font*)
  (symbol-cleanup '*window*)
  (symbol-cleanup '*window-position*)
  (symbol-cleanup 'check-query-best)
  (symbol-cleanup '*gcontext*)
  (symbol-cleanup 'c2s)
  (symbol-cleanup '*access-hosts*)
  (symbol-cleanup 'check-wm-class)
  (symbol-cleanup '*rdb-tmp*)
  (symbol-cleanup '*rdb-dpy*)
  (symbol-cleanup '*white-color*) (symbol-cleanup '*black-color*)
  (symbol-cleanup 'create-font-cursor)
  (symbol-cleanup 'map-windows)
  (symbol-cleanup 'iter-windows)
  (symbol-cleanup 'check-timeout))
T
