# 1 "point.m"
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
extern struct modDescriptor  *_OBJCBIND_point(void);
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
extern struct modDescriptor point_modDesc;

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

# 32 "./point.h"
struct Point_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./point.h"
int xLoc;
int yLoc;};

# 32 "./point.h"
extern id  Point;

# 32 "./point.h"
extern struct _SHARED _Point;
extern struct _SHARED __Point;


# 36 "point.m"
static id c_Point_new(struct Point_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 38 "point.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,int,int))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],0,0));
}

static id c_Point_x_y_(struct Point_PRIVATE *self,SEL _cmd,int x,int y)
{
id objcT1,objcT2;

# 43 "point.m"
return(objcT1=(objcT2=__Point.clsSuper,(*_impSuper(objcT2,selTransTbl[1]))((id)self,selTransTbl[1])),(*(id(*)(id,SEL,int,int))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0],x,y));
}

# 53 "point.m"
static id i_Point_x_y_(struct Point_PRIVATE *self,SEL _cmd,int x,int y)
{self->
xLoc=x;self->
yLoc=y;
return(id)self;
}

static id i_Point_x_(struct Point_PRIVATE *self,SEL _cmd,int x)
{self->
xLoc=x;
return(id)self;
}

static id i_Point_y_(struct Point_PRIVATE *self,SEL _cmd,int y)
{self->
yLoc=y;
return(id)self;
}

static int i_Point_x(struct Point_PRIVATE *self,SEL _cmd)
{
return self->xLoc;
}

static int i_Point_y(struct Point_PRIVATE *self,SEL _cmd)
{
return self->yLoc;
}

# 89 "point.m"
static unsigned i_Point_hash(struct Point_PRIVATE *self,SEL _cmd)
{
return self->xLoc^self->yLoc;
}

static BOOL i_Point_isEqual_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT3,objcT4,objcT5;
return(objcT3=aPoint,(*(BOOL(*)(id,SEL,id))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],(id)self->isa))&&
(objcT4=aPoint,(*(int(*)(id,SEL))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]))==self->xLoc&&(objcT5=aPoint,(*(int(*)(id,SEL))_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]))==self->yLoc;
}

static BOOL i_Point_isBelow_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT6;

# 103 "point.m"
return self->yLoc>(objcT6=aPoint,(*(int(*)(id,SEL))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
}

static BOOL i_Point_isAbove_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT7;

# 108 "point.m"
return self->yLoc<(objcT7=aPoint,(*(int(*)(id,SEL))_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4]));
}

static BOOL i_Point_isLeft_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT8;

# 113 "point.m"
return self->xLoc<(objcT8=aPoint,(*(int(*)(id,SEL))_imp(objcT8,selTransTbl[3]))(objcT8,selTransTbl[3]));
}

static BOOL i_Point_isRight_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT9;

# 118 "point.m"
return self->xLoc>(objcT9=aPoint,(*(int(*)(id,SEL))_imp(objcT9,selTransTbl[3]))(objcT9,selTransTbl[3]));
}

# 128 "point.m"
static id i_Point_moveBy_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT10,objcT11;
self->
# 130 "point.m"
xLoc+=(objcT10=aPoint,(*(int(*)(id,SEL))_imp(objcT10,selTransTbl[3]))(objcT10,selTransTbl[3]));self->
yLoc+=(objcT11=aPoint,(*(int(*)(id,SEL))_imp(objcT11,selTransTbl[4]))(objcT11,selTransTbl[4]));
return(id)self;
}

static id i_Point_moveBy__(struct Point_PRIVATE *self,SEL _cmd,int x,int y)
{self->
xLoc+=x;self->
yLoc+=y;
return(id)self;
}

static id i_Point_moveTo_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT12,objcT13;
self->
# 144 "point.m"
xLoc=(objcT12=aPoint,(*(int(*)(id,SEL))_imp(objcT12,selTransTbl[3]))(objcT12,selTransTbl[3]));self->
yLoc=(objcT13=aPoint,(*(int(*)(id,SEL))_imp(objcT13,selTransTbl[4]))(objcT13,selTransTbl[4]));
return(id)self;
}

static id i_Point_plus_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT14,objcT15,objcT16;

# 151 "point.m"
return(objcT14=self->isa,(*(id(*)(id,SEL,int,int))_imp(objcT14,selTransTbl[0]))(objcT14,selTransTbl[0],self->xLoc+(objcT15=aPoint,(*(int(*)(id,SEL))_imp(objcT15,selTransTbl[3]))(objcT15,selTransTbl[3])),self->yLoc+(objcT16=aPoint,(*(int(*)(id,SEL))_imp(objcT16,selTransTbl[4]))(objcT16,selTransTbl[4]))));
}
static id i_Point_translateBy_(struct Point_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT17,objcT18,objcT19;

# 155 "point.m"
return(objcT17=self->isa,(*(id(*)(id,SEL,int,int))_imp(objcT17,selTransTbl[0]))(objcT17,selTransTbl[0],self->xLoc+(objcT18=aPoint,(*(int(*)(id,SEL))_imp(objcT18,selTransTbl[3]))(objcT18,selTransTbl[3])),self->yLoc+(objcT19=aPoint,(*(int(*)(id,SEL))_imp(objcT19,selTransTbl[4]))(objcT19,selTransTbl[4]))));
}

# 164 "point.m"
static id i_Point_printOn_(struct Point_PRIVATE *self,SEL _cmd,IOD aFile)
{
printf("(%i,%i)",self->xLoc,self->yLoc);
return(id)self;
}


static id i_Point_fileOutOn_(struct Point_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT20,objcT21,objcT22;

# 173 "point.m"
(objcT20=_Point.clsSuper,(*_impSuper(objcT20,selTransTbl[5]))((id)self,selTransTbl[5],aFiler));
(objcT21=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT21,selTransTbl[6]))(objcT21,selTransTbl[6], &self->xLoc,'i'));
(objcT22=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT22,selTransTbl[6]))(objcT22,selTransTbl[6], &self->yLoc,'i'));
return(id)self;
}

static id i_Point_fileInFrom_(struct Point_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT23,objcT24,objcT25;

# 181 "point.m"
(objcT23=_Point.clsSuper,(*_impSuper(objcT23,selTransTbl[7]))((id)self,selTransTbl[7],aFiler));
(objcT24=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT24,selTransTbl[8]))(objcT24,selTransTbl[8], &self->xLoc,'i'));
(objcT25=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT25,selTransTbl[8]))(objcT25,selTransTbl[8], &self->yLoc,'i'));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Point_clsDispatchTbl[] ={
{"new",(id (*)())c_Point_new},
{"x:y:",(id (*)())c_Point_x_y_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Point_nstDispatchTbl[] ={
{"x:y:",(id (*)())i_Point_x_y_},
{"x:",(id (*)())i_Point_x_},
{"y:",(id (*)())i_Point_y_},
{"x",(id (*)())i_Point_x},
{"y",(id (*)())i_Point_y},
{"hash",(id (*)())i_Point_hash},
{"isEqual:",(id (*)())i_Point_isEqual_},
{"isBelow:",(id (*)())i_Point_isBelow_},
{"isAbove:",(id (*)())i_Point_isAbove_},
{"isLeft:",(id (*)())i_Point_isLeft_},
{"isRight:",(id (*)())i_Point_isRight_},
{"moveBy:",(id (*)())i_Point_moveBy_},
{"moveBy::",(id (*)())i_Point_moveBy__},
{"moveTo:",(id (*)())i_Point_moveTo_},
{"plus:",(id (*)())i_Point_plus_},
{"translateBy:",(id (*)())i_Point_translateBy_},
{"printOn:",(id (*)())i_Point_printOn_},
{"fileOutOn:",(id (*)())i_Point_fileOutOn_},
{"fileInFrom:",(id (*)())i_Point_fileInFrom_},
{(char*)0,(id (*)())0}
};
id Point = (id)&_Point;
id  *OBJCCLASS_Point(void) { return &Point; }
struct _SHARED  _Point = {
  (id)&__Point,
  (id)&_Object,
  "Point",
  0,
  sizeof(struct Point_PRIVATE),
  19,
  _Point_nstDispatchTbl,
  41,
  &point_modDesc,
  0,
  (id)0,
  &Point,
};
id  OBJCCFUNC_Point(void) { return (id)&_Point; }
id  OBJCCSUPER_Point(void) { return _Point.clsSuper; }
struct _SHARED __Point = {
  (id)&__Object,
  (id)&__Object,
  "Point",
  0,
  sizeof(struct _SHARED),
  2,
  _Point_clsDispatchTbl,
  34,
  &point_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Point(void) { return (id)&__Point; }
id  OBJCMSUPER_Point(void) { return __Point.clsSuper; }
static char *_selTransTbl[] ={
"x:y:",
"new",
"isKindOf:",
"x",
"y",
"fileOutOn:",
"fileOut:type:",
"fileInFrom:",
"fileIn:type:",
0
};
struct modDescriptor point_modDesc = {
  "point",
  "objc3.3.19",
  0L,
  0,
  0,
  &Point,
  9,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_point(void)
{
  selTransTbl = _selTransTbl;
  return &point_modDesc;
}
int _OBJCPOSTLINK_point = 1;


