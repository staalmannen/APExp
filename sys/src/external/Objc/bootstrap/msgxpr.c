# 1 "msgxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_msgxpr(void);
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
extern struct modDescriptor msgxpr_modDesc;

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
# 28 "./../../include/objpak/set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
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
# 22 "./msgxpr.h"
extern id msgwraps;
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
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
# 22 "./def.h"
extern id curdef;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
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
# 51 "msgxpr.m"
id msgwraps;
# 24 "./msgxpr.h"
struct MesgExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 26 "./msgxpr.h"
id msg;
id sel;
id rcvr;
BOOL supermsg;
BOOL infactory;
BOOL indispatchfun;
BOOL methodfound;
id method;
id classdef;
id tmpvar;
id refvar;
id icache;
char*fwdname;
char*dispname;
char*argstructname;
id msgwrap;};

# 24 "./msgxpr.h"
extern id  MesgExpr;

# 24 "./msgxpr.h"
extern struct _SHARED _MesgExpr;
extern struct _SHARED __MesgExpr;


# 57 "msgxpr.m"
static BOOL i_MesgExpr_canforward(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 62 "msgxpr.m"
return self->method!=(id)0&&(objcT0=self->method,(*(BOOL(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));

}

static unsigned i_MesgExpr_hash(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 68 "msgxpr.m"
id a;

if((a=(objcT1=(id)self,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1])))){
id objcT2;

# 71 "msgxpr.m"
return(objcT2=a,(*(unsigned(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
}else{
id objcT3;

# 73 "msgxpr.m"
return(objcT3=self->msg,(*(unsigned(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]));
}
}

static BOOL i_MesgExpr_isEqual_(struct MesgExpr_PRIVATE *self,SEL _cmd,id that)
{
if((id)self==that){
return(BOOL)1;
}else{
id objcT4,objcT5,objcT6,objcT7,objcT8;

# 82 "msgxpr.m"
id a=(objcT4=(id)self,(*_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1]));
id b=(objcT5=that,(*_imp(objcT5,selTransTbl[1]))(objcT5,selTransTbl[1]));

if( !a)
a=(objcT6=(id)self,(*_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4]));
if( !b)
b=(objcT7=that,(*_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4]));
return(objcT8=a,(*(BOOL(*)(id,SEL,id))_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5],b));
}
}

static id i_MesgExpr_receiver_(struct MesgExpr_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
rcvr=aRcvr;
return(id)self;
}

static id i_MesgExpr_msg_(struct MesgExpr_PRIVATE *self,SEL _cmd,id m)
{self->
msg=m;
(void)0;
return(id)self;
}

static id i_MesgExpr_tmpvar(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 108 "msgxpr.m"
if(self->tmpvar)
return self->tmpvar;

return self->tmpvar=(objcT9=trlunit,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
}

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 114 "msgxpr.m"
static id i_MesgExpr_icache(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11;

# 116 "msgxpr.m"
if(self->icache)
return self->icache;
return self->icache=(objcT10=String,(*(id(*)(id,SEL,STR,...))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7],"objcIC%i",(objcT11=trlunit,(*(int(*)(id,SEL))_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8]))));
}

static id i_MesgExpr_msg(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
return self->msg;
}

static id i_MesgExpr_method_(struct MesgExpr_PRIVATE *self,SEL _cmd,id m)
{
id objcT12;

# 128 "msgxpr.m"
if(self->methodfound)(objcT12=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT12,selTransTbl[9]))(objcT12,selTransTbl[9],_cmd));self->
methodfound++;self->
method=m;
return(id)self;
}

static id i_MesgExpr_method(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
if(self->methodfound){
return self->method;
}else{
id objcT13,objcT14;
self->
# 139 "msgxpr.m"
methodfound++;self->
method=(objcT13=trlunit,(*_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10],(objcT14=(id)self,(*_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11]))));
if( !self->method&&o_warnundefined){
id objcT15;

# 142 "msgxpr.m"
warnat(self->msg,"argument types for '%s' default to 'id'",(objcT15=self->sel,(*(STR(*)(id,SEL))_imp(objcT15,selTransTbl[12]))(objcT15,selTransTbl[12])));
}else{
id objcT16,objcT17;

# 144 "msgxpr.m"
if((objcT16=self->method,(*(BOOL(*)(id,SEL))_imp(objcT16,selTransTbl[13]))(objcT16,selTransTbl[13])))
(objcT17=self->msg,(*_imp(objcT17,selTransTbl[14]))(objcT17,selTransTbl[14]));
}
return self->method;
}
}

static id i_MesgExpr_indispatchfun_(struct MesgExpr_PRIVATE *self,SEL _cmd,BOOL f)
{self->
indispatchfun=f;
return(id)self;
}

static BOOL i_MesgExpr_varargs(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19;

# 159 "msgxpr.m"
return(objcT18=(objcT19=(id)self,(*_imp(objcT19,selTransTbl[1]))(objcT19,selTransTbl[1])),(*(BOOL(*)(id,SEL))_imp(objcT18,selTransTbl[13]))(objcT18,selTransTbl[13]));
}

static id i_MesgExpr_selector(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT20;

# 164 "msgxpr.m"
if(self->sel)
return self->sel;self->
sel=(objcT20=self->msg,(*_imp(objcT20,selTransTbl[11]))(objcT20,selTransTbl[11]));
return self->sel;
}

static id i_MesgExpr_typesynth(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT21,objcT22;

# 172 "msgxpr.m"
if((objcT21=(id)self,(*_imp(objcT21,selTransTbl[1]))(objcT21,selTransTbl[1])))self->
type=(objcT22=self->method,(*_imp(objcT22,selTransTbl[15]))(objcT22,selTransTbl[15]));
if( !self->type)self->
type=t_id;
return(id)self;
}

static id i_MesgExpr_synth(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT23,objcT24,objcT25,objcT34,objcT35;
id objcT36,objcT37;
self->
# 182 "msgxpr.m"
method=(objcT23=(id)self,(*_imp(objcT23,selTransTbl[1]))(objcT23,selTransTbl[1]));
if((objcT24=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT24,selTransTbl[13]))(objcT24,selTransTbl[13])))
(objcT25=self->msg,(*_imp(objcT25,selTransTbl[16]))(objcT25,selTransTbl[16]));

if(curcompound){
id objcT26,objcT27,objcT30,objcT31,objcT32;
id objcT33;

# 187 "msgxpr.m"
BOOL inm=(curdef&&(objcT26=curdef,(*(BOOL(*)(id,SEL))_imp(objcT26,selTransTbl[17]))(objcT26,selTransTbl[17])));


if(inm&&(objcT27=self->rcvr,(*(BOOL(*)(id,SEL))_imp(objcT27,selTransTbl[18]))(objcT27,selTransTbl[18]))){
id objcT28,objcT29;
self->
# 191 "msgxpr.m"
supermsg= !strcmp((objcT28=self->rcvr,(*(STR(*)(id,SEL))_imp(objcT28,selTransTbl[12]))(objcT28,selTransTbl[12])),"super");self->
infactory=(objcT29=curdef,(*(BOOL(*)(id,SEL))_imp(objcT29,selTransTbl[19]))(objcT29,selTransTbl[19]));self->
classdef=curclassdef;
if(self->supermsg)self->
rcvr=(id)0;
}
(objcT30=curcompound,(*_imp(objcT30,selTransTbl[20]))(objcT30,selTransTbl[20],(objcT31=(id)self,(*_imp(objcT31,selTransTbl[21]))(objcT31,selTransTbl[21]))));
if(o_inlinecache)
(objcT32=curcompound,(*_imp(objcT32,selTransTbl[22]))(objcT32,selTransTbl[22],(objcT33=(id)self,(*_imp(objcT33,selTransTbl[23]))(objcT33,selTransTbl[23]))));
}else{
fatalat(self->msg,"message expression outside compound statement");
}

if(self->rcvr)
(objcT34=self->rcvr,(*_imp(objcT34,selTransTbl[24]))(objcT34,selTransTbl[24]));
(objcT35=self->msg,(*_imp(objcT35,selTransTbl[24]))(objcT35,selTransTbl[24]));

if(o_refcnt&&(objcT36=(objcT37=(id)self,(*_imp(objcT37,selTransTbl[25]))(objcT37,selTransTbl[25])),(*(BOOL(*)(id,SEL))_imp(objcT36,selTransTbl[26]))(objcT36,selTransTbl[26]))){
id objcT38,objcT39,objcT40;
self->
# 209 "msgxpr.m"
refvar=(objcT38=trlunit,(*_imp(objcT38,selTransTbl[6]))(objcT38,selTransTbl[6]));
(objcT39=curcompound,(*_imp(objcT39,selTransTbl[20]))(objcT39,selTransTbl[20],self->refvar));
(objcT40=curcompound,(*_imp(objcT40,selTransTbl[27]))(objcT40,selTransTbl[27],self->refvar));
}
return(id)self;
}

static id i_MesgExpr_assignrcvr(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT41,objcT42,objcT43;

# 218 "msgxpr.m"
id t=(objcT41=(id)self,(*_imp(objcT41,selTransTbl[21]))(objcT41,selTransTbl[21]));

gf("%s=",(objcT42=t,(*(STR(*)(id,SEL))_imp(objcT42,selTransTbl[12]))(objcT42,selTransTbl[12])));
(objcT43=self->rcvr,(*_imp(objcT43,selTransTbl[28]))(objcT43,selTransTbl[28]));
return(id)self;
}

static id i_MesgExpr_assignsuper(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT44,objcT45,objcT46,objcT47;

# 227 "msgxpr.m"
id t=(objcT44=(id)self,(*_imp(objcT44,selTransTbl[21]))(objcT44,selTransTbl[21]));

gf("%s=",(objcT45=t,(*(STR(*)(id,SEL))_imp(objcT45,selTransTbl[12]))(objcT45,selTransTbl[12])));
(void)0;
return(self->infactory)?(objcT46=self->classdef,(*_imp(objcT46,selTransTbl[29]))(objcT46,selTransTbl[29])):(objcT47=self->classdef,(*_imp(objcT47,selTransTbl[30]))(objcT47,selTransTbl[30]));
}

static id i_MesgExpr_genimpcall_(struct MesgExpr_PRIVATE *self,SEL _cmd,BOOL tosuper)
{
char*messenger;

if( !o_fwd){
id objcT48;

# 239 "msgxpr.m"
messenger=(tosuper)?"_impSuper":"_imp";
gf("%s(%s,",messenger,(objcT48=self->tmpvar,(*(STR(*)(id,SEL))_imp(objcT48,selTransTbl[12]))(objcT48,selTransTbl[12])));
if(self->indispatchfun){
gs("_cmd");
}else{
id objcT49,objcT50;

# 244 "msgxpr.m"
(objcT49=(objcT50=(id)self,(*_imp(objcT50,selTransTbl[11]))(objcT50,selTransTbl[11])),(*_imp(objcT49,selTransTbl[28]))(objcT49,selTransTbl[28]));
}
gc(')');
}else{
id objcT51,objcT54;

# 248 "msgxpr.m"
messenger=(tosuper)?"fwdimpSuper":"fwdimp";
gf("%s(%s,",messenger,(objcT51=self->tmpvar,(*(STR(*)(id,SEL))_imp(objcT51,selTransTbl[12]))(objcT51,selTransTbl[12])));
if(self->indispatchfun){
gs("_cmd");
}else{
id objcT52,objcT53;

# 253 "msgxpr.m"
(objcT52=(objcT53=(id)self,(*_imp(objcT53,selTransTbl[11]))(objcT53,selTransTbl[11])),(*_imp(objcT52,selTransTbl[28]))(objcT52,selTransTbl[28]));
}
gc(',');
if((objcT54=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT54,selTransTbl[0]))(objcT54,selTransTbl[0]))){
id objcT55;

# 257 "msgxpr.m"
if((objcT55=self->method,(*(BOOL(*)(id,SEL))_imp(objcT55,selTransTbl[31]))(objcT55,selTransTbl[31]))){
gs("selptrfwd");
}else{
id objcT56;

# 260 "msgxpr.m"
gf("fwdTransTbl[%i]",(objcT56=trlunit,(*(int(*)(id,SEL,id))_imp(objcT56,selTransTbl[32]))(objcT56,selTransTbl[32],(id)self)));
}
}else{
gs((o_cplus)?"(id(*)(...))0":"(id(*)())0");
if(o_warnfwd){
id objcT57;

# 265 "msgxpr.m"
char*fmt;

if(self->method){
fmt="forwarding of '%s' messages not supported";
}else{
fmt="cannot forward '%s'. no such method found.";
}
warnat(self->msg,fmt,(objcT57=self->sel,(*(STR(*)(id,SEL))_imp(objcT57,selTransTbl[12]))(objcT57,selTransTbl[12])));
}
}
gc(')');
}

return(id)self;
}

static id i_MesgExpr_geninlinecall_(struct MesgExpr_PRIVATE *self,SEL _cmd,BOOL tosuper)
{
id objcT58,objcT59,objcT60;

# 283 "msgxpr.m"
char*fmt;
char*tvar=(objcT58=self->tmpvar,(*(STR(*)(id,SEL))_imp(objcT58,selTransTbl[12]))(objcT58,selTransTbl[12]));
char*cache=(objcT59=self->icache,(*(STR(*)(id,SEL))_imp(objcT59,selTransTbl[12]))(objcT59,selTransTbl[12]));

gf("(%s)?(",tvar);
gc('(');
if( !o_otb){
fmt=(tosuper)?"%s":"%s->isa";
}else{
fmt=(tosuper)?"%s":"%s->ptr->isa";
}
gf(fmt,tvar);
gf("==%s.cls)?%s.imp:",cache,cache);
gc('(');
gf("%s.cls=",cache);
gf(fmt,tvar);
gf(",%s.imp=",cache);
(objcT60=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT60,selTransTbl[33]))(objcT60,selTransTbl[33],tosuper));
gc(')');
gs("):_nilHandler");
return(id)self;
}



static id i_MesgExpr_gencall_(struct MesgExpr_PRIVATE *self,SEL _cmd,BOOL tosuper)
{
id objcT61;

# 310 "msgxpr.m"
gs("(*");
if(self->method&&(objcT61=self->method,(*(BOOL(*)(id,SEL))_imp(objcT61,selTransTbl[34]))(objcT61,selTransTbl[34]))){
id objcT62;

# 312 "msgxpr.m"
gc('(');
(objcT62=self->method,(*_imp(objcT62,selTransTbl[35]))(objcT62,selTransTbl[35]));
gc(')');
}
if(o_inlinecache&& !self->indispatchfun){
id objcT63;

# 317 "msgxpr.m"
gc('(');
(objcT63=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT63,selTransTbl[36]))(objcT63,selTransTbl[36],tosuper));
gc(')');
}else{
id objcT64;

# 321 "msgxpr.m"
(objcT64=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT64,selTransTbl[33]))(objcT64,selTransTbl[33],tosuper));
}
gc(')');
return(id)self;
}

static id i_MesgExpr_genmsgargs_(struct MesgExpr_PRIVATE *self,SEL _cmd,BOOL tosuper)
{
if(tosuper){
id objcT65;

# 330 "msgxpr.m"
gs("(id)");
(objcT65=e_self,(*_imp(objcT65,selTransTbl[37]))(objcT65,selTransTbl[37]));
}else{
id objcT66;

# 333 "msgxpr.m"
gs((objcT66=self->tmpvar,(*(STR(*)(id,SEL))_imp(objcT66,selTransTbl[12]))(objcT66,selTransTbl[12])));
}

gc(',');
if(self->indispatchfun){
gs("_cmd");
}else{
id objcT67,objcT68;

# 340 "msgxpr.m"
(objcT67=(objcT68=(id)self,(*_imp(objcT68,selTransTbl[11]))(objcT68,selTransTbl[11])),(*_imp(objcT67,selTransTbl[28]))(objcT67,selTransTbl[28]));
}

if(self->indispatchfun){
id objcT69;

# 344 "msgxpr.m"
(objcT69=self->method,(*_imp(objcT69,selTransTbl[38]))(objcT69,selTransTbl[38]));
}else{
id objcT70;

# 346 "msgxpr.m"
(objcT70=self->msg,(*_imp(objcT70,selTransTbl[39]))(objcT70,selTransTbl[39]));
}

return(id)self;
}

static id i_MesgExpr_genmsg_(struct MesgExpr_PRIVATE *self,SEL _cmd,BOOL insuper)
{
id objcT71,objcT72;

# 354 "msgxpr.m"
(objcT71=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT71,selTransTbl[40]))(objcT71,selTransTbl[40],insuper));
gc('(');
(objcT72=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT72,selTransTbl[41]))(objcT72,selTransTbl[41],insuper));
gc(')');
return(id)self;
}

static id i_MesgExpr_genmsg(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT73,objcT74;

# 363 "msgxpr.m"
gc('(');
(objcT73=(id)self,(*_imp(objcT73,selTransTbl[42]))(objcT73,selTransTbl[42]));
gc(',');
(objcT74=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT74,selTransTbl[43]))(objcT74,selTransTbl[43],(BOOL)0));
gc(')');
return(id)self;
}

static id i_MesgExpr_gensupermsg(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT75,objcT76;

# 373 "msgxpr.m"
gc('(');
(objcT75=(id)self,(*_imp(objcT75,selTransTbl[44]))(objcT75,selTransTbl[44]));
gc(',');
(objcT76=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT76,selTransTbl[43]))(objcT76,selTransTbl[43],(BOOL)1));
gc(')');
return(id)self;
}

static int i_MesgExpr_lineno(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT77;

# 383 "msgxpr.m"
return(objcT77=self->msg,(*(int(*)(id,SEL))_imp(objcT77,selTransTbl[45]))(objcT77,selTransTbl[45]));
}

static id i_MesgExpr_filename(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT78;

# 388 "msgxpr.m"
return(objcT78=self->msg,(*_imp(objcT78,selTransTbl[46]))(objcT78,selTransTbl[46]));
}

static id i_MesgExpr_gen(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT79,objcT80,objcT81,objcT83,objcT84;

# 393 "msgxpr.m"
gl((objcT79=self->msg,(*(int(*)(id,SEL))_imp(objcT79,selTransTbl[45]))(objcT79,selTransTbl[45])),(objcT80=(objcT81=self->msg,(*_imp(objcT81,selTransTbl[46]))(objcT81,selTransTbl[46])),(*(STR(*)(id,SEL))_imp(objcT80,selTransTbl[12]))(objcT80,selTransTbl[12])));
if(self->refvar){
id objcT82;

# 395 "msgxpr.m"
gc('(');
gs((objcT82=self->refvar,(*(STR(*)(id,SEL))_imp(objcT82,selTransTbl[12]))(objcT82,selTransTbl[12])));
gc('=');
}
(self->supermsg)?(objcT83=(id)self,(*_imp(objcT83,selTransTbl[47]))(objcT83,selTransTbl[47])):(objcT84=(id)self,(*_imp(objcT84,selTransTbl[48]))(objcT84,selTransTbl[48]));
if(self->refvar)gc(')');
return(id)self;
}

# 59 "./symbol.h"
extern id  Symbol;

# 404 "msgxpr.m"
static char*i_MesgExpr_fwdname(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT85,objcT86,objcT87,objcT88;

# 406 "msgxpr.m"
(void)0;
if(self->fwdname)
return self->fwdname;self->
fwdname=(objcT85=(objcT86=(objcT87=Symbol,(*(id(*)(id,SEL,STR,...))_imp(objcT87,selTransTbl[7]))(objcT87,selTransTbl[7],"%s_fwd",(objcT88=self->sel,(*(STR(*)(id,SEL))_imp(objcT88,selTransTbl[12]))(objcT88,selTransTbl[12])))),(*_imp(objcT86,selTransTbl[49]))(objcT86,selTransTbl[49])),(*(STR(*)(id,SEL))_imp(objcT85,selTransTbl[50]))(objcT85,selTransTbl[50]));
return self->fwdname;
}

static char*i_MesgExpr_dispname(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT89,objcT90,objcT91,objcT92;

# 415 "msgxpr.m"
(void)0;
if(self->dispname)
return self->dispname;self->
dispname=(objcT89=(objcT90=(objcT91=Symbol,(*(id(*)(id,SEL,STR,...))_imp(objcT91,selTransTbl[7]))(objcT91,selTransTbl[7],"%s_disp",(objcT92=self->sel,(*(STR(*)(id,SEL))_imp(objcT92,selTransTbl[12]))(objcT92,selTransTbl[12])))),(*_imp(objcT90,selTransTbl[49]))(objcT90,selTransTbl[49])),(*(STR(*)(id,SEL))_imp(objcT89,selTransTbl[50]))(objcT89,selTransTbl[50]));
return self->dispname;
}

static char*i_MesgExpr_argstructname(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT93,objcT94,objcT95,objcT96;

# 424 "msgxpr.m"
(void)0;
if(self->argstructname)
return self->argstructname;self->
argstructname=(objcT93=(objcT94=(objcT95=Symbol,(*(id(*)(id,SEL,STR,...))_imp(objcT95,selTransTbl[7]))(objcT95,selTransTbl[7],"%s_args",(objcT96=self->sel,(*(STR(*)(id,SEL))_imp(objcT96,selTransTbl[12]))(objcT96,selTransTbl[12])))),(*_imp(objcT94,selTransTbl[49]))(objcT94,selTransTbl[49])),(*(STR(*)(id,SEL))_imp(objcT93,selTransTbl[50]))(objcT93,selTransTbl[50]));
return self->argstructname;
}

static id i_MesgExpr_genargstruct(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT97,objcT98;

# 433 "msgxpr.m"
(void)0;
gf("struct %s {\n",(objcT97=(id)self,(*(char*(*)(id,SEL))_imp(objcT97,selTransTbl[51]))(objcT97,selTransTbl[51])));
(objcT98=self->method,(*_imp(objcT98,selTransTbl[52]))(objcT98,selTransTbl[52]));
gs("};\n");
return(id)self;
}

static id i_MesgExpr_xgendispfun(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT99,objcT100,objcT101,objcT102,objcT103;

# 442 "msgxpr.m"
id rt;

(void)0;
gf("static void %s(id self,SEL _cmd",(objcT99=(id)self,(*(char*(*)(id,SEL))_imp(objcT99,selTransTbl[53]))(objcT99,selTransTbl[53])));
gf(",struct %s *args)\n",(objcT100=(id)self,(*(char*(*)(id,SEL))_imp(objcT100,selTransTbl[51]))(objcT100,selTransTbl[51])));
gs("{\n");
if((rt=(objcT101=self->method,(*_imp(objcT101,selTransTbl[15]))(objcT101,selTransTbl[15])))==(id)0|| !(objcT102=rt,(*(BOOL(*)(id,SEL))_imp(objcT102,selTransTbl[54]))(objcT102,selTransTbl[54]))){
gs("args->_retval = ");
}
(objcT103=(id)self,(*(id(*)(id,SEL,BOOL))_imp(objcT103,selTransTbl[43]))(objcT103,selTransTbl[43],(BOOL)0));
gs(";\n");
gs("}\n");
return(id)self;
}

static id i_MesgExpr_gendispfun(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT104;

# 459 "msgxpr.m"
(void)0;self->
rcvr=e_self;self->
tmpvar=e_self;self->
indispatchfun++;
return(objcT104=(id)self,(*_imp(objcT104,selTransTbl[55]))(objcT104,selTransTbl[55]));
}

static id i_MesgExpr_gendispargsintostruct(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT105;

# 468 "msgxpr.m"
(objcT105=self->method,(*_imp(objcT105,selTransTbl[56]))(objcT105,selTransTbl[56]));
return(id)self;
}

static id i_MesgExpr_genfwdstub(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT106,objcT107,objcT108,objcT109,objcT110;
id objcT111,objcT112,objcT113;

# 474 "msgxpr.m"
id rt;

(void)0;
gs("static ");
(objcT106=self->method,(*_imp(objcT106,selTransTbl[57]))(objcT106,selTransTbl[57]));
gf(" %s(id self,SEL _cmd",(objcT107=(id)self,(*(char*(*)(id,SEL))_imp(objcT107,selTransTbl[58]))(objcT107,selTransTbl[58])));
(objcT108=self->method,(*_imp(objcT108,selTransTbl[59]))(objcT108,selTransTbl[59]));
gs(")\n");
gs("{\n");
gf("struct %s args;\n",(objcT109=(id)self,(*(char*(*)(id,SEL))_imp(objcT109,selTransTbl[51]))(objcT109,selTransTbl[51])));
(objcT110=(id)self,(*_imp(objcT110,selTransTbl[56]))(objcT110,selTransTbl[56]));
gf("fwdmsg(self,_cmd,&args,(ARGIMP)%s);\n",(objcT111=(id)self,(*(char*(*)(id,SEL))_imp(objcT111,selTransTbl[53]))(objcT111,selTransTbl[53])));
if((rt=(objcT112=self->method,(*_imp(objcT112,selTransTbl[15]))(objcT112,selTransTbl[15])))==(id)0|| !(objcT113=rt,(*(BOOL(*)(id,SEL))_imp(objcT113,selTransTbl[54]))(objcT113,selTransTbl[54]))){
gs("return args._retval;\n");
}
gs("}\n");
return(id)self;
}

static id i_MesgExpr_st80(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT114,objcT115;

# 495 "msgxpr.m"
gc('(');
(objcT114=self->rcvr,(*_imp(objcT114,selTransTbl[60]))(objcT114,selTransTbl[60]));
(objcT115=self->msg,(*_imp(objcT115,selTransTbl[60]))(objcT115,selTransTbl[60]));
gc(')');
return(id)self;
}

static id i_MesgExpr_send_sel_with_to_(struct MesgExpr_PRIVATE *self,SEL _cmd,IMP i,SEL sel,id kw,id rcvr)
{
id objcT116;

# 504 "msgxpr.m"
return(objcT116=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT116,selTransTbl[61]))(objcT116,selTransTbl[61],_cmd));
}

static id i_MesgExpr_go(struct MesgExpr_PRIVATE *self,SEL _cmd)
{
id objcT117;

# 509 "msgxpr.m"
id r;
if((r=(objcT117=self->rcvr,(*_imp(objcT117,selTransTbl[62]))(objcT117,selTransTbl[62])))){
id objcT118,objcT119,objcT120;

# 511 "msgxpr.m"
SEL s;
char*sn;
sn=(objcT118=(objcT119=(id)self,(*_imp(objcT119,selTransTbl[11]))(objcT119,selTransTbl[11])),(*(STR(*)(id,SEL))_imp(objcT118,selTransTbl[12]))(objcT118,selTransTbl[12]));
if((s=(objcT120=(id)self,(*(SEL(*)(id,SEL,STR))_imp(objcT120,selTransTbl[63]))(objcT120,selTransTbl[63],sn)))){
id objcT121,objcT122,objcT123,objcT124,objcT125;

# 515 "msgxpr.m"
IMP i=(objcT121=r,(*(IMP(*)(id,SEL,SEL))_imp(objcT121,selTransTbl[64]))(objcT121,selTransTbl[64],s));
if( !self->msgwrap)self->msgwrap=(objcT122=msgwraps,(*_imp(objcT122,selTransTbl[65]))(objcT122,selTransTbl[65],(id)self));
if( !self->msgwrap)(objcT123=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT123,selTransTbl[66]))(objcT123,selTransTbl[66],"'%s' can't send this type of message",sn));
return(objcT124=self->msgwrap,(*(id(*)(id,SEL,IMP,SEL,id,id))_imp(objcT124,selTransTbl[67]))(objcT124,selTransTbl[67],i,s,(objcT125=self->msg,(*_imp(objcT125,selTransTbl[68]))(objcT125,selTransTbl[68])),r));
}else{
id objcT126;

# 520 "msgxpr.m"
return(objcT126=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT126,selTransTbl[66]))(objcT126,selTransTbl[66],"selector %s not loaded",sn));
}
}else{
return(id)0;
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _MesgExpr_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _MesgExpr_nstDispatchTbl[] ={
{"canforward",(id (*)())i_MesgExpr_canforward},
{"hash",(id (*)())i_MesgExpr_hash},
{"isEqual:",(id (*)())i_MesgExpr_isEqual_},
{"receiver:",(id (*)())i_MesgExpr_receiver_},
{"msg:",(id (*)())i_MesgExpr_msg_},
{"tmpvar",(id (*)())i_MesgExpr_tmpvar},
{"icache",(id (*)())i_MesgExpr_icache},
{"msg",(id (*)())i_MesgExpr_msg},
{"method:",(id (*)())i_MesgExpr_method_},
{"method",(id (*)())i_MesgExpr_method},
{"indispatchfun:",(id (*)())i_MesgExpr_indispatchfun_},
{"varargs",(id (*)())i_MesgExpr_varargs},
{"selector",(id (*)())i_MesgExpr_selector},
{"typesynth",(id (*)())i_MesgExpr_typesynth},
{"synth",(id (*)())i_MesgExpr_synth},
{"assignrcvr",(id (*)())i_MesgExpr_assignrcvr},
{"assignsuper",(id (*)())i_MesgExpr_assignsuper},
{"genimpcall:",(id (*)())i_MesgExpr_genimpcall_},
{"geninlinecall:",(id (*)())i_MesgExpr_geninlinecall_},
{"gencall:",(id (*)())i_MesgExpr_gencall_},
{"genmsgargs:",(id (*)())i_MesgExpr_genmsgargs_},
{"genmsg:",(id (*)())i_MesgExpr_genmsg_},
{"genmsg",(id (*)())i_MesgExpr_genmsg},
{"gensupermsg",(id (*)())i_MesgExpr_gensupermsg},
{"lineno",(id (*)())i_MesgExpr_lineno},
{"filename",(id (*)())i_MesgExpr_filename},
{"gen",(id (*)())i_MesgExpr_gen},
{"fwdname",(id (*)())i_MesgExpr_fwdname},
{"dispname",(id (*)())i_MesgExpr_dispname},
{"argstructname",(id (*)())i_MesgExpr_argstructname},
{"genargstruct",(id (*)())i_MesgExpr_genargstruct},
{"xgendispfun",(id (*)())i_MesgExpr_xgendispfun},
{"gendispfun",(id (*)())i_MesgExpr_gendispfun},
{"gendispargsintostruct",(id (*)())i_MesgExpr_gendispargsintostruct},
{"genfwdstub",(id (*)())i_MesgExpr_genfwdstub},
{"st80",(id (*)())i_MesgExpr_st80},
{"send:sel:with:to:",(id (*)())i_MesgExpr_send_sel_with_to_},
{"go",(id (*)())i_MesgExpr_go},
{(char*)0,(id (*)())0}
};
id MesgExpr = (id)&_MesgExpr;
id  *OBJCCLASS_MesgExpr(void) { return &MesgExpr; }
struct _SHARED  _MesgExpr = {
  (id)&__MesgExpr,
  (id)&_Expr,
  "MesgExpr",
  0,
  sizeof(struct MesgExpr_PRIVATE),
  38,
  _MesgExpr_nstDispatchTbl,
  41,
  &msgxpr_modDesc,
  0,
  (id)0,
  &MesgExpr,
};
id  OBJCCFUNC_MesgExpr(void) { return (id)&_MesgExpr; }
id  OBJCCSUPER_MesgExpr(void) { return _MesgExpr.clsSuper; }
struct _SHARED __MesgExpr = {
  (id)&__Object,
  (id)&__Expr,
  "MesgExpr",
  0,
  sizeof(struct _SHARED),
  0,
  _MesgExpr_clsDispatchTbl,
  34,
  &msgxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_MesgExpr(void) { return (id)&__MesgExpr; }
id  OBJCMSUPER_MesgExpr(void) { return __MesgExpr.clsSuper; }
static char *_selTransTbl[] ={
"canforward",
"method",
"typehash",
"hash",
"msg",
"typeEqual:",
"gettmpvar",
"sprintf:",
"icachecount",
"notImplemented:",
"lookupmethod:",
"selector",
"str",
"varargs",
"cvtcommalist",
"restype",
"warnforwithmethod",
"ismethdef",
"isidentexpr",
"factory",
"addtmpvar:",
"tmpvar",
"addicache:",
"icache",
"synth",
"type",
"isid",
"adddecref:",
"gen",
"genmetasuper",
"gensuper",
"isselptr",
"fwdoffset:",
"genimpcall:",
"needscast",
"gencast",
"geninlinecall:",
"sgen",
"gendispargs",
"genmsgargs",
"gencall:",
"genmsgargs:",
"assignrcvr",
"genmsg:",
"assignsuper",
"lineno",
"filename",
"gensupermsg",
"genmsg",
"toscores",
"strCopy",
"argstructname",
"genargstruct",
"dispname",
"isvoid",
"xgendispfun",
"gendispargsintostruct",
"genrestype",
"fwdname",
"genparmlist",
"st80",
"subclassResponsibility:",
"go",
"findSel:",
"methodFor:",
"find:",
"error:",
"send:sel:with:to:",
"ksel",
0
};
struct modDescriptor msgxpr_modDesc = {
  "msgxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &MesgExpr,
  69,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_msgxpr(void)
{
  selTransTbl = _selTransTbl;
  return &msgxpr_modDesc;
}
int _OBJCPOSTLINK_msgxpr = 1;


