# 1 "constxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_constxpr(void);
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
extern struct modDescriptor constxpr_modDesc;

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
# 22 "./constxpr.h"
struct ConstantExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./constxpr.h"
id identifier;
id stringchain;
id strcontent;};

# 22 "./constxpr.h"
extern id  ConstantExpr;

# 22 "./constxpr.h"
extern struct _SHARED _ConstantExpr;
extern struct _SHARED __ConstantExpr;


# 42 "constxpr.m"
static BOOL i_ConstantExpr_isconstexpr(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_ConstantExpr_identifier_(struct ConstantExpr_PRIVATE *self,SEL _cmd,id aNode)
{self->
identifier=aNode;
return(id)self;
}

static id i_ConstantExpr_stringchain_(struct ConstantExpr_PRIVATE *self,SEL _cmd,id aList)
{self->
stringchain=aList;
return(id)self;
}

static id i_ConstantExpr_identifier(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
return self->identifier;
}

static id i_ConstantExpr_stringchain(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
return self->stringchain;
}

static BOOL i_ConstantExpr_isEqual_(struct ConstantExpr_PRIVATE *self,SEL _cmd,id x)
{
id objcT0,objcT1;

# 71 "constxpr.m"
(void)0;
return(objcT0=self->identifier,(*(BOOL(*)(id,SEL,id))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(objcT1=x,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]))));
}

static int i_ConstantExpr_lineno(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3,objcT4;

# 77 "constxpr.m"
if(self->identifier)
return(objcT2=self->identifier,(*(int(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return(objcT3=(objcT4=self->stringchain,(*(id(*)(id,SEL,unsigned))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3],0)),(*(int(*)(id,SEL))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
}

static id i_ConstantExpr_filename(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6,objcT7;

# 84 "constxpr.m"
if(self->identifier)
return(objcT5=self->identifier,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));
return(objcT6=(objcT7=self->stringchain,(*(id(*)(id,SEL,unsigned))_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3],0)),(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
}

static int i_ConstantExpr_asInt(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 91 "constxpr.m"
return(objcT8=self->identifier,(*(int(*)(id,SEL))_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
}

static id i_ConstantExpr_synth(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_ConstantExpr_typesynth(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 101 "constxpr.m"
if(self->identifier)self->
type=(objcT9=self->identifier,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
if(self->stringchain)self->
type=t_str;
if( !self->type)self->type=t_unknown;
return(id)self;
}

static id i_ConstantExpr_gen(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11;

# 111 "constxpr.m"
if(self->identifier)
(objcT10=self->identifier,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
if(self->stringchain)
(objcT11=self->stringchain,(*(id(*)(id,SEL,SEL))_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8],selTransTbl[7]));
return(id)self;
}

# 59 "./symbol.h"
extern id  Symbol;

# 118 "constxpr.m"
static id i_ConstantExpr_concatstringchain(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT12,objcT13,objcT16;

# 120 "constxpr.m"
int i,n;
id s=(objcT12=Symbol,(*_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9]));
for(i=0,n=(objcT13=self->stringchain,(*(unsigned(*)(id,SEL))_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10]));i<n;i++){
id objcT14,objcT15;

# 123 "constxpr.m"
id o=(objcT14=self->stringchain,(*(id(*)(id,SEL,unsigned))_imp(objcT14,selTransTbl[3]))(objcT14,selTransTbl[3],i));
(objcT15=s,(*_imp(objcT15,selTransTbl[11]))(objcT15,selTransTbl[11],o));
}
return(objcT16=s,(*_imp(objcT16,selTransTbl[12]))(objcT16,selTransTbl[12]));
}

# 24 "./scalar.h"
extern id  Scalar;

# 129 "constxpr.m"
static id i_ConstantExpr_go(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT17,objcT18;

# 131 "constxpr.m"
id v=(objcT17=Scalar,(*_imp(objcT17,selTransTbl[9]))(objcT17,selTransTbl[9]));
if( !self->type)(objcT18=(id)self,(*_imp(objcT18,selTransTbl[13]))(objcT18,selTransTbl[13]));
if(self->identifier){
id objcT19,objcT25,objcT26,objcT27,objcT28;
id objcT29,objcT30;

# 134 "constxpr.m"
if((objcT19=self->type,(*(BOOL(*)(id,SEL,id))_imp(objcT19,selTransTbl[0]))(objcT19,selTransTbl[0],t_char))){
id objcT20,objcT21,objcT22,objcT23,objcT24;

# 135 "constxpr.m"
id s=(objcT20=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT20,selTransTbl[14]))(objcT20,selTransTbl[14],(objcT21=self->identifier,(*(STR(*)(id,SEL))_imp(objcT21,selTransTbl[15]))(objcT21,selTransTbl[15]))));
(objcT22=s,(*_imp(objcT22,selTransTbl[16]))(objcT22,selTransTbl[16]));
(objcT23=v,(*(id(*)(id,SEL,char))_imp(objcT23,selTransTbl[17]))(objcT23,selTransTbl[17], *(objcT24=s,(*(STR(*)(id,SEL))_imp(objcT24,selTransTbl[15]))(objcT24,selTransTbl[15]))));
}
if((objcT25=self->type,(*(BOOL(*)(id,SEL,id))_imp(objcT25,selTransTbl[0]))(objcT25,selTransTbl[0],t_int)))(objcT26=v,(*(id(*)(id,SEL,int))_imp(objcT26,selTransTbl[18]))(objcT26,selTransTbl[18],atoi((objcT27=self->identifier,(*(STR(*)(id,SEL))_imp(objcT27,selTransTbl[15]))(objcT27,selTransTbl[15])))));
if((objcT28=self->type,(*(BOOL(*)(id,SEL,id))_imp(objcT28,selTransTbl[0]))(objcT28,selTransTbl[0],t_double)))(objcT29=v,(*(id(*)(id,SEL,double))_imp(objcT29,selTransTbl[19]))(objcT29,selTransTbl[19],atof((objcT30=self->identifier,(*(STR(*)(id,SEL))_imp(objcT30,selTransTbl[15]))(objcT30,selTransTbl[15])))));
}
if(self->stringchain){
id objcT31,objcT32,objcT33;

# 143 "constxpr.m"
if( !self->strcontent)self->strcontent=(objcT31=(id)self,(*_imp(objcT31,selTransTbl[20]))(objcT31,selTransTbl[20]));
(objcT32=v,(*(id(*)(id,SEL,char*))_imp(objcT32,selTransTbl[21]))(objcT32,selTransTbl[21],(objcT33=self->strcontent,(*(STR(*)(id,SEL))_imp(objcT33,selTransTbl[22]))(objcT33,selTransTbl[22]))));
}
return v;
}

static id i_ConstantExpr_st80(struct ConstantExpr_PRIVATE *self,SEL _cmd)
{
id objcT34,objcT35;

# 151 "constxpr.m"
if(self->identifier)
(objcT34=self->identifier,(*_imp(objcT34,selTransTbl[23]))(objcT34,selTransTbl[23]));
if(self->stringchain)
(objcT35=self->stringchain,(*(id(*)(id,SEL,SEL))_imp(objcT35,selTransTbl[8]))(objcT35,selTransTbl[8],_cmd));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _ConstantExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ConstantExpr_nstDispatchTbl[] ={
{"isconstexpr",(id (*)())i_ConstantExpr_isconstexpr},
{"identifier:",(id (*)())i_ConstantExpr_identifier_},
{"stringchain:",(id (*)())i_ConstantExpr_stringchain_},
{"identifier",(id (*)())i_ConstantExpr_identifier},
{"stringchain",(id (*)())i_ConstantExpr_stringchain},
{"isEqual:",(id (*)())i_ConstantExpr_isEqual_},
{"lineno",(id (*)())i_ConstantExpr_lineno},
{"filename",(id (*)())i_ConstantExpr_filename},
{"asInt",(id (*)())i_ConstantExpr_asInt},
{"synth",(id (*)())i_ConstantExpr_synth},
{"typesynth",(id (*)())i_ConstantExpr_typesynth},
{"gen",(id (*)())i_ConstantExpr_gen},
{"concatstringchain",(id (*)())i_ConstantExpr_concatstringchain},
{"go",(id (*)())i_ConstantExpr_go},
{"st80",(id (*)())i_ConstantExpr_st80},
{(char*)0,(id (*)())0}
};
id ConstantExpr = (id)&_ConstantExpr;
id  *OBJCCLASS_ConstantExpr(void) { return &ConstantExpr; }
struct _SHARED  _ConstantExpr = {
  (id)&__ConstantExpr,
  (id)&_Expr,
  "ConstantExpr",
  0,
  sizeof(struct ConstantExpr_PRIVATE),
  15,
  _ConstantExpr_nstDispatchTbl,
  41,
  &constxpr_modDesc,
  0,
  (id)0,
  &ConstantExpr,
};
id  OBJCCFUNC_ConstantExpr(void) { return (id)&_ConstantExpr; }
id  OBJCCSUPER_ConstantExpr(void) { return _ConstantExpr.clsSuper; }
struct _SHARED __ConstantExpr = {
  (id)&__Object,
  (id)&__Expr,
  "ConstantExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _ConstantExpr_clsDispatchTbl,
  34,
  &constxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ConstantExpr(void) { return (id)&__ConstantExpr; }
id  OBJCMSUPER_ConstantExpr(void) { return __ConstantExpr.clsSuper; }
static char *_selTransTbl[] ={
"isEqual:",
"identifier",
"lineno",
"at:",
"filename",
"asInt",
"type",
"gen",
"elementsPerform:",
"new",
"size",
"concat:",
"unescape",
"typesynth",
"str:",
"str",
"unescapeChar",
"u_char:",
"u_int:",
"u_double:",
"concatstringchain",
"u_str:",
"strCopy",
"st80",
0
};
struct modDescriptor constxpr_modDesc = {
  "constxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &ConstantExpr,
  24,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_constxpr(void)
{
  selTransTbl = _selTransTbl;
  return &constxpr_modDesc;
}
int _OBJCPOSTLINK_constxpr = 1;


