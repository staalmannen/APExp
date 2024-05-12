# 1 "binxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_binxpr(void);
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
extern struct modDescriptor binxpr_modDesc;

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
# 22 "./binxpr.h"
struct BinaryExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./binxpr.h"
STR op;
id lhs,rhs;};

# 22 "./binxpr.h"
extern id  BinaryExpr;

# 22 "./binxpr.h"
extern struct _SHARED _BinaryExpr;
extern struct _SHARED __BinaryExpr;


# 39 "binxpr.m"
static id i_BinaryExpr_rhs_(struct BinaryExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
rhs=aRcvr;
return(id)self;
}

static id i_BinaryExpr_op_(struct BinaryExpr_PRIVATE *self,SEL _cmd,STR anop)
{self->
op=anop;
return(id)self;
}

static id i_BinaryExpr_lhs_(struct BinaryExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
lhs=aRcvr;
return(id)self;
}

static BOOL i_BinaryExpr_isconstexpr(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 59 "binxpr.m"
return(objcT0=self->lhs,(*(BOOL(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]))&&(objcT1=self->rhs,(*(BOOL(*)(id,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
}

static int i_BinaryExpr_lineno(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 64 "binxpr.m"
return(objcT2=self->lhs,(*(int(*)(id,SEL))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
}

static id i_BinaryExpr_filename(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 69 "binxpr.m"
return(objcT3=self->lhs,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
}

static id i_BinaryExpr_typesynth(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5,objcT6;
self->
# 74 "binxpr.m"
type=(objcT4=(objcT5=self->lhs,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3])),(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4],(objcT6=self->rhs,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]))));
return(id)self;
}

static id i_BinaryExpr_synth(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;

# 80 "binxpr.m"
(objcT7=self->lhs,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5]));
(objcT8=self->rhs,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
return(id)self;
}

static id i_BinaryExpr_gen(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10;

# 87 "binxpr.m"
(objcT9=self->lhs,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
gs(self->op);
(objcT10=self->rhs,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
return(id)self;
}

static id i_BinaryExpr_st80(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT11,objcT12;

# 95 "binxpr.m"
(objcT11=self->lhs,(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7]));
gs(self->op);
(objcT12=self->rhs,(*_imp(objcT12,selTransTbl[7]))(objcT12,selTransTbl[7]));
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 101 "binxpr.m"
static id i_BinaryExpr_go(struct BinaryExpr_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14,objcT15,objcT16,objcT17;
id objcT18,objcT19,objcT20,objcT21,objcT22;
id objcT23,objcT24,objcT25,objcT26,objcT27;
id objcT28,objcT29,objcT30,objcT31,objcT32;
id objcT33,objcT34,objcT35,objcT36,objcT37;

# 103 "binxpr.m"
id a,b,r;
int s=0;
a=(objcT13=self->lhs,(*_imp(objcT13,selTransTbl[8]))(objcT13,selTransTbl[8]));
b=(objcT14=self->rhs,(*_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8]));
r=(objcT15=Scalar,(*_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9]));
if(strcmp(self->op,"*")==0)s=(objcT16=a,(*(int(*)(id,SEL))_imp(objcT16,selTransTbl[10]))(objcT16,selTransTbl[10]))*(objcT17=b,(*(int(*)(id,SEL))_imp(objcT17,selTransTbl[10]))(objcT17,selTransTbl[10]));
else if(strcmp(self->op,"/")==0)s=(objcT18=a,(*(int(*)(id,SEL))_imp(objcT18,selTransTbl[10]))(objcT18,selTransTbl[10]))/(objcT19=b,(*(int(*)(id,SEL))_imp(objcT19,selTransTbl[10]))(objcT19,selTransTbl[10]));
else if(strcmp(self->op,"%")==0)s=(objcT20=a,(*(int(*)(id,SEL))_imp(objcT20,selTransTbl[10]))(objcT20,selTransTbl[10]))%(objcT21=b,(*(int(*)(id,SEL))_imp(objcT21,selTransTbl[10]))(objcT21,selTransTbl[10]));
else if(strcmp(self->op,"+")==0)s=(objcT22=a,(*(int(*)(id,SEL))_imp(objcT22,selTransTbl[10]))(objcT22,selTransTbl[10]))+(objcT23=b,(*(int(*)(id,SEL))_imp(objcT23,selTransTbl[10]))(objcT23,selTransTbl[10]));
else if(strcmp(self->op,"-")==0)s=(objcT24=a,(*(int(*)(id,SEL))_imp(objcT24,selTransTbl[10]))(objcT24,selTransTbl[10]))-(objcT25=b,(*(int(*)(id,SEL))_imp(objcT25,selTransTbl[10]))(objcT25,selTransTbl[10]));
else if(strcmp(self->op,"|")==0)s=(objcT26=a,(*(int(*)(id,SEL))_imp(objcT26,selTransTbl[10]))(objcT26,selTransTbl[10]))|(objcT27=b,(*(int(*)(id,SEL))_imp(objcT27,selTransTbl[10]))(objcT27,selTransTbl[10]));
else if(strcmp(self->op,"||")==0)s=(objcT28=a,(*(int(*)(id,SEL))_imp(objcT28,selTransTbl[10]))(objcT28,selTransTbl[10]))||(objcT29=b,(*(int(*)(id,SEL))_imp(objcT29,selTransTbl[10]))(objcT29,selTransTbl[10]));
else if(strcmp(self->op,"&")==0)s=(objcT30=a,(*(int(*)(id,SEL))_imp(objcT30,selTransTbl[10]))(objcT30,selTransTbl[10]))||(objcT31=b,(*(int(*)(id,SEL))_imp(objcT31,selTransTbl[10]))(objcT31,selTransTbl[10]));
else if(strcmp(self->op,"&&")==0)s=(objcT32=a,(*(int(*)(id,SEL))_imp(objcT32,selTransTbl[10]))(objcT32,selTransTbl[10]))||(objcT33=b,(*(int(*)(id,SEL))_imp(objcT33,selTransTbl[10]))(objcT33,selTransTbl[10]));
else if(strcmp(self->op,"^")==0)s=(objcT34=a,(*(int(*)(id,SEL))_imp(objcT34,selTransTbl[10]))(objcT34,selTransTbl[10]))^(objcT35=b,(*(int(*)(id,SEL))_imp(objcT35,selTransTbl[10]))(objcT35,selTransTbl[10]));
else(objcT36=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT36,selTransTbl[11]))(objcT36,selTransTbl[11],_cmd));
return(objcT37=r,(*(id(*)(id,SEL,int))_imp(objcT37,selTransTbl[12]))(objcT37,selTransTbl[12],s));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _BinaryExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _BinaryExpr_nstDispatchTbl[] ={
{"rhs:",(id (*)())i_BinaryExpr_rhs_},
{"op:",(id (*)())i_BinaryExpr_op_},
{"lhs:",(id (*)())i_BinaryExpr_lhs_},
{"isconstexpr",(id (*)())i_BinaryExpr_isconstexpr},
{"lineno",(id (*)())i_BinaryExpr_lineno},
{"filename",(id (*)())i_BinaryExpr_filename},
{"typesynth",(id (*)())i_BinaryExpr_typesynth},
{"synth",(id (*)())i_BinaryExpr_synth},
{"gen",(id (*)())i_BinaryExpr_gen},
{"st80",(id (*)())i_BinaryExpr_st80},
{"go",(id (*)())i_BinaryExpr_go},
{(char*)0,(id (*)())0}
};
id BinaryExpr = (id)&_BinaryExpr;
id  *OBJCCLASS_BinaryExpr(void) { return &BinaryExpr; }
struct _SHARED  _BinaryExpr = {
  (id)&__BinaryExpr,
  (id)&_Expr,
  "BinaryExpr",
  0,
  sizeof(struct BinaryExpr_PRIVATE),
  11,
  _BinaryExpr_nstDispatchTbl,
  41,
  &binxpr_modDesc,
  0,
  (id)0,
  &BinaryExpr,
};
id  OBJCCFUNC_BinaryExpr(void) { return (id)&_BinaryExpr; }
id  OBJCCSUPER_BinaryExpr(void) { return _BinaryExpr.clsSuper; }
struct _SHARED __BinaryExpr = {
  (id)&__Object,
  (id)&__Expr,
  "BinaryExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _BinaryExpr_clsDispatchTbl,
  34,
  &binxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_BinaryExpr(void) { return (id)&__BinaryExpr; }
id  OBJCMSUPER_BinaryExpr(void) { return __BinaryExpr.clsSuper; }
static char *_selTransTbl[] ={
"isconstexpr",
"lineno",
"filename",
"type",
"max:",
"synth",
"gen",
"st80",
"go",
"new",
"u_int",
"notImplemented:",
"u_int:",
0
};
struct modDescriptor binxpr_modDesc = {
  "binxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &BinaryExpr,
  13,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_binxpr(void)
{
  selTransTbl = _selTransTbl;
  return &binxpr_modDesc;
}
int _OBJCPOSTLINK_binxpr = 1;


