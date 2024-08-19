# 1 "castxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_castxpr(void);
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
extern struct modDescriptor castxpr_modDesc;

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
# 22 "./castxpr.h"
struct CastExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./castxpr.h"
id cast,expr;};

# 22 "./castxpr.h"
extern id  CastExpr;

# 22 "./castxpr.h"
extern struct _SHARED _CastExpr;
extern struct _SHARED __CastExpr;


# 36 "castxpr.m"
static id i_CastExpr_expr_(struct CastExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
expr=aRcvr;
return(id)self;
}

static int i_CastExpr_lineno(struct CastExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 44 "castxpr.m"
return(objcT0=self->cast,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_CastExpr_filename(struct CastExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 49 "castxpr.m"
return(objcT1=self->cast,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static BOOL i_CastExpr_isconstexpr(struct CastExpr_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 54 "castxpr.m"
return(objcT2=self->expr,(*(BOOL(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
}

static id i_CastExpr_cast_(struct CastExpr_PRIVATE *self,SEL _cmd,id args)
{self->
cast=args;
return(id)self;
}

static id i_CastExpr_typesynth(struct CastExpr_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 65 "castxpr.m"
(objcT3=self->expr,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));self->
type=self->cast;
return(id)self;
}

static id i_CastExpr_synth(struct CastExpr_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 72 "castxpr.m"
(objcT4=self->expr,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
return(id)self;
}

static id i_CastExpr_gen(struct CastExpr_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6,objcT7,objcT8,objcT9;

# 78 "castxpr.m"
gl((objcT5=(id)self,(*(int(*)(id,SEL))_imp(objcT5,selTransTbl[0]))(objcT5,selTransTbl[0])),(objcT6=(objcT7=(id)self,(*_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1])),(*(STR(*)(id,SEL))_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5])));
gc('(');
(objcT8=self->cast,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
gc(')');
(objcT9=self->expr,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
return(id)self;
}

static id i_CastExpr_go(struct CastExpr_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 88 "castxpr.m"
return(objcT10=self->expr,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _CastExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _CastExpr_nstDispatchTbl[] ={
{"expr:",(id (*)())i_CastExpr_expr_},
{"lineno",(id (*)())i_CastExpr_lineno},
{"filename",(id (*)())i_CastExpr_filename},
{"isconstexpr",(id (*)())i_CastExpr_isconstexpr},
{"cast:",(id (*)())i_CastExpr_cast_},
{"typesynth",(id (*)())i_CastExpr_typesynth},
{"synth",(id (*)())i_CastExpr_synth},
{"gen",(id (*)())i_CastExpr_gen},
{"go",(id (*)())i_CastExpr_go},
{(char*)0,(id (*)())0}
};
id CastExpr = (id)&_CastExpr;
id  *OBJCCLASS_CastExpr(void) { return &CastExpr; }
struct _SHARED  _CastExpr = {
  (id)&__CastExpr,
  (id)&_Expr,
  "CastExpr",
  0,
  sizeof(struct CastExpr_PRIVATE),
  9,
  _CastExpr_nstDispatchTbl,
  41,
  &castxpr_modDesc,
  0,
  (id)0,
  &CastExpr,
};
id  OBJCCFUNC_CastExpr(void) { return (id)&_CastExpr; }
id  OBJCCSUPER_CastExpr(void) { return _CastExpr.clsSuper; }
struct _SHARED __CastExpr = {
  (id)&__Object,
  (id)&__Expr,
  "CastExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _CastExpr_clsDispatchTbl,
  34,
  &castxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_CastExpr(void) { return (id)&__CastExpr; }
id  OBJCMSUPER_CastExpr(void) { return __CastExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"isconstexpr",
"typesynth",
"synth",
"str",
"gen",
"go",
0
};
struct modDescriptor castxpr_modDesc = {
  "castxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &CastExpr,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_castxpr(void)
{
  selTransTbl = _selTransTbl;
  return &castxpr_modDesc;
}
int _OBJCPOSTLINK_castxpr = 1;


