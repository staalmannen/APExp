# 1 "deref.m"
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
extern struct modDescriptor  *_OBJCBIND_deref(void);
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
extern struct modDescriptor deref_modDesc;

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
# 22 "./deref.h"
struct Dereference_PRIVATE {

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

# 22 "./deref.h"
extern id  Dereference;

# 22 "./deref.h"
extern struct _SHARED _Dereference;
extern struct _SHARED __Dereference;


# 41 "deref.m"
static id c_Dereference_new(struct Dereference_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 43 "deref.m"
return(objcT0=(objcT1=__Dereference.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0])),(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],"*"));
}

static id i_Dereference_typesynth(struct Dereference_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;
self->
# 48 "deref.m"
type=(objcT2=(objcT3=self->expr,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2])),(*_imp(objcT2,selTransTbl[3]))(objcT2,selTransTbl[3]));
return(id)self;
}

# 22 "./aryvar.h"
extern id  ArrayVariable;

# 24 "./scalar.h"
extern id  Scalar;

# 52 "deref.m"
static id i_Dereference_go(struct Dereference_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5,objcT6;

# 54 "deref.m"
id x=(objcT4=self->expr,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));

if((objcT5=x,(*(BOOL(*)(id,SEL,id))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5],(id)(objcT6=ArrayVariable,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]))))){
id objcT7;

# 57 "deref.m"
return(objcT7=x,(*(id(*)(id,SEL,unsigned))_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7],0));
}else{
id objcT8,objcT12;

# 59 "deref.m"
if((objcT8=x,(*_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2]))==t_str){
id objcT9,objcT10,objcT11;

# 60 "deref.m"
STR s=(objcT9=x,(*(char*(*)(id,SEL))_imp(objcT9,selTransTbl[8]))(objcT9,selTransTbl[8]));
return(objcT10=(objcT11=Scalar,(*_imp(objcT11,selTransTbl[0]))(objcT11,selTransTbl[0])),(*(id(*)(id,SEL,char))_imp(objcT10,selTransTbl[9]))(objcT10,selTransTbl[9], *s));
}
return(objcT12=(id)self,(*_imp(objcT12,selTransTbl[10]))(objcT12,selTransTbl[10]));
}
}

static id i_Dereference_assignvar_(struct Dereference_PRIVATE *self,SEL _cmd,id v)
{
id objcT13,objcT14,objcT15;

# 69 "deref.m"
id x=(objcT13=self->expr,(*_imp(objcT13,selTransTbl[4]))(objcT13,selTransTbl[4]));

if((objcT14=x,(*(BOOL(*)(id,SEL,id))_imp(objcT14,selTransTbl[5]))(objcT14,selTransTbl[5],(id)(objcT15=ArrayVariable,(*_imp(objcT15,selTransTbl[6]))(objcT15,selTransTbl[6]))))){
id objcT16;

# 72 "deref.m"
(objcT16=x,(*(id(*)(id,SEL,unsigned,id))_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11],0,v));
return v;
}else{
id objcT17,objcT20;

# 75 "deref.m"
if((objcT17=x,(*_imp(objcT17,selTransTbl[2]))(objcT17,selTransTbl[2]))==t_str){
id objcT18,objcT19;

# 76 "deref.m"
STR s=(objcT18=x,(*(char*(*)(id,SEL))_imp(objcT18,selTransTbl[8]))(objcT18,selTransTbl[8])); *
s=(objcT19=v,(*(char(*)(id,SEL))_imp(objcT19,selTransTbl[12]))(objcT19,selTransTbl[12]));
return v;
}
return(objcT20=(id)self,(*_imp(objcT20,selTransTbl[10]))(objcT20,selTransTbl[10]));
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  UnaryExpr;
extern struct _SHARED _UnaryExpr;
extern struct _SHARED __UnaryExpr;
static struct _SLT _Dereference_clsDispatchTbl[] ={
{"new",(id (*)())c_Dereference_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _Dereference_nstDispatchTbl[] ={
{"typesynth",(id (*)())i_Dereference_typesynth},
{"go",(id (*)())i_Dereference_go},
{"assignvar:",(id (*)())i_Dereference_assignvar_},
{(char*)0,(id (*)())0}
};
id Dereference = (id)&_Dereference;
id  *OBJCCLASS_Dereference(void) { return &Dereference; }
struct _SHARED  _Dereference = {
  (id)&__Dereference,
  (id)&_UnaryExpr,
  "Dereference",
  0,
  sizeof(struct Dereference_PRIVATE),
  3,
  _Dereference_nstDispatchTbl,
  41,
  &deref_modDesc,
  0,
  (id)0,
  &Dereference,
};
id  OBJCCFUNC_Dereference(void) { return (id)&_Dereference; }
id  OBJCCSUPER_Dereference(void) { return _Dereference.clsSuper; }
struct _SHARED __Dereference = {
  (id)&__Object,
  (id)&__UnaryExpr,
  "Dereference",
  0,
  sizeof(struct _SHARED),
  1,
  _Dereference_clsDispatchTbl,
  34,
  &deref_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Dereference(void) { return (id)&__Dereference; }
id  OBJCMSUPER_Dereference(void) { return __Dereference.clsSuper; }
static char *_selTransTbl[] ={
"new",
"op:",
"type",
"star",
"go",
"isKindOf:",
"class",
"at:",
"u_str",
"u_char:",
"notImplemented",
"at:put:",
"u_char",
0
};
struct modDescriptor deref_modDesc = {
  "deref",
  "objc3.3.19",
  0L,
  0,
  0,
  &Dereference,
  13,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_deref(void)
{
  selTransTbl = _selTransTbl;
  return &deref_modDesc;
}
int _OBJCPOSTLINK_deref = 1;


