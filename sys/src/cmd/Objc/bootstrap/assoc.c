# 1 "assoc.m"
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
extern struct modDescriptor  *_OBJCBIND_assoc(void);
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
extern struct modDescriptor assoc_modDesc;

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

# 35 "./assoc.h"
struct Assoc_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 37 "./assoc.h"
id key;
id value;};

# 35 "./assoc.h"
extern id  Assoc;

# 35 "./assoc.h"
extern struct _SHARED _Assoc;
extern struct _SHARED __Assoc;


# 34 "assoc.m"
static id i_Assoc_key_value_(struct Assoc_PRIVATE *self,SEL _cmd,id aKey,id aValue)
{self->
key=aKey;self->
value=aValue;
return(id)self;
}

static id c_Assoc_key_(struct Assoc_PRIVATE *self,SEL _cmd,id aKey)
{
id objcT0;

# 43 "assoc.m"
return(objcT0=(id)self,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],aKey,(id)0));
}

static id c_Assoc_key_value_(struct Assoc_PRIVATE *self,SEL _cmd,id aKey,id aValue)
{
id objcT1,objcT2;

# 48 "assoc.m"
id newObj=(objcT1=__Assoc.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
(objcT2=newObj,(*_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0],aKey,aValue));
return newObj;
}

# 59 "assoc.m"
static id i_Assoc_key(struct Assoc_PRIVATE *self,SEL _cmd)
{
return self->key;
}

static STR i_Assoc_str(struct Assoc_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 66 "assoc.m"
return(objcT3=self->key,(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
}

static id i_Assoc_value(struct Assoc_PRIVATE *self,SEL _cmd)
{
return self->value;
}

static id i_Assoc_free(struct Assoc_PRIVATE *self,SEL _cmd)
{
id objcT4;
return(objcT4=_Assoc.clsSuper,(*_impSuper(objcT4,selTransTbl[3]))((id)self,selTransTbl[3]));
}

static id i_Assoc_freeAll(struct Assoc_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6,objcT7;
self->
# 82 "assoc.m"
key=(objcT5=self->key,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3]));self->
value=(objcT6=self->value,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
return(objcT7=_Assoc.clsSuper,(*_impSuper(objcT7,selTransTbl[3]))((id)self,selTransTbl[3]));
}

static id i_Assoc_release(struct Assoc_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 94 "assoc.m"
return(objcT8=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4],_cmd));

}

# 104 "assoc.m"
static unsigned i_Assoc_hash(struct Assoc_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 106 "assoc.m"
return(objcT9=self->key,(*(unsigned(*)(id,SEL))_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5]));
}

static id i_Assoc_self(struct Assoc_PRIVATE *self,SEL _cmd)
{

return self->key;
}

static BOOL i_Assoc_isEqual_(struct Assoc_PRIVATE *self,SEL _cmd,id anAssoc)
{
id objcT10,objcT11;
return((id)self==anAssoc)?(BOOL)1:(objcT10=self->key,(*(BOOL(*)(id,SEL,id))_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6],(objcT11=anAssoc,(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7]))));
}

static int i_Assoc_compare_(struct Assoc_PRIVATE *self,SEL _cmd,id anAssoc)
{
id objcT12,objcT13;

# 123 "assoc.m"
return(objcT12=self->key,(*(int(*)(id,SEL,id))_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8],(objcT13=anAssoc,(*_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7]))));
}

# 132 "assoc.m"
static id i_Assoc_value_(struct Assoc_PRIVATE *self,SEL _cmd,id aValue)
{
id tmp=self->value;self->
value=aValue;
return tmp;
}

# 145 "assoc.m"
static id i_Assoc_printOn_(struct Assoc_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT14,objcT15;

# 147 "assoc.m"
(objcT14=self->key,(*(id(*)(id,SEL,IOD))_imp(objcT14,selTransTbl[9]))(objcT14,selTransTbl[9],aFile));
fprintf(aFile,"\t");
(objcT15=self->value,(*(id(*)(id,SEL,IOD))_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9],aFile));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Assoc_clsDispatchTbl[] ={
{"key:",(id (*)())c_Assoc_key_},
{"key:value:",(id (*)())c_Assoc_key_value_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Assoc_nstDispatchTbl[] ={
{"key:value:",(id (*)())i_Assoc_key_value_},
{"key",(id (*)())i_Assoc_key},
{"str",(id (*)())i_Assoc_str},
{"value",(id (*)())i_Assoc_value},
{"free",(id (*)())i_Assoc_free},
{"freeAll",(id (*)())i_Assoc_freeAll},
{"release",(id (*)())i_Assoc_release},
{"hash",(id (*)())i_Assoc_hash},
{"self",(id (*)())i_Assoc_self},
{"isEqual:",(id (*)())i_Assoc_isEqual_},
{"compare:",(id (*)())i_Assoc_compare_},
{"value:",(id (*)())i_Assoc_value_},
{"printOn:",(id (*)())i_Assoc_printOn_},
{(char*)0,(id (*)())0}
};
id Assoc = (id)&_Assoc;
id  *OBJCCLASS_Assoc(void) { return &Assoc; }
struct _SHARED  _Assoc = {
  (id)&__Assoc,
  (id)&_Object,
  "Assoc",
  0,
  sizeof(struct Assoc_PRIVATE),
  13,
  _Assoc_nstDispatchTbl,
  41,
  &assoc_modDesc,
  0,
  (id)0,
  &Assoc,
};
id  OBJCCFUNC_Assoc(void) { return (id)&_Assoc; }
id  OBJCCSUPER_Assoc(void) { return _Assoc.clsSuper; }
struct _SHARED __Assoc = {
  (id)&__Object,
  (id)&__Object,
  "Assoc",
  0,
  sizeof(struct _SHARED),
  2,
  _Assoc_clsDispatchTbl,
  34,
  &assoc_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Assoc(void) { return (id)&__Assoc; }
id  OBJCMSUPER_Assoc(void) { return __Assoc.clsSuper; }
static char *_selTransTbl[] ={
"key:value:",
"new",
"str",
"free",
"notImplemented:",
"hash",
"isEqual:",
"self",
"compare:",
"printOn:",
0
};
struct modDescriptor assoc_modDesc = {
  "assoc",
  "objc3.3.19",
  0L,
  0,
  0,
  &Assoc,
  10,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_assoc(void)
{
  selTransTbl = _selTransTbl;
  return &assoc_modDesc;
}
int _OBJCPOSTLINK_assoc = 1;


