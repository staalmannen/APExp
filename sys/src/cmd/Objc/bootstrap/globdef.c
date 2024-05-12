# 1 "globdef.m"
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
extern struct modDescriptor  *_OBJCBIND_globdef(void);
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
extern struct modDescriptor globdef_modDesc;

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
# 22 "./def.h"
extern id curdef;
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
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
# 22 "./trlunit.h"
extern id trlunit;
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
# 22 "./globdef.h"
struct GlobDef_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./globdef.h"
BOOL isstatic;
BOOL isextern;
id value;
id initializer;
id type;};

# 22 "./globdef.h"
extern id  GlobDef;

# 22 "./globdef.h"
extern struct _SHARED _GlobDef;
extern struct _SHARED __GlobDef;


# 48 "globdef.m"
static BOOL i_GlobDef_isextern(struct GlobDef_PRIVATE *self,SEL _cmd)
{
return self->isextern;
}

static BOOL i_GlobDef_isstatic(struct GlobDef_PRIVATE *self,SEL _cmd)
{
return self->isstatic;
}

static id i_GlobDef_value(struct GlobDef_PRIVATE *self,SEL _cmd)
{
return self->value;
}

static id i_GlobDef_defval_(struct GlobDef_PRIVATE *self,SEL _cmd,id v)
{self->
value=v;
return(id)self;
}

static id i_GlobDef_type_(struct GlobDef_PRIVATE *self,SEL _cmd,id i)
{self->
type=i;
return(id)self;
}

static id i_GlobDef_initializer_(struct GlobDef_PRIVATE *self,SEL _cmd,id i)
{self->
initializer=i;
return(id)self;
}

static id i_GlobDef_reset(struct GlobDef_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;
self->
# 83 "globdef.m"
value=(self->initializer)?(objcT0=self->initializer,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0])):(objcT1=self->type,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _GlobDef_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _GlobDef_nstDispatchTbl[] ={
{"isextern",(id (*)())i_GlobDef_isextern},
{"isstatic",(id (*)())i_GlobDef_isstatic},
{"value",(id (*)())i_GlobDef_value},
{"defval:",(id (*)())i_GlobDef_defval_},
{"type:",(id (*)())i_GlobDef_type_},
{"initializer:",(id (*)())i_GlobDef_initializer_},
{"reset",(id (*)())i_GlobDef_reset},
{(char*)0,(id (*)())0}
};
id GlobDef = (id)&_GlobDef;
id  *OBJCCLASS_GlobDef(void) { return &GlobDef; }
struct _SHARED  _GlobDef = {
  (id)&__GlobDef,
  (id)&_Node,
  "GlobDef",
  0,
  sizeof(struct GlobDef_PRIVATE),
  7,
  _GlobDef_nstDispatchTbl,
  41,
  &globdef_modDesc,
  0,
  (id)0,
  &GlobDef,
};
id  OBJCCFUNC_GlobDef(void) { return (id)&_GlobDef; }
id  OBJCCSUPER_GlobDef(void) { return _GlobDef.clsSuper; }
struct _SHARED __GlobDef = {
  (id)&__Object,
  (id)&__Node,
  "GlobDef",
  0,
  sizeof(struct _SHARED),
  0,
  _GlobDef_clsDispatchTbl,
  34,
  &globdef_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_GlobDef(void) { return (id)&__GlobDef; }
id  OBJCMSUPER_GlobDef(void) { return __GlobDef.clsSuper; }
static char *_selTransTbl[] ={
"go",
"zero",
0
};
struct modDescriptor globdef_modDesc = {
  "globdef",
  "objc3.3.19",
  0L,
  0,
  0,
  &GlobDef,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_globdef(void)
{
  selTransTbl = _selTransTbl;
  return &globdef_modDesc;
}
int _OBJCPOSTLINK_globdef = 1;


