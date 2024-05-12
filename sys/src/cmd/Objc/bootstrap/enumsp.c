# 1 "enumsp.m"
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
extern struct modDescriptor  *_OBJCBIND_enumsp(void);
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
extern struct modDescriptor enumsp_modDesc;

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
# 22 "./enumsp.h"
struct EnumSpec_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./enumsp.h"
id keyw,name;
id lbrace;
id enumtors;
id rbrace;};

# 22 "./enumsp.h"
extern id  EnumSpec;

# 22 "./enumsp.h"
extern struct _SHARED _EnumSpec;
extern struct _SHARED __EnumSpec;


# 37 "enumsp.m"
static int i_EnumSpec_lineno(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 39 "enumsp.m"
return(objcT0=self->keyw,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_EnumSpec_filename(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 44 "enumsp.m"
return(objcT1=self->keyw,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_EnumSpec_keyw_(struct EnumSpec_PRIVATE *self,SEL _cmd,id akeyw)
{self->
keyw=akeyw;
return(id)self;
}

static id i_EnumSpec_name_(struct EnumSpec_PRIVATE *self,SEL _cmd,id akeyw)
{self->
name=akeyw;
return(id)self;
}

static id i_EnumSpec_lbrace_(struct EnumSpec_PRIVATE *self,SEL _cmd,id lb)
{self->
lbrace=lb;
return(id)self;
}

static id i_EnumSpec_rbrace_(struct EnumSpec_PRIVATE *self,SEL _cmd,id rb)
{self->
rbrace=rb;
return(id)self;
}

static id i_EnumSpec_enumtors_(struct EnumSpec_PRIVATE *self,SEL _cmd,id aList)
{

(void)0;self->
enumtors=aList;
return(id)self;
}

static BOOL i_EnumSpec_isscalartype(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_EnumSpec_isvolatile(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_EnumSpec_isrefcounted(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static id i_EnumSpec_synth(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 96 "enumsp.m"
if(self->enumtors)
(objcT2=self->enumtors,(*(id(*)(id,SEL,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],_cmd));
return(id)self;
}

static id i_EnumSpec_gen(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4;

# 103 "enumsp.m"
(objcT3=self->keyw,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
(objcT4=self->name,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));
if(self->enumtors){
id objcT5,objcT6,objcT13;

# 106 "enumsp.m"
int comma=0;
int i,n=(objcT5=self->enumtors,(*(unsigned(*)(id,SEL))_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));

if(self->lbrace)
(objcT6=self->lbrace,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
else
gc('{');
if(n){
id objcT7,objcT8,objcT9;

# 114 "enumsp.m"
id e=(objcT7=self->enumtors,(*(id(*)(id,SEL,unsigned))_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],0));
(objcT8=e,(*_imp(objcT8,selTransTbl[3]))(objcT8,selTransTbl[3]));
comma=(objcT9=e,(*(BOOL(*)(id,SEL))_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
}
for(i=1;i<n;i++){
id objcT10,objcT11,objcT12;

# 119 "enumsp.m"
id e=(objcT10=self->enumtors,(*(id(*)(id,SEL,unsigned))_imp(objcT10,selTransTbl[5]))(objcT10,selTransTbl[5],i));
if(comma)gc(',');
(objcT11=e,(*_imp(objcT11,selTransTbl[3]))(objcT11,selTransTbl[3]));
comma=(objcT12=e,(*(BOOL(*)(id,SEL))_imp(objcT12,selTransTbl[6]))(objcT12,selTransTbl[6]));
}
if(self->rbrace)
(objcT13=self->rbrace,(*_imp(objcT13,selTransTbl[3]))(objcT13,selTransTbl[3]));
else
gc('}');
}
return(id)self;
}

static BOOL i_EnumSpec_canforward(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_EnumSpec_isselptr(struct EnumSpec_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _EnumSpec_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _EnumSpec_nstDispatchTbl[] ={
{"lineno",(id (*)())i_EnumSpec_lineno},
{"filename",(id (*)())i_EnumSpec_filename},
{"keyw:",(id (*)())i_EnumSpec_keyw_},
{"name:",(id (*)())i_EnumSpec_name_},
{"lbrace:",(id (*)())i_EnumSpec_lbrace_},
{"rbrace:",(id (*)())i_EnumSpec_rbrace_},
{"enumtors:",(id (*)())i_EnumSpec_enumtors_},
{"isscalartype",(id (*)())i_EnumSpec_isscalartype},
{"isvolatile",(id (*)())i_EnumSpec_isvolatile},
{"isrefcounted",(id (*)())i_EnumSpec_isrefcounted},
{"synth",(id (*)())i_EnumSpec_synth},
{"gen",(id (*)())i_EnumSpec_gen},
{"canforward",(id (*)())i_EnumSpec_canforward},
{"isselptr",(id (*)())i_EnumSpec_isselptr},
{(char*)0,(id (*)())0}
};
id EnumSpec = (id)&_EnumSpec;
id  *OBJCCLASS_EnumSpec(void) { return &EnumSpec; }
struct _SHARED  _EnumSpec = {
  (id)&__EnumSpec,
  (id)&_Node,
  "EnumSpec",
  0,
  sizeof(struct EnumSpec_PRIVATE),
  14,
  _EnumSpec_nstDispatchTbl,
  41,
  &enumsp_modDesc,
  0,
  (id)0,
  &EnumSpec,
};
id  OBJCCFUNC_EnumSpec(void) { return (id)&_EnumSpec; }
id  OBJCCSUPER_EnumSpec(void) { return _EnumSpec.clsSuper; }
struct _SHARED __EnumSpec = {
  (id)&__Object,
  (id)&__Node,
  "EnumSpec",
  0,
  sizeof(struct _SHARED),
  0,
  _EnumSpec_clsDispatchTbl,
  34,
  &enumsp_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_EnumSpec(void) { return (id)&__EnumSpec; }
id  OBJCMSUPER_EnumSpec(void) { return __EnumSpec.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"elementsPerform:",
"gen",
"size",
"at:",
"isenumtor",
0
};
struct modDescriptor enumsp_modDesc = {
  "enumsp",
  "objc3.3.19",
  0L,
  0,
  0,
  &EnumSpec,
  7,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_enumsp(void)
{
  selTransTbl = _selTransTbl;
  return &enumsp_modDesc;
}
int _OBJCPOSTLINK_enumsp = 1;


