# 1 "arydecl.m"
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
extern struct modDescriptor  *_OBJCBIND_arydecl(void);
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
extern struct modDescriptor arydecl_modDesc;

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
# 22 "./arydecl.h"
struct ArrayDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./arydecl.h"
id decl,expr;};

# 22 "./arydecl.h"
extern id  ArrayDecl;

# 22 "./arydecl.h"
extern struct _SHARED _ArrayDecl;
extern struct _SHARED __ArrayDecl;


# 36 "arydecl.m"
static id i_ArrayDecl_decl(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
return self->decl;
}

static id i_ArrayDecl_expr(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
return self->expr;
}

static id i_ArrayDecl_decl_(struct ArrayDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
decl=aRcvr;
return(id)self;
}

static id i_ArrayDecl_star(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
if(self->decl){
id objcT0,objcT1,objcT2;

# 55 "arydecl.m"
return(objcT0=(objcT1=(id)self,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0])),(*_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],(objcT2=self->decl,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]))));
}else{
return(id)0;
}
}

static id i_ArrayDecl_abstrdecl(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
if(self->decl){
id objcT3,objcT4,objcT5;

# 64 "arydecl.m"
id x=(objcT3=self->decl,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));

return(objcT4=(objcT5=(id)self,(*_imp(objcT5,selTransTbl[0]))(objcT5,selTransTbl[0])),(*_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1],x));
}else{
return(id)self;
}
}

static unsigned i_ArrayDecl_hash(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7;

# 74 "arydecl.m"
unsigned h=0;

if(self->decl)
h^=(objcT6=self->decl,(*(unsigned(*)(id,SEL))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
if(self->expr)
h^=(objcT7=self->expr,(*(unsigned(*)(id,SEL))_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4]));
return h;
}

static BOOL i_ArrayDecl_isEqual_(struct ArrayDecl_PRIVATE *self,SEL _cmd,id x)
{
id objcT8,objcT9,objcT10,objcT11;

# 85 "arydecl.m"
id a,b;

if((id)self==x)
return(BOOL)1;
a=(objcT8=x,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
if(self->decl&&a&& !(objcT9=self->decl,(*(BOOL(*)(id,SEL,id))_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6],a)))
return(BOOL)0;
if(( !self->decl|| !a)&&(self->decl!=a))
return(BOOL)0;
b=(objcT10=x,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
if(self->expr&&b&& !(objcT11=self->expr,(*(BOOL(*)(id,SEL,id))_imp(objcT11,selTransTbl[6]))(objcT11,selTransTbl[6],b)))
return(BOOL)0;
if(( !self->expr|| !b)&&(self->expr!=b))
return(BOOL)0;
return(BOOL)1;
}

static id i_ArrayDecl_identifier(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
id objcT12;

# 104 "arydecl.m"
return(self->decl)?(objcT12=self->decl,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8])):(id)0;
}

static BOOL i_ArrayDecl_isfunproto(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 109 "arydecl.m"
return(self->decl)?(objcT13=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT13,selTransTbl[9]))(objcT13,selTransTbl[9])):(BOOL)0;
}

static id i_ArrayDecl_expr_(struct ArrayDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
expr=aRcvr;
return(id)self;
}

static id i_ArrayDecl_gendef_(struct ArrayDecl_PRIVATE *self,SEL _cmd,id sym)
{
id objcT16;

# 120 "arydecl.m"
if(self->decl){
id objcT14;

# 121 "arydecl.m"
(objcT14=self->decl,(*_imp(objcT14,selTransTbl[10]))(objcT14,selTransTbl[10],sym));
}else{
id objcT15;

# 123 "arydecl.m"
if(sym)
(objcT15=sym,(*_imp(objcT15,selTransTbl[11]))(objcT15,selTransTbl[11]));
}
gc('[');
if(self->expr)
(objcT16=self->expr,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11]));
gc(']');
return(id)self;
}

static id i_ArrayDecl_gen(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
id objcT17,objcT18;

# 135 "arydecl.m"
if(self->decl)
(objcT17=self->decl,(*_imp(objcT17,selTransTbl[11]))(objcT17,selTransTbl[11]));
gc('[');
if(self->expr)
(objcT18=self->expr,(*_imp(objcT18,selTransTbl[11]))(objcT18,selTransTbl[11]));
gc(']');
return(id)self;
}

static id i_ArrayDecl_st80(struct ArrayDecl_PRIVATE *self,SEL _cmd)
{
id objcT19;

# 146 "arydecl.m"
if(self->decl)
(objcT19=self->decl,(*_imp(objcT19,selTransTbl[12]))(objcT19,selTransTbl[12]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _ArrayDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ArrayDecl_nstDispatchTbl[] ={
{"decl",(id (*)())i_ArrayDecl_decl},
{"expr",(id (*)())i_ArrayDecl_expr},
{"decl:",(id (*)())i_ArrayDecl_decl_},
{"star",(id (*)())i_ArrayDecl_star},
{"abstrdecl",(id (*)())i_ArrayDecl_abstrdecl},
{"hash",(id (*)())i_ArrayDecl_hash},
{"isEqual:",(id (*)())i_ArrayDecl_isEqual_},
{"identifier",(id (*)())i_ArrayDecl_identifier},
{"isfunproto",(id (*)())i_ArrayDecl_isfunproto},
{"expr:",(id (*)())i_ArrayDecl_expr_},
{"gendef:",(id (*)())i_ArrayDecl_gendef_},
{"gen",(id (*)())i_ArrayDecl_gen},
{"st80",(id (*)())i_ArrayDecl_st80},
{(char*)0,(id (*)())0}
};
id ArrayDecl = (id)&_ArrayDecl;
id  *OBJCCLASS_ArrayDecl(void) { return &ArrayDecl; }
struct _SHARED  _ArrayDecl = {
  (id)&__ArrayDecl,
  (id)&_Decl,
  "ArrayDecl",
  0,
  sizeof(struct ArrayDecl_PRIVATE),
  13,
  _ArrayDecl_nstDispatchTbl,
  41,
  &arydecl_modDesc,
  0,
  (id)0,
  &ArrayDecl,
};
id  OBJCCFUNC_ArrayDecl(void) { return (id)&_ArrayDecl; }
id  OBJCCSUPER_ArrayDecl(void) { return _ArrayDecl.clsSuper; }
struct _SHARED __ArrayDecl = {
  (id)&__Object,
  (id)&__Decl,
  "ArrayDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _ArrayDecl_clsDispatchTbl,
  34,
  &arydecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ArrayDecl(void) { return (id)&__ArrayDecl; }
id  OBJCMSUPER_ArrayDecl(void) { return __ArrayDecl.clsSuper; }
static char *_selTransTbl[] ={
"copy",
"decl:",
"star",
"abstrdecl",
"hash",
"decl",
"isEqual:",
"expr",
"identifier",
"isfunproto",
"gendef:",
"gen",
"st80",
0
};
struct modDescriptor arydecl_modDesc = {
  "arydecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &ArrayDecl,
  13,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_arydecl(void)
{
  selTransTbl = _selTransTbl;
  return &arydecl_modDesc;
}
int _OBJCPOSTLINK_arydecl = 1;


