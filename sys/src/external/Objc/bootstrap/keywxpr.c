# 1 "keywxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_keywxpr(void);
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
extern struct modDescriptor keywxpr_modDesc;

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
# 32 "./../../include/objpak/ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
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
# 22 "./keywxpr.h"
struct KeywExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./keywxpr.h"
id keyw;
id expr;
id exprlist;};

# 22 "./keywxpr.h"
extern id  KeywExpr;

# 22 "./keywxpr.h"
extern struct _SHARED _KeywExpr;
extern struct _SHARED __KeywExpr;


# 45 "keywxpr.m"
static id i_KeywExpr_keyw(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
return self->keyw;
}

static id i_KeywExpr_keyw_(struct KeywExpr_PRIVATE *self,SEL _cmd,id sel)
{self->
keyw=sel;
return(id)self;
}

static id i_KeywExpr_arg_(struct KeywExpr_PRIVATE *self,SEL _cmd,id a)
{self->
expr=a;
return(id)self;
}

static unsigned i_KeywExpr_typehash(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 64 "keywxpr.m"
return(objcT0=t_id,(*(unsigned(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static BOOL i_KeywExpr_typeEqual_(struct KeywExpr_PRIVATE *self,SEL _cmd,id x)
{
return(BOOL)1;
}

static id i_KeywExpr_selcons_(struct KeywExpr_PRIVATE *self,SEL _cmd,id sel)
{
id objcT1,objcT2;

# 74 "keywxpr.m"
if(self->keyw)
(objcT1=sel,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],self->keyw));
(objcT2=sel,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return(id)self;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 22 "./commaxpr.h"
extern id  CommaExpr;

# 80 "keywxpr.m"
static id i_KeywExpr_cvtcommalist(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4,objcT5,objcT6,objcT9;
id objcT10;

# 82 "keywxpr.m"
id e;self->
# 87 "keywxpr.m"
exprlist=(objcT3=OrdCltn,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));

for(e=self->expr;(objcT4=e,(*(BOOL(*)(id,SEL,id))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4],(id)(objcT5=CommaExpr,(*_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]))));e=(objcT6=e,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]))){
id objcT7,objcT8;

# 90 "keywxpr.m"
(objcT7=self->exprlist,(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7],(objcT8=e,(*_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8]))));
}self->
expr=(id)0;
(objcT9=self->exprlist,(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7],e));
if(o_debuginfo)
fprintf(stderr,"message with %d varargs\n",(objcT10=self->exprlist,(*(unsigned(*)(id,SEL))_imp(objcT10,selTransTbl[9]))(objcT10,selTransTbl[9])));
return(id)self;
}

# 22 "./constxpr.h"
extern id  ConstantExpr;

# 99 "keywxpr.m"
static id i_KeywExpr_warnforwithmethod(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 101 "keywxpr.m"
int n;

(void)0;
if((n=(objcT11=self->exprlist,(*(unsigned(*)(id,SEL))_imp(objcT11,selTransTbl[9]))(objcT11,selTransTbl[9])))){
id objcT12,objcT13,objcT14;

# 105 "keywxpr.m"
id e=(objcT12=self->exprlist,(*(id(*)(id,SEL,unsigned))_imp(objcT12,selTransTbl[10]))(objcT12,selTransTbl[10],0));

if((objcT13=e,(*(BOOL(*)(id,SEL,id))_imp(objcT13,selTransTbl[4]))(objcT13,selTransTbl[4],(id)(objcT14=ConstantExpr,(*_imp(objcT14,selTransTbl[5]))(objcT14,selTransTbl[5]))))){
id objcT15;

# 108 "keywxpr.m"
int m=(objcT15=e,(*(int(*)(id,SEL))_imp(objcT15,selTransTbl[11]))(objcT15,selTransTbl[11]));


if(m!=0&&n!=m+1){
warn("argument count '%d' followed by %d arguments",m,n-1);
}
}
}
return(id)self;
}

static id i_KeywExpr_synth(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
id objcT16,objcT17;

# 121 "keywxpr.m"
if(self->expr)
(objcT16=self->expr,(*_imp(objcT16,selTransTbl[12]))(objcT16,selTransTbl[12]));
if(self->exprlist)
(objcT17=self->exprlist,(*(id(*)(id,SEL,SEL))_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13],_cmd));
return(id)self;
}

static id i_KeywExpr_genarg(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 130 "keywxpr.m"
if(self->expr)
(objcT18=self->expr,(*_imp(objcT18,selTransTbl[14]))(objcT18,selTransTbl[14]));
if(self->exprlist)
gcommalist(self->exprlist);
return(id)self;
}



static BOOL i_KeywExpr_isselptr(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_KeywExpr_canforward(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_KeywExpr_st80(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
id objcT19,objcT20,objcT21;

# 151 "keywxpr.m"
if(self->keyw)
(objcT19=self->keyw,(*_imp(objcT19,selTransTbl[15]))(objcT19,selTransTbl[15]));
gc(':');
if(self->expr)
(objcT20=self->expr,(*_imp(objcT20,selTransTbl[15]))(objcT20,selTransTbl[15]));
if(self->exprlist)
(objcT21=self->exprlist,(*(id(*)(id,SEL,SEL))_imp(objcT21,selTransTbl[13]))(objcT21,selTransTbl[13],_cmd));
return(id)self;
}

static id i_KeywExpr_go(struct KeywExpr_PRIVATE *self,SEL _cmd)
{
id objcT22,objcT23;

# 163 "keywxpr.m"
if(self->exprlist)(objcT22=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT22,selTransTbl[16]))(objcT22,selTransTbl[16],_cmd));
return(objcT23=self->expr,(*_imp(objcT23,selTransTbl[17]))(objcT23,selTransTbl[17]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _KeywExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _KeywExpr_nstDispatchTbl[] ={
{"keyw",(id (*)())i_KeywExpr_keyw},
{"keyw:",(id (*)())i_KeywExpr_keyw_},
{"arg:",(id (*)())i_KeywExpr_arg_},
{"typehash",(id (*)())i_KeywExpr_typehash},
{"typeEqual:",(id (*)())i_KeywExpr_typeEqual_},
{"selcons:",(id (*)())i_KeywExpr_selcons_},
{"cvtcommalist",(id (*)())i_KeywExpr_cvtcommalist},
{"warnforwithmethod",(id (*)())i_KeywExpr_warnforwithmethod},
{"synth",(id (*)())i_KeywExpr_synth},
{"genarg",(id (*)())i_KeywExpr_genarg},
{"isselptr",(id (*)())i_KeywExpr_isselptr},
{"canforward",(id (*)())i_KeywExpr_canforward},
{"st80",(id (*)())i_KeywExpr_st80},
{"go",(id (*)())i_KeywExpr_go},
{(char*)0,(id (*)())0}
};
id KeywExpr = (id)&_KeywExpr;
id  *OBJCCLASS_KeywExpr(void) { return &KeywExpr; }
struct _SHARED  _KeywExpr = {
  (id)&__KeywExpr,
  (id)&_Expr,
  "KeywExpr",
  0,
  sizeof(struct KeywExpr_PRIVATE),
  14,
  _KeywExpr_nstDispatchTbl,
  41,
  &keywxpr_modDesc,
  0,
  (id)0,
  &KeywExpr,
};
id  OBJCCFUNC_KeywExpr(void) { return (id)&_KeywExpr; }
id  OBJCCSUPER_KeywExpr(void) { return _KeywExpr.clsSuper; }
struct _SHARED __KeywExpr = {
  (id)&__Object,
  (id)&__Expr,
  "KeywExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _KeywExpr_clsDispatchTbl,
  34,
  &keywxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_KeywExpr(void) { return (id)&__KeywExpr; }
id  OBJCMSUPER_KeywExpr(void) { return __KeywExpr.clsSuper; }
static char *_selTransTbl[] ={
"hash",
"add:",
"addcol",
"new",
"isKindOf:",
"class",
"lhs",
"addFirst:",
"rhs",
"size",
"at:",
"asInt",
"synth",
"elementsPerform:",
"gen",
"st80",
"notImplemented:",
"go",
0
};
struct modDescriptor keywxpr_modDesc = {
  "keywxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &KeywExpr,
  18,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_keywxpr(void)
{
  selTransTbl = _selTransTbl;
  return &keywxpr_modDesc;
}
int _OBJCPOSTLINK_keywxpr = 1;


