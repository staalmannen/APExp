# 1 "gasmstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_gasmstmt(void);
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
extern struct modDescriptor gasmstmt_modDesc;

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
# 22 "./gasmstmt.h"
struct GnuAsmStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./gasmstmt.h"
id keyw,typequal,expr;
id asmop1,asmop2,clobbers;};

# 22 "./gasmstmt.h"
extern id  GnuAsmStmt;

# 22 "./gasmstmt.h"
extern struct _SHARED _GnuAsmStmt;
extern struct _SHARED __GnuAsmStmt;


# 37 "gasmstmt.m"
static id i_GnuAsmStmt_keyw_(struct GnuAsmStmt_PRIVATE *self,SEL _cmd,id k)
{self->
keyw=k;
return(id)self;
}

static id i_GnuAsmStmt_typequal_(struct GnuAsmStmt_PRIVATE *self,SEL _cmd,id k)
{self->
typequal=k;
return(id)self;
}

static id i_GnuAsmStmt_expr_(struct GnuAsmStmt_PRIVATE *self,SEL _cmd,id e)
{self->
expr=e;
return(id)self;
}

static id i_GnuAsmStmt_asmop1_(struct GnuAsmStmt_PRIVATE *self,SEL _cmd,id op)
{self->
asmop1=op;
return(id)self;
}

static id i_GnuAsmStmt_asmop2_(struct GnuAsmStmt_PRIVATE *self,SEL _cmd,id op)
{self->
asmop2=op;
return(id)self;
}

static id i_GnuAsmStmt_clobbers_(struct GnuAsmStmt_PRIVATE *self,SEL _cmd,id c)
{self->
clobbers=c;
return(id)self;
}

static id i_GnuAsmStmt_synth(struct GnuAsmStmt_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2;

# 75 "gasmstmt.m"
(objcT0=self->expr,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
if(self->asmop1)
(objcT1=self->asmop1,(*(id(*)(id,SEL,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],_cmd));
if(self->asmop2)
(objcT2=self->asmop2,(*(id(*)(id,SEL,SEL))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1],_cmd));
return(id)self;
}

static id i_GnuAsmStmt_gen(struct GnuAsmStmt_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4,objcT5;

# 85 "gasmstmt.m"
(objcT3=self->keyw,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
if(self->typequal)
(objcT4=self->typequal,(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2]));
gc('(');
if(self->expr)
(objcT5=self->expr,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]));
if(self->asmop1||self->asmop2||self->clobbers){
gc(':');
}
if(self->asmop1){
gcommalist(self->asmop1);
}
if(self->asmop2||self->clobbers){
gc(':');
}
if(self->asmop2){
gcommalist(self->asmop2);
}
if(self->clobbers){
gc(':');
}
if(self->clobbers){
id objcT6;

# 107 "gasmstmt.m"
int i,n;
int comma=0;

for(i=0,n=(objcT6=self->clobbers,(*(unsigned(*)(id,SEL))_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));i<n;i++){
id objcT7,objcT8;

# 111 "gasmstmt.m"
if(comma)
gc(',');
else
comma++;
(objcT7=(objcT8=self->clobbers,(*(id(*)(id,SEL,unsigned))_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4],i)),(*(id(*)(id,SEL,SEL))_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1],_cmd));
}
}
gc(')');
gc(';');
return(id)self;
}

static id i_GnuAsmStmt_st80(struct GnuAsmStmt_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 125 "gasmstmt.m"
(objcT9=self->expr,(*_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5]));
gs(".\n");
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _GnuAsmStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _GnuAsmStmt_nstDispatchTbl[] ={
{"keyw:",(id (*)())i_GnuAsmStmt_keyw_},
{"typequal:",(id (*)())i_GnuAsmStmt_typequal_},
{"expr:",(id (*)())i_GnuAsmStmt_expr_},
{"asmop1:",(id (*)())i_GnuAsmStmt_asmop1_},
{"asmop2:",(id (*)())i_GnuAsmStmt_asmop2_},
{"clobbers:",(id (*)())i_GnuAsmStmt_clobbers_},
{"synth",(id (*)())i_GnuAsmStmt_synth},
{"gen",(id (*)())i_GnuAsmStmt_gen},
{"st80",(id (*)())i_GnuAsmStmt_st80},
{(char*)0,(id (*)())0}
};
id GnuAsmStmt = (id)&_GnuAsmStmt;
id  *OBJCCLASS_GnuAsmStmt(void) { return &GnuAsmStmt; }
struct _SHARED  _GnuAsmStmt = {
  (id)&__GnuAsmStmt,
  (id)&_Stmt,
  "GnuAsmStmt",
  0,
  sizeof(struct GnuAsmStmt_PRIVATE),
  9,
  _GnuAsmStmt_nstDispatchTbl,
  41,
  &gasmstmt_modDesc,
  0,
  (id)0,
  &GnuAsmStmt,
};
id  OBJCCFUNC_GnuAsmStmt(void) { return (id)&_GnuAsmStmt; }
id  OBJCCSUPER_GnuAsmStmt(void) { return _GnuAsmStmt.clsSuper; }
struct _SHARED __GnuAsmStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "GnuAsmStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _GnuAsmStmt_clsDispatchTbl,
  34,
  &gasmstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_GnuAsmStmt(void) { return (id)&__GnuAsmStmt; }
id  OBJCMSUPER_GnuAsmStmt(void) { return __GnuAsmStmt.clsSuper; }
static char *_selTransTbl[] ={
"synth",
"elementsPerform:",
"gen",
"size",
"at:",
"st80",
0
};
struct modDescriptor gasmstmt_modDesc = {
  "gasmstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &GnuAsmStmt,
  6,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_gasmstmt(void)
{
  selTransTbl = _selTransTbl;
  return &gasmstmt_modDesc;
}
int _OBJCPOSTLINK_gasmstmt = 1;


