// FontConfig-like API implementation
#include <u.h>
#include <libc.h>
#include <bio.h>
#include <draw.h>
#include <memdraw.h>
#include "dat.h"

static FcFontSet*
allocfontset(void)
{
	return emalloc9p(sizeof(FcPattern));
};

static FcPattern*
allocpat(void)
{
	return emalloc9p(sizeof(FcPattern));
};

int
FcInit(void)
{
	return 1;
};

FcConfig*
FcInitLoadConfigAndFonts(void)
{
	return emalloc9p(sizeof(FcConfig));
};

static void
appendfontset(FcFontSet* fset, FcPattern* pat)
{
	int n;
	n = fset->nfont;
	fset->fonts = realloc(fset->fonts, (n+1)*sizeof(FcPattern*));
	fset->fonts[n++] = pat;
	fset->nfont = n;
};

void
FcFontSetDestroy(FcFontSet* fset)
{
	int i;
	for(i = 0; i < fset->nfont; i++)
		free(fset->fonts[i]);
	free(fset);
};

FcFontSet*
FcConfigGetFonts(FcConfig*, int)
{
	FcFontSet* fset;
	FcPattern* d;
	Biobuf *b;
	char *s, *pr, *file, *line, *f[3];
	int ntok;

	fset = allocfontset();

	file = "/sys/lib/fontsrv.map";
	b = Bopen(file, OREAD);
	if(b == 0)
		return fset;
	while((line = Brdline(b, '\n')) != nil){
		line[Blinelen(b)-1] = 0;
		s = strchr(line, '#');
		if(s != nil && (s == line || s[-1] == ' ' || s[-1] == '\t'))
			*s = '\0'; 	/* chop comment iff after whitespace */
		ntok = tokenize(line, f, nelem(f));
		switch(ntok){
		case 1:
			d = allocpat();
			d->fontfile = strdup(f[0]);
			pr = utfrrune(f[0], '/');
			if(pr)
				pr++;
			else
				pr = f[0];
			d->name = strdup(pr);
			appendfontset(fset, d);
			break;
		case 2:
			d = allocpat();
			d->name = strdup(f[0]);
			d->fontfile = strdup(f[1]);
			appendfontset(fset, d);
			break;
		}
	}
	Bterm(b);
	return fset;
};

int
FcPatternGetString(FcPattern* pat, int attr, int, FcChar8** res)
{
	switch(attr){
	case FC_POSTSCRIPT_NAME:
		*res = pat->name;
		return FcResultMatch;
	case FC_FILE:
		*res = pat->fontfile;
		return FcResultMatch;
	}
	return -1;
}

int
FcPatternGetInteger(FcPattern* pat, int attr, int, int* res)
{
	switch(attr){
	case FC_INDEX:
		*res = pat->index;
		return FcResultMatch;
	}
	return -1;
}
