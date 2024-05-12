# 1 "objcrt.m"
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
extern struct modDescriptor  *_OBJCBIND_objcrt(void);
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
extern struct modDescriptor objcrt_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stddef.h"
#include <stddef.h>

# 55 "./objcrt.h"
typedef char*SEL;
typedef char*STR;
typedef char BOOL;
typedef FILE*IOD;
typedef id SHR;
# 64 "./objcrt.h"
typedef id(*IMP)();


typedef void(*ARGIMP)(id,SEL,void*);
# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 117 "./objcrt.h"
struct objcrt_private
{
id isa;
# 123 "./objcrt.h"
unsigned short attr;
unsigned short objID;

};

struct objcrt_shared
{
id isa;
# 134 "./objcrt.h"
id clsSuper;
char*clsName;
char*clsTypes;
short clsSizInstance;
short clsSizDict;
struct objcrt_slt*clsDispTable;
long clsStatus;
struct objcrt_modDescriptor*clsMod;
unsigned clsVersion;
id clsCats;
id*clsGlbl;
};

typedef struct objcrt_shared*Cls_t;
# 179 "./objcrt.h"
struct objcrt_slt
{
SEL _cmd;
IMP _imp;
};
# 189 "./objcrt.h"
struct objcrt_useDescriptor
{
int processed;
struct objcrt_useDescriptor*next;
struct objcrt_useDescriptor***uses;
struct objcrt_modDescriptor*(*bind)();
};
# 201 "./objcrt.h"
typedef struct hashedSelector
{
struct hashedSelector*next;
STR key;
}
HASH,*PHASH;
# 213 "./objcrt.h"
typedef struct objcrt_modDescriptor MOD,*PMOD;
typedef struct objcrt_methodDescriptor METH,*PMETH;

struct objcrt_modDescriptor
{
STR modName;
STR modVersion;
long modStatus;
SEL modMinSel;
SEL modMaxSel;
id*modClsLst;
short modSelRef;
SEL*modSelTbl;
PMETH modMapTbl;
};

struct objcrt_modEntry
{
PMOD(*modLink)();
PMOD modInfo;
};

typedef struct objcrt_modEntry*Mentry_t;

struct objcrt_methodDescriptor
{
id*cls;
SEL*sel;
IMP imp;
};
# 256 "./objcrt.h"
extern BOOL msgFlag;
extern FILE*msgIOD;
extern FILE*dbgIOD;
extern BOOL allocFlag;
extern BOOL dbgFlag;
extern BOOL noCacheFlag;
extern BOOL noNilRcvr;
# 269 "./objcrt.h"
SEL selUid(STR);
STR selName(SEL);
void dbg(char*fmt,...);
void loadobjc(void*modPtr);
void unloadobjc(void*modPtr);
# 286 "./objcrt.h"
IMP _imp(id,SEL);
IMP _impSuper(id,SEL);
# 291 "./objcrt.h"
IMP fwdimp(id,SEL,IMP);
IMP fwdimpSuper(id,SEL,IMP);
void fwdmsg(id,SEL,void*,ARGIMP);
id selptrfwd(id,SEL,id,id,id,id);


id idincref(id obj);
id idassign(id*lhs,id rhs);
id iddecref(id obj);
# 320 "./objcrt.h"
extern id(*oc_alloc)(id,unsigned int);
extern id(*oc_dealloc)(id);
extern id(*oc_copy)(id,unsigned int);
extern id(*oc_error)(id,STR,va_list);

extern id(*oc_cvtToId)(STR);
extern SEL(*oc_cvtToSel)(STR);

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

void addSubclassesTo(id c,STR name);

id newsubclass(STR name,id superClass,int ivars,int cvars);
void linkclass(id aclass);
void unlinkclass(id aclass);

void addMethods(id src,id dst);

void poseAs(id posing,id target);
id swapclass(id self,id target);
# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 42 "./Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//string.h"
#include <string.h>


# 61 "objcrt.m"
static BOOL
isfactory(Cls_t cls)
{
return(cls)->clsStatus&0x1L;
}

static BOOL
ismeta(Cls_t cls)
{
return(cls)->clsStatus&0x2L;
}

static BOOL
iscatgry(Cls_t cls)
{
return(cls)->clsStatus&0x40L;
}

static Cls_t
getmeta(Cls_t cls)
{
return ismeta(cls)?cls:((Cls_t)(cls->isa));
}

static BOOL
initlzd(Cls_t cls)
{
return getmeta(cls)->clsStatus&0x4L;
}

static void
markinitlzd(Cls_t cls)
{
getmeta(cls)->clsStatus|=0x4L;
}

static BOOL
ismapped(Cls_t aCls)
{
return(aCls)->clsStatus&0x10L;
}

static void
markmapped(Cls_t aCls)
{
aCls->clsStatus|=0x10L;
}

static id
getisa(id anObject)
{

return anObject->isa;
# 117 "objcrt.m"
}

static void
setisa(id anObject,id aClass)
{

anObject->isa=aClass;
# 127 "objcrt.m"
}

static short
nstsize(id aClass)
{
return((Cls_t)(aClass))->clsSizInstance;
}
# 138 "objcrt.m"
static PHASH*hashList;
static int nHashLists;

# 153 "objcrt.m"
static void
markmodmapped(struct objcrt_modDescriptor*aMod)
{
(aMod)->modStatus|=0x2L;
}

static BOOL
morethanone(struct objcrt_modDescriptor*aMod)
{
return(aMod)->modStatus&0x4L;
}

static SEL minsel,maxsel;

static BOOL
isminmaxsel(SEL s)
{
return(minsel<=s)&&(s<=maxsel);
}
# 189 "objcrt.m"
extern Mentry_t _objcModules;
# 199 "objcrt.m"
typedef struct modnode
{
Mentry_t objcmodules;
struct modnode*next;
}*
modnode_t;

static modnode_t modnodelist;

static modnode_t
newmodnode(Mentry_t me,modnode_t next)
{
modnode_t r;
r=(modnode_t)OC_Malloc(sizeof(struct modnode));
r->next=next;
r->objcmodules=me;
return r;
}

static void
freemodnode(modnode_t*n,modnode_t m)
{ *
n=m->next;
OC_Free(m);
}
# 231 "objcrt.m"
static id outOfMem;

void*
OC_Malloc(size_t nBytes)
{
id objcT0;

# 236 "objcrt.m"
void*data;


if( !nBytes)
nBytes=sizeof(void*);
if(nBytes>32*1024)
dbg("OC_Malloc call for %i bytes\n",nBytes);
# 247 "objcrt.m"
data=malloc(nBytes);
# 251 "objcrt.m"
if( !data)
(objcT0=outOfMem,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
return data;
}

void*
OC_MallocAtomic(size_t nBytes)
{
id objcT1;

# 259 "objcrt.m"
void*data;

if( !nBytes)
nBytes=sizeof(void*);
if(nBytes>32*1024)
dbg("OC_MallocAtomic call for %i bytes\n",nBytes);
# 269 "objcrt.m"
data=malloc(nBytes);
# 273 "objcrt.m"
if( !data)
(objcT1=outOfMem,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
return data;
}

void*
OC_Calloc(size_t nBytes)
{
char*p;

p=(char*)OC_Malloc(nBytes);

memset(p,0,nBytes);

return(void*)p;
}

void*
OC_Realloc(void*data,size_t nBytes)
{
id objcT2;
if( !nBytes)
nBytes=sizeof(void*);
if(nBytes>32*1024)
dbg("OC_Realloc call for %i bytes\n",nBytes);
# 302 "objcrt.m"
data=realloc(data,nBytes);
# 306 "objcrt.m"
if( !data)
(objcT2=outOfMem,(*_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0]));
return data;
}

void*
OC_Free(void*data)
{
# 317 "objcrt.m"
free(data);

return NULL;
}

# 359 "objcrt.m"
id
idassign(id*lhs,id rhs)
{
# 380 "objcrt.m"
return( *lhs=rhs);
}

id
idincref(id rhs)
{
# 396 "objcrt.m"
return rhs;
}

id
iddecref(id e)
{
# 415 "objcrt.m"
return(id)0;
}

# 40 "./Object.h"
extern id  Object;

# 418 "objcrt.m"
static id
nstalloc(id aClass,unsigned int nBytes)
{
id objcT3;

# 421 "objcrt.m"
id anObject;
unsigned aSize;
if( !aClass)
(objcT3=Object,(*(id(*)(id,SEL,STR,...))_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1],"alloc: nil class"));
aSize=nstsize(aClass)+nBytes;

anObject=(id)OC_Calloc(aSize);
# 433 "objcrt.m"
setisa(anObject,aClass);
return anObject;
}

static id
nstcopy(id anObject,unsigned int nBytes)
{
char*p,*q;
id newObject;
unsigned aSize;
id aClass=getisa(anObject);

aSize=nstsize(aClass)+nBytes;


newObject=(id)OC_Malloc(aSize);
p=(char*)newObject;
q=(char*)anObject;
# 459 "objcrt.m"
memcpy(p,q,aSize);
# 464 "objcrt.m"
(void)0;
return newObject;
}

static id
nstdealloc(id anObject)
{
setisa(anObject,(id)0);


OC_Free(anObject);
# 481 "objcrt.m"
return(id)0;
}

id(*oc_alloc)(id,unsigned int)=nstalloc;
id(*oc_copy)(id,unsigned int)=nstcopy;
# 489 "objcrt.m"
id(*oc_dealloc)(id)=nstdealloc;

# 520 "objcrt.m"
static id
reportv(id self,STR fmt,va_list ap)
{
fflush(stderr);
fprintf(stderr,"error: ");
vfprintf(stderr,fmt,ap);
fprintf(stderr,"\n");
fprintf(stderr,"(Use a debugger to see a message backtrace).\n");
fflush(stderr);
abort();
# 533 "objcrt.m"
}

static id
report(id self,STR fmt,...)
{
va_list ap;

va_start(ap,fmt);
reportv(self,fmt,ap);
va_end(ap);
return self;
}

id(*oc_error)(id self,STR fmt,va_list ap)=reportv;

# 556 "objcrt.m"
static void
nofiler(void)
{
id objcT4;

# 559 "objcrt.m"
(objcT4=Object,(*(id(*)(id,SEL,STR,...))_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1],"No filer class linked into application."));
}

static id
readfilein(STR aFileName)
{
FILE*f;
id r=(id)0;
if((f=fopen(aFileName,"r")))
{
r=( *_fileIn)(f);
fclose(f);
}
return r;
}

static BOOL
storefileout(STR aFileName,id anObject)
{
FILE*f;
BOOL r=(BOOL)0;
if((f=fopen(aFileName,"w")))
{
r=( *_fileOut)(f,anObject);
fclose(f);
}
return r;
}

static id
nofilein(FILE*f)
{
nofiler();
return(id)0;
}
static BOOL
nofileout(FILE*f,id anObject)
{
nofiler();
return(BOOL)0;
}

id(*_fileIn)(FILE*)=nofilein;
id(*_readFrom)(STR)=readfilein;
BOOL(*_fileOut)(FILE*,id)=nofileout;
BOOL(*_storeOn)(STR,id)=storefileout;



void
setfilein(id(*f)(FILE*))
{
_fileIn=f;
}
void
setfileout(BOOL(*f)(FILE*,id))
{
_fileOut=f;
}

# 623 "objcrt.m"
id
__showOn(id self,unsigned level)
{
( *_fileOut)(stderr,self);
return(id)0;
}

id(*_showOn)(id,unsigned)=__showOn;

# 640 "objcrt.m"
static int
strCmp(char*s1,char*s2)
{
int r;
int c1,c2;

while(1)
{
c1= *s1++;
c2= *s2++;
if(c1=='\0')
return(c2==0)?0: -1;
if(c2=='\0')
return 1;
if((r=c1-c2))
return r;
}
}

static unsigned
strHash(char*s)
{
unsigned hash=0;

while(1)
{
if( *s=='\0')
break;
else
hash^= *s++;
if( *s=='\0')
break;
else
hash^=( *s++<<8);
if( *s=='\0')
break;
else
hash^=( *s++<<16);
if( *s=='\0')
break;
else
hash^=( *s++<<24);
}

return hash;
}

static void
hashInit()
{
int i;
nHashLists=73;

hashList=(PHASH*)OC_Malloc(nHashLists*sizeof(PHASH));

for(i=0;i<nHashLists;i++)
hashList[i]=0;
# 702 "objcrt.m"
}

static PHASH
hashNew(STR key,PHASH link)
{
int n;
PHASH obj;
(void)0;
obj=(PHASH)OC_Malloc(sizeof(HASH));
obj->next=link;
n=strlen(key);
obj->key=(STR)OC_Malloc(n+1);
strcpy(obj->key,key);
return obj;
}

static PHASH
search(STR key,int*slot,PHASH*prev)
{
PHASH target; *

slot=strHash(key)%nHashLists; *
prev=0;
target=hashList[ *slot];

while(target&&(strCmp(key,target->key)!=0))
{ *
prev=target;
target=target->next;
}

return target;
}

static PHASH
hashEnter(STR key,int slot)
{
(void)0;
if(minsel)
{
if(key<minsel)
minsel=key;
if(key>maxsel)
maxsel=key;
}
else
{
minsel=key;
maxsel=key;
}
if(slot<0)
slot=strHash(key)%nHashLists;
hashList[slot]=hashNew(key,hashList[slot]);
return hashList[slot];
}

static PHASH
hashLookup(STR key,int*slot)
{
PHASH prev;
return search(key,slot, &prev);
}

# 816 "objcrt.m"
static void
mapsels(PMOD info,SEL*sel)
{
PHASH ent;
int i,slot;

for(i=0;i<info->modSelRef;i++)
{
SEL k;

if( !(ent=hashLookup(info->modSelTbl[i], &slot)))
{
ent=hashEnter(info->modSelTbl[i],slot);
}

k=ent->key;

if(sel!=0&& *sel==info->modSelTbl[i])
{ *
sel=k;
}


info->modSelTbl[i]=k;
}


markmodmapped(info);
}

static void
mapcls(Cls_t cls)
{
PHASH ent;
int i,slot;

for(i=0;i<cls->clsSizDict;i++)
{
if( !(ent=hashLookup(cls->clsDispTable[i]._cmd, &slot)))
{
ent=hashEnter(cls->clsDispTable[i]._cmd,slot);
}


cls->clsDispTable[i]._cmd=ent->key;
}

markmapped(cls);
}

static void
mapclass(Cls_t cls)
{
if( !ismapped(cls))
mapcls(cls);


while(isfactory(cls))
{
cls=getmeta(cls);
if( !ismapped(cls))
mapcls(cls);
}
}
# 887 "objcrt.m"
static BOOL objcinitflag;
# 896 "objcrt.m"
static struct objcrt_useDescriptor*modlist=0;
static int bindcnt=0;


extern struct objcrt_useDescriptor*OCU_main;

# 907 "objcrt.m"
static void
traverse(struct objcrt_useDescriptor*desc)
{
struct objcrt_useDescriptor***nxt;


desc->processed=1;


for(nxt=desc->uses; *nxt;nxt++)
{
if( * *nxt&& !(( * *nxt)->processed))
traverse( * *nxt);
}
# 928 "objcrt.m"
if(desc->bind)
{
desc->next=modlist;
modlist=desc;
bindcnt++;
}
}

static Mentry_t
findmods(struct objcrt_useDescriptor*desc)
{
Mentry_t tmp;
unsigned aSize;
Mentry_t theModules;
struct objcrt_useDescriptor*md;

if(desc&& !(desc->processed))
traverse(desc);

aSize=(bindcnt+1)*sizeof(struct objcrt_modEntry);
theModules=(Mentry_t)OC_Malloc(aSize);
# 954 "objcrt.m"
for(md=modlist,tmp=theModules;md;md=md->next,tmp++)
{
tmp->modLink=md->bind;
tmp->modInfo=0;
}


tmp->modLink=0;
tmp->modInfo=0;

return theModules;
}

static void
initsels(Mentry_t modPtr)
{
static int needHashInit=1;
# 976 "objcrt.m"
if(needHashInit)
{
hashInit();
needHashInit=0;
}

for(;modPtr&&modPtr->modLink;modPtr++)
{
PMOD info=modPtr->modInfo=( *modPtr->modLink)();

if(info)
{
id*cls;

if(info->modSelTbl)
mapsels(info,0);

cls=modPtr->modInfo->modClsLst;

if(morethanone(modPtr->modInfo))
{
while( *cls)
mapclass(((Cls_t)( *cls++)));
}
else
{
if(cls)
mapclass(((Cls_t)( *cls)));
}
}
}
}

static void
initcls(id cls)
{
id objcT5;

# 1012 "objcrt.m"
Cls_t aCls=((Cls_t)(cls));

if(initlzd(aCls))
return;
# 1029 "objcrt.m"
if(aCls->clsSuper)
{
initcls(aCls->clsSuper);
}
# 1039 "objcrt.m"
if(initlzd(aCls))
return;
markinitlzd(aCls);

if(iscatgry(aCls))
addMethods(cls,aCls->clsSuper);
(objcT5=cls,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]));
}

static void
initmods(Mentry_t modPtr)
{
for(;modPtr->modInfo;modPtr++)
{
id*cls=modPtr->modInfo->modClsLst;

if(morethanone(modPtr->modInfo))
{
while( *cls)
{
initcls( *cls);
cls++;
}
}
else
{
if(cls&& *cls)
{
initcls( *cls);
}
}
}
}

# 1085 "objcrt.m"
static void
msgiods(void)
{
STR s;


dbgIOD=stderr;
if((s=(getenv("OBJCRTDBG"))))
{
dbgFlag=(BOOL)1;
if(strcmp(s,"stderr")==0)
{
dbgIOD=stderr;
}
else
{
dbgIOD=fopen(s,"w");
setbuf(dbgIOD,NULL);
}
}

msgIOD=stderr;
if((s=(getenv("OBJCRTMSG"))))
{
msgFlag=(BOOL)1;
if(strcmp(s,"stderr")==0)
{
msgIOD=stderr;
}
else
{
msgIOD=fopen(s,"w");


if(dbgFlag)
setbuf(msgIOD,NULL);
}
}
# 1127 "objcrt.m"
}

# 28 "./OutOfMem.h"
extern id  OutOfMemory;

# 1129 "objcrt.m"
int
_objcInitNoShared(
Mentry_t _objcModules,struct objcrt_useDescriptor*OCU_main)
{
modnode_t m;

if(objcinitflag)
{
return 1;
}
else
{
id objcT6;
msgiods();
# 1148 "objcrt.m"
if( !_objcModules)
_objcModules=findmods(OCU_main);
loadobjc(_objcModules);
# 1158 "objcrt.m"
for(m=modnodelist;m;m=m->next)
initsels(m->objcmodules);
for(m=modnodelist;m;m=m->next)
initmods(m->objcmodules);
# 1168 "objcrt.m"
outOfMem=(objcT6=OutOfMemory,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
# 1174 "objcrt.m"
objcinitflag=(BOOL)1;


return 0;
}
}

# 1186 "objcrt.m"
int
oc_objcInit(int debug,BOOL traceInit)
{
return _objcInitNoShared(_objcModules,OCU_main);
}

# 1199 "objcrt.m"
STR
selName(SEL sel)
{
if(isminmaxsel(sel))
{
return(STR)(sel);
}
else
{
return NULL;
}
}

SEL
selUid(STR sel)
{
int slot;
PHASH retVal;
if((retVal=hashLookup(sel, &slot)))
return(SEL)retVal->key;
return NULL;
}

static SEL
cvtToSel(STR aString)
{
if(aString==NULL)
return NULL;
return selUid(aString);
}

static id
cvtToId(STR aClassName)
{
modnode_t m;
Mentry_t modPtr;

if(aClassName==NULL)
return(id)0;

for(m=modnodelist;m;m=m->next)
{
for(modPtr=m->objcmodules;modPtr&&modPtr->modLink;modPtr++)
{
id*cls;
Cls_t aCls;

cls=modPtr->modInfo->modClsLst;

if(morethanone(modPtr->modInfo))
{
while( *cls)
{
aCls=((Cls_t)( *cls));
if(strCmp(aCls->clsName,aClassName)==0)
{
return *cls;
}
cls++;
}
}
else
{
if(cls)
{
aCls=((Cls_t)( *cls));
if(strCmp(aCls->clsName,aClassName)==0)
return *cls;
}
}
}
}

return(id)0;
}


id(*oc_cvtToId)(STR)=cvtToId;
SEL(*oc_cvtToSel)(STR)=cvtToSel;

# 1285 "objcrt.m"
static BOOL
issubclass(Cls_t aCls,STR aClassname)
{
if(aCls->clsSuper)
{
Cls_t clsSuper=((Cls_t)(aCls->clsSuper));
return strCmp(clsSuper->clsName,aClassname)==0;
}
else
{
return 0;
}
}

void
addSubclassesTo(id c,STR aClassname)
{
modnode_t m;
Mentry_t modPtr;

for(m=modnodelist;m;m=m->next)
{
for(modPtr=m->objcmodules;modPtr&&modPtr->modLink;modPtr++)
{
id*cls;
Cls_t aCls;

cls=modPtr->modInfo->modClsLst;

if(morethanone(modPtr->modInfo))
{
while( *cls)
{
id objcT7;

# 1318 "objcrt.m"
aCls=((Cls_t)( *cls));
if(issubclass(aCls,aClassname))
(objcT7=c,(*_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4], *cls));
cls++;
}
}
else
{
if(cls)
{
id objcT8;

# 1328 "objcrt.m"
aCls=((Cls_t)( *cls));
if(issubclass(aCls,aClassname))
(objcT8=c,(*_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4], *cls));
}
}
}
}
}

# 1343 "objcrt.m"
static id
newShared(int aSize)
{
return(id)OC_Malloc(aSize);
}

static id
newMeta(STR name,id superClass,int esize)
{
id m;
Cls_t n;

m=newShared(sizeof(struct objcrt_shared));
n=((Cls_t)(m));

n->isa=((Cls_t)(superClass))->isa;
n->clsSuper=superClass;
n->clsName=name;
n->clsTypes=((Cls_t)(superClass))->clsTypes;
n->clsSizInstance=((Cls_t)(superClass))->clsSizInstance+esize;
n->clsSizDict=0;
n->clsDispTable=NULL;
n->clsStatus=0;
n->clsMod=NULL;
n->clsVersion=((Cls_t)(superClass))->clsVersion;
n->clsGlbl=NULL;

return m;
}

static id
newClass(STR name,id superClass,int eisize,int ecsize)
{
id m,meta;
Cls_t n,c;

meta=newMeta(name,((Cls_t)(superClass))->isa,ecsize);
m=newShared(((Cls_t)(meta))->clsSizInstance);
n=((Cls_t)(m));
c=((Cls_t)(superClass));

n->isa=meta;
n->clsSuper=superClass;
n->clsName=name;
n->clsTypes=c->clsTypes;
n->clsSizInstance=c->clsSizInstance+eisize;
n->clsSizDict=0;
n->clsDispTable=NULL;
n->clsStatus=0;
n->clsMod=NULL;
n->clsVersion=c->clsVersion;
n->clsGlbl=NULL;

return m;
}

static PMOD
newModDesc(id*clsLst)
{
PMOD mod=(PMOD)OC_Malloc(sizeof(MOD));

mod->modName="dynamic";
mod->modName="2.3.15";

mod->modStatus=0;
mod->modMinSel=NULL;
mod->modMaxSel=NULL;
mod->modClsLst=clsLst;
mod->modSelRef=0;
mod->modSelTbl=NULL;
mod->modMapTbl=NULL;

return mod;
}

static PMOD dynMod;
static PMOD
dynBIND(void)
{
return dynMod;
}

static void
addModEntry(id aCls)
{
id*clsLst;
Mentry_t entry,sentin;
entry=(Mentry_t)OC_Malloc(2*sizeof(struct objcrt_modEntry));

clsLst=OC_Malloc(sizeof(id)); *
clsLst=aCls;
dynMod=newModDesc(clsLst);

entry->modLink=dynBIND;
entry->modInfo=NULL;


sentin=entry+1;
sentin->modLink=NULL;
sentin->modInfo=NULL;

loadobjc(entry);
}

id
newsubclass(STR name,id superClass,int ivars,int cvars)
{
return newClass(name,superClass,ivars,cvars);
}

void
linkclass(id aclass)
{
addModEntry(aclass);
}

void
unlinkclass(id aclass)
{
modnode_t m;
Mentry_t modPtr;

if(aclass==(id)0)
return;

for(m=modnodelist;m;m=m->next)
{
for(modPtr=m->objcmodules;modPtr&&modPtr->modLink;modPtr++)
{
id*cls;

cls=modPtr->modInfo->modClsLst;

if(morethanone(modPtr->modInfo))
{
while( *cls)
{
if( *cls==aclass)
{
unloadobjc(modPtr);
return;
}
cls++;
}
}
else
{
if(cls)
{
if( *cls==aclass)
{
unloadobjc(modPtr);
return;
}
}
}
}
}
}

# 1514 "objcrt.m"
char*
objcrt_bindError(char*m)
{
fprintf(stderr,"objcrt initialization error (_OBJCBIND_%s)",m);
return NULL;
}

static void
prnframe(FILE*f,id obj,SEL sel,BOOL isSuper)
{
char*nam,*fac;

if(obj)
{
Cls_t cls=((Cls_t)(getisa(obj)));
nam=cls->clsName;
fac=(ismeta(cls))?"+":"-";
}
else
{
nam="nil";
fac="";
}

fprintf(f,(isSuper?"%s\t%s%s\tsuper\n":"%s\t%s%s\n"),nam,fac,sel);
}

static id
_errHandler(id self,SEL sel)
{
if(sel==selTransTbl[5])
{
char*msg;
msg="Completely messed up: Object does not recognize -doesNotRecognize:";
return report(self,msg);
}
else
{
id objcT9;

# 1552 "objcrt.m"
return(objcT9=self,(*(id(*)(id,SEL,SEL))_imp(objcT9,selTransTbl[5]))(objcT9,selTransTbl[5],sel));
}
}

static id
_nofwdHandler(id self,SEL sel)
{
return report(self,"'%s': This type of message cannot be forwarded.",sel);
}

static id
_freedHandler(id self,SEL sel)
{
return report(self,"Message '%s' sent to freed object.",sel);
}
# 1571 "objcrt.m"
BOOL noNilRcvr=(BOOL)0;

id
_nilHandler(id self,SEL sel)
{
return(noNilRcvr)?report(self,"Message '%s' sent to nil.",sel):(id)0;
}
# 1614 "objcrt.m"
static id clsCache[1031];
static SEL selCache[1031];
static IMP impCache[1031];


static void
flushCache(void)
{
int i=0;
for(i=0;i<1031;i++)
clsCache[i]=(id)0;
}

FILE*msgIOD;
BOOL msgFlag=(BOOL)0;
BOOL noCacheFlag=(BOOL)0;
BOOL dbgFlag=(BOOL)0;
BOOL allocFlag=(BOOL)0;
FILE*dbgIOD;

# 1665 "objcrt.m"
static IMP
_getImp(id cls,SEL sel,int index,IMP fwd)
{
Cls_t wCls;
id ncls=cls;

do
{
int n;
struct objcrt_slt*smt;

wCls=((Cls_t)(ncls));
smt=wCls->clsDispTable;

for(n=0;n<wCls->clsSizDict;n++,smt++)
{

if(sel==smt->_cmd)
{
if(noCacheFlag)
{
return smt->_imp;
}
else
{
IMP imp=smt->_imp;

selCache[index]=sel;
clsCache[index]=cls;
impCache[index]=imp;

return imp;
}
}
}
}
while((ncls=wCls->clsSuper));

if(objcinitflag)
{
return(fwd)?fwd:_nofwdHandler;
}
else
{
return _errHandler;
}
}

# 1720 "objcrt.m"
IMP
_imp(id aRecvr,SEL aSel)
{
return fwdimp(aRecvr,aSel,(IMP)_errHandler);
}

IMP
_impSuper(id aRecvr,SEL aSel)
{
return fwdimpSuper(aRecvr,aSel,(IMP)_errHandler);
}

IMP
fwdimp(id aRecvr,SEL aSel,IMP fwd)
{
id shr;
int index;
Cls_t wCls;
BOOL inSuper=(BOOL)0;

if(msgFlag)
prnframe(msgIOD,aRecvr,aSel,inSuper);
if( !aRecvr)
return(IMP)_nilHandler;
shr=getisa(aRecvr);
if( !shr)
return(IMP)_freedHandler;


index=(int)((((unsigned long)aSel)^((unsigned long)shr))%1031);

if( !noCacheFlag)
{

if(clsCache[index]==shr&&selCache[index]==aSel)
{
IMP imp=impCache[index];
return imp;
}

}
# 1765 "objcrt.m"
if(ismeta((wCls=((Cls_t)(shr)))))
{
if( !initlzd(wCls))
initcls(aRecvr);
}
else
{
if( !initlzd(wCls))
initcls(shr);
}

return _getImp(shr,aSel,index,fwd);
}

IMP
fwdimpSuper(id aClass,SEL aSel,IMP fwd)
{
int index;
BOOL inSuper=(BOOL)1;

if(msgFlag)
prnframe(msgIOD,aClass,aSel,inSuper);
if( !aClass)
return(IMP)_nilHandler;


index=(int)((((unsigned long)aSel)^((unsigned long)aClass))%1031);

if( !noCacheFlag)
{

if(clsCache[index]==aClass&&selCache[index]==aSel)
{
IMP imp=impCache[index];
return imp;
}

}

return _getImp(aClass,aSel,index,fwd);
}

# 37 "./Message.h"
extern id  Message;

# 1807 "objcrt.m"
void
fwdmsg(id self,SEL sel,void*args,ARGIMP disp)
{
if(sel==selTransTbl[6])
{
char*msg;
msg="Completely messed up: Object does not understand -doesNotUnderstand:";
report(self,msg);
}
else
{
id objcT10,objcT11,objcT12;

# 1818 "objcrt.m"
id msg=(objcT10=Message,(*(id(*)(id,SEL,SEL,ARGIMP,void*))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7],sel,disp,args));
(objcT11=self,(*_imp(objcT11,selTransTbl[6]))(objcT11,selTransTbl[6],msg));
msg=(objcT12=msg,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8]));
}
}

static void
selptrdisp(id self,SEL sel,id*p)
{
p[0]=( *fwdimp(self,sel,selptrfwd))(self,sel,p[1],p[2],p[3],p[4]);
}

id
selptrfwd(id self,SEL sel,id a,id b,id c,id d)
{
id p[5];
p[1]=a;
p[2]=b;
p[3]=c;
p[4]=d;
fwdmsg(self,sel,p,(ARGIMP)selptrdisp);
return p[0];
}

# 1847 "objcrt.m"
void
dbg(char*fmt,...)
{
if(dbgFlag)
{
va_list arglist;
va_start(arglist,fmt);
vfprintf(dbgIOD,fmt,arglist);
va_end(arglist);
fflush(dbgIOD);
}
}

# 1867 "objcrt.m"
static struct objcrt_slt*
newDispTable(int n)
{
return(struct objcrt_slt*)OC_Malloc(n*sizeof(struct objcrt_slt));
}

static void
copyDispTable(struct objcrt_slt*dst,struct objcrt_slt*src,int n)
{
while(n--)
{
dst->_imp=src->_imp;
dst->_cmd=src->_cmd;
dst++;
src++;
}
}

static void
freeDispTable(struct objcrt_slt*self)
{

}

static void
addnstmeth(Cls_t src,Cls_t dst)
{
struct objcrt_slt*n=newDispTable(dst->clsSizDict+src->clsSizDict);
copyDispTable(n,dst->clsDispTable,dst->clsSizDict);
copyDispTable(n+dst->clsSizDict,src->clsDispTable,src->clsSizDict);
dst->clsSizDict+=src->clsSizDict;
freeDispTable(dst->clsDispTable);
dst->clsDispTable=n;
}

void
addMethods(id isrc,id idst)
{
STR srcName,dstName;
Cls_t src=((Cls_t)(isrc));
Cls_t dst=((Cls_t)(idst));


if(src==dst)
return;
# 1918 "objcrt.m"
srcName=src->clsName;
dstName=dst->clsName;

if(src->clsSuper&&((Cls_t)(src->clsSuper))!=dst)
{
id objcT13;

# 1923 "objcrt.m"
(objcT13=isrc,(*(id(*)(id,SEL,STR,...))_imp(objcT13,selTransTbl[1]))(objcT13,selTransTbl[1],"addMethods: %s not direct subclass of %s.",
srcName,dstName));
}

if(src->clsSizInstance!=dst->clsSizInstance)
{
id objcT14;

# 1929 "objcrt.m"
(objcT14=isrc,(*(id(*)(id,SEL,STR,...))_imp(objcT14,selTransTbl[1]))(objcT14,selTransTbl[1],"addMethods: %s adds instance variables to %s.",
srcName,dstName));
}

addnstmeth(src,dst);
addnstmeth(getmeta(src),getmeta(dst));


flushCache();
}

# 1946 "objcrt.m"
id
swapclass(id self,id other)
{
# 1956 "objcrt.m"
return self;
}

void
poseAs(id iposing,id itarget)
{
modnode_t m;
Mentry_t modPtr;
STR newName,posingName,targetName;
Cls_t posing=((Cls_t)(iposing));
Cls_t target=((Cls_t)(itarget));


if(posing==target)
return;
# 1977 "objcrt.m"
posingName=posing->clsName;
targetName=target->clsName;

if( !((target)->clsStatus&0x8L))
{
id objcT15;

# 1982 "objcrt.m"
(objcT15=itarget,(*(id(*)(id,SEL,STR,...))_imp(objcT15,selTransTbl[1]))(objcT15,selTransTbl[1],"poseAs: %s needs to be recompiled",targetName));
}

if(posing->clsSuper&&((Cls_t)(posing->clsSuper))!=target)
{
id objcT16;

# 1987 "objcrt.m"
(objcT16=iposing,(*(id(*)(id,SEL,STR,...))_imp(objcT16,selTransTbl[1]))(objcT16,selTransTbl[1],"poseAs: %s not direct subclass of %s.",
posingName,targetName));
}

if(posing->clsSizInstance!=target->clsSizInstance)
{
id objcT17;

# 1993 "objcrt.m"
(objcT17=iposing,(*(id(*)(id,SEL,STR,...))_imp(objcT17,selTransTbl[1]))(objcT17,selTransTbl[1],"poseAs: %s adds instance variables to %s.",
posingName,targetName));
}
# 2002 "objcrt.m"
newName=(char*)OC_Malloc(strlen(targetName)+2+1);
strcpy(newName,"_%");
strcpy(newName+2,targetName);

posing->clsName=targetName;
getmeta(posing)->clsName=getmeta(target)->clsName;
target->clsName=newName+1;
getmeta(target)->clsName=newName;
# 2015 "objcrt.m"
for(m=modnodelist;m;m=m->next)
{
for(modPtr=m->objcmodules;modPtr&&modPtr->modLink;modPtr++)
{
id*cls;
Cls_t aCls;

cls=modPtr->modInfo->modClsLst;

if(morethanone(modPtr->modInfo))
{
while( *cls)
{
aCls=((Cls_t)( *cls++));
if(aCls==posing)
continue;
if(aCls->clsSuper==itarget)
{
aCls->clsSuper=iposing;
getmeta(aCls)->clsSuper=posing->isa;
}
}
}
else
{
if(cls)
{
aCls=((Cls_t)( *cls));
if(aCls==posing)
continue;
if(aCls->clsSuper==itarget)
{
aCls->clsSuper=iposing;
getmeta(aCls)->clsSuper=posing->isa;
}
}
}
}
}


(void)0;
if(target->clsGlbl) *
(target->clsGlbl)=iposing;


flushCache();
}

# 2069 "objcrt.m"
static void
initobjc(Mentry_t modPtr)
{
initsels(modPtr);
initmods(modPtr);
}

void
loadobjc(void*p)
{
Mentry_t modPtr=(Mentry_t)p;

if( !modPtr)
report((id)0,"loadobjc with NULL argument");
# 2093 "objcrt.m"
modnodelist=newmodnode(modPtr,modnodelist);

if( !objcinitflag)
{
return;
}
else
{
initobjc(modPtr);
return;
}
}

void
unloadobjc(void*p)
{
id objcT18;

# 2109 "objcrt.m"
modnode_t m,*n;
Mentry_t modPtr=(Mentry_t)p;

if( !modPtr)
report((id)0,"unloadobjc with NULL argument");

for(n=( &modnodelist),m=( *n);m;m=( *n))
{
if(modPtr==m->objcmodules)
{
freemodnode(n,m);
flushCache();
return;
}
else
{
n= &(m->next);
}
}

(objcT18=Object,(*(id(*)(id,SEL,STR,...))_imp(objcT18,selTransTbl[1]))(objcT18,selTransTbl[1],"unloadobjc() for module that is not loaded."));
}
static char *_selTransTbl[] ={
"signal",
"error:",
"initialize",
"new",
"add:",
"doesNotRecognize:",
"doesNotUnderstand:",
"selector:dispatch:args:",
"free",
0
};
struct modDescriptor objcrt_modDesc = {
  "objcrt",
  "objc3.3.19",
  0L,
  0,
  0,
  0,
  9,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_objcrt(void)
{
  selTransTbl = _selTransTbl;
  return &objcrt_modDesc;
}
int _OBJCPOSTLINK_objcrt = 1;


