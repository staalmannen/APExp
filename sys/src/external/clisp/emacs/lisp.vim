" Vim syntax file
" Language: Lisp (with extensions for CLISP)

set enc=utf-8
set iskeyword+=&
set ignorecase
set smartcase

" CLISP FFI:
syn match lispDecl "\<\(ffi:\)\?def-c-\(var\|const\|enum\|type\|struct\)\>"
syn match lispDecl "\<\(ffi:\)\?def-call-\(out\|in\)\>"
syn match lispDecl "\<\(ffi:\)\?c-\(function\|struct\|pointer\|string\)\>"
syn match lispDecl "\<\(ffi:\)\?c-ptr\(-null\)\?\>"
syn match lispDecl "\<\(ffi:\)\?c-array\(-ptr\|-max\)\?\>"
syn match lispDecl "\<\(ffi:\)\?[us]\?\(char\|short\|int\|long\)\>"
syn keyword lispDecl size_t off_t time_t handle
syn match lispDecl "\<\(win32:\|w32\)\?d\?word\>"
syn match lispDecl "\<\([us]_\?\)\?int\(8\|16\|32\|64\)\(_t\)\?\>"
syn match lispFunc "\<\(ffi:\)\?with-c-\(place\|var\)\>"
syn match lispFunc "\<\(ffi:\)\?with-foreign-\(object\|string\)\>"
syn match lispFunc "\<\(ffi:\)\?default-foreign-\(language\|library\)\>"
syn match lispFunc "\<\([us]_\?\)\?\(element\|deref\|cast\|slot\|validp\)\>"
syn match lispFunc "\<\(ffi:\)\?set-foreign-pointer\>"
syn match lispFunc "\<\(ffi:\)\?allocate-\(deep\|shallow\)\>"
syn match lispFunc "\<\(ffi:\)\?c-lines\>"
syn match lispFunc "\<\(ffi:\)\?foreign-\(value\|free\|variable\|function\|object\)\>"
syn match lispFunc "\<\(ffi:\)\?foreign-address\(-null\|unsigned\)\?\>"
syn match lispFunc "\<\(ffi:\)\?undigned-foreign-address\>"
syn match lispFunc "\<\(ffi:\)\?c-var-\(address\|object\)\>"
syn match lispFunc "\<\(ffi:\)\?typeof\>"
syn match lispFunc "\<\(ffi:\)\?\(bit\)\?sizeof\>"
syn keyword lispKey :arguments :return-type :library :full :malloc-free
syn keyword lispKey :none :alloca :in :out :in-out :stdc-stdcall :stdc :c
syn keyword lispKey :language :built-in :typedef :external
syn keyword lispKey :fini :init-once :init-always

" ANSI Extended LOOP:
syn keyword lispKey :while :until :for :do :if :then :else :when :unless :in
syn keyword lispKey :across :finally :collect :nconc :maximize :minimize :sum
syn keyword lispKey :and :with :initially :append :into :count :end :repeat
syn keyword lispKey :always :never :thereis :from :to :upto :downto :below
syn keyword lispKey :above :by :on :being :each :the :hash-key :hash-keys
syn keyword lispKey :hash-value :hash-values :using :of-type :upfrom :downfrom

" CLISP Macros, functions et al:
syn match lispFunc "\<\(ext:\)\?with-collect\>"
syn match lispFunc "\<\(ext:\)\?letf\*\?\>"
syn match lispFunc "\<\(ext:\)\?finalize\>\>"
syn match lispFunc "\<\(ext:\)\?memoized\>"
syn match lispFunc "\<\(ext:\)\?getenv\>"
syn match lispFunc "\<\(ext:\)\?convert-string-\(to\|from\)-bytes\>"
syn match lispFunc "\<\(ext:\)\?ethe\>"
syn match lispFunc "\<\(ext:\)\?with-gensyms\>"
syn match lispFunc "\<\(ext:\)\?open-http\>"
syn match lispFunc "\<\(ext:\)\?string-concat\>"
syn match lispFunc "\<\(ext:\)\?with-http-\(in\|out\)put\>"
syn match lispFunc "\<\(ext:\)\?with-html-output\>"
syn match lispFunc "\<\(ext:\)\?expand-form\>"
syn match lispFunc "\<\(ext:\)\?\(without-\)\?package-lock\>"
syn match lispFunc "\<\(ext:\)\?re-export\>"
syn match lispFunc "\<\(ext:\)\?saveinitmem\>"
syn match lispFunc "\<\(ext:\)\?\(read\|write\)-\(integer\|float\)\>"
syn match lispFunc "\<\(ext:\)\?\(read\|write\)-\(char\|byte\)-sequence\>"
syn match lispFunc "\<\(custom:\)\?\*system-package-list\*\>"
syn match lispFunc "\<\(custom:\)\?\*ansi\*\>"
syn keyword lispKey :unix :mac :dos :little :big :external-format :buffered

" General Lisp:
" +constant+
syn match lispSpecial "\<+[a-zA-Z_][a-zA-Z_0-9-]*+\>"
" defpackage arguments
syn keyword lispKey :documentation :shadowing-import-from :modern :export
syn keyword lispKey :case-sensitive :case-inverted :shadow :import-from :intern
" lambda list keywords
syn keyword lispKey &allow-other-keys &aux &body
syn keyword lispKey &environment &key &optional &rest &whole
" make-array argument
syn keyword lispKey :fill-pointer
" readtable-case values
syn keyword lispKey :upcase :downcase :preserve :invert
" eval-when situations
syn keyword lispKey :load-toplevel :compile-toplevel :execute
" '(#\") should not start a string
syn region  lispAtomList  contained matchgroup=Special start="(" skip="|.\{-}|" matchgroup=Special end=")" contains=@lispAtomCluster,lispString,lispSpecial
