# 1 "Object.m"
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
extern struct modDescriptor  *_OBJCBIND_Object(void);
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
extern struct modDescriptor Object_modDesc;

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

# 40 "./Object.h"
struct Object_PRIVATE {

id isa;
# 46 "./Object.h"
unsigned short attr;
unsigned short objID;};

# 40 "./Object.h"
extern id  Object;

# 40 "./Object.h"
extern struct _SHARED _Object;
extern struct _SHARED __Object;


# 41 "Object.m"
static id c_Object_initialize(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Object_initialize(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

# 58 "Object.m"
static id i_Object_str_(struct Object_PRIVATE *self,SEL _cmd,STR s)
{
id objcT0;

# 60 "Object.m"
return(objcT0=(id)self,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id c_Object_new(struct Object_PRIVATE *self,SEL _cmd)
{
id newObject=( *oc_alloc)((id)self,0);
return newObject;
}

static id i_Object_new(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 71 "Object.m"
return(objcT1=(id)self,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
}

static id i_Object_increfs(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static id i_Object_copy(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 81 "Object.m"
id newObject=( *oc_copy)((id)self,0);
(objcT2=newObject,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
return newObject;
}

static id i_Object_deepCopy(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 88 "Object.m"
id newObject=( *oc_copy)((id)self,0);
(objcT3=newObject,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1]));
return newObject;
}

static id i_Object_free(struct Object_PRIVATE *self,SEL _cmd)
{self->
# 98 "Object.m"
isa=(id)0;
return(oc_dealloc)?( *oc_dealloc)((id)self):(id)0;

}

static id i_Object_decrefs(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static id i_Object_release(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT4;
return(objcT4=(id)self,(*_imp(objcT4,selTransTbl[0]))(objcT4,selTransTbl[0]));
# 116 "Object.m"
}

static id c_Object_free(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static id c_Object_release(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

# 135 "Object.m"
static id i_Object_self(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Object_yourself(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Object_class(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 147 "Object.m"
return(objcT5=self->isa,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]));
}
static id i_Object_superclass(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 151 "Object.m"
return(objcT6=self->isa,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
}
static id i_Object_superClass(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT7;

# 155 "Object.m"
return(objcT7=self->isa,(*_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4]));
}

static id c_Object_class(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id c_Object_superclass(struct Object_PRIVATE *self,SEL _cmd)
{
return((Cls_t)((id)self))->clsSuper;
}

static id c_Object_superClass(struct Object_PRIVATE *self,SEL _cmd)
{
return((Cls_t)((id)self))->clsSuper;
}

static id i_Object_add_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT8;

# 175 "Object.m"
return(objcT8=(id)self,(*_imp(objcT8,selTransTbl[0]))(objcT8,selTransTbl[0]));
}

static STR i_Object_name(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 180 "Object.m"
return(objcT9=self->isa,(*(STR(*)(id,SEL))_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5]));
}

static STR c_Object_name(struct Object_PRIVATE *self,SEL _cmd)
{
return((Cls_t)((id)self))->clsName;
}

static id i_Object_findClass_(struct Object_PRIVATE *self,SEL _cmd,STR name)
{
return( *oc_cvtToId)(name);
}

static SEL i_Object_findSel_(struct Object_PRIVATE *self,SEL _cmd,STR name)
{

return( *oc_cvtToSel)(name);
}

static SEL i_Object_selOfSTR_(struct Object_PRIVATE *self,SEL _cmd,STR name)
{
id objcT10;

# 201 "Object.m"
SEL aSel=(objcT10=(id)self,(*(SEL(*)(id,SEL,STR))_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6],name));
if(aSel)
{
return aSel;
}
else
{
id objcT11;

# 208 "Object.m"
(objcT11=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7],"Selector not found in selector table."));
return NULL;
}
}

static id i_Object_idOfSTR_(struct Object_PRIVATE *self,SEL _cmd,STR aClassName)
{
id objcT12;

# 215 "Object.m"
id aClass=(objcT12=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8],aClassName));
if(aClass)
{
return aClass;
}
else
{
id objcT13;

# 222 "Object.m"
return(objcT13=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7],"Class not linked in application."));
}
}

# 233 "Object.m"
static unsigned i_Object_hash(struct Object_PRIVATE *self,SEL _cmd)
{
# 239 "Object.m"
return(unsigned)((id)self-(id)0);
}

static BOOL i_Object_isEqual_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
return(BOOL)(anObject==(id)self);
}

static STR i_Object_str(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT14;

# 249 "Object.m"
return(objcT14=self->isa,(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[5]))(objcT14,selTransTbl[5]));
}

static unsigned i_Object_size(struct Object_PRIVATE *self,SEL _cmd)
{
return 0;
}

static BOOL c_Object_isEqual_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
return(BOOL)((id)self==anObject);
}

static BOOL i_Object_isSame_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
return(BOOL)((id)self==anObject);
}

static BOOL i_Object_notEqual_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT15;

# 269 "Object.m"
return(objcT15=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9],anObject))==(BOOL)0;
}

static BOOL i_Object_notSame_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT16;

# 274 "Object.m"
return(BOOL) !(objcT16=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT16,selTransTbl[10]))(objcT16,selTransTbl[10],anObject));
}

static int i_Object_compare_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT17;

# 279 "Object.m"
(objcT17=(id)self,(*_imp(objcT17,selTransTbl[11]))(objcT17,selTransTbl[11]));
return 0;
}

static int i_Object_invertCompare_(struct Object_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT18;

# 285 "Object.m"
int cmp=(objcT18=(id)self,(*(int(*)(id,SEL,id))_imp(objcT18,selTransTbl[12]))(objcT18,selTransTbl[12],anObject));
return cmp? -cmp:0;
}

# 296 "Object.m"
static BOOL i_Object_respondsTo_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
Cls_t cls;
unsigned n;
id ncls=self->isa;
struct objcrt_slt*smt;

do
{
cls=((Cls_t)(ncls));
for(smt=cls->clsDispTable,n=cls->clsSizDict;n--;smt++)
{

if(smt->_cmd==aSelector)
return(BOOL)1;
}
}
while((ncls=cls->clsSuper));

return(BOOL)0;
}

static BOOL i_Object_isMemberOf_(struct Object_PRIVATE *self,SEL _cmd,id aClass)
{
return(BOOL)(self->isa==aClass);
}

static BOOL i_Object_isKindOf_(struct Object_PRIVATE *self,SEL _cmd,id aClass)
{
id ncls=self->isa;
Cls_t cls=((Cls_t)(self->isa));

for(;ncls;(ncls=cls->clsSuper))
{
cls=((Cls_t)(ncls));
if(ncls==aClass)
return(BOOL)1;
}

return(BOOL)0;
}

# 343 "Object.m"
static id c_Object_someInstance(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT19;

# 348 "Object.m"
return(objcT19=(id)self,(*_imp(objcT19,selTransTbl[0]))(objcT19,selTransTbl[0]));

}

static id i_Object_nextInstance(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT20;

# 357 "Object.m"
return(objcT20=(id)self,(*_imp(objcT20,selTransTbl[0]))(objcT20,selTransTbl[0]));

}

static id i_Object_become_(struct Object_PRIVATE *self,SEL _cmd,id other)
{
id objcT21;

# 370 "Object.m"
return(objcT21=(id)self,(*_imp(objcT21,selTransTbl[0]))(objcT21,selTransTbl[0]));

}

static id c_Object_become_(struct Object_PRIVATE *self,SEL _cmd,id other)
{
id objcT22;

# 379 "Object.m"
return(objcT22=(id)self,(*_imp(objcT22,selTransTbl[0]))(objcT22,selTransTbl[0]));

}

# 389 "Object.m"
static id c_Object_subclasses(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT23,objcT24,objcT25;

# 391 "Object.m"
id c=(objcT23=(objcT24=Object,(*(id(*)(id,SEL,STR))_imp(objcT24,selTransTbl[13]))(objcT24,selTransTbl[13],"OrdCltn")),(*_imp(objcT23,selTransTbl[14]))(objcT23,selTransTbl[14]));
addSubclassesTo(c,(objcT25=(id)self,(*(STR(*)(id,SEL))_imp(objcT25,selTransTbl[5]))(objcT25,selTransTbl[5])));
return c;
}
static id c_Object_poseAs_(struct Object_PRIVATE *self,SEL _cmd,id superClass)
{
poseAs(((id)self),(superClass));
return(id)self;
}

static id c_Object_addMethodsTo_(struct Object_PRIVATE *self,SEL _cmd,id superClass)
{
addMethods((id)self,superClass);
return(id)self;
}

static id c_Object_subclass_(struct Object_PRIVATE *self,SEL _cmd,STR name)
{
id objcT26;

# 409 "Object.m"
return(objcT26=(id)self,(*(id(*)(id,SEL,STR,int,int))_imp(objcT26,selTransTbl[15]))(objcT26,selTransTbl[15],name,0,0));
}

static id c_Object_subclass___(struct Object_PRIVATE *self,SEL _cmd,STR name,int ivars,int cvars)
{
return newsubclass(name,(id)self,ivars,cvars);
}

static id c_Object_load(struct Object_PRIVATE *self,SEL _cmd)
{
linkclass((id)self);
return(id)self;
}

static id c_Object_unload(struct Object_PRIVATE *self,SEL _cmd)
{
unlinkclass((id)self);
return(id)0;
}

static BOOL
inherits(Cls_t aCls,STR name)
{
id ncls=aCls->clsSuper;

while(ncls)
{
Cls_t cls=((Cls_t)(ncls));
if(strcmp(cls->clsName,name)==0)
return(BOOL)1;
ncls=cls->clsSuper;
}

return(BOOL)0;
}

static BOOL c_Object_inheritsFrom_(struct Object_PRIVATE *self,SEL _cmd,id aClass)
{
id objcT27;

# 447 "Object.m"
return inherits(((Cls_t)((id)self)),(STR)(objcT27=aClass,(*(STR(*)(id,SEL))_imp(objcT27,selTransTbl[5]))(objcT27,selTransTbl[5])));
}

static BOOL c_Object_isSubclassOf_(struct Object_PRIVATE *self,SEL _cmd,id aClass)
{
id objcT28;

# 452 "Object.m"
return(objcT28=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT28,selTransTbl[16]))(objcT28,selTransTbl[16],aClass));
}

# 462 "Object.m"
static id i_Object_subclassResponsibility(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT29;

# 464 "Object.m"
return(objcT29=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT29,selTransTbl[7]))(objcT29,selTransTbl[7],"Subclass should have implemented one of my methods."));
}

static id i_Object_subclassResponsibility_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT30;

# 469 "Object.m"
return(objcT30=(id)self,(*_imp(objcT30,selTransTbl[17]))(objcT30,selTransTbl[17]));
}

static id i_Object_notImplemented(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT31;

# 474 "Object.m"
return(objcT31=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT31,selTransTbl[7]))(objcT31,selTransTbl[7],"Does not implement this message."));
}


static id i_Object_notImplemented_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT32;

# 480 "Object.m"
return(objcT32=(id)self,(*_imp(objcT32,selTransTbl[11]))(objcT32,selTransTbl[11]));
}

static id i_Object_shouldNotImplement(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT33;

# 485 "Object.m"
return(objcT33=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT33,selTransTbl[7]))(objcT33,selTransTbl[7],"Message is not appropriate for this class."));
}

static id i_Object_shouldNotImplement_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT34;

# 490 "Object.m"
return(objcT34=(id)self,(*_imp(objcT34,selTransTbl[0]))(objcT34,selTransTbl[0]));
}

static id i_Object_shouldNotImplement_from_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector,id superClass)
{
id objcT35;

# 495 "Object.m"
return(objcT35=(id)self,(*_imp(objcT35,selTransTbl[0]))(objcT35,selTransTbl[0]));
}

static id i_Object_vsprintf__(struct Object_PRIVATE *self,SEL _cmd,STR format,va_list*ap)
{
id objcT36;

# 500 "Object.m"
return(objcT36=(id)self,(*_imp(objcT36,selTransTbl[0]))(objcT36,selTransTbl[0]));
}

static id i_Object_error_(struct Object_PRIVATE *self,SEL _cmd,STR format,...)
{
id objcT37;

# 505 "Object.m"
va_list ap;
static id MsgClass;
if( !MsgClass)
MsgClass=(objcT37=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT37,selTransTbl[8]))(objcT37,selTransTbl[8],"String"));
# 512 "Object.m"
va_start(ap,format);
if(MsgClass)
{
id objcT38,objcT39;

# 515 "Object.m"
(objcT38=(id)self,(*_imp(objcT38,selTransTbl[18]))(objcT38,selTransTbl[18],(objcT39=MsgClass,(*(id(*)(id,SEL,STR,va_list*))_imp(objcT39,selTransTbl[19]))(objcT39,selTransTbl[19],format, &ap))));
}
else
{
( *oc_error)((id)self,format,ap);
}
va_end(ap);

return(id)self;
}

# 44 "./Block.h"
extern id  Block;

# 526 "Object.m"
static id i_Object_halt_(struct Object_PRIVATE *self,SEL _cmd,id message)
{
id objcT40;

# 528 "Object.m"
(objcT40=Block,(*_imp(objcT40,selTransTbl[20]))(objcT40,selTransTbl[20],message,(id)self));
return(id)self;
}

# 540 "Object.m"
static id i_Object_doesNotRecognize_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT41;

# 542 "Object.m"
return(objcT41=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT41,selTransTbl[7]))(objcT41,selTransTbl[7],"Message not recognized by this class."));
}
static id i_Object_doesNotUnderstand_(struct Object_PRIVATE *self,SEL _cmd,id aMessage)
{
id objcT42,objcT43;

# 546 "Object.m"
return(objcT42=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT42,selTransTbl[21]))(objcT42,selTransTbl[21],(objcT43=aMessage,(*(SEL(*)(id,SEL))_imp(objcT43,selTransTbl[22]))(objcT43,selTransTbl[22]))));
}

# 556 "Object.m"
static IMP i_Object_methodFor_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
return _imp((id)self,aSelector);
}

static IMP c_Object_instanceMethodFor_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
return _impSuper((id)self,aSelector);
}

# 573 "Object.m"
static id i_Object_perform_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector)
{
return( *fwdimp((id)self,aSelector,selptrfwd))((id)self,aSelector);
}

static id i_Object_perform_with_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject)
{

return( *fwdimp((id)self,aSelector,selptrfwd))((id)self,aSelector,anObject);
}

static id i_Object_perform_with_with_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject)
{

return( *fwdimp((id)self,aSelector,selptrfwd))((id)self,aSelector,anObject,otherObject);
}

static id i_Object_perform_with_with_with_(struct Object_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject,id thirdObj)
{

return( *fwdimp((id)self,aSelector,selptrfwd))((id)self,aSelector,anObject,otherObject,thirdObj);
}

# 601 "Object.m"
static id i_Object_print(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT44;

# 603 "Object.m"
return(objcT44=(id)self,(*(id(*)(id,SEL,IOD))_imp(objcT44,selTransTbl[23]))(objcT44,selTransTbl[23],stdout));
}

static id c_Object_print(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT45;

# 608 "Object.m"
printf("%s",(objcT45=(id)self,(*(STR(*)(id,SEL))_imp(objcT45,selTransTbl[5]))(objcT45,selTransTbl[5])));
return(id)self;
}


static id i_Object_printLine(struct Object_PRIVATE *self,SEL _cmd)
{
id objcT46;

# 615 "Object.m"
(objcT46=(id)self,(*_imp(objcT46,selTransTbl[24]))(objcT46,selTransTbl[24]));
printf("\n");
return(id)self;
}

static id i_Object_show(struct Object_PRIVATE *self,SEL _cmd)
{
( *_showOn)((id)self,0);
return(id)self;
}

static id i_Object_printToFile_(struct Object_PRIVATE *self,SEL _cmd,FILE*aFile)
{
id objcT47;

# 637 "Object.m"
return(objcT47=(id)self,(*(id(*)(id,SEL,IOD))_imp(objcT47,selTransTbl[23]))(objcT47,selTransTbl[23],aFile));
}

static id i_Object_printOn_(struct Object_PRIVATE *self,SEL _cmd,IOD anIOD)
{
return(id)self;
}

# 651 "Object.m"
static STR c_Object_objcrtRevision(struct Object_PRIVATE *self,SEL _cmd)
{
return"3.3.37";
}

# 662 "Object.m"
static id c_Object_readFrom_(struct Object_PRIVATE *self,SEL _cmd,STR aFileName)
{
return( *_readFrom)(aFileName);
}
static BOOL i_Object_storeOn_(struct Object_PRIVATE *self,SEL _cmd,STR aFileName)
{
return( *_storeOn)(aFileName,(id)self);
}

# 676 "Object.m"
static id i_Object_fileOutIdsFor_(struct Object_PRIVATE *self,SEL _cmd,id aFiler)
{
return(id)self;
}

static id i_Object_fileInIdsFrom_(struct Object_PRIVATE *self,SEL _cmd,id aFiler)
{
return(id)self;
}

static id i_Object_fileOutIdsFor(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Object_fileInIdsFrom(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Object_fileOutOn_(struct Object_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT48,objcT49;

# 698 "Object.m"
(objcT48=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT48,selTransTbl[25]))(objcT48,selTransTbl[25], &self->isa,'#'));
return(objcT49=(id)self,(*_imp(objcT49,selTransTbl[26]))(objcT49,selTransTbl[26],aFiler));
}
static id c_Object_fileInFrom_(struct Object_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT50;

# 703 "Object.m"
id newObject=( *oc_alloc)((id)self,0);
return(objcT50=newObject,(*_imp(objcT50,selTransTbl[27]))(objcT50,selTransTbl[27],aFiler));
}

static id i_Object_fileInFrom_(struct Object_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT51;

# 709 "Object.m"
return(objcT51=(id)self,(*_imp(objcT51,selTransTbl[28]))(objcT51,selTransTbl[28],aFiler));
}
static id i_Object_fileOut_type_(struct Object_PRIVATE *self,SEL _cmd,void*value,char typeDesc)
{
id objcT52;

# 713 "Object.m"
return(objcT52=(id)self,(*_imp(objcT52,selTransTbl[17]))(objcT52,selTransTbl[17]));
}

static id i_Object_fileIn_type_(struct Object_PRIVATE *self,SEL _cmd,void*value,char typeDesc)
{
id objcT53;

# 718 "Object.m"
return(objcT53=(id)self,(*_imp(objcT53,selTransTbl[17]))(objcT53,selTransTbl[17]));
}

static id i_Object_awake(struct Object_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Object_awakeFrom_(struct Object_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT54;

# 728 "Object.m"
return(objcT54=(id)self,(*_imp(objcT54,selTransTbl[29]))(objcT54,selTransTbl[29]));
}
static struct _SLT _Object_clsDispatchTbl[] ={
{"initialize",(id (*)())c_Object_initialize},
{"new",(id (*)())c_Object_new},
{"free",(id (*)())c_Object_free},
{"release",(id (*)())c_Object_release},
{"class",(id (*)())c_Object_class},
{"superclass",(id (*)())c_Object_superclass},
{"superClass",(id (*)())c_Object_superClass},
{"name",(id (*)())c_Object_name},
{"isEqual:",(id (*)())c_Object_isEqual_},
{"someInstance",(id (*)())c_Object_someInstance},
{"become:",(id (*)())c_Object_become_},
{"subclasses",(id (*)())c_Object_subclasses},
{"poseAs:",(id (*)())c_Object_poseAs_},
{"addMethodsTo:",(id (*)())c_Object_addMethodsTo_},
{"subclass:",(id (*)())c_Object_subclass_},
{"subclass:::",(id (*)())c_Object_subclass___},
{"load",(id (*)())c_Object_load},
{"unload",(id (*)())c_Object_unload},
{"inheritsFrom:",(id (*)())c_Object_inheritsFrom_},
{"isSubclassOf:",(id (*)())c_Object_isSubclassOf_},
{"instanceMethodFor:",(id (*)())c_Object_instanceMethodFor_},
{"print",(id (*)())c_Object_print},
{"objcrtRevision",(id (*)())c_Object_objcrtRevision},
{"readFrom:",(id (*)())c_Object_readFrom_},
{"fileInFrom:",(id (*)())c_Object_fileInFrom_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Object_nstDispatchTbl[] ={
{"initialize",(id (*)())i_Object_initialize},
{"str:",(id (*)())i_Object_str_},
{"new",(id (*)())i_Object_new},
{"increfs",(id (*)())i_Object_increfs},
{"copy",(id (*)())i_Object_copy},
{"deepCopy",(id (*)())i_Object_deepCopy},
{"free",(id (*)())i_Object_free},
{"decrefs",(id (*)())i_Object_decrefs},
{"release",(id (*)())i_Object_release},
{"self",(id (*)())i_Object_self},
{"yourself",(id (*)())i_Object_yourself},
{"class",(id (*)())i_Object_class},
{"superclass",(id (*)())i_Object_superclass},
{"superClass",(id (*)())i_Object_superClass},
{"add:",(id (*)())i_Object_add_},
{"name",(id (*)())i_Object_name},
{"findClass:",(id (*)())i_Object_findClass_},
{"findSel:",(id (*)())i_Object_findSel_},
{"selOfSTR:",(id (*)())i_Object_selOfSTR_},
{"idOfSTR:",(id (*)())i_Object_idOfSTR_},
{"hash",(id (*)())i_Object_hash},
{"isEqual:",(id (*)())i_Object_isEqual_},
{"str",(id (*)())i_Object_str},
{"size",(id (*)())i_Object_size},
{"isSame:",(id (*)())i_Object_isSame_},
{"notEqual:",(id (*)())i_Object_notEqual_},
{"notSame:",(id (*)())i_Object_notSame_},
{"compare:",(id (*)())i_Object_compare_},
{"invertCompare:",(id (*)())i_Object_invertCompare_},
{"respondsTo:",(id (*)())i_Object_respondsTo_},
{"isMemberOf:",(id (*)())i_Object_isMemberOf_},
{"isKindOf:",(id (*)())i_Object_isKindOf_},
{"nextInstance",(id (*)())i_Object_nextInstance},
{"become:",(id (*)())i_Object_become_},
{"subclassResponsibility",(id (*)())i_Object_subclassResponsibility},
{"subclassResponsibility:",(id (*)())i_Object_subclassResponsibility_},
{"notImplemented",(id (*)())i_Object_notImplemented},
{"notImplemented:",(id (*)())i_Object_notImplemented_},
{"shouldNotImplement",(id (*)())i_Object_shouldNotImplement},
{"shouldNotImplement:",(id (*)())i_Object_shouldNotImplement_},
{"shouldNotImplement:from:",(id (*)())i_Object_shouldNotImplement_from_},
{"vsprintf::",(id (*)())i_Object_vsprintf__},
{"error:",(id (*)())i_Object_error_},
{"halt:",(id (*)())i_Object_halt_},
{"doesNotRecognize:",(id (*)())i_Object_doesNotRecognize_},
{"doesNotUnderstand:",(id (*)())i_Object_doesNotUnderstand_},
{"methodFor:",(id (*)())i_Object_methodFor_},
{"perform:",(id (*)())i_Object_perform_},
{"perform:with:",(id (*)())i_Object_perform_with_},
{"perform:with:with:",(id (*)())i_Object_perform_with_with_},
{"perform:with:with:with:",(id (*)())i_Object_perform_with_with_with_},
{"print",(id (*)())i_Object_print},
{"printLine",(id (*)())i_Object_printLine},
{"show",(id (*)())i_Object_show},
{"printToFile:",(id (*)())i_Object_printToFile_},
{"printOn:",(id (*)())i_Object_printOn_},
{"storeOn:",(id (*)())i_Object_storeOn_},
{"fileOutIdsFor:",(id (*)())i_Object_fileOutIdsFor_},
{"fileInIdsFrom:",(id (*)())i_Object_fileInIdsFrom_},
{"fileOutIdsFor",(id (*)())i_Object_fileOutIdsFor},
{"fileInIdsFrom",(id (*)())i_Object_fileInIdsFrom},
{"fileOutOn:",(id (*)())i_Object_fileOutOn_},
{"fileInFrom:",(id (*)())i_Object_fileInFrom_},
{"fileOut:type:",(id (*)())i_Object_fileOut_type_},
{"fileIn:type:",(id (*)())i_Object_fileIn_type_},
{"awake",(id (*)())i_Object_awake},
{"awakeFrom:",(id (*)())i_Object_awakeFrom_},
{(char*)0,(id (*)())0}
};
id Object = (id)&_Object;
id  *OBJCCLASS_Object(void) { return &Object; }
struct _SHARED  _Object = {
  (id)&__Object,
  0,
  "Object",
  0,
  sizeof(struct Object_PRIVATE),
  67,
  _Object_nstDispatchTbl,
  41,
  &Object_modDesc,
  0,
  (id)0,
  &Object,
};
id  OBJCCFUNC_Object(void) { return (id)&_Object; }
id  OBJCCSUPER_Object(void) { return _Object.clsSuper; }
struct _SHARED __Object = {
  (id)&__Object,
  (id)&_Object,
  "Object",
  0,
  sizeof(struct _SHARED),
  25,
  _Object_clsDispatchTbl,
  34,
  &Object_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Object(void) { return (id)&__Object; }
id  OBJCMSUPER_Object(void) { return __Object.clsSuper; }
static char *_selTransTbl[] ={
"shouldNotImplement",
"increfs",
"class",
"superclass",
"superClass",
"name",
"findSel:",
"error:",
"findClass:",
"isEqual:",
"isSame:",
"notImplemented",
"compare:",
"idOfSTR:",
"new",
"subclass:::",
"inheritsFrom:",
"subclassResponsibility",
"halt:",
"vsprintf::",
"halt:value:",
"doesNotRecognize:",
"selector",
"printOn:",
"print",
"fileOut:type:",
"fileOutIdsFor:",
"fileInFrom:",
"fileInIdsFrom:",
"awake",
0
};
struct modDescriptor Object_modDesc = {
  "Object",
  "objc3.3.19",
  0L,
  0,
  0,
  &Object,
  30,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_Object(void)
{
  selTransTbl = _selTransTbl;
  return &Object_modDesc;
}
int _OBJCPOSTLINK_Object = 1;


