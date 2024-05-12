# 1 "btincall.m"
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
extern struct modDescriptor  *_OBJCBIND_btincall(void);
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
extern struct modDescriptor btincall_modDesc;

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
# 22 "./btincall.h"
struct BuiltinCall_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./btincall.h"
id funname,funargs;};

# 22 "./btincall.h"
extern id  BuiltinCall;

# 22 "./btincall.h"
extern struct _SHARED _BuiltinCall;
extern struct _SHARED __BuiltinCall;


# 38 "btincall.m"
static id i_BuiltinCall_funname_(struct BuiltinCall_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
funname=aRcvr;
return(id)self;
}

static id i_BuiltinCall_funargs_(struct BuiltinCall_PRIVATE *self,SEL _cmd,id args)
{self->
funargs=args;
return(id)self;
}

static int i_BuiltinCall_lineno(struct BuiltinCall_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 52 "btincall.m"
return(objcT0=self->funname,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_BuiltinCall_filename(struct BuiltinCall_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 57 "btincall.m"
return(objcT1=self->funname,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_BuiltinCall_gen(struct BuiltinCall_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 62 "btincall.m"
(objcT2=self->funname,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
gc('(');
if(self->funargs)
gcommalist(self->funargs);
gc(')');
return(id)self;
}

static id i_BuiltinCall_typesynth(struct BuiltinCall_PRIVATE *self,SEL _cmd)
{self->
type=t_int;
return(id)self;
}

static id i_BuiltinCall_synth(struct BuiltinCall_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4;

# 78 "btincall.m"
(objcT3=self->funname,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
if(self->funargs)
(objcT4=self->funargs,(*(id(*)(id,SEL,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4],_cmd));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _BuiltinCall_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _BuiltinCall_nstDispatchTbl[] ={
{"funname:",(id (*)())i_BuiltinCall_funname_},
{"funargs:",(id (*)())i_BuiltinCall_funargs_},
{"lineno",(id (*)())i_BuiltinCall_lineno},
{"filename",(id (*)())i_BuiltinCall_filename},
{"gen",(id (*)())i_BuiltinCall_gen},
{"typesynth",(id (*)())i_BuiltinCall_typesynth},
{"synth",(id (*)())i_BuiltinCall_synth},
{(char*)0,(id (*)())0}
};
id BuiltinCall = (id)&_BuiltinCall;
id  *OBJCCLASS_BuiltinCall(void) { return &BuiltinCall; }
struct _SHARED  _BuiltinCall = {
  (id)&__BuiltinCall,
  (id)&_Expr,
  "BuiltinCall",
  0,
  sizeof(struct BuiltinCall_PRIVATE),
  7,
  _BuiltinCall_nstDispatchTbl,
  41,
  &btincall_modDesc,
  0,
  (id)0,
  &BuiltinCall,
};
id  OBJCCFUNC_BuiltinCall(void) { return (id)&_BuiltinCall; }
id  OBJCCSUPER_BuiltinCall(void) { return _BuiltinCall.clsSuper; }
struct _SHARED __BuiltinCall = {
  (id)&__Object,
  (id)&__Expr,
  "BuiltinCall",
  0,
  sizeof(struct _SHARED),
  0,
  _BuiltinCall_clsDispatchTbl,
  34,
  &btincall_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_BuiltinCall(void) { return (id)&__BuiltinCall; }
id  OBJCMSUPER_BuiltinCall(void) { return __BuiltinCall.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"gen",
"synth",
"elementsPerform:",
0
};
struct modDescriptor btincall_modDesc = {
  "btincall",
  "objc3.3.19",
  0L,
  0,
  0,
  &BuiltinCall,
  5,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_btincall(void)
{
  selTransTbl = _selTransTbl;
  return &btincall_modDesc;
}
int _OBJCPOSTLINK_btincall = 1;


