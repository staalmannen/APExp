# 1 "compdef.m"
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
extern struct modDescriptor  *_OBJCBIND_compdef(void);
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
extern struct modDescriptor compdef_modDesc;

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
# 22 "./structsp.h"
extern id curstruct;
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
# 22 "./compdef.h"
struct ComponentDef_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./compdef.h"
id specs;
id decllist;};

# 22 "./compdef.h"
extern id  ComponentDef;

# 22 "./compdef.h"
extern struct _SHARED _ComponentDef;
extern struct _SHARED __ComponentDef;


# 43 "compdef.m"
static id i_ComponentDef_specs(struct ComponentDef_PRIVATE *self,SEL _cmd){
return self->specs;
}

static id i_ComponentDef_specs_(struct ComponentDef_PRIVATE *self,SEL _cmd,id aSpec)
{self->
specs=aSpec;
return(id)self;
}

static id i_ComponentDef_decllist(struct ComponentDef_PRIVATE *self,SEL _cmd){
return self->decllist;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 57 "compdef.m"
static id i_ComponentDef_add_(struct ComponentDef_PRIVATE *self,SEL _cmd,id aDecl)
{
id objcT0,objcT1;

# 59 "compdef.m"
if( !self->decllist)self->
decllist=(objcT0=OrdCltn,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
(objcT1=self->decllist,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],aDecl));
return(id)self;
}

static id i_ComponentDef_gen(struct ComponentDef_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 67 "compdef.m"
if(self->specs)
(objcT2=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],selTransTbl[3]));
if(self->decllist)
gcommalist(self->decllist);
gc(';');
return(id)self;
}

# 34 "./type.h"
extern id  Type;

# 22 "./bflddecl.h"
extern id  BitfieldDecl;

# 24 "./structsp.h"
extern id  StructSpec;

# 75 "compdef.m"
static id i_ComponentDef_synth(struct ComponentDef_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 77 "compdef.m"
int i,n;

(void)0;
for(i=0,n=(objcT3=self->decllist,(*(unsigned(*)(id,SEL))_imp(objcT3,selTransTbl[4]))(objcT3,selTransTbl[4]));i<n;i++){
id objcT4,objcT5;

# 81 "compdef.m"
id var=(objcT4=(objcT5=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5],i)),(*_imp(objcT4,selTransTbl[6]))(objcT4,selTransTbl[6]));

if(var){
id objcT6,objcT7,objcT13;

# 84 "compdef.m"
id t=(objcT6=Type,(*_imp(objcT6,selTransTbl[0]))(objcT6,selTransTbl[0]));
id d=(objcT7=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],i));

if(self->specs){
id objcT8,objcT9,objcT10;

# 88 "compdef.m"
(objcT8=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2],_cmd));
(objcT9=t,(*_imp(objcT9,selTransTbl[7]))(objcT9,selTransTbl[7],self->specs));
(objcT10=t,(*_imp(objcT10,selTransTbl[8]))(objcT10,selTransTbl[8],d));
}else{
id objcT11,objcT12;

# 92 "compdef.m"
(objcT11=t,(*_imp(objcT11,selTransTbl[9]))(objcT11,selTransTbl[9],s_int));
(objcT12=t,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8],d));
}
(objcT13=curstruct,(*_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10],var,t));
}else{
id objcT14,objcT15,objcT16;

# 97 "compdef.m"
if( !(objcT14=(objcT15=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT15,selTransTbl[5]))(objcT15,selTransTbl[5],i)),(*(BOOL(*)(id,SEL,id))_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11],(id)(objcT16=BitfieldDecl,(*_imp(objcT16,selTransTbl[12]))(objcT16,selTransTbl[12]))))){
id objcT17,objcT18,objcT19;

# 98 "compdef.m"
char*what="class definition";
char*ms="missing name in component of %s";

if((objcT17=curstruct,(*(BOOL(*)(id,SEL,id))_imp(objcT17,selTransTbl[11]))(objcT17,selTransTbl[11],(id)(objcT18=StructSpec,(*_imp(objcT18,selTransTbl[12]))(objcT18,selTransTbl[12])))))
what="struct or union";
if(self->specs)
warnat((objcT19=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT19,selTransTbl[5]))(objcT19,selTransTbl[5],0)),ms,what);
else
warn(ms,what);
}
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
static struct _SLT _ComponentDef_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _ComponentDef_nstDispatchTbl[] ={
{"specs",(id (*)())i_ComponentDef_specs},
{"specs:",(id (*)())i_ComponentDef_specs_},
{"decllist",(id (*)())i_ComponentDef_decllist},
{"add:",(id (*)())i_ComponentDef_add_},
{"gen",(id (*)())i_ComponentDef_gen},
{"synth",(id (*)())i_ComponentDef_synth},
{(char*)0,(id (*)())0}
};
id ComponentDef = (id)&_ComponentDef;
id  *OBJCCLASS_ComponentDef(void) { return &ComponentDef; }
struct _SHARED  _ComponentDef = {
  (id)&__ComponentDef,
  (id)&_Node,
  "ComponentDef",
  0,
  sizeof(struct ComponentDef_PRIVATE),
  6,
  _ComponentDef_nstDispatchTbl,
  41,
  &compdef_modDesc,
  0,
  (id)0,
  &ComponentDef,
};
id  OBJCCFUNC_ComponentDef(void) { return (id)&_ComponentDef; }
id  OBJCCSUPER_ComponentDef(void) { return _ComponentDef.clsSuper; }
struct _SHARED __ComponentDef = {
  (id)&__Object,
  (id)&__Node,
  "ComponentDef",
  0,
  sizeof(struct _SHARED),
  0,
  _ComponentDef_clsDispatchTbl,
  34,
  &compdef_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ComponentDef(void) { return (id)&__ComponentDef; }
id  OBJCMSUPER_ComponentDef(void) { return __ComponentDef.clsSuper; }
static char *_selTransTbl[] ={
"new",
"add:",
"elementsPerform:",
"gen",
"size",
"at:",
"identifier",
"specs:",
"decl:",
"addspec:",
"defcomp:astype:",
"isKindOf:",
"class",
0
};
struct modDescriptor compdef_modDesc = {
  "compdef",
  "objc3.3.19",
  0L,
  0,
  0,
  &ComponentDef,
  13,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_compdef(void)
{
  selTransTbl = _selTransTbl;
  return &compdef_modDesc;
}
int _OBJCPOSTLINK_compdef = 1;


