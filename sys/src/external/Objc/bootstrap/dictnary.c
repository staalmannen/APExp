# 1 "dictnary.m"
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
extern struct modDescriptor  *_OBJCBIND_dictnary(void);
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
extern struct modDescriptor dictnary_modDesc;

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

# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 28 "./set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 32 "./dictnary.h"
struct Dictionary_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./dictnary.h"
id associations;};

# 32 "./dictnary.h"
extern id  Dictionary;

# 32 "./dictnary.h"
extern struct _SHARED _Dictionary;
extern struct _SHARED __Dictionary;


# 36 "./set.h"
extern id  Set;

# 42 "dictnary.m"
static void
setUp(id*associations)
{
id objcT0;
 *
# 45 "dictnary.m"
associations=(objcT0=Set,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id c_Dictionary_new(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT1,objcT2;

# 50 "dictnary.m"
id newObject=(objcT1=__Dictionary.clsSuper,(*_impSuper(objcT1,selTransTbl[0]))((id)self,selTransTbl[0]));
setUp((objcT2=newObject,(*(id*(*)(id,SEL))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1])));
return newObject;
}

static id i_Dictionary_copyAssociations(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT3;
self->
# 57 "dictnary.m"
associations=(objcT3=self->associations,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
return(id)self;
}

static id i_Dictionary_copy(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;

# 63 "dictnary.m"
return(objcT4=(objcT5=_Dictionary.clsSuper,(*_impSuper(objcT5,selTransTbl[2]))((id)self,selTransTbl[2])),(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));
}

static id i_Dictionary_deepCopyAssociations(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT6;
self->
# 68 "dictnary.m"
associations=(objcT6=self->associations,(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
return(id)self;
}

static id i_Dictionary_deepCopy(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;


return(objcT7=(objcT8=_Dictionary.clsSuper,(*_impSuper(objcT8,selTransTbl[2]))((id)self,selTransTbl[2])),(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5]));
}

static id i_Dictionary_emptyYourself(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 82 "dictnary.m"
(objcT9=self->associations,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
return(id)self;
}

static id i_Dictionary_freeContents(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 88 "dictnary.m"
(objcT10=self->associations,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
return(id)self;
}

static id i_Dictionary_freeAll(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 94 "dictnary.m"
(objcT11=self->associations,(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7]));
return(id)self;
}

static id i_Dictionary_free(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT12,objcT13;
self->
# 100 "dictnary.m"
associations=(objcT12=self->associations,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8]));
return(objcT13=_Dictionary.clsSuper,(*_impSuper(objcT13,selTransTbl[8]))((id)self,selTransTbl[8]));
}

static id i_Dictionary_release(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT14;

# 110 "dictnary.m"
return(objcT14=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT14,selTransTbl[9]))(objcT14,selTransTbl[9],_cmd));

}

# 121 "dictnary.m"
static id i_Dictionary_associations(struct Dictionary_PRIVATE *self,SEL _cmd)
{
return self->associations;
}

static id*i_Dictionary_associationsRef(struct Dictionary_PRIVATE *self,SEL _cmd)
{
return &self->associations;
}

static unsigned i_Dictionary_size(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT15;

# 133 "dictnary.m"
return(objcT15=self->associations,(*(unsigned(*)(id,SEL))_imp(objcT15,selTransTbl[10]))(objcT15,selTransTbl[10]));
}

static BOOL i_Dictionary_isEmpty(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT16;

# 138 "dictnary.m"
return(objcT16=self->associations,(*(BOOL(*)(id,SEL))_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11]));
}

static BOOL i_Dictionary_includesKey_(struct Dictionary_PRIVATE *self,SEL _cmd,id aKey)
{
id objcT17;

# 143 "dictnary.m"
return(BOOL)((objcT17=(id)self,(*_imp(objcT17,selTransTbl[12]))(objcT17,selTransTbl[12],aKey))!=(id)0);
}

# 153 "dictnary.m"
static unsigned i_Dictionary_hash(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 155 "dictnary.m"
return(objcT18=self->associations,(*(unsigned(*)(id,SEL))_imp(objcT18,selTransTbl[13]))(objcT18,selTransTbl[13]));
}

static BOOL i_Dictionary_isEqual_(struct Dictionary_PRIVATE *self,SEL _cmd,id aDic)
{
id objcT19,objcT20;

# 160 "dictnary.m"
if((id)self==aDic)
return(BOOL)1;
return(objcT19=self->associations,(*(BOOL(*)(id,SEL,id))_imp(objcT19,selTransTbl[14]))(objcT19,selTransTbl[14],(objcT20=aDic,(*_imp(objcT20,selTransTbl[15]))(objcT20,selTransTbl[15]))));
}

# 172 "dictnary.m"
static id i_Dictionary_associationAt_(struct Dictionary_PRIVATE *self,SEL _cmd,id aKey)
{
id objcT21;
return(objcT21=self->associations,(*_imp(objcT21,selTransTbl[16]))(objcT21,selTransTbl[16],aKey));
}

static id i_Dictionary_atKey_(struct Dictionary_PRIVATE *self,SEL _cmd,id aKey)
{
id objcT22,objcT23;

# 180 "dictnary.m"
id association=(objcT22=(id)self,(*_imp(objcT22,selTransTbl[12]))(objcT22,selTransTbl[12],aKey));
return(association)?(objcT23=association,(*_imp(objcT23,selTransTbl[17]))(objcT23,selTransTbl[17])):(id)0;
}

static id i_Dictionary_atKey_ifAbsent_(struct Dictionary_PRIVATE *self,SEL _cmd,id aKey,id exceptionBlock)
{
id objcT24,objcT25,objcT26;

# 186 "dictnary.m"
id association=(objcT24=(id)self,(*_imp(objcT24,selTransTbl[12]))(objcT24,selTransTbl[12],aKey));
return(association)?(objcT25=association,(*_imp(objcT25,selTransTbl[17]))(objcT25,selTransTbl[17])):(objcT26=exceptionBlock,(*_imp(objcT26,selTransTbl[17]))(objcT26,selTransTbl[17]));
}

# 40 "./ocstring.h"
extern id  String;

# 190 "dictnary.m"
static id i_Dictionary_atKeySTR_(struct Dictionary_PRIVATE *self,SEL _cmd,STR strKey)
{
id objcT27,objcT28;

# 192 "dictnary.m"
return(objcT27=(id)self,(*_imp(objcT27,selTransTbl[18]))(objcT27,selTransTbl[18],(objcT28=String,(*(id(*)(id,SEL,STR))_imp(objcT28,selTransTbl[19]))(objcT28,selTransTbl[19],strKey))));
}

# 35 "./assoc.h"
extern id  Assoc;

# 195 "dictnary.m"
static id i_Dictionary_atKey_put_(struct Dictionary_PRIVATE *self,SEL _cmd,id aKey,id anObject)
{
id objcT29,objcT30,objcT31;

# 197 "dictnary.m"
return(objcT29=(objcT30=self->associations,(*_imp(objcT30,selTransTbl[20]))(objcT30,selTransTbl[20],(objcT31=Assoc,(*_imp(objcT31,selTransTbl[21]))(objcT31,selTransTbl[21],aKey)))),(*_imp(objcT29,selTransTbl[22]))(objcT29,selTransTbl[22],anObject));
}

static id i_Dictionary_atKeySTR_put_(struct Dictionary_PRIVATE *self,SEL _cmd,STR strKey,id anObject)
{
id objcT32,objcT33;

# 202 "dictnary.m"
return(objcT32=(id)self,(*_imp(objcT32,selTransTbl[23]))(objcT32,selTransTbl[23],(objcT33=String,(*(id(*)(id,SEL,STR))_imp(objcT33,selTransTbl[19]))(objcT33,selTransTbl[19],strKey)),anObject));
}

# 32 "./keyseq.h"
extern id  KeySequence;

# 35 "./sequence.h"
extern id  Sequence;

# 205 "dictnary.m"
static id i_Dictionary_eachKey(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT34,objcT35,objcT36;

# 207 "dictnary.m"
id aCarrier=(objcT34=KeySequence,(*_imp(objcT34,selTransTbl[24]))(objcT34,selTransTbl[24],(objcT35=self->associations,(*_imp(objcT35,selTransTbl[25]))(objcT35,selTransTbl[25]))));
return(objcT36=Sequence,(*_imp(objcT36,selTransTbl[24]))(objcT36,selTransTbl[24],aCarrier));
}

# 32 "./valueseq.h"
extern id  ValueSequence;

# 210 "dictnary.m"
static id i_Dictionary_eachValue(struct Dictionary_PRIVATE *self,SEL _cmd)
{
id objcT37,objcT38,objcT39;

# 212 "dictnary.m"
id aCarrier=(objcT37=ValueSequence,(*_imp(objcT37,selTransTbl[24]))(objcT37,selTransTbl[24],(objcT38=self->associations,(*_imp(objcT38,selTransTbl[25]))(objcT38,selTransTbl[25]))));
return(objcT39=Sequence,(*_imp(objcT39,selTransTbl[24]))(objcT39,selTransTbl[24],aCarrier));
}

# 28 "./notfound.h"
extern id  NotFound;

# 222 "dictnary.m"
static id i_Dictionary_removeKey_(struct Dictionary_PRIVATE *self,SEL _cmd,id key)
{
id objcT40,objcT41;

# 224 "dictnary.m"
id assoc,v;
if((assoc=(objcT40=(objcT41=(id)self,(*_imp(objcT41,selTransTbl[15]))(objcT41,selTransTbl[15])),(*_imp(objcT40,selTransTbl[26]))(objcT40,selTransTbl[26],key))))
{
id objcT42,objcT43;

# 227 "dictnary.m"
v=(objcT42=assoc,(*_imp(objcT42,selTransTbl[17]))(objcT42,selTransTbl[17]));

assoc=(objcT43=assoc,(*_imp(objcT43,selTransTbl[8]))(objcT43,selTransTbl[8]));

return v;
}
else
{
id objcT44;

# 235 "dictnary.m"
(objcT44=NotFound,(*_imp(objcT44,selTransTbl[27]))(objcT44,selTransTbl[27]));
return(id)0;
}
}

static id i_Dictionary_removeKey_ifAbsent_(struct Dictionary_PRIVATE *self,SEL _cmd,id key,id aBlock)
{
id objcT45,objcT46;

# 242 "dictnary.m"
id assoc,v;
if((assoc=(objcT45=(objcT46=(id)self,(*_imp(objcT46,selTransTbl[15]))(objcT46,selTransTbl[15])),(*_imp(objcT45,selTransTbl[26]))(objcT45,selTransTbl[26],key))))
{
id objcT47,objcT48;

# 245 "dictnary.m"
v=(objcT47=assoc,(*_imp(objcT47,selTransTbl[17]))(objcT47,selTransTbl[17]));

assoc=(objcT48=assoc,(*_imp(objcT48,selTransTbl[8]))(objcT48,selTransTbl[8]));

return v;
}
else
{
id objcT49;

# 253 "dictnary.m"
return(objcT49=aBlock,(*_imp(objcT49,selTransTbl[17]))(objcT49,selTransTbl[17]));
}
}

# 265 "dictnary.m"
static id i_Dictionary_keysDo_(struct Dictionary_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT50,objcT51,objcT52,objcT53;

# 267 "dictnary.m"
id aKey;
id keys=(objcT50=(id)self,(*_imp(objcT50,selTransTbl[28]))(objcT50,selTransTbl[28]));

while((aKey=(objcT51=keys,(*_imp(objcT51,selTransTbl[29]))(objcT51,selTransTbl[29]))))
(objcT52=aBlock,(*_imp(objcT52,selTransTbl[22]))(objcT52,selTransTbl[22],aKey));

keys=(objcT53=keys,(*_imp(objcT53,selTransTbl[8]))(objcT53,selTransTbl[8]));


return(id)self;
}

# 286 "dictnary.m"
static id i_Dictionary_printOn_(struct Dictionary_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT54;

# 288 "dictnary.m"
(objcT54=self->associations,(*(id(*)(id,SEL,IOD))_imp(objcT54,selTransTbl[30]))(objcT54,selTransTbl[30],aFile));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Dictionary_clsDispatchTbl[] ={
{"new",(id (*)())c_Dictionary_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _Dictionary_nstDispatchTbl[] ={
{"copyAssociations",(id (*)())i_Dictionary_copyAssociations},
{"copy",(id (*)())i_Dictionary_copy},
{"deepCopyAssociations",(id (*)())i_Dictionary_deepCopyAssociations},
{"deepCopy",(id (*)())i_Dictionary_deepCopy},
{"emptyYourself",(id (*)())i_Dictionary_emptyYourself},
{"freeContents",(id (*)())i_Dictionary_freeContents},
{"freeAll",(id (*)())i_Dictionary_freeAll},
{"free",(id (*)())i_Dictionary_free},
{"release",(id (*)())i_Dictionary_release},
{"associations",(id (*)())i_Dictionary_associations},
{"associationsRef",(id (*)())i_Dictionary_associationsRef},
{"size",(id (*)())i_Dictionary_size},
{"isEmpty",(id (*)())i_Dictionary_isEmpty},
{"includesKey:",(id (*)())i_Dictionary_includesKey_},
{"hash",(id (*)())i_Dictionary_hash},
{"isEqual:",(id (*)())i_Dictionary_isEqual_},
{"associationAt:",(id (*)())i_Dictionary_associationAt_},
{"atKey:",(id (*)())i_Dictionary_atKey_},
{"atKey:ifAbsent:",(id (*)())i_Dictionary_atKey_ifAbsent_},
{"atKeySTR:",(id (*)())i_Dictionary_atKeySTR_},
{"atKey:put:",(id (*)())i_Dictionary_atKey_put_},
{"atKeySTR:put:",(id (*)())i_Dictionary_atKeySTR_put_},
{"eachKey",(id (*)())i_Dictionary_eachKey},
{"eachValue",(id (*)())i_Dictionary_eachValue},
{"removeKey:",(id (*)())i_Dictionary_removeKey_},
{"removeKey:ifAbsent:",(id (*)())i_Dictionary_removeKey_ifAbsent_},
{"keysDo:",(id (*)())i_Dictionary_keysDo_},
{"printOn:",(id (*)())i_Dictionary_printOn_},
{(char*)0,(id (*)())0}
};
id Dictionary = (id)&_Dictionary;
id  *OBJCCLASS_Dictionary(void) { return &Dictionary; }
struct _SHARED  _Dictionary = {
  (id)&__Dictionary,
  (id)&_Object,
  "Dictionary",
  0,
  sizeof(struct Dictionary_PRIVATE),
  28,
  _Dictionary_nstDispatchTbl,
  41,
  &dictnary_modDesc,
  0,
  (id)0,
  &Dictionary,
};
id  OBJCCFUNC_Dictionary(void) { return (id)&_Dictionary; }
id  OBJCCSUPER_Dictionary(void) { return _Dictionary.clsSuper; }
struct _SHARED __Dictionary = {
  (id)&__Object,
  (id)&__Object,
  "Dictionary",
  0,
  sizeof(struct _SHARED),
  1,
  _Dictionary_clsDispatchTbl,
  34,
  &dictnary_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Dictionary(void) { return (id)&__Dictionary; }
id  OBJCMSUPER_Dictionary(void) { return __Dictionary.clsSuper; }
static char *_selTransTbl[] ={
"new",
"associationsRef",
"copy",
"copyAssociations",
"deepCopy",
"deepCopyAssociations",
"freeContents",
"freeAll",
"free",
"notImplemented:",
"size",
"isEmpty",
"associationAt:",
"hash",
"isEqual:",
"associations",
"find:",
"value",
"atKey:",
"str:",
"filter:",
"key:",
"value:",
"atKey:put:",
"over:",
"eachElement",
"remove:",
"signal",
"eachKey",
"next",
"printOn:",
0
};
struct modDescriptor dictnary_modDesc = {
  "dictnary",
  "objc3.3.19",
  0L,
  0,
  0,
  &Dictionary,
  31,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_dictnary(void)
{
  selTransTbl = _selTransTbl;
  return &dictnary_modDesc;
}
int _OBJCPOSTLINK_dictnary = 1;


