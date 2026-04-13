#include <termios.h>

void
cfmakeraw(struct termios *t)
{
	t->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON|IXOFF);
	t->c_oflag &= ~OPOST;
	t->c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
	t->c_cflag &= ~(CSIZE|PARENB);
	t->c_cflag |= CS8;
	t->c_cc[VMIN]  = 1;
	t->c_cc[VTIME] = 0;
}

speed_t
cfgetospeed(const struct termios *)
{
	return B0;
}

int
cfsetospeed(struct termios *, speed_t)
{
	return 0;
}

speed_t
cfgetispeed(const struct termios *)
{
	return B0;
}

int
cfsetispeed(struct termios *, speed_t)
{
	return 0;
}

