# 1 "enumtor.m"
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
extern struct modDescriptor  *_OBJCBIND_enumtor(void);
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
extern struct modDescriptor enumtor_modDesc;

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
# 22 "./trlunit.h"
extern id trlunit;
# 22 "./enumtor.h"
struct Enumerator_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./enumtor.h"
id name,value;};

# 22 "./enumtor.h"
extern id  Enumerator;

# 22 "./enumtor.h"
extern struct _SHARED _Enumerator;
extern struct _SHARED __Enumerator;


# 37 "enumtor.m"
static BOOL i_Enumerator_isenumtor(struct Enumerator_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_Enumerator_name_(struct Enumerator_PRIVATE *self,SEL _cmd,id n)
{self->
name=n;
return(id)self;
}

static id i_Enumerator_value_(struct Enumerator_PRIVATE *self,SEL _cmd,id v)
{self->
value=v;
return(id)self;
}

static STR i_Enumerator_str(struct Enumerator_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 56 "enumtor.m"
return(objcT0=self->name,(*(STR(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static unsigned i_Enumerator_hash(struct Enumerator_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 61 "enumtor.m"
return(objcT1=self->name,(*(unsigned(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static BOOL i_Enumerator_isEqual_(struct Enumerator_PRIVATE *self,SEL _cmd,id x)
{
id objcT2,objcT3;

# 66 "enumtor.m"
return strcmp((objcT2=self->name,(*(STR(*)(id,SEL))_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0])),(objcT3=x,(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0])))==0;
}

static id i_Enumerator_synth(struct Enumerator_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 71 "enumtor.m"
(objcT4=trlunit,(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],(id)self));
return(id)self;
}

static id i_Enumerator_gen(struct Enumerator_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 77 "enumtor.m"
(objcT5=self->name,(*_imp(objcT5,selTransTbl[3]))(objcT5,selTransTbl[3]));
if(self->value){
id objcT6;

# 79 "enumtor.m"
gc('=');
(objcT6=self->value,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
}
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _Enumerator_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Enumerator_nstDispatchTbl[] ={
{"isenumtor",(id (*)())i_Enumerator_isenumtor},
{"name:",(id (*)())i_Enumerator_name_},
{"value:",(id (*)())i_Enumerator_value_},
{"str",(id (*)())i_Enumerator_str},
{"hash",(id (*)())i_Enumerator_hash},
{"isEqual:",(id (*)())i_Enumerator_isEqual_},
{"synth",(id (*)())i_Enumerator_synth},
{"gen",(id (*)())i_Enumerator_gen},
{(char*)0,(id (*)())0}
};
id Enumerator = (id)&_Enumerator;
id  *OBJCCLASS_Enumerator(void) { return &Enumerator; }
struct _SHARED  _Enumerator = {
  (id)&__Enumerator,
  (id)&_Node,
  "Enumerator",
  0,
  sizeof(struct Enumerator_PRIVATE),
  8,
  _Enumerator_nstDispatchTbl,
  41,
  &enumtor_modDesc,
  0,
  (id)0,
  &Enumerator,
};
id  OBJCCFUNC_Enumerator(void) { return (id)&_Enumerator; }
id  OBJCCSUPER_Enumerator(void) { return _Enumerator.clsSuper; }
struct _SHARED __Enumerator = {
  (id)&__Object,
  (id)&__Node,
  "Enumerator",
  0,
  sizeof(struct _SHARED),
  0,
  _Enumerator_clsDispatchTbl,
  34,
  &enumtor_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Enumerator(void) { return (id)&__Enumerator; }
id  OBJCMSUPER_Enumerator(void) { return __Enumerator.clsSuper; }
static char *_selTransTbl[] ={
"str",
"hash",
"defenumtor:",
"gen",
0
};
struct modDescriptor enumtor_modDesc = {
  "enumtor",
  "objc3.3.19",
  0L,
  0,
  0,
  &Enumerator,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_enumtor(void)
{
  selTransTbl = _selTransTbl;
  return &enumtor_modDesc;
}
int _OBJCPOSTLINK_enumtor = 1;


