# 1 "stclass.m"
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
extern struct modDescriptor  *_OBJCBIND_stclass(void);
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
extern struct modDescriptor stclass_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//string.h"
#include <string.h>

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

# 32 "./../../include/objpak/ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 22 "./symbol.h"
extern id s_void;
extern id s_char;
extern id s_bool;
extern id s_int;
extern id s_uns;
extern id s_long;
extern id s_double;
extern id s_str;
extern id s_sel;
extern id s_newblock;
extern id s_main;
extern id s_objcmain;
extern id s_id;
extern id s_nil;
extern id s_self;
extern id s_cmd;
extern id s_super;
extern id s_type;
extern id s_aFiler;
extern id s_fileIn;
extern id s_fileOut;
extern id s_fileInIdsFrom;
extern id s_fileOutIdsFor;
extern id s_returnval;
extern id s_returnflag;
extern id s_increfs;
extern id s_decrefs;
extern id s_idincref;
extern id s_iddecref;

BOOL istypeword(id sym);
BOOL isbuiltinfun(id sym);
int pragmatoggle(char*s);
void definebuiltintype(char*s);
void definebuiltinfun(char*s);
void definebuiltinvar(char*s);
# 22 "./stclass.h"
struct Storageclass_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./../../include/objpak/array.h"
unsigned capacity;
# 42 "./../../include/objpak/ocstring.h"
struct objstr value;
# 61 "./symbol.h"
int lineno;
id filename;
id type;};

# 22 "./stclass.h"
extern id  Storageclass;

# 22 "./stclass.h"
extern struct _SHARED _Storageclass;
extern struct _SHARED __Storageclass;


# 37 "stclass.m"
static id c_Storageclass_str_lineno_filename_(struct Storageclass_PRIVATE *self,SEL _cmd,char*s,int no,id fn)
{
id objcT0,objcT1;

# 39 "stclass.m"
return(objcT0=(objcT1=__Storageclass.clsSuper,(*(id(*)(id,SEL,STR))_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0],s)),(*(id(*)(id,SEL,int,id))_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],no,fn));
}

static BOOL i_Storageclass_isstorageclass(struct Storageclass_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Symbol;
extern struct _SHARED _Symbol;
extern struct _SHARED __Symbol;
static struct _SLT _Storageclass_clsDispatchTbl[] ={
{"str:lineno:filename:",(id (*)())c_Storageclass_str_lineno_filename_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Storageclass_nstDispatchTbl[] ={
{"isstorageclass",(id (*)())i_Storageclass_isstorageclass},
{(char*)0,(id (*)())0}
};
id Storageclass = (id)&_Storageclass;
id  *OBJCCLASS_Storageclass(void) { return &Storageclass; }
struct _SHARED  _Storageclass = {
  (id)&__Storageclass,
  (id)&_Symbol,
  "Storageclass",
  0,
  sizeof(struct Storageclass_PRIVATE),
  1,
  _Storageclass_nstDispatchTbl,
  41,
  &stclass_modDesc,
  0,
  (id)0,
  &Storageclass,
};
id  OBJCCFUNC_Storageclass(void) { return (id)&_Storageclass; }
id  OBJCCSUPER_Storageclass(void) { return _Storageclass.clsSuper; }
struct _SHARED __Storageclass = {
  (id)&__Object,
  (id)&__Symbol,
  "Storageclass",
  0,
  sizeof(struct _SHARED),
  1,
  _Storageclass_clsDispatchTbl,
  34,
  &stclass_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Storageclass(void) { return (id)&__Storageclass; }
id  OBJCMSUPER_Storageclass(void) { return __Storageclass.clsSuper; }
static char *_selTransTbl[] ={
"str:",
"lineno:filename:",
0
};
struct modDescriptor stclass_modDesc = {
  "stclass",
  "objc3.3.19",
  0L,
  0,
  0,
  &Storageclass,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_stclass(void)
{
  selTransTbl = _selTransTbl;
  return &stclass_modDesc;
}
int _OBJCPOSTLINK_stclass = 1;


