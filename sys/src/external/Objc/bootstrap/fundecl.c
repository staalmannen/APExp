# 1 "fundecl.m"
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
extern struct modDescriptor  *_OBJCBIND_fundecl(void);
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
extern struct modDescriptor fundecl_modDesc;

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
# 22 "./fundecl.h"
struct FunctionDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./fundecl.h"
id decl,args;};

# 22 "./fundecl.h"
extern id  FunctionDecl;

# 22 "./fundecl.h"
extern struct _SHARED _FunctionDecl;
extern struct _SHARED __FunctionDecl;


# 22 "./precdecl.h"
extern id  PrecDecl;

# 22 "./pointer.h"
extern id  Pointer;

# 41 "fundecl.m"
static id i_FunctionDecl_abstrdecl(struct FunctionDecl_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 43 "fundecl.m"
id x=(objcT0=self->decl,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));

if(x){
id objcT1,objcT2;

# 46 "fundecl.m"
return(objcT1=(objcT2=(id)self,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1])),(*_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],x));
}else{
id objcT3,objcT4,objcT5,objcT6,objcT7;

# 48 "fundecl.m"
x=(objcT3=(objcT4=PrecDecl,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3])),(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],(objcT5=Pointer,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3]))));
return(objcT6=(objcT7=(id)self,(*_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1])),(*_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2],x));
}
}

static BOOL i_FunctionDecl_isfunproto(struct FunctionDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_FunctionDecl_decl_(struct FunctionDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
decl=aRcvr;
return(id)self;
}

static id i_FunctionDecl_args_(struct FunctionDecl_PRIVATE *self,SEL _cmd,id aList)
{self->
args=aList;
return(id)self;
}

static id i_FunctionDecl_identifier(struct FunctionDecl_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 72 "fundecl.m"
return(objcT8=self->decl,(*_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4]));
}

static id i_FunctionDecl_gendef_(struct FunctionDecl_PRIVATE *self,SEL _cmd,id sym)
{
id objcT11;

# 77 "fundecl.m"
if(self->decl){
id objcT9;

# 78 "fundecl.m"
(objcT9=self->decl,(*_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5],sym));
}else{
id objcT10;

# 80 "fundecl.m"
if(sym)
(objcT10=sym,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
}
gc('(');
if(self->args)
(objcT11=self->args,(*_imp(objcT11,selTransTbl[6]))(objcT11,selTransTbl[6]));
gc(')');
return(id)self;
}

static id i_FunctionDecl_gen(struct FunctionDecl_PRIVATE *self,SEL _cmd)
{
id objcT12,objcT13;

# 92 "fundecl.m"
if(self->decl)
(objcT12=self->decl,(*_imp(objcT12,selTransTbl[6]))(objcT12,selTransTbl[6]));
gc('(');
if(self->args)
(objcT13=self->args,(*_imp(objcT13,selTransTbl[6]))(objcT13,selTransTbl[6]));
gc(')');
return(id)self;
}

static id i_FunctionDecl_star(struct FunctionDecl_PRIVATE *self,SEL _cmd)
{
id objcT14,objcT15,objcT16;

# 103 "fundecl.m"
return(objcT14=(objcT15=(id)self,(*_imp(objcT15,selTransTbl[1]))(objcT15,selTransTbl[1])),(*_imp(objcT14,selTransTbl[2]))(objcT14,selTransTbl[2],(objcT16=self->decl,(*_imp(objcT16,selTransTbl[7]))(objcT16,selTransTbl[7]))));
}

static id i_FunctionDecl_funcall(struct FunctionDecl_PRIVATE *self,SEL _cmd)
{
id objcT17,objcT18,objcT19,objcT20;

# 108 "fundecl.m"
if(self->decl==(id)0||(objcT17=self->decl,(*_imp(objcT17,selTransTbl[7]))(objcT17,selTransTbl[7]))==(id)0)
return(id)0;
return(objcT18=(objcT19=(id)self,(*_imp(objcT19,selTransTbl[1]))(objcT19,selTransTbl[1])),(*_imp(objcT18,selTransTbl[2]))(objcT18,selTransTbl[2],(objcT20=self->decl,(*_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8]))));
}

static id i_FunctionDecl_synth(struct FunctionDecl_PRIVATE *self,SEL _cmd)
{
id objcT21,objcT22;

# 115 "fundecl.m"
if(self->decl)
(objcT21=self->decl,(*_imp(objcT21,selTransTbl[9]))(objcT21,selTransTbl[9]));
if(self->args)
(objcT22=self->args,(*_imp(objcT22,selTransTbl[9]))(objcT22,selTransTbl[9]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _FunctionDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _FunctionDecl_nstDispatchTbl[] ={
{"abstrdecl",(id (*)())i_FunctionDecl_abstrdecl},
{"isfunproto",(id (*)())i_FunctionDecl_isfunproto},
{"decl:",(id (*)())i_FunctionDecl_decl_},
{"args:",(id (*)())i_FunctionDecl_args_},
{"identifier",(id (*)())i_FunctionDecl_identifier},
{"gendef:",(id (*)())i_FunctionDecl_gendef_},
{"gen",(id (*)())i_FunctionDecl_gen},
{"star",(id (*)())i_FunctionDecl_star},
{"funcall",(id (*)())i_FunctionDecl_funcall},
{"synth",(id (*)())i_FunctionDecl_synth},
{(char*)0,(id (*)())0}
};
id FunctionDecl = (id)&_FunctionDecl;
id  *OBJCCLASS_FunctionDecl(void) { return &FunctionDecl; }
struct _SHARED  _FunctionDecl = {
  (id)&__FunctionDecl,
  (id)&_Decl,
  "FunctionDecl",
  0,
  sizeof(struct FunctionDecl_PRIVATE),
  10,
  _FunctionDecl_nstDispatchTbl,
  41,
  &fundecl_modDesc,
  0,
  (id)0,
  &FunctionDecl,
};
id  OBJCCFUNC_FunctionDecl(void) { return (id)&_FunctionDecl; }
id  OBJCCSUPER_FunctionDecl(void) { return _FunctionDecl.clsSuper; }
struct _SHARED __FunctionDecl = {
  (id)&__Object,
  (id)&__Decl,
  "FunctionDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _FunctionDecl_clsDispatchTbl,
  34,
  &fundecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_FunctionDecl(void) { return (id)&__FunctionDecl; }
id  OBJCMSUPER_FunctionDecl(void) { return __FunctionDecl.clsSuper; }
static char *_selTransTbl[] ={
"abstrdecl",
"copy",
"decl:",
"new",
"identifier",
"gendef:",
"gen",
"star",
"funcall",
"synth",
0
};
struct modDescriptor fundecl_modDesc = {
  "fundecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &FunctionDecl,
  10,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_fundecl(void)
{
  selTransTbl = _selTransTbl;
  return &fundecl_modDesc;
}
int _OBJCPOSTLINK_fundecl = 1;


