# 1 "intarray.m"
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
extern struct modDescriptor  *_OBJCBIND_intarray(void);
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
extern struct modDescriptor intarray_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//assert.h"
#include <assert.h>

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

# 28 "./intarray.h"
typedef struct intary
{
int capacity;
int*ptr;
}*
intary_t;
# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 35 "./intarray.h"
struct IntArray_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./array.h"
unsigned capacity;
# 37 "./intarray.h"
struct intary value;};

# 35 "./intarray.h"
extern id  IntArray;

# 35 "./intarray.h"
extern struct _SHARED _IntArray;
extern struct _SHARED __IntArray;


# 42 "intarray.m"
static void
fill(int*p,int v,int n)
{
while(n--)
{ *
p++=v;
}
}

static void
init(intary_t self,int v,int c)
{
int*p=(int*)OC_MallocAtomic(c*sizeof(int));
self->capacity=c;
self->ptr=p;
fill(p,v,c);
}

static id c_IntArray_new(struct IntArray_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 62 "intarray.m"
id newObj=(objcT0=__IntArray.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
init((objcT1=newObj,(*(intary_t(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1])),0,(16));
return newObj;
}

static id c_IntArray_new_(struct IntArray_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT2,objcT3;

# 69 "intarray.m"
id newObj=(objcT2=__IntArray.clsSuper,(*_impSuper(objcT2,selTransTbl[0]))((id)self,selTransTbl[0]));
init((objcT3=newObj,(*(intary_t(*)(id,SEL))_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1])),0,n);
return newObj;
}

static id c_IntArray_with_(struct IntArray_PRIVATE *self,SEL _cmd,int nArgs,...)
{
id objcT4;
unsigned i;
va_list vp;
id newObject=(objcT4=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],nArgs));
# 94 "intarray.m"
va_start(vp,nArgs);
for(i=0;i<nArgs;i++)
{
id objcT5;

# 97 "intarray.m"
int anObject=va_arg(vp,int);
(objcT5=newObject,(*(int(*)(id,SEL,unsigned,int))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],i,anObject));
}
va_end(vp);


return newObject;
}

static void
intncpy(int*p,int*q,int n)
{
while(n--)
{ *
p++= *q++;
}
}

static void
copy(intary_t dst,intary_t src)
{
int n=src->capacity;

dst->capacity=n+1;
dst->ptr=(int*)OC_MallocAtomic(dst->capacity*sizeof(int));

intncpy(dst->ptr,src->ptr,n);
}

static id i_IntArray_copy(struct IntArray_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7;

# 128 "intarray.m"
id aCopy=(objcT6=_IntArray.clsSuper,(*_impSuper(objcT6,selTransTbl[4]))((id)self,selTransTbl[4]));
copy((objcT7=aCopy,(*(intary_t(*)(id,SEL))_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1])),( &self->value));
return aCopy;
}

static id i_IntArray_deepCopy(struct IntArray_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 135 "intarray.m"
return(objcT8=(id)self,(*_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4]));
}

static void
clear(intary_t self)
{
OC_Free(self->ptr);
self->ptr=NULL;
}

static id i_IntArray_free(struct IntArray_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 147 "intarray.m"
clear(( &self->value));
return(objcT9=_IntArray.clsSuper,(*_impSuper(objcT9,selTransTbl[5]))((id)self,selTransTbl[5]));
}

# 157 "intarray.m"
static intary_t i_IntArray_intaryvalue(struct IntArray_PRIVATE *self,SEL _cmd)
{
return( &self->value);
}

static unsigned i_IntArray_size(struct IntArray_PRIVATE *self,SEL _cmd)
{
return( &self->value)->capacity;
}

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 167 "intarray.m"
static int
intat(intary_t self,int i)
{
if(0<=i&&i<self->capacity)
{
return(self->ptr)[i];
}
else
{
id objcT10;

# 176 "intarray.m"
(objcT10=OutOfBounds,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
return 0;
}
}

static int i_IntArray_intAt_(struct IntArray_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
return intat(( &self->value),anOffset);
}

static int
intputint(int*self,int c)
{
int r= *self; *
self=c;
return r;
}

static int
putintat(intary_t self,int i,int c)
{
if(0<=i&&i<self->capacity)
{
return intputint(self->ptr+i,c);
}
else
{
id objcT11;

# 203 "intarray.m"
(objcT11=OutOfBounds,(*_imp(objcT11,selTransTbl[6]))(objcT11,selTransTbl[6]));
return 0;
}
}

static int i_IntArray_intAt_put_(struct IntArray_PRIVATE *self,SEL _cmd,unsigned anOffset,int anInt)
{
return putintat(( &self->value),anOffset,anInt);
}

# 219 "intarray.m"
static void
resize(intary_t self,unsigned c)
{
int min,n;
int*newp=(int*)OC_Realloc(self->ptr,c*sizeof(int));
n=self->capacity;
min=(n<c)?n:c;
fill(newp+min,0,c-min);
self->ptr=newp;
self->capacity=c;
}

static unsigned i_IntArray_capacity(struct IntArray_PRIVATE *self,SEL _cmd)
{
return( &self->value)->capacity;
}

static id i_IntArray_capacity_(struct IntArray_PRIVATE *self,SEL _cmd,unsigned nSlots)
{
resize(( &self->value),nSlots);
return(id)self;
}

static void
removezeroes(int*to,int*limit)
{
int*from;

while((to<limit)&&( *to!=0))
{
to++;
}
for(from=to+1;from<limit;from++)
{
if( *from) *
to++= *from;
}
while(to<limit)
{ *
to++=0;
}
}

static void
packcontents(intary_t self)
{
removezeroes(self->ptr,self->ptr+self->capacity);
}

static id i_IntArray_packContents(struct IntArray_PRIVATE *self,SEL _cmd)
{
packcontents(( &self->value));
return(id)self;
}

# 280 "intarray.m"
static id i_IntArray_printOn_(struct IntArray_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT12,objcT13,objcT14;

# 282 "intarray.m"
unsigned i,n=(objcT12=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT12,selTransTbl[7]))(objcT12,selTransTbl[7]));
if(n)
fprintf(aFile,"%i",(objcT13=(id)self,(*(int(*)(id,SEL,unsigned))_imp(objcT13,selTransTbl[8]))(objcT13,selTransTbl[8],0)));
for(i=1;i<n;i++)
fprintf(aFile,",%i",(objcT14=(id)self,(*(int(*)(id,SEL,unsigned))_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8],i)));
return(id)self;
}

# 297 "intarray.m"
static void
intfileout(id aFiler,int*p,int n)
{
while(n--)
{
id objcT15;

# 302 "intarray.m"
(objcT15=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9],p++,'i'));
}
}

static void
intfilein(id aFiler,int*p,int n)
{
while(n--)
{
id objcT16;

# 311 "intarray.m"
(objcT16=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT16,selTransTbl[10]))(objcT16,selTransTbl[10],p++,'i'));
}
}

static void
fileout(id aFiler,intary_t self)
{
id objcT17;

# 318 "intarray.m"
(objcT17=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT17,selTransTbl[9]))(objcT17,selTransTbl[9], &self->capacity,'i'));
intfileout(aFiler,self->ptr,self->capacity);
}

static void
filein(id aFiler,intary_t self)
{
id objcT18;

# 325 "intarray.m"
(objcT18=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT18,selTransTbl[10]))(objcT18,selTransTbl[10], &self->capacity,'i'));
self->ptr=(int*)OC_MallocAtomic(self->capacity*sizeof(int));
intfilein(aFiler,self->ptr,self->capacity);
}

static id i_IntArray_fileOutOn_(struct IntArray_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT19;

# 332 "intarray.m"
(objcT19=_IntArray.clsSuper,(*_impSuper(objcT19,selTransTbl[11]))((id)self,selTransTbl[11],aFiler));
fileout(aFiler, &self->value);
return(id)self;
}

static id i_IntArray_fileInFrom_(struct IntArray_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT20;

# 339 "intarray.m"
(objcT20=_IntArray.clsSuper,(*_impSuper(objcT20,selTransTbl[12]))((id)self,selTransTbl[12],aFiler));
filein(aFiler, &self->value);
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Array;
extern struct _SHARED _Array;
extern struct _SHARED __Array;
static struct _SLT _IntArray_clsDispatchTbl[] ={
{"new",(id (*)())c_IntArray_new},
{"new:",(id (*)())c_IntArray_new_},
{"with:",(id (*)())c_IntArray_with_},
{(char*)0,(id (*)())0}
};
static struct _SLT _IntArray_nstDispatchTbl[] ={
{"copy",(id (*)())i_IntArray_copy},
{"deepCopy",(id (*)())i_IntArray_deepCopy},
{"free",(id (*)())i_IntArray_free},
{"intaryvalue",(id (*)())i_IntArray_intaryvalue},
{"size",(id (*)())i_IntArray_size},
{"intAt:",(id (*)())i_IntArray_intAt_},
{"intAt:put:",(id (*)())i_IntArray_intAt_put_},
{"capacity",(id (*)())i_IntArray_capacity},
{"capacity:",(id (*)())i_IntArray_capacity_},
{"packContents",(id (*)())i_IntArray_packContents},
{"printOn:",(id (*)())i_IntArray_printOn_},
{"fileOutOn:",(id (*)())i_IntArray_fileOutOn_},
{"fileInFrom:",(id (*)())i_IntArray_fileInFrom_},
{(char*)0,(id (*)())0}
};
id IntArray = (id)&_IntArray;
id  *OBJCCLASS_IntArray(void) { return &IntArray; }
struct _SHARED  _IntArray = {
  (id)&__IntArray,
  (id)&_Array,
  "IntArray",
  0,
  sizeof(struct IntArray_PRIVATE),
  13,
  _IntArray_nstDispatchTbl,
  41,
  &intarray_modDesc,
  0,
  (id)0,
  &IntArray,
};
id  OBJCCFUNC_IntArray(void) { return (id)&_IntArray; }
id  OBJCCSUPER_IntArray(void) { return _IntArray.clsSuper; }
struct _SHARED __IntArray = {
  (id)&__Object,
  (id)&__Array,
  "IntArray",
  0,
  sizeof(struct _SHARED),
  3,
  _IntArray_clsDispatchTbl,
  34,
  &intarray_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_IntArray(void) { return (id)&__IntArray; }
id  OBJCMSUPER_IntArray(void) { return __IntArray.clsSuper; }
static char *_selTransTbl[] ={
"new",
"intaryvalue",
"new:",
"intAt:put:",
"copy",
"free",
"signal",
"size",
"intAt:",
"fileOut:type:",
"fileIn:type:",
"fileOutOn:",
"fileInFrom:",
0
};
struct modDescriptor intarray_modDesc = {
  "intarray",
  "objc3.3.19",
  0L,
  0,
  0,
  &IntArray,
  13,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_intarray(void)
{
  selTransTbl = _selTransTbl;
  return &intarray_modDesc;
}
int _OBJCPOSTLINK_intarray = 1;


