typedef struct XFont XFont;

enum {
	SubfontSize = 32,
	MaxSubfont = (Runemax+1)/SubfontSize,
};

struct XFont
{
	char *name;
	int loaded;
	uchar range[MaxSubfont]; // range[i] = fontfile starting at i*SubfontSize exists
	ushort file[MaxSubfont];	// file[i] == fontfile i's lo rune / SubfontSize
	int nfile;
	int unit;
	double height;
	double originy;
	void (*loadheight)(XFont*, int, int*, int*);
	char *fonttext;
	int nfonttext;

	// fontconfig workarround, as FC_FULLNAME does not work for matching fonts.
	char *fontfile;
	int  index;
};

void	loadfonts(void);
void	load(XFont*);
Memsubfont*	mksubfont(XFont*, char*, int, int, int, int);

void *emalloc9p(ulong);
void	drawpjw(Memimage*, Fontchar*, int, int, int, int);

extern XFont *xfont;
extern int nxfont;

// FontConfig-like API
typedef struct FcConfig FcConfig;
typedef struct FcFontSet FcFontSet;
typedef struct FcPattern FcPattern;

typedef char FcChar8;

struct FcConfig {
	void*	aux;
};

struct FcFontSet {
	int	nfont;
	FcPattern**	fonts;
};

struct FcPattern {
	// access through FcPatternGetString, FcPatternGetInteger
	int	index;
	char*	name;
	char*	fontfile;
};

enum {
	FcSetSystem,
	FcResultMatch,
	FC_POSTSCRIPT_NAME,
	FC_FILE,
	FC_INDEX,
};

int	FcInit(void);
FcConfig*	FcInitLoadConfigAndFonts(void);
void	FcFontSetDestroy(FcFontSet*);
FcFontSet*	FcConfigGetFonts(FcConfig*, int);
int	FcPatternGetString(FcPattern*, int, int, FcChar8**);
int	FcPatternGetInteger(FcPattern*, int, int, int*);

