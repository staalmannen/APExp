# 1 "listxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_listxpr(void);
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
extern struct modDescriptor listxpr_modDesc;

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

# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
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
# 22 "./listxpr.h"
struct ListExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./listxpr.h"
id lbrace;
id exprs;
id rbrace;};

# 22 "./listxpr.h"
extern id  ListExpr;

# 22 "./listxpr.h"
extern struct _SHARED _ListExpr;
extern struct _SHARED __ListExpr;


# 37 "listxpr.m"
static id i_ListExpr_lbrace_(struct ListExpr_PRIVATE *self,SEL _cmd,id lb)
{self->
lbrace=lb;
return(id)self;
}

static id i_ListExpr_rbrace_(struct ListExpr_PRIVATE *self,SEL _cmd,id rb)
{self->
rbrace=rb;
return(id)self;
}

static id i_ListExpr_exprs_(struct ListExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
exprs=aRcvr;
return(id)self;
}

static id i_ListExpr_synth(struct ListExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 57 "listxpr.m"
(objcT0=self->exprs,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
return(id)self;
}

static BOOL i_ListExpr_isconstexpr(struct ListExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 63 "listxpr.m"
int i,n;

for(i=0,n=(objcT1=self->exprs,(*(unsigned(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));i<n;i++){
id objcT2,objcT3;

# 66 "listxpr.m"
if( !(objcT2=(objcT3=self->exprs,(*(id(*)(id,SEL,unsigned))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],i)),(*(BOOL(*)(id,SEL))_imp(objcT2,selTransTbl[3]))(objcT2,selTransTbl[3])))
return(BOOL)0;
}
return(BOOL)1;
}

static id i_ListExpr_gen(struct ListExpr_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;

# 74 "listxpr.m"
if(self->lbrace)
(objcT4=self->lbrace,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
else
gc('{');
gcommalist(self->exprs);
if(self->rbrace)
(objcT5=self->rbrace,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));
else
gc('}');
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _ListExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ListExpr_nstDispatchTbl[] ={
{"lbrace:",(id (*)())i_ListExpr_lbrace_},
{"rbrace:",(id (*)())i_ListExpr_rbrace_},
{"exprs:",(id (*)())i_ListExpr_exprs_},
{"synth",(id (*)())i_ListExpr_synth},
{"isconstexpr",(id (*)())i_ListExpr_isconstexpr},
{"gen",(id (*)())i_ListExpr_gen},
{(char*)0,(id (*)())0}
};
id ListExpr = (id)&_ListExpr;
id  *OBJCCLASS_ListExpr(void) { return &ListExpr; }
struct _SHARED  _ListExpr = {
  (id)&__ListExpr,
  (id)&_Expr,
  "ListExpr",
  0,
  sizeof(struct ListExpr_PRIVATE),
  6,
  _ListExpr_nstDispatchTbl,
  41,
  &listxpr_modDesc,
  0,
  (id)0,
  &ListExpr,
};
id  OBJCCFUNC_ListExpr(void) { return (id)&_ListExpr; }
id  OBJCCSUPER_ListExpr(void) { return _ListExpr.clsSuper; }
struct _SHARED __ListExpr = {
  (id)&__Object,
  (id)&__Expr,
  "ListExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _ListExpr_clsDispatchTbl,
  34,
  &listxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ListExpr(void) { return (id)&__ListExpr; }
id  OBJCMSUPER_ListExpr(void) { return __ListExpr.clsSuper; }
static char *_selTransTbl[] ={
"elementsPerform:",
"size",
"at:",
"isconstexpr",
"gen",
0
};
struct modDescriptor listxpr_modDesc = {
  "listxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &ListExpr,
  5,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_listxpr(void)
{
  selTransTbl = _selTransTbl;
  return &listxpr_modDesc;
}
int _OBJCPOSTLINK_listxpr = 1;


