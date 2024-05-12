# 1 "dasmstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_dasmstmt(void);
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
extern struct modDescriptor dasmstmt_modDesc;

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
# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
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
# 22 "./dasmstmt.h"
struct DosAsmStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./dasmstmt.h"
id keyw;};

# 22 "./dasmstmt.h"
extern id  DosAsmStmt;

# 22 "./dasmstmt.h"
extern struct _SHARED _DosAsmStmt;
extern struct _SHARED __DosAsmStmt;


# 39 "dasmstmt.m"
static id c_DosAsmStmt_str_(struct DosAsmStmt_PRIVATE *self,SEL _cmd,STR s)
{
id objcT0,objcT1;

# 41 "dasmstmt.m"
return(objcT0=(objcT1=__DosAsmStmt.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0])),(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],s));
}

# 59 "./symbol.h"
extern id  Symbol;

# 44 "dasmstmt.m"
static id i_DosAsmStmt_str_(struct DosAsmStmt_PRIVATE *self,SEL _cmd,STR s)
{
id objcT2;
self->
# 46 "dasmstmt.m"
keyw=(objcT2=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1],s));
return(id)self;
}

static id i_DosAsmStmt_synth(struct DosAsmStmt_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_DosAsmStmt_gen(struct DosAsmStmt_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 57 "dasmstmt.m"
(objcT3=self->keyw,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _DosAsmStmt_clsDispatchTbl[] ={
{"str:",(id (*)())c_DosAsmStmt_str_},
{(char*)0,(id (*)())0}
};
static struct _SLT _DosAsmStmt_nstDispatchTbl[] ={
{"str:",(id (*)())i_DosAsmStmt_str_},
{"synth",(id (*)())i_DosAsmStmt_synth},
{"gen",(id (*)())i_DosAsmStmt_gen},
{(char*)0,(id (*)())0}
};
id DosAsmStmt = (id)&_DosAsmStmt;
id  *OBJCCLASS_DosAsmStmt(void) { return &DosAsmStmt; }
struct _SHARED  _DosAsmStmt = {
  (id)&__DosAsmStmt,
  (id)&_Stmt,
  "DosAsmStmt",
  0,
  sizeof(struct DosAsmStmt_PRIVATE),
  3,
  _DosAsmStmt_nstDispatchTbl,
  41,
  &dasmstmt_modDesc,
  0,
  (id)0,
  &DosAsmStmt,
};
id  OBJCCFUNC_DosAsmStmt(void) { return (id)&_DosAsmStmt; }
id  OBJCCSUPER_DosAsmStmt(void) { return _DosAsmStmt.clsSuper; }
struct _SHARED __DosAsmStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "DosAsmStmt",
  0,
  sizeof(struct _SHARED),
  1,
  _DosAsmStmt_clsDispatchTbl,
  34,
  &dasmstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_DosAsmStmt(void) { return (id)&__DosAsmStmt; }
id  OBJCMSUPER_DosAsmStmt(void) { return __DosAsmStmt.clsSuper; }
static char *_selTransTbl[] ={
"new",
"str:",
"gen",
0
};
struct modDescriptor dasmstmt_modDesc = {
  "dasmstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &DosAsmStmt,
  3,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_dasmstmt(void)
{
  selTransTbl = _selTransTbl;
  return &dasmstmt_modDesc;
}
int _OBJCPOSTLINK_dasmstmt = 1;


