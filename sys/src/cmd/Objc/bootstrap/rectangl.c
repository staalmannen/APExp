# 1 "rectangl.m"
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
extern struct modDescriptor  *_OBJCBIND_rectangl(void);
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
extern struct modDescriptor rectangl_modDesc;

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

# 32 "./rectangl.h"
struct Rectangle_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./rectangl.h"
id origin;
id corner;};

# 32 "./rectangl.h"
extern id  Rectangle;

# 32 "./rectangl.h"
extern struct _SHARED _Rectangle;
extern struct _SHARED __Rectangle;


# 32 "./point.h"
extern id  Point;

# 36 "rectangl.m"
static id c_Rectangle_new(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2;

# 38 "rectangl.m"
return(objcT0=(id)self,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(objcT1=Point,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1])),(objcT2=Point,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]))));
}

static id c_Rectangle_origin_corner_(struct Rectangle_PRIVATE *self,SEL _cmd,id p,id q)
{
id objcT3,objcT4;

# 43 "rectangl.m"
return(objcT3=(objcT4=__Rectangle.clsSuper,(*_impSuper(objcT4,selTransTbl[1]))((id)self,selTransTbl[1])),(*_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0],p,q));
}

static id i_Rectangle_origin_extent_(struct Rectangle_PRIVATE *self,SEL _cmd,id p,id q)
{
id objcT5;

# 48 "rectangl.m"
return(objcT5=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2],_cmd));
}

static id c_Rectangle_origin_extent_(struct Rectangle_PRIVATE *self,SEL _cmd,id p,id q)
{
id objcT6,objcT7;

# 53 "rectangl.m"
return(objcT6=(objcT7=__Rectangle.clsSuper,(*_impSuper(objcT7,selTransTbl[1]))((id)self,selTransTbl[1])),(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3],p,q));
}

static id c_Rectangle_origin__corner__(struct Rectangle_PRIVATE *self,SEL _cmd,int x1,int y1,int x2,int y2)
{
id objcT8,objcT9,objcT10;

# 58 "rectangl.m"
return(objcT8=(objcT9=(objcT10=__Rectangle.clsSuper,(*_impSuper(objcT10,selTransTbl[1]))((id)self,selTransTbl[1])),(*(id(*)(id,SEL,int,int))_imp(objcT9,selTransTbl[4]))(objcT9,selTransTbl[4],x1,y1)),(*(id(*)(id,SEL,int,int))_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5],x2,y2));
}

static id c_Rectangle_origin__extent__(struct Rectangle_PRIVATE *self,SEL _cmd,int x,int y,int w,int h)
{
id objcT11,objcT12,objcT13;

# 63 "rectangl.m"
return(objcT11=(objcT12=(objcT13=__Rectangle.clsSuper,(*_impSuper(objcT13,selTransTbl[1]))((id)self,selTransTbl[1])),(*(id(*)(id,SEL,int,int))_imp(objcT12,selTransTbl[4]))(objcT12,selTransTbl[4],x,y)),(*(id(*)(id,SEL,int,int))_imp(objcT11,selTransTbl[6]))(objcT11,selTransTbl[6],w,h));
}

static id i_Rectangle_copy(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT14,objcT15,objcT16,objcT17;

# 68 "rectangl.m"
return(objcT14=(objcT15=_Rectangle.clsSuper,(*_impSuper(objcT15,selTransTbl[7]))((id)self,selTransTbl[7])),(*_imp(objcT14,selTransTbl[0]))(objcT14,selTransTbl[0],(objcT16=self->origin,(*_imp(objcT16,selTransTbl[7]))(objcT16,selTransTbl[7])),(objcT17=self->corner,(*_imp(objcT17,selTransTbl[7]))(objcT17,selTransTbl[7]))));
}

static id i_Rectangle_deepCopy(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19,objcT20,objcT21;

# 73 "rectangl.m"
return(objcT18=(objcT19=_Rectangle.clsSuper,(*_impSuper(objcT19,selTransTbl[7]))((id)self,selTransTbl[7])),(*_imp(objcT18,selTransTbl[0]))(objcT18,selTransTbl[0],(objcT20=self->origin,(*_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8])),(objcT21=self->corner,(*_imp(objcT21,selTransTbl[8]))(objcT21,selTransTbl[8]))));
}

static id i_Rectangle_free(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT22,objcT23,objcT24;
self->
# 78 "rectangl.m"
corner=(objcT22=self->corner,(*_imp(objcT22,selTransTbl[9]))(objcT22,selTransTbl[9]));self->
origin=(objcT23=self->origin,(*_imp(objcT23,selTransTbl[9]))(objcT23,selTransTbl[9]));
return(objcT24=_Rectangle.clsSuper,(*_impSuper(objcT24,selTransTbl[9]))((id)self,selTransTbl[9]));
}

# 90 "rectangl.m"
static id i_Rectangle_origin_(struct Rectangle_PRIVATE *self,SEL _cmd,id p)
{self->
origin=p;
return(id)self;
}

static id i_Rectangle_corner_(struct Rectangle_PRIVATE *self,SEL _cmd,id q)
{self->
corner=q;
return(id)self;
}

static id i_Rectangle_origin_corner_(struct Rectangle_PRIVATE *self,SEL _cmd,id p,id q)
{
id objcT25,objcT26;

# 104 "rectangl.m"
(objcT25=(id)self,(*_imp(objcT25,selTransTbl[10]))(objcT25,selTransTbl[10],p));
(objcT26=(id)self,(*_imp(objcT26,selTransTbl[11]))(objcT26,selTransTbl[11],q));
return(id)self;
}

static id i_Rectangle_extent__(struct Rectangle_PRIVATE *self,SEL _cmd,int w,int h)
{
id objcT27,objcT28,objcT29,objcT30;

# 111 "rectangl.m"
(objcT27=(id)self,(*_imp(objcT27,selTransTbl[11]))(objcT27,selTransTbl[11],(objcT28=Point,(*(id(*)(id,SEL,int,int))_imp(objcT28,selTransTbl[12]))(objcT28,selTransTbl[12],(objcT29=self->origin,(*(int(*)(id,SEL))_imp(objcT29,selTransTbl[13]))(objcT29,selTransTbl[13]))+w,(objcT30=self->origin,(*(int(*)(id,SEL))_imp(objcT30,selTransTbl[14]))(objcT30,selTransTbl[14]))+h))));
return(id)self;
}

static id i_Rectangle_extent_(struct Rectangle_PRIVATE *self,SEL _cmd,id q)
{
id objcT31,objcT32,objcT33;

# 117 "rectangl.m"
(objcT31=(id)self,(*(id(*)(id,SEL,int,int))_imp(objcT31,selTransTbl[6]))(objcT31,selTransTbl[6],(objcT32=q,(*(int(*)(id,SEL))_imp(objcT32,selTransTbl[13]))(objcT32,selTransTbl[13])),(objcT33=q,(*(int(*)(id,SEL))_imp(objcT33,selTransTbl[14]))(objcT33,selTransTbl[14]))));
return(id)self;
}

static id i_Rectangle_origin__(struct Rectangle_PRIVATE *self,SEL _cmd,int x1,int y1)
{
id objcT34,objcT35;

# 123 "rectangl.m"
return(objcT34=(id)self,(*_imp(objcT34,selTransTbl[10]))(objcT34,selTransTbl[10],(objcT35=Point,(*(id(*)(id,SEL,int,int))_imp(objcT35,selTransTbl[12]))(objcT35,selTransTbl[12],x1,y1))));
}

static id i_Rectangle_corner__(struct Rectangle_PRIVATE *self,SEL _cmd,int x1,int y1)
{
id objcT36,objcT37;

# 128 "rectangl.m"
return(objcT36=(id)self,(*_imp(objcT36,selTransTbl[11]))(objcT36,selTransTbl[11],(objcT37=Point,(*(id(*)(id,SEL,int,int))_imp(objcT37,selTransTbl[12]))(objcT37,selTransTbl[12],x1,y1))));
}

# 138 "rectangl.m"
static BOOL i_Rectangle_contains_(struct Rectangle_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT38,objcT39,objcT40,objcT41,objcT42;
id objcT43;

# 140 "rectangl.m"
int xLoc=(objcT38=aPoint,(*(int(*)(id,SEL))_imp(objcT38,selTransTbl[13]))(objcT38,selTransTbl[13]));
int yLoc=(objcT39=aPoint,(*(int(*)(id,SEL))_imp(objcT39,selTransTbl[14]))(objcT39,selTransTbl[14]));
return((objcT40=self->origin,(*(int(*)(id,SEL))_imp(objcT40,selTransTbl[13]))(objcT40,selTransTbl[13]))<=xLoc&&xLoc<=(objcT41=self->corner,(*(int(*)(id,SEL))_imp(objcT41,selTransTbl[13]))(objcT41,selTransTbl[13])))&&
((objcT42=self->origin,(*(int(*)(id,SEL))_imp(objcT42,selTransTbl[14]))(objcT42,selTransTbl[14]))<=yLoc&&yLoc<=(objcT43=self->corner,(*(int(*)(id,SEL))_imp(objcT43,selTransTbl[14]))(objcT43,selTransTbl[14])));
}

static unsigned i_Rectangle_hash(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT44,objcT45;

# 148 "rectangl.m"
return(objcT44=self->origin,(*(unsigned(*)(id,SEL))_imp(objcT44,selTransTbl[15]))(objcT44,selTransTbl[15]))^(objcT45=self->corner,(*(unsigned(*)(id,SEL))_imp(objcT45,selTransTbl[15]))(objcT45,selTransTbl[15]));
}

static BOOL i_Rectangle_isEqual_(struct Rectangle_PRIVATE *self,SEL _cmd,id aRectangle)
{
id objcT46,objcT47,objcT48,objcT49,objcT50;
return(objcT46=aRectangle,(*(BOOL(*)(id,SEL,id))_imp(objcT46,selTransTbl[16]))(objcT46,selTransTbl[16],(id)self->isa))&&
(objcT47=self->origin,(*(BOOL(*)(id,SEL,id))_imp(objcT47,selTransTbl[17]))(objcT47,selTransTbl[17],(objcT48=aRectangle,(*_imp(objcT48,selTransTbl[18]))(objcT48,selTransTbl[18]))))&&
(objcT49=self->corner,(*(BOOL(*)(id,SEL,id))_imp(objcT49,selTransTbl[17]))(objcT49,selTransTbl[17],(objcT50=aRectangle,(*_imp(objcT50,selTransTbl[19]))(objcT50,selTransTbl[19]))));
}

# 166 "rectangl.m"
static int i_Rectangle_left(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT51;

# 168 "rectangl.m"
return(objcT51=self->origin,(*(int(*)(id,SEL))_imp(objcT51,selTransTbl[13]))(objcT51,selTransTbl[13]));
}

static int i_Rectangle_right(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT52;

# 173 "rectangl.m"
return(objcT52=self->corner,(*(int(*)(id,SEL))_imp(objcT52,selTransTbl[13]))(objcT52,selTransTbl[13]));
}

static int i_Rectangle_top(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT53;

# 178 "rectangl.m"
return(objcT53=self->origin,(*(int(*)(id,SEL))_imp(objcT53,selTransTbl[14]))(objcT53,selTransTbl[14]));
}

static int i_Rectangle_bottom(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT54;

# 183 "rectangl.m"
return(objcT54=self->corner,(*(int(*)(id,SEL))_imp(objcT54,selTransTbl[14]))(objcT54,selTransTbl[14]));
}

static int i_Rectangle_width(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT55,objcT56;

# 188 "rectangl.m"
return(objcT55=self->corner,(*(int(*)(id,SEL))_imp(objcT55,selTransTbl[13]))(objcT55,selTransTbl[13]))-(objcT56=self->origin,(*(int(*)(id,SEL))_imp(objcT56,selTransTbl[13]))(objcT56,selTransTbl[13]));
}

static int i_Rectangle_height(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT57,objcT58;

# 193 "rectangl.m"
return(objcT57=self->corner,(*(int(*)(id,SEL))_imp(objcT57,selTransTbl[14]))(objcT57,selTransTbl[14]))-(objcT58=self->origin,(*(int(*)(id,SEL))_imp(objcT58,selTransTbl[14]))(objcT58,selTransTbl[14]));
}

static id i_Rectangle_origin(struct Rectangle_PRIVATE *self,SEL _cmd)
{
return self->origin;
}

static id i_Rectangle_topLeft(struct Rectangle_PRIVATE *self,SEL _cmd)
{
return self->origin;
}

static id i_Rectangle_topRight(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT59,objcT60,objcT61;

# 208 "rectangl.m"
return(objcT59=Point,(*(id(*)(id,SEL,int,int))_imp(objcT59,selTransTbl[12]))(objcT59,selTransTbl[12],(objcT60=self->corner,(*(int(*)(id,SEL))_imp(objcT60,selTransTbl[13]))(objcT60,selTransTbl[13])),(objcT61=self->origin,(*(int(*)(id,SEL))_imp(objcT61,selTransTbl[14]))(objcT61,selTransTbl[14]))));
}

static id i_Rectangle_topCenter(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT62,objcT63,objcT64,objcT65;

# 213 "rectangl.m"
return(objcT62=Point,(*(id(*)(id,SEL,int,int))_imp(objcT62,selTransTbl[12]))(objcT62,selTransTbl[12],(objcT63=self->corner,(*(int(*)(id,SEL))_imp(objcT63,selTransTbl[13]))(objcT63,selTransTbl[13]))+(objcT64=(id)self,(*(int(*)(id,SEL))_imp(objcT64,selTransTbl[20]))(objcT64,selTransTbl[20]))/2,(objcT65=self->origin,(*(int(*)(id,SEL))_imp(objcT65,selTransTbl[14]))(objcT65,selTransTbl[14]))));
}

static id i_Rectangle_corner(struct Rectangle_PRIVATE *self,SEL _cmd)
{
return self->corner;
}

static id i_Rectangle_bottomLeft(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT66,objcT67,objcT68;

# 223 "rectangl.m"
return(objcT66=Point,(*(id(*)(id,SEL,int,int))_imp(objcT66,selTransTbl[12]))(objcT66,selTransTbl[12],(objcT67=self->origin,(*(int(*)(id,SEL))_imp(objcT67,selTransTbl[13]))(objcT67,selTransTbl[13])),(objcT68=self->corner,(*(int(*)(id,SEL))_imp(objcT68,selTransTbl[14]))(objcT68,selTransTbl[14]))));
}

static id i_Rectangle_bottomCenter(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT69,objcT70,objcT71,objcT72;

# 228 "rectangl.m"
return(objcT69=Point,(*(id(*)(id,SEL,int,int))_imp(objcT69,selTransTbl[12]))(objcT69,selTransTbl[12],(objcT70=self->corner,(*(int(*)(id,SEL))_imp(objcT70,selTransTbl[13]))(objcT70,selTransTbl[13]))+(objcT71=(id)self,(*(int(*)(id,SEL))_imp(objcT71,selTransTbl[20]))(objcT71,selTransTbl[20]))/2,(objcT72=self->corner,(*(int(*)(id,SEL))_imp(objcT72,selTransTbl[14]))(objcT72,selTransTbl[14]))));
}

static id i_Rectangle_bottomRight(struct Rectangle_PRIVATE *self,SEL _cmd)
{
return self->corner;
}

static id i_Rectangle_center(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT73,objcT74,objcT75,objcT76,objcT77;

# 238 "rectangl.m"
int x=(objcT73=(id)self,(*(int(*)(id,SEL))_imp(objcT73,selTransTbl[21]))(objcT73,selTransTbl[21]))+(objcT74=(id)self,(*(int(*)(id,SEL))_imp(objcT74,selTransTbl[20]))(objcT74,selTransTbl[20]))/2;
int y=(objcT75=(id)self,(*(int(*)(id,SEL))_imp(objcT75,selTransTbl[22]))(objcT75,selTransTbl[22]))+(objcT76=(id)self,(*(int(*)(id,SEL))_imp(objcT76,selTransTbl[23]))(objcT76,selTransTbl[23]))/2;
return(objcT77=Point,(*(id(*)(id,SEL,int,int))_imp(objcT77,selTransTbl[12]))(objcT77,selTransTbl[12],x,y));
}

static id i_Rectangle_leftCenter(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT78,objcT79,objcT80,objcT81;

# 245 "rectangl.m"
int y=(objcT78=(id)self,(*(int(*)(id,SEL))_imp(objcT78,selTransTbl[22]))(objcT78,selTransTbl[22]))+(objcT79=(id)self,(*(int(*)(id,SEL))_imp(objcT79,selTransTbl[23]))(objcT79,selTransTbl[23]))/2;
return(objcT80=Point,(*(id(*)(id,SEL,int,int))_imp(objcT80,selTransTbl[12]))(objcT80,selTransTbl[12],(objcT81=self->origin,(*(int(*)(id,SEL))_imp(objcT81,selTransTbl[13]))(objcT81,selTransTbl[13])),y));
}

static id i_Rectangle_rightCenter(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT82,objcT83,objcT84,objcT85;

# 251 "rectangl.m"
int y=(objcT82=(id)self,(*(int(*)(id,SEL))_imp(objcT82,selTransTbl[22]))(objcT82,selTransTbl[22]))+(objcT83=(id)self,(*(int(*)(id,SEL))_imp(objcT83,selTransTbl[23]))(objcT83,selTransTbl[23]))/2;
return(objcT84=Point,(*(id(*)(id,SEL,int,int))_imp(objcT84,selTransTbl[12]))(objcT84,selTransTbl[12],(objcT85=self->corner,(*(int(*)(id,SEL))_imp(objcT85,selTransTbl[13]))(objcT85,selTransTbl[13])),y));
}

static id i_Rectangle_extent(struct Rectangle_PRIVATE *self,SEL _cmd)
{
id objcT86,objcT87,objcT88;

# 257 "rectangl.m"
return(objcT86=Point,(*(id(*)(id,SEL,int,int))_imp(objcT86,selTransTbl[12]))(objcT86,selTransTbl[12],(objcT87=(id)self,(*(int(*)(id,SEL))_imp(objcT87,selTransTbl[20]))(objcT87,selTransTbl[20])),(objcT88=(id)self,(*(int(*)(id,SEL))_imp(objcT88,selTransTbl[23]))(objcT88,selTransTbl[23]))));
}

static id i_Rectangle_quickMerge_(struct Rectangle_PRIVATE *self,SEL _cmd,id rect)
{
id objcT89,objcT90,objcT91,objcT92,objcT93;
id objcT94,objcT95,objcT96,objcT97,objcT98;
id objcT99,objcT100;

# 262 "rectangl.m"
id tmp;
int ax1,ay1,ax2,ay2;
int bx1,by1,bx2,by2;
int minx,miny,maxx,maxy;

tmp=(objcT89=(id)self,(*_imp(objcT89,selTransTbl[18]))(objcT89,selTransTbl[18]));
ax1=(objcT90=tmp,(*(int(*)(id,SEL))_imp(objcT90,selTransTbl[13]))(objcT90,selTransTbl[13]));
ay1=(objcT91=tmp,(*(int(*)(id,SEL))_imp(objcT91,selTransTbl[14]))(objcT91,selTransTbl[14]));
tmp=(objcT92=(id)self,(*_imp(objcT92,selTransTbl[19]))(objcT92,selTransTbl[19]));
ax2=(objcT93=tmp,(*(int(*)(id,SEL))_imp(objcT93,selTransTbl[13]))(objcT93,selTransTbl[13]));
ay2=(objcT94=tmp,(*(int(*)(id,SEL))_imp(objcT94,selTransTbl[14]))(objcT94,selTransTbl[14]));
tmp=(objcT95=rect,(*_imp(objcT95,selTransTbl[18]))(objcT95,selTransTbl[18]));
bx1=(objcT96=tmp,(*(int(*)(id,SEL))_imp(objcT96,selTransTbl[13]))(objcT96,selTransTbl[13]));
by1=(objcT97=tmp,(*(int(*)(id,SEL))_imp(objcT97,selTransTbl[14]))(objcT97,selTransTbl[14]));
tmp=(objcT98=rect,(*_imp(objcT98,selTransTbl[19]))(objcT98,selTransTbl[19]));
bx2=(objcT99=tmp,(*(int(*)(id,SEL))_imp(objcT99,selTransTbl[13]))(objcT99,selTransTbl[13]));
by2=(objcT100=tmp,(*(int(*)(id,SEL))_imp(objcT100,selTransTbl[14]))(objcT100,selTransTbl[14]));

minx=(ax1<bx1)?ax1:bx1;
miny=(ay1<by1)?ay1:by1;
maxx=(ax2>bx2)?ax2:bx2;
maxy=(ay2>by2)?ay2:by2;

if(ax1==minx&&ay1==miny&&ax2==maxx&&ay2==maxy)
{
return(id)self;
}
else
{
id objcT101;

# 291 "rectangl.m"
return(objcT101=Rectangle,(*(id(*)(id,SEL,int,int,int,int))_imp(objcT101,selTransTbl[24]))(objcT101,selTransTbl[24],minx,miny,maxx,maxy));
}
}

# 302 "rectangl.m"
static id i_Rectangle_moveBy_(struct Rectangle_PRIVATE *self,SEL _cmd,id aPoint)
{
id objcT102,objcT103;

# 304 "rectangl.m"
(objcT102=self->origin,(*_imp(objcT102,selTransTbl[25]))(objcT102,selTransTbl[25],aPoint));
(objcT103=self->corner,(*_imp(objcT103,selTransTbl[25]))(objcT103,selTransTbl[25],aPoint));
return(id)self;
}

static id i_Rectangle_translateBy_(struct Rectangle_PRIVATE *self,SEL _cmd,id p)
{
id objcT104,objcT105,objcT106;

# 311 "rectangl.m"
return(objcT104=self->isa,(*_imp(objcT104,selTransTbl[0]))(objcT104,selTransTbl[0],(objcT105=self->origin,(*_imp(objcT105,selTransTbl[26]))(objcT105,selTransTbl[26],p)),(objcT106=self->corner,(*_imp(objcT106,selTransTbl[26]))(objcT106,selTransTbl[26],p))));
}

static id i_Rectangle_align_with_(struct Rectangle_PRIVATE *self,SEL _cmd,id p1,id p2)
{
id objcT107,objcT108,objcT109,objcT110,objcT111;
id objcT112,objcT113,objcT114,objcT115;

# 316 "rectangl.m"
int x=(objcT107=p2,(*(int(*)(id,SEL))_imp(objcT107,selTransTbl[13]))(objcT107,selTransTbl[13]))-(objcT108=p1,(*(int(*)(id,SEL))_imp(objcT108,selTransTbl[13]))(objcT108,selTransTbl[13]));
int y=(objcT109=p2,(*(int(*)(id,SEL))_imp(objcT109,selTransTbl[14]))(objcT109,selTransTbl[14]))-(objcT110=p1,(*(int(*)(id,SEL))_imp(objcT110,selTransTbl[14]))(objcT110,selTransTbl[14]));
return(objcT111=self->isa,(*(id(*)(id,SEL,int,int,int,int))_imp(objcT111,selTransTbl[24]))(objcT111,selTransTbl[24],(objcT112=self->origin,(*(int(*)(id,SEL))_imp(objcT112,selTransTbl[13]))(objcT112,selTransTbl[13]))+x,(objcT113=self->origin,(*(int(*)(id,SEL))_imp(objcT113,selTransTbl[14]))(objcT113,selTransTbl[14]))+y,(objcT114=self->corner,(*(int(*)(id,SEL))_imp(objcT114,selTransTbl[13]))(objcT114,selTransTbl[13]))+x,(objcT115=self->corner,(*(int(*)(id,SEL))_imp(objcT115,selTransTbl[14]))(objcT115,selTransTbl[14]))+y));
}

# 327 "rectangl.m"
static id i_Rectangle_printOn_(struct Rectangle_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT116,objcT117;

# 329 "rectangl.m"
fprintf(aFile,"(");
(objcT116=self->origin,(*(id(*)(id,SEL,IOD))_imp(objcT116,selTransTbl[27]))(objcT116,selTransTbl[27],aFile));
fprintf(aFile,",");
(objcT117=self->corner,(*(id(*)(id,SEL,IOD))_imp(objcT117,selTransTbl[27]))(objcT117,selTransTbl[27],aFile));
fprintf(aFile,")");
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Rectangle_clsDispatchTbl[] ={
{"new",(id (*)())c_Rectangle_new},
{"origin:corner:",(id (*)())c_Rectangle_origin_corner_},
{"origin:extent:",(id (*)())c_Rectangle_origin_extent_},
{"origin::corner::",(id (*)())c_Rectangle_origin__corner__},
{"origin::extent::",(id (*)())c_Rectangle_origin__extent__},
{(char*)0,(id (*)())0}
};
static struct _SLT _Rectangle_nstDispatchTbl[] ={
{"origin:extent:",(id (*)())i_Rectangle_origin_extent_},
{"copy",(id (*)())i_Rectangle_copy},
{"deepCopy",(id (*)())i_Rectangle_deepCopy},
{"free",(id (*)())i_Rectangle_free},
{"origin:",(id (*)())i_Rectangle_origin_},
{"corner:",(id (*)())i_Rectangle_corner_},
{"origin:corner:",(id (*)())i_Rectangle_origin_corner_},
{"extent::",(id (*)())i_Rectangle_extent__},
{"extent:",(id (*)())i_Rectangle_extent_},
{"origin::",(id (*)())i_Rectangle_origin__},
{"corner::",(id (*)())i_Rectangle_corner__},
{"contains:",(id (*)())i_Rectangle_contains_},
{"hash",(id (*)())i_Rectangle_hash},
{"isEqual:",(id (*)())i_Rectangle_isEqual_},
{"left",(id (*)())i_Rectangle_left},
{"right",(id (*)())i_Rectangle_right},
{"top",(id (*)())i_Rectangle_top},
{"bottom",(id (*)())i_Rectangle_bottom},
{"width",(id (*)())i_Rectangle_width},
{"height",(id (*)())i_Rectangle_height},
{"origin",(id (*)())i_Rectangle_origin},
{"topLeft",(id (*)())i_Rectangle_topLeft},
{"topRight",(id (*)())i_Rectangle_topRight},
{"topCenter",(id (*)())i_Rectangle_topCenter},
{"corner",(id (*)())i_Rectangle_corner},
{"bottomLeft",(id (*)())i_Rectangle_bottomLeft},
{"bottomCenter",(id (*)())i_Rectangle_bottomCenter},
{"bottomRight",(id (*)())i_Rectangle_bottomRight},
{"center",(id (*)())i_Rectangle_center},
{"leftCenter",(id (*)())i_Rectangle_leftCenter},
{"rightCenter",(id (*)())i_Rectangle_rightCenter},
{"extent",(id (*)())i_Rectangle_extent},
{"quickMerge:",(id (*)())i_Rectangle_quickMerge_},
{"moveBy:",(id (*)())i_Rectangle_moveBy_},
{"translateBy:",(id (*)())i_Rectangle_translateBy_},
{"align:with:",(id (*)())i_Rectangle_align_with_},
{"printOn:",(id (*)())i_Rectangle_printOn_},
{(char*)0,(id (*)())0}
};
id Rectangle = (id)&_Rectangle;
id  *OBJCCLASS_Rectangle(void) { return &Rectangle; }
struct _SHARED  _Rectangle = {
  (id)&__Rectangle,
  (id)&_Object,
  "Rectangle",
  0,
  sizeof(struct Rectangle_PRIVATE),
  37,
  _Rectangle_nstDispatchTbl,
  41,
  &rectangl_modDesc,
  0,
  (id)0,
  &Rectangle,
};
id  OBJCCFUNC_Rectangle(void) { return (id)&_Rectangle; }
id  OBJCCSUPER_Rectangle(void) { return _Rectangle.clsSuper; }
struct _SHARED __Rectangle = {
  (id)&__Object,
  (id)&__Object,
  "Rectangle",
  0,
  sizeof(struct _SHARED),
  5,
  _Rectangle_clsDispatchTbl,
  34,
  &rectangl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Rectangle(void) { return (id)&__Rectangle; }
id  OBJCMSUPER_Rectangle(void) { return __Rectangle.clsSuper; }
static char *_selTransTbl[] ={
"origin:corner:",
"new",
"notImplemented:",
"origin:extent:",
"origin::",
"corner::",
"extent::",
"copy",
"deepCopy",
"free",
"origin:",
"corner:",
"x:y:",
"x",
"y",
"hash",
"isKindOf:",
"isEqual:",
"origin",
"corner",
"width",
"left",
"top",
"height",
"origin::corner::",
"moveBy:",
"translateBy:",
"printOn:",
0
};
struct modDescriptor rectangl_modDesc = {
  "rectangl",
  "objc3.3.19",
  0L,
  0,
  0,
  &Rectangle,
  28,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_rectangl(void)
{
  selTransTbl = _selTransTbl;
  return &rectangl_modDesc;
}
int _OBJCPOSTLINK_rectangl = 1;


