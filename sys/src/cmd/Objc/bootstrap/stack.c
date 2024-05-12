# 1 "stack.m"
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
extern struct modDescriptor  *_OBJCBIND_stack(void);
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
extern struct modDescriptor stack_modDesc;

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

# 28 "./set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 31 "./ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 38 "./../../include/objcrt/Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 28 "./stack.h"
struct Stack_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 30 "./stack.h"
id contents;};

# 28 "./stack.h"
extern id  Stack;

# 28 "./stack.h"
extern struct _SHARED _Stack;
extern struct _SHARED __Stack;


# 42 "stack.m"
static id c_Stack_new(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 44 "stack.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(16)));
}

static id i_Stack_contents_(struct Stack_PRIVATE *self,SEL _cmd,id anObject)
{self->
contents=anObject;
return(id)self;
}

static id i_Stack_contents(struct Stack_PRIVATE *self,SEL _cmd)
{
return self->contents;
}

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 58 "stack.m"
static id c_Stack_new_(struct Stack_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT1,objcT2,objcT3;

# 60 "stack.m"
return(objcT1=(objcT2=__Stack.clsSuper,(*_impSuper(objcT2,selTransTbl[1]))((id)self,selTransTbl[1])),(*_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],(objcT3=OrdCltn,(*(id(*)(id,SEL,unsigned))_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0],n))));
}

static id i_Stack_copy(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;

# 65 "stack.m"
id aCopy=(objcT4=_Stack.clsSuper,(*_impSuper(objcT4,selTransTbl[3]))((id)self,selTransTbl[3]));self->
contents=(objcT5=self->contents,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3]));
return aCopy;
}

static id i_Stack_deepCopy(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7;


id aCopy=(objcT6=_Stack.clsSuper,(*_impSuper(objcT6,selTransTbl[3]))((id)self,selTransTbl[3]));self->
contents=(objcT7=self->contents,(*_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4]));
return aCopy;
}

static id i_Stack_emptyYourself(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 82 "stack.m"
(objcT8=self->contents,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
return(id)self;
}

static id i_Stack_freeContents(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 88 "stack.m"
(objcT9=self->contents,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
return(id)self;
}

static id i_Stack_free(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11;
self->
# 94 "stack.m"
contents=(objcT10=self->contents,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
return(objcT11=_Stack.clsSuper,(*_impSuper(objcT11,selTransTbl[7]))((id)self,selTransTbl[7]));
}

# 104 "stack.m"
static unsigned i_Stack_size(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT12;

# 106 "stack.m"
return(objcT12=self->contents,(*(unsigned(*)(id,SEL))_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8]));
}

static unsigned i_Stack_depth(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 111 "stack.m"
return(objcT13=self->contents,(*(unsigned(*)(id,SEL))_imp(objcT13,selTransTbl[8]))(objcT13,selTransTbl[8]));
}

static BOOL i_Stack_isEmpty(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT14;

# 116 "stack.m"
return(objcT14=self->contents,(*(BOOL(*)(id,SEL))_imp(objcT14,selTransTbl[9]))(objcT14,selTransTbl[9]));
}

static id i_Stack_eachElement(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT15;

# 121 "stack.m"
return(objcT15=self->contents,(*_imp(objcT15,selTransTbl[10]))(objcT15,selTransTbl[10]));
}

static id i_Stack_topElement(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT16;

# 126 "stack.m"
return(objcT16=self->contents,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11]));
}

# 135 "stack.m"
static id i_Stack_push_(struct Stack_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT17;

# 137 "stack.m"
(objcT17=self->contents,(*_imp(objcT17,selTransTbl[12]))(objcT17,selTransTbl[12],anObject));
return(id)self;
}

static id i_Stack_add_(struct Stack_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT18;

# 143 "stack.m"
(objcT18=self->contents,(*_imp(objcT18,selTransTbl[12]))(objcT18,selTransTbl[12],anObject));
return(id)self;
}

static id i_Stack_pop(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT19;

# 149 "stack.m"
return(objcT19=self->contents,(*_imp(objcT19,selTransTbl[13]))(objcT19,selTransTbl[13]));
}

static id i_Stack_swap(struct Stack_PRIVATE *self,SEL _cmd)
{
id objcT20;

# 154 "stack.m"
unsigned n=(objcT20=self->contents,(*(unsigned(*)(id,SEL))_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8]));

if(n>=2)
{
id objcT21,objcT22,objcT23,objcT24;

# 158 "stack.m"
id anObject=(objcT21=self->contents,(*(id(*)(id,SEL,unsigned))_imp(objcT21,selTransTbl[14]))(objcT21,selTransTbl[14],n-1));
(objcT22=self->contents,(*(id(*)(id,SEL,unsigned,id))_imp(objcT22,selTransTbl[15]))(objcT22,selTransTbl[15],n-1,(objcT23=self->contents,(*(id(*)(id,SEL,unsigned))_imp(objcT23,selTransTbl[14]))(objcT23,selTransTbl[14],n-2))));
(objcT24=self->contents,(*(id(*)(id,SEL,unsigned,id))_imp(objcT24,selTransTbl[15]))(objcT24,selTransTbl[15],n-2,anObject));
return(id)self;
}
else
{
id objcT25;

# 165 "stack.m"
return(objcT25=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT25,selTransTbl[16]))(objcT25,selTransTbl[16],_cmd));
}
}

static id i_Stack_at_(struct Stack_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
id objcT26;

# 171 "stack.m"
unsigned n=(objcT26=self->contents,(*(unsigned(*)(id,SEL))_imp(objcT26,selTransTbl[8]))(objcT26,selTransTbl[8]));
if(anOffset>=n)
{
id objcT27;

# 174 "stack.m"
return(objcT27=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT27,selTransTbl[16]))(objcT27,selTransTbl[16],_cmd));
}
else
{
id objcT28;

# 178 "stack.m"
return(objcT28=self->contents,(*(id(*)(id,SEL,unsigned))_imp(objcT28,selTransTbl[14]))(objcT28,selTransTbl[14],n-1-anOffset));
}
}

static id i_Stack_removeAt_(struct Stack_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
id objcT29;

# 184 "stack.m"
unsigned n=(objcT29=self->contents,(*(unsigned(*)(id,SEL))_imp(objcT29,selTransTbl[8]))(objcT29,selTransTbl[8]));
if(anOffset>=n)
{
id objcT30;

# 187 "stack.m"
return(objcT30=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT30,selTransTbl[16]))(objcT30,selTransTbl[16],_cmd));
}
else
{
id objcT31;

# 191 "stack.m"
return(objcT31=self->contents,(*(id(*)(id,SEL,unsigned))_imp(objcT31,selTransTbl[17]))(objcT31,selTransTbl[17],n-1-anOffset));
}
}

# 201 "stack.m"
static id i_Stack_printOn_(struct Stack_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT32,objcT33,objcT34;

# 203 "stack.m"
(objcT32=(objcT33=(objcT34=(id)self,(*_imp(objcT34,selTransTbl[10]))(objcT34,selTransTbl[10])),(*(id(*)(id,SEL,IOD))_imp(objcT33,selTransTbl[18]))(objcT33,selTransTbl[18],aFile)),(*_imp(objcT32,selTransTbl[7]))(objcT32,selTransTbl[7]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Cltn;
extern struct _SHARED _Cltn;
extern struct _SHARED __Cltn;
static struct _SLT _Stack_clsDispatchTbl[] ={
{"new",(id (*)())c_Stack_new},
{"new:",(id (*)())c_Stack_new_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Stack_nstDispatchTbl[] ={
{"contents:",(id (*)())i_Stack_contents_},
{"contents",(id (*)())i_Stack_contents},
{"copy",(id (*)())i_Stack_copy},
{"deepCopy",(id (*)())i_Stack_deepCopy},
{"emptyYourself",(id (*)())i_Stack_emptyYourself},
{"freeContents",(id (*)())i_Stack_freeContents},
{"free",(id (*)())i_Stack_free},
{"size",(id (*)())i_Stack_size},
{"depth",(id (*)())i_Stack_depth},
{"isEmpty",(id (*)())i_Stack_isEmpty},
{"eachElement",(id (*)())i_Stack_eachElement},
{"topElement",(id (*)())i_Stack_topElement},
{"push:",(id (*)())i_Stack_push_},
{"add:",(id (*)())i_Stack_add_},
{"pop",(id (*)())i_Stack_pop},
{"swap",(id (*)())i_Stack_swap},
{"at:",(id (*)())i_Stack_at_},
{"removeAt:",(id (*)())i_Stack_removeAt_},
{"printOn:",(id (*)())i_Stack_printOn_},
{(char*)0,(id (*)())0}
};
id Stack = (id)&_Stack;
id  *OBJCCLASS_Stack(void) { return &Stack; }
struct _SHARED  _Stack = {
  (id)&__Stack,
  (id)&_Cltn,
  "Stack",
  0,
  sizeof(struct Stack_PRIVATE),
  19,
  _Stack_nstDispatchTbl,
  41,
  &stack_modDesc,
  0,
  (id)0,
  &Stack,
};
id  OBJCCFUNC_Stack(void) { return (id)&_Stack; }
id  OBJCCSUPER_Stack(void) { return _Stack.clsSuper; }
struct _SHARED __Stack = {
  (id)&__Object,
  (id)&__Cltn,
  "Stack",
  0,
  sizeof(struct _SHARED),
  2,
  _Stack_clsDispatchTbl,
  34,
  &stack_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Stack(void) { return (id)&__Stack; }
id  OBJCMSUPER_Stack(void) { return __Stack.clsSuper; }
static char *_selTransTbl[] ={
"new:",
"new",
"contents:",
"copy",
"deepCopy",
"emptyYourself",
"freeContents",
"free",
"size",
"isEmpty",
"eachElement",
"lastElement",
"add:",
"removeLast",
"at:",
"at:put:",
"notImplemented:",
"removeAt:",
"printOn:",
0
};
struct modDescriptor stack_modDesc = {
  "stack",
  "objc3.3.19",
  0L,
  0,
  0,
  &Stack,
  19,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_stack(void)
{
  selTransTbl = _selTransTbl;
  return &stack_modDesc;
}
int _OBJCPOSTLINK_stack = 1;


