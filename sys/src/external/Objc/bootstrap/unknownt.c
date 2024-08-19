# 1 "unknownt.m"
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
extern struct modDescriptor  *_OBJCBIND_unknownt(void);
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
extern struct modDescriptor unknownt_modDesc;

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

# 28 "./unknownt.h"
struct UnknownType_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 35 "./../../include/objcrt/Exceptn.h"
id messageText;
id tag;
id resumeHandler;
# 30 "./unknownt.h"
char aChar;};
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

# 28 "./unknownt.h"
extern id  UnknownType;

# 28 "./unknownt.h"
extern struct Exception_SHARED _UnknownType;
extern struct _SHARED __UnknownType;


# 28 "unknownt.m"
static char i_UnknownType_typeDesc(struct UnknownType_PRIVATE *self,SEL _cmd)
{
return self->aChar;
}

static id i_UnknownType_typeDesc_(struct UnknownType_PRIVATE *self,SEL _cmd,char c)
{self->
aChar=c;
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Exception;
extern struct Exception_SHARED _Exception;
extern struct _SHARED __Exception;
static struct _SLT _UnknownType_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _UnknownType_nstDispatchTbl[] ={
{"typeDesc",(id (*)())i_UnknownType_typeDesc},
{"typeDesc:",(id (*)())i_UnknownType_typeDesc_},
{(char*)0,(id (*)())0}
};
id UnknownType = (id)&_UnknownType;
id  *OBJCCLASS_UnknownType(void) { return &UnknownType; }
struct Exception_SHARED  _UnknownType = {
  (id)&__UnknownType,
  (id)&_Exception,
  "UnknownType",
  0,
  sizeof(struct UnknownType_PRIVATE),
  2,
  _UnknownType_nstDispatchTbl,
  41,
  &unknownt_modDesc,
  0,
  (id)0,
  &UnknownType,
};
id  OBJCCFUNC_UnknownType(void) { return (id)&_UnknownType; }
id  OBJCCSUPER_UnknownType(void) { return _UnknownType.clsSuper; }
struct _SHARED __UnknownType = {
  (id)&__Object,
  (id)&__Exception,
  "UnknownType",
  0,
  sizeof(struct Exception_SHARED),
  0,
  _UnknownType_clsDispatchTbl,
  34,
  &unknownt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_UnknownType(void) { return (id)&__UnknownType; }
id  OBJCMSUPER_UnknownType(void) { return __UnknownType.clsSuper; }
static char *_selTransTbl[] ={
0
};
struct modDescriptor unknownt_modDesc = {
  "unknownt",
  "objc3.3.19",
  0L,
  0,
  0,
  &UnknownType,
  0,
  0,
  0
};
struct modDescriptor *_OBJCBIND_unknownt(void)
{
  selTransTbl = _selTransTbl;
  return &unknownt_modDesc;
}
int _OBJCPOSTLINK_unknownt = 1;


