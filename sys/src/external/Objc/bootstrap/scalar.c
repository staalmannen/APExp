# 1 "scalar.m"
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
extern struct modDescriptor  *_OBJCBIND_scalar(void);
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
extern struct modDescriptor scalar_modDesc;

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

# 32 "./../../include/objpak/ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
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
# 22 "./type.h"
extern id t_unknown;
extern id t_void;
extern id t_char;
extern id t_bool;
extern id t_int;
extern id t_long;
extern id t_uns;
extern id t_double;
extern id t_str;
extern id t_sel;
extern id t_id;
# 24 "./scalar.h"
struct Scalar_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 26 "./scalar.h"
id type;
union{
int un_int;
unsigned un_uns;
long un_long;
char un_char;
float un_float;
double un_double;
char*un_str;
void*un_voidstar;
FILE*un_fp;
}u;};

# 24 "./scalar.h"
extern id  Scalar;

# 24 "./scalar.h"
extern struct _SHARED _Scalar;
extern struct _SHARED __Scalar;


# 38 "scalar.m"
static id i_Scalar_type(struct Scalar_PRIVATE *self,SEL _cmd)
{
return self->type;
}

static id i_Scalar_errorconvert(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1;

# 45 "scalar.m"
gstderr();(objcT0=self->type,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));gnormal();
return(objcT1=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],"don't know how to convert type"));
}

static int i_Scalar_u_int(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 51 "scalar.m"
if(self->type==t_int)return self->u.un_int;
if(self->type==t_char)return(int)self->u.un_char;
if(self->type==t_long)return(int)self->u.un_long;
if(self->type==t_uns)return(int)self->u.un_uns;
if(self->type==t_double)return(int)self->u.un_double;
(objcT2=(id)self,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return 0;
}

static unsigned i_Scalar_u_uns(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 62 "scalar.m"
if(self->type==t_uns)return self->u.un_uns;
if(self->type==t_int)return(unsigned)self->u.un_int;
if(self->type==t_char)return(unsigned)self->u.un_char;
if(self->type==t_long)return(unsigned)self->u.un_long;
(objcT3=(id)self,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
return 0;
}

static id i_Scalar_u_int_(struct Scalar_PRIVATE *self,SEL _cmd,int x)
{self->
type=t_int;self->u.un_int=x;return(id)self;
}

static id i_Scalar_u_uns_(struct Scalar_PRIVATE *self,SEL _cmd,unsigned x)
{self->
type=t_uns;self->u.un_uns=x;return(id)self;
}

static id i_Scalar_u_long_(struct Scalar_PRIVATE *self,SEL _cmd,long x)
{self->
type=t_long;self->u.un_long=x;return(id)self;
}

static long i_Scalar_u_long(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 87 "scalar.m"
if(self->type==t_long)return self->u.un_long;
if(self->type==t_int)return(long)self->u.un_int;
(objcT4=(id)self,(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2]));
return 0;
}

static id i_Scalar_u_char_(struct Scalar_PRIVATE *self,SEL _cmd,char x)
{self->
type=t_char;self->u.un_char=x;return(id)self;
}

static char i_Scalar_u_char(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 100 "scalar.m"
if(self->type==t_char)return self->u.un_char;
if(self->type==t_int)return(char)self->u.un_int;
(objcT5=(id)self,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]));
return 0;
}

static id i_Scalar_u_float_(struct Scalar_PRIVATE *self,SEL _cmd,float x)
{self->
type=t_double;self->u.un_float=x;return(id)self;
}

static float i_Scalar_u_float(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 113 "scalar.m"
if(self->type==t_double)return self->u.un_float;
if(self->type==t_int)return(float)self->u.un_int;
(objcT6=(id)self,(*_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2]));
return 0;
}

static id i_Scalar_u_double_(struct Scalar_PRIVATE *self,SEL _cmd,double x)
{self->
type=t_double;self->u.un_double=x;return(id)self;
}

static double i_Scalar_u_double(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT7;

# 126 "scalar.m"
if(self->type==t_double)return self->u.un_double;
if(self->type==t_int)return(double)self->u.un_int;
(objcT7=(id)self,(*_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2]));
return 0;
}

static id i_Scalar_u_str_(struct Scalar_PRIVATE *self,SEL _cmd,char*x)
{
id objcT8;

# 134 "scalar.m"
if( !t_str)(objcT8=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT8,selTransTbl[1]))(objcT8,selTransTbl[1],"type not initialized"));self->
type=t_str;self->u.un_str=x;return(id)self;
}

static char*i_Scalar_u_str(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 140 "scalar.m"
if(self->type==t_str)return self->u.un_str;
(objcT9=(id)self,(*_imp(objcT9,selTransTbl[2]))(objcT9,selTransTbl[2]));
return(char*)0;
}

static id i_Scalar_u_voidstar_(struct Scalar_PRIVATE *self,SEL _cmd,void*x)
{self->
type=t_str;self->u.un_voidstar=x;return(id)self;
}

static void*i_Scalar_u_voidstar(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT10;

# 152 "scalar.m"
if(self->type==t_str)return self->u.un_voidstar;
(objcT10=(id)self,(*_imp(objcT10,selTransTbl[2]))(objcT10,selTransTbl[2]));
return(void*)0;
}

static id i_Scalar_u_fp_(struct Scalar_PRIVATE *self,SEL _cmd,FILE*x)
{self->
type=t_str;self->u.un_fp=x;return(id)self;
}

static FILE*i_Scalar_u_fp(struct Scalar_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 164 "scalar.m"
if(self->type==t_str)return(FILE*)self->u.un_fp;
(objcT11=(id)self,(*_imp(objcT11,selTransTbl[2]))(objcT11,selTransTbl[2]));
return(FILE*)0;
}

static BOOL i_Scalar_isEqual_(struct Scalar_PRIVATE *self,SEL _cmd,id x)
{
id objcT12;
return self->u.un_int==(objcT12=x,(*(int(*)(id,SEL))_imp(objcT12,selTransTbl[3]))(objcT12,selTransTbl[3]));
# 176 "scalar.m"
}

static BOOL i_Scalar_isZero(struct Scalar_PRIVATE *self,SEL _cmd)
{
return self->u.un_int==0;
}

static id i_Scalar_increment(struct Scalar_PRIVATE *self,SEL _cmd)
{self->
u.un_int++;
return(id)self;
}

static id i_Scalar_decrement(struct Scalar_PRIVATE *self,SEL _cmd)
{self->
u.un_int--;
return(id)self;
}

static id i_Scalar_printOn_(struct Scalar_PRIVATE *self,SEL _cmd,IOD x)
{
id objcT13;

# 197 "scalar.m"
if(self->type==t_int){fprintf(x,"%i",self->u.un_int);return(id)self;}
if(self->type==t_char){fprintf(x,"%c",self->u.un_char);return(id)self;}
if(self->type==t_long){fprintf(x,"%li",self->u.un_long);return(id)self;}
if(self->type==t_uns){fprintf(x,"%u",self->u.un_uns);return(id)self;}
if(self->type==t_double){fprintf(x,"%g",self->u.un_double);return(id)self;}
if(self->type==t_str){fprintf(x,"%s",self->u.un_str);return(id)self;}
(objcT13=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT13,selTransTbl[1]))(objcT13,selTransTbl[1],"don't know how to print scalar"));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Variable;
extern struct _SHARED _Variable;
extern struct _SHARED __Variable;
static struct _SLT _Scalar_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Scalar_nstDispatchTbl[] ={
{"type",(id (*)())i_Scalar_type},
{"errorconvert",(id (*)())i_Scalar_errorconvert},
{"u_int",(id (*)())i_Scalar_u_int},
{"u_uns",(id (*)())i_Scalar_u_uns},
{"u_int:",(id (*)())i_Scalar_u_int_},
{"u_uns:",(id (*)())i_Scalar_u_uns_},
{"u_long:",(id (*)())i_Scalar_u_long_},
{"u_long",(id (*)())i_Scalar_u_long},
{"u_char:",(id (*)())i_Scalar_u_char_},
{"u_char",(id (*)())i_Scalar_u_char},
{"u_float:",(id (*)())i_Scalar_u_float_},
{"u_float",(id (*)())i_Scalar_u_float},
{"u_double:",(id (*)())i_Scalar_u_double_},
{"u_double",(id (*)())i_Scalar_u_double},
{"u_str:",(id (*)())i_Scalar_u_str_},
{"u_str",(id (*)())i_Scalar_u_str},
{"u_voidstar:",(id (*)())i_Scalar_u_voidstar_},
{"u_voidstar",(id (*)())i_Scalar_u_voidstar},
{"u_fp:",(id (*)())i_Scalar_u_fp_},
{"u_fp",(id (*)())i_Scalar_u_fp},
{"isEqual:",(id (*)())i_Scalar_isEqual_},
{"isZero",(id (*)())i_Scalar_isZero},
{"increment",(id (*)())i_Scalar_increment},
{"decrement",(id (*)())i_Scalar_decrement},
{"printOn:",(id (*)())i_Scalar_printOn_},
{(char*)0,(id (*)())0}
};
id Scalar = (id)&_Scalar;
id  *OBJCCLASS_Scalar(void) { return &Scalar; }
struct _SHARED  _Scalar = {
  (id)&__Scalar,
  (id)&_Variable,
  "Scalar",
  0,
  sizeof(struct Scalar_PRIVATE),
  25,
  _Scalar_nstDispatchTbl,
  41,
  &scalar_modDesc,
  0,
  (id)0,
  &Scalar,
};
id  OBJCCFUNC_Scalar(void) { return (id)&_Scalar; }
id  OBJCCSUPER_Scalar(void) { return _Scalar.clsSuper; }
struct _SHARED __Scalar = {
  (id)&__Object,
  (id)&__Variable,
  "Scalar",
  0,
  sizeof(struct _SHARED),
  0,
  _Scalar_clsDispatchTbl,
  34,
  &scalar_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Scalar(void) { return (id)&__Scalar; }
id  OBJCMSUPER_Scalar(void) { return __Scalar.clsSuper; }
static char *_selTransTbl[] ={
"gen",
"error:",
"errorconvert",
"u_int",
0
};
struct modDescriptor scalar_modDesc = {
  "scalar",
  "objc3.3.19",
  0L,
  0,
  0,
  &Scalar,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_scalar(void)
{
  selTransTbl = _selTransTbl;
  return &scalar_modDesc;
}
int _OBJCPOSTLINK_scalar = 1;


