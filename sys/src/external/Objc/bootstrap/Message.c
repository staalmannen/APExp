# 1 "Message.m"
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
extern struct modDescriptor  *_OBJCBIND_Message(void);
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
extern struct modDescriptor Message_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stddef.h"
#include <stddef.h>

# 55 "./objcrt.h"
typedef char*SEL;
typedef char*STR;
typedef char BOOL;
typedef FILE*IOD;
typedef id SHR;
# 64 "./objcrt.h"
typedef id(*IMP)();


typedef void(*ARGIMP)(id,SEL,void*);
# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 117 "./objcrt.h"
struct objcrt_private
{
id isa;
# 123 "./objcrt.h"
unsigned short attr;
unsigned short objID;

};

struct objcrt_shared
{
id isa;
# 134 "./objcrt.h"
id clsSuper;
char*clsName;
char*clsTypes;
short clsSizInstance;
short clsSizDict;
struct objcrt_slt*clsDispTable;
long clsStatus;
struct objcrt_modDescriptor*clsMod;
unsigned clsVersion;
id clsCats;
id*clsGlbl;
};

typedef struct objcrt_shared*Cls_t;
# 179 "./objcrt.h"
struct objcrt_slt
{
SEL _cmd;
IMP _imp;
};
# 189 "./objcrt.h"
struct objcrt_useDescriptor
{
int processed;
struct objcrt_useDescriptor*next;
struct objcrt_useDescriptor***uses;
struct objcrt_modDescriptor*(*bind)();
};
# 201 "./objcrt.h"
typedef struct hashedSelector
{
struct hashedSelector*next;
STR key;
}
HASH,*PHASH;
# 213 "./objcrt.h"
typedef struct objcrt_modDescriptor MOD,*PMOD;
typedef struct objcrt_methodDescriptor METH,*PMETH;

struct objcrt_modDescriptor
{
STR modName;
STR modVersion;
long modStatus;
SEL modMinSel;
SEL modMaxSel;
id*modClsLst;
short modSelRef;
SEL*modSelTbl;
PMETH modMapTbl;
};

struct objcrt_modEntry
{
PMOD(*modLink)();
PMOD modInfo;
};

typedef struct objcrt_modEntry*Mentry_t;

struct objcrt_methodDescriptor
{
id*cls;
SEL*sel;
IMP imp;
};
# 256 "./objcrt.h"
extern BOOL msgFlag;
extern FILE*msgIOD;
extern FILE*dbgIOD;
extern BOOL allocFlag;
extern BOOL dbgFlag;
extern BOOL noCacheFlag;
extern BOOL noNilRcvr;
# 269 "./objcrt.h"
SEL selUid(STR);
STR selName(SEL);
void dbg(char*fmt,...);
void loadobjc(void*modPtr);
void unloadobjc(void*modPtr);
# 286 "./objcrt.h"
IMP _imp(id,SEL);
IMP _impSuper(id,SEL);
# 291 "./objcrt.h"
IMP fwdimp(id,SEL,IMP);
IMP fwdimpSuper(id,SEL,IMP);
void fwdmsg(id,SEL,void*,ARGIMP);
id selptrfwd(id,SEL,id,id,id,id);


id idincref(id obj);
id idassign(id*lhs,id rhs);
id iddecref(id obj);
# 320 "./objcrt.h"
extern id(*oc_alloc)(id,unsigned int);
extern id(*oc_dealloc)(id);
extern id(*oc_copy)(id,unsigned int);
extern id(*oc_error)(id,STR,va_list);

extern id(*oc_cvtToId)(STR);
extern SEL(*oc_cvtToSel)(STR);

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

void addSubclassesTo(id c,STR name);

id newsubclass(STR name,id superClass,int ivars,int cvars);
void linkclass(id aclass);
void unlinkclass(id aclass);

void addMethods(id src,id dst);

void poseAs(id posing,id target);
id swapclass(id self,id target);
# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 37 "./Message.h"
struct Message_PRIVATE {

# 42 "./Object.h"
id isa;
# 46 "./Object.h"
unsigned short attr;
unsigned short objID;
# 39 "./Message.h"
SEL selector;
ARGIMP dispatch;
void*args;};

# 37 "./Message.h"
extern id  Message;

# 37 "./Message.h"
extern struct _SHARED _Message;
extern struct _SHARED __Message;


# 40 "Message.m"
static id i_Message_selector_dispatch_args_(struct Message_PRIVATE *self,SEL _cmd,SEL s,ARGIMP d,void*a)
{self->
selector=s;self->
args=a;self->
dispatch=d;
return(id)self;
}

static id c_Message_new(struct Message_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 50 "Message.m"
return(objcT0=(id)self,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id c_Message_selector_dispatch_args_(struct Message_PRIVATE *self,SEL _cmd,SEL s,ARGIMP d,void*a)
{
id objcT1,objcT2;

# 55 "Message.m"
return(objcT1=(objcT2=__Message.clsSuper,(*_impSuper(objcT2,selTransTbl[1]))((id)self,selTransTbl[1])),(*(id(*)(id,SEL,SEL,ARGIMP,void*))_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],s,d,a));
}

# 64 "Message.m"
static SEL i_Message_selector(struct Message_PRIVATE *self,SEL _cmd)
{
return self->selector;
}

static id i_Message_printOn_(struct Message_PRIVATE *self,SEL _cmd,IOD anIod)
{
fprintf(anIod,"#%s",self->selector);
return(id)self;
}

# 81 "Message.m"
static id i_Message_sentTo_(struct Message_PRIVATE *self,SEL _cmd,id receiver)
{
( *self->dispatch)(receiver,self->selector,self->args);
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Message_clsDispatchTbl[] ={
{"new",(id (*)())c_Message_new},
{"selector:dispatch:args:",(id (*)())c_Message_selector_dispatch_args_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Message_nstDispatchTbl[] ={
{"selector:dispatch:args:",(id (*)())i_Message_selector_dispatch_args_},
{"selector",(id (*)())i_Message_selector},
{"printOn:",(id (*)())i_Message_printOn_},
{"sentTo:",(id (*)())i_Message_sentTo_},
{(char*)0,(id (*)())0}
};
id Message = (id)&_Message;
id  *OBJCCLASS_Message(void) { return &Message; }
struct _SHARED  _Message = {
  (id)&__Message,
  (id)&_Object,
  "Message",
  0,
  sizeof(struct Message_PRIVATE),
  4,
  _Message_nstDispatchTbl,
  41,
  &Message_modDesc,
  0,
  (id)0,
  &Message,
};
id  OBJCCFUNC_Message(void) { return (id)&_Message; }
id  OBJCCSUPER_Message(void) { return _Message.clsSuper; }
struct _SHARED __Message = {
  (id)&__Object,
  (id)&__Object,
  "Message",
  0,
  sizeof(struct _SHARED),
  2,
  _Message_clsDispatchTbl,
  34,
  &Message_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Message(void) { return (id)&__Message; }
id  OBJCMSUPER_Message(void) { return __Message.clsSuper; }
static char *_selTransTbl[] ={
"shouldNotImplement",
"new",
"selector:dispatch:args:",
0
};
struct modDescriptor Message_modDesc = {
  "Message",
  "objc3.3.19",
  0L,
  0,
  0,
  &Message,
  3,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_Message(void)
{
  selTransTbl = _selTransTbl;
  return &Message_modDesc;
}
int _OBJCPOSTLINK_Message = 1;


