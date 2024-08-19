# 1 "contstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_contstmt(void);
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
extern struct modDescriptor contstmt_modDesc;

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
# 22 "./stkframe.h"
extern id topframe;
# 22 "./contstmt.h"
struct ContinueStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./contstmt.h"
id keyw;};

# 22 "./contstmt.h"
extern id  ContinueStmt;

# 22 "./contstmt.h"
extern struct _SHARED _ContinueStmt;
extern struct _SHARED __ContinueStmt;


# 37 "contstmt.m"
static id i_ContinueStmt_keyw_(struct ContinueStmt_PRIVATE *self,SEL _cmd,id aKeyw)
{self->
keyw=aKeyw;
return(id)self;
}

static id i_ContinueStmt_synth(struct ContinueStmt_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_ContinueStmt_gen(struct ContinueStmt_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 50 "contstmt.m"
(objcT0=self->keyw,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
gc(';');
return(id)self;
}

static id i_ContinueStmt_st80(struct ContinueStmt_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 57 "contstmt.m"
gs((objcT1=self->keyw,(*(STR(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1])));
gs(".\n");
return(id)self;
}

static id i_ContinueStmt_go(struct ContinueStmt_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3,objcT4,objcT5,objcT6;

# 64 "contstmt.m"
if(strcmp((objcT2=self->keyw,(*(STR(*)(id,SEL))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1])),"break")==0)(objcT3=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],(BOOL)1));
else if(strcmp((objcT4=self->keyw,(*(STR(*)(id,SEL))_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1])),"continue")==0)(objcT5=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],(BOOL)1));
else(objcT6=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4],_cmd));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _ContinueStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ContinueStmt_nstDispatchTbl[] ={
{"keyw:",(id (*)())i_ContinueStmt_keyw_},
{"synth",(id (*)())i_ContinueStmt_synth},
{"gen",(id (*)())i_ContinueStmt_gen},
{"st80",(id (*)())i_ContinueStmt_st80},
{"go",(id (*)())i_ContinueStmt_go},
{(char*)0,(id (*)())0}
};
id ContinueStmt = (id)&_ContinueStmt;
id  *OBJCCLASS_ContinueStmt(void) { return &ContinueStmt; }
struct _SHARED  _ContinueStmt = {
  (id)&__ContinueStmt,
  (id)&_Stmt,
  "ContinueStmt",
  0,
  sizeof(struct ContinueStmt_PRIVATE),
  5,
  _ContinueStmt_nstDispatchTbl,
  41,
  &contstmt_modDesc,
  0,
  (id)0,
  &ContinueStmt,
};
id  OBJCCFUNC_ContinueStmt(void) { return (id)&_ContinueStmt; }
id  OBJCCSUPER_ContinueStmt(void) { return _ContinueStmt.clsSuper; }
struct _SHARED __ContinueStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "ContinueStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _ContinueStmt_clsDispatchTbl,
  34,
  &contstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ContinueStmt(void) { return (id)&__ContinueStmt; }
id  OBJCMSUPER_ContinueStmt(void) { return __ContinueStmt.clsSuper; }
static char *_selTransTbl[] ={
"gen",
"str",
"breakframe:",
"contframe:",
"notImplemented:",
0
};
struct modDescriptor contstmt_modDesc = {
  "contstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &ContinueStmt,
  5,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_contstmt(void)
{
  selTransTbl = _selTransTbl;
  return &contstmt_modDesc;
}
int _OBJCPOSTLINK_contstmt = 1;


