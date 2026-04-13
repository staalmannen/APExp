#ifndef __IOCTL_H__
#define __IOCTL_H__

#ifdef __cplusplus
extern "C" {
#endif

/* FIONREAD: return number of bytes readable in *(long*)arg */
#define FIONREAD 1

/* TIOCGWINSZ/TIOCSWINSZ: get/set terminal window size. */
#define TIOCGWINSZ 2
#define TIOCSWINSZ 3

#ifndef __struct_winsize_defined
#define __struct_winsize_defined
struct winsize {
	unsigned short ws_row;
	unsigned short ws_col;
	unsigned short ws_xpixel;
	unsigned short ws_ypixel;
};
#endif

int ioctl(int, unsigned long, void*);

#ifdef __cplusplus
}
#endif


#endif /* !__IOCTL_H__ */
