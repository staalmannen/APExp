# 1 "condxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_condxpr(void);
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
extern struct modDescriptor condxpr_modDesc;

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
# 22 "./condxpr.h"
struct CondExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./condxpr.h"
id expr,lhs,rhs;};

# 22 "./condxpr.h"
extern id  CondExpr;

# 22 "./condxpr.h"
extern struct _SHARED _CondExpr;
extern struct _SHARED __CondExpr;


# 38 "condxpr.m"
static id i_CondExpr_expr_(struct CondExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
expr=aRcvr;
return(id)self;
}

static id i_CondExpr_lhs_(struct CondExpr_PRIVATE *self,SEL _cmd,id args)
{self->
lhs=args;
return(id)self;
}

static id i_CondExpr_rhs_(struct CondExpr_PRIVATE *self,SEL _cmd,id args)
{self->
rhs=args;
return(id)self;
}

static int i_CondExpr_lineno(struct CondExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 58 "condxpr.m"
return(objcT0=self->expr,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_CondExpr_filename(struct CondExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 63 "condxpr.m"
return(objcT1=self->expr,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_CondExpr_typesynth(struct CondExpr_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 68 "condxpr.m"
if(self->lhs)self->type=(objcT2=self->lhs,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));else self->type=(objcT3=self->rhs,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
# 74 "condxpr.m"
return(id)self;
}

static id i_CondExpr_synth(struct CondExpr_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5,objcT6;

# 79 "condxpr.m"
(objcT4=self->expr,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));
if(self->lhs)(objcT5=self->lhs,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3]));
(objcT6=self->rhs,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
return(id)self;
}

static id i_CondExpr_gen(struct CondExpr_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8,objcT9;

# 87 "condxpr.m"
(objcT7=self->expr,(*_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4]));
gc('?');
if(self->lhs)(objcT8=self->lhs,(*_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4]));
gc(':');
(objcT9=self->rhs,(*_imp(objcT9,selTransTbl[4]))(objcT9,selTransTbl[4]));
return(id)self;
}

static id i_CondExpr_st80(struct CondExpr_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11,objcT12;

# 97 "condxpr.m"
gc('(');
gc('(');
(objcT10=self->expr,(*_imp(objcT10,selTransTbl[5]))(objcT10,selTransTbl[5]));
gc(')');
gs("ifTrue:[");
if(self->lhs)(objcT11=self->lhs,(*_imp(objcT11,selTransTbl[5]))(objcT11,selTransTbl[5]));
gs("]ifFalse:[");
(objcT12=self->rhs,(*_imp(objcT12,selTransTbl[5]))(objcT12,selTransTbl[5]));
gc(']');
gc(')');
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 110 "condxpr.m"
static id i_CondExpr_go(struct CondExpr_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14,objcT15,objcT16;

# 112 "condxpr.m"
id c=(objcT13=self->expr,(*_imp(objcT13,selTransTbl[6]))(objcT13,selTransTbl[6]));
if( !(((objcT14=c,(*(BOOL(*)(id,SEL,id))_imp(objcT14,selTransTbl[7]))(objcT14,selTransTbl[7],(id)(objcT15=Scalar,(*_imp(objcT15,selTransTbl[8]))(objcT15,selTransTbl[8])))))?(objcT16=c,(*(BOOL(*)(id,SEL))_imp(objcT16,selTransTbl[9]))(objcT16,selTransTbl[9])):((c)?0:1))){
id objcT17;

# 114 "condxpr.m"
return(self->lhs)?(objcT17=self->lhs,(*_imp(objcT17,selTransTbl[6]))(objcT17,selTransTbl[6])):c;
}else{
id objcT18;

# 116 "condxpr.m"
return(objcT18=self->rhs,(*_imp(objcT18,selTransTbl[6]))(objcT18,selTransTbl[6]));
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _CondExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _CondExpr_nstDispatchTbl[] ={
{"expr:",(id (*)())i_CondExpr_expr_},
{"lhs:",(id (*)())i_CondExpr_lhs_},
{"rhs:",(id (*)())i_CondExpr_rhs_},
{"lineno",(id (*)())i_CondExpr_lineno},
{"filename",(id (*)())i_CondExpr_filename},
{"typesynth",(id (*)())i_CondExpr_typesynth},
{"synth",(id (*)())i_CondExpr_synth},
{"gen",(id (*)())i_CondExpr_gen},
{"st80",(id (*)())i_CondExpr_st80},
{"go",(id (*)())i_CondExpr_go},
{(char*)0,(id (*)())0}
};
id CondExpr = (id)&_CondExpr;
id  *OBJCCLASS_CondExpr(void) { return &CondExpr; }
struct _SHARED  _CondExpr = {
  (id)&__CondExpr,
  (id)&_Expr,
  "CondExpr",
  0,
  sizeof(struct CondExpr_PRIVATE),
  10,
  _CondExpr_nstDispatchTbl,
  41,
  &condxpr_modDesc,
  0,
  (id)0,
  &CondExpr,
};
id  OBJCCFUNC_CondExpr(void) { return (id)&_CondExpr; }
id  OBJCCSUPER_CondExpr(void) { return _CondExpr.clsSuper; }
struct _SHARED __CondExpr = {
  (id)&__Object,
  (id)&__Expr,
  "CondExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _CondExpr_clsDispatchTbl,
  34,
  &condxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_CondExpr(void) { return (id)&__CondExpr; }
id  OBJCMSUPER_CondExpr(void) { return __CondExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"type",
"synth",
"gen",
"st80",
"go",
"isKindOf:",
"class",
"isZero",
0
};
struct modDescriptor condxpr_modDesc = {
  "condxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &CondExpr,
  10,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_condxpr(void)
{
  selTransTbl = _selTransTbl;
  return &condxpr_modDesc;
}
int _OBJCPOSTLINK_condxpr = 1;


