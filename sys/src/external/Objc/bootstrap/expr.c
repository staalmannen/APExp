# 1 "expr.m"
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
extern struct modDescriptor  *_OBJCBIND_expr(void);
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
extern struct modDescriptor expr_modDesc;

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
# 39 "expr.m"
id e_nil;
id e_self;
id e_cmd;
id e_super;
id e_aFiler;
id e_ft_id;
# 29 "./expr.h"
struct Expr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;};

# 29 "./expr.h"
extern id  Expr;

# 29 "./expr.h"
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;


# 22 "./identxpr.h"
extern id  IdentifierExpr;

# 22 "./constxpr.h"
extern id  ConstantExpr;

# 59 "./symbol.h"
extern id  Symbol;

# 22 "./castxpr.h"
extern id  CastExpr;

# 48 "expr.m"
static id c_Expr_commonexprs(struct Expr_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2,objcT3,objcT4;
id objcT5,objcT6,objcT7,objcT8,objcT9;
id objcT10,objcT11,objcT12,objcT13,objcT14;
id objcT15,objcT16;

# 50 "expr.m"
e_self=(objcT0=(objcT1=IdentifierExpr,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0])),(*_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],s_self));
e_cmd=(objcT2=(objcT3=IdentifierExpr,(*_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0])),(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1],s_cmd));
e_super=(objcT4=(objcT5=IdentifierExpr,(*_imp(objcT5,selTransTbl[0]))(objcT5,selTransTbl[0])),(*_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1],s_super));
e_aFiler=(objcT6=(objcT7=IdentifierExpr,(*_imp(objcT7,selTransTbl[0]))(objcT7,selTransTbl[0])),(*_imp(objcT6,selTransTbl[1]))(objcT6,selTransTbl[1],s_aFiler));
e_ft_id=(objcT8=(objcT9=ConstantExpr,(*_imp(objcT9,selTransTbl[0]))(objcT9,selTransTbl[0])),(*_imp(objcT8,selTransTbl[1]))(objcT8,selTransTbl[1],(objcT10=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT10,selTransTbl[2]))(objcT10,selTransTbl[2],"'@'"))));
e_nil=(objcT11=(objcT12=ConstantExpr,(*_imp(objcT12,selTransTbl[0]))(objcT12,selTransTbl[0])),(*_imp(objcT11,selTransTbl[1]))(objcT11,selTransTbl[1],(objcT13=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT13,selTransTbl[2]))(objcT13,selTransTbl[2],"0"))));
(void)0;
e_nil=(objcT14=(objcT15=(objcT16=CastExpr,(*_imp(objcT16,selTransTbl[0]))(objcT16,selTransTbl[0])),(*_imp(objcT15,selTransTbl[3]))(objcT15,selTransTbl[3],e_nil)),(*_imp(objcT14,selTransTbl[4]))(objcT14,selTransTbl[4],t_id));
return(id)self;
}

static int i_Expr_lineno(struct Expr_PRIVATE *self,SEL _cmd)
{
id objcT17;

# 63 "expr.m"
(objcT17=(id)self,(*_imp(objcT17,selTransTbl[5]))(objcT17,selTransTbl[5]));
return 0;
}

static id i_Expr_filename(struct Expr_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 69 "expr.m"
(objcT18=(id)self,(*_imp(objcT18,selTransTbl[5]))(objcT18,selTransTbl[5]));
return(id)0;
}

static id i_Expr_type(struct Expr_PRIVATE *self,SEL _cmd)
{
if(self->type){
return self->type;
}else{
id objcT19;

# 78 "expr.m"
(objcT19=(id)self,(*_imp(objcT19,selTransTbl[6]))(objcT19,selTransTbl[6]));
(void)0;
return self->type;
}
}

static id i_Expr_type_(struct Expr_PRIVATE *self,SEL _cmd,id t)
{self->
type=t;
return(id)self;
}

static id i_Expr_typesynth(struct Expr_PRIVATE *self,SEL _cmd)
{
id objcT20;

# 92 "expr.m"
return(objcT20=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT20,selTransTbl[7]))(objcT20,selTransTbl[7],_cmd));
}

static id i_Expr_gen(struct Expr_PRIVATE *self,SEL _cmd)
{
id objcT21;

# 97 "expr.m"
return(objcT21=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT21,selTransTbl[7]))(objcT21,selTransTbl[7],_cmd));
}

static id i_Expr_identifier(struct Expr_PRIVATE *self,SEL _cmd)
{
id objcT22;

# 102 "expr.m"
return(objcT22=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT22,selTransTbl[7]))(objcT22,selTransTbl[7],_cmd));
}

static BOOL i_Expr_isidentexpr(struct Expr_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Expr_isconstexpr(struct Expr_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _Expr_clsDispatchTbl[] ={
{"commonexprs",(id (*)())c_Expr_commonexprs},
{(char*)0,(id (*)())0}
};
static struct _SLT _Expr_nstDispatchTbl[] ={
{"lineno",(id (*)())i_Expr_lineno},
{"filename",(id (*)())i_Expr_filename},
{"type",(id (*)())i_Expr_type},
{"type:",(id (*)())i_Expr_type_},
{"typesynth",(id (*)())i_Expr_typesynth},
{"gen",(id (*)())i_Expr_gen},
{"identifier",(id (*)())i_Expr_identifier},
{"isidentexpr",(id (*)())i_Expr_isidentexpr},
{"isconstexpr",(id (*)())i_Expr_isconstexpr},
{(char*)0,(id (*)())0}
};
id Expr = (id)&_Expr;
id  *OBJCCLASS_Expr(void) { return &Expr; }
struct _SHARED  _Expr = {
  (id)&__Expr,
  (id)&_Node,
  "Expr",
  0,
  sizeof(struct Expr_PRIVATE),
  9,
  _Expr_nstDispatchTbl,
  41,
  &expr_modDesc,
  0,
  (id)0,
  &Expr,
};
id  OBJCCFUNC_Expr(void) { return (id)&_Expr; }
id  OBJCCSUPER_Expr(void) { return _Expr.clsSuper; }
struct _SHARED __Expr = {
  (id)&__Object,
  (id)&__Node,
  "Expr",
  0,
  sizeof(struct _SHARED),
  1,
  _Expr_clsDispatchTbl,
  34,
  &expr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Expr(void) { return (id)&__Expr; }
id  OBJCMSUPER_Expr(void) { return __Expr.clsSuper; }
static char *_selTransTbl[] ={
"new",
"identifier:",
"str:",
"expr:",
"cast:",
"subclassResponsibility",
"typesynth",
"subclassResponsibility:",
0
};
struct modDescriptor expr_modDesc = {
  "expr",
  "objc3.3.19",
  0L,
  0,
  0,
  &Expr,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_expr(void)
{
  selTransTbl = _selTransTbl;
  return &expr_modDesc;
}
int _OBJCPOSTLINK_expr = 1;


