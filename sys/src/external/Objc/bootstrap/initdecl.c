# 1 "initdecl.m"
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
extern struct modDescriptor  *_OBJCBIND_initdecl(void);
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
extern struct modDescriptor initdecl_modDesc;

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
# 22 "./initdecl.h"
struct InitDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./initdecl.h"
id decl,initializer;
BOOL initnil;
BOOL incref;};

# 22 "./initdecl.h"
extern id  InitDecl;

# 22 "./initdecl.h"
extern struct _SHARED _InitDecl;
extern struct _SHARED __InitDecl;


# 39 "initdecl.m"
static BOOL i_InitDecl_isinit(struct InitDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

# 22 "./listxpr.h"
extern id  ListExpr;

# 44 "initdecl.m"
static BOOL i_InitDecl_islistinit(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 46 "initdecl.m"
return(objcT0=self->initializer,(*(BOOL(*)(id,SEL,id))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(id)(objcT1=ListExpr,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]))));
}

static BOOL i_InitDecl_isfunproto(struct InitDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static id i_InitDecl_decl(struct InitDecl_PRIVATE *self,SEL _cmd)
{
return self->decl;
}

static id i_InitDecl_decl_(struct InitDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
decl=aRcvr;
return(id)self;
}

static id i_InitDecl_initializer(struct InitDecl_PRIVATE *self,SEL _cmd)
{
return self->initializer;
}

static id i_InitDecl_initializer_(struct InitDecl_PRIVATE *self,SEL _cmd,id aDecl)
{self->
initializer=aDecl;
return(id)self;
}

static id i_InitDecl_initnil(struct InitDecl_PRIVATE *self,SEL _cmd)
{self->
initnil=(BOOL)1;self->
initializer=e_nil;
return(id)self;
}

static id i_InitDecl_incref(struct InitDecl_PRIVATE *self,SEL _cmd)
{self->
incref++;
return(id)self;
}

static id i_InitDecl_abstrdecl(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 91 "initdecl.m"
return(objcT2=self->decl,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
}

static id i_InitDecl_identifier(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 96 "initdecl.m"
return(objcT3=self->decl,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
}

static id i_InitDecl_synth(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;

# 101 "initdecl.m"
(objcT4=self->decl,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
(objcT5=self->initializer,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));
return(id)self;
}

static id i_InitDecl_synthinits(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 108 "initdecl.m"
(objcT6=self->initializer,(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
return(id)self;
}

static id i_InitDecl_hide_rename_(struct InitDecl_PRIVATE *self,SEL _cmd,id x,id y)
{
id objcT7;

# 114 "initdecl.m"
(objcT7=self->decl,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],x,y));
return(id)self;
}

static id i_InitDecl_gen(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 120 "initdecl.m"
(objcT8=self->decl,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
gc('=');
if(self->initnil){
id objcT9;

# 123 "initdecl.m"
(objcT9=self->initializer,(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7]));
}else{
id objcT10;

# 125 "initdecl.m"
if(self->incref)
gs("idincref(");
(objcT10=self->initializer,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
if(self->incref)
gc(')');
}
return(id)self;
}

static id i_InitDecl_st80(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 136 "initdecl.m"
(objcT11=self->decl,(*_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8]));
return(id)self;
}

static id i_InitDecl_st80inits(struct InitDecl_PRIVATE *self,SEL _cmd)
{
id objcT12,objcT13;

# 142 "initdecl.m"
(objcT12=self->decl,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8]));
# 146 "initdecl.m"
gs(":=");

(objcT13=self->initializer,(*_imp(objcT13,selTransTbl[8]))(objcT13,selTransTbl[8]));
gs(".\n");
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _InitDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _InitDecl_nstDispatchTbl[] ={
{"isinit",(id (*)())i_InitDecl_isinit},
{"islistinit",(id (*)())i_InitDecl_islistinit},
{"isfunproto",(id (*)())i_InitDecl_isfunproto},
{"decl",(id (*)())i_InitDecl_decl},
{"decl:",(id (*)())i_InitDecl_decl_},
{"initializer",(id (*)())i_InitDecl_initializer},
{"initializer:",(id (*)())i_InitDecl_initializer_},
{"initnil",(id (*)())i_InitDecl_initnil},
{"incref",(id (*)())i_InitDecl_incref},
{"abstrdecl",(id (*)())i_InitDecl_abstrdecl},
{"identifier",(id (*)())i_InitDecl_identifier},
{"synth",(id (*)())i_InitDecl_synth},
{"synthinits",(id (*)())i_InitDecl_synthinits},
{"hide:rename:",(id (*)())i_InitDecl_hide_rename_},
{"gen",(id (*)())i_InitDecl_gen},
{"st80",(id (*)())i_InitDecl_st80},
{"st80inits",(id (*)())i_InitDecl_st80inits},
{(char*)0,(id (*)())0}
};
id InitDecl = (id)&_InitDecl;
id  *OBJCCLASS_InitDecl(void) { return &InitDecl; }
struct _SHARED  _InitDecl = {
  (id)&__InitDecl,
  (id)&_Decl,
  "InitDecl",
  0,
  sizeof(struct InitDecl_PRIVATE),
  17,
  _InitDecl_nstDispatchTbl,
  41,
  &initdecl_modDesc,
  0,
  (id)0,
  &InitDecl,
};
id  OBJCCFUNC_InitDecl(void) { return (id)&_InitDecl; }
id  OBJCCSUPER_InitDecl(void) { return _InitDecl.clsSuper; }
struct _SHARED __InitDecl = {
  (id)&__Object,
  (id)&__Decl,
  "InitDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _InitDecl_clsDispatchTbl,
  34,
  &initdecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_InitDecl(void) { return (id)&__InitDecl; }
id  OBJCMSUPER_InitDecl(void) { return __InitDecl.clsSuper; }
static char *_selTransTbl[] ={
"isKindOf:",
"class",
"abstrdecl",
"identifier",
"synth",
"hide:rename:",
"gen",
"sgen",
"st80",
0
};
struct modDescriptor initdecl_modDesc = {
  "initdecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &InitDecl,
  9,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_initdecl(void)
{
  selTransTbl = _selTransTbl;
  return &initdecl_modDesc;
}
int _OBJCPOSTLINK_initdecl = 1;


