# 1 "pfixdecl.m"
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
extern struct modDescriptor  *_OBJCBIND_pfixdecl(void);
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
extern struct modDescriptor pfixdecl_modDesc;

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
# 22 "./pfixdecl.h"
struct PostfixDecl_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./pfixdecl.h"
id prefix,decl,postfix;};

# 22 "./pfixdecl.h"
extern id  PostfixDecl;

# 22 "./pfixdecl.h"
extern struct _SHARED _PostfixDecl;
extern struct _SHARED __PostfixDecl;


# 36 "pfixdecl.m"
static id i_PostfixDecl_abstrdecl(struct PostfixDecl_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2;

# 38 "pfixdecl.m"
return(objcT0=(objcT1=(id)self,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0])),(*_imp(objcT0,selTransTbl[1]))(objcT0,selTransTbl[1],(objcT2=self->decl,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]))));
}

static id i_PostfixDecl_identifier(struct PostfixDecl_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 43 "pfixdecl.m"
return(self->decl)?(objcT3=self->decl,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3])):(id)0;
}

static BOOL i_PostfixDecl_isfunproto(struct PostfixDecl_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 48 "pfixdecl.m"
return(self->decl)?(objcT4=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4])):(BOOL)0;
}

static id i_PostfixDecl_prefix_(struct PostfixDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
prefix=aRcvr;
return(id)self;
}

static id i_PostfixDecl_decl_(struct PostfixDecl_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
decl=aRcvr;
return(id)self;
}

static id i_PostfixDecl_postfix_(struct PostfixDecl_PRIVATE *self,SEL _cmd,id aDecl)
{self->
postfix=aDecl;
return(id)self;
}

static id i_PostfixDecl_star(struct PostfixDecl_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6,objcT7;

# 71 "pfixdecl.m"
return(objcT5=(objcT6=(id)self,(*_imp(objcT6,selTransTbl[0]))(objcT6,selTransTbl[0])),(*_imp(objcT5,selTransTbl[1]))(objcT5,selTransTbl[1],(objcT7=self->decl,(*_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5]))));
}

static id i_PostfixDecl_synth(struct PostfixDecl_PRIVATE *self,SEL _cmd)
{
id objcT8,objcT9,objcT10;

# 76 "pfixdecl.m"
if(self->prefix)
(objcT8=self->prefix,(*_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
if(self->decl)
(objcT9=self->decl,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
if(self->postfix)
(objcT10=self->postfix,(*_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
return(id)self;
}

static id i_PostfixDecl_gen(struct PostfixDecl_PRIVATE *self,SEL _cmd)
{
id objcT11,objcT12;

# 87 "pfixdecl.m"
if(self->prefix)
(objcT11=self->prefix,(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7]));
if(self->decl)
(objcT12=self->decl,(*_imp(objcT12,selTransTbl[7]))(objcT12,selTransTbl[7]));
if(self->postfix){
id objcT13;

# 92 "pfixdecl.m"
gc(' ');
(objcT13=self->postfix,(*_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7]));
}
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Decl;
extern struct _SHARED _Decl;
extern struct _SHARED __Decl;
static struct _SLT _PostfixDecl_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _PostfixDecl_nstDispatchTbl[] ={
{"abstrdecl",(id (*)())i_PostfixDecl_abstrdecl},
{"identifier",(id (*)())i_PostfixDecl_identifier},
{"isfunproto",(id (*)())i_PostfixDecl_isfunproto},
{"prefix:",(id (*)())i_PostfixDecl_prefix_},
{"decl:",(id (*)())i_PostfixDecl_decl_},
{"postfix:",(id (*)())i_PostfixDecl_postfix_},
{"star",(id (*)())i_PostfixDecl_star},
{"synth",(id (*)())i_PostfixDecl_synth},
{"gen",(id (*)())i_PostfixDecl_gen},
{(char*)0,(id (*)())0}
};
id PostfixDecl = (id)&_PostfixDecl;
id  *OBJCCLASS_PostfixDecl(void) { return &PostfixDecl; }
struct _SHARED  _PostfixDecl = {
  (id)&__PostfixDecl,
  (id)&_Decl,
  "PostfixDecl",
  0,
  sizeof(struct PostfixDecl_PRIVATE),
  9,
  _PostfixDecl_nstDispatchTbl,
  41,
  &pfixdecl_modDesc,
  0,
  (id)0,
  &PostfixDecl,
};
id  OBJCCFUNC_PostfixDecl(void) { return (id)&_PostfixDecl; }
id  OBJCCSUPER_PostfixDecl(void) { return _PostfixDecl.clsSuper; }
struct _SHARED __PostfixDecl = {
  (id)&__Object,
  (id)&__Decl,
  "PostfixDecl",
  0,
  sizeof(struct _SHARED),
  0,
  _PostfixDecl_clsDispatchTbl,
  34,
  &pfixdecl_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_PostfixDecl(void) { return (id)&__PostfixDecl; }
id  OBJCMSUPER_PostfixDecl(void) { return __PostfixDecl.clsSuper; }
static char *_selTransTbl[] ={
"copy",
"decl:",
"abstrdecl",
"identifier",
"isfunproto",
"star",
"synth",
"gen",
0
};
struct modDescriptor pfixdecl_modDesc = {
  "pfixdecl",
  "objc3.3.19",
  0L,
  0,
  0,
  &PostfixDecl,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_pfixdecl(void)
{
  selTransTbl = _selTransTbl;
  return &pfixdecl_modDesc;
}
int _OBJCPOSTLINK_pfixdecl = 1;


