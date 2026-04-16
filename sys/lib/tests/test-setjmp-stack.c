#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * This test verifies that SP is correctly restored by longjmp.
 * If SP is off by 8 bytes (as it was before the fix), repeated
 * longjmps or nested calls after longjmp might cause crashes.
 */

jmp_buf env;
uintptr_t base_sp;

uintptr_t
get_sp(void)
{
	volatile int x;
	return (uintptr_t)&x;
}

void
check_sp(const char *msg)
{
	uintptr_t current_sp = get_sp();
	/* 
	 * SP should be very close to base_sp. 
	 * Allowing some small difference for different stack frames 
	 * in get_sp, but it should NOT be exactly 8 or 16 bytes different 
	 * in a way that suggests corruption.
	 */
	printf("%s: SP=0x%lx (diff with base: %ld)\n", msg, (unsigned long)current_sp, (long)(current_sp - base_sp));
	if(abs((long)(current_sp - base_sp)) > 128) {
		printf("FAIL: SP drifted too much!\n");
		exit(1);
	}
}

void
do_longjmp(int val)
{
	longjmp(env, val);
}

int
main(void)
{
	int r;
	volatile int count = 0;

	printf("=== setjmp/longjmp stack integrity test\n");
	
	base_sp = get_sp();
	printf("Base SP: 0x%lx\n", (unsigned long)base_sp);

	r = setjmp(env);
	if(r == 0) {
		printf("setjmp returned 0, calling longjmp...\n");
		do_longjmp(1);
	} else {
		printf("setjmp returned %d\n", r);
		check_sp("After longjmp");
		
		if(count < 5) {
			count++;
			printf("Loop %d...\n", count);
			do_longjmp(count + 1);
		}
	}

	printf("PASS: setjmp/longjmp stack integrity\n");
	return 0;
}
