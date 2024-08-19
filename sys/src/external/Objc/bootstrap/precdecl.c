# 1 "precdecl.m"
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
extern struct modDescriptor  *_OBJCBIND_precdecl(void);
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
extern struct modDescriptor precdecl_modDesc;

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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./precdecl.h"
struct PrecDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./precdecl.h"
id decl,typequals;};

# 22 "./precdecl.h"
extern id  PrecDecl;

# 22 "./precdecl.h"
extern struct _SHARED _PrecDecl;
extern struct _SHARED __PrecDecl;


# 39 "precdecl.m"
static id i_PrecDecl_abstrdecl(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
if(self->decl){
id objcT0,objcT1,objcT2;

# 42 "precdecl.m"
id x=(objcT0=self->decl,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));

if(x)
return(objcT1=(objcT2=PrecDecl,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1])),(*_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],x));
}
return(id)0;
}

static id i_PrecDecl_decl_(struct PrecDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{
(void)0;self->
decl=aRcvr;
return(id)self;
}

static id i_PrecDecl_typequals_(struct PrecDecl_PRIVATE *self,SEL _cmd,id aList)
{
(void)0;self->
typequals=aList;
return(id)self;
}

static id i_PrecDecl_identifier(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 66 "precdecl.m"
return(self->decl)?(objcT3=self->decl,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3])):(id)0;
}

static BOOL i_PrecDecl_isfunproto(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 71 "precdecl.m"
return(self->decl)?(objcT4=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4])):(BOOL)0;
}

static id i_PrecDecl_hide_rename_(struct PrecDecl_PRIVATE *self,SEL _cmd,id x,id y)
{
id objcT5;

# 76 "precdecl.m"
if(self->decl)
(objcT5=self->decl,(*_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5],x,y));
return(id)self;
}

static id i_PrecDecl_star(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
id objcT6,objcT7,objcT8;

# 83 "precdecl.m"
id r=(objcT6=self->decl,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]));

return(r)?(objcT7=(objcT8=(id)self,(*_imp(objcT8,selTransTbl[7]))(objcT8,selTransTbl[7])),(*_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2],r)):(id)0;
}

static id i_PrecDecl_funcall(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10,objcT11;

# 90 "precdecl.m"
id r=(objcT9=self->decl,(*_imp(objcT9,selTransTbl[8]))(objcT9,selTransTbl[8]));

return(r)?(objcT10=(objcT11=(id)self,(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7])),(*_imp(objcT10,selTransTbl[2]))(objcT10,selTransTbl[2],r)):(id)0;
}

static id i_PrecDecl_synth(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
id objcT12,objcT13;

# 97 "precdecl.m"
if(self->typequals)
(objcT12=self->typequals,(*(id(*)(id,SEL,SEL))_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9],_cmd));
if(self->decl)
(objcT13=self->decl,(*_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10]));
return(id)self;
}

static id i_PrecDecl_gendef_(struct PrecDecl_PRIVATE *self,SEL _cmd,id sym)
{
id objcT14,objcT15;

# 106 "precdecl.m"
gc('(');
if(self->typequals)
(objcT14=self->typequals,(*(id(*)(id,SEL,SEL,id))_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11],_cmd,sym));
if(self->decl)
(objcT15=self->decl,(*_imp(objcT15,selTransTbl[12]))(objcT15,selTransTbl[12],sym));
gc(')');
return(id)self;
}

static id i_PrecDecl_gen(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
id objcT16,objcT17;

# 117 "precdecl.m"
gc('(');
if(self->typequals)
(objcT16=self->typequals,(*(id(*)(id,SEL,SEL))_imp(objcT16,selTransTbl[9]))(objcT16,selTransTbl[9],_cmd));
if(self->decl)
(objcT17=self->decl,(*_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13]));
gc(')');
return(id)self;
}

static id i_PrecDecl_st80(struct PrecDecl_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 128 "precdecl.m"
gc('(');
if(self->decl)
(objcT18=self->decl,(*_imp(objcT18,selTransTbl[14]))(objcT18,selTransTbl[14]));
gc(')');
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _PrecDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _PrecDecl_nstDispatchTbl[] ={
{"abstrdecl",(id (*)())i_PrecDecl_abstrdecl},
{"decl:",(id (*)())i_PrecDecl_decl_},
{"typequals:",(id (*)())i_PrecDecl_typequals_},
{"identifier",(id (*)())i_PrecDecl_identifier},
{"isfunproto",(id (*)())i_PrecDecl_isfunproto},
{"hide:rename:",(id (*)())i_PrecDecl_hide_rename_},
{"star",(id (*)())i_PrecDecl_star},
{"funcall",(id (*)())i_PrecDecl_funcall},
{"synth",(id (*)())i_PrecDecl_synth},
{"gendef:",(id (*)())i_PrecDecl_gendef_},
{"gen",(id (*)())i_PrecDecl_gen},
{"st80",(id (*)())i_PrecDecl_st80},
{(char*)0,(id (*)())0}
};
id PrecDecl = (id)&_PrecDecl;
id  *OBJCCLASS_PrecDecl(void) { return &PrecDecl; }
struct _SHARED  _PrecDecl = {
  (id)&__PrecDecl,
  (id)&_Decl,
  "PrecDecl",
  0,
  sizeof(struct PrecDecl_PRIVATE),
  12,
  _PrecDecl_nstDispatchTbl,
  41,
  &precdecl_modDesc,
  0,
  (id)0,
  &PrecDecl,
};
id  OBJCCFUNC_PrecDecl(void) { return (id)&_PrecDecl; }
id  OBJCCSUPER_PrecDecl(void) { return _PrecDecl.clsSuper; }
struct _SHARED __PrecDecl = {
  (id)&__Object,
  (id)&__Decl,
  "PrecDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _PrecDecl_clsDispatchTbl,
  34,
  &precdecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_PrecDecl(void) { return (id)&__PrecDecl; }
id  OBJCMSUPER_PrecDecl(void) { return __PrecDecl.clsSuper; }
static char *_selTransTbl[] ={
"abstrdecl",
"new",
"decl:",
"identifier",
"isfunproto",
"hide:rename:",
"star",
"copy",
"funcall",
"elementsPerform:",
"synth",
"elementsPerform:with:",
"gendef:",
"gen",
"st80",
0
};
struct modDescriptor precdecl_modDesc = {
  "precdecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &PrecDecl,
  15,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_precdecl(void)
{
  selTransTbl = _selTransTbl;
  return &precdecl_modDesc;
}
int _OBJCPOSTLINK_precdecl = 1;


