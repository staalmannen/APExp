# 1 "idarray.m"
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
extern struct modDescriptor  *_OBJCBIND_idarray(void);
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
extern struct modDescriptor idarray_modDesc;

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

# 28 "./idarray.h"
typedef struct idary
{
int capacity;
id*ptr;
}*
idary_t;
# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 35 "./idarray.h"
struct IdArray_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./array.h"
unsigned capacity;
# 37 "./idarray.h"
struct idary value;};

# 35 "./idarray.h"
extern id  IdArray;

# 35 "./idarray.h"
extern struct _SHARED _IdArray;
extern struct _SHARED __IdArray;


# 54 "idarray.m"
static void
init(idary_t self,id v,int c)
{
id*p=(id*)OC_Calloc(c*sizeof(id));
self->capacity=c;
self->ptr=p;
}

static id c_IdArray_new(struct IdArray_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 64 "idarray.m"
id newObj=(objcT0=__IdArray.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
init((objcT1=newObj,(*(idary_t(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1])),(id)0,(16));
return newObj;
}

static id c_IdArray_new_(struct IdArray_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT2,objcT3;

# 71 "idarray.m"
id newObj=(objcT2=__IdArray.clsSuper,(*_impSuper(objcT2,selTransTbl[0]))((id)self,selTransTbl[0]));
init((objcT3=newObj,(*(idary_t(*)(id,SEL))_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1])),(id)0,n);
return newObj;
}

static id c_IdArray_with_(struct IdArray_PRIVATE *self,SEL _cmd,int nArgs,...)
{
id objcT4;
unsigned i;
va_list vp;
id newObject=(objcT4=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],nArgs));
# 96 "idarray.m"
va_start(vp,nArgs);
for(i=0;i<nArgs;i++)
{
id objcT5;

# 99 "idarray.m"
id anObject=va_arg(vp,id);
(objcT5=newObject,(*(id(*)(id,SEL,unsigned,id))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],i,anObject));
}
va_end(vp);


return newObject;
}

static void
idncpy(id*p,id*q,int n)
{
while(n--)
{ *
p++= *q++;
}
}

static void
copy(idary_t dst,idary_t src)
{
int n=src->capacity;
dst->capacity=n;
dst->ptr=(id*)OC_Malloc(n*sizeof(id));
idncpy(dst->ptr,src->ptr,n);
}

static id i_IdArray_copy(struct IdArray_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7;

# 128 "idarray.m"
id aCopy=(objcT6=_IdArray.clsSuper,(*_impSuper(objcT6,selTransTbl[4]))((id)self,selTransTbl[4]));
copy((objcT7=aCopy,(*(idary_t(*)(id,SEL))_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1])),( &self->value));
return aCopy;
}

static void
idndeepcpy(id*p,id*q,int n)
{
while(n--)
{
id objcT8;
 *
# 138 "idarray.m"
p++=(objcT8= *q++,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
}
}

static void
deepcopy(idary_t dst,idary_t src)
{
int n=src->capacity;
dst->capacity=n;
dst->ptr=(id*)OC_Malloc(n*sizeof(id));
idndeepcpy(dst->ptr,src->ptr,n);
}

static id i_IdArray_deepCopy(struct IdArray_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10;

# 153 "idarray.m"
id aCopy=(objcT9=_IdArray.clsSuper,(*_impSuper(objcT9,selTransTbl[4]))((id)self,selTransTbl[4]));
deepcopy((objcT10=aCopy,(*(idary_t(*)(id,SEL))_imp(objcT10,selTransTbl[1]))(objcT10,selTransTbl[1])),( &self->value));
return aCopy;
}

static void
clear(idary_t self)
{
OC_Free(self->ptr);
self->ptr=NULL;
}

static id i_IdArray_free(struct IdArray_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 167 "idarray.m"
clear(( &self->value));
return(objcT11=_IdArray.clsSuper,(*_impSuper(objcT11,selTransTbl[6]))((id)self,selTransTbl[6]));
}

# 177 "idarray.m"
static idary_t i_IdArray_idaryvalue(struct IdArray_PRIVATE *self,SEL _cmd)
{
return( &self->value);
}

static unsigned
getsize(idary_t self)
{
unsigned s=0;
int i=self->capacity;
while(i--)
if((self->ptr)[i])
s++;
return s;
}

static unsigned i_IdArray_size(struct IdArray_PRIVATE *self,SEL _cmd)
{
return getsize(( &self->value));
}

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 198 "idarray.m"
static id
at(idary_t self,int i)
{
if(0<=i&&i<self->capacity)
{
return(self->ptr)[i];
}
else
{
id objcT12;

# 207 "idarray.m"
(objcT12=OutOfBounds,(*_imp(objcT12,selTransTbl[7]))(objcT12,selTransTbl[7]));
return(id)0;
}
}

static id i_IdArray_at_(struct IdArray_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
return at(( &self->value),anOffset);
}

static id
idputid(id*self,id c)
{
id r= *self; *
self=c;
return r;
}

static id
putat(idary_t self,int i,id c)
{
if(0<=i&&i<self->capacity)
{
return idputid(self->ptr+i,c);
}
else
{
id objcT13;

# 234 "idarray.m"
(objcT13=OutOfBounds,(*_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7]));
return(id)0;
}
}

static id i_IdArray_at_put_(struct IdArray_PRIVATE *self,SEL _cmd,unsigned anOffset,id anObject)
{
return putat(( &self->value),anOffset,anObject);
}

# 250 "idarray.m"
static unsigned i_IdArray_capacity(struct IdArray_PRIVATE *self,SEL _cmd)
{
return(( &self->value)->capacity);
}

static void
resize(idary_t self,unsigned c)
{
int min,n;
id*newp=(id*)OC_Realloc(self->ptr,c*sizeof(id));
n=self->capacity;
min=(n<c)?n:c;
memset(newp+min,0,sizeof(id)*(c-min));
self->ptr=newp;
self->capacity=c;
}

static id i_IdArray_capacity_(struct IdArray_PRIVATE *self,SEL _cmd,unsigned nSlots)
{
resize(( &self->value),nSlots);
return(id)self;
}

static void
removenils(id*to,id*limit)
{
id*from;

while((to<limit)&&( *to!=(id)0))
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
to++=(id)0;
}
}

static void
packcontents(idary_t self)
{
removenils(self->ptr,self->ptr+self->capacity);
}

static id i_IdArray_packContents(struct IdArray_PRIVATE *self,SEL _cmd)
{
packcontents(( &self->value));
return(id)self;
}

# 311 "idarray.m"
static id i_IdArray_printOn_(struct IdArray_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT14;

# 313 "idarray.m"
unsigned i,n=(objcT14=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8]));

if(n)
{
id objcT15,objcT16;

# 317 "idarray.m"
id o=(objcT15=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9],0));
if(o)
(objcT16=o,(*(id(*)(id,SEL,IOD))_imp(objcT16,selTransTbl[10]))(objcT16,selTransTbl[10],aFile));
else
fprintf(aFile,"nil");
}

for(i=0;i<n;i++)
{
id objcT17,objcT18;

# 326 "idarray.m"
id o=(objcT17=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT17,selTransTbl[9]))(objcT17,selTransTbl[9],i));
fprintf(aFile,",");
if(o)
(objcT18=o,(*(id(*)(id,SEL,IOD))_imp(objcT18,selTransTbl[10]))(objcT18,selTransTbl[10],aFile));
else
fprintf(aFile,"nil");
}

return(id)self;
}

# 344 "idarray.m"
static void
idfileout(id aFiler,id*p,int n)
{
while(n--)
{
id objcT19;

# 349 "idarray.m"
(objcT19=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT19,selTransTbl[11]))(objcT19,selTransTbl[11],p++,'@'));
}
}

static void
idfilein(id aFiler,id*p,int n)
{
while(n--)
{
id objcT20;

# 358 "idarray.m"
(objcT20=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT20,selTransTbl[12]))(objcT20,selTransTbl[12],p++,'@'));
}
}

static void
fileout(id aFiler,idary_t self)
{
id objcT21;

# 365 "idarray.m"
(objcT21=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT21,selTransTbl[11]))(objcT21,selTransTbl[11], &self->capacity,'i'));
idfileout(aFiler,self->ptr,self->capacity);
}

static void
filein(id aFiler,idary_t self)
{
id objcT22;

# 372 "idarray.m"
(objcT22=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT22,selTransTbl[12]))(objcT22,selTransTbl[12], &self->capacity,'i'));
self->ptr=(id*)OC_Malloc(self->capacity*sizeof(id));
idfilein(aFiler,self->ptr,self->capacity);
}

static id i_IdArray_fileOutOn_(struct IdArray_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT23;

# 379 "idarray.m"
(objcT23=_IdArray.clsSuper,(*_impSuper(objcT23,selTransTbl[13]))((id)self,selTransTbl[13],aFiler));
fileout(aFiler,( &self->value));
return(id)self;
}

static id i_IdArray_fileInFrom_(struct IdArray_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT24;

# 386 "idarray.m"
(objcT24=_IdArray.clsSuper,(*_impSuper(objcT24,selTransTbl[14]))((id)self,selTransTbl[14],aFiler));
filein(aFiler,( &self->value));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Array;
extern struct _SHARED _Array;
extern struct _SHARED __Array;
static struct _SLT _IdArray_clsDispatchTbl[] ={
{"new",(id (*)())c_IdArray_new},
{"new:",(id (*)())c_IdArray_new_},
{"with:",(id (*)())c_IdArray_with_},
{(char*)0,(id (*)())0}
};
static struct _SLT _IdArray_nstDispatchTbl[] ={
{"copy",(id (*)())i_IdArray_copy},
{"deepCopy",(id (*)())i_IdArray_deepCopy},
{"free",(id (*)())i_IdArray_free},
{"idaryvalue",(id (*)())i_IdArray_idaryvalue},
{"size",(id (*)())i_IdArray_size},
{"at:",(id (*)())i_IdArray_at_},
{"at:put:",(id (*)())i_IdArray_at_put_},
{"capacity",(id (*)())i_IdArray_capacity},
{"capacity:",(id (*)())i_IdArray_capacity_},
{"packContents",(id (*)())i_IdArray_packContents},
{"printOn:",(id (*)())i_IdArray_printOn_},
{"fileOutOn:",(id (*)())i_IdArray_fileOutOn_},
{"fileInFrom:",(id (*)())i_IdArray_fileInFrom_},
{(char*)0,(id (*)())0}
};
id IdArray = (id)&_IdArray;
id  *OBJCCLASS_IdArray(void) { return &IdArray; }
struct _SHARED  _IdArray = {
  (id)&__IdArray,
  (id)&_Array,
  "IdArray",
  0,
  sizeof(struct IdArray_PRIVATE),
  13,
  _IdArray_nstDispatchTbl,
  41,
  &idarray_modDesc,
  0,
  (id)0,
  &IdArray,
};
id  OBJCCFUNC_IdArray(void) { return (id)&_IdArray; }
id  OBJCCSUPER_IdArray(void) { return _IdArray.clsSuper; }
struct _SHARED __IdArray = {
  (id)&__Object,
  (id)&__Array,
  "IdArray",
  0,
  sizeof(struct _SHARED),
  3,
  _IdArray_clsDispatchTbl,
  34,
  &idarray_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_IdArray(void) { return (id)&__IdArray; }
id  OBJCMSUPER_IdArray(void) { return __IdArray.clsSuper; }
static char *_selTransTbl[] ={
"new",
"idaryvalue",
"new:",
"at:put:",
"copy",
"deepCopy",
"free",
"signal",
"size",
"at:",
"printOn:",
"fileOut:type:",
"fileIn:type:",
"fileOutOn:",
"fileInFrom:",
0
};
struct modDescriptor idarray_modDesc = {
  "idarray",
  "objc3.3.19",
  0L,
  0,
  0,
  &IdArray,
  15,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_idarray(void)
{
  selTransTbl = _selTransTbl;
  return &idarray_modDesc;
}
int _OBJCPOSTLINK_idarray = 1;


