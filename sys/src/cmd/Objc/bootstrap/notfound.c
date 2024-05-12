# 1 "notfound.m"
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
extern struct modDescriptor  *_OBJCBIND_notfound(void);
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
extern struct modDescriptor notfound_modDesc;

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

# 28 "./notfound.h"
struct NotFound_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 35 "./../../include/objcrt/Exceptn.h"
id messageText;
id tag;
id resumeHandler;};
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

# 28 "./notfound.h"
extern id  NotFound;

# 28 "./notfound.h"
extern struct Exception_SHARED _NotFound;
extern struct _SHARED __NotFound;

extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Exception;
extern struct Exception_SHARED _Exception;
extern struct _SHARED __Exception;
static struct _SLT _NotFound_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _NotFound_nstDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
id NotFound = (id)&_NotFound;
id  *OBJCCLASS_NotFound(void) { return &NotFound; }
struct Exception_SHARED  _NotFound = {
  (id)&__NotFound,
  (id)&_Exception,
  "NotFound",
  0,
  sizeof(struct NotFound_PRIVATE),
  0,
  _NotFound_nstDispatchTbl,
  41,
  &notfound_modDesc,
  0,
  (id)0,
  &NotFound,
};
id  OBJCCFUNC_NotFound(void) { return (id)&_NotFound; }
id  OBJCCSUPER_NotFound(void) { return _NotFound.clsSuper; }
struct _SHARED __NotFound = {
  (id)&__Object,
  (id)&__Exception,
  "NotFound",
  0,
  sizeof(struct Exception_SHARED),
  0,
  _NotFound_clsDispatchTbl,
  34,
  &notfound_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_NotFound(void) { return (id)&__NotFound; }
id  OBJCMSUPER_NotFound(void) { return __NotFound.clsSuper; }
static char *_selTransTbl[] ={
0
};
struct modDescriptor notfound_modDesc = {
  "notfound",
  "objc3.3.19",
  0L,
  0,
  0,
  &NotFound,
  0,
  0,
  0
};
struct modDescriptor *_OBJCBIND_notfound(void)
{
  selTransTbl = _selTransTbl;
  return &notfound_modDesc;
}
int _OBJCPOSTLINK_notfound = 1;


