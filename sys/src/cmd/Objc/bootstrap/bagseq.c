# 1 "bagseq.m"
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
extern struct modDescriptor  *_OBJCBIND_bagseq(void);
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
extern struct modDescriptor bagseq_modDesc;

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

struct BagSequence_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 38 "./bagseq.h"
struct objbagseq value;};

# 36 "./bagseq.h"
extern id  BagSequence;

# 36 "./bagseq.h"
extern struct _SHARED _BagSequence;
extern struct _SHARED __BagSequence;


# 29 "bagseq.m"
static objbagseq_t i_BagSequence_objbagseqvalue(struct BagSequence_PRIVATE *self,SEL _cmd)
{
return &self->value;
}

static void
objbagseq_init(objbagseq_t self,id bag)
{
id objcT0;

# 37 "bagseq.m"
self->set=(objcT0=bag,(*(objbag_t(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
self->offset= -1;
self->cnt=0;
}

static id c_BagSequence_over_(struct BagSequence_PRIVATE *self,SEL _cmd,id bag)
{
id objcT1,objcT2;

# 44 "bagseq.m"
id newObj=(objcT1=__BagSequence.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
objbagseq_init((objcT2=newObj,(*(objbagseq_t(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2])),bag);
return newObj;
}

static id i_BagSequence_copy(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 51 "bagseq.m"
return(objcT3=_BagSequence.clsSuper,(*_impSuper(objcT3,selTransTbl[3]))((id)self,selTransTbl[3]));
}

static id i_BagSequence_free(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 56 "bagseq.m"
return(objcT4=_BagSequence.clsSuper,(*_impSuper(objcT4,selTransTbl[4]))((id)self,selTransTbl[4]));
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

static int
objbagseq_size(objbagseq_t self)
{
return size(self->set);
}

static int
cntat(objbag_t self,int i)
{
(void)0;
return(self->cnts)[i];
}

static id
at(objbag_t self,int i)
{
(void)0;
return(self->ptr)[i];
}

static unsigned i_BagSequence_size(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 99 "bagseq.m"
return(unsigned)objbagseq_size((objcT5=(id)self,(*(objbagseq_t(*)(id,SEL))_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2])));
}

static int
ptrmatch(id*p,int i,int n)
{
while(i<n)
if(p[i])
return i;
else
i++;
return -1;
}

static int
match(objbag_t self,int i)
{
return ptrmatch(self->ptr,i,self->capacity);
}

static id
next(objbagseq_t self)
{
if(self->cnt>0)
{
self->cnt--;
return at(self->set,self->offset);
}
else
{
int i=match(self->set,self->offset+1);
if(i== -1)
{
return(id)0;
}
else
{
id obj=at(self->set,i);
self->cnt=cntat(self->set,i)-1;
(void)0;
self->offset=i;
return obj;
}
}
}

static id i_BagSequence_next(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 147 "bagseq.m"
return next((objcT6=(id)self,(*(objbagseq_t(*)(id,SEL))_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2])));
}

static id
peek(objbagseq_t self)
{
if(self->cnt)
{
return at(self->set,self->offset);
}
else
{
int i=match(self->set,self->offset+1);
if(i== -1)
{
return(id)0;
}
else
{
return at(self->set,i);
}
}
}

static id i_BagSequence_peek(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT7;

# 173 "bagseq.m"
return peek((objcT7=(id)self,(*(objbagseq_t(*)(id,SEL))_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2])));
}

static int
ptrprev(id*p,int i)
{
while( --i)
if(p[i])
return i;
return -1;
}

static int
prev(objbag_t self,int i)
{
return ptrprev(self->ptr,i);
}

static id
objbagseq_prev(objbagseq_t self)
{
int i=prev(self->set,self->offset);
return(i== -1)?(id)0:at(self->set,i);
}

static id i_BagSequence_previous(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 200 "bagseq.m"
return objbagseq_prev((objcT8=(id)self,(*(objbagseq_t(*)(id,SEL))_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2])));
}

static id
objbagseq_first(objbagseq_t self)
{
int i=match(self->set,0);
return(i== -1)?(id)0:at(self->set,i);
}

static id i_BagSequence_first(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 212 "bagseq.m"
return objbagseq_first((objcT9=(id)self,(*(objbagseq_t(*)(id,SEL))_imp(objcT9,selTransTbl[2]))(objcT9,selTransTbl[2])));
}

static int
last(objbag_t self)
{
return prev(self,self->capacity);
}

static id
objbagseq_last(objbagseq_t self)
{
int i=last(self->set);
return(i== -1)?(id)0:at(self->set,i);
}

static id i_BagSequence_last(struct BagSequence_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 230 "bagseq.m"
return objbagseq_last((objcT10=(id)self,(*(objbagseq_t(*)(id,SEL))_imp(objcT10,selTransTbl[2]))(objcT10,selTransTbl[2])));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _BagSequence_clsDispatchTbl[] ={
{"over:",(id (*)())c_BagSequence_over_},
{(char*)0,(id (*)())0}
};
static struct _SLT _BagSequence_nstDispatchTbl[] ={
{"objbagseqvalue",(id (*)())i_BagSequence_objbagseqvalue},
{"copy",(id (*)())i_BagSequence_copy},
{"free",(id (*)())i_BagSequence_free},
{"size",(id (*)())i_BagSequence_size},
{"next",(id (*)())i_BagSequence_next},
{"peek",(id (*)())i_BagSequence_peek},
{"previous",(id (*)())i_BagSequence_previous},
{"first",(id (*)())i_BagSequence_first},
{"last",(id (*)())i_BagSequence_last},
{(char*)0,(id (*)())0}
};
id BagSequence = (id)&_BagSequence;
id  *OBJCCLASS_BagSequence(void) { return &BagSequence; }
struct _SHARED  _BagSequence = {
  (id)&__BagSequence,
  (id)&_Object,
  "BagSequence",
  0,
  sizeof(struct BagSequence_PRIVATE),
  9,
  _BagSequence_nstDispatchTbl,
  41,
  &bagseq_modDesc,
  0,
  (id)0,
  &BagSequence,
};
id  OBJCCFUNC_BagSequence(void) { return (id)&_BagSequence; }
id  OBJCCSUPER_BagSequence(void) { return _BagSequence.clsSuper; }
struct _SHARED __BagSequence = {
  (id)&__Object,
  (id)&__Object,
  "BagSequence",
  0,
  sizeof(struct _SHARED),
  1,
  _BagSequence_clsDispatchTbl,
  34,
  &bagseq_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_BagSequence(void) { return (id)&__BagSequence; }
id  OBJCMSUPER_BagSequence(void) { return __BagSequence.clsSuper; }
static char *_selTransTbl[] ={
"objbagvalue",
"new",
"objbagseqvalue",
"copy",
"free",
0
};
struct modDescriptor bagseq_modDesc = {
  "bagseq",
  "objc3.3.19",
  0L,
  0,
  0,
  &BagSequence,
  5,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_bagseq(void)
{
  selTransTbl = _selTransTbl;
  return &bagseq_modDesc;
}
int _OBJCPOSTLINK_bagseq = 1;


