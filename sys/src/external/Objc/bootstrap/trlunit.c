# 1 "trlunit.m"
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
extern struct modDescriptor  *_OBJCBIND_trlunit(void);
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
extern struct modDescriptor trlunit_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stddef.h"
#include <stddef.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//ctype.h"
#include <ctype.h>

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
# 28 "./../../include/objpak/set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 31 "./../../include/objpak/sortcltn.h"
typedef struct objbbt
{
struct objbbt*ulink;
struct objbbt*rlink;
struct objbbt*llink;
int balance;
id key;
}*
objbbt_t;
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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
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
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
# 22 "./msgxpr.h"
extern id msgwraps;
# 49 "trlunit.m"
id trlunit;
# 24 "./trlunit.h"
struct TranslationUnit_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 26 "./trlunit.h"
int msgcount;
int icachecount;
int blockcount;
int heapvarcount;
int retlabelcount;
id types,typedic;
id defdic;
id globals,globaldic,globalvals;
id builtinfuns,builtintypes;
id clsimpl;
id clsimpls;
id seldic,selcltn;
id msgdic,fwdcltn;
char*modname;
char*modversion;
char*bindfunname;
char*moddescname;
id usesentries;
id definesentries;
id methods;
id classdefs;
id structdefs;
id gentypes;
id enumtors;
BOOL usingblocks;
BOOL usingselfassign;};

# 24 "./trlunit.h"
extern id  TranslationUnit;

# 24 "./trlunit.h"
extern struct _SHARED _TranslationUnit;
extern struct _SHARED __TranslationUnit;


# 59 "./symbol.h"
extern id  Symbol;

# 34 "./type.h"
extern id  Type;

# 29 "./expr.h"
extern id  Expr;

# 53 "trlunit.m"
static id c_TranslationUnit_new(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2,objcT3;

# 55 "trlunit.m"
(objcT0=Symbol,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
(objcT1=Type,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
(objcT2=Expr,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
return trlunit=(objcT3=__TranslationUnit.clsSuper,(*_impSuper(objcT3,selTransTbl[3]))((id)self,selTransTbl[3]));
}

static int i_TranslationUnit_msgcount(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
return self->msgcount++;
}

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 66 "trlunit.m"
static id i_TranslationUnit_gettmpvar(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT4,objcT5;

# 68 "trlunit.m"
return(objcT4=String,(*(id(*)(id,SEL,STR,...))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4],"objcT%i",(objcT5=trlunit,(*(int(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]))));
}

static int i_TranslationUnit_icachecount(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
return self->icachecount++;
}

static int i_TranslationUnit_blockcount(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
return self->blockcount++;
}

static int i_TranslationUnit_heapvarcount(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
return self->heapvarcount++;
}

static id i_TranslationUnit_returnlabel(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 88 "trlunit.m"
return(objcT6=String,(*(id(*)(id,SEL,STR,...))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4],"_cleanup%i",self->retlabelcount++));
}

static BOOL i_TranslationUnit_usingselfassign(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
return self->usingselfassign;
}

static id i_TranslationUnit_usingselfassign_(struct TranslationUnit_PRIVATE *self,SEL _cmd,BOOL x)
{self->
usingselfassign=x;
return(id)self;
}

static BOOL i_TranslationUnit_usingblocks(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
return self->usingblocks;
}

static id i_TranslationUnit_usingblocks_(struct TranslationUnit_PRIVATE *self,SEL _cmd,BOOL x)
{self->
usingblocks=x;
return(id)self;
}

static id i_TranslationUnit_inlinecacheprologue(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{

if(o_cplus){
gs("struct objcrt_inlineCache {id cls;id (*imp)(...);};\n");
}else{
gs("struct objcrt_inlineCache {id cls;id (*imp)();};\n");
}
# 124 "trlunit.m"
if(o_cplus){
gextc();
gf("id %s _nilHandler(...);\n",o_bind);
}else{
gf("id %s _nilHandler(id,char*);\n",o_bind);
}

return(id)self;
}

static id i_TranslationUnit_setmodversion_(struct TranslationUnit_PRIVATE *self,SEL _cmd,char*v)
{self->
modversion=v;
return(id)self;
}

static char*
mystrrchr(const char*s,int c)
{
char*t=(char*)s;

while( *t){
t++;
}

while(t!=s){
if( *t==c)
return t;
else
t--;
}

return( *t==c)?t:NULL;
}

static id i_TranslationUnit_setmodname_(struct TranslationUnit_PRIVATE *self,SEL _cmd,char*filename)
{
id objcT7,objcT8,objcT9,objcT10,objcT11;
id objcT12;

# 161 "trlunit.m"
id s;
char*p;
char*cp;

p=mystrrchr(filename,o_pathsep[0]);
s=(objcT7=String,(*(id(*)(id,SEL,STR))_imp(objcT7,selTransTbl[6]))(objcT7,selTransTbl[6],(p)?p+1:(char*)filename));
p=(objcT8=s,(*(STR(*)(id,SEL))_imp(objcT8,selTransTbl[7]))(objcT8,selTransTbl[7]));
if((cp=mystrrchr(p,'.'))!=NULL) *
cp='\0';
for(cp=p; *cp!='\0';cp++){
if( !isalnum( *cp)) *
cp='_';
}self->


modname=p;


s=(objcT9=String,(*(id(*)(id,SEL,STR,...))_imp(objcT9,selTransTbl[4]))(objcT9,selTransTbl[4],"_OBJCBIND_%s",p));self->
bindfunname=(objcT10=s,(*(STR(*)(id,SEL))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));
# 184 "trlunit.m"
s=(objcT11=String,(*(id(*)(id,SEL,STR,...))_imp(objcT11,selTransTbl[4]))(objcT11,selTransTbl[4],"%s_modDesc",p));self->
moddescname=(objcT12=s,(*(STR(*)(id,SEL))_imp(objcT12,selTransTbl[7]))(objcT12,selTransTbl[7]));
# 190 "trlunit.m"
return(id)self;
}

static char*i_TranslationUnit_moddescname(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
(void)0;
return self->moddescname;
}

static id i_TranslationUnit_checkbindprologue(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
gs("\nextern char *objcrt_bindError(char *);\n");
return(id)self;
}

# 25 "./classdef.h"
extern id  ClassDef;

# 205 "trlunit.m"
static id i_TranslationUnit_prologue(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14,objcT15,objcT16;

# 207 "trlunit.m"
(void)0;

if(o_comments)
gs("/* objc prologue */\n");

if(o_otb){
gs("struct _PRIVATE {\n");
gs("  struct OTB *isa;\n");
gs("};\n");
gs("struct OTB {\n");
gs("  struct _PRIVATE *ptr;\n");
g_otbvars();
gs("};\n");
gs("typedef struct OTB *id;\n");
}else{
if( !o_refcnt){
gs("struct _PRIVATE { struct _PRIVATE *isa; };\n");
}else{
gs("struct _PRIVATE { struct _PRIVATE *isa;unsigned int _refcnt; };\n");
}
gs("typedef struct _PRIVATE *id;\n");
}

(objcT13=(objcT14=ClassDef,(*_imp(objcT14,selTransTbl[3]))(objcT14,selTransTbl[3])),(*_imp(objcT13,selTransTbl[8]))(objcT13,selTransTbl[8]));

if( !o_fwd){
if(o_cplus){
gextc();
gf("id %s (* _imp(id,char*))(...);\n",o_bind);
gextc();
gf("id %s (* _impSuper(id,char*))(...);\n",o_bind);
}else{
gf("extern id %s (* _imp(id,char*))();\n",o_bind);
gf("extern id %s (* _impSuper(id,char*))();\n",o_bind);
}
}
if(o_inlinecache)
(objcT15=(id)self,(*_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9]));

gf("extern struct modDescriptor %s *%s(void);\n",o_bind,self->bindfunname);

if(o_refbind){

gf("static char **selTransTbl = (char **)%s;\n",self->bindfunname);
}else{

gs("static char **selTransTbl;\n");
}

if(o_fwd){
if(o_cplus){
gs("static id (**fwdTransTbl)(...);\n");
}else{
gs("static id (**fwdTransTbl)();\n");
}
}

if(o_cplus){
gs("struct _SLT {char *_cmd;id (*_imp)(...);};\n");
}else{
gs("struct _SLT {char *_cmd;id (*_imp)();};\n");
}


gs("struct modDescriptor {\n");

gs("  char *modName;\n");
gs("  char *modVersion;\n");
gs("  long modStatus;\n");
gs("  char *modMinSel;\n");
gs("  char *modMaxSel;\n");
gs("  id *modClsLst;\n");
gs("  short modSelRef;\n");
gs("  char **modSelTbl;\n");
gs("  struct methodDescriptor *modMapTbl;\n");

gs("};\n");

gf("extern struct modDescriptor %s;\n",self->moddescname);
if(o_checkbind)
(objcT16=(id)self,(*_imp(objcT16,selTransTbl[10]))(objcT16,selTransTbl[10]));
if(o_comments)
gs("/* end of objc prologue */\n");
return(id)self;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 293 "trlunit.m"
static id i_TranslationUnit_allclsimpls(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT17,objcT18;

# 295 "trlunit.m"
if(self->clsimpls)
return self->clsimpls;
if(self->clsimpl)
return(objcT17=(objcT18=OrdCltn,(*_imp(objcT18,selTransTbl[3]))(objcT18,selTransTbl[3])),(*_imp(objcT17,selTransTbl[11]))(objcT17,selTransTbl[11],self->clsimpl));
return(id)0;
}

static id i_TranslationUnit_addclsimpl_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id c)
{

if(self->clsimpls){
id objcT19;

# 306 "trlunit.m"
(void)0;
(objcT19=self->clsimpls,(*_imp(objcT19,selTransTbl[11]))(objcT19,selTransTbl[11],c));
}else{
if(self->clsimpl){
if(o_oneperfile){
fatal("only one implementation per file allowed");
}else{
id objcT20,objcT21,objcT22;
self->
# 313 "trlunit.m"
clsimpls=(objcT20=OrdCltn,(*_imp(objcT20,selTransTbl[3]))(objcT20,selTransTbl[3]));
(objcT21=self->clsimpls,(*_imp(objcT21,selTransTbl[11]))(objcT21,selTransTbl[11],self->clsimpl));
(objcT22=self->clsimpls,(*_imp(objcT22,selTransTbl[11]))(objcT22,selTransTbl[11],c));self->
clsimpl=(id)0;
}
}else{self->
clsimpl=c;
}
}
return(id)self;
}

# 32 "./../../include/objpak/dictnary.h"
extern id  Dictionary;

# 325 "trlunit.m"
static int i_TranslationUnit_seloffset_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id selname)
{
id objcT25,objcT26;

# 327 "trlunit.m"
int n;
id val;

if( !self->selcltn){
id objcT23,objcT24;
self->
# 331 "trlunit.m"
selcltn=(objcT23=OrdCltn,(*_imp(objcT23,selTransTbl[3]))(objcT23,selTransTbl[3]));self->
seldic=(objcT24=Dictionary,(*_imp(objcT24,selTransTbl[3]))(objcT24,selTransTbl[3]));
}
n=(objcT25=self->selcltn,(*(unsigned(*)(id,SEL))_imp(objcT25,selTransTbl[12]))(objcT25,selTransTbl[12]));
if((val=(objcT26=self->seldic,(*_imp(objcT26,selTransTbl[13]))(objcT26,selTransTbl[13],selname)))){
id objcT27;

# 336 "trlunit.m"
return(objcT27=val,(*(int(*)(id,SEL))_imp(objcT27,selTransTbl[14]))(objcT27,selTransTbl[14]));
}else{
id objcT28,objcT29,objcT30;

# 338 "trlunit.m"
(objcT28=self->selcltn,(*_imp(objcT28,selTransTbl[11]))(objcT28,selTransTbl[11],selname));
(objcT29=self->seldic,(*_imp(objcT29,selTransTbl[15]))(objcT29,selTransTbl[15],selname,(objcT30=String,(*(id(*)(id,SEL,STR,...))_imp(objcT30,selTransTbl[4]))(objcT30,selTransTbl[4],"%i",n))));
}
return n;
}

static int i_TranslationUnit_fwdoffset_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id msg)
{
id objcT33,objcT34;

# 346 "trlunit.m"
int n;
id val;

if( !self->fwdcltn){
id objcT31,objcT32;
self->
# 350 "trlunit.m"
fwdcltn=(objcT31=OrdCltn,(*_imp(objcT31,selTransTbl[3]))(objcT31,selTransTbl[3]));self->
msgdic=(objcT32=Dictionary,(*_imp(objcT32,selTransTbl[3]))(objcT32,selTransTbl[3]));
}
n=(objcT33=self->fwdcltn,(*(unsigned(*)(id,SEL))_imp(objcT33,selTransTbl[12]))(objcT33,selTransTbl[12]));
# 357 "trlunit.m"
if((val=(objcT34=self->msgdic,(*_imp(objcT34,selTransTbl[13]))(objcT34,selTransTbl[13],msg)))){
id objcT41;

# 358 "trlunit.m"
if(o_debuginfo){
id objcT35,objcT36,objcT37,objcT38,objcT39;
id objcT40;

# 359 "trlunit.m"
id x=(objcT35=msg,(*_imp(objcT35,selTransTbl[16]))(objcT35,selTransTbl[16]));
id y=(objcT36=(objcT37=self->fwdcltn,(*(id(*)(id,SEL,unsigned))_imp(objcT37,selTransTbl[17]))(objcT37,selTransTbl[17],(objcT38=val,(*(int(*)(id,SEL))_imp(objcT38,selTransTbl[14]))(objcT38,selTransTbl[14])))),(*_imp(objcT36,selTransTbl[16]))(objcT36,selTransTbl[16]));

fprintf(stderr,"using '%s' dispatch fun for '%s'\n",(objcT39=y,(*(STR(*)(id,SEL))_imp(objcT39,selTransTbl[18]))(objcT39,selTransTbl[18])),(objcT40=x,(*(STR(*)(id,SEL))_imp(objcT40,selTransTbl[18]))(objcT40,selTransTbl[18])));
}
return(objcT41=val,(*(int(*)(id,SEL))_imp(objcT41,selTransTbl[14]))(objcT41,selTransTbl[14]));
}else{
id objcT42,objcT43,objcT44;

# 366 "trlunit.m"
(objcT42=self->fwdcltn,(*_imp(objcT42,selTransTbl[11]))(objcT42,selTransTbl[11],msg));
(objcT43=self->msgdic,(*_imp(objcT43,selTransTbl[15]))(objcT43,selTransTbl[15],msg,(objcT44=String,(*(id(*)(id,SEL,STR,...))_imp(objcT44,selTransTbl[4]))(objcT44,selTransTbl[4],"%i",n))));
}
return n;
}

static id i_TranslationUnit_genmodclslst(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT45;

# 374 "trlunit.m"
int i,n;

(void)0;
gs("static id _modClsLst[] ={\n");
for(i=0,n=(objcT45=self->clsimpls,(*(unsigned(*)(id,SEL))_imp(objcT45,selTransTbl[12]))(objcT45,selTransTbl[12]));i<n;i++){
id objcT46,objcT47;

# 379 "trlunit.m"
STR s=(objcT46=(objcT47=self->clsimpls,(*(id(*)(id,SEL,unsigned))_imp(objcT47,selTransTbl[17]))(objcT47,selTransTbl[17],i)),(*(char*(*)(id,SEL))_imp(objcT46,selTransTbl[19]))(objcT46,selTransTbl[19]));


gf("(id)&_%s,\n",s);
}

gs("(id)0};\n");
return(id)self;
}

static id i_TranslationUnit_genseltranstbl(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT48;

# 391 "trlunit.m"
int i,n=(self->selcltn)?(objcT48=self->selcltn,(*(unsigned(*)(id,SEL))_imp(objcT48,selTransTbl[12]))(objcT48,selTransTbl[12])):0;

gs("static char *_selTransTbl[] ={\n");
for(i=0;i<n;i++){
id objcT49,objcT50;

# 395 "trlunit.m"
STR s=(objcT49=(objcT50=self->selcltn,(*(id(*)(id,SEL,unsigned))_imp(objcT50,selTransTbl[17]))(objcT50,selTransTbl[17],i)),(*(STR(*)(id,SEL))_imp(objcT49,selTransTbl[18]))(objcT49,selTransTbl[18]));

gf("\"%s\",\n",s);
}

gs("0\n};\n");
return(id)self;
}

static id i_TranslationUnit_genfwdstubs(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT51;

# 406 "trlunit.m"
int i,n;
# 411 "trlunit.m"
n=(self->fwdcltn)?(objcT51=self->fwdcltn,(*(unsigned(*)(id,SEL))_imp(objcT51,selTransTbl[12]))(objcT51,selTransTbl[12])):0;
for(i=0;i<n;i++){
id objcT52,objcT53,objcT54,objcT55;

# 413 "trlunit.m"
id msg=(objcT52=self->fwdcltn,(*(id(*)(id,SEL,unsigned))_imp(objcT52,selTransTbl[17]))(objcT52,selTransTbl[17],i));

(objcT53=msg,(*_imp(objcT53,selTransTbl[20]))(objcT53,selTransTbl[20]));
(objcT54=msg,(*_imp(objcT54,selTransTbl[21]))(objcT54,selTransTbl[21]));
(objcT55=msg,(*_imp(objcT55,selTransTbl[22]))(objcT55,selTransTbl[22]));
}
return(id)self;
}

static id i_TranslationUnit_genfwdtranstbl(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT56;

# 424 "trlunit.m"
int i,n;

n=(self->fwdcltn)?(objcT56=self->fwdcltn,(*(unsigned(*)(id,SEL))_imp(objcT56,selTransTbl[12]))(objcT56,selTransTbl[12])):0;

if(o_cplus){
gs("static id (*(_fwdTransTbl[]))(...) ={\n");
}else{
gs("static id (*(_fwdTransTbl[]))() ={\n");
}

for(i=0;i<n;i++){
id objcT57,objcT58;

# 435 "trlunit.m"
char*s=(objcT57=(objcT58=self->fwdcltn,(*(id(*)(id,SEL,unsigned))_imp(objcT58,selTransTbl[17]))(objcT58,selTransTbl[17],i)),(*(char*(*)(id,SEL))_imp(objcT57,selTransTbl[23]))(objcT57,selTransTbl[23]));

if(o_cplus){
gf("(id(*)(...))%s,\n",s);
}else{
gf("(id(*)())%s,\n",s);
}
}


if(o_cplus){
gs("(id(*)(...))0\n};\n");
}else{
gs("(id(*)())0\n};\n");
}

return(id)self;
}

# 460 "trlunit.m"
static id i_TranslationUnit_genmoddesc(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT59;

# 462 "trlunit.m"
int selsize=(self->selcltn)?(objcT59=self->selcltn,(*(unsigned(*)(id,SEL))_imp(objcT59,selTransTbl[12]))(objcT59,selTransTbl[12])):0;
long modstatus=(self->clsimpls)?0x4L:0;
# 468 "trlunit.m"
gf("struct modDescriptor %s = {\n",self->moddescname);
gf("  \"%s\",\n",self->modname);
gf("  \"%s\",\n",self->modversion);
gf("  %iL,\n",modstatus);

gs("  0,\n");
gs("  0,\n");
if(self->clsimpl){
id objcT60;
char*cname=(objcT60=self->clsimpl,(*(char*(*)(id,SEL))_imp(objcT60,selTransTbl[19]))(objcT60,selTransTbl[19]));

gf("  &%s,\n",cname);
}else{
if(self->clsimpls){

(void)0;
gs("  _modClsLst,\n");
}else{
gs("  0,\n");
}
}
if(selsize){
gf("  %i,\n",selsize);
gs("  _selTransTbl,\n");
}else{
gs("  0,\n");
gs("  0,\n");
}


gs("  0\n};\n");
return(id)self;
}

static id i_TranslationUnit_genglobfuncall(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT61,objcT62;

# 504 "trlunit.m"
id all=(objcT61=(id)self,(*_imp(objcT61,selTransTbl[24]))(objcT61,selTransTbl[24]));

if(all)
(objcT62=all,(*(id(*)(id,SEL,SEL))_imp(objcT62,selTransTbl[25]))(objcT62,selTransTbl[25],selTransTbl[26]));
return(id)self;
}

static id i_TranslationUnit_genbindfun(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT63;
gf("struct modDescriptor %s*%s(void)\n{\n",o_bind,self->bindfunname);
gs("  selTransTbl = _selTransTbl;\n");
if(o_fwd){
gs("  fwdTransTbl = _fwdTransTbl;\n");
}

if( !o_shareddata)
(objcT63=(id)self,(*_imp(objcT63,selTransTbl[26]))(objcT63,selTransTbl[26]));
gf("  return &%s;\n}\n",self->moddescname);
return(id)self;
}

# 36 "./../../include/objpak/set.h"
extern id  Set;

# 526 "trlunit.m"
static id i_TranslationUnit_usesentry_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id name)
{
id objcT64,objcT65;

# 528 "trlunit.m"
if( !self->usesentries)self->
usesentries=(objcT64=Set,(*_imp(objcT64,selTransTbl[3]))(objcT64,selTransTbl[3]));
# 534 "trlunit.m"
(objcT65=self->usesentries,(*_imp(objcT65,selTransTbl[11]))(objcT65,selTransTbl[11],name));
return(id)self;
}

static id i_TranslationUnit_definesentry_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id name)
{
id objcT66,objcT67;

# 540 "trlunit.m"
if( !self->definesentries)self->
definesentries=(objcT66=Set,(*_imp(objcT66,selTransTbl[3]))(objcT66,selTransTbl[3]));
# 546 "trlunit.m"
(objcT67=self->definesentries,(*_imp(objcT67,selTransTbl[11]))(objcT67,selTransTbl[11],name));
return(id)self;
}

static BOOL i_TranslationUnit_definesmain(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT68;

# 552 "trlunit.m"
return(objcT68=self->definesentries,(*(BOOL(*)(id,SEL,id))_imp(objcT68,selTransTbl[27]))(objcT68,selTransTbl[27],s_main));
}

static id i_TranslationUnit_genusesentries(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT69,objcT70;

# 557 "trlunit.m"
id seq,entry;

if(o_comments){
gs("/* Objective C Use (OCU) entries */\n");
}
seq=(objcT69=self->usesentries,(*_imp(objcT69,selTransTbl[28]))(objcT69,selTransTbl[28]));
while((entry=(objcT70=seq,(*_imp(objcT70,selTransTbl[29]))(objcT70,selTransTbl[29])))){
id objcT71;

# 564 "trlunit.m"
char*s=(objcT71=entry,(*(STR(*)(id,SEL))_imp(objcT71,selTransTbl[18]))(objcT71,selTransTbl[18]));
# 568 "trlunit.m"
if(o_attrcommon)
gs("__attribute__((__common__)) ");
gf("struct useDescriptor *OCU_%s;\n",s);
}
return(id)self;
}

static id i_TranslationUnit_genusecontrol(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT72,objcT73;

# 577 "trlunit.m"
id seq,entry;

gs("static struct useDescriptor **_useControl[] = {\n");

seq=(objcT72=self->usesentries,(*_imp(objcT72,selTransTbl[28]))(objcT72,selTransTbl[28]));
while((entry=(objcT73=seq,(*_imp(objcT73,selTransTbl[29]))(objcT73,selTransTbl[29])))){
id objcT74;

# 583 "trlunit.m"
char*s=(objcT74=entry,(*(STR(*)(id,SEL))_imp(objcT74,selTransTbl[18]))(objcT74,selTransTbl[18]));

gf("  &OCU_%s,\n",s);
}
gs("0};\n");
gs("static struct useDescriptor _useDesc = {\n");
gs("  0,\n");
gs("  0,\n");
gs("  _useControl,\n");
gf("  %s",self->bindfunname);
gs("\n};\n");

return(id)self;
}

static id i_TranslationUnit_gendefinesentries(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT75,objcT76;

# 600 "trlunit.m"
id seq,entry;

if(o_comments)
gs("/* Objective C Use (OCU) defines */\n");

seq=(objcT75=self->definesentries,(*_imp(objcT75,selTransTbl[28]))(objcT75,selTransTbl[28]));
while((entry=(objcT76=seq,(*_imp(objcT76,selTransTbl[29]))(objcT76,selTransTbl[29])))){
id objcT77;

# 607 "trlunit.m"
char*s=(objcT77=entry,(*(STR(*)(id,SEL))_imp(objcT77,selTransTbl[18]))(objcT77,selTransTbl[18]));

if(o_attrcommon)
gs("__attribute__((__common__)) ");
gf("struct useDescriptor *OCU_%s = &_useDesc;\n",s);
}

return(id)self;
}

static id i_TranslationUnit_genocu(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT78,objcT79,objcT80,objcT81;

# 619 "trlunit.m"
gs("struct useDescriptor {\n");
gs("  int processed;\n");
gs("  struct useDescriptor *next;\n");
gs("  struct useDescriptor ***uses;\n");
gs("  struct modDescriptor *(*bind)();\n");
gs("};\n");

(objcT78=(id)self,(*_imp(objcT78,selTransTbl[30]))(objcT78,selTransTbl[30]));
(objcT79=(id)self,(*_imp(objcT79,selTransTbl[31]))(objcT79,selTransTbl[31]));
(objcT80=(id)self,(*_imp(objcT80,selTransTbl[32]))(objcT80,selTransTbl[32]));
# 634 "trlunit.m"
if((objcT81=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT81,selTransTbl[33]))(objcT81,selTransTbl[33]))){
gs("struct modEntry *_objcModules = 0;\n");
}
return(id)self;
}

static id i_TranslationUnit_postlinkmark(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT82;

# 649 "trlunit.m"
gf("int _OBJCPOSTLINK_%s = 1;\n",self->modname);
if((objcT82=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT82,selTransTbl[33]))(objcT82,selTransTbl[33]))){
gs("struct useDescriptor *OCU_main = 0;\n");
}
return(id)self;
}

static id i_TranslationUnit_otbmark(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
gf("int _OBJCOTB_%s = 1;\n",self->modname);
return(id)self;
}

static id i_TranslationUnit_epilogue(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT84,objcT91,objcT92;

# 664 "trlunit.m"
id e;

o_nolinetags++;

if(curclassdef){
id objcT83;

# 669 "trlunit.m"
(objcT83=curclassdef,(*_imp(objcT83,selTransTbl[34]))(objcT83,selTransTbl[34]));
}
if(o_comments){
gs("\n/* objc epilogue */\n");
}else{
gc('\n');
}

if((e=(objcT84=(id)self,(*_imp(objcT84,selTransTbl[24]))(objcT84,selTransTbl[24])))){
id objcT85;

# 678 "trlunit.m"
(objcT85=e,(*(id(*)(id,SEL,SEL))_imp(objcT85,selTransTbl[25]))(objcT85,selTransTbl[25],selTransTbl[35]));
}
if(o_fwd){
id objcT86,objcT87,objcT88;

# 681 "trlunit.m"
(objcT86=(id)self,(*_imp(objcT86,selTransTbl[36]))(objcT86,selTransTbl[36]));
(objcT87=(id)self,(*_imp(objcT87,selTransTbl[37]))(objcT87,selTransTbl[37]));
(objcT88=(id)self,(*_imp(objcT88,selTransTbl[38]))(objcT88,selTransTbl[38]));
}else{
id objcT89;

# 685 "trlunit.m"
(objcT89=(id)self,(*_imp(objcT89,selTransTbl[37]))(objcT89,selTransTbl[37]));
}

if(self->clsimpls){
id objcT90;

# 689 "trlunit.m"
(objcT90=(id)self,(*_imp(objcT90,selTransTbl[39]))(objcT90,selTransTbl[39]));
}
(objcT91=(id)self,(*_imp(objcT91,selTransTbl[40]))(objcT91,selTransTbl[40]));
(objcT92=(id)self,(*_imp(objcT92,selTransTbl[41]))(objcT92,selTransTbl[41]));

if(o_postlink){
id objcT93;

# 695 "trlunit.m"
(objcT93=(id)self,(*_imp(objcT93,selTransTbl[42]))(objcT93,selTransTbl[42]));
}else{
id objcT94;

# 697 "trlunit.m"
(objcT94=(id)self,(*_imp(objcT94,selTransTbl[43]))(objcT94,selTransTbl[43]));
}

if(o_otb){
id objcT95;

# 701 "trlunit.m"
(objcT95=(id)self,(*_imp(objcT95,selTransTbl[44]))(objcT95,selTransTbl[44]));
}
gc('\n');
gc('\n');
o_nolinetags--;
return(id)self;
}

static BOOL i_TranslationUnit_istypeword_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id node)
{
id objcT96,objcT97;

# 711 "trlunit.m"
if(self->builtintypes!=(id)0&&(objcT96=self->builtintypes,(*_imp(objcT96,selTransTbl[45]))(objcT96,selTransTbl[45],node))!=(id)0)
return(BOOL)1;
if(self->types!=(id)0&&(objcT97=self->types,(*(BOOL(*)(id,SEL,id))_imp(objcT97,selTransTbl[46]))(objcT97,selTransTbl[46],node)))
return(BOOL)1;
return(BOOL)0;
}

static BOOL i_TranslationUnit_isbuiltinfun_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id node)
{
id objcT98;

# 720 "trlunit.m"
return self->builtinfuns!=(id)0&&(objcT98=self->builtinfuns,(*_imp(objcT98,selTransTbl[45]))(objcT98,selTransTbl[45],node))!=(id)0;
}

static id i_TranslationUnit_defbuiltinfun_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id node)
{
id objcT99,objcT100;

# 725 "trlunit.m"
if( !self->builtinfuns)self->
builtinfuns=(objcT99=Set,(*_imp(objcT99,selTransTbl[3]))(objcT99,selTransTbl[3]));
(objcT100=self->builtinfuns,(*_imp(objcT100,selTransTbl[11]))(objcT100,selTransTbl[11],node));
return(id)self;
}

static id i_TranslationUnit_defbuiltintype_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id node)
{
id objcT101,objcT102;

# 733 "trlunit.m"
if( !self->builtintypes)self->
builtintypes=(objcT101=Set,(*_imp(objcT101,selTransTbl[3]))(objcT101,selTransTbl[3]));
(objcT102=self->builtintypes,(*_imp(objcT102,selTransTbl[11]))(objcT102,selTransTbl[11],node));
return(id)self;
}

static id i_TranslationUnit_def_astype_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id node,id aType)
{
id objcT107,objcT108;

# 741 "trlunit.m"
if( !self->typedic){
id objcT103,objcT104;
self->
# 742 "trlunit.m"
typedic=(objcT103=Dictionary,(*_imp(objcT103,selTransTbl[3]))(objcT103,selTransTbl[3]));self->
types=(objcT104=Set,(*_imp(objcT104,selTransTbl[3]))(objcT104,selTransTbl[3]));
}
if(o_debuginfo){
id objcT105,objcT106;

# 746 "trlunit.m"
fprintf(stderr,"typedef %s as '",(objcT105=node,(*(STR(*)(id,SEL))_imp(objcT105,selTransTbl[18]))(objcT105,selTransTbl[18])));
gstderr();
(objcT106=aType,(*_imp(objcT106,selTransTbl[47]))(objcT106,selTransTbl[47]));
gnormal();
fprintf(stderr,"'\n");
}
(objcT107=self->types,(*_imp(objcT107,selTransTbl[11]))(objcT107,selTransTbl[11],node));
(void)0;
(objcT108=self->typedic,(*_imp(objcT108,selTransTbl[15]))(objcT108,selTransTbl[15],node,aType));
return(id)self;
}

static id i_TranslationUnit_defenumtor_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id e)
{
id objcT109,objcT110;

# 760 "trlunit.m"
if( !self->enumtors)self->
enumtors=(objcT109=Set,(*_imp(objcT109,selTransTbl[3]))(objcT109,selTransTbl[3]));
(objcT110=self->enumtors,(*_imp(objcT110,selTransTbl[11]))(objcT110,selTransTbl[11],e));
return(id)self;
}

static id i_TranslationUnit_lookupenumtor_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sym)
{
id objcT111;

# 768 "trlunit.m"
return(self->enumtors)?(objcT111=self->enumtors,(*_imp(objcT111,selTransTbl[45]))(objcT111,selTransTbl[45],sym)):(id)0;
}

static id i_TranslationUnit_defstruct_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id e)
{
id objcT112,objcT113;

# 773 "trlunit.m"
if( !self->structdefs)self->
structdefs=(objcT112=Set,(*_imp(objcT112,selTransTbl[3]))(objcT112,selTransTbl[3]));
(objcT113=self->structdefs,(*_imp(objcT113,selTransTbl[11]))(objcT113,selTransTbl[11],e));
return(id)self;
}

static id i_TranslationUnit_lookupstruct_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id e)
{
id objcT114;

# 781 "trlunit.m"
return(self->structdefs)?(objcT114=self->structdefs,(*_imp(objcT114,selTransTbl[45]))(objcT114,selTransTbl[45],e)):(id)0;
}

static id i_TranslationUnit_lookuptype_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sym)
{
id objcT115;

# 786 "trlunit.m"
return(self->typedic)?(objcT115=self->typedic,(*_imp(objcT115,selTransTbl[13]))(objcT115,selTransTbl[13],sym)):(id)0;
}

static id i_TranslationUnit_lookupglobal_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sym)
{
id objcT116;

# 791 "trlunit.m"
return(self->globaldic)?(objcT116=self->globaldic,(*_imp(objcT116,selTransTbl[13]))(objcT116,selTransTbl[13],sym)):(id)0;
}

static id i_TranslationUnit_lookupdef_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sym)
{
id objcT117;

# 796 "trlunit.m"
return(self->defdic)?(objcT117=self->defdic,(*_imp(objcT117,selTransTbl[13]))(objcT117,selTransTbl[13],sym)):(id)0;
}

static id i_TranslationUnit_def_as_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sym,id d)
{
id objcT119;

# 801 "trlunit.m"
if( !self->defdic){
id objcT118;
self->
# 802 "trlunit.m"
defdic=(objcT118=Dictionary,(*_imp(objcT118,selTransTbl[3]))(objcT118,selTransTbl[3]));
}
(objcT119=self->defdic,(*_imp(objcT119,selTransTbl[15]))(objcT119,selTransTbl[15],sym,d));
return(id)self;
}

static id i_TranslationUnit_defdata_astype_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id node,id aType)
{
id objcT122,objcT123;

# 810 "trlunit.m"
if( !self->globaldic){
id objcT120,objcT121;
self->
# 811 "trlunit.m"
globaldic=(objcT120=Dictionary,(*_imp(objcT120,selTransTbl[3]))(objcT120,selTransTbl[3]));self->
globals=(objcT121=Set,(*_imp(objcT121,selTransTbl[3]))(objcT121,selTransTbl[3]));
}
(objcT122=self->globals,(*_imp(objcT122,selTransTbl[11]))(objcT122,selTransTbl[11],node));
(void)0;
(objcT123=self->globaldic,(*_imp(objcT123,selTransTbl[15]))(objcT123,selTransTbl[15],node,aType));
return(id)self;
}

static id i_TranslationUnit_def_asclass_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sym,id classdef)
{
id objcT124,objcT125;

# 822 "trlunit.m"
if( !self->classdefs)self->
classdefs=(objcT124=Dictionary,(*_imp(objcT124,selTransTbl[3]))(objcT124,selTransTbl[3]));
(objcT125=self->classdefs,(*_imp(objcT125,selTransTbl[15]))(objcT125,selTransTbl[15],sym,classdef));
return(id)self;
}

static id i_TranslationUnit_lookupclass_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sym)
{
id objcT126;

# 830 "trlunit.m"
return(objcT126=self->classdefs,(*_imp(objcT126,selTransTbl[13]))(objcT126,selTransTbl[13],sym));
}

static id i_TranslationUnit_lookupmethod_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sel)
{
id objcT127;

# 835 "trlunit.m"
return(objcT127=self->methods,(*_imp(objcT127,selTransTbl[13]))(objcT127,selTransTbl[13],sel));
}

static id i_TranslationUnit_def_asmethod_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id sel,id method)
{
id objcT128,objcT129;

# 840 "trlunit.m"
if( !self->methods)self->
methods=(objcT128=Dictionary,(*_imp(objcT128,selTransTbl[3]))(objcT128,selTransTbl[3]));
(objcT129=self->methods,(*_imp(objcT129,selTransTbl[15]))(objcT129,selTransTbl[15],sel,method));
return(id)self;
}

static id i_TranslationUnit_addgentype_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id s)
{
id objcT130,objcT131;

# 848 "trlunit.m"
if( !self->gentypes)self->
gentypes=(objcT130=Set,(*_imp(objcT130,selTransTbl[3]))(objcT130,selTransTbl[3]));
(objcT131=self->gentypes,(*_imp(objcT131,selTransTbl[11]))(objcT131,selTransTbl[11],s));
return(id)self;
}

static BOOL i_TranslationUnit_isgentype_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id s)
{
id objcT132;

# 856 "trlunit.m"
return(objcT132=self->gentypes,(*(BOOL(*)(id,SEL,id))_imp(objcT132,selTransTbl[46]))(objcT132,selTransTbl[46],s));
}

static id i_TranslationUnit_go(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT133,objcT134;

# 861 "trlunit.m"
if(self->clsimpl)(objcT133=self->clsimpl,(*_imp(objcT133,selTransTbl[48]))(objcT133,selTransTbl[48]));
if(self->clsimpls)(objcT134=self->clsimpls,(*(id(*)(id,SEL,SEL))_imp(objcT134,selTransTbl[25]))(objcT134,selTransTbl[25],_cmd));
return(id)self;
}

static id i_TranslationUnit_reset(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT135,objcT136,objcT137;

# 868 "trlunit.m"
id v,s;
v=(objcT135=self->defdic,(*_imp(objcT135,selTransTbl[49]))(objcT135,selTransTbl[49]));
while((s=(objcT136=v,(*_imp(objcT136,selTransTbl[29]))(objcT136,selTransTbl[29]))))(objcT137=s,(*_imp(objcT137,selTransTbl[50]))(objcT137,selTransTbl[50]));
return(id)self;
}

static id i_TranslationUnit_inspectbutton(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
printf("name=INSPECT\n");
printf("button=2\n");
printf("action=open Menu.$LININFO\n");
return(id)self;
}

# 41 "./../../include/objpak/sortcltn.h"
extern id  SortCltn;

# 883 "trlunit.m"
static id i_TranslationUnit_browseallclasses(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT138,objcT139,objcT140,objcT143,objcT144;

# 885 "trlunit.m"
FILE*f;
id sorted;
id c,classes;
sorted=(objcT138=SortCltn,(*_imp(objcT138,selTransTbl[3]))(objcT138,selTransTbl[3]));
classes=(objcT139=self->classdefs,(*_imp(objcT139,selTransTbl[49]))(objcT139,selTransTbl[49]));
while((c=(objcT140=classes,(*_imp(objcT140,selTransTbl[29]))(objcT140,selTransTbl[29])))){
id objcT141,objcT142;

# 891 "trlunit.m"
(objcT141=sorted,(*_imp(objcT141,selTransTbl[11]))(objcT141,selTransTbl[11],c));
(objcT142=c,(*_imp(objcT142,selTransTbl[51]))(objcT142,selTransTbl[51]));
}
f=freopen(browsepath("Menu.classes"),"w",stdout);
if( !f){
fatal("cannot open Menu.classes for writing\n");
return(id)self;
}
printf("menu=Classes\n");
classes=(objcT143=sorted,(*_imp(objcT143,selTransTbl[28]))(objcT143,selTransTbl[28]));
while((c=(objcT144=classes,(*_imp(objcT144,selTransTbl[29]))(objcT144,selTransTbl[29])))){
id objcT145,objcT146;

# 902 "trlunit.m"
printf("name='%s'\n",(objcT145=c,(*(char*(*)(id,SEL))_imp(objcT145,selTransTbl[19]))(objcT145,selTransTbl[19])));
printf("action=open Menu.%s\n",(objcT146=c,(*(char*(*)(id,SEL))_imp(objcT146,selTransTbl[19]))(objcT146,selTransTbl[19])));
}
fclose(f);
return(id)self;
}

static id i_TranslationUnit_findsubclasses_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id s)
{
id objcT147,objcT148,objcT149;

# 911 "trlunit.m"
id sorted;
id c,classes;
sorted=(objcT147=SortCltn,(*_imp(objcT147,selTransTbl[3]))(objcT147,selTransTbl[3]));
classes=(objcT148=self->classdefs,(*_imp(objcT148,selTransTbl[49]))(objcT148,selTransTbl[49]));
while((c=(objcT149=classes,(*_imp(objcT149,selTransTbl[29]))(objcT149,selTransTbl[29])))){
id objcT150,objcT151;

# 916 "trlunit.m"
if((objcT150=c,(*_imp(objcT150,selTransTbl[52]))(objcT150,selTransTbl[52]))==s)(objcT151=sorted,(*_imp(objcT151,selTransTbl[11]))(objcT151,selTransTbl[11],c));
}
return sorted;
}

static id i_TranslationUnit_browsesubclasses_filename_title_(struct TranslationUnit_PRIVATE *self,SEL _cmd,id c,char*filename,char*title)
{
id objcT152,objcT153,objcT154,objcT157,objcT158;
id objcT166,objcT167,objcT168;

# 923 "trlunit.m"
int i;
FILE*f;
id d,e,subclasses,classes;

f=freopen(browsepath(filename),"w",stdout);
if( !f){
fatal("cannot open %s for writing\n",filename);
return(id)self;
}

printf("menu=%s\n",title);

classes=(objcT152=c,(*_imp(objcT152,selTransTbl[28]))(objcT152,selTransTbl[28]));
subclasses=(objcT153=OrdCltn,(*_imp(objcT153,selTransTbl[3]))(objcT153,selTransTbl[3]));
while((d=(objcT154=classes,(*_imp(objcT154,selTransTbl[29]))(objcT154,selTransTbl[29])))){
id objcT155,objcT156;

# 938 "trlunit.m"
(objcT155=subclasses,(*_imp(objcT155,selTransTbl[11]))(objcT155,selTransTbl[11],(objcT156=(id)self,(*_imp(objcT156,selTransTbl[53]))(objcT156,selTransTbl[53],d))));
}

i=0;
classes=(objcT157=c,(*_imp(objcT157,selTransTbl[28]))(objcT157,selTransTbl[28]));
while((d=(objcT158=classes,(*_imp(objcT158,selTransTbl[29]))(objcT158,selTransTbl[29])))){
id objcT159,objcT160;

# 944 "trlunit.m"
e=(objcT159=subclasses,(*(id(*)(id,SEL,unsigned))_imp(objcT159,selTransTbl[17]))(objcT159,selTransTbl[17],i++));
if((objcT160=e,(*(unsigned(*)(id,SEL))_imp(objcT160,selTransTbl[12]))(objcT160,selTransTbl[12]))){
id objcT161,objcT162,objcT163;

# 946 "trlunit.m"
printf("name='%s...'\n",(objcT161=d,(*(char*(*)(id,SEL))_imp(objcT161,selTransTbl[19]))(objcT161,selTransTbl[19])));
printf("lininfo='%s'\n",(objcT162=d,(*(char*(*)(id,SEL))_imp(objcT162,selTransTbl[19]))(objcT162,selTransTbl[19])));
printf("action=open Menu.sub%s\n",(objcT163=d,(*(char*(*)(id,SEL))_imp(objcT163,selTransTbl[19]))(objcT163,selTransTbl[19])));
}else{
id objcT164,objcT165;

# 950 "trlunit.m"
printf("name='%s'\n",(objcT164=d,(*(char*(*)(id,SEL))_imp(objcT164,selTransTbl[19]))(objcT164,selTransTbl[19])));
printf("lininfo='%s'\n",(objcT165=d,(*(char*(*)(id,SEL))_imp(objcT165,selTransTbl[19]))(objcT165,selTransTbl[19])));
printf("action=none\n");
}
}
(objcT166=(id)self,(*_imp(objcT166,selTransTbl[54]))(objcT166,selTransTbl[54]));
fclose(f);

i=0;
classes=(objcT167=c,(*_imp(objcT167,selTransTbl[28]))(objcT167,selTransTbl[28]));
while((d=(objcT168=classes,(*_imp(objcT168,selTransTbl[29]))(objcT168,selTransTbl[29])))){
id objcT169,objcT170;

# 961 "trlunit.m"
e=(objcT169=subclasses,(*(id(*)(id,SEL,unsigned))_imp(objcT169,selTransTbl[17]))(objcT169,selTransTbl[17],i++));
if((objcT170=e,(*(unsigned(*)(id,SEL))_imp(objcT170,selTransTbl[12]))(objcT170,selTransTbl[12]))){
id objcT171,objcT172,objcT173,objcT174,objcT175;

# 963 "trlunit.m"
id fn=(objcT171=String,(*(id(*)(id,SEL,STR,...))_imp(objcT171,selTransTbl[4]))(objcT171,selTransTbl[4],"Menu.sub%s",(objcT172=d,(*(char*(*)(id,SEL))_imp(objcT172,selTransTbl[19]))(objcT172,selTransTbl[19]))));
(objcT173=(id)self,(*(id(*)(id,SEL,id,char*,char*))_imp(objcT173,selTransTbl[55]))(objcT173,selTransTbl[55],e,(objcT174=fn,(*(STR(*)(id,SEL))_imp(objcT174,selTransTbl[18]))(objcT174,selTransTbl[18])),(objcT175=d,(*(char*(*)(id,SEL))_imp(objcT175,selTransTbl[19]))(objcT175,selTransTbl[19]))));
}
}

return(id)self;
}

static id i_TranslationUnit_browsemain(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
FILE*f=freopen(browsepath("Menu.main"),"w",stdout);
if( !f){
fatal("cannot open Menu.main for writing\n");
return(id)self;
}

printf("menu=Browser\n");
printf("name=Classes\n");
printf("action=open Menu.classes\n");
printf("name=Class Hierarchy\n");
printf("action=open Menu.root\n");
printf("name=Unix shell\n");
printf("action=unix-system\n");
printf("name=Quit\n");
printf("action=exit\n");
fclose(f);
return(id)self;
}

static id i_TranslationUnit_browse(struct TranslationUnit_PRIVATE *self,SEL _cmd)
{
id objcT176,objcT177,objcT178,objcT179;

# 994 "trlunit.m"
id rootclasses;
(void)0;
(objcT176=(id)self,(*_imp(objcT176,selTransTbl[56]))(objcT176,selTransTbl[56]));
(objcT177=(id)self,(*_imp(objcT177,selTransTbl[57]))(objcT177,selTransTbl[57]));
rootclasses=(objcT178=(id)self,(*_imp(objcT178,selTransTbl[53]))(objcT178,selTransTbl[53],(id)0));
(objcT179=(id)self,(*(id(*)(id,SEL,id,char*,char*))_imp(objcT179,selTransTbl[55]))(objcT179,selTransTbl[55],rootclasses,"Menu.root","Root"));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _TranslationUnit_clsDispatchTbl[] ={
{"new",(id (*)())c_TranslationUnit_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _TranslationUnit_nstDispatchTbl[] ={
{"msgcount",(id (*)())i_TranslationUnit_msgcount},
{"gettmpvar",(id (*)())i_TranslationUnit_gettmpvar},
{"icachecount",(id (*)())i_TranslationUnit_icachecount},
{"blockcount",(id (*)())i_TranslationUnit_blockcount},
{"heapvarcount",(id (*)())i_TranslationUnit_heapvarcount},
{"returnlabel",(id (*)())i_TranslationUnit_returnlabel},
{"usingselfassign",(id (*)())i_TranslationUnit_usingselfassign},
{"usingselfassign:",(id (*)())i_TranslationUnit_usingselfassign_},
{"usingblocks",(id (*)())i_TranslationUnit_usingblocks},
{"usingblocks:",(id (*)())i_TranslationUnit_usingblocks_},
{"inlinecacheprologue",(id (*)())i_TranslationUnit_inlinecacheprologue},
{"setmodversion:",(id (*)())i_TranslationUnit_setmodversion_},
{"setmodname:",(id (*)())i_TranslationUnit_setmodname_},
{"moddescname",(id (*)())i_TranslationUnit_moddescname},
{"checkbindprologue",(id (*)())i_TranslationUnit_checkbindprologue},
{"prologue",(id (*)())i_TranslationUnit_prologue},
{"allclsimpls",(id (*)())i_TranslationUnit_allclsimpls},
{"addclsimpl:",(id (*)())i_TranslationUnit_addclsimpl_},
{"seloffset:",(id (*)())i_TranslationUnit_seloffset_},
{"fwdoffset:",(id (*)())i_TranslationUnit_fwdoffset_},
{"genmodclslst",(id (*)())i_TranslationUnit_genmodclslst},
{"genseltranstbl",(id (*)())i_TranslationUnit_genseltranstbl},
{"genfwdstubs",(id (*)())i_TranslationUnit_genfwdstubs},
{"genfwdtranstbl",(id (*)())i_TranslationUnit_genfwdtranstbl},
{"genmoddesc",(id (*)())i_TranslationUnit_genmoddesc},
{"genglobfuncall",(id (*)())i_TranslationUnit_genglobfuncall},
{"genbindfun",(id (*)())i_TranslationUnit_genbindfun},
{"usesentry:",(id (*)())i_TranslationUnit_usesentry_},
{"definesentry:",(id (*)())i_TranslationUnit_definesentry_},
{"definesmain",(id (*)())i_TranslationUnit_definesmain},
{"genusesentries",(id (*)())i_TranslationUnit_genusesentries},
{"genusecontrol",(id (*)())i_TranslationUnit_genusecontrol},
{"gendefinesentries",(id (*)())i_TranslationUnit_gendefinesentries},
{"genocu",(id (*)())i_TranslationUnit_genocu},
{"postlinkmark",(id (*)())i_TranslationUnit_postlinkmark},
{"otbmark",(id (*)())i_TranslationUnit_otbmark},
{"epilogue",(id (*)())i_TranslationUnit_epilogue},
{"istypeword:",(id (*)())i_TranslationUnit_istypeword_},
{"isbuiltinfun:",(id (*)())i_TranslationUnit_isbuiltinfun_},
{"defbuiltinfun:",(id (*)())i_TranslationUnit_defbuiltinfun_},
{"defbuiltintype:",(id (*)())i_TranslationUnit_defbuiltintype_},
{"def:astype:",(id (*)())i_TranslationUnit_def_astype_},
{"defenumtor:",(id (*)())i_TranslationUnit_defenumtor_},
{"lookupenumtor:",(id (*)())i_TranslationUnit_lookupenumtor_},
{"defstruct:",(id (*)())i_TranslationUnit_defstruct_},
{"lookupstruct:",(id (*)())i_TranslationUnit_lookupstruct_},
{"lookuptype:",(id (*)())i_TranslationUnit_lookuptype_},
{"lookupglobal:",(id (*)())i_TranslationUnit_lookupglobal_},
{"lookupdef:",(id (*)())i_TranslationUnit_lookupdef_},
{"def:as:",(id (*)())i_TranslationUnit_def_as_},
{"defdata:astype:",(id (*)())i_TranslationUnit_defdata_astype_},
{"def:asclass:",(id (*)())i_TranslationUnit_def_asclass_},
{"lookupclass:",(id (*)())i_TranslationUnit_lookupclass_},
{"lookupmethod:",(id (*)())i_TranslationUnit_lookupmethod_},
{"def:asmethod:",(id (*)())i_TranslationUnit_def_asmethod_},
{"addgentype:",(id (*)())i_TranslationUnit_addgentype_},
{"isgentype:",(id (*)())i_TranslationUnit_isgentype_},
{"go",(id (*)())i_TranslationUnit_go},
{"reset",(id (*)())i_TranslationUnit_reset},
{"inspectbutton",(id (*)())i_TranslationUnit_inspectbutton},
{"browseallclasses",(id (*)())i_TranslationUnit_browseallclasses},
{"findsubclasses:",(id (*)())i_TranslationUnit_findsubclasses_},
{"browsesubclasses:filename:title:",(id (*)())i_TranslationUnit_browsesubclasses_filename_title_},
{"browsemain",(id (*)())i_TranslationUnit_browsemain},
{"browse",(id (*)())i_TranslationUnit_browse},
{(char*)0,(id (*)())0}
};
id TranslationUnit = (id)&_TranslationUnit;
id  *OBJCCLASS_TranslationUnit(void) { return &TranslationUnit; }
struct _SHARED  _TranslationUnit = {
  (id)&__TranslationUnit,
  (id)&_Node,
  "TranslationUnit",
  0,
  sizeof(struct TranslationUnit_PRIVATE),
  65,
  _TranslationUnit_nstDispatchTbl,
  41,
  &trlunit_modDesc,
  0,
  (id)0,
  &TranslationUnit,
};
id  OBJCCFUNC_TranslationUnit(void) { return (id)&_TranslationUnit; }
id  OBJCCSUPER_TranslationUnit(void) { return _TranslationUnit.clsSuper; }
struct _SHARED __TranslationUnit = {
  (id)&__Object,
  (id)&__Node,
  "TranslationUnit",
  0,
  sizeof(struct _SHARED),
  1,
  _TranslationUnit_clsDispatchTbl,
  34,
  &trlunit_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_TranslationUnit(void) { return (id)&__TranslationUnit; }
id  OBJCMSUPER_TranslationUnit(void) { return __TranslationUnit.clsSuper; }
static char *_selTransTbl[] ={
"commonsymbols",
"commontypes",
"commonexprs",
"new",
"sprintf:",
"msgcount",
"str:",
"strCopy",
"genshartype",
"inlinecacheprologue",
"checkbindprologue",
"add:",
"size",
"atKey:",
"asInt",
"atKey:put:",
"selector",
"at:",
"str",
"classname",
"genargstruct",
"gendispfun",
"genfwdstub",
"fwdname",
"allclsimpls",
"elementsPerform:",
"genglobfuncall",
"contains:",
"eachElement",
"next",
"genusesentries",
"genusecontrol",
"gendefinesentries",
"definesmain",
"warnpending",
"genimpl",
"genfwdstubs",
"genseltranstbl",
"genfwdtranstbl",
"genmodclslst",
"genmoddesc",
"genbindfun",
"postlinkmark",
"genocu",
"otbmark",
"find:",
"includes:",
"gen",
"go",
"eachValue",
"reset",
"browse",
"superclassdef",
"findsubclasses:",
"inspectbutton",
"browsesubclasses:filename:title:",
"browsemain",
"browseallclasses",
0
};
struct modDescriptor trlunit_modDesc = {
  "trlunit",
  "objc3.3.19",
  0L,
  0,
  0,
  &TranslationUnit,
  58,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_trlunit(void)
{
  selTransTbl = _selTransTbl;
  return &trlunit_modDesc;
}
int _OBJCPOSTLINK_trlunit = 1;


