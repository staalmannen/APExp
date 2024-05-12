# 1 "typeinc.m"
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
extern struct modDescriptor  *_OBJCBIND_typeinc(void);
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
extern struct modDescriptor typeinc_modDesc;

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
# 28 "./typeinc.h"
struct TypeInconsistency_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 35 "./../../include/objcrt/Exceptn.h"
id messageText;
id tag;
id resumeHandler;
# 30 "./typeinc.h"
char gotChar;
char wantChar;};
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

# 28 "./typeinc.h"
extern id  TypeInconsistency;

# 28 "./typeinc.h"
extern struct Exception_SHARED _TypeInconsistency;
extern struct _SHARED __TypeInconsistency;


# 30 "typeinc.m"
static char i_TypeInconsistency_gotChar(struct TypeInconsistency_PRIVATE *self,SEL _cmd)
{
return self->gotChar;
}

static char i_TypeInconsistency_wantChar(struct TypeInconsistency_PRIVATE *self,SEL _cmd)
{
return self->wantChar;
}

static id i_TypeInconsistency_got_wanted_(struct TypeInconsistency_PRIVATE *self,SEL _cmd,char c,char w)
{self->
gotChar=c;self->
wantChar=w;
return(id)self;
}

# 40 "./ocstring.h"
extern id  String;

# 47 "typeinc.m"
static id i_TypeInconsistency_signal(struct TypeInconsistency_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 49 "typeinc.m"
if( !self->messageText)
{
id objcT0;
self->
# 51 "typeinc.m"
messageText=(objcT0=String,(*(id(*)(id,SEL,STR,...))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],"Want %c, got %c",self->wantChar,self->gotChar));
}
return(objcT1=_TypeInconsistency.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Exception;
extern struct Exception_SHARED _Exception;
extern struct _SHARED __Exception;
static struct _SLT _TypeInconsistency_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _TypeInconsistency_nstDispatchTbl[] ={
{"gotChar",(id (*)())i_TypeInconsistency_gotChar},
{"wantChar",(id (*)())i_TypeInconsistency_wantChar},
{"got:wanted:",(id (*)())i_TypeInconsistency_got_wanted_},
{"signal",(id (*)())i_TypeInconsistency_signal},
{(char*)0,(id (*)())0}
};
id TypeInconsistency = (id)&_TypeInconsistency;
id  *OBJCCLASS_TypeInconsistency(void) { return &TypeInconsistency; }
struct Exception_SHARED  _TypeInconsistency = {
  (id)&__TypeInconsistency,
  (id)&_Exception,
  "TypeInconsistency",
  0,
  sizeof(struct TypeInconsistency_PRIVATE),
  4,
  _TypeInconsistency_nstDispatchTbl,
  41,
  &typeinc_modDesc,
  0,
  (id)0,
  &TypeInconsistency,
};
id  OBJCCFUNC_TypeInconsistency(void) { return (id)&_TypeInconsistency; }
id  OBJCCSUPER_TypeInconsistency(void) { return _TypeInconsistency.clsSuper; }
struct _SHARED __TypeInconsistency = {
  (id)&__Object,
  (id)&__Exception,
  "TypeInconsistency",
  0,
  sizeof(struct Exception_SHARED),
  0,
  _TypeInconsistency_clsDispatchTbl,
  34,
  &typeinc_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_TypeInconsistency(void) { return (id)&__TypeInconsistency; }
id  OBJCMSUPER_TypeInconsistency(void) { return __TypeInconsistency.clsSuper; }
static char *_selTransTbl[] ={
"sprintf:",
"signal",
0
};
struct modDescriptor typeinc_modDesc = {
  "typeinc",
  "objc3.3.19",
  0L,
  0,
  0,
  &TypeInconsistency,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_typeinc(void)
{
  selTransTbl = _selTransTbl;
  return &typeinc_modDesc;
}
int _OBJCPOSTLINK_typeinc = 1;


