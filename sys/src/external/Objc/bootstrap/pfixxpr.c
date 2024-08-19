# 1 "pfixxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_pfixxpr(void);
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
extern struct modDescriptor pfixxpr_modDesc;

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
# 22 "./pfixxpr.h"
struct PostfixExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./pfixxpr.h"
id expr;
STR op;};

# 22 "./pfixxpr.h"
extern id  PostfixExpr;

# 22 "./pfixxpr.h"
extern struct _SHARED _PostfixExpr;
extern struct _SHARED __PostfixExpr;


# 39 "pfixxpr.m"
static id i_PostfixExpr_op_(struct PostfixExpr_PRIVATE *self,SEL _cmd,STR anop)
{self->
op=anop;
return(id)self;
}

static id i_PostfixExpr_expr_(struct PostfixExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
expr=aRcvr;
return(id)self;
}

static int i_PostfixExpr_lineno(struct PostfixExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 53 "pfixxpr.m"
return(objcT0=self->expr,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_PostfixExpr_filename(struct PostfixExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 58 "pfixxpr.m"
return(objcT1=self->expr,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_PostfixExpr_synth(struct PostfixExpr_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 63 "pfixxpr.m"
(objcT2=self->expr,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return(id)self;
}

static id i_PostfixExpr_typesynth(struct PostfixExpr_PRIVATE *self,SEL _cmd)
{
id objcT3;
self->
# 69 "pfixxpr.m"
type=(objcT3=self->expr,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
return(id)self;
}

static id i_PostfixExpr_gen(struct PostfixExpr_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 75 "pfixxpr.m"
(objcT4=self->expr,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
gs(self->op);
return(id)self;
}

static id i_PostfixExpr_go(struct PostfixExpr_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6,objcT7,objcT8,objcT9;
id objcT10;

# 82 "pfixxpr.m"
id v,w;
v=(objcT5=self->expr,(*_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]));
w=(objcT6=v,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]));
if(strcmp(self->op,"++")==0)(objcT7=w,(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7]));
else if(strcmp(self->op,"--")==0)(objcT8=w,(*_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8]));
else(objcT9=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9],_cmd));
(objcT10=self->expr,(*_imp(objcT10,selTransTbl[10]))(objcT10,selTransTbl[10],w));
return v;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _PostfixExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _PostfixExpr_nstDispatchTbl[] ={
{"op:",(id (*)())i_PostfixExpr_op_},
{"expr:",(id (*)())i_PostfixExpr_expr_},
{"lineno",(id (*)())i_PostfixExpr_lineno},
{"filename",(id (*)())i_PostfixExpr_filename},
{"synth",(id (*)())i_PostfixExpr_synth},
{"typesynth",(id (*)())i_PostfixExpr_typesynth},
{"gen",(id (*)())i_PostfixExpr_gen},
{"go",(id (*)())i_PostfixExpr_go},
{(char*)0,(id (*)())0}
};
id PostfixExpr = (id)&_PostfixExpr;
id  *OBJCCLASS_PostfixExpr(void) { return &PostfixExpr; }
struct _SHARED  _PostfixExpr = {
  (id)&__PostfixExpr,
  (id)&_Expr,
  "PostfixExpr",
  0,
  sizeof(struct PostfixExpr_PRIVATE),
  8,
  _PostfixExpr_nstDispatchTbl,
  41,
  &pfixxpr_modDesc,
  0,
  (id)0,
  &PostfixExpr,
};
id  OBJCCFUNC_PostfixExpr(void) { return (id)&_PostfixExpr; }
id  OBJCCSUPER_PostfixExpr(void) { return _PostfixExpr.clsSuper; }
struct _SHARED __PostfixExpr = {
  (id)&__Object,
  (id)&__Expr,
  "PostfixExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _PostfixExpr_clsDispatchTbl,
  34,
  &pfixxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_PostfixExpr(void) { return (id)&__PostfixExpr; }
id  OBJCMSUPER_PostfixExpr(void) { return __PostfixExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"synth",
"type",
"gen",
"go",
"copy",
"increment",
"decrement",
"notImplemented:",
"assignvar:",
0
};
struct modDescriptor pfixxpr_modDesc = {
  "pfixxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &PostfixExpr,
  11,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_pfixxpr(void)
{
  selTransTbl = _selTransTbl;
  return &pfixxpr_modDesc;
}
int _OBJCPOSTLINK_pfixxpr = 1;


