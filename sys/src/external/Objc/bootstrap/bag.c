# 1 "bag.m"
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
extern struct modDescriptor  *_OBJCBIND_bag(void);
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
extern struct modDescriptor bag_modDesc;

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

# 28 "./bag.h"
typedef struct objbag
{
int count;
int capacity;
id*ptr;
int*cnts;
}*
objbag_t;
# 28 "./bagseq.h"
typedef struct objbagseq
{
objbag_t set;
int offset;
int cnt;
}*
objbagseq_t;
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
# 37 "./bag.h"
struct Bag_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 39 "./bag.h"
struct objbag value;};

# 37 "./bag.h"
extern id  Bag;

# 37 "./bag.h"
extern struct _SHARED _Bag;
extern struct _SHARED __Bag;


# 46 "bag.m"
static void
ptrzero(id*p,int*m,int c)
{
while(c--)
{ *
p++=(id)0; *
m++=0;
}
}

static void
init(objbag_t self,int n,int c)
{
(void)0;
self->count=n;
self->capacity=c;
self->ptr=(id*)OC_Calloc(c*sizeof(id));
self->cnts=(int*)OC_MallocAtomic(c*sizeof(int));
memset(self->cnts,0,sizeof(int)*c);
}

static void
initzero(objbag_t self,int c)
{
init(self,0,c);
}

static id c_Bag_new(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 75 "bag.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],16));
}

static id c_Bag_new_(struct Bag_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT1,objcT2;

# 80 "bag.m"
id newObj=(objcT1=__Bag.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
initzero((objcT2=newObj,(*(objbag_t(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2])),n);
return newObj;
}

# 91 "bag.m"
static id c_Bag_with_(struct Bag_PRIVATE *self,SEL _cmd,int nArgs,...)
{
id objcT3;

# 93 "bag.m"
id newObject;


va_list vp;

newObject=(objcT3=(id)self,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1]));
# 113 "bag.m"
va_start(vp,nArgs);
while(nArgs-->0)
{
id objcT4;

# 116 "bag.m"
id anObject=va_arg(vp,id);
(objcT4=newObject,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3],anObject));
}
va_end(vp);


return newObject;
}

static id c_Bag_with_with_(struct Bag_PRIVATE *self,SEL _cmd,id firstObject,id nextObject)
{
id objcT5,objcT6,objcT7;

# 127 "bag.m"
return(objcT5=(objcT6=(objcT7=(id)self,(*_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1])),(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3],firstObject)),(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],nextObject));
}

static id c_Bag_add_(struct Bag_PRIVATE *self,SEL _cmd,id firstObject)
{
id objcT8,objcT9;

# 132 "bag.m"
return(objcT8=(objcT9=(id)self,(*_imp(objcT9,selTransTbl[1]))(objcT9,selTransTbl[1])),(*_imp(objcT8,selTransTbl[3]))(objcT8,selTransTbl[3],firstObject));
}

static void
ptrcopy(id*p,int*mp,id*q,int*mq,int c)
{
while(c--)
{ *
p++= *q++; *
mp++= *mq++;
}
}

static void
copy(objbag_t dst,objbag_t src)
{
init(dst,src->count,src->capacity);
ptrcopy(dst->ptr,dst->cnts,src->ptr,src->cnts,src->capacity);
}

static id i_Bag_copy(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11;

# 154 "bag.m"
id aCopy=(objcT10=_Bag.clsSuper,(*_impSuper(objcT10,selTransTbl[4]))((id)self,selTransTbl[4]));
copy((objcT11=aCopy,(*(objbag_t(*)(id,SEL))_imp(objcT11,selTransTbl[2]))(objcT11,selTransTbl[2])),( &self->value));
return aCopy;
}

static void
ptrdeepcopy(id*p,int*mp,id*q,int*mq,int c)
{
while(c--)
{
id objcT12;

# 164 "bag.m"
id obj= *q++; *
p++=(obj)?(objcT12=obj,(*_imp(objcT12,selTransTbl[5]))(objcT12,selTransTbl[5])):(id)0; *
mp++= *mq++;
}
}

static void
deepcopy(objbag_t dst,objbag_t src)
{
init(dst,src->count,src->capacity);
ptrdeepcopy(dst->ptr,dst->cnts,src->ptr,src->cnts,src->capacity);
}

static id i_Bag_deepCopy(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14;


id aCopy=(objcT13=_Bag.clsSuper,(*_impSuper(objcT13,selTransTbl[4]))((id)self,selTransTbl[4]));
deepcopy((objcT14=aCopy,(*(objbag_t(*)(id,SEL))_imp(objcT14,selTransTbl[2]))(objcT14,selTransTbl[2])),( &self->value));
return aCopy;
}

static void
empty(objbag_t self)
{
self->count=0;
ptrzero(self->ptr,self->cnts,self->capacity);
}

static id i_Bag_emptyYourself(struct Bag_PRIVATE *self,SEL _cmd)
{
empty(( &self->value));
return(id)self;
}

static void
ptraddself(int*m,int c)
{
while(c--)
{
( *m)*=2;
m++;
}
}

static void
addself(objbag_t self)
{
ptraddself(self->cnts,self->capacity);
}

static id i_Bag_addYourself(struct Bag_PRIVATE *self,SEL _cmd)
{

addself(( &self->value));
return(id)self;
}

static void
ptrclear(id*p,int*m,int c)
{
while(c--)
{
id objcT15;

# 228 "bag.m"
id obj= *p; *
p++=(obj)?(objcT15=obj,(*_imp(objcT15,selTransTbl[6]))(objcT15,selTransTbl[6])):(id)0; *
m++=0;
}
}

static void
freecontents(objbag_t self)
{
self->count=0;
ptrclear(self->ptr,self->cnts,self->capacity);
}

static id i_Bag_freeContents(struct Bag_PRIVATE *self,SEL _cmd)
{
freecontents(( &self->value));
return(id)self;
}

static void
clear(objbag_t self)
{
self->count=0;
self->capacity=0;
OC_Free(self->ptr);
self->ptr=NULL;
OC_Free(self->cnts);
self->cnts=NULL;
}

static id i_Bag_free(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT16;

# 260 "bag.m"
clear(( &self->value));
return(objcT16=_Bag.clsSuper,(*_impSuper(objcT16,selTransTbl[6]))((id)self,selTransTbl[6]));
}

static id i_Bag_release(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT17;

# 271 "bag.m"
return(objcT17=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT17,selTransTbl[7]))(objcT17,selTransTbl[7],_cmd));

}

# 281 "bag.m"
static objbag_t i_Bag_objbagvalue(struct Bag_PRIVATE *self,SEL _cmd)
{
return( &self->value);
}

static int
ptrsize(id*p,int*m,int c)
{
int n=0;
while(c--)
{
n+=( *m++);
}
return n;
}

static int
size(objbag_t self)
{
return ptrsize(self->ptr,self->cnts,self->capacity);
}

static unsigned i_Bag_size(struct Bag_PRIVATE *self,SEL _cmd)
{
return(unsigned)size(( &self->value));
}

static BOOL i_Bag_isEmpty(struct Bag_PRIVATE *self,SEL _cmd)
{
return self->value.count==0;
}

# 36 "./bagseq.h"
extern id  BagSequence;

# 35 "./sequence.h"
extern id  Sequence;

# 313 "bag.m"
static id i_Bag_eachElement(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19;

# 315 "bag.m"
id aCarrier=(objcT18=BagSequence,(*_imp(objcT18,selTransTbl[8]))(objcT18,selTransTbl[8],(id)self));
return(objcT19=Sequence,(*_imp(objcT19,selTransTbl[8]))(objcT19,selTransTbl[8],aCarrier));
}

# 325 "bag.m"
static unsigned i_Bag_hash(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT20;

# 327 "bag.m"
return(objcT20=_Bag.clsSuper,(*(unsigned(*)(id,SEL))_impSuper(objcT20,selTransTbl[9]))((id)self,selTransTbl[9]));
}

static BOOL i_Bag_isEqual_(struct Bag_PRIVATE *self,SEL _cmd,id bag)
{
id objcT21,objcT22,objcT23,objcT24,objcT25;
id objcT26,objcT29;

# 332 "bag.m"
id anElement,aSequence;
if((id)self==bag)
return(BOOL)1;
if( !(objcT21=bag,(*(BOOL(*)(id,SEL,id))_imp(objcT21,selTransTbl[10]))(objcT21,selTransTbl[10],(id)(objcT22=Bag,(*_imp(objcT22,selTransTbl[11]))(objcT22,selTransTbl[11])))))
return(BOOL)0;
if((objcT23=bag,(*(unsigned(*)(id,SEL))_imp(objcT23,selTransTbl[12]))(objcT23,selTransTbl[12]))!=(objcT24=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT24,selTransTbl[12]))(objcT24,selTransTbl[12])))
return(BOOL)0;
aSequence=(objcT25=(id)self,(*_imp(objcT25,selTransTbl[13]))(objcT25,selTransTbl[13]));
while((anElement=(objcT26=aSequence,(*_imp(objcT26,selTransTbl[14]))(objcT26,selTransTbl[14]))))
{
id objcT27;

# 342 "bag.m"
if((objcT27=bag,(*(BOOL(*)(id,SEL,id))_imp(objcT27,selTransTbl[15]))(objcT27,selTransTbl[15],anElement)))
{
id objcT28;
(objcT28=aSequence,(*_imp(objcT28,selTransTbl[6]))(objcT28,selTransTbl[6]));

return(BOOL)0;
}
}

(objcT29=aSequence,(*_imp(objcT29,selTransTbl[6]))(objcT29,selTransTbl[6]));

return(BOOL)1;
}

# 362 "bag.m"
static unsigned
ptrfind(id*p,id obj,int n)
{
id objcT30;

# 365 "bag.m"
id*begin,*now,*end;

begin=p;
now=p+(((objcT30=obj,(*(unsigned(*)(id,SEL))_imp(objcT30,selTransTbl[9]))(objcT30,selTransTbl[9])))%n);
end=p+n;

for(;n--;now++)
{
id objcT31;

# 373 "bag.m"
if(now>=end)
now=begin;
if( *now==(id)0||(objcT31= *now,(*(BOOL(*)(id,SEL,id))_imp(objcT31,selTransTbl[16]))(objcT31,selTransTbl[16],obj)))
return(unsigned)(now-begin);
}

fprintf(stderr,"find: table full shouldn't happen");
return 0;
}

static id*
find(objbag_t self,id obj,int**m)
{
unsigned of=ptrfind(self->ptr,obj,self->capacity); *
m=self->cnts+of;
return self->ptr+of;
}

static id i_Bag_add_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT32;

# 393 "bag.m"
(objcT32=(id)self,(*_imp(objcT32,selTransTbl[17]))(objcT32,selTransTbl[17],anObject));
return(id)self;
}

static BOOL
needsexpand(objbag_t self)
{
return 2*self->count>self->capacity;
}


static void
ptrrehash(id*newp,int*nm,int newc,id*old,int*om,int oldc)
{
while(oldc--)
{
id obj= *old++;
int cnt= *om++;
id*newend=newp+newc;
if(obj)
{
id objcT33;

# 414 "bag.m"
id*pos=newp+((objcT33=obj,(*(unsigned(*)(id,SEL))_imp(objcT33,selTransTbl[9]))(objcT33,selTransTbl[9]))%((unsigned)newc));
while( *pos)
{
pos++;
if(pos==newend)
pos=newp;
} *
pos=obj;
nm[pos-newp]=cnt;
}
}
}

static void
rehash(objbag_t self)
{
int c;
int*nm,*om;
id*newp,*old;

c=self->capacity;
old=self->ptr;
newp=(id*)OC_Calloc(c*sizeof(id));
om=self->cnts;
nm=(int*)OC_MallocAtomic(c*sizeof(int));
memset(nm,0,sizeof(int)*c);

ptrrehash(newp,nm,c,old,om,c);

OC_Free(old);
OC_Free(om);
self->ptr=newp;
self->cnts=nm;
}

static void
expand(objbag_t self)
{
int*nm,*om;
id*newp,*old;
int newc,oldc;

oldc=self->capacity;
old=self->ptr;
om=self->cnts;
newc=1+2*oldc;
newp=(id*)OC_Calloc(newc*sizeof(id));
nm=(int*)OC_MallocAtomic(newc*sizeof(int));
memset(nm,0,sizeof(int)*newc);

ptrrehash(newp,nm,newc,old,om,oldc);

OC_Free(old);
OC_Free(om);
self->ptr=newp;
self->cnts=nm;
self->capacity=newc;
}

static id
add(objbag_t self,id obj)
{
id*p;
int*m;

if(needsexpand(self))
expand(self);

if( *(p=find(self,obj, &m)))
{
( *m)++;
return(id)0;
}
else
{
self->count++; *
m=1;
return *p=obj;
}
}

static id i_Bag_addNTest_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
return add(( &self->value),anObject);
}
else
{
return(id)0;
}
}

static id
filter(objbag_t self,id obj)
{
id*p;
int*m;

if(needsexpand(self))
expand(self);

if( *(p=find(self,obj, &m)))
{
( *m)++;
return *p;
}
else
{
self->count++; *
m=1; *
p=obj;
return(id)0;
}
}

static id i_Bag_filter_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
id t=filter(( &self->value),anObject);
if(t)
{
id objcT34;
(objcT34=anObject,(*_imp(objcT34,selTransTbl[6]))(objcT34,selTransTbl[6]));

return t;
}
else
{
return anObject;
}
}
else
{
return(id)0;
}
}


static id i_Bag_add_ifDuplicate_(struct Bag_PRIVATE *self,SEL _cmd,id anObject,id aBlock)
{
if(anObject)
{
id t=filter(( &self->value),anObject);
if(t)
{
id objcT35;

# 561 "bag.m"
(objcT35=aBlock,(*_imp(objcT35,selTransTbl[18]))(objcT35,selTransTbl[18]));
return t;
}
else
{
return anObject;
}
}
else
{
return(id)0;
}
}


static id
replace(objbag_t self,id obj)
{
id*p;
int*m;

if(needsexpand(self))
expand(self);

if( *(p=find(self,obj, &m)))
{
id tmp= *p; *
p=obj;
return tmp;
}
else
{
self->count++; *
p=obj;
return(id)0;
}
}

static id i_Bag_replace_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
return replace(( &self->value),anObject);
}
else
{
return(id)0;
}
}

# 617 "bag.m"
static id
delete(objbag_t self,id obj)
{
id*p;
int*m;

if( *(p=find(self,obj, &m)))
{
id tmp= *p;
if((( *m)--)==0)
{ *
p=(id)0;
self->count--;
}
rehash(self);
return tmp;
}
else
{
return(id)0;
}
}

static id i_Bag_remove_(struct Bag_PRIVATE *self,SEL _cmd,id oldObject)
{
if(oldObject)
{
return delete(( &self->value),oldObject);
}
else
{
return(id)0;
}
}

static id i_Bag_remove_ifAbsent_(struct Bag_PRIVATE *self,SEL _cmd,id oldObject,id exceptionBlock)
{
if(oldObject)
{
return delete(( &self->value),oldObject);
}
else
{
return(id)0;
}
}

# 670 "bag.m"
static BOOL i_Bag_includesAllOf_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT36,objcT37,objcT39;

# 678 "bag.m"
BOOL res=(BOOL)1;
id e,seq=(objcT36=aCltn,(*_imp(objcT36,selTransTbl[13]))(objcT36,selTransTbl[13]));
while((e=(objcT37=seq,(*_imp(objcT37,selTransTbl[14]))(objcT37,selTransTbl[14]))))
{
id objcT38;

# 682 "bag.m"
if( !(objcT38=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT38,selTransTbl[19]))(objcT38,selTransTbl[19],e)))
{
res=(BOOL)0;
goto done;
}
}
done:

(objcT39=seq,(*_imp(objcT39,selTransTbl[6]))(objcT39,selTransTbl[6]));

return res;
}
}

static BOOL i_Bag_includesAnyOf_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT40,objcT41,objcT43;

# 704 "bag.m"
BOOL res=(BOOL)0;
id e,seq=(objcT40=aCltn,(*_imp(objcT40,selTransTbl[13]))(objcT40,selTransTbl[13]));
while((e=(objcT41=seq,(*_imp(objcT41,selTransTbl[14]))(objcT41,selTransTbl[14]))))
{
id objcT42;

# 708 "bag.m"
if((objcT42=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT42,selTransTbl[19]))(objcT42,selTransTbl[19],e)))
{
res=(BOOL)1;
goto done;
}
}
done:

(objcT43=seq,(*_imp(objcT43,selTransTbl[6]))(objcT43,selTransTbl[6]));

return res;
}
}

# 728 "bag.m"
static id i_Bag_addAll_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT44;

# 732 "bag.m"
(objcT44=(id)self,(*_imp(objcT44,selTransTbl[20]))(objcT44,selTransTbl[20]));
}
else
{
id objcT45,objcT46,objcT48;

# 736 "bag.m"
id e,seq;

seq=(objcT45=aCltn,(*_imp(objcT45,selTransTbl[13]))(objcT45,selTransTbl[13]));
while((e=(objcT46=seq,(*_imp(objcT46,selTransTbl[14]))(objcT46,selTransTbl[14]))))
{
id objcT47;

# 741 "bag.m"
(objcT47=(id)self,(*_imp(objcT47,selTransTbl[3]))(objcT47,selTransTbl[3],e));
}

seq=(objcT48=seq,(*_imp(objcT48,selTransTbl[6]))(objcT48,selTransTbl[6]));

}

return(id)self;
}

static id i_Bag_addContentsOf_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT49;

# 753 "bag.m"
return(objcT49=(id)self,(*_imp(objcT49,selTransTbl[21]))(objcT49,selTransTbl[21],aCltn));
}

static id i_Bag_addContentsTo_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT50;

# 758 "bag.m"
return(objcT50=aCltn,(*_imp(objcT50,selTransTbl[21]))(objcT50,selTransTbl[21],(id)self));
}

static id i_Bag_removeAll_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT51;

# 765 "bag.m"
(objcT51=(id)self,(*_imp(objcT51,selTransTbl[22]))(objcT51,selTransTbl[22]));
}
else
{
id objcT52,objcT53,objcT55;

# 769 "bag.m"
id e,seq;

seq=(objcT52=aCltn,(*_imp(objcT52,selTransTbl[13]))(objcT52,selTransTbl[13]));
while((e=(objcT53=seq,(*_imp(objcT53,selTransTbl[14]))(objcT53,selTransTbl[14]))))
{
id objcT54;

# 774 "bag.m"
(objcT54=(id)self,(*_imp(objcT54,selTransTbl[23]))(objcT54,selTransTbl[23],e));
}

seq=(objcT55=seq,(*_imp(objcT55,selTransTbl[6]))(objcT55,selTransTbl[6]));

}

return(id)self;
}

static id i_Bag_removeContentsFrom_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT56;

# 786 "bag.m"
return(objcT56=aCltn,(*_imp(objcT56,selTransTbl[24]))(objcT56,selTransTbl[24],(id)self));
}

static id i_Bag_removeContentsOf_(struct Bag_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT57;

# 791 "bag.m"
return(objcT57=(id)self,(*_imp(objcT57,selTransTbl[24]))(objcT57,selTransTbl[24],aCltn));
}

# 800 "bag.m"
static id i_Bag_intersection_(struct Bag_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT58;

# 804 "bag.m"
return(objcT58=(id)self,(*_imp(objcT58,selTransTbl[4]))(objcT58,selTransTbl[4]));
}
else
{
id objcT59,objcT60,objcT61,objcT64;

# 808 "bag.m"
id anElement,elements;
id intersection=(objcT59=self->isa,(*_imp(objcT59,selTransTbl[1]))(objcT59,selTransTbl[1]));

elements=(objcT60=(id)self,(*_imp(objcT60,selTransTbl[13]))(objcT60,selTransTbl[13]));
while((anElement=(objcT61=elements,(*_imp(objcT61,selTransTbl[14]))(objcT61,selTransTbl[14]))))
{
id objcT62,objcT63;

# 814 "bag.m"
if((objcT62=bag,(*_imp(objcT62,selTransTbl[25]))(objcT62,selTransTbl[25],anElement)))
(objcT63=intersection,(*_imp(objcT63,selTransTbl[3]))(objcT63,selTransTbl[3],anElement));
}

elements=(objcT64=elements,(*_imp(objcT64,selTransTbl[6]))(objcT64,selTransTbl[6]));


return intersection;
}
}

static id i_Bag_union_(struct Bag_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT65;

# 829 "bag.m"
return(objcT65=(id)self,(*_imp(objcT65,selTransTbl[4]))(objcT65,selTransTbl[4]));
}
else
{
id objcT66,objcT67;

# 833 "bag.m"
return(objcT66=(objcT67=(id)self,(*_imp(objcT67,selTransTbl[4]))(objcT67,selTransTbl[4])),(*_imp(objcT66,selTransTbl[21]))(objcT66,selTransTbl[21],bag));
}
}

static id i_Bag_difference_(struct Bag_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT68;

# 841 "bag.m"
return(objcT68=self->isa,(*_imp(objcT68,selTransTbl[1]))(objcT68,selTransTbl[1]));
}
else
{
id objcT69,objcT70;

# 845 "bag.m"
return(objcT69=(objcT70=(id)self,(*_imp(objcT70,selTransTbl[4]))(objcT70,selTransTbl[4])),(*_imp(objcT69,selTransTbl[24]))(objcT69,selTransTbl[24],bag));
}
}

# 36 "./set.h"
extern id  Set;

# 855 "bag.m"
static id i_Bag_asSet(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT71,objcT72;
if((objcT71=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT71,selTransTbl[10]))(objcT71,selTransTbl[10],(id)(objcT72=Set,(*_imp(objcT72,selTransTbl[11]))(objcT72,selTransTbl[11])))))
{
return(id)self;
}
else
{
id objcT73,objcT74;

# 864 "bag.m"
return(objcT73=(objcT74=Set,(*_imp(objcT74,selTransTbl[1]))(objcT74,selTransTbl[1])),(*_imp(objcT73,selTransTbl[21]))(objcT73,selTransTbl[21],(id)self));
}
}

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 868 "bag.m"
static id i_Bag_asOrdCltn(struct Bag_PRIVATE *self,SEL _cmd)
{
id objcT75,objcT76;
if((objcT75=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT75,selTransTbl[10]))(objcT75,selTransTbl[10],(id)(objcT76=OrdCltn,(*_imp(objcT76,selTransTbl[11]))(objcT76,selTransTbl[11])))))
{
return(id)self;
}
else
{
id objcT77,objcT78;

# 877 "bag.m"
return(objcT77=(objcT78=OrdCltn,(*_imp(objcT78,selTransTbl[1]))(objcT78,selTransTbl[1])),(*_imp(objcT77,selTransTbl[21]))(objcT77,selTransTbl[21],(id)self));
}
}

# 888 "bag.m"
static id i_Bag_detect_(struct Bag_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT79,objcT80,objcT83;

# 890 "bag.m"
id e,seq;

seq=(objcT79=(id)self,(*_imp(objcT79,selTransTbl[13]))(objcT79,selTransTbl[13]));

while((e=(objcT80=seq,(*_imp(objcT80,selTransTbl[14]))(objcT80,selTransTbl[14]))))
{
id objcT81;

# 896 "bag.m"
if(((objcT81=aBlock,(*_imp(objcT81,selTransTbl[26]))(objcT81,selTransTbl[26],e))))
{
id objcT82;
seq=(objcT82=seq,(*_imp(objcT82,selTransTbl[6]))(objcT82,selTransTbl[6]));

return e;
}
}


seq=(objcT83=seq,(*_imp(objcT83,selTransTbl[6]))(objcT83,selTransTbl[6]));

return(id)0;
}

static id i_Bag_detect_ifNone_(struct Bag_PRIVATE *self,SEL _cmd,id aBlock,id noneBlock)
{
id objcT84,objcT85,objcT88,objcT89;

# 913 "bag.m"
id e,seq;

seq=(objcT84=(id)self,(*_imp(objcT84,selTransTbl[13]))(objcT84,selTransTbl[13]));

while((e=(objcT85=seq,(*_imp(objcT85,selTransTbl[14]))(objcT85,selTransTbl[14]))))
{
id objcT86;

# 919 "bag.m"
if(((objcT86=aBlock,(*_imp(objcT86,selTransTbl[26]))(objcT86,selTransTbl[26],e))))
{
id objcT87;
seq=(objcT87=seq,(*_imp(objcT87,selTransTbl[6]))(objcT87,selTransTbl[6]));

return e;
}
}


seq=(objcT88=seq,(*_imp(objcT88,selTransTbl[6]))(objcT88,selTransTbl[6]));

return(objcT89=noneBlock,(*_imp(objcT89,selTransTbl[18]))(objcT89,selTransTbl[18]));
}

static id i_Bag_select_(struct Bag_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT90,objcT91,objcT92,objcT95;

# 936 "bag.m"
id e,seq;
id newObject=(objcT90=self->isa,(*_imp(objcT90,selTransTbl[1]))(objcT90,selTransTbl[1]));

seq=(objcT91=(id)self,(*_imp(objcT91,selTransTbl[13]))(objcT91,selTransTbl[13]));

while((e=(objcT92=seq,(*_imp(objcT92,selTransTbl[14]))(objcT92,selTransTbl[14]))))
{
id objcT93;

# 943 "bag.m"
if(((objcT93=testBlock,(*_imp(objcT93,selTransTbl[26]))(objcT93,selTransTbl[26],e))))
{
id objcT94;

# 945 "bag.m"
(objcT94=newObject,(*_imp(objcT94,selTransTbl[3]))(objcT94,selTransTbl[3],e));
}
}


seq=(objcT95=seq,(*_imp(objcT95,selTransTbl[6]))(objcT95,selTransTbl[6]));

return newObject;
}

static id i_Bag_reject_(struct Bag_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT96,objcT97,objcT98,objcT101;

# 957 "bag.m"
id e,seq;
id newObject=(objcT96=self->isa,(*_imp(objcT96,selTransTbl[1]))(objcT96,selTransTbl[1]));

seq=(objcT97=(id)self,(*_imp(objcT97,selTransTbl[13]))(objcT97,selTransTbl[13]));

while((e=(objcT98=seq,(*_imp(objcT98,selTransTbl[14]))(objcT98,selTransTbl[14]))))
{
id objcT99;

# 964 "bag.m"
if( !((objcT99=testBlock,(*_imp(objcT99,selTransTbl[26]))(objcT99,selTransTbl[26],e))))
{
id objcT100;

# 966 "bag.m"
(objcT100=newObject,(*_imp(objcT100,selTransTbl[3]))(objcT100,selTransTbl[3],e));
}
}


seq=(objcT101=seq,(*_imp(objcT101,selTransTbl[6]))(objcT101,selTransTbl[6]));

return newObject;
}

static id i_Bag_collect_(struct Bag_PRIVATE *self,SEL _cmd,id transformBlock)
{
id objcT102,objcT103,objcT104,objcT107;

# 978 "bag.m"
id e,seq;
id newObject=(objcT102=self->isa,(*_imp(objcT102,selTransTbl[1]))(objcT102,selTransTbl[1]));

seq=(objcT103=(id)self,(*_imp(objcT103,selTransTbl[13]))(objcT103,selTransTbl[13]));

while((e=(objcT104=seq,(*_imp(objcT104,selTransTbl[14]))(objcT104,selTransTbl[14]))))
{
id objcT105;

# 985 "bag.m"
id anImage=(objcT105=transformBlock,(*_imp(objcT105,selTransTbl[26]))(objcT105,selTransTbl[26],e));
if(anImage)
{
id objcT106;

# 988 "bag.m"
(objcT106=newObject,(*_imp(objcT106,selTransTbl[3]))(objcT106,selTransTbl[3],anImage));
}
}


seq=(objcT107=seq,(*_imp(objcT107,selTransTbl[6]))(objcT107,selTransTbl[6]));

return newObject;
}

static unsigned i_Bag_count_(struct Bag_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT108,objcT109,objcT111;

# 1000 "bag.m"
id e,seq;
unsigned c=0;

seq=(objcT108=(id)self,(*_imp(objcT108,selTransTbl[13]))(objcT108,selTransTbl[13]));
while((e=(objcT109=seq,(*_imp(objcT109,selTransTbl[14]))(objcT109,selTransTbl[14]))))
{
id objcT110;

# 1006 "bag.m"
if((objcT110=aBlock,(*_imp(objcT110,selTransTbl[26]))(objcT110,selTransTbl[26],e)))
{
c++;
}
}

seq=(objcT111=seq,(*_imp(objcT111,selTransTbl[6]))(objcT111,selTransTbl[6]));


return c;
}

# 1026 "bag.m"
static id i_Bag_elementsPerform_(struct Bag_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT112,objcT113,objcT115;

# 1028 "bag.m"
id e,seq;

seq=(objcT112=(id)self,(*_imp(objcT112,selTransTbl[13]))(objcT112,selTransTbl[13]));
while((e=(objcT113=seq,(*_imp(objcT113,selTransTbl[14]))(objcT113,selTransTbl[14]))))
{
id objcT114;

# 1033 "bag.m"
(objcT114=e,(*(id(*)(id,SEL,SEL))_imp(objcT114,selTransTbl[27]))(objcT114,selTransTbl[27],aSelector));
}

seq=(objcT115=seq,(*_imp(objcT115,selTransTbl[6]))(objcT115,selTransTbl[6]));


return(id)self;
}

static id i_Bag_elementsPerform_with_(struct Bag_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject)
{
id objcT116,objcT117,objcT119;

# 1044 "bag.m"
id e,seq;

seq=(objcT116=(id)self,(*_imp(objcT116,selTransTbl[13]))(objcT116,selTransTbl[13]));
while((e=(objcT117=seq,(*_imp(objcT117,selTransTbl[14]))(objcT117,selTransTbl[14]))))
{
id objcT118;

# 1049 "bag.m"
(objcT118=e,(*(id(*)(id,SEL,SEL,id))_imp(objcT118,selTransTbl[28]))(objcT118,selTransTbl[28],aSelector,anObject));
}

seq=(objcT119=seq,(*_imp(objcT119,selTransTbl[6]))(objcT119,selTransTbl[6]));


return(id)self;
}

static id i_Bag_elementsPerform_with_with_(struct Bag_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject)
{
id objcT120,objcT121,objcT123;

# 1060 "bag.m"
id e,seq;

seq=(objcT120=(id)self,(*_imp(objcT120,selTransTbl[13]))(objcT120,selTransTbl[13]));
while((e=(objcT121=seq,(*_imp(objcT121,selTransTbl[14]))(objcT121,selTransTbl[14]))))
{
id objcT122;

# 1065 "bag.m"
(objcT122=e,(*(id(*)(id,SEL,SEL,id,id))_imp(objcT122,selTransTbl[29]))(objcT122,selTransTbl[29],aSelector,anObject,otherObject));
}

seq=(objcT123=seq,(*_imp(objcT123,selTransTbl[6]))(objcT123,selTransTbl[6]));


return(id)self;
}

static id i_Bag_elementsPerform_with_with_with_(struct Bag_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject,id thirdObj)
{
id objcT124,objcT125,objcT127;

# 1076 "bag.m"
id e,seq;

seq=(objcT124=(id)self,(*_imp(objcT124,selTransTbl[13]))(objcT124,selTransTbl[13]));
while((e=(objcT125=seq,(*_imp(objcT125,selTransTbl[14]))(objcT125,selTransTbl[14]))))
{
id objcT126;

# 1081 "bag.m"
(objcT126=e,(*(id(*)(id,SEL,SEL,id,id,id))_imp(objcT126,selTransTbl[30]))(objcT126,selTransTbl[30],aSelector,anObject,otherObject,thirdObj));
}

seq=(objcT127=seq,(*_imp(objcT127,selTransTbl[6]))(objcT127,selTransTbl[6]));


return(id)self;
}

# 1096 "bag.m"
static id i_Bag_do_(struct Bag_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT128,objcT129,objcT131;

# 1098 "bag.m"
id e,seq;

seq=(objcT128=(id)self,(*_imp(objcT128,selTransTbl[13]))(objcT128,selTransTbl[13]));

while((e=(objcT129=seq,(*_imp(objcT129,selTransTbl[14]))(objcT129,selTransTbl[14]))))
{
id objcT130;

# 1104 "bag.m"
(objcT130=aBlock,(*_imp(objcT130,selTransTbl[26]))(objcT130,selTransTbl[26],e));
}


seq=(objcT131=seq,(*_imp(objcT131,selTransTbl[6]))(objcT131,selTransTbl[6]));

return(id)self;
}
static id i_Bag_do_until_(struct Bag_PRIVATE *self,SEL _cmd,id aBlock,BOOL*flag)
{
id objcT132,objcT133,objcT135;

# 1114 "bag.m"
id e,seq;

seq=(objcT132=(id)self,(*_imp(objcT132,selTransTbl[13]))(objcT132,selTransTbl[13]));

while((e=(objcT133=seq,(*_imp(objcT133,selTransTbl[14]))(objcT133,selTransTbl[14]))))
{
id objcT134;

# 1120 "bag.m"
(objcT134=aBlock,(*_imp(objcT134,selTransTbl[26]))(objcT134,selTransTbl[26],e));
if( *flag)
break;
}


seq=(objcT135=seq,(*_imp(objcT135,selTransTbl[6]))(objcT135,selTransTbl[6]));

return(id)self;
}

# 1138 "bag.m"
static id i_Bag_find_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
int*m;
return(anObject)? *find(( &self->value),anObject, &m):(id)0;
}

static BOOL i_Bag_contains_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT136;

# 1146 "bag.m"
return(BOOL)((objcT136=(id)self,(*_imp(objcT136,selTransTbl[25]))(objcT136,selTransTbl[25],anObject))?(BOOL)1:(BOOL)0);
}

static BOOL i_Bag_includes_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT137;

# 1151 "bag.m"
return(BOOL)((objcT137=(id)self,(*_imp(objcT137,selTransTbl[25]))(objcT137,selTransTbl[25],anObject))?(BOOL)1:(BOOL)0);
}

static unsigned i_Bag_occurrencesOf_(struct Bag_PRIVATE *self,SEL _cmd,id anObject)
{
int*m;
find(( &self->value),anObject, &m);
return *m;
}

# 1167 "bag.m"
static id i_Bag_printOn_(struct Bag_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT138,objcT139,objcT140;
(objcT138=(objcT139=(objcT140=(id)self,(*_imp(objcT140,selTransTbl[13]))(objcT140,selTransTbl[13])),(*(id(*)(id,SEL,IOD))_imp(objcT139,selTransTbl[31]))(objcT139,selTransTbl[31],aFile)),(*_imp(objcT138,selTransTbl[6]))(objcT138,selTransTbl[6]));
return(id)self;
# 1176 "bag.m"
}

# 1185 "bag.m"
static void
ptrfileout(id aFiler,id*a,int*m,int n)
{
while(n--)
{
id obj= *a++;
int cnt= *m++;
if(cnt)
{
id objcT141,objcT142;

# 1194 "bag.m"
(objcT141=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT141,selTransTbl[32]))(objcT141,selTransTbl[32], &obj,'@'));
(objcT142=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT142,selTransTbl[32]))(objcT142,selTransTbl[32], &cnt,'i'));
}
}
}

static void
ptrfilein(id aFiler,id*a,int*m,int n)
{
# 1209 "bag.m"
while(n--)
{
id objcT143,objcT144;

# 1211 "bag.m"
(objcT143=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT143,selTransTbl[33]))(objcT143,selTransTbl[33],a++,'@'));
(objcT144=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT144,selTransTbl[33]))(objcT144,selTransTbl[33],m++,'i'));
}
}

static void
fileout(id aFiler,objbag_t self)
{
id objcT145;

# 1219 "bag.m"
int n=self->count;
(objcT145=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT145,selTransTbl[32]))(objcT145,selTransTbl[32], &n,'i'));
ptrfileout(aFiler,self->ptr,self->cnts,self->capacity);
}

static void
filein(id aFiler,objbag_t self)
{
id objcT146;

# 1227 "bag.m"
int n;
(objcT146=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT146,selTransTbl[33]))(objcT146,selTransTbl[33], &n,'i'));
init(self,n,n);
ptrfilein(aFiler,self->ptr,self->cnts,n);
}

static id i_Bag_fileOutOn_(struct Bag_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT147;

# 1235 "bag.m"
(objcT147=_Bag.clsSuper,(*_impSuper(objcT147,selTransTbl[34]))((id)self,selTransTbl[34],aFiler));
fileout(aFiler,( &self->value));
return(id)self;
}

static id i_Bag_fileInFrom_(struct Bag_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT148;

# 1242 "bag.m"
(objcT148=_Bag.clsSuper,(*_impSuper(objcT148,selTransTbl[35]))((id)self,selTransTbl[35],aFiler));
filein(aFiler,( &self->value));
return(id)self;
}

static id i_Bag_awakeFrom_(struct Bag_PRIVATE *self,SEL _cmd,id aFiler)
{

expand(( &self->value));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Cltn;
extern struct _SHARED _Cltn;
extern struct _SHARED __Cltn;
static struct _SLT _Bag_clsDispatchTbl[] ={
{"new",(id (*)())c_Bag_new},
{"new:",(id (*)())c_Bag_new_},
{"with:",(id (*)())c_Bag_with_},
{"with:with:",(id (*)())c_Bag_with_with_},
{"add:",(id (*)())c_Bag_add_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Bag_nstDispatchTbl[] ={
{"copy",(id (*)())i_Bag_copy},
{"deepCopy",(id (*)())i_Bag_deepCopy},
{"emptyYourself",(id (*)())i_Bag_emptyYourself},
{"addYourself",(id (*)())i_Bag_addYourself},
{"freeContents",(id (*)())i_Bag_freeContents},
{"free",(id (*)())i_Bag_free},
{"release",(id (*)())i_Bag_release},
{"objbagvalue",(id (*)())i_Bag_objbagvalue},
{"size",(id (*)())i_Bag_size},
{"isEmpty",(id (*)())i_Bag_isEmpty},
{"eachElement",(id (*)())i_Bag_eachElement},
{"hash",(id (*)())i_Bag_hash},
{"isEqual:",(id (*)())i_Bag_isEqual_},
{"add:",(id (*)())i_Bag_add_},
{"addNTest:",(id (*)())i_Bag_addNTest_},
{"filter:",(id (*)())i_Bag_filter_},
{"add:ifDuplicate:",(id (*)())i_Bag_add_ifDuplicate_},
{"replace:",(id (*)())i_Bag_replace_},
{"remove:",(id (*)())i_Bag_remove_},
{"remove:ifAbsent:",(id (*)())i_Bag_remove_ifAbsent_},
{"includesAllOf:",(id (*)())i_Bag_includesAllOf_},
{"includesAnyOf:",(id (*)())i_Bag_includesAnyOf_},
{"addAll:",(id (*)())i_Bag_addAll_},
{"addContentsOf:",(id (*)())i_Bag_addContentsOf_},
{"addContentsTo:",(id (*)())i_Bag_addContentsTo_},
{"removeAll:",(id (*)())i_Bag_removeAll_},
{"removeContentsFrom:",(id (*)())i_Bag_removeContentsFrom_},
{"removeContentsOf:",(id (*)())i_Bag_removeContentsOf_},
{"intersection:",(id (*)())i_Bag_intersection_},
{"union:",(id (*)())i_Bag_union_},
{"difference:",(id (*)())i_Bag_difference_},
{"asSet",(id (*)())i_Bag_asSet},
{"asOrdCltn",(id (*)())i_Bag_asOrdCltn},
{"detect:",(id (*)())i_Bag_detect_},
{"detect:ifNone:",(id (*)())i_Bag_detect_ifNone_},
{"select:",(id (*)())i_Bag_select_},
{"reject:",(id (*)())i_Bag_reject_},
{"collect:",(id (*)())i_Bag_collect_},
{"count:",(id (*)())i_Bag_count_},
{"elementsPerform:",(id (*)())i_Bag_elementsPerform_},
{"elementsPerform:with:",(id (*)())i_Bag_elementsPerform_with_},
{"elementsPerform:with:with:",(id (*)())i_Bag_elementsPerform_with_with_},
{"elementsPerform:with:with:with:",(id (*)())i_Bag_elementsPerform_with_with_with_},
{"do:",(id (*)())i_Bag_do_},
{"do:until:",(id (*)())i_Bag_do_until_},
{"find:",(id (*)())i_Bag_find_},
{"contains:",(id (*)())i_Bag_contains_},
{"includes:",(id (*)())i_Bag_includes_},
{"occurrencesOf:",(id (*)())i_Bag_occurrencesOf_},
{"printOn:",(id (*)())i_Bag_printOn_},
{"fileOutOn:",(id (*)())i_Bag_fileOutOn_},
{"fileInFrom:",(id (*)())i_Bag_fileInFrom_},
{"awakeFrom:",(id (*)())i_Bag_awakeFrom_},
{(char*)0,(id (*)())0}
};
id Bag = (id)&_Bag;
id  *OBJCCLASS_Bag(void) { return &Bag; }
struct _SHARED  _Bag = {
  (id)&__Bag,
  (id)&_Cltn,
  "Bag",
  0,
  sizeof(struct Bag_PRIVATE),
  53,
  _Bag_nstDispatchTbl,
  41,
  &bag_modDesc,
  0,
  (id)0,
  &Bag,
};
id  OBJCCFUNC_Bag(void) { return (id)&_Bag; }
id  OBJCCSUPER_Bag(void) { return _Bag.clsSuper; }
struct _SHARED __Bag = {
  (id)&__Object,
  (id)&__Cltn,
  "Bag",
  0,
  sizeof(struct _SHARED),
  5,
  _Bag_clsDispatchTbl,
  34,
  &bag_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Bag(void) { return (id)&__Bag; }
id  OBJCMSUPER_Bag(void) { return __Bag.clsSuper; }
static char *_selTransTbl[] ={
"new:",
"new",
"objbagvalue",
"add:",
"copy",
"deepCopy",
"free",
"notImplemented:",
"over:",
"hash",
"isKindOf:",
"class",
"size",
"eachElement",
"next",
"contains:",
"isEqual:",
"addNTest:",
"value",
"includes:",
"addYourself",
"addAll:",
"emptyYourself",
"remove:",
"removeAll:",
"find:",
"value:",
"perform:",
"perform:with:",
"perform:with:with:",
"perform:with:with:with:",
"printOn:",
"fileOut:type:",
"fileIn:type:",
"fileOutOn:",
"fileInFrom:",
0
};
struct modDescriptor bag_modDesc = {
  "bag",
  "objc3.3.19",
  0L,
  0,
  0,
  &Bag,
  36,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_bag(void)
{
  selTransTbl = _selTransTbl;
  return &bag_modDesc;
}
int _OBJCPOSTLINK_bag = 1;


