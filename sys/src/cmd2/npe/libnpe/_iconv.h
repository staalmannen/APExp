enum {
	Itranslit = 1<<0, /* no transliteration is performed :( */
	Iignore = 1<<1, /* this option is ignored (pun TOTALLY intended) if Itranslit is set */

	Tcs = 0,
	Us,
};

struct iconv_s {
	char to[16];
	char from[16];
	int fd;
};
