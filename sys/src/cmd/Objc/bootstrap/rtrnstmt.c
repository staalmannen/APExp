# 1 "rtrnstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_rtrnstmt(void);
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
extern struct modDescriptor rtrnstmt_modDesc;

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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
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
# 22 "./def.h"
extern id curdef;
# 22 "./stkframe.h"
extern id topframe;
# 22 "./rtrnstmt.h"
struct ReturnStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./rtrnstmt.h"
id keyw;
id expr;
id compound;
BOOL incretval;};

# 22 "./rtrnstmt.h"
extern id  ReturnStmt;

# 22 "./rtrnstmt.h"
extern struct _SHARED _ReturnStmt;
extern struct _SHARED __ReturnStmt;


# 44 "rtrnstmt.m"
static id i_ReturnStmt_keyw_(struct ReturnStmt_PRIVATE *self,SEL _cmd,id aKeyw)
{self->
keyw=aKeyw;
return(id)self;
}

static id i_ReturnStmt_expr_(struct ReturnStmt_PRIVATE *self,SEL _cmd,id anExpr)
{self->
expr=anExpr;
return(id)self;
}

static id i_ReturnStmt_synth(struct ReturnStmt_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT2;

# 58 "rtrnstmt.m"
id c;

for(c=curcompound;c;c=(objcT0=c,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]))){
id objcT1;

# 61 "rtrnstmt.m"
if((objcT1=c,(*(BOOL(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]))){
fatalat(self->keyw,"non-local return from within block not yet supported");
}
}
(objcT2=self->expr,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
if(o_refcnt){
id objcT9;

# 67 "rtrnstmt.m"
if(self->expr){
id objcT3,objcT4,objcT5;

# 68 "rtrnstmt.m"
id t=(objcT3=self->expr,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));

if( !(objcT4=self->expr,(*(BOOL(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]))&&(objcT5=t,(*(BOOL(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5])))self->
incretval++;

else if(curclassdef){
id objcT6;
if(curdef&&(objcT6=curdef,(*(BOOL(*)(id,SEL))_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]))){
id objcT7,objcT8;

# 76 "rtrnstmt.m"
if((objcT7=t,(*(BOOL(*)(id,SEL,id))_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7],(objcT8=curclassdef,(*_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8])))))self->
incretval++;
}
}
}self->

compound=curcompound;
(objcT9=self->compound,(*_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9]));
}

return(id)self;
}

static id i_ReturnStmt_gen(struct ReturnStmt_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 91 "rtrnstmt.m"
id label;
if(o_refcnt&&(label=(objcT10=self->compound,(*_imp(objcT10,selTransTbl[10]))(objcT10,selTransTbl[10])))!=(id)0){
id objcT15;

# 93 "rtrnstmt.m"
if(self->keyw){
id objcT11,objcT12,objcT13;

# 94 "rtrnstmt.m"
gl((objcT11=self->keyw,(*(int(*)(id,SEL))_imp(objcT11,selTransTbl[11]))(objcT11,selTransTbl[11])),(objcT12=(objcT13=self->keyw,(*_imp(objcT13,selTransTbl[12]))(objcT13,selTransTbl[12])),(*(STR(*)(id,SEL))_imp(objcT12,selTransTbl[13]))(objcT12,selTransTbl[13])));
}
gs("if (_returnflag==0) {_returnflag++;");
if(self->expr){
id objcT14;

# 98 "rtrnstmt.m"
gs("_returnval=");
(objcT14=self->expr,(*_imp(objcT14,selTransTbl[14]))(objcT14,selTransTbl[14]));
gc(';');
}
if(self->incretval){
gs("idincref(_returnval);");
}
gf("goto %s;}",(objcT15=label,(*(STR(*)(id,SEL))_imp(objcT15,selTransTbl[13]))(objcT15,selTransTbl[13])));
}else{
id objcT16,objcT17;

# 107 "rtrnstmt.m"
if(self->keyw)
(objcT16=self->keyw,(*_imp(objcT16,selTransTbl[14]))(objcT16,selTransTbl[14]));
else
gs("return");
if(self->expr)
(objcT17=self->expr,(*_imp(objcT17,selTransTbl[14]))(objcT17,selTransTbl[14]));
gc(';');
}
return(id)self;
}

static id i_ReturnStmt_st80(struct ReturnStmt_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19;

# 120 "rtrnstmt.m"
gc('^');
if(self->expr)
(objcT18=self->expr,(*_imp(objcT18,selTransTbl[15]))(objcT18,selTransTbl[15]));
else
(objcT19=e_self,(*_imp(objcT19,selTransTbl[15]))(objcT19,selTransTbl[15]));
gs(".\n");
return(id)self;
}

static id i_ReturnStmt_go(struct ReturnStmt_PRIVATE *self,SEL _cmd)
{
id objcT20,objcT21,objcT22;

# 131 "rtrnstmt.m"
(objcT20=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT20,selTransTbl[16]))(objcT20,selTransTbl[16],(BOOL)1));
if(self->expr)(objcT21=topframe,(*_imp(objcT21,selTransTbl[17]))(objcT21,selTransTbl[17],(objcT22=self->expr,(*_imp(objcT22,selTransTbl[18]))(objcT22,selTransTbl[18]))));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _ReturnStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ReturnStmt_nstDispatchTbl[] ={
{"keyw:",(id (*)())i_ReturnStmt_keyw_},
{"expr:",(id (*)())i_ReturnStmt_expr_},
{"synth",(id (*)())i_ReturnStmt_synth},
{"gen",(id (*)())i_ReturnStmt_gen},
{"st80",(id (*)())i_ReturnStmt_st80},
{"go",(id (*)())i_ReturnStmt_go},
{(char*)0,(id (*)())0}
};
id ReturnStmt = (id)&_ReturnStmt;
id  *OBJCCLASS_ReturnStmt(void) { return &ReturnStmt; }
struct _SHARED  _ReturnStmt = {
  (id)&__ReturnStmt,
  (id)&_Stmt,
  "ReturnStmt",
  0,
  sizeof(struct ReturnStmt_PRIVATE),
  6,
  _ReturnStmt_nstDispatchTbl,
  41,
  &rtrnstmt_modDesc,
  0,
  (id)0,
  &ReturnStmt,
};
id  OBJCCFUNC_ReturnStmt(void) { return (id)&_ReturnStmt; }
id  OBJCCSUPER_ReturnStmt(void) { return _ReturnStmt.clsSuper; }
struct _SHARED __ReturnStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "ReturnStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _ReturnStmt_clsDispatchTbl,
  34,
  &rtrnstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ReturnStmt(void) { return (id)&__ReturnStmt; }
id  OBJCMSUPER_ReturnStmt(void) { return __ReturnStmt.clsSuper; }
static char *_selTransTbl[] ={
"enclosing",
"isblockexpr",
"synth",
"type",
"isconstexpr",
"isid",
"ismethdef",
"isEqual:",
"selftype",
"usereturnflag",
"nextreturnlabel",
"lineno",
"filename",
"str",
"gen",
"st80",
"quitframe:",
"returnval:",
"go",
0
};
struct modDescriptor rtrnstmt_modDesc = {
  "rtrnstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &ReturnStmt,
  19,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_rtrnstmt(void)
{
  selTransTbl = _selTransTbl;
  return &rtrnstmt_modDesc;
}
int _OBJCPOSTLINK_rtrnstmt = 1;


