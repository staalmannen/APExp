# 1 "dotxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_dotxpr(void);
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
extern struct modDescriptor dotxpr_modDesc;

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

# 32 "./../../include/objpak/ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
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
# 22 "./symbol.h"
extern id s_void;
extern id s_char;
extern id s_bool;
extern id s_int;
extern id s_uns;
extern id s_long;
extern id s_double;
extern id s_str;
extern id s_sel;
extern id s_newblock;
extern id s_main;
extern id s_objcmain;
extern id s_id;
extern id s_nil;
extern id s_self;
extern id s_cmd;
extern id s_super;
extern id s_type;
extern id s_aFiler;
extern id s_fileIn;
extern id s_fileOut;
extern id s_fileInIdsFrom;
extern id s_fileOutIdsFor;
extern id s_returnval;
extern id s_returnflag;
extern id s_increfs;
extern id s_decrefs;
extern id s_idincref;
extern id s_iddecref;

BOOL istypeword(id sym);
BOOL isbuiltinfun(id sym);
int pragmatoggle(char*s);
void definebuiltintype(char*s);
void definebuiltinfun(char*s);
void definebuiltinvar(char*s);
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
# 22 "./dotxpr.h"
struct DotExpr_PRIVATE {

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

# 22 "./dotxpr.h"
extern id  DotExpr;

# 22 "./dotxpr.h"
extern struct _SHARED _DotExpr;
extern struct _SHARED __DotExpr;


# 40 "dotxpr.m"
static id c_DotExpr_new(struct DotExpr_PRIVATE *self,SEL _cmd){
id objcT0,objcT1;

# 41 "dotxpr.m"
return(objcT0=(objcT1=__DotExpr.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0])),(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],"."));
}

static id i_DotExpr_typesynth(struct DotExpr_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3,objcT4;

# 46 "dotxpr.m"
(void)0;self->
type=(objcT2=self->lhs,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));self->
type=(objcT3=self->type,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3],self->rhs));
if( !self->type)
fatalat(self->rhs,"structure has no field '%s'",(objcT4=self->rhs,(*(STR(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4])));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  BinaryExpr;
extern struct _SHARED _BinaryExpr;
extern struct _SHARED __BinaryExpr;
static struct _SLT _DotExpr_clsDispatchTbl[] ={
{"new",(id (*)())c_DotExpr_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _DotExpr_nstDispatchTbl[] ={
{"typesynth",(id (*)())i_DotExpr_typesynth},
{(char*)0,(id (*)())0}
};
id DotExpr = (id)&_DotExpr;
id  *OBJCCLASS_DotExpr(void) { return &DotExpr; }
struct _SHARED  _DotExpr = {
  (id)&__DotExpr,
  (id)&_BinaryExpr,
  "DotExpr",
  0,
  sizeof(struct DotExpr_PRIVATE),
  1,
  _DotExpr_nstDispatchTbl,
  41,
  &dotxpr_modDesc,
  0,
  (id)0,
  &DotExpr,
};
id  OBJCCFUNC_DotExpr(void) { return (id)&_DotExpr; }
id  OBJCCSUPER_DotExpr(void) { return _DotExpr.clsSuper; }
struct _SHARED __DotExpr = {
  (id)&__Object,
  (id)&__BinaryExpr,
  "DotExpr",
  0,
  sizeof(struct _SHARED),
  1,
  _DotExpr_clsDispatchTbl,
  34,
  &dotxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_DotExpr(void) { return (id)&__DotExpr; }
id  OBJCMSUPER_DotExpr(void) { return __DotExpr.clsSuper; }
static char *_selTransTbl[] ={
"new",
"op:",
"type",
"dot:",
"str",
0
};
struct modDescriptor dotxpr_modDesc = {
  "dotxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &DotExpr,
  5,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_dotxpr(void)
{
  selTransTbl = _selTransTbl;
  return &dotxpr_modDesc;
}
int _OBJCPOSTLINK_dotxpr = 1;


