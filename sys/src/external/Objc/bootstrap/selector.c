# 1 "selector.m"
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
extern struct modDescriptor  *_OBJCBIND_selector(void);
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
extern struct modDescriptor selector_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//string.h"
#include <string.h>

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
# 22 "./trlunit.h"
extern id trlunit;
# 22 "./options.h"
void defoptions(void);

extern int o_warnings;
extern int o_gnu;
extern int o_darwin;
extern int o_m64;
extern int o_sunstudio;
extern int o_hpux;
extern int o_vms;
extern int o_refcnt;
extern int o_ppi;
extern int o_watcom;
extern int o_ibmvac;
extern int o_msdos;
extern int o_enableasm;
extern int o_nolinetags;
extern int o_buffered;
extern int o_quiet;
extern int o_outputcode;
extern int o_version;
extern int o_otb;
extern int o_llkeyw;
extern int o_comments;
extern int o_duptypedefs;
extern int o_seltranslation;
extern int o_categories;
extern int o_blocks;
extern int o_fwd;
extern int o_selptr;
extern int o_cache;
extern int o_filer;
extern int o_selfassign;
extern char*o_bind;
extern char*o_browsedir;
extern int o_refbind;
extern int o_inlinecache;
extern int o_cplus;
extern int o_gencode;
extern int o_st80;
extern int o_selfassign;
extern int o_nilrcvr;
extern int o_shareddata;
extern int o_oneperfile;
extern int o_cvars;
extern int o_warnlex;
extern int o_warnfwd;
extern int o_warnsuggest;
extern int o_warnintvar;
extern int o_warnclasstype;
extern int o_warntypeconflict;
extern int o_warnundefined;
extern int o_warnlocalnst;
extern int o_warnnotfound;
extern int o_warnmissingmethods;
extern int o_attrcommon;
extern int o_postlink;
extern char*o_infile;
extern char*o_outfile;
extern char*o_srcfilename;
extern char*o_initcall;
extern char*o_tagformat;
extern char*o_mainfun;
extern char*o_pathsep;
extern int o_debuginfo;
extern int o_checkbind;
extern int o_linemax;
extern int o_structassign;
extern id o_stepbreak;
extern int o_stepnext;
# 22 "./selector.h"
struct Selector_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./../../include/objpak/array.h"
unsigned capacity;
# 42 "./../../include/objpak/ocstring.h"
struct objstr value;
# 24 "./selector.h"
int lineno;
id filename;};

# 22 "./selector.h"
extern id  Selector;

# 22 "./selector.h"
extern struct _SHARED _Selector;
extern struct _SHARED __Selector;


# 39 "selector.m"
static id i_Selector_add_(struct Selector_PRIVATE *self,SEL _cmd,id comp)
{
id objcT0,objcT1;

# 41 "selector.m"
(objcT0=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(objcT1=comp,(*(STR(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]))));
if( !self->filename){
id objcT2,objcT3;
self->
# 43 "selector.m"
lineno=(objcT2=comp,(*(int(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));self->
filename=(objcT3=comp,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
}
return(id)self;
}

static int i_Selector_lineno(struct Selector_PRIVATE *self,SEL _cmd)
{
return self->lineno;
}

static id i_Selector_filename(struct Selector_PRIVATE *self,SEL _cmd)
{
return self->filename;
}

static id i_Selector_addcol(struct Selector_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 61 "selector.m"
(objcT4=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT4,selTransTbl[0]))(objcT4,selTransTbl[0],":"));
return(id)self;
}

static id i_Selector_gen(struct Selector_PRIVATE *self,SEL _cmd)
{
if( !o_seltranslation){
id objcT5;

# 68 "selector.m"
gf("\"%s\"",(objcT5=(id)self,(*(STR(*)(id,SEL))_imp(objcT5,selTransTbl[1]))(objcT5,selTransTbl[1])));
}else{
id objcT6;

# 70 "selector.m"
int offset=(objcT6=trlunit,(*(int(*)(id,SEL,id))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4],(id)self));

if(o_checkbind){
gs("((selTransTbl)?");
}
gs("selTransTbl[");
if(o_comments){
id objcT7;

# 77 "selector.m"
gf("/* %s */",(objcT7=(id)self,(*(STR(*)(id,SEL))_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1])));
}
gf("%i]",offset);
if(o_checkbind){
id objcT8;

# 81 "selector.m"
gf(":objcrt_bindError(\"%s\"))",(objcT8=trlunit,(*(char*(*)(id,SEL))_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5])));
}
}

return(id)self;
}

static id i_Selector_st80(struct Selector_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 90 "selector.m"
gs((objcT9=(id)self,(*(STR(*)(id,SEL))_imp(objcT9,selTransTbl[1]))(objcT9,selTransTbl[1])));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  String;
extern struct _SHARED _String;
extern struct _SHARED __String;
static struct _SLT _Selector_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Selector_nstDispatchTbl[] ={
{"add:",(id (*)())i_Selector_add_},
{"lineno",(id (*)())i_Selector_lineno},
{"filename",(id (*)())i_Selector_filename},
{"addcol",(id (*)())i_Selector_addcol},
{"gen",(id (*)())i_Selector_gen},
{"st80",(id (*)())i_Selector_st80},
{(char*)0,(id (*)())0}
};
id Selector = (id)&_Selector;
id  *OBJCCLASS_Selector(void) { return &Selector; }
struct _SHARED  _Selector = {
  (id)&__Selector,
  (id)&_String,
  "Selector",
  0,
  sizeof(struct Selector_PRIVATE),
  6,
  _Selector_nstDispatchTbl,
  41,
  &selector_modDesc,
  0,
  (id)0,
  &Selector,
};
id  OBJCCFUNC_Selector(void) { return (id)&_Selector; }
id  OBJCCSUPER_Selector(void) { return _Selector.clsSuper; }
struct _SHARED __Selector = {
  (id)&__Object,
  (id)&__String,
  "Selector",
  0,
  sizeof(struct _SHARED),
  0,
  _Selector_clsDispatchTbl,
  34,
  &selector_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Selector(void) { return (id)&__Selector; }
id  OBJCMSUPER_Selector(void) { return __Selector.clsSuper; }
static char *_selTransTbl[] ={
"concatSTR:",
"str",
"lineno",
"filename",
"seloffset:",
"moddescname",
0
};
struct modDescriptor selector_modDesc = {
  "selector",
  "objc3.3.19",
  0L,
  0,
  0,
  &Selector,
  6,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_selector(void)
{
  selTransTbl = _selTransTbl;
  return &selector_modDesc;
}
int _OBJCPOSTLINK_selector = 1;


