# 1 "objgraph.m"
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
extern struct modDescriptor  *_OBJCBIND_objgraph(void);
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
extern struct modDescriptor objgraph_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

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

# 32 "./objgraph.h"
struct ObjGraph_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;};

# 32 "./objgraph.h"
extern id  ObjGraph;

# 32 "./objgraph.h"
extern struct _SHARED _ObjGraph;
extern struct _SHARED __ObjGraph;


# 32 "objgraph.m"
static id c_ObjGraph_over_(struct ObjGraph_PRIVATE *self,SEL _cmd,id anId)
{
id objcT0;

# 34 "objgraph.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
}

static id i_ObjGraph_over_unique_(struct ObjGraph_PRIVATE *self,SEL _cmd,id anId,BOOL flag)
{
id objcT1;

# 39 "objgraph.m"
return(objcT1=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0],_cmd));
}

static id c_ObjGraph_over_unique_(struct ObjGraph_PRIVATE *self,SEL _cmd,id anId,BOOL flag)
{
id objcT2;

# 44 "objgraph.m"
return(objcT2=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0],_cmd));
}

static unsigned i_ObjGraph_size(struct ObjGraph_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 49 "objgraph.m"
(objcT3=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0],_cmd));
return 0;
}

static id i_ObjGraph_error_(struct ObjGraph_PRIVATE *self,SEL _cmd,STR fmt,...)
{
id objcT4;

# 55 "objgraph.m"
(objcT4=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT4,selTransTbl[0]))(objcT4,selTransTbl[0],_cmd));
return(id)self;
}

static id i_ObjGraph_add_(struct ObjGraph_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT5;

# 61 "objgraph.m"
(objcT5=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT5,selTransTbl[0]))(objcT5,selTransTbl[0],_cmd));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _ObjGraph_clsDispatchTbl[] ={
{"over:",(id (*)())c_ObjGraph_over_},
{"over:unique:",(id (*)())c_ObjGraph_over_unique_},
{(char*)0,(id (*)())0}
};
static struct _SLT _ObjGraph_nstDispatchTbl[] ={
{"over:unique:",(id (*)())i_ObjGraph_over_unique_},
{"size",(id (*)())i_ObjGraph_size},
{"error:",(id (*)())i_ObjGraph_error_},
{"add:",(id (*)())i_ObjGraph_add_},
{(char*)0,(id (*)())0}
};
id ObjGraph = (id)&_ObjGraph;
id  *OBJCCLASS_ObjGraph(void) { return &ObjGraph; }
struct _SHARED  _ObjGraph = {
  (id)&__ObjGraph,
  (id)&_Object,
  "ObjGraph",
  0,
  sizeof(struct ObjGraph_PRIVATE),
  4,
  _ObjGraph_nstDispatchTbl,
  41,
  &objgraph_modDesc,
  0,
  (id)0,
  &ObjGraph,
};
id  OBJCCFUNC_ObjGraph(void) { return (id)&_ObjGraph; }
id  OBJCCSUPER_ObjGraph(void) { return _ObjGraph.clsSuper; }
struct _SHARED __ObjGraph = {
  (id)&__Object,
  (id)&__Object,
  "ObjGraph",
  0,
  sizeof(struct _SHARED),
  2,
  _ObjGraph_clsDispatchTbl,
  34,
  &objgraph_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ObjGraph(void) { return (id)&__ObjGraph; }
id  OBJCMSUPER_ObjGraph(void) { return __ObjGraph.clsSuper; }
static char *_selTransTbl[] ={
"notImplemented:",
0
};
struct modDescriptor objgraph_modDesc = {
  "objgraph",
  "objc3.3.19",
  0L,
  0,
  0,
  &ObjGraph,
  1,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_objgraph(void)
{
  selTransTbl = _selTransTbl;
  return &objgraph_modDesc;
}
int _OBJCPOSTLINK_objgraph = 1;


