#include <features.h>

volatile int __dummy_lock = 0;

volatile int *const __at_quick_exit_lockptr = &__dummy_lock;
volatile int *const __atexit_lockptr        = &__dummy_lock;
volatile int *const __gettext_lockptr       = &__dummy_lock;
volatile int *const __locale_lockptr        = &__dummy_lock;
volatile int *const __random_lockptr        = &__dummy_lock;
volatile int *const __sem_open_lockptr      = &__dummy_lock;
volatile int *const __stdio_ofl_lockptr     = &__dummy_lock;
volatile int *const __syslog_lockptr        = &__dummy_lock;
volatile int *const __timezone_lockptr      = &__dummy_lock;
volatile int *const __bump_lockptr          = &__dummy_lock;
volatile int *const __vmlock_lockptr        = &__dummy_lock;

extern hidden volatile int *const __bump_lockptr;

extern hidden volatile int *const __vmlock_lockptr;


void __malloc_atfork(int who) {
    /* no-op for Plan9/APE */
}

void __ldso_atfork(int who) {
    /* no-op: you probably do not have a dynamic loader */
}

void __pthread_key_atfork(int who) {
    /* no-op: no pthread key fork semantics in your system */
}

void __post_Fork(int who) {
    /* no-op */
}


