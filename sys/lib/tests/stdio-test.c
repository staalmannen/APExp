#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	FILE *f;
	char buf[100];

	f = fopen("/tmp/test.txt", "w");
	if (!f) {
		perror("fopen");
		return 1;
	}
	fprintf(f, "Hello from musl stdio!\n");
	fclose(f);

	f = fopen("/tmp/test.txt", "r");
	fgets(buf, sizeof(buf), f);
	printf("Read: %s", buf);
	fclose(f);

	return 0;
}

