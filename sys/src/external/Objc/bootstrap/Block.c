# 1 "Block.m"
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
extern struct modDescriptor  *_OBJCBIND_Block(void);
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
extern struct modDescriptor Block_modDesc;

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

# 42 "./Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//setjmp.h"
#include <setjmp.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 44 "./Block.h"
struct Block_PRIVATE {

# 42 "./Object.h"
id isa;
# 46 "./Object.h"
unsigned short attr;
unsigned short objID;
# 46 "./Block.h"
IMP fn;
IMP dtor;
int nVars;
void**data;
id nextBlock;};

# 44 "./Block.h"
extern id  Block;

# 44 "./Block.h"
extern struct _SHARED _Block;
extern struct _SHARED __Block;


# 53 "Block.m"
id newBlock(int n,IMP f,void*d,IMP c)
{
id objcT0;

# 55 "Block.m"
return(objcT0=Block,(*(id(*)(id,SEL,int,IMP,void**,IMP))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],n,f,(void**)d,c));
}

# 64 "Block.m"
static id
err_fun(id thisBlock,void**data,id msg,id rcv)
{
id objcT1,objcT2;

# 67 "Block.m"
if(rcv)
fprintf(stderr,"%s: ",(objcT1=rcv,(*(STR(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1])));
if(msg)
(objcT2=msg,(*(id(*)(id,SEL,IOD))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],stderr));
else
fprintf(stderr,"(null message)");
if(rcv!=(id)0||msg!=(id)0)
fprintf(stderr,"\n");
abort();
# 79 "Block.m"
}

static id i_Block_blkc_blkfn_blkv_blkdtor_(struct Block_PRIVATE *self,SEL _cmd,int n,IMP f,void**d,IMP c)
{self->
nVars=n;self->
fn=f;self->
data=d;self->
dtor=c;
return(id)self;
}

static id c_Block_new(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 92 "Block.m"
return(objcT3=(id)self,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
}

static id i_Block_copy(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 97 "Block.m"
return(objcT4=(id)self,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));
}

static id i_Block_deepCopy(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 102 "Block.m"
return(objcT5=(id)self,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3]));
}

static id c_Block_blkc_blkfn_blkv_blkdtor_(struct Block_PRIVATE *self,SEL _cmd,int n,IMP f,void**d,IMP c)
{
id objcT6,objcT7;

# 107 "Block.m"
return(objcT6=(objcT7=__Block.clsSuper,(*_impSuper(objcT7,selTransTbl[4]))((id)self,selTransTbl[4])),(*(id(*)(id,SEL,int,IMP,void**,IMP))_imp(objcT6,selTransTbl[0]))(objcT6,selTransTbl[0],n,f,d,c));
}

static id i_Block_free(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 112 "Block.m"
if(self->data)
( *((void(*)(void**))self->dtor))(self->data);
return(objcT8=_Block.clsSuper,(*_impSuper(objcT8,selTransTbl[5]))((id)self,selTransTbl[5]));
}

static id i_Block_release(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 119 "Block.m"
if(self->data)
( *((void(*)(void**))self->dtor))(self->data);
return(objcT9=_Block.clsSuper,(*_impSuper(objcT9,selTransTbl[6]))((id)self,selTransTbl[6]));
}
# 130 "Block.m"
static id errorHandler;
static id defaultHandler;

static id c_Block_errorHandler(struct Block_PRIVATE *self,SEL _cmd)
{
if( !defaultHandler)
{
defaultHandler=newBlock(2,(IMP)err_fun,NULL,NULL);
}
if(errorHandler)
{
return errorHandler;
}
else
{
return defaultHandler;
}
}

static id c_Block_errorHandler_(struct Block_PRIVATE *self,SEL _cmd,id aHandler)
{
id objcT10;

# 151 "Block.m"
id ret=defaultHandler;
defaultHandler=(objcT10=aHandler,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
return ret;
}

static id c_Block_halt_value_(struct Block_PRIVATE *self,SEL _cmd,id message,id receiver)
{
id objcT11,objcT13;

# 158 "Block.m"
id handler=(objcT11=(id)self,(*_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8]));
if(errorHandler)
{
id objcT12;

# 161 "Block.m"
errorHandler=(objcT12=errorHandler,(*_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9]));

}
return(objcT13=handler,(*_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10],message,receiver));
}

static id i_Block_ifError_(struct Block_PRIVATE *self,SEL _cmd,id aHandler)
{
id objcT17,objcT18;

# 169 "Block.m"
id returnValue;
if(errorHandler)
{
id objcT14,objcT15;

# 172 "Block.m"
errorHandler=(objcT14=errorHandler,(*_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11],(objcT15=aHandler,(*_imp(objcT15,selTransTbl[7]))(objcT15,selTransTbl[7]))));
}
else
{
id objcT16;

# 176 "Block.m"
errorHandler=(objcT16=aHandler,(*_imp(objcT16,selTransTbl[7]))(objcT16,selTransTbl[7]));
}
returnValue=(objcT17=(id)self,(*_imp(objcT17,selTransTbl[12]))(objcT17,selTransTbl[12]));
errorHandler=(objcT18=errorHandler,(*_imp(objcT18,selTransTbl[9]))(objcT18,selTransTbl[9]));
return returnValue;
}

static id i_Block_value_ifError_(struct Block_PRIVATE *self,SEL _cmd,id anObject,id aHandler)
{
id objcT22,objcT23;

# 185 "Block.m"
id returnValue;
if(errorHandler)
{
id objcT19,objcT20;

# 188 "Block.m"
errorHandler=(objcT19=errorHandler,(*_imp(objcT19,selTransTbl[11]))(objcT19,selTransTbl[11],(objcT20=aHandler,(*_imp(objcT20,selTransTbl[7]))(objcT20,selTransTbl[7]))));
}
else
{
id objcT21;

# 192 "Block.m"
errorHandler=(objcT21=aHandler,(*_imp(objcT21,selTransTbl[7]))(objcT21,selTransTbl[7]));
}
returnValue=(objcT22=(id)self,(*_imp(objcT22,selTransTbl[13]))(objcT22,selTransTbl[13],anObject));
(objcT23=aHandler,(*_imp(objcT23,selTransTbl[9]))(objcT23,selTransTbl[9]));
return returnValue;
}

static id i_Block_push_(struct Block_PRIVATE *self,SEL _cmd,id aBlock)
{self->
nextBlock=aBlock;
return(id)self;
}

static id i_Block_pop(struct Block_PRIVATE *self,SEL _cmd)
{
return self->nextBlock;
}

static id i_Block_on_do_(struct Block_PRIVATE *self,SEL _cmd,id aClassOfExceptions,id aHandler)
{
id objcT24,objcT25;

# 212 "Block.m"
id returnValue;
(objcT24=aClassOfExceptions,(*_imp(objcT24,selTransTbl[14]))(objcT24,selTransTbl[14],aHandler));
returnValue=(objcT25=(id)self,(*_imp(objcT25,selTransTbl[12]))(objcT25,selTransTbl[12]));
return returnValue;
}

static id i_Block_value_on_do_(struct Block_PRIVATE *self,SEL _cmd,id anObject,id aClassOfExceptions,id aHandler)
{
id objcT26,objcT27;

# 220 "Block.m"
id returnValue;
(objcT26=aClassOfExceptions,(*_imp(objcT26,selTransTbl[14]))(objcT26,selTransTbl[14],aHandler));
returnValue=(objcT27=(id)self,(*_imp(objcT27,selTransTbl[13]))(objcT27,selTransTbl[13],anObject));
return returnValue;
}

# 233 "Block.m"
static id i_Block_errorNumArgs(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT28;

# 235 "Block.m"
return(objcT28=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT28,selTransTbl[15]))(objcT28,selTransTbl[15],"Block has wrong number of arguments."));
}

static id i_Block_errorGoodHandler(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT29;

# 240 "Block.m"
return(self->nVars==2)?(id)self:(objcT29=(id)self,(*_imp(objcT29,selTransTbl[16]))(objcT29,selTransTbl[16]));
}

static id i_Block_value(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT30;

# 245 "Block.m"
return(self->nVars==0)?(id)( *self->fn)((id)self,self->data):(objcT30=(id)self,(*_imp(objcT30,selTransTbl[16]))(objcT30,selTransTbl[16]));
}

static int i_Block_intvalue(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT31;

# 250 "Block.m"
if(self->nVars!=0)
(objcT31=(id)self,(*_imp(objcT31,selTransTbl[16]))(objcT31,selTransTbl[16]));
return( *((int(*)(id,void*))self->fn))((id)self,self->data);
}

# 267 "Block.m"
static id i_Block_atExit(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT32;

return(objcT32=(id)self,(*_imp(objcT32,selTransTbl[17]))(objcT32,selTransTbl[17]));
# 284 "Block.m"
}

static id i_Block_value_(struct Block_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT33;

# 288 "Block.m"
return(self->nVars==1)?(id)( *self->fn)((id)self,self->data,anObject):(objcT33=(id)self,(*_imp(objcT33,selTransTbl[16]))(objcT33,selTransTbl[16]));
}

static int i_Block_intvalue_(struct Block_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT34;

# 293 "Block.m"
if(self->nVars!=1)
(objcT34=(id)self,(*_imp(objcT34,selTransTbl[16]))(objcT34,selTransTbl[16]));
return( *((int(*)(id,void*,id))self->fn))((id)self,self->data,anObject);
}

static id i_Block_value_value_(struct Block_PRIVATE *self,SEL _cmd,id firstObject,id secondObject)
{
if(self->nVars==2)
{
return(id)( *self->fn)((id)self,self->data,firstObject,secondObject);
}
else
{
id objcT35;

# 306 "Block.m"
return(objcT35=(id)self,(*_imp(objcT35,selTransTbl[16]))(objcT35,selTransTbl[16]));
}
}

static int i_Block_intvalue_value_(struct Block_PRIVATE *self,SEL _cmd,id firstObject,id secondObject)
{
id objcT36;

# 312 "Block.m"
if(self->nVars!=2)
(objcT36=(id)self,(*_imp(objcT36,selTransTbl[16]))(objcT36,selTransTbl[16]));
return( *((int(*)(id,void*,id,id))self->fn))((id)self,self->data,firstObject,secondObject);
}

# 324 "Block.m"
static id i_Block_repeatTimes_(struct Block_PRIVATE *self,SEL _cmd,int n)
{
id objcT37;

# 326 "Block.m"
int i;
for(i=0;i<n;i++)
(objcT37=(id)self,(*_imp(objcT37,selTransTbl[12]))(objcT37,selTransTbl[12]));
return(id)self;
}

static id i_Block_shouldNotImplement(struct Block_PRIVATE *self,SEL _cmd)
{
id objcT38;

(objcT38=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT38,selTransTbl[15]))(objcT38,selTransTbl[15],"Message is not approriate for this class."));
return(id)self;
}

static id i_Block_printOn_(struct Block_PRIVATE *self,SEL _cmd,IOD anIod)
{
id objcT39;

return(objcT39=(id)self,(*_imp(objcT39,selTransTbl[3]))(objcT39,selTransTbl[3]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Block_clsDispatchTbl[] ={
{"new",(id (*)())c_Block_new},
{"blkc:blkfn:blkv:blkdtor:",(id (*)())c_Block_blkc_blkfn_blkv_blkdtor_},
{"errorHandler",(id (*)())c_Block_errorHandler},
{"errorHandler:",(id (*)())c_Block_errorHandler_},
{"halt:value:",(id (*)())c_Block_halt_value_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Block_nstDispatchTbl[] ={
{"blkc:blkfn:blkv:blkdtor:",(id (*)())i_Block_blkc_blkfn_blkv_blkdtor_},
{"copy",(id (*)())i_Block_copy},
{"deepCopy",(id (*)())i_Block_deepCopy},
{"free",(id (*)())i_Block_free},
{"release",(id (*)())i_Block_release},
{"ifError:",(id (*)())i_Block_ifError_},
{"value:ifError:",(id (*)())i_Block_value_ifError_},
{"push:",(id (*)())i_Block_push_},
{"pop",(id (*)())i_Block_pop},
{"on:do:",(id (*)())i_Block_on_do_},
{"value:on:do:",(id (*)())i_Block_value_on_do_},
{"errorNumArgs",(id (*)())i_Block_errorNumArgs},
{"errorGoodHandler",(id (*)())i_Block_errorGoodHandler},
{"value",(id (*)())i_Block_value},
{"intvalue",(id (*)())i_Block_intvalue},
{"atExit",(id (*)())i_Block_atExit},
{"value:",(id (*)())i_Block_value_},
{"intvalue:",(id (*)())i_Block_intvalue_},
{"value:value:",(id (*)())i_Block_value_value_},
{"intvalue:value:",(id (*)())i_Block_intvalue_value_},
{"repeatTimes:",(id (*)())i_Block_repeatTimes_},
{"shouldNotImplement",(id (*)())i_Block_shouldNotImplement},
{"printOn:",(id (*)())i_Block_printOn_},
{(char*)0,(id (*)())0}
};
id Block = (id)&_Block;
id  *OBJCCLASS_Block(void) { return &Block; }
struct _SHARED  _Block = {
  (id)&__Block,
  (id)&_Object,
  "Block",
  0,
  sizeof(struct Block_PRIVATE),
  23,
  _Block_nstDispatchTbl,
  41,
  &Block_modDesc,
  0,
  (id)0,
  &Block,
};
id  OBJCCFUNC_Block(void) { return (id)&_Block; }
id  OBJCCSUPER_Block(void) { return _Block.clsSuper; }
struct _SHARED __Block = {
  (id)&__Object,
  (id)&__Object,
  "Block",
  0,
  sizeof(struct _SHARED),
  5,
  _Block_clsDispatchTbl,
  34,
  &Block_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Block(void) { return (id)&__Block; }
id  OBJCMSUPER_Block(void) { return __Block.clsSuper; }
static char *_selTransTbl[] ={
"blkc:blkfn:blkv:blkdtor:",
"name",
"printOn:",
"shouldNotImplement",
"new",
"free",
"release",
"errorGoodHandler",
"errorHandler",
"pop",
"value:value:",
"push:",
"value",
"value:",
"install:",
"error:",
"errorNumArgs",
"notImplemented",
0
};
struct modDescriptor Block_modDesc = {
  "Block",
  "objc3.3.19",
  0L,
  0,
  0,
  &Block,
  18,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_Block(void)
{
  selTransTbl = _selTransTbl;
  return &Block_modDesc;
}
int _OBJCPOSTLINK_Block = 1;


