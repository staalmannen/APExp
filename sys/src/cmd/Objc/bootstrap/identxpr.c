# 1 "identxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_identxpr(void);
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
extern struct modDescriptor identxpr_modDesc;

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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./def.h"
extern id curdef;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
# 22 "./stkframe.h"
extern id topframe;
# 22 "./identxpr.h"
struct IdentifierExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./identxpr.h"
id identifier;
BOOL ivar;
BOOL cvar;
BOOL isself;
BOOL lhsself;
BOOL isclassref;
BOOL infactory;
BOOL isglobal;
BOOL isstkvar;
id heapvarblock;
id maybeheapvarblock;
id classdef;};

# 22 "./identxpr.h"
extern id  IdentifierExpr;

# 22 "./identxpr.h"
extern struct _SHARED _IdentifierExpr;
extern struct _SHARED __IdentifierExpr;


# 51 "identxpr.m"
static id c_IdentifierExpr_resolve_(struct IdentifierExpr_PRIVATE *self,SEL _cmd,id sym)
{
id objcT0;

# 53 "identxpr.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],_cmd));
}

# 59 "./symbol.h"
extern id  Symbol;

# 56 "identxpr.m"
static id c_IdentifierExpr_str_(struct IdentifierExpr_PRIVATE *self,SEL _cmd,STR s)
{
id objcT1,objcT2,objcT3;

# 58 "identxpr.m"
return(objcT1=(objcT2=__IdentifierExpr.clsSuper,(*_impSuper(objcT2,selTransTbl[1]))((id)self,selTransTbl[1])),(*_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],(objcT3=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3],s))));
}

static STR i_IdentifierExpr_str(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 63 "identxpr.m"
return(objcT4=self->identifier,(*(STR(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
}

static int i_IdentifierExpr_lineno(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT5;

# 68 "identxpr.m"
return(objcT5=self->identifier,(*(int(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]));
}

static id i_IdentifierExpr_filename(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 73 "identxpr.m"
return(objcT6=self->identifier,(*_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]));
}

static id i_IdentifierExpr_identifier(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
return self->identifier;
}

static id i_IdentifierExpr_identifier_(struct IdentifierExpr_PRIVATE *self,SEL _cmd,id aNode)
{self->
identifier=aNode;
return(id)self;
}

static id i_IdentifierExpr_lhsself_(struct IdentifierExpr_PRIVATE *self,SEL _cmd,BOOL x)
{self->
lhsself=x;
return(id)self;
}

static id i_IdentifierExpr_check_type_in_inblock_(struct IdentifierExpr_PRIVATE *self,SEL _cmd,id x,id t,id compound,BOOL insideblock)
{
id objcT7;

# 95 "identxpr.m"
if((objcT7=compound,(*(BOOL(*)(id,SEL,id))_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7],x))){
id objcT8,objcT9;
self->
# 96 "identxpr.m"
heapvarblock=compound;
(objcT8=curdef,(*_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8],compound));
(objcT9=curcompound,(*_imp(objcT9,selTransTbl[8]))(objcT9,selTransTbl[8],compound));
}else{
if(insideblock){
id objcT10,objcT11,objcT12;
self->
# 101 "identxpr.m"
heapvarblock=compound;
(objcT10=compound,(*_imp(objcT10,selTransTbl[9]))(objcT10,selTransTbl[9],x,t));
(objcT11=curdef,(*_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8],compound));
(objcT12=curcompound,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8],compound));
}else{self->
maybeheapvarblock=compound;
}
}
return(id)self;
}



static BOOL i_IdentifierExpr_inblock(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 116 "identxpr.m"
id c;

for(c=curcompound;c;c=(objcT13=c,(*_imp(objcT13,selTransTbl[10]))(objcT13,selTransTbl[10]))){
id objcT14;

# 119 "identxpr.m"
if((objcT14=c,(*(BOOL(*)(id,SEL))_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11])))
return(BOOL)1;
}
return(BOOL)0;
}

static id i_IdentifierExpr_checkselfheapvar(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT15,objcT16,objcT17,objcT18;

# 127 "identxpr.m"
id c,t_self;

c=(objcT15=curdef,(*_imp(objcT15,selTransTbl[12]))(objcT15,selTransTbl[12]));self->
classdef=curclassdef;
t_self=(objcT16=self->classdef,(*_imp(objcT16,selTransTbl[13]))(objcT16,selTransTbl[13]));
return(objcT17=(id)self,(*(id(*)(id,SEL,id,id,id,BOOL))_imp(objcT17,selTransTbl[14]))(objcT17,selTransTbl[14],s_self,t_self,c,(objcT18=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT18,selTransTbl[15]))(objcT18,selTransTbl[15]))));
}

static id i_IdentifierExpr_typesynth(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT19;

# 137 "identxpr.m"
if( !self->type)
(objcT19=(id)self,(*_imp(objcT19,selTransTbl[16]))(objcT19,selTransTbl[16]));
return(id)self;
}

static id i_IdentifierExpr_synth(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT20,objcT45,objcT48,objcT52;

# 144 "identxpr.m"
id c;
BOOL usingblocks=(o_blocks&&(objcT20=trlunit,(*(BOOL(*)(id,SEL))_imp(objcT20,selTransTbl[17]))(objcT20,selTransTbl[17])));
# 149 "identxpr.m"
if(1){
id objcT21,objcT29;

# 150 "identxpr.m"
int insideblock=0;

for(c=curcompound;c;c=(objcT21=c,(*_imp(objcT21,selTransTbl[10]))(objcT21,selTransTbl[10]))){
id objcT22;

# 153 "identxpr.m"
if((self->type=(objcT22=c,(*_imp(objcT22,selTransTbl[18]))(objcT22,selTransTbl[18],self->identifier)))){
id objcT23;
if( !o_postlink&&(objcT23=self->type,(*(BOOL(*)(id,SEL))_imp(objcT23,selTransTbl[19]))(objcT23,selTransTbl[19]))){
id objcT24;

# 156 "identxpr.m"
(objcT24=trlunit,(*_imp(objcT24,selTransTbl[20]))(objcT24,selTransTbl[20],self->identifier));
}else{self->
isstkvar++;
}
if(usingblocks){
id objcT25;

# 161 "identxpr.m"
(objcT25=(id)self,(*(id(*)(id,SEL,id,id,id,BOOL))_imp(objcT25,selTransTbl[14]))(objcT25,selTransTbl[14],self->identifier,self->type,c,insideblock));
}
return(id)self;
}
if(usingblocks){
id objcT26,objcT27;

# 166 "identxpr.m"
BOOL isblock=(objcT26=c,(*(BOOL(*)(id,SEL))_imp(objcT26,selTransTbl[11]))(objcT26,selTransTbl[11]));

if(isblock&&(self->type=(objcT27=c,(*_imp(objcT27,selTransTbl[21]))(objcT27,selTransTbl[21],self->identifier)))){
id objcT28;
self->
# 169 "identxpr.m"
isstkvar++;
(objcT28=(id)self,(*(id(*)(id,SEL,id,id,id,BOOL))_imp(objcT28,selTransTbl[14]))(objcT28,selTransTbl[14],self->identifier,self->type,c,insideblock));
return(id)self;
}
if(isblock)
insideblock++;
}
}

if(curdef&&(self->type=(objcT29=curdef,(*_imp(objcT29,selTransTbl[21]))(objcT29,selTransTbl[21],self->identifier)))){
id objcT30,objcT31,objcT32,objcT33;

# 179 "identxpr.m"
id c=(objcT30=curdef,(*_imp(objcT30,selTransTbl[12]))(objcT30,selTransTbl[12]));self->
isstkvar++;
(objcT31=(id)self,(*(id(*)(id,SEL,id,id,id,BOOL))_imp(objcT31,selTransTbl[14]))(objcT31,selTransTbl[14],self->identifier,self->type,c,insideblock));self->
isself=((objcT32=self->identifier,(*(BOOL(*)(id,SEL,id))_imp(objcT32,selTransTbl[22]))(objcT32,selTransTbl[22],s_self))&&(objcT33=curdef,(*(BOOL(*)(id,SEL))_imp(objcT33,selTransTbl[23]))(objcT33,selTransTbl[23])));
return(id)self;
}
}


if(curclassdef){
id objcT34,objcT35,objcT40;

# 189 "identxpr.m"
BOOL ism=(curdef!=(id)0&&(objcT34=curdef,(*(BOOL(*)(id,SEL))_imp(objcT34,selTransTbl[23]))(objcT34,selTransTbl[23])));
char*msg="%s variable '%s' used outside method implementation";

if((objcT35=curclassdef,(*(BOOL(*)(id,SEL,id))_imp(objcT35,selTransTbl[24]))(objcT35,selTransTbl[24],self->identifier))){
if(ism){
id objcT36,objcT37,objcT38;
self->
# 194 "identxpr.m"
ivar++;self->
classdef=curclassdef;self->
infactory=(objcT36=curdef,(*(BOOL(*)(id,SEL))_imp(objcT36,selTransTbl[25]))(objcT36,selTransTbl[25]));self->
type=(objcT37=curclassdef,(*_imp(objcT37,selTransTbl[26]))(objcT37,selTransTbl[26],self->identifier));
if(usingblocks)
(objcT38=(id)self,(*_imp(objcT38,selTransTbl[27]))(objcT38,selTransTbl[27]));
return(id)self;
}else{
id objcT39;

# 202 "identxpr.m"
warnat(self->identifier,msg,"instance",(objcT39=self->identifier,(*(STR(*)(id,SEL))_imp(objcT39,selTransTbl[4]))(objcT39,selTransTbl[4])));
}
}
if((objcT40=curclassdef,(*(BOOL(*)(id,SEL,id))_imp(objcT40,selTransTbl[28]))(objcT40,selTransTbl[28],self->identifier))){
if(ism){
id objcT41,objcT42,objcT43;
self->
# 207 "identxpr.m"
cvar++;self->
classdef=curclassdef;self->
infactory=(objcT41=curdef,(*(BOOL(*)(id,SEL))_imp(objcT41,selTransTbl[25]))(objcT41,selTransTbl[25]));self->
type=(objcT42=curclassdef,(*_imp(objcT42,selTransTbl[29]))(objcT42,selTransTbl[29],self->identifier));
if(usingblocks)
(objcT43=(id)self,(*_imp(objcT43,selTransTbl[27]))(objcT43,selTransTbl[27]));
return(id)self;
}else{
id objcT44;

# 215 "identxpr.m"
warnat(self->identifier,msg,"class",(objcT44=self->identifier,(*(STR(*)(id,SEL))_imp(objcT44,selTransTbl[4]))(objcT44,selTransTbl[4])));
}
}
}


if((self->type=(objcT45=trlunit,(*_imp(objcT45,selTransTbl[30]))(objcT45,selTransTbl[30],self->identifier)))){
id objcT46,objcT47;
self->
# 222 "identxpr.m"
isglobal++;
if( !o_postlink&&(objcT46=self->type,(*(BOOL(*)(id,SEL))_imp(objcT46,selTransTbl[31]))(objcT46,selTransTbl[31])))
(objcT47=trlunit,(*_imp(objcT47,selTransTbl[20]))(objcT47,selTransTbl[20],self->identifier));
return(id)self;
}


if((c=(objcT48=trlunit,(*_imp(objcT48,selTransTbl[32]))(objcT48,selTransTbl[32],self->identifier)))){
id objcT51;
self->
# 230 "identxpr.m"
type=t_id;
if(curdef){
id objcT49;

# 232 "identxpr.m"
(objcT49=curdef,(*_imp(objcT49,selTransTbl[33]))(objcT49,selTransTbl[33],c));
}else{
id objcT50;

# 234 "identxpr.m"
char*msg="classname '%s' used outside method or function implementation";

warnat(self->identifier,msg,(objcT50=self->identifier,(*(STR(*)(id,SEL))_imp(objcT50,selTransTbl[4]))(objcT50,selTransTbl[4])));
}
if( !o_postlink)
(objcT51=trlunit,(*_imp(objcT51,selTransTbl[20]))(objcT51,selTransTbl[20],self->identifier));self->
isclassref++;self->
classdef=c;
return(id)self;
}
if((objcT52=trlunit,(*_imp(objcT52,selTransTbl[34]))(objcT52,selTransTbl[34],self->identifier))){self->
type=t_int;
return(id)self;
}
if(o_warnintvar){
id objcT53;

# 249 "identxpr.m"
warnat(self->identifier,"definition of '%s' defaults to 'int'",(objcT53=self->identifier,(*(STR(*)(id,SEL))_imp(objcT53,selTransTbl[4]))(objcT53,selTransTbl[4])));
}self->
isglobal++;self->
type=t_int;
return(id)self;
}

# 259 "identxpr.m"
static id i_IdentifierExpr_checkagain(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT54;

# 261 "identxpr.m"
id x=(self->ivar||self->cvar)?s_self:self->identifier;

if((objcT54=self->maybeheapvarblock,(*(BOOL(*)(id,SEL,id))_imp(objcT54,selTransTbl[7]))(objcT54,selTransTbl[7],x))){self->
heapvarblock=self->maybeheapvarblock;self->
maybeheapvarblock=(id)0;
}else{self->
maybeheapvarblock=(id)0;
}
return(id)self;
}

static id i_IdentifierExpr_gen(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT55;

# 274 "identxpr.m"
if(self->maybeheapvarblock)
(objcT55=(id)self,(*_imp(objcT55,selTransTbl[35]))(objcT55,selTransTbl[35]));

if(self->isself&& !self->lhsself)
gs("(id)");

if(self->heapvarblock){
id objcT56;

# 281 "identxpr.m"
gs((objcT56=self->heapvarblock,(*(char*(*)(id,SEL))_imp(objcT56,selTransTbl[36]))(objcT56,selTransTbl[36])));
gs("->");
}
if(self->ivar){
gs("self->");
if(o_otb)
gs("ptr->");
}
if(self->cvar){
id objcT57;

# 290 "identxpr.m"
gf("((struct %s *)",(objcT57=self->classdef,(*(char*(*)(id,SEL))_imp(objcT57,selTransTbl[37]))(objcT57,selTransTbl[37])));
if(self->infactory){
gs("self)->");
}else{
gs("self->isa)->");
}
if(o_otb)
gs("ptr->");
}
if(self->isclassref){
id objcT58;

# 300 "identxpr.m"
(objcT58=self->classdef,(*_imp(objcT58,selTransTbl[38]))(objcT58,selTransTbl[38]));
}else{
id objcT59;

# 302 "identxpr.m"
(objcT59=self->identifier,(*_imp(objcT59,selTransTbl[39]))(objcT59,selTransTbl[39]));
}
return(id)self;
}

static id i_IdentifierExpr_st80(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT60;

# 309 "identxpr.m"
(objcT60=self->identifier,(*_imp(objcT60,selTransTbl[40]))(objcT60,selTransTbl[40]));
return(id)self;
}

static BOOL i_IdentifierExpr_isidentexpr(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_IdentifierExpr_go(struct IdentifierExpr_PRIVATE *self,SEL _cmd)
{
id objcT69,objcT70,objcT71;

# 320 "identxpr.m"
id v;
id c;
# 325 "identxpr.m"
if(self->isglobal){
id objcT61,objcT62;

# 326 "identxpr.m"
return(objcT61=(objcT62=loadedmodules,(*_imp(objcT62,selTransTbl[41]))(objcT62,selTransTbl[41],self->identifier)),(*_imp(objcT61,selTransTbl[42]))(objcT61,selTransTbl[42]));
}
# 331 "identxpr.m"
if(self->isstkvar){
id objcT63;

# 332 "identxpr.m"
return(objcT63=topframe,(*_imp(objcT63,selTransTbl[43]))(objcT63,selTransTbl[43],self->identifier));
}
# 337 "identxpr.m"
if(self->isclassref){
id objcT64,objcT65,objcT66;

# 338 "identxpr.m"
id c;
char*name=(objcT64=self->classdef,(*(char*(*)(id,SEL))_imp(objcT64,selTransTbl[44]))(objcT64,selTransTbl[44]));
(void)0;
c=(objcT65=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT65,selTransTbl[45]))(objcT65,selTransTbl[45],name));
if( !c)(objcT66=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT66,selTransTbl[46]))(objcT66,selTransTbl[46],"class '%s' not loaded",name));
return c;
}
# 348 "identxpr.m"
if(self->ivar){
id objcT67,objcT68;

# 349 "identxpr.m"
return(objcT67=self->classdef,(*(id(*)(id,SEL,id,BOOL,id))_imp(objcT67,selTransTbl[47]))(objcT67,selTransTbl[47],(objcT68=topframe,(*_imp(objcT68,selTransTbl[48]))(objcT68,selTransTbl[48])),self->infactory,self->identifier));
}
if(self->cvar)return(objcT69=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT69,selTransTbl[0]))(objcT69,selTransTbl[0],_cmd));

return(objcT70=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT70,selTransTbl[46]))(objcT70,selTransTbl[46],"cant find variable '%s'",(objcT71=self->identifier,(*(STR(*)(id,SEL))_imp(objcT71,selTransTbl[4]))(objcT71,selTransTbl[4]))));
}

static id i_IdentifierExpr_assignvar_(struct IdentifierExpr_PRIVATE *self,SEL _cmd,id v)
{
id objcT74;

# 358 "identxpr.m"
id c;
# 362 "identxpr.m"
if(self->isglobal){
id objcT72,objcT73;

# 363 "identxpr.m"
id g=(objcT72=loadedmodules,(*_imp(objcT72,selTransTbl[41]))(objcT72,selTransTbl[41],self->identifier));
(objcT73=g,(*_imp(objcT73,selTransTbl[49]))(objcT73,selTransTbl[49],v));
return v;
}


for(c=topframe;c;c=(objcT74=c,(*_imp(objcT74,selTransTbl[10]))(objcT74,selTransTbl[10]))){
id objcT75;

# 370 "identxpr.m"
if((self->type=(objcT75=c,(*_imp(objcT75,selTransTbl[18]))(objcT75,selTransTbl[18],self->identifier)))){
id objcT76,objcT77,objcT78,objcT79;
if((objcT76=self->type,(*(BOOL(*)(id,SEL))_imp(objcT76,selTransTbl[19]))(objcT76,selTransTbl[19]))||(objcT77=self->type,(*(BOOL(*)(id,SEL))_imp(objcT77,selTransTbl[50]))(objcT77,selTransTbl[50])))
(objcT78=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT78,selTransTbl[0]))(objcT78,selTransTbl[0],_cmd));

(objcT79=c,(*_imp(objcT79,selTransTbl[51]))(objcT79,selTransTbl[51],self->identifier,v));
return v;
}
}

if(self->ivar){
id objcT80,objcT81;

# 381 "identxpr.m"
return(objcT80=self->classdef,(*(id(*)(id,SEL,id,BOOL,id,id))_imp(objcT80,selTransTbl[52]))(objcT80,selTransTbl[52],(objcT81=topframe,(*_imp(objcT81,selTransTbl[48]))(objcT81,selTransTbl[48])),self->infactory,self->identifier,v));
}
if(self->cvar){
id objcT82;

# 384 "identxpr.m"
return(objcT82=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT82,selTransTbl[0]))(objcT82,selTransTbl[0],_cmd));
}


return v;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _IdentifierExpr_clsDispatchTbl[] ={
{"resolve:",(id (*)())c_IdentifierExpr_resolve_},
{"str:",(id (*)())c_IdentifierExpr_str_},
{(char*)0,(id (*)())0}
};
static struct _SLT _IdentifierExpr_nstDispatchTbl[] ={
{"str",(id (*)())i_IdentifierExpr_str},
{"lineno",(id (*)())i_IdentifierExpr_lineno},
{"filename",(id (*)())i_IdentifierExpr_filename},
{"identifier",(id (*)())i_IdentifierExpr_identifier},
{"identifier:",(id (*)())i_IdentifierExpr_identifier_},
{"lhsself:",(id (*)())i_IdentifierExpr_lhsself_},
{"check:type:in:inblock:",(id (*)())i_IdentifierExpr_check_type_in_inblock_},
{"inblock",(id (*)())i_IdentifierExpr_inblock},
{"checkselfheapvar",(id (*)())i_IdentifierExpr_checkselfheapvar},
{"typesynth",(id (*)())i_IdentifierExpr_typesynth},
{"synth",(id (*)())i_IdentifierExpr_synth},
{"checkagain",(id (*)())i_IdentifierExpr_checkagain},
{"gen",(id (*)())i_IdentifierExpr_gen},
{"st80",(id (*)())i_IdentifierExpr_st80},
{"isidentexpr",(id (*)())i_IdentifierExpr_isidentexpr},
{"go",(id (*)())i_IdentifierExpr_go},
{"assignvar:",(id (*)())i_IdentifierExpr_assignvar_},
{(char*)0,(id (*)())0}
};
id IdentifierExpr = (id)&_IdentifierExpr;
id  *OBJCCLASS_IdentifierExpr(void) { return &IdentifierExpr; }
struct _SHARED  _IdentifierExpr = {
  (id)&__IdentifierExpr,
  (id)&_Expr,
  "IdentifierExpr",
  0,
  sizeof(struct IdentifierExpr_PRIVATE),
  17,
  _IdentifierExpr_nstDispatchTbl,
  41,
  &identxpr_modDesc,
  0,
  (id)0,
  &IdentifierExpr,
};
id  OBJCCFUNC_IdentifierExpr(void) { return (id)&_IdentifierExpr; }
id  OBJCCSUPER_IdentifierExpr(void) { return _IdentifierExpr.clsSuper; }
struct _SHARED __IdentifierExpr = {
  (id)&__Object,
  (id)&__Expr,
  "IdentifierExpr",
  0,
  sizeof(struct _SHARED),
  2,
  _IdentifierExpr_clsDispatchTbl,
  34,
  &identxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_IdentifierExpr(void) { return (id)&__IdentifierExpr; }
id  OBJCMSUPER_IdentifierExpr(void) { return __IdentifierExpr.clsSuper; }
static char *_selTransTbl[] ={
"notImplemented:",
"new",
"identifier:",
"str:",
"str",
"lineno",
"filename",
"isheapvar:",
"addheapvarblock:",
"defheapvar:type:",
"enclosing",
"isblockexpr",
"compound",
"selftype",
"check:type:in:inblock:",
"inblock",
"synth",
"usingblocks",
"lookuplocal:",
"isextern",
"usesentry:",
"lookupparm:",
"isEqual:",
"ismethdef",
"isivar:",
"factory",
"lookupivar:",
"checkselfheapvar",
"iscvar:",
"lookupcvar:",
"lookupglobal:",
"definesocu",
"lookupclass:",
"addclassreference:",
"lookupenumtor:",
"checkagain",
"heapvarptrname",
"shartypename",
"genclassref",
"gen",
"st80",
"resolve:",
"value",
"lookupval:",
"classname",
"findClass:",
"error:",
"getivarval:::",
"lookupself",
"defval:",
"isstatic",
"defval:as:",
"setivarval::::",
0
};
struct modDescriptor identxpr_modDesc = {
  "identxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &IdentifierExpr,
  53,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_identxpr(void)
{
  selTransTbl = _selTransTbl;
  return &identxpr_modDesc;
}
int _OBJCPOSTLINK_identxpr = 1;


