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

	Task* Tp;

	printf("Task(%d)\n", i);

	if (--i > 0) {
		NEW_TASK(Tp, Task(i));
	}

	resultis(i);
}

void
main(int argc, char *argv[])
{
	Task* Tp;

	if (argc > 1) {
		nTask = atoi(argv[1]);
	}

	printf("begin\n");

	NEW_TASK(Tp, Task(nTask));

	printf("end\n");
	exit(0);
}
