# 1 "treeseq.m"
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
extern struct modDescriptor  *_OBJCBIND_treeseq(void);
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
extern struct modDescriptor treeseq_modDesc;

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

# 31 "./sortcltn.h"
typedef struct objbbt
{
struct objbbt*ulink;
struct objbbt*rlink;
struct objbbt*llink;
int balance;
id key;
}*
objbbt_t;
# 28 "./treeseq.h"
struct TreeSequence_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 30 "./treeseq.h"
objbbt_t top;
objbbt_t next;
objbbt_t prev;};

# 28 "./treeseq.h"
extern id  TreeSequence;

# 28 "./treeseq.h"
extern struct _SHARED _TreeSequence;
extern struct _SHARED __TreeSequence;


# 27 "treeseq.m"
static objbbt_t
first(objbbt_t p)
{
while(p->llink)
p=p->llink;
return p;
}

static objbbt_t
last(objbbt_t p)
{
while(p->rlink)
p=p->rlink;
return p;
}

static id i_TreeSequence_setUpSort_(struct TreeSequence_PRIVATE *self,SEL _cmd,id aSort)
{
id objcT0;
self->
# 45 "treeseq.m"
top=(objcT0=aSort,(*(objbbt_t(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));self->
prev=NULL;self->
next=(self->top)?first(self->top):NULL;
return(id)self;
}

static id c_TreeSequence_over_(struct TreeSequence_PRIVATE *self,SEL _cmd,id aSort)
{
id objcT1,objcT2;

# 53 "treeseq.m"
id newObj=(objcT1=__TreeSequence.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
(objcT2=newObj,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],aSort));
return newObj;
}

static id i_TreeSequence_copy(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 60 "treeseq.m"
return(objcT3=_TreeSequence.clsSuper,(*_impSuper(objcT3,selTransTbl[3]))((id)self,selTransTbl[3]));
}

static id i_TreeSequence_free(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 65 "treeseq.m"
return(objcT4=_TreeSequence.clsSuper,(*_impSuper(objcT4,selTransTbl[4]))((id)self,selTransTbl[4]));
}

static int
size(objbbt_t self)
{
int n=1;
if(self->llink)
n+=size(self->llink);
if(self->rlink)
n+=size(self->rlink);
return n;
}

static unsigned i_TreeSequence_size(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
return(self->top)?size(self->top):0;
}

static objbbt_t
nextulink(objbbt_t p,objbbt_t top)
{
while(p!=top)
{
objbbt_t ulink;
ulink=p->ulink;
if(p==ulink->llink)
return ulink;
p=ulink;
}

return NULL;
}

static objbbt_t
nextnode(objbbt_t p,objbbt_t top)
{
objbbt_t link;

if((link=p->rlink))
{
return first(link);
}
else
{
return nextulink(p,top);
}
}

static id i_TreeSequence_next(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
if(self->next)
{self->
prev=self->next;self->
next=nextnode(self->next,self->top);
return self->prev->key;
}
else
{
return(id)0;
}
}

static id i_TreeSequence_peek(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
return(self->next)?self->next->key:(id)0;
}

static id i_TreeSequence_previous(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
return(self->prev)?self->prev->key:(id)0;
}

static id i_TreeSequence_first(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
if(self->top)
{
objbbt_t f=first(self->top);
return f->key;
}
else
{
return(id)0;
}
}

static id i_TreeSequence_last(struct TreeSequence_PRIVATE *self,SEL _cmd)
{
if(self->top)
{
objbbt_t l=last(self->top);
return l->key;
}
else
{
return(id)0;
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _TreeSequence_clsDispatchTbl[] ={
{"over:",(id (*)())c_TreeSequence_over_},
{(char*)0,(id (*)())0}
};
static struct _SLT _TreeSequence_nstDispatchTbl[] ={
{"setUpSort:",(id (*)())i_TreeSequence_setUpSort_},
{"copy",(id (*)())i_TreeSequence_copy},
{"free",(id (*)())i_TreeSequence_free},
{"size",(id (*)())i_TreeSequence_size},
{"next",(id (*)())i_TreeSequence_next},
{"peek",(id (*)())i_TreeSequence_peek},
{"previous",(id (*)())i_TreeSequence_previous},
{"first",(id (*)())i_TreeSequence_first},
{"last",(id (*)())i_TreeSequence_last},
{(char*)0,(id (*)())0}
};
id TreeSequence = (id)&_TreeSequence;
id  *OBJCCLASS_TreeSequence(void) { return &TreeSequence; }
struct _SHARED  _TreeSequence = {
  (id)&__TreeSequence,
  (id)&_Object,
  "TreeSequence",
  0,
  sizeof(struct TreeSequence_PRIVATE),
  9,
  _TreeSequence_nstDispatchTbl,
  41,
  &treeseq_modDesc,
  0,
  (id)0,
  &TreeSequence,
};
id  OBJCCFUNC_TreeSequence(void) { return (id)&_TreeSequence; }
id  OBJCCSUPER_TreeSequence(void) { return _TreeSequence.clsSuper; }
struct _SHARED __TreeSequence = {
  (id)&__Object,
  (id)&__Object,
  "TreeSequence",
  0,
  sizeof(struct _SHARED),
  1,
  _TreeSequence_clsDispatchTbl,
  34,
  &treeseq_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_TreeSequence(void) { return (id)&__TreeSequence; }
id  OBJCMSUPER_TreeSequence(void) { return __TreeSequence.clsSuper; }
static char *_selTransTbl[] ={
"objbbtTop",
"new",
"setUpSort:",
"copy",
"free",
0
};
struct modDescriptor treeseq_modDesc = {
  "treeseq",
  "objc3.3.19",
  0L,
  0,
  0,
  &TreeSequence,
  5,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_treeseq(void)
{
  selTransTbl = _selTransTbl;
  return &treeseq_modDesc;
}
int _OBJCPOSTLINK_treeseq = 1;


