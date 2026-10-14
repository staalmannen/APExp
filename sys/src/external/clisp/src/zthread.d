/*
 * CLISP thread functions - multiprocessing
 * Distributed under the GNU GPL as a part of GNU CLISP
 * Sam Steingold 2003-2010
 * Vladimir Tzankov 2008-2010
 */

#include "lispbibl.c"

#ifdef MULTITHREAD

/* mutex for guarding access to O(all_mutexes) */
global xmutex_t all_mutexes_lock;
/* mutex for guarding access to O(all_exemptions) */
global xmutex_t all_exemptions_lock;

/* signals an error of obj is not thread. returns the thread*/
local maygc object check_thread(object obj)
{
  while (!threadp(obj)) {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(obj);             /* TYPE-ERROR slot DATUM */
    pushSTACK(S(thread));       /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(obj); pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: ~S is not a thread"));
    obj = value1;
  }
  return obj;
}

/* signals an error of obj is not mutex. returns the mutex*/
local maygc object check_mutex(object obj)
{
  while (!mutexp(obj)) {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(obj);             /* TYPE-ERROR slot DATUM */
    pushSTACK(S(mutex));        /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(obj); pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: ~S is not a mutex"));
    obj = value1;
  }
  return obj;
}

/* signals an error of obj is not exemption (POSIX condition).*/
local maygc object check_exemption(object obj)
{
  while (!exemptionp(obj)) {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(obj);             /* TYPE-ERROR slot DATUM */
    pushSTACK(S(exemption));    /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(obj); pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: ~S is not an exemption"));
    obj = value1;
  }
  return obj;
}

/* check the :NAME argument; accept:
 a string should, obviously, be allowed.
 a symbol is useful for
    (eq (symbol-value (foo-name foo)) foo)
    (eq (foo-name (symbol-value sym)) sym)
 an integer is useful for array pools (name = index into the pool)
 > name_arg: the :NAME argument
 > dflt: the default for unbound */
local object check_name_arg (object name_arg, object dflt) {
  if (!boundp(name_arg)) return dflt;
  while (!stringp(name_arg) && !symbolp(name_arg) && !integerp(name_arg)) {
    pushSTACK(NIL);              /* no PLACE */
    pushSTACK(name_arg);         /* TYPE-ERROR slot DATUM */
    pushSTACK(O(type_name_arg)); /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(name_arg); pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: name ~S should be a string, a symbol, or an integer"));
    name_arg = value1;
  }
  return name_arg;
}

/* releases the clisp_thread_t memory of the list of Thread records */
global void release_threads (object list) {
  /* Nothing to do here actually. In the past the memory of some
     thread allocated objects was released after the thread records has
     been GC-ed. Now everything is released upon thread termination.
     However this may be useful in future - when we will have threads
     created from foreign code callbacks (maybe). So it is left here. */
 #if 0
  while (!endp(list)) {
    list = Cdr(list);
  }
 #endif
}

/* releases the OS mutexes for mutex objects in the list */
global void release_mutexes (object list)
{
  while (!endp(list)) {
    begin_system_call();
    xmutex_destroy(TheMutex(Car(list))->xmu_system);
    free(TheMutex(Car(list))->xmu_system);
    end_system_call();
    list = Cdr(list);
  }
}

/* releases the OS condition variables for exemption objects in the list */
global void release_exemptions (object list)
{
  while (!endp(list)) {
    begin_system_call();
    xcondition_destroy(TheExemption(Car(list))->xco_system);
    free(TheExemption(Car(list))->xco_system);
    end_system_call();
    list = Cdr(list);
  }
}

/* UP: called at thread exiting. performs cleanup/checks.
   currently checks whether the exiting thread does not hold any mutex and
   releases them (if any) */
global maygc void thread_cleanup (void) {
  /* We are going to die - final cleanup will be performed. We do not want
   to be interrupted during it (actually no problem to be interrupted but
   if the interrupt performs non-local exit (incl. THREAD-KILL) we will end
   with inconsistent stack and various other problems - i.e. SIGSEGV) */
  var clisp_thread_t *me = current_thread();
  var uintC locked_mutexes = 0;
  me->_thread_is_dying = true; /* disables interrupts */
  /* traverse all mutexes and check for ownership
   nb: here the thread cannot be interrupted - no need for WITH_OS_MUTEX_LOCK*/
  var bool locked = false; /* dummy */
  GC_SAFE_MUTEX_LOCK(&all_mutexes_lock,&locked);
  var object list = O(all_mutexes);
  while (!endp(list)) {
    if (eq(TheMutex(Car(list))->xmu_owner, me->_lthread)) {
      /* we own the mutex. warn and release */
      pushSTACK(Car(list));
      locked_mutexes++;
    }
    list = Cdr(list);
  }
  GC_SAFE_MUTEX_UNLOCK(&all_mutexes_lock);
  /* now report and unlock all locked (by current thread) ones */
  var uintC count;
  dotimesC(count, locked_mutexes, {
    var object mutex = STACK_0;
    { /* warn */
      pushSTACK(NIL); pushSTACK(me->_lthread);
      pushSTACK(mutex);
      STACK_2 = CLSTEXT("Thread ~S is exiting while still owning mutex ~S. The mutex will be released.");
      funcall(S(warn),3);
    }
    /* release the mutex */
    TheMutex(STACK_0)->xmu_recurse_count = 0;
    TheMutex(STACK_0)->xmu_owner = NIL;
    GC_SAFE_MUTEX_UNLOCK(TheMutex(STACK_0)->xmu_system);
    skipSTACK(1); /* mutex */
  });
  /* from now on the thread may be considered inactive from lisp land
     let's signal join exemption that we are ready */
  pushSTACK(TheThread(me->_lthread)->xth_join_lock);
  funcall(L(mutex_lock),1);
  /* store the thread return values */
  TheThread(me->_lthread)->xth_values = popSTACK();
  /* broadcast to waiters */
  pushSTACK(TheThread(me->_lthread)->xth_join_exemption);
  funcall(L(exemption_broadcast),1);
  /* unlock mutex */
  pushSTACK(TheThread(me->_lthread)->xth_join_lock);
  funcall(L(mutex_unlock),1);

  /* the lisp stack should be unwound here. check it and complain. */
  if (!(eq(STACK_0,nullobj) && eq(STACK_1,nullobj))) {
    /* we should always have empty stack - this is an error. */
    NOTREACHED;
  }
}

/* UP: creates initial bindings in thread context from alist
 > initial_bindings: alist of (symbol . form) elements */
global void initialize_thread_bindings(gcv_object_t *initial_bindings) {
  /* do not defer interrupts by default and while evaluating initial forms */
  Symbol_thread_value(S(defer_interrupts)) = NIL;
  Symbol_thread_value(S(deferred_interrupts)) = NIL;
  if (!missingp(*initial_bindings)) {
    var uintC bind_count = 0;
    var gcv_object_t *bottom = &STACK_0;
    while (!endp(*initial_bindings)) { /* it is proper list */
      var object pair=Car(*initial_bindings);
      if (consp(pair) && symbolp(Car(pair))) {
        var object sym = Car(pair);
        /* look in the stack whether we have already bound this symbol */
        var gcv_object_t *top = &STACK_0;
        for (;bottom != top && !eq(*top,sym); top skipSTACKop 1) ;
        if (bottom == top) { /* not found */
          pushSTACK(sym); bind_count++; /* push the symbol */
          /* if the symbol does not have per thread value cell - add one */
          if (TheSymbol(sym)->tls_index == SYMBOL_TLS_INDEX_NONE) {
            pushSTACK(pair);
            add_per_thread_special_var(sym); /* maygc */
            pair = popSTACK();
          }
          eval(Cdr(pair)); /* maygc */
          Symbol_thread_value(STACK_0) = value1;
        }
      }
      *initial_bindings = Cdr(*initial_bindings);
    }
    skipSTACK(bind_count); /* restore the stack */
  }
}

/* All newly created threads start here.*/
local THREADPROC_SIGNATURE thread_stub(void *arg)
{
  #if USE_CUSTOM_TLS == 2
  tse __tse_entry;
  tse *__thread_tse_entry=&__tse_entry;
  #endif
  clisp_thread_t *me=(clisp_thread_t *)arg;
  set_current_thread(me); /* first: initialize TLS */
  var struct backtrace_t bt;
  me->_SP_anchor=(void*)SP();
  /* initialize backtrace */
  bt.bt_next = NULL;
  bt.bt_function = L(make_thread); /* not exactly */
  bt.bt_stack = STACK STACKop -1;
  bt.bt_num_arg = -1;
  back_trace = &bt;
  /* push the exit tag */
  pushSTACK(O(thread_exit_tag));
  var gcv_object_t *initial_bindings = &STACK_1;
  var gcv_object_t *funptr = &STACK_2;
  /* create the thread exit CATCH frame */
  var gcv_object_t* top_of_frame = STACK STACKop 1;
  var sp_jmp_buf returner; /* return point */
  finish_entry_frame(CATCH,returner,,{
    /* on thread kill in value1 we have :arguments list */
    skipSTACK(3+1);STACK_0=value1;goto end_of_thread;});
  {
    /* make "top" driver frame */
    var gcv_object_t* top_of_frame = STACK; /* pointer above frame */
    var sp_jmp_buf returner; /* remember entry point */
    /* driver frame in order to be able to kill the thread and unwind the stack
       via reset(0) call. It discards the CATCH frame as well. Useful when an
       error (error xxx) happens in the thread. */
    finish_entry_frame(DRIVER,returner,,{
      skipSTACK(2+3+1);STACK_0=NIL;goto end_of_thread;});
    /* initialize the low level i/o stuff for this thread*/
    init_reader_low(me);
    /* initialize thread special variables bindings */
    initialize_thread_bindings(initial_bindings);
    funcall(*funptr,0); /* call fun */
    skipSTACK(2+3+2);/* driver frame, catch frame, function + initial bindings*/
    /* store return values */
    mv_to_list();
    /* mark that thread will exit normally */
    TheThread(me->_lthread)->xth_flags |= thread_flag_normal_exit;
  }
 end_of_thread:
  /* stack layout: nullobj, nullobj, list of return values */
  /* cleanup any resources the thread still owns (locks currently) and
     signal thread's dead */
  thread_cleanup();
  /* un-register the thread and de-allocate stacks */
  delete_thread(me);
  xthread_exit(0);
  return NULL;
}

LISPFUN(make_thread,seclass_default,1,0,norest,key,4,
        (kw(name),kw(initial_bindings),kw(cstack_size),kw(vstack_size)))
{ /* (MAKE-THREAD function
                  &key name
                  (initial-bindings THREADS:*default-special-bindings*)
                  (cstack-size THREADS::*DEFAULT-CONTROL-STACK-SIZE*)
                  (vstack-size THREADS::*DEFAULT-VALUE-STACK-SIZE*)) */
  var clisp_thread_t *new_thread;
  /* init the stack size if not specified */
  if (missingp(STACK_0)) STACK_0 = Symbol_value(S(default_value_stack_size));
  if (missingp(STACK_1)) STACK_1 = Symbol_value(S(default_control_stack_size));
  var uintM vstack_size = I_to_uint32(check_uint32(popSTACK()));
  var uintM cstack_size = I_to_uint32(check_uint32(popSTACK()));
  if (!vstack_size) { /* lisp stack empty ? */
    /* use the same as the caller */
    vstack_size=STACK_item_count(STACK_bound,STACK_start);
  }
  if (cstack_size > 0 && cstack_size < 0x10000) { /* cstack too small ? */
    /* TODO: or maybe signal an error */
    /* let's allocate at least 64K */
    cstack_size = 0x10000;
  }
  if (vstack_size < ca_limit_1) {
    /* TODO: maybe signal an error */
    vstack_size = ca_limit_1;
  }
  /* check initial bindings */
  if (!boundp(STACK_0)) /* if not bound set to mt:*default-special-bidnings* */
    STACK_0 = Symbol_value(S(default_special_bindings));
  /* check that the list is proper one */
  STACK_0 = check_list(STACK_0);
  var object tail = NIL;
  var object len = list_length(STACK_0, &tail);
  if (!nullp(tail)) error_proper_list_dotted(S(make_thread),tail);
  if (nullp(len)) error_proper_list_circular(S(make_thread),STACK_0);
  /* check the function object has been passed*/
  if (!functionp(STACK_2))
    STACK_2 = check_function_replacement(STACK_2);
  /* set thread name */
  STACK_1 = check_name_arg(STACK_1,Closure_name(STACK_2));
  /* do allocations before thread locking */
  pushSTACK(allocate_thread(&STACK_1)); /* put it in GC visible place */
  pushSTACK(allocate_cons());
  /* stack layout: function, name, initial-binding, thread, cons */
  /* let's lock in order to create and register */
  var bool alloc_failed = false;
  var bool startup_failed = false;
  WITH_OS_MUTEX_LOCK(5,&allthreads_lock, {
    /* create clsp_thread_t */
    new_thread=create_thread(vstack_size);
    if (new_thread) {
      /* push 2 null objects in the thread stack to mark it's end (bottom) */
      NC_pushSTACK(new_thread->_STACK,nullobj);
      NC_pushSTACK(new_thread->_STACK,nullobj);
      /* push the function to be executed */
      NC_pushSTACK(new_thread->_STACK,STACK_4);
      /* push the initial bindings alist */
      NC_pushSTACK(new_thread->_STACK,STACK_2);

      var object new_cons=STACK_0;
      var object lthr=STACK_1;
      /* initialize the thread references */
      new_thread->_lthread=lthr;
      TheThread(lthr)->xth_globals=new_thread;
      /* add to all_threads global */
      Car(new_cons) = lthr;
      Cdr(new_cons) = O(all_threads);
      O(all_threads) = new_cons;
      /* create the OS thread */
      if (xthread_create(&TheThread(lthr)->xth_system,
                         &thread_stub,new_thread,cstack_size)) {
        /* mark the thread as terminated - thread-join will not block */
        TheThread(lthr)->xth_values = NIL;
        /* remove from O(all_threads) - this thread has never been alive */
        deleteq(O(all_threads),lthr);
        /* destroy clisp_thread_t */
        delete_thread(new_thread);
        startup_failed = true;
      }
    } else alloc_failed = true;
  });
  if (alloc_failed) {
    pushSTACK(S(make_thread));
    error(control_error,GETTEXT("~S: thread resource allocation failed"));
  }
  if (startup_failed) {
    pushSTACK(S(make_thread));
    error(control_error,GETTEXT("~S: spawning OS thread failed"));
  }
  VALUES1(STACK_1); /* return the thread */
  skipSTACK(5);
}

/* lock for the timeout_call_chain */
global spinlock_t timeout_call_chain_lock;
/* chain of sorted by expire time timeout_calls */
global timeout_call *timeout_call_chain=NULL;

/* returns true if p1 is before p2 (or equal) */
global bool timeval_less(struct timeval *p1, struct timeval *p2)
{
  return p1->tv_sec < p2->tv_sec
    || ((p1->tv_sec == p2->tv_sec) && ((p1->tv_usec <= p2->tv_usec)));
}

/* insert into sorted chain of timeout calls.
   returns true if it was inserted as first element.
   should be called with timeout_scheduler_lock held. */
local bool insert_timeout_call(timeout_call *tc)
{
  timeout_call **lastnextp=&timeout_call_chain,*chain=timeout_call_chain;
  while (chain != NULL && timeval_less(chain->expire, tc->expire)) {
    lastnextp=&chain->next; chain=chain->next;
  }
  *lastnextp=tc;
  tc->next=chain;
  return lastnextp == &timeout_call_chain;
}
/* removes a timeout_call from the chain and warns if it has failed.
   should be called without holding timeout_scheduler_lock (acquires it) */
local maygc void remove_timeout_call(timeout_call *tc)
{
  /* we do not use GC safe version here since we want to prevent
     thread interruption when unwiding the stack. If we do not this
     it will be possible to be interrupted here and current thread killed.
     this will leave bad pointer in the chain and will cause SIGSEGV in
     signal handling thread */
  spinlock_acquire(&timeout_call_chain_lock);
  var timeout_call **lastnextp=&timeout_call_chain,*chain=timeout_call_chain;
  while (chain != NULL && chain != tc) {
    lastnextp=&chain->next; chain=chain->next;
  }
  if (chain) { /* found - chain next. */
    *lastnextp = chain->next;
  }
  spinlock_release(&timeout_call_chain_lock);
  /* tc is on the current thread stack */
  if (chain && tc->failed) { /* tc == chain, if chain != NULL*/
    pushSTACK(CLSTEXT("CALL-WITH-TIMEOUT has failed in thread ~S."));
    pushSTACK(current_thread()->_lthread); /* tc->thread->_lthread */
    funcall(S(warn),2);
  }
}

LISPFUNN(call_with_timeout,3)
{ /* (CALL-WITH-TIMEOUT timeout timeout-function body-function)
     It's too expensive to spawn a new OS thread here.
     Instead CATCH frame is established, a timeout_call is queued
     in our signal handling thread and the body is executed. If the timeout
     elapses - the signal handling thread will interrupt the body
     and the timeout function will be executed. */
  var struct timeval tv;
  var struct timeval *tvp = sec_usec(STACK_2,unbound,&tv);
  if (tvp) {
    /* create the throw tag */
    funcall(L(gensym),0); pushSTACK(value1);
    var gcv_object_t* top_of_frame = STACK STACKop 1;
    var sp_jmp_buf returner; /* return point */
    finish_entry_frame(CATCH,returner,,{skipSTACK(3);goto timeout_function;});
    GC_SAFE_SPINLOCK_ACQUIRE(&timeout_call_chain_lock);
    /* start calculating the timeout after we get the spinlock ???
       maybe before is better and not to try anything if we are delayed */
    var struct timeval now;
    var struct timeval timeout;
    gettimeofday(&now,NULL);
    timeout.tv_sec = now.tv_sec + tv.tv_sec;
    timeout.tv_usec = (now.tv_usec + tv.tv_usec);
    /* no more than a second of carry */
    if (timeout.tv_usec >= 1000000) {
      timeout.tv_sec += 1;
      timeout.tv_usec -= 1000000;
    }
    var timeout_call tc={current_thread(),&STACK_2,false,&timeout,NULL};
    {
      /* funcall in UNWIND_PROTECT frame in order to cleanup the chain */
      var gcv_object_t* top_of_frame = STACK;
      var sp_jmp_buf returner; /* return point */
      finish_entry_frame(UNWIND_PROTECT,returner,,{
        var restartf_t fun = unwind_protect_to_save.fun;
        var gcv_object_t* arg = unwind_protect_to_save.upto_frame;
        remove_timeout_call(&tc);
        skipSTACK(2); /* unwind the frame */
        fun(arg); /* jump further */
      });
      /* insert in sorted chain and signal if needed */
      if (insert_timeout_call(&tc)) {
        begin_system_call(); signal_timeout_call(); end_system_call();
      }
      spinlock_release(&timeout_call_chain_lock); /* release the lock */
      funcall(STACK_5,0); /* call the body function */
      remove_timeout_call(&tc); /* everything seems fine - no timeout */
      skipSTACK(2 + 3); /* unwind_protect frame + CATCH frame*/
    }
  } else {
  timeout_function:
    funcall(STACK_1,0);
  }
  skipSTACK(3);
}

LISPFUNN(thread_yield,0)
{ /* (THREAD-YIELD) */
  begin_blocking_system_call(); /* give GC chance */
  xthread_yield();
  end_blocking_system_call();
  VALUES1(current_thread()->_lthread);
}

/* UP: push THREAD-INTERRUPT data on the thread stack - args + fun + argcount
   > thr: the thread to be interrupted
   > function: function to be executed in thr's context
   > args: list of arguments to pass to function
   Modifies the stack of the thr */
local void push_interrupt_arguments(clisp_thread_t *thr, object function,
                                    object args)
{
  if (missingp(function)) { /* i.e. INVOKE-DEBUGGER */
    NC_pushSTACK(thr->_STACK,S(interrupt_condition));
    NC_pushSTACK(thr->_STACK,S(invoke_debugger));
    NC_pushSTACK(thr->_STACK,posfixnum(1)); /* 1 argument */
  } else if (eq(function, T)) { /* i.e. THREAD-KILL */
    NC_pushSTACK(thr->_STACK,O(thread_exit_tag)); /* thread exit tag */
    NC_pushSTACK(thr->_STACK,args); /* thread return values */
    NC_pushSTACK(thr->_STACK,S(thread_throw_tag)); /* %THROW-TAG */
    NC_pushSTACK(thr->_STACK,posfixnum(2)); /* 1 argument */
  } else { /* real function */
    var uintC argcnt=0;
    while (!endp(args)) {
      NC_pushSTACK(thr->_STACK,Car(args));
      args = Cdr(args);
      argcnt++;
    }
    NC_pushSTACK(thr->_STACK,function);
    NC_pushSTACK(thr->_STACK,posfixnum(argcnt));
  }
}

LISPFUN(thread_interrupt,seclass_default,1,0,norest,key,3,
        (kw(function),kw(override),kw(arguments)))
{ /* (THREAD-INTERRUPT thread &key function override arguments) */
  var bool interrupted = false;
  var bool override = !missingp(STACK_1);
  STACK_3 = check_thread(STACK_3);
  /* if no arguments - set to empty list */
  STACK_0 = boundp(STACK_0) ? check_list(STACK_0) : NIL;
  if (TheThread(STACK_3)->xth_globals == current_thread()) {
    /* we want to interrupt ourselves ? strange but let's do it */
    push_interrupt_arguments(current_thread(),STACK_2,STACK_0);
    var uintC argcnt=posfixnum_to_V(popSTACK());
    funcall(popSTACK(),argcnt);
    interrupted=true;
  } else { /* really interrupt another thread */
    if (suspend_thread(STACK_3,false)) { /* still alive? */
      var clisp_thread_t *clt = TheThread(STACK_3)->xth_globals;
      var gcv_object_t *saved_stack=clt->_STACK;
      /* be sure that the signal we send will be received */
      spinlock_acquire(&clt->_signal_reenter_ok);
      /* push arguments */
      push_interrupt_arguments(clt,STACK_2,STACK_0);
      /* push override flag */
      NC_pushSTACK(clt->_STACK, override ? T : NIL);
      if (!(interrupted = interrupt_thread(clt))) {
        /* for some reason we were unable to send the signal */
        clt->_STACK=saved_stack;
      }
    }
    resume_thread(STACK_3, true);
  }
  VALUES2(STACK_3, interrupted ? T : NIL);
  skipSTACK(4);
}

LISPFUNN(threadp,1)
{ /* (THREADP object) */
  var object obj = popSTACK();
  VALUES_IF(threadp(obj));
}

LISPFUNNR(thread_name,1)
{ /* (THREAD-NAME thread) */
  var object obj=check_thread(popSTACK());
  VALUES1(TheThread(obj)->xth_name);
}

LISPFUN(thread_join,seclass_read,1,0,norest,key,1,(kw(timeout)))
{ /* (THREAD-JOIN thread [:timeout]) */
  var bool timeout=false;
  STACK_1=check_thread(STACK_1);
  if (!boundp(TheThread(STACK_1)->xth_values)) {
    /* thread is still running */
    var gcv_object_t *thr_ = &STACK_1;
    var gcv_object_t *timeout_ = &STACK_0;
    WITH_LISP_MUTEX_LOCK(0,false,&TheThread(*thr_)->xth_join_lock,{
      while (!timeout && !boundp(TheThread(*thr_)->xth_values)) {
        /* wait on the join exemption */
        pushSTACK(TheThread(*thr_)->xth_join_exemption);
        pushSTACK(TheThread(*thr_)->xth_join_lock);
        pushSTACK(S(Ktimeout)); pushSTACK(*timeout_);
        funcall(L(exemption_wait),4);
        timeout = eq(value1, NIL);
      }
    });
  }
  if (!timeout) {
    /* for sure we have thread's xth_values bound */
    VALUES2(TheThread(STACK_1)->xth_values, thread_killedp(STACK_1) ? NIL : T);
  } else {
    VALUES2(NIL,S(Ktimeout)); /* timeout */
  }
  skipSTACK(2);
}

LISPFUNN(thread_active_p,1)
{ /* (THREAD-ACTIVE-P thread) */
  var object obj=check_thread(popSTACK());
  /* consider the thread active until it has not set it return values.
   just the thread_delete() is left to be performed (and there is no way
   to interrupt the thread while doing it)*/
  VALUES_IF(!boundp(TheThread(obj)->xth_values));
}

LISPFUNN(current_thread,0)
{ /* (CURRENT-THREAD) */
  VALUES1(current_thread()->_lthread);
}

LISPFUNN(list_threads,0)
{ /* (LIST-THREADS) */
  /* do no lock here - anyway until result is returned thread list may
     change. while we run there may be new thread(s) added to front of the
     O(all_threads) that will missed from result (only during gc threads are
     removed from this list and there is no chance for gc to run while we are
     in the loop) */
  var uintC count=0;
  var object list=O(all_threads);
  for (;!endp(list);count++,list=Cdr(list))
    pushSTACK(Car(list));
  VALUES1(listof(count));
}

LISPFUNNR(symbol_value_thread,2)
{ /* (MT:SYMBOL-VALUE-THREAD symbol thread) */
  STACK_1 = check_symbol(STACK_1);
  /* handle first cases when we do not need to lock threads */
  if (nullp(STACK_0)) { /* global symvalue */
    var object symvalue = TheSymbol(STACK_1)->symvalue;
    if (boundp(symvalue)) VALUES2(symvalue,T); else VALUES2(NIL,NIL);
  } else { /* specific thread specified */
    var uintL idx=TheSymbol(STACK_1)->tls_index;
    if (idx == SYMBOL_TLS_INDEX_NONE) { /* not special variable */
      VALUES2(NIL,NIL);
    } else { /* there may be per thread values */
      if (eq(STACK_0,T)) { /* current thread symvalue */
        pushSTACK(current_thread()->_ptr_symvalues[idx]);
        pushSTACK(NIL); /* placeholder for now */
      } else { /* ! current thread - we need to lock threads */
        STACK_0 = check_thread(STACK_0);
        pushSTACK(NIL); pushSTACK(NIL);
        var gcv_object_t *thr_ = &STACK_2;
        var gcv_object_t *value1_ = &STACK_1;
        var gcv_object_t *value2_ = &STACK_0;
        WITH_OS_MUTEX_LOCK(0,&allthreads_lock, {
          if (boundp(TheThread(*thr_)->xth_values)) { /* thread has exited? */
            *value2_ = S(thread_active_p);
          } else { /* thread is still alive */
            *value1_ = TheThread(*thr_)->xth_globals->_ptr_symvalues[idx];
          }
        });
      }
      /* now fix up the return values */
      if (nullp(STACK_0)) { /* thread alive (incl. current thread) */
        if (eq(STACK_1,SYMVALUE_EMPTY)) { /* no value */
          STACK_1 = NIL;
        } else if (!boundp(STACK_1)) { /* bound but later makunbound-ed */
          STACK_1 = NIL; STACK_0 = S(makunbound);
        } else { /* there is a value */
          STACK_0 = T;
        }
      }
      STACK_to_mv(2);
    }
  }
  skipSTACK(2);
}

LISPFUNN(set_symbol_value_thread,3)
{ /* (SETF (MT:SYMBOL-VALUE-THREAD symbol thread) value) */
  STACK_2 = check_symbol(STACK_2);
  /* handle first cases when we do not need to lock threads */
  if (nullp(STACK_1)) { /* global symvalue */
    TheSymbol(STACK_2)->symvalue = STACK_0;
  } else { /* specific thread specified */
    var uintL idx=TheSymbol(STACK_2)->tls_index;
    if (idx == SYMBOL_TLS_INDEX_NONE) { /* not special variable */
      skipSTACK(1); /* skip value */
      STACK_0 = STACK_1; /* = symbol (CELL-ERROR Slot NAME, symbol) */
      pushSTACK(S(set_symbol_value_thread));
      error(unbound_variable,GETTEXT("~S: ~S is not per thread special variable"));
    } else { /* let's set the per thread value */
      if (eq(STACK_1,T)) { /* current thread symvalue */
        current_thread()->_ptr_symvalues[idx] = STACK_0;
      } else { /* ! current thread - we need to lock threads */
        STACK_1 = check_thread(STACK_1);
        var bool thr_was_dead = false;
        var gcv_object_t *thr_ = &STACK_1;
        var gcv_object_t *value_ = &STACK_0;
        WITH_OS_MUTEX_LOCK(0,&allthreads_lock, {
          if (boundp(TheThread(*thr_)->xth_values)) { /* thread has exited? */
            thr_was_dead = true;
          } else { /* thread is still alive  - set the symbol value */
            TheThread(*thr_)->xth_globals->_ptr_symvalues[idx] = *value_;
          }
        });
        if (thr_was_dead) {
          skipSTACK(1); /* value */
          pushSTACK(S(set_symbol_value_thread));
          error(control_error,GETTEXT("~S: thread ~S is not active"));
        }
      }
    }
  }
  VALUES1(STACK_0);
  skipSTACK(3);
}

LISPFUNN(mutexp,1)
{ /* (MUTEXP object) */
  var object obj = popSTACK();
  VALUES_IF(mutexp(obj));
}

LISPFUN(make_mutex,seclass_default,0,0,norest,key,2,
        (kw(name),kw(recursive_p)))
{ /* (MAKE-MUTEX &key name (recursive-p nil) ) */
  var bool recursive = ! missingp(STACK_0);
  skipSTACK(1); /* ditch the recursive_p */
  STACK_0 = check_name_arg(STACK_0,NIL);
  /* overwrite the name on the STACK with the newly allocated object */
  STACK_0 = allocate_mutex(&STACK_0);
  if (!nullp(STACK_0) && recursive) /* set recursive flag */
    TheMutex(STACK_0)->xmu_flags |= mutex_flag_recursive;
  VALUES1(popSTACK());
}

LISPFUNNR(mutex_name,1)
{ /* (MUTEX-NAME thread) */
  var object obj=check_mutex(popSTACK());
  VALUES1(TheMutex(obj)->xmu_name);
}

LISPFUN(mutex_lock,seclass_default,1,0,norest,key,1,
        (kw(timeout)))
{ /* (MUTEX-LOCK mutex [:timeout]) */
  var struct timeval tv;
  var struct timeval *tvp = sec_usec(popSTACK(),unbound,&tv);
  var gcv_object_t *mxrec = &STACK_0; /* mutex record */
  *mxrec = check_mutex(*mxrec);
  /* do we already hold the mutex */
  if (eq(TheMutex(*mxrec)->xmu_owner, current_thread()->_lthread)) {
    if (!mutex_recursivep(*mxrec)) {
      /* non-recursive mutex already owned by the current thread.
         signal error */
      var object mx = *mxrec;
      pushSTACK(mx); /* CELL-ERROR Slot NAME */
      pushSTACK(current_thread()->_lthread);
      pushSTACK(mx); pushSTACK(S(mutex_lock));
      error(control_error,GETTEXT("~S: non-recursive mutex ~S is already owned by thread ~S"));
    } else {
      /* just increase the recurse counter */
      TheMutex(*mxrec)->xmu_recurse_count++;
      VALUES1(T);
    }
  } else {
    /* obtain the lock */
    var clisp_thread_t *thr = current_thread();
    var xmutex_t *m = TheMutex(*mxrec)->xmu_system;
    var int res = 0;
    /* following is like GC_SAFE_MUTEX_LOCK() but does not possibly
       handle the pending interrupts at the end */
    thr->_wait_mutex = m;
    begin_system_call(); GC_SAFE_REGION_BEGIN();
    if (!tvp)
      res = xmutex_lock(m);
    else
      res = xmutex_timedlock(m,tvp->tv_sec*1000 + tvp->tv_usec/1000);
    thr->_wait_mutex = NULL;
    /* do not (possibly) handle pending interrupts here since on non-local exit
       from interrupt we may leave the mutex object in inconsistent state*/
    GC_SAFE_REGION_END_WITHOUT_INTERRUPTS(); end_system_call();

    if (!res) { /* if we got the mutex */
      ASSERT(TheMutex(*mxrec)->xmu_recurse_count == 0);
      ASSERT(nullp(TheMutex(*mxrec)->xmu_owner));
      TheMutex(*mxrec)->xmu_owner = thr->_lthread;
      TheMutex(*mxrec)->xmu_recurse_count++;
    }
    /* now the mutex record is in consistent state - handle pending
       interrupts (if any) */
    HANDLE_PENDING_INTERRUPTS(thr);
    /* TODO: here we assume the only error we may get is ETIMEDOUT.
       in case of other errors we have to signal an error */
    VALUES1(res ? NIL : T);
  }
  skipSTACK(1);
}

LISPFUNN(mutex_unlock,1)
{ /* (MUTEX-UNLOCK mutex) */
  STACK_0 = check_mutex(STACK_0);
  /* do we own the mutex ? */
  if (!eq(TheMutex(STACK_0)->xmu_owner, current_thread()->_lthread)) {
    /* trying to unlock mutex not owned by the current thread.
       signal an error.*/
    var object mx = STACK_0;
    pushSTACK(mx); /* CELL-ERROR Slot NAME */
    pushSTACK(current_thread()->_lthread);
    pushSTACK(mx); pushSTACK(S(mutex_unlock));
    error(control_error,GETTEXT("~S: mutex ~S is not owned by thread ~S"));
  }
  /* decrease the recurse count. if last - unlock really. */
  if ((--TheMutex(STACK_0)->xmu_recurse_count) == 0) {
    /* important to set owner before we really release the lock */
    TheMutex(STACK_0)->xmu_owner = NIL;
    GC_SAFE_MUTEX_UNLOCK(TheMutex(STACK_0)->xmu_system);
  }
  skipSTACK(1);
  VALUES0;
}

LISPFUNN(mutex_recursive_p,1)
{ /* (MUTEX-RECURSIVE-P object) */
  var object mx = check_mutex(popSTACK());
  VALUES_IF(mutex_recursivep(mx));
}

LISPFUNN(mutex_owner,1)
{ /* (MUTEX-OWNER onject) */
  var object mx = check_mutex(popSTACK());
  VALUES2(TheMutex(mx)->xmu_owner,fixnum(TheMutex(mx)->xmu_recurse_count));
}

LISPFUNN(exemptionp,1)
{ /* (EXEMPTIONP object) */
  var object obj = popSTACK();
  VALUES_IF(exemptionp(obj));
}

LISPFUN(make_exemption,seclass_default,0,0,norest,key,1,(kw(name)))
{ /* (MAKE-EXEMPTION &key name) */
  STACK_0 = check_name_arg(STACK_0,NIL);
  /* overwrite the name on the STACK with the newly allocated object */
  STACK_0 = allocate_exemption(&STACK_0);
  VALUES1(popSTACK());
}

LISPFUNNR(exemption_name,1)
{ /* (EXEMPTION-NAME thread) */
  var object obj=check_exemption(popSTACK());
  VALUES1(TheExemption(obj)->xco_name);
}

LISPFUN(exemption_wait,seclass_default,2,0,norest,key,1,(kw(timeout)))
{ /* (EXEMPTION-WAIT exemption mutex) */
  var struct timeval tv;
  var struct timeval *tvp = sec_usec(popSTACK(),unbound,&tv);
  STACK_0 = check_mutex(STACK_0);
  STACK_1 = check_exemption(STACK_1);
  if (!eq(TheMutex(STACK_0)->xmu_owner, current_thread()->_lthread)) {
    /* the mutex should be owned by the calling thread. */
    var object mx = STACK_0;
    pushSTACK(mx); /* CELL-ERROR Slot NAME */
    pushSTACK(current_thread()->_lthread);
    pushSTACK(mx); pushSTACK(S(exemption_wait));
    error(control_error,GETTEXT("~S: mutex ~S should be owned by ~S"));
  }
  /* we are the owners - let's see how many times we we have locked it */
  if (TheMutex(STACK_0)->xmu_recurse_count != 1) {
    /* using recursive mutex with condition variables may cause really
       weird errors that are almost impossible to debug.
       Let's check that we have locked it only once. */
    var object mx = STACK_0;
    pushSTACK(mx); /* CELL-ERROR Slot NAME */
    pushSTACK(current_thread()->_lthread);
    pushSTACK(mx); pushSTACK(S(exemption_wait));
    error(control_error,GETTEXT("~S: recursive mutex ~S is locked multiple times by ~S"));
  }
  /* pthread_cond_wait() will release the OS mutex - so clear the owner. */
  TheMutex(STACK_0)->xmu_owner = NIL; TheMutex(STACK_0)->xmu_recurse_count = 0;
  /* get the pointer before we allow the GC to run */
  var xmutex_t *m = TheMutex(STACK_0)->xmu_system;
  var xcondition_t *c = TheExemption(STACK_1)->xco_system;
  var gcv_object_t *mxrec = &STACK_0; /*in case of interrupt STACK_0 != mutex*/
  clisp_thread_t *thr = current_thread();
  var int res;

  thr->_wait_condition = c;
  thr->_wait_mutex = m;
  begin_system_call(); GC_SAFE_REGION_BEGIN();
  if (tvp)
    res = xcondition_timedwait(c,m,tvp->tv_sec*1000 + tvp->tv_usec/1000);
  else
    res = xcondition_wait(c,m);
  thr->_wait_mutex = NULL;
  thr->_wait_condition = NULL;
  /* do not (possibly) handle pending interrupts here since on non-local exit
     from interrupt we may leave the mutex object in inconsistent state*/
  GC_SAFE_REGION_END_WITHOUT_INTERRUPTS(); end_system_call();

  /* set again the owner. even in case of error - this should be fine. */
  TheMutex(*mxrec)->xmu_owner = current_thread()->_lthread;
  TheMutex(*mxrec)->xmu_recurse_count = 1;
  /* handle (if any) interrupts */
  HANDLE_PENDING_INTERRUPTS(thr);
  skipSTACK(2);
  VALUES1(res ? NIL : T);
}

#define EXEMPTION_OP_ON_STACK_0(op)                                  \
  do {                                                               \
    STACK_0 = check_exemption(STACK_0);                              \
    begin_system_call();                                             \
    op(TheExemption(STACK_0)->xco_system);                           \
    end_system_call();                                               \
    VALUES1(popSTACK());                                             \
  } while(0)


LISPFUNN(exemption_signal,1)
{ /* (EXEMPTION-SIGNAL exemption) */
  EXEMPTION_OP_ON_STACK_0(xcondition_signal);
}

LISPFUNN(exemption_broadcast,1)
{ /* (EXEMPTION-BROADCAST exemption) */
  EXEMPTION_OP_ON_STACK_0(xcondition_broadcast);
}

/*****************************************************************************/
/* LOW-LEVEL THREADS STUFF */

/* TODO: not the right place to put these stuff. separate file is better ? */
#if defined(POSIX_THREADS)

/* UP: fills timespec with millis milliseconds form "now"
   <> r: timespec to be filled
   > millis: milliseconds */
local inline void get_abs_timeout(struct timespec *r, uintL millis) {
  var struct timeval tv;
  gettimeofday(&tv, NULL);
  r->tv_sec = tv.tv_sec + (tv.tv_usec + millis * 1000) / 1000000;
  r->tv_nsec = 1000 * ((tv.tv_usec + millis*1000) % 1000000);
}


#else /* WIN32_THREADS */

/* UP: helper function for waiting on a condition associated with "raw" mutex
 > c: condition object
 > m: xmutex_raw_t object
 > millis: timeout in milliseconds
 < returns 0 if the condition was signaled, 1 on timeout */
local inline int win32_xcondition_wait(xcondition_t *c,xmutex_raw_t *m,
                                       uintL millis)
{
  EnterCriticalSection(&(c)->cs);
  (c)->waiting_count++;
  LeaveCriticalSection(&(c)->cs);
  LeaveCriticalSection(m);
  var DWORD timeout = millis == THREAD_WAIT_INFINITE ? INFINITE : millis;
  var DWORD r = WaitForSingleObject((c)->sem,timeout);
  EnterCriticalSection(m);
  return r == WAIT_OBJECT_0 ? 0 : 1;
}

#endif

/* UP: initializes xlock_t
 <> l: the lock
 < Returns 0 on success, oherwise the error code returnd from pthreads */
int xlock_init(xlock_t *l)
{
  var int r;
  if (r=xmutex_raw_init(&l->xl_internal_mutex)) return r;
  if (r=xmutex_raw_init(&l->xl_mutex)) {
    xmutex_raw_destroy(&l->xl_internal_mutex);
    return r;
  }
  if (r=xcondition_init(&l->xl_wait_cv)) {
    xmutex_raw_destroy(&l->xl_internal_mutex);
    xmutex_raw_destroy(&l->xl_mutex);
    return r;
  }
  l->xl_owned = false;
  l->xl_recurse_count = 0;
  return 0;
}

/* UP: destroys and frees xlock_t resources
   > l: the lock
   < returns always 0 (TODO: error checking - but what can it help?) */
int xlock_destroy(xlock_t *l)
{
  xmutex_raw_destroy(&l->xl_internal_mutex);
  xmutex_raw_destroy(&l->xl_mutex);
  xcondition_destroy(&l->xl_wait_cv);
  return 0;
}

/* UP: Implements waiting on xlock_t in "polling" mode - so async POSIX signals
   can be handled if arrive
   > l: the lock
   > timeout: wait timeout in milliseconds
   > lock_read: should we really unlock the mutex or just "mark" it as unlocked
   < Returns 0 on success, otherwise the error code from pthreads
   The rationale is: when mutex is passed to pthread_cond_wait() it is
   automatically acquired on return - so no need to really lock it. */
int xlock_lock_helper(xlock_t *l, uintL timeout,bool lock_real)
{
  var int r = 0;
  if (l->xl_owned && xthread_equal(l->xl_owner,xthread_self())) {
    l->xl_recurse_count++;
  } else {
    /* we will never wait here (at least not for a long time) */
    xmutex_raw_lock(&l->xl_internal_mutex);
    if (lock_real) {
      var clisp_thread_t *thr = current_thread();
     #ifdef POSIX_THREADS
      var struct timespec ww;
      if (timeout != THREAD_WAIT_INFINITE) {
        get_abs_timeout(&ww,timeout);
      }
     #endif
      /* while we cannot get the real lock */
      while (r = xmutex_raw_trylock(&l->xl_mutex)) {
        if (!l->xl_owned) {
          /* not owned but still locked - i.e. xcodition_wait() caused it.
             wait forever - really soon pthread_cond_wait() will release it.
             there is no way to block forever since here we own the internal
             mutex as well - e.g. just a single thread may wait xl_mutex and it
             will grab it */
          r = xmutex_raw_lock(&l->xl_mutex);
          break;
        } else {
          /* check for interrupts before waiting */
          if (thr && thr->_pending_interrupts) {
            /* handle them */
            xmutex_raw_unlock(&l->xl_internal_mutex);
            thr->_wait_mutex=NULL;
            GC_SAFE_REGION_END_WITHOUT_INTERRUPTS();
            handle_pending_interrupts();
            thr->_wait_mutex=l;
            xmutex_raw_lock(&l->xl_internal_mutex);
            GC_SAFE_REGION_BEGIN();
            continue;
          }
       #ifdef POSIX_THREADS
          if (timeout != THREAD_WAIT_INFINITE) {
            r = pthread_cond_timedwait(&l->xl_wait_cv,&l->xl_internal_mutex,&ww);
          } else {
            r = pthread_cond_wait(&l->xl_wait_cv,&l->xl_internal_mutex);
          }
       #else /* WIN32 */
          r = win32_xcondition_wait(&l->xl_wait_cv,&l->xl_internal_mutex,timeout);
       #endif
          if (r != 0) break;
        }
      }
      if (r == 0) {
        ASSERT(!l->xl_owned); ASSERT(l->xl_recurse_count == 0);
        l->xl_owner = xthread_self();
        l->xl_owned = true;
        l->xl_recurse_count = 1;
      }
    } else {
      /* if is not real lock - we own the the real mutex + guarding one */
      ASSERT(!l->xl_owned);
      l->xl_owner = xthread_self();
      l->xl_owned = true;
      l->xl_recurse_count = 1;
    }
    xmutex_raw_unlock(&l->xl_internal_mutex);
  }
  return r;
}

/* UP: unlocks (or marks as unlocked) the xlock_t
 > l: the lock
 > unlock_real: should we really unlock it or just mark it?
 < returns 0 if successful, -1 if we the caller does not own the lock
 The rationale is: if mutex is passed to pthread_cond_wait() it is
 automatically unlocked - so unlock_real=false will be used to mark
 the xlock_t as unlocked and pthread_cond_wait() will finish the whole
 process. */
int xlock_unlock_helper(xlock_t *l, bool unlock_real)
{
  if (l->xl_owned && xthread_equal(l->xl_owner,xthread_self())) {
    if (!--l->xl_recurse_count) {
      /* we will never wait here (at least not for a long time) */
      xmutex_raw_lock(&l->xl_internal_mutex);
      l->xl_owned = false;
      if (unlock_real)
        xmutex_raw_unlock(&l->xl_mutex);
      xcondition_signal(&l->xl_wait_cv);
      xmutex_raw_unlock(&l->xl_internal_mutex);
    }
    return 0;
  }
  return -1; /* the caller is not the owner */
}

/* UP: Implements waiting on xcondition_t in "polling" mode - so async POSIX
   signals can be handled if arrive
   > c: the condition variable
   > m: the mutex /xlock_t/
   > timeout: timeout in milliseconds
   < Returns 0 on success, otherwise the error code from pthreads */
int xcondition_wait_helper(xcondition_t *c,xlock_t *m, uintL timeout)
{
  var int r=-1;
  /* mutex is owned by us and it is locked just once.
     our caller assures this */
  xlock_unlock_helper(m,false); /* mark as unlocked */
#ifdef POSIX_THREADS
  if (timeout != THREAD_WAIT_INFINITE) {
    var struct timespec ww;
    get_abs_timeout(&ww,timeout);
    r = pthread_cond_timedwait(c,&m->xl_mutex,&ww);
  } else {
    r = pthread_cond_wait(c,&m->xl_mutex);
  }
#else /* WIN32 */
  r = win32_xcondition_wait(c,&m->xl_mutex,timeout);
#endif
  /* mark again the mutex as ours */
  xlock_lock_helper(m,0,false);
  return r;
}

#endif /* MULTITHREAD */
