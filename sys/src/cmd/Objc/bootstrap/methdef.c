# 1 "methdef.m"
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
extern struct modDescriptor  *_OBJCBIND_methdef(void);
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
extern struct modDescriptor methdef_modDesc;

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

# 28 "./../../include/objpak/set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./msgxpr.h"
extern id msgwraps;
# 22 "./stkframe.h"
extern id topframe;
# 22 "./methdef.h"
struct MethodDef_PRIVATE {

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
# 24 "./methdef.h"
id unit;
BOOL factory;
id method;
id body;
char*impname;
char*selname;
id classdef;
id breakpt;};

# 22 "./methdef.h"
extern id  MethodDef;

# 22 "./methdef.h"
extern struct _SHARED _MethodDef;
extern struct _SHARED __MethodDef;


# 50 "methdef.m"
static unsigned i_MethodDef_hash(struct MethodDef_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 52 "methdef.m"
return(objcT0=self->method,(*(unsigned(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static BOOL i_MethodDef_isEqual_(struct MethodDef_PRIVATE *self,SEL _cmd,id that)
{
if((id)self==that){
return(BOOL)1;
}else{
id objcT1,objcT2;

# 60 "methdef.m"
id b=(objcT1=that,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
return(objcT2=self->method,(*(BOOL(*)(id,SEL,id))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],b));
}
}

static BOOL i_MethodDef_factory(struct MethodDef_PRIVATE *self,SEL _cmd)
{
return self->factory;
}

static id i_MethodDef_restype(struct MethodDef_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 72 "methdef.m"
id r=(objcT3=self->method,(*_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));

return(r)?r:t_id;
}

static BOOL i_MethodDef_ismethdef(struct MethodDef_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_MethodDef_factory_(struct MethodDef_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
factory=flag;
return(id)self;
}

static char*i_MethodDef_selname(struct MethodDef_PRIVATE *self,SEL _cmd)
{
(void)0;
return self->selname;
}

static char*i_MethodDef_impname(struct MethodDef_PRIVATE *self,SEL _cmd)
{
(void)0;
return self->impname;
}

static id i_MethodDef_method(struct MethodDef_PRIVATE *self,SEL _cmd)
{
return self->method;
}

static id i_MethodDef_selector(struct MethodDef_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 107 "methdef.m"
return(objcT4=self->method,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
}

static id i_MethodDef_method_(struct MethodDef_PRIVATE *self,SEL _cmd,id aDecl)
{self->
method=aDecl;
return(id)self;
}

static id i_MethodDef_compound(struct MethodDef_PRIVATE *self,SEL _cmd)
{
return self->body;
}

static id i_MethodDef_body_(struct MethodDef_PRIVATE *self,SEL _cmd,id aBody)
{self->
body=aBody;
return(id)self;
}

static id i_MethodDef_classdef_(struct MethodDef_PRIVATE *self,SEL _cmd,id aClass)
{self->
classdef=aClass;
return(id)self;
}

static id i_MethodDef_prototype(struct MethodDef_PRIVATE *self,SEL _cmd)
{
if( !curclassdef){
fatal("method prototype outside interface");
}else{
id objcT5,objcT6;

# 138 "methdef.m"
id m,s=(objcT5=(id)self,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));

if(o_warntypeconflict&&(m=(objcT6=trlunit,(*_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5],s)))){
id objcT7;
if((objcT7=m,(*(BOOL(*)(id,SEL,id))_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2],self->method))){
(void)0;
}else{
id objcT8,objcT9,objcT10,objcT11;

# 145 "methdef.m"
int no=(objcT8=m,(*(int(*)(id,SEL))_imp(objcT8,selTransTbl[6]))(objcT8,selTransTbl[6]));
char*fn=(objcT9=(objcT10=m,(*_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7])),(*(STR(*)(id,SEL))_imp(objcT9,selTransTbl[8]))(objcT9,selTransTbl[8]));

warn("selector '%s' previously declared at %s:%d",(objcT11=s,(*(STR(*)(id,SEL))_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8])),fn,no);
}
}else{
id objcT12;

# 151 "methdef.m"
(objcT12=trlunit,(*_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9],s,self->method));
if(self->factory){
id objcT13;

# 153 "methdef.m"
(objcT13=curclassdef,(*_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10],s));
}else{
id objcT14;

# 155 "methdef.m"
(objcT14=curclassdef,(*_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11],s));
}
}
}
return(id)self;
}

# 59 "./symbol.h"
extern id  Symbol;

# 162 "methdef.m"
static id i_MethodDef_synth(struct MethodDef_PRIVATE *self,SEL _cmd)
{self->
unit=trlunit;

if( !curclassdef){
fatal("method definition outside implementation");
}else{
id objcT15,objcT16,objcT17,objcT18,objcT19;
id objcT20,objcT21,objcT22,objcT23,objcT24;
id objcT25,objcT26,objcT27,objcT28,objcT29;
id objcT30,objcT31,objcT32,objcT33,objcT34;
id objcT35,objcT36,objcT39,objcT40;

# 169 "methdef.m"
id t;
id x;
char*fmt;

(objcT15=(id)self,(*_imp(objcT15,selTransTbl[12]))(objcT15,selTransTbl[12],curclassdef));
curdef=(id)self;
curcompound=(id)0;
x=(objcT16=s_self,(*_imp(objcT16,selTransTbl[13]))(objcT16,selTransTbl[13]));
(objcT17=x,(*(id(*)(id,SEL,int))_imp(objcT17,selTransTbl[14]))(objcT17,selTransTbl[14],(objcT18=self->method,(*(int(*)(id,SEL))_imp(objcT18,selTransTbl[6]))(objcT18,selTransTbl[6]))));
(objcT19=x,(*_imp(objcT19,selTransTbl[15]))(objcT19,selTransTbl[15],(objcT20=self->method,(*_imp(objcT20,selTransTbl[7]))(objcT20,selTransTbl[7]))));
(objcT21=(id)self,(*_imp(objcT21,selTransTbl[16]))(objcT21,selTransTbl[16],x,(objcT22=self->classdef,(*_imp(objcT22,selTransTbl[17]))(objcT22,selTransTbl[17]))));
x=(objcT23=s_cmd,(*_imp(objcT23,selTransTbl[13]))(objcT23,selTransTbl[13]));
(objcT24=x,(*(id(*)(id,SEL,int))_imp(objcT24,selTransTbl[14]))(objcT24,selTransTbl[14],(objcT25=self->method,(*(int(*)(id,SEL))_imp(objcT25,selTransTbl[6]))(objcT25,selTransTbl[6]))));
(objcT26=x,(*_imp(objcT26,selTransTbl[15]))(objcT26,selTransTbl[15],(objcT27=self->method,(*_imp(objcT27,selTransTbl[7]))(objcT27,selTransTbl[7]))));
(objcT28=(id)self,(*_imp(objcT28,selTransTbl[16]))(objcT28,selTransTbl[16],x,t_sel));
(objcT29=self->method,(*_imp(objcT29,selTransTbl[18]))(objcT29,selTransTbl[18]));
(objcT30=curclassdef,(*_imp(objcT30,selTransTbl[19]))(objcT30,selTransTbl[19]));self->
selname=(objcT31=(objcT32=self->method,(*_imp(objcT32,selTransTbl[4]))(objcT32,selTransTbl[4])),(*(STR(*)(id,SEL))_imp(objcT31,selTransTbl[8]))(objcT31,selTransTbl[8]));
fmt=(self->factory)?"c_%s_%s":"i_%s_%s";
t=(objcT33=(objcT34=Symbol,(*(id(*)(id,SEL,STR,...))_imp(objcT34,selTransTbl[20]))(objcT34,selTransTbl[20],fmt,(objcT35=curclassdef,(*(char*(*)(id,SEL))_imp(objcT35,selTransTbl[21]))(objcT35,selTransTbl[21])),self->selname)),(*_imp(objcT33,selTransTbl[22]))(objcT33,selTransTbl[22]));self->
impname=(objcT36=t,(*(STR(*)(id,SEL))_imp(objcT36,selTransTbl[23]))(objcT36,selTransTbl[23]));
if(self->factory){
id objcT37;

# 191 "methdef.m"
(objcT37=curclassdef,(*_imp(objcT37,selTransTbl[24]))(objcT37,selTransTbl[24],(id)self));
}else{
id objcT38;

# 193 "methdef.m"
(objcT38=curclassdef,(*_imp(objcT38,selTransTbl[25]))(objcT38,selTransTbl[25],(id)self));
}
(objcT39=trlunit,(*(id(*)(id,SEL,BOOL))_imp(objcT39,selTransTbl[26]))(objcT39,selTransTbl[26],(BOOL)0));
(objcT40=self->body,(*_imp(objcT40,selTransTbl[18]))(objcT40,selTransTbl[18]));
curdef=(id)0;
}
return(id)self;
}

static id i_MethodDef_gen(struct MethodDef_PRIVATE *self,SEL _cmd)
{
id objcT41,objcT42,objcT43,objcT44,objcT45;
id objcT46,objcT47,objcT48,objcT49,objcT50;

# 204 "methdef.m"
id f,c;

(objcT41=self->classdef,(*_imp(objcT41,selTransTbl[27]))(objcT41,selTransTbl[27]));
(objcT42=_MethodDef.clsSuper,(*_impSuper(objcT42,selTransTbl[27]))((id)self,selTransTbl[27]));
if((f=(objcT43=self->method,(*_imp(objcT43,selTransTbl[7]))(objcT43,selTransTbl[7]))))
gl((objcT44=self->method,(*(int(*)(id,SEL))_imp(objcT44,selTransTbl[6]))(objcT44,selTransTbl[6])),(objcT45=f,(*(STR(*)(id,SEL))_imp(objcT45,selTransTbl[8]))(objcT45,selTransTbl[8])));
gs("static");
(objcT46=self->method,(*_imp(objcT46,selTransTbl[28]))(objcT46,selTransTbl[28]));
gs(self->impname);
gc('(');
c=self->classdef;
(void)0;
gf("struct %s *self,SEL _cmd",(o_otb)?(objcT47=c,(*(char*(*)(id,SEL))_imp(objcT47,selTransTbl[29]))(objcT47,selTransTbl[29])):(objcT48=c,(*(char*(*)(id,SEL))_imp(objcT48,selTransTbl[30]))(objcT48,selTransTbl[30])));
(objcT49=self->method,(*_imp(objcT49,selTransTbl[31]))(objcT49,selTransTbl[31]));
gc(')');
(objcT50=self->body,(*_imp(objcT50,selTransTbl[27]))(objcT50,selTransTbl[27]));
return(id)self;
}

static id i_MethodDef_st80(struct MethodDef_PRIVATE *self,SEL _cmd)
{
id objcT51,objcT52,objcT53,objcT54,objcT55;
id objcT56,objcT57,objcT58,objcT59;

# 225 "methdef.m"
int no;
char*fn,*sl;

(objcT51=self->classdef,(*_imp(objcT51,selTransTbl[32]))(objcT51,selTransTbl[32]));
gf("!%s methodsFor:'POC Generated' stamp: 'POC'!",(objcT52=self->classdef,(*(char*(*)(id,SEL))_imp(objcT52,selTransTbl[21]))(objcT52,selTransTbl[21])));
gc('\n');
(objcT53=self->method,(*_imp(objcT53,selTransTbl[32]))(objcT53,selTransTbl[32]));
gc('\n');
no=(objcT54=self->method,(*(int(*)(id,SEL))_imp(objcT54,selTransTbl[6]))(objcT54,selTransTbl[6]));
fn=(objcT55=(objcT56=self->method,(*_imp(objcT56,selTransTbl[7]))(objcT56,selTransTbl[7])),(*(STR(*)(id,SEL))_imp(objcT55,selTransTbl[8]))(objcT55,selTransTbl[8]));
sl=(objcT57=(objcT58=self->method,(*_imp(objcT58,selTransTbl[4]))(objcT58,selTransTbl[4])),(*(STR(*)(id,SEL))_imp(objcT57,selTransTbl[8]))(objcT57,selTransTbl[8]));
gf("\t\"Generated from '%c%s' at %s:%d\"",(self->factory)?'+':'-',sl,fn,no);
gc('\n');
(objcT59=self->body,(*_imp(objcT59,selTransTbl[32]))(objcT59,selTransTbl[32]));
gs("! !\n");
gc('\n');
return(id)self;
}

# 24 "./stkframe.h"
extern id  Stackframe;

# 244 "methdef.m"
static id i_MethodDef_fcall_(struct MethodDef_PRIVATE *self,SEL _cmd,id x)
{
id objcT60,objcT61,objcT62,objcT63,objcT64;

# 246 "methdef.m"
id r;
trlunit=self->unit;
if(self->breakpt)(objcT60=self->breakpt,(*_imp(objcT60,selTransTbl[33]))(objcT60,selTransTbl[33]));
(objcT61=(objcT62=Stackframe,(*_imp(objcT62,selTransTbl[34]))(objcT62,selTransTbl[34])),(*_imp(objcT61,selTransTbl[35]))(objcT61,selTransTbl[35],(id)self));
r=(objcT63=self->body,(*_imp(objcT63,selTransTbl[36]))(objcT63,selTransTbl[36],x));
(objcT64=Stackframe,(*_imp(objcT64,selTransTbl[37]))(objcT64,selTransTbl[37]));
return r;
}

static id i_MethodDef_printBtOn_(struct MethodDef_PRIVATE *self,SEL _cmd,IOD d)
{
id objcT65,objcT66,objcT67,objcT68,objcT69;
id objcT70;

# 257 "methdef.m"
int no=(objcT65=self->method,(*(int(*)(id,SEL))_imp(objcT65,selTransTbl[6]))(objcT65,selTransTbl[6]));
char*fn=(objcT66=(objcT67=self->method,(*_imp(objcT67,selTransTbl[7]))(objcT67,selTransTbl[7])),(*(STR(*)(id,SEL))_imp(objcT66,selTransTbl[8]))(objcT66,selTransTbl[8]));
char*cn=(objcT68=self->classdef,(*(char*(*)(id,SEL))_imp(objcT68,selTransTbl[21]))(objcT68,selTransTbl[21]));
char*sn=(objcT69=(objcT70=(id)self,(*_imp(objcT70,selTransTbl[4]))(objcT70,selTransTbl[4])),(*(STR(*)(id,SEL))_imp(objcT69,selTransTbl[8]))(objcT69,selTransTbl[8]));
fprintf(d,(self->factory)?"+":"-");
fprintf(d,"[%s %s] at %s:%d\n",cn,sn,fn,no);
return(id)self;
}

static id i_MethodDef_setbreak_(struct MethodDef_PRIVATE *self,SEL _cmd,id bkpt)
{self->
breakpt=bkpt;
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Def;
extern struct _SHARED _Def;
extern struct _SHARED __Def;
static struct _SLT _MethodDef_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _MethodDef_nstDispatchTbl[] ={
{"hash",(id (*)())i_MethodDef_hash},
{"isEqual:",(id (*)())i_MethodDef_isEqual_},
{"factory",(id (*)())i_MethodDef_factory},
{"restype",(id (*)())i_MethodDef_restype},
{"ismethdef",(id (*)())i_MethodDef_ismethdef},
{"factory:",(id (*)())i_MethodDef_factory_},
{"selname",(id (*)())i_MethodDef_selname},
{"impname",(id (*)())i_MethodDef_impname},
{"method",(id (*)())i_MethodDef_method},
{"selector",(id (*)())i_MethodDef_selector},
{"method:",(id (*)())i_MethodDef_method_},
{"compound",(id (*)())i_MethodDef_compound},
{"body:",(id (*)())i_MethodDef_body_},
{"classdef:",(id (*)())i_MethodDef_classdef_},
{"prototype",(id (*)())i_MethodDef_prototype},
{"synth",(id (*)())i_MethodDef_synth},
{"gen",(id (*)())i_MethodDef_gen},
{"st80",(id (*)())i_MethodDef_st80},
{"fcall:",(id (*)())i_MethodDef_fcall_},
{"printBtOn:",(id (*)())i_MethodDef_printBtOn_},
{"setbreak:",(id (*)())i_MethodDef_setbreak_},
{(char*)0,(id (*)())0}
};
id MethodDef = (id)&_MethodDef;
id  *OBJCCLASS_MethodDef(void) { return &MethodDef; }
struct _SHARED  _MethodDef = {
  (id)&__MethodDef,
  (id)&_Def,
  "MethodDef",
  0,
  sizeof(struct MethodDef_PRIVATE),
  21,
  _MethodDef_nstDispatchTbl,
  41,
  &methdef_modDesc,
  0,
  (id)0,
  &MethodDef,
};
id  OBJCCFUNC_MethodDef(void) { return (id)&_MethodDef; }
id  OBJCCSUPER_MethodDef(void) { return _MethodDef.clsSuper; }
struct _SHARED __MethodDef = {
  (id)&__Object,
  (id)&__Def,
  "MethodDef",
  0,
  sizeof(struct _SHARED),
  0,
  _MethodDef_clsDispatchTbl,
  34,
  &methdef_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_MethodDef(void) { return (id)&__MethodDef; }
id  OBJCMSUPER_MethodDef(void) { return __MethodDef.clsSuper; }
static char *_selTransTbl[] ={
"typehash",
"method",
"typeEqual:",
"restype",
"selector",
"lookupmethod:",
"lineno",
"filename",
"str",
"def:asmethod:",
"addclssel:",
"addnstsel:",
"classdef:",
"copy",
"lineno:",
"filename:",
"defparm:astype:",
"selftype",
"synth",
"forceimpl",
"sprintf:",
"classname",
"toscores",
"strCopy",
"addclsdisp:",
"addnstdisp:",
"usingselfassign:",
"gen",
"genrestype",
"otbtypename",
"privtypename",
"genparmlist",
"st80",
"go",
"push",
"def:",
"fcall:",
"pop",
0
};
struct modDescriptor methdef_modDesc = {
  "methdef",
  "objc3.3.19",
  0L,
  0,
  0,
  &MethodDef,
  38,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_methdef(void)
{
  selTransTbl = _selTransTbl;
  return &methdef_modDesc;
}
int _OBJCPOSTLINK_methdef = 1;


