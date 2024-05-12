# 1 "gattrib.m"
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
extern struct modDescriptor  *_OBJCBIND_gattrib(void);
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
extern struct modDescriptor gattrib_modDesc;

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
# 22 "./gattrib.h"
struct GnuAttrib_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./gattrib.h"
id anyword,exprlist;};

# 22 "./gattrib.h"
extern id  GnuAttrib;

# 22 "./gattrib.h"
extern struct _SHARED _GnuAttrib;
extern struct _SHARED __GnuAttrib;


# 36 "gattrib.m"
static id i_GnuAttrib_anyword_(struct GnuAttrib_PRIVATE *self,SEL _cmd,id w)
{self->
anyword=w;
return(id)self;
}

static id i_GnuAttrib_exprlist_(struct GnuAttrib_PRIVATE *self,SEL _cmd,id aList)
{self->
exprlist=aList;
return(id)self;
}

static id i_GnuAttrib_synth(struct GnuAttrib_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 50 "gattrib.m"
(objcT0=self->exprlist,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
return(id)self;
}

static id i_GnuAttrib_gen(struct GnuAttrib_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 56 "gattrib.m"
if(self->anyword)
(objcT1=self->anyword,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
if(self->exprlist){
gc('(');
gcommalist(self->exprlist);
gc(')');
}
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _GnuAttrib_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _GnuAttrib_nstDispatchTbl[] ={
{"anyword:",(id (*)())i_GnuAttrib_anyword_},
{"exprlist:",(id (*)())i_GnuAttrib_exprlist_},
{"synth",(id (*)())i_GnuAttrib_synth},
{"gen",(id (*)())i_GnuAttrib_gen},
{(char*)0,(id (*)())0}
};
id GnuAttrib = (id)&_GnuAttrib;
id  *OBJCCLASS_GnuAttrib(void) { return &GnuAttrib; }
struct _SHARED  _GnuAttrib = {
  (id)&__GnuAttrib,
  (id)&_Node,
  "GnuAttrib",
  0,
  sizeof(struct GnuAttrib_PRIVATE),
  4,
  _GnuAttrib_nstDispatchTbl,
  41,
  &gattrib_modDesc,
  0,
  (id)0,
  &GnuAttrib,
};
id  OBJCCFUNC_GnuAttrib(void) { return (id)&_GnuAttrib; }
id  OBJCCSUPER_GnuAttrib(void) { return _GnuAttrib.clsSuper; }
struct _SHARED __GnuAttrib = {
  (id)&__Object,
  (id)&__Node,
  "GnuAttrib",
  0,
  sizeof(struct _SHARED),
  0,
  _GnuAttrib_clsDispatchTbl,
  34,
  &gattrib_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_GnuAttrib(void) { return (id)&__GnuAttrib; }
id  OBJCMSUPER_GnuAttrib(void) { return __GnuAttrib.clsSuper; }
static char *_selTransTbl[] ={
"elementsPerform:",
"gen",
0
};
struct modDescriptor gattrib_modDesc = {
  "gattrib",
  "objc3.3.19",
  0L,
  0,
  0,
  &GnuAttrib,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_gattrib(void)
{
  selTransTbl = _selTransTbl;
  return &gattrib_modDesc;
}
int _OBJCPOSTLINK_gattrib = 1;


