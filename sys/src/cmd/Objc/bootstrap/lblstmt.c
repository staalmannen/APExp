# 1 "lblstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_lblstmt(void);
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
extern struct modDescriptor lblstmt_modDesc;

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
# 22 "./lblstmt.h"
struct LabeledStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./lblstmt.h"
id label,stmt;};

# 22 "./lblstmt.h"
extern id  LabeledStmt;

# 22 "./lblstmt.h"
extern struct _SHARED _LabeledStmt;
extern struct _SHARED __LabeledStmt;


# 36 "lblstmt.m"
static id i_LabeledStmt_label_(struct LabeledStmt_PRIVATE *self,SEL _cmd,id aLabel)
{self->
label=aLabel;
return(id)self;
}

static id i_LabeledStmt_stmt_(struct LabeledStmt_PRIVATE *self,SEL _cmd,id aStmt)
{self->
stmt=aStmt;
return(id)self;
}

static id i_LabeledStmt_synth(struct LabeledStmt_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 50 "lblstmt.m"
(objcT0=self->stmt,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
return(id)self;
}

static id i_LabeledStmt_gen(struct LabeledStmt_PRIVATE *self,SEL _cmd)
{
id objcT1,objcT2;

# 56 "lblstmt.m"
(objcT1=self->label,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
gc(':');
(objcT2=self->stmt,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _LabeledStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _LabeledStmt_nstDispatchTbl[] ={
{"label:",(id (*)())i_LabeledStmt_label_},
{"stmt:",(id (*)())i_LabeledStmt_stmt_},
{"synth",(id (*)())i_LabeledStmt_synth},
{"gen",(id (*)())i_LabeledStmt_gen},
{(char*)0,(id (*)())0}
};
id LabeledStmt = (id)&_LabeledStmt;
id  *OBJCCLASS_LabeledStmt(void) { return &LabeledStmt; }
struct _SHARED  _LabeledStmt = {
  (id)&__LabeledStmt,
  (id)&_Stmt,
  "LabeledStmt",
  0,
  sizeof(struct LabeledStmt_PRIVATE),
  4,
  _LabeledStmt_nstDispatchTbl,
  41,
  &lblstmt_modDesc,
  0,
  (id)0,
  &LabeledStmt,
};
id  OBJCCFUNC_LabeledStmt(void) { return (id)&_LabeledStmt; }
id  OBJCCSUPER_LabeledStmt(void) { return _LabeledStmt.clsSuper; }
struct _SHARED __LabeledStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "LabeledStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _LabeledStmt_clsDispatchTbl,
  34,
  &lblstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_LabeledStmt(void) { return (id)&__LabeledStmt; }
id  OBJCMSUPER_LabeledStmt(void) { return __LabeledStmt.clsSuper; }
static char *_selTransTbl[] ={
"synth",
"gen",
0
};
struct modDescriptor lblstmt_modDesc = {
  "lblstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &LabeledStmt,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_lblstmt(void)
{
  selTransTbl = _selTransTbl;
  return &lblstmt_modDesc;
}
int _OBJCPOSTLINK_lblstmt = 1;


