#include <objpak.h>

main(int argc, char *argv[])
{
	int i;
	FILE *fp;
	char buf[5000];
	id lp = [OrdCltn new];

	if (argc == 1)
		fp = stdin;
	else
		fp = fopen(argv[1], "r");

	while (fgets(buf,sizeof buf,fp) != NULL) [lp add:[String str:buf]];

        i=[lp size];while (i) [[lp at:--i] print];
}
