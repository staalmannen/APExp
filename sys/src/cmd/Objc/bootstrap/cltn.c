# 1 "cltn.m"
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
extern struct modDescriptor  *_OBJCBIND_cltn(void);
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
extern struct modDescriptor cltn_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

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

# 28 "./set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 31 "./ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 38 "./../../include/objcrt/Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 32 "./cltn.h"
struct Cltn_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;};

# 32 "./cltn.h"
extern id  Cltn;

# 32 "./cltn.h"
extern struct _SHARED _Cltn;
extern struct _SHARED __Cltn;


# 35 "cltn.m"
static id i_Cltn_eachElement(struct Cltn_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 37 "cltn.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
}

static BOOL i_Cltn_includes_(struct Cltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT1;

# 42 "cltn.m"
(objcT1=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0],_cmd));
return(BOOL)0;
}


static id i_Cltn_add_(struct Cltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT2;

# 49 "cltn.m"
return(objcT2=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0],_cmd));
}

static id i_Cltn_remove_(struct Cltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT3;

# 54 "cltn.m"
return(objcT3=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0],_cmd));
}

static id i_Cltn_addYourself(struct Cltn_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 59 "cltn.m"
return(objcT4=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT4,selTransTbl[0]))(objcT4,selTransTbl[0],_cmd));
}

static id i_Cltn_emptyYourself(struct Cltn_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 64 "cltn.m"
return(objcT5=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT5,selTransTbl[0]))(objcT5,selTransTbl[0],_cmd));
}

static id i_Cltn_perform_with_with_with_(struct Cltn_PRIVATE *self,SEL _cmd,SEL aSel,id a,id b,id c)
{
id objcT6;
return(objcT6=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT6,selTransTbl[0]))(objcT6,selTransTbl[0],_cmd));
}

# 79 "cltn.m"
static id c_Cltn_with_(struct Cltn_PRIVATE *self,SEL _cmd,int nArgs,...)
{
id objcT7;

# 81 "cltn.m"
id newObject;


va_list vp;

newObject=(objcT7=(id)self,(*_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1]));
# 101 "cltn.m"
va_start(vp,nArgs);
while(nArgs-->0)
{
id objcT8;

# 104 "cltn.m"
id anObject=va_arg(vp,id);
(objcT8=newObject,(*_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2],anObject));
}
va_end(vp);


return newObject;
}

static id c_Cltn_with_with_(struct Cltn_PRIVATE *self,SEL _cmd,id firstObject,id nextObject)
{
id objcT9,objcT10,objcT11;

# 115 "cltn.m"
return(objcT9=(objcT10=(objcT11=(id)self,(*_imp(objcT11,selTransTbl[1]))(objcT11,selTransTbl[1])),(*_imp(objcT10,selTransTbl[2]))(objcT10,selTransTbl[2],firstObject)),(*_imp(objcT9,selTransTbl[2]))(objcT9,selTransTbl[2],nextObject));
}

static id c_Cltn_add_(struct Cltn_PRIVATE *self,SEL _cmd,id firstObject)
{
id objcT12,objcT13;

# 120 "cltn.m"
return(objcT12=(objcT13=(id)self,(*_imp(objcT13,selTransTbl[1]))(objcT13,selTransTbl[1])),(*_imp(objcT12,selTransTbl[2]))(objcT12,selTransTbl[2],firstObject));
}

# 129 "cltn.m"
static BOOL i_Cltn_includesAllOf_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT14,objcT15,objcT17;

# 137 "cltn.m"
BOOL res=(BOOL)1;
id e,seq=(objcT14=aCltn,(*_imp(objcT14,selTransTbl[3]))(objcT14,selTransTbl[3]));
while((e=(objcT15=seq,(*_imp(objcT15,selTransTbl[4]))(objcT15,selTransTbl[4]))))
{
id objcT16;

# 141 "cltn.m"
if( !(objcT16=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT16,selTransTbl[5]))(objcT16,selTransTbl[5],e)))
{
res=(BOOL)0;
goto done;
}
}
done:

(objcT17=seq,(*_imp(objcT17,selTransTbl[6]))(objcT17,selTransTbl[6]));

return res;
}
}

static BOOL i_Cltn_includesAnyOf_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT18,objcT19,objcT21;

# 163 "cltn.m"
BOOL res=(BOOL)0;
id e,seq=(objcT18=aCltn,(*_imp(objcT18,selTransTbl[3]))(objcT18,selTransTbl[3]));
while((e=(objcT19=seq,(*_imp(objcT19,selTransTbl[4]))(objcT19,selTransTbl[4]))))
{
id objcT20;

# 167 "cltn.m"
if((objcT20=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT20,selTransTbl[5]))(objcT20,selTransTbl[5],e)))
{
res=(BOOL)1;
goto done;
}
}
done:

(objcT21=seq,(*_imp(objcT21,selTransTbl[6]))(objcT21,selTransTbl[6]));

return res;
}
}

# 187 "cltn.m"
static id i_Cltn_addAll_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT22;

# 191 "cltn.m"
(objcT22=(id)self,(*_imp(objcT22,selTransTbl[7]))(objcT22,selTransTbl[7]));
}
else
{
id objcT23,objcT24,objcT26;

# 195 "cltn.m"
id e,seq;

seq=(objcT23=aCltn,(*_imp(objcT23,selTransTbl[3]))(objcT23,selTransTbl[3]));
while((e=(objcT24=seq,(*_imp(objcT24,selTransTbl[4]))(objcT24,selTransTbl[4]))))
{
id objcT25;

# 200 "cltn.m"
(objcT25=(id)self,(*_imp(objcT25,selTransTbl[2]))(objcT25,selTransTbl[2],e));
}

seq=(objcT26=seq,(*_imp(objcT26,selTransTbl[6]))(objcT26,selTransTbl[6]));

}

return(id)self;
}

static id i_Cltn_addContentsOf_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT27;

# 212 "cltn.m"
return(objcT27=(id)self,(*_imp(objcT27,selTransTbl[8]))(objcT27,selTransTbl[8],aCltn));
}

static id i_Cltn_addContentsTo_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT28;

# 217 "cltn.m"
return(objcT28=aCltn,(*_imp(objcT28,selTransTbl[8]))(objcT28,selTransTbl[8],(id)self));
}

static id i_Cltn_removeAll_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT29;

# 224 "cltn.m"
(objcT29=(id)self,(*_imp(objcT29,selTransTbl[9]))(objcT29,selTransTbl[9]));
}
else
{
id objcT30,objcT31,objcT33;

# 228 "cltn.m"
id e,seq;

seq=(objcT30=aCltn,(*_imp(objcT30,selTransTbl[3]))(objcT30,selTransTbl[3]));
while((e=(objcT31=seq,(*_imp(objcT31,selTransTbl[4]))(objcT31,selTransTbl[4]))))
{
id objcT32;

# 233 "cltn.m"
(objcT32=(id)self,(*_imp(objcT32,selTransTbl[10]))(objcT32,selTransTbl[10],e));
}

seq=(objcT33=seq,(*_imp(objcT33,selTransTbl[6]))(objcT33,selTransTbl[6]));

}

return(id)self;
}

static id i_Cltn_removeContentsFrom_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT34;

# 245 "cltn.m"
return(objcT34=aCltn,(*_imp(objcT34,selTransTbl[11]))(objcT34,selTransTbl[11],(id)self));
}

static id i_Cltn_removeContentsOf_(struct Cltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT35;

# 250 "cltn.m"
return(objcT35=(id)self,(*_imp(objcT35,selTransTbl[11]))(objcT35,selTransTbl[11],aCltn));
}

# 259 "cltn.m"
static id i_Cltn_intersection_(struct Cltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT36;

# 263 "cltn.m"
return(objcT36=(id)self,(*_imp(objcT36,selTransTbl[12]))(objcT36,selTransTbl[12]));
}
else
{
id objcT37,objcT38,objcT39,objcT42;

# 267 "cltn.m"
id anElement,elements;
id intersection=(objcT37=self->isa,(*_imp(objcT37,selTransTbl[1]))(objcT37,selTransTbl[1]));

elements=(objcT38=(id)self,(*_imp(objcT38,selTransTbl[3]))(objcT38,selTransTbl[3]));
while((anElement=(objcT39=elements,(*_imp(objcT39,selTransTbl[4]))(objcT39,selTransTbl[4]))))
{
id objcT40,objcT41;

# 273 "cltn.m"
if((objcT40=bag,(*_imp(objcT40,selTransTbl[13]))(objcT40,selTransTbl[13],anElement)))
(objcT41=intersection,(*_imp(objcT41,selTransTbl[2]))(objcT41,selTransTbl[2],anElement));
}

elements=(objcT42=elements,(*_imp(objcT42,selTransTbl[6]))(objcT42,selTransTbl[6]));


return intersection;
}
}

static id i_Cltn_union_(struct Cltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT43;

# 288 "cltn.m"
return(objcT43=(id)self,(*_imp(objcT43,selTransTbl[12]))(objcT43,selTransTbl[12]));
}
else
{
id objcT44,objcT45;

# 292 "cltn.m"
return(objcT44=(objcT45=(id)self,(*_imp(objcT45,selTransTbl[12]))(objcT45,selTransTbl[12])),(*_imp(objcT44,selTransTbl[8]))(objcT44,selTransTbl[8],bag));
}
}

static id i_Cltn_difference_(struct Cltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT46;

# 300 "cltn.m"
return(objcT46=self->isa,(*_imp(objcT46,selTransTbl[1]))(objcT46,selTransTbl[1]));
}
else
{
id objcT47,objcT48;

# 304 "cltn.m"
return(objcT47=(objcT48=(id)self,(*_imp(objcT48,selTransTbl[12]))(objcT48,selTransTbl[12])),(*_imp(objcT47,selTransTbl[11]))(objcT47,selTransTbl[11],bag));
}
}

# 36 "./set.h"
extern id  Set;

# 314 "cltn.m"
static id i_Cltn_asSet(struct Cltn_PRIVATE *self,SEL _cmd)
{
id objcT49,objcT50;
if((objcT49=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT49,selTransTbl[14]))(objcT49,selTransTbl[14],(id)(objcT50=Set,(*_imp(objcT50,selTransTbl[15]))(objcT50,selTransTbl[15])))))
{
return(id)self;
}
else
{
id objcT51,objcT52;

# 323 "cltn.m"
return(objcT51=(objcT52=Set,(*_imp(objcT52,selTransTbl[1]))(objcT52,selTransTbl[1])),(*_imp(objcT51,selTransTbl[8]))(objcT51,selTransTbl[8],(id)self));
}
}

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 327 "cltn.m"
static id i_Cltn_asOrdCltn(struct Cltn_PRIVATE *self,SEL _cmd)
{
id objcT53,objcT54;
if((objcT53=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT53,selTransTbl[14]))(objcT53,selTransTbl[14],(id)(objcT54=OrdCltn,(*_imp(objcT54,selTransTbl[15]))(objcT54,selTransTbl[15])))))
{
return(id)self;
}
else
{
id objcT55,objcT56;

# 336 "cltn.m"
return(objcT55=(objcT56=OrdCltn,(*_imp(objcT56,selTransTbl[1]))(objcT56,selTransTbl[1])),(*_imp(objcT55,selTransTbl[8]))(objcT55,selTransTbl[8],(id)self));
}
}

# 347 "cltn.m"
static id i_Cltn_detect_(struct Cltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT57,objcT58,objcT61;

# 349 "cltn.m"
id e,seq;

seq=(objcT57=(id)self,(*_imp(objcT57,selTransTbl[3]))(objcT57,selTransTbl[3]));

while((e=(objcT58=seq,(*_imp(objcT58,selTransTbl[4]))(objcT58,selTransTbl[4]))))
{
id objcT59;

# 355 "cltn.m"
if(((objcT59=aBlock,(*_imp(objcT59,selTransTbl[16]))(objcT59,selTransTbl[16],e))))
{
id objcT60;
seq=(objcT60=seq,(*_imp(objcT60,selTransTbl[6]))(objcT60,selTransTbl[6]));

return e;
}
}


seq=(objcT61=seq,(*_imp(objcT61,selTransTbl[6]))(objcT61,selTransTbl[6]));

return(id)0;
}

static id i_Cltn_detect_ifNone_(struct Cltn_PRIVATE *self,SEL _cmd,id aBlock,id noneBlock)
{
id objcT62,objcT63,objcT66,objcT67;

# 372 "cltn.m"
id e,seq;

seq=(objcT62=(id)self,(*_imp(objcT62,selTransTbl[3]))(objcT62,selTransTbl[3]));

while((e=(objcT63=seq,(*_imp(objcT63,selTransTbl[4]))(objcT63,selTransTbl[4]))))
{
id objcT64;

# 378 "cltn.m"
if(((objcT64=aBlock,(*_imp(objcT64,selTransTbl[16]))(objcT64,selTransTbl[16],e))))
{
id objcT65;
seq=(objcT65=seq,(*_imp(objcT65,selTransTbl[6]))(objcT65,selTransTbl[6]));

return e;
}
}


seq=(objcT66=seq,(*_imp(objcT66,selTransTbl[6]))(objcT66,selTransTbl[6]));

return(objcT67=noneBlock,(*_imp(objcT67,selTransTbl[17]))(objcT67,selTransTbl[17]));
}

static id i_Cltn_select_(struct Cltn_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT68,objcT69,objcT70,objcT73;

# 395 "cltn.m"
id e,seq;
id newObject=(objcT68=self->isa,(*_imp(objcT68,selTransTbl[1]))(objcT68,selTransTbl[1]));

seq=(objcT69=(id)self,(*_imp(objcT69,selTransTbl[3]))(objcT69,selTransTbl[3]));

while((e=(objcT70=seq,(*_imp(objcT70,selTransTbl[4]))(objcT70,selTransTbl[4]))))
{
id objcT71;

# 402 "cltn.m"
if(((objcT71=testBlock,(*_imp(objcT71,selTransTbl[16]))(objcT71,selTransTbl[16],e))))
{
id objcT72;

# 404 "cltn.m"
(objcT72=newObject,(*_imp(objcT72,selTransTbl[2]))(objcT72,selTransTbl[2],e));
}
}


seq=(objcT73=seq,(*_imp(objcT73,selTransTbl[6]))(objcT73,selTransTbl[6]));

return newObject;
}

static id i_Cltn_reject_(struct Cltn_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT74,objcT75,objcT76,objcT79;

# 416 "cltn.m"
id e,seq;
id newObject=(objcT74=self->isa,(*_imp(objcT74,selTransTbl[1]))(objcT74,selTransTbl[1]));

seq=(objcT75=(id)self,(*_imp(objcT75,selTransTbl[3]))(objcT75,selTransTbl[3]));

while((e=(objcT76=seq,(*_imp(objcT76,selTransTbl[4]))(objcT76,selTransTbl[4]))))
{
id objcT77;

# 423 "cltn.m"
if( !((objcT77=testBlock,(*_imp(objcT77,selTransTbl[16]))(objcT77,selTransTbl[16],e))))
{
id objcT78;

# 425 "cltn.m"
(objcT78=newObject,(*_imp(objcT78,selTransTbl[2]))(objcT78,selTransTbl[2],e));
}
}


seq=(objcT79=seq,(*_imp(objcT79,selTransTbl[6]))(objcT79,selTransTbl[6]));

return newObject;
}

static id i_Cltn_collect_(struct Cltn_PRIVATE *self,SEL _cmd,id transformBlock)
{
id objcT80,objcT81,objcT82,objcT85;

# 437 "cltn.m"
id e,seq;
id newObject=(objcT80=self->isa,(*_imp(objcT80,selTransTbl[1]))(objcT80,selTransTbl[1]));

seq=(objcT81=(id)self,(*_imp(objcT81,selTransTbl[3]))(objcT81,selTransTbl[3]));

while((e=(objcT82=seq,(*_imp(objcT82,selTransTbl[4]))(objcT82,selTransTbl[4]))))
{
id objcT83;

# 444 "cltn.m"
id anImage=(objcT83=transformBlock,(*_imp(objcT83,selTransTbl[16]))(objcT83,selTransTbl[16],e));
if(anImage)
{
id objcT84;

# 447 "cltn.m"
(objcT84=newObject,(*_imp(objcT84,selTransTbl[2]))(objcT84,selTransTbl[2],anImage));
}
}


seq=(objcT85=seq,(*_imp(objcT85,selTransTbl[6]))(objcT85,selTransTbl[6]));

return newObject;
}

static unsigned i_Cltn_count_(struct Cltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT86,objcT87,objcT89;

# 459 "cltn.m"
id e,seq;
unsigned c=0;

seq=(objcT86=(id)self,(*_imp(objcT86,selTransTbl[3]))(objcT86,selTransTbl[3]));
while((e=(objcT87=seq,(*_imp(objcT87,selTransTbl[4]))(objcT87,selTransTbl[4]))))
{
id objcT88;

# 465 "cltn.m"
if((objcT88=aBlock,(*_imp(objcT88,selTransTbl[16]))(objcT88,selTransTbl[16],e)))
{
c++;
}
}

seq=(objcT89=seq,(*_imp(objcT89,selTransTbl[6]))(objcT89,selTransTbl[6]));


return c;
}

# 485 "cltn.m"
static id i_Cltn_elementsPerform_(struct Cltn_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT90,objcT91,objcT93;

# 487 "cltn.m"
id e,seq;

seq=(objcT90=(id)self,(*_imp(objcT90,selTransTbl[3]))(objcT90,selTransTbl[3]));
while((e=(objcT91=seq,(*_imp(objcT91,selTransTbl[4]))(objcT91,selTransTbl[4]))))
{
id objcT92;

# 492 "cltn.m"
(objcT92=e,(*(id(*)(id,SEL,SEL))_imp(objcT92,selTransTbl[18]))(objcT92,selTransTbl[18],aSelector));
}

seq=(objcT93=seq,(*_imp(objcT93,selTransTbl[6]))(objcT93,selTransTbl[6]));


return(id)self;
}

static id i_Cltn_elementsPerform_with_(struct Cltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject)
{
id objcT94,objcT95,objcT97;

# 503 "cltn.m"
id e,seq;

seq=(objcT94=(id)self,(*_imp(objcT94,selTransTbl[3]))(objcT94,selTransTbl[3]));
while((e=(objcT95=seq,(*_imp(objcT95,selTransTbl[4]))(objcT95,selTransTbl[4]))))
{
id objcT96;

# 508 "cltn.m"
(objcT96=e,(*(id(*)(id,SEL,SEL,id))_imp(objcT96,selTransTbl[19]))(objcT96,selTransTbl[19],aSelector,anObject));
}

seq=(objcT97=seq,(*_imp(objcT97,selTransTbl[6]))(objcT97,selTransTbl[6]));


return(id)self;
}

static id i_Cltn_elementsPerform_with_with_(struct Cltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject)
{
id objcT98,objcT99,objcT101;

# 519 "cltn.m"
id e,seq;

seq=(objcT98=(id)self,(*_imp(objcT98,selTransTbl[3]))(objcT98,selTransTbl[3]));
while((e=(objcT99=seq,(*_imp(objcT99,selTransTbl[4]))(objcT99,selTransTbl[4]))))
{
id objcT100;

# 524 "cltn.m"
(objcT100=e,(*(id(*)(id,SEL,SEL,id,id))_imp(objcT100,selTransTbl[20]))(objcT100,selTransTbl[20],aSelector,anObject,otherObject));
}

seq=(objcT101=seq,(*_imp(objcT101,selTransTbl[6]))(objcT101,selTransTbl[6]));


return(id)self;
}

static id i_Cltn_elementsPerform_with_with_with_(struct Cltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject,id thirdObj)
{
id objcT102,objcT103,objcT105;

# 535 "cltn.m"
id e,seq;

seq=(objcT102=(id)self,(*_imp(objcT102,selTransTbl[3]))(objcT102,selTransTbl[3]));
while((e=(objcT103=seq,(*_imp(objcT103,selTransTbl[4]))(objcT103,selTransTbl[4]))))
{
id objcT104;

# 540 "cltn.m"
(objcT104=e,(*(id(*)(id,SEL,SEL,id,id,id))_imp(objcT104,selTransTbl[21]))(objcT104,selTransTbl[21],aSelector,anObject,otherObject,thirdObj));
}

seq=(objcT105=seq,(*_imp(objcT105,selTransTbl[6]))(objcT105,selTransTbl[6]));


return(id)self;
}

# 555 "cltn.m"
static id i_Cltn_do_(struct Cltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT106,objcT107,objcT109;

# 557 "cltn.m"
id e,seq;

seq=(objcT106=(id)self,(*_imp(objcT106,selTransTbl[3]))(objcT106,selTransTbl[3]));

while((e=(objcT107=seq,(*_imp(objcT107,selTransTbl[4]))(objcT107,selTransTbl[4]))))
{
id objcT108;

# 563 "cltn.m"
(objcT108=aBlock,(*_imp(objcT108,selTransTbl[16]))(objcT108,selTransTbl[16],e));
}


seq=(objcT109=seq,(*_imp(objcT109,selTransTbl[6]))(objcT109,selTransTbl[6]));

return(id)self;
}
static id i_Cltn_do_until_(struct Cltn_PRIVATE *self,SEL _cmd,id aBlock,BOOL*flag)
{
id objcT110,objcT111,objcT113;

# 573 "cltn.m"
id e,seq;

seq=(objcT110=(id)self,(*_imp(objcT110,selTransTbl[3]))(objcT110,selTransTbl[3]));

while((e=(objcT111=seq,(*_imp(objcT111,selTransTbl[4]))(objcT111,selTransTbl[4]))))
{
id objcT112;

# 579 "cltn.m"
(objcT112=aBlock,(*_imp(objcT112,selTransTbl[16]))(objcT112,selTransTbl[16],e));
if( *flag)
break;
}


seq=(objcT113=seq,(*_imp(objcT113,selTransTbl[6]))(objcT113,selTransTbl[6]));

return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Cltn_clsDispatchTbl[] ={
{"with:",(id (*)())c_Cltn_with_},
{"with:with:",(id (*)())c_Cltn_with_with_},
{"add:",(id (*)())c_Cltn_add_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Cltn_nstDispatchTbl[] ={
{"eachElement",(id (*)())i_Cltn_eachElement},
{"includes:",(id (*)())i_Cltn_includes_},
{"add:",(id (*)())i_Cltn_add_},
{"remove:",(id (*)())i_Cltn_remove_},
{"addYourself",(id (*)())i_Cltn_addYourself},
{"emptyYourself",(id (*)())i_Cltn_emptyYourself},
{"perform:with:with:with:",(id (*)())i_Cltn_perform_with_with_with_},
{"includesAllOf:",(id (*)())i_Cltn_includesAllOf_},
{"includesAnyOf:",(id (*)())i_Cltn_includesAnyOf_},
{"addAll:",(id (*)())i_Cltn_addAll_},
{"addContentsOf:",(id (*)())i_Cltn_addContentsOf_},
{"addContentsTo:",(id (*)())i_Cltn_addContentsTo_},
{"removeAll:",(id (*)())i_Cltn_removeAll_},
{"removeContentsFrom:",(id (*)())i_Cltn_removeContentsFrom_},
{"removeContentsOf:",(id (*)())i_Cltn_removeContentsOf_},
{"intersection:",(id (*)())i_Cltn_intersection_},
{"union:",(id (*)())i_Cltn_union_},
{"difference:",(id (*)())i_Cltn_difference_},
{"asSet",(id (*)())i_Cltn_asSet},
{"asOrdCltn",(id (*)())i_Cltn_asOrdCltn},
{"detect:",(id (*)())i_Cltn_detect_},
{"detect:ifNone:",(id (*)())i_Cltn_detect_ifNone_},
{"select:",(id (*)())i_Cltn_select_},
{"reject:",(id (*)())i_Cltn_reject_},
{"collect:",(id (*)())i_Cltn_collect_},
{"count:",(id (*)())i_Cltn_count_},
{"elementsPerform:",(id (*)())i_Cltn_elementsPerform_},
{"elementsPerform:with:",(id (*)())i_Cltn_elementsPerform_with_},
{"elementsPerform:with:with:",(id (*)())i_Cltn_elementsPerform_with_with_},
{"elementsPerform:with:with:with:",(id (*)())i_Cltn_elementsPerform_with_with_with_},
{"do:",(id (*)())i_Cltn_do_},
{"do:until:",(id (*)())i_Cltn_do_until_},
{(char*)0,(id (*)())0}
};
id Cltn = (id)&_Cltn;
id  *OBJCCLASS_Cltn(void) { return &Cltn; }
struct _SHARED  _Cltn = {
  (id)&__Cltn,
  (id)&_Object,
  "Cltn",
  0,
  sizeof(struct Cltn_PRIVATE),
  32,
  _Cltn_nstDispatchTbl,
  41,
  &cltn_modDesc,
  0,
  (id)0,
  &Cltn,
};
id  OBJCCFUNC_Cltn(void) { return (id)&_Cltn; }
id  OBJCCSUPER_Cltn(void) { return _Cltn.clsSuper; }
struct _SHARED __Cltn = {
  (id)&__Object,
  (id)&__Object,
  "Cltn",
  0,
  sizeof(struct _SHARED),
  3,
  _Cltn_clsDispatchTbl,
  34,
  &cltn_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Cltn(void) { return (id)&__Cltn; }
id  OBJCMSUPER_Cltn(void) { return __Cltn.clsSuper; }
static char *_selTransTbl[] ={
"subclassResponsibility:",
"new",
"add:",
"eachElement",
"next",
"includes:",
"free",
"addYourself",
"addAll:",
"emptyYourself",
"remove:",
"removeAll:",
"copy",
"find:",
"isKindOf:",
"class",
"value:",
"value",
"perform:",
"perform:with:",
"perform:with:with:",
"perform:with:with:with:",
0
};
struct modDescriptor cltn_modDesc = {
  "cltn",
  "objc3.3.19",
  0L,
  0,
  0,
  &Cltn,
  22,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_cltn(void)
{
  selTransTbl = _selTransTbl;
  return &cltn_modDesc;
}
int _OBJCPOSTLINK_cltn = 1;


