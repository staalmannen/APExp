# 1 "typeof.m"
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
extern struct modDescriptor  *_OBJCBIND_typeof(void);
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
extern struct modDescriptor typeof_modDesc;

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
# 22 "./typeof.h"
struct TypeOf_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./typeof.h"
id keyw;
id expr;};

# 22 "./typeof.h"
extern id  TypeOf;

# 22 "./typeof.h"
extern struct _SHARED _TypeOf;
extern struct _SHARED __TypeOf;


# 38 "typeof.m"
static id i_TypeOf_keyw_(struct TypeOf_PRIVATE *self,SEL _cmd,id kw)
{self->
keyw=kw;
return(id)self;
}

static id i_TypeOf_keyw(struct TypeOf_PRIVATE *self,SEL _cmd)
{
return self->keyw;
}

static id i_TypeOf_expr_(struct TypeOf_PRIVATE *self,SEL _cmd,id e)
{self->
expr=e;
return(id)self;
}

static id i_TypeOf_expr(struct TypeOf_PRIVATE *self,SEL _cmd)
{
return self->expr;
}

static id i_TypeOf_synth(struct TypeOf_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 62 "typeof.m"
(objcT0=self->expr,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
return(id)self;
}

static id i_TypeOf_gen(struct TypeOf_PRIVATE *self,SEL _cmd)
{
id objcT1,objcT2;

# 68 "typeof.m"
(objcT1=self->keyw,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));gc('(');(objcT2=self->expr,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));gc(')');
return(id)self;
}

static BOOL i_TypeOf_isid(struct TypeOf_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_TypeOf_isvoid(struct TypeOf_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_TypeOf_isscalartype(struct TypeOf_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_TypeOf_canforward(struct TypeOf_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_TypeOf_isselptr(struct TypeOf_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _TypeOf_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _TypeOf_nstDispatchTbl[] ={
{"keyw:",(id (*)())i_TypeOf_keyw_},
{"keyw",(id (*)())i_TypeOf_keyw},
{"expr:",(id (*)())i_TypeOf_expr_},
{"expr",(id (*)())i_TypeOf_expr},
{"synth",(id (*)())i_TypeOf_synth},
{"gen",(id (*)())i_TypeOf_gen},
{"isid",(id (*)())i_TypeOf_isid},
{"isvoid",(id (*)())i_TypeOf_isvoid},
{"isscalartype",(id (*)())i_TypeOf_isscalartype},
{"canforward",(id (*)())i_TypeOf_canforward},
{"isselptr",(id (*)())i_TypeOf_isselptr},
{(char*)0,(id (*)())0}
};
id TypeOf = (id)&_TypeOf;
id  *OBJCCLASS_TypeOf(void) { return &TypeOf; }
struct _SHARED  _TypeOf = {
  (id)&__TypeOf,
  (id)&_Node,
  "TypeOf",
  0,
  sizeof(struct TypeOf_PRIVATE),
  11,
  _TypeOf_nstDispatchTbl,
  41,
  &typeof_modDesc,
  0,
  (id)0,
  &TypeOf,
};
id  OBJCCFUNC_TypeOf(void) { return (id)&_TypeOf; }
id  OBJCCSUPER_TypeOf(void) { return _TypeOf.clsSuper; }
struct _SHARED __TypeOf = {
  (id)&__Object,
  (id)&__Node,
  "TypeOf",
  0,
  sizeof(struct _SHARED),
  0,
  _TypeOf_clsDispatchTbl,
  34,
  &typeof_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_TypeOf(void) { return (id)&__TypeOf; }
id  OBJCMSUPER_TypeOf(void) { return __TypeOf.clsSuper; }
static char *_selTransTbl[] ={
"synth",
"gen",
0
};
struct modDescriptor typeof_modDesc = {
  "typeof",
  "objc3.3.19",
  0L,
  0,
  0,
  &TypeOf,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_typeof(void)
{
  selTransTbl = _selTransTbl;
  return &typeof_modDesc;
}
int _OBJCPOSTLINK_typeof = 1;


