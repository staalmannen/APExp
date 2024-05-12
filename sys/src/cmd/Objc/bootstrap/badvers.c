# 1 "badvers.m"
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
extern struct modDescriptor  *_OBJCBIND_badvers(void);
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
extern struct modDescriptor badvers_modDesc;

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

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 28 "./badvers.h"
struct BadVersion_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 35 "./../../include/objcrt/Exceptn.h"
id messageText;
id tag;
id resumeHandler;
# 30 "./badvers.h"
int badVersion;
int goodVersion;};
struct Exception_SHARED {
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

# 41 "./../../include/objcrt/Exceptn.h"
id handler;};

# 28 "./badvers.h"
extern id  BadVersion;

# 28 "./badvers.h"
extern struct Exception_SHARED _BadVersion;
extern struct _SHARED __BadVersion;


# 30 "badvers.m"
static int i_BadVersion_goodVersion(struct BadVersion_PRIVATE *self,SEL _cmd)
{
return self->goodVersion;
}

static int i_BadVersion_badVersion(struct BadVersion_PRIVATE *self,SEL _cmd)
{
return self->badVersion;
}

static id i_BadVersion_goodVersion_badVersion_(struct BadVersion_PRIVATE *self,SEL _cmd,int g,int b)
{self->
goodVersion=g;self->
badVersion=b;
return(id)self;
}

# 40 "./ocstring.h"
extern id  String;

# 47 "badvers.m"
static id i_BadVersion_signal(struct BadVersion_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 49 "badvers.m"
if( !self->messageText)
{
id objcT0;
self->
# 51 "badvers.m"
messageText=(objcT0=String,(*(id(*)(id,SEL,STR,...))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],"Expect version %i, got version %i",self->goodVersion,self->badVersion));
}
return(objcT1=_BadVersion.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Exception;
extern struct Exception_SHARED _Exception;
extern struct _SHARED __Exception;
static struct _SLT _BadVersion_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _BadVersion_nstDispatchTbl[] ={
{"goodVersion",(id (*)())i_BadVersion_goodVersion},
{"badVersion",(id (*)())i_BadVersion_badVersion},
{"goodVersion:badVersion:",(id (*)())i_BadVersion_goodVersion_badVersion_},
{"signal",(id (*)())i_BadVersion_signal},
{(char*)0,(id (*)())0}
};
id BadVersion = (id)&_BadVersion;
id  *OBJCCLASS_BadVersion(void) { return &BadVersion; }
struct Exception_SHARED  _BadVersion = {
  (id)&__BadVersion,
  (id)&_Exception,
  "BadVersion",
  0,
  sizeof(struct BadVersion_PRIVATE),
  4,
  _BadVersion_nstDispatchTbl,
  41,
  &badvers_modDesc,
  0,
  (id)0,
  &BadVersion,
};
id  OBJCCFUNC_BadVersion(void) { return (id)&_BadVersion; }
id  OBJCCSUPER_BadVersion(void) { return _BadVersion.clsSuper; }
struct _SHARED __BadVersion = {
  (id)&__Object,
  (id)&__Exception,
  "BadVersion",
  0,
  sizeof(struct Exception_SHARED),
  0,
  _BadVersion_clsDispatchTbl,
  34,
  &badvers_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_BadVersion(void) { return (id)&__BadVersion; }
id  OBJCMSUPER_BadVersion(void) { return __BadVersion.clsSuper; }
static char *_selTransTbl[] ={
"sprintf:",
"signal",
0
};
struct modDescriptor badvers_modDesc = {
  "badvers",
  "objc3.3.19",
  0L,
  0,
  0,
  &BadVersion,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_badvers(void)
{
  selTransTbl = _selTransTbl;
  return &badvers_modDesc;
}
int _OBJCPOSTLINK_badvers = 1;


