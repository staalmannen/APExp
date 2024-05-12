# 1 "sortcltn.m"
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
extern struct modDescriptor  *_OBJCBIND_sortcltn(void);
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
extern struct modDescriptor sortcltn_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

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
# 28 "./set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 31 "./ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 38 "./../../include/objcrt/Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 41 "./sortcltn.h"
struct SortCltn_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 43 "./sortcltn.h"
struct objbbt value;
SEL cmpSel;
id cmpBlk;};

# 41 "./sortcltn.h"
extern id  SortCltn;

# 41 "./sortcltn.h"
extern struct _SHARED _SortCltn;
extern struct _SHARED __SortCltn;


# 49 "sortcltn.m"
static objbbt_t
alloc()
{
return(objbbt_t)OC_Malloc(sizeof(struct objbbt));
}

static objbbt_t
init(objbbt_t self,id key)
{
self->ulink=NULL;
self->llink=NULL;
self->rlink=NULL;
self->key=key;
self->balance=0;
return self;
}

static objbbt_t
create(id key)
{
return init(alloc(),key);
}

static int
signum(objbbt_t ulink,objbbt_t self)
{
(void)0;
return(ulink->llink==self)? -1: +1;
}

static objbbt_t
slink(objbbt_t self,int sign)
{
(void)0;
return(sign>0)?self->rlink:self->llink;
}

static void
setllink(objbbt_t self,objbbt_t node)
{
self->llink=node;
if(node)
node->ulink=self;
}

static void
setrlink(objbbt_t self,objbbt_t node)
{
self->rlink=node;
if(node)
node->ulink=self;
}

static void
setslink(objbbt_t self,objbbt_t node,int sign)
{
if(sign>0)
setrlink(self,node);
else
setllink(self,node);
}

static void
freeobjects(objbbt_t self)
{
id objcT0;

# 114 "sortcltn.m"
if(self->llink)
freeobjects(self->llink);
if(self->rlink)
freeobjects(self->rlink);
self->key=(objcT0=self->key,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static objbbt_t
destroy(objbbt_t self)
{
if(self->llink)
self->llink=destroy(self->llink);
if(self->rlink)
self->rlink=destroy(self->rlink);
self->key=(id)0;
OC_Free(self);
return NULL;
}

static id c_SortCltn_new(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 135 "sortcltn.m"
return(objcT1=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],selTransTbl[2]));
}

static id c_SortCltn_new_(struct SortCltn_PRIVATE *self,SEL _cmd,unsigned n)
{
id objcT2;

# 140 "sortcltn.m"
return(objcT2=(id)self,(*_imp(objcT2,selTransTbl[3]))(objcT2,selTransTbl[3]));
}

static id c_SortCltn_newDictCompare(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 145 "sortcltn.m"
return(objcT3=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1],selTransTbl[4]));
}

static id i_SortCltn_setupcmpblock_(struct SortCltn_PRIVATE *self,SEL _cmd,id sortBlock)
{self->
cmpBlk=sortBlock;
init( &self->value,(id)0xdeadbeaf);
return(id)self;
}

# 162 "sortcltn.m"
static id c_SortCltn_sortBy_(struct SortCltn_PRIVATE *self,SEL _cmd,id sortBlock)
{
id objcT4,objcT5;
id newObj=(objcT4=__SortCltn.clsSuper,(*_impSuper(objcT4,selTransTbl[3]))((id)self,selTransTbl[3]));
(objcT5=newObj,(*_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5],sortBlock));
return newObj;
# 171 "sortcltn.m"
}

static id c_SortCltn_sortBlock_(struct SortCltn_PRIVATE *self,SEL _cmd,id sortBlock)
{
id objcT6;

# 175 "sortcltn.m"
return(objcT6=(id)self,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6],sortBlock));
}

static id i_SortCltn_setupcmpsel_(struct SortCltn_PRIVATE *self,SEL _cmd,SEL aSel)
{self->
cmpSel=aSel;
init( &self->value,(id)0);
return(id)self;
}

static id c_SortCltn_newCmpSel_(struct SortCltn_PRIVATE *self,SEL _cmd,SEL aSel)
{
id objcT7,objcT8;

# 187 "sortcltn.m"
id newObj=(objcT7=__SortCltn.clsSuper,(*_impSuper(objcT7,selTransTbl[3]))((id)self,selTransTbl[3]));
(objcT8=newObj,(*(id(*)(id,SEL,SEL))_imp(objcT8,selTransTbl[7]))(objcT8,selTransTbl[7],aSel));
return newObj;
}

# 198 "sortcltn.m"
static id c_SortCltn_with_(struct SortCltn_PRIVATE *self,SEL _cmd,int nArgs,...)
{
id objcT9;

# 200 "sortcltn.m"
id newObject;


va_list vp;

newObject=(objcT9=(id)self,(*_imp(objcT9,selTransTbl[3]))(objcT9,selTransTbl[3]));
# 220 "sortcltn.m"
va_start(vp,nArgs);
while(nArgs-->0)
{
id objcT10;

# 223 "sortcltn.m"
id anObject=va_arg(vp,id);
(objcT10=newObject,(*_imp(objcT10,selTransTbl[8]))(objcT10,selTransTbl[8],anObject));
}
va_end(vp);


return newObject;
}

static id c_SortCltn_with_with_(struct SortCltn_PRIVATE *self,SEL _cmd,id firstObject,id nextObject)
{
id objcT11,objcT12,objcT13;

# 234 "sortcltn.m"
return(objcT11=(objcT12=(objcT13=(id)self,(*_imp(objcT13,selTransTbl[3]))(objcT13,selTransTbl[3])),(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8],firstObject)),(*_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8],nextObject));
}

static id c_SortCltn_add_(struct SortCltn_PRIVATE *self,SEL _cmd,id firstObject)
{
id objcT14,objcT15;

# 239 "sortcltn.m"
return(objcT14=(objcT15=(id)self,(*_imp(objcT15,selTransTbl[3]))(objcT15,selTransTbl[3])),(*_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8],firstObject));
}

static id i_SortCltn_copy(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT16,objcT17;

# 244 "sortcltn.m"
return(objcT16=(objcT17=self->isa,(*_imp(objcT17,selTransTbl[3]))(objcT17,selTransTbl[3])),(*_imp(objcT16,selTransTbl[9]))(objcT16,selTransTbl[9],(id)self));
}

static id i_SortCltn_deepCopy(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19,objcT20,objcT21,objcT22;
id objcT23;

# 249 "sortcltn.m"
id aSeq,elt;
id aCopy=(objcT18=self->isa,(*_imp(objcT18,selTransTbl[3]))(objcT18,selTransTbl[3]));

aSeq=(objcT19=(id)self,(*_imp(objcT19,selTransTbl[10]))(objcT19,selTransTbl[10]));
while((elt=(objcT20=aSeq,(*_imp(objcT20,selTransTbl[11]))(objcT20,selTransTbl[11]))))
(objcT21=aCopy,(*_imp(objcT21,selTransTbl[8]))(objcT21,selTransTbl[8],(objcT22=elt,(*_imp(objcT22,selTransTbl[12]))(objcT22,selTransTbl[12]))));

aSeq=(objcT23=aSeq,(*_imp(objcT23,selTransTbl[0]))(objcT23,selTransTbl[0]));


return aCopy;
}

static id i_SortCltn_emptyYourself(struct SortCltn_PRIVATE *self,SEL _cmd)
{
if(self->value.llink)self->
value.llink=destroy(self->value.llink);
return(id)self;
}

static id i_SortCltn_freeContents(struct SortCltn_PRIVATE *self,SEL _cmd)
{
if(self->value.llink)
{
freeobjects(self->value.llink);self->
value.llink=destroy(self->value.llink);
}
return(id)self;
}

static id i_SortCltn_free(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT24;

# 281 "sortcltn.m"
if(self->value.llink)self->
value.llink=destroy(self->value.llink);
return(objcT24=_SortCltn.clsSuper,(*_impSuper(objcT24,selTransTbl[0]))((id)self,selTransTbl[0]));
}

static id i_SortCltn_release(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT25;

# 292 "sortcltn.m"
return(objcT25=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT25,selTransTbl[13]))(objcT25,selTransTbl[13],_cmd));

}

# 302 "sortcltn.m"
static objbbt_t i_SortCltn_objbbtTop(struct SortCltn_PRIVATE *self,SEL _cmd)
{
return self->value.llink;
}

static SEL i_SortCltn_comparisonSelector(struct SortCltn_PRIVATE *self,SEL _cmd)
{
return self->cmpSel;
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

static unsigned i_SortCltn_size(struct SortCltn_PRIVATE *self,SEL _cmd)
{
return(self->value.llink)?size(self->value.llink):0;
}

static BOOL i_SortCltn_isEmpty(struct SortCltn_PRIVATE *self,SEL _cmd)
{
return self->value.llink==NULL;
}

# 28 "./treeseq.h"
extern id  TreeSequence;

# 35 "./sequence.h"
extern id  Sequence;

# 333 "sortcltn.m"
static id i_SortCltn_eachElement(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT26,objcT27;

# 335 "sortcltn.m"
id aCarrier=(objcT26=TreeSequence,(*_imp(objcT26,selTransTbl[14]))(objcT26,selTransTbl[14],(id)self));
return(objcT27=Sequence,(*_imp(objcT27,selTransTbl[14]))(objcT27,selTransTbl[14],aCarrier));
}

# 345 "sortcltn.m"
static unsigned i_SortCltn_hash(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT28;

# 347 "sortcltn.m"
(objcT28=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT28,selTransTbl[13]))(objcT28,selTransTbl[13],_cmd));
return 0;
}

static BOOL i_SortCltn_isEqual_(struct SortCltn_PRIVATE *self,SEL _cmd,id aSort)
{
id objcT29;

# 353 "sortcltn.m"
(objcT29=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT29,selTransTbl[13]))(objcT29,selTransTbl[13],_cmd));
return(BOOL)0;
}

# 363 "sortcltn.m"
static int
cmp(objbbt_t self,id key,SEL cmpSel,id cmpBlk,objbbt_t*offset)
{
int c=0;
objbbt_t link;
id bkey=self->key;

if(cmpBlk)
{

if(key==bkey)
{
c=0;
}
else
{
id objcT30;

# 379 "sortcltn.m"
c=(objcT30=cmpBlk,(*(int(*)(id,SEL,id,id))_imp(objcT30,selTransTbl[15]))(objcT30,selTransTbl[15],key,bkey));
}

}
else
{
if(key==bkey)
{
c=0;
}
else
{
id objcT31;

# 391 "sortcltn.m"
c=((int(*)(id,SEL,id))(objcT31=key,(*(IMP(*)(id,SEL,SEL))_imp(objcT31,selTransTbl[16]))(objcT31,selTransTbl[16],cmpSel)))(key,cmpSel,bkey);
}
}

if(c==0)
{ *
offset=self;
return c;
}
link=(c<0)?self->llink:self->rlink;

return(link)?cmp(link,key,cmpSel,cmpBlk,offset):( *offset=self,c);
}

static int
cmpne(objbbt_t self,id key,SEL cmpSel,id cmpBlk,objbbt_t*offset)
{
int c=0;
objbbt_t link;
id bkey=self->key;

if(cmpBlk)
{

if(key==bkey)
{
c=0;
}
else
{
id objcT32;

# 421 "sortcltn.m"
c=(objcT32=cmpBlk,(*(int(*)(id,SEL,id,id))_imp(objcT32,selTransTbl[15]))(objcT32,selTransTbl[15],key,bkey));
}

}
else
{
if(key==bkey)
{
c=0;
}
else
{
id objcT33;

# 433 "sortcltn.m"
c=((int(*)(id,SEL,id))(objcT33=key,(*(IMP(*)(id,SEL,SEL))_imp(objcT33,selTransTbl[16]))(objcT33,selTransTbl[16],cmpSel)))(key,cmpSel,bkey);
}
}

if(c==0)
{
c= +1;
}
link=(c<0)?self->llink:self->rlink;

return(link)?cmpne(link,key,cmpSel,cmpBlk,offset):( *offset=self,c);
}

static int
height(objbbt_t self)
{
if(self)
{
int a,b;
a=height(self->llink);
b=height(self->rlink);
(void)0;
return 1+((a>b)?a:b);
}
else
{
return 0;
}
}

static objbbt_t
bnode(objbbt_t top,objbbt_t newp)
{
while(newp!=top&&newp->balance==0)
newp=newp->ulink;
(void)0;
return newp;
}

static int
adjust(objbbt_t b,objbbt_t newp)
{
int sign=0;
objbbt_t ulink;

while(1)
{
ulink=newp->ulink;
sign=signum(ulink,newp);
if(ulink==b)
break;
(void)0;
ulink->balance=sign;
newp=ulink;
}

return sign;
}

# 502 "sortcltn.m"
static void
sglrot(objbbt_t A,objbbt_t B,int sign)
{
objbbt_t U=A->ulink;
setslink(A,slink(B, -sign),sign);
setslink(B,A, -sign);
A->balance=0;
B->balance=0;
setslink(U,B,signum(U,A));
}

# 524 "sortcltn.m"
static void
dblrot(objbbt_t A,objbbt_t B,int sign)
{
objbbt_t U=A->ulink;
objbbt_t X=slink(B, -sign);

setslink(B,slink(X,sign), -sign);
setslink(X,B, +sign);
setslink(A,slink(X, -sign),sign);
setslink(X,A, -sign);

if(X->balance== +sign)
{
A->balance= -sign;
B->balance=0;
}
if(X->balance==0)
{
A->balance=0;
B->balance=0;
}
if(X->balance== -sign)
{
A->balance=0;
B->balance= +sign;
}

X->balance=0;
setslink(U,X,signum(U,A));
}

static void
rot(objbbt_t A,int sign)
{
objbbt_t B=slink(A,sign);
(void)0;

if(sign== +B->balance)
{
sglrot(A,B,sign);
return;
}
if(sign== -B->balance)
{
dblrot(A,B,sign);
return;
}
}

static void
rebalance(objbbt_t top,objbbt_t newp)
{
int sign;
objbbt_t b;

b=bnode(top,newp);
sign=adjust(b,newp);

if(b->balance==0)
{
b->balance=sign;
return;
}
if(b->balance== -sign)
{
b->balance=0;
return;
}
if(b->balance== +sign)
{
rot(b,sign);
return;
}
}

static void
addfirst(objbbt_t self,id key)
{
setllink(self,create(key));
}

static void
addat(objbbt_t top,id key,int c,objbbt_t offset)
{
objbbt_t newp=create(key);

(void)0;
if(c<0)
setllink(offset,newp);
if(c>0)
setrlink(offset,newp);

rebalance(top,newp);
# 621 "sortcltn.m"
}

static void
add(objbbt_t top,id key,SEL selCmp,id cmpBlk)
{
objbbt_t offset=NULL;
int c=cmpne(top,key,selCmp,cmpBlk, &offset);
addat(top,key,c,offset);
}

static id i_SortCltn_add_(struct SortCltn_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
if(self->value.llink)
{
add(self->value.llink,anObject,self->cmpSel,self->cmpBlk);
return(id)self;
}
else
{
addfirst( &self->value,anObject);
return(id)self;
}
}
else
{
return(id)0;
}
}

static id
addnfind(objbbt_t top,id key,SEL selCmp,id cmpBlk)
{
objbbt_t offset=NULL;
int c=cmpne(top,key,selCmp,cmpBlk, &offset);
if(c==0)
{
return offset->key;
}
else
{
addat(top,key,c,offset);
return key;
}
}

static id i_SortCltn_addNTest_(struct SortCltn_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
if(self->value.llink)
{
id res=addnfind(self->value.llink,anObject,self->cmpSel,self->cmpBlk);
return(res==anObject)?anObject:(id)0;
}
else
{
addfirst( &self->value,anObject);
return anObject;
}
}
else
{
return(id)0;
}
}

static id i_SortCltn_filter_(struct SortCltn_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
if(self->value.llink)
{
id objcT34;

# 695 "sortcltn.m"
id res=addnfind(self->value.llink,anObject,self->cmpSel,self->cmpBlk);

return(res==anObject)?anObject:((objcT34=anObject,(*_imp(objcT34,selTransTbl[0]))(objcT34,selTransTbl[0])),res);
# 701 "sortcltn.m"
}
else
{
addfirst( &self->value,anObject);
return anObject;
}
}
else
{
return(id)0;
}
}

static id
replace(objbbt_t top,id key,SEL selCmp,id cmpBlk)
{
objbbt_t offset=NULL;
int c=cmpne(top,key,selCmp,cmpBlk, &offset);
if(c==0)
{
id tmp=offset->key;
offset->key=key;
return tmp;
}
else
{
addat(top,key,c,offset);
return(id)0;
}
}

static id i_SortCltn_replace_(struct SortCltn_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
if(self->value.llink)
{
return replace(self->value.llink,anObject,self->cmpSel,self->cmpBlk);
}
else
{
addfirst( &self->value,anObject);
return(id)0;
}
}
else
{
return(id)0;
}
}

# 758 "sortcltn.m"
static id i_SortCltn_remove_(struct SortCltn_PRIVATE *self,SEL _cmd,id oldObject)
{
if(oldObject)
{
id objcT35;

# 762 "sortcltn.m"
return(objcT35=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT35,selTransTbl[13]))(objcT35,selTransTbl[13],_cmd));
}
else
{
return(id)0;
}
}

# 776 "sortcltn.m"
static BOOL i_SortCltn_includesAllOf_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT36,objcT37,objcT39;

# 784 "sortcltn.m"
BOOL res=(BOOL)1;
id e,seq=(objcT36=aCltn,(*_imp(objcT36,selTransTbl[10]))(objcT36,selTransTbl[10]));
while((e=(objcT37=seq,(*_imp(objcT37,selTransTbl[11]))(objcT37,selTransTbl[11]))))
{
id objcT38;

# 788 "sortcltn.m"
if( !(objcT38=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT38,selTransTbl[17]))(objcT38,selTransTbl[17],e)))
{
res=(BOOL)0;
goto done;
}
}
done:

(objcT39=seq,(*_imp(objcT39,selTransTbl[0]))(objcT39,selTransTbl[0]));

return res;
}
}

static BOOL i_SortCltn_includesAnyOf_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
return(BOOL)1;
}
else
{
id objcT40,objcT41,objcT43;

# 810 "sortcltn.m"
BOOL res=(BOOL)0;
id e,seq=(objcT40=aCltn,(*_imp(objcT40,selTransTbl[10]))(objcT40,selTransTbl[10]));
while((e=(objcT41=seq,(*_imp(objcT41,selTransTbl[11]))(objcT41,selTransTbl[11]))))
{
id objcT42;

# 814 "sortcltn.m"
if((objcT42=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT42,selTransTbl[17]))(objcT42,selTransTbl[17],e)))
{
res=(BOOL)1;
goto done;
}
}
done:

(objcT43=seq,(*_imp(objcT43,selTransTbl[0]))(objcT43,selTransTbl[0]));

return res;
}
}

# 834 "sortcltn.m"
static id i_SortCltn_addAll_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT44;

# 838 "sortcltn.m"
(objcT44=(id)self,(*_imp(objcT44,selTransTbl[18]))(objcT44,selTransTbl[18]));
}
else
{
id objcT45,objcT46,objcT48;

# 842 "sortcltn.m"
id e,seq;

seq=(objcT45=aCltn,(*_imp(objcT45,selTransTbl[10]))(objcT45,selTransTbl[10]));
while((e=(objcT46=seq,(*_imp(objcT46,selTransTbl[11]))(objcT46,selTransTbl[11]))))
{
id objcT47;

# 847 "sortcltn.m"
(objcT47=(id)self,(*_imp(objcT47,selTransTbl[8]))(objcT47,selTransTbl[8],e));
}

seq=(objcT48=seq,(*_imp(objcT48,selTransTbl[0]))(objcT48,selTransTbl[0]));

}

return(id)self;
}

static id i_SortCltn_addContentsOf_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT49;

# 859 "sortcltn.m"
return(objcT49=(id)self,(*_imp(objcT49,selTransTbl[9]))(objcT49,selTransTbl[9],aCltn));
}

static id i_SortCltn_addContentsTo_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT50;

# 864 "sortcltn.m"
return(objcT50=aCltn,(*_imp(objcT50,selTransTbl[9]))(objcT50,selTransTbl[9],(id)self));
}

static id i_SortCltn_removeAll_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
if((id)self==aCltn)
{
id objcT51;

# 871 "sortcltn.m"
(objcT51=(id)self,(*_imp(objcT51,selTransTbl[19]))(objcT51,selTransTbl[19]));
}
else
{
id objcT52,objcT53,objcT55;

# 875 "sortcltn.m"
id e,seq;

seq=(objcT52=aCltn,(*_imp(objcT52,selTransTbl[10]))(objcT52,selTransTbl[10]));
while((e=(objcT53=seq,(*_imp(objcT53,selTransTbl[11]))(objcT53,selTransTbl[11]))))
{
id objcT54;

# 880 "sortcltn.m"
(objcT54=(id)self,(*_imp(objcT54,selTransTbl[20]))(objcT54,selTransTbl[20],e));
}

seq=(objcT55=seq,(*_imp(objcT55,selTransTbl[0]))(objcT55,selTransTbl[0]));

}

return(id)self;
}

static id i_SortCltn_removeContentsFrom_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT56;

# 892 "sortcltn.m"
return(objcT56=aCltn,(*_imp(objcT56,selTransTbl[21]))(objcT56,selTransTbl[21],(id)self));
}

static id i_SortCltn_removeContentsOf_(struct SortCltn_PRIVATE *self,SEL _cmd,id aCltn)
{
id objcT57;

# 897 "sortcltn.m"
return(objcT57=(id)self,(*_imp(objcT57,selTransTbl[21]))(objcT57,selTransTbl[21],aCltn));
}

# 906 "sortcltn.m"
static id i_SortCltn_intersection_(struct SortCltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT58;

# 910 "sortcltn.m"
return(objcT58=(id)self,(*_imp(objcT58,selTransTbl[22]))(objcT58,selTransTbl[22]));
}
else
{
id objcT59,objcT60,objcT61,objcT64;

# 914 "sortcltn.m"
id anElement,elements;
id intersection=(objcT59=self->isa,(*_imp(objcT59,selTransTbl[3]))(objcT59,selTransTbl[3]));

elements=(objcT60=(id)self,(*_imp(objcT60,selTransTbl[10]))(objcT60,selTransTbl[10]));
while((anElement=(objcT61=elements,(*_imp(objcT61,selTransTbl[11]))(objcT61,selTransTbl[11]))))
{
id objcT62,objcT63;

# 920 "sortcltn.m"
if((objcT62=bag,(*_imp(objcT62,selTransTbl[23]))(objcT62,selTransTbl[23],anElement)))
(objcT63=intersection,(*_imp(objcT63,selTransTbl[8]))(objcT63,selTransTbl[8],anElement));
}

elements=(objcT64=elements,(*_imp(objcT64,selTransTbl[0]))(objcT64,selTransTbl[0]));


return intersection;
}
}

static id i_SortCltn_union_(struct SortCltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT65;

# 935 "sortcltn.m"
return(objcT65=(id)self,(*_imp(objcT65,selTransTbl[22]))(objcT65,selTransTbl[22]));
}
else
{
id objcT66,objcT67;

# 939 "sortcltn.m"
return(objcT66=(objcT67=(id)self,(*_imp(objcT67,selTransTbl[22]))(objcT67,selTransTbl[22])),(*_imp(objcT66,selTransTbl[9]))(objcT66,selTransTbl[9],bag));
}
}

static id i_SortCltn_difference_(struct SortCltn_PRIVATE *self,SEL _cmd,id bag)
{
if((id)self==bag)
{
id objcT68;

# 947 "sortcltn.m"
return(objcT68=self->isa,(*_imp(objcT68,selTransTbl[3]))(objcT68,selTransTbl[3]));
}
else
{
id objcT69,objcT70;

# 951 "sortcltn.m"
return(objcT69=(objcT70=(id)self,(*_imp(objcT70,selTransTbl[22]))(objcT70,selTransTbl[22])),(*_imp(objcT69,selTransTbl[21]))(objcT69,selTransTbl[21],bag));
}
}

# 36 "./set.h"
extern id  Set;

# 961 "sortcltn.m"
static id i_SortCltn_asSet(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT71,objcT72;
if((objcT71=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT71,selTransTbl[24]))(objcT71,selTransTbl[24],(id)(objcT72=Set,(*_imp(objcT72,selTransTbl[25]))(objcT72,selTransTbl[25])))))
{
return(id)self;
}
else
{
id objcT73,objcT74;

# 970 "sortcltn.m"
return(objcT73=(objcT74=Set,(*_imp(objcT74,selTransTbl[3]))(objcT74,selTransTbl[3])),(*_imp(objcT73,selTransTbl[9]))(objcT73,selTransTbl[9],(id)self));
}
}

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 974 "sortcltn.m"
static id i_SortCltn_asOrdCltn(struct SortCltn_PRIVATE *self,SEL _cmd)
{
id objcT75,objcT76;
if((objcT75=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT75,selTransTbl[24]))(objcT75,selTransTbl[24],(id)(objcT76=OrdCltn,(*_imp(objcT76,selTransTbl[25]))(objcT76,selTransTbl[25])))))
{
return(id)self;
}
else
{
id objcT77,objcT78;

# 983 "sortcltn.m"
return(objcT77=(objcT78=OrdCltn,(*_imp(objcT78,selTransTbl[3]))(objcT78,selTransTbl[3])),(*_imp(objcT77,selTransTbl[9]))(objcT77,selTransTbl[9],(id)self));
}
}

# 994 "sortcltn.m"
static id i_SortCltn_detect_(struct SortCltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT79,objcT80,objcT83;

# 996 "sortcltn.m"
id e,seq;

seq=(objcT79=(id)self,(*_imp(objcT79,selTransTbl[10]))(objcT79,selTransTbl[10]));

while((e=(objcT80=seq,(*_imp(objcT80,selTransTbl[11]))(objcT80,selTransTbl[11]))))
{
id objcT81;

# 1002 "sortcltn.m"
if(((objcT81=aBlock,(*_imp(objcT81,selTransTbl[26]))(objcT81,selTransTbl[26],e))))
{
id objcT82;
seq=(objcT82=seq,(*_imp(objcT82,selTransTbl[0]))(objcT82,selTransTbl[0]));

return e;
}
}


seq=(objcT83=seq,(*_imp(objcT83,selTransTbl[0]))(objcT83,selTransTbl[0]));

return(id)0;
}

static id i_SortCltn_detect_ifNone_(struct SortCltn_PRIVATE *self,SEL _cmd,id aBlock,id noneBlock)
{
id objcT84,objcT85,objcT88,objcT89;

# 1019 "sortcltn.m"
id e,seq;

seq=(objcT84=(id)self,(*_imp(objcT84,selTransTbl[10]))(objcT84,selTransTbl[10]));

while((e=(objcT85=seq,(*_imp(objcT85,selTransTbl[11]))(objcT85,selTransTbl[11]))))
{
id objcT86;

# 1025 "sortcltn.m"
if(((objcT86=aBlock,(*_imp(objcT86,selTransTbl[26]))(objcT86,selTransTbl[26],e))))
{
id objcT87;
seq=(objcT87=seq,(*_imp(objcT87,selTransTbl[0]))(objcT87,selTransTbl[0]));

return e;
}
}


seq=(objcT88=seq,(*_imp(objcT88,selTransTbl[0]))(objcT88,selTransTbl[0]));

return(objcT89=noneBlock,(*_imp(objcT89,selTransTbl[27]))(objcT89,selTransTbl[27]));
}

static id i_SortCltn_select_(struct SortCltn_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT90,objcT91,objcT92,objcT95;

# 1042 "sortcltn.m"
id e,seq;
id newObject=(objcT90=self->isa,(*_imp(objcT90,selTransTbl[3]))(objcT90,selTransTbl[3]));

seq=(objcT91=(id)self,(*_imp(objcT91,selTransTbl[10]))(objcT91,selTransTbl[10]));

while((e=(objcT92=seq,(*_imp(objcT92,selTransTbl[11]))(objcT92,selTransTbl[11]))))
{
id objcT93;

# 1049 "sortcltn.m"
if(((objcT93=testBlock,(*_imp(objcT93,selTransTbl[26]))(objcT93,selTransTbl[26],e))))
{
id objcT94;

# 1051 "sortcltn.m"
(objcT94=newObject,(*_imp(objcT94,selTransTbl[8]))(objcT94,selTransTbl[8],e));
}
}


seq=(objcT95=seq,(*_imp(objcT95,selTransTbl[0]))(objcT95,selTransTbl[0]));

return newObject;
}

static id i_SortCltn_reject_(struct SortCltn_PRIVATE *self,SEL _cmd,id testBlock)
{
id objcT96,objcT97,objcT98,objcT101;

# 1063 "sortcltn.m"
id e,seq;
id newObject=(objcT96=self->isa,(*_imp(objcT96,selTransTbl[3]))(objcT96,selTransTbl[3]));

seq=(objcT97=(id)self,(*_imp(objcT97,selTransTbl[10]))(objcT97,selTransTbl[10]));

while((e=(objcT98=seq,(*_imp(objcT98,selTransTbl[11]))(objcT98,selTransTbl[11]))))
{
id objcT99;

# 1070 "sortcltn.m"
if( !((objcT99=testBlock,(*_imp(objcT99,selTransTbl[26]))(objcT99,selTransTbl[26],e))))
{
id objcT100;

# 1072 "sortcltn.m"
(objcT100=newObject,(*_imp(objcT100,selTransTbl[8]))(objcT100,selTransTbl[8],e));
}
}


seq=(objcT101=seq,(*_imp(objcT101,selTransTbl[0]))(objcT101,selTransTbl[0]));

return newObject;
}

static id i_SortCltn_collect_(struct SortCltn_PRIVATE *self,SEL _cmd,id transformBlock)
{
id objcT102,objcT103,objcT104,objcT107;

# 1084 "sortcltn.m"
id e,seq;
id newObject=(objcT102=self->isa,(*_imp(objcT102,selTransTbl[3]))(objcT102,selTransTbl[3]));

seq=(objcT103=(id)self,(*_imp(objcT103,selTransTbl[10]))(objcT103,selTransTbl[10]));

while((e=(objcT104=seq,(*_imp(objcT104,selTransTbl[11]))(objcT104,selTransTbl[11]))))
{
id objcT105;

# 1091 "sortcltn.m"
id anImage=(objcT105=transformBlock,(*_imp(objcT105,selTransTbl[26]))(objcT105,selTransTbl[26],e));
if(anImage)
{
id objcT106;

# 1094 "sortcltn.m"
(objcT106=newObject,(*_imp(objcT106,selTransTbl[8]))(objcT106,selTransTbl[8],anImage));
}
}


seq=(objcT107=seq,(*_imp(objcT107,selTransTbl[0]))(objcT107,selTransTbl[0]));

return newObject;
}

static unsigned i_SortCltn_count_(struct SortCltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT108,objcT109,objcT111;

# 1106 "sortcltn.m"
id e,seq;
unsigned c=0;

seq=(objcT108=(id)self,(*_imp(objcT108,selTransTbl[10]))(objcT108,selTransTbl[10]));
while((e=(objcT109=seq,(*_imp(objcT109,selTransTbl[11]))(objcT109,selTransTbl[11]))))
{
id objcT110;

# 1112 "sortcltn.m"
if((objcT110=aBlock,(*_imp(objcT110,selTransTbl[26]))(objcT110,selTransTbl[26],e)))
{
c++;
}
}

seq=(objcT111=seq,(*_imp(objcT111,selTransTbl[0]))(objcT111,selTransTbl[0]));


return c;
}

# 1132 "sortcltn.m"
static id i_SortCltn_elementsPerform_(struct SortCltn_PRIVATE *self,SEL _cmd,SEL aSelector)
{
id objcT112,objcT113,objcT115;

# 1134 "sortcltn.m"
id e,seq;

seq=(objcT112=(id)self,(*_imp(objcT112,selTransTbl[10]))(objcT112,selTransTbl[10]));
while((e=(objcT113=seq,(*_imp(objcT113,selTransTbl[11]))(objcT113,selTransTbl[11]))))
{
id objcT114;

# 1139 "sortcltn.m"
(objcT114=e,(*(id(*)(id,SEL,SEL))_imp(objcT114,selTransTbl[28]))(objcT114,selTransTbl[28],aSelector));
}

seq=(objcT115=seq,(*_imp(objcT115,selTransTbl[0]))(objcT115,selTransTbl[0]));


return(id)self;
}

static id i_SortCltn_elementsPerform_with_(struct SortCltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject)
{
id objcT116,objcT117,objcT119;

# 1150 "sortcltn.m"
id e,seq;

seq=(objcT116=(id)self,(*_imp(objcT116,selTransTbl[10]))(objcT116,selTransTbl[10]));
while((e=(objcT117=seq,(*_imp(objcT117,selTransTbl[11]))(objcT117,selTransTbl[11]))))
{
id objcT118;

# 1155 "sortcltn.m"
(objcT118=e,(*(id(*)(id,SEL,SEL,id))_imp(objcT118,selTransTbl[29]))(objcT118,selTransTbl[29],aSelector,anObject));
}

seq=(objcT119=seq,(*_imp(objcT119,selTransTbl[0]))(objcT119,selTransTbl[0]));


return(id)self;
}

static id i_SortCltn_elementsPerform_with_with_(struct SortCltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject)
{
id objcT120,objcT121,objcT123;

# 1166 "sortcltn.m"
id e,seq;

seq=(objcT120=(id)self,(*_imp(objcT120,selTransTbl[10]))(objcT120,selTransTbl[10]));
while((e=(objcT121=seq,(*_imp(objcT121,selTransTbl[11]))(objcT121,selTransTbl[11]))))
{
id objcT122;

# 1171 "sortcltn.m"
(objcT122=e,(*(id(*)(id,SEL,SEL,id,id))_imp(objcT122,selTransTbl[30]))(objcT122,selTransTbl[30],aSelector,anObject,otherObject));
}

seq=(objcT123=seq,(*_imp(objcT123,selTransTbl[0]))(objcT123,selTransTbl[0]));


return(id)self;
}

static id i_SortCltn_elementsPerform_with_with_with_(struct SortCltn_PRIVATE *self,SEL _cmd,SEL aSelector,id anObject,id otherObject,id thirdObj)
{
id objcT124,objcT125,objcT127;

# 1182 "sortcltn.m"
id e,seq;

seq=(objcT124=(id)self,(*_imp(objcT124,selTransTbl[10]))(objcT124,selTransTbl[10]));
while((e=(objcT125=seq,(*_imp(objcT125,selTransTbl[11]))(objcT125,selTransTbl[11]))))
{
id objcT126;

# 1187 "sortcltn.m"
(objcT126=e,(*(id(*)(id,SEL,SEL,id,id,id))_imp(objcT126,selTransTbl[31]))(objcT126,selTransTbl[31],aSelector,anObject,otherObject,thirdObj));
}

seq=(objcT127=seq,(*_imp(objcT127,selTransTbl[0]))(objcT127,selTransTbl[0]));


return(id)self;
}

# 1202 "sortcltn.m"
static id i_SortCltn_do_(struct SortCltn_PRIVATE *self,SEL _cmd,id aBlock)
{
id objcT128,objcT129,objcT131;

# 1204 "sortcltn.m"
id e,seq;

seq=(objcT128=(id)self,(*_imp(objcT128,selTransTbl[10]))(objcT128,selTransTbl[10]));

while((e=(objcT129=seq,(*_imp(objcT129,selTransTbl[11]))(objcT129,selTransTbl[11]))))
{
id objcT130;

# 1210 "sortcltn.m"
(objcT130=aBlock,(*_imp(objcT130,selTransTbl[26]))(objcT130,selTransTbl[26],e));
}


seq=(objcT131=seq,(*_imp(objcT131,selTransTbl[0]))(objcT131,selTransTbl[0]));

return(id)self;
}
static id i_SortCltn_do_until_(struct SortCltn_PRIVATE *self,SEL _cmd,id aBlock,BOOL*flag)
{
id objcT132,objcT133,objcT135;

# 1220 "sortcltn.m"
id e,seq;

seq=(objcT132=(id)self,(*_imp(objcT132,selTransTbl[10]))(objcT132,selTransTbl[10]));

while((e=(objcT133=seq,(*_imp(objcT133,selTransTbl[11]))(objcT133,selTransTbl[11]))))
{
id objcT134;

# 1226 "sortcltn.m"
(objcT134=aBlock,(*_imp(objcT134,selTransTbl[26]))(objcT134,selTransTbl[26],e));
if( *flag)
break;
}


seq=(objcT135=seq,(*_imp(objcT135,selTransTbl[0]))(objcT135,selTransTbl[0]));

return(id)self;
}

# 1244 "sortcltn.m"
static id
find(objbbt_t self,id key,SEL cmpSel,id cmpBlk)
{
int c;
objbbt_t offset=NULL;

if((c=cmp(self,key,cmpSel,cmpBlk, &offset)))
{
return(id)0;
}
else
{
(void)0;
return offset->key;
}
}

static id i_SortCltn_find_(struct SortCltn_PRIVATE *self,SEL _cmd,id anObject)
{
if(anObject)
{
return(self->value.llink)?find(self->value.llink,anObject,self->cmpSel,self->cmpBlk):(id)0;
}
else
{
return(id)0;
}
}

static BOOL i_SortCltn_contains_(struct SortCltn_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT136;

# 1275 "sortcltn.m"
return(BOOL)((objcT136=(id)self,(*_imp(objcT136,selTransTbl[23]))(objcT136,selTransTbl[23],anObject))?(BOOL)1:(BOOL)0);
}

# 1284 "sortcltn.m"
static id i_SortCltn_printOn_(struct SortCltn_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT137,objcT138,objcT139;

# 1286 "sortcltn.m"
id s=(objcT137=(id)self,(*_imp(objcT137,selTransTbl[10]))(objcT137,selTransTbl[10]));
(objcT138=s,(*(id(*)(id,SEL,IOD))_imp(objcT138,selTransTbl[32]))(objcT138,selTransTbl[32],aFile));

(objcT139=s,(*_imp(objcT139,selTransTbl[0]))(objcT139,selTransTbl[0]));

return(id)self;
}

# 1300 "sortcltn.m"
static id i_SortCltn_fileOutOn_(struct SortCltn_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT140;

# 1302 "sortcltn.m"
return(objcT140=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT140,selTransTbl[13]))(objcT140,selTransTbl[13],_cmd));
}

static id i_SortCltn_fileInFrom_(struct SortCltn_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT141;

# 1307 "sortcltn.m"
return(objcT141=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT141,selTransTbl[13]))(objcT141,selTransTbl[13],_cmd));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Cltn;
extern struct _SHARED _Cltn;
extern struct _SHARED __Cltn;
static struct _SLT _SortCltn_clsDispatchTbl[] ={
{"new",(id (*)())c_SortCltn_new},
{"new:",(id (*)())c_SortCltn_new_},
{"newDictCompare",(id (*)())c_SortCltn_newDictCompare},
{"sortBy:",(id (*)())c_SortCltn_sortBy_},
{"sortBlock:",(id (*)())c_SortCltn_sortBlock_},
{"newCmpSel:",(id (*)())c_SortCltn_newCmpSel_},
{"with:",(id (*)())c_SortCltn_with_},
{"with:with:",(id (*)())c_SortCltn_with_with_},
{"add:",(id (*)())c_SortCltn_add_},
{(char*)0,(id (*)())0}
};
static struct _SLT _SortCltn_nstDispatchTbl[] ={
{"setupcmpblock:",(id (*)())i_SortCltn_setupcmpblock_},
{"setupcmpsel:",(id (*)())i_SortCltn_setupcmpsel_},
{"copy",(id (*)())i_SortCltn_copy},
{"deepCopy",(id (*)())i_SortCltn_deepCopy},
{"emptyYourself",(id (*)())i_SortCltn_emptyYourself},
{"freeContents",(id (*)())i_SortCltn_freeContents},
{"free",(id (*)())i_SortCltn_free},
{"release",(id (*)())i_SortCltn_release},
{"objbbtTop",(id (*)())i_SortCltn_objbbtTop},
{"comparisonSelector",(id (*)())i_SortCltn_comparisonSelector},
{"size",(id (*)())i_SortCltn_size},
{"isEmpty",(id (*)())i_SortCltn_isEmpty},
{"eachElement",(id (*)())i_SortCltn_eachElement},
{"hash",(id (*)())i_SortCltn_hash},
{"isEqual:",(id (*)())i_SortCltn_isEqual_},
{"add:",(id (*)())i_SortCltn_add_},
{"addNTest:",(id (*)())i_SortCltn_addNTest_},
{"filter:",(id (*)())i_SortCltn_filter_},
{"replace:",(id (*)())i_SortCltn_replace_},
{"remove:",(id (*)())i_SortCltn_remove_},
{"includesAllOf:",(id (*)())i_SortCltn_includesAllOf_},
{"includesAnyOf:",(id (*)())i_SortCltn_includesAnyOf_},
{"addAll:",(id (*)())i_SortCltn_addAll_},
{"addContentsOf:",(id (*)())i_SortCltn_addContentsOf_},
{"addContentsTo:",(id (*)())i_SortCltn_addContentsTo_},
{"removeAll:",(id (*)())i_SortCltn_removeAll_},
{"removeContentsFrom:",(id (*)())i_SortCltn_removeContentsFrom_},
{"removeContentsOf:",(id (*)())i_SortCltn_removeContentsOf_},
{"intersection:",(id (*)())i_SortCltn_intersection_},
{"union:",(id (*)())i_SortCltn_union_},
{"difference:",(id (*)())i_SortCltn_difference_},
{"asSet",(id (*)())i_SortCltn_asSet},
{"asOrdCltn",(id (*)())i_SortCltn_asOrdCltn},
{"detect:",(id (*)())i_SortCltn_detect_},
{"detect:ifNone:",(id (*)())i_SortCltn_detect_ifNone_},
{"select:",(id (*)())i_SortCltn_select_},
{"reject:",(id (*)())i_SortCltn_reject_},
{"collect:",(id (*)())i_SortCltn_collect_},
{"count:",(id (*)())i_SortCltn_count_},
{"elementsPerform:",(id (*)())i_SortCltn_elementsPerform_},
{"elementsPerform:with:",(id (*)())i_SortCltn_elementsPerform_with_},
{"elementsPerform:with:with:",(id (*)())i_SortCltn_elementsPerform_with_with_},
{"elementsPerform:with:with:with:",(id (*)())i_SortCltn_elementsPerform_with_with_with_},
{"do:",(id (*)())i_SortCltn_do_},
{"do:until:",(id (*)())i_SortCltn_do_until_},
{"find:",(id (*)())i_SortCltn_find_},
{"contains:",(id (*)())i_SortCltn_contains_},
{"printOn:",(id (*)())i_SortCltn_printOn_},
{"fileOutOn:",(id (*)())i_SortCltn_fileOutOn_},
{"fileInFrom:",(id (*)())i_SortCltn_fileInFrom_},
{(char*)0,(id (*)())0}
};
id SortCltn = (id)&_SortCltn;
id  *OBJCCLASS_SortCltn(void) { return &SortCltn; }
struct _SHARED  _SortCltn = {
  (id)&__SortCltn,
  (id)&_Cltn,
  "SortCltn",
  0,
  sizeof(struct SortCltn_PRIVATE),
  50,
  _SortCltn_nstDispatchTbl,
  41,
  &sortcltn_modDesc,
  0,
  (id)0,
  &SortCltn,
};
id  OBJCCFUNC_SortCltn(void) { return (id)&_SortCltn; }
id  OBJCCSUPER_SortCltn(void) { return _SortCltn.clsSuper; }
struct _SHARED __SortCltn = {
  (id)&__Object,
  (id)&__Cltn,
  "SortCltn",
  0,
  sizeof(struct _SHARED),
  9,
  _SortCltn_clsDispatchTbl,
  34,
  &sortcltn_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_SortCltn(void) { return (id)&__SortCltn; }
id  OBJCMSUPER_SortCltn(void) { return __SortCltn.clsSuper; }
static char *_selTransTbl[] ={
"free",
"newCmpSel:",
"compare:",
"new",
"dictCompare:",
"setupcmpblock:",
"sortBy:",
"setupcmpsel:",
"add:",
"addAll:",
"eachElement",
"next",
"deepCopy",
"notImplemented:",
"over:",
"intvalue:value:",
"methodFor:",
"includes:",
"addYourself",
"emptyYourself",
"remove:",
"removeAll:",
"copy",
"find:",
"isKindOf:",
"class",
"value:",
"value",
"perform:",
"perform:with:",
"perform:with:with:",
"perform:with:with:with:",
"printOn:",
0
};
struct modDescriptor sortcltn_modDesc = {
  "sortcltn",
  "objc3.3.19",
  0L,
  0,
  0,
  &SortCltn,
  33,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_sortcltn(void)
{
  selTransTbl = _selTransTbl;
  return &sortcltn_modDesc;
}
int _OBJCPOSTLINK_sortcltn = 1;


