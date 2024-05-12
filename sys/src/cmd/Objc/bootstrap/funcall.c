# 1 "funcall.m"
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
extern struct modDescriptor  *_OBJCBIND_funcall(void);
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
extern struct modDescriptor funcall_modDesc;

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

# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 28 "./../../include/objpak/idarray.h"
typedef struct idary
{
int capacity;
id*ptr;
}*
idary_t;
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
# 22 "./compstmt.h"
extern id curcompound;
extern id curloopcompound;
# 22 "./trlunit.h"
extern id trlunit;
# 22 "./def.h"
extern id curdef;
# 22 "./funcall.h"
struct FunctionCall_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 31 "./expr.h"
id type;
# 24 "./funcall.h"
id funname,funargs;
id refvar;};

# 22 "./funcall.h"
extern id  FunctionCall;

# 22 "./funcall.h"
extern struct _SHARED _FunctionCall;
extern struct _SHARED __FunctionCall;


# 46 "funcall.m"
static id i_FunctionCall_funname_(struct FunctionCall_PRIVATE *self,SEL _cmd,id aRcvr)
{self->
funname=aRcvr;
return(id)self;
}

static id i_FunctionCall_funargs_(struct FunctionCall_PRIVATE *self,SEL _cmd,id args)
{self->
funargs=args;
return(id)self;
}

static int i_FunctionCall_lineno(struct FunctionCall_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 60 "funcall.m"
return(objcT0=self->funname,(*(int(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
}

static id i_FunctionCall_filename(struct FunctionCall_PRIVATE *self,SEL _cmd)
{
id objcT1;

# 65 "funcall.m"
return(objcT1=self->funname,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
}

static id i_FunctionCall_gen(struct FunctionCall_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 70 "funcall.m"
if(self->refvar){
id objcT2,objcT3,objcT4,objcT5;

# 71 "funcall.m"
gl((objcT2=(id)self,(*(int(*)(id,SEL))_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0])),(objcT3=(objcT4=(id)self,(*_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1])),(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2])));
gc('(');
gs((objcT5=self->refvar,(*(STR(*)(id,SEL))_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2])));
gc('=');
}
(objcT6=self->funname,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));
gc('(');
if(self->funargs)
gcommalist(self->funargs);
gc(')');
if(self->refvar)gc(')');
return(id)self;
}

static id i_FunctionCall_typesynth(struct FunctionCall_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;
self->
# 87 "funcall.m"
type=(objcT7=self->funname,(*_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4]));self->
type=(objcT8=self->type,(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
if( !self->type){
warn("can't make function call to this type of object");self->
type=t_int;
}
return(id)self;
}

static id i_FunctionCall_synth(struct FunctionCall_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10,objcT11,objcT12;

# 98 "funcall.m"
(objcT9=self->funname,(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6]));
if(self->funargs)
(objcT10=self->funargs,(*(id(*)(id,SEL,SEL))_imp(objcT10,selTransTbl[7]))(objcT10,selTransTbl[7],_cmd));
if(o_refcnt&&(objcT11=(objcT12=(id)self,(*_imp(objcT12,selTransTbl[4]))(objcT12,selTransTbl[4])),(*(BOOL(*)(id,SEL))_imp(objcT11,selTransTbl[8]))(objcT11,selTransTbl[8]))){
id objcT13,objcT14,objcT15;
self->
# 102 "funcall.m"
refvar=(objcT13=trlunit,(*_imp(objcT13,selTransTbl[9]))(objcT13,selTransTbl[9]));
(objcT14=curcompound,(*_imp(objcT14,selTransTbl[10]))(objcT14,selTransTbl[10],self->refvar));
(objcT15=curcompound,(*_imp(objcT15,selTransTbl[11]))(objcT15,selTransTbl[11],self->refvar));
}
return(id)self;
}

# 35 "./../../include/objpak/idarray.h"
extern id  IdArray;

# 109 "funcall.m"
static id i_FunctionCall_go(struct FunctionCall_PRIVATE *self,SEL _cmd)
{
id objcT16,objcT17;

# 111 "funcall.m"
id args;
int i,n;
id fdef=(objcT16=self->funname,(*_imp(objcT16,selTransTbl[12]))(objcT16,selTransTbl[12]));
if((objcT17=fdef,(*(BOOL(*)(id,SEL))_imp(objcT17,selTransTbl[13]))(objcT17,selTransTbl[13]))){
id objcT18,objcT19,objcT23;

# 115 "funcall.m"
n=(objcT18=self->funargs,(*(unsigned(*)(id,SEL))_imp(objcT18,selTransTbl[14]))(objcT18,selTransTbl[14]));
args=(objcT19=IdArray,(*(id(*)(id,SEL,unsigned))_imp(objcT19,selTransTbl[15]))(objcT19,selTransTbl[15],n));
for(i=0;i<n;i++){
id objcT20,objcT21,objcT22;

# 118 "funcall.m"
(objcT20=args,(*(id(*)(id,SEL,unsigned,id))_imp(objcT20,selTransTbl[16]))(objcT20,selTransTbl[16],i,(objcT21=(objcT22=self->funargs,(*(id(*)(id,SEL,unsigned))_imp(objcT22,selTransTbl[17]))(objcT22,selTransTbl[17],i)),(*_imp(objcT21,selTransTbl[12]))(objcT21,selTransTbl[12]))));
}
return(objcT23=fdef,(*_imp(objcT23,selTransTbl[18]))(objcT23,selTransTbl[18],args));
}else{
id objcT24;

# 122 "funcall.m"
return(objcT24=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT24,selTransTbl[19]))(objcT24,selTransTbl[19],"Object is not a function name"));
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Expr;
extern struct _SHARED _Expr;
extern struct _SHARED __Expr;
static struct _SLT _FunctionCall_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _FunctionCall_nstDispatchTbl[] ={
{"funname:",(id (*)())i_FunctionCall_funname_},
{"funargs:",(id (*)())i_FunctionCall_funargs_},
{"lineno",(id (*)())i_FunctionCall_lineno},
{"filename",(id (*)())i_FunctionCall_filename},
{"gen",(id (*)())i_FunctionCall_gen},
{"typesynth",(id (*)())i_FunctionCall_typesynth},
{"synth",(id (*)())i_FunctionCall_synth},
{"go",(id (*)())i_FunctionCall_go},
{(char*)0,(id (*)())0}
};
id FunctionCall = (id)&_FunctionCall;
id  *OBJCCLASS_FunctionCall(void) { return &FunctionCall; }
struct _SHARED  _FunctionCall = {
  (id)&__FunctionCall,
  (id)&_Expr,
  "FunctionCall",
  0,
  sizeof(struct FunctionCall_PRIVATE),
  8,
  _FunctionCall_nstDispatchTbl,
  41,
  &funcall_modDesc,
  0,
  (id)0,
  &FunctionCall,
};
id  OBJCCFUNC_FunctionCall(void) { return (id)&_FunctionCall; }
id  OBJCCSUPER_FunctionCall(void) { return _FunctionCall.clsSuper; }
struct _SHARED __FunctionCall = {
  (id)&__Object,
  (id)&__Expr,
  "FunctionCall",
  0,
  sizeof(struct _SHARED),
  0,
  _FunctionCall_clsDispatchTbl,
  34,
  &funcall_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_FunctionCall(void) { return (id)&__FunctionCall; }
id  OBJCMSUPER_FunctionCall(void) { return __FunctionCall.clsSuper; }
static char *_selTransTbl[] ={
"lineno",
"filename",
"str",
"gen",
"type",
"funcall",
"synth",
"elementsPerform:",
"isid",
"gettmpvar",
"addtmpvar:",
"adddecref:",
"go",
"isfundef",
"size",
"new:",
"at:put:",
"at:",
"fcall:",
"error:",
0
};
struct modDescriptor funcall_modDesc = {
  "funcall",
  "objc3.3.19",
  0L,
  0,
  0,
  &FunctionCall,
  20,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_funcall(void)
{
  selTransTbl = _selTransTbl;
  return &funcall_modDesc;
}
int _OBJCPOSTLINK_funcall = 1;


