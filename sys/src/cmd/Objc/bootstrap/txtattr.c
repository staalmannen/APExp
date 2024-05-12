# 1 "txtattr.m"
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
extern struct modDescriptor  *_OBJCBIND_txtattr(void);
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
extern struct modDescriptor txtattr_modDesc;

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

# 32 "./txtattr.h"
struct TextAttribute_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./txtattr.h"
unsigned emphasiscode;};

# 32 "./txtattr.h"
extern id  TextAttribute;

# 32 "./txtattr.h"
extern struct _SHARED _TextAttribute;
extern struct _SHARED __TextAttribute;


# 31 "txtattr.m"
static id c_TextAttribute_normal(struct TextAttribute_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 33 "txtattr.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],0));
}

static id c_TextAttribute_new(struct TextAttribute_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 38 "txtattr.m"
return(objcT1=(id)self,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id c_TextAttribute_bold(struct TextAttribute_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 43 "txtattr.m"
return(objcT2=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0],1));
}

static id c_TextAttribute_emphasiscode_(struct TextAttribute_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT3,objcT4;

# 48 "txtattr.m"
return(objcT3=(objcT4=__TextAttribute.clsSuper,(*_impSuper(objcT4,selTransTbl[2]))((id)self,selTransTbl[2])),(*(id(*)(id,SEL,unsigned))_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0],n));
}


static unsigned i_TextAttribute_emphasiscode(struct TextAttribute_PRIVATE *self,SEL _cmd)
{
return self->emphasiscode;
}

static id i_TextAttribute_emphasiscode_(struct TextAttribute_PRIVATE *self,SEL _cmd,unsigned c)
{self->
emphasiscode=c;
return(id)self;
}


static BOOL i_TextAttribute_isEqual_(struct TextAttribute_PRIVATE *self,SEL _cmd,id attrib)
{
if((id)self==attrib)
{
return(BOOL)1;
}
else
{
id objcT5,objcT6;

# 72 "txtattr.m"
return((objcT5=attrib,(*(BOOL(*)(id,SEL,id))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],(id)self->isa)))&&(self->emphasiscode==(objcT6=attrib,(*(unsigned(*)(id,SEL))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4])));
}
}


static BOOL i_TextAttribute_dominates_(struct TextAttribute_PRIVATE *self,SEL _cmd,id attrib)
{
id objcT7;

# 79 "txtattr.m"
if((objcT7=attrib,(*(BOOL(*)(id,SEL,id))_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3],(id)self->isa)))
{
id objcT8;

# 81 "txtattr.m"
return(objcT8=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5],attrib));
}
else
{
return(BOOL)0;
}
}

static id i_TextAttribute_reset(struct TextAttribute_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static BOOL i_TextAttribute_set(struct TextAttribute_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}


static id i_TextAttribute_emphasizeScanner_(struct TextAttribute_PRIVATE *self,SEL _cmd,id aScanner)
{
return(id)self;
}


static id i_TextAttribute_printOn_(struct TextAttribute_PRIVATE *self,SEL _cmd,IOD aFile)
{
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _TextAttribute_clsDispatchTbl[] ={
{"normal",(id (*)())c_TextAttribute_normal},
{"new",(id (*)())c_TextAttribute_new},
{"bold",(id (*)())c_TextAttribute_bold},
{"emphasiscode:",(id (*)())c_TextAttribute_emphasiscode_},
{(char*)0,(id (*)())0}
};
static struct _SLT _TextAttribute_nstDispatchTbl[] ={
{"emphasiscode",(id (*)())i_TextAttribute_emphasiscode},
{"emphasiscode:",(id (*)())i_TextAttribute_emphasiscode_},
{"isEqual:",(id (*)())i_TextAttribute_isEqual_},
{"dominates:",(id (*)())i_TextAttribute_dominates_},
{"reset",(id (*)())i_TextAttribute_reset},
{"set",(id (*)())i_TextAttribute_set},
{"emphasizeScanner:",(id (*)())i_TextAttribute_emphasizeScanner_},
{"printOn:",(id (*)())i_TextAttribute_printOn_},
{(char*)0,(id (*)())0}
};
id TextAttribute = (id)&_TextAttribute;
id  *OBJCCLASS_TextAttribute(void) { return &TextAttribute; }
struct _SHARED  _TextAttribute = {
  (id)&__TextAttribute,
  (id)&_Object,
  "TextAttribute",
  0,
  sizeof(struct TextAttribute_PRIVATE),
  8,
  _TextAttribute_nstDispatchTbl,
  41,
  &txtattr_modDesc,
  0,
  (id)0,
  &TextAttribute,
};
id  OBJCCFUNC_TextAttribute(void) { return (id)&_TextAttribute; }
id  OBJCCSUPER_TextAttribute(void) { return _TextAttribute.clsSuper; }
struct _SHARED __TextAttribute = {
  (id)&__Object,
  (id)&__Object,
  "TextAttribute",
  0,
  sizeof(struct _SHARED),
  4,
  _TextAttribute_clsDispatchTbl,
  34,
  &txtattr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_TextAttribute(void) { return (id)&__TextAttribute; }
id  OBJCMSUPER_TextAttribute(void) { return __TextAttribute.clsSuper; }
static char *_selTransTbl[] ={
"emphasiscode:",
"normal",
"new",
"isMemberOf:",
"emphasiscode",
"isEqual:",
0
};
struct modDescriptor txtattr_modDesc = {
  "txtattr",
  "objc3.3.19",
  0L,
  0,
  0,
  &TextAttribute,
  6,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_txtattr(void)
{
  selTransTbl = _selTransTbl;
  return &txtattr_modDesc;
}
int _OBJCPOSTLINK_txtattr = 1;


