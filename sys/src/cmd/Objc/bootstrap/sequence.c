# 1 "sequence.m"
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
extern struct modDescriptor  *_OBJCBIND_sequence(void);
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
extern struct modDescriptor sequence_modDesc;

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

# 38 "./../../include/objcrt/Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 35 "./sequence.h"
struct Sequence_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 37 "./sequence.h"
id carrier;};

# 35 "./sequence.h"
extern id  Sequence;

# 35 "./sequence.h"
extern struct _SHARED _Sequence;
extern struct _SHARED __Sequence;


# 36 "sequence.m"
static id i_Sequence_setUpCarrier_(struct Sequence_PRIVATE *self,SEL _cmd,id aCarrier)
{self->
carrier=aCarrier;
return(id)self;
}

static id c_Sequence_over_(struct Sequence_PRIVATE *self,SEL _cmd,id aCarrier)
{
id objcT0,objcT1;

# 44 "sequence.m"
id newObj=(objcT0=__Sequence.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
(objcT1=newObj,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],aCarrier));
return newObj;
}

static id i_Sequence_over_(struct Sequence_PRIVATE *self,SEL _cmd,id aCarrier)
{
id objcT2;

# 51 "sequence.m"
return(objcT2=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],_cmd));
}

static id i_Sequence_copy(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4;

# 56 "sequence.m"
return(objcT3=self->isa,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3],(objcT4=self->carrier,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]))));
}

static id i_Sequence_free(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6;
self->
# 61 "sequence.m"
carrier=(objcT5=self->carrier,(*_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]));
return(objcT6=_Sequence.clsSuper,(*_impSuper(objcT6,selTransTbl[5]))((id)self,selTransTbl[5]));
}

static id i_Sequence_release(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT7;

# 71 "sequence.m"
return(objcT7=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2],_cmd));

}

# 81 "sequence.m"
static unsigned i_Sequence_size(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 83 "sequence.m"
return(objcT8=self->carrier,(*(unsigned(*)(id,SEL))_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
}

# 92 "sequence.m"
static id i_Sequence_next(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 94 "sequence.m"
return(objcT9=self->carrier,(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7]));
}

static id i_Sequence_peek(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 99 "sequence.m"
return(objcT10=self->carrier,(*_imp(objcT10,selTransTbl[8]))(objcT10,selTransTbl[8]));
}

static id i_Sequence_previous(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 104 "sequence.m"
return(objcT11=self->carrier,(*_imp(objcT11,selTransTbl[9]))(objcT11,selTransTbl[9]));
}

static id i_Sequence_first(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT12;

# 109 "sequence.m"
return(objcT12=self->carrier,(*_imp(objcT12,selTransTbl[10]))(objcT12,selTransTbl[10]));
}

static id i_Sequence_last(struct Sequence_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 114 "sequence.m"
return(objcT13=self->carrier,(*_imp(objcT13,selTransTbl[11]))(objcT13,selTransTbl[11]));
}

# 123 "sequence.m"
static id i_Sequence_printOn_(struct Sequence_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT14;

# 125 "sequence.m"
id aMember;
while((aMember=(objcT14=(id)self,(*_imp(objcT14,selTransTbl[7]))(objcT14,selTransTbl[7]))))
{
id objcT15;

# 128 "sequence.m"
(objcT15=aMember,(*(id(*)(id,SEL,IOD))_imp(objcT15,selTransTbl[12]))(objcT15,selTransTbl[12],aFile));
fprintf(aFile,"\n");
}
return(id)self;
}

# 141 "sequence.m"
static id i_Sequence_do_(struct Sequence_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT16,objcT17;

# 143 "sequence.m"
id aMember;
while((aMember=(objcT16=(id)self,(*_imp(objcT16,selTransTbl[7]))(objcT16,selTransTbl[7]))))
(objcT17=aBlock,(*_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13],aMember));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Sequence_clsDispatchTbl[] ={
{"over:",(id (*)())c_Sequence_over_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Sequence_nstDispatchTbl[] ={
{"setUpCarrier:",(id (*)())i_Sequence_setUpCarrier_},
{"over:",(id (*)())i_Sequence_over_},
{"copy",(id (*)())i_Sequence_copy},
{"free",(id (*)())i_Sequence_free},
{"release",(id (*)())i_Sequence_release},
{"size",(id (*)())i_Sequence_size},
{"next",(id (*)())i_Sequence_next},
{"peek",(id (*)())i_Sequence_peek},
{"previous",(id (*)())i_Sequence_previous},
{"first",(id (*)())i_Sequence_first},
{"last",(id (*)())i_Sequence_last},
{"printOn:",(id (*)())i_Sequence_printOn_},
{"do:",(id (*)())i_Sequence_do_},
{(char*)0,(id (*)())0}
};
id Sequence = (id)&_Sequence;
id  *OBJCCLASS_Sequence(void) { return &Sequence; }
struct _SHARED  _Sequence = {
  (id)&__Sequence,
  (id)&_Object,
  "Sequence",
  0,
  sizeof(struct Sequence_PRIVATE),
  13,
  _Sequence_nstDispatchTbl,
  41,
  &sequence_modDesc,
  0,
  (id)0,
  &Sequence,
};
id  OBJCCFUNC_Sequence(void) { return (id)&_Sequence; }
id  OBJCCSUPER_Sequence(void) { return _Sequence.clsSuper; }
struct _SHARED __Sequence = {
  (id)&__Object,
  (id)&__Object,
  "Sequence",
  0,
  sizeof(struct _SHARED),
  1,
  _Sequence_clsDispatchTbl,
  34,
  &sequence_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Sequence(void) { return (id)&__Sequence; }
id  OBJCMSUPER_Sequence(void) { return __Sequence.clsSuper; }
static char *_selTransTbl[] ={
"new",
"setUpCarrier:",
"notImplemented:",
"over:",
"copy",
"free",
"size",
"next",
"peek",
"previous",
"first",
"last",
"printOn:",
"value:",
0
};
struct modDescriptor sequence_modDesc = {
  "sequence",
  "objc3.3.19",
  0L,
  0,
  0,
  &Sequence,
  14,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_sequence(void)
{
  selTransTbl = _selTransTbl;
  return &sequence_modDesc;
}
int _OBJCPOSTLINK_sequence = 1;


