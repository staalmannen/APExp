# 1 "blockxpr.m"
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
extern struct modDescriptor  *_OBJCBIND_blockxpr(void);
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
extern struct modDescriptor blockxpr_modDesc;

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
# 28 "./../../include/objpak/set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./blockxpr.h"
extern id curcompound;
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
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
# 22 "./def.h"
extern id curdef;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
# 22 "./trlunit.h"
extern id trlunit;
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
# 24 "./blockxpr.h"
struct BlockExpr_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 26 "./blockxpr.h"
id lbrace,rbrace;
id parms,datadefs,stmts,expr;
id initializers;
id parmnames,parmtypes;
id enclosing;
id enclosingdef;
id tmpvars;
id icaches;
id locals;
id localdic;
id alllocals;
id heapvars,heapnames,heaptypes;
id heapparms;
char*heapvarptrname;
char*heapvartypename;
id localexprs;
int numparms;
int numheapvarblocks;
id heapvarblocks;
int blockcount;
char*blkconsname;
char*blkdtorname;
char*blkfunname;
char*blkdataname;
char*blktypename;
id restype;
id returnlabel;
id refvar;
id increfs,decrefs;};

# 24 "./blockxpr.h"
extern id  BlockExpr;

# 24 "./blockxpr.h"
extern struct _SHARED _BlockExpr;
extern struct _SHARED __BlockExpr;


# 56 "blockxpr.m"
static id i_BlockExpr_usereturnflag(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_BlockExpr_blockcount_(struct BlockExpr_PRIVATE *self,SEL _cmd,int x)
{self->
blockcount=x;
return(id)self;
}

static id c_BlockExpr_new(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2,objcT3;

# 69 "blockxpr.m"
(objcT0=trlunit,(*(id(*)(id,SEL,BOOL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(BOOL)1));
return(objcT1=(objcT2=__BlockExpr.clsSuper,(*_impSuper(objcT2,selTransTbl[1]))((id)self,selTransTbl[1])),(*(id(*)(id,SEL,int))_imp(objcT1,selTransTbl[2]))(objcT1,selTransTbl[2],(objcT3=trlunit,(*(int(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]))));
}

static BOOL i_BlockExpr_isblockexpr(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static id i_BlockExpr_lbrace_(struct BlockExpr_PRIVATE *self,SEL _cmd,id lb)
{self->
lbrace=lb;
return(id)self;
}

static id i_BlockExpr_rbrace_(struct BlockExpr_PRIVATE *self,SEL _cmd,id rb)
{self->
rbrace=rb;
return(id)self;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 90 "blockxpr.m"
static id i_BlockExpr_defparm_astype_(struct BlockExpr_PRIVATE *self,SEL _cmd,id sym,id t)
{
id objcT5;

# 92 "blockxpr.m"
if( !self->parmnames){
id objcT4;
self->
# 93 "blockxpr.m"
parmnames=(objcT4=OrdCltn,(*_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1]));
}
(objcT5=self->parmnames,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4],sym));
(void)0;
return(id)self;
}

# 22 "./keywdecl.h"
extern id  KeywDecl;

# 100 "blockxpr.m"
static id i_BlockExpr_parms_(struct BlockExpr_PRIVATE *self,SEL _cmd,id aList)
{
id objcT6,objcT7;
int i,n;self->

parms=(objcT6=OrdCltn,(*_imp(objcT6,selTransTbl[1]))(objcT6,selTransTbl[1]));
for(i=0,n=(objcT7=aList,(*(unsigned(*)(id,SEL))_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5]));i<n;i++){
id objcT8,objcT9,objcT10,objcT11;

# 107 "blockxpr.m"
(objcT8=self->parms,(*_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4],(objcT9=(objcT10=KeywDecl,(*_imp(objcT10,selTransTbl[1]))(objcT10,selTransTbl[1])),(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6],(objcT11=aList,(*(id(*)(id,SEL,unsigned))_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7],i))))));
}self->
parmnames=aList;
# 113 "blockxpr.m"
return(id)self;
}

static id i_BlockExpr_datadefs_(struct BlockExpr_PRIVATE *self,SEL _cmd,id aList)
{self->
datadefs=aList;
return(id)self;
}

static id i_BlockExpr_stmts_(struct BlockExpr_PRIVATE *self,SEL _cmd,id aList)
{self->
stmts=aList;
return(id)self;
}

static id i_BlockExpr_expr_(struct BlockExpr_PRIVATE *self,SEL _cmd,id anExpr)
{self->
expr=anExpr;
return(id)self;
}

static id i_BlockExpr_lookupparm_(struct BlockExpr_PRIVATE *self,SEL _cmd,id sym)
{
id objcT12;

# 136 "blockxpr.m"
if(self->parmnames&&(objcT12=self->parmnames,(*_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8],sym)))
return t_id;
return(id)0;
}

static id i_BlockExpr_nextreturnlabel(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 143 "blockxpr.m"
return(objcT13=(id)self,(*_imp(objcT13,selTransTbl[9]))(objcT13,selTransTbl[9]));
}

static id i_BlockExpr_returnlabel(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT14;

# 148 "blockxpr.m"
(void)0;self->
returnlabel=(objcT14=trlunit,(*_imp(objcT14,selTransTbl[9]))(objcT14,selTransTbl[9]));
return self->returnlabel;
}

static int i_BlockExpr_lineno(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT15;

# 155 "blockxpr.m"
return(objcT15=self->lbrace,(*(int(*)(id,SEL))_imp(objcT15,selTransTbl[10]))(objcT15,selTransTbl[10]));
}

static id i_BlockExpr_filename(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT16;

# 160 "blockxpr.m"
return(objcT16=self->lbrace,(*_imp(objcT16,selTransTbl[11]))(objcT16,selTransTbl[11]));
}

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 163 "blockxpr.m"
static id i_BlockExpr_synth(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19,objcT20,objcT21,objcT22;
id objcT23,objcT24,objcT25,objcT26,objcT27;
id objcT28,objcT29,objcT30,objcT31,objcT32;
id objcT33;

# 165 "blockxpr.m"
if( !o_blocks){
fatalat(self->lbrace,"blocks not allowed with -noBlocks");
return(id)self;
}
if(curdef){
id objcT17;

# 170 "blockxpr.m"
(objcT17=curdef,(*_imp(objcT17,selTransTbl[12]))(objcT17,selTransTbl[12],(id)self));
}else{
fatalat(self->lbrace,"block expression outside method or function definition");
}self->
enclosing=curcompound;
curcompound=(id)self;
# 183 "blockxpr.m"
if(self->datadefs)
(objcT18=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT18,selTransTbl[13]))(objcT18,selTransTbl[13],_cmd));
if(self->stmts)
(objcT19=self->stmts,(*(id(*)(id,SEL,SEL))_imp(objcT19,selTransTbl[13]))(objcT19,selTransTbl[13],_cmd));
if(self->expr)
(objcT20=self->expr,(*_imp(objcT20,selTransTbl[14]))(objcT20,selTransTbl[14]));self->
numparms=(self->parms)?(objcT21=self->parms,(*(unsigned(*)(id,SEL))_imp(objcT21,selTransTbl[5]))(objcT21,selTransTbl[5])):0;self->
blkconsname=(objcT22=(objcT23=String,(*(id(*)(id,SEL,STR,...))_imp(objcT23,selTransTbl[15]))(objcT23,selTransTbl[15],"newblk%i",self->blockcount)),(*(STR(*)(id,SEL))_imp(objcT22,selTransTbl[16]))(objcT22,selTransTbl[16]));self->
blkdtorname=(objcT24=(objcT25=String,(*(id(*)(id,SEL,STR,...))_imp(objcT25,selTransTbl[15]))(objcT25,selTransTbl[15],"clearblk%i",self->blockcount)),(*(STR(*)(id,SEL))_imp(objcT24,selTransTbl[16]))(objcT24,selTransTbl[16]));self->
blkfunname=(objcT26=(objcT27=String,(*(id(*)(id,SEL,STR,...))_imp(objcT27,selTransTbl[15]))(objcT27,selTransTbl[15],"blkfun%i",self->blockcount)),(*(STR(*)(id,SEL))_imp(objcT26,selTransTbl[16]))(objcT26,selTransTbl[16]));self->
blkdataname=(objcT28=(objcT29=String,(*(id(*)(id,SEL,STR,...))_imp(objcT29,selTransTbl[15]))(objcT29,selTransTbl[15],"blkdata%i",self->blockcount)),(*(STR(*)(id,SEL))_imp(objcT28,selTransTbl[16]))(objcT28,selTransTbl[16]));self->
blktypename=(objcT30=(objcT31=String,(*(id(*)(id,SEL,STR,...))_imp(objcT31,selTransTbl[15]))(objcT31,selTransTbl[15],"struct blktype%i",self->blockcount)),(*(STR(*)(id,SEL))_imp(objcT30,selTransTbl[16]))(objcT30,selTransTbl[16]));self->
restype=(self->expr)?(objcT32=self->expr,(*_imp(objcT32,selTransTbl[17]))(objcT32,selTransTbl[17])):t_id;
if(self->heapvars)
(objcT33=(id)self,(*_imp(objcT33,selTransTbl[18]))(objcT33,selTransTbl[18]));
curcompound=self->enclosing;

if(o_refcnt){
id objcT34,objcT35,objcT36,objcT37,objcT43;

# 201 "blockxpr.m"
int i,n;self->

refvar=(objcT34=trlunit,(*_imp(objcT34,selTransTbl[19]))(objcT34,selTransTbl[19]));
(objcT35=curcompound,(*_imp(objcT35,selTransTbl[20]))(objcT35,selTransTbl[20],self->refvar));
(objcT36=curcompound,(*_imp(objcT36,selTransTbl[21]))(objcT36,selTransTbl[21],self->refvar));
for(i=0,n=(objcT37=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT37,selTransTbl[5]))(objcT37,selTransTbl[5]));i<n;i++){
id objcT38,objcT39,objcT40;

# 207 "blockxpr.m"
id x=(objcT38=self->parmnames,(*(id(*)(id,SEL,unsigned))_imp(objcT38,selTransTbl[7]))(objcT38,selTransTbl[7],i));

if((objcT39=(objcT40=(id)self,(*_imp(objcT40,selTransTbl[22]))(objcT40,selTransTbl[22],x)),(*(BOOL(*)(id,SEL))_imp(objcT39,selTransTbl[23]))(objcT39,selTransTbl[23]))){
id objcT41,objcT42;

# 210 "blockxpr.m"
(objcT41=(id)self,(*_imp(objcT41,selTransTbl[24]))(objcT41,selTransTbl[24],x));
(objcT42=(id)self,(*_imp(objcT42,selTransTbl[21]))(objcT42,selTransTbl[21],x));
}
}
for(i=0,n=(objcT43=self->locals,(*(unsigned(*)(id,SEL))_imp(objcT43,selTransTbl[5]))(objcT43,selTransTbl[5]));i<n;i++){
id objcT44,objcT45,objcT46,objcT47;

# 215 "blockxpr.m"
id x=(objcT44=self->locals,(*(id(*)(id,SEL,unsigned))_imp(objcT44,selTransTbl[7]))(objcT44,selTransTbl[7],i));

if((objcT45=(objcT46=(id)self,(*_imp(objcT46,selTransTbl[25]))(objcT46,selTransTbl[25],x)),(*(BOOL(*)(id,SEL))_imp(objcT45,selTransTbl[23]))(objcT45,selTransTbl[23]))&& !(objcT47=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT47,selTransTbl[26]))(objcT47,selTransTbl[26],x))){
id objcT48;

# 218 "blockxpr.m"
(objcT48=(id)self,(*_imp(objcT48,selTransTbl[21]))(objcT48,selTransTbl[21],x));
}
}
}
return(id)self;
}

static id i_BlockExpr_typesynth(struct BlockExpr_PRIVATE *self,SEL _cmd)
{self->
type=t_id;
return(id)self;
}

static id i_BlockExpr_genblocktype(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
if(self->numheapvarblocks){
int i;

gf("%s {\n",self->blktypename);
for(i=0;i<self->numheapvarblocks;i++){
id objcT49,objcT50,objcT51;

# 238 "blockxpr.m"
id c=(objcT49=self->heapvarblocks,(*(id(*)(id,SEL,unsigned))_imp(objcT49,selTransTbl[7]))(objcT49,selTransTbl[7],i));
char*hvt=(objcT50=c,(*(char*(*)(id,SEL))_imp(objcT50,selTransTbl[27]))(objcT50,selTransTbl[27]));
char*hvp=(objcT51=c,(*(char*(*)(id,SEL))_imp(objcT51,selTransTbl[28]))(objcT51,selTransTbl[28]));

gf("%s *%s;\n",hvt,hvp);
}
gs("};\n");
}
return(id)self;
}

static id i_BlockExpr_packblockdata(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
int i;

for(i=0;i<self->numheapvarblocks;i++){
id objcT52,objcT53;

# 254 "blockxpr.m"
id c=(objcT52=self->heapvarblocks,(*(id(*)(id,SEL,unsigned))_imp(objcT52,selTransTbl[7]))(objcT52,selTransTbl[7],i));
char*hvp=(objcT53=c,(*(char*(*)(id,SEL))_imp(objcT53,selTransTbl[28]))(objcT53,selTransTbl[28]));

gf("%s->%s=%s;\n",self->blkdataname,hvp,hvp);
gf("%s->heaprefcnt++;\n",hvp);
}
return(id)self;
}

static id i_BlockExpr_unpackblockdata(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
int i;

for(i=0;i<self->numheapvarblocks;i++){
id objcT54,objcT55,objcT56;

# 268 "blockxpr.m"
id c=(objcT54=self->heapvarblocks,(*(id(*)(id,SEL,unsigned))_imp(objcT54,selTransTbl[7]))(objcT54,selTransTbl[7],i));
char*hvt=(objcT55=c,(*(char*(*)(id,SEL))_imp(objcT55,selTransTbl[27]))(objcT55,selTransTbl[27]));
char*hvp=(objcT56=c,(*(char*(*)(id,SEL))_imp(objcT56,selTransTbl[28]))(objcT56,selTransTbl[28]));

gf("%s *%s=%s->%s;\n",hvt,hvp,self->blkdataname,hvp);
}
return(id)self;
}

static id i_BlockExpr_genconstructor(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT60;

# 279 "blockxpr.m"
(void)0;
gf("static id %s(",self->blkconsname);
if( !self->numheapvarblocks){
gs("void");
}else{
int i;
int comma=0;

for(i=0;i<self->numheapvarblocks;i++){
id objcT57,objcT58,objcT59;

# 288 "blockxpr.m"
id c=(objcT57=self->heapvarblocks,(*(id(*)(id,SEL,unsigned))_imp(objcT57,selTransTbl[7]))(objcT57,selTransTbl[7],i));
char*hvt=(objcT58=c,(*(char*(*)(id,SEL))_imp(objcT58,selTransTbl[27]))(objcT58,selTransTbl[27]));
char*hvp=(objcT59=c,(*(char*(*)(id,SEL))_imp(objcT59,selTransTbl[28]))(objcT59,selTransTbl[28]));

if(comma)
gc(',');
else
comma++;
gf("%s *%s",hvt,hvp);
}
}
gs(")\n");
gs("{\n");
if(self->numheapvarblocks){

gf("%s *%s=OC_Malloc(sizeof(%s));\n",self->blktypename,self->blkdataname,self->blktypename);
}
if(self->numheapvarblocks)
(objcT60=(id)self,(*_imp(objcT60,selTransTbl[29]))(objcT60,selTransTbl[29]));
gf("return newBlock(%i,(IMP)%s,",self->numparms,self->blkfunname);
if( !o_postlink){
id objcT61;

# 309 "blockxpr.m"
(objcT61=trlunit,(*_imp(objcT61,selTransTbl[30]))(objcT61,selTransTbl[30],s_newblock));
}
if(self->numheapvarblocks){
gf("%s,(IMP)%s);\n",self->blkdataname,self->blkdtorname);
}else{
gs("(void*)0,(IMP)0);\n");
}
gs("}\n");
return(id)self;
}

static id i_BlockExpr_gendestructor(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT62;

# 322 "blockxpr.m"
int i;
(void)0;
gc('\n');
gf("static void %s(%s *%s)\n",self->blkdtorname,self->blktypename,self->blkdataname);
gs("{\n");
(objcT62=(id)self,(*_imp(objcT62,selTransTbl[31]))(objcT62,selTransTbl[31]));
for(i=0;i<self->numheapvarblocks;i++){
id objcT63,objcT64;

# 329 "blockxpr.m"
(objcT63=(objcT64=self->heapvarblocks,(*(id(*)(id,SEL,unsigned))_imp(objcT64,selTransTbl[7]))(objcT64,selTransTbl[7],i)),(*_imp(objcT63,selTransTbl[32]))(objcT63,selTransTbl[32]));
}
gf("OC_Free(%s);\n",self->blkdataname);
gs("}\n");
return(id)self;
}

static id i_BlockExpr_genblockfun(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT65,objcT66,objcT67,objcT72,objcT73;
id objcT74,objcT75,objcT76,objcT77,objcT86;
id objcT87;

# 338 "blockxpr.m"
(objcT65=(id)self,(*_imp(objcT65,selTransTbl[33]))(objcT65,selTransTbl[33]));
gs("static");
(objcT66=self->restype,(*_imp(objcT66,selTransTbl[34]))(objcT66,selTransTbl[34],(id)0));
gs(self->blkfunname);
gs("(id thisBlock,");
if(self->numheapvarblocks){
gf("%s *%s",self->blktypename,self->blkdataname);
}else{
gf("void *%s",self->blkdataname);
}
if(self->parms)
(objcT67=self->parms,(*(id(*)(id,SEL,SEL))_imp(objcT67,selTransTbl[13]))(objcT67,selTransTbl[13],selTransTbl[35]));
gs(")\n{\n");
if(o_refcnt){
id objcT68;

# 352 "blockxpr.m"
gs("int _returnflag = 0;\n");
if( !(objcT68=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT68,selTransTbl[36]))(objcT68,selTransTbl[36]))){
id objcT69,objcT70;

# 354 "blockxpr.m"
(objcT69=self->restype,(*_imp(objcT69,selTransTbl[34]))(objcT69,selTransTbl[34],s_returnval));
if((objcT70=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT70,selTransTbl[37]))(objcT70,selTransTbl[37]))){
id objcT71;

# 356 "blockxpr.m"
gs("=(");
(objcT71=self->restype,(*_imp(objcT71,selTransTbl[38]))(objcT71,selTransTbl[38]));
gs(")0");
}
gs(";\n");
}
}
if(self->heapvars)
(objcT72=(id)self,(*_imp(objcT72,selTransTbl[39]))(objcT72,selTransTbl[39]));
if(self->numheapvarblocks)
(objcT73=(id)self,(*_imp(objcT73,selTransTbl[31]))(objcT73,selTransTbl[31]));
if(self->tmpvars)
gvarlist(self->tmpvars,"id",(o_refcnt)?"=(id)0":"");
if(self->icaches)
gvarlist(self->icaches,"static struct objcrt_inlineCache","");
if(self->datadefs)
(objcT74=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT74,selTransTbl[13]))(objcT74,selTransTbl[13],selTransTbl[40]));
if(self->increfs)
(objcT75=(id)self,(*_imp(objcT75,selTransTbl[41]))(objcT75,selTransTbl[41]));
if(self->initializers)
(objcT76=self->initializers,(*(id(*)(id,SEL,SEL))_imp(objcT76,selTransTbl[13]))(objcT76,selTransTbl[13],selTransTbl[40]));
if(self->stmts)
(objcT77=self->stmts,(*(id(*)(id,SEL,SEL))_imp(objcT77,selTransTbl[13]))(objcT77,selTransTbl[13],selTransTbl[40]));
if(self->returnlabel){
id objcT78;

# 380 "blockxpr.m"
gc('\n');
gs((objcT78=self->returnlabel,(*(STR(*)(id,SEL))_imp(objcT78,selTransTbl[42]))(objcT78,selTransTbl[42])));
gs(":\n");
}
if(o_refcnt){
id objcT79,objcT82;

# 385 "blockxpr.m"
gs("_returnflag++;\n");
if(self->expr&& !(objcT79=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT79,selTransTbl[36]))(objcT79,selTransTbl[36]))){
id objcT80,objcT81;

# 387 "blockxpr.m"
gs("_returnval=");
(objcT80=self->expr,(*_imp(objcT80,selTransTbl[40]))(objcT80,selTransTbl[40]));
gs(";\n");
if((objcT81=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT81,selTransTbl[23]))(objcT81,selTransTbl[23])))
gs("idincref(_returnval);");
}
if(self->decrefs)
(objcT82=(id)self,(*_imp(objcT82,selTransTbl[43]))(objcT82,selTransTbl[43]));
}
if(self->heapvars){
id objcT83;

# 397 "blockxpr.m"
(objcT83=(id)self,(*_imp(objcT83,selTransTbl[32]))(objcT83,selTransTbl[32]));
}
if(self->expr){
if(o_refcnt){
id objcT84;

# 401 "blockxpr.m"
if((objcT84=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT84,selTransTbl[36]))(objcT84,selTransTbl[36]))){
gs("return;\n");
}else{
gs("return _returnval;");
}
}else{
id objcT85;

# 407 "blockxpr.m"
gs("return ");
(objcT85=self->expr,(*_imp(objcT85,selTransTbl[40]))(objcT85,selTransTbl[40]));
gs(";\n");
}
}else{
if(o_refcnt){
gs("return idincref(thisBlock);\n");
}else{
gs("return thisBlock;\n");
}
}
gs("}\n");

if(self->numheapvarblocks)(objcT86=(id)self,(*_imp(objcT86,selTransTbl[44]))(objcT86,selTransTbl[44]));
(objcT87=(id)self,(*_imp(objcT87,selTransTbl[45]))(objcT87,selTransTbl[45]));

return(id)self;
}

static id i_BlockExpr_addheapvarblock_(struct BlockExpr_PRIVATE *self,SEL _cmd,id c)
{
if(c==(id)self){
return(id)self;
}else{
id objcT88,objcT89,objcT90,objcT91;

# 431 "blockxpr.m"
if( !self->heapvarblocks)self->
heapvarblocks=(objcT88=OrdCltn,(*_imp(objcT88,selTransTbl[1]))(objcT88,selTransTbl[1]));
(objcT89=self->heapvarblocks,(*_imp(objcT89,selTransTbl[46]))(objcT89,selTransTbl[46],c));self->
numheapvarblocks=(objcT90=self->heapvarblocks,(*(unsigned(*)(id,SEL))_imp(objcT90,selTransTbl[5]))(objcT90,selTransTbl[5]));
if(self->enclosing)
(objcT91=self->enclosing,(*_imp(objcT91,selTransTbl[47]))(objcT91,selTransTbl[47],c));
return(id)self;
}
}

static id i_BlockExpr_gen(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT92,objcT93,objcT94;

# 443 "blockxpr.m"
int i;
int comma=0;

gl((objcT92=(id)self,(*(int(*)(id,SEL))_imp(objcT92,selTransTbl[10]))(objcT92,selTransTbl[10])),(objcT93=(objcT94=(id)self,(*_imp(objcT94,selTransTbl[11]))(objcT94,selTransTbl[11])),(*(STR(*)(id,SEL))_imp(objcT93,selTransTbl[42]))(objcT93,selTransTbl[42])));
if(self->refvar){
id objcT95;

# 448 "blockxpr.m"
gc('(');
gs((objcT95=self->refvar,(*(STR(*)(id,SEL))_imp(objcT95,selTransTbl[42]))(objcT95,selTransTbl[42])));
gc('=');
}
gf("%s(",self->blkconsname);
for(i=0;i<self->numheapvarblocks;i++){
id objcT96,objcT97;

# 454 "blockxpr.m"
if(comma)
gc(',');
else
comma++;
gs((objcT96=(objcT97=self->heapvarblocks,(*(id(*)(id,SEL,unsigned))_imp(objcT97,selTransTbl[7]))(objcT97,selTransTbl[7],i)),(*(char*(*)(id,SEL))_imp(objcT96,selTransTbl[28]))(objcT96,selTransTbl[28])));
}
gc(')');
if(self->refvar)gc(')');
return(id)self;
}

# 24 "./shared.m"
static id i_BlockExpr_enclosing(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
return self->enclosing;
}

static id i_BlockExpr_addtmpvar_(struct BlockExpr_PRIVATE *self,SEL _cmd,id tvar)
{
id objcT98,objcT99;

# 31 "./shared.m"
if( !self->tmpvars)self->
tmpvars=(objcT98=OrdCltn,(*_imp(objcT98,selTransTbl[1]))(objcT98,selTransTbl[1]));
(objcT99=self->tmpvars,(*_imp(objcT99,selTransTbl[4]))(objcT99,selTransTbl[4],tvar));
return(id)self;
}

static id i_BlockExpr_addicache_(struct BlockExpr_PRIVATE *self,SEL _cmd,id tvar)
{
id objcT100,objcT101;

# 39 "./shared.m"
if( !self->icaches)self->
icaches=(objcT100=OrdCltn,(*_imp(objcT100,selTransTbl[1]))(objcT100,selTransTbl[1]));
(objcT101=self->icaches,(*_imp(objcT101,selTransTbl[4]))(objcT101,selTransTbl[4],tvar));
return(id)self;
}

static id i_BlockExpr_addincref_(struct BlockExpr_PRIVATE *self,SEL _cmd,id v)
{
id objcT102,objcT103;

# 47 "./shared.m"
if( !self->increfs)self->
increfs=(objcT102=OrdCltn,(*_imp(objcT102,selTransTbl[1]))(objcT102,selTransTbl[1]));
(objcT103=self->increfs,(*_imp(objcT103,selTransTbl[4]))(objcT103,selTransTbl[4],v));
return(id)self;
}

static id i_BlockExpr_genincrefs(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT104;

# 55 "./shared.m"
int i,n=(objcT104=self->increfs,(*(unsigned(*)(id,SEL))_imp(objcT104,selTransTbl[5]))(objcT104,selTransTbl[5]));

for(i=0;i<n;i++){
id objcT105,objcT106,objcT107,objcT108,objcT109;

# 58 "./shared.m"
if(self->lbrace)gl((objcT105=self->lbrace,(*(int(*)(id,SEL))_imp(objcT105,selTransTbl[10]))(objcT105,selTransTbl[10])),(objcT106=(objcT107=self->lbrace,(*_imp(objcT107,selTransTbl[11]))(objcT107,selTransTbl[11])),(*(STR(*)(id,SEL))_imp(objcT106,selTransTbl[42]))(objcT106,selTransTbl[42])));
gf("idincref(%s);\n",(objcT108=(objcT109=self->increfs,(*(id(*)(id,SEL,unsigned))_imp(objcT109,selTransTbl[7]))(objcT109,selTransTbl[7],i)),(*(STR(*)(id,SEL))_imp(objcT108,selTransTbl[42]))(objcT108,selTransTbl[42])));
}
gc('\n');
return(id)self;
}

static id i_BlockExpr_adddecref_(struct BlockExpr_PRIVATE *self,SEL _cmd,id v)
{
id objcT110,objcT111,objcT112;

# 67 "./shared.m"
if( !self->decrefs)self->
decrefs=(objcT110=OrdCltn,(*_imp(objcT110,selTransTbl[1]))(objcT110,selTransTbl[1]));
(objcT111=self->decrefs,(*_imp(objcT111,selTransTbl[4]))(objcT111,selTransTbl[4],v));

if(curloopcompound&&(id)self!=curloopcompound)
(objcT112=curloopcompound,(*_imp(objcT112,selTransTbl[21]))(objcT112,selTransTbl[21],v));
return(id)self;
}

static id i_BlockExpr_gendecrefs(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT113;

# 78 "./shared.m"
int i,n=(objcT113=self->decrefs,(*(unsigned(*)(id,SEL))_imp(objcT113,selTransTbl[5]))(objcT113,selTransTbl[5]));

for(i=0;i<n;i++){
id objcT114,objcT115,objcT116,objcT117,objcT118;

# 81 "./shared.m"
char*s=(objcT114=(objcT115=self->decrefs,(*(id(*)(id,SEL,unsigned))_imp(objcT115,selTransTbl[7]))(objcT115,selTransTbl[7],i)),(*(STR(*)(id,SEL))_imp(objcT114,selTransTbl[42]))(objcT114,selTransTbl[42]));

if(self->rbrace)gl((objcT116=self->rbrace,(*(int(*)(id,SEL))_imp(objcT116,selTransTbl[10]))(objcT116,selTransTbl[10])),(objcT117=(objcT118=self->rbrace,(*_imp(objcT118,selTransTbl[11]))(objcT118,selTransTbl[11])),(*(STR(*)(id,SEL))_imp(objcT117,selTransTbl[42]))(objcT117,selTransTbl[42])));
gf("%s=iddecref(%s);\n",s,s);
}
gc('\n');
return(id)self;
}

static id i_BlockExpr_lookuplocal_(struct BlockExpr_PRIVATE *self,SEL _cmd,id sym)
{
id objcT119;

# 92 "./shared.m"
return(self->localdic)?(objcT119=self->localdic,(*_imp(objcT119,selTransTbl[48]))(objcT119,selTransTbl[48],sym)):(id)0;
}

# 32 "./../../include/objpak/dictnary.h"
extern id  Dictionary;

# 95 "./shared.m"
static id i_BlockExpr_deflocal_astype_(struct BlockExpr_PRIVATE *self,SEL _cmd,id sym,id t)
{
id objcT122,objcT123,objcT124;

# 97 "./shared.m"
if( !self->localdic){
id objcT120,objcT121;
self->
# 98 "./shared.m"
localdic=(objcT120=Dictionary,(*_imp(objcT120,selTransTbl[1]))(objcT120,selTransTbl[1]));self->
locals=(objcT121=OrdCltn,(*_imp(objcT121,selTransTbl[1]))(objcT121,selTransTbl[1]));
}
(objcT122=self->localdic,(*_imp(objcT122,selTransTbl[49]))(objcT122,selTransTbl[49],sym,t));
(objcT123=self->locals,(*_imp(objcT123,selTransTbl[4]))(objcT123,selTransTbl[4],sym));
if(curdef&&((objcT124=curdef,(*(BOOL(*)(id,SEL))_imp(objcT124,selTransTbl[50]))(objcT124,selTransTbl[50])))){
id objcT125,objcT127;

# 104 "./shared.m"
(void)0;
if((objcT125=curclassdef,(*(BOOL(*)(id,SEL,id))_imp(objcT125,selTransTbl[51]))(objcT125,selTransTbl[51],sym))){
id objcT126;

# 106 "./shared.m"
warnat(sym,"definition of local '%s' hides instance variable",(objcT126=sym,(*(STR(*)(id,SEL))_imp(objcT126,selTransTbl[42]))(objcT126,selTransTbl[42])));
}
if((objcT127=curclassdef,(*(BOOL(*)(id,SEL,id))_imp(objcT127,selTransTbl[52]))(objcT127,selTransTbl[52],sym))){
id objcT128;

# 109 "./shared.m"
warnat(sym,"definition of local '%s' hides class variable",(objcT128=sym,(*(STR(*)(id,SEL))_imp(objcT128,selTransTbl[42]))(objcT128,selTransTbl[42])));
}
}
return(id)self;
}

static id i_BlockExpr_genheapvarptr(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
char*p=self->heapvarptrname;
char*t=self->heapvartypename;

(void)0;

gf("%s *%s=(%s *)OC_Calloc(sizeof(%s));\n",t,p,t,t);
return(id)self;
}

static id i_BlockExpr_freeheapvarptr(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT129;

# 128 "./shared.m"
char*p=self->heapvarptrname;

gf("if (%s->heaprefcnt-- == 0) {\n",p);
if(o_refcnt)(objcT129=(id)self,(*_imp(objcT129,selTransTbl[53]))(objcT129,selTransTbl[53]));
gf("OC_Free(%s);\n",p);
gs("}\n");

return(id)self;
}

static id i_BlockExpr_gendecrefsheapvars(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT130;

# 140 "./shared.m"
int i,n=(objcT130=self->heapnames,(*(unsigned(*)(id,SEL))_imp(objcT130,selTransTbl[5]))(objcT130,selTransTbl[5]));
char*hvp=self->heapvarptrname;

for(i=0;i<n;i++){
id objcT131,objcT132,objcT133;

# 144 "./shared.m"
id x=(objcT131=self->heapnames,(*(id(*)(id,SEL,unsigned))_imp(objcT131,selTransTbl[7]))(objcT131,selTransTbl[7],i));
id t=(objcT132=self->heaptypes,(*(id(*)(id,SEL,unsigned))_imp(objcT132,selTransTbl[7]))(objcT132,selTransTbl[7],i));

(void)0;
if((objcT133=t,(*(BOOL(*)(id,SEL))_imp(objcT133,selTransTbl[23]))(objcT133,selTransTbl[23]))){
id objcT134;

# 149 "./shared.m"
char*s=(objcT134=x,(*(STR(*)(id,SEL))_imp(objcT134,selTransTbl[42]))(objcT134,selTransTbl[42]));
gf("%s->%s=iddecref(%s->%s);\n",hvp,s,hvp,s);
}
}
return(id)self;
}

static id i_BlockExpr_genheapvartype(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT135;

# 158 "./shared.m"
int i,n=(objcT135=self->heapnames,(*(unsigned(*)(id,SEL))_imp(objcT135,selTransTbl[5]))(objcT135,selTransTbl[5]));

if( !n)
return(id)self;
gf("%s {\n",self->heapvartypename);
gs("int heaprefcnt;\n");
for(i=0;i<n;i++){
id objcT136,objcT137,objcT138;

# 165 "./shared.m"
id x=(objcT136=self->heapnames,(*(id(*)(id,SEL,unsigned))_imp(objcT136,selTransTbl[7]))(objcT136,selTransTbl[7],i));
id t=(objcT137=self->heaptypes,(*(id(*)(id,SEL,unsigned))_imp(objcT137,selTransTbl[7]))(objcT137,selTransTbl[7],i));

(void)0;
(objcT138=t,(*_imp(objcT138,selTransTbl[34]))(objcT138,selTransTbl[34],x));
gs(";\n");
}
gs("};\n");
return(id)self;
}

static id i_BlockExpr_heapvars(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static BOOL i_BlockExpr_isheapvar_(struct BlockExpr_PRIVATE *self,SEL _cmd,id x)
{
id objcT139;

# 183 "./shared.m"
return(self->heapvars)?(objcT139=self->heapvars,(*(BOOL(*)(id,SEL,id))_imp(objcT139,selTransTbl[54]))(objcT139,selTransTbl[54],x)):(BOOL)0;
}

# 36 "./../../include/objpak/set.h"
extern id  Set;

# 186 "./shared.m"
static id i_BlockExpr_defheapvar_type_(struct BlockExpr_PRIVATE *self,SEL _cmd,id x,id t)
{
id objcT148;

# 188 "./shared.m"
int i;

if( !self->heapvars){
id objcT140,objcT141,objcT142,objcT143,objcT144;
id objcT145,objcT146,objcT147;
self->
# 191 "./shared.m"
heapvars=(objcT140=Set,(*_imp(objcT140,selTransTbl[1]))(objcT140,selTransTbl[1]));self->
heapnames=(objcT141=OrdCltn,(*_imp(objcT141,selTransTbl[1]))(objcT141,selTransTbl[1]));self->
heaptypes=(objcT142=OrdCltn,(*_imp(objcT142,selTransTbl[1]))(objcT142,selTransTbl[1]));
i=(objcT143=trlunit,(*(int(*)(id,SEL))_imp(objcT143,selTransTbl[55]))(objcT143,selTransTbl[55]));self->
heapvarptrname=(objcT144=(objcT145=String,(*(id(*)(id,SEL,STR,...))_imp(objcT145,selTransTbl[15]))(objcT145,selTransTbl[15],"heapvars%i",i)),(*(STR(*)(id,SEL))_imp(objcT144,selTransTbl[16]))(objcT144,selTransTbl[16]));self->
heapvartypename=(objcT146=(objcT147=String,(*(id(*)(id,SEL,STR,...))_imp(objcT147,selTransTbl[15]))(objcT147,selTransTbl[15],"struct heaptype%i",i)),(*(STR(*)(id,SEL))_imp(objcT146,selTransTbl[16]))(objcT146,selTransTbl[16]));
}
if((objcT148=t,(*(BOOL(*)(id,SEL))_imp(objcT148,selTransTbl[56]))(objcT148,selTransTbl[56]))){
id objcT149;

# 199 "./shared.m"
char*msg="can't use static local variables (%s) from within block";

fatalat(x,msg,(objcT149=x,(*(STR(*)(id,SEL))_imp(objcT149,selTransTbl[42]))(objcT149,selTransTbl[42])));
}else{
id objcT150;

# 203 "./shared.m"
if((objcT150=self->heapvars,(*_imp(objcT150,selTransTbl[57]))(objcT150,selTransTbl[57],x))!=(id)0){
id objcT151,objcT152;

# 204 "./shared.m"
(objcT151=self->heapnames,(*_imp(objcT151,selTransTbl[4]))(objcT151,selTransTbl[4],x));
(objcT152=self->heaptypes,(*_imp(objcT152,selTransTbl[4]))(objcT152,selTransTbl[4],t));
}
}
return(id)self;
}

static char*i_BlockExpr_heapvarptrname(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
(void)0;
return self->heapvarptrname;
}

static char*i_BlockExpr_heapvartypename(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
(void)0;
return self->heapvartypename;
}

static id i_BlockExpr_removeheapvarsfromdatadefs(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT153,objcT165;

# 225 "./shared.m"
int n;

(void)0;self->
initializers=(objcT153=OrdCltn,(*_imp(objcT153,selTransTbl[1]))(objcT153,selTransTbl[1]));

if(self->parmnames){
id objcT154;

# 231 "./shared.m"
n=(objcT154=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT154,selTransTbl[5]))(objcT154,selTransTbl[5]));
while(n--){
id objcT155,objcT156;

# 233 "./shared.m"
id p=(objcT155=self->parmnames,(*(id(*)(id,SEL,unsigned))_imp(objcT155,selTransTbl[7]))(objcT155,selTransTbl[7],n));

if((objcT156=self->heapvars,(*(BOOL(*)(id,SEL,id))_imp(objcT156,selTransTbl[54]))(objcT156,selTransTbl[54],p))){
id objcT157,objcT158,objcT159;

# 236 "./shared.m"
id x=(objcT157=(objcT158=mkidentexpr(p),(*(id(*)(id,SEL,BOOL))_imp(objcT158,selTransTbl[58]))(objcT158,selTransTbl[58],(BOOL)1)),(*_imp(objcT157,selTransTbl[14]))(objcT157,selTransTbl[14]));
id y=mkidentexpr(p);

(objcT159=self->initializers,(*_imp(objcT159,selTransTbl[4]))(objcT159,selTransTbl[4],mkexprstmt(mkassignexpr(x,"=",y))));
}
}
}
if(self->datadefs){
id objcT160;

# 244 "./shared.m"
n=(objcT160=self->datadefs,(*(unsigned(*)(id,SEL))_imp(objcT160,selTransTbl[5]))(objcT160,selTransTbl[5]));
while(n--){
id objcT161,objcT162,objcT163,objcT164;

# 246 "./shared.m"
id def=(objcT161=self->datadefs,(*(id(*)(id,SEL,unsigned))_imp(objcT161,selTransTbl[7]))(objcT161,selTransTbl[7],n));

(objcT162=def,(*_imp(objcT162,selTransTbl[59]))(objcT162,selTransTbl[59],self->heapvars,self->initializers));
if((objcT163=def,(*_imp(objcT163,selTransTbl[60]))(objcT163,selTransTbl[60]))==(id)0)
(objcT164=self->datadefs,(*(id(*)(id,SEL,unsigned))_imp(objcT164,selTransTbl[61]))(objcT164,selTransTbl[61],n));
}
}
if((objcT165=self->datadefs,(*(unsigned(*)(id,SEL))_imp(objcT165,selTransTbl[5]))(objcT165,selTransTbl[5]))==0)self->
datadefs=(id)0;
return(id)self;
}

static id i_BlockExpr_fcall_(struct BlockExpr_PRIVATE *self,SEL _cmd,id x)
{
id objcT166,objcT167;

# 260 "./shared.m"
if((objcT166=x,(*(unsigned(*)(id,SEL))_imp(objcT166,selTransTbl[5]))(objcT166,selTransTbl[5]))<(objcT167=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT167,selTransTbl[5]))(objcT167,selTransTbl[5]))){
id objcT168;

# 261 "./shared.m"
return(objcT168=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT168,selTransTbl[62]))(objcT168,selTransTbl[62],"Arguments expected"));
}else{
id objcT169,objcT173,objcT174;

# 263 "./shared.m"
int i,n;
(void)0;
for(i=0,n=(objcT169=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT169,selTransTbl[5]))(objcT169,selTransTbl[5]));i<n;i++){
id objcT170,objcT171,objcT172;

# 266 "./shared.m"
(objcT170=topframe,(*_imp(objcT170,selTransTbl[63]))(objcT170,selTransTbl[63],(objcT171=self->parmnames,(*(id(*)(id,SEL,unsigned))_imp(objcT171,selTransTbl[7]))(objcT171,selTransTbl[7],i)),(objcT172=x,(*(id(*)(id,SEL,unsigned))_imp(objcT172,selTransTbl[7]))(objcT172,selTransTbl[7],i))));
}
(objcT173=(id)self,(*_imp(objcT173,selTransTbl[64]))(objcT173,selTransTbl[64]));
if((objcT174=topframe,(*(BOOL(*)(id,SEL))_imp(objcT174,selTransTbl[65]))(objcT174,selTransTbl[65]))){
id objcT175;

# 270 "./shared.m"
return(objcT175=topframe,(*_imp(objcT175,selTransTbl[66]))(objcT175,selTransTbl[66]));
}else{
return(id)0;
}
}
}

# 24 "./stkframe.h"
extern id  Stackframe;

# 277 "./shared.m"
static id i_BlockExpr_switchOn__(struct BlockExpr_PRIVATE *self,SEL _cmd,BOOL dosw,id e)
{
id objcT176,objcT177,objcT178,objcT179,objcT187;
id objcT191,objcT192;

# 279 "./shared.m"
int i,n;
BOOL quit=(BOOL)0;
BOOL dobrk=(BOOL)0;
BOOL docont=(BOOL)0;
id frame=(objcT176=(objcT177=Stackframe,(*_imp(objcT177,selTransTbl[67]))(objcT177,selTransTbl[67])),(*_imp(objcT176,selTransTbl[68]))(objcT176,selTransTbl[68],(id)self));
if(self->datadefs)(objcT178=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT178,selTransTbl[13]))(objcT178,selTransTbl[13],selTransTbl[64]));
i=0;
n=(objcT179=self->stmts,(*(unsigned(*)(id,SEL))_imp(objcT179,selTransTbl[5]))(objcT179,selTransTbl[5]));
if(dosw)for(;i<n;i++){
id objcT180,objcT181;

# 288 "./shared.m"
if((objcT180=(objcT181=self->stmts,(*(id(*)(id,SEL,unsigned))_imp(objcT181,selTransTbl[7]))(objcT181,selTransTbl[7],i)),(*(BOOL(*)(id,SEL,id))_imp(objcT180,selTransTbl[69]))(objcT180,selTransTbl[69],e)))break;
}
for(;i<n;i++){
id objcT182,objcT183,objcT184,objcT185,objcT186;

# 291 "./shared.m"
(objcT182=(objcT183=self->stmts,(*(id(*)(id,SEL,unsigned))_imp(objcT183,selTransTbl[7]))(objcT183,selTransTbl[7],i)),(*_imp(objcT182,selTransTbl[64]))(objcT182,selTransTbl[64]));
if((quit=(objcT184=frame,(*(BOOL(*)(id,SEL))_imp(objcT184,selTransTbl[65]))(objcT184,selTransTbl[65]))))break;
if((docont=(objcT185=frame,(*(BOOL(*)(id,SEL))_imp(objcT185,selTransTbl[70]))(objcT185,selTransTbl[70]))))break;
if((dobrk=(objcT186=frame,(*(BOOL(*)(id,SEL))_imp(objcT186,selTransTbl[71]))(objcT186,selTransTbl[71]))))break;
}
(objcT187=Stackframe,(*_imp(objcT187,selTransTbl[72]))(objcT187,selTransTbl[72]));
if(quit){
id objcT188,objcT189,objcT190;

# 298 "./shared.m"
(objcT188=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT188,selTransTbl[73]))(objcT188,selTransTbl[73],(BOOL)1));
(objcT189=topframe,(*_imp(objcT189,selTransTbl[74]))(objcT189,selTransTbl[74],(objcT190=frame,(*_imp(objcT190,selTransTbl[66]))(objcT190,selTransTbl[66]))));
}
if(docont)(objcT191=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT191,selTransTbl[75]))(objcT191,selTransTbl[75],(BOOL)1));
if(dobrk)(objcT192=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT192,selTransTbl[76]))(objcT192,selTransTbl[76],(BOOL)1));
return(id)self;
}

static id i_BlockExpr_switchOn_(struct BlockExpr_PRIVATE *self,SEL _cmd,id e)
{
id objcT193;

# 308 "./shared.m"
return(objcT193=(id)self,(*(id(*)(id,SEL,BOOL,id))_imp(objcT193,selTransTbl[77]))(objcT193,selTransTbl[77],(BOOL)1,e));
}

static id i_BlockExpr_go(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT194;

# 313 "./shared.m"
return(objcT194=(id)self,(*(id(*)(id,SEL,BOOL,id))_imp(objcT194,selTransTbl[77]))(objcT194,selTransTbl[77],(BOOL)0,(id)0));
}

# 467 "blockxpr.m"
static id i_BlockExpr_st80(struct BlockExpr_PRIVATE *self,SEL _cmd)
{
id objcT196,objcT197,objcT198,objcT199;

# 469 "blockxpr.m"
gc('[');
if(self->parms){
id objcT195;

# 471 "blockxpr.m"
(objcT195=self->parms,(*(id(*)(id,SEL,SEL))_imp(objcT195,selTransTbl[13]))(objcT195,selTransTbl[13],_cmd));
gc('|');
}
gc('\n');
gc('|');
if(self->datadefs)
(objcT196=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT196,selTransTbl[13]))(objcT196,selTransTbl[13],_cmd));
gc('|');
gc('\n');
if(self->datadefs)
(objcT197=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT197,selTransTbl[13]))(objcT197,selTransTbl[13],selTransTbl[78]));
if(self->stmts)
(objcT198=self->stmts,(*(id(*)(id,SEL,SEL))_imp(objcT198,selTransTbl[13]))(objcT198,selTransTbl[13],_cmd));
if(self->expr)
(objcT199=self->expr,(*_imp(objcT199,selTransTbl[79]))(objcT199,selTransTbl[79]));
gc(']');
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _BlockExpr_clsDispatchTbl[] ={
{"new",(id (*)())c_BlockExpr_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _BlockExpr_nstDispatchTbl[] ={
{"usereturnflag",(id (*)())i_BlockExpr_usereturnflag},
{"blockcount:",(id (*)())i_BlockExpr_blockcount_},
{"isblockexpr",(id (*)())i_BlockExpr_isblockexpr},
{"lbrace:",(id (*)())i_BlockExpr_lbrace_},
{"rbrace:",(id (*)())i_BlockExpr_rbrace_},
{"defparm:astype:",(id (*)())i_BlockExpr_defparm_astype_},
{"parms:",(id (*)())i_BlockExpr_parms_},
{"datadefs:",(id (*)())i_BlockExpr_datadefs_},
{"stmts:",(id (*)())i_BlockExpr_stmts_},
{"expr:",(id (*)())i_BlockExpr_expr_},
{"lookupparm:",(id (*)())i_BlockExpr_lookupparm_},
{"nextreturnlabel",(id (*)())i_BlockExpr_nextreturnlabel},
{"returnlabel",(id (*)())i_BlockExpr_returnlabel},
{"lineno",(id (*)())i_BlockExpr_lineno},
{"filename",(id (*)())i_BlockExpr_filename},
{"synth",(id (*)())i_BlockExpr_synth},
{"typesynth",(id (*)())i_BlockExpr_typesynth},
{"genblocktype",(id (*)())i_BlockExpr_genblocktype},
{"packblockdata",(id (*)())i_BlockExpr_packblockdata},
{"unpackblockdata",(id (*)())i_BlockExpr_unpackblockdata},
{"genconstructor",(id (*)())i_BlockExpr_genconstructor},
{"gendestructor",(id (*)())i_BlockExpr_gendestructor},
{"genblockfun",(id (*)())i_BlockExpr_genblockfun},
{"addheapvarblock:",(id (*)())i_BlockExpr_addheapvarblock_},
{"gen",(id (*)())i_BlockExpr_gen},
{"enclosing",(id (*)())i_BlockExpr_enclosing},
{"addtmpvar:",(id (*)())i_BlockExpr_addtmpvar_},
{"addicache:",(id (*)())i_BlockExpr_addicache_},
{"addincref:",(id (*)())i_BlockExpr_addincref_},
{"genincrefs",(id (*)())i_BlockExpr_genincrefs},
{"adddecref:",(id (*)())i_BlockExpr_adddecref_},
{"gendecrefs",(id (*)())i_BlockExpr_gendecrefs},
{"lookuplocal:",(id (*)())i_BlockExpr_lookuplocal_},
{"deflocal:astype:",(id (*)())i_BlockExpr_deflocal_astype_},
{"genheapvarptr",(id (*)())i_BlockExpr_genheapvarptr},
{"freeheapvarptr",(id (*)())i_BlockExpr_freeheapvarptr},
{"gendecrefsheapvars",(id (*)())i_BlockExpr_gendecrefsheapvars},
{"genheapvartype",(id (*)())i_BlockExpr_genheapvartype},
{"heapvars",(id (*)())i_BlockExpr_heapvars},
{"isheapvar:",(id (*)())i_BlockExpr_isheapvar_},
{"defheapvar:type:",(id (*)())i_BlockExpr_defheapvar_type_},
{"heapvarptrname",(id (*)())i_BlockExpr_heapvarptrname},
{"heapvartypename",(id (*)())i_BlockExpr_heapvartypename},
{"removeheapvarsfromdatadefs",(id (*)())i_BlockExpr_removeheapvarsfromdatadefs},
{"fcall:",(id (*)())i_BlockExpr_fcall_},
{"switchOn::",(id (*)())i_BlockExpr_switchOn__},
{"switchOn:",(id (*)())i_BlockExpr_switchOn_},
{"go",(id (*)())i_BlockExpr_go},
{"st80",(id (*)())i_BlockExpr_st80},
{(char*)0,(id (*)())0}
};
id BlockExpr = (id)&_BlockExpr;
id  *OBJCCLASS_BlockExpr(void) { return &BlockExpr; }
struct _SHARED  _BlockExpr = {
  (id)&__BlockExpr,
  (id)&_Expr,
  "BlockExpr",
  0,
  sizeof(struct BlockExpr_PRIVATE),
  49,
  _BlockExpr_nstDispatchTbl,
  41,
  &blockxpr_modDesc,
  0,
  (id)0,
  &BlockExpr,
};
id  OBJCCFUNC_BlockExpr(void) { return (id)&_BlockExpr; }
id  OBJCCSUPER_BlockExpr(void) { return _BlockExpr.clsSuper; }
struct _SHARED __BlockExpr = {
  (id)&__Object,
  (id)&__Expr,
  "BlockExpr",
  0,
  sizeof(struct _SHARED),
  1,
  _BlockExpr_clsDispatchTbl,
  34,
  &blockxpr_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_BlockExpr(void) { return (id)&__BlockExpr; }
id  OBJCMSUPER_BlockExpr(void) { return __BlockExpr.clsSuper; }
static char *_selTransTbl[] ={
"usingblocks:",
"new",
"blockcount:",
"blockcount",
"add:",
"size",
"arg:",
"at:",
"findMatching:",
"returnlabel",
"lineno",
"filename",
"addblockreference:",
"elementsPerform:",
"synth",
"sprintf:",
"strCopy",
"type",
"removeheapvarsfromdatadefs",
"gettmpvar",
"addtmpvar:",
"adddecref:",
"lookupparm:",
"isid",
"addincref:",
"lookuplocal:",
"isheapvar:",
"heapvartypename",
"heapvarptrname",
"packblockdata",
"usesentry:",
"unpackblockdata",
"freeheapvarptr",
"genblocktype",
"gendef:",
"gencommaparm",
"isvoid",
"isscalartype",
"genabstrtype",
"genheapvarptr",
"gen",
"genincrefs",
"str",
"gendecrefs",
"gendestructor",
"genconstructor",
"addIfAbsent:",
"addheapvarblock:",
"atKey:",
"atKey:put:",
"ismethdef",
"isivar:",
"iscvar:",
"gendecrefsheapvars",
"contains:",
"heapvarcount",
"isstatic",
"addNTest:",
"lhsself:",
"removevars:initializers:",
"decllist",
"removeAt:",
"error:",
"defval:as:",
"go",
"quitframe",
"returnval",
"push",
"compound:",
"iscaseOf:",
"contframe",
"breakframe",
"pop",
"quitframe:",
"returnval:",
"contframe:",
"breakframe:",
"switchOn::",
"st80inits",
"st80",
0
};
struct modDescriptor blockxpr_modDesc = {
  "blockxpr",
  "objc3.3.19",
  0L,
  0,
  0,
  &BlockExpr,
  80,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_blockxpr(void)
{
  selTransTbl = _selTransTbl;
  return &blockxpr_modDesc;
}
int _OBJCPOSTLINK_blockxpr = 1;


