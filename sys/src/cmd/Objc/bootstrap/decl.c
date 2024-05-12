# 1 "decl.m"
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
extern struct modDescriptor  *_OBJCBIND_decl(void);
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
extern struct modDescriptor decl_modDesc;

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
# 22 "./decl.h"
struct Decl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;};

# 22 "./decl.h"
extern id  Decl;

# 22 "./decl.h"
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;


# 35 "decl.m"
static id i_Decl_hide_rename_(struct Decl_PRIVATE *self,SEL _cmd,id sym,id x)
{
id objcT0;

# 37 "decl.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
}

static id i_Decl_abstrdecl(struct Decl_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 42 "decl.m"
return(objcT1=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0],_cmd));
}

static BOOL i_Decl_isinit(struct Decl_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Decl_islistinit(struct Decl_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Decl_isfunproto(struct Decl_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Decl_canforward(struct Decl_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Decl_isscalartype(struct Decl_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Decl_ispointer(struct Decl_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static id i_Decl_star(struct Decl_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static id i_Decl_dot_(struct Decl_PRIVATE *self,SEL _cmd,id sym)
{
return(id)0;
}

static id i_Decl_funcall(struct Decl_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static id i_Decl_identifier(struct Decl_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 92 "decl.m"
return(objcT2=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0],_cmd));
}

static id i_Decl_genabstrtype(struct Decl_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 97 "decl.m"
return(objcT3=(id)self,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1],(id)0));
}

static id i_Decl_gendef_(struct Decl_PRIVATE *self,SEL _cmd,id sym)
{
id objcT4;

# 102 "decl.m"
return(objcT4=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT4,selTransTbl[0]))(objcT4,selTransTbl[0],_cmd));
}

static id i_Decl_synth(struct Decl_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 107 "decl.m"
return(objcT5=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT5,selTransTbl[0]))(objcT5,selTransTbl[0],_cmd));
}

static id i_Decl_synthinits(struct Decl_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Decl_st80(struct Decl_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 117 "decl.m"
return(objcT6=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT6,selTransTbl[0]))(objcT6,selTransTbl[0],_cmd));
}

static id i_Decl_st80inits(struct Decl_PRIVATE *self,SEL _cmd)
{
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _Decl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Decl_nstDispatchTbl[] ={
{"hide:rename:",(id (*)())i_Decl_hide_rename_},
{"abstrdecl",(id (*)())i_Decl_abstrdecl},
{"isinit",(id (*)())i_Decl_isinit},
{"islistinit",(id (*)())i_Decl_islistinit},
{"isfunproto",(id (*)())i_Decl_isfunproto},
{"canforward",(id (*)())i_Decl_canforward},
{"isscalartype",(id (*)())i_Decl_isscalartype},
{"ispointer",(id (*)())i_Decl_ispointer},
{"star",(id (*)())i_Decl_star},
{"dot:",(id (*)())i_Decl_dot_},
{"funcall",(id (*)())i_Decl_funcall},
{"identifier",(id (*)())i_Decl_identifier},
{"genabstrtype",(id (*)())i_Decl_genabstrtype},
{"gendef:",(id (*)())i_Decl_gendef_},
{"synth",(id (*)())i_Decl_synth},
{"synthinits",(id (*)())i_Decl_synthinits},
{"st80",(id (*)())i_Decl_st80},
{"st80inits",(id (*)())i_Decl_st80inits},
{(char*)0,(id (*)())0}
};
id Decl = (id)&_Decl;
id  *OBJCCLASS_Decl(void) { return &Decl; }
struct _SHARED  _Decl = {
  (id)&__Decl,
  (id)&_Node,
  "Decl",
  0,
  sizeof(struct Decl_PRIVATE),
  18,
  _Decl_nstDispatchTbl,
  41,
  &decl_modDesc,
  0,
  (id)0,
  &Decl,
};
id  OBJCCFUNC_Decl(void) { return (id)&_Decl; }
id  OBJCCSUPER_Decl(void) { return _Decl.clsSuper; }
struct _SHARED __Decl = {
  (id)&__Object,
  (id)&__Node,
  "Decl",
  0,
  sizeof(struct _SHARED),
  0,
  _Decl_clsDispatchTbl,
  34,
  &decl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Decl(void) { return (id)&__Decl; }
id  OBJCMSUPER_Decl(void) { return __Decl.clsSuper; }
static char *_selTransTbl[] ={
"subclassResponsibility:",
"gendef:",
0
};
struct modDescriptor decl_modDesc = {
  "decl",
  "objc3.3.19",
  0L,
  0,
  0,
  &Decl,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_decl(void)
{
  selTransTbl = _selTransTbl;
  return &decl_modDesc;
}
int _OBJCPOSTLINK_decl = 1;


