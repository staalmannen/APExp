# 1 "txtstyle.m"
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
extern struct modDescriptor  *_OBJCBIND_txtstyle(void);
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
extern struct modDescriptor txtstyle_modDesc;

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
# 28 "./txtstyle.h"
struct TextStyle_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./array.h"
unsigned capacity;
# 42 "./ocstring.h"
struct objstr value;};

# 28 "./txtstyle.h"
extern id  TextStyle;

# 28 "./txtstyle.h"
extern struct _SHARED _TextStyle;
extern struct _SHARED __TextStyle;


# 31 "txtstyle.m"
static id c_TextStyle_default(struct TextStyle_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 33 "txtstyle.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],"Default"));
}

static id c_TextStyle_named_(struct TextStyle_PRIVATE *self,SEL _cmd,STR name)
{
id objcT1;

# 38 "txtstyle.m"
return(objcT1=__TextStyle.clsSuper,(*(id(*)(id,SEL,STR))_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1],name));
}


static STR i_TextStyle_name(struct TextStyle_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 44 "txtstyle.m"
return(objcT2=(id)self,(*(STR(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
}


static id i_TextStyle_printOn_(struct TextStyle_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT3;

# 50 "txtstyle.m"
fprintf(aFile,"TextStyle %s",(objcT3=(id)self,(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3])));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  String;
extern struct _SHARED _String;
extern struct _SHARED __String;
static struct _SLT _TextStyle_clsDispatchTbl[] ={
{"default",(id (*)())c_TextStyle_default},
{"named:",(id (*)())c_TextStyle_named_},
{(char*)0,(id (*)())0}
};
static struct _SLT _TextStyle_nstDispatchTbl[] ={
{"name",(id (*)())i_TextStyle_name},
{"printOn:",(id (*)())i_TextStyle_printOn_},
{(char*)0,(id (*)())0}
};
id TextStyle = (id)&_TextStyle;
id  *OBJCCLASS_TextStyle(void) { return &TextStyle; }
struct _SHARED  _TextStyle = {
  (id)&__TextStyle,
  (id)&_String,
  "TextStyle",
  0,
  sizeof(struct TextStyle_PRIVATE),
  2,
  _TextStyle_nstDispatchTbl,
  41,
  &txtstyle_modDesc,
  0,
  (id)0,
  &TextStyle,
};
id  OBJCCFUNC_TextStyle(void) { return (id)&_TextStyle; }
id  OBJCCSUPER_TextStyle(void) { return _TextStyle.clsSuper; }
struct _SHARED __TextStyle = {
  (id)&__Object,
  (id)&__String,
  "TextStyle",
  0,
  sizeof(struct _SHARED),
  2,
  _TextStyle_clsDispatchTbl,
  34,
  &txtstyle_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_TextStyle(void) { return (id)&__TextStyle; }
id  OBJCMSUPER_TextStyle(void) { return __TextStyle.clsSuper; }
static char *_selTransTbl[] ={
"named:",
"str:",
"str",
"name",
0
};
struct modDescriptor txtstyle_modDesc = {
  "txtstyle",
  "objc3.3.19",
  0L,
  0,
  0,
  &TextStyle,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_txtstyle(void)
{
  selTransTbl = _selTransTbl;
  return &txtstyle_modDesc;
}
int _OBJCPOSTLINK_txtstyle = 1;


