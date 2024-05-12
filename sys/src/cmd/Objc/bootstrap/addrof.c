# 1 "addrof.m"
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
extern struct modDescriptor  *_OBJCBIND_addrof(void);
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
extern struct modDescriptor addrof_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

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

# 22 "./node.h"
extern FILE*gfile;
extern int inlineno;
extern id infilename;
extern int outlineno;
extern char*outfilename;
extern int exitstatus;
extern id loadedmodules;

void gc(char c);
void gextc(void);
void gcom(char*cm);
void gvarlist(id c,char*sp,char*iz);
void gcommalist(id c);
void gs(char*str);
void gf(char*fmt,...);
void gl(int no,char*fn);
void g_otbvars(void);
void gstderr(void);
void gnormal(void);
char*browsepath(char*filename);

void warn(char*fmt,...);
void warnat(id sym,char*fmt,...);
void fatal(char*fmt,...);
void fatalat(id sym,char*fmt,...);
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./type.h"
extern id t_unknown;
extern id t_void;
extern id t_char;
extern id t_bool;
extern id t_int;
extern id t_long;
extern id t_uns;
extern id t_double;
extern id t_str;
extern id t_sel;
extern id t_id;
# 22 "./addrof.h"
struct AddressOf_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./unyxpr.h"
STR op;
id expr;};

# 22 "./addrof.h"
extern id  AddressOf;

# 22 "./addrof.h"
extern struct _SHARED _AddressOf;
extern struct _SHARED __AddressOf;


# 38 "addrof.m"
static id c_AddressOf_new(struct AddressOf_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 40 "addrof.m"
return(objcT0=(objcT1=__AddressOf.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0])),(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],"&"));
}

static id i_AddressOf_typesynth(struct AddressOf_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 45 "addrof.m"
id t=(objcT2=self->expr,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));self->

type=(objcT3=t,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  UnaryExpr;
extern struct _SHARED _UnaryExpr;
extern struct _SHARED __UnaryExpr;
static struct _SLT _AddressOf_clsDispatchTbl[] ={
{"new",(id (*)())c_AddressOf_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _AddressOf_nstDispatchTbl[] ={
{"typesynth",(id (*)())i_AddressOf_typesynth},
{(char*)0,(id (*)())0}
};
id AddressOf = (id)&_AddressOf;
id  *OBJCCLASS_AddressOf(void) { return &AddressOf; }
struct _SHARED  _AddressOf = {
  (id)&__AddressOf,
  (id)&_UnaryExpr,
  "AddressOf",
  0,
  sizeof(struct AddressOf_PRIVATE),
  1,
  _AddressOf_nstDispatchTbl,
  41,
  &addrof_modDesc,
  0,
  (id)0,
  &AddressOf,
};
id  OBJCCFUNC_AddressOf(void) { return (id)&_AddressOf; }
id  OBJCCSUPER_AddressOf(void) { return _AddressOf.clsSuper; }
struct _SHARED __AddressOf = {
  (id)&__Object,
  (id)&__UnaryExpr,
  "AddressOf",
  0,
  sizeof(struct _SHARED),
  1,
  _AddressOf_clsDispatchTbl,
  34,
  &addrof_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_AddressOf(void) { return (id)&__AddressOf; }
id  OBJCMSUPER_AddressOf(void) { return __AddressOf.clsSuper; }
static char *_selTransTbl[] ={
"new",
"op:",
"type",
"ampersand",
0
};
struct modDescriptor addrof_modDesc = {
  "addrof",
  "objc3.3.19",
  0L,
  0,
  0,
  &AddressOf,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_addrof(void)
{
  selTransTbl = _selTransTbl;
  return &addrof_modDesc;
}
int _OBJCPOSTLINK_addrof = 1;


