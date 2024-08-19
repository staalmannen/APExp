# 1 "setseq.m"
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
extern struct modDescriptor  *_OBJCBIND_setseq(void);
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
extern struct modDescriptor setseq_modDesc;

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

struct SetSequence_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 37 "./setseq.h"
struct objsetseq value;};

# 35 "./setseq.h"
extern id  SetSequence;

# 35 "./setseq.h"
extern struct _SHARED _SetSequence;
extern struct _SHARED __SetSequence;


# 29 "setseq.m"
static objsetseq_t i_SetSequence_objsetseqvalue(struct SetSequence_PRIVATE *self,SEL _cmd)
{
return &self->value;
}

static void
objsetseq_init(objsetseq_t self,id set)
{
id objcT0;

# 37 "setseq.m"
self->set=(objcT0=set,(*(objset_t(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
self->offset=0;
}

static id c_SetSequence_over_(struct SetSequence_PRIVATE *self,SEL _cmd,id set)
{
id objcT1,objcT2;

# 43 "setseq.m"
id newObj=(objcT1=__SetSequence.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
objsetseq_init((objcT2=newObj,(*(objsetseq_t(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2])),set);
return newObj;
}

static id i_SetSequence_copy(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 50 "setseq.m"
return(objcT3=_SetSequence.clsSuper,(*_impSuper(objcT3,selTransTbl[3]))((id)self,selTransTbl[3]));
}

static id i_SetSequence_free(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 55 "setseq.m"
return(objcT4=_SetSequence.clsSuper,(*_impSuper(objcT4,selTransTbl[4]))((id)self,selTransTbl[4]));
}

static int
size(objset_t self)
{
return self->count;
}

static int
objsetseq_size(objsetseq_t self)
{
return size(self->set);
}

static id
at(objset_t self,int i)
{
(void)0;
return(self->ptr)[i];
}

static unsigned i_SetSequence_size(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 79 "setseq.m"
return(unsigned)objsetseq_size((objcT5=(id)self,(*(objsetseq_t(*)(id,SEL))_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2])));
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
match(objset_t self,int i)
{
return ptrmatch(self->ptr,i,self->capacity);
}

static id
next(objsetseq_t self)
{
int i=match(self->set,self->offset);
if(i== -1)
{
return(id)0;
}
else
{
id obj=at(self->set,i);
self->offset=i+1;
return obj;
}
}

static id i_SetSequence_next(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 117 "setseq.m"
return next((objcT6=(id)self,(*(objsetseq_t(*)(id,SEL))_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2])));
}

static id
peek(objsetseq_t self)
{
int i=match(self->set,self->offset);
if(i== -1)
{
return(id)0;
}
else
{
return at(self->set,i);
}
}

static id i_SetSequence_peek(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT7;

# 136 "setseq.m"
return peek((objcT7=(id)self,(*(objsetseq_t(*)(id,SEL))_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2])));
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
prev(objset_t self,int i)
{
return ptrprev(self->ptr,i);
}

static id
objsetseq_prev(objsetseq_t self)
{
int i=prev(self->set,self->offset);
return(i== -1)?(id)0:at(self->set,i);
}

static id i_SetSequence_previous(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 163 "setseq.m"
return objsetseq_prev((objcT8=(id)self,(*(objsetseq_t(*)(id,SEL))_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2])));
}

static id
objsetseq_first(objsetseq_t self)
{
int i=match(self->set,0);
return(i== -1)?(id)0:at(self->set,i);
}

static id i_SetSequence_first(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 175 "setseq.m"
return objsetseq_first((objcT9=(id)self,(*(objsetseq_t(*)(id,SEL))_imp(objcT9,selTransTbl[2]))(objcT9,selTransTbl[2])));
}

static int
last(objset_t self)
{
return prev(self,self->capacity);
}

static id
objsetseq_last(objsetseq_t self)
{
int i=last(self->set);
return(i== -1)?(id)0:at(self->set,i);
}

static id i_SetSequence_last(struct SetSequence_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 193 "setseq.m"
return objsetseq_last((objcT10=(id)self,(*(objsetseq_t(*)(id,SEL))_imp(objcT10,selTransTbl[2]))(objcT10,selTransTbl[2])));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _SetSequence_clsDispatchTbl[] ={
{"over:",(id (*)())c_SetSequence_over_},
{(char*)0,(id (*)())0}
};
static struct _SLT _SetSequence_nstDispatchTbl[] ={
{"objsetseqvalue",(id (*)())i_SetSequence_objsetseqvalue},
{"copy",(id (*)())i_SetSequence_copy},
{"free",(id (*)())i_SetSequence_free},
{"size",(id (*)())i_SetSequence_size},
{"next",(id (*)())i_SetSequence_next},
{"peek",(id (*)())i_SetSequence_peek},
{"previous",(id (*)())i_SetSequence_previous},
{"first",(id (*)())i_SetSequence_first},
{"last",(id (*)())i_SetSequence_last},
{(char*)0,(id (*)())0}
};
id SetSequence = (id)&_SetSequence;
id  *OBJCCLASS_SetSequence(void) { return &SetSequence; }
struct _SHARED  _SetSequence = {
  (id)&__SetSequence,
  (id)&_Object,
  "SetSequence",
  0,
  sizeof(struct SetSequence_PRIVATE),
  9,
  _SetSequence_nstDispatchTbl,
  41,
  &setseq_modDesc,
  0,
  (id)0,
  &SetSequence,
};
id  OBJCCFUNC_SetSequence(void) { return (id)&_SetSequence; }
id  OBJCCSUPER_SetSequence(void) { return _SetSequence.clsSuper; }
struct _SHARED __SetSequence = {
  (id)&__Object,
  (id)&__Object,
  "SetSequence",
  0,
  sizeof(struct _SHARED),
  1,
  _SetSequence_clsDispatchTbl,
  34,
  &setseq_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_SetSequence(void) { return (id)&__SetSequence; }
id  OBJCMSUPER_SetSequence(void) { return __SetSequence.clsSuper; }
static char *_selTransTbl[] ={
"objsetvalue",
"new",
"objsetseqvalue",
"copy",
"free",
0
};
struct modDescriptor setseq_modDesc = {
  "setseq",
  "objc3.3.19",
  0L,
  0,
  0,
  &SetSequence,
  5,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_setseq(void)
{
  selTransTbl = _selTransTbl;
  return &setseq_modDesc;
}
int _OBJCPOSTLINK_setseq = 1;


