# 1 "namedecl.m"
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
extern struct modDescriptor  *_OBJCBIND_namedecl(void);
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
extern struct modDescriptor namedecl_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//string.h"
#include <string.h>

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
# 22 "./symbol.h"
extern id s_void;
extern id s_char;
extern id s_bool;
extern id s_int;
extern id s_uns;
extern id s_long;
extern id s_double;
extern id s_str;
extern id s_sel;
extern id s_newblock;
extern id s_main;
extern id s_objcmain;
extern id s_id;
extern id s_nil;
extern id s_self;
extern id s_cmd;
extern id s_super;
extern id s_type;
extern id s_aFiler;
extern id s_fileIn;
extern id s_fileOut;
extern id s_fileInIdsFrom;
extern id s_fileOutIdsFor;
extern id s_returnval;
extern id s_returnflag;
extern id s_increfs;
extern id s_decrefs;
extern id s_idincref;
extern id s_iddecref;

BOOL istypeword(id sym);
BOOL isbuiltinfun(id sym);
int pragmatoggle(char*s);
void definebuiltintype(char*s);
void definebuiltinfun(char*s);
void definebuiltinvar(char*s);
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
# 22 "./namedecl.h"
struct NameDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./namedecl.h"
id identifier;
id hide;};

# 22 "./namedecl.h"
extern id  NameDecl;

# 22 "./namedecl.h"
extern struct _SHARED _NameDecl;
extern struct _SHARED __NameDecl;


# 39 "namedecl.m"
static id i_NameDecl_abstrdecl(struct NameDecl_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static id i_NameDecl_identifier_(struct NameDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
identifier=aRcvr;
return(id)self;
}

static BOOL i_NameDecl_isEqual_(struct NameDecl_PRIVATE *self,SEL _cmd,id x)
{
id objcT0,objcT1;

# 52 "namedecl.m"
BOOL ok=(BOOL)1;
id y=(objcT0=x,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));

if(self->identifier&&y&& !(objcT1=self->identifier,(*(BOOL(*)(id,SEL,id))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],y)))
ok=(BOOL)0;
if( !self->identifier|| !y)
ok=(self->identifier==y);
return ok;
}

static BOOL i_NameDecl_canforward(struct NameDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_NameDecl_isscalartype(struct NameDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_NameDecl_gen(struct NameDecl_PRIVATE *self,SEL _cmd)
{
if(self->hide){
id objcT2;

# 75 "namedecl.m"
(objcT2=self->hide,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
}else{
id objcT3;

# 77 "namedecl.m"
(objcT3=self->identifier,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
}
return(id)self;
}

static id i_NameDecl_hide_rename_(struct NameDecl_PRIVATE *self,SEL _cmd,id x,id y)
{
id objcT4;

# 84 "namedecl.m"
if((objcT4=self->identifier,(*(BOOL(*)(id,SEL,id))_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1],x))){
id objcT5,objcT6,objcT7,objcT8;

# 85 "namedecl.m"
(objcT5=y,(*(id(*)(id,SEL,int))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],(objcT6=self->identifier,(*(int(*)(id,SEL))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]))));
(objcT7=y,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],(objcT8=self->identifier,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]))));self->
hide=y;
}
return(id)self;
}

static id i_NameDecl_identifier(struct NameDecl_PRIVATE *self,SEL _cmd)
{
return self->identifier;
}

static id i_NameDecl_gendef_(struct NameDecl_PRIVATE *self,SEL _cmd,id sym)
{
id objcT9;

# 99 "namedecl.m"
if(sym)
(objcT9=sym,(*_imp(objcT9,selTransTbl[2]))(objcT9,selTransTbl[2]));
return(id)self;
}

static id i_NameDecl_synth(struct NameDecl_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_NameDecl_st80(struct NameDecl_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 111 "namedecl.m"
(objcT10=self->identifier,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _NameDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _NameDecl_nstDispatchTbl[] ={
{"abstrdecl",(id (*)())i_NameDecl_abstrdecl},
{"identifier:",(id (*)())i_NameDecl_identifier_},
{"isEqual:",(id (*)())i_NameDecl_isEqual_},
{"canforward",(id (*)())i_NameDecl_canforward},
{"isscalartype",(id (*)())i_NameDecl_isscalartype},
{"gen",(id (*)())i_NameDecl_gen},
{"hide:rename:",(id (*)())i_NameDecl_hide_rename_},
{"identifier",(id (*)())i_NameDecl_identifier},
{"gendef:",(id (*)())i_NameDecl_gendef_},
{"synth",(id (*)())i_NameDecl_synth},
{"st80",(id (*)())i_NameDecl_st80},
{(char*)0,(id (*)())0}
};
id NameDecl = (id)&_NameDecl;
id  *OBJCCLASS_NameDecl(void) { return &NameDecl; }
struct _SHARED  _NameDecl = {
  (id)&__NameDecl,
  (id)&_Decl,
  "NameDecl",
  0,
  sizeof(struct NameDecl_PRIVATE),
  11,
  _NameDecl_nstDispatchTbl,
  41,
  &namedecl_modDesc,
  0,
  (id)0,
  &NameDecl,
};
id  OBJCCFUNC_NameDecl(void) { return (id)&_NameDecl; }
id  OBJCCSUPER_NameDecl(void) { return _NameDecl.clsSuper; }
struct _SHARED __NameDecl = {
  (id)&__Object,
  (id)&__Decl,
  "NameDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _NameDecl_clsDispatchTbl,
  34,
  &namedecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_NameDecl(void) { return (id)&__NameDecl; }
id  OBJCMSUPER_NameDecl(void) { return __NameDecl.clsSuper; }
static char *_selTransTbl[] ={
"identifier",
"isEqual:",
"gen",
"lineno:",
"lineno",
"filename:",
"filename",
"st80",
0
};
struct modDescriptor namedecl_modDesc = {
  "namedecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &NameDecl,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_namedecl(void)
{
  selTransTbl = _selTransTbl;
  return &namedecl_modDesc;
}
int _OBJCPOSTLINK_namedecl = 1;


