/* Handling of terminating signals. */

/* in MT signals are handled in spvw.d:signal_handler_thread()*/
#if !defined(MULTITHREAD)

/* --------------------------- Specification ----------------------------- */

#if defined(HAVE_SIGNALS)
/* Installs the SIGTERM handler. */
local void install_sigterm_handler (void);
#endif

/* --------------------------- Implementation ---------------------------- */

#if defined(HAVE_SIGNALS)

local void set_sigterm_handler (signal_handler_t handler) {
  /* Iterate over those signals whose default action exits. */
#ifdef SIGHUP
  /* maybe ignore? No, use nohup instead */
  SIGNAL(SIGHUP,handler);
#endif
#ifdef SIGQUIT
  SIGNAL(SIGQUIT,handler);
#endif
#ifdef SIGILL
  SIGNAL(SIGILL,handler);
#endif
#ifdef SIGABRT
  SIGNAL(SIGABRT,handler);
#endif
#ifdef SIGKILL
  SIGNAL(SIGKILL,handler);
#endif
#ifdef SIGTERM
  SIGNAL(SIGTERM,handler);
#endif
}

local void uninstall_sigterm_handler (void) {
  begin_system_call();
  set_sigterm_handler(SIG_DFL);
  end_system_call();
}


/* print the "exiting" message and quit */
local void quit_on_signal (int sig) {
 #ifndef NO_ASYNC_INTERRUPTS
  if (quit_on_signal_in_progress) { /* quit without much ado */
    /* next signal will bypass this function and kill CLISP instantly: */
    uninstall_sigterm_handler();
    fprintf(stderr,GETTEXT("Signal %d while exiting on a signal; cleanup may be incomplete\n"),sig);
    raise(sig);    /* kill CLISP instantly with the correct exit code */
    return;        /* return from signal handler if the signal is blocked */
  }
  quit_on_signal_in_progress = true;
  signal_handler_prepare_for_lisp(sig);
  pushSTACK(Symbol_value(S(error_output))); fresh_line(&STACK_0);
  pushSTACK(CLSTEXT("Exiting on signal ")); pushSTACK(STACK_1);
  funcall(L(write_string),2);   /* (write-line "exiting" stderr) */
  pushSTACK(sint_to_I(sig)); pushSTACK(STACK_1);
  funcall(L(prin1),2);            /* (prin1 signal stderr) */
  terpri(&STACK_0); skipSTACK(1); /* drop *error-output* */
  final_exitcode = - sig;
  quit();
 #endif
}

/* install error handlers for as many signals as possible */
local void install_sigterm_handler (void) {
  set_sigterm_handler(&quit_on_signal);
#ifdef SIGTTOU
  /* we must ignore SIGTTOU to avoid the following issue:
      - when CLISP is running in the background,
      - and its i/o is not redirected,
      - and CLISP receives a terminating signal,
     then CLISP will be stopped instead of being terminated
     when it will try to write the "exiting..." message:
  <http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap11.html>
         Attempts by a process in a background process group to write to
         its controlling terminal shall cause the process group to be
         sent a SIGTTOU signal */
  SIGNAL(SIGTTOU,SIG_IGN);
#endif
}
#endif
#endif /* !MULTITHREAD */
