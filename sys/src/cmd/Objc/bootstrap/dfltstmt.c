# 1 "dfltstmt.m"
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
extern struct modDescriptor  *_OBJCBIND_dfltstmt(void);
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
extern struct modDescriptor dfltstmt_modDesc;

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
# 22 "./dfltstmt.h"
struct DefaultStmt_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./dfltstmt.h"
id keyw,stmt;};

# 22 "./dfltstmt.h"
extern id  DefaultStmt;

# 22 "./dfltstmt.h"
extern struct _SHARED _DefaultStmt;
extern struct _SHARED __DefaultStmt;


# 38 "dfltstmt.m"
static id i_DefaultStmt_stmt_(struct DefaultStmt_PRIVATE *self,SEL _cmd,id aStmt)
{
id objcT0;
self->
# 40 "dfltstmt.m"
stmt=aStmt;
if(o_refcnt&& !(objcT0=self->stmt,(*(BOOL(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]))){self->
stmt=mkcompstmt((id)0,(id)0,mklist((id)0,self->stmt),(id)0,(id)0);
}
return(id)self;
}

static id i_DefaultStmt_keyw_(struct DefaultStmt_PRIVATE *self,SEL _cmd,id aKeyw)
{self->
keyw=aKeyw;
return(id)self;
}

static id i_DefaultStmt_synth(struct DefaultStmt_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 55 "dfltstmt.m"
(objcT1=self->stmt,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
return(id)self;
}

static id i_DefaultStmt_gen(struct DefaultStmt_PRIVATE *self,SEL _cmd)
{
id objcT2,objcT3;

# 61 "dfltstmt.m"
(objcT2=self->keyw,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
gc(':');
(objcT3=self->stmt,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
return(id)self;
}

static BOOL i_DefaultStmt_iscaseOf_(struct DefaultStmt_PRIVATE *self,SEL _cmd,id e)
{
return(BOOL)1;
}

static id i_DefaultStmt_go(struct DefaultStmt_PRIVATE *self,SEL _cmd)
{
id objcT4;

# 74 "dfltstmt.m"
return(objcT4=self->stmt,(*_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Stmt;
extern struct _SHARED _Stmt;
extern struct _SHARED __Stmt;
static struct _SLT _DefaultStmt_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _DefaultStmt_nstDispatchTbl[] ={
{"stmt:",(id (*)())i_DefaultStmt_stmt_},
{"keyw:",(id (*)())i_DefaultStmt_keyw_},
{"synth",(id (*)())i_DefaultStmt_synth},
{"gen",(id (*)())i_DefaultStmt_gen},
{"iscaseOf:",(id (*)())i_DefaultStmt_iscaseOf_},
{"go",(id (*)())i_DefaultStmt_go},
{(char*)0,(id (*)())0}
};
id DefaultStmt = (id)&_DefaultStmt;
id  *OBJCCLASS_DefaultStmt(void) { return &DefaultStmt; }
struct _SHARED  _DefaultStmt = {
  (id)&__DefaultStmt,
  (id)&_Stmt,
  "DefaultStmt",
  0,
  sizeof(struct DefaultStmt_PRIVATE),
  6,
  _DefaultStmt_nstDispatchTbl,
  41,
  &dfltstmt_modDesc,
  0,
  (id)0,
  &DefaultStmt,
};
id  OBJCCFUNC_DefaultStmt(void) { return (id)&_DefaultStmt; }
id  OBJCCSUPER_DefaultStmt(void) { return _DefaultStmt.clsSuper; }
struct _SHARED __DefaultStmt = {
  (id)&__Object,
  (id)&__Stmt,
  "DefaultStmt",
  0,
  sizeof(struct _SHARED),
  0,
  _DefaultStmt_clsDispatchTbl,
  34,
  &dfltstmt_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_DefaultStmt(void) { return (id)&__DefaultStmt; }
id  OBJCMSUPER_DefaultStmt(void) { return __DefaultStmt.clsSuper; }
static char *_selTransTbl[] ={
"iscompstmt",
"synth",
"gen",
"go",
0
};
struct modDescriptor dfltstmt_modDesc = {
  "dfltstmt",
  "objc3.3.19",
  0L,
  0,
  0,
  &DefaultStmt,
  4,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_dfltstmt(void)
{
  selTransTbl = _selTransTbl;
  return &dfltstmt_modDesc;
}
int _OBJCPOSTLINK_dfltstmt = 1;


