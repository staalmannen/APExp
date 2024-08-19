# 1 "valueseq.m"
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
extern struct modDescriptor  *_OBJCBIND_valueseq(void);
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
extern struct modDescriptor valueseq_modDesc;

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

# 32 "./valueseq.h"
struct ValueSequence_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./valueseq.h"
id carrier;};

# 32 "./valueseq.h"
extern id  ValueSequence;

# 32 "./valueseq.h"
extern struct _SHARED _ValueSequence;
extern struct _SHARED __ValueSequence;


# 35 "valueseq.m"
static id i_ValueSequence_setUpCarrier_(struct ValueSequence_PRIVATE *self,SEL _cmd,id aCarrier)
{self->
carrier=aCarrier;
return(id)self;
}

static id c_ValueSequence_over_(struct ValueSequence_PRIVATE *self,SEL _cmd,id aCarrier)
{
id objcT0,objcT1;

# 43 "valueseq.m"
id newObj=(objcT0=__ValueSequence.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
(objcT1=newObj,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],aCarrier));
return newObj;
}

static id i_ValueSequence_copy(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 50 "valueseq.m"
return(objcT2=self->isa,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],(objcT3=self->carrier,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]))));
}

static id i_ValueSequence_free(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;
self->
# 55 "valueseq.m"
carrier=(objcT4=self->carrier,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
return(objcT5=_ValueSequence.clsSuper,(*_impSuper(objcT5,selTransTbl[4]))((id)self,selTransTbl[4]));
}

# 66 "valueseq.m"
static unsigned i_ValueSequence_size(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 68 "valueseq.m"
return(objcT6=self->carrier,(*(unsigned(*)(id,SEL))_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5]));
}

# 78 "valueseq.m"
static id i_ValueSequence_next(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;

# 80 "valueseq.m"
return(objcT7=(objcT8=self->carrier,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6])),(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7]));
}

static id i_ValueSequence_peek(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10;

# 85 "valueseq.m"
return(objcT9=(objcT10=self->carrier,(*_imp(objcT10,selTransTbl[8]))(objcT10,selTransTbl[8])),(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7]));
}

static id i_ValueSequence_previous(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT11,objcT12;

# 90 "valueseq.m"
return(objcT11=(objcT12=self->carrier,(*_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9])),(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7]));
}

static id i_ValueSequence_first(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14;

# 95 "valueseq.m"
return(objcT13=(objcT14=self->carrier,(*_imp(objcT14,selTransTbl[10]))(objcT14,selTransTbl[10])),(*_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7]));
}

static id i_ValueSequence_last(struct ValueSequence_PRIVATE *self,SEL _cmd)
{
id objcT15,objcT16;

# 100 "valueseq.m"
return(objcT15=(objcT16=self->carrier,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11])),(*_imp(objcT15,selTransTbl[7]))(objcT15,selTransTbl[7]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _ValueSequence_clsDispatchTbl[] ={
{"over:",(id (*)())c_ValueSequence_over_},
{(char*)0,(id (*)())0}
};
static struct _SLT _ValueSequence_nstDispatchTbl[] ={
{"setUpCarrier:",(id (*)())i_ValueSequence_setUpCarrier_},
{"copy",(id (*)())i_ValueSequence_copy},
{"free",(id (*)())i_ValueSequence_free},
{"size",(id (*)())i_ValueSequence_size},
{"next",(id (*)())i_ValueSequence_next},
{"peek",(id (*)())i_ValueSequence_peek},
{"previous",(id (*)())i_ValueSequence_previous},
{"first",(id (*)())i_ValueSequence_first},
{"last",(id (*)())i_ValueSequence_last},
{(char*)0,(id (*)())0}
};
id ValueSequence = (id)&_ValueSequence;
id  *OBJCCLASS_ValueSequence(void) { return &ValueSequence; }
struct _SHARED  _ValueSequence = {
  (id)&__ValueSequence,
  (id)&_Object,
  "ValueSequence",
  0,
  sizeof(struct ValueSequence_PRIVATE),
  9,
  _ValueSequence_nstDispatchTbl,
  41,
  &valueseq_modDesc,
  0,
  (id)0,
  &ValueSequence,
};
id  OBJCCFUNC_ValueSequence(void) { return (id)&_ValueSequence; }
id  OBJCCSUPER_ValueSequence(void) { return _ValueSequence.clsSuper; }
struct _SHARED __ValueSequence = {
  (id)&__Object,
  (id)&__Object,
  "ValueSequence",
  0,
  sizeof(struct _SHARED),
  1,
  _ValueSequence_clsDispatchTbl,
  34,
  &valueseq_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ValueSequence(void) { return (id)&__ValueSequence; }
id  OBJCMSUPER_ValueSequence(void) { return __ValueSequence.clsSuper; }
static char *_selTransTbl[] ={
"new",
"setUpCarrier:",
"over:",
"copy",
"free",
"size",
"next",
"value",
"peek",
"previous",
"first",
"last",
0
};
struct modDescriptor valueseq_modDesc = {
  "valueseq",
  "objc3.3.19",
  0L,
  0,
  0,
  &ValueSequence,
  12,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_valueseq(void)
{
  selTransTbl = _selTransTbl;
  return &valueseq_modDesc;
}
int _OBJCPOSTLINK_valueseq = 1;


