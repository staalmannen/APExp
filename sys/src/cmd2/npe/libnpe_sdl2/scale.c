#include "_sdl.h"

void *
npe_sdl_scale(u32int *src, int iw, int ih, u32int *dst, int ow, int oh)
{
	int i, j, m, n;
	u32int *d;

	if(iw == ow && ih == oh)
		return src;

	d = dst;
	n = ow/iw;
	for(; ih > 0 && oh > 0; ih--){
		for(i = j = 0; i < iw; i++, src++)
			for(m = 0; m < n && j < ow; m++, j++)
				*dst++ = *src;
		oh--;
		for(m = 1; m < n && oh > 0; m++){
			memmove(dst, dst-j, j*4);
			dst += j;
			oh--;
		}
	}

	return d;
}
