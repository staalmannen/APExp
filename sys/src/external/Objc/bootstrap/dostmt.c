# 1 "dostmt.m"
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
extern struct modDescriptor  *_OBJCBIND_dostmt(void);
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
extern struct modDescriptor dostmt_modDesc;

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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
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
# 22 "./dostmt.h"
struct DoStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./dostmt.h"
id keyw,stmt,wkeyw,expr;};

# 22 "./dostmt.h"
extern id  DoStmt;

# 22 "./dostmt.h"
extern struct _SHARED _DoStmt;
extern struct _SHARED __DoStmt;


# 42 "dostmt.m"
static id i_DoStmt_keyw_(struct DoStmt_PRIVATE *self,SEL _cmd,id aKeyw)
{self->
keyw=aKeyw;
return(id)self;
}

static id i_DoStmt_stmt_(struct DoStmt_PRIVATE *self,SEL _cmd,id aStmt)
{
id objcT0;
self->
# 50 "dostmt.m"
stmt=aStmt;
if(o_refcnt&& !(objcT0=self->stmt,(*(BOOL(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]))){self->
stmt=mkcompstmt((id)0,(id)0,mklist((id)0,self->stmt),(id)0,(id)0);
}
return(id)self;
}

static id i_DoStmt_wkeyw_(struct DoStmt_PRIVATE *self,SEL _cmd,id wKeyw)
{self->
wkeyw=wKeyw;
return(id)self;
}

static id i_DoStmt_expr_(struct DoStmt_PRIVATE *self,SEL _cmd,id anExpr)
{self->
expr=anExpr;
return(id)self;
}

static id i_DoStmt_synth(struct DoStmt_PRIVATE *self,SEL _cmd)
{
id objcT1,objcT2;

# 71 "dostmt.m"
(objcT1=self->stmt,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
if(o_refcnt)
curloopcompound=self->stmt;
(objcT2=self->expr,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
curloopcompound=(id)0;
return(id)self;
}

static id i_DoStmt_gen(struct DoStmt_PRIVATE *self,SEL _cmd)
{
id objcT3,objcT4,objcT5,objcT6;

# 81 "dostmt.m"
(objcT3=self->keyw,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
(objcT4=self->stmt,(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2]));
(objcT5=self->wkeyw,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]));
gc('(');
(objcT6=self->expr,(*_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2]));
gc(')');
gc(';');
return(id)self;
}

static id i_DoStmt_st80(struct DoStmt_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8,objcT9;

# 93 "dostmt.m"
(objcT7=self->stmt,(*_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3]));
gc('[');
(objcT8=self->expr,(*_imp(objcT8,selTransTbl[3]))(objcT8,selTransTbl[3]));
gs("]whileTrue:[\n");
(objcT9=self->stmt,(*_imp(objcT9,selTransTbl[3]))(objcT9,selTransTbl[3]));
gc(']');
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 102 "dostmt.m"
static id i_DoStmt_go(struct DoStmt_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14,objcT15,objcT16,objcT17;

# 104 "dostmt.m"
id e;
do{
id objcT10,objcT11,objcT12;

# 106 "dostmt.m"
(objcT10=self->stmt,(*_imp(objcT10,selTransTbl[4]))(objcT10,selTransTbl[4]));
if((objcT11=topframe,(*(BOOL(*)(id,SEL))_imp(objcT11,selTransTbl[5]))(objcT11,selTransTbl[5])))break;
(objcT12=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT12,selTransTbl[6]))(objcT12,selTransTbl[6],(BOOL)0));
}while(e=(objcT13=self->expr,(*_imp(objcT13,selTransTbl[4]))(objcT13,selTransTbl[4])), !(((objcT14=e,(*(BOOL(*)(id,SEL,id))_imp(objcT14,selTransTbl[7]))(objcT14,selTransTbl[7],(id)(objcT15=Scalar,(*_imp(objcT15,selTransTbl[8]))(objcT15,selTransTbl[8])))))?(objcT16=e,(*(BOOL(*)(id,SEL))_imp(objcT16,selTransTbl[9]))(objcT16,selTransTbl[9])):((e)?0:1)));
(objcT17=topframe,(*(id(*)(id,SEL,BOOL))_imp(objcT17,selTransTbl[10]))(objcT17,selTransTbl[10],(BOOL)0));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _DoStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _DoStmt_nstDispatchTbl[] ={
{"keyw:",(id (*)())i_DoStmt_keyw_},
{"stmt:",(id (*)())i_DoStmt_stmt_},
{"wkeyw:",(id (*)())i_DoStmt_wkeyw_},
{"expr:",(id (*)())i_DoStmt_expr_},
{"synth",(id (*)())i_DoStmt_synth},
{"gen",(id (*)())i_DoStmt_gen},
{"st80",(id (*)())i_DoStmt_st80},
{"go",(id (*)())i_DoStmt_go},
{(char*)0,(id (*)())0}
};
id DoStmt = (id)&_DoStmt;
id  *OBJCCLASS_DoStmt(void) { return &DoStmt; }
struct _SHARED  _DoStmt = {
  (id)&__DoStmt,
  (id)&_Stmt,
  "DoStmt",
  0,
  sizeof(struct DoStmt_PRIVATE),
  8,
  _DoStmt_nstDispatchTbl,
  41,
  &dostmt_modDesc,
  0,
  (id)0,
  &DoStmt,
};
id  OBJCCFUNC_DoStmt(void) { return (id)&_DoStmt; }
id  OBJCCSUPER_DoStmt(void) { return _DoStmt.clsSuper; }
struct _SHARED __DoStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "DoStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _DoStmt_clsDispatchTbl,
  34,
  &dostmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_DoStmt(void) { return (id)&__DoStmt; }
id  OBJCMSUPER_DoStmt(void) { return __DoStmt.clsSuper; }
static char *_selTransTbl[] ={
"iscompstmt",
"synth",
"gen",
"st80",
"go",
"breakframe",
"contframe:",
"isKindOf:",
"class",
"isZero",
"breakframe:",
0
};
struct modDescriptor dostmt_modDesc = {
  "dostmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &DoStmt,
  11,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_dostmt(void)
{
  selTransTbl = _selTransTbl;
  return &dostmt_modDesc;
}
int _OBJCPOSTLINK_dostmt = 1;


