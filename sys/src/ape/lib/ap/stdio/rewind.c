/*
 * pANS stdio -- rewind
 */
#include "iolib.h"

/*
 * C99 7.19.9.5: rewind sets the position to the beginning of the file
 * "and clears the error indicator for the stream". That last part is
 * what distinguishes it from fseek(f, 0L, SEEK_SET), which leaves the
 * error indicator alone (7.19.9.2), and it is the only way a caller
 * can clear an error other than clearerr.
 */
void rewind(FILE *f){
	fseeko(f, 0, SEEK_SET);
	clearerr(f);
}
