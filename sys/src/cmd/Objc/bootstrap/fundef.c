# 1 "fundef.m"
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
extern struct modDescriptor  *_OBJCBIND_fundef(void);
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
extern struct modDescriptor fundef_modDesc;

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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./trlunit.h"
extern id trlunit;
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
# 22 "./stkframe.h"
extern id topframe;
# 22 "./fundef.h"
struct FunctionDef_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 26 "./def.h"
id parmdic;
id heapvars;
id parmnames;
id classreferences;
id blockreferences;
id heapvarblocks;
# 24 "./fundef.h"
id unit;
id datadefspecs,decl,body;
BOOL isinline,isstatic,isextern,istypedef;
id breakpt;};

# 22 "./fundef.h"
extern id  FunctionDef;

# 22 "./fundef.h"
extern struct _SHARED _FunctionDef;
extern struct _SHARED __FunctionDef;


# 47 "fundef.m"
static id i_FunctionDef_compound(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 49 "fundef.m"
return(objcT0=self->body,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static BOOL i_FunctionDef_isfundef(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static BOOL i_FunctionDef_isextern(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
return self->isextern;
}

static BOOL i_FunctionDef_isstatic(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
return self->isstatic;
}

static id i_FunctionDef_datadefspecs_(struct FunctionDef_PRIVATE *self,SEL _cmd,id s)
{self->
datadefspecs=s;
return(id)self;
}

static id i_FunctionDef_decl_(struct FunctionDef_PRIVATE *self,SEL _cmd,id d)
{self->
decl=d;
return(id)self;
}

static id i_FunctionDef_body_(struct FunctionDef_PRIVATE *self,SEL _cmd,id b)
{self->
body=b;
return(id)self;
}

static id i_FunctionDef_synthattrs(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 87 "fundef.m"
int i,n;self->

unit=trlunit;

for(i=0,n=(objcT1=self->datadefspecs,(*(unsigned(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));i<n;i++){
id objcT2,objcT3;

# 92 "fundef.m"
id s=(objcT2=self->datadefspecs,(*(id(*)(id,SEL,unsigned))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],i));

if((objcT3=s,(*(BOOL(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]))){
id objcT4,objcT5,objcT6,objcT7;

# 95 "fundef.m"
if((objcT4=s,(*(BOOL(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4])))self->
istypedef++;
else if((objcT5=s,(*(BOOL(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5])))self->
isstatic++;
else if((objcT6=s,(*(BOOL(*)(id,SEL))_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6])))self->
isinline++;
else if((objcT7=s,(*(BOOL(*)(id,SEL))_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7])))self->
isextern++;
}
}
return(id)self;
}

static BOOL i_FunctionDef_definesocu(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
return !self->isstatic&& !self->isinline;
}

static id i_FunctionDef_restype(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
id objcT8,objcT9,objcT10;

# 115 "fundef.m"
id x,v=(objcT8=self->decl,(*_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8]));

x=(objcT9=trlunit,(*_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9],v));
(void)0;
return(objcT10=x,(*_imp(objcT10,selTransTbl[10]))(objcT10,selTransTbl[10]));
}

static id i_FunctionDef_synth(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
id objcT11,objcT12,objcT13,objcT14,objcT15;
id objcT16,objcT17,objcT18;

# 124 "fundef.m"
id v;

curdef=(id)self;
curcompound=(id)0;


(objcT11=self->decl,(*_imp(objcT11,selTransTbl[11]))(objcT11,selTransTbl[11]));
(objcT12=(id)self,(*_imp(objcT12,selTransTbl[12]))(objcT12,selTransTbl[12]));
v=(objcT13=self->decl,(*_imp(objcT13,selTransTbl[8]))(objcT13,selTransTbl[8]));
(objcT14=trlunit,(*_imp(objcT14,selTransTbl[13]))(objcT14,selTransTbl[13],v,(id)self));
if(self->istypedef)
fatal("illegal storage class for %s",(objcT15=v,(*(STR(*)(id,SEL))_imp(objcT15,selTransTbl[14]))(objcT15,selTransTbl[14])));
if( !o_postlink&&(objcT16=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT16,selTransTbl[15]))(objcT16,selTransTbl[15])))
(objcT17=trlunit,(*_imp(objcT17,selTransTbl[16]))(objcT17,selTransTbl[16],v));
(objcT18=self->body,(*_imp(objcT18,selTransTbl[11]))(objcT18,selTransTbl[11]));
curdef=(id)0;
return(id)self;
}

# 59 "./symbol.h"
extern id  Symbol;

# 143 "fundef.m"
static id i_FunctionDef_genmain(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
id objcT23,objcT24,objcT25,objcT26,objcT27;
id objcT28,objcT29;

# 145 "fundef.m"
if(o_initcall){
char*fmt;

gc('\n');
if( !o_shareddata){
gs("extern struct useDescriptor *OCU_main;\n");
gs("extern struct modEntry *_objcModules;\n");
if(o_cplus){
fmt="extern \"C\" int %s(void *mods,void *desc);\n";
}else{
fmt="extern int %s(void *mods,void *desc);\n";
}
}else{
if(o_cplus){
fmt="extern \"C\" int %s(int debug,int traceInit);\n";
}else{
fmt="extern int %s(int debug,int traceInit);\n";
}
}
gf(fmt,o_initcall);
}else{
fatal("no initialization call defined (use -init)");
}

if(o_filer){
id objcT19,objcT20,objcT21,objcT22;

# 170 "fundef.m"
gs((o_cplus)?"extern \"C\"":"extern");
gs(" void *_OBJCBIND_ascfiler(void);\n");
gs((o_cplus)?"extern \"C\"":"extern");
gs(" void *_OBJCBIND_ocstring(void);\n");
if( !o_postlink)
(objcT19=trlunit,(*_imp(objcT19,selTransTbl[17]))(objcT19,selTransTbl[17],(objcT20=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT20,selTransTbl[18]))(objcT20,selTransTbl[18],"AsciiFiler"))));
if( !o_postlink)
(objcT21=trlunit,(*_imp(objcT21,selTransTbl[17]))(objcT21,selTransTbl[17],(objcT22=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT22,selTransTbl[18]))(objcT22,selTransTbl[18],"String"))));
}
if(self->datadefspecs)
(objcT23=self->datadefspecs,(*(id(*)(id,SEL,SEL))_imp(objcT23,selTransTbl[19]))(objcT23,selTransTbl[19],selTransTbl[20]));
(objcT24=self->decl,(*_imp(objcT24,selTransTbl[20]))(objcT24,selTransTbl[20]));
gs("{\n");

if(o_filer){
gs("_OBJCBIND_ascfiler();\n");
gs("_OBJCBIND_ocstring();\n");
}
if( !o_cache){
gs("noCacheFlag=1;\n");
}
if( !o_nilrcvr){
gs("noNilRcvr=1;\n");
}
if( !o_shareddata){
gf("%s(_objcModules,OCU_main);\n",o_initcall);
}else{
gf("%s(0,0);\n",o_initcall);
}

if( !o_postlink)
(objcT25=trlunit,(*_imp(objcT25,selTransTbl[17]))(objcT25,selTransTbl[17],(objcT26=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT26,selTransTbl[18]))(objcT26,selTransTbl[18],o_initcall))));

if(self->datadefspecs==(id)0|| !(objcT27=(objcT28=self->datadefspecs,(*(id(*)(id,SEL,unsigned))_imp(objcT28,selTransTbl[2]))(objcT28,selTransTbl[2],0)),(*(BOOL(*)(id,SEL))_imp(objcT27,selTransTbl[21]))(objcT27,selTransTbl[21])))
gs("return");
gs((objcT29=s_objcmain,(*(STR(*)(id,SEL))_imp(objcT29,selTransTbl[14]))(objcT29,selTransTbl[14])));
gc('(');
o_nolinetags++;
if(self->parmnames)
gcommalist(self->parmnames);
o_nolinetags--;
gs(");\n");

gs("}\n");
return(id)self;
}

static id i_FunctionDef_gen(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
id objcT30,objcT31,objcT32,objcT33,objcT37;
id objcT38;

# 219 "fundef.m"
char*s;
BOOL ismain;

(void)0;
s=(objcT30=(objcT31=self->decl,(*_imp(objcT31,selTransTbl[8]))(objcT31,selTransTbl[8])),(*(STR(*)(id,SEL))_imp(objcT30,selTransTbl[14]))(objcT30,selTransTbl[14]));
ismain= !strcmp(s,o_mainfun);
(objcT32=_FunctionDef.clsSuper,(*_impSuper(objcT32,selTransTbl[20]))((id)self,selTransTbl[20]));
if(self->datadefspecs)
(objcT33=self->datadefspecs,(*(id(*)(id,SEL,SEL))_imp(objcT33,selTransTbl[19]))(objcT33,selTransTbl[19],selTransTbl[20]));
if(ismain){
id objcT34,objcT35;

# 229 "fundef.m"
o_nolinetags++;
(objcT34=self->decl,(*_imp(objcT34,selTransTbl[22]))(objcT34,selTransTbl[22],s_objcmain));
o_nolinetags--;
(objcT35=trlunit,(*_imp(objcT35,selTransTbl[16]))(objcT35,selTransTbl[16],s_main));
}else{
id objcT36;

# 234 "fundef.m"
(objcT36=self->decl,(*_imp(objcT36,selTransTbl[20]))(objcT36,selTransTbl[20]));
}
(objcT37=self->body,(*_imp(objcT37,selTransTbl[20]))(objcT37,selTransTbl[20]));
if(ismain)
(objcT38=(id)self,(*_imp(objcT38,selTransTbl[23]))(objcT38,selTransTbl[23]));
return(id)self;
}

static id i_FunctionDef_go(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
id objcT39;

# 244 "fundef.m"
return(objcT39=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT39,selTransTbl[24]))(objcT39,selTransTbl[24],_cmd));
}

# 24 "./stkframe.h"
extern id  Stackframe;

# 247 "fundef.m"
static id i_FunctionDef_fcall_(struct FunctionDef_PRIVATE *self,SEL _cmd,id x)
{
id objcT40,objcT41,objcT42,objcT43,objcT44;

# 249 "fundef.m"
id r;
trlunit=self->unit;
(objcT40=(objcT41=Stackframe,(*_imp(objcT41,selTransTbl[25]))(objcT41,selTransTbl[25])),(*_imp(objcT40,selTransTbl[26]))(objcT40,selTransTbl[26],(id)self));
if(self->breakpt)(objcT42=self->breakpt,(*_imp(objcT42,selTransTbl[27]))(objcT42,selTransTbl[27]));
r=(objcT43=self->body,(*_imp(objcT43,selTransTbl[28]))(objcT43,selTransTbl[28],x));
(objcT44=Stackframe,(*_imp(objcT44,selTransTbl[29]))(objcT44,selTransTbl[29]));
return r;
}

static id i_FunctionDef_printBtOn_(struct FunctionDef_PRIVATE *self,SEL _cmd,IOD d)
{
id objcT45,objcT46,objcT47,objcT48,objcT49;

# 260 "fundef.m"
id n;
int lo;
char*fn;
n=(objcT45=self->decl,(*_imp(objcT45,selTransTbl[8]))(objcT45,selTransTbl[8]));
fn=(objcT46=(objcT47=n,(*_imp(objcT47,selTransTbl[30]))(objcT47,selTransTbl[30])),(*(STR(*)(id,SEL))_imp(objcT46,selTransTbl[14]))(objcT46,selTransTbl[14]));
lo=(objcT48=n,(*(int(*)(id,SEL))_imp(objcT48,selTransTbl[31]))(objcT48,selTransTbl[31]));
fprintf(d,"%s () at %s:%d\n",(objcT49=n,(*(STR(*)(id,SEL))_imp(objcT49,selTransTbl[14]))(objcT49,selTransTbl[14])),fn,lo);
return(id)self;
}

static id i_FunctionDef_setbreak_(struct FunctionDef_PRIVATE *self,SEL _cmd,id bkpt)
{self->
breakpt=bkpt;
return(id)self;
}

static id i_FunctionDef_defval_(struct FunctionDef_PRIVATE *self,SEL _cmd,id v)
{
id objcT50;

# 278 "fundef.m"
return(objcT50=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT50,selTransTbl[32]))(objcT50,selTransTbl[32],"Attempt to assign a value to function"));
}

static id i_FunctionDef_value(struct FunctionDef_PRIVATE *self,SEL _cmd)
{
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Def;
extern struct _SHARED _Def;
extern struct _SHARED __Def;
static struct _SLT _FunctionDef_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _FunctionDef_nstDispatchTbl[] ={
{"compound",(id (*)())i_FunctionDef_compound},
{"isfundef",(id (*)())i_FunctionDef_isfundef},
{"isextern",(id (*)())i_FunctionDef_isextern},
{"isstatic",(id (*)())i_FunctionDef_isstatic},
{"datadefspecs:",(id (*)())i_FunctionDef_datadefspecs_},
{"decl:",(id (*)())i_FunctionDef_decl_},
{"body:",(id (*)())i_FunctionDef_body_},
{"synthattrs",(id (*)())i_FunctionDef_synthattrs},
{"definesocu",(id (*)())i_FunctionDef_definesocu},
{"restype",(id (*)())i_FunctionDef_restype},
{"synth",(id (*)())i_FunctionDef_synth},
{"genmain",(id (*)())i_FunctionDef_genmain},
{"gen",(id (*)())i_FunctionDef_gen},
{"go",(id (*)())i_FunctionDef_go},
{"fcall:",(id (*)())i_FunctionDef_fcall_},
{"printBtOn:",(id (*)())i_FunctionDef_printBtOn_},
{"setbreak:",(id (*)())i_FunctionDef_setbreak_},
{"defval:",(id (*)())i_FunctionDef_defval_},
{"value",(id (*)())i_FunctionDef_value},
{(char*)0,(id (*)())0}
};
id FunctionDef = (id)&_FunctionDef;
id  *OBJCCLASS_FunctionDef(void) { return &FunctionDef; }
struct _SHARED  _FunctionDef = {
  (id)&__FunctionDef,
  (id)&_Def,
  "FunctionDef",
  0,
  sizeof(struct FunctionDef_PRIVATE),
  19,
  _FunctionDef_nstDispatchTbl,
  41,
  &fundef_modDesc,
  0,
  (id)0,
  &FunctionDef,
};
id  OBJCCFUNC_FunctionDef(void) { return (id)&_FunctionDef; }
id  OBJCCSUPER_FunctionDef(void) { return _FunctionDef.clsSuper; }
struct _SHARED __FunctionDef = {
  (id)&__Object,
  (id)&__Def,
  "FunctionDef",
  0,
  sizeof(struct _SHARED),
  0,
  _FunctionDef_clsDispatchTbl,
  34,
  &fundef_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_FunctionDef(void) { return (id)&__FunctionDef; }
id  OBJCMSUPER_FunctionDef(void) { return __FunctionDef.clsSuper; }
static char *_selTransTbl[] ={
"compound",
"size",
"at:",
"isstorageclass",
"istypedef",
"isstatic",
"isinline",
"isextern",
"identifier",
"lookupglobal:",
"funcall",
"synth",
"synthattrs",
"def:as:",
"str",
"definesocu",
"definesentry:",
"usesentry:",
"str:",
"elementsPerform:",
"gen",
"isvoid",
"gendef:",
"genmain",
"shouldNotImplement:",
"push",
"def:",
"go",
"fcall:",
"pop",
"filename",
"lineno",
"error:",
0
};
struct modDescriptor fundef_modDesc = {
  "fundef",
  "objc3.3.19",
  0L,
  0,
  0,
  &FunctionDef,
  33,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_fundef(void)
{
  selTransTbl = _selTransTbl;
  return &fundef_modDesc;
}
int _OBJCPOSTLINK_fundef = 1;


