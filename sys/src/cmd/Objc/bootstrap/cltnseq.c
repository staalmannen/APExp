# 1 "cltnseq.m"
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
extern struct modDescriptor  *_OBJCBIND_cltnseq(void);
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
extern struct modDescriptor cltnseq_modDesc;

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

# 31 "./ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 32 "./cltnseq.h"
struct CollectionSequence_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./cltnseq.h"
id collection;
unsigned offset;};

# 32 "./cltnseq.h"
extern id  CollectionSequence;

# 32 "./cltnseq.h"
extern struct _SHARED _CollectionSequence;
extern struct _SHARED __CollectionSequence;


# 31 "cltnseq.m"
static id i_CollectionSequence_collection_(struct CollectionSequence_PRIVATE *self,SEL _cmd,id aCol)
{self->
collection=aCol;self->
offset=0;
return(id)self;
}

static id c_CollectionSequence_over_(struct CollectionSequence_PRIVATE *self,SEL _cmd,id aCol)
{
id objcT0,objcT1;

# 40 "cltnseq.m"
id newObj=(objcT0=__CollectionSequence.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
(objcT1=newObj,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],aCol));
return newObj;
}

static id i_CollectionSequence_copy(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 47 "cltnseq.m"
return(objcT2=_CollectionSequence.clsSuper,(*_impSuper(objcT2,selTransTbl[2]))((id)self,selTransTbl[2]));
}

static id i_CollectionSequence_free(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 52 "cltnseq.m"
return(objcT3=_CollectionSequence.clsSuper,(*_impSuper(objcT3,selTransTbl[3]))((id)self,selTransTbl[3]));
}

static id i_CollectionSequence_release(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 61 "cltnseq.m"
return(objcT4=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4],_cmd));

}

static unsigned i_CollectionSequence_size(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 67 "cltnseq.m"
return(objcT5=self->collection,(*(unsigned(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]));
}

static id i_CollectionSequence_next(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7;

# 72 "cltnseq.m"
return(self->offset<(objcT6=self->collection,(*(unsigned(*)(id,SEL))_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5])))?(objcT7=self->collection,(*(id(*)(id,SEL,unsigned))_imp(objcT7,selTransTbl[6]))(objcT7,selTransTbl[6],self->offset++)):(id)0;
}

static id i_CollectionSequence_peek(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT8,objcT9;

# 77 "cltnseq.m"
return(self->offset<(objcT8=self->collection,(*(unsigned(*)(id,SEL))_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5])))?(objcT9=self->collection,(*(id(*)(id,SEL,unsigned))_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6],self->offset)):(id)0;
}

static id i_CollectionSequence_previous(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 82 "cltnseq.m"
(void)0;
return(0<self->offset)?(objcT10=self->collection,(*(id(*)(id,SEL,unsigned))_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6],self->offset-1)):(id)0;
}

static id i_CollectionSequence_first(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 88 "cltnseq.m"
return(objcT11=self->collection,(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7]));
}

static id i_CollectionSequence_last(struct CollectionSequence_PRIVATE *self,SEL _cmd)
{
id objcT12;

# 93 "cltnseq.m"
return(objcT12=self->collection,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _CollectionSequence_clsDispatchTbl[] ={
{"over:",(id (*)())c_CollectionSequence_over_},
{(char*)0,(id (*)())0}
};
static struct _SLT _CollectionSequence_nstDispatchTbl[] ={
{"collection:",(id (*)())i_CollectionSequence_collection_},
{"copy",(id (*)())i_CollectionSequence_copy},
{"free",(id (*)())i_CollectionSequence_free},
{"release",(id (*)())i_CollectionSequence_release},
{"size",(id (*)())i_CollectionSequence_size},
{"next",(id (*)())i_CollectionSequence_next},
{"peek",(id (*)())i_CollectionSequence_peek},
{"previous",(id (*)())i_CollectionSequence_previous},
{"first",(id (*)())i_CollectionSequence_first},
{"last",(id (*)())i_CollectionSequence_last},
{(char*)0,(id (*)())0}
};
id CollectionSequence = (id)&_CollectionSequence;
id  *OBJCCLASS_CollectionSequence(void) { return &CollectionSequence; }
struct _SHARED  _CollectionSequence = {
  (id)&__CollectionSequence,
  (id)&_Object,
  "CollectionSequence",
  0,
  sizeof(struct CollectionSequence_PRIVATE),
  10,
  _CollectionSequence_nstDispatchTbl,
  41,
  &cltnseq_modDesc,
  0,
  (id)0,
  &CollectionSequence,
};
id  OBJCCFUNC_CollectionSequence(void) { return (id)&_CollectionSequence; }
id  OBJCCSUPER_CollectionSequence(void) { return _CollectionSequence.clsSuper; }
struct _SHARED __CollectionSequence = {
  (id)&__Object,
  (id)&__Object,
  "CollectionSequence",
  0,
  sizeof(struct _SHARED),
  1,
  _CollectionSequence_clsDispatchTbl,
  34,
  &cltnseq_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_CollectionSequence(void) { return (id)&__CollectionSequence; }
id  OBJCMSUPER_CollectionSequence(void) { return __CollectionSequence.clsSuper; }
static char *_selTransTbl[] ={
"new",
"collection:",
"copy",
"free",
"notImplemented:",
"size",
"at:",
"firstElement",
"lastElement",
0
};
struct modDescriptor cltnseq_modDesc = {
  "cltnseq",
  "objc3.3.19",
  0L,
  0,
  0,
  &CollectionSequence,
  9,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_cltnseq(void)
{
  selTransTbl = _selTransTbl;
  return &cltnseq_modDesc;
}
int _OBJCPOSTLINK_cltnseq = 1;


