#include <stdio.h>
#include <ureg.h>
#include <stddef.h>

int main() {
	struct Ureg u;
	printf("sizeof(Ureg) = %d\n", (int)sizeof(struct Ureg));
	printf("offset ax = %d\n", (int)offsetof(struct Ureg, ax));
	printf("offset pc = %d\n", (int)offsetof(struct Ureg, pc));
	printf("offset sp = %d\n", (int)offsetof(struct Ureg, sp));
	printf("offset ss = %d\n", (int)offsetof(struct Ureg, ss));
	
	/* Check segments which are often source of alignment issues */
	printf("offset ds = %d\n", (int)offsetof(struct Ureg, ds));
	printf("offset es = %d\n", (int)offsetof(struct Ureg, es));
	printf("offset fs = %d\n", (int)offsetof(struct Ureg, fs));
	printf("offset gs = %d\n", (int)offsetof(struct Ureg, gs));
	printf("offset type = %d\n", (int)offsetof(struct Ureg, type));
	
	return 0;
}
