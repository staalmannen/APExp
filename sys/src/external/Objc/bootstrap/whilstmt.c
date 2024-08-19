# 1 "whilstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_whilstmt(void);
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
extern struct modDescriptor whilstmt_modDesc;

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
# 22 "./options.h"
void defoptions(void);

extern int o_warnings;
extern int o_gnu;
extern int o_darwin;
extern int o_m64;
extern int o_sunstudio;
extern int o_hpux;
extern int o_vms;
extern int o_refcnt;
extern int o_ppi;
extern int o_watcom;
extern int o_ibmvac;
extern int o_msdos;
extern int o_enableasm;
extern int o_nolinetags;
extern int o_buffered;
extern int o_quiet;
extern int o_outputcode;
extern int o_version;
extern int o_otb;
extern int o_llkeyw;
extern int o_comments;
extern int o_duptypedefs;
extern int o_seltranslation;
extern int o_categories;
extern int o_blocks;
extern int o_fwd;
extern int o_selptr;
extern int o_cache;
extern int o_filer;
extern int o_selfassign;
extern char*o_bind;
extern char*o_browsedir;
extern int o_refbind;
extern int o_inlinecache;
extern int o_cplus;
extern int o_gencode;
extern int o_st80;
extern int o_selfassign;
extern int o_nilrcvr;
extern int o_shareddata;
extern int o_oneperfile;
extern int o_cvars;
extern int o_warnlex;
extern int o_warnfwd;
extern int o_warnsuggest;
extern int o_warnintvar;
extern int o_warnclasstype;
extern int o_warntypeconflict;
extern int o_warnundefined;
extern int o_warnlocalnst;
extern int o_warnnotfound;
extern int o_warnmissingmethods;
extern int o_attrcommon;
extern int o_postlink;
extern char*o_infile;
extern char*o_outfile;
extern char*o_srcfilename;
extern char*o_initcall;
extern char*o_tagformat;
extern char*o_mainfun;
extern char*o_pathsep;
extern int o_debuginfo;
extern int o_checkbind;
extern int o_linemax;
extern int o_structassign;
extern id o_stepbreak;
extern int o_stepnext;
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./stkframe.h"
extern id topframe;
# 22 "./whilstmt.h"
struct WhileStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./ifstmt.h"
id keyw,expr,stmt;
id ekeyw,estmt;};

# 22 "./whilstmt.h"
extern id  WhileStmt;

# 22 "./whilstmt.h"
extern struct _SHARED _WhileStmt;
extern struct _SHARED __WhileStmt;


# 42 "whilstmt.m"
static id i_WhileStmt_synth(struct WhileStmt_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 44 "whilstmt.m"
if(o_refcnt)
curloopcompound=self->stmt;
(objcT0=self->expr,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
curloopcompound=(id)0;
(objcT1=self->stmt,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
return(id)self;
}

static id i_WhileStmt_st80(struct WhileStmt_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 54 "whilstmt.m"
gc('[');
(objcT2=self->expr,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
gc(']');
gs("whileTrue:[");
(objcT3=self->stmt,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1]));
gc(']');
gs(".\n");
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 65 "whilstmt.m"
static id i_WhileStmt_go(struct WhileStmt_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5,objcT6,objcT7,objcT11;

# 67 "whilstmt.m"
id e;
while(e=(objcT4=self->expr,(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2])), !(((objcT5=e,(*(BOOL(*)(id,SEL,id))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],(id)(objcT6=Scalar,(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4])))))?(objcT7=e,(*(BOOL(*)(id,SEL))_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5])):((e)?0:1))){
id objcT8,objcT9,objcT10;

# 69 "whilstmt.m"
(objcT8=self->stmt,(*_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2]));
if((objcT9=topframe,(*(BOOL(*)(id,SEL))_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6])))break;
(objcT10=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7],(BOOL)0));
}
(objcT11=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8],(BOOL)0));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  IfStmt;
extern struct _SHARED _IfStmt;
extern struct _SHARED __IfStmt;
static struct _SLT _WhileStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _WhileStmt_nstDispatchTbl[] ={
{"synth",(id (*)())i_WhileStmt_synth},
{"st80",(id (*)())i_WhileStmt_st80},
{"go",(id (*)())i_WhileStmt_go},
{(char*)0,(id (*)())0}
};
id WhileStmt = (id)&_WhileStmt;
id  *OBJCCLASS_WhileStmt(void) { return &WhileStmt; }
struct _SHARED  _WhileStmt = {
  (id)&__WhileStmt,
  (id)&_IfStmt,
  "WhileStmt",
  0,
  sizeof(struct WhileStmt_PRIVATE),
  3,
  _WhileStmt_nstDispatchTbl,
  41,
  &whilstmt_modDesc,
  0,
  (id)0,
  &WhileStmt,
};
id  OBJCCFUNC_WhileStmt(void) { return (id)&_WhileStmt; }
id  OBJCCSUPER_WhileStmt(void) { return _WhileStmt.clsSuper; }
struct _SHARED __WhileStmt = {
  (id)&__Object,
  (id)&__IfStmt,
  "WhileStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _WhileStmt_clsDispatchTbl,
  34,
  &whilstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_WhileStmt(void) { return (id)&__WhileStmt; }
id  OBJCMSUPER_WhileStmt(void) { return __WhileStmt.clsSuper; }
static char *_selTransTbl[] ={
"synth",
"st80",
"go",
"isKindOf:",
"class",
"isZero",
"breakframe",
"contframe:",
"breakframe:",
0
};
struct modDescriptor whilstmt_modDesc = {
  "whilstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &WhileStmt,
  9,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_whilstmt(void)
{
  selTransTbl = _selTransTbl;
  return &whilstmt_modDesc;
}
int _OBJCPOSTLINK_whilstmt = 1;


