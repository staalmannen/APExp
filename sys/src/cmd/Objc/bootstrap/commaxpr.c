# 1 "commaxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_commaxpr(void);
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
extern struct modDescriptor commaxpr_modDesc;

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
# 22 "./commaxpr.h"
struct CommaExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./commaxpr.h"
id lhs,rhs;};

# 22 "./commaxpr.h"
extern id  CommaExpr;

# 22 "./commaxpr.h"
extern struct _SHARED _CommaExpr;
extern struct _SHARED __CommaExpr;


# 36 "commaxpr.m"
static id i_CommaExpr_lhs(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
return self->lhs;
}

static id i_CommaExpr_lhs_(struct CommaExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
lhs=aRcvr;
return(id)self;
}

static id i_CommaExpr_rhs(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
return self->rhs;
}

static id i_CommaExpr_rhs_(struct CommaExpr_PRIVATE *self,SEL _cmd,id args)
{self->
rhs=args;
return(id)self;
}

static int i_CommaExpr_lineno(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 60 "commaxpr.m"
return(objcT0=self->lhs,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_CommaExpr_filename(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 65 "commaxpr.m"
return(objcT1=self->lhs,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_CommaExpr_typesynth(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3,objcT4;

# 70 "commaxpr.m"
(objcT2=self->lhs,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
(objcT3=self->rhs,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));self->
type=(objcT4=self->rhs,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));
return(id)self;
}

static id i_CommaExpr_synth(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6;

# 78 "commaxpr.m"
(objcT5=self->lhs,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));
(objcT6=self->rhs,(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
return(id)self;
}

static id i_CommaExpr_gen(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;

# 85 "commaxpr.m"
(objcT7=self->lhs,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5]));
gc(',');
(objcT8=self->rhs,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
return(id)self;
}

static id i_CommaExpr_go(struct CommaExpr_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10;

# 93 "commaxpr.m"
(objcT9=self->lhs,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));return(objcT10=self->rhs,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _CommaExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _CommaExpr_nstDispatchTbl[] ={
{"lhs",(id (*)())i_CommaExpr_lhs},
{"lhs:",(id (*)())i_CommaExpr_lhs_},
{"rhs",(id (*)())i_CommaExpr_rhs},
{"rhs:",(id (*)())i_CommaExpr_rhs_},
{"lineno",(id (*)())i_CommaExpr_lineno},
{"filename",(id (*)())i_CommaExpr_filename},
{"typesynth",(id (*)())i_CommaExpr_typesynth},
{"synth",(id (*)())i_CommaExpr_synth},
{"gen",(id (*)())i_CommaExpr_gen},
{"go",(id (*)())i_CommaExpr_go},
{(char*)0,(id (*)())0}
};
id CommaExpr = (id)&_CommaExpr;
id  *OBJCCLASS_CommaExpr(void) { return &CommaExpr; }
struct _SHARED  _CommaExpr = {
  (id)&__CommaExpr,
  (id)&_Expr,
  "CommaExpr",
  0,
  sizeof(struct CommaExpr_PRIVATE),
  10,
  _CommaExpr_nstDispatchTbl,
  41,
  &commaxpr_modDesc,
  0,
  (id)0,
  &CommaExpr,
};
id  OBJCCFUNC_CommaExpr(void) { return (id)&_CommaExpr; }
id  OBJCCSUPER_CommaExpr(void) { return _CommaExpr.clsSuper; }
struct _SHARED __CommaExpr = {
  (id)&__Object,
  (id)&__Expr,
  "CommaExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _CommaExpr_clsDispatchTbl,
  34,
  &commaxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_CommaExpr(void) { return (id)&__CommaExpr; }
id  OBJCMSUPER_CommaExpr(void) { return __CommaExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"typesynth",
"type",
"synth",
"gen",
"go",
0
};
struct modDescriptor commaxpr_modDesc = {
  "commaxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &CommaExpr,
  7,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_commaxpr(void)
{
  selTransTbl = _selTransTbl;
  return &commaxpr_modDesc;
}
int _OBJCPOSTLINK_commaxpr = 1;


