#include <stdio.h>
#include <unistd.h>

void debug_print(const char *msg) {
	write(2, msg, __builtin_strlen(msg));
	write(2, "\n", 1);
}

int main(int argc, char *argv[], char *envp[]) {
	debug_print("TEST: main() started");

	debug_print("TEST: about to call fopen");
	FILE *f = fopen("/tmp/test.txt", "w");

	if (!f) {
		debug_print("TEST: fopen failed");
		return 1;
	}

	debug_print("TEST: fopen succeeded");
	fprintf(f, "Hello from musl stdio!\n");

	debug_print("TEST: about to fclose");
	fclose(f);

	debug_print("TEST: main() exiting");
	return 0;
}

