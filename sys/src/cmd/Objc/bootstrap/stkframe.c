# 1 "stkframe.m"
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
extern struct modDescriptor  *_OBJCBIND_stkframe(void);
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
extern struct modDescriptor stkframe_modDesc;

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
# 22 "./stkframe.h"
extern id topframe;
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./def.h"
extern id curdef;
# 22 "./symbol.h"
extern id s_void;
extern id s_char;
extern id s_bool;
extern id s_int;
extern id s_uns;
extern id s_long;
extern id s_double;
extern id s_str;
extern id s_sel;
extern id s_newblock;
extern id s_main;
extern id s_objcmain;
extern id s_id;
extern id s_nil;
extern id s_self;
extern id s_cmd;
extern id s_super;
extern id s_type;
extern id s_aFiler;
extern id s_fileIn;
extern id s_fileOut;
extern id s_fileInIdsFrom;
extern id s_fileOutIdsFor;
extern id s_returnval;
extern id s_returnflag;
extern id s_increfs;
extern id s_decrefs;
extern id s_idincref;
extern id s_iddecref;

BOOL istypeword(id sym);
BOOL isbuiltinfun(id sym);
int pragmatoggle(char*s);
void definebuiltintype(char*s);
void definebuiltinfun(char*s);
void definebuiltinvar(char*s);
# 42 "stkframe.m"
id topframe;
# 24 "./stkframe.h"
struct Stackframe_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 26 "./stkframe.h"
id vals;
id def;
id compound;
id previous,next;
BOOL quitframe;
BOOL breakframe;
BOOL contframe;
id returnval;};

# 24 "./stkframe.h"
extern id  Stackframe;

# 24 "./stkframe.h"
extern struct _SHARED _Stackframe;
extern struct _SHARED __Stackframe;


# 46 "stkframe.m"
static id i_Stackframe_next_(struct Stackframe_PRIVATE *self,SEL _cmd,id x)
{self->
next=x;
return(id)self;
}

static id i_Stackframe_previous_(struct Stackframe_PRIVATE *self,SEL _cmd,id x)
{self->
previous=x;
return(id)self;
}

static id i_Stackframe_next(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->next;
}

static id i_Stackframe_previous(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->previous;
}

static id c_Stackframe_push(struct Stackframe_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 70 "stkframe.m"
id frame=(objcT0=__Stackframe.clsSuper,(*_impSuper(objcT0,selTransTbl[0]))((id)self,selTransTbl[0]));
if(topframe){
id objcT1,objcT2;

# 72 "stkframe.m"
(objcT1=topframe,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],frame));
(objcT2=frame,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],topframe));
}
topframe=frame;
return frame;
}

static id c_Stackframe_pop(struct Stackframe_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 81 "stkframe.m"
if(topframe)topframe=(objcT3=topframe,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
return(id)0;
}

static id i_Stackframe_compound_(struct Stackframe_PRIVATE *self,SEL _cmd,id x)
{self->
compound=x;
return(id)self;
}

static id i_Stackframe_def(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->def;
}

static id i_Stackframe_def_(struct Stackframe_PRIVATE *self,SEL _cmd,id m)
{self->
compound=(id)0;self->
def=m;
return(id)self;
}

static id i_Stackframe_compound(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->compound;
}

static id i_Stackframe_lookupself(struct Stackframe_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 110 "stkframe.m"
return(objcT4=(id)self,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4],s_self));
}

static id i_Stackframe_lookuplocal_(struct Stackframe_PRIVATE *self,SEL _cmd,id sym)
{
id objcT5;

# 115 "stkframe.m"
return(objcT5=self->compound,(*_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5],sym));
}

static id i_Stackframe_lookupval_(struct Stackframe_PRIVATE *self,SEL _cmd,id sym)
{
id objcT6,objcT8;

# 120 "stkframe.m"
if((objcT6=self->vals,(*(BOOL(*)(id,SEL,id))_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6],sym))){
id objcT7;

# 121 "stkframe.m"
return(objcT7=self->vals,(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7],sym));
}
if((objcT8=self->compound,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5],sym))){
id objcT9,objcT10;

# 124 "stkframe.m"
(objcT9=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT9,selTransTbl[8]))(objcT9,selTransTbl[8],"Variable '%s' was not initialized",(objcT10=sym,(*(STR(*)(id,SEL))_imp(objcT10,selTransTbl[9]))(objcT10,selTransTbl[9]))));
return(id)self;
}else{
id objcT11;

# 127 "stkframe.m"
id e=(objcT11=(id)self,(*_imp(objcT11,selTransTbl[10]))(objcT11,selTransTbl[10]));
if(e){
id objcT12;

# 129 "stkframe.m"
return(objcT12=e,(*_imp(objcT12,selTransTbl[4]))(objcT12,selTransTbl[4],sym));
}else{
id objcT13,objcT14;

# 131 "stkframe.m"
(objcT13=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT13,selTransTbl[8]))(objcT13,selTransTbl[8],"Can't find variable '%s'",(objcT14=sym,(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[9]))(objcT14,selTransTbl[9]))));
return(id)0;
}
}
}

# 32 "./../../include/objpak/dictnary.h"
extern id  Dictionary;

# 137 "stkframe.m"
static id i_Stackframe_defval_as_(struct Stackframe_PRIVATE *self,SEL _cmd,id sym,id scalar)
{
id objcT16;

# 139 "stkframe.m"
if( !self->vals){
id objcT15;
self->
# 140 "stkframe.m"
vals=(objcT15=Dictionary,(*_imp(objcT15,selTransTbl[0]))(objcT15,selTransTbl[0]));
}
(objcT16=self->vals,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11],sym,scalar));
return(id)self;
}

static id i_Stackframe_enclosing(struct Stackframe_PRIVATE *self,SEL _cmd)
{
id objcT17;

# 148 "stkframe.m"
id f=(objcT17=(id)self,(*_imp(objcT17,selTransTbl[3]))(objcT17,selTransTbl[3]));
if(f){
if(self->compound){
# 155 "stkframe.m"
return f;
}else{
return(id)0;
}
}else{
return(id)0;
}
}

static id i_Stackframe_quitframe_(struct Stackframe_PRIVATE *self,SEL _cmd,BOOL x)
{self->
quitframe=x;self->breakframe=x;return(id)self;
}

static BOOL i_Stackframe_quitframe(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->quitframe;
}

static id i_Stackframe_breakframe_(struct Stackframe_PRIVATE *self,SEL _cmd,BOOL x)
{self->
breakframe=x;return(id)self;
}

static BOOL i_Stackframe_breakframe(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->breakframe;
}

static id i_Stackframe_contframe_(struct Stackframe_PRIVATE *self,SEL _cmd,BOOL x)
{self->
contframe=x;return(id)self;
}

static BOOL i_Stackframe_contframe(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->contframe;
}

static id i_Stackframe_exitframe(struct Stackframe_PRIVATE *self,SEL _cmd)
{
id objcT18;

# 196 "stkframe.m"
id frm;
for(frm=(id)self;frm;frm=(objcT18=frm,(*_imp(objcT18,selTransTbl[3]))(objcT18,selTransTbl[3]))){
id objcT19;

# 198 "stkframe.m"
(objcT19=frm,(*(id(*)(id,SEL,BOOL))_imp(objcT19,selTransTbl[12]))(objcT19,selTransTbl[12],(BOOL)1));
}
return(id)self;
}

static id i_Stackframe_returnval(struct Stackframe_PRIVATE *self,SEL _cmd)
{
return self->returnval;
}

static id i_Stackframe_returnval_(struct Stackframe_PRIVATE *self,SEL _cmd,id x)
{self->
returnval=x;return(id)self;
}

static id i_Stackframe_printBtOn_(struct Stackframe_PRIVATE *self,SEL _cmd,IOD d)
{
id objcT20;

# 215 "stkframe.m"
id frm;
int c=0;

for(frm=(id)self;frm;frm=(objcT20=frm,(*_imp(objcT20,selTransTbl[3]))(objcT20,selTransTbl[3]))){
id objcT21;

# 219 "stkframe.m"
if((objcT21=frm,(*_imp(objcT21,selTransTbl[13]))(objcT21,selTransTbl[13]))==(id)0){
id objcT22,objcT23;

# 220 "stkframe.m"
fprintf(d,"#%d  ",c++);(objcT22=(objcT23=frm,(*_imp(objcT23,selTransTbl[14]))(objcT23,selTransTbl[14])),(*(id(*)(id,SEL,IOD))_imp(objcT22,selTransTbl[15]))(objcT22,selTransTbl[15],d));
}
}

return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Stackframe_clsDispatchTbl[] ={
{"push",(id (*)())c_Stackframe_push},
{"pop",(id (*)())c_Stackframe_pop},
{(char*)0,(id (*)())0}
};
static struct _SLT _Stackframe_nstDispatchTbl[] ={
{"next:",(id (*)())i_Stackframe_next_},
{"previous:",(id (*)())i_Stackframe_previous_},
{"next",(id (*)())i_Stackframe_next},
{"previous",(id (*)())i_Stackframe_previous},
{"compound:",(id (*)())i_Stackframe_compound_},
{"def",(id (*)())i_Stackframe_def},
{"def:",(id (*)())i_Stackframe_def_},
{"compound",(id (*)())i_Stackframe_compound},
{"lookupself",(id (*)())i_Stackframe_lookupself},
{"lookuplocal:",(id (*)())i_Stackframe_lookuplocal_},
{"lookupval:",(id (*)())i_Stackframe_lookupval_},
{"defval:as:",(id (*)())i_Stackframe_defval_as_},
{"enclosing",(id (*)())i_Stackframe_enclosing},
{"quitframe:",(id (*)())i_Stackframe_quitframe_},
{"quitframe",(id (*)())i_Stackframe_quitframe},
{"breakframe:",(id (*)())i_Stackframe_breakframe_},
{"breakframe",(id (*)())i_Stackframe_breakframe},
{"contframe:",(id (*)())i_Stackframe_contframe_},
{"contframe",(id (*)())i_Stackframe_contframe},
{"exitframe",(id (*)())i_Stackframe_exitframe},
{"returnval",(id (*)())i_Stackframe_returnval},
{"returnval:",(id (*)())i_Stackframe_returnval_},
{"printBtOn:",(id (*)())i_Stackframe_printBtOn_},
{(char*)0,(id (*)())0}
};
id Stackframe = (id)&_Stackframe;
id  *OBJCCLASS_Stackframe(void) { return &Stackframe; }
struct _SHARED  _Stackframe = {
  (id)&__Stackframe,
  (id)&_Object,
  "Stackframe",
  0,
  sizeof(struct Stackframe_PRIVATE),
  23,
  _Stackframe_nstDispatchTbl,
  41,
  &stkframe_modDesc,
  0,
  (id)0,
  &Stackframe,
};
id  OBJCCFUNC_Stackframe(void) { return (id)&_Stackframe; }
id  OBJCCSUPER_Stackframe(void) { return _Stackframe.clsSuper; }
struct _SHARED __Stackframe = {
  (id)&__Object,
  (id)&__Object,
  "Stackframe",
  0,
  sizeof(struct _SHARED),
  2,
  _Stackframe_clsDispatchTbl,
  34,
  &stkframe_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Stackframe(void) { return (id)&__Stackframe; }
id  OBJCMSUPER_Stackframe(void) { return __Stackframe.clsSuper; }
static char *_selTransTbl[] ={
"new",
"next:",
"previous:",
"previous",
"lookupval:",
"lookuplocal:",
"includesKey:",
"atKey:",
"error:",
"str",
"enclosing",
"atKey:put:",
"quitframe:",
"compound",
"def",
"printBtOn:",
0
};
struct modDescriptor stkframe_modDesc = {
  "stkframe",
  "objc3.3.19",
  0L,
  0,
  0,
  &Stackframe,
  16,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_stkframe(void)
{
  selTransTbl = _selTransTbl;
  return &stkframe_modDesc;
}
int _OBJCPOSTLINK_stkframe = 1;


