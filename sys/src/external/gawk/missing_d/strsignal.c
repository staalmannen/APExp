/* strsignal --- replacement version for systems that don't have it */

char *
strsignal(int signal)
{
	static char buffer[100];

	sprintf(buffer, "signal %d", signal);

	return buffer;
}
