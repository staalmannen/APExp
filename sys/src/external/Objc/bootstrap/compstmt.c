# 1 "compstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_compstmt(void);
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
extern struct modDescriptor compstmt_modDesc;

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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./def.h"
extern id curdef;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
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
# 52 "compstmt.m"
id curcompound;
id curloopcompound;
# 25 "./compstmt.h"
struct CompoundStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 27 "./compstmt.h"
id lbrace;
id datadefs;
id initializers;
id stmts;
id subblock;
id rbrace;
id enclosing;
id returnlabel;
id parmnames;
id tmpvars;
id icaches;
id localdic;
id locals;
id alllocals;
id heapvars,heapnames,heaptypes;
id heapparms;
char*heapvarptrname;
char*heapvartypename;
id localexprs;
id heapvarblocks;
id restype;
id increfs,decrefs;
BOOL bracedgroup;
BOOL needreturnflag;
BOOL checkreturnflag;};

# 25 "./compstmt.h"
extern id  CompoundStmt;

# 25 "./compstmt.h"
extern struct _SHARED _CompoundStmt;
extern struct _SHARED __CompoundStmt;


# 57 "compstmt.m"
static BOOL i_CompoundStmt_isbracedgroup(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
return self->bracedgroup;
}

static id i_CompoundStmt_setbracedgroup_(struct CompoundStmt_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
bracedgroup=flag;
return(id)self;
}

static id i_CompoundStmt_setreturnflag(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
if(self->checkreturnflag){
return(id)self;
}else{
if(self->enclosing){
id objcT0;
self->
# 74 "compstmt.m"
checkreturnflag++;
(objcT0=self->enclosing,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}else{self->
needreturnflag++;
}
}
return(id)self;
}

static id i_CompoundStmt_usereturnflag(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
if(self->enclosing){
id objcT1;
self->
# 86 "compstmt.m"
checkreturnflag++;
(objcT1=self->enclosing,(*_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
}else{self->
needreturnflag++;
}
return(id)self;
}

static BOOL i_CompoundStmt_iscompstmt(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
return(BOOL)1;
}

static int i_CompoundStmt_lineno(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT2;

# 101 "compstmt.m"
if(self->lbrace)return(objcT2=self->lbrace,(*(int(*)(id,SEL))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
return 0;
}

static id i_CompoundStmt_filename(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT3;

# 107 "compstmt.m"
if(self->lbrace)return(objcT3=self->lbrace,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
return(id)0;
}

static id i_CompoundStmt_lbrace_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id lb)
{self->
lbrace=lb;
return(id)self;
}

static id i_CompoundStmt_rbrace_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id rb)
{self->
rbrace=rb;
return(id)self;
}

static id i_CompoundStmt_datadefs_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id defs)
{self->
datadefs=defs;
return(id)self;
}

static id i_CompoundStmt_stmts_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id stmtlist)
{self->
stmts=stmtlist;
return(id)self;
}

static id i_CompoundStmt_subblock_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id sub)
{self->
subblock=sub;
return(id)self;
}

static id i_CompoundStmt_nextreturnlabel(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
if(self->returnlabel){
return self->returnlabel;
}else{
if(self->enclosing){
if(self->decrefs||self->heapvars){
id objcT4;

# 148 "compstmt.m"
return(objcT4=(id)self,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));
}else{
id objcT5;

# 150 "compstmt.m"
return(objcT5=self->enclosing,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4]));
}
}else{
id objcT6;
return(objcT6=(id)self,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
}
}
}

static id i_CompoundStmt_returnlabel(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
(void)0;

if( !self->returnlabel){
if(self->bracedgroup){
fatal("-refcnt doesn't work inside GNU ({...}) braced groups");
}else{
id objcT7;
self->
# 167 "compstmt.m"
returnlabel=(objcT7=trlunit,(*_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3]));
}
}

return self->returnlabel;
}

static id i_CompoundStmt_lookupparm_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id sym)
{
return(id)0;
}

static id i_CompoundStmt_synth(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT16,objcT17,objcT18,objcT19;

# 181 "compstmt.m"
int i,n;self->

enclosing=curcompound;
curcompound=(id)self;
if( !self->enclosing){
id objcT8,objcT9;
self->
# 186 "compstmt.m"
restype=(objcT8=curdef,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));self->
parmnames=(objcT9=curdef,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
if(o_refcnt){
id objcT10;

# 189 "compstmt.m"
for(i=0,n=(objcT10=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7]));i<n;i++){
id objcT11,objcT12,objcT13;

# 190 "compstmt.m"
id x=(objcT11=self->parmnames,(*(id(*)(id,SEL,unsigned))_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8],i));

if((objcT12=(objcT13=curdef,(*_imp(objcT13,selTransTbl[9]))(objcT13,selTransTbl[9],x)),(*(BOOL(*)(id,SEL))_imp(objcT12,selTransTbl[10]))(objcT12,selTransTbl[10]))){
id objcT14,objcT15;

# 193 "compstmt.m"
(objcT14=(id)self,(*_imp(objcT14,selTransTbl[11]))(objcT14,selTransTbl[11],x));
(objcT15=(id)self,(*_imp(objcT15,selTransTbl[12]))(objcT15,selTransTbl[12],x));
}
}
}
}
if(self->datadefs)
(objcT16=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT16,selTransTbl[13]))(objcT16,selTransTbl[13],_cmd));
if(self->stmts)
(objcT17=self->stmts,(*(id(*)(id,SEL,SEL))_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13],_cmd));
if(self->heapvars)
(objcT18=(id)self,(*_imp(objcT18,selTransTbl[14]))(objcT18,selTransTbl[14]));
if(o_refcnt)
for(i=0,n=(objcT19=self->locals,(*(unsigned(*)(id,SEL))_imp(objcT19,selTransTbl[7]))(objcT19,selTransTbl[7]));i<n;i++){
id objcT20,objcT21,objcT22,objcT23;

# 207 "compstmt.m"
id x=(objcT20=self->locals,(*(id(*)(id,SEL,unsigned))_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8],i));

if((objcT21=(objcT22=(id)self,(*_imp(objcT22,selTransTbl[15]))(objcT22,selTransTbl[15],x)),(*(BOOL(*)(id,SEL))_imp(objcT21,selTransTbl[10]))(objcT21,selTransTbl[10]))&& !(objcT23=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT23,selTransTbl[16]))(objcT23,selTransTbl[16],x))){
id objcT24;

# 210 "compstmt.m"
(objcT24=(id)self,(*_imp(objcT24,selTransTbl[12]))(objcT24,selTransTbl[12],x));
}
}
curcompound=self->enclosing;
return(id)self;
}

static id i_CompoundStmt_gen(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT25,objcT26,objcT30,objcT31,objcT32;
id objcT33,objcT34,objcT35,objcT42;

# 219 "compstmt.m"
if(self->lbrace)
(objcT25=self->lbrace,(*_imp(objcT25,selTransTbl[17]))(objcT25,selTransTbl[17]));
else
gc('{');
if(self->heapvars||self->tmpvars||self->icaches||(o_refcnt&&self->enclosing==(id)0))
gc('\n');
if(self->needreturnflag)gs("int _returnflag = 0;\n");
if(o_refcnt&&self->enclosing==(id)0&& !(objcT26=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT26,selTransTbl[18]))(objcT26,selTransTbl[18]))){
id objcT27,objcT28;

# 227 "compstmt.m"
(objcT27=self->restype,(*_imp(objcT27,selTransTbl[19]))(objcT27,selTransTbl[19],s_returnval));
if((objcT28=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT28,selTransTbl[20]))(objcT28,selTransTbl[20]))){
id objcT29;
gs("=(");
(objcT29=self->restype,(*_imp(objcT29,selTransTbl[21]))(objcT29,selTransTbl[21]));
gs(")0");
}
gs(";\n");
}
if(self->heapvars)
(objcT30=(id)self,(*_imp(objcT30,selTransTbl[22]))(objcT30,selTransTbl[22]));
if(self->tmpvars)
gvarlist(self->tmpvars,"id",(o_refcnt)?"=(id)0":"");
if(self->icaches)
gvarlist(self->icaches,"static struct objcrt_inlineCache","");
if(self->datadefs)
(objcT31=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT31,selTransTbl[13]))(objcT31,selTransTbl[13],_cmd));
if(self->increfs)
(objcT32=(id)self,(*_imp(objcT32,selTransTbl[23]))(objcT32,selTransTbl[23]));
if(self->initializers)
(objcT33=self->initializers,(*(id(*)(id,SEL,SEL))_imp(objcT33,selTransTbl[13]))(objcT33,selTransTbl[13],_cmd));
if(self->stmts)
(objcT34=self->stmts,(*(id(*)(id,SEL,SEL))_imp(objcT34,selTransTbl[13]))(objcT34,selTransTbl[13],_cmd));
if(self->subblock)
(objcT35=self->subblock,(*_imp(objcT35,selTransTbl[17]))(objcT35,selTransTbl[17]));
if(self->returnlabel){
id objcT36;

# 253 "compstmt.m"
gc('\n');
gs((objcT36=self->returnlabel,(*(STR(*)(id,SEL))_imp(objcT36,selTransTbl[24]))(objcT36,selTransTbl[24])));
gs(":\n");
}
if(self->heapvars){
id objcT37;

# 258 "compstmt.m"
(objcT37=(id)self,(*_imp(objcT37,selTransTbl[25]))(objcT37,selTransTbl[25]));
}
if(o_refcnt){
id objcT38;

# 261 "compstmt.m"
if(self->decrefs)
(objcT38=(id)self,(*_imp(objcT38,selTransTbl[26]))(objcT38,selTransTbl[26]));
if(self->checkreturnflag){
id objcT39,objcT40;

# 264 "compstmt.m"
gf("if (_returnflag) goto %s;\n",(objcT39=(objcT40=self->enclosing,(*_imp(objcT40,selTransTbl[4]))(objcT40,selTransTbl[4])),(*(STR(*)(id,SEL))_imp(objcT39,selTransTbl[24]))(objcT39,selTransTbl[24])));
}
if(self->enclosing==(id)0){
id objcT41;

# 267 "compstmt.m"
if((objcT41=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT41,selTransTbl[18]))(objcT41,selTransTbl[18]))){
gs("return;\n");
}else{
gs("return _returnval;");
}
}
}
if(self->rbrace)
(objcT42=self->rbrace,(*_imp(objcT42,selTransTbl[17]))(objcT42,selTransTbl[17]));
else
gc('}');
return(id)self;
}

# 24 "./shared.m"
static id i_CompoundStmt_enclosing(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
return self->enclosing;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 29 "./shared.m"
static id i_CompoundStmt_addtmpvar_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id tvar)
{
id objcT43,objcT44;

# 31 "./shared.m"
if( !self->tmpvars)self->
tmpvars=(objcT43=OrdCltn,(*_imp(objcT43,selTransTbl[27]))(objcT43,selTransTbl[27]));
(objcT44=self->tmpvars,(*_imp(objcT44,selTransTbl[28]))(objcT44,selTransTbl[28],tvar));
return(id)self;
}

static id i_CompoundStmt_addicache_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id tvar)
{
id objcT45,objcT46;

# 39 "./shared.m"
if( !self->icaches)self->
icaches=(objcT45=OrdCltn,(*_imp(objcT45,selTransTbl[27]))(objcT45,selTransTbl[27]));
(objcT46=self->icaches,(*_imp(objcT46,selTransTbl[28]))(objcT46,selTransTbl[28],tvar));
return(id)self;
}

static id i_CompoundStmt_addincref_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id v)
{
id objcT47,objcT48;

# 47 "./shared.m"
if( !self->increfs)self->
increfs=(objcT47=OrdCltn,(*_imp(objcT47,selTransTbl[27]))(objcT47,selTransTbl[27]));
(objcT48=self->increfs,(*_imp(objcT48,selTransTbl[28]))(objcT48,selTransTbl[28],v));
return(id)self;
}

static id i_CompoundStmt_genincrefs(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT49;

# 55 "./shared.m"
int i,n=(objcT49=self->increfs,(*(unsigned(*)(id,SEL))_imp(objcT49,selTransTbl[7]))(objcT49,selTransTbl[7]));

for(i=0;i<n;i++){
id objcT50,objcT51,objcT52,objcT53,objcT54;

# 58 "./shared.m"
if(self->lbrace)gl((objcT50=self->lbrace,(*(int(*)(id,SEL))_imp(objcT50,selTransTbl[1]))(objcT50,selTransTbl[1])),(objcT51=(objcT52=self->lbrace,(*_imp(objcT52,selTransTbl[2]))(objcT52,selTransTbl[2])),(*(STR(*)(id,SEL))_imp(objcT51,selTransTbl[24]))(objcT51,selTransTbl[24])));
gf("idincref(%s);\n",(objcT53=(objcT54=self->increfs,(*(id(*)(id,SEL,unsigned))_imp(objcT54,selTransTbl[8]))(objcT54,selTransTbl[8],i)),(*(STR(*)(id,SEL))_imp(objcT53,selTransTbl[24]))(objcT53,selTransTbl[24])));
}
gc('\n');
return(id)self;
}

static id i_CompoundStmt_adddecref_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id v)
{
id objcT55,objcT56,objcT57;

# 67 "./shared.m"
if( !self->decrefs)self->
decrefs=(objcT55=OrdCltn,(*_imp(objcT55,selTransTbl[27]))(objcT55,selTransTbl[27]));
(objcT56=self->decrefs,(*_imp(objcT56,selTransTbl[28]))(objcT56,selTransTbl[28],v));

if(curloopcompound&&(id)self!=curloopcompound)
(objcT57=curloopcompound,(*_imp(objcT57,selTransTbl[12]))(objcT57,selTransTbl[12],v));
return(id)self;
}

static id i_CompoundStmt_gendecrefs(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT58;

# 78 "./shared.m"
int i,n=(objcT58=self->decrefs,(*(unsigned(*)(id,SEL))_imp(objcT58,selTransTbl[7]))(objcT58,selTransTbl[7]));

for(i=0;i<n;i++){
id objcT59,objcT60,objcT61,objcT62,objcT63;

# 81 "./shared.m"
char*s=(objcT59=(objcT60=self->decrefs,(*(id(*)(id,SEL,unsigned))_imp(objcT60,selTransTbl[8]))(objcT60,selTransTbl[8],i)),(*(STR(*)(id,SEL))_imp(objcT59,selTransTbl[24]))(objcT59,selTransTbl[24]));

if(self->rbrace)gl((objcT61=self->rbrace,(*(int(*)(id,SEL))_imp(objcT61,selTransTbl[1]))(objcT61,selTransTbl[1])),(objcT62=(objcT63=self->rbrace,(*_imp(objcT63,selTransTbl[2]))(objcT63,selTransTbl[2])),(*(STR(*)(id,SEL))_imp(objcT62,selTransTbl[24]))(objcT62,selTransTbl[24])));
gf("%s=iddecref(%s);\n",s,s);
}
gc('\n');
return(id)self;
}

static id i_CompoundStmt_lookuplocal_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id sym)
{
id objcT64;

# 92 "./shared.m"
return(self->localdic)?(objcT64=self->localdic,(*_imp(objcT64,selTransTbl[29]))(objcT64,selTransTbl[29],sym)):(id)0;
}

# 32 "./../../include/objpak/dictnary.h"
extern id  Dictionary;

# 95 "./shared.m"
static id i_CompoundStmt_deflocal_astype_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id sym,id t)
{
id objcT67,objcT68,objcT69;

# 97 "./shared.m"
if( !self->localdic){
id objcT65,objcT66;
self->
# 98 "./shared.m"
localdic=(objcT65=Dictionary,(*_imp(objcT65,selTransTbl[27]))(objcT65,selTransTbl[27]));self->
locals=(objcT66=OrdCltn,(*_imp(objcT66,selTransTbl[27]))(objcT66,selTransTbl[27]));
}
(objcT67=self->localdic,(*_imp(objcT67,selTransTbl[30]))(objcT67,selTransTbl[30],sym,t));
(objcT68=self->locals,(*_imp(objcT68,selTransTbl[28]))(objcT68,selTransTbl[28],sym));
if(curdef&&((objcT69=curdef,(*(BOOL(*)(id,SEL))_imp(objcT69,selTransTbl[31]))(objcT69,selTransTbl[31])))){
id objcT70,objcT72;

# 104 "./shared.m"
(void)0;
if((objcT70=curclassdef,(*(BOOL(*)(id,SEL,id))_imp(objcT70,selTransTbl[32]))(objcT70,selTransTbl[32],sym))){
id objcT71;

# 106 "./shared.m"
warnat(sym,"definition of local '%s' hides instance variable",(objcT71=sym,(*(STR(*)(id,SEL))_imp(objcT71,selTransTbl[24]))(objcT71,selTransTbl[24])));
}
if((objcT72=curclassdef,(*(BOOL(*)(id,SEL,id))_imp(objcT72,selTransTbl[33]))(objcT72,selTransTbl[33],sym))){
id objcT73;

# 109 "./shared.m"
warnat(sym,"definition of local '%s' hides class variable",(objcT73=sym,(*(STR(*)(id,SEL))_imp(objcT73,selTransTbl[24]))(objcT73,selTransTbl[24])));
}
}
return(id)self;
}

static id i_CompoundStmt_genheapvarptr(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
char*p=self->heapvarptrname;
char*t=self->heapvartypename;

(void)0;

gf("%s *%s=(%s *)OC_Calloc(sizeof(%s));\n",t,p,t,t);
return(id)self;
}

static id i_CompoundStmt_freeheapvarptr(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT74;

# 128 "./shared.m"
char*p=self->heapvarptrname;

gf("if (%s->heaprefcnt-- == 0) {\n",p);
if(o_refcnt)(objcT74=(id)self,(*_imp(objcT74,selTransTbl[34]))(objcT74,selTransTbl[34]));
gf("OC_Free(%s);\n",p);
gs("}\n");

return(id)self;
}

static id i_CompoundStmt_gendecrefsheapvars(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT75;

# 140 "./shared.m"
int i,n=(objcT75=self->heapnames,(*(unsigned(*)(id,SEL))_imp(objcT75,selTransTbl[7]))(objcT75,selTransTbl[7]));
char*hvp=self->heapvarptrname;

for(i=0;i<n;i++){
id objcT76,objcT77,objcT78;

# 144 "./shared.m"
id x=(objcT76=self->heapnames,(*(id(*)(id,SEL,unsigned))_imp(objcT76,selTransTbl[8]))(objcT76,selTransTbl[8],i));
id t=(objcT77=self->heaptypes,(*(id(*)(id,SEL,unsigned))_imp(objcT77,selTransTbl[8]))(objcT77,selTransTbl[8],i));

(void)0;
if((objcT78=t,(*(BOOL(*)(id,SEL))_imp(objcT78,selTransTbl[10]))(objcT78,selTransTbl[10]))){
id objcT79;

# 149 "./shared.m"
char*s=(objcT79=x,(*(STR(*)(id,SEL))_imp(objcT79,selTransTbl[24]))(objcT79,selTransTbl[24]));
gf("%s->%s=iddecref(%s->%s);\n",hvp,s,hvp,s);
}
}
return(id)self;
}

static id i_CompoundStmt_genheapvartype(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT80;

# 158 "./shared.m"
int i,n=(objcT80=self->heapnames,(*(unsigned(*)(id,SEL))_imp(objcT80,selTransTbl[7]))(objcT80,selTransTbl[7]));

if( !n)
return(id)self;
gf("%s {\n",self->heapvartypename);
gs("int heaprefcnt;\n");
for(i=0;i<n;i++){
id objcT81,objcT82,objcT83;

# 165 "./shared.m"
id x=(objcT81=self->heapnames,(*(id(*)(id,SEL,unsigned))_imp(objcT81,selTransTbl[8]))(objcT81,selTransTbl[8],i));
id t=(objcT82=self->heaptypes,(*(id(*)(id,SEL,unsigned))_imp(objcT82,selTransTbl[8]))(objcT82,selTransTbl[8],i));

(void)0;
(objcT83=t,(*_imp(objcT83,selTransTbl[19]))(objcT83,selTransTbl[19],x));
gs(";\n");
}
gs("};\n");
return(id)self;
}

static id i_CompoundStmt_heapvars(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
return(id)0;
}

static BOOL i_CompoundStmt_isheapvar_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id x)
{
id objcT84;

# 183 "./shared.m"
return(self->heapvars)?(objcT84=self->heapvars,(*(BOOL(*)(id,SEL,id))_imp(objcT84,selTransTbl[35]))(objcT84,selTransTbl[35],x)):(BOOL)0;
}

# 36 "./../../include/objpak/set.h"
extern id  Set;

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 186 "./shared.m"
static id i_CompoundStmt_defheapvar_type_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id x,id t)
{
id objcT93;

# 188 "./shared.m"
int i;

if( !self->heapvars){
id objcT85,objcT86,objcT87,objcT88,objcT89;
id objcT90,objcT91,objcT92;
self->
# 191 "./shared.m"
heapvars=(objcT85=Set,(*_imp(objcT85,selTransTbl[27]))(objcT85,selTransTbl[27]));self->
heapnames=(objcT86=OrdCltn,(*_imp(objcT86,selTransTbl[27]))(objcT86,selTransTbl[27]));self->
heaptypes=(objcT87=OrdCltn,(*_imp(objcT87,selTransTbl[27]))(objcT87,selTransTbl[27]));
i=(objcT88=trlunit,(*(int(*)(id,SEL))_imp(objcT88,selTransTbl[36]))(objcT88,selTransTbl[36]));self->
heapvarptrname=(objcT89=(objcT90=String,(*(id(*)(id,SEL,STR,...))_imp(objcT90,selTransTbl[37]))(objcT90,selTransTbl[37],"heapvars%i",i)),(*(STR(*)(id,SEL))_imp(objcT89,selTransTbl[38]))(objcT89,selTransTbl[38]));self->
heapvartypename=(objcT91=(objcT92=String,(*(id(*)(id,SEL,STR,...))_imp(objcT92,selTransTbl[37]))(objcT92,selTransTbl[37],"struct heaptype%i",i)),(*(STR(*)(id,SEL))_imp(objcT91,selTransTbl[38]))(objcT91,selTransTbl[38]));
}
if((objcT93=t,(*(BOOL(*)(id,SEL))_imp(objcT93,selTransTbl[39]))(objcT93,selTransTbl[39]))){
id objcT94;

# 199 "./shared.m"
char*msg="can't use static local variables (%s) from within block";

fatalat(x,msg,(objcT94=x,(*(STR(*)(id,SEL))_imp(objcT94,selTransTbl[24]))(objcT94,selTransTbl[24])));
}else{
id objcT95;

# 203 "./shared.m"
if((objcT95=self->heapvars,(*_imp(objcT95,selTransTbl[40]))(objcT95,selTransTbl[40],x))!=(id)0){
id objcT96,objcT97;

# 204 "./shared.m"
(objcT96=self->heapnames,(*_imp(objcT96,selTransTbl[28]))(objcT96,selTransTbl[28],x));
(objcT97=self->heaptypes,(*_imp(objcT97,selTransTbl[28]))(objcT97,selTransTbl[28],t));
}
}
return(id)self;
}

static char*i_CompoundStmt_heapvarptrname(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
(void)0;
return self->heapvarptrname;
}

static char*i_CompoundStmt_heapvartypename(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
(void)0;
return self->heapvartypename;
}

static id i_CompoundStmt_removeheapvarsfromdatadefs(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT98,objcT110;

# 225 "./shared.m"
int n;

(void)0;self->
initializers=(objcT98=OrdCltn,(*_imp(objcT98,selTransTbl[27]))(objcT98,selTransTbl[27]));

if(self->parmnames){
id objcT99;

# 231 "./shared.m"
n=(objcT99=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT99,selTransTbl[7]))(objcT99,selTransTbl[7]));
while(n--){
id objcT100,objcT101;

# 233 "./shared.m"
id p=(objcT100=self->parmnames,(*(id(*)(id,SEL,unsigned))_imp(objcT100,selTransTbl[8]))(objcT100,selTransTbl[8],n));

if((objcT101=self->heapvars,(*(BOOL(*)(id,SEL,id))_imp(objcT101,selTransTbl[35]))(objcT101,selTransTbl[35],p))){
id objcT102,objcT103,objcT104;

# 236 "./shared.m"
id x=(objcT102=(objcT103=mkidentexpr(p),(*(id(*)(id,SEL,BOOL))_imp(objcT103,selTransTbl[41]))(objcT103,selTransTbl[41],(BOOL)1)),(*_imp(objcT102,selTransTbl[42]))(objcT102,selTransTbl[42]));
id y=mkidentexpr(p);

(objcT104=self->initializers,(*_imp(objcT104,selTransTbl[28]))(objcT104,selTransTbl[28],mkexprstmt(mkassignexpr(x,"=",y))));
}
}
}
if(self->datadefs){
id objcT105;

# 244 "./shared.m"
n=(objcT105=self->datadefs,(*(unsigned(*)(id,SEL))_imp(objcT105,selTransTbl[7]))(objcT105,selTransTbl[7]));
while(n--){
id objcT106,objcT107,objcT108,objcT109;

# 246 "./shared.m"
id def=(objcT106=self->datadefs,(*(id(*)(id,SEL,unsigned))_imp(objcT106,selTransTbl[8]))(objcT106,selTransTbl[8],n));

(objcT107=def,(*_imp(objcT107,selTransTbl[43]))(objcT107,selTransTbl[43],self->heapvars,self->initializers));
if((objcT108=def,(*_imp(objcT108,selTransTbl[44]))(objcT108,selTransTbl[44]))==(id)0)
(objcT109=self->datadefs,(*(id(*)(id,SEL,unsigned))_imp(objcT109,selTransTbl[45]))(objcT109,selTransTbl[45],n));
}
}
if((objcT110=self->datadefs,(*(unsigned(*)(id,SEL))_imp(objcT110,selTransTbl[7]))(objcT110,selTransTbl[7]))==0)self->
datadefs=(id)0;
return(id)self;
}

static id i_CompoundStmt_fcall_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id x)
{
id objcT111,objcT112;

# 260 "./shared.m"
if((objcT111=x,(*(unsigned(*)(id,SEL))_imp(objcT111,selTransTbl[7]))(objcT111,selTransTbl[7]))<(objcT112=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT112,selTransTbl[7]))(objcT112,selTransTbl[7]))){
id objcT113;

# 261 "./shared.m"
return(objcT113=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT113,selTransTbl[46]))(objcT113,selTransTbl[46],"Arguments expected"));
}else{
id objcT114,objcT118,objcT119;

# 263 "./shared.m"
int i,n;
(void)0;
for(i=0,n=(objcT114=self->parmnames,(*(unsigned(*)(id,SEL))_imp(objcT114,selTransTbl[7]))(objcT114,selTransTbl[7]));i<n;i++){
id objcT115,objcT116,objcT117;

# 266 "./shared.m"
(objcT115=topframe,(*_imp(objcT115,selTransTbl[47]))(objcT115,selTransTbl[47],(objcT116=self->parmnames,(*(id(*)(id,SEL,unsigned))_imp(objcT116,selTransTbl[8]))(objcT116,selTransTbl[8],i)),(objcT117=x,(*(id(*)(id,SEL,unsigned))_imp(objcT117,selTransTbl[8]))(objcT117,selTransTbl[8],i))));
}
(objcT118=(id)self,(*_imp(objcT118,selTransTbl[48]))(objcT118,selTransTbl[48]));
if((objcT119=topframe,(*(BOOL(*)(id,SEL))_imp(objcT119,selTransTbl[49]))(objcT119,selTransTbl[49]))){
id objcT120;

# 270 "./shared.m"
return(objcT120=topframe,(*_imp(objcT120,selTransTbl[50]))(objcT120,selTransTbl[50]));
}else{
return(id)0;
}
}
}

# 24 "./stkframe.h"
extern id  Stackframe;

# 277 "./shared.m"
static id i_CompoundStmt_switchOn__(struct CompoundStmt_PRIVATE *self,SEL _cmd,BOOL dosw,id e)
{
id objcT121,objcT122,objcT123,objcT124,objcT132;
id objcT136,objcT137;

# 279 "./shared.m"
int i,n;
BOOL quit=(BOOL)0;
BOOL dobrk=(BOOL)0;
BOOL docont=(BOOL)0;
id frame=(objcT121=(objcT122=Stackframe,(*_imp(objcT122,selTransTbl[51]))(objcT122,selTransTbl[51])),(*_imp(objcT121,selTransTbl[52]))(objcT121,selTransTbl[52],(id)self));
if(self->datadefs)(objcT123=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT123,selTransTbl[13]))(objcT123,selTransTbl[13],selTransTbl[48]));
i=0;
n=(objcT124=self->stmts,(*(unsigned(*)(id,SEL))_imp(objcT124,selTransTbl[7]))(objcT124,selTransTbl[7]));
if(dosw)for(;i<n;i++){
id objcT125,objcT126;

# 288 "./shared.m"
if((objcT125=(objcT126=self->stmts,(*(id(*)(id,SEL,unsigned))_imp(objcT126,selTransTbl[8]))(objcT126,selTransTbl[8],i)),(*(BOOL(*)(id,SEL,id))_imp(objcT125,selTransTbl[53]))(objcT125,selTransTbl[53],e)))break;
}
for(;i<n;i++){
id objcT127,objcT128,objcT129,objcT130,objcT131;

# 291 "./shared.m"
(objcT127=(objcT128=self->stmts,(*(id(*)(id,SEL,unsigned))_imp(objcT128,selTransTbl[8]))(objcT128,selTransTbl[8],i)),(*_imp(objcT127,selTransTbl[48]))(objcT127,selTransTbl[48]));
if((quit=(objcT129=frame,(*(BOOL(*)(id,SEL))_imp(objcT129,selTransTbl[49]))(objcT129,selTransTbl[49]))))break;
if((docont=(objcT130=frame,(*(BOOL(*)(id,SEL))_imp(objcT130,selTransTbl[54]))(objcT130,selTransTbl[54]))))break;
if((dobrk=(objcT131=frame,(*(BOOL(*)(id,SEL))_imp(objcT131,selTransTbl[55]))(objcT131,selTransTbl[55]))))break;
}
(objcT132=Stackframe,(*_imp(objcT132,selTransTbl[56]))(objcT132,selTransTbl[56]));
if(quit){
id objcT133,objcT134,objcT135;

# 298 "./shared.m"
(objcT133=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT133,selTransTbl[57]))(objcT133,selTransTbl[57],(BOOL)1));
(objcT134=topframe,(*_imp(objcT134,selTransTbl[58]))(objcT134,selTransTbl[58],(objcT135=frame,(*_imp(objcT135,selTransTbl[50]))(objcT135,selTransTbl[50]))));
}
if(docont)(objcT136=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT136,selTransTbl[59]))(objcT136,selTransTbl[59],(BOOL)1));
if(dobrk)(objcT137=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT137,selTransTbl[60]))(objcT137,selTransTbl[60],(BOOL)1));
return(id)self;
}

static id i_CompoundStmt_switchOn_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id e)
{
id objcT138;

# 308 "./shared.m"
return(objcT138=(id)self,(*(id(*)(id,SEL,BOOL,id))_imp(objcT138,selTransTbl[61]))(objcT138,selTransTbl[61],(BOOL)1,e));
}

static id i_CompoundStmt_go(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT139;

# 313 "./shared.m"
return(objcT139=(id)self,(*(id(*)(id,SEL,BOOL,id))_imp(objcT139,selTransTbl[61]))(objcT139,selTransTbl[61],(BOOL)0,(id)0));
}

# 283 "compstmt.m"
static id i_CompoundStmt_addheapvarblock_(struct CompoundStmt_PRIVATE *self,SEL _cmd,id c)
{
if(c==(id)self){
return(id)self;
}else{
id objcT140;

# 288 "compstmt.m"
if(self->enclosing)
(objcT140=self->enclosing,(*_imp(objcT140,selTransTbl[62]))(objcT140,selTransTbl[62],c));
return(id)self;
}
}

static id i_CompoundStmt_st80(struct CompoundStmt_PRIVATE *self,SEL _cmd)
{
id objcT141,objcT142,objcT143;

# 296 "compstmt.m"
gc('|');
if(self->datadefs)
(objcT141=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT141,selTransTbl[13]))(objcT141,selTransTbl[13],_cmd));
gc('|');
gc('\n');
if(self->datadefs)
(objcT142=self->datadefs,(*(id(*)(id,SEL,SEL))_imp(objcT142,selTransTbl[13]))(objcT142,selTransTbl[13],selTransTbl[63]));
(objcT143=self->stmts,(*(id(*)(id,SEL,SEL))_imp(objcT143,selTransTbl[13]))(objcT143,selTransTbl[13],_cmd));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _CompoundStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _CompoundStmt_nstDispatchTbl[] ={
{"isbracedgroup",(id (*)())i_CompoundStmt_isbracedgroup},
{"setbracedgroup:",(id (*)())i_CompoundStmt_setbracedgroup_},
{"setreturnflag",(id (*)())i_CompoundStmt_setreturnflag},
{"usereturnflag",(id (*)())i_CompoundStmt_usereturnflag},
{"iscompstmt",(id (*)())i_CompoundStmt_iscompstmt},
{"lineno",(id (*)())i_CompoundStmt_lineno},
{"filename",(id (*)())i_CompoundStmt_filename},
{"lbrace:",(id (*)())i_CompoundStmt_lbrace_},
{"rbrace:",(id (*)())i_CompoundStmt_rbrace_},
{"datadefs:",(id (*)())i_CompoundStmt_datadefs_},
{"stmts:",(id (*)())i_CompoundStmt_stmts_},
{"subblock:",(id (*)())i_CompoundStmt_subblock_},
{"nextreturnlabel",(id (*)())i_CompoundStmt_nextreturnlabel},
{"returnlabel",(id (*)())i_CompoundStmt_returnlabel},
{"lookupparm:",(id (*)())i_CompoundStmt_lookupparm_},
{"synth",(id (*)())i_CompoundStmt_synth},
{"gen",(id (*)())i_CompoundStmt_gen},
{"enclosing",(id (*)())i_CompoundStmt_enclosing},
{"addtmpvar:",(id (*)())i_CompoundStmt_addtmpvar_},
{"addicache:",(id (*)())i_CompoundStmt_addicache_},
{"addincref:",(id (*)())i_CompoundStmt_addincref_},
{"genincrefs",(id (*)())i_CompoundStmt_genincrefs},
{"adddecref:",(id (*)())i_CompoundStmt_adddecref_},
{"gendecrefs",(id (*)())i_CompoundStmt_gendecrefs},
{"lookuplocal:",(id (*)())i_CompoundStmt_lookuplocal_},
{"deflocal:astype:",(id (*)())i_CompoundStmt_deflocal_astype_},
{"genheapvarptr",(id (*)())i_CompoundStmt_genheapvarptr},
{"freeheapvarptr",(id (*)())i_CompoundStmt_freeheapvarptr},
{"gendecrefsheapvars",(id (*)())i_CompoundStmt_gendecrefsheapvars},
{"genheapvartype",(id (*)())i_CompoundStmt_genheapvartype},
{"heapvars",(id (*)())i_CompoundStmt_heapvars},
{"isheapvar:",(id (*)())i_CompoundStmt_isheapvar_},
{"defheapvar:type:",(id (*)())i_CompoundStmt_defheapvar_type_},
{"heapvarptrname",(id (*)())i_CompoundStmt_heapvarptrname},
{"heapvartypename",(id (*)())i_CompoundStmt_heapvartypename},
{"removeheapvarsfromdatadefs",(id (*)())i_CompoundStmt_removeheapvarsfromdatadefs},
{"fcall:",(id (*)())i_CompoundStmt_fcall_},
{"switchOn::",(id (*)())i_CompoundStmt_switchOn__},
{"switchOn:",(id (*)())i_CompoundStmt_switchOn_},
{"go",(id (*)())i_CompoundStmt_go},
{"addheapvarblock:",(id (*)())i_CompoundStmt_addheapvarblock_},
{"st80",(id (*)())i_CompoundStmt_st80},
{(char*)0,(id (*)())0}
};
id CompoundStmt = (id)&_CompoundStmt;
id  *OBJCCLASS_CompoundStmt(void) { return &CompoundStmt; }
struct _SHARED  _CompoundStmt = {
  (id)&__CompoundStmt,
  (id)&_Stmt,
  "CompoundStmt",
  0,
  sizeof(struct CompoundStmt_PRIVATE),
  42,
  _CompoundStmt_nstDispatchTbl,
  41,
  &compstmt_modDesc,
  0,
  (id)0,
  &CompoundStmt,
};
id  OBJCCFUNC_CompoundStmt(void) { return (id)&_CompoundStmt; }
id  OBJCCSUPER_CompoundStmt(void) { return _CompoundStmt.clsSuper; }
struct _SHARED __CompoundStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "CompoundStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _CompoundStmt_clsDispatchTbl,
  34,
  &compstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_CompoundStmt(void) { return (id)&__CompoundStmt; }
id  OBJCMSUPER_CompoundStmt(void) { return __CompoundStmt.clsSuper; }
static char *_selTransTbl[] ={
"setreturnflag",
"lineno",
"filename",
"returnlabel",
"nextreturnlabel",
"restype",
"parmnames",
"size",
"at:",
"lookupparm:",
"isid",
"addincref:",
"adddecref:",
"elementsPerform:",
"removeheapvarsfromdatadefs",
"lookuplocal:",
"isheapvar:",
"gen",
"isvoid",
"gendef:",
"isscalartype",
"genabstrtype",
"genheapvarptr",
"genincrefs",
"str",
"freeheapvarptr",
"gendecrefs",
"new",
"add:",
"atKey:",
"atKey:put:",
"ismethdef",
"isivar:",
"iscvar:",
"gendecrefsheapvars",
"contains:",
"heapvarcount",
"sprintf:",
"strCopy",
"isstatic",
"addNTest:",
"lhsself:",
"synth",
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
"addheapvarblock:",
"st80inits",
0
};
struct modDescriptor compstmt_modDesc = {
  "compstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &CompoundStmt,
  64,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_compstmt(void)
{
  selTransTbl = _selTransTbl;
  return &compstmt_modDesc;
}
int _OBJCPOSTLINK_compstmt = 1;


