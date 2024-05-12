# 1 "stmt.m"
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
extern struct modDescriptor  *_OBJCBIND_stmt(void);
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
extern struct modDescriptor stmt_modDesc;

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
# 22 "./stmt.h"
struct Stmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;};

# 22 "./stmt.h"
extern id  Stmt;

# 22 "./stmt.h"
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;


# 36 "stmt.m"
static BOOL i_Stmt_isblockexpr(struct Stmt_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Stmt_iscompstmt(struct Stmt_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static id i_Stmt_gen(struct Stmt_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 48 "stmt.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
}

static BOOL i_Stmt_iscaseOf_(struct Stmt_PRIVATE *self,SEL _cmd,id e)
{
return(BOOL)0;
}

static id i_Stmt_go(struct Stmt_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 58 "stmt.m"
if(o_stepbreak!=(id)0&&o_stepnext!=0)(objcT1=o_stepbreak,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _Stmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Stmt_nstDispatchTbl[] ={
{"isblockexpr",(id (*)())i_Stmt_isblockexpr},
{"iscompstmt",(id (*)())i_Stmt_iscompstmt},
{"gen",(id (*)())i_Stmt_gen},
{"iscaseOf:",(id (*)())i_Stmt_iscaseOf_},
{"go",(id (*)())i_Stmt_go},
{(char*)0,(id (*)())0}
};
id Stmt = (id)&_Stmt;
id  *OBJCCLASS_Stmt(void) { return &Stmt; }
struct _SHARED  _Stmt = {
  (id)&__Stmt,
  (id)&_Node,
  "Stmt",
  0,
  sizeof(struct Stmt_PRIVATE),
  5,
  _Stmt_nstDispatchTbl,
  41,
  &stmt_modDesc,
  0,
  (id)0,
  &Stmt,
};
id  OBJCCFUNC_Stmt(void) { return (id)&_Stmt; }
id  OBJCCSUPER_Stmt(void) { return _Stmt.clsSuper; }
struct _SHARED __Stmt = {
  (id)&__Object,
  (id)&__Node,
  "Stmt",
  0,
  sizeof(struct _SHARED),
  0,
  _Stmt_clsDispatchTbl,
  34,
  &stmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Stmt(void) { return (id)&__Stmt; }
id  OBJCMSUPER_Stmt(void) { return __Stmt.clsSuper; }
static char *_selTransTbl[] ={
"subclassResponsibility:",
"go",
0
};
struct modDescriptor stmt_modDesc = {
  "stmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &Stmt,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_stmt(void)
{
  selTransTbl = _selTransTbl;
  return &stmt_modDesc;
}
int _OBJCPOSTLINK_stmt = 1;


