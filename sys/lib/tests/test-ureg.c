#include <stdio.h>
#include <ureg.h>
#include <stddef.h>

int main() {
	struct Ureg u;
	printf("sizeof(Ureg) = %d\n", (int)sizeof(struct Ureg));
	printf("offset ax = %d\n", (int)offsetof(struct Ureg, ax));
	printf("offset pc = %d\n", (int)offsetof(struct Ureg, pc));
	printf("offset sp = %d\n", (int)offsetof(struct Ureg, sp));
	return 0;
}
