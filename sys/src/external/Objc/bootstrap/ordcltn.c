# 1 "ordcltn.m"
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
extern struct modDescriptor  *_OBJCBIND_ordcltn(void);
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
extern struct modDescriptor ordcltn_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//string.h"
#include <string.h>

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

# 31 "./ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 28 "./set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 38 "./../../include/objcrt/Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 41 "ordcltn.m"
typedef struct
{
# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 41 "./ordcltn.h"
struct objcol value;
# 44 "ordcltn.m"
}
TFOrdCltn;
# 39 "./ordcltn.h"
struct OrdCltn_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 41 "./ordcltn.h"
struct objcol value;};

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 39 "./ordcltn.h"
extern struct _SHARED _OrdCltn;
extern struct _SHARED __OrdCltn;


# 55 "ordcltn.m"
static void
ptrinit(id*p,id q,int c)
{
while(c--) *
p++=q;
}

static void
init(objcol_t self,int n,int c)
{
(void)0;
self->count=n;
self->capacity=c;
self->ptr=(id*)OC_Calloc(c*sizeof(id));
}

static id c_OrdCltn_new(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 73 "ordcltn.m"
int n=(16);
id newObject=(objcT0=__OrdCltn.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
# 80 "ordcltn.m"
init( &(((TFOrdCltn*)newObject)->value),0,n);

return newObject;
}

static id c_OrdCltn_new_(struct OrdCltn_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT1,objcT2;

# 87 "ordcltn.m"
id newObject=(objcT1=__OrdCltn.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0]));
init((objcT2=newObject,(*(objcol_t(*)(id,SEL))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1])),0,n);
return newObject;
}

# 98 "ordcltn.m"
static id c_OrdCltn_with_(struct OrdCltn_PRIVATE *self,SEL _cmd,int nArgs,...)
{
id objcT3;

# 100 "ordcltn.m"
id newObject;


va_list vp;

newObject=(objcT3=(id)self,(*_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0]));
# 120 "ordcltn.m"
va_start(vp,nArgs);
while(nArgs-->0)
{
id objcT4;

# 123 "ordcltn.m"
id anObject=va_arg(vp,id);
(objcT4=newObject,(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],anObject));
}
va_end(vp);


return newObject;
}

static id c_OrdCltn_with_with_(struct OrdCltn_PRIVATE *self,SEL _cmd,id firstObject,id nextObject)
{
id objcT5,objcT6,objcT7;

# 134 "ordcltn.m"
return(objcT5=(objcT6=(objcT7=(id)self,(*_imp(objcT7,selTransTbl[0]))(objcT7,selTransTbl[0])),(*_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2],firstObject)),(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2],nextObject));
}

static id c_OrdCltn_add_(struct OrdCltn_PRIVATE *self,SEL _cmd,id firstObject)
{
id objcT8,objcT9;

# 139 "ordcltn.m"
return(objcT8=(objcT9=(id)self,(*_imp(objcT9,selTransTbl[0]))(objcT9,selTransTbl[0])),(*_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2],firstObject));
}

static void
ptrcopy(id*p,id*q,int c)
{
while(c--)
{ *
p++= *q++;
}
}

static void
copy(objcol_t dst,objcol_t src)
{
init(dst,src->count,src->count);
ptrcopy(dst->ptr,src->ptr,src->count);
}

static id i_OrdCltn_copy(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11;

# 160 "ordcltn.m"
id aCopy=(objcT10=_OrdCltn.clsSuper,(*_impSuper(objcT10,selTransTbl[3]))((id)self,selTransTbl[3]));
copy((objcT11=aCopy,(*(objcol_t(*)(id,SEL))_imp(objcT11,selTransTbl[1]))(objcT11,selTransTbl[1])),( &self->value));
return aCopy;
}

static void
ptrdeepcopy(id*p,id*q,int c)
{
while(c--)
{
id objcT12;

# 170 "ordcltn.m"
id obj= *q++; *
p++=(obj)?(objcT12=obj,(*_imp(objcT12,selTransTbl[4]))(objcT12,selTransTbl[4])):(id)0;
}
}

static void
deepcopy(objcol_t dst,objcol_t src)
{
init(dst,src->count,src->count);
ptrdeepcopy(dst->ptr,src->ptr,src->count);
}

static id i_OrdCltn_deepCopy(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14;


id aCopy=(objcT13=_OrdCltn.clsSuper,(*_impSuper(objcT13,selTransTbl[3]))((id)self,selTransTbl[3]));
deepcopy((objcT14=aCopy,(*(objcol_t(*)(id,SEL))_imp(objcT14,selTransTbl[1]))(objcT14,selTransTbl[1])),( &self->value));
return aCopy;
}

static void
empty(objcol_t self)
{
ptrinit(self->ptr,(id)0,self->count);
self->count=0;
}

static id i_OrdCltn_emptyYourself(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
empty(( &self->value));
return(id)self;
}

static void
ptrclear(id*p,int c)
{
while(c--)
{
id objcT15;

# 210 "ordcltn.m"
id obj= *p; *
p++=(obj)?(objcT15=obj,(*_imp(objcT15,selTransTbl[5]))(objcT15,selTransTbl[5])):(id)0;
}
}

static void
freecontents(objcol_t self)
{
ptrclear(self->ptr,self->count);
self->count=0;
}

static id i_OrdCltn_freeContents(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
freecontents(( &self->value));
return(id)self;
}

static void
ptrclearall(id*p,int c)
{
while(c--)
{
id objcT16;

# 233 "ordcltn.m"
id obj= *p; *
p++=(obj)?(objcT16=obj,(*_imp(objcT16,selTransTbl[6]))(objcT16,selTransTbl[6])):(id)0;
}
}

static void
freeall(objcol_t self)
{
ptrclearall(self->ptr,self->count);
self->count=0;
}

static id i_OrdCltn_freeAll(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
freeall(( &self->value));
return(id)self;
}

static void
clear(objcol_t self)
{
self->count=0;
self->capacity=0;
OC_Free(self->ptr);
self->ptr=NULL;
}

static id i_OrdCltn_free(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT17;

# 262 "ordcltn.m"
clear(( &self->value));
return(objcT17=_OrdCltn.clsSuper,(*_impSuper(objcT17,selTransTbl[5]))((id)self,selTransTbl[5]));
}

static id i_OrdCltn_release(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 273 "ordcltn.m"
return(objcT18=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT18,selTransTbl[7]))(objcT18,selTransTbl[7],_cmd));

}

# 283 "ordcltn.m"
static objcol_t i_OrdCltn_objcolvalue(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return &self->value;
}

static unsigned i_OrdCltn_size(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return(unsigned)(( &self->value)->count);
}

static BOOL i_OrdCltn_isEmpty(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return( &self->value)->count==0;
}

static unsigned i_OrdCltn_lastOffset(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return( &self->value)->count-1;
}

# 32 "./cltnseq.h"
extern id  CollectionSequence;

# 35 "./sequence.h"
extern id  Sequence;

# 303 "ordcltn.m"
static id i_OrdCltn_eachElement(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT19,objcT20;

# 305 "ordcltn.m"
id aCarrier=(objcT19=CollectionSequence,(*_imp(objcT19,selTransTbl[8]))(objcT19,selTransTbl[8],(id)self));
return(objcT20=Sequence,(*_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8],aCarrier));
}

static id
ptrfirst(id*p,int n)
{
return(n)?p[0]:(id)0;
}

static id
first(objcol_t self)
{
return ptrfirst(self->ptr,self->count);
}

static id i_OrdCltn_firstElement(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return first(( &self->value));
}

static id
ptrlast(id*p,int n)
{
return(n)?p[n-1]:(id)0;
}

static id
last(objcol_t self)
{
return ptrlast(self->ptr,self->count);
}

static id i_OrdCltn_lastElement(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return last(( &self->value));
}

# 349 "ordcltn.m"
static unsigned
ptrhash(id*p,int n)
{
unsigned code=n;
while(n--)
{
id objcT21;

# 355 "ordcltn.m"
code^=(objcT21= *p++,(*(unsigned(*)(id,SEL))_imp(objcT21,selTransTbl[9]))(objcT21,selTransTbl[9]));
}
return code;
}

static unsigned
hashcontents(objcol_t a)
{
return ptrhash(a->ptr,a->count);
}

static unsigned i_OrdCltn_hash(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return hashcontents( &self->value);
}

static BOOL
ptreq(id*p,id*q,int n)
{
while(n--)
{
id objcT22;

# 376 "ordcltn.m"
if( !(objcT22= *p++,(*(BOOL(*)(id,SEL,id))_imp(objcT22,selTransTbl[10]))(objcT22,selTransTbl[10], *q++)))
{
return(BOOL)0;
}
}
return(BOOL)1;
}

static BOOL
eq(objcol_t a,objcol_t b)
{
if(a->count==b->count)
{
return ptreq(a->ptr,b->ptr,a->count);
}
else
{
return(BOOL)0;
}
}

static BOOL i_OrdCltn_isEqual_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT23;

# 399 "ordcltn.m"
return((id)self==aCltn)?(BOOL)1:eq(( &self->value),(objcT23=aCltn,(*(objcol_t(*)(id,SEL))_imp(objcT23,selTransTbl[1]))(objcT23,selTransTbl[1])));
}

# 408 "ordcltn.m"
static BOOL
needsexpand(objcol_t self)
{
(void)0;
return self->count==self->capacity;
}

static void
expand(objcol_t self)
{
self->capacity=1+2*self->capacity;
self->ptr=(id*)OC_Realloc(self->ptr,sizeof(id)*self->capacity);
memset(self->ptr+self->count,0,sizeof(id)*(self->capacity-self->count));
}

static int
ptraddlast(id*p,id obj,int n)
{
p[n]=obj;
return n+1;
}

static void
addlast(objcol_t self,id obj)
{
if(needsexpand(self))
{
expand(self);
}
self->count=ptraddlast(self->ptr,obj,self->count);
}

static id i_OrdCltn_add_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
addlast(( &self->value),anObject);
return(id)self;
}
else
{
return(id)self;
}
}

static id i_OrdCltn_addYourself(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT24,objcT25,objcT26;

# 455 "ordcltn.m"
int i,n=(objcT24=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT24,selTransTbl[11]))(objcT24,selTransTbl[11]));
for(i=0;i<n;i++)
(objcT25=(id)self,(*_imp(objcT25,selTransTbl[2]))(objcT25,selTransTbl[2],(objcT26=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT26,selTransTbl[12]))(objcT26,selTransTbl[12],i))));
return(id)self;
}

static int
ptraddfirst(id*p,id obj,int n)
{
int m=n;
p+=n;
while(m--)
{
id*q=p-1; *
p= *q;
p=q;
} *
p=obj;
return n+1;
}

static void
addfirst(objcol_t self,id obj)
{
if(needsexpand(self))
{
expand(self);
}
self->count=ptraddfirst(self->ptr,obj,self->count);
}

static id i_OrdCltn_addFirst_(struct OrdCltn_PRIVATE *self,SEL _cmd,id newObject)
{
if(newObject)
{
addfirst(( &self->value),newObject);
return(id)self;
}
else
{
return(id)self;
}
}

static id i_OrdCltn_addLast_(struct OrdCltn_PRIVATE *self,SEL _cmd,id newObject)
{
id objcT27;

# 501 "ordcltn.m"
return(objcT27=(id)self,(*_imp(objcT27,selTransTbl[2]))(objcT27,selTransTbl[2],newObject));
}

static id i_OrdCltn_addIfAbsent_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT28;

# 506 "ordcltn.m"
if((objcT28=(id)self,(*_imp(objcT28,selTransTbl[13]))(objcT28,selTransTbl[13],anObject))==(id)0)
{
id objcT29;

# 508 "ordcltn.m"
(objcT29=(id)self,(*_imp(objcT29,selTransTbl[2]))(objcT29,selTransTbl[2],anObject));
}
return(id)self;
}

static id i_OrdCltn_addIfAbsentMatching_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT30;

# 515 "ordcltn.m"
if((objcT30=(id)self,(*_imp(objcT30,selTransTbl[14]))(objcT30,selTransTbl[14],anObject))==(id)0)
{
id objcT31;

# 517 "ordcltn.m"
(objcT31=(id)self,(*_imp(objcT31,selTransTbl[2]))(objcT31,selTransTbl[2],anObject));
}
return(id)self;
}

# 528 "ordcltn.m"
static int
ptrinsert(id*p,id obj,int i,int n)
{
if(i==n)
{
return ptraddlast(p,obj,n);
}
else
{
return i+ptraddfirst(p+i,obj,n-i);
}
}

static void
insert(objcol_t self,id obj,int i)
{
if(needsexpand(self))
{
expand(self);
}

self->count=ptrinsert(self->ptr,obj,i,self->count);
}

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 552 "ordcltn.m"
static id i_OrdCltn_at_insert_(struct OrdCltn_PRIVATE *self,SEL _cmd,unsigned anOffset,id anObject)
{
if(anObject)
{
id objcT32;

# 556 "ordcltn.m"
if(anOffset>(objcT32=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT32,selTransTbl[11]))(objcT32,selTransTbl[11])))
{
id objcT33,objcT34,objcT35,objcT36;

# 558 "ordcltn.m"
(objcT33=(objcT34=(objcT35=OutOfBounds,(*(id(*)(id,SEL,unsigned))_imp(objcT35,selTransTbl[15]))(objcT35,selTransTbl[15],(objcT36=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT36,selTransTbl[11]))(objcT36,selTransTbl[11])))),(*(id(*)(id,SEL,unsigned))_imp(objcT34,selTransTbl[12]))(objcT34,selTransTbl[12],anOffset)),(*_imp(objcT33,selTransTbl[16]))(objcT33,selTransTbl[16]));
}
else
{
insert(( &self->value),anObject,(int)anOffset);
}
return(id)self;
}
else
{
return(id)self;
}
}

# 28 "./notfound.h"
extern id  NotFound;

# 572 "ordcltn.m"
static id i_OrdCltn_couldntfind(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT37;

# 574 "ordcltn.m"
return(objcT37=NotFound,(*_imp(objcT37,selTransTbl[16]))(objcT37,selTransTbl[16]));
}

static id i_OrdCltn_insert_after_(struct OrdCltn_PRIVATE *self,SEL _cmd,id newObject,id oldObject)
{
if(newObject)
{
id objcT38;

# 581 "ordcltn.m"
unsigned offset=(objcT38=(id)self,(*(unsigned(*)(id,SEL,id))_imp(objcT38,selTransTbl[17]))(objcT38,selTransTbl[17],oldObject));
if(offset==(unsigned) -1)
{
id objcT39;

# 584 "ordcltn.m"
return(objcT39=(id)self,(*_imp(objcT39,selTransTbl[18]))(objcT39,selTransTbl[18]));
}
else
{
id objcT40;

# 588 "ordcltn.m"
return(objcT40=(id)self,(*(id(*)(id,SEL,unsigned,id))_imp(objcT40,selTransTbl[19]))(objcT40,selTransTbl[19],offset+1,newObject));
}
}
else
{
return(id)self;
}
}

static id i_OrdCltn_insert_before_(struct OrdCltn_PRIVATE *self,SEL _cmd,id newObject,id oldObject)
{
if(newObject)
{
id objcT41;

# 601 "ordcltn.m"
unsigned offset=(objcT41=(id)self,(*(unsigned(*)(id,SEL,id))_imp(objcT41,selTransTbl[17]))(objcT41,selTransTbl[17],oldObject));
if(offset==(unsigned) -1)
{
id objcT42;

# 604 "ordcltn.m"
return(objcT42=(id)self,(*_imp(objcT42,selTransTbl[18]))(objcT42,selTransTbl[18]));
}
else
{
id objcT43;

# 608 "ordcltn.m"
return(objcT43=(id)self,(*(id(*)(id,SEL,unsigned,id))_imp(objcT43,selTransTbl[19]))(objcT43,selTransTbl[19],offset-1,newObject));
}
}
else
{
return(id)self;
}
}

# 623 "ordcltn.m"
static id i_OrdCltn_after_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT44;

# 625 "ordcltn.m"
unsigned offset=(objcT44=(id)self,(*(unsigned(*)(id,SEL,id))_imp(objcT44,selTransTbl[17]))(objcT44,selTransTbl[17],anObject));
if(offset==(unsigned) -1)
{
id objcT45;

# 628 "ordcltn.m"
return(objcT45=(id)self,(*_imp(objcT45,selTransTbl[18]))(objcT45,selTransTbl[18]));
}
else
{
id objcT46,objcT47;

# 632 "ordcltn.m"
return(offset==(objcT46=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT46,selTransTbl[20]))(objcT46,selTransTbl[20])))?(id)0:(objcT47=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT47,selTransTbl[12]))(objcT47,selTransTbl[12],offset+1));
}
}

static id i_OrdCltn_before_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT48;

# 638 "ordcltn.m"
unsigned offset=(objcT48=(id)self,(*(unsigned(*)(id,SEL,id))_imp(objcT48,selTransTbl[17]))(objcT48,selTransTbl[17],anObject));
if(offset==(unsigned) -1)
{
id objcT49;

# 641 "ordcltn.m"
return(objcT49=(id)self,(*_imp(objcT49,selTransTbl[18]))(objcT49,selTransTbl[18]));
}
else
{
id objcT50;

# 645 "ordcltn.m"
return(offset==0)?(id)0:(objcT50=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT50,selTransTbl[12]))(objcT50,selTransTbl[12],offset-1));
}
}

static id
at(objcol_t self,int i)
{
(void)0;
return(self->ptr)[i];
}

static id i_OrdCltn_at_(struct OrdCltn_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
id objcT51;

# 658 "ordcltn.m"
if(anOffset>=(objcT51=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT51,selTransTbl[11]))(objcT51,selTransTbl[11])))
{
id objcT52,objcT53,objcT54,objcT55;

# 660 "ordcltn.m"
(objcT52=(objcT53=(objcT54=OutOfBounds,(*(id(*)(id,SEL,unsigned))_imp(objcT54,selTransTbl[15]))(objcT54,selTransTbl[15],(objcT55=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT55,selTransTbl[11]))(objcT55,selTransTbl[11])))),(*(id(*)(id,SEL,unsigned))_imp(objcT53,selTransTbl[12]))(objcT53,selTransTbl[12],anOffset)),(*_imp(objcT52,selTransTbl[16]))(objcT52,selTransTbl[16]));
return(id)0;
}
else
{
return at(( &self->value),anOffset);
}
}

static id
atput(objcol_t self,int i,id obj)
{
id tmp;
(void)0;
tmp=(self->ptr)[i];
(self->ptr)[i]=obj;
return tmp;
}

static id i_OrdCltn_at_put_(struct OrdCltn_PRIVATE *self,SEL _cmd,unsigned anOffset,id anObject)
{
id objcT56;

# 681 "ordcltn.m"
if(anOffset>=(objcT56=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT56,selTransTbl[11]))(objcT56,selTransTbl[11])))
{
id objcT57,objcT58,objcT59,objcT60;

# 683 "ordcltn.m"
(objcT57=(objcT58=(objcT59=OutOfBounds,(*(id(*)(id,SEL,unsigned))_imp(objcT59,selTransTbl[15]))(objcT59,selTransTbl[15],(objcT60=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT60,selTransTbl[11]))(objcT60,selTransTbl[11])))),(*(id(*)(id,SEL,unsigned))_imp(objcT58,selTransTbl[12]))(objcT58,selTransTbl[12],anOffset)),(*_imp(objcT57,selTransTbl[16]))(objcT57,selTransTbl[16]));
return(id)0;
}
else
{
return atput(( &self->value),anOffset,anObject);
}
}

# 698 "ordcltn.m"
static id
ptrremovefirst(id*p,int n)
{
id obj= *p;
n--;
while(n--)
{
id*q=p+1; *
p= *q;
p=q;
} *
p=(id)0;
return obj;
}

static id
removefirst(objcol_t self)
{
if(self->count)
{
id obj=ptrremovefirst(self->ptr,self->count);
self->count--;
return obj;
}
else
{
return(id)0;
}
}

static id i_OrdCltn_removeFirst(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return removefirst(( &self->value));
}

static id
ptrremove(id*p)
{
id obj= *p; *
p=(id)0;
return obj;
}

static id
removelast(objcol_t self)
{
if(self->count)
{
id obj=ptrremove(self->ptr+self->count-1);
self->count--;
return obj;
}
else
{
return(id)0;
}
}

static id i_OrdCltn_removeLast(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
return removelast(( &self->value));
}

static id
ptrremoveat(id*p,int i,int n)
{
if(i==n-1)
{
return ptrremove(p+n-1);
}
else
{
return ptrremovefirst(p+i,n-i);
}
}

static id
removeat(objcol_t self,int i)
{
if(self->count)
{
id obj=ptrremoveat(self->ptr,i,self->count);
self->count--;
return obj;
}
else
{
return(id)0;
}
}

static id i_OrdCltn_removeAt_(struct OrdCltn_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
id objcT61;

# 791 "ordcltn.m"
if(anOffset>=(objcT61=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT61,selTransTbl[11]))(objcT61,selTransTbl[11])))
{
id objcT62,objcT63,objcT64,objcT65;

# 793 "ordcltn.m"
(objcT62=(objcT63=(objcT64=OutOfBounds,(*(id(*)(id,SEL,unsigned))_imp(objcT64,selTransTbl[15]))(objcT64,selTransTbl[15],(objcT65=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT65,selTransTbl[11]))(objcT65,selTransTbl[11])))),(*(id(*)(id,SEL,unsigned))_imp(objcT63,selTransTbl[12]))(objcT63,selTransTbl[12],anOffset)),(*_imp(objcT62,selTransTbl[16]))(objcT62,selTransTbl[16]));
return(id)0;
}
else
{
return removeat(( &self->value),anOffset);
}
}

static id i_OrdCltn_removeAtIndex_(struct OrdCltn_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
id objcT66;

# 804 "ordcltn.m"
return(objcT66=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT66,selTransTbl[21]))(objcT66,selTransTbl[21],anOffset));
}

static id i_OrdCltn_remove_(struct OrdCltn_PRIVATE *self,SEL _cmd,id oldObject)
{
id objcT67;

# 809 "ordcltn.m"
unsigned offset=(objcT67=(id)self,(*(unsigned(*)(id,SEL,id))_imp(objcT67,selTransTbl[17]))(objcT67,selTransTbl[17],oldObject));
if(offset==(unsigned) -1)
{
return(id)0;
}
else
{
id objcT68;

# 816 "ordcltn.m"
return(objcT68=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT68,selTransTbl[21]))(objcT68,selTransTbl[21],offset));
}
}


static id i_OrdCltn_remove_ifAbsent_(struct OrdCltn_PRIVATE *self,SEL _cmd,id oldObject,id exceptionBlock)
{
id objcT69,objcT70;

# 823 "ordcltn.m"
id anObject=(objcT69=(id)self,(*_imp(objcT69,selTransTbl[22]))(objcT69,selTransTbl[22],oldObject));
return(anObject)?anObject:(objcT70=exceptionBlock,(*_imp(objcT70,selTransTbl[23]))(objcT70,selTransTbl[23]));
}

# 834 "ordcltn.m"
static BOOL i_OrdCltn_includesAllOf_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT71,objcT72,objcT74;

# 842 "ordcltn.m"
BOOL res=(BOOL)1;
id e,seq=(objcT71=aCltn,(*_imp(objcT71,selTransTbl[24]))(objcT71,selTransTbl[24]));
while((e=(objcT72=seq,(*_imp(objcT72,selTransTbl[25]))(objcT72,selTransTbl[25]))))
{
id objcT73;

# 846 "ordcltn.m"
if( !(objcT73=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT73,selTransTbl[26]))(objcT73,selTransTbl[26],e)))
{
res=(BOOL)0;
goto done;
}
}
done:

(objcT74=seq,(*_imp(objcT74,selTransTbl[5]))(objcT74,selTransTbl[5]));

return res;
}
}

static BOOL i_OrdCltn_includesAnyOf_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT75,objcT76,objcT78;

# 868 "ordcltn.m"
BOOL res=(BOOL)0;
id e,seq=(objcT75=aCltn,(*_imp(objcT75,selTransTbl[24]))(objcT75,selTransTbl[24]));
while((e=(objcT76=seq,(*_imp(objcT76,selTransTbl[25]))(objcT76,selTransTbl[25]))))
{
id objcT77;

# 872 "ordcltn.m"
if((objcT77=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT77,selTransTbl[26]))(objcT77,selTransTbl[26],e)))
{
res=(BOOL)1;
goto done;
}
}
done:

(objcT78=seq,(*_imp(objcT78,selTransTbl[5]))(objcT78,selTransTbl[5]));

return res;
}
}

# 892 "ordcltn.m"
static id i_OrdCltn_addAll_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT79;

# 896 "ordcltn.m"
(objcT79=(id)self,(*_imp(objcT79,selTransTbl[27]))(objcT79,selTransTbl[27]));
}
else
{
id objcT80,objcT81,objcT83;

# 900 "ordcltn.m"
id e,seq;

seq=(objcT80=aCltn,(*_imp(objcT80,selTransTbl[24]))(objcT80,selTransTbl[24]));
while((e=(objcT81=seq,(*_imp(objcT81,selTransTbl[25]))(objcT81,selTransTbl[25]))))
{
id objcT82;

# 905 "ordcltn.m"
(objcT82=(id)self,(*_imp(objcT82,selTransTbl[2]))(objcT82,selTransTbl[2],e));
}

seq=(objcT83=seq,(*_imp(objcT83,selTransTbl[5]))(objcT83,selTransTbl[5]));

}

return(id)self;
}

static id i_OrdCltn_addContentsOf_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT84;

# 917 "ordcltn.m"
return(objcT84=(id)self,(*_imp(objcT84,selTransTbl[28]))(objcT84,selTransTbl[28],aCltn));
}

static id i_OrdCltn_addContentsTo_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT85;

# 922 "ordcltn.m"
return(objcT85=aCltn,(*_imp(objcT85,selTransTbl[28]))(objcT85,selTransTbl[28],(id)self));
}

static id i_OrdCltn_removeAll_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT86;

# 929 "ordcltn.m"
(objcT86=(id)self,(*_imp(objcT86,selTransTbl[29]))(objcT86,selTransTbl[29]));
}
else
{
id objcT87,objcT88,objcT90;

# 933 "ordcltn.m"
id e,seq;

seq=(objcT87=aCltn,(*_imp(objcT87,selTransTbl[24]))(objcT87,selTransTbl[24]));
while((e=(objcT88=seq,(*_imp(objcT88,selTransTbl[25]))(objcT88,selTransTbl[25]))))
{
id objcT89;

# 938 "ordcltn.m"
(objcT89=(id)self,(*_imp(objcT89,selTransTbl[22]))(objcT89,selTransTbl[22],e));
}

seq=(objcT90=seq,(*_imp(objcT90,selTransTbl[5]))(objcT90,selTransTbl[5]));

}

return(id)self;
}

static id i_OrdCltn_removeContentsFrom_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT91;

# 950 "ordcltn.m"
return(objcT91=aCltn,(*_imp(objcT91,selTransTbl[30]))(objcT91,selTransTbl[30],(id)self));
}

static id i_OrdCltn_removeContentsOf_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT92;

# 955 "ordcltn.m"
return(objcT92=(id)self,(*_imp(objcT92,selTransTbl[30]))(objcT92,selTransTbl[30],aCltn));
}

# 964 "ordcltn.m"
static id i_OrdCltn_intersection_(struct OrdCltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT93;

# 968 "ordcltn.m"
return(objcT93=(id)self,(*_imp(objcT93,selTransTbl[3]))(objcT93,selTransTbl[3]));
}
else
{
id objcT94,objcT95,objcT96,objcT99;

# 972 "ordcltn.m"
id anElement,elements;
id intersection=(objcT94=self->isa,(*_imp(objcT94,selTransTbl[0]))(objcT94,selTransTbl[0]));

elements=(objcT95=(id)self,(*_imp(objcT95,selTransTbl[24]))(objcT95,selTransTbl[24]));
while((anElement=(objcT96=elements,(*_imp(objcT96,selTransTbl[25]))(objcT96,selTransTbl[25]))))
{
id objcT97,objcT98;

# 978 "ordcltn.m"
if((objcT97=bag,(*_imp(objcT97,selTransTbl[13]))(objcT97,selTransTbl[13],anElement)))
(objcT98=intersection,(*_imp(objcT98,selTransTbl[2]))(objcT98,selTransTbl[2],anElement));
}

elements=(objcT99=elements,(*_imp(objcT99,selTransTbl[5]))(objcT99,selTransTbl[5]));


return intersection;
}
}

static id i_OrdCltn_union_(struct OrdCltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT100;

# 993 "ordcltn.m"
return(objcT100=(id)self,(*_imp(objcT100,selTransTbl[3]))(objcT100,selTransTbl[3]));
}
else
{
id objcT101,objcT102;

# 997 "ordcltn.m"
return(objcT101=(objcT102=(id)self,(*_imp(objcT102,selTransTbl[3]))(objcT102,selTransTbl[3])),(*_imp(objcT101,selTransTbl[28]))(objcT101,selTransTbl[28],bag));
}
}

static id i_OrdCltn_difference_(struct OrdCltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT103;

# 1005 "ordcltn.m"
return(objcT103=self->isa,(*_imp(objcT103,selTransTbl[0]))(objcT103,selTransTbl[0]));
}
else
{
id objcT104,objcT105;

# 1009 "ordcltn.m"
return(objcT104=(objcT105=(id)self,(*_imp(objcT105,selTransTbl[3]))(objcT105,selTransTbl[3])),(*_imp(objcT104,selTransTbl[30]))(objcT104,selTransTbl[30],bag));
}
}

# 36 "./set.h"
extern id  Set;

# 1019 "ordcltn.m"
static id i_OrdCltn_asSet(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT106,objcT107;
if((objcT106=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT106,selTransTbl[31]))(objcT106,selTransTbl[31],(id)(objcT107=Set,(*_imp(objcT107,selTransTbl[32]))(objcT107,selTransTbl[32])))))
{
return(id)self;
}
else
{
id objcT108,objcT109;

# 1028 "ordcltn.m"
return(objcT108=(objcT109=Set,(*_imp(objcT109,selTransTbl[0]))(objcT109,selTransTbl[0])),(*_imp(objcT108,selTransTbl[28]))(objcT108,selTransTbl[28],(id)self));
}
}

static id i_OrdCltn_asOrdCltn(struct OrdCltn_PRIVATE *self,SEL _cmd)
{
id objcT110,objcT111;
if((objcT110=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT110,selTransTbl[31]))(objcT110,selTransTbl[31],(id)(objcT111=OrdCltn,(*_imp(objcT111,selTransTbl[32]))(objcT111,selTransTbl[32])))))
{
return(id)self;
}
else
{
id objcT112,objcT113;

# 1041 "ordcltn.m"
return(objcT112=(objcT113=OrdCltn,(*_imp(objcT113,selTransTbl[0]))(objcT113,selTransTbl[0])),(*_imp(objcT112,selTransTbl[28]))(objcT112,selTransTbl[28],(id)self));
}
}

# 1052 "ordcltn.m"
static id i_OrdCltn_detect_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT114,objcT115,objcT118;

# 1054 "ordcltn.m"
id e,seq;

seq=(objcT114=(id)self,(*_imp(objcT114,selTransTbl[24]))(objcT114,selTransTbl[24]));

while((e=(objcT115=seq,(*_imp(objcT115,selTransTbl[25]))(objcT115,selTransTbl[25]))))
{
id objcT116;

# 1060 "ordcltn.m"
if(((objcT116=aBlock,(*_imp(objcT116,selTransTbl[33]))(objcT116,selTransTbl[33],e))))
{
id objcT117;
seq=(objcT117=seq,(*_imp(objcT117,selTransTbl[5]))(objcT117,selTransTbl[5]));

return e;
}
}


seq=(objcT118=seq,(*_imp(objcT118,selTransTbl[5]))(objcT118,selTransTbl[5]));

return(id)0;
}

static id i_OrdCltn_detect_ifNone_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aBlock,id noneBlock)
{
id objcT119,objcT120,objcT123,objcT124;

# 1077 "ordcltn.m"
id e,seq;

seq=(objcT119=(id)self,(*_imp(objcT119,selTransTbl[24]))(objcT119,selTransTbl[24]));

while((e=(objcT120=seq,(*_imp(objcT120,selTransTbl[25]))(objcT120,selTransTbl[25]))))
{
id objcT121;

# 1083 "ordcltn.m"
if(((objcT121=aBlock,(*_imp(objcT121,selTransTbl[33]))(objcT121,selTransTbl[33],e))))
{
id objcT122;
seq=(objcT122=seq,(*_imp(objcT122,selTransTbl[5]))(objcT122,selTransTbl[5]));

return e;
}
}


seq=(objcT123=seq,(*_imp(objcT123,selTransTbl[5]))(objcT123,selTransTbl[5]));

return(objcT124=noneBlock,(*_imp(objcT124,selTransTbl[23]))(objcT124,selTransTbl[23]));
}

static id i_OrdCltn_select_(struct OrdCltn_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT125,objcT126,objcT127,objcT130;

# 1100 "ordcltn.m"
id e,seq;
id newObject=(objcT125=self->isa,(*_imp(objcT125,selTransTbl[0]))(objcT125,selTransTbl[0]));

seq=(objcT126=(id)self,(*_imp(objcT126,selTransTbl[24]))(objcT126,selTransTbl[24]));

while((e=(objcT127=seq,(*_imp(objcT127,selTransTbl[25]))(objcT127,selTransTbl[25]))))
{
id objcT128;

# 1107 "ordcltn.m"
if(((objcT128=testBlock,(*_imp(objcT128,selTransTbl[33]))(objcT128,selTransTbl[33],e))))
{
id objcT129;

# 1109 "ordcltn.m"
(objcT129=newObject,(*_imp(objcT129,selTransTbl[2]))(objcT129,selTransTbl[2],e));
}
}


seq=(objcT130=seq,(*_imp(objcT130,selTransTbl[5]))(objcT130,selTransTbl[5]));

return newObject;
}

static id i_OrdCltn_reject_(struct OrdCltn_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT131,objcT132,objcT133,objcT136;

# 1121 "ordcltn.m"
id e,seq;
id newObject=(objcT131=self->isa,(*_imp(objcT131,selTransTbl[0]))(objcT131,selTransTbl[0]));

seq=(objcT132=(id)self,(*_imp(objcT132,selTransTbl[24]))(objcT132,selTransTbl[24]));

while((e=(objcT133=seq,(*_imp(objcT133,selTransTbl[25]))(objcT133,selTransTbl[25]))))
{
id objcT134;

# 1128 "ordcltn.m"
if( !((objcT134=testBlock,(*_imp(objcT134,selTransTbl[33]))(objcT134,selTransTbl[33],e))))
{
id objcT135;

# 1130 "ordcltn.m"
(objcT135=newObject,(*_imp(objcT135,selTransTbl[2]))(objcT135,selTransTbl[2],e));
}
}


seq=(objcT136=seq,(*_imp(objcT136,selTransTbl[5]))(objcT136,selTransTbl[5]));

return newObject;
}

static id i_OrdCltn_collect_(struct OrdCltn_PRIVATE *self,SEL _cmd,id transformBlock)
{
id objcT137,objcT138,objcT139,objcT142;

# 1142 "ordcltn.m"
id e,seq;
id newObject=(objcT137=self->isa,(*_imp(objcT137,selTransTbl[0]))(objcT137,selTransTbl[0]));

seq=(objcT138=(id)self,(*_imp(objcT138,selTransTbl[24]))(objcT138,selTransTbl[24]));

while((e=(objcT139=seq,(*_imp(objcT139,selTransTbl[25]))(objcT139,selTransTbl[25]))))
{
id objcT140;

# 1149 "ordcltn.m"
id anImage=(objcT140=transformBlock,(*_imp(objcT140,selTransTbl[33]))(objcT140,selTransTbl[33],e));
if(anImage)
{
id objcT141;

# 1152 "ordcltn.m"
(objcT141=newObject,(*_imp(objcT141,selTransTbl[2]))(objcT141,selTransTbl[2],anImage));
}
}


seq=(objcT142=seq,(*_imp(objcT142,selTransTbl[5]))(objcT142,selTransTbl[5]));

return newObject;
}

static unsigned i_OrdCltn_count_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT143,objcT144,objcT146;

# 1164 "ordcltn.m"
id e,seq;
unsigned c=0;

seq=(objcT143=(id)self,(*_imp(objcT143,selTransTbl[24]))(objcT143,selTransTbl[24]));
while((e=(objcT144=seq,(*_imp(objcT144,selTransTbl[25]))(objcT144,selTransTbl[25]))))
{
id objcT145;

# 1170 "ordcltn.m"
if((objcT145=aBlock,(*_imp(objcT145,selTransTbl[33]))(objcT145,selTransTbl[33],e)))
{
c++;
}
}

seq=(objcT146=seq,(*_imp(objcT146,selTransTbl[5]))(objcT146,selTransTbl[5]));


return c;
}

# 1190 "ordcltn.m"
static id i_OrdCltn_elementsPerform_(struct OrdCltn_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT147;

# 1192 "ordcltn.m"
int i,n;
for(i=0,n=(objcT147=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT147,selTransTbl[11]))(objcT147,selTransTbl[11]));i<n;i++)
{
id objcT148,objcT149;

# 1195 "ordcltn.m"
(objcT148=(objcT149=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT149,selTransTbl[12]))(objcT149,selTransTbl[12],i)),(*(id(*)(id,SEL,SEL))_imp(objcT148,selTransTbl[34]))(objcT148,selTransTbl[34],aSelector));
}
return(id)self;
}

static id i_OrdCltn_elementsPerform_with_(struct OrdCltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject)
{
id objcT150;

# 1202 "ordcltn.m"
int i,n;
for(i=0,n=(objcT150=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT150,selTransTbl[11]))(objcT150,selTransTbl[11]));i<n;i++)
{
id objcT151,objcT152;

# 1205 "ordcltn.m"
(objcT151=(objcT152=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT152,selTransTbl[12]))(objcT152,selTransTbl[12],i)),(*(id(*)(id,SEL,SEL,id))_imp(objcT151,selTransTbl[35]))(objcT151,selTransTbl[35],aSelector,anObject));
}
return(id)self;
}

static id i_OrdCltn_elementsPerform_with_with_(struct OrdCltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject)
{
id objcT153;

# 1212 "ordcltn.m"
int i,n;
for(i=0,n=(objcT153=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT153,selTransTbl[11]))(objcT153,selTransTbl[11]));i<n;i++)
{
id objcT154,objcT155;

# 1215 "ordcltn.m"
(objcT154=(objcT155=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT155,selTransTbl[12]))(objcT155,selTransTbl[12],i)),(*(id(*)(id,SEL,SEL,id,id))_imp(objcT154,selTransTbl[36]))(objcT154,selTransTbl[36],aSelector,anObject,otherObject));
}
return(id)self;
}

static id i_OrdCltn_elementsPerform_with_with_with_(struct OrdCltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject,id thirdObj)
{
id objcT156;

# 1222 "ordcltn.m"
int i,n;
for(i=0,n=(objcT156=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT156,selTransTbl[11]))(objcT156,selTransTbl[11]));i<n;i++)
{
id objcT157,objcT158;

# 1225 "ordcltn.m"
(objcT157=(objcT158=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT158,selTransTbl[12]))(objcT158,selTransTbl[12],i)),(*(id(*)(id,SEL,SEL,id,id,id))_imp(objcT157,selTransTbl[37]))(objcT157,selTransTbl[37],aSelector,anObject,otherObject,thirdObj));
}
return(id)self;
}

# 1236 "ordcltn.m"
static id i_OrdCltn_do_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT159;

# 1238 "ordcltn.m"
int i=0;
int n=(objcT159=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT159,selTransTbl[11]))(objcT159,selTransTbl[11]));
for(i=0;i<n;i++)
{
id objcT160,objcT161;

# 1242 "ordcltn.m"
(objcT160=aBlock,(*_imp(objcT160,selTransTbl[33]))(objcT160,selTransTbl[33],(objcT161=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT161,selTransTbl[12]))(objcT161,selTransTbl[12],i))));
}
return(id)self;
}

static id i_OrdCltn_do_until_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aBlock,BOOL*flag)
{
id objcT162;

# 1249 "ordcltn.m"
int i=0;
int n=(objcT162=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT162,selTransTbl[11]))(objcT162,selTransTbl[11]));
for(i=0;i<n;i++)
{
id objcT163,objcT164;

# 1253 "ordcltn.m"
(objcT163=aBlock,(*_imp(objcT163,selTransTbl[33]))(objcT163,selTransTbl[33],(objcT164=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT164,selTransTbl[12]))(objcT164,selTransTbl[12],i))));
if( *flag)
break;
}
return(id)self;
}

static id i_OrdCltn_reverseDo_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT165;

# 1262 "ordcltn.m"
unsigned n=(objcT165=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT165,selTransTbl[11]))(objcT165,selTransTbl[11]));
while(n--)
{
id objcT166,objcT167;

# 1265 "ordcltn.m"
(objcT166=aBlock,(*_imp(objcT166,selTransTbl[33]))(objcT166,selTransTbl[33],(objcT167=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT167,selTransTbl[12]))(objcT167,selTransTbl[12],n))));
}
return(id)self;
}

# 1277 "ordcltn.m"
static id
ptrfind(id*p,id obj,int n)
{
int i;
for(i=0;i<n;i++)
{
if(p[i]==obj)
{
return p[i];
}
}
return(id)0;
}

static id
find(objcol_t self,id obj)
{
return ptrfind(self->ptr,obj,self->count);
}

static id i_OrdCltn_find_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
return find(( &self->value),anObject);
}

static id
ptrfindmatch(id*p,id obj,int n)
{
int i;
for(i=0;i<n;i++)
{
id objcT168;

# 1308 "ordcltn.m"
if(p[i]==obj||(objcT168=p[i],(*(BOOL(*)(id,SEL,id))_imp(objcT168,selTransTbl[10]))(objcT168,selTransTbl[10],obj)))
{
return p[i];
}
}
return(id)0;
}

static id
findmatch(objcol_t self,id obj)
{
return ptrfindmatch(self->ptr,obj,self->count);
}

static id i_OrdCltn_findMatching_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
return findmatch(( &self->value),anObject);
}

static BOOL i_OrdCltn_includes_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT169;

# 1329 "ordcltn.m"
return(objcT169=(id)self,(*_imp(objcT169,selTransTbl[14]))(objcT169,selTransTbl[14],anObject))!=(id)0;
}

static id
ptrfindstr(id*p,STR s,int n)
{
int i;
for(i=0;i<n;i++)
{
id objcT170;

# 1338 "ordcltn.m"
if((objcT170=p[i],(*(BOOL(*)(id,SEL,STR))_imp(objcT170,selTransTbl[38]))(objcT170,selTransTbl[38],s)))
{
return p[i];
}
}
return(id)0;
}

static id
findstr(objcol_t self,STR s)
{
return ptrfindstr(self->ptr,s,self->count);
}

static id i_OrdCltn_findSTR_(struct OrdCltn_PRIVATE *self,SEL _cmd,STR aString)
{
return findstr(( &self->value),aString);
}

static BOOL i_OrdCltn_contains_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT171;

# 1359 "ordcltn.m"
return(objcT171=(id)self,(*_imp(objcT171,selTransTbl[13]))(objcT171,selTransTbl[13],anObject))!=(id)0;
}

static int
ptroffset(id*p,id obj,int n)
{
int i;
for(i=0;i<n;i++)
{
if( *p++==obj)
{
return i;
}
}
return -1;
}

static int
offset(objcol_t self,id obj)
{
return ptroffset(self->ptr,obj,self->count);
}

static unsigned i_OrdCltn_offsetOf_(struct OrdCltn_PRIVATE *self,SEL _cmd,id anObject)
{
return(unsigned)offset(( &self->value),anObject);
}

# 1393 "ordcltn.m"
static id i_OrdCltn_printOn_(struct OrdCltn_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT172;

# 1395 "ordcltn.m"
int i,n=(objcT172=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT172,selTransTbl[11]))(objcT172,selTransTbl[11]));
for(i=0;i<n;i++)
{
id objcT173,objcT174;

# 1398 "ordcltn.m"
id s=(objcT173=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT173,selTransTbl[12]))(objcT173,selTransTbl[12],i));
(objcT174=s,(*(id(*)(id,SEL,IOD))_imp(objcT174,selTransTbl[39]))(objcT174,selTransTbl[39],aFile));
fprintf(aFile,"\n");
}
return(id)self;
}

# 1412 "ordcltn.m"
static void
ptrfileout(id aFiler,id*a,int n)
{
while(n--)
{
id objcT175;

# 1417 "ordcltn.m"
(objcT175=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT175,selTransTbl[40]))(objcT175,selTransTbl[40],a++,'@'));
}
}

static void
ptrfilein(id aFiler,id*a,int n)
{
while(n--)
{
id objcT176;

# 1426 "ordcltn.m"
(objcT176=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT176,selTransTbl[41]))(objcT176,selTransTbl[41],a++,'@'));
}
}

static void
fileout(id aFiler,objcol_t self)
{
id objcT177,objcT178;

# 1433 "ordcltn.m"
(objcT177=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT177,selTransTbl[40]))(objcT177,selTransTbl[40], &self->count,'i'));
(objcT178=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT178,selTransTbl[40]))(objcT178,selTransTbl[40], &self->capacity,'i'));
ptrfileout(aFiler,self->ptr,self->count);
}

static void
filein(id aFiler,objcol_t self)
{
id objcT179,objcT180;

# 1441 "ordcltn.m"
int n,c;
(objcT179=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT179,selTransTbl[41]))(objcT179,selTransTbl[41], &n,'i'));
(objcT180=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT180,selTransTbl[41]))(objcT180,selTransTbl[41], &c,'i'));
init(self,n,c);
ptrfilein(aFiler,self->ptr,n);
}

static id i_OrdCltn_fileOutOn_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT181;

# 1450 "ordcltn.m"
(objcT181=_OrdCltn.clsSuper,(*_impSuper(objcT181,selTransTbl[42]))((id)self,selTransTbl[42],aFiler));
fileout(aFiler, &self->value);
return(id)self;
}

static id i_OrdCltn_fileInFrom_(struct OrdCltn_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT182;

# 1457 "ordcltn.m"
(objcT182=_OrdCltn.clsSuper,(*_impSuper(objcT182,selTransTbl[43]))((id)self,selTransTbl[43],aFiler));
filein(aFiler, &self->value);
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Cltn;
extern struct _SHARED _Cltn;
extern struct _SHARED __Cltn;
static struct _SLT _OrdCltn_clsDispatchTbl[] ={
{"new",(id (*)())c_OrdCltn_new},
{"new:",(id (*)())c_OrdCltn_new_},
{"with:",(id (*)())c_OrdCltn_with_},
{"with:with:",(id (*)())c_OrdCltn_with_with_},
{"add:",(id (*)())c_OrdCltn_add_},
{(char*)0,(id (*)())0}
};
static struct _SLT _OrdCltn_nstDispatchTbl[] ={
{"copy",(id (*)())i_OrdCltn_copy},
{"deepCopy",(id (*)())i_OrdCltn_deepCopy},
{"emptyYourself",(id (*)())i_OrdCltn_emptyYourself},
{"freeContents",(id (*)())i_OrdCltn_freeContents},
{"freeAll",(id (*)())i_OrdCltn_freeAll},
{"free",(id (*)())i_OrdCltn_free},
{"release",(id (*)())i_OrdCltn_release},
{"objcolvalue",(id (*)())i_OrdCltn_objcolvalue},
{"size",(id (*)())i_OrdCltn_size},
{"isEmpty",(id (*)())i_OrdCltn_isEmpty},
{"lastOffset",(id (*)())i_OrdCltn_lastOffset},
{"eachElement",(id (*)())i_OrdCltn_eachElement},
{"firstElement",(id (*)())i_OrdCltn_firstElement},
{"lastElement",(id (*)())i_OrdCltn_lastElement},
{"hash",(id (*)())i_OrdCltn_hash},
{"isEqual:",(id (*)())i_OrdCltn_isEqual_},
{"add:",(id (*)())i_OrdCltn_add_},
{"addYourself",(id (*)())i_OrdCltn_addYourself},
{"addFirst:",(id (*)())i_OrdCltn_addFirst_},
{"addLast:",(id (*)())i_OrdCltn_addLast_},
{"addIfAbsent:",(id (*)())i_OrdCltn_addIfAbsent_},
{"addIfAbsentMatching:",(id (*)())i_OrdCltn_addIfAbsentMatching_},
{"at:insert:",(id (*)())i_OrdCltn_at_insert_},
{"couldntfind",(id (*)())i_OrdCltn_couldntfind},
{"insert:after:",(id (*)())i_OrdCltn_insert_after_},
{"insert:before:",(id (*)())i_OrdCltn_insert_before_},
{"after:",(id (*)())i_OrdCltn_after_},
{"before:",(id (*)())i_OrdCltn_before_},
{"at:",(id (*)())i_OrdCltn_at_},
{"at:put:",(id (*)())i_OrdCltn_at_put_},
{"removeFirst",(id (*)())i_OrdCltn_removeFirst},
{"removeLast",(id (*)())i_OrdCltn_removeLast},
{"removeAt:",(id (*)())i_OrdCltn_removeAt_},
{"removeAtIndex:",(id (*)())i_OrdCltn_removeAtIndex_},
{"remove:",(id (*)())i_OrdCltn_remove_},
{"remove:ifAbsent:",(id (*)())i_OrdCltn_remove_ifAbsent_},
{"includesAllOf:",(id (*)())i_OrdCltn_includesAllOf_},
{"includesAnyOf:",(id (*)())i_OrdCltn_includesAnyOf_},
{"addAll:",(id (*)())i_OrdCltn_addAll_},
{"addContentsOf:",(id (*)())i_OrdCltn_addContentsOf_},
{"addContentsTo:",(id (*)())i_OrdCltn_addContentsTo_},
{"removeAll:",(id (*)())i_OrdCltn_removeAll_},
{"removeContentsFrom:",(id (*)())i_OrdCltn_removeContentsFrom_},
{"removeContentsOf:",(id (*)())i_OrdCltn_removeContentsOf_},
{"intersection:",(id (*)())i_OrdCltn_intersection_},
{"union:",(id (*)())i_OrdCltn_union_},
{"difference:",(id (*)())i_OrdCltn_difference_},
{"asSet",(id (*)())i_OrdCltn_asSet},
{"asOrdCltn",(id (*)())i_OrdCltn_asOrdCltn},
{"detect:",(id (*)())i_OrdCltn_detect_},
{"detect:ifNone:",(id (*)())i_OrdCltn_detect_ifNone_},
{"select:",(id (*)())i_OrdCltn_select_},
{"reject:",(id (*)())i_OrdCltn_reject_},
{"collect:",(id (*)())i_OrdCltn_collect_},
{"count:",(id (*)())i_OrdCltn_count_},
{"elementsPerform:",(id (*)())i_OrdCltn_elementsPerform_},
{"elementsPerform:with:",(id (*)())i_OrdCltn_elementsPerform_with_},
{"elementsPerform:with:with:",(id (*)())i_OrdCltn_elementsPerform_with_with_},
{"elementsPerform:with:with:with:",(id (*)())i_OrdCltn_elementsPerform_with_with_with_},
{"do:",(id (*)())i_OrdCltn_do_},
{"do:until:",(id (*)())i_OrdCltn_do_until_},
{"reverseDo:",(id (*)())i_OrdCltn_reverseDo_},
{"find:",(id (*)())i_OrdCltn_find_},
{"findMatching:",(id (*)())i_OrdCltn_findMatching_},
{"includes:",(id (*)())i_OrdCltn_includes_},
{"findSTR:",(id (*)())i_OrdCltn_findSTR_},
{"contains:",(id (*)())i_OrdCltn_contains_},
{"offsetOf:",(id (*)())i_OrdCltn_offsetOf_},
{"printOn:",(id (*)())i_OrdCltn_printOn_},
{"fileOutOn:",(id (*)())i_OrdCltn_fileOutOn_},
{"fileInFrom:",(id (*)())i_OrdCltn_fileInFrom_},
{(char*)0,(id (*)())0}
};
id OrdCltn = (id)&_OrdCltn;
id  *OBJCCLASS_OrdCltn(void) { return &OrdCltn; }
struct _SHARED  _OrdCltn = {
  (id)&__OrdCltn,
  (id)&_Cltn,
  "OrdCltn",
  0,
  sizeof(struct OrdCltn_PRIVATE),
  71,
  _OrdCltn_nstDispatchTbl,
  41,
  &ordcltn_modDesc,
  0,
  (id)0,
  &OrdCltn,
};
id  OBJCCFUNC_OrdCltn(void) { return (id)&_OrdCltn; }
id  OBJCCSUPER_OrdCltn(void) { return _OrdCltn.clsSuper; }
struct _SHARED __OrdCltn = {
  (id)&__Object,
  (id)&__Cltn,
  "OrdCltn",
  0,
  sizeof(struct _SHARED),
  5,
  _OrdCltn_clsDispatchTbl,
  34,
  &ordcltn_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_OrdCltn(void) { return (id)&__OrdCltn; }
id  OBJCMSUPER_OrdCltn(void) { return __OrdCltn.clsSuper; }
static char *_selTransTbl[] ={
"new",
"objcolvalue",
"add:",
"copy",
"deepCopy",
"free",
"freeAll",
"notImplemented:",
"over:",
"hash",
"isEqual:",
"size",
"at:",
"find:",
"findMatching:",
"new:",
"signal",
"offsetOf:",
"couldntfind",
"at:insert:",
"lastOffset",
"removeAt:",
"remove:",
"value",
"eachElement",
"next",
"includes:",
"addYourself",
"addAll:",
"emptyYourself",
"removeAll:",
"isKindOf:",
"class",
"value:",
"perform:",
"perform:with:",
"perform:with:with:",
"perform:with:with:with:",
"isEqualSTR:",
"printOn:",
"fileOut:type:",
"fileIn:type:",
"fileOutOn:",
"fileInFrom:",
0
};
struct modDescriptor ordcltn_modDesc = {
  "ordcltn",
  "objc3.3.19",
  0L,
  0,
  0,
  &OrdCltn,
  44,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_ordcltn(void)
{
  selTransTbl = _selTransTbl;
  return &ordcltn_modDesc;
}
int _OBJCPOSTLINK_ordcltn = 1;


