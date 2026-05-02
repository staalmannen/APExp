#include <wchar.h>
#include <string.h>

void mbszero(mbstate_t *ps) {
    memset(ps, 0, sizeof(mbstate_t));
}
