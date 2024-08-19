# 1 "Exceptn.m"
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
extern struct modDescriptor  *_OBJCBIND_Exceptn(void);
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
extern struct modDescriptor Exceptn_modDesc;

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

# 1 "../../util//stdio.h"
#include <stdio.h>

# 42 "./Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 37 "./Exceptn.h"
struct Exception_PRIVATE {

# 42 "./Object.h"
id isa;
# 46 "./Object.h"
unsigned short attr;
unsigned short objID;
# 39 "./Exceptn.h"
id messageText;
id tag;
id resumeHandler;};
struct Exception_SHARED {
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

# 45 "./Exceptn.h"
id handler;};

# 37 "./Exceptn.h"
extern id  Exception;

# 37 "./Exceptn.h"
extern struct Exception_SHARED _Exception;
extern struct _SHARED __Exception;


# 41 "Exceptn.m"
static id c_Exception_install_(struct Exception_PRIVATE *self,SEL _cmd,id aHandler)
{
if(((struct Exception_SHARED *)self)->handler)
{
id objcT0;
((struct Exception_SHARED *)self)->
# 45 "Exceptn.m"
handler=(objcT0=aHandler,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],((struct Exception_SHARED *)self)->handler));
}
else
{((struct Exception_SHARED *)self)->
handler=aHandler;
}
return(id)self;
}

# 60 "Exceptn.m"
static id i_Exception_defaultAction(struct Exception_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 62 "Exceptn.m"
return(objcT1=(id)self,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

# 71 "Exceptn.m"
static id c_Exception_signal(struct Exception_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 73 "Exceptn.m"
return(objcT2=(objcT3=(id)self,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2])),(*_imp(objcT2,selTransTbl[3]))(objcT2,selTransTbl[3]));
}

static id c_Exception_signal_(struct Exception_PRIVATE *self,SEL _cmd,STR message)
{
id objcT4,objcT5;

# 78 "Exceptn.m"
return(objcT4=(objcT5=(id)self,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2])),(*(id(*)(id,SEL,STR))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4],message));
}

static id i_Exception_free(struct Exception_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7;

# 83 "Exceptn.m"
if(self->messageText)self->
messageText=(objcT6=self->messageText,(*_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5]));
return(objcT7=_Exception.clsSuper,(*_impSuper(objcT7,selTransTbl[5]))((id)self,selTransTbl[5]));
}

# 95 "Exceptn.m"
static id i_Exception_signal(struct Exception_PRIVATE *self,SEL _cmd)
{
if(((struct Exception_SHARED *)self->isa)->handler)
{
id objcT8,objcT9;
self->
# 99 "Exceptn.m"
resumeHandler=((struct Exception_SHARED *)self->isa)->handler;((struct Exception_SHARED *)self->isa)->
handler=(objcT8=((struct Exception_SHARED *)self->isa)->handler,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
return(objcT9=self->resumeHandler,(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7],(id)self));
}
else
{
id objcT10;

# 105 "Exceptn.m"
return(objcT10=(id)self,(*_imp(objcT10,selTransTbl[8]))(objcT10,selTransTbl[8],self->messageText));
}
}

static id i_Exception_signal_(struct Exception_PRIVATE *self,SEL _cmd,STR message)
{
id objcT11,objcT12;

# 111 "Exceptn.m"
return(objcT11=(objcT12=(id)self,(*_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9],message)),(*_imp(objcT11,selTransTbl[3]))(objcT11,selTransTbl[3]));
}

static id i_Exception_messageText(struct Exception_PRIVATE *self,SEL _cmd)
{
return self->messageText;
}

static STR i_Exception_str(struct Exception_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 121 "Exceptn.m"
return(objcT13=self->messageText,(*(STR(*)(id,SEL))_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10]));
}

static id i_Exception_messageText_(struct Exception_PRIVATE *self,SEL _cmd,id message)
{self->
messageText=message;
return(id)self;
}

static id i_Exception_str_(struct Exception_PRIVATE *self,SEL _cmd,STR message)
{
id objcT14,objcT15,objcT16;

# 132 "Exceptn.m"
static id MsgClass;
id aMessage;
if( !MsgClass)
MsgClass=(objcT14=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11],"String"));
return(objcT15=(id)self,(*_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9],(objcT16=MsgClass,(*(id(*)(id,SEL,STR))_imp(objcT16,selTransTbl[12]))(objcT16,selTransTbl[12],message))));
}

# 145 "Exceptn.m"
static id i_Exception_resignalAs_(struct Exception_PRIVATE *self,SEL _cmd,id replacementException)
{
id objcT17;

# 147 "Exceptn.m"
return(objcT17=(id)self,(*_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13]));
}

static id i_Exception_resume(struct Exception_PRIVATE *self,SEL _cmd)
{((struct Exception_SHARED *)self->isa)->
handler=self->resumeHandler;
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Exception_clsDispatchTbl[] ={
{"install:",(id (*)())c_Exception_install_},
{"signal",(id (*)())c_Exception_signal},
{"signal:",(id (*)())c_Exception_signal_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Exception_nstDispatchTbl[] ={
{"defaultAction",(id (*)())i_Exception_defaultAction},
{"free",(id (*)())i_Exception_free},
{"signal",(id (*)())i_Exception_signal},
{"signal:",(id (*)())i_Exception_signal_},
{"messageText",(id (*)())i_Exception_messageText},
{"str",(id (*)())i_Exception_str},
{"messageText:",(id (*)())i_Exception_messageText_},
{"str:",(id (*)())i_Exception_str_},
{"resignalAs:",(id (*)())i_Exception_resignalAs_},
{"resume",(id (*)())i_Exception_resume},
{(char*)0,(id (*)())0}
};
id Exception = (id)&_Exception;
id  *OBJCCLASS_Exception(void) { return &Exception; }
struct Exception_SHARED  _Exception = {
  (id)&__Exception,
  (id)&_Object,
  "Exception",
  0,
  sizeof(struct Exception_PRIVATE),
  10,
  _Exception_nstDispatchTbl,
  41,
  &Exceptn_modDesc,
  0,
  (id)0,
  &Exception,
};
id  OBJCCFUNC_Exception(void) { return (id)&_Exception; }
id  OBJCCSUPER_Exception(void) { return _Exception.clsSuper; }
struct _SHARED __Exception = {
  (id)&__Object,
  (id)&__Object,
  "Exception",
  0,
  sizeof(struct Exception_SHARED),
  3,
  _Exception_clsDispatchTbl,
  34,
  &Exceptn_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Exception(void) { return (id)&__Exception; }
id  OBJCMSUPER_Exception(void) { return __Exception.clsSuper; }
static char *_selTransTbl[] ={
"push:",
"subclassResponsibility",
"new",
"signal",
"signal:",
"free",
"pop",
"value:",
"halt:",
"messageText:",
"str",
"findClass:",
"str:",
"notImplemented",
0
};
struct modDescriptor Exceptn_modDesc = {
  "Exceptn",
  "objc3.3.19",
  0L,
  0,
  0,
  &Exception,
  14,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_Exceptn(void)
{
  selTransTbl = _selTransTbl;
  return &Exceptn_modDesc;
}
int _OBJCPOSTLINK_Exceptn = 1;


