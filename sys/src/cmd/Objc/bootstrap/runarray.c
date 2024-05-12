# 1 "runarray.m"
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
extern struct modDescriptor  *_OBJCBIND_runarray(void);
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
extern struct modDescriptor runarray_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//ctype.h"
#include <ctype.h>

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
# 28 "./intarray.h"
typedef struct intary
{
int capacity;
int*ptr;
}*
intary_t;
# 28 "./runarray.h"
struct RunArray_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 30 "./runarray.h"
id runs;
id values;
unsigned size;
int laststart;
int lastend;
int lastsegment;};

# 28 "./runarray.h"
extern id  RunArray;

# 28 "./runarray.h"
extern struct _SHARED _RunArray;
extern struct _SHARED __RunArray;


# 36 "runarray.m"
static id i_RunArray_reset(struct RunArray_PRIVATE *self,SEL _cmd)
{self->
laststart= -1;
return(id)self;
}

static id i_RunArray_check(struct RunArray_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 44 "runarray.m"
int i,n;
id attrs;
unsigned s;
unsigned totalsize=0;

(void)0;

for(i=0,n=(objcT0=self->values,(*(unsigned(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));i<n;i++)
{
id objcT1,objcT2;

# 53 "runarray.m"
attrs=(objcT1=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],i));
(void)0;
s=(objcT2=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],i));
(void)0;
totalsize+=s;
}

(void)0;
return(id)self;
}

# 35 "./intarray.h"
extern id  IntArray;

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 64 "runarray.m"
static id c_RunArray_new(struct RunArray_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4,objcT5,objcT6;

# 66 "runarray.m"
return(objcT3=(objcT4=__RunArray.clsSuper,(*_impSuper(objcT4,selTransTbl[3]))((id)self,selTransTbl[3])),(*_imp(objcT3,selTransTbl[4]))(objcT3,selTransTbl[4],(objcT5=IntArray,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3])),(objcT6=OrdCltn,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]))));
}

static id i_RunArray_free(struct RunArray_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8,objcT9,objcT10,objcT11;

# 71 "runarray.m"
(objcT7=self->values,(*(id(*)(id,SEL,SEL))_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],selTransTbl[6]));
(objcT8=(objcT9=self->values,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6])),(*_imp(objcT8,selTransTbl[7]))(objcT8,selTransTbl[7]));
(objcT10=self->runs,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
return(objcT11=_RunArray.clsSuper,(*_impSuper(objcT11,selTransTbl[7]))((id)self,selTransTbl[7]));
}


static id i_RunArray_values(struct RunArray_PRIVATE *self,SEL _cmd)
{
return self->values;
}

static id i_RunArray_runs(struct RunArray_PRIVATE *self,SEL _cmd)
{
return self->runs;
}

static id i_RunArray_runs_values_(struct RunArray_PRIVATE *self,SEL _cmd,id r,id v)
{
id objcT12;
self->
# 90 "runarray.m"
runs=r;self->
values=v;
(objcT12=(id)self,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8]));
return(id)self;
}

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 28 "./notfound.h"
extern id  NotFound;

# 96 "runarray.m"
static id i_RunArray_at_(struct RunArray_PRIVATE *self,SEL _cmd,unsigned i)
{
id objcT17,objcT20;

# 98 "runarray.m"
int j,n;
unsigned p;

if(i>=self->size)
{
id objcT13;

# 103 "runarray.m"
(objcT13=OutOfBounds,(*_imp(objcT13,selTransTbl[9]))(objcT13,selTransTbl[9]));
return(id)0;
}
# 109 "runarray.m"
if(self->laststart!= -1)
{
id objcT14;

# 111 "runarray.m"
if(self->laststart<=i&&i<self->lastend)
return(objcT14=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT14,selTransTbl[1]))(objcT14,selTransTbl[1],self->lastsegment));
if(i==self->lastend)
{
id objcT15,objcT16;
self->
# 115 "runarray.m"
lastsegment++;self->
laststart=self->lastend;self->
lastend=self->laststart+(objcT15=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT15,selTransTbl[2]))(objcT15,selTransTbl[2],self->lastsegment));
return(objcT16=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT16,selTransTbl[1]))(objcT16,selTransTbl[1],self->lastsegment));
}
}
# 124 "runarray.m"
for(j=0,p=0,n=(objcT17=self->values,(*(unsigned(*)(id,SEL))_imp(objcT17,selTransTbl[0]))(objcT17,selTransTbl[0]));j<n;j++)
{
id objcT18;

# 126 "runarray.m"
unsigned q=p+(objcT18=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT18,selTransTbl[2]))(objcT18,selTransTbl[2],j));
if(p<=i&&i<q)
{
id objcT19;
self->
# 129 "runarray.m"
laststart=p;self->
lastend=q;self->
lastsegment=j;
return(objcT19=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT19,selTransTbl[1]))(objcT19,selTransTbl[1],j));
}
p=q;
}

(objcT20=NotFound,(*_imp(objcT20,selTransTbl[9]))(objcT20,selTransTbl[9]));
return(id)0;
}

static unsigned i_RunArray_runLengthAt_(struct RunArray_PRIVATE *self,SEL _cmd,unsigned i)
{
id objcT23,objcT25;

# 143 "runarray.m"
int j,n;
unsigned p;

if(i>=self->size)
{
id objcT21;

# 148 "runarray.m"
(objcT21=OutOfBounds,(*_imp(objcT21,selTransTbl[9]))(objcT21,selTransTbl[9]));
return 0;
}
# 154 "runarray.m"
if(self->laststart!= -1)
{
if(self->laststart<=i&&i<self->lastend)
return self->lastend-i;
if(i==self->lastend)
{
id objcT22;
self->
# 160 "runarray.m"
lastsegment++;self->
laststart=self->lastend;self->
lastend=self->laststart+(objcT22=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT22,selTransTbl[2]))(objcT22,selTransTbl[2],self->lastsegment));
return self->lastend-i;
}
}
# 169 "runarray.m"
for(j=0,p=0,n=(objcT23=self->values,(*(unsigned(*)(id,SEL))_imp(objcT23,selTransTbl[0]))(objcT23,selTransTbl[0]));j<n;j++)
{
id objcT24;

# 171 "runarray.m"
unsigned q=p+(objcT24=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT24,selTransTbl[2]))(objcT24,selTransTbl[2],j));
if(p<=i&&i<q)
{self->
laststart=p;self->
lastend=q;self->
lastsegment=j;
return self->lastend-i;
}
p=q;
}

(objcT25=NotFound,(*_imp(objcT25,selTransTbl[9]))(objcT25,selTransTbl[9]));
return 0;
}


static unsigned i_RunArray_size(struct RunArray_PRIVATE *self,SEL _cmd)
{
return self->size;
}

static id i_RunArray_calcsize(struct RunArray_PRIVATE *self,SEL _cmd)
{
id objcT26;

# 194 "runarray.m"
int i,n;
int totalsize=0;

(void)0;

for(i=0,n=(objcT26=self->values,(*(unsigned(*)(id,SEL))_imp(objcT26,selTransTbl[0]))(objcT26,selTransTbl[0]));i<n;i++)
{
id objcT27;

# 201 "runarray.m"
int s=(objcT27=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT27,selTransTbl[2]))(objcT27,selTransTbl[2],i));

totalsize+=s;
}self->

size=totalsize;
return(id)self;
}

static id i_RunArray_setsize_(struct RunArray_PRIVATE *self,SEL _cmd,unsigned newsize)
{
if(self->size==newsize)
return(id)self;

if(self->size<newsize)
{
id objcT28,objcT29,objcT30,objcT31,objcT32;
id objcT33;

# 217 "runarray.m"
int n=(objcT28=self->values,(*(unsigned(*)(id,SEL))_imp(objcT28,selTransTbl[0]))(objcT28,selTransTbl[0]));
int m=(objcT29=self->runs,(*(unsigned(*)(id,SEL))_imp(objcT29,selTransTbl[10]))(objcT29,selTransTbl[10]));
if(m<(n+1))
(objcT30=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT30,selTransTbl[11]))(objcT30,selTransTbl[11],(2*m+1)));
(objcT31=self->values,(*_imp(objcT31,selTransTbl[12]))(objcT31,selTransTbl[12],(objcT32=OrdCltn,(*_imp(objcT32,selTransTbl[3]))(objcT32,selTransTbl[3]))));
(objcT33=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT33,selTransTbl[13]))(objcT33,selTransTbl[13],n,(newsize-self->size)));self->
size=newsize;
}
else
{
id objcT34;

# 227 "runarray.m"
(objcT34=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT34,selTransTbl[14]))(objcT34,selTransTbl[14],_cmd));
}

(void)0;
return(id)self;
}

static id i_RunArray_addAttribute_to_(struct RunArray_PRIVATE *self,SEL _cmd,id attrib,id v)
{
id objcT35,objcT36,objcT41;

# 236 "runarray.m"
int n=(objcT35=v,(*(unsigned(*)(id,SEL))_imp(objcT35,selTransTbl[0]))(objcT35,selTransTbl[0]));

(objcT36=attrib,(*_imp(objcT36,selTransTbl[8]))(objcT36,selTransTbl[8]));
while(n--)
{
id objcT37,objcT38;

# 241 "runarray.m"
if((objcT37=attrib,(*(BOOL(*)(id,SEL,id))_imp(objcT37,selTransTbl[15]))(objcT37,selTransTbl[15],(objcT38=v,(*(id(*)(id,SEL,unsigned))_imp(objcT38,selTransTbl[1]))(objcT38,selTransTbl[1],n)))))
{
id objcT39,objcT40;

# 243 "runarray.m"
id atb=(objcT39=v,(*(id(*)(id,SEL,unsigned))_imp(objcT39,selTransTbl[16]))(objcT39,selTransTbl[16],n));

(objcT40=atb,(*_imp(objcT40,selTransTbl[7]))(objcT40,selTransTbl[7]));

}
}
if((objcT41=attrib,(*(BOOL(*)(id,SEL))_imp(objcT41,selTransTbl[17]))(objcT41,selTransTbl[17])))
{
id objcT42;

# 251 "runarray.m"
(objcT42=v,(*_imp(objcT42,selTransTbl[12]))(objcT42,selTransTbl[12],attrib));

}
else
{
id objcT43;

# 256 "runarray.m"
(objcT43=attrib,(*_imp(objcT43,selTransTbl[7]))(objcT43,selTransTbl[7]));

}
return(id)self;
}

static id i_RunArray_breakat_(struct RunArray_PRIVATE *self,SEL _cmd,int i)
{
id objcT44,objcT55;

# 264 "runarray.m"
int j,k,p,n;

for(j=0,p=0,n=(objcT44=self->values,(*(unsigned(*)(id,SEL))_imp(objcT44,selTransTbl[0]))(objcT44,selTransTbl[0]));j<n;j++)
{
id objcT45;

# 268 "runarray.m"
unsigned q=p+(objcT45=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT45,selTransTbl[2]))(objcT45,selTransTbl[2],j));

if(p==i||q==i)
return(id)self;
if(p<i&&q>i)
{
id objcT46,objcT47,objcT48,objcT49,objcT50;
id objcT51,objcT52,objcT53,objcT54;

# 274 "runarray.m"
int m=(objcT46=self->runs,(*(unsigned(*)(id,SEL))_imp(objcT46,selTransTbl[10]))(objcT46,selTransTbl[10]));
id v=(objcT47=(objcT48=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT48,selTransTbl[1]))(objcT48,selTransTbl[1],j)),(*_imp(objcT47,selTransTbl[18]))(objcT47,selTransTbl[18]));

if(m<(n+1))
(objcT49=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT49,selTransTbl[11]))(objcT49,selTransTbl[11],(2*m+1)));
(objcT50=self->values,(*(id(*)(id,SEL,unsigned,id))_imp(objcT50,selTransTbl[19]))(objcT50,selTransTbl[19],j,v));
k=n;
while( --k>=j)
(objcT51=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT51,selTransTbl[13]))(objcT51,selTransTbl[13],k+1,(objcT52=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT52,selTransTbl[2]))(objcT52,selTransTbl[2],k))));
(objcT53=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT53,selTransTbl[13]))(objcT53,selTransTbl[13],j,i-p));
(objcT54=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT54,selTransTbl[13]))(objcT54,selTransTbl[13],j+1,q-i));
return(id)self;
}
p=q;
}
return(objcT55=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT55,selTransTbl[20]))(objcT55,selTransTbl[20],"Error in run computation"));
}

static id i_RunArray_addAttribute_from_size_(struct RunArray_PRIVATE *self,SEL _cmd,id attrib,unsigned p,unsigned s)
{
id objcT61,objcT62,objcT69,objcT70,objcT75;

# 294 "runarray.m"
int i;

if(s==0)
return(id)self;
# 301 "runarray.m"
if(p>=self->size)
{
id objcT56,objcT57,objcT58,objcT59,objcT60;

# 303 "runarray.m"
if(p>self->size)
(objcT56=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT56,selTransTbl[21]))(objcT56,selTransTbl[21],p));
(objcT57=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT57,selTransTbl[21]))(objcT57,selTransTbl[21],p+s));
i=(objcT58=self->values,(*(unsigned(*)(id,SEL))_imp(objcT58,selTransTbl[0]))(objcT58,selTransTbl[0]));
(void)0;
return(objcT59=(id)self,(*_imp(objcT59,selTransTbl[22]))(objcT59,selTransTbl[22],attrib,(objcT60=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT60,selTransTbl[1]))(objcT60,selTransTbl[1],i-1))));
}
# 313 "runarray.m"
i=(objcT61=self->values,(*(unsigned(*)(id,SEL))_imp(objcT61,selTransTbl[0]))(objcT61,selTransTbl[0]));
if((i!=0)&&(p+s==self->size)&&(s==(objcT62=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT62,selTransTbl[2]))(objcT62,selTransTbl[2],i-1))))
{
id objcT63,objcT64;

# 316 "runarray.m"
return(objcT63=(id)self,(*_imp(objcT63,selTransTbl[22]))(objcT63,selTransTbl[22],attrib,(objcT64=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT64,selTransTbl[1]))(objcT64,selTransTbl[1],i-1))));
}
# 322 "runarray.m"
if(p+s>self->size)
{
id objcT65,objcT66;

# 324 "runarray.m"
(objcT65=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT65,selTransTbl[21]))(objcT65,selTransTbl[21],p+s));
(objcT66=(id)self,(*(id(*)(id,SEL,int))_imp(objcT66,selTransTbl[23]))(objcT66,selTransTbl[23],p));
}
else
{
id objcT67,objcT68;

# 329 "runarray.m"
(objcT67=(id)self,(*(id(*)(id,SEL,int))_imp(objcT67,selTransTbl[23]))(objcT67,selTransTbl[23],p));
(objcT68=(id)self,(*(id(*)(id,SEL,int))_imp(objcT68,selTransTbl[23]))(objcT68,selTransTbl[23],p+s));
}

(objcT69=(id)self,(*_imp(objcT69,selTransTbl[8]))(objcT69,selTransTbl[8]));

for(i=0;i<self->size;i+=(objcT70=(id)self,(*(unsigned(*)(id,SEL,unsigned))_imp(objcT70,selTransTbl[24]))(objcT70,selTransTbl[24],i)))
{
id objcT71,objcT72,objcT73,objcT74;

# 337 "runarray.m"
if(i==p+s)
break;
if(i>p+s)
(objcT71=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT71,selTransTbl[20]))(objcT71,selTransTbl[20],"Error in run computation."));
if(i>=p)
(objcT72=(id)self,(*_imp(objcT72,selTransTbl[22]))(objcT72,selTransTbl[22],(objcT73=attrib,(*_imp(objcT73,selTransTbl[25]))(objcT73,selTransTbl[25])),(objcT74=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT74,selTransTbl[1]))(objcT74,selTransTbl[1],i))));
}


(objcT75=attrib,(*_imp(objcT75,selTransTbl[7]))(objcT75,selTransTbl[7]));

return(id)self;
}

static id i_RunArray_calcinsertsegment_(struct RunArray_PRIVATE *self,SEL _cmd,int i)
{
id objcT77,objcT79;

# 353 "runarray.m"
int j,n;
unsigned p;

if(i>=self->size)
{
id objcT76;

# 358 "runarray.m"
(objcT76=OutOfBounds,(*_imp(objcT76,selTransTbl[9]))(objcT76,selTransTbl[9]));
return(id)0;
}
# 364 "runarray.m"
if(self->laststart!= -1)
{

if(self->laststart<i&&i<=self->lastend)
return(id)self;
}
# 373 "runarray.m"
for(j=0,p=0,n=(objcT77=self->values,(*(unsigned(*)(id,SEL))_imp(objcT77,selTransTbl[0]))(objcT77,selTransTbl[0]));j<n;j++)
{
id objcT78;

# 375 "runarray.m"
unsigned q=p+(objcT78=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT78,selTransTbl[2]))(objcT78,selTransTbl[2],j));

if(p<=i&&i<=q)
{self->
laststart=p;self->
lastend=q;self->
lastsegment=j;
return(id)self;
}
p=q;
}

(objcT79=NotFound,(*_imp(objcT79,selTransTbl[9]))(objcT79,selTransTbl[9]));
return(id)0;
}

static id i_RunArray_at_insert_count_(struct RunArray_PRIVATE *self,SEL _cmd,unsigned anOffset,char*aString,int n)
{
id objcT87;

# 393 "runarray.m"
if(anOffset==self->size)
{
id objcT80;

# 395 "runarray.m"
int s=(objcT80=self->runs,(*(unsigned(*)(id,SEL))_imp(objcT80,selTransTbl[0]))(objcT80,selTransTbl[0]));
if(s)
{
id objcT81,objcT82;

# 398 "runarray.m"
(objcT81=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT81,selTransTbl[13]))(objcT81,selTransTbl[13],s-1,(objcT82=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT82,selTransTbl[2]))(objcT82,selTransTbl[2],s-1))+n));self->
size+=n;
}
else
{
id objcT83;

# 403 "runarray.m"
(objcT83=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT83,selTransTbl[21]))(objcT83,selTransTbl[21],self->size+n));
}
}
else
{
id objcT84,objcT85,objcT86;

# 408 "runarray.m"
(objcT84=(id)self,(*(id(*)(id,SEL,int))_imp(objcT84,selTransTbl[26]))(objcT84,selTransTbl[26],anOffset));
(objcT85=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT85,selTransTbl[13]))(objcT85,selTransTbl[13],self->lastsegment,(objcT86=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT86,selTransTbl[2]))(objcT86,selTransTbl[2],self->lastsegment))+n));self->
size+=n;
}
(objcT87=(id)self,(*_imp(objcT87,selTransTbl[8]))(objcT87,selTransTbl[8]));
(void)0;
return(id)self;
}

static id i_RunArray_deleteFrom_to_(struct RunArray_PRIVATE *self,SEL _cmd,unsigned p,unsigned q)
{
id objcT89,objcT90,objcT91,objcT111;

# 419 "runarray.m"
int i,is,j,je,n;

if(p>q)
{
id objcT88;

# 423 "runarray.m"
(objcT88=OutOfBounds,(*_imp(objcT88,selTransTbl[9]))(objcT88,selTransTbl[9]));
return(id)0;
}

(void)0;

n=q-p+1;
(objcT89=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT89,selTransTbl[1]))(objcT89,selTransTbl[1],p));
i=self->lastsegment;
is=self->laststart;
(objcT90=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT90,selTransTbl[1]))(objcT90,selTransTbl[1],q));
j=self->lastsegment;
je=self->lastend;
(objcT91=(id)self,(*_imp(objcT91,selTransTbl[8]))(objcT91,selTransTbl[8]));

if(i==j)
{
id objcT92,objcT93;

# 440 "runarray.m"
int m=(objcT92=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT92,selTransTbl[2]))(objcT92,selTransTbl[2],i));

(void)0;
(objcT93=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT93,selTransTbl[13]))(objcT93,selTransTbl[13],i,m-n));
if(m==n)
{
id objcT94,objcT95,objcT96;

# 446 "runarray.m"
id atb=(objcT94=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT94,selTransTbl[16]))(objcT94,selTransTbl[16],i));

(objcT95=(objcT96=atb,(*_imp(objcT96,selTransTbl[6]))(objcT96,selTransTbl[6])),(*_imp(objcT95,selTransTbl[7]))(objcT95,selTransTbl[7]));

}
}
else
{
id objcT97,objcT98,objcT99,objcT100,objcT101;

# 454 "runarray.m"
int m,k,r;

m=(objcT97=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT97,selTransTbl[2]))(objcT97,selTransTbl[2],i));
(void)0;
(objcT98=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT98,selTransTbl[13]))(objcT98,selTransTbl[13],i,p-is));
for(k=i+1;k<j;k++)
(objcT99=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT99,selTransTbl[13]))(objcT99,selTransTbl[13],k,0));
m=(objcT100=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT100,selTransTbl[2]))(objcT100,selTransTbl[2],j));
(void)0;
(objcT101=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT101,selTransTbl[13]))(objcT101,selTransTbl[13],j,je-q-1));

r=i;
if(is==p)
{
id objcT102,objcT103,objcT104;

# 468 "runarray.m"
id atb=(objcT102=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT102,selTransTbl[16]))(objcT102,selTransTbl[16],r));

(objcT103=(objcT104=atb,(*_imp(objcT104,selTransTbl[6]))(objcT104,selTransTbl[6])),(*_imp(objcT103,selTransTbl[7]))(objcT103,selTransTbl[7]));

}
else
{
r++;
}
for(k=i+1;k<j;k++)
{
id objcT105,objcT106,objcT107;

# 479 "runarray.m"
id atb=(objcT105=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT105,selTransTbl[16]))(objcT105,selTransTbl[16],r));

(objcT106=(objcT107=atb,(*_imp(objcT107,selTransTbl[6]))(objcT107,selTransTbl[6])),(*_imp(objcT106,selTransTbl[7]))(objcT106,selTransTbl[7]));

}
if(je==q+1)
{
id objcT108,objcT109,objcT110;

# 486 "runarray.m"
id atb=(objcT108=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT108,selTransTbl[16]))(objcT108,selTransTbl[16],r));

(objcT109=(objcT110=atb,(*_imp(objcT110,selTransTbl[6]))(objcT110,selTransTbl[6])),(*_imp(objcT109,selTransTbl[7]))(objcT109,selTransTbl[7]));

}
}self->

size-=n;
(objcT111=self->runs,(*_imp(objcT111,selTransTbl[27]))(objcT111,selTransTbl[27]));

(void)0;
return(id)self;
}

static id i_RunArray_concat_(struct RunArray_PRIVATE *self,SEL _cmd,id b)
{
id objcT112,objcT113,objcT114,objcT115,objcT116;
id objcT117,objcT118,objcT119,objcT120,objcT121;
id objcT122,objcT123,objcT124;

# 502 "runarray.m"
int i,m,n,k;
id v,r=(objcT112=b,(*_imp(objcT112,selTransTbl[28]))(objcT112,selTransTbl[28]));

k=(objcT113=self->values,(*(unsigned(*)(id,SEL))_imp(objcT113,selTransTbl[0]))(objcT113,selTransTbl[0]));
n=(objcT114=(objcT115=b,(*_imp(objcT115,selTransTbl[29]))(objcT115,selTransTbl[29])),(*(unsigned(*)(id,SEL))_imp(objcT114,selTransTbl[0]))(objcT114,selTransTbl[0]));
for(i=0;i<n;i++)
(objcT116=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT116,selTransTbl[13]))(objcT116,selTransTbl[13],k+i,(objcT117=r,(*(int(*)(id,SEL,unsigned))_imp(objcT117,selTransTbl[2]))(objcT117,selTransTbl[2],i))));

v=(objcT118=(objcT119=b,(*_imp(objcT119,selTransTbl[29]))(objcT119,selTransTbl[29])),(*_imp(objcT118,selTransTbl[18]))(objcT118,selTransTbl[18]));
(objcT120=self->values,(*_imp(objcT120,selTransTbl[30]))(objcT120,selTransTbl[30],v));

(objcT121=v,(*_imp(objcT121,selTransTbl[7]))(objcT121,selTransTbl[7]));

m=(objcT122=self->runs,(*(unsigned(*)(id,SEL))_imp(objcT122,selTransTbl[10]))(objcT122,selTransTbl[10]));
if(m<k+n)
(objcT123=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT123,selTransTbl[11]))(objcT123,selTransTbl[11],(k+n+4)));self->

size+=(objcT124=b,(*(unsigned(*)(id,SEL))_imp(objcT124,selTransTbl[0]))(objcT124,selTransTbl[0]));
(void)0;
return(id)self;
}

static id i_RunArray_coalesce(struct RunArray_PRIVATE *self,SEL _cmd)
{
id objcT125;

# 526 "runarray.m"
int n=(objcT125=self->values,(*(unsigned(*)(id,SEL))_imp(objcT125,selTransTbl[0]))(objcT125,selTransTbl[0]));

while(n--)
{
id objcT126,objcT127,objcT128;

# 530 "runarray.m"
id v,w;
if(n==0)
break;
v=(objcT126=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT126,selTransTbl[1]))(objcT126,selTransTbl[1],n));
w=(objcT127=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT127,selTransTbl[1]))(objcT127,selTransTbl[1],n-1));
if((objcT128=v,(*(BOOL(*)(id,SEL,id))_imp(objcT128,selTransTbl[31]))(objcT128,selTransTbl[31],w)))
{
id objcT129,objcT130,objcT131,objcT132,objcT133;
id objcT134,objcT135,objcT136;

# 537 "runarray.m"
id atb;
unsigned p=(objcT129=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT129,selTransTbl[2]))(objcT129,selTransTbl[2],n));
unsigned q=(objcT130=self->runs,(*(int(*)(id,SEL,unsigned))_imp(objcT130,selTransTbl[2]))(objcT130,selTransTbl[2],n-1));
(objcT131=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT131,selTransTbl[13]))(objcT131,selTransTbl[13],n-1,p+q));
(objcT132=self->runs,(*(int(*)(id,SEL,unsigned,int))_imp(objcT132,selTransTbl[13]))(objcT132,selTransTbl[13],n,0));
atb=(objcT133=self->values,(*(id(*)(id,SEL,unsigned))_imp(objcT133,selTransTbl[16]))(objcT133,selTransTbl[16],n));

(objcT134=(objcT135=atb,(*_imp(objcT135,selTransTbl[6]))(objcT135,selTransTbl[6])),(*_imp(objcT134,selTransTbl[7]))(objcT134,selTransTbl[7]));

(objcT136=self->runs,(*_imp(objcT136,selTransTbl[27]))(objcT136,selTransTbl[27]));
}
}

return(id)self;
}


static id i_RunArray_printOn_(struct RunArray_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT137,objcT138;

# 556 "runarray.m"
fprintf(aFile,"RunArray runs ");
(objcT137=self->runs,(*(id(*)(id,SEL,IOD))_imp(objcT137,selTransTbl[32]))(objcT137,selTransTbl[32],aFile));
(objcT138=self->values,(*(id(*)(id,SEL,IOD))_imp(objcT138,selTransTbl[32]))(objcT138,selTransTbl[32],aFile));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Cltn;
extern struct _SHARED _Cltn;
extern struct _SHARED __Cltn;
static struct _SLT _RunArray_clsDispatchTbl[] ={
{"new",(id (*)())c_RunArray_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _RunArray_nstDispatchTbl[] ={
{"reset",(id (*)())i_RunArray_reset},
{"check",(id (*)())i_RunArray_check},
{"free",(id (*)())i_RunArray_free},
{"values",(id (*)())i_RunArray_values},
{"runs",(id (*)())i_RunArray_runs},
{"runs:values:",(id (*)())i_RunArray_runs_values_},
{"at:",(id (*)())i_RunArray_at_},
{"runLengthAt:",(id (*)())i_RunArray_runLengthAt_},
{"size",(id (*)())i_RunArray_size},
{"calcsize",(id (*)())i_RunArray_calcsize},
{"setsize:",(id (*)())i_RunArray_setsize_},
{"addAttribute:to:",(id (*)())i_RunArray_addAttribute_to_},
{"breakat:",(id (*)())i_RunArray_breakat_},
{"addAttribute:from:size:",(id (*)())i_RunArray_addAttribute_from_size_},
{"calcinsertsegment:",(id (*)())i_RunArray_calcinsertsegment_},
{"at:insert:count:",(id (*)())i_RunArray_at_insert_count_},
{"deleteFrom:to:",(id (*)())i_RunArray_deleteFrom_to_},
{"concat:",(id (*)())i_RunArray_concat_},
{"coalesce",(id (*)())i_RunArray_coalesce},
{"printOn:",(id (*)())i_RunArray_printOn_},
{(char*)0,(id (*)())0}
};
id RunArray = (id)&_RunArray;
id  *OBJCCLASS_RunArray(void) { return &RunArray; }
struct _SHARED  _RunArray = {
  (id)&__RunArray,
  (id)&_Cltn,
  "RunArray",
  0,
  sizeof(struct RunArray_PRIVATE),
  20,
  _RunArray_nstDispatchTbl,
  41,
  &runarray_modDesc,
  0,
  (id)0,
  &RunArray,
};
id  OBJCCFUNC_RunArray(void) { return (id)&_RunArray; }
id  OBJCCSUPER_RunArray(void) { return _RunArray.clsSuper; }
struct _SHARED __RunArray = {
  (id)&__Object,
  (id)&__Cltn,
  "RunArray",
  0,
  sizeof(struct _SHARED),
  1,
  _RunArray_clsDispatchTbl,
  34,
  &runarray_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_RunArray(void) { return (id)&__RunArray; }
id  OBJCMSUPER_RunArray(void) { return __RunArray.clsSuper; }
static char *_selTransTbl[] ={
"size",
"at:",
"intAt:",
"new",
"runs:values:",
"elementsPerform:",
"freeContents",
"free",
"reset",
"signal",
"capacity",
"capacity:",
"add:",
"intAt:put:",
"notImplemented:",
"dominates:",
"removeAt:",
"set",
"deepCopy",
"at:insert:",
"error:",
"setsize:",
"addAttribute:to:",
"breakat:",
"runLengthAt:",
"copy",
"calcinsertsegment:",
"packContents",
"runs",
"values",
"addAll:",
"isEqual:",
"printOn:",
0
};
struct modDescriptor runarray_modDesc = {
  "runarray",
  "objc3.3.19",
  0L,
  0,
  0,
  &RunArray,
  33,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_runarray(void)
{
  selTransTbl = _selTransTbl;
  return &runarray_modDesc;
}
int _OBJCPOSTLINK_runarray = 1;


