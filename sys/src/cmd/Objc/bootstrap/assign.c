# 1 "assign.m"
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
extern struct modDescriptor  *_OBJCBIND_assign(void);
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
extern struct modDescriptor assign_modDesc;

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
# 22 "./def.h"
extern id curdef;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
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
# 22 "./trlunit.h"
extern id trlunit;
# 22 "./assign.h"
struct Assignment_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./binxpr.h"
STR op;
id lhs,rhs;
# 24 "./assign.h"
id classdef;
BOOL isidassign;
BOOL isselfassign;};

# 22 "./assign.h"
extern id  Assignment;

# 22 "./assign.h"
extern struct _SHARED _Assignment;
extern struct _SHARED __Assignment;


# 44 "assign.m"
static int i_Assignment_lineno(struct Assignment_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 46 "assign.m"
return(objcT0=self->lhs,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_Assignment_filename(struct Assignment_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 51 "assign.m"
return(objcT1=self->lhs,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_Assignment_typesynth(struct Assignment_PRIVATE *self,SEL _cmd)
{
id objcT2;
self->
# 56 "assign.m"
type=(objcT2=self->lhs,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return(id)self;
}

static id i_Assignment_synth(struct Assignment_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4,objcT5,objcT6;

# 62 "assign.m"
(objcT3=_Assignment.clsSuper,(*_impSuper(objcT3,selTransTbl[3]))((id)self,selTransTbl[3]));
if(curdef&&(objcT4=curdef,(*(BOOL(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]))&&(objcT5=self->lhs,(*(BOOL(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]))&&strcmp((objcT6=self->lhs,(*(STR(*)(id,SEL))_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6])),"self")==0){
id objcT7;

# 64 "assign.m"
(objcT7=trlunit,(*(id(*)(id,SEL,BOOL))_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7],(BOOL)1));
if( !o_selfassign){
id objcT8;

# 66 "assign.m"
id sym=(objcT8=self->lhs,(*_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8]));

fatalat(sym,"assignment to 'self' not allowed with -noSelfAssign");
}else{
id objcT9;
self->
# 70 "assign.m"
classdef=curclassdef;self->
isselfassign++;

(objcT9=self->lhs,(*(id(*)(id,SEL,BOOL))_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9],(BOOL)1));
}
}
if(o_refcnt){
id objcT10,objcT11;

# 77 "assign.m"
if(self->isselfassign||(objcT10=(objcT11=self->lhs,(*_imp(objcT11,selTransTbl[2]))(objcT11,selTransTbl[2])),(*(BOOL(*)(id,SEL))_imp(objcT10,selTransTbl[10]))(objcT10,selTransTbl[10])))self->
isidassign++;
}
return(id)self;
}

static id i_Assignment_gen(struct Assignment_PRIVATE *self,SEL _cmd)
{
id objcT23;

# 85 "assign.m"
if(self->isidassign){
id objcT12,objcT13,objcT14;

# 86 "assign.m"
gl((objcT12=self->lhs,(*(int(*)(id,SEL))_imp(objcT12,selTransTbl[0]))(objcT12,selTransTbl[0])),(objcT13=(objcT14=self->lhs,(*_imp(objcT14,selTransTbl[1]))(objcT14,selTransTbl[1])),(*(STR(*)(id,SEL))_imp(objcT13,selTransTbl[6]))(objcT13,selTransTbl[6])));
if( !self->isselfassign){
id objcT15,objcT16;

# 88 "assign.m"
gs("idassign(&");
(objcT15=self->lhs,(*_imp(objcT15,selTransTbl[11]))(objcT15,selTransTbl[11]));
gc(',');
(objcT16=self->rhs,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11]));
gc(')');
}else{
id objcT17,objcT18;

# 94 "assign.m"
gs("idassign((id*)(&");
(objcT17=self->lhs,(*_imp(objcT17,selTransTbl[11]))(objcT17,selTransTbl[11]));
gs("),");
(objcT18=self->rhs,(*_imp(objcT18,selTransTbl[11]))(objcT18,selTransTbl[11]));
gc(')');
}
return(id)self;
}
if(self->isselfassign){
id objcT19,objcT22;

# 103 "assign.m"
(objcT19=self->lhs,(*_imp(objcT19,selTransTbl[11]))(objcT19,selTransTbl[11]));
gs(self->op);

if( !o_otb){
id objcT20;

# 107 "assign.m"
gf("(struct %s*)",(objcT20=self->classdef,(*(char*(*)(id,SEL))_imp(objcT20,selTransTbl[12]))(objcT20,selTransTbl[12])));
}else{
id objcT21;

# 109 "assign.m"
gf("(struct %s*)",(objcT21=self->classdef,(*(char*(*)(id,SEL))_imp(objcT21,selTransTbl[13]))(objcT21,selTransTbl[13])));
}
gc('(');
(objcT22=self->rhs,(*_imp(objcT22,selTransTbl[11]))(objcT22,selTransTbl[11]));
gc(')');
return(id)self;
}
return(objcT23=_Assignment.clsSuper,(*_impSuper(objcT23,selTransTbl[11]))((id)self,selTransTbl[11]));
}

static id i_Assignment_go(struct Assignment_PRIVATE *self,SEL _cmd)
{
id objcT24,objcT25;

# 121 "assign.m"
return(objcT24=self->lhs,(*_imp(objcT24,selTransTbl[14]))(objcT24,selTransTbl[14],(objcT25=self->rhs,(*_imp(objcT25,selTransTbl[15]))(objcT25,selTransTbl[15]))));
}

static id i_Assignment_st80(struct Assignment_PRIVATE *self,SEL _cmd)
{
id objcT26,objcT27;

# 126 "assign.m"
(objcT26=self->lhs,(*_imp(objcT26,selTransTbl[16]))(objcT26,selTransTbl[16]));
# 130 "assign.m"
gs(":=");

(objcT27=self->rhs,(*_imp(objcT27,selTransTbl[16]))(objcT27,selTransTbl[16]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  BinaryExpr;
extern struct _SHARED _BinaryExpr;
extern struct _SHARED __BinaryExpr;
static struct _SLT _Assignment_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Assignment_nstDispatchTbl[] ={
{"lineno",(id (*)())i_Assignment_lineno},
{"filename",(id (*)())i_Assignment_filename},
{"typesynth",(id (*)())i_Assignment_typesynth},
{"synth",(id (*)())i_Assignment_synth},
{"gen",(id (*)())i_Assignment_gen},
{"go",(id (*)())i_Assignment_go},
{"st80",(id (*)())i_Assignment_st80},
{(char*)0,(id (*)())0}
};
id Assignment = (id)&_Assignment;
id  *OBJCCLASS_Assignment(void) { return &Assignment; }
struct _SHARED  _Assignment = {
  (id)&__Assignment,
  (id)&_BinaryExpr,
  "Assignment",
  0,
  sizeof(struct Assignment_PRIVATE),
  7,
  _Assignment_nstDispatchTbl,
  41,
  &assign_modDesc,
  0,
  (id)0,
  &Assignment,
};
id  OBJCCFUNC_Assignment(void) { return (id)&_Assignment; }
id  OBJCCSUPER_Assignment(void) { return _Assignment.clsSuper; }
struct _SHARED __Assignment = {
  (id)&__Object,
  (id)&__BinaryExpr,
  "Assignment",
  0,
  sizeof(struct _SHARED),
  0,
  _Assignment_clsDispatchTbl,
  34,
  &assign_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Assignment(void) { return (id)&__Assignment; }
id  OBJCMSUPER_Assignment(void) { return __Assignment.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"type",
"synth",
"ismethdef",
"isidentexpr",
"str",
"usingselfassign:",
"identifier",
"lhsself:",
"isrefcounted",
"gen",
"privtypename",
"otbtypename",
"assignvar:",
"go",
"st80",
0
};
struct modDescriptor assign_modDesc = {
  "assign",
  "objc3.3.19",
  0L,
  0,
  0,
  &Assignment,
  17,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_assign(void)
{
  selTransTbl = _selTransTbl;
  return &assign_modDesc;
}
int _OBJCPOSTLINK_assign = 1;


