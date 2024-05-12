# 1 "bflddecl.m"
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
extern struct modDescriptor  *_OBJCBIND_bflddecl(void);
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
extern struct modDescriptor bflddecl_modDesc;

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
# 22 "./bflddecl.h"
struct BitfieldDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./bflddecl.h"
id decl,expr;};

# 22 "./bflddecl.h"
extern id  BitfieldDecl;

# 22 "./bflddecl.h"
extern struct _SHARED _BitfieldDecl;
extern struct _SHARED __BitfieldDecl;


# 36 "bflddecl.m"
static id i_BitfieldDecl_abstrdecl(struct BitfieldDecl_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 38 "bflddecl.m"
return(objcT0=self->decl,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_BitfieldDecl_decl_(struct BitfieldDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
decl=aRcvr;
return(id)self;
}

static id i_BitfieldDecl_expr_(struct BitfieldDecl_PRIVATE *self,SEL _cmd,id anExpr)
{self->
expr=anExpr;
return(id)self;
}

static id i_BitfieldDecl_identifier(struct BitfieldDecl_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 55 "bflddecl.m"
return(objcT1=self->decl,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_BitfieldDecl_gen(struct BitfieldDecl_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 60 "bflddecl.m"
(void)0;
if(self->decl)
(objcT2=self->decl,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
gc(':');
(objcT3=self->expr,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _BitfieldDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _BitfieldDecl_nstDispatchTbl[] ={
{"abstrdecl",(id (*)())i_BitfieldDecl_abstrdecl},
{"decl:",(id (*)())i_BitfieldDecl_decl_},
{"expr:",(id (*)())i_BitfieldDecl_expr_},
{"identifier",(id (*)())i_BitfieldDecl_identifier},
{"gen",(id (*)())i_BitfieldDecl_gen},
{(char*)0,(id (*)())0}
};
id BitfieldDecl = (id)&_BitfieldDecl;
id  *OBJCCLASS_BitfieldDecl(void) { return &BitfieldDecl; }
struct _SHARED  _BitfieldDecl = {
  (id)&__BitfieldDecl,
  (id)&_Decl,
  "BitfieldDecl",
  0,
  sizeof(struct BitfieldDecl_PRIVATE),
  5,
  _BitfieldDecl_nstDispatchTbl,
  41,
  &bflddecl_modDesc,
  0,
  (id)0,
  &BitfieldDecl,
};
id  OBJCCFUNC_BitfieldDecl(void) { return (id)&_BitfieldDecl; }
id  OBJCCSUPER_BitfieldDecl(void) { return _BitfieldDecl.clsSuper; }
struct _SHARED __BitfieldDecl = {
  (id)&__Object,
  (id)&__Decl,
  "BitfieldDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _BitfieldDecl_clsDispatchTbl,
  34,
  &bflddecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_BitfieldDecl(void) { return (id)&__BitfieldDecl; }
id  OBJCMSUPER_BitfieldDecl(void) { return __BitfieldDecl.clsSuper; }
static char *_selTransTbl[] ={
"abstrdecl",
"identifier",
"gen",
0
};
struct modDescriptor bflddecl_modDesc = {
  "bflddecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &BitfieldDecl,
  3,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_bflddecl(void)
{
  selTransTbl = _selTransTbl;
  return &bflddecl_modDesc;
}
int _OBJCPOSTLINK_bflddecl = 1;


