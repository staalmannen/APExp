# 1 "parmdef.m"
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
extern struct modDescriptor  *_OBJCBIND_parmdef(void);
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
extern struct modDescriptor parmdef_modDesc;

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

# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
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
# 22 "./parmdef.h"
struct ParameterDef_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./parmdef.h"
id specs;
id decl;};

# 22 "./parmdef.h"
extern id  ParameterDef;

# 22 "./parmdef.h"
extern struct _SHARED _ParameterDef;
extern struct _SHARED __ParameterDef;


# 42 "parmdef.m"
static id i_ParameterDef_specs(struct ParameterDef_PRIVATE *self,SEL _cmd){
return self->specs;
}

static id i_ParameterDef_specs_(struct ParameterDef_PRIVATE *self,SEL _cmd,id aSpec)
{self->
specs=aSpec;
return(id)self;
}

static id i_ParameterDef_decl_(struct ParameterDef_PRIVATE *self,SEL _cmd,id aDecl)
{self->
decl=aDecl;
return(id)self;
}

static id i_ParameterDef_gen(struct ParameterDef_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 60 "parmdef.m"
if(self->specs)
(objcT0=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],selTransTbl[1]));
if(self->decl)
(objcT1=self->decl,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
return(id)self;
}

# 34 "./type.h"
extern id  Type;

# 67 "parmdef.m"
static id i_ParameterDef_synth(struct ParameterDef_PRIVATE *self,SEL _cmd)
{
if(curdef){
id objcT2;

# 70 "parmdef.m"
id v=(id)0;

if(self->decl)
v=(objcT2=self->decl,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
if( !self->decl|| !v){
id objcT3,objcT4,objcT5;

# 75 "parmdef.m"
if(self->specs&&(objcT3=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]))==1&&(objcT4=(objcT5=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4],0)),(*(BOOL(*)(id,SEL))_imp(objcT4,selTransTbl[5]))(objcT4,selTransTbl[5])))
return(id)self;
warn("missing parameter name in function definition");
}else{
id objcT6,objcT7,objcT8,objcT9;

# 79 "parmdef.m"
id t=(objcT6=Type,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]));

(objcT7=t,(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7],self->specs));
(objcT8=t,(*_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8],self->decl));
(objcT9=curdef,(*_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9],v,t));
}
}
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _ParameterDef_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ParameterDef_nstDispatchTbl[] ={
{"specs",(id (*)())i_ParameterDef_specs},
{"specs:",(id (*)())i_ParameterDef_specs_},
{"decl:",(id (*)())i_ParameterDef_decl_},
{"gen",(id (*)())i_ParameterDef_gen},
{"synth",(id (*)())i_ParameterDef_synth},
{(char*)0,(id (*)())0}
};
id ParameterDef = (id)&_ParameterDef;
id  *OBJCCLASS_ParameterDef(void) { return &ParameterDef; }
struct _SHARED  _ParameterDef = {
  (id)&__ParameterDef,
  (id)&_Node,
  "ParameterDef",
  0,
  sizeof(struct ParameterDef_PRIVATE),
  5,
  _ParameterDef_nstDispatchTbl,
  41,
  &parmdef_modDesc,
  0,
  (id)0,
  &ParameterDef,
};
id  OBJCCFUNC_ParameterDef(void) { return (id)&_ParameterDef; }
id  OBJCCSUPER_ParameterDef(void) { return _ParameterDef.clsSuper; }
struct _SHARED __ParameterDef = {
  (id)&__Object,
  (id)&__Node,
  "ParameterDef",
  0,
  sizeof(struct _SHARED),
  0,
  _ParameterDef_clsDispatchTbl,
  34,
  &parmdef_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ParameterDef(void) { return (id)&__ParameterDef; }
id  OBJCMSUPER_ParameterDef(void) { return __ParameterDef.clsSuper; }
static char *_selTransTbl[] ={
"elementsPerform:",
"gen",
"identifier",
"size",
"at:",
"isvoid",
"new",
"specs:",
"decl:",
"defparm:astype:",
0
};
struct modDescriptor parmdef_modDesc = {
  "parmdef",
  "objc3.3.19",
  0L,
  0,
  0,
  &ParameterDef,
  10,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_parmdef(void)
{
  selTransTbl = _selTransTbl;
  return &parmdef_modDesc;
}
int _OBJCPOSTLINK_parmdef = 1;


