# 1 "precxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_precxpr(void);
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
extern struct modDescriptor precxpr_modDesc;

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
# 22 "./precxpr.h"
struct PrecExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./precxpr.h"
id expr;};

# 22 "./precxpr.h"
extern id  PrecExpr;

# 22 "./precxpr.h"
extern struct _SHARED _PrecExpr;
extern struct _SHARED __PrecExpr;


# 36 "precxpr.m"
static id i_PrecExpr_expr_(struct PrecExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
expr=aRcvr;
return(id)self;
}

static int i_PrecExpr_lineno(struct PrecExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 44 "precxpr.m"
return(objcT0=self->expr,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_PrecExpr_filename(struct PrecExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 49 "precxpr.m"
return(objcT1=self->expr,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_PrecExpr_synth(struct PrecExpr_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 54 "precxpr.m"
(objcT2=self->expr,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return(id)self;
}

static id i_PrecExpr_typesynth(struct PrecExpr_PRIVATE *self,SEL _cmd)
{
id objcT3;
self->
# 60 "precxpr.m"
type=(objcT3=self->expr,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
return(id)self;
}

static id i_PrecExpr_gen(struct PrecExpr_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5,objcT6,objcT7;

# 66 "precxpr.m"
gl((objcT4=(id)self,(*(int(*)(id,SEL))_imp(objcT4,selTransTbl[0]))(objcT4,selTransTbl[0])),(objcT5=(objcT6=(id)self,(*_imp(objcT6,selTransTbl[1]))(objcT6,selTransTbl[1])),(*(STR(*)(id,SEL))_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4])));
gc('(');
(objcT7=self->expr,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5]));
gc(')');
return(id)self;
}

static id i_PrecExpr_st80(struct PrecExpr_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 75 "precxpr.m"
gc('(');
(objcT8=self->expr,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
gc(')');
return(id)self;
}

static id i_PrecExpr_go(struct PrecExpr_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 83 "precxpr.m"
return(objcT9=self->expr,(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _PrecExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _PrecExpr_nstDispatchTbl[] ={
{"expr:",(id (*)())i_PrecExpr_expr_},
{"lineno",(id (*)())i_PrecExpr_lineno},
{"filename",(id (*)())i_PrecExpr_filename},
{"synth",(id (*)())i_PrecExpr_synth},
{"typesynth",(id (*)())i_PrecExpr_typesynth},
{"gen",(id (*)())i_PrecExpr_gen},
{"st80",(id (*)())i_PrecExpr_st80},
{"go",(id (*)())i_PrecExpr_go},
{(char*)0,(id (*)())0}
};
id PrecExpr = (id)&_PrecExpr;
id  *OBJCCLASS_PrecExpr(void) { return &PrecExpr; }
struct _SHARED  _PrecExpr = {
  (id)&__PrecExpr,
  (id)&_Expr,
  "PrecExpr",
  0,
  sizeof(struct PrecExpr_PRIVATE),
  8,
  _PrecExpr_nstDispatchTbl,
  41,
  &precxpr_modDesc,
  0,
  (id)0,
  &PrecExpr,
};
id  OBJCCFUNC_PrecExpr(void) { return (id)&_PrecExpr; }
id  OBJCCSUPER_PrecExpr(void) { return _PrecExpr.clsSuper; }
struct _SHARED __PrecExpr = {
  (id)&__Object,
  (id)&__Expr,
  "PrecExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _PrecExpr_clsDispatchTbl,
  34,
  &precxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_PrecExpr(void) { return (id)&__PrecExpr; }
id  OBJCMSUPER_PrecExpr(void) { return __PrecExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"synth",
"type",
"str",
"gen",
"st80",
"go",
0
};
struct modDescriptor precxpr_modDesc = {
  "precxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &PrecExpr,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_precxpr(void)
{
  selTransTbl = _selTransTbl;
  return &precxpr_modDesc;
}
int _OBJCPOSTLINK_precxpr = 1;


