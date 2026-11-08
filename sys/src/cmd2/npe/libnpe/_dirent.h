struct DIR {
	Dir *d;
	struct dirent de;
	int fd;
	long n; /* number of entries in d */
	long i; /* current entry to return from readdir */
};
