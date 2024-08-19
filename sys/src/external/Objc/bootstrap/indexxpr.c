# 1 "indexxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_indexxpr(void);
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
extern struct modDescriptor indexxpr_modDesc;

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
# 22 "./indexxpr.h"
struct IndexExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./indexxpr.h"
id lhs,rhs;};

# 22 "./indexxpr.h"
extern id  IndexExpr;

# 22 "./indexxpr.h"
extern struct _SHARED _IndexExpr;
extern struct _SHARED __IndexExpr;


# 40 "indexxpr.m"
static id i_IndexExpr_lhs_(struct IndexExpr_PRIVATE *self,SEL _cmd,id e){self->
lhs=e;
return(id)self;
}
static id i_IndexExpr_rhs_(struct IndexExpr_PRIVATE *self,SEL _cmd,id e){self->
rhs=e;
return(id)self;
}

static int i_IndexExpr_lineno(struct IndexExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 51 "indexxpr.m"
return(objcT0=self->lhs,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_IndexExpr_filename(struct IndexExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 56 "indexxpr.m"
return(objcT1=self->lhs,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_IndexExpr_synth(struct IndexExpr_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 61 "indexxpr.m"
(objcT2=self->lhs,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
(objcT3=self->rhs,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
return(id)self;
}

static id i_IndexExpr_typesynth(struct IndexExpr_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;
self->
# 68 "indexxpr.m"
type=(objcT4=(objcT5=self->lhs,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3])),(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
return(id)self;
}

static id i_IndexExpr_gen(struct IndexExpr_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7;

# 74 "indexxpr.m"
(objcT6=self->lhs,(*_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5]));
gc('[');
(objcT7=self->rhs,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5]));
gc(']');
return(id)self;
}

# 22 "./aryvar.h"
extern id  ArrayVariable;

# 24 "./scalar.h"
extern id  Scalar;

# 81 "indexxpr.m"
static id i_IndexExpr_go(struct IndexExpr_PRIVATE *self,SEL _cmd)
{
id objcT8,objcT9,objcT10,objcT11;

# 83 "indexxpr.m"
id a=(objcT8=self->lhs,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
id b=(objcT9=self->rhs,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));

if((objcT10=a,(*(BOOL(*)(id,SEL,id))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7],(id)(objcT11=ArrayVariable,(*_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8]))))){
id objcT12,objcT13;

# 87 "indexxpr.m"
int i=(objcT12=b,(*(int(*)(id,SEL))_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9]));
return(objcT13=a,(*(id(*)(id,SEL,unsigned))_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10],i));
}else{
id objcT14,objcT15,objcT19;

# 90 "indexxpr.m"
int i=(objcT14=b,(*(int(*)(id,SEL))_imp(objcT14,selTransTbl[9]))(objcT14,selTransTbl[9]));
if((objcT15=a,(*_imp(objcT15,selTransTbl[3]))(objcT15,selTransTbl[3]))==t_str){
id objcT16,objcT17,objcT18;

# 92 "indexxpr.m"
STR s=(objcT16=a,(*(char*(*)(id,SEL))_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11]));
return(objcT17=(objcT18=Scalar,(*_imp(objcT18,selTransTbl[12]))(objcT18,selTransTbl[12])),(*(id(*)(id,SEL,char))_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13],s[i]));
}
return(objcT19=(id)self,(*_imp(objcT19,selTransTbl[14]))(objcT19,selTransTbl[14]));
}
}

static id i_IndexExpr_assignvar_(struct IndexExpr_PRIVATE *self,SEL _cmd,id v)
{
id objcT20,objcT21,objcT22,objcT23;

# 101 "indexxpr.m"
id a=(objcT20=self->lhs,(*_imp(objcT20,selTransTbl[6]))(objcT20,selTransTbl[6]));
id b=(objcT21=self->rhs,(*_imp(objcT21,selTransTbl[6]))(objcT21,selTransTbl[6]));

if((objcT22=a,(*(BOOL(*)(id,SEL,id))_imp(objcT22,selTransTbl[7]))(objcT22,selTransTbl[7],(id)(objcT23=ArrayVariable,(*_imp(objcT23,selTransTbl[8]))(objcT23,selTransTbl[8]))))){
id objcT24,objcT25;

# 105 "indexxpr.m"
int i=(objcT24=b,(*(int(*)(id,SEL))_imp(objcT24,selTransTbl[9]))(objcT24,selTransTbl[9]));
(objcT25=a,(*(id(*)(id,SEL,unsigned,id))_imp(objcT25,selTransTbl[15]))(objcT25,selTransTbl[15],i,v));
return v;
}else{
id objcT26,objcT27,objcT30;

# 109 "indexxpr.m"
int i=(objcT26=b,(*(int(*)(id,SEL))_imp(objcT26,selTransTbl[9]))(objcT26,selTransTbl[9]));
if((objcT27=a,(*_imp(objcT27,selTransTbl[3]))(objcT27,selTransTbl[3]))==t_str){
id objcT28,objcT29;

# 111 "indexxpr.m"
STR s=(objcT28=a,(*(char*(*)(id,SEL))_imp(objcT28,selTransTbl[11]))(objcT28,selTransTbl[11]));
s[i]=(objcT29=v,(*(char(*)(id,SEL))_imp(objcT29,selTransTbl[16]))(objcT29,selTransTbl[16]));
return v;
}
return(objcT30=(id)self,(*_imp(objcT30,selTransTbl[14]))(objcT30,selTransTbl[14]));
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _IndexExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _IndexExpr_nstDispatchTbl[] ={
{"lhs:",(id (*)())i_IndexExpr_lhs_},
{"rhs:",(id (*)())i_IndexExpr_rhs_},
{"lineno",(id (*)())i_IndexExpr_lineno},
{"filename",(id (*)())i_IndexExpr_filename},
{"synth",(id (*)())i_IndexExpr_synth},
{"typesynth",(id (*)())i_IndexExpr_typesynth},
{"gen",(id (*)())i_IndexExpr_gen},
{"go",(id (*)())i_IndexExpr_go},
{"assignvar:",(id (*)())i_IndexExpr_assignvar_},
{(char*)0,(id (*)())0}
};
id IndexExpr = (id)&_IndexExpr;
id  *OBJCCLASS_IndexExpr(void) { return &IndexExpr; }
struct _SHARED  _IndexExpr = {
  (id)&__IndexExpr,
  (id)&_Expr,
  "IndexExpr",
  0,
  sizeof(struct IndexExpr_PRIVATE),
  9,
  _IndexExpr_nstDispatchTbl,
  41,
  &indexxpr_modDesc,
  0,
  (id)0,
  &IndexExpr,
};
id  OBJCCFUNC_IndexExpr(void) { return (id)&_IndexExpr; }
id  OBJCCSUPER_IndexExpr(void) { return _IndexExpr.clsSuper; }
struct _SHARED __IndexExpr = {
  (id)&__Object,
  (id)&__Expr,
  "IndexExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _IndexExpr_clsDispatchTbl,
  34,
  &indexxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_IndexExpr(void) { return (id)&__IndexExpr; }
id  OBJCMSUPER_IndexExpr(void) { return __IndexExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"synth",
"type",
"star",
"gen",
"go",
"isKindOf:",
"class",
"u_int",
"at:",
"u_str",
"new",
"u_char:",
"notImplemented",
"at:put:",
"u_char",
0
};
struct modDescriptor indexxpr_modDesc = {
  "indexxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &IndexExpr,
  17,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_indexxpr(void)
{
  selTransTbl = _selTransTbl;
  return &indexxpr_modDesc;
}
int _OBJCPOSTLINK_indexxpr = 1;


