# 1 "paragrph.m"
struct _PRIVATE { struct _PRIVATE *isa; };
typedef struct _PRIVATE *id;
struct _SHARED {
  id isa;
  id clsSuper;
  char *clsName;
  char *clsTypes;
  short clsSizInstance;
  short clsSizDict;
  struct _SLT *clsDispTable;
  long clsStatus;
  struct modDescriptor *clsMod;
  unsigned clsVersion;
  id clsCats;
  id *clsGlbl;
};
extern id  (* _imp(id,char*))();
extern id  (* _impSuper(id,char*))();
extern struct modDescriptor  *_OBJCBIND_paragrph(void);
static char **selTransTbl;
struct _SLT {char *_cmd;id (*_imp)();};
struct modDescriptor {
  char *modName;
  char *modVersion;
  long modStatus;
  char *modMinSel;
  char *modMaxSel;
  id *modClsLst;
  short modSelRef;
  char **modSelTbl;
  struct methodDescriptor *modMapTbl;
};
extern struct modDescriptor paragrph_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//ctype.h"
#include <ctype.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stddef.h"
#include <stddef.h>

# 53 "./../../include/objcrt/objcrt.h"
typedef char*SEL;
typedef char*STR;
typedef char BOOL;
typedef FILE*IOD;
typedef id SHR;
# 62 "./../../include/objcrt/objcrt.h"
typedef id(*IMP)();


typedef void(*ARGIMP)(id,SEL,void*);
# 85 "./../../include/objcrt/objcrt.h"
extern BOOL msgFlag;
extern FILE*msgIOD;
extern FILE*dbgIOD;
extern BOOL allocFlag;
extern BOOL dbgFlag;
extern BOOL noCacheFlag;
extern BOOL noNilRcvr;
# 98 "./../../include/objcrt/objcrt.h"
SEL selUid(STR);
STR selName(SEL);
void dbg(char*fmt,...);
void loadobjc(void*modPtr);
void unloadobjc(void*modPtr);
# 106 "./../../include/objcrt/objcrt.h"
IMP fwdimp(id,SEL,IMP);
IMP fwdimpSuper(id,SEL,IMP);
void fwdmsg(id,SEL,void*,ARGIMP);
id selptrfwd(id,SEL,id,id,id,id);


id idincref(id obj);
id idassign(id*lhs,id rhs);
id iddecref(id obj);

extern id(*_fileIn)(FILE*);
extern BOOL(*_fileOut)(FILE*,id);
extern BOOL(*_storeOn)(STR,id);
extern id(*_readFrom)(STR);
void setfilein(id(*f)(FILE*));
void setfileout(BOOL(*f)(FILE*,id));

extern id(*_showOn)(id,unsigned);

void*OC_Malloc(size_t);
void*OC_MallocAtomic(size_t);
void*OC_Calloc(size_t);
void*OC_Realloc(void*,size_t);
void*OC_Free(void*data);
# 1 "../../util//string.h"
#include <string.h>

# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 32 "./paragrph.h"
struct Paragraph_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./paragrph.h"
id text;
id textStyle;
id offset;};

# 32 "./paragrph.h"
extern id  Paragraph;

# 32 "./paragrph.h"
extern struct _SHARED _Paragraph;
extern struct _SHARED __Paragraph;


# 32 "./octext.h"
extern id  Text;

# 33 "paragrph.m"
static id c_Paragraph_new(struct Paragraph_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 35 "paragrph.m"
return(objcT0=(id)self,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(objcT1=Text,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]))));
}

# 28 "./txtstyle.h"
extern id  TextStyle;

# 38 "paragrph.m"
static id c_Paragraph_withText_(struct Paragraph_PRIVATE *self,SEL _cmd,id aText)
{
id objcT2,objcT3;

# 40 "paragrph.m"
return(objcT2=(id)self,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],aText,(objcT3=TextStyle,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]))));
}

static id c_Paragraph_withText_style_(struct Paragraph_PRIVATE *self,SEL _cmd,id aText,id aStyle)
{
id objcT4,objcT5;

# 45 "paragrph.m"
return(objcT4=(objcT5=__Paragraph.clsSuper,(*_impSuper(objcT5,selTransTbl[1]))((id)self,selTransTbl[1])),(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],aText,aStyle));
}

static id i_Paragraph_withText_style_(struct Paragraph_PRIVATE *self,SEL _cmd,id r,id v)
{self->
text=r;self->
textStyle=v;
return(id)self;
}

static id i_Paragraph_copy(struct Paragraph_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7,objcT8;

# 57 "paragrph.m"
return(objcT6=self->isa,(*_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2],(objcT7=self->text,(*_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4])),(objcT8=self->textStyle,(*_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4]))));
}

static id i_Paragraph_free(struct Paragraph_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10,objcT11;
self->
# 62 "paragrph.m"
text=(objcT9=self->text,(*_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5]));self->
textStyle=(objcT10=self->textStyle,(*_imp(objcT10,selTransTbl[5]))(objcT10,selTransTbl[5]));
return(objcT11=_Paragraph.clsSuper,(*_impSuper(objcT11,selTransTbl[5]))((id)self,selTransTbl[5]));
}


static id i_Paragraph_text(struct Paragraph_PRIVATE *self,SEL _cmd)
{
return self->text;
}

static id i_Paragraph_textStyle(struct Paragraph_PRIVATE *self,SEL _cmd)
{
return self->textStyle;
}

static id i_Paragraph_text_(struct Paragraph_PRIVATE *self,SEL _cmd,id v)
{self->
text=v;
return(id)self;
}

static id i_Paragraph_textStyle_(struct Paragraph_PRIVATE *self,SEL _cmd,id v)
{self->
textStyle=v;
return(id)self;
}


static id i_Paragraph_asString(struct Paragraph_PRIVATE *self,SEL _cmd)
{
id objcT12;

# 93 "paragrph.m"
return(objcT12=self->text,(*_imp(objcT12,selTransTbl[6]))(objcT12,selTransTbl[6]));
}

static id i_Paragraph_asText(struct Paragraph_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 98 "paragrph.m"
return(objcT13=self->text,(*_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7]));
}


static id i_Paragraph_printOn_(struct Paragraph_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT14;

# 104 "paragrph.m"
(objcT14=self->text,(*(id(*)(id,SEL,IOD))_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8],aFile));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Paragraph_clsDispatchTbl[] ={
{"new",(id (*)())c_Paragraph_new},
{"withText:",(id (*)())c_Paragraph_withText_},
{"withText:style:",(id (*)())c_Paragraph_withText_style_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Paragraph_nstDispatchTbl[] ={
{"withText:style:",(id (*)())i_Paragraph_withText_style_},
{"copy",(id (*)())i_Paragraph_copy},
{"free",(id (*)())i_Paragraph_free},
{"text",(id (*)())i_Paragraph_text},
{"textStyle",(id (*)())i_Paragraph_textStyle},
{"text:",(id (*)())i_Paragraph_text_},
{"textStyle:",(id (*)())i_Paragraph_textStyle_},
{"asString",(id (*)())i_Paragraph_asString},
{"asText",(id (*)())i_Paragraph_asText},
{"printOn:",(id (*)())i_Paragraph_printOn_},
{(char*)0,(id (*)())0}
};
id Paragraph = (id)&_Paragraph;
id  *OBJCCLASS_Paragraph(void) { return &Paragraph; }
struct _SHARED  _Paragraph = {
  (id)&__Paragraph,
  (id)&_Object,
  "Paragraph",
  0,
  sizeof(struct Paragraph_PRIVATE),
  10,
  _Paragraph_nstDispatchTbl,
  41,
  &paragrph_modDesc,
  0,
  (id)0,
  &Paragraph,
};
id  OBJCCFUNC_Paragraph(void) { return (id)&_Paragraph; }
id  OBJCCSUPER_Paragraph(void) { return _Paragraph.clsSuper; }
struct _SHARED __Paragraph = {
  (id)&__Object,
  (id)&__Object,
  "Paragraph",
  0,
  sizeof(struct _SHARED),
  3,
  _Paragraph_clsDispatchTbl,
  34,
  &paragrph_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Paragraph(void) { return (id)&__Paragraph; }
id  OBJCMSUPER_Paragraph(void) { return __Paragraph.clsSuper; }
static char *_selTransTbl[] ={
"withText:",
"new",
"withText:style:",
"default",
"copy",
"free",
"asString",
"asText",
"printOn:",
0
};
struct modDescriptor paragrph_modDesc = {
  "paragrph",
  "objc3.3.19",
  0L,
  0,
  0,
  &Paragraph,
  9,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_paragrph(void)
{
  selTransTbl = _selTransTbl;
  return &paragrph_modDesc;
}
int _OBJCPOSTLINK_paragrph = 1;


