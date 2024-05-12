# 1 "funbody.m"
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
extern struct modDescriptor  *_OBJCBIND_funbody(void);
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
extern struct modDescriptor funbody_modDesc;

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
# 22 "./def.h"
extern id curdef;
# 22 "./funbody.h"
struct FunctionBody_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./funbody.h"
id datadefs,compound;};

# 22 "./funbody.h"
extern id  FunctionBody;

# 22 "./funbody.h"
extern struct _SHARED _FunctionBody;
extern struct _SHARED __FunctionBody;


# 38 "funbody.m"
static id i_FunctionBody_compound(struct FunctionBody_PRIVATE *self,SEL _cmd){
return self->compound;
}
static id i_FunctionBody_datadefs_(struct FunctionBody_PRIVATE *self,SEL _cmd,id defs){
id objcT0;

# 42 "funbody.m"
int i,n;
for(i=0,n=(objcT0=defs,(*(unsigned(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));i<n;i++){
id objcT1,objcT2;

# 44 "funbody.m"
(objcT1=(objcT2=defs,(*(id(*)(id,SEL,unsigned))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1],i)),(*(id(*)(id,SEL,BOOL))_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],(BOOL)1));
}self->
datadefs=defs;
return(id)self;
}
static id i_FunctionBody_compound_(struct FunctionBody_PRIVATE *self,SEL _cmd,id aCompound){self->
compound=aCompound;
return(id)self;
}

static id i_FunctionBody_gen(struct FunctionBody_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4;

# 56 "funbody.m"
(void)0;
if(self->datadefs)
(objcT3=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3],selTransTbl[4]));
(objcT4=self->compound,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
return(id)self;
}

static id i_FunctionBody_synth(struct FunctionBody_PRIVATE *self,SEL _cmd)
{
id objcT6;
if(self->datadefs){
id objcT5;

# 67 "funbody.m"
(objcT5=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3],_cmd));
}
(objcT6=self->compound,(*_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5]));
return(id)self;
}

static id i_FunctionBody_fcall_(struct FunctionBody_PRIVATE *self,SEL _cmd,id x)
{
id objcT7;

# 75 "funbody.m"
return(objcT7=self->compound,(*_imp(objcT7,selTransTbl[6]))(objcT7,selTransTbl[6],x));
}

static id i_FunctionBody_go(struct FunctionBody_PRIVATE *self,SEL _cmd)
{
id objcT8;

# 80 "funbody.m"
return(objcT8=self->compound,(*_imp(objcT8,selTransTbl[7]))(objcT8,selTransTbl[7]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _FunctionBody_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _FunctionBody_nstDispatchTbl[] ={
{"compound",(id (*)())i_FunctionBody_compound},
{"datadefs:",(id (*)())i_FunctionBody_datadefs_},
{"compound:",(id (*)())i_FunctionBody_compound_},
{"gen",(id (*)())i_FunctionBody_gen},
{"synth",(id (*)())i_FunctionBody_synth},
{"fcall:",(id (*)())i_FunctionBody_fcall_},
{"go",(id (*)())i_FunctionBody_go},
{(char*)0,(id (*)())0}
};
id FunctionBody = (id)&_FunctionBody;
id  *OBJCCLASS_FunctionBody(void) { return &FunctionBody; }
struct _SHARED  _FunctionBody = {
  (id)&__FunctionBody,
  (id)&_Node,
  "FunctionBody",
  0,
  sizeof(struct FunctionBody_PRIVATE),
  7,
  _FunctionBody_nstDispatchTbl,
  41,
  &funbody_modDesc,
  0,
  (id)0,
  &FunctionBody,
};
id  OBJCCFUNC_FunctionBody(void) { return (id)&_FunctionBody; }
id  OBJCCSUPER_FunctionBody(void) { return _FunctionBody.clsSuper; }
struct _SHARED __FunctionBody = {
  (id)&__Object,
  (id)&__Node,
  "FunctionBody",
  0,
  sizeof(struct _SHARED),
  0,
  _FunctionBody_clsDispatchTbl,
  34,
  &funbody_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_FunctionBody(void) { return (id)&__FunctionBody; }
id  OBJCMSUPER_FunctionBody(void) { return __FunctionBody.clsSuper; }
static char *_selTransTbl[] ={
"size",
"at:",
"iskandr:",
"elementsPerform:",
"gen",
"synth",
"fcall:",
"go",
0
};
struct modDescriptor funbody_modDesc = {
  "funbody",
  "objc3.3.19",
  0L,
  0,
  0,
  &FunctionBody,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_funbody(void)
{
  selTransTbl = _selTransTbl;
  return &funbody_modDesc;
}
int _OBJCPOSTLINK_funbody = 1;


