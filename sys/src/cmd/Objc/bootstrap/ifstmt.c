# 1 "ifstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_ifstmt(void);
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
extern struct modDescriptor ifstmt_modDesc;

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
# 22 "./ifstmt.h"
struct IfStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./ifstmt.h"
id keyw,expr,stmt;
id ekeyw,estmt;};

# 22 "./ifstmt.h"
extern id  IfStmt;

# 22 "./ifstmt.h"
extern struct _SHARED _IfStmt;
extern struct _SHARED __IfStmt;


# 42 "ifstmt.m"
static id i_IfStmt_keyw_(struct IfStmt_PRIVATE *self,SEL _cmd,id aKeyw)
{self->
keyw=aKeyw;
return(id)self;
}

static id i_IfStmt_expr_(struct IfStmt_PRIVATE *self,SEL _cmd,id anExpr)
{self->
expr=anExpr;
return(id)self;
}

static id i_IfStmt_stmt_(struct IfStmt_PRIVATE *self,SEL _cmd,id aStmt)
{
id objcT0;
self->
# 56 "ifstmt.m"
stmt=aStmt;
if(o_refcnt&& !(objcT0=self->stmt,(*(BOOL(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]))){self->
stmt=mkcompstmt((id)0,(id)0,mklist((id)0,self->stmt),(id)0,(id)0);
}
return(id)self;
}

static id i_IfStmt_ekeyw_(struct IfStmt_PRIVATE *self,SEL _cmd,id eKeyw)
{self->
ekeyw=eKeyw;
return(id)self;
}

static id i_IfStmt_estmt_(struct IfStmt_PRIVATE *self,SEL _cmd,id eStmt)
{
id objcT1;
self->
# 71 "ifstmt.m"
estmt=eStmt;
if(o_refcnt&& !(objcT1=self->estmt,(*(BOOL(*)(id,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]))){self->
estmt=mkcompstmt((id)0,(id)0,mklist((id)0,self->estmt),(id)0,(id)0);
}
return(id)self;
}

static id i_IfStmt_synth(struct IfStmt_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3,objcT4;

# 80 "ifstmt.m"
(objcT2=self->expr,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
(objcT3=self->stmt,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1]));
if(self->estmt)
(objcT4=self->estmt,(*_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1]));
return(id)self;
}

static id i_IfStmt_gen(struct IfStmt_PRIVATE *self,SEL _cmd)
{
id objcT5,objcT6,objcT7,objcT8,objcT9;

# 89 "ifstmt.m"
(objcT5=self->keyw,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]));
gc('(');
(objcT6=self->expr,(*_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2]));
gc(')');
(objcT7=self->stmt,(*_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2]));
if(self->ekeyw)
(objcT8=self->ekeyw,(*_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2]));
if(self->estmt)
(objcT9=self->estmt,(*_imp(objcT9,selTransTbl[2]))(objcT9,selTransTbl[2]));
return(id)self;
}

static id i_IfStmt_st80(struct IfStmt_PRIVATE *self,SEL _cmd)
{
id objcT10,objcT11;

# 103 "ifstmt.m"
gc('(');
(objcT10=self->expr,(*_imp(objcT10,selTransTbl[3]))(objcT10,selTransTbl[3]));
gc(')');
gs("ifTrue:[");
(objcT11=self->stmt,(*_imp(objcT11,selTransTbl[3]))(objcT11,selTransTbl[3]));
gc(']');
if(self->estmt){
id objcT12;

# 110 "ifstmt.m"
gs("ifFalse:[");
(objcT12=self->estmt,(*_imp(objcT12,selTransTbl[3]))(objcT12,selTransTbl[3]));
gc(']');
}
gs(".\n");
return(id)self;
}

# 24 "./scalar.h"
extern id  Scalar;

# 118 "ifstmt.m"
static id i_IfStmt_go(struct IfStmt_PRIVATE *self,SEL _cmd)
{
id objcT13,objcT14,objcT15,objcT16;

# 120 "ifstmt.m"
id e;
if(e=(objcT13=self->expr,(*_imp(objcT13,selTransTbl[4]))(objcT13,selTransTbl[4])), !(((objcT14=e,(*(BOOL(*)(id,SEL,id))_imp(objcT14,selTransTbl[5]))(objcT14,selTransTbl[5],(id)(objcT15=Scalar,(*_imp(objcT15,selTransTbl[6]))(objcT15,selTransTbl[6])))))?(objcT16=e,(*(BOOL(*)(id,SEL))_imp(objcT16,selTransTbl[7]))(objcT16,selTransTbl[7])):((e)?0:1))){
id objcT17;

# 122 "ifstmt.m"
(objcT17=self->stmt,(*_imp(objcT17,selTransTbl[4]))(objcT17,selTransTbl[4]));
}else{
id objcT18;

# 124 "ifstmt.m"
if(self->estmt)(objcT18=self->estmt,(*_imp(objcT18,selTransTbl[4]))(objcT18,selTransTbl[4]));
}
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _IfStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _IfStmt_nstDispatchTbl[] ={
{"keyw:",(id (*)())i_IfStmt_keyw_},
{"expr:",(id (*)())i_IfStmt_expr_},
{"stmt:",(id (*)())i_IfStmt_stmt_},
{"ekeyw:",(id (*)())i_IfStmt_ekeyw_},
{"estmt:",(id (*)())i_IfStmt_estmt_},
{"synth",(id (*)())i_IfStmt_synth},
{"gen",(id (*)())i_IfStmt_gen},
{"st80",(id (*)())i_IfStmt_st80},
{"go",(id (*)())i_IfStmt_go},
{(char*)0,(id (*)())0}
};
id IfStmt = (id)&_IfStmt;
id  *OBJCCLASS_IfStmt(void) { return &IfStmt; }
struct _SHARED  _IfStmt = {
  (id)&__IfStmt,
  (id)&_Stmt,
  "IfStmt",
  0,
  sizeof(struct IfStmt_PRIVATE),
  9,
  _IfStmt_nstDispatchTbl,
  41,
  &ifstmt_modDesc,
  0,
  (id)0,
  &IfStmt,
};
id  OBJCCFUNC_IfStmt(void) { return (id)&_IfStmt; }
id  OBJCCSUPER_IfStmt(void) { return _IfStmt.clsSuper; }
struct _SHARED __IfStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "IfStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _IfStmt_clsDispatchTbl,
  34,
  &ifstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_IfStmt(void) { return (id)&__IfStmt; }
id  OBJCMSUPER_IfStmt(void) { return __IfStmt.clsSuper; }
static char *_selTransTbl[] ={
"iscompstmt",
"synth",
"gen",
"st80",
"go",
"isKindOf:",
"class",
"isZero",
0
};
struct modDescriptor ifstmt_modDesc = {
  "ifstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &IfStmt,
  8,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_ifstmt(void)
{
  selTransTbl = _selTransTbl;
  return &ifstmt_modDesc;
}
int _OBJCPOSTLINK_ifstmt = 1;


