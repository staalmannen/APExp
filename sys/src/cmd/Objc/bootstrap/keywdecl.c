# 1 "keywdecl.m"
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
extern struct modDescriptor  *_OBJCBIND_keywdecl(void);
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
extern struct modDescriptor keywdecl_modDesc;

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

# 32 "./../../include/objpak/ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
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
# 22 "./type.h"
extern id t_unknown;
extern id t_void;
extern id t_char;
extern id t_bool;
extern id t_int;
extern id t_long;
extern id t_uns;
extern id t_double;
extern id t_str;
extern id t_sel;
extern id t_id;
# 22 "./def.h"
extern id curdef;
# 22 "./keywdecl.h"
struct KeywDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./keywdecl.h"
id keyw,cast,arg;
id hide;};

# 22 "./keywdecl.h"
extern id  KeywDecl;

# 22 "./keywdecl.h"
extern struct _SHARED _KeywDecl;
extern struct _SHARED __KeywDecl;


# 40 "keywdecl.m"
static id i_KeywDecl_identifier(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
return self->arg;
}

static id i_KeywDecl_keyw(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
return self->keyw;
}

static id i_KeywDecl_keyw_(struct KeywDecl_PRIVATE *self,SEL _cmd,id sel)
{self->
keyw=sel;
return(id)self;
}

static id i_KeywDecl_cast(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
return self->cast;
}

static id i_KeywDecl_cast_(struct KeywDecl_PRIVATE *self,SEL _cmd,id c)
{self->
cast=c;
return(id)self;
}

static unsigned i_KeywDecl_typehash(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 69 "keywdecl.m"
return(self->cast)?(objcT0=self->cast,(*(unsigned(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0])):(objcT1=t_id,(*(unsigned(*)(id,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
}

static BOOL i_KeywDecl_typeEqual_(struct KeywDecl_PRIVATE *self,SEL _cmd,id x)
{
id objcT2,objcT3;

# 74 "keywdecl.m"
id a=self->cast;
id b=(objcT2=x,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));

if( !a)
a=t_id;
if( !b)
b=t_id;
return(objcT3=a,(*(BOOL(*)(id,SEL,id))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],b));
}

static id i_KeywDecl_hide_rename_(struct KeywDecl_PRIVATE *self,SEL _cmd,id x,id y)
{
id objcT4;

# 86 "keywdecl.m"
if((objcT4=self->arg,(*(BOOL(*)(id,SEL,id))_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],x)))self->
hide=y;
return(id)self;
}

static id i_KeywDecl_arg_(struct KeywDecl_PRIVATE *self,SEL _cmd,id a)
{self->
arg=a;
return(id)self;
}

static id i_KeywDecl_selcons_(struct KeywDecl_PRIVATE *self,SEL _cmd,id sel)
{
id objcT5,objcT6;

# 99 "keywdecl.m"
if(self->keyw)
(objcT5=sel,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],self->keyw));
(objcT6=sel,(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
return(id)self;
}

static id i_KeywDecl_genparm(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id x=(self->hide)?self->hide:self->arg;

if(self->cast){
id objcT7;

# 110 "keywdecl.m"
(objcT7=self->cast,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],x));
}else{
id objcT8;

# 112 "keywdecl.m"
(objcT8=t_id,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5],x));
}
return(id)self;
}

static id i_KeywDecl_gencommaparm(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 119 "keywdecl.m"
gc(',');
return(objcT9=(id)self,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
}

static BOOL i_KeywDecl_canforward(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 125 "keywdecl.m"
return(self->cast)?(objcT10=self->cast,(*(BOOL(*)(id,SEL))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7])):(BOOL)1;
}

static BOOL i_KeywDecl_isid(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 130 "keywdecl.m"
return(self->cast)?(objcT11=self->cast,(*(BOOL(*)(id,SEL))_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8])):(BOOL)1;
}

static BOOL i_KeywDecl_isselptr(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT12;

# 135 "keywdecl.m"
return(self->cast)?(objcT12=self->cast,(*(BOOL(*)(id,SEL))_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9])):(BOOL)1;
}

static id i_KeywDecl_gendef_(struct KeywDecl_PRIVATE *self,SEL _cmd,id sym)
{
if(self->cast){
id objcT13;

# 141 "keywdecl.m"
(objcT13=self->cast,(*_imp(objcT13,selTransTbl[5]))(objcT13,selTransTbl[5],sym));
}else{
id objcT14;

# 143 "keywdecl.m"
gs("id");
if(sym)
gs((objcT14=sym,(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[10]))(objcT14,selTransTbl[10])));
}
return(id)self;
}

static id i_KeywDecl_gendisparg(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT15;

# 152 "keywdecl.m"
gs("args->");
(objcT15=self->arg,(*_imp(objcT15,selTransTbl[11]))(objcT15,selTransTbl[11]));
return(id)self;
}

static id i_KeywDecl_gendispargsintostruct(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT16,objcT17;

# 159 "keywdecl.m"
gs("args.");
(objcT16=self->arg,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11]));
gc('=');
(objcT17=self->arg,(*_imp(objcT17,selTransTbl[11]))(objcT17,selTransTbl[11]));
gc(';');
gc('\n');
return(id)self;
}

static id i_KeywDecl_gen(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_KeywDecl_synth(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 175 "keywdecl.m"
(void)0;
(void)0;
(objcT18=curdef,(*_imp(objcT18,selTransTbl[12]))(objcT18,selTransTbl[12],self->arg,(self->cast)?self->cast:t_id));
return(id)self;
}

static id i_KeywDecl_st80(struct KeywDecl_PRIVATE *self,SEL _cmd)
{
id objcT19,objcT20;

# 183 "keywdecl.m"
if(self->keyw)
(objcT19=self->keyw,(*_imp(objcT19,selTransTbl[13]))(objcT19,selTransTbl[13]));
gc(':');
(objcT20=self->arg,(*_imp(objcT20,selTransTbl[13]))(objcT20,selTransTbl[13]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _KeywDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _KeywDecl_nstDispatchTbl[] ={
{"identifier",(id (*)())i_KeywDecl_identifier},
{"keyw",(id (*)())i_KeywDecl_keyw},
{"keyw:",(id (*)())i_KeywDecl_keyw_},
{"cast",(id (*)())i_KeywDecl_cast},
{"cast:",(id (*)())i_KeywDecl_cast_},
{"typehash",(id (*)())i_KeywDecl_typehash},
{"typeEqual:",(id (*)())i_KeywDecl_typeEqual_},
{"hide:rename:",(id (*)())i_KeywDecl_hide_rename_},
{"arg:",(id (*)())i_KeywDecl_arg_},
{"selcons:",(id (*)())i_KeywDecl_selcons_},
{"genparm",(id (*)())i_KeywDecl_genparm},
{"gencommaparm",(id (*)())i_KeywDecl_gencommaparm},
{"canforward",(id (*)())i_KeywDecl_canforward},
{"isid",(id (*)())i_KeywDecl_isid},
{"isselptr",(id (*)())i_KeywDecl_isselptr},
{"gendef:",(id (*)())i_KeywDecl_gendef_},
{"gendisparg",(id (*)())i_KeywDecl_gendisparg},
{"gendispargsintostruct",(id (*)())i_KeywDecl_gendispargsintostruct},
{"gen",(id (*)())i_KeywDecl_gen},
{"synth",(id (*)())i_KeywDecl_synth},
{"st80",(id (*)())i_KeywDecl_st80},
{(char*)0,(id (*)())0}
};
id KeywDecl = (id)&_KeywDecl;
id  *OBJCCLASS_KeywDecl(void) { return &KeywDecl; }
struct _SHARED  _KeywDecl = {
  (id)&__KeywDecl,
  (id)&_Decl,
  "KeywDecl",
  0,
  sizeof(struct KeywDecl_PRIVATE),
  21,
  _KeywDecl_nstDispatchTbl,
  41,
  &keywdecl_modDesc,
  0,
  (id)0,
  &KeywDecl,
};
id  OBJCCFUNC_KeywDecl(void) { return (id)&_KeywDecl; }
id  OBJCCSUPER_KeywDecl(void) { return _KeywDecl.clsSuper; }
struct _SHARED __KeywDecl = {
  (id)&__Object,
  (id)&__Decl,
  "KeywDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _KeywDecl_clsDispatchTbl,
  34,
  &keywdecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_KeywDecl(void) { return (id)&__KeywDecl; }
id  OBJCMSUPER_KeywDecl(void) { return __KeywDecl.clsSuper; }
static char *_selTransTbl[] ={
"hash",
"cast",
"isEqual:",
"add:",
"addcol",
"gendef:",
"genparm",
"canforward",
"isid",
"isselptr",
"str",
"gen",
"defparm:astype:",
"st80",
0
};
struct modDescriptor keywdecl_modDesc = {
  "keywdecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &KeywDecl,
  14,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_keywdecl(void)
{
  selTransTbl = _selTransTbl;
  return &keywdecl_modDesc;
}
int _OBJCPOSTLINK_keywdecl = 1;


