# 1 "relxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_relxpr(void);
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
extern struct modDescriptor relxpr_modDesc;

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
# 22 "./relxpr.h"
struct RelationExpr_PRIVATE {

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

# 22 "./relxpr.h"
extern id  RelationExpr;

# 22 "./relxpr.h"
extern struct _SHARED _RelationExpr;
extern struct _SHARED __RelationExpr;


# 40 "relxpr.m"
static id i_RelationExpr_typesynth(struct RelationExpr_PRIVATE *self,SEL _cmd)
{self->
type=t_int;
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 46 "relxpr.m"
static id i_RelationExpr_go(struct RelationExpr_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2,objcT3,objcT4;
id objcT6,objcT7,objcT9,objcT10;

# 48 "relxpr.m"
id a,b,r;
int s=0;
int av,bv;
a=(objcT0=self->lhs,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
b=(objcT1=self->rhs,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
r=(objcT2=Scalar,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
if((objcT3=a,(*(BOOL(*)(id,SEL,id))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],(id)(objcT4=Scalar,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]))))){
id objcT5;

# 55 "relxpr.m"
av=(objcT5=a,(*(int(*)(id,SEL))_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));
}else{
av=(a)?1:0;
}
if((objcT6=b,(*(BOOL(*)(id,SEL,id))_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2],(id)(objcT7=Scalar,(*_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3]))))){
id objcT8;

# 60 "relxpr.m"
bv=(objcT8=b,(*(int(*)(id,SEL))_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4]));
}else{
bv=(b)?1:0;
}
if(strcmp(self->op,"<")==0)s=av<bv;
else if(strcmp(self->op,">")==0)s=av>bv;
else if(strcmp(self->op,"==")==0)s=av==bv;
else if(strcmp(self->op,"!=")==0)s=av!=bv;
else if(strcmp(self->op,">=")==0)s=av>=bv;
else if(strcmp(self->op,"<=")==0)s=av<=bv;
else(objcT9=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5],_cmd));
return(objcT10=r,(*(id(*)(id,SEL,int))_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6],s));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  BinaryExpr;
extern struct _SHARED _BinaryExpr;
extern struct _SHARED __BinaryExpr;
static struct _SLT _RelationExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _RelationExpr_nstDispatchTbl[] ={
{"typesynth",(id (*)())i_RelationExpr_typesynth},
{"go",(id (*)())i_RelationExpr_go},
{(char*)0,(id (*)())0}
};
id RelationExpr = (id)&_RelationExpr;
id  *OBJCCLASS_RelationExpr(void) { return &RelationExpr; }
struct _SHARED  _RelationExpr = {
  (id)&__RelationExpr,
  (id)&_BinaryExpr,
  "RelationExpr",
  0,
  sizeof(struct RelationExpr_PRIVATE),
  2,
  _RelationExpr_nstDispatchTbl,
  41,
  &relxpr_modDesc,
  0,
  (id)0,
  &RelationExpr,
};
id  OBJCCFUNC_RelationExpr(void) { return (id)&_RelationExpr; }
id  OBJCCSUPER_RelationExpr(void) { return _RelationExpr.clsSuper; }
struct _SHARED __RelationExpr = {
  (id)&__Object,
  (id)&__BinaryExpr,
  "RelationExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _RelationExpr_clsDispatchTbl,
  34,
  &relxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_RelationExpr(void) { return (id)&__RelationExpr; }
id  OBJCMSUPER_RelationExpr(void) { return __RelationExpr.clsSuper; }
static char *_selTransTbl[] ={
"go",
"new",
"isKindOf:",
"class",
"u_int",
"notImplemented:",
"u_int:",
0
};
struct modDescriptor relxpr_modDesc = {
  "relxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &RelationExpr,
  7,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_relxpr(void)
{
  selTransTbl = _selTransTbl;
  return &relxpr_modDesc;
}
int _OBJCPOSTLINK_relxpr = 1;


