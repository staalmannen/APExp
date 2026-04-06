#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *f;
	char buf[100];

	fprintf(stderr, "Starting test...\n");
	fflush(stderr);

	fprintf(stderr, "Opening /tmp/test.txt for writing...\n");
	fflush(stderr);
	f = fopen("/tmp/test.txt", "w");
	if (!f) {
		perror("fopen");
		return 1;
	}

	fprintf(stderr, "Writing to file...\n");
	fflush(stderr);
	fprintf(f, "Hello from musl stdio!\n");

	fprintf(stderr, "Closing file...\n");
	fflush(stderr);
	fclose(f);

	fprintf(stderr, "Opening /tmp/test.txt for reading...\n");
	fflush(stderr);
	f = fopen("/tmp/test.txt", "r");
	if (!f) {
		perror("fopen for read");
		return 1;
	}

	fprintf(stderr, "Reading from file...\n");
	fflush(stderr);
	fgets(buf, sizeof(buf), f);
	printf("Read: %s", buf);

	fprintf(stderr, "Closing file...\n");
	fflush(stderr);
	fclose(f);

	fprintf(stderr, "Test completed successfully!\n");
	fflush(stderr);
	return 0;
}

