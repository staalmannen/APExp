# 1 "gotostmt.m"
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
extern struct modDescriptor  *_OBJCBIND_gotostmt(void);
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
extern struct modDescriptor gotostmt_modDesc;

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
# 22 "./gotostmt.h"
struct GotoStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./gotostmt.h"
id label,keyw;};

# 22 "./gotostmt.h"
extern id  GotoStmt;

# 22 "./gotostmt.h"
extern struct _SHARED _GotoStmt;
extern struct _SHARED __GotoStmt;


# 36 "gotostmt.m"
static id i_GotoStmt_label_(struct GotoStmt_PRIVATE *self,SEL _cmd,id aLabel)
{self->
label=aLabel;
return(id)self;
}

static id i_GotoStmt_keyw_(struct GotoStmt_PRIVATE *self,SEL _cmd,id aKeyw)
{self->
keyw=aKeyw;
return(id)self;
}

static id i_GotoStmt_synth(struct GotoStmt_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_GotoStmt_gen(struct GotoStmt_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 55 "gotostmt.m"
(objcT0=self->keyw,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
gc(' ');
(objcT1=self->label,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
gc(';');
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _GotoStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _GotoStmt_nstDispatchTbl[] ={
{"label:",(id (*)())i_GotoStmt_label_},
{"keyw:",(id (*)())i_GotoStmt_keyw_},
{"synth",(id (*)())i_GotoStmt_synth},
{"gen",(id (*)())i_GotoStmt_gen},
{(char*)0,(id (*)())0}
};
id GotoStmt = (id)&_GotoStmt;
id  *OBJCCLASS_GotoStmt(void) { return &GotoStmt; }
struct _SHARED  _GotoStmt = {
  (id)&__GotoStmt,
  (id)&_Stmt,
  "GotoStmt",
  0,
  sizeof(struct GotoStmt_PRIVATE),
  4,
  _GotoStmt_nstDispatchTbl,
  41,
  &gotostmt_modDesc,
  0,
  (id)0,
  &GotoStmt,
};
id  OBJCCFUNC_GotoStmt(void) { return (id)&_GotoStmt; }
id  OBJCCSUPER_GotoStmt(void) { return _GotoStmt.clsSuper; }
struct _SHARED __GotoStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "GotoStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _GotoStmt_clsDispatchTbl,
  34,
  &gotostmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_GotoStmt(void) { return (id)&__GotoStmt; }
id  OBJCMSUPER_GotoStmt(void) { return __GotoStmt.clsSuper; }
static char *_selTransTbl[] ={
"gen",
0
};
struct modDescriptor gotostmt_modDesc = {
  "gotostmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &GotoStmt,
  1,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_gotostmt(void)
{
  selTransTbl = _selTransTbl;
  return &gotostmt_modDesc;
}
int _OBJCPOSTLINK_gotostmt = 1;


