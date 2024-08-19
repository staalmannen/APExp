# 1 "def.m"
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
extern struct modDescriptor  *_OBJCBIND_def(void);
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
extern struct modDescriptor def_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

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

# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 28 "./../../include/objpak/set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 22 "./node.h"
extern FILE*gfile;
extern int inlineno;
extern id infilename;
extern int outlineno;
extern char*outfilename;
extern int exitstatus;
extern id loadedmodules;

void gc(char c);
void gextc(void);
void gcom(char*cm);
void gvarlist(id c,char*sp,char*iz);
void gcommalist(id c);
void gs(char*str);
void gf(char*fmt,...);
void gl(int no,char*fn);
void g_otbvars(void);
void gstderr(void);
void gnormal(void);
char*browsepath(char*filename);

void warn(char*fmt,...);
void warnat(id sym,char*fmt,...);
void fatal(char*fmt,...);
void fatalat(id sym,char*fmt,...);
# 22 "./def.h"
extern id curdef;
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./blockxpr.h"
extern id curcompound;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
# 39 "def.m"
id curdef;
# 24 "./def.h"
struct Def_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 26 "./def.h"
id parmdic;
id heapvars;
id parmnames;
id classreferences;
id blockreferences;
id heapvarblocks;};

# 24 "./def.h"
extern id  Def;

# 24 "./def.h"
extern struct _SHARED _Def;
extern struct _SHARED __Def;


# 43 "def.m"
static id i_Def_restype(struct Def_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 45 "def.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
}

static id i_Def_compound(struct Def_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 50 "def.m"
return(objcT1=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],_cmd));
}

static id i_Def_parmnames(struct Def_PRIVATE *self,SEL _cmd)
{
return self->parmnames;
}

# 36 "./../../include/objpak/set.h"
extern id  Set;

# 58 "def.m"
static id i_Def_defheapvar_type_(struct Def_PRIVATE *self,SEL _cmd,id x,id t)
{
id objcT2,objcT3,objcT4,objcT5;

# 60 "def.m"
if( !self->heapvars)self->
heapvars=(objcT2=Set,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
(objcT3=self->heapvars,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3],x));
(objcT4=(objcT5=(id)self,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4])),(*_imp(objcT4,selTransTbl[5]))(objcT4,selTransTbl[5],x,t));
return(id)self;
}

static BOOL i_Def_isfundef(struct Def_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Def_ismethdef(struct Def_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static id i_Def_synth(struct Def_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 79 "def.m"
return(objcT6=(id)self,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]));
}

# 32 "./../../include/objpak/dictnary.h"
extern id  Dictionary;

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 82 "def.m"
static id i_Def_defparm_astype_(struct Def_PRIVATE *self,SEL _cmd,id sym,id aType)
{
id objcT9,objcT10;

# 84 "def.m"
if( !self->parmdic){
id objcT7,objcT8;
self->
# 85 "def.m"
parmdic=(objcT7=Dictionary,(*_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2]));self->
parmnames=(objcT8=OrdCltn,(*_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2]));
}
(objcT9=self->parmdic,(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7],sym,aType));
(objcT10=self->parmnames,(*_imp(objcT10,selTransTbl[3]))(objcT10,selTransTbl[3],sym));
return(id)self;
}

static id i_Def_lookupparm_(struct Def_PRIVATE *self,SEL _cmd,id sym)
{
id objcT11;

# 95 "def.m"
return(self->parmdic)?(objcT11=self->parmdic,(*_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8],sym)):(id)0;
}

static id i_Def_addclassreference_(struct Def_PRIVATE *self,SEL _cmd,id x)
{
id objcT12,objcT13;

# 100 "def.m"
if( !self->classreferences)self->
classreferences=(objcT12=OrdCltn,(*_imp(objcT12,selTransTbl[2]))(objcT12,selTransTbl[2]));
(objcT13=self->classreferences,(*_imp(objcT13,selTransTbl[3]))(objcT13,selTransTbl[3],x));
return(id)self;
}

static id i_Def_addblockreference_(struct Def_PRIVATE *self,SEL _cmd,id x)
{
id objcT14,objcT15;

# 108 "def.m"
if( !self->blockreferences)self->
blockreferences=(objcT14=OrdCltn,(*_imp(objcT14,selTransTbl[2]))(objcT14,selTransTbl[2]));
(objcT15=self->blockreferences,(*_imp(objcT15,selTransTbl[3]))(objcT15,selTransTbl[3],x));
return(id)self;
}

static id i_Def_addheapvarblock_(struct Def_PRIVATE *self,SEL _cmd,id x)
{
id objcT16,objcT17;

# 116 "def.m"
if( !self->heapvarblocks)self->
heapvarblocks=(objcT16=Set,(*_imp(objcT16,selTransTbl[2]))(objcT16,selTransTbl[2]));
(objcT17=self->heapvarblocks,(*_imp(objcT17,selTransTbl[3]))(objcT17,selTransTbl[3],x));
return(id)self;
}

static id i_Def_gen(struct Def_PRIVATE *self,SEL _cmd)
{
gc('\n');
if(self->classreferences){
id objcT18;

# 126 "def.m"
(objcT18=self->classreferences,(*(id(*)(id,SEL,SEL))_imp(objcT18,selTransTbl[9]))(objcT18,selTransTbl[9],selTransTbl[10]));
}
if(self->heapvarblocks){
id objcT19;

# 129 "def.m"
(objcT19=self->heapvarblocks,(*(id(*)(id,SEL,SEL))_imp(objcT19,selTransTbl[9]))(objcT19,selTransTbl[9],selTransTbl[11]));
}
if(self->blockreferences){
id objcT20,objcT21,objcT22;

# 132 "def.m"
int n=(objcT20=self->blockreferences,(*(unsigned(*)(id,SEL))_imp(objcT20,selTransTbl[12]))(objcT20,selTransTbl[12]));

while(n--)
(objcT21=(objcT22=self->blockreferences,(*(id(*)(id,SEL,unsigned))_imp(objcT22,selTransTbl[13]))(objcT22,selTransTbl[13],n)),(*_imp(objcT21,selTransTbl[14]))(objcT21,selTransTbl[14]));
}
return(id)self;
}

static id i_Def_reset(struct Def_PRIVATE *self,SEL _cmd)
{
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _Def_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Def_nstDispatchTbl[] ={
{"restype",(id (*)())i_Def_restype},
{"compound",(id (*)())i_Def_compound},
{"parmnames",(id (*)())i_Def_parmnames},
{"defheapvar:type:",(id (*)())i_Def_defheapvar_type_},
{"isfundef",(id (*)())i_Def_isfundef},
{"ismethdef",(id (*)())i_Def_ismethdef},
{"synth",(id (*)())i_Def_synth},
{"defparm:astype:",(id (*)())i_Def_defparm_astype_},
{"lookupparm:",(id (*)())i_Def_lookupparm_},
{"addclassreference:",(id (*)())i_Def_addclassreference_},
{"addblockreference:",(id (*)())i_Def_addblockreference_},
{"addheapvarblock:",(id (*)())i_Def_addheapvarblock_},
{"gen",(id (*)())i_Def_gen},
{"reset",(id (*)())i_Def_reset},
{(char*)0,(id (*)())0}
};
id Def = (id)&_Def;
id  *OBJCCLASS_Def(void) { return &Def; }
struct _SHARED  _Def = {
  (id)&__Def,
  (id)&_Node,
  "Def",
  0,
  sizeof(struct Def_PRIVATE),
  14,
  _Def_nstDispatchTbl,
  41,
  &def_modDesc,
  0,
  (id)0,
  &Def,
};
id  OBJCCFUNC_Def(void) { return (id)&_Def; }
id  OBJCCSUPER_Def(void) { return _Def.clsSuper; }
struct _SHARED __Def = {
  (id)&__Object,
  (id)&__Node,
  "Def",
  0,
  sizeof(struct _SHARED),
  0,
  _Def_clsDispatchTbl,
  34,
  &def_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Def(void) { return (id)&__Def; }
id  OBJCMSUPER_Def(void) { return __Def.clsSuper; }
static char *_selTransTbl[] ={
"subclassResponsibility:",
"notImplemented:",
"new",
"add:",
"compound",
"defheapvar:type:",
"subclassResponsibility",
"atKey:put:",
"atKey:",
"elementsPerform:",
"genintf",
"genheapvartype",
"size",
"at:",
"genblockfun",
0
};
struct modDescriptor def_modDesc = {
  "def",
  "objc3.3.19",
  0L,
  0,
  0,
  &Def,
  15,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_def(void)
{
  selTransTbl = _selTransTbl;
  return &def_modDesc;
}
int _OBJCPOSTLINK_def = 1;


