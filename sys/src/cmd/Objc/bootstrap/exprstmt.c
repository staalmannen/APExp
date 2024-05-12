# 1 "exprstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_exprstmt(void);
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
extern struct modDescriptor exprstmt_modDesc;

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
# 22 "./exprstmt.h"
struct ExprStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./exprstmt.h"
id expr;
BOOL forcenewline;};

# 22 "./exprstmt.h"
extern id  ExprStmt;

# 22 "./exprstmt.h"
extern struct _SHARED _ExprStmt;
extern struct _SHARED __ExprStmt;


# 36 "exprstmt.m"
static id i_ExprStmt_expr_(struct ExprStmt_PRIVATE *self,SEL _cmd,id anExpr)
{self->
expr=anExpr;
return(id)self;
}

static id i_ExprStmt_forcenewline_(struct ExprStmt_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
forcenewline=flag;
return(id)self;
}

static id i_ExprStmt_synth(struct ExprStmt_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 50 "exprstmt.m"
(objcT0=self->expr,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
return(id)self;
}

static id i_ExprStmt_gen(struct ExprStmt_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 56 "exprstmt.m"
if(self->expr)
(objcT1=self->expr,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
gc(';');
if(self->forcenewline)gc('\n');
return(id)self;
}

static id i_ExprStmt_go(struct ExprStmt_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 65 "exprstmt.m"
(objcT2=self->expr,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return(id)self;
}

static id i_ExprStmt_st80(struct ExprStmt_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 71 "exprstmt.m"
(objcT3=self->expr,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
gs(".\n");
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _ExprStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ExprStmt_nstDispatchTbl[] ={
{"expr:",(id (*)())i_ExprStmt_expr_},
{"forcenewline:",(id (*)())i_ExprStmt_forcenewline_},
{"synth",(id (*)())i_ExprStmt_synth},
{"gen",(id (*)())i_ExprStmt_gen},
{"go",(id (*)())i_ExprStmt_go},
{"st80",(id (*)())i_ExprStmt_st80},
{(char*)0,(id (*)())0}
};
id ExprStmt = (id)&_ExprStmt;
id  *OBJCCLASS_ExprStmt(void) { return &ExprStmt; }
struct _SHARED  _ExprStmt = {
  (id)&__ExprStmt,
  (id)&_Stmt,
  "ExprStmt",
  0,
  sizeof(struct ExprStmt_PRIVATE),
  6,
  _ExprStmt_nstDispatchTbl,
  41,
  &exprstmt_modDesc,
  0,
  (id)0,
  &ExprStmt,
};
id  OBJCCFUNC_ExprStmt(void) { return (id)&_ExprStmt; }
id  OBJCCSUPER_ExprStmt(void) { return _ExprStmt.clsSuper; }
struct _SHARED __ExprStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "ExprStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _ExprStmt_clsDispatchTbl,
  34,
  &exprstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ExprStmt(void) { return (id)&__ExprStmt; }
id  OBJCMSUPER_ExprStmt(void) { return __ExprStmt.clsSuper; }
static char *_selTransTbl[] ={
"synth",
"gen",
"go",
"st80",
0
};
struct modDescriptor exprstmt_modDesc = {
  "exprstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &ExprStmt,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_exprstmt(void)
{
  selTransTbl = _selTransTbl;
  return &exprstmt_modDesc;
}
int _OBJCPOSTLINK_exprstmt = 1;


