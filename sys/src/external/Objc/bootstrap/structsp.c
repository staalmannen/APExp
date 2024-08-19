# 1 "structsp.m"
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
extern struct modDescriptor  *_OBJCBIND_structsp(void);
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
extern struct modDescriptor structsp_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//string.h"
#include <string.h>

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
# 22 "./structsp.h"
extern id curstruct;
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
# 42 "structsp.m"
id curstruct;
# 24 "./structsp.h"
struct StructSpec_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 26 "./structsp.h"
id keyw,name;
id lbrace;
id defs;
id rbrace;
id compdic,compnames,comptypes;};

# 24 "./structsp.h"
extern id  StructSpec;

# 24 "./structsp.h"
extern struct _SHARED _StructSpec;
extern struct _SHARED __StructSpec;


# 46 "structsp.m"
static int i_StructSpec_lineno(struct StructSpec_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 48 "structsp.m"
return(objcT0=self->keyw,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_StructSpec_filename(struct StructSpec_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 53 "structsp.m"
return(objcT1=self->keyw,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_StructSpec_keyw_(struct StructSpec_PRIVATE *self,SEL _cmd,id akeyw)
{self->
keyw=akeyw;
return(id)self;
}

static id i_StructSpec_name_(struct StructSpec_PRIVATE *self,SEL _cmd,id akeyw)
{self->
name=akeyw;
return(id)self;
}

static id i_StructSpec_defs_(struct StructSpec_PRIVATE *self,SEL _cmd,id akeyw)
{self->
defs=akeyw;
return(id)self;
}

static id i_StructSpec_lbrace_(struct StructSpec_PRIVATE *self,SEL _cmd,id lb)
{self->
lbrace=lb;
return(id)self;
}

static id i_StructSpec_rbrace_(struct StructSpec_PRIVATE *self,SEL _cmd,id rb)
{self->
rbrace=rb;
return(id)self;
}

static unsigned i_StructSpec_hash(struct StructSpec_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 88 "structsp.m"
return(objcT2=self->name,(*(unsigned(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
}

static STR i_StructSpec_str(struct StructSpec_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 93 "structsp.m"
return(objcT3=self->name,(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
}

static BOOL i_StructSpec_isEqual_(struct StructSpec_PRIVATE *self,SEL _cmd,id x)
{
id objcT4,objcT5;

# 98 "structsp.m"
if( !self->name)
return(id)self==x;

return((id)self==x)?(BOOL)1:strcmp((objcT4=self->name,(*(STR(*)(id,SEL))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3])),(objcT5=x,(*(STR(*)(id,SEL))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3])))==0;
}

static id i_StructSpec_synth(struct StructSpec_PRIVATE *self,SEL _cmd)
{
id outerstruct=curstruct;
curstruct=(id)self;
if(self->defs){
id objcT6,objcT7;

# 109 "structsp.m"
(objcT6=self->defs,(*(id(*)(id,SEL,SEL))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4],_cmd));
if(self->name)
(objcT7=trlunit,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],(id)self));
}
curstruct=outerstruct;
return(id)self;
}

static id i_StructSpec_gen(struct StructSpec_PRIVATE *self,SEL _cmd)
{
id objcT8,objcT9;

# 119 "structsp.m"
(objcT8=self->keyw,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
if(self->name)
(objcT9=self->name,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
if(self->defs){
id objcT10,objcT11,objcT12;

# 123 "structsp.m"
if(self->lbrace)
(objcT10=self->lbrace,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
else
gc('{');
(objcT11=self->defs,(*(id(*)(id,SEL,SEL))_imp(objcT11,selTransTbl[4]))(objcT11,selTransTbl[4],_cmd));
if(self->rbrace)
(objcT12=self->rbrace,(*_imp(objcT12,selTransTbl[6]))(objcT12,selTransTbl[6]));
else
gc('}');
}
return(id)self;
}

static BOOL i_StructSpec_isscalartype(struct StructSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_StructSpec_isvolatile(struct StructSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_StructSpec_isrefcounted(struct StructSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_StructSpec_canforward(struct StructSpec_PRIVATE *self,SEL _cmd)
{

return o_structassign;
}

static BOOL i_StructSpec_isselptr(struct StructSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static id i_StructSpec_lookupcomp_(struct StructSpec_PRIVATE *self,SEL _cmd,id c)
{
id objcT13;

# 164 "structsp.m"
return(self->compdic)?(objcT13=self->compdic,(*_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7],c)):(id)0;
}

# 32 "./../../include/objpak/dictnary.h"
extern id  Dictionary;

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 167 "structsp.m"
static id i_StructSpec_defcomp_astype_(struct StructSpec_PRIVATE *self,SEL _cmd,id sym,id t)
{
id objcT17,objcT18,objcT19;

# 169 "structsp.m"
if( !self->compdic){
id objcT14,objcT15,objcT16;
self->
# 170 "structsp.m"
compdic=(objcT14=Dictionary,(*_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8]));self->
compnames=(objcT15=OrdCltn,(*_imp(objcT15,selTransTbl[8]))(objcT15,selTransTbl[8]));self->
comptypes=(objcT16=OrdCltn,(*_imp(objcT16,selTransTbl[8]))(objcT16,selTransTbl[8]));
}
(objcT17=self->compdic,(*_imp(objcT17,selTransTbl[9]))(objcT17,selTransTbl[9],sym,t));
(objcT18=self->compnames,(*_imp(objcT18,selTransTbl[10]))(objcT18,selTransTbl[10],sym));
(objcT19=self->comptypes,(*_imp(objcT19,selTransTbl[10]))(objcT19,selTransTbl[10],t));
return(id)self;
}

static id i_StructSpec_dot_(struct StructSpec_PRIVATE *self,SEL _cmd,id sym)
{
if(self->compdic){
id objcT20;

# 183 "structsp.m"
return(objcT20=self->compdic,(*_imp(objcT20,selTransTbl[7]))(objcT20,selTransTbl[7],sym));
}else{
if(self->name){
id objcT21;

# 186 "structsp.m"
id s=(objcT21=trlunit,(*_imp(objcT21,selTransTbl[11]))(objcT21,selTransTbl[11],(id)self));

if( !s){
id objcT22;

# 189 "structsp.m"
warnat(sym,"incomplete definition of struct '%s'",(objcT22=self->name,(*(STR(*)(id,SEL))_imp(objcT22,selTransTbl[3]))(objcT22,selTransTbl[3])));
return(id)0;
}else{
id objcT23;

# 192 "structsp.m"
return(objcT23=s,(*_imp(objcT23,selTransTbl[12]))(objcT23,selTransTbl[12],sym));
}
}else{
return(id)0;
}
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _StructSpec_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _StructSpec_nstDispatchTbl[] ={
{"lineno",(id (*)())i_StructSpec_lineno},
{"filename",(id (*)())i_StructSpec_filename},
{"keyw:",(id (*)())i_StructSpec_keyw_},
{"name:",(id (*)())i_StructSpec_name_},
{"defs:",(id (*)())i_StructSpec_defs_},
{"lbrace:",(id (*)())i_StructSpec_lbrace_},
{"rbrace:",(id (*)())i_StructSpec_rbrace_},
{"hash",(id (*)())i_StructSpec_hash},
{"str",(id (*)())i_StructSpec_str},
{"isEqual:",(id (*)())i_StructSpec_isEqual_},
{"synth",(id (*)())i_StructSpec_synth},
{"gen",(id (*)())i_StructSpec_gen},
{"isscalartype",(id (*)())i_StructSpec_isscalartype},
{"isvolatile",(id (*)())i_StructSpec_isvolatile},
{"isrefcounted",(id (*)())i_StructSpec_isrefcounted},
{"canforward",(id (*)())i_StructSpec_canforward},
{"isselptr",(id (*)())i_StructSpec_isselptr},
{"lookupcomp:",(id (*)())i_StructSpec_lookupcomp_},
{"defcomp:astype:",(id (*)())i_StructSpec_defcomp_astype_},
{"dot:",(id (*)())i_StructSpec_dot_},
{(char*)0,(id (*)())0}
};
id StructSpec = (id)&_StructSpec;
id  *OBJCCLASS_StructSpec(void) { return &StructSpec; }
struct _SHARED  _StructSpec = {
  (id)&__StructSpec,
  (id)&_Node,
  "StructSpec",
  0,
  sizeof(struct StructSpec_PRIVATE),
  20,
  _StructSpec_nstDispatchTbl,
  41,
  &structsp_modDesc,
  0,
  (id)0,
  &StructSpec,
};
id  OBJCCFUNC_StructSpec(void) { return (id)&_StructSpec; }
id  OBJCCSUPER_StructSpec(void) { return _StructSpec.clsSuper; }
struct _SHARED __StructSpec = {
  (id)&__Object,
  (id)&__Node,
  "StructSpec",
  0,
  sizeof(struct _SHARED),
  0,
  _StructSpec_clsDispatchTbl,
  34,
  &structsp_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_StructSpec(void) { return (id)&__StructSpec; }
id  OBJCMSUPER_StructSpec(void) { return __StructSpec.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"hash",
"str",
"elementsPerform:",
"defstruct:",
"gen",
"atKey:",
"new",
"atKey:put:",
"add:",
"lookupstruct:",
"dot:",
0
};
struct modDescriptor structsp_modDesc = {
  "structsp",
  "objc3.3.19",
  0L,
  0,
  0,
  &StructSpec,
  13,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_structsp(void)
{
  selTransTbl = _selTransTbl;
  return &structsp_modDesc;
}
int _OBJCPOSTLINK_structsp = 1;


