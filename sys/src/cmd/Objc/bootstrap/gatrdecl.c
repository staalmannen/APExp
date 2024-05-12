# 1 "gatrdecl.m"
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
extern struct modDescriptor  *_OBJCBIND_gatrdecl(void);
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
extern struct modDescriptor gatrdecl_modDesc;

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
# 22 "./gatrdecl.h"
struct GnuAttribDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./gatrdecl.h"
id keyw,attribs;};

# 22 "./gatrdecl.h"
extern id  GnuAttribDecl;

# 22 "./gatrdecl.h"
extern struct _SHARED _GnuAttribDecl;
extern struct _SHARED __GnuAttribDecl;


# 36 "gatrdecl.m"
static id i_GnuAttribDecl_keyw_(struct GnuAttribDecl_PRIVATE *self,SEL _cmd,id k)
{self->
keyw=k;
return(id)self;
}

static id i_GnuAttribDecl_attribs_(struct GnuAttribDecl_PRIVATE *self,SEL _cmd,id aList)
{self->
attribs=aList;
return(id)self;
}

static id i_GnuAttribDecl_synth(struct GnuAttribDecl_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 50 "gatrdecl.m"
(objcT0=self->attribs,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
return(id)self;
}

static BOOL i_GnuAttribDecl_isgnuattrib(struct GnuAttribDecl_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_GnuAttribDecl_gen(struct GnuAttribDecl_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 61 "gatrdecl.m"
(objcT1=self->keyw,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
gs("((");
gcommalist(self->attribs);
gs("))");
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _GnuAttribDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _GnuAttribDecl_nstDispatchTbl[] ={
{"keyw:",(id (*)())i_GnuAttribDecl_keyw_},
{"attribs:",(id (*)())i_GnuAttribDecl_attribs_},
{"synth",(id (*)())i_GnuAttribDecl_synth},
{"isgnuattrib",(id (*)())i_GnuAttribDecl_isgnuattrib},
{"gen",(id (*)())i_GnuAttribDecl_gen},
{(char*)0,(id (*)())0}
};
id GnuAttribDecl = (id)&_GnuAttribDecl;
id  *OBJCCLASS_GnuAttribDecl(void) { return &GnuAttribDecl; }
struct _SHARED  _GnuAttribDecl = {
  (id)&__GnuAttribDecl,
  (id)&_Node,
  "GnuAttribDecl",
  0,
  sizeof(struct GnuAttribDecl_PRIVATE),
  5,
  _GnuAttribDecl_nstDispatchTbl,
  41,
  &gatrdecl_modDesc,
  0,
  (id)0,
  &GnuAttribDecl,
};
id  OBJCCFUNC_GnuAttribDecl(void) { return (id)&_GnuAttribDecl; }
id  OBJCCSUPER_GnuAttribDecl(void) { return _GnuAttribDecl.clsSuper; }
struct _SHARED __GnuAttribDecl = {
  (id)&__Object,
  (id)&__Node,
  "GnuAttribDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _GnuAttribDecl_clsDispatchTbl,
  34,
  &gatrdecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_GnuAttribDecl(void) { return (id)&__GnuAttribDecl; }
id  OBJCMSUPER_GnuAttribDecl(void) { return __GnuAttribDecl.clsSuper; }
static char *_selTransTbl[] ={
"elementsPerform:",
"gen",
0
};
struct modDescriptor gatrdecl_modDesc = {
  "gatrdecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &GnuAttribDecl,
  2,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_gatrdecl(void)
{
  selTransTbl = _selTransTbl;
  return &gatrdecl_modDesc;
}
int _OBJCPOSTLINK_gatrdecl = 1;


