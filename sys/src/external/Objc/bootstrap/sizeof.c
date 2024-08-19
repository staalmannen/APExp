# 1 "sizeof.m"
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
extern struct modDescriptor  *_OBJCBIND_sizeof(void);
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
extern struct modDescriptor sizeof_modDesc;

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
# 22 "./sizeof.h"
struct SizeOf_PRIVATE {

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

# 22 "./sizeof.h"
extern id  SizeOf;

# 22 "./sizeof.h"
extern struct _SHARED _SizeOf;
extern struct _SHARED __SizeOf;


# 38 "sizeof.m"
static id c_SizeOf_new(struct SizeOf_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 40 "sizeof.m"
return(objcT0=(objcT1=__SizeOf.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0])),(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],"sizeof"));
}

static id i_SizeOf_typesynth(struct SizeOf_PRIVATE *self,SEL _cmd)
{self->
type=t_int;
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  UnaryExpr;
extern struct _SHARED _UnaryExpr;
extern struct _SHARED __UnaryExpr;
static struct _SLT _SizeOf_clsDispatchTbl[] ={
{"new",(id (*)())c_SizeOf_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _SizeOf_nstDispatchTbl[] ={
{"typesynth",(id (*)())i_SizeOf_typesynth},
{(char*)0,(id (*)())0}
};
id SizeOf = (id)&_SizeOf;
id  *OBJCCLASS_SizeOf(void) { return &SizeOf; }
struct _SHARED  _SizeOf = {
  (id)&__SizeOf,
  (id)&_UnaryExpr,
  "SizeOf",
  0,
  sizeof(struct SizeOf_PRIVATE),
  1,
  _SizeOf_nstDispatchTbl,
  41,
  &sizeof_modDesc,
  0,
  (id)0,
  &SizeOf,
};
id  OBJCCFUNC_SizeOf(void) { return (id)&_SizeOf; }
id  OBJCCSUPER_SizeOf(void) { return _SizeOf.clsSuper; }
struct _SHARED __SizeOf = {
  (id)&__Object,
  (id)&__UnaryExpr,
  "SizeOf",
  0,
  sizeof(struct _SHARED),
  1,
  _SizeOf_clsDispatchTbl,
  34,
  &sizeof_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_SizeOf(void) { return (id)&__SizeOf; }
id  OBJCMSUPER_SizeOf(void) { return __SizeOf.clsSuper; }
static char *_selTransTbl[] ={
"new",
"op:",
0
};
struct modDescriptor sizeof_modDesc = {
  "sizeof",
  "objc3.3.19",
  0L,
  0,
  0,
  &SizeOf,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_sizeof(void)
{
  selTransTbl = _selTransTbl;
  return &sizeof_modDesc;
}
int _OBJCPOSTLINK_sizeof = 1;


