# 1 "selxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_selxpr(void);
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
extern struct modDescriptor selxpr_modDesc;

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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./type.h"
extern id t_unknown;
extern id t_void;
extern id t_char;
extern id t_bool;
extern id t_int;
extern id t_long;
extern id t_uns;
extern id t_double;
extern id t_str;
extern id t_sel;
extern id t_id;
# 22 "./trlunit.h"
extern id trlunit;
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
# 22 "./selxpr.h"
struct SelectorExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./selxpr.h"
id selector;};

# 22 "./selxpr.h"
extern id  SelectorExpr;

# 22 "./selxpr.h"
extern struct _SHARED _SelectorExpr;
extern struct _SHARED __SelectorExpr;


# 41 "selxpr.m"
static id i_SelectorExpr_selector_(struct SelectorExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
selector=aRcvr;
return(id)self;
}

static int i_SelectorExpr_lineno(struct SelectorExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 49 "selxpr.m"
return(objcT0=self->selector,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_SelectorExpr_filename(struct SelectorExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 54 "selxpr.m"
return(objcT1=self->selector,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_SelectorExpr_typesynth(struct SelectorExpr_PRIVATE *self,SEL _cmd)
{self->
type=t_sel;
return(id)self;
}

static id i_SelectorExpr_synth(struct SelectorExpr_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 65 "selxpr.m"
id method=(objcT2=trlunit,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],self->selector));

if( !method&&o_warnundefined){
id objcT3;

# 68 "selxpr.m"
warn("argument types for '%s' default to 'id'",(objcT3=self->selector,(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3])));
}
return(id)self;
}

static id i_SelectorExpr_gen(struct SelectorExpr_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 75 "selxpr.m"
(objcT4=self->selector,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 79 "selxpr.m"
static id i_SelectorExpr_go(struct SelectorExpr_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6,objcT7;
return(objcT5=(objcT6=Scalar,(*_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5])),(*(id(*)(id,SEL,char*))_imp(objcT5,selTransTbl[6]))(objcT5,selTransTbl[6],selUid((objcT7=self->selector,(*(STR(*)(id,SEL))_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3])))));
# 86 "selxpr.m"
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _SelectorExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _SelectorExpr_nstDispatchTbl[] ={
{"selector:",(id (*)())i_SelectorExpr_selector_},
{"lineno",(id (*)())i_SelectorExpr_lineno},
{"filename",(id (*)())i_SelectorExpr_filename},
{"typesynth",(id (*)())i_SelectorExpr_typesynth},
{"synth",(id (*)())i_SelectorExpr_synth},
{"gen",(id (*)())i_SelectorExpr_gen},
{"go",(id (*)())i_SelectorExpr_go},
{(char*)0,(id (*)())0}
};
id SelectorExpr = (id)&_SelectorExpr;
id  *OBJCCLASS_SelectorExpr(void) { return &SelectorExpr; }
struct _SHARED  _SelectorExpr = {
  (id)&__SelectorExpr,
  (id)&_Expr,
  "SelectorExpr",
  0,
  sizeof(struct SelectorExpr_PRIVATE),
  7,
  _SelectorExpr_nstDispatchTbl,
  41,
  &selxpr_modDesc,
  0,
  (id)0,
  &SelectorExpr,
};
id  OBJCCFUNC_SelectorExpr(void) { return (id)&_SelectorExpr; }
id  OBJCCSUPER_SelectorExpr(void) { return _SelectorExpr.clsSuper; }
struct _SHARED __SelectorExpr = {
  (id)&__Object,
  (id)&__Expr,
  "SelectorExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _SelectorExpr_clsDispatchTbl,
  34,
  &selxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_SelectorExpr(void) { return (id)&__SelectorExpr; }
id  OBJCMSUPER_SelectorExpr(void) { return __SelectorExpr.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"lookupmethod:",
"str",
"gen",
"new",
"u_str:",
0
};
struct modDescriptor selxpr_modDesc = {
  "selxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &SelectorExpr,
  7,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_selxpr(void)
{
  selTransTbl = _selTransTbl;
  return &selxpr_modDesc;
}
int _OBJCPOSTLINK_selxpr = 1;


