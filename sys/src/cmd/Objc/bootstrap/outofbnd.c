# 1 "outofbnd.m"
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
extern struct modDescriptor  *_OBJCBIND_outofbnd(void);
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
extern struct modDescriptor outofbnd_modDesc;

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
# 28 "./outofbnd.h"
struct OutOfBounds_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 35 "./../../include/objcrt/Exceptn.h"
id messageText;
id tag;
id resumeHandler;
# 30 "./outofbnd.h"
unsigned size;
unsigned offset;};
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

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 28 "./outofbnd.h"
extern struct Exception_SHARED _OutOfBounds;
extern struct _SHARED __OutOfBounds;


# 30 "outofbnd.m"
static unsigned i_OutOfBounds_size(struct OutOfBounds_PRIVATE *self,SEL _cmd)
{
return self->size;
}

static id i_OutOfBounds_at_(struct OutOfBounds_PRIVATE *self,SEL _cmd,unsigned n)
{self->
offset=n;
return(id)self;
}

static id c_OutOfBounds_new_(struct OutOfBounds_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT0,objcT1;

# 43 "outofbnd.m"
return(objcT0=(objcT1=__OutOfBounds.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0])),(*(id(*)(id,SEL,unsigned))_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],n));
}

static id i_OutOfBounds_new_(struct OutOfBounds_PRIVATE *self,SEL _cmd,unsigned n)
{self->
size=n;
return(id)self;
}

# 40 "./ocstring.h"
extern id  String;

# 52 "outofbnd.m"
static id i_OutOfBounds_signal(struct OutOfBounds_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 54 "outofbnd.m"
if( !self->messageText)
{
id objcT2;
self->
# 56 "outofbnd.m"
messageText=(objcT2=String,(*(id(*)(id,SEL,STR,...))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],"offset %u, size %u",self->offset,self->size));
}
return(objcT3=_OutOfBounds.clsSuper,(*_impSuper(objcT3,selTransTbl[3]))((id)self,selTransTbl[3]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Exception;
extern struct Exception_SHARED _Exception;
extern struct _SHARED __Exception;
static struct _SLT _OutOfBounds_clsDispatchTbl[] ={
{"new:",(id (*)())c_OutOfBounds_new_},
{(char*)0,(id (*)())0}
};
static struct _SLT _OutOfBounds_nstDispatchTbl[] ={
{"size",(id (*)())i_OutOfBounds_size},
{"at:",(id (*)())i_OutOfBounds_at_},
{"new:",(id (*)())i_OutOfBounds_new_},
{"signal",(id (*)())i_OutOfBounds_signal},
{(char*)0,(id (*)())0}
};
id OutOfBounds = (id)&_OutOfBounds;
id  *OBJCCLASS_OutOfBounds(void) { return &OutOfBounds; }
struct Exception_SHARED  _OutOfBounds = {
  (id)&__OutOfBounds,
  (id)&_Exception,
  "OutOfBounds",
  0,
  sizeof(struct OutOfBounds_PRIVATE),
  4,
  _OutOfBounds_nstDispatchTbl,
  41,
  &outofbnd_modDesc,
  0,
  (id)0,
  &OutOfBounds,
};
id  OBJCCFUNC_OutOfBounds(void) { return (id)&_OutOfBounds; }
id  OBJCCSUPER_OutOfBounds(void) { return _OutOfBounds.clsSuper; }
struct _SHARED __OutOfBounds = {
  (id)&__Object,
  (id)&__Exception,
  "OutOfBounds",
  0,
  sizeof(struct Exception_SHARED),
  1,
  _OutOfBounds_clsDispatchTbl,
  34,
  &outofbnd_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_OutOfBounds(void) { return (id)&__OutOfBounds; }
id  OBJCMSUPER_OutOfBounds(void) { return __OutOfBounds.clsSuper; }
static char *_selTransTbl[] ={
"new",
"new:",
"sprintf:",
"signal",
0
};
struct modDescriptor outofbnd_modDesc = {
  "outofbnd",
  "objc3.3.19",
  0L,
  0,
  0,
  &OutOfBounds,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_outofbnd(void)
{
  selTransTbl = _selTransTbl;
  return &outofbnd_modDesc;
}
int _OBJCPOSTLINK_outofbnd = 1;


