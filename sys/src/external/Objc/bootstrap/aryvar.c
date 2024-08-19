# 1 "aryvar.m"
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
extern struct modDescriptor  *_OBJCBIND_aryvar(void);
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
extern struct modDescriptor aryvar_modDesc;

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
# 22 "./aryvar.h"
struct ArrayVariable_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./aryvar.h"
id value;};

# 22 "./aryvar.h"
extern id  ArrayVariable;

# 22 "./aryvar.h"
extern struct _SHARED _ArrayVariable;
extern struct _SHARED __ArrayVariable;


# 38 "aryvar.m"
static id i_ArrayVariable_value_(struct ArrayVariable_PRIVATE *self,SEL _cmd,id v)
{self->
value=v;
return(id)self;
}

static id i_ArrayVariable_value(struct ArrayVariable_PRIVATE *self,SEL _cmd)
{
return self->value;
}

static unsigned i_ArrayVariable_size(struct ArrayVariable_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 51 "aryvar.m"
return(objcT0=self->value,(*(unsigned(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 54 "aryvar.m"
static id c_ArrayVariable_new(struct ArrayVariable_PRIVATE *self,SEL _cmd)
{
id objcT1,objcT2,objcT3;

# 56 "aryvar.m"
return(objcT1=(objcT2=__ArrayVariable.clsSuper,(*_impSuper(objcT2,selTransTbl[1]))((id)self,selTransTbl[1])),(*_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],(objcT3=OrdCltn,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1]))));
}

static id c_ArrayVariable_new_(struct ArrayVariable_PRIVATE *self,SEL _cmd,unsigned x)
{
id objcT4,objcT5,objcT6;

# 61 "aryvar.m"
return(objcT4=(objcT5=__ArrayVariable.clsSuper,(*_impSuper(objcT5,selTransTbl[1]))((id)self,selTransTbl[1])),(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],(objcT6=OrdCltn,(*(id(*)(id,SEL,unsigned))_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3],x))));
}

static id i_ArrayVariable_at_(struct ArrayVariable_PRIVATE *self,SEL _cmd,unsigned i)
{
id objcT7;

# 66 "aryvar.m"
return(objcT7=self->value,(*(id(*)(id,SEL,unsigned))_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4],i));
}

static id i_ArrayVariable_add_(struct ArrayVariable_PRIVATE *self,SEL _cmd,id x)
{
id objcT8;

# 71 "aryvar.m"
(objcT8=self->value,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5],x));
return(id)self;
}

static id i_ArrayVariable_addAll_(struct ArrayVariable_PRIVATE *self,SEL _cmd,id x)
{
id objcT9;

# 77 "aryvar.m"
(objcT9=self->value,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6],x));
return(id)self;
}

static id i_ArrayVariable_at_put_(struct ArrayVariable_PRIVATE *self,SEL _cmd,unsigned i,id v)
{
id objcT10;

# 83 "aryvar.m"
(objcT10=self->value,(*(id(*)(id,SEL,unsigned,id))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7],i,v));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Variable;
extern struct _SHARED _Variable;
extern struct _SHARED __Variable;
static struct _SLT _ArrayVariable_clsDispatchTbl[] ={
{"new",(id (*)())c_ArrayVariable_new},
{"new:",(id (*)())c_ArrayVariable_new_},
{(char*)0,(id (*)())0}
};
static struct _SLT _ArrayVariable_nstDispatchTbl[] ={
{"value:",(id (*)())i_ArrayVariable_value_},
{"value",(id (*)())i_ArrayVariable_value},
{"size",(id (*)())i_ArrayVariable_size},
{"at:",(id (*)())i_ArrayVariable_at_},
{"add:",(id (*)())i_ArrayVariable_add_},
{"addAll:",(id (*)())i_ArrayVariable_addAll_},
{"at:put:",(id (*)())i_ArrayVariable_at_put_},
{(char*)0,(id (*)())0}
};
id ArrayVariable = (id)&_ArrayVariable;
id  *OBJCCLASS_ArrayVariable(void) { return &ArrayVariable; }
struct _SHARED  _ArrayVariable = {
  (id)&__ArrayVariable,
  (id)&_Variable,
  "ArrayVariable",
  0,
  sizeof(struct ArrayVariable_PRIVATE),
  7,
  _ArrayVariable_nstDispatchTbl,
  41,
  &aryvar_modDesc,
  0,
  (id)0,
  &ArrayVariable,
};
id  OBJCCFUNC_ArrayVariable(void) { return (id)&_ArrayVariable; }
id  OBJCCSUPER_ArrayVariable(void) { return _ArrayVariable.clsSuper; }
struct _SHARED __ArrayVariable = {
  (id)&__Object,
  (id)&__Variable,
  "ArrayVariable",
  0,
  sizeof(struct _SHARED),
  2,
  _ArrayVariable_clsDispatchTbl,
  34,
  &aryvar_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ArrayVariable(void) { return (id)&__ArrayVariable; }
id  OBJCMSUPER_ArrayVariable(void) { return __ArrayVariable.clsSuper; }
static char *_selTransTbl[] ={
"size",
"new",
"value:",
"new:",
"at:",
"add:",
"addAll:",
"at:put:",
0
};
struct modDescriptor aryvar_modDesc = {
  "aryvar",
  "objc3.3.19",
  0L,
  0,
  0,
  &ArrayVariable,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_aryvar(void)
{
  selTransTbl = _selTransTbl;
  return &aryvar_modDesc;
}
int _OBJCPOSTLINK_aryvar = 1;


