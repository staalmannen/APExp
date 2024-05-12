# 1 "stardecl.m"
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
extern struct modDescriptor  *_OBJCBIND_stardecl(void);
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
extern struct modDescriptor stardecl_modDesc;

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
# 22 "./stardecl.h"
struct StarDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./stardecl.h"
id pointer,decl;};

# 22 "./stardecl.h"
extern id  StarDecl;

# 22 "./stardecl.h"
extern struct _SHARED _StarDecl;
extern struct _SHARED __StarDecl;


# 37 "stardecl.m"
static id i_StarDecl_abstrdecl(struct StarDecl_PRIVATE *self,SEL _cmd)
{
if(self->decl){
id objcT0;

# 40 "stardecl.m"
id x=(objcT0=self->decl,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));

if(x){
id objcT1,objcT2,objcT3;

# 43 "stardecl.m"
return(objcT1=(objcT2=(objcT3=StarDecl,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1])),(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],x)),(*_imp(objcT1,selTransTbl[3]))(objcT1,selTransTbl[3],self->pointer));
}else{
return self->pointer;
}
}else{
return self->pointer;
}
}

static id i_StarDecl_pointer_(struct StarDecl_PRIVATE *self,SEL _cmd,id aPointer)
{self->
pointer=aPointer;
return(id)self;
}

static id i_StarDecl_decl_(struct StarDecl_PRIVATE *self,SEL _cmd,id aDecl)
{self->
decl=aDecl;
return(id)self;
}

static id i_StarDecl_identifier(struct StarDecl_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 66 "stardecl.m"
return(self->decl)?(objcT4=self->decl,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4])):(id)0;
}

static BOOL i_StarDecl_isfunproto(struct StarDecl_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 71 "stardecl.m"
return(self->decl)?(objcT5=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5])):(BOOL)0;
}

static BOOL i_StarDecl_ispointer(struct StarDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_StarDecl_canforward(struct StarDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_StarDecl_isscalartype(struct StarDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_StarDecl_hide_rename_(struct StarDecl_PRIVATE *self,SEL _cmd,id x,id y)
{
id objcT6;

# 91 "stardecl.m"
if(self->decl)
(objcT6=self->decl,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6],x,y));
return(id)self;
}

static id i_StarDecl_star(struct StarDecl_PRIVATE *self,SEL _cmd)
{
if(self->decl){
id objcT7,objcT8,objcT9;

# 99 "stardecl.m"
return(objcT7=(objcT8=(id)self,(*_imp(objcT8,selTransTbl[7]))(objcT8,selTransTbl[7])),(*_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2],(objcT9=self->decl,(*_imp(objcT9,selTransTbl[8]))(objcT9,selTransTbl[8]))));
}else{
id objcT10,objcT11,objcT12;

# 101 "stardecl.m"
id p=(objcT10=self->pointer,(*_imp(objcT10,selTransTbl[8]))(objcT10,selTransTbl[8]));

return(p)?(objcT11=(objcT12=(id)self,(*_imp(objcT12,selTransTbl[7]))(objcT12,selTransTbl[7])),(*_imp(objcT11,selTransTbl[3]))(objcT11,selTransTbl[3],p)):(id)0;
}
}

static id i_StarDecl_funcall(struct StarDecl_PRIVATE *self,SEL _cmd)
{
if(self->decl){
id objcT13,objcT14,objcT15,objcT16,objcT17;

# 110 "stardecl.m"
id p=(objcT13=self->decl,(*_imp(objcT13,selTransTbl[9]))(objcT13,selTransTbl[9]));

if(p)
return(objcT14=(objcT15=(id)self,(*_imp(objcT15,selTransTbl[7]))(objcT15,selTransTbl[7])),(*_imp(objcT14,selTransTbl[2]))(objcT14,selTransTbl[2],p));
if(self->pointer)
return(objcT16=(objcT17=(id)self,(*_imp(objcT17,selTransTbl[7]))(objcT17,selTransTbl[7])),(*_imp(objcT16,selTransTbl[2]))(objcT16,selTransTbl[2],(id)0));
return(id)0;
}else{
return(id)0;
}
}

static id i_StarDecl_gen(struct StarDecl_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19;

# 124 "stardecl.m"
(objcT18=self->pointer,(*_imp(objcT18,selTransTbl[10]))(objcT18,selTransTbl[10]));
if(self->decl)
(objcT19=self->decl,(*_imp(objcT19,selTransTbl[10]))(objcT19,selTransTbl[10]));
return(id)self;
}

static id i_StarDecl_gendef_(struct StarDecl_PRIVATE *self,SEL _cmd,id sym)
{
if(self->decl){
id objcT20,objcT21;

# 133 "stardecl.m"
(objcT20=self->pointer,(*_imp(objcT20,selTransTbl[10]))(objcT20,selTransTbl[10]));
(objcT21=self->decl,(*_imp(objcT21,selTransTbl[11]))(objcT21,selTransTbl[11],sym));
}else{
id objcT22;

# 136 "stardecl.m"
(objcT22=self->pointer,(*_imp(objcT22,selTransTbl[11]))(objcT22,selTransTbl[11],sym));
}
return(id)self;
}

static id i_StarDecl_synth(struct StarDecl_PRIVATE *self,SEL _cmd)
{
id objcT23;

# 143 "stardecl.m"
if(self->decl)
(objcT23=self->decl,(*_imp(objcT23,selTransTbl[12]))(objcT23,selTransTbl[12]));
return(id)self;
}

static id i_StarDecl_st80(struct StarDecl_PRIVATE *self,SEL _cmd)
{
id objcT24;

# 150 "stardecl.m"
if(self->decl)
(objcT24=self->decl,(*_imp(objcT24,selTransTbl[13]))(objcT24,selTransTbl[13]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _StarDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _StarDecl_nstDispatchTbl[] ={
{"abstrdecl",(id (*)())i_StarDecl_abstrdecl},
{"pointer:",(id (*)())i_StarDecl_pointer_},
{"decl:",(id (*)())i_StarDecl_decl_},
{"identifier",(id (*)())i_StarDecl_identifier},
{"isfunproto",(id (*)())i_StarDecl_isfunproto},
{"ispointer",(id (*)())i_StarDecl_ispointer},
{"canforward",(id (*)())i_StarDecl_canforward},
{"isscalartype",(id (*)())i_StarDecl_isscalartype},
{"hide:rename:",(id (*)())i_StarDecl_hide_rename_},
{"star",(id (*)())i_StarDecl_star},
{"funcall",(id (*)())i_StarDecl_funcall},
{"gen",(id (*)())i_StarDecl_gen},
{"gendef:",(id (*)())i_StarDecl_gendef_},
{"synth",(id (*)())i_StarDecl_synth},
{"st80",(id (*)())i_StarDecl_st80},
{(char*)0,(id (*)())0}
};
id StarDecl = (id)&_StarDecl;
id  *OBJCCLASS_StarDecl(void) { return &StarDecl; }
struct _SHARED  _StarDecl = {
  (id)&__StarDecl,
  (id)&_Decl,
  "StarDecl",
  0,
  sizeof(struct StarDecl_PRIVATE),
  15,
  _StarDecl_nstDispatchTbl,
  41,
  &stardecl_modDesc,
  0,
  (id)0,
  &StarDecl,
};
id  OBJCCFUNC_StarDecl(void) { return (id)&_StarDecl; }
id  OBJCCSUPER_StarDecl(void) { return _StarDecl.clsSuper; }
struct _SHARED __StarDecl = {
  (id)&__Object,
  (id)&__Decl,
  "StarDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _StarDecl_clsDispatchTbl,
  34,
  &stardecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_StarDecl(void) { return (id)&__StarDecl; }
id  OBJCMSUPER_StarDecl(void) { return __StarDecl.clsSuper; }
static char *_selTransTbl[] ={
"abstrdecl",
"new",
"decl:",
"pointer:",
"identifier",
"isfunproto",
"hide:rename:",
"copy",
"star",
"funcall",
"gen",
"gendef:",
"synth",
"st80",
0
};
struct modDescriptor stardecl_modDesc = {
  "stardecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &StarDecl,
  14,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_stardecl(void)
{
  selTransTbl = _selTransTbl;
  return &stardecl_modDesc;
}
int _OBJCPOSTLINK_stardecl = 1;


