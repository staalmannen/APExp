# 1 "OutOfMem.m"
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
extern struct modDescriptor  *_OBJCBIND_OutOfMem(void);
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
extern struct modDescriptor OutOfMem_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stddef.h"
#include <stddef.h>

# 55 "./objcrt.h"
typedef char*SEL;
typedef char*STR;
typedef char BOOL;
typedef FILE*IOD;
typedef id SHR;
# 64 "./objcrt.h"
typedef id(*IMP)();


typedef void(*ARGIMP)(id,SEL,void*);
# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 117 "./objcrt.h"
struct objcrt_private
{
id isa;
# 123 "./objcrt.h"
unsigned short attr;
unsigned short objID;

};

struct objcrt_shared
{
id isa;
# 134 "./objcrt.h"
id clsSuper;
char*clsName;
char*clsTypes;
short clsSizInstance;
short clsSizDict;
struct objcrt_slt*clsDispTable;
long clsStatus;
struct objcrt_modDescriptor*clsMod;
unsigned clsVersion;
id clsCats;
id*clsGlbl;
};

typedef struct objcrt_shared*Cls_t;
# 179 "./objcrt.h"
struct objcrt_slt
{
SEL _cmd;
IMP _imp;
};
# 189 "./objcrt.h"
struct objcrt_useDescriptor
{
int processed;
struct objcrt_useDescriptor*next;
struct objcrt_useDescriptor***uses;
struct objcrt_modDescriptor*(*bind)();
};
# 201 "./objcrt.h"
typedef struct hashedSelector
{
struct hashedSelector*next;
STR key;
}
HASH,*PHASH;
# 213 "./objcrt.h"
typedef struct objcrt_modDescriptor MOD,*PMOD;
typedef struct objcrt_methodDescriptor METH,*PMETH;

struct objcrt_modDescriptor
{
STR modName;
STR modVersion;
long modStatus;
SEL modMinSel;
SEL modMaxSel;
id*modClsLst;
short modSelRef;
SEL*modSelTbl;
PMETH modMapTbl;
};

struct objcrt_modEntry
{
PMOD(*modLink)();
PMOD modInfo;
};

typedef struct objcrt_modEntry*Mentry_t;

struct objcrt_methodDescriptor
{
id*cls;
SEL*sel;
IMP imp;
};
# 256 "./objcrt.h"
extern BOOL msgFlag;
extern FILE*msgIOD;
extern FILE*dbgIOD;
extern BOOL allocFlag;
extern BOOL dbgFlag;
extern BOOL noCacheFlag;
extern BOOL noNilRcvr;
# 269 "./objcrt.h"
SEL selUid(STR);
STR selName(SEL);
void dbg(char*fmt,...);
void loadobjc(void*modPtr);
void unloadobjc(void*modPtr);
# 286 "./objcrt.h"
IMP _imp(id,SEL);
IMP _impSuper(id,SEL);
# 291 "./objcrt.h"
IMP fwdimp(id,SEL,IMP);
IMP fwdimpSuper(id,SEL,IMP);
void fwdmsg(id,SEL,void*,ARGIMP);
id selptrfwd(id,SEL,id,id,id,id);


id idincref(id obj);
id idassign(id*lhs,id rhs);
id iddecref(id obj);
# 320 "./objcrt.h"
extern id(*oc_alloc)(id,unsigned int);
extern id(*oc_dealloc)(id);
extern id(*oc_copy)(id,unsigned int);
extern id(*oc_error)(id,STR,va_list);

extern id(*oc_cvtToId)(STR);
extern SEL(*oc_cvtToSel)(STR);

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

void addSubclassesTo(id c,STR name);

id newsubclass(STR name,id superClass,int ivars,int cvars);
void linkclass(id aclass);
void unlinkclass(id aclass);

void addMethods(id src,id dst);

void poseAs(id posing,id target);
id swapclass(id self,id target);
# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 28 "./OutOfMem.h"
struct OutOfMemory_PRIVATE {

# 42 "./Object.h"
id isa;
# 46 "./Object.h"
unsigned short attr;
unsigned short objID;
# 39 "./Exceptn.h"
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

# 45 "./Exceptn.h"
id handler;};

# 28 "./OutOfMem.h"
extern id  OutOfMemory;

# 28 "./OutOfMem.h"
extern struct Exception_SHARED _OutOfMemory;
extern struct _SHARED __OutOfMemory;

extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Exception;
extern struct Exception_SHARED _Exception;
extern struct _SHARED __Exception;
static struct _SLT _OutOfMemory_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _OutOfMemory_nstDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
id OutOfMemory = (id)&_OutOfMemory;
id  *OBJCCLASS_OutOfMemory(void) { return &OutOfMemory; }
struct Exception_SHARED  _OutOfMemory = {
  (id)&__OutOfMemory,
  (id)&_Exception,
  "OutOfMemory",
  0,
  sizeof(struct OutOfMemory_PRIVATE),
  0,
  _OutOfMemory_nstDispatchTbl,
  41,
  &OutOfMem_modDesc,
  0,
  (id)0,
  &OutOfMemory,
};
id  OBJCCFUNC_OutOfMemory(void) { return (id)&_OutOfMemory; }
id  OBJCCSUPER_OutOfMemory(void) { return _OutOfMemory.clsSuper; }
struct _SHARED __OutOfMemory = {
  (id)&__Object,
  (id)&__Exception,
  "OutOfMemory",
  0,
  sizeof(struct Exception_SHARED),
  0,
  _OutOfMemory_clsDispatchTbl,
  34,
  &OutOfMem_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_OutOfMemory(void) { return (id)&__OutOfMemory; }
id  OBJCMSUPER_OutOfMemory(void) { return __OutOfMemory.clsSuper; }
static char *_selTransTbl[] ={
0
};
struct modDescriptor OutOfMem_modDesc = {
  "OutOfMem",
  "objc3.3.19",
  0L,
  0,
  0,
  &OutOfMemory,
  0,
  0,
  0
};
struct modDescriptor *_OBJCBIND_OutOfMem(void)
{
  selTransTbl = _selTransTbl;
  return &OutOfMem_modDesc;
}
int _OBJCPOSTLINK_OutOfMem = 1;


