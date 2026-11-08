#include "string.h"
#include "errno.h"

char *
strerror(int e)
{
	switch(e){
	case ENOENT: return "ENOENT";
	}

	return "???";
}
