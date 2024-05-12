# 1 "array.m"
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
extern struct modDescriptor  *_OBJCBIND_array(void);
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
extern struct modDescriptor array_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

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

# 32 "./array.h"
struct Array_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./array.h"
unsigned capacity;};

# 32 "./array.h"
extern id  Array;

# 32 "./array.h"
extern struct _SHARED _Array;
extern struct _SHARED __Array;

extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Array_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Array_nstDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
id Array = (id)&_Array;
id  *OBJCCLASS_Array(void) { return &Array; }
struct _SHARED  _Array = {
  (id)&__Array,
  (id)&_Object,
  "Array",
  0,
  sizeof(struct Array_PRIVATE),
  0,
  _Array_nstDispatchTbl,
  41,
  &array_modDesc,
  0,
  (id)0,
  &Array,
};
id  OBJCCFUNC_Array(void) { return (id)&_Array; }
id  OBJCCSUPER_Array(void) { return _Array.clsSuper; }
struct _SHARED __Array = {
  (id)&__Object,
  (id)&__Object,
  "Array",
  0,
  sizeof(struct _SHARED),
  0,
  _Array_clsDispatchTbl,
  34,
  &array_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Array(void) { return (id)&__Array; }
id  OBJCMSUPER_Array(void) { return __Array.clsSuper; }
static char *_selTransTbl[] ={
0
};
struct modDescriptor array_modDesc = {
  "array",
  "objc3.3.19",
  0L,
  0,
  0,
  &Array,
  0,
  0,
  0
};
struct modDescriptor *_OBJCBIND_array(void)
{
  selTransTbl = _selTransTbl;
  return &array_modDesc;
}
int _OBJCPOSTLINK_array = 1;


