#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "lib.h"

/*
 * Thread-specific data keys, and the destructors POSIX attaches to them.
 *
 * This used to reject any key with a destructor out of hand, returning
 * EINVAL with a note that it was not implemented yet. That is not a
 * limitation a caller can work around: POSIX gives
 * pthread_key_create no way to fail for a destructor it dislikes, so
 * code that wants one treats EINVAL as impossible and gives up. gnulib
 * does exactly that --
 *
 *	#define gl_tls_key_init(NAME, DESTRUCTOR)		\
 *	   do { if (glthread_tls_key_init (&NAME, DESTRUCTOR))	\
 *	          abort (); } while (0)
 *
 * -- so strsignal(), which keeps a per-thread buffer freed by a
 * destructor, aborted on its first call. m4 calls strsignal(SIGSEGV) at
 * m4.c:445, four lines into main, and died there with no diagnostic:
 * every m4 run in the tree, including the one bison shells out to,
 * which is why bison could not generate a parser.
 *
 * Destructors are run now rather than merely accepted. A key that
 * silently never destroys anything is the posix_spawn file-actions
 * mistake again: the caller cannot tell, and what it loses is a leak
 * per thread rather than an error.
 *
 * The registry holds the caller's pthread_key_t *, not a copy, because
 * that is already how these keys work here: pthread_getspecific and
 * pthread_setspecific take the key *by value*, so every copy shares one
 * `arenas' array and the original object is the only stable identity.
 * POSIX keys are long-lived by construction, so a key whose storage
 * outlives pthread_key_delete is the caller's error, as it would be
 * anywhere.
 */

static Lock keylock;
static pthread_key_t *keys[PTHREAD_KEYS_MAX];

int
pthread_key_create(pthread_key_t *key, void (*destr_func)(void*))
{
	int i;

	memset(key, 0, sizeof(*key));
	key->destroy = destr_func;
	key->n = 32;
	key->arenas = malloc(sizeof(*key->arenas)*key->n);
	if(key->arenas == NULL)
		return ENOMEM;
	memset(key->arenas, 0, sizeof(*key->arenas)*key->n);

	if(destr_func == NULL)
		return 0;

	/* only keys with a destructor need to be found again at exit */
	lock(&keylock);
	for(i = 0; i < PTHREAD_KEYS_MAX; i++)
		if(keys[i] == NULL){
			keys[i] = key;
			unlock(&keylock);
			return 0;
		}
	unlock(&keylock);

	free(key->arenas);
	key->arenas = NULL;
	return EAGAIN;		/* POSIX: too many keys */
}

/*
 * pthread_key_delete takes the key by value, so there is no pointer to
 * match on. The arenas array is the one thing every copy of a key
 * shares, which makes it the identity here.
 */
void
_pthreadkeyforget(void *arenas)
{
	int i;

	if(arenas == NULL)
		return;
	lock(&keylock);
	for(i = 0; i < PTHREAD_KEYS_MAX; i++)
		if(keys[i] != NULL && (void *)keys[i]->arenas == arenas)
			keys[i] = NULL;
	unlock(&keylock);
}

/*
 * Run the calling thread's destructors, from pthread_exit.
 *
 * POSIX 1003.1 pthread_key_create: the value is set to NULL *before*
 * the destructor is called, and the whole sweep is repeated while any
 * destructor has stored a new non-null value, up to
 * PTHREAD_DESTRUCTOR_ITERATIONS times. A destructor that keeps
 * reinstating a value is not an error; it just stops being run.
 */
void
_pthreadkeydtors(void)
{
	pthread_key_t *key;
	void (*destroy)(void*);
	void *val;
	int i, round, more;

	for(round = 0; round < PTHREAD_DESTRUCTOR_ITERATIONS; round++){
		more = 0;
		for(i = 0; i < PTHREAD_KEYS_MAX; i++){
			lock(&keylock);
			key = keys[i];
			unlock(&keylock);
			if(key == NULL)
				continue;
			val = pthread_getspecific(*key);
			destroy = key->destroy;
			if(val == NULL || destroy == NULL)
				continue;
			pthread_setspecific(*key, NULL);
			(*destroy)(val);
			more = 1;
		}
		if(!more)
			break;
	}
}
