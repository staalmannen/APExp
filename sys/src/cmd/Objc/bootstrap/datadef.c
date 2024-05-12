# 1 "datadef.m"
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
extern struct modDescriptor  *_OBJCBIND_datadef(void);
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
extern struct modDescriptor datadef_modDesc;

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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 23 "./util.h"
extern FILE*yyin;
extern int yyparse();

FILE*openfile(STR name,STR modfs);
FILE*reopenfile(STR name,STR modfs,FILE*of);

extern int okblock;

id mkcppdirect(char*s);
id mkexprstmt(id expr);
id mklabeledstmt(id label,id stmt);
id mkcasestmt(id keyw,id expr,id stmt);
id mkdefaultstmt(id keyw,id stmt);
id mkifstmt(id keyw,id expr,id stmt);
id mkifelsestmt(id keyw,id expr,id stmt,id ekeyw,id estmt);
id mkswitchstmt(id keyw,id expr,id stmt);
id mkwhilestmt(id keyw,id expr,id stmt);
id mkdostmt(id keyw,id stmt,id wkeyw,id expr);
id mkforstmt(id keyw,id a,id b,id c,id stmt);
id mkgotostmt(id keyw,id label);
id mkcontinuestmt(id keyw);
id mkbreakstmt(id keyw);
id mkreturnstmt(id keyw,id expr);
id mkcastexpr(id a,id b);
id mkcondexpr(id a,id b,id c);
id mkunaryexpr(STR op,id a);
id mksizeof(id a);
id mktypeof(id kw,id a);
id mkaddressof(id a);
id mkdereference(id a);
id mkbinexpr(id a,STR op,id b);
id mkcommaexpr(id a,id b);
id mkrelexpr(id a,STR op,id b);
id mkassignexpr(id a,STR op,id b);
id mkfuncall(id funname,id args);
id mkbuiltincall(id funname,id args);
id mkfunbody(id datadefs,id compound);
void declarefun(id specs,id decl);
void declaremeth(BOOL factory,id decl);
id mkfundef(id specs,id decl,id body);
id mkmethdef(BOOL factory,id decl,id body);
id mkmesgexpr(id receiver,id args);
id mkdecl(id ident);
id mkprecdecl(id tquals,id decl);
id mkarraydecl(id lhs,id ix);
id mkfundecl(id lhs,id args);
id mkprefixdecl(id lhs,id rhs);
id mkpostfixdecl(id lhs,id rhs);
id mkpointer(id specs,id pointer);
id mkbitfielddecl(id decl,id expr);
id mkstardecl(id pointer,id decl);
id mkasmop(id string,id expr);
id mkasmstmt(id keyw,id tqual,id expr,id asmop1,id asmop2,id clobbers);
id mkcompstmt(id lb,id datadefs,id stmtlist,id subblock,id rb);
id mklist(id c,id s);
id mklist2(id c,id s,id t);
id atdefsaddall(id c,id n);
id mkblockexpr(id lb,id parms,id datadefs,id stmts,id expr,id rb);
id mkclassdef(id keyw,id name,id sname,id ivars,id cvars);
id mkdatadef(id datadef,id specs,id decl,id initializer);
id mkencodeexpr(id name);
id mkenumspec(id keyw,id name,id lb,id list,id rb);
id mkenumerator(id name,id value);
id mkgnuattrib(id anyword,id exprlist);
id mkgnuattribdecl(id keyw,id list);
id mklistexpr(id lb,id x,id rb);
id mktypename(id specs,id decl);
id mkcomponentdef(id cdef,id specs,id decl);
id mkstructspec(id keyw,id name,id lb,id defs,id rb);
id mkkeywarg(id sel,id arg);
id mkkeywdecl(id sel,id cast,id arg);
id mkmethproto(id cast,id usel,id ksel,BOOL varargs);
id mkidentexpr(id name);
id mkconstexpr(id name,id schain);
id mkprecexpr(id expr);
id mkbracedgroup(id expr);
id mkarrowexpr(id array,id ix);
id mkdotexpr(id array,id ix);
id mkindexexpr(id array,id ix);
id mkpostfixexpr(id expr,id pf);
id mkparmdef(id parmdef,id specs,id decl);
id mkparmdeflist(id idents,id parmdefs,BOOL varargs);
id mkselarg(id selarg,id usel,int ncols);
id mkselectorexpr(id expr);

void procextdef(id def);
void finclassdef(void);
void datadefokblock(id datadef,id specs,id decl);

id mkfileinmeth(id classdef,id ivarnames,id ivartypes);
id mkfileoutmeth(id classdef,id ivarnames,id ivartypes);

id mkincrefsmeth(id classdef,id ivarnames,id ivartypes);
id mkdecrefsmeth(id classdef,id ivarnames,id ivartypes);
# 22 "./stkframe.h"
extern id topframe;
# 22 "./datadef.h"
struct DataDef_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./datadef.h"
id unit;
id specs;
id decllist;
BOOL istypedef;
BOOL isstatic;
BOOL isinline;
BOOL isextern;
BOOL iskandr;};

# 22 "./datadef.h"
extern id  DataDef;

# 22 "./datadef.h"
extern struct _SHARED _DataDef;
extern struct _SHARED __DataDef;


# 51 "datadef.m"
static id i_DataDef_specs(struct DataDef_PRIVATE *self,SEL _cmd)
{
return self->specs;
}

static id i_DataDef_decllist(struct DataDef_PRIVATE *self,SEL _cmd)
{
return self->decllist;
}

static id i_DataDef_specs_(struct DataDef_PRIVATE *self,SEL _cmd,id aSpec)
{self->
specs=aSpec;
return(id)self;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 67 "datadef.m"
static id i_DataDef_add_(struct DataDef_PRIVATE *self,SEL _cmd,id aDecl)
{
id objcT1;

# 69 "datadef.m"
if( !self->decllist){
id objcT0;
self->
# 70 "datadef.m"
decllist=(objcT0=OrdCltn,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}
(objcT1=self->decllist,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],aDecl));
return(id)self;
}

static id i_DataDef_synthattrs(struct DataDef_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 78 "datadef.m"
int i,n;

for(i=0,n=(objcT2=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));i<n;i++){
id objcT3,objcT4;

# 81 "datadef.m"
id s=(objcT3=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3],i));

if((objcT4=s,(*(BOOL(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]))){
id objcT5,objcT6,objcT7,objcT8;

# 84 "datadef.m"
if((objcT5=s,(*(BOOL(*)(id,SEL))_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5])))self->
istypedef++;
else if((objcT6=s,(*(BOOL(*)(id,SEL))_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6])))self->
isstatic++;
else if((objcT7=s,(*(BOOL(*)(id,SEL))_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7])))self->
isinline++;
else if((objcT8=s,(*(BOOL(*)(id,SEL))_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8])))self->
isextern++;
}
}
return(id)self;
}

static BOOL i_DataDef_isfundef(struct DataDef_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_DataDef_iskandr(struct DataDef_PRIVATE *self,SEL _cmd)
{
return self->iskandr;
}

static id i_DataDef_iskandr_(struct DataDef_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
iskandr=flag;
return(id)self;
}

static BOOL i_DataDef_istypedef(struct DataDef_PRIVATE *self,SEL _cmd)
{
return self->istypedef;
}

static BOOL i_DataDef_isextern(struct DataDef_PRIVATE *self,SEL _cmd)
{
return self->isextern;
}

static BOOL i_DataDef_isstatic(struct DataDef_PRIVATE *self,SEL _cmd)
{
return self->isstatic;
}

static BOOL i_DataDef_isinline(struct DataDef_PRIVATE *self,SEL _cmd)
{
return self->isinline;
}

static BOOL i_DataDef_definesocu(struct DataDef_PRIVATE *self,SEL _cmd)
{

return !self->isstatic&& !self->isextern&& !self->isinline;
}

# 34 "./type.h"
extern id  Type;

# 22 "./globdef.h"
extern id  GlobDef;

# 22 "./initdecl.h"
extern id  InitDecl;

# 139 "datadef.m"
static id i_DataDef_synth(struct DataDef_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10,objcT11;

# 141 "datadef.m"
int i,n;
id gdef=(id)0;self->

unit=trlunit;

if(self->specs)
(objcT9=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9],_cmd));
(objcT10=(id)self,(*_imp(objcT10,selTransTbl[10]))(objcT10,selTransTbl[10]));

for(i=0,n=(objcT11=self->decllist,(*(unsigned(*)(id,SEL))_imp(objcT11,selTransTbl[2]))(objcT11,selTransTbl[2]));i<n;i++){
id objcT12,objcT13;

# 151 "datadef.m"
id var=(objcT12=(objcT13=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT13,selTransTbl[3]))(objcT13,selTransTbl[3],i)),(*_imp(objcT12,selTransTbl[11]))(objcT12,selTransTbl[11]));

if(var){
id objcT14,objcT15,objcT20,objcT21,objcT22;
id objcT23;

# 154 "datadef.m"
id t=(objcT14=Type,(*_imp(objcT14,selTransTbl[0]))(objcT14,selTransTbl[0]));
id d=(objcT15=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT15,selTransTbl[3]))(objcT15,selTransTbl[3],i));

if(self->specs){
id objcT16,objcT17;

# 158 "datadef.m"
(objcT16=t,(*_imp(objcT16,selTransTbl[12]))(objcT16,selTransTbl[12],self->specs));
(objcT17=t,(*_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13],d));
}else{
id objcT18,objcT19;

# 161 "datadef.m"
(objcT18=t,(*_imp(objcT18,selTransTbl[14]))(objcT18,selTransTbl[14],s_int));
(objcT19=t,(*_imp(objcT19,selTransTbl[13]))(objcT19,selTransTbl[13],d));
}
(objcT20=t,(*(id(*)(id,SEL,BOOL))_imp(objcT20,selTransTbl[15]))(objcT20,selTransTbl[15],self->isstatic));
(objcT21=t,(*(id(*)(id,SEL,BOOL))_imp(objcT21,selTransTbl[16]))(objcT21,selTransTbl[16],self->isextern));
if((objcT22=d,(*(BOOL(*)(id,SEL))_imp(objcT22,selTransTbl[17]))(objcT22,selTransTbl[17])))
(objcT23=t,(*(id(*)(id,SEL,BOOL))_imp(objcT23,selTransTbl[18]))(objcT23,selTransTbl[18],(BOOL)1));
if(self->istypedef){
if(curdef){
warn("typedef not allowed inside function or method definition");
}else{
id objcT24;

# 172 "datadef.m"
(objcT24=trlunit,(*_imp(objcT24,selTransTbl[19]))(objcT24,selTransTbl[19],var,t));
}
}else{
id objcT34,objcT39;

# 175 "datadef.m"
if(curdef){
if(curcompound){
id objcT25;

# 177 "datadef.m"
(objcT25=curcompound,(*_imp(objcT25,selTransTbl[20]))(objcT25,selTransTbl[20],var,t));
}else{
id objcT26;

# 179 "datadef.m"
(objcT26=curdef,(*_imp(objcT26,selTransTbl[21]))(objcT26,selTransTbl[21],var,t));
}
}else{
id objcT27,objcT28,objcT31,objcT32;

# 182 "datadef.m"
(objcT27=trlunit,(*_imp(objcT27,selTransTbl[22]))(objcT27,selTransTbl[22],var,t));
if( !(objcT28=d,(*(BOOL(*)(id,SEL))_imp(objcT28,selTransTbl[23]))(objcT28,selTransTbl[23]))&& !self->isextern){
id objcT29,objcT30;

# 184 "datadef.m"
gdef=(objcT29=GlobDef,(*_imp(objcT29,selTransTbl[0]))(objcT29,selTransTbl[0]));
(objcT30=trlunit,(*_imp(objcT30,selTransTbl[24]))(objcT30,selTransTbl[24],var,gdef));
}
if( !o_postlink&&(objcT31=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT31,selTransTbl[25]))(objcT31,selTransTbl[25]))&& !(objcT32=d,(*(BOOL(*)(id,SEL))_imp(objcT32,selTransTbl[23]))(objcT32,selTransTbl[23]))){
id objcT33;

# 188 "datadef.m"
(objcT33=trlunit,(*_imp(objcT33,selTransTbl[26]))(objcT33,selTransTbl[26],var));
}
}


(objcT34=d,(*_imp(objcT34,selTransTbl[27]))(objcT34,selTransTbl[27]));

if(gdef){
id objcT35,objcT36,objcT37,objcT38;

# 196 "datadef.m"
(objcT35=gdef,(*_imp(objcT35,selTransTbl[28]))(objcT35,selTransTbl[28],t));
if((objcT36=d,(*(BOOL(*)(id,SEL))_imp(objcT36,selTransTbl[29]))(objcT36,selTransTbl[29])))(objcT37=gdef,(*_imp(objcT37,selTransTbl[30]))(objcT37,selTransTbl[30],(objcT38=d,(*_imp(objcT38,selTransTbl[31]))(objcT38,selTransTbl[31]))));
}


if(o_refcnt&&(objcT39=t,(*(BOOL(*)(id,SEL))_imp(objcT39,selTransTbl[32]))(objcT39,selTransTbl[32]))){
id objcT40;

# 202 "datadef.m"
if((objcT40=d,(*(BOOL(*)(id,SEL))_imp(objcT40,selTransTbl[29]))(objcT40,selTransTbl[29]))){
id objcT41,objcT42,objcT43;

# 203 "datadef.m"
if( !(objcT41=(objcT42=d,(*_imp(objcT42,selTransTbl[31]))(objcT42,selTransTbl[31])),(*(BOOL(*)(id,SEL))_imp(objcT41,selTransTbl[33]))(objcT41,selTransTbl[33])))(objcT43=d,(*_imp(objcT43,selTransTbl[34]))(objcT43,selTransTbl[34]));
}else{

if( !self->isextern&& !self->isstatic&& !self->iskandr){
id objcT44,objcT45,objcT46,objcT47;

# 207 "datadef.m"
d=(objcT44=(objcT45=(objcT46=InitDecl,(*_imp(objcT46,selTransTbl[0]))(objcT46,selTransTbl[0])),(*_imp(objcT45,selTransTbl[13]))(objcT45,selTransTbl[13],d)),(*_imp(objcT44,selTransTbl[35]))(objcT44,selTransTbl[35]));
(objcT47=self->decllist,(*(id(*)(id,SEL,unsigned,id))_imp(objcT47,selTransTbl[36]))(objcT47,selTransTbl[36],i,d));
}
}
}
}
}else{
fatal("missing name in data definition");
}
}

return(id)self;
}

static id i_DataDef_removevars_initializers_(struct DataDef_PRIVATE *self,SEL _cmd,id set,id cltn)
{
id objcT48,objcT62;

# 223 "datadef.m"
int n=(objcT48=self->decllist,(*(unsigned(*)(id,SEL))_imp(objcT48,selTransTbl[2]))(objcT48,selTransTbl[2]));

while(n--){
id objcT49,objcT50,objcT51,objcT52;

# 226 "datadef.m"
id d,v;
BOOL isheapvar;

d=(objcT49=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT49,selTransTbl[3]))(objcT49,selTransTbl[3],n));
v=(objcT50=d,(*_imp(objcT50,selTransTbl[11]))(objcT50,selTransTbl[11]));
isheapvar=(objcT51=set,(*(BOOL(*)(id,SEL,id))_imp(objcT51,selTransTbl[37]))(objcT51,selTransTbl[37],v));
if((objcT52=d,(*(BOOL(*)(id,SEL))_imp(objcT52,selTransTbl[29]))(objcT52,selTransTbl[29]))){
id objcT53;

# 233 "datadef.m"
if((objcT53=d,(*(BOOL(*)(id,SEL))_imp(objcT53,selTransTbl[17]))(objcT53,selTransTbl[17]))){
id objcT54,objcT55;

# 234 "datadef.m"
if(isheapvar|| !(objcT54=(objcT55=d,(*_imp(objcT55,selTransTbl[31]))(objcT55,selTransTbl[31])),(*(BOOL(*)(id,SEL))_imp(objcT54,selTransTbl[33]))(objcT54,selTransTbl[33]))){
char*m="list initializers not yet allowed in function with Blocks";

fatalat(v,m);
}
}else{
id objcT56,objcT57,objcT58,objcT59,objcT60;

# 240 "datadef.m"
id x=(objcT56=mkidentexpr(v),(*_imp(objcT56,selTransTbl[38]))(objcT56,selTransTbl[38]));

(objcT57=cltn,(*_imp(objcT57,selTransTbl[39]))(objcT57,selTransTbl[39],mkexprstmt(mkassignexpr(x,"=",(objcT58=d,(*_imp(objcT58,selTransTbl[31]))(objcT58,selTransTbl[31]))))));
(objcT59=self->decllist,(*(id(*)(id,SEL,unsigned,id))_imp(objcT59,selTransTbl[36]))(objcT59,selTransTbl[36],n,(objcT60=d,(*_imp(objcT60,selTransTbl[40]))(objcT60,selTransTbl[40]))));
}
}
if(isheapvar){
id objcT61;

# 247 "datadef.m"
(objcT61=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT61,selTransTbl[41]))(objcT61,selTransTbl[41],n));
}
}
if( !(objcT62=self->decllist,(*(unsigned(*)(id,SEL))_imp(objcT62,selTransTbl[2]))(objcT62,selTransTbl[2])))self->
decllist=(id)0;
return(id)self;
}

static id i_DataDef_gen(struct DataDef_PRIVATE *self,SEL _cmd)
{
id objcT63;

# 257 "datadef.m"
if(self->specs)
(objcT63=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT63,selTransTbl[9]))(objcT63,selTransTbl[9],selTransTbl[42]));
if(self->decllist)
gcommalist(self->decllist);
gc(';');
return(id)self;
}

static id i_DataDef_st80(struct DataDef_PRIVATE *self,SEL _cmd)
{
id objcT64;

# 267 "datadef.m"
if(self->decllist)
(objcT64=self->decllist,(*(id(*)(id,SEL,SEL))_imp(objcT64,selTransTbl[9]))(objcT64,selTransTbl[9],_cmd));
return(id)self;
}

static id i_DataDef_st80inits(struct DataDef_PRIVATE *self,SEL _cmd)
{
id objcT65;

# 274 "datadef.m"
if(self->decllist)
(objcT65=self->decllist,(*(id(*)(id,SEL,SEL))_imp(objcT65,selTransTbl[9]))(objcT65,selTransTbl[9],_cmd));
return(id)self;
}

static id i_DataDef_go(struct DataDef_PRIVATE *self,SEL _cmd)
{
id objcT66;

# 281 "datadef.m"
int i,n;

for(i=0,n=(objcT66=self->decllist,(*(unsigned(*)(id,SEL))_imp(objcT66,selTransTbl[2]))(objcT66,selTransTbl[2]));i<n;i++){
id objcT67,objcT68,objcT69;

# 284 "datadef.m"
id d,v;
d=(objcT67=self->decllist,(*(id(*)(id,SEL,unsigned))_imp(objcT67,selTransTbl[3]))(objcT67,selTransTbl[3],i));
v=(objcT68=d,(*_imp(objcT68,selTransTbl[11]))(objcT68,selTransTbl[11]));
if((objcT69=d,(*(BOOL(*)(id,SEL))_imp(objcT69,selTransTbl[29]))(objcT69,selTransTbl[29]))){
id objcT70,objcT71,objcT72;

# 288 "datadef.m"
id e=(objcT70=d,(*_imp(objcT70,selTransTbl[31]))(objcT70,selTransTbl[31]));
(objcT71=topframe,(*_imp(objcT71,selTransTbl[43]))(objcT71,selTransTbl[43],v,(objcT72=e,(*_imp(objcT72,selTransTbl[44]))(objcT72,selTransTbl[44]))));
}
}

return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _DataDef_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _DataDef_nstDispatchTbl[] ={
{"specs",(id (*)())i_DataDef_specs},
{"decllist",(id (*)())i_DataDef_decllist},
{"specs:",(id (*)())i_DataDef_specs_},
{"add:",(id (*)())i_DataDef_add_},
{"synthattrs",(id (*)())i_DataDef_synthattrs},
{"isfundef",(id (*)())i_DataDef_isfundef},
{"iskandr",(id (*)())i_DataDef_iskandr},
{"iskandr:",(id (*)())i_DataDef_iskandr_},
{"istypedef",(id (*)())i_DataDef_istypedef},
{"isextern",(id (*)())i_DataDef_isextern},
{"isstatic",(id (*)())i_DataDef_isstatic},
{"isinline",(id (*)())i_DataDef_isinline},
{"definesocu",(id (*)())i_DataDef_definesocu},
{"synth",(id (*)())i_DataDef_synth},
{"removevars:initializers:",(id (*)())i_DataDef_removevars_initializers_},
{"gen",(id (*)())i_DataDef_gen},
{"st80",(id (*)())i_DataDef_st80},
{"st80inits",(id (*)())i_DataDef_st80inits},
{"go",(id (*)())i_DataDef_go},
{(char*)0,(id (*)())0}
};
id DataDef = (id)&_DataDef;
id  *OBJCCLASS_DataDef(void) { return &DataDef; }
struct _SHARED  _DataDef = {
  (id)&__DataDef,
  (id)&_Node,
  "DataDef",
  0,
  sizeof(struct DataDef_PRIVATE),
  19,
  _DataDef_nstDispatchTbl,
  41,
  &datadef_modDesc,
  0,
  (id)0,
  &DataDef,
};
id  OBJCCFUNC_DataDef(void) { return (id)&_DataDef; }
id  OBJCCSUPER_DataDef(void) { return _DataDef.clsSuper; }
struct _SHARED __DataDef = {
  (id)&__Object,
  (id)&__Node,
  "DataDef",
  0,
  sizeof(struct _SHARED),
  0,
  _DataDef_clsDispatchTbl,
  34,
  &datadef_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_DataDef(void) { return (id)&__DataDef; }
id  OBJCMSUPER_DataDef(void) { return __DataDef.clsSuper; }
static char *_selTransTbl[] ={
"new",
"add:",
"size",
"at:",
"isstorageclass",
"istypedef",
"isstatic",
"isinline",
"isextern",
"elementsPerform:",
"synthattrs",
"identifier",
"specs:",
"decl:",
"addspec:",
"isstatic:",
"isextern:",
"islistinit",
"haslistinit:",
"def:astype:",
"deflocal:astype:",
"defparm:astype:",
"defdata:astype:",
"isfunproto",
"def:as:",
"definesocu",
"definesentry:",
"synthinits",
"type:",
"isinit",
"initializer:",
"initializer",
"isid",
"isconstexpr",
"incref",
"initnil",
"at:put:",
"contains:",
"synth",
"addFirst:",
"decl",
"removeAt:",
"gen",
"defval:as:",
"go",
0
};
struct modDescriptor datadef_modDesc = {
  "datadef",
  "objc3.3.19",
  0L,
  0,
  0,
  &DataDef,
  45,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_datadef(void)
{
  selTransTbl = _selTransTbl;
  return &datadef_modDesc;
}
int _OBJCPOSTLINK_datadef = 1;


