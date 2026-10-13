# CLISP .gdbinit
set language c

define boot
  file lisp.run
  set args -B . -N locale -E 1:1 -q -norc -M lispinit.mem
end
document boot
         debug the boot linking set
end

define base
  file base/lisp.run
  set args -B . -N locale -E 1:1 -q -norc -M base/lispinit.mem
end
document base
         debug the base linking set
end

define full
  file full/lisp.run
  set args -B . -N locale -E 1:1 -q -norc -M full/lispinit.mem
  # -i ../tests/tests -x '(run-test "***/test")'
  # -i clx/new-clx/demos/clx-demos.lisp -x '(clx-demos:run-all-demos)'
  break xlib_error_handler
  break x_type_error
  break error_closed_display
  break error_bdb
  break error_gdbm
  break error_pcre
end
document full
         debug the full linking set
end

define interpreted
  file lisp.run
  set args -B . -N locale -E 1:1 -q -norc -M interpreted.mem
end
document interpreted
         debug the boot linking set with the interpreted memory image
end

define zout
  output object_out($arg0)
  echo \n
end
document zout
         print the specified object with PRIN1 (consing!)
end

define xout
  output nobject_out(0,$arg0)
  echo \n
end
document xout
         print the specified object with nobject_out (non-consing)
end

# ffi.tst requires -E utf-8
define run_test
  run -B . -N locale -E utf-8 -q -norc -M lispinit.mem -i tests/tests -x "(run-test \"tests/$arg0\")"
end
document run_test
         run the specified test in the test suite
end

define run_all_tests
  run -B . -N locale -E utf-8 -q -norc -M lispinit.mem -i tests/tests -x "(cd \"tests/\") (run-all-tests)"
end
document run_all_tests
         run the whole test suite
end

define run_all_tests_parallel
  run -B . -N locale -E utf-8 -q -norc -M lispinit.mem -i tests/tests -x "(cd \"tests/\") (run-all-tests-parallel)"
end
document run_all_tests_parallel
         run the whole test suite, each file in its own thread
end

define run_mod_test
  run -B . -N locale -E 1:1 -q -norc -M base/lispinit.mem -i tests/tests -x "(run-test \"../modules/$arg0/test.tst\" :logname \"$arg0/test.erg\")"
end
document run_mod_test
         run the tests for the specified module
end

define run_ansi_tests
  run -B . -N locale -E utf-8 -q -norc -M lispinit.mem -ansi -x "(cd \"ansi-tests/\") (load \"clispload.lsp\") (in-package \"CL-TEST\") (time (regression-test:do-tests))"
end
document run_ansi_tests
         run the ANSI test suite
end

define run_ansi_tests_compiled
  run -B . -N locale -E utf-8 -q -norc -M lispinit.mem -ansi -x "(cd \"ansi-tests/\") (load \"clispload.lsp\") (in-package \"CL-TEST\") (setq regression-test::*compile-tests* t) (time (regression-test:do-tests))"
end
document run_ansi_tests_compiled
         run the gcl/ansi-test suite - compiled
end

define stack
  set $idx = $arg1
  while $idx >= $arg0
    echo ***** STACK_
    output $idx
    echo \ *****\n
    output object_out(STACK[-1-$idx])
    echo \n
    set $idx = $idx-1
  end
end
document stack
         print the section of STACK
end

define zbacktrace
  p back_trace_out(0,0)
end
document zbacktrace
         print the CLISP backtrace
end

break funcall
commands
  xout fun
end
disable

break apply
commands
  xout fun
end
disable

break eval
commands
  xout form
end
disable

break interpret_bytecode_
commands
  xout closure
end
disable

break gar_col
disable

# not available with MULTITHREAD
#watch back_trace
#commands
#  zbacktrace
#  continue
#end

break register_foreign_inttype
commands
  silent
  printf "%30s: %d %d\n", name_asciz, size, signed_p
  continue
end

break main_actions
commands
  silent
  call check_funtab()
  continue
end

break error_notreached
break SP_ueber
break STACK_ueber

break error
break prepare_error
break OS_error
break OS_file_error
break OS_filestream_error
break errno_out_low
break break_driver
break signal_and_debug

info break

#ifdef GENERATIONAL_GC
# This command fails in a build without GENERATIONAL_GC; this is normal.
break sigsegv_handler_failed
# You need to execute these two commands by hand, but *only* in a build
# with GENERATIONAL_GC. Also you need to undo them when the breakpoint
# at sigsegv_handler_failed has been triggered.
#handle SIGSEGV noprint nostop
#handle SIGBUS noprint nostop
#endif

#ifdef MULTITHREAD
# you need this when debugging multithreaded CLISP
# because SIGUSR1 is used by WITH-TIMEOUT
#handle SIGUSR1 noprint nostop
#end

# cut and paste when you stop in interpret_bytecode_()
watch byteptr
commands
  output byteptr-byteptr_in
  echo \n
end
