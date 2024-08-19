# 1 "switstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_switstmt(void);
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
extern struct modDescriptor switstmt_modDesc;

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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./stkframe.h"
extern id topframe;
# 22 "./switstmt.h"
struct SwitchStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./ifstmt.h"
id keyw,expr,stmt;
id ekeyw,estmt;};

# 22 "./switstmt.h"
extern id  SwitchStmt;

# 22 "./switstmt.h"
extern struct _SHARED _SwitchStmt;
extern struct _SHARED __SwitchStmt;


# 39 "switstmt.m"
static id i_SwitchStmt_st80(struct SwitchStmt_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 41 "switstmt.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
}

static id i_SwitchStmt_go(struct SwitchStmt_PRIVATE *self,SEL _cmd)
{
id objcT1,objcT2,objcT3;

# 46 "switstmt.m"
id r;
id e=(objcT1=self->expr,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
r=(objcT2=self->stmt,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],e));
(objcT3=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3],(BOOL)0));
return r;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  IfStmt;
extern struct _SHARED _IfStmt;
extern struct _SHARED __IfStmt;
static struct _SLT _SwitchStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _SwitchStmt_nstDispatchTbl[] ={
{"st80",(id (*)())i_SwitchStmt_st80},
{"go",(id (*)())i_SwitchStmt_go},
{(char*)0,(id (*)())0}
};
id SwitchStmt = (id)&_SwitchStmt;
id  *OBJCCLASS_SwitchStmt(void) { return &SwitchStmt; }
struct _SHARED  _SwitchStmt = {
  (id)&__SwitchStmt,
  (id)&_IfStmt,
  "SwitchStmt",
  0,
  sizeof(struct SwitchStmt_PRIVATE),
  2,
  _SwitchStmt_nstDispatchTbl,
  41,
  &switstmt_modDesc,
  0,
  (id)0,
  &SwitchStmt,
};
id  OBJCCFUNC_SwitchStmt(void) { return (id)&_SwitchStmt; }
id  OBJCCSUPER_SwitchStmt(void) { return _SwitchStmt.clsSuper; }
struct _SHARED __SwitchStmt = {
  (id)&__Object,
  (id)&__IfStmt,
  "SwitchStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _SwitchStmt_clsDispatchTbl,
  34,
  &switstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_SwitchStmt(void) { return (id)&__SwitchStmt; }
id  OBJCMSUPER_SwitchStmt(void) { return __SwitchStmt.clsSuper; }
static char *_selTransTbl[] ={
"notImplemented:",
"go",
"switchOn:",
"breakframe:",
0
};
struct modDescriptor switstmt_modDesc = {
  "switstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &SwitchStmt,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_switstmt(void)
{
  selTransTbl = _selTransTbl;
  return &switstmt_modDesc;
}
int _OBJCPOSTLINK_switstmt = 1;


