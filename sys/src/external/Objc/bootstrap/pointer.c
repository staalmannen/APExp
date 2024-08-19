# 1 "pointer.m"
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
extern struct modDescriptor  *_OBJCBIND_pointer(void);
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
extern struct modDescriptor pointer_modDesc;

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
# 22 "./pointer.h"
struct Pointer_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./pointer.h"
id specs,pointer;};

# 22 "./pointer.h"
extern id  Pointer;

# 22 "./pointer.h"
extern struct _SHARED _Pointer;
extern struct _SHARED __Pointer;


# 37 "pointer.m"
static id i_Pointer_pointer(struct Pointer_PRIVATE *self,SEL _cmd)
{
return self->pointer;
}

static int i_Pointer_numpointers(struct Pointer_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 44 "pointer.m"
id e,p;
int h=1;

for(e=(id)self;(p=(objcT0=e,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0])));e=p)
h++;
return h;
}

static id i_Pointer_abstrdecl(struct Pointer_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static unsigned i_Pointer_hash(struct Pointer_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 59 "pointer.m"
return(objcT1=(id)self,(*(int(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static BOOL i_Pointer_isEqual_(struct Pointer_PRIVATE *self,SEL _cmd,id x)
{
id objcT2,objcT3;

# 64 "pointer.m"
return(objcT2=(id)self,(*(int(*)(id,SEL))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]))==(objcT3=x,(*(int(*)(id,SEL))_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1]));
}

static BOOL i_Pointer_ispointer(struct Pointer_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_Pointer_canforward(struct Pointer_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_Pointer_isscalartype(struct Pointer_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_Pointer_specs_(struct Pointer_PRIVATE *self,SEL _cmd,id aList)
{self->
specs=aList;
return(id)self;
}

static id i_Pointer_hide_rename_(struct Pointer_PRIVATE *self,SEL _cmd,id x,id y)
{
return(id)self;
}

static id i_Pointer_pointer_(struct Pointer_PRIVATE *self,SEL _cmd,id aDecl)
{
(void)0;self->
pointer=aDecl;
return(id)self;
}

static id i_Pointer_star(struct Pointer_PRIVATE *self,SEL _cmd)
{
if(self->pointer){
id objcT4,objcT5,objcT6;

# 103 "pointer.m"
return(objcT4=(objcT5=(id)self,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2])),(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3],(objcT6=self->pointer,(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]))));
}else{
return(id)0;
}
}

static id i_Pointer_identifier(struct Pointer_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static id i_Pointer_gen(struct Pointer_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;

# 116 "pointer.m"
gc('*');
if(self->specs)
(objcT7=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],selTransTbl[6]));
if(self->pointer)
(objcT8=self->pointer,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
return(id)self;
}

static id i_Pointer_gendef_(struct Pointer_PRIVATE *self,SEL _cmd,id sym)
{
id objcT9;

# 126 "pointer.m"
gc('*');
if(self->specs)
(objcT9=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5],selTransTbl[6]));
if(self->pointer){
id objcT10;

# 130 "pointer.m"
(objcT10=self->pointer,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7],sym));
}else{
id objcT11;

# 132 "pointer.m"
if(sym)
(objcT11=sym,(*_imp(objcT11,selTransTbl[6]))(objcT11,selTransTbl[6]));
}
return(id)self;
}

static id i_Pointer_synth(struct Pointer_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Pointer_st80(struct Pointer_PRIVATE *self,SEL _cmd)
{
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _Pointer_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Pointer_nstDispatchTbl[] ={
{"pointer",(id (*)())i_Pointer_pointer},
{"numpointers",(id (*)())i_Pointer_numpointers},
{"abstrdecl",(id (*)())i_Pointer_abstrdecl},
{"hash",(id (*)())i_Pointer_hash},
{"isEqual:",(id (*)())i_Pointer_isEqual_},
{"ispointer",(id (*)())i_Pointer_ispointer},
{"canforward",(id (*)())i_Pointer_canforward},
{"isscalartype",(id (*)())i_Pointer_isscalartype},
{"specs:",(id (*)())i_Pointer_specs_},
{"hide:rename:",(id (*)())i_Pointer_hide_rename_},
{"pointer:",(id (*)())i_Pointer_pointer_},
{"star",(id (*)())i_Pointer_star},
{"identifier",(id (*)())i_Pointer_identifier},
{"gen",(id (*)())i_Pointer_gen},
{"gendef:",(id (*)())i_Pointer_gendef_},
{"synth",(id (*)())i_Pointer_synth},
{"st80",(id (*)())i_Pointer_st80},
{(char*)0,(id (*)())0}
};
id Pointer = (id)&_Pointer;
id  *OBJCCLASS_Pointer(void) { return &Pointer; }
struct _SHARED  _Pointer = {
  (id)&__Pointer,
  (id)&_Decl,
  "Pointer",
  0,
  sizeof(struct Pointer_PRIVATE),
  17,
  _Pointer_nstDispatchTbl,
  41,
  &pointer_modDesc,
  0,
  (id)0,
  &Pointer,
};
id  OBJCCFUNC_Pointer(void) { return (id)&_Pointer; }
id  OBJCCSUPER_Pointer(void) { return _Pointer.clsSuper; }
struct _SHARED __Pointer = {
  (id)&__Object,
  (id)&__Decl,
  "Pointer",
  0,
  sizeof(struct _SHARED),
  0,
  _Pointer_clsDispatchTbl,
  34,
  &pointer_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Pointer(void) { return (id)&__Pointer; }
id  OBJCMSUPER_Pointer(void) { return __Pointer.clsSuper; }
static char *_selTransTbl[] ={
"pointer",
"numpointers",
"copy",
"pointer:",
"star",
"elementsPerform:",
"gen",
"gendef:",
0
};
struct modDescriptor pointer_modDesc = {
  "pointer",
  "objc3.3.19",
  0L,
  0,
  0,
  &Pointer,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_pointer(void)
{
  selTransTbl = _selTransTbl;
  return &pointer_modDesc;
}
int _OBJCPOSTLINK_pointer = 1;


