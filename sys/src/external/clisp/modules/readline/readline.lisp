;;; readline & history interface
;;; http://tiswww.case.edu/php/chet/readline/readline.html
;;; http://tiswww.case.edu/php/chet/readline/history.html
;;;
;;; Copyright (C) 2005-2010 by Sam Steingold
;;; This is Free Software, covered by the GNU GPL (v2+)
;;; See http://www.gnu.org/copyleft/gpl.html
;;;
;;; based on readline 6.1
;;; to upgrade: download readline source distributions and diff headers

(defpackage "READLINE"
  (:use "CL" "EXT" "FFI")
  (:shadowing-import-from "EXPORTING"
    #:defconstant #:defun #:defmacro #:defvar #:def-c-type #:def-c-enum
    #:def-c-struct #:def-c-var #:def-c-const #:def-call-out)
  (:documentation "
Interface to the GNU readline and history library. It allows you to
- use readline functionality for user input in your programs
  (see functions readline, add-history, and stream *readline-input-stream*)
- expand readline functionality with new functions that can be bound to keys
  (see add-defun, add-funmap-entry)
- run things on background while waiting for user input (see event-hook)
- more stuff (read readline info pages)"))

(in-package "READLINE")

(setf (documentation (find-package "READLINE") 'sys::impnotes) "readline-mod")

;;; foreign function definitions
(default-foreign-language :stdc)
(eval-when (compile) (setq *foreign-guard* t))

(c-lines "#include \"config.h\"~%") ; local readline config
(c-lines "#include <stdio.h>~%")

;;; ------ readline ------

(c-lines "#include <readline/readline.h>~%")

(def-c-const readline-version-number (:name "RL_READLINE_VERSION")
  (:documentation "Readline numeric version, see also `readline-version'."))
(def-c-const readline-version-major (:name "RL_VERSION_MAJOR")
  (:documentation "Readline major version."))
(def-c-const readline-version-minor (:name "RL_VERSION_MINOR")
  (:documentation "Readline minor version."))

(def-c-type command-func-t
    (c-function (:arguments (rep int) (char int))
                (:return-type int)))
(def-c-type compentry-func-t
    (c-function (:arguments (rep c-string) (char int))
                (:return-type c-string)))
(def-c-type completion-func-t
    (c-function (:arguments (rep c-string) (char int) (rep int))
                (:return-type (c-ptr c-string))))
(def-c-type readline-hook-function (c-function (:return-type int)))
(def-c-type readline-vcpfunc (c-function (:arguments (text c-string))))
(def-c-type keymap c-pointer)

;;; Basic behavior
(def-call-out readline (:name "readline")
  (:documentation
    "Prompt and return string read from readline library or nil as eof.")
  (:arguments (prompt c-string))
  (:return-type c-string :malloc-free))

(def-call-out set-prompt (:name "rl_set_prompt") ; untested
  (:arguments (prompt c-string))
  (:return-type int))

(def-call-out initialize (:name "rl_initialize")
  (:arguments) (:return-type int))

(def-call-out read-init-file (:name "rl_read_init_file")
  (:arguments (name c-string))
  (:return-type int))

;;; Function naming

(def-call-out add-defun (:name "rl_add_defun")
  (:arguments (name c-string :in :malloc-free)
              (callback command-func-t) (key int))
  (:return-type int)
  (:documentation "Bind function to a name and key. You can use
name in ~/.inputrc. This is preferred way of adding new functions."))

;;; Keymaps
(def-call-out make-bare-keymap (:name "rl_make_bare_keymap") ; untested
  (:documentation "Make empty keymap.")
  (:arguments) (:return-type keymap))

(def-call-out copy-keymap (:name "rl_copy_keymap") ; untested
  (:arguments (map keymap) (:return-type keymap)))

(def-call-out make-keymap (:name "rl_make_keymap") ; untested
  (:documentation "Make simple keymap - chars bound to self-insert etc.")
  (:arguments) (:return-type keymap))

(def-call-out discard-keymap (:name "rl_discard_keymap") ; untested
  (:documentation "Discard allocated keymap.")
  (:arguments (map keymap)) (:return-type nil))

(def-call-out get-keymap (:name "rl_get_keymap") ; untested
  (:documentation "Return current keymap")
  (:arguments) (:return-type keymap))

(def-call-out set-keymap (:name "rl_set_keymap") ; untested
  (:documentation "Set keymap as current")
  (:arguments (map keymap)) (:return-type nil))

(def-call-out get-keymap-by-name (:name "rl_get_keymap_by_name") ; untested
  (:documentation "Get keymap with given name (e.g., emacs, vi)")
  (:arguments (name c-string)) (:return-type keymap))

(def-call-out get-keymap-name (:name "rl_get_keymap_by_name") ; untested
  (:arguments (keymap keymap)) (:return-type c-string))

;;; Binding Keys

(def-call-out bind-key (:name "rl_bind_key")
  (:arguments (key int) (callback command-func-t))
  (:return-type int))

(def-call-out bind-key-in-map (:name "rl_bind_key_in_map") ; untested
  (:arguments (key int) (callback command-func-t) (map keymap))
  (:return-type int))

(def-call-out bind-key-if-unbound (:name "rl_bind_key_if_unbound") ; untested
  (:arguments (key int) (callback command-func-t))
  (:return-type int))

(def-call-out bind-key-if-unbound-in-map (:name "rl_bind_key_if_unbound_in_map") ; untested
  (:arguments (key int) (callback command-func-t) (map keymap))
  (:return-type int))

(def-call-out unbind-key (:name "rl_unbind_key")
  (:arguments (key int))
  (:return-type int))

(def-call-out unbind-key-in-map (:name "rl_unbind_key_in_map") ; untested
  (:arguments (key int) (map keymap))
  (:return-type int))

(def-call-out unbind-function-in-map (:name "rl_unbind_function_in_map") ; untested
  (:arguments (fn command-func-t) (map keymap))
  (:return-type int))

(def-call-out unbind-command-in-map (:name "rl_unbind_command_in_map") ; untested
  (:arguments (command c-string) (map keymap))
  (:return-type int))

(def-call-out bind-keyseq (:name "rl_bind_keyseq")
  (:arguments (keyseq c-string)
              (callback command-func-t))
  (:return-type int))

(def-call-out bind-keyseq-in-map (:name "rl_bind_keyseq_in_map")
  (:arguments (keyseq c-string) (callback command-func-t) (map keymap))
  (:return-type int))

; set-key is equivalent to bind-keyseq-in-map

(def-call-out bind-keyseq-if-unbound (:name "rl_bind_keyseq_if_unbound"); untested
  (:arguments (keyseq c-string)
              (callback command-func-t))
  (:return-type int))

(def-call-out bind-keyseq-if-unbound-in-map (:name "rl_bind_keyseq_if_unbound_in_map"); untested
  (:arguments (keyseq c-string) (callback command-func-t) (map keymap))
  (:return-type int))

(def-call-out generic-bind (:name "rl_generic_bind") ; untested
  (:arguments (type int) (keyseq c-string) (data c-pointer) (map keymap))
  (:return-type int))

(def-call-out parse-and-bind (:name "rl_parse_and_bind")
  (:arguments (line c-string))
  (:return-type int))

;;; Associating Function Names and Bindings

(def-call-out named-function (:name "rl_named_function")
  (:arguments (name c-string))
  (:return-type command-func-t))

(def-call-out function-of-keyseq (:name "rl_function_of_keyseq")
  (:arguments (keyseq c-string) (map keymap) (type (c-ptr int) :out))
  (:return-type command-func-t))

(def-call-out invoking-keyseqs (:name "rl_invoking_keyseqs")
  (:arguments (function command-func-t))
  (:return-type (c-array-ptr c-string)))

(def-call-out invoking-keyseqs-in-map (:name "rl_invoking_keyseqs_in_map") ; untested
  (:arguments (function command-func-t) (map keymap))
  (:return-type (c-array-ptr c-string)))

(def-call-out function-dumper (:name "rl_function_dumper")
  (:arguments (readable int))
  (:return-type nil))

(def-call-out list-funmap-names (:name "rl_list_funmap_names")
  (:arguments) (:return-type nil))

;;; !!! Returned array should be freed, but if I :malloc-free it, clisp
;;; tries to free the c-string too. Bad.
(def-call-out funmap-names (:name "rl_funmap_names") ; FIXME: leaks
  (:arguments) (:return-type (c-array-ptr c-string)))

(def-call-out add-funmap-entry  (:name "rl_add_funmap_entry") ; untested
  (:arguments (name c-string :in :malloc-free) (callback command-func-t))
  (:return-type int)
  (:documentation "Bind function to a name known to readline."))


;;; Allowing undoing

;;; constants used by add-undo.
(def-c-enum undo_code UNDO_DELETE UNDO_INSERT UNDO_BEGIN UNDO_END)

(def-call-out begin-undo-group  (:name "rl_begin_undo_group") ; untested
  (:arguments) (:return-type int))

(def-call-out end-undo-group (:name "rl_end_undo_group") ; untested
  (:arguments) (:return-type int))

(def-call-out add-undo (:name "rl_add_undo") ; untested
  (:arguments (what int) (start int) (end int) (text c-string))
  (:return-type nil))

(def-call-out free-undo-list (:name "rl_free_undo_list") ; untested
  (:arguments) (:return-type nil))

(def-call-out do-undo  (:name "rl_do_undo") ; untested
  (:arguments) (:return-type int))

(def-call-out modifying (:name "rl_modifying") ; untested
  (:arguments (start int) (end int))
  (:return-type int))

;;; Redisplay

(def-call-out redisplay (:name "rl_redisplay")
  (:arguments) (:return-type int))

(def-call-out forced-update-display (:name "rl_forced_update_display")
  (:arguments) (:return-type int))

(def-call-out on-new-line (:name "rl_on_new_line")
  (:arguments) (:return-type int))

(def-call-out on-new-line-with-prompt (:name "rl_on_new_line_with_prompt") ; untested
  (:arguments ) (:return-type int))

(def-call-out reset-line-state (:name "rl_reset_line_state") ; untested
  (:arguments) (:return-type int))

(def-call-out crlf (:name "rl_crlf") ; untested
  (:arguments) (:return-type int))

(def-call-out show-char (:name "rl_show_char") ; untested
  (:arguments (char int)) (:return-type int))

(def-call-out message (:name "rl_message") ; untested
  (:arguments (text c-string))
  (:return-type int)
  (:documentation
    "Prints message (given as a format string - beware of %) in message area."))

(def-call-out clear-message (:name "rl_clear_message") ; untested
  (:arguments) (:return-type int))

(def-call-out save-prompt (:name "rl_save_prompt") ; untested
  (:arguments) (:return-type nil))

(def-call-out restore-prompt (:name "rl_restore_prompt") ; untested
  (:arguments) (:return-type nil))

(def-call-out expand-prompt (:name "rl_expand_prompt") ; untested
  (:arguments (prompt c-string)) (:return-type int))

;;; Modifying text

(def-call-out insert-text (:name "rl_insert_text")
  (:arguments (text c-string))
  (:return-type int))

(def-call-out delete-text (:name "rl_delete_text") ; untested
  (:arguments (start int) (end int))
  (:return-type int))

(def-call-out copy-text (:name "rl_copy_text") ; untested
  (:arguments (start int) (end int))
  (:return-type int))

(def-call-out kill-text (:name "rl_kill_text") ; untested
  (:arguments (start int) (end int))
  (:return-type int))

(def-call-out push-macro-input (:name "rl_push_macro_input")
  (:arguments (macro c-string))
  (:return-type int))

;;; Character input

(def-call-out read-key (:name "rl_read_key") ; untested
  (:arguments) (:return-type int))

(def-call-out getc (:name "rl_getc") ; untested
  (:arguments (stream c-pointer)) (:return-type int))

(def-call-out stuff-char (:name "rl_stuff_char") ; untested
  (:arguments (char int)) (:return-type int))

(def-call-out execute-next (:name "rl_execute_next") ; untested
  (:arguments (char int)) (:return-type int))

(def-call-out clear-pending-input (:name "rl_clear_pending_input") ; untested
  (:arguments) (:return-type int))

(def-call-out set-keyboard-input-timeout (:name "rl_set_keyboard_input_timeout")
  (:arguments (microseconds int))
  (:return-type int)) ; returns old value

;;; Terminal management

(def-call-out prep-terminal (:name "rl_prep_terminal") ; untested
  (:arguments (meta-flag int)) (:return-type nil))

(def-call-out deprep-terminal (:name "rl_deprep_terminal") ; untested
  (:arguments) (:return-type nil))

(def-call-out tty-set-default-bindings (:name "rl_tty_set_default_bindings") ; untested
  (:arguments (map keymap)) (:return-type nil))

(def-call-out reset-terminal (:name "rl_reset_terminal") ; untested
  (:arguments (terminal-name c-string)) (:return-type int))


;;; Utility

(def-call-out replace-line (:name "rl_replace_line") ; untested
  (:arguments (new-line c-string) (clear-undo int))
  (:return-type nil))

(def-call-out extend-line-buffer (:name "rl_extend_line_buffer") ; untested
  (:arguments (len int))
  (:return-type int))

(def-call-out ding (:name "rl_ding")
  (:arguments) (:return-type int))

(def-call-out alphabetic (:name "rl_alphabetic")
  (:arguments (c int)) (:return-type int))

(def-call-out free (:name "rl_free")
  (:arguments (arg c-pointer)) (:return-type nil))

(def-call-out display-match-list (:name "rl_display_match_list")
  (:arguments (matches (c-array-ptr c-string)) (len int) (max int))
  (:return-type nil))

;;; Miscellaneous functions

(def-call-out variable-value (:name "rl_variable_value")
  (:arguments (variable c-string))
  (:return-type c-string))

(def-call-out variable-bind (:name "rl_variable_bind")
  (:arguments (variable c-string) (value c-string))
  (:return-type int))

(def-call-out macro-dumper (:name "rl_macro_dumper") ; untested
  (:arguments (readable int))
  (:return-type nil))

(def-call-out variable-dumper (:name "rl_variable_dumper") ; untested
  (:arguments (readable int))
  (:return-type nil))

(def-call-out echo-signal-char (:name "rl_echo_signal_char") ; untested
  (:arguments (readable int))
  (:return-type nil))

(def-call-out set-paren-blink-timeout (:name "rl_set_paren_blink_timeout") ; untested
  (:arguments (u int))
  (:return-type int))

(def-call-out get-termcap (:name "rl_get_termcap") ; untested
  (:arguments (cap c-string))
  (:return-type c-string))

;;; Signal Handling
(def-call-out resize-terminal (:name "rl_resize_terminal")
  (:arguments) (:return-type nil))

(def-call-out set-screen-size (:name "rl_set_screen_size")
  (:arguments (rows int) (cols int)) (:return-type nil))

(def-call-out get-screen-size (:name "rl_get_screen_size")
  (:arguments (rows (c-ptr int) :out) (cols (c-ptr int) :out))
  (:return-type nil))

(def-call-out reset-screen-size (:name "rl_reset_screen_size")
  (:arguments) (:return-type nil))

;;; Alternate interface
(def-call-out callback-handler-install (:name "rl_callback_handler_install")
  (:arguments (prompt c-string) (lhandler readline-vcpfunc)))
(def-call-out callback-read-char (:name "rl_callback_read_char"))
(def-call-out callback-handler-remove (:name "rl_callback_handler_remove"))



;;; variables
(def-c-var library-version (:name "rl_library_version")
  (:documentation
   "The version of this incarnation of the readline library, e.g., \"4.2\".")
  (:type c-string) (:read-only t))
(def-c-var readline-version (:name "rl_readline_version")
  (:type int) (:read-only t)
  (:documentation
   "The version of this incarnation of the readline library, e.g., 0x0402."))
(def-c-var gnu-readline-p (:name "rl_gnu_readline_p") (:type int)
  (:documentation "True if this is real GNU readline."))
(def-c-var readline-state (:name "rl_readline_state") (:type int)
  (:documentation "Flags word encapsulating the current readline state."))
(def-c-var editing-mode (:name "rl_editing_mode") (:type int)
  (:documentation "Says which editing mode readline is currently using.
1 means emacs mode; 0 means vi mode."))
(defconstant editing-mode-vi 0)
(defconstant editing-mode-emacs 1)
(def-c-var insert-mode (:name "rl_insert_mode") (:type int)
  (:documentation "Insert or overwrite mode for emacs mode.
1 means insert mode; 0 means overwrite mode.
Reset to insert mode on each input line."))
(defconstant insert-mode-overwrite 0)
(defconstant insert-mode-insert 1)
(def-c-var readline-name (:name "rl_readline_name")
  (:type c-string) (:alloc :malloc-free)
  (:documentation "The name of the calling program.
You should initialize this to whatever was in argv[0].
It is used when parsing conditionals."))
(def-c-var prompt (:name "rl_prompt") (:type c-string) (:read-only t)
  (:documentation "The prompt readline uses.
This is set from the argument to readline (),
and should not be assigned to directly."))
(def-c-var display-prompt (:name "rl_display_prompt")
  (:type c-string) (:read-only t)
  (:documentation "The prompt string that is actually displayed by rl_redisplay.
Public so applications can more easily supply their own redisplay functions."))
(def-c-var line-buffer (:name "rl_line_buffer") (:type c-string)
  (:documentation "The line gathered so far."))
(def-c-var point (:name "rl_point") (:type int)
  (:documentation "The offset of current position in line-buffer"))
(def-c-var end (:name "rl_end") (:type int)
  (:documentation "The offset of current position in line-buffer"))
(def-c-var mark (:name "rl_mark") (:type int)
  (:documentation "The MARK (saved position) in the current line."))
(def-c-var done (:name "rl_done") (:type int)
  (:documentation
    "Non-zero value causes Readline to return the current line immediately."))
(def-c-var pending-input (:name "rl_pending_input") (:type int)
  (:documentation "Setting this to a value makes it next keystroke read."))
(def-c-var dispatching (:name "rl_dispatching") (:type int) (:read-only t)
  (:documentation "Non-zero if function is being called from a key binding."))
(def-c-var explicit-arg (:name "rl_explicit_arg") (:type int)
  (:documentation "Non-zero if the user typed a numeric argument before executing the current function."))
(def-c-var numeric-arg (:name "rl_numeric_arg") (:type int)
  (:documentation "The current value of the numeric argument specified by the user."))
(def-c-var last-func (:name "rl_last_func") (:type command-func-t)
  (:documentation
   "The address of the last command function Readline executed."))
(def-c-var terminal-name (:name "rl_terminal_name") (:type c-string)
  (:documentation "The name of the terminal to use."))
(def-c-var instream (:name "rl_instream") (:type c-pointer))
(def-c-var outstream (:name "rl_outstream") (:type c-pointer))
(def-c-var prefer-env-winsize (:name "rl_prefer_env_winsize") (:type int)
  (:documentation "If non-zero, Readline gives values of LINES and COLUMNS
from the environment greater precedence than values fetched from the kernel
when computing the screen dimensions."))
(def-c-var startup-hook (:name "rl_startup_hook") (:type readline-hook-function)
  (:documentation "If non-zero, then this is the address of a function to call
just before readline_internal() prints the first prompt."))
(def-c-var pre-input-hook (:name "rl_pre_input_hook")
  (:type readline-hook-function)
  (:documentation "If non-zero, this is the address of a function to call
just before readline_internal_setup() returns and readline_internal starts
reading input characters."))
(def-c-var event-hook (:name "rl_event_hook") (:type readline-hook-function)
  (:documentation "The address of a function to call periodically while
Readline is awaiting character input, or NULL, for no event handling."))
(def-c-var getc-function (:name "rl_getc_function")
  (:type (c-function (:arguments (instream c-pointer)) (:return-type int)))
  (:documentation "The address of the function to call to fetch a character
from the current Readline input stream."))

;; Display variables.
(def-c-var erase-empty-line (:name "rl_erase_empty_line") (:type int)
  (:documentation "If non-zero, readline will erase the entire line,
including any prompt, if the only thing typed on an otherwise-blank
line is something bound to rl_newline."))
(def-c-var already-prompted (:name "rl_already_prompted") (:type int)
  (:documentation "If non-zero, the application has already printed the
prompt (rl_prompt) before calling readline, so readline should not output
it the first time redisplay is done."))
(def-c-var num-chars-to-read (:name "rl_num_chars_to_read") (:type int)
  (:documentation "A non-zero value means to read only this many characters
rather than up to a character bound to accept-line."))
(def-c-var executing-macro (:name "rl_executing_macro") (:type c-string)
  (:documentation "The text of a currently-executing keyboard macro."))

(def-c-var filename-quoting-desired (:name "rl_filename_quoting_desired")
  (:type int)
  (:documentation "Non-zero means that the results of the matches are to be
quoted using double quotes (or an application-specific quoting mechanism)
if the filename contains any characters in rl_word_break_chars.
This is ALWAYS non-zero on entry, and can only be changed within a completion
entry finder function."))
(def-c-var attempted-completion-over (:name "rl_attempted_completion_over")
  (:type int)
  (:documentation "Non-zero means to suppress normal filename completion after
the user-specified completion function has been called."))
(def-c-var completion-type (:name "rl_completion_type") (:type int)
  (:documentation "Set to a character describing the type of completion being
attempted by rl_complete_internal; available for use by application completion
functions."))
(def-c-var completion-invoking-key (:name "rl_completion_invoking_key")
  (:type int)
  (:documentation
   "Set to the last key used to invoke one of the completion functions"))
(def-c-var completion-query-items (:name "rl_completion_query_items")
  (:type int)
  (:documentation "Up to this many items will be displayed in response to a
possible-completions call.  After that, we ask the user if she
is sure she wants to see them all.  The default value is 100."))
(def-c-var completion-append-character (:name "rl_completion_append_character")
  (:type int)
  (:documentation "Character appended to completed words when at the end of
the line.  The default is a space.  Nothing is added if this is '\0'."))
(def-c-var completion-suppress-append (:name "rl_completion_suppress_append")
  (:type int)
  (:documentation "If set to non-zero by an application completion function,
rl_completion_append_character will not be appended."))
(def-c-var completion-quote-character (:name "rl_completion_quote_character")
  (:type int)
  (:documentation "Set to any quote character readline thinks it finds before
any application completion function is called."))
(def-c-var completion-found-quote (:name "rl_completion_found_quote")
  (:type int) (:documentation "Set to a non-zero value if readline found
quoting anywhere in the word to be completed; set before any application
completion function is called."))
(def-c-var completion-suppress-quote (:name "rl_completion_suppress_quote")
  (:type int) (:documentation "If non-zero, the completion functions don't
append any closing quote. This is set to 0 by rl_complete_internal and may be
changed by an application-specific completion function."))
(def-c-var sort-completion-matches (:name "rl_sort_completion_matches")
  (:type int) (:documentation "If non-zero, readline will sort the completion
matches.  On by default."))
(def-c-var completion-mark-symlink-dirs (:type int)
  (:name "rl_completion_mark_symlink_dirs")
  (:documentation "If non-zero, a slash will be appended to completed filenames
that are symbolic links to directory names, subject to the value of the
mark-directories variable (which is user-settable).
This exists so that application completion functions can override the user's
preference (set via the mark-symlinked-directories variable) if appropriate.
It's set to the value of _rl_complete_mark_symlink_dirs in
rl_complete_internal before any application-specific completion
function is called, so without that function doing anything, the user's
preferences are honored."))
(def-c-var ignore-completion-duplicates (:type int)
  (:name "rl_ignore_completion_duplicates")
  (:documentation "If non-zero, then disallow duplicates in the matches."))
(def-c-var inhibit-completion (:name "rl_inhibit_completion") (:type int)
  (:documentation "If this is non-zero, completion is (temporarily) inhibited,
and the completion character will be inserted as any other."))

(def-c-const state-none (:name "RL_STATE_NONE") ; 0x000000
  (:documentation "no state; before first call"))
(def-c-const state-initializing (:name "RL_STATE_INITIALIZING") ; 0x000001
  (:documentation "initializing"))
(def-c-const state-initialized (:name "RL_STATE_INITIALIZED") ; 0x000002
  (:documentation "initialization done"))
(def-c-const state-termprepped (:name "RL_STATE_TERMPREPPED") ; 0x000004
  (:documentation "terminal is prepped"))
(def-c-const state-readcmd (:name "RL_STATE_READCMD") ; 0x000008
  (:documentation "reading a command key"))
(def-c-const state-metanext (:name "RL_STATE_METANEXT") ; 0x000010
  (:documentation "reading input after ESC"))
(def-c-const state-dispatching (:name "RL_STATE_DISPATCHING") ; 0x000020
  (:documentation "dispatching to a command"))
(def-c-const state-moreinput (:name "RL_STATE_MOREINPUT") ; 0x000040
  (:documentation "reading more input in a command function"))
(def-c-const state-isearch (:name "RL_STATE_ISEARCH") ; 0x000080
  (:documentation "doing incremental search"))
(def-c-const state-nsearch (:name "RL_STATE_NSEARCH") ; 0x000100
  (:documentation "doing non-inc search"))
(def-c-const state-search (:name "RL_STATE_SEARCH") ; 0x000200
  (:documentation "doing a history search"))
(def-c-const state-numericarg (:name "RL_STATE_NUMERICARG") ; 0x000400
  (:documentation "reading numeric argument"))
(def-c-const state-macroinput (:name "RL_STATE_MACROINPUT") ; 0x000800
  (:documentation "getting input from a macro"))
(def-c-const state-macrodef (:name "RL_STATE_MACRODEF") ; 0x001000
  (:documentation "defining keyboard macro"))
(def-c-const state-overwrite (:name "RL_STATE_OVERWRITE") ; 0x002000
  (:documentation "overwrite mode"))
(def-c-const state-completing (:name "RL_STATE_COMPLETING") ; 0x004000
  (:documentation "doing completion"))
(def-c-const state-sighandler (:name "RL_STATE_SIGHANDLER") ; 0x008000
  (:documentation "in readline sighandler"))
(def-c-const state-undoing (:name "RL_STATE_UNDOING") ; 0x010000
  (:documentation "doing an undo"))
(def-c-const state-inputpending (:name "RL_STATE_INPUTPENDING") ; 0x020000
  (:documentation "rl_execute_next called"))
(def-c-const state-ttycsaved (:name "RL_STATE_TTYCSAVED") ; 0x040000
  (:documentation "tty special chars saved"))
(def-c-const state-callback (:name "RL_STATE_CALLBACK") ; 0x080000
  (:documentation "using the callback interface"))
(def-c-const state-vimotion (:name "RL_STATE_VIMOTION") ; 0x100000
  (:documentation "reading vi motion arg"))
(def-c-const state-multikey (:name "RL_STATE_MULTIKEY") ; 0x200000
  (:documentation "reading multiple-key command"))
(def-c-const state-vicmdonce (:name "RL_STATE_VICMDONCE") ; 0x400000
  (:documentation "entered vi command mode at least once"))
(def-c-const state-redisplaying (:name "RL_STATE_REDISPLAYING") ; 0x800000
  (:documentation "updating terminal display"))
(def-c-const state-done (:name "RL_STATE_DONE") ; 0x1000000
  (:documentation "done; accepted line"))

(def-c-const readerr ; (-2)
  (:documentation " Input error; can be returned by (*rl_getc_function)
if readline is reading a top-level command (RL_ISSTATE (RL_STATE_READCMD))."))

(def-c-const default-inputrc (:name "DEFAULT_INPUTRC")
  (:type c-string)              ; "~/.inputrc"
  (:documentation
   "The next-to-last-ditch effort file name for a user-specific init file."))

(def-c-const sys-inputrc (:name "SYS_INPUTRC")
  (:type c-string) ; "/etc/inputrc"
  (:documentation
   "The ultimate last-ditch filenname for an init file -- system-wide."))

;;; ------ history ------

(c-lines "#include <readline/history.h>~%")

;;; History List Management

(def-call-out using-history (:name "using_history")
  (:arguments) (:return-type nil))

(def-call-out add-history (:name "add_history")
  (:arguments (line c-string)) (:return-type nil))

(def-call-out clear-history (:name "clear_history")
  (:arguments) (:return-type nil))

(def-call-out stifle-history (:name "stifle_history")
  (:arguments (count int)) (:return-type nil))

(def-call-out unstifle-history (:name "unstifle_history")
  (:arguments) (:return-type int))

(def-call-out history-stifled-p (:name "history_is_stifled")
  (:arguments) (:return-type int))

;;; Information About the History List

(def-call-out where-history (:name "where_history")
  (:arguments) (:return-type int))

(def-call-out history-total-bytes (:name "history_total_bytes")
  (:arguments) (:return-type int))

;;; Moving Around the History List

(def-call-out history-set-pos (:name "history_set_pos")
  (:arguments (pos int)) (:return-type int))

;;; Searching the History List

(def-call-out history-search (:name "history_search")
  (:arguments (string c-string) (direction int)) (:return-type int))

(def-call-out history-search-prefix (:name "history_search_prefix")
  (:arguments (string c-string) (direction int)) (:return-type int))

(def-call-out history-search-pos (:name "history_search_pos")
  (:arguments (string c-string) (direction int) (pos int)) (:return-type int))

;;; Managing the History File

(def-call-out read-history (:name "read_history")
  (:arguments (file c-string)) (:return-type int))

(def-call-out read-history-range (:name "read_history_range")
  (:arguments (file c-string) (start int) (end int)) (:return-type int))

(def-call-out write-history (:name "write_history")
  (:arguments (file c-string)) (:return-type int))

(def-call-out append-history (:name "append_history")
  (:arguments (count int) (file c-string)) (:return-type int))

(def-call-out history-truncate-file (:name "history_truncate_file")
  (:arguments (file c-string) (nlines int)) (:return-type int))

;; tilde.h

(def-call-out tilde-expand (:name "tilde_expand")
  (:arguments (string c-string)) (:return-type c-string))

;;; done with ffi

;;; Define input stream that will read from readline-enabled input.
;;; This is not strictly interface to readline capability, but it makes the
;;; interface more usable - you can, e.g., (read *readline-input-stream*)

(defun readline-reader ()
  "Read a single line using GNU readline with the standard CLISP prompt."
  (let ((string (readline (ext:string-concat (sys::prompt-start)
                                             (sys::prompt-body)
                                             (sys::prompt-finish)))))
    (declare (type (or null string) string))
    (when string                ; string=NIL ==> EOF
      (cond ((zerop (length string)) #1=#.(string #\NewLine))
            (t (add-history string)
               (ext:string-concat string #1#))))))

(defvar *readline-input-stream*
  (make-buffered-input-stream #'readline-reader nil)
  "Use this input stream to allow readline editing.")

(pushnew :readline *features*)
(provide "readline")
(pushnew "READLINE" custom:*system-package-list* :test #'string=)
