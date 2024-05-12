# 1 "unyxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_unyxpr(void);
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
extern struct modDescriptor unyxpr_modDesc;

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
# 22 "./unyxpr.h"
struct UnaryExpr_PRIVATE {

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

# 22 "./unyxpr.h"
extern id  UnaryExpr;

# 22 "./unyxpr.h"
extern struct _SHARED _UnaryExpr;
extern struct _SHARED __UnaryExpr;


# 39 "unyxpr.m"
static id i_UnaryExpr_op_(struct UnaryExpr_PRIVATE *self,SEL _cmd,STR anop)
{self->
op=anop;
return(id)self;
}

static id i_UnaryExpr_expr_(struct UnaryExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
expr=aRcvr;
return(id)self;
}

static int i_UnaryExpr_lineno(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 53 "unyxpr.m"
return(objcT0=self->expr,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_UnaryExpr_filename(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 58 "unyxpr.m"
return(objcT1=self->expr,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_UnaryExpr_typesynth(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT2;
self->
# 63 "unyxpr.m"
type=(objcT2=self->expr,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return(id)self;
}

static id i_UnaryExpr_synth(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 69 "unyxpr.m"
(objcT3=self->expr,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
return(id)self;
}

static id i_UnaryExpr_gen(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 75 "unyxpr.m"
gc(' ');
gs(self->op);
(objcT4=self->expr,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
return(id)self;
}

static BOOL i_UnaryExpr_isconstexpr(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 83 "unyxpr.m"
return(objcT5=self->expr,(*(BOOL(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]));
}

static id i_UnaryExpr_st80(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 88 "unyxpr.m"
gc('(');
gs(self->op);
(objcT6=self->expr,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]));
gc(')');
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 95 "unyxpr.m"
static id i_UnaryExpr_go(struct UnaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8,objcT9,objcT11,objcT12;
id objcT13;

# 97 "unyxpr.m"
id a,r;
int s=0;
a=(objcT7=self->expr,(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7]));
if((objcT8=a,(*(BOOL(*)(id,SEL,id))_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8],(id)(objcT9=Scalar,(*_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9]))))){
id objcT10;

# 101 "unyxpr.m"
s=(objcT10=a,(*(int(*)(id,SEL))_imp(objcT10,selTransTbl[10]))(objcT10,selTransTbl[10]));
}else{
s=(a)?1:0;
}
r=(objcT11=Scalar,(*_imp(objcT11,selTransTbl[11]))(objcT11,selTransTbl[11]));
if(strcmp(self->op,"-")==0)s= -s;
else if(strcmp(self->op,"+")==0)s= +s;
else if(strcmp(self->op,"!")==0)s= !s;
else(objcT12=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT12,selTransTbl[12]))(objcT12,selTransTbl[12],_cmd));
return(objcT13=r,(*(id(*)(id,SEL,int))_imp(objcT13,selTransTbl[13]))(objcT13,selTransTbl[13],s));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _UnaryExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _UnaryExpr_nstDispatchTbl[] ={
{"op:",(id (*)())i_UnaryExpr_op_},
{"expr:",(id (*)())i_UnaryExpr_expr_},
{"lineno",(id (*)())i_UnaryExpr_lineno},
{"filename",(id (*)())i_UnaryExpr_filename},
{"typesynth",(id (*)())i_UnaryExpr_typesynth},
{"synth",(id (*)())i_UnaryExpr_synth},
{"gen",(id (*)())i_UnaryExpr_gen},
{"isconstexpr",(id (*)())i_UnaryExpr_isconstexpr},
{"st80",(id (*)())i_UnaryExpr_st80},
{"go",(id (*)())i_UnaryExpr_go},
{(char*)0,(id (*)())0}
};
id UnaryExpr = (id)&_UnaryExpr;
id  *OBJCCLASS_UnaryExpr(void) { return &UnaryExpr; }
struct _SHARED  _UnaryExpr = {
  (id)&__UnaryExpr,
  (id)&_Expr,
  "UnaryExpr",
  0,
  sizeof(struct UnaryExpr_PRIVATE),
  10,
  _UnaryExpr_nstDispatchTbl,
  41,
  &unyxpr_modDesc,
  0,
  (id)0,
  &UnaryExpr,
};
id  OBJCCFUNC_UnaryExpr(void) { return (id)&_UnaryExpr; }
id  OBJCCSUPER_UnaryExpr(void) { return _UnaryExpr.clsSuper; }
struct _SHARED __UnaryExpr = {
  (id)&__Object,
  (id)&__Expr,
  "UnaryExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _UnaryExpr_clsDispatchTbl,
  34,
  &unyxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_UnaryExpr(void) { return (id)&__UnaryExpr; }
id  OBJCMSUPER_UnaryExpr(void) { return __UnaryExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"type",
"synth",
"gen",
"isconstexpr",
"st80",
"go",
"isKindOf:",
"class",
"u_int",
"new",
"notImplemented:",
"u_int:",
0
};
struct modDescriptor unyxpr_modDesc = {
  "unyxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &UnaryExpr,
  14,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_unyxpr(void)
{
  selTransTbl = _selTransTbl;
  return &unyxpr_modDesc;
}
int _OBJCPOSTLINK_unyxpr = 1;


