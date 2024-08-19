# 1 "keyseq.m"
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
extern struct modDescriptor  *_OBJCBIND_keyseq(void);
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
extern struct modDescriptor keyseq_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

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

# 32 "./keyseq.h"
struct KeySequence_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./keyseq.h"
id carrier;};

# 32 "./keyseq.h"
extern id  KeySequence;

# 32 "./keyseq.h"
extern struct _SHARED _KeySequence;
extern struct _SHARED __KeySequence;


# 35 "keyseq.m"
static id i_KeySequence_setUpCarrier_(struct KeySequence_PRIVATE *self,SEL _cmd,id aCarrier)
{self->
carrier=aCarrier;
return(id)self;
}

static id c_KeySequence_over_(struct KeySequence_PRIVATE *self,SEL _cmd,id aCarrier)
{
id objcT0,objcT1;

# 43 "keyseq.m"
id newObj=(objcT0=__KeySequence.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
(objcT1=newObj,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],aCarrier));
return newObj;
}

static id i_KeySequence_copy(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 50 "keyseq.m"
return(objcT2=self->isa,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],(objcT3=self->carrier,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]))));
}

static id i_KeySequence_free(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;
self->
# 55 "keyseq.m"
carrier=(objcT4=self->carrier,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
return(objcT5=_KeySequence.clsSuper,(*_impSuper(objcT5,selTransTbl[4]))((id)self,selTransTbl[4]));
}

# 66 "keyseq.m"
static unsigned i_KeySequence_size(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 68 "keyseq.m"
return(objcT6=self->carrier,(*(unsigned(*)(id,SEL))_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5]));
}

# 78 "keyseq.m"
static id i_KeySequence_next(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;

# 80 "keyseq.m"
return(objcT7=(objcT8=self->carrier,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6])),(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7]));
}

static id i_KeySequence_peek(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10;

# 85 "keyseq.m"
return(objcT9=(objcT10=self->carrier,(*_imp(objcT10,selTransTbl[8]))(objcT10,selTransTbl[8])),(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7]));
}

static id i_KeySequence_previous(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT11,objcT12;

# 90 "keyseq.m"
return(objcT11=(objcT12=self->carrier,(*_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9])),(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7]));
}

static id i_KeySequence_first(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14;

# 95 "keyseq.m"
return(objcT13=(objcT14=self->carrier,(*_imp(objcT14,selTransTbl[10]))(objcT14,selTransTbl[10])),(*_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7]));
}

static id i_KeySequence_last(struct KeySequence_PRIVATE *self,SEL _cmd)
{
id objcT15,objcT16;

# 100 "keyseq.m"
return(objcT15=(objcT16=self->carrier,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11])),(*_imp(objcT15,selTransTbl[7]))(objcT15,selTransTbl[7]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _KeySequence_clsDispatchTbl[] ={
{"over:",(id (*)())c_KeySequence_over_},
{(char*)0,(id (*)())0}
};
static struct _SLT _KeySequence_nstDispatchTbl[] ={
{"setUpCarrier:",(id (*)())i_KeySequence_setUpCarrier_},
{"copy",(id (*)())i_KeySequence_copy},
{"free",(id (*)())i_KeySequence_free},
{"size",(id (*)())i_KeySequence_size},
{"next",(id (*)())i_KeySequence_next},
{"peek",(id (*)())i_KeySequence_peek},
{"previous",(id (*)())i_KeySequence_previous},
{"first",(id (*)())i_KeySequence_first},
{"last",(id (*)())i_KeySequence_last},
{(char*)0,(id (*)())0}
};
id KeySequence = (id)&_KeySequence;
id  *OBJCCLASS_KeySequence(void) { return &KeySequence; }
struct _SHARED  _KeySequence = {
  (id)&__KeySequence,
  (id)&_Object,
  "KeySequence",
  0,
  sizeof(struct KeySequence_PRIVATE),
  9,
  _KeySequence_nstDispatchTbl,
  41,
  &keyseq_modDesc,
  0,
  (id)0,
  &KeySequence,
};
id  OBJCCFUNC_KeySequence(void) { return (id)&_KeySequence; }
id  OBJCCSUPER_KeySequence(void) { return _KeySequence.clsSuper; }
struct _SHARED __KeySequence = {
  (id)&__Object,
  (id)&__Object,
  "KeySequence",
  0,
  sizeof(struct _SHARED),
  1,
  _KeySequence_clsDispatchTbl,
  34,
  &keyseq_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_KeySequence(void) { return (id)&__KeySequence; }
id  OBJCMSUPER_KeySequence(void) { return __KeySequence.clsSuper; }
static char *_selTransTbl[] ={
"new",
"setUpCarrier:",
"over:",
"copy",
"free",
"size",
"next",
"key",
"peek",
"previous",
"first",
"last",
0
};
struct modDescriptor keyseq_modDesc = {
  "keyseq",
  "objc3.3.19",
  0L,
  0,
  0,
  &KeySequence,
  12,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_keyseq(void)
{
  selTransTbl = _selTransTbl;
  return &keyseq_modDesc;
}
int _OBJCPOSTLINK_keyseq = 1;


