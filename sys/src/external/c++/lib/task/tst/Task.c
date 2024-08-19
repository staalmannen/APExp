#include <stdio.h>
#include <stdlib.h>
#include <task.h>
#include <Task.h>


int nTask = 1;

class Task : public task {
public:
	Task(int);
};

Task::Task(int i) : task("Task", SHARED, 3000)
{
	INIT_TASK();

	fprintf(stderr, "Task(%d)\n", i);

	resultis(i);
}

void
main(int argc, char *argv[])
{
	int i;
	Task* Tp;

	if (argc > 1) {
		nTask = atoi(argv[1]);
	}

	printf("begin\n");

	for (i = 1; i <= nTask; i++) {
		NEW_TASK(Tp, Task(i));
	}

	printf("end\n");
	exit(0);
}
