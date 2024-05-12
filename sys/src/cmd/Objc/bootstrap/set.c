# 1 "set.m"
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
extern struct modDescriptor  *_OBJCBIND_set(void);
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
extern struct modDescriptor set_modDesc;

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

# 28 "./set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 28 "./setseq.h"
typedef struct objsetseq
{
objset_t set;
int offset;
}*
objsetseq_t;
# 31 "./ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
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
# 36 "./set.h"
struct Set_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 38 "./set.h"
struct objset value;};

# 36 "./set.h"
extern id  Set;

# 36 "./set.h"
extern struct _SHARED _Set;
extern struct _SHARED __Set;


# 45 "set.m"
static void
ptrzero(id*p,int c)
{
while(c--)
{ *
p++=(id)0;
}
}

# 70 "set.m"
static void
init(objset_t self,int n,int c)
{
(void)0;
self->count=n;
self->capacity=c;
self->ptr=(id*)OC_Calloc(c*sizeof(id));
}

static void
initzero(objset_t self,int c)
{
init(self,0,c);
}

static id c_Set_new(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 87 "set.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],16));
}

static id c_Set_new_(struct Set_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT1,objcT2;

# 92 "set.m"
id newObj=(objcT1=__Set.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
initzero((objcT2=newObj,(*(objset_t(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2])),n);
return newObj;
}

# 103 "set.m"
static id c_Set_with_(struct Set_PRIVATE *self,SEL _cmd,int nArgs,...)
{
id objcT3;

# 105 "set.m"
id newObject;


va_list vp;

newObject=(objcT3=(id)self,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1]));
# 125 "set.m"
va_start(vp,nArgs);
while(nArgs-->0)
{
id objcT4;

# 128 "set.m"
id anObject=va_arg(vp,id);
(objcT4=newObject,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3],anObject));
}
va_end(vp);


return newObject;
}

static id c_Set_with_with_(struct Set_PRIVATE *self,SEL _cmd,id firstObject,id nextObject)
{
id objcT5,objcT6,objcT7;

# 139 "set.m"
return(objcT5=(objcT6=(objcT7=(id)self,(*_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1])),(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3],firstObject)),(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],nextObject));
}

static id c_Set_add_(struct Set_PRIVATE *self,SEL _cmd,id firstObject)
{
id objcT8,objcT9;

# 144 "set.m"
return(objcT8=(objcT9=(id)self,(*_imp(objcT9,selTransTbl[1]))(objcT9,selTransTbl[1])),(*_imp(objcT8,selTransTbl[3]))(objcT8,selTransTbl[3],firstObject));
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
copy(objset_t dst,objset_t src)
{
init(dst,src->count,src->capacity);
ptrcopy(dst->ptr,src->ptr,src->capacity);
}

static id i_Set_copy(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11;

# 165 "set.m"
id aCopy=(objcT10=_Set.clsSuper,(*_impSuper(objcT10,selTransTbl[4]))((id)self,selTransTbl[4]));
copy((objcT11=aCopy,(*(objset_t(*)(id,SEL))_imp(objcT11,selTransTbl[2]))(objcT11,selTransTbl[2])),( &self->value));
return aCopy;
}

static void
ptrdeepcopy(id*p,id*q,int c)
{
while(c--)
{
id objcT12;

# 175 "set.m"
id obj= *q++; *
p++=(obj)?(objcT12=obj,(*_imp(objcT12,selTransTbl[5]))(objcT12,selTransTbl[5])):(id)0;
}
}

static void
deepcopy(objset_t dst,objset_t src)
{
init(dst,src->count,src->capacity);
ptrdeepcopy(dst->ptr,src->ptr,src->capacity);
}

static id i_Set_deepCopy(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14;


id aCopy=(objcT13=_Set.clsSuper,(*_impSuper(objcT13,selTransTbl[4]))((id)self,selTransTbl[4]));
deepcopy((objcT14=aCopy,(*(objset_t(*)(id,SEL))_imp(objcT14,selTransTbl[2]))(objcT14,selTransTbl[2])),( &self->value));
return aCopy;
}

static void
empty(objset_t self)
{
self->count=0;
ptrzero(self->ptr,self->capacity);
}

static id i_Set_emptyYourself(struct Set_PRIVATE *self,SEL _cmd)
{
empty(( &self->value));
return(id)self;
}

static id i_Set_addYourself(struct Set_PRIVATE *self,SEL _cmd)
{

return(id)self;
}

static void
ptrclear(id*p,int c)
{
while(c--)
{
id objcT15;

# 221 "set.m"
id obj= *p; *
p++=(obj)?(objcT15=obj,(*_imp(objcT15,selTransTbl[6]))(objcT15,selTransTbl[6])):(id)0;
}
}

static void
freecontents(objset_t self)
{
self->count=0;
ptrclear(self->ptr,self->capacity);
(void)0;
}

static id i_Set_freeContents(struct Set_PRIVATE *self,SEL _cmd)
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

# 245 "set.m"
id obj= *p; *
p++=(obj)?(objcT16=obj,(*_imp(objcT16,selTransTbl[7]))(objcT16,selTransTbl[7])):(id)0;
}
}

static void
freeall(objset_t self)
{
self->count=0;
ptrclearall(self->ptr,self->capacity);
(void)0;
}

static id i_Set_freeAll(struct Set_PRIVATE *self,SEL _cmd)
{
freeall(( &self->value));
return(id)self;
}

static void
clear(objset_t self)
{
self->count=0;
self->capacity=0;
OC_Free(self->ptr);
self->ptr=NULL;
}

static id i_Set_free(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT17;

# 275 "set.m"
clear(( &self->value));
return(objcT17=_Set.clsSuper,(*_impSuper(objcT17,selTransTbl[6]))((id)self,selTransTbl[6]));
}

static id i_Set_release(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 286 "set.m"
return(objcT18=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT18,selTransTbl[8]))(objcT18,selTransTbl[8],_cmd));

}

# 296 "set.m"
static objset_t i_Set_objsetvalue(struct Set_PRIVATE *self,SEL _cmd)
{
return &self->value;
}

static int
count(objset_t self)
{
(void)0;
return self->count;
}

static unsigned i_Set_size(struct Set_PRIVATE *self,SEL _cmd)
{
return(unsigned)count(( &self->value));
}

static BOOL i_Set_isEmpty(struct Set_PRIVATE *self,SEL _cmd)
{
return count(( &self->value))==0;
}

# 35 "./setseq.h"
extern id  SetSequence;

# 35 "./sequence.h"
extern id  Sequence;

# 318 "set.m"
static id i_Set_eachElement(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT19,objcT20;

# 320 "set.m"
id aCarrier=(objcT19=SetSequence,(*_imp(objcT19,selTransTbl[9]))(objcT19,selTransTbl[9],(id)self));
return(objcT20=Sequence,(*_imp(objcT20,selTransTbl[9]))(objcT20,selTransTbl[9],aCarrier));
}

# 330 "set.m"
static unsigned
ptrhash(id*p,int n)
{
unsigned code=n;
while(n--)
{
id objcT21;

# 336 "set.m"
id q= *p++;
if(q)
code^=(objcT21=q,(*(unsigned(*)(id,SEL))_imp(objcT21,selTransTbl[10]))(objcT21,selTransTbl[10]));
}
return code;
}

static unsigned
hashcontents(objset_t a)
{
return ptrhash(a->ptr,a->count);
}

static unsigned i_Set_hash(struct Set_PRIVATE *self,SEL _cmd)
{
return hashcontents( &self->value);
}

static BOOL i_Set_isEqual_(struct Set_PRIVATE *self,SEL _cmd,id set)
{
id objcT22,objcT23,objcT24,objcT25,objcT26;
id objcT27,objcT29;

# 356 "set.m"
id e,seq;
BOOL res=(BOOL)1;
if((id)self==set)
{
return(BOOL)1;
}
if( !(objcT22=set,(*(BOOL(*)(id,SEL,id))_imp(objcT22,selTransTbl[11]))(objcT22,selTransTbl[11],(id)(objcT23=Set,(*_imp(objcT23,selTransTbl[12]))(objcT23,selTransTbl[12])))))
{
return(BOOL)0;
}
if((objcT24=set,(*(unsigned(*)(id,SEL))_imp(objcT24,selTransTbl[13]))(objcT24,selTransTbl[13]))!=(objcT25=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT25,selTransTbl[13]))(objcT25,selTransTbl[13])))
{
return(BOOL)0;
}
seq=(objcT26=(id)self,(*_imp(objcT26,selTransTbl[14]))(objcT26,selTransTbl[14]));
while((e=(objcT27=seq,(*_imp(objcT27,selTransTbl[15]))(objcT27,selTransTbl[15]))))
{
id objcT28;

# 373 "set.m"
if((objcT28=set,(*(BOOL(*)(id,SEL,id))_imp(objcT28,selTransTbl[16]))(objcT28,selTransTbl[16],e)))
{
res=(BOOL)0;
goto done;
}
}
done:

(objcT29=seq,(*_imp(objcT29,selTransTbl[6]))(objcT29,selTransTbl[6]));

return res;
}

# 392 "set.m"
static id*
ptrfind(id*p,id obj,int n)
{
id objcT30;

# 395 "set.m"
id*begin,*now,*end;

begin=p;
now=p+(((objcT30=obj,(*(unsigned(*)(id,SEL))_imp(objcT30,selTransTbl[10]))(objcT30,selTransTbl[10])))%n);
end=p+n;

for(;n--;now++)
{
id objcT31;

# 403 "set.m"
if(now>=end)
{
now=begin;
}
if( *now==(id)0||(objcT31= *now,(*(BOOL(*)(id,SEL,id))_imp(objcT31,selTransTbl[17]))(objcT31,selTransTbl[17],obj)))
{
return now;
}
}

fprintf(stderr,"find: table full shouldn't happen");
return NULL;
}

static id*
find(objset_t self,id obj)
{
(void)0;
return ptrfind(self->ptr,obj,self->capacity);
}

static id i_Set_add_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT32;

# 426 "set.m"
(objcT32=(id)self,(*_imp(objcT32,selTransTbl[18]))(objcT32,selTransTbl[18],anObject));
return(id)self;
}

static BOOL
needsexpand(objset_t self)
{
return 2*self->count>self->capacity;
}


static void
ptrrehash(id*newp,int newc,id*old,int oldc)
{
while(oldc--)
{
id obj= *old++;
id*newend=newp+newc;
if(obj)
{
id objcT33;

# 446 "set.m"
id*pos=newp+((objcT33=obj,(*(unsigned(*)(id,SEL))_imp(objcT33,selTransTbl[10]))(objcT33,selTransTbl[10]))%((unsigned)newc));
while( *pos)
{
pos++;
if(pos==newend)
{
pos=newp;
}
} *
pos=obj;
}
}
}

static void
rehash(objset_t self)
{
int c;
id*newp,*old;

c=self->capacity;
old=self->ptr;
newp=(id*)OC_Calloc(c*sizeof(id));

(void)0;
ptrrehash(newp,c,old,c);
(void)0;

OC_Free(old);
self->ptr=newp;
}

static void
expand(objset_t self)
{
id*newp,*old;
int newc,oldc;

oldc=self->capacity;
old=self->ptr;
newc=1+2*oldc;
newp=(id*)OC_Calloc(newc*sizeof(id));

(void)0;
ptrrehash(newp,newc,old,oldc);
(void)0;

OC_Free(old);
self->ptr=newp;
self->capacity=newc;
}

static id
add(objset_t self,id obj)
{
id*p;

if(needsexpand(self))
{
expand(self);
}

if( *(p=find(self,obj)))
{
return(id)0;
}
else
{
self->count++;
return *p=obj;
}
}

static id i_Set_addNTest_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
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
filter(objset_t self,id obj)
{
id*p;

if(needsexpand(self))
{
expand(self);
}

if( *(p=find(self,obj)))
{
return *p;
}
else
{
self->count++; *
p=obj;
return(id)0;
}
}

static id i_Set_filter_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
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


static id i_Set_add_ifDuplicate_(struct Set_PRIVATE *self,SEL _cmd,id anObject,id aBlock)
{
if(anObject)
{
id t=filter(( &self->value),anObject);
if(t)
{
id objcT35;

# 584 "set.m"
(objcT35=aBlock,(*_imp(objcT35,selTransTbl[19]))(objcT35,selTransTbl[19]));
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
replace(objset_t self,id obj)
{
id*p;

if(needsexpand(self))
{
expand(self);
}

if( *(p=find(self,obj)))
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

static id i_Set_replace_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
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

# 641 "set.m"
static id
delete(objset_t self,id obj)
{
id*p;

if( *(p=find(self,obj)))
{
id tmp= *p; *
p=(id)0;
self->count--;
rehash(self);
return tmp;
}
else
{
return(id)0;
}
}

static id i_Set_remove_(struct Set_PRIVATE *self,SEL _cmd,id oldObject)
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

static id i_Set_remove_ifAbsent_(struct Set_PRIVATE *self,SEL _cmd,id oldObject,id exceptionBlock)
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

# 690 "set.m"
static BOOL i_Set_includesAllOf_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT36,objcT37,objcT39;

# 698 "set.m"
BOOL res=(BOOL)1;
id e,seq=(objcT36=aCltn,(*_imp(objcT36,selTransTbl[14]))(objcT36,selTransTbl[14]));
while((e=(objcT37=seq,(*_imp(objcT37,selTransTbl[15]))(objcT37,selTransTbl[15]))))
{
id objcT38;

# 702 "set.m"
if( !(objcT38=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT38,selTransTbl[20]))(objcT38,selTransTbl[20],e)))
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

static BOOL i_Set_includesAnyOf_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT40,objcT41,objcT43;

# 724 "set.m"
BOOL res=(BOOL)0;
id e,seq=(objcT40=aCltn,(*_imp(objcT40,selTransTbl[14]))(objcT40,selTransTbl[14]));
while((e=(objcT41=seq,(*_imp(objcT41,selTransTbl[15]))(objcT41,selTransTbl[15]))))
{
id objcT42;

# 728 "set.m"
if((objcT42=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT42,selTransTbl[20]))(objcT42,selTransTbl[20],e)))
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

# 748 "set.m"
static id i_Set_addAll_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT44;

# 752 "set.m"
(objcT44=(id)self,(*_imp(objcT44,selTransTbl[21]))(objcT44,selTransTbl[21]));
}
else
{
id objcT45,objcT46,objcT48;

# 756 "set.m"
id e,seq;

seq=(objcT45=aCltn,(*_imp(objcT45,selTransTbl[14]))(objcT45,selTransTbl[14]));
while((e=(objcT46=seq,(*_imp(objcT46,selTransTbl[15]))(objcT46,selTransTbl[15]))))
{
id objcT47;

# 761 "set.m"
(objcT47=(id)self,(*_imp(objcT47,selTransTbl[3]))(objcT47,selTransTbl[3],e));
}

seq=(objcT48=seq,(*_imp(objcT48,selTransTbl[6]))(objcT48,selTransTbl[6]));

}

return(id)self;
}

static id i_Set_addContentsOf_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT49;

# 773 "set.m"
return(objcT49=(id)self,(*_imp(objcT49,selTransTbl[22]))(objcT49,selTransTbl[22],aCltn));
}

static id i_Set_addContentsTo_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT50;

# 778 "set.m"
return(objcT50=aCltn,(*_imp(objcT50,selTransTbl[22]))(objcT50,selTransTbl[22],(id)self));
}

static id i_Set_removeAll_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT51;

# 785 "set.m"
(objcT51=(id)self,(*_imp(objcT51,selTransTbl[23]))(objcT51,selTransTbl[23]));
}
else
{
id objcT52,objcT53,objcT55;

# 789 "set.m"
id e,seq;

seq=(objcT52=aCltn,(*_imp(objcT52,selTransTbl[14]))(objcT52,selTransTbl[14]));
while((e=(objcT53=seq,(*_imp(objcT53,selTransTbl[15]))(objcT53,selTransTbl[15]))))
{
id objcT54;

# 794 "set.m"
(objcT54=(id)self,(*_imp(objcT54,selTransTbl[24]))(objcT54,selTransTbl[24],e));
}

seq=(objcT55=seq,(*_imp(objcT55,selTransTbl[6]))(objcT55,selTransTbl[6]));

}

return(id)self;
}

static id i_Set_removeContentsFrom_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT56;

# 806 "set.m"
return(objcT56=aCltn,(*_imp(objcT56,selTransTbl[25]))(objcT56,selTransTbl[25],(id)self));
}

static id i_Set_removeContentsOf_(struct Set_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT57;

# 811 "set.m"
return(objcT57=(id)self,(*_imp(objcT57,selTransTbl[25]))(objcT57,selTransTbl[25],aCltn));
}

# 820 "set.m"
static id i_Set_intersection_(struct Set_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT58;

# 824 "set.m"
return(objcT58=(id)self,(*_imp(objcT58,selTransTbl[4]))(objcT58,selTransTbl[4]));
}
else
{
id objcT59,objcT60,objcT61,objcT64;

# 828 "set.m"
id anElement,elements;
id intersection=(objcT59=self->isa,(*_imp(objcT59,selTransTbl[1]))(objcT59,selTransTbl[1]));

elements=(objcT60=(id)self,(*_imp(objcT60,selTransTbl[14]))(objcT60,selTransTbl[14]));
while((anElement=(objcT61=elements,(*_imp(objcT61,selTransTbl[15]))(objcT61,selTransTbl[15]))))
{
id objcT62,objcT63;

# 834 "set.m"
if((objcT62=bag,(*_imp(objcT62,selTransTbl[26]))(objcT62,selTransTbl[26],anElement)))
(objcT63=intersection,(*_imp(objcT63,selTransTbl[3]))(objcT63,selTransTbl[3],anElement));
}

elements=(objcT64=elements,(*_imp(objcT64,selTransTbl[6]))(objcT64,selTransTbl[6]));


return intersection;
}
}

static id i_Set_union_(struct Set_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT65;

# 849 "set.m"
return(objcT65=(id)self,(*_imp(objcT65,selTransTbl[4]))(objcT65,selTransTbl[4]));
}
else
{
id objcT66,objcT67;

# 853 "set.m"
return(objcT66=(objcT67=(id)self,(*_imp(objcT67,selTransTbl[4]))(objcT67,selTransTbl[4])),(*_imp(objcT66,selTransTbl[22]))(objcT66,selTransTbl[22],bag));
}
}

static id i_Set_difference_(struct Set_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT68;

# 861 "set.m"
return(objcT68=self->isa,(*_imp(objcT68,selTransTbl[1]))(objcT68,selTransTbl[1]));
}
else
{
id objcT69,objcT70;

# 865 "set.m"
return(objcT69=(objcT70=(id)self,(*_imp(objcT70,selTransTbl[4]))(objcT70,selTransTbl[4])),(*_imp(objcT69,selTransTbl[25]))(objcT69,selTransTbl[25],bag));
}
}

# 875 "set.m"
static id i_Set_asSet(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT71,objcT72;
if((objcT71=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT71,selTransTbl[11]))(objcT71,selTransTbl[11],(id)(objcT72=Set,(*_imp(objcT72,selTransTbl[12]))(objcT72,selTransTbl[12])))))
{
return(id)self;
}
else
{
id objcT73,objcT74;

# 884 "set.m"
return(objcT73=(objcT74=Set,(*_imp(objcT74,selTransTbl[1]))(objcT74,selTransTbl[1])),(*_imp(objcT73,selTransTbl[22]))(objcT73,selTransTbl[22],(id)self));
}
}

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 888 "set.m"
static id i_Set_asOrdCltn(struct Set_PRIVATE *self,SEL _cmd)
{
id objcT75,objcT76;
if((objcT75=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT75,selTransTbl[11]))(objcT75,selTransTbl[11],(id)(objcT76=OrdCltn,(*_imp(objcT76,selTransTbl[12]))(objcT76,selTransTbl[12])))))
{
return(id)self;
}
else
{
id objcT77,objcT78;

# 897 "set.m"
return(objcT77=(objcT78=OrdCltn,(*_imp(objcT78,selTransTbl[1]))(objcT78,selTransTbl[1])),(*_imp(objcT77,selTransTbl[22]))(objcT77,selTransTbl[22],(id)self));
}
}

# 908 "set.m"
static id i_Set_detect_(struct Set_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT79,objcT80,objcT83;

# 910 "set.m"
id e,seq;

seq=(objcT79=(id)self,(*_imp(objcT79,selTransTbl[14]))(objcT79,selTransTbl[14]));

while((e=(objcT80=seq,(*_imp(objcT80,selTransTbl[15]))(objcT80,selTransTbl[15]))))
{
id objcT81;

# 916 "set.m"
if(((objcT81=aBlock,(*_imp(objcT81,selTransTbl[27]))(objcT81,selTransTbl[27],e))))
{
id objcT82;
seq=(objcT82=seq,(*_imp(objcT82,selTransTbl[6]))(objcT82,selTransTbl[6]));

return e;
}
}


seq=(objcT83=seq,(*_imp(objcT83,selTransTbl[6]))(objcT83,selTransTbl[6]));

return(id)0;
}

static id i_Set_detect_ifNone_(struct Set_PRIVATE *self,SEL _cmd,id aBlock,id noneBlock)
{
id objcT84,objcT85,objcT88,objcT89;

# 933 "set.m"
id e,seq;

seq=(objcT84=(id)self,(*_imp(objcT84,selTransTbl[14]))(objcT84,selTransTbl[14]));

while((e=(objcT85=seq,(*_imp(objcT85,selTransTbl[15]))(objcT85,selTransTbl[15]))))
{
id objcT86;

# 939 "set.m"
if(((objcT86=aBlock,(*_imp(objcT86,selTransTbl[27]))(objcT86,selTransTbl[27],e))))
{
id objcT87;
seq=(objcT87=seq,(*_imp(objcT87,selTransTbl[6]))(objcT87,selTransTbl[6]));

return e;
}
}


seq=(objcT88=seq,(*_imp(objcT88,selTransTbl[6]))(objcT88,selTransTbl[6]));

return(objcT89=noneBlock,(*_imp(objcT89,selTransTbl[19]))(objcT89,selTransTbl[19]));
}

static id i_Set_select_(struct Set_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT90,objcT91,objcT92,objcT95;

# 956 "set.m"
id e,seq;
id newObject=(objcT90=self->isa,(*_imp(objcT90,selTransTbl[1]))(objcT90,selTransTbl[1]));

seq=(objcT91=(id)self,(*_imp(objcT91,selTransTbl[14]))(objcT91,selTransTbl[14]));

while((e=(objcT92=seq,(*_imp(objcT92,selTransTbl[15]))(objcT92,selTransTbl[15]))))
{
id objcT93;

# 963 "set.m"
if(((objcT93=testBlock,(*_imp(objcT93,selTransTbl[27]))(objcT93,selTransTbl[27],e))))
{
id objcT94;

# 965 "set.m"
(objcT94=newObject,(*_imp(objcT94,selTransTbl[3]))(objcT94,selTransTbl[3],e));
}
}


seq=(objcT95=seq,(*_imp(objcT95,selTransTbl[6]))(objcT95,selTransTbl[6]));

return newObject;
}

static id i_Set_reject_(struct Set_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT96,objcT97,objcT98,objcT101;

# 977 "set.m"
id e,seq;
id newObject=(objcT96=self->isa,(*_imp(objcT96,selTransTbl[1]))(objcT96,selTransTbl[1]));

seq=(objcT97=(id)self,(*_imp(objcT97,selTransTbl[14]))(objcT97,selTransTbl[14]));

while((e=(objcT98=seq,(*_imp(objcT98,selTransTbl[15]))(objcT98,selTransTbl[15]))))
{
id objcT99;

# 984 "set.m"
if( !((objcT99=testBlock,(*_imp(objcT99,selTransTbl[27]))(objcT99,selTransTbl[27],e))))
{
id objcT100;

# 986 "set.m"
(objcT100=newObject,(*_imp(objcT100,selTransTbl[3]))(objcT100,selTransTbl[3],e));
}
}


seq=(objcT101=seq,(*_imp(objcT101,selTransTbl[6]))(objcT101,selTransTbl[6]));

return newObject;
}

static id i_Set_collect_(struct Set_PRIVATE *self,SEL _cmd,id transformBlock)
{
id objcT102,objcT103,objcT104,objcT107;

# 998 "set.m"
id e,seq;
id newObject=(objcT102=self->isa,(*_imp(objcT102,selTransTbl[1]))(objcT102,selTransTbl[1]));

seq=(objcT103=(id)self,(*_imp(objcT103,selTransTbl[14]))(objcT103,selTransTbl[14]));

while((e=(objcT104=seq,(*_imp(objcT104,selTransTbl[15]))(objcT104,selTransTbl[15]))))
{
id objcT105;

# 1005 "set.m"
id anImage=(objcT105=transformBlock,(*_imp(objcT105,selTransTbl[27]))(objcT105,selTransTbl[27],e));
if(anImage)
{
id objcT106;

# 1008 "set.m"
(objcT106=newObject,(*_imp(objcT106,selTransTbl[3]))(objcT106,selTransTbl[3],anImage));
}
}


seq=(objcT107=seq,(*_imp(objcT107,selTransTbl[6]))(objcT107,selTransTbl[6]));

return newObject;
}

static unsigned i_Set_count_(struct Set_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT108,objcT109,objcT111;

# 1020 "set.m"
id e,seq;
unsigned c=0;

seq=(objcT108=(id)self,(*_imp(objcT108,selTransTbl[14]))(objcT108,selTransTbl[14]));
while((e=(objcT109=seq,(*_imp(objcT109,selTransTbl[15]))(objcT109,selTransTbl[15]))))
{
id objcT110;

# 1026 "set.m"
if((objcT110=aBlock,(*_imp(objcT110,selTransTbl[27]))(objcT110,selTransTbl[27],e)))
{
c++;
}
}

seq=(objcT111=seq,(*_imp(objcT111,selTransTbl[6]))(objcT111,selTransTbl[6]));


return c;
}

# 1046 "set.m"
static id i_Set_elementsPerform_(struct Set_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT112,objcT113,objcT115;

# 1048 "set.m"
id e,seq;

seq=(objcT112=(id)self,(*_imp(objcT112,selTransTbl[14]))(objcT112,selTransTbl[14]));
while((e=(objcT113=seq,(*_imp(objcT113,selTransTbl[15]))(objcT113,selTransTbl[15]))))
{
id objcT114;

# 1053 "set.m"
(objcT114=e,(*(id(*)(id,SEL,SEL))_imp(objcT114,selTransTbl[28]))(objcT114,selTransTbl[28],aSelector));
}

seq=(objcT115=seq,(*_imp(objcT115,selTransTbl[6]))(objcT115,selTransTbl[6]));


return(id)self;
}

static id i_Set_elementsPerform_with_(struct Set_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject)
{
id objcT116,objcT117,objcT119;

# 1064 "set.m"
id e,seq;

seq=(objcT116=(id)self,(*_imp(objcT116,selTransTbl[14]))(objcT116,selTransTbl[14]));
while((e=(objcT117=seq,(*_imp(objcT117,selTransTbl[15]))(objcT117,selTransTbl[15]))))
{
id objcT118;

# 1069 "set.m"
(objcT118=e,(*(id(*)(id,SEL,SEL,id))_imp(objcT118,selTransTbl[29]))(objcT118,selTransTbl[29],aSelector,anObject));
}

seq=(objcT119=seq,(*_imp(objcT119,selTransTbl[6]))(objcT119,selTransTbl[6]));


return(id)self;
}

static id i_Set_elementsPerform_with_with_(struct Set_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject)
{
id objcT120,objcT121,objcT123;

# 1080 "set.m"
id e,seq;

seq=(objcT120=(id)self,(*_imp(objcT120,selTransTbl[14]))(objcT120,selTransTbl[14]));
while((e=(objcT121=seq,(*_imp(objcT121,selTransTbl[15]))(objcT121,selTransTbl[15]))))
{
id objcT122;

# 1085 "set.m"
(objcT122=e,(*(id(*)(id,SEL,SEL,id,id))_imp(objcT122,selTransTbl[30]))(objcT122,selTransTbl[30],aSelector,anObject,otherObject));
}

seq=(objcT123=seq,(*_imp(objcT123,selTransTbl[6]))(objcT123,selTransTbl[6]));


return(id)self;
}

static id i_Set_elementsPerform_with_with_with_(struct Set_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject,id thirdObj)
{
id objcT124,objcT125,objcT127;

# 1096 "set.m"
id e,seq;

seq=(objcT124=(id)self,(*_imp(objcT124,selTransTbl[14]))(objcT124,selTransTbl[14]));
while((e=(objcT125=seq,(*_imp(objcT125,selTransTbl[15]))(objcT125,selTransTbl[15]))))
{
id objcT126;

# 1101 "set.m"
(objcT126=e,(*(id(*)(id,SEL,SEL,id,id,id))_imp(objcT126,selTransTbl[31]))(objcT126,selTransTbl[31],aSelector,anObject,otherObject,thirdObj));
}

seq=(objcT127=seq,(*_imp(objcT127,selTransTbl[6]))(objcT127,selTransTbl[6]));


return(id)self;
}

# 1116 "set.m"
static id i_Set_do_(struct Set_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT128,objcT129,objcT131;

# 1118 "set.m"
id e,seq;

seq=(objcT128=(id)self,(*_imp(objcT128,selTransTbl[14]))(objcT128,selTransTbl[14]));

while((e=(objcT129=seq,(*_imp(objcT129,selTransTbl[15]))(objcT129,selTransTbl[15]))))
{
id objcT130;

# 1124 "set.m"
(objcT130=aBlock,(*_imp(objcT130,selTransTbl[27]))(objcT130,selTransTbl[27],e));
}


seq=(objcT131=seq,(*_imp(objcT131,selTransTbl[6]))(objcT131,selTransTbl[6]));

return(id)self;
}
static id i_Set_do_until_(struct Set_PRIVATE *self,SEL _cmd,id aBlock,BOOL*flag)
{
id objcT132,objcT133,objcT135;

# 1134 "set.m"
id e,seq;

seq=(objcT132=(id)self,(*_imp(objcT132,selTransTbl[14]))(objcT132,selTransTbl[14]));

while((e=(objcT133=seq,(*_imp(objcT133,selTransTbl[15]))(objcT133,selTransTbl[15]))))
{
id objcT134;

# 1140 "set.m"
(objcT134=aBlock,(*_imp(objcT134,selTransTbl[27]))(objcT134,selTransTbl[27],e));
if( *flag)
break;
}


seq=(objcT135=seq,(*_imp(objcT135,selTransTbl[6]))(objcT135,selTransTbl[6]));

return(id)self;
}

# 1158 "set.m"
static id i_Set_find_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
{
return(anObject)? *find(( &self->value),anObject):(id)0;
}

static BOOL i_Set_contains_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT136;

# 1165 "set.m"
return(BOOL)((objcT136=(id)self,(*_imp(objcT136,selTransTbl[26]))(objcT136,selTransTbl[26],anObject))?(BOOL)1:(BOOL)0);
}

static BOOL i_Set_includes_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT137;

# 1170 "set.m"
return(objcT137=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT137,selTransTbl[16]))(objcT137,selTransTbl[16],anObject));
}

static unsigned i_Set_occurrencesOf_(struct Set_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT138;

# 1175 "set.m"
return(unsigned)((objcT138=(id)self,(*_imp(objcT138,selTransTbl[26]))(objcT138,selTransTbl[26],anObject))?1:0);
}

# 1184 "set.m"
static id i_Set_printOn_(struct Set_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT139,objcT140,objcT141;

# 1186 "set.m"
id s=(objcT139=(id)self,(*_imp(objcT139,selTransTbl[14]))(objcT139,selTransTbl[14]));
(objcT140=s,(*(id(*)(id,SEL,IOD))_imp(objcT140,selTransTbl[32]))(objcT140,selTransTbl[32],aFile));

(objcT141=s,(*_imp(objcT141,selTransTbl[6]))(objcT141,selTransTbl[6]));

return(id)self;
}

# 1201 "set.m"
static void
ptrfileout(id aFiler,id*a,int n)
{
while(n--)
{
id obj= *a++;
if(obj)
{
id objcT142;

# 1209 "set.m"
(objcT142=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT142,selTransTbl[33]))(objcT142,selTransTbl[33], &obj,'@'));
}
}
}

static void
ptrfilein(id aFiler,id*a,int n)
{
# 1223 "set.m"
while(n--)
{
id objcT143;

# 1225 "set.m"
(objcT143=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT143,selTransTbl[34]))(objcT143,selTransTbl[34],a++,'@'));
}
}

static void
fileout(id aFiler,objset_t self)
{
id objcT144;

# 1232 "set.m"
int n=self->count;
(objcT144=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT144,selTransTbl[33]))(objcT144,selTransTbl[33], &n,'i'));
ptrfileout(aFiler,self->ptr,self->capacity);
}

static void
filein(id aFiler,objset_t self)
{
id objcT145;

# 1240 "set.m"
int n;
(objcT145=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT145,selTransTbl[34]))(objcT145,selTransTbl[34], &n,'i'));
init(self,n,n);
ptrfilein(aFiler,self->ptr,n);
}

static id i_Set_fileOutOn_(struct Set_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT146;

# 1248 "set.m"
(objcT146=_Set.clsSuper,(*_impSuper(objcT146,selTransTbl[35]))((id)self,selTransTbl[35],aFiler));
fileout(aFiler, &self->value);
return(id)self;
}

static id i_Set_fileInFrom_(struct Set_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT147;

# 1255 "set.m"
(objcT147=_Set.clsSuper,(*_impSuper(objcT147,selTransTbl[36]))((id)self,selTransTbl[36],aFiler));
filein(aFiler, &self->value);
return(id)self;
}

static id i_Set_awakeFrom_(struct Set_PRIVATE *self,SEL _cmd,id aFiler)
{

expand( &self->value);
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Cltn;
extern struct _SHARED _Cltn;
extern struct _SHARED __Cltn;
static struct _SLT _Set_clsDispatchTbl[] ={
{"new",(id (*)())c_Set_new},
{"new:",(id (*)())c_Set_new_},
{"with:",(id (*)())c_Set_with_},
{"with:with:",(id (*)())c_Set_with_with_},
{"add:",(id (*)())c_Set_add_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Set_nstDispatchTbl[] ={
{"copy",(id (*)())i_Set_copy},
{"deepCopy",(id (*)())i_Set_deepCopy},
{"emptyYourself",(id (*)())i_Set_emptyYourself},
{"addYourself",(id (*)())i_Set_addYourself},
{"freeContents",(id (*)())i_Set_freeContents},
{"freeAll",(id (*)())i_Set_freeAll},
{"free",(id (*)())i_Set_free},
{"release",(id (*)())i_Set_release},
{"objsetvalue",(id (*)())i_Set_objsetvalue},
{"size",(id (*)())i_Set_size},
{"isEmpty",(id (*)())i_Set_isEmpty},
{"eachElement",(id (*)())i_Set_eachElement},
{"hash",(id (*)())i_Set_hash},
{"isEqual:",(id (*)())i_Set_isEqual_},
{"add:",(id (*)())i_Set_add_},
{"addNTest:",(id (*)())i_Set_addNTest_},
{"filter:",(id (*)())i_Set_filter_},
{"add:ifDuplicate:",(id (*)())i_Set_add_ifDuplicate_},
{"replace:",(id (*)())i_Set_replace_},
{"remove:",(id (*)())i_Set_remove_},
{"remove:ifAbsent:",(id (*)())i_Set_remove_ifAbsent_},
{"includesAllOf:",(id (*)())i_Set_includesAllOf_},
{"includesAnyOf:",(id (*)())i_Set_includesAnyOf_},
{"addAll:",(id (*)())i_Set_addAll_},
{"addContentsOf:",(id (*)())i_Set_addContentsOf_},
{"addContentsTo:",(id (*)())i_Set_addContentsTo_},
{"removeAll:",(id (*)())i_Set_removeAll_},
{"removeContentsFrom:",(id (*)())i_Set_removeContentsFrom_},
{"removeContentsOf:",(id (*)())i_Set_removeContentsOf_},
{"intersection:",(id (*)())i_Set_intersection_},
{"union:",(id (*)())i_Set_union_},
{"difference:",(id (*)())i_Set_difference_},
{"asSet",(id (*)())i_Set_asSet},
{"asOrdCltn",(id (*)())i_Set_asOrdCltn},
{"detect:",(id (*)())i_Set_detect_},
{"detect:ifNone:",(id (*)())i_Set_detect_ifNone_},
{"select:",(id (*)())i_Set_select_},
{"reject:",(id (*)())i_Set_reject_},
{"collect:",(id (*)())i_Set_collect_},
{"count:",(id (*)())i_Set_count_},
{"elementsPerform:",(id (*)())i_Set_elementsPerform_},
{"elementsPerform:with:",(id (*)())i_Set_elementsPerform_with_},
{"elementsPerform:with:with:",(id (*)())i_Set_elementsPerform_with_with_},
{"elementsPerform:with:with:with:",(id (*)())i_Set_elementsPerform_with_with_with_},
{"do:",(id (*)())i_Set_do_},
{"do:until:",(id (*)())i_Set_do_until_},
{"find:",(id (*)())i_Set_find_},
{"contains:",(id (*)())i_Set_contains_},
{"includes:",(id (*)())i_Set_includes_},
{"occurrencesOf:",(id (*)())i_Set_occurrencesOf_},
{"printOn:",(id (*)())i_Set_printOn_},
{"fileOutOn:",(id (*)())i_Set_fileOutOn_},
{"fileInFrom:",(id (*)())i_Set_fileInFrom_},
{"awakeFrom:",(id (*)())i_Set_awakeFrom_},
{(char*)0,(id (*)())0}
};
id Set = (id)&_Set;
id  *OBJCCLASS_Set(void) { return &Set; }
struct _SHARED  _Set = {
  (id)&__Set,
  (id)&_Cltn,
  "Set",
  0,
  sizeof(struct Set_PRIVATE),
  54,
  _Set_nstDispatchTbl,
  41,
  &set_modDesc,
  0,
  (id)0,
  &Set,
};
id  OBJCCFUNC_Set(void) { return (id)&_Set; }
id  OBJCCSUPER_Set(void) { return _Set.clsSuper; }
struct _SHARED __Set = {
  (id)&__Object,
  (id)&__Cltn,
  "Set",
  0,
  sizeof(struct _SHARED),
  5,
  _Set_clsDispatchTbl,
  34,
  &set_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Set(void) { return (id)&__Set; }
id  OBJCMSUPER_Set(void) { return __Set.clsSuper; }
static char *_selTransTbl[] ={
"new:",
"new",
"objsetvalue",
"add:",
"copy",
"deepCopy",
"free",
"freeAll",
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
struct modDescriptor set_modDesc = {
  "set",
  "objc3.3.19",
  0L,
  0,
  0,
  &Set,
  37,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_set(void)
{
  selTransTbl = _selTransTbl;
  return &set_modDesc;
}
int _OBJCPOSTLINK_set = 1;


