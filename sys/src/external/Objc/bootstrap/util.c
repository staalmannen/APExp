# 1 "util.m"
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
extern struct modDescriptor  *_OBJCBIND_util(void);
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
extern struct modDescriptor util_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//ctype.h"
#include <ctype.h>

# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

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
# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
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
# 22 "./msgxpr.h"
extern id msgwraps;
# 22 "./blockxpr.h"
extern id curcompound;
# 22 "./structsp.h"
extern id curstruct;
# 22 "./def.h"
extern id curdef;
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
# 22 "./trlunit.h"
extern id trlunit;

# 111 "util.m"
void
procextdef(id def)
{
id objcT0,objcT1,objcT2;

# 114 "util.m"
(objcT0=def,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
if(o_outputcode)
(objcT1=def,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]));
if(o_st80)
(objcT2=def,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));
}

void
finclassdef(void)
{
if(curclassdef){
id objcT3,objcT6;

# 125 "util.m"
if((objcT3=curclassdef,(*(int(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3]))){
if(o_filer){
id objcT4;

# 127 "util.m"
(objcT4=curclassdef,(*_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));
}
if(o_refcnt){
id objcT5;

# 130 "util.m"
(objcT5=curclassdef,(*_imp(objcT5,selTransTbl[5]))(objcT5,selTransTbl[5]));
}
}
if(o_warnmissingmethods&&(objcT6=curclassdef,(*(BOOL(*)(id,SEL))_imp(objcT6,selTransTbl[6]))(objcT6,selTransTbl[6]))){
id objcT7;

# 134 "util.m"
(objcT7=curclassdef,(*_imp(objcT7,selTransTbl[7]))(objcT7,selTransTbl[7]));
}
curclassdef=(id)0;
}else{
fatal("illegal end of class definition.");
}
}

FILE*
openfile(STR name,STR modfs)
{
FILE*f;

if((f=fopen(name,modfs))==NULL){
fprintf(stderr,"objc1: Unable to open %s\n",name);
exit(1);
}
return f;
}

FILE*
reopenfile(STR name,STR modfs,FILE*of)
{
FILE*f;

if((f=freopen(name,modfs,of))==NULL){
fprintf(stderr,"objc1: Unable to open %s\n",name);
exit(1);
}
return f;
}

static char*
setinlineno(char*s)
{
char*p=s;
int c,n=0;

while((c= *p++)&&'0'<=c&&c<='9'){
n=n*10+(c-'0');
}

inlineno=n;
return p-1;
}

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 180 "util.m"
static BOOL
setinfilename(char*s)
{
char*p=s;
int c,n=0;

while((c= *p++)&&c!='"')
n++;


if(c=='"'){
id objcT8;

# 191 "util.m"
infilename=(objcT8=String,(*(id(*)(id,SEL,STR,int))_imp(objcT8,selTransTbl[8]))(objcT8,selTransTbl[8],s,n));
return(BOOL)1;
}else{
return(BOOL)0;
}
}

static BOOL
isline(char*s)
{
int c;
char*p=s;


c= *p++;
if(c=='#'){
c= *p++;
}else{
return(BOOL)0;
}


while(c&&(c==' '||c=='\t'))
c= *p++;


if(c=='l'){
char*key="ine";

if(strncmp(p,key,strlen(key))==0){
p+=strlen(key);
c= *p++;
}else{
return(BOOL)0;
}
}

while(c&&(c==' '||c=='\t'))
c= *p++;


if(c&&'0'<=c&&c<='9'){
p=setinlineno(p-1);
c= *p++;
}else{
return(BOOL)0;
}


while(c&&(c==' '||c=='\t'))
c= *p++;


if(c&&c=='"'){
return setinfilename(p);

}else{


return(BOOL)1;
}
}

# 257 "util.m"
static BOOL
ispragma(char*s)
{
id objcT9,objcT10;

# 260 "util.m"
char*t;
id x=(objcT9=String,(*(id(*)(id,SEL,STR))_imp(objcT9,selTransTbl[9]))(objcT9,selTransTbl[9],s));
char*sep=" #/\t\n\r";

t=strtok((objcT10=x,(*(STR(*)(id,SEL))_imp(objcT10,selTransTbl[10]))(objcT10,selTransTbl[10])),sep);
if(strcmp(t,"pragma")!=0)return(BOOL)0;
if((t=strtok(NULL,sep))==NULL)return(BOOL)0;

if(strcmp(t,"OCbuiltInFctn")==0){
definebuiltinfun(strtok(NULL,sep));
return(BOOL)1;
}
if(strcmp(t,"OCbuiltInVar")==0){
definebuiltinvar(strtok(NULL,sep));
return(BOOL)1;
}
if(strcmp(t,"OCbuiltInType")==0){
definebuiltintype(strtok(NULL,sep));
return(BOOL)1;
}
if(strcmp(t,"OCRefCnt")==0){
o_refcnt=pragmatoggle(strtok(NULL,sep));
return(BOOL)1;
}
if(strcmp(t,"OCInlineCache")==0){
o_inlinecache=pragmatoggle(strtok(NULL,sep));
return(BOOL)1;
}
if(strcmp(t,"token")==0){
if((t=strtok(NULL,sep))==NULL)return(BOOL)0;


if(strcmp(t,"TYPE")==0){
definebuiltintype(strtok(NULL,sep));
return(BOOL)0;
}


if(strcmp(t,"VARIETY")==0){
if((t=strtok(NULL,sep))==NULL)return(BOOL)0;

if(strcmp(t,"signed")==0||strcmp(t,"unsigned")==0){
if((t=strtok(NULL,sep))==NULL)return(BOOL)0;
}

definebuiltintype(t);
return(BOOL)0;
}


if(strcmp(t,"PROC")==0){

while(1){
char*s;
if((s=strtok(NULL," \t\n\r"))==NULL)return(BOOL)0;
if(strcmp(s,"#")==0)break;
t=s;
}
definebuiltinfun(t);
return(BOOL)0;
}


return(BOOL)0;
}
return(BOOL)0;
}

# 22 "./cppdirec.h"
extern id  CppDirective;

# 328 "util.m"
id
mkcppdirect(char*s)
{
id objcT11;

# 331 "util.m"
id r;
int n;
char*t;

if(isline(s))
return(id)0;
if(ispragma(s))
return(id)0;


t="#printLine ";
n=strlen(t);
if(strncmp(s,t,n)==0)
s+=n;
t="#pragma printLine ";
n=strlen(t);
if(strncmp(s,t,n)==0)
s+=n;

t="#pragma\tprintLine ";
n=strlen(t);
if(strncmp(s,t,n)==0)
s+=n;

r=(objcT11=CppDirective,(*(id(*)(id,SEL,char*,int,id))_imp(objcT11,selTransTbl[11]))(objcT11,selTransTbl[11],s,inlineno,infilename));
return r;
}

# 22 "./exprstmt.h"
extern id  ExprStmt;

# 359 "util.m"
id
mkexprstmt(id expr)
{
id objcT12,objcT13;

# 362 "util.m"
id r=(objcT12=ExprStmt,(*_imp(objcT12,selTransTbl[12]))(objcT12,selTransTbl[12]));
(objcT13=r,(*_imp(objcT13,selTransTbl[13]))(objcT13,selTransTbl[13],expr));
return r;
}

id
mkexprstmtx(id expr)
{
id objcT14,objcT15,objcT16;

# 370 "util.m"
id r=(objcT14=ExprStmt,(*_imp(objcT14,selTransTbl[12]))(objcT14,selTransTbl[12]));
(objcT15=r,(*_imp(objcT15,selTransTbl[13]))(objcT15,selTransTbl[13],expr));
(objcT16=r,(*(id(*)(id,SEL,BOOL))_imp(objcT16,selTransTbl[14]))(objcT16,selTransTbl[14],(BOOL)1));
return r;
}

# 22 "./lblstmt.h"
extern id  LabeledStmt;

# 376 "util.m"
id
mklabeledstmt(id label,id stmt)
{
id objcT17,objcT18,objcT19;

# 379 "util.m"
id r=(objcT17=LabeledStmt,(*_imp(objcT17,selTransTbl[12]))(objcT17,selTransTbl[12]));

(objcT18=r,(*_imp(objcT18,selTransTbl[15]))(objcT18,selTransTbl[15],label));
(objcT19=r,(*_imp(objcT19,selTransTbl[16]))(objcT19,selTransTbl[16],stmt));
return r;
}

# 22 "./casestmt.h"
extern id  CaseStmt;

# 386 "util.m"
id
mkcasestmt(id keyw,id expr,id stmt)
{
id objcT20,objcT21,objcT22,objcT23;

# 389 "util.m"
id r=(objcT20=CaseStmt,(*_imp(objcT20,selTransTbl[12]))(objcT20,selTransTbl[12]));

(objcT21=r,(*_imp(objcT21,selTransTbl[17]))(objcT21,selTransTbl[17],keyw));
(objcT22=r,(*_imp(objcT22,selTransTbl[13]))(objcT22,selTransTbl[13],expr));
(objcT23=r,(*_imp(objcT23,selTransTbl[16]))(objcT23,selTransTbl[16],stmt));
return r;
}

# 22 "./dfltstmt.h"
extern id  DefaultStmt;

# 397 "util.m"
id
mkdefaultstmt(id keyw,id stmt)
{
id objcT24,objcT25,objcT26;

# 400 "util.m"
id r=(objcT24=DefaultStmt,(*_imp(objcT24,selTransTbl[12]))(objcT24,selTransTbl[12]));

(objcT25=r,(*_imp(objcT25,selTransTbl[17]))(objcT25,selTransTbl[17],keyw));
(objcT26=r,(*_imp(objcT26,selTransTbl[16]))(objcT26,selTransTbl[16],stmt));
return r;
}

# 22 "./ifstmt.h"
extern id  IfStmt;

# 407 "util.m"
id
mkifstmt(id keyw,id expr,id stmt)
{
id objcT27,objcT28,objcT29,objcT30;

# 410 "util.m"
id r=(objcT27=IfStmt,(*_imp(objcT27,selTransTbl[12]))(objcT27,selTransTbl[12]));

(objcT28=r,(*_imp(objcT28,selTransTbl[17]))(objcT28,selTransTbl[17],keyw));
(objcT29=r,(*_imp(objcT29,selTransTbl[13]))(objcT29,selTransTbl[13],expr));
(objcT30=r,(*_imp(objcT30,selTransTbl[16]))(objcT30,selTransTbl[16],stmt));
return r;
}

id
mkifelsestmt(id keyw,id expr,id stmt,id ekeyw,id estmt)
{
id objcT31,objcT32,objcT33,objcT34,objcT35;
id objcT36;

# 421 "util.m"
id r=(objcT31=IfStmt,(*_imp(objcT31,selTransTbl[12]))(objcT31,selTransTbl[12]));

(objcT32=r,(*_imp(objcT32,selTransTbl[17]))(objcT32,selTransTbl[17],keyw));
(objcT33=r,(*_imp(objcT33,selTransTbl[13]))(objcT33,selTransTbl[13],expr));
(objcT34=r,(*_imp(objcT34,selTransTbl[16]))(objcT34,selTransTbl[16],stmt));
(objcT35=r,(*_imp(objcT35,selTransTbl[18]))(objcT35,selTransTbl[18],ekeyw));
(objcT36=r,(*_imp(objcT36,selTransTbl[19]))(objcT36,selTransTbl[19],estmt));
return r;
}

# 22 "./switstmt.h"
extern id  SwitchStmt;

# 431 "util.m"
id
mkswitchstmt(id keyw,id expr,id stmt)
{
id objcT37,objcT38,objcT39,objcT40;

# 434 "util.m"
id r=(objcT37=SwitchStmt,(*_imp(objcT37,selTransTbl[12]))(objcT37,selTransTbl[12]));

(objcT38=r,(*_imp(objcT38,selTransTbl[17]))(objcT38,selTransTbl[17],keyw));
(objcT39=r,(*_imp(objcT39,selTransTbl[13]))(objcT39,selTransTbl[13],expr));
(objcT40=r,(*_imp(objcT40,selTransTbl[16]))(objcT40,selTransTbl[16],stmt));
return r;
}

# 22 "./whilstmt.h"
extern id  WhileStmt;

# 442 "util.m"
id
mkwhilestmt(id keyw,id expr,id stmt)
{
id objcT41,objcT42,objcT43,objcT44;

# 445 "util.m"
id r=(objcT41=WhileStmt,(*_imp(objcT41,selTransTbl[12]))(objcT41,selTransTbl[12]));

(objcT42=r,(*_imp(objcT42,selTransTbl[17]))(objcT42,selTransTbl[17],keyw));
(objcT43=r,(*_imp(objcT43,selTransTbl[13]))(objcT43,selTransTbl[13],expr));
(objcT44=r,(*_imp(objcT44,selTransTbl[16]))(objcT44,selTransTbl[16],stmt));
return r;
}

# 22 "./dostmt.h"
extern id  DoStmt;

# 453 "util.m"
id
mkdostmt(id keyw,id stmt,id wkeyw,id expr)
{
id objcT45,objcT46,objcT47,objcT48,objcT49;

# 456 "util.m"
id r=(objcT45=DoStmt,(*_imp(objcT45,selTransTbl[12]))(objcT45,selTransTbl[12]));

(objcT46=r,(*_imp(objcT46,selTransTbl[17]))(objcT46,selTransTbl[17],keyw));
(objcT47=r,(*_imp(objcT47,selTransTbl[16]))(objcT47,selTransTbl[16],stmt));
(objcT48=r,(*_imp(objcT48,selTransTbl[20]))(objcT48,selTransTbl[20],wkeyw));
(objcT49=r,(*_imp(objcT49,selTransTbl[13]))(objcT49,selTransTbl[13],expr));
return r;
}

# 22 "./forstmt.h"
extern id  ForStmt;

# 465 "util.m"
id
mkforstmt(id keyw,id a,id b,id c,id stmt)
{
id objcT50,objcT51,objcT52,objcT53;

# 468 "util.m"
id r=(objcT50=ForStmt,(*_imp(objcT50,selTransTbl[12]))(objcT50,selTransTbl[12]));

(objcT51=r,(*_imp(objcT51,selTransTbl[17]))(objcT51,selTransTbl[17],keyw));
(objcT52=r,(*_imp(objcT52,selTransTbl[21]))(objcT52,selTransTbl[21],a,b,c));
(objcT53=r,(*_imp(objcT53,selTransTbl[16]))(objcT53,selTransTbl[16],stmt));
return r;
}

# 22 "./gotostmt.h"
extern id  GotoStmt;

# 476 "util.m"
id
mkgotostmt(id keyw,id label)
{
id objcT54,objcT55,objcT56;

# 479 "util.m"
id r=(objcT54=GotoStmt,(*_imp(objcT54,selTransTbl[12]))(objcT54,selTransTbl[12]));

(objcT55=r,(*_imp(objcT55,selTransTbl[17]))(objcT55,selTransTbl[17],keyw));
(objcT56=r,(*_imp(objcT56,selTransTbl[15]))(objcT56,selTransTbl[15],label));
return r;
}

# 22 "./contstmt.h"
extern id  ContinueStmt;

# 486 "util.m"
id
mkcontinuestmt(id keyw)
{
id objcT57,objcT58;

# 489 "util.m"
id r=(objcT57=ContinueStmt,(*_imp(objcT57,selTransTbl[12]))(objcT57,selTransTbl[12]));

(objcT58=r,(*_imp(objcT58,selTransTbl[17]))(objcT58,selTransTbl[17],keyw));
return r;
}

id
mkbreakstmt(id keyw)
{
return mkcontinuestmt(keyw);
}

# 22 "./rtrnstmt.h"
extern id  ReturnStmt;

# 501 "util.m"
id
mkreturnstmt(id keyw,id expr)
{
id objcT59,objcT60,objcT61;

# 504 "util.m"
id r=(objcT59=ReturnStmt,(*_imp(objcT59,selTransTbl[12]))(objcT59,selTransTbl[12]));

(objcT60=r,(*_imp(objcT60,selTransTbl[17]))(objcT60,selTransTbl[17],keyw));
(objcT61=r,(*_imp(objcT61,selTransTbl[13]))(objcT61,selTransTbl[13],expr));
return r;
}

id
mkreturnx(id x)
{
id objcT62,objcT63;

# 514 "util.m"
return(objcT62=(objcT63=ReturnStmt,(*_imp(objcT63,selTransTbl[12]))(objcT63,selTransTbl[12])),(*_imp(objcT62,selTransTbl[13]))(objcT62,selTransTbl[13],x));
}

# 22 "./castxpr.h"
extern id  CastExpr;

# 517 "util.m"
id
mkcastexpr(id a,id b)
{
id objcT64,objcT65,objcT66;

# 520 "util.m"
id r=(objcT64=CastExpr,(*_imp(objcT64,selTransTbl[12]))(objcT64,selTransTbl[12]));

(objcT65=r,(*_imp(objcT65,selTransTbl[22]))(objcT65,selTransTbl[22],a));
(objcT66=r,(*_imp(objcT66,selTransTbl[13]))(objcT66,selTransTbl[13],b));
return r;
}

# 22 "./condxpr.h"
extern id  CondExpr;

# 527 "util.m"
id
mkcondexpr(id a,id b,id c)
{
id objcT67,objcT68,objcT69,objcT70;

# 530 "util.m"
id r=(objcT67=CondExpr,(*_imp(objcT67,selTransTbl[12]))(objcT67,selTransTbl[12]));

(objcT68=r,(*_imp(objcT68,selTransTbl[13]))(objcT68,selTransTbl[13],a));
(objcT69=r,(*_imp(objcT69,selTransTbl[23]))(objcT69,selTransTbl[23],b));
(objcT70=r,(*_imp(objcT70,selTransTbl[24]))(objcT70,selTransTbl[24],c));
return r;
}

# 22 "./unyxpr.h"
extern id  UnaryExpr;

# 538 "util.m"
id
mkunaryexpr(STR op,id a)
{
id objcT71,objcT72,objcT73;

# 541 "util.m"
id r=(objcT71=UnaryExpr,(*_imp(objcT71,selTransTbl[12]))(objcT71,selTransTbl[12]));

(objcT72=r,(*(id(*)(id,SEL,STR))_imp(objcT72,selTransTbl[25]))(objcT72,selTransTbl[25],op));
(objcT73=r,(*_imp(objcT73,selTransTbl[13]))(objcT73,selTransTbl[13],a));
return r;
}

# 22 "./deref.h"
extern id  Dereference;

# 548 "util.m"
id
mkdereference(id a)
{
id objcT74,objcT75;

# 551 "util.m"
id r=(objcT74=Dereference,(*_imp(objcT74,selTransTbl[12]))(objcT74,selTransTbl[12]));

(objcT75=r,(*_imp(objcT75,selTransTbl[13]))(objcT75,selTransTbl[13],a));
return r;
}

# 22 "./sizeof.h"
extern id  SizeOf;

# 557 "util.m"
id
mksizeof(id a)
{
id objcT76,objcT77;

# 560 "util.m"
id r=(objcT76=SizeOf,(*_imp(objcT76,selTransTbl[12]))(objcT76,selTransTbl[12]));

(objcT77=r,(*_imp(objcT77,selTransTbl[13]))(objcT77,selTransTbl[13],a));
return r;
}

# 22 "./typeof.h"
extern id  TypeOf;

# 566 "util.m"
id
mktypeof(id kw,id a)
{
id objcT78,objcT79,objcT80;

# 569 "util.m"
id r=(objcT78=TypeOf,(*_imp(objcT78,selTransTbl[12]))(objcT78,selTransTbl[12]));

(objcT79=r,(*_imp(objcT79,selTransTbl[17]))(objcT79,selTransTbl[17],kw));
(objcT80=r,(*_imp(objcT80,selTransTbl[13]))(objcT80,selTransTbl[13],a));
return r;
}

# 22 "./addrof.h"
extern id  AddressOf;

# 576 "util.m"
id
mkaddressof(id a)
{
id objcT81,objcT82;

# 579 "util.m"
id r=(objcT81=AddressOf,(*_imp(objcT81,selTransTbl[12]))(objcT81,selTransTbl[12]));

(objcT82=r,(*_imp(objcT82,selTransTbl[13]))(objcT82,selTransTbl[13],a));
return r;
}

# 22 "./binxpr.h"
extern id  BinaryExpr;

# 585 "util.m"
id
mkbinexpr(id a,STR op,id b)
{
id objcT83,objcT84,objcT85,objcT86;

# 588 "util.m"
id r=(objcT83=BinaryExpr,(*_imp(objcT83,selTransTbl[12]))(objcT83,selTransTbl[12]));

(objcT84=r,(*_imp(objcT84,selTransTbl[23]))(objcT84,selTransTbl[23],a));
(objcT85=r,(*_imp(objcT85,selTransTbl[24]))(objcT85,selTransTbl[24],b));
(objcT86=r,(*(id(*)(id,SEL,STR))_imp(objcT86,selTransTbl[25]))(objcT86,selTransTbl[25],op));
return r;
}

# 22 "./commaxpr.h"
extern id  CommaExpr;

# 596 "util.m"
id
mkcommaexpr(id a,id b)
{
id objcT87,objcT88,objcT89;

# 599 "util.m"
id r=(objcT87=CommaExpr,(*_imp(objcT87,selTransTbl[12]))(objcT87,selTransTbl[12]));

(objcT88=r,(*_imp(objcT88,selTransTbl[23]))(objcT88,selTransTbl[23],a));
(objcT89=r,(*_imp(objcT89,selTransTbl[24]))(objcT89,selTransTbl[24],b));
return r;
}

# 22 "./assign.h"
extern id  Assignment;

# 606 "util.m"
id
mkassignexpr(id a,STR op,id b)
{
id objcT90,objcT91,objcT92,objcT93;

# 609 "util.m"
id r=(objcT90=Assignment,(*_imp(objcT90,selTransTbl[12]))(objcT90,selTransTbl[12]));

(objcT91=r,(*_imp(objcT91,selTransTbl[23]))(objcT91,selTransTbl[23],a));
(objcT92=r,(*_imp(objcT92,selTransTbl[24]))(objcT92,selTransTbl[24],b));
(objcT93=r,(*(id(*)(id,SEL,STR))_imp(objcT93,selTransTbl[25]))(objcT93,selTransTbl[25],op));
return r;
}

# 22 "./relxpr.h"
extern id  RelationExpr;

# 617 "util.m"
id
mkrelexpr(id a,STR op,id b)
{
id objcT94,objcT95,objcT96,objcT97;

# 620 "util.m"
id r=(objcT94=RelationExpr,(*_imp(objcT94,selTransTbl[12]))(objcT94,selTransTbl[12]));

(objcT95=r,(*_imp(objcT95,selTransTbl[23]))(objcT95,selTransTbl[23],a));
(objcT96=r,(*_imp(objcT96,selTransTbl[24]))(objcT96,selTransTbl[24],b));
(objcT97=r,(*(id(*)(id,SEL,STR))_imp(objcT97,selTransTbl[25]))(objcT97,selTransTbl[25],op));
return r;
}

# 22 "./btincall.h"
extern id  BuiltinCall;

# 628 "util.m"
id
mkbuiltincall(id funname,id args)
{
id objcT98,objcT99,objcT100;

# 631 "util.m"
id r=(objcT98=BuiltinCall,(*_imp(objcT98,selTransTbl[12]))(objcT98,selTransTbl[12]));

(objcT99=r,(*_imp(objcT99,selTransTbl[26]))(objcT99,selTransTbl[26],funname));
(objcT100=r,(*_imp(objcT100,selTransTbl[27]))(objcT100,selTransTbl[27],args));
return r;
}

# 22 "./funcall.h"
extern id  FunctionCall;

# 638 "util.m"
id
mkfuncall(id funname,id args)
{
id objcT101,objcT102,objcT103;

# 641 "util.m"
id r=(objcT101=FunctionCall,(*_imp(objcT101,selTransTbl[12]))(objcT101,selTransTbl[12]));

(objcT102=r,(*_imp(objcT102,selTransTbl[26]))(objcT102,selTransTbl[26],funname));
(objcT103=r,(*_imp(objcT103,selTransTbl[27]))(objcT103,selTransTbl[27],args));
return r;
}

# 22 "./funbody.h"
extern id  FunctionBody;

# 648 "util.m"
id
mkfunbody(id datadefs,id compound)
{
id objcT104,objcT105,objcT106;

# 651 "util.m"
id r=(objcT104=FunctionBody,(*_imp(objcT104,selTransTbl[12]))(objcT104,selTransTbl[12]));

(objcT105=r,(*_imp(objcT105,selTransTbl[28]))(objcT105,selTransTbl[28],datadefs));
(objcT106=r,(*_imp(objcT106,selTransTbl[29]))(objcT106,selTransTbl[29],compound));
return r;
}

# 22 "./datadef.h"
extern id  DataDef;

# 658 "util.m"
void
declarefun(id specs,id decl)
{
id objcT107,objcT108,objcT109,objcT110;

# 661 "util.m"
id d=(objcT107=DataDef,(*_imp(objcT107,selTransTbl[12]))(objcT107,selTransTbl[12]));

if(specs)
(objcT108=d,(*_imp(objcT108,selTransTbl[30]))(objcT108,selTransTbl[30],specs));
(objcT109=d,(*_imp(objcT109,selTransTbl[31]))(objcT109,selTransTbl[31],decl));
(objcT110=d,(*_imp(objcT110,selTransTbl[0]))(objcT110,selTransTbl[0]));
}

# 22 "./methdef.h"
extern id  MethodDef;

# 669 "util.m"
void
declaremeth(BOOL factory,id decl)
{
id objcT111,objcT112,objcT113,objcT114;

# 672 "util.m"
id r=(objcT111=MethodDef,(*_imp(objcT111,selTransTbl[12]))(objcT111,selTransTbl[12]));

(objcT112=r,(*(id(*)(id,SEL,BOOL))_imp(objcT112,selTransTbl[32]))(objcT112,selTransTbl[32],factory));
(objcT113=r,(*_imp(objcT113,selTransTbl[33]))(objcT113,selTransTbl[33],decl));
(objcT114=r,(*_imp(objcT114,selTransTbl[34]))(objcT114,selTransTbl[34]));
}

# 22 "./fundef.h"
extern id  FunctionDef;

# 679 "util.m"
id
mkfundef(id specs,id decl,id body)
{
id objcT115,objcT116,objcT117,objcT118;

# 682 "util.m"
id r=(objcT115=FunctionDef,(*_imp(objcT115,selTransTbl[12]))(objcT115,selTransTbl[12]));

(objcT116=r,(*_imp(objcT116,selTransTbl[35]))(objcT116,selTransTbl[35],specs));
(objcT117=r,(*_imp(objcT117,selTransTbl[36]))(objcT117,selTransTbl[36],decl));
(objcT118=r,(*_imp(objcT118,selTransTbl[37]))(objcT118,selTransTbl[37],body));
return r;
}

id
mkmethdef(BOOL factory,id decl,id body)
{
id objcT119,objcT120,objcT121,objcT122;

# 693 "util.m"
id r=(objcT119=MethodDef,(*_imp(objcT119,selTransTbl[12]))(objcT119,selTransTbl[12]));

(objcT120=r,(*(id(*)(id,SEL,BOOL))_imp(objcT120,selTransTbl[32]))(objcT120,selTransTbl[32],factory));
(objcT121=r,(*_imp(objcT121,selTransTbl[33]))(objcT121,selTransTbl[33],decl));
(objcT122=r,(*_imp(objcT122,selTransTbl[37]))(objcT122,selTransTbl[37],body));
return r;
}

# 24 "./msgxpr.h"
extern id  MesgExpr;

# 701 "util.m"
id
mkmesgexpr(id receiver,id args)
{
id objcT123,objcT124,objcT125;

# 704 "util.m"
id r=(objcT123=MesgExpr,(*_imp(objcT123,selTransTbl[12]))(objcT123,selTransTbl[12]));

(objcT124=r,(*_imp(objcT124,selTransTbl[38]))(objcT124,selTransTbl[38],receiver));
(objcT125=r,(*_imp(objcT125,selTransTbl[39]))(objcT125,selTransTbl[39],args));
return r;
}

# 22 "./namedecl.h"
extern id  NameDecl;

# 711 "util.m"
id
mkdecl(id ident)
{
id objcT126,objcT127;

# 714 "util.m"
id r=(objcT126=NameDecl,(*_imp(objcT126,selTransTbl[12]))(objcT126,selTransTbl[12]));

(objcT127=r,(*_imp(objcT127,selTransTbl[40]))(objcT127,selTransTbl[40],ident));
return r;
}

# 22 "./precdecl.h"
extern id  PrecDecl;

# 720 "util.m"
id
mkprecdecl(id typequals,id decl)
{
id objcT128,objcT129,objcT130;

# 723 "util.m"
id r=(objcT128=PrecDecl,(*_imp(objcT128,selTransTbl[12]))(objcT128,selTransTbl[12]));

if(typequals)
(objcT129=r,(*_imp(objcT129,selTransTbl[41]))(objcT129,selTransTbl[41],typequals));
if(decl)
(objcT130=r,(*_imp(objcT130,selTransTbl[36]))(objcT130,selTransTbl[36],decl));
return r;
}

# 22 "./arydecl.h"
extern id  ArrayDecl;

# 732 "util.m"
id
mkarraydecl(id lhs,id ix)
{
id objcT131,objcT132,objcT133;

# 735 "util.m"
id r=(objcT131=ArrayDecl,(*_imp(objcT131,selTransTbl[12]))(objcT131,selTransTbl[12]));

(objcT132=r,(*_imp(objcT132,selTransTbl[36]))(objcT132,selTransTbl[36],lhs));
(objcT133=r,(*_imp(objcT133,selTransTbl[13]))(objcT133,selTransTbl[13],ix));
return r;
}

# 22 "./fundecl.h"
extern id  FunctionDecl;

# 742 "util.m"
id
mkfundecl(id lhs,id args)
{
id objcT134,objcT135,objcT136;

# 745 "util.m"
id r=(objcT134=FunctionDecl,(*_imp(objcT134,selTransTbl[12]))(objcT134,selTransTbl[12]));

(objcT135=r,(*_imp(objcT135,selTransTbl[36]))(objcT135,selTransTbl[36],lhs));
(objcT136=r,(*_imp(objcT136,selTransTbl[42]))(objcT136,selTransTbl[42],args));
return r;
}

# 22 "./pfixdecl.h"
extern id  PostfixDecl;

# 752 "util.m"
id
mkprefixdecl(id lhs,id rhs)
{
id objcT137,objcT138,objcT139;

# 755 "util.m"
id r=(objcT137=PostfixDecl,(*_imp(objcT137,selTransTbl[12]))(objcT137,selTransTbl[12]));

(objcT138=r,(*_imp(objcT138,selTransTbl[43]))(objcT138,selTransTbl[43],lhs));
(objcT139=r,(*_imp(objcT139,selTransTbl[36]))(objcT139,selTransTbl[36],rhs));
return r;
}

id
mkpostfixdecl(id lhs,id rhs)
{
id objcT140,objcT141,objcT142;

# 765 "util.m"
id r=(objcT140=PostfixDecl,(*_imp(objcT140,selTransTbl[12]))(objcT140,selTransTbl[12]));

(objcT141=r,(*_imp(objcT141,selTransTbl[36]))(objcT141,selTransTbl[36],lhs));
(objcT142=r,(*_imp(objcT142,selTransTbl[44]))(objcT142,selTransTbl[44],rhs));
return r;
}

# 22 "./pointer.h"
extern id  Pointer;

# 772 "util.m"
id
mkpointer(id specs,id pointer)
{
id objcT143,objcT144,objcT145;

# 775 "util.m"
id r=(objcT143=Pointer,(*_imp(objcT143,selTransTbl[12]))(objcT143,selTransTbl[12]));

if(specs)
(objcT144=r,(*_imp(objcT144,selTransTbl[30]))(objcT144,selTransTbl[30],specs));
if(pointer)
(objcT145=r,(*_imp(objcT145,selTransTbl[45]))(objcT145,selTransTbl[45],pointer));
return r;
}

# 22 "./bflddecl.h"
extern id  BitfieldDecl;

# 784 "util.m"
id
mkbitfielddecl(id decl,id expr)
{
id objcT146,objcT147,objcT148;

# 787 "util.m"
id r=(objcT146=BitfieldDecl,(*_imp(objcT146,selTransTbl[12]))(objcT146,selTransTbl[12]));

(objcT147=r,(*_imp(objcT147,selTransTbl[36]))(objcT147,selTransTbl[36],decl));
(objcT148=r,(*_imp(objcT148,selTransTbl[13]))(objcT148,selTransTbl[13],expr));
return r;
}

# 22 "./stardecl.h"
extern id  StarDecl;

# 794 "util.m"
id
mkstardecl(id pointer,id decl)
{
id objcT149,objcT150,objcT151;

# 797 "util.m"
id r=(objcT149=StarDecl,(*_imp(objcT149,selTransTbl[12]))(objcT149,selTransTbl[12]));

(objcT150=r,(*_imp(objcT150,selTransTbl[45]))(objcT150,selTransTbl[45],pointer));
(objcT151=r,(*_imp(objcT151,selTransTbl[36]))(objcT151,selTransTbl[36],decl));
return r;
}

# 22 "./gasmop.h"
extern id  GnuAsmOp;

# 804 "util.m"
id
mkasmop(id aList,id expr)
{
id objcT152,objcT153,objcT154;

# 807 "util.m"
id r=(objcT152=GnuAsmOp,(*_imp(objcT152,selTransTbl[12]))(objcT152,selTransTbl[12]));

(objcT153=r,(*_imp(objcT153,selTransTbl[46]))(objcT153,selTransTbl[46],aList));
(objcT154=r,(*_imp(objcT154,selTransTbl[13]))(objcT154,selTransTbl[13],expr));
return r;
}

# 22 "./gasmstmt.h"
extern id  GnuAsmStmt;

# 814 "util.m"
id
mkasmstmt(id keyw,id typequal,id expr,id asmop1,id asmop2,id clobbers)
{
id objcT155,objcT156,objcT157,objcT158,objcT159;
id objcT160,objcT161;

# 817 "util.m"
id r=(objcT155=GnuAsmStmt,(*_imp(objcT155,selTransTbl[12]))(objcT155,selTransTbl[12]));

(objcT156=r,(*_imp(objcT156,selTransTbl[17]))(objcT156,selTransTbl[17],keyw));
(objcT157=r,(*_imp(objcT157,selTransTbl[47]))(objcT157,selTransTbl[47],typequal));
(objcT158=r,(*_imp(objcT158,selTransTbl[13]))(objcT158,selTransTbl[13],expr));
(objcT159=r,(*_imp(objcT159,selTransTbl[48]))(objcT159,selTransTbl[48],asmop1));
(objcT160=r,(*_imp(objcT160,selTransTbl[49]))(objcT160,selTransTbl[49],asmop2));
(objcT161=r,(*_imp(objcT161,selTransTbl[50]))(objcT161,selTransTbl[50],clobbers));
return r;
}

# 25 "./compstmt.h"
extern id  CompoundStmt;

# 828 "util.m"
id
mkcompstmt(id lbrace,id datadefs,id stmtlist,id subblock,id rbrace)
{
id objcT162,objcT163,objcT164,objcT165,objcT166;
id objcT167;

# 831 "util.m"
id r=(objcT162=CompoundStmt,(*_imp(objcT162,selTransTbl[12]))(objcT162,selTransTbl[12]));

(objcT163=r,(*_imp(objcT163,selTransTbl[51]))(objcT163,selTransTbl[51],lbrace));
(objcT164=r,(*_imp(objcT164,selTransTbl[28]))(objcT164,selTransTbl[28],datadefs));
(objcT165=r,(*_imp(objcT165,selTransTbl[52]))(objcT165,selTransTbl[52],stmtlist));
(objcT166=r,(*_imp(objcT166,selTransTbl[53]))(objcT166,selTransTbl[53],subblock));
(objcT167=r,(*_imp(objcT167,selTransTbl[54]))(objcT167,selTransTbl[54],rbrace));
return r;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 841 "util.m"
id
mklist(id c,id s)
{
id objcT168,objcT169;

# 844 "util.m"
if(c==(id)0)
c=(objcT168=OrdCltn,(*_imp(objcT168,selTransTbl[12]))(objcT168,selTransTbl[12]));
(void)0;
(objcT169=c,(*_imp(objcT169,selTransTbl[31]))(objcT169,selTransTbl[31],s));
return c;
}

id
mklist2(id c,id s,id t)
{
id objcT170,objcT171,objcT172;

# 854 "util.m"
if(c==(id)0)
c=(objcT170=OrdCltn,(*_imp(objcT170,selTransTbl[12]))(objcT170,selTransTbl[12]));
(void)0;
(objcT171=c,(*_imp(objcT171,selTransTbl[31]))(objcT171,selTransTbl[31],s));
(objcT172=c,(*_imp(objcT172,selTransTbl[31]))(objcT172,selTransTbl[31],t));
return c;
}

id
atdefsadd(id c,id cls)
{
id objcT173,objcT174,objcT175;

# 865 "util.m"
id scls=(objcT173=cls,(*_imp(objcT173,selTransTbl[55]))(objcT173,selTransTbl[55]));

if(scls)
atdefsadd(c,scls);
(objcT174=c,(*_imp(objcT174,selTransTbl[56]))(objcT174,selTransTbl[56],(objcT175=cls,(*_imp(objcT175,selTransTbl[57]))(objcT175,selTransTbl[57]))));
return c;
}

id
atdefsaddall(id c,id n)
{
id objcT176,objcT177;

# 876 "util.m"
id cls;

if(c==(id)0)
c=(objcT176=OrdCltn,(*_imp(objcT176,selTransTbl[12]))(objcT176,selTransTbl[12]));
(void)0;
if((cls=(objcT177=trlunit,(*_imp(objcT177,selTransTbl[58]))(objcT177,selTransTbl[58],n)))){
atdefsadd(c,cls);
}else{
id objcT178;

# 884 "util.m"
fatal("cannot find @defs of '%s'",(objcT178=n,(*(STR(*)(id,SEL))_imp(objcT178,selTransTbl[10]))(objcT178,selTransTbl[10])));
}
return c;
}

# 24 "./blockxpr.h"
extern id  BlockExpr;

# 889 "util.m"
id
mkblockexpr(id lb,id parms,id datadefs,id stmts,id expr,id rb)
{
id objcT179,objcT180,objcT181,objcT182,objcT183;
id objcT184,objcT185;

# 892 "util.m"
id r=(objcT179=BlockExpr,(*_imp(objcT179,selTransTbl[12]))(objcT179,selTransTbl[12]));

(objcT180=r,(*_imp(objcT180,selTransTbl[51]))(objcT180,selTransTbl[51],lb));
(objcT181=r,(*_imp(objcT181,selTransTbl[59]))(objcT181,selTransTbl[59],parms));
(objcT182=r,(*_imp(objcT182,selTransTbl[28]))(objcT182,selTransTbl[28],datadefs));
(objcT183=r,(*_imp(objcT183,selTransTbl[52]))(objcT183,selTransTbl[52],stmts));
(objcT184=r,(*_imp(objcT184,selTransTbl[13]))(objcT184,selTransTbl[13],expr));
(objcT185=r,(*_imp(objcT185,selTransTbl[54]))(objcT185,selTransTbl[54],rb));
return r;
}

# 25 "./classdef.h"
extern id  ClassDef;

# 903 "util.m"
id
mkclassdef(id keyw,id name,id sname,id ivars,id cvars)
{
id objcT186,objcT187,objcT188,objcT198;

# 906 "util.m"
id r;
BOOL intfkeyw=(keyw!=(id)0&&strstr((objcT186=keyw,(*(STR(*)(id,SEL))_imp(objcT186,selTransTbl[10]))(objcT186,selTransTbl[10])),"interface")!=NULL);
BOOL implkeyw=(keyw!=(id)0&&strstr((objcT187=keyw,(*(STR(*)(id,SEL))_imp(objcT187,selTransTbl[10]))(objcT187,selTransTbl[10])),"implementation")!=NULL);


if((r=(objcT188=trlunit,(*_imp(objcT188,selTransTbl[58]))(objcT188,selTransTbl[58],name)))){
if(intfkeyw){
id objcT189;

# 913 "util.m"
fatal("multiple interfaces for class %s.",(objcT189=r,(*(char*(*)(id,SEL))_imp(objcT189,selTransTbl[60]))(objcT189,selTransTbl[60])));
}else{
id objcT190,objcT191,objcT192;

# 915 "util.m"
if(sname)
(objcT190=r,(*_imp(objcT190,selTransTbl[61]))(objcT190,selTransTbl[61],sname));
if(ivars)
(objcT191=r,(*_imp(objcT191,selTransTbl[62]))(objcT191,selTransTbl[62],ivars));
if(cvars)
(objcT192=r,(*_imp(objcT192,selTransTbl[63]))(objcT192,selTransTbl[63],cvars));
}
}else{
id objcT193,objcT194,objcT195,objcT196,objcT197;

# 923 "util.m"
r=(objcT193=ClassDef,(*_imp(objcT193,selTransTbl[12]))(objcT193,selTransTbl[12]));
(objcT194=r,(*_imp(objcT194,selTransTbl[64]))(objcT194,selTransTbl[64],name));
(objcT195=r,(*_imp(objcT195,selTransTbl[65]))(objcT195,selTransTbl[65],sname));
(objcT196=r,(*_imp(objcT196,selTransTbl[66]))(objcT196,selTransTbl[66],ivars));
(objcT197=r,(*_imp(objcT197,selTransTbl[67]))(objcT197,selTransTbl[67],cvars));
}

if(implkeyw)
(objcT198=r,(*_imp(objcT198,selTransTbl[68]))(objcT198,selTransTbl[68]));

if(curclassdef){
id objcT199;

# 934 "util.m"
warn("definition of %s not properly ended.",(objcT199=curclassdef,(*(char*(*)(id,SEL))_imp(objcT199,selTransTbl[60]))(objcT199,selTransTbl[60])));
curclassdef=r;
}else{
curclassdef=r;
}

return r;
}

BOOL
lhsisid(id specs,id decl)
{
id objcT200,objcT201,objcT202,objcT203,objcT204;

# 946 "util.m"
return(objcT200=specs,(*(unsigned(*)(id,SEL))_imp(objcT200,selTransTbl[69]))(objcT200,selTransTbl[69]))==1&&(objcT201=(objcT202=specs,(*(id(*)(id,SEL,unsigned))_imp(objcT202,selTransTbl[70]))(objcT202,selTransTbl[70],0)),(*(BOOL(*)(id,SEL))_imp(objcT201,selTransTbl[71]))(objcT201,selTransTbl[71]))&&(objcT203=decl,(*(BOOL(*)(id,SEL,id))_imp(objcT203,selTransTbl[72]))(objcT203,selTransTbl[72],(id)(objcT204=NameDecl,(*_imp(objcT204,selTransTbl[73]))(objcT204,selTransTbl[73]))));
}

void
datadefokblock(id datadef,id specs,id decl)
{
# 955 "util.m"
if(specs){
okblock=lhsisid(specs,decl);
}else{
id objcT205;

# 958 "util.m"
okblock=lhsisid((objcT205=datadef,(*_imp(objcT205,selTransTbl[74]))(objcT205,selTransTbl[74])),decl);
}
}

# 22 "./initdecl.h"
extern id  InitDecl;

# 962 "util.m"
id
mkdatadef(id datadef,id specs,id decl,id initializer)
{
id objcT206,objcT207,objcT211;

# 965 "util.m"
if(datadef==(id)0)
datadef=(objcT206=DataDef,(*_imp(objcT206,selTransTbl[12]))(objcT206,selTransTbl[12]));
if(specs)
(objcT207=datadef,(*_imp(objcT207,selTransTbl[30]))(objcT207,selTransTbl[30],specs));
if(initializer){
id objcT208,objcT209,objcT210;

# 970 "util.m"
decl=(objcT208=(objcT209=(objcT210=InitDecl,(*_imp(objcT210,selTransTbl[12]))(objcT210,selTransTbl[12])),(*_imp(objcT209,selTransTbl[36]))(objcT209,selTransTbl[36],decl)),(*_imp(objcT208,selTransTbl[75]))(objcT208,selTransTbl[75],initializer));
}
(objcT211=datadef,(*_imp(objcT211,selTransTbl[31]))(objcT211,selTransTbl[31],decl));
return datadef;
}

id
mkencodeexpr(id name)
{
return(id)0;
}

# 22 "./enumsp.h"
extern id  EnumSpec;

# 982 "util.m"
id
mkenumspec(id keyw,id name,id lb,id list,id rb)
{
id objcT212,objcT213,objcT214,objcT215,objcT216;
id objcT217;

# 985 "util.m"
id r=(objcT212=EnumSpec,(*_imp(objcT212,selTransTbl[12]))(objcT212,selTransTbl[12]));

(objcT213=r,(*_imp(objcT213,selTransTbl[17]))(objcT213,selTransTbl[17],keyw));
(objcT214=r,(*_imp(objcT214,selTransTbl[76]))(objcT214,selTransTbl[76],name));
(objcT215=r,(*_imp(objcT215,selTransTbl[51]))(objcT215,selTransTbl[51],lb));
if(list)
(objcT216=r,(*_imp(objcT216,selTransTbl[77]))(objcT216,selTransTbl[77],list));
(objcT217=r,(*_imp(objcT217,selTransTbl[54]))(objcT217,selTransTbl[54],rb));
return r;
}

# 22 "./enumtor.h"
extern id  Enumerator;

# 996 "util.m"
id
mkenumerator(id name,id value)
{
id objcT218,objcT219,objcT220;

# 999 "util.m"
id r=(objcT218=Enumerator,(*_imp(objcT218,selTransTbl[12]))(objcT218,selTransTbl[12]));

(objcT219=r,(*_imp(objcT219,selTransTbl[76]))(objcT219,selTransTbl[76],name));
if(value)(objcT220=r,(*_imp(objcT220,selTransTbl[78]))(objcT220,selTransTbl[78],value));
return r;
}

# 22 "./gattrib.h"
extern id  GnuAttrib;

# 1006 "util.m"
id
mkgnuattrib(id anyword,id exprlist)
{
id objcT221,objcT222,objcT223;

# 1009 "util.m"
id r=(objcT221=GnuAttrib,(*_imp(objcT221,selTransTbl[12]))(objcT221,selTransTbl[12]));

(objcT222=r,(*_imp(objcT222,selTransTbl[79]))(objcT222,selTransTbl[79],anyword));
(objcT223=r,(*_imp(objcT223,selTransTbl[80]))(objcT223,selTransTbl[80],exprlist));
return r;
}

# 22 "./gatrdecl.h"
extern id  GnuAttribDecl;

# 1016 "util.m"
id
mkgnuattribdecl(id keyw,id list)
{
id objcT224,objcT225,objcT226;

# 1019 "util.m"
id r=(objcT224=GnuAttribDecl,(*_imp(objcT224,selTransTbl[12]))(objcT224,selTransTbl[12]));

(objcT225=r,(*_imp(objcT225,selTransTbl[17]))(objcT225,selTransTbl[17],keyw));
(objcT226=r,(*_imp(objcT226,selTransTbl[81]))(objcT226,selTransTbl[81],list));
return r;
}

# 22 "./listxpr.h"
extern id  ListExpr;

# 1026 "util.m"
id
mklistexpr(id lb,id x,id rb)
{
id objcT227,objcT228,objcT229,objcT230;

# 1029 "util.m"
id r=(objcT227=ListExpr,(*_imp(objcT227,selTransTbl[12]))(objcT227,selTransTbl[12]));

(objcT228=r,(*_imp(objcT228,selTransTbl[51]))(objcT228,selTransTbl[51],lb));
(objcT229=r,(*_imp(objcT229,selTransTbl[82]))(objcT229,selTransTbl[82],x));
(objcT230=r,(*_imp(objcT230,selTransTbl[54]))(objcT230,selTransTbl[54],rb));
return r;
}

# 34 "./type.h"
extern id  Type;

# 1037 "util.m"
id
mktypename(id specs,id decl)
{
id objcT231,objcT232,objcT233;

# 1040 "util.m"
id r=(objcT231=Type,(*_imp(objcT231,selTransTbl[12]))(objcT231,selTransTbl[12]));

(objcT232=r,(*_imp(objcT232,selTransTbl[30]))(objcT232,selTransTbl[30],specs));
(objcT233=r,(*_imp(objcT233,selTransTbl[36]))(objcT233,selTransTbl[36],decl));
return r;
}

# 22 "./compdef.h"
extern id  ComponentDef;

# 1047 "util.m"
id
mkcomponentdef(id cdef,id specs,id decl)
{
id objcT234,objcT235,objcT236;

# 1050 "util.m"
if(cdef==(id)0)
cdef=(objcT234=ComponentDef,(*_imp(objcT234,selTransTbl[12]))(objcT234,selTransTbl[12]));
if(specs)
(objcT235=cdef,(*_imp(objcT235,selTransTbl[30]))(objcT235,selTransTbl[30],specs));
(objcT236=cdef,(*_imp(objcT236,selTransTbl[31]))(objcT236,selTransTbl[31],decl));
return cdef;
}

# 24 "./structsp.h"
extern id  StructSpec;

# 1058 "util.m"
id
mkstructspec(id keyw,id name,id lb,id defs,id rb)
{
id objcT237,objcT238,objcT239,objcT240,objcT241;
id objcT242;

# 1061 "util.m"
id r=(objcT237=StructSpec,(*_imp(objcT237,selTransTbl[12]))(objcT237,selTransTbl[12]));

(objcT238=r,(*_imp(objcT238,selTransTbl[17]))(objcT238,selTransTbl[17],keyw));
(objcT239=r,(*_imp(objcT239,selTransTbl[76]))(objcT239,selTransTbl[76],name));
(objcT240=r,(*_imp(objcT240,selTransTbl[51]))(objcT240,selTransTbl[51],lb));
if(defs)
(objcT241=r,(*_imp(objcT241,selTransTbl[83]))(objcT241,selTransTbl[83],defs));
(objcT242=r,(*_imp(objcT242,selTransTbl[54]))(objcT242,selTransTbl[54],rb));
return r;
}

# 22 "./keywxpr.h"
extern id  KeywExpr;

# 1072 "util.m"
id
mkkeywarg(id sel,id arg)
{
id objcT243,objcT244,objcT245;

# 1075 "util.m"
id r=(objcT243=KeywExpr,(*_imp(objcT243,selTransTbl[12]))(objcT243,selTransTbl[12]));

(objcT244=r,(*_imp(objcT244,selTransTbl[17]))(objcT244,selTransTbl[17],sel));
(objcT245=r,(*_imp(objcT245,selTransTbl[84]))(objcT245,selTransTbl[84],arg));
return r;
}

# 22 "./keywdecl.h"
extern id  KeywDecl;

# 1082 "util.m"
id
mkkeywdecl(id sel,id cast,id arg)
{
id objcT246,objcT247,objcT248,objcT249;

# 1085 "util.m"
id r=(objcT246=KeywDecl,(*_imp(objcT246,selTransTbl[12]))(objcT246,selTransTbl[12]));

(objcT247=r,(*_imp(objcT247,selTransTbl[17]))(objcT247,selTransTbl[17],sel));
(objcT248=r,(*_imp(objcT248,selTransTbl[22]))(objcT248,selTransTbl[22],cast));
(objcT249=r,(*_imp(objcT249,selTransTbl[84]))(objcT249,selTransTbl[84],arg));
return r;
}

# 22 "./method.h"
extern id  Method;

# 1093 "util.m"
id
mkmethproto(id cast,id usel,id ksel,BOOL varargs)
{
id objcT250,objcT251,objcT252,objcT253,objcT254;

# 1096 "util.m"
id r=(objcT250=Method,(*_imp(objcT250,selTransTbl[12]))(objcT250,selTransTbl[12]));

(objcT251=r,(*_imp(objcT251,selTransTbl[85]))(objcT251,selTransTbl[85],cast));
(objcT252=r,(*_imp(objcT252,selTransTbl[86]))(objcT252,selTransTbl[86],usel));
(objcT253=r,(*_imp(objcT253,selTransTbl[87]))(objcT253,selTransTbl[87],ksel));
(objcT254=r,(*(id(*)(id,SEL,BOOL))_imp(objcT254,selTransTbl[88]))(objcT254,selTransTbl[88],varargs));
return r;
}

# 22 "./identxpr.h"
extern id  IdentifierExpr;

# 1105 "util.m"
id
mkidentexpr(id name)
{
id objcT255,objcT256;

# 1108 "util.m"
id r=(objcT255=IdentifierExpr,(*_imp(objcT255,selTransTbl[12]))(objcT255,selTransTbl[12]));

(objcT256=r,(*_imp(objcT256,selTransTbl[40]))(objcT256,selTransTbl[40],name));
return r;
}

# 22 "./constxpr.h"
extern id  ConstantExpr;

# 1114 "util.m"
id
mkconstexpr(id name,id schain)
{
id objcT257,objcT258,objcT259;

# 1117 "util.m"
id r=(objcT257=ConstantExpr,(*_imp(objcT257,selTransTbl[12]))(objcT257,selTransTbl[12]));

if(name)
(objcT258=r,(*_imp(objcT258,selTransTbl[40]))(objcT258,selTransTbl[40],name));
if(schain)
(objcT259=r,(*_imp(objcT259,selTransTbl[46]))(objcT259,selTransTbl[46],schain));
return r;
}

# 22 "./precxpr.h"
extern id  PrecExpr;

# 1126 "util.m"
id
mkprecexpr(id expr)
{
id objcT260,objcT261;

# 1129 "util.m"
id r=(objcT260=PrecExpr,(*_imp(objcT260,selTransTbl[12]))(objcT260,selTransTbl[12]));

(objcT261=r,(*_imp(objcT261,selTransTbl[13]))(objcT261,selTransTbl[13],expr));
return r;
}

id
mkbracedgroup(id expr)
{
id objcT262;

# 1138 "util.m"
(objcT262=expr,(*(id(*)(id,SEL,BOOL))_imp(objcT262,selTransTbl[89]))(objcT262,selTransTbl[89],(BOOL)1));
return mkprecexpr(expr);
}

# 22 "./arrowxpr.h"
extern id  ArrowExpr;

# 1142 "util.m"
id
mkarrowexpr(id array,id ix)
{
id objcT263,objcT264,objcT265;

# 1145 "util.m"
id r=(objcT263=ArrowExpr,(*_imp(objcT263,selTransTbl[12]))(objcT263,selTransTbl[12]));

(objcT264=r,(*_imp(objcT264,selTransTbl[23]))(objcT264,selTransTbl[23],array));
(objcT265=r,(*_imp(objcT265,selTransTbl[24]))(objcT265,selTransTbl[24],ix));
return r;
}

# 22 "./dotxpr.h"
extern id  DotExpr;

# 1152 "util.m"
id
mkdotexpr(id array,id ix)
{
id objcT266,objcT267,objcT268;

# 1155 "util.m"
id r=(objcT266=DotExpr,(*_imp(objcT266,selTransTbl[12]))(objcT266,selTransTbl[12]));

(objcT267=r,(*_imp(objcT267,selTransTbl[23]))(objcT267,selTransTbl[23],array));
(objcT268=r,(*_imp(objcT268,selTransTbl[24]))(objcT268,selTransTbl[24],ix));
return r;
}

# 22 "./indexxpr.h"
extern id  IndexExpr;

# 1162 "util.m"
id
mkindexexpr(id array,id ix)
{
id objcT269,objcT270,objcT271;

# 1165 "util.m"
id r=(objcT269=IndexExpr,(*_imp(objcT269,selTransTbl[12]))(objcT269,selTransTbl[12]));

(objcT270=r,(*_imp(objcT270,selTransTbl[23]))(objcT270,selTransTbl[23],array));
(objcT271=r,(*_imp(objcT271,selTransTbl[24]))(objcT271,selTransTbl[24],ix));
return r;
}

# 22 "./pfixxpr.h"
extern id  PostfixExpr;

# 1172 "util.m"
id
mkpostfixexpr(id expr,id pf)
{
id objcT272,objcT273,objcT274,objcT275;

# 1175 "util.m"
id r=(objcT272=PostfixExpr,(*_imp(objcT272,selTransTbl[12]))(objcT272,selTransTbl[12]));

(objcT273=r,(*_imp(objcT273,selTransTbl[13]))(objcT273,selTransTbl[13],expr));
(objcT274=r,(*(id(*)(id,SEL,STR))_imp(objcT274,selTransTbl[25]))(objcT274,selTransTbl[25],(objcT275=pf,(*(STR(*)(id,SEL))_imp(objcT275,selTransTbl[90]))(objcT275,selTransTbl[90]))));
return r;
}

# 22 "./parmdef.h"
extern id  ParameterDef;

# 1182 "util.m"
id
mkparmdef(id parmdef,id specs,id decl)
{
id objcT276,objcT277,objcT278;

# 1185 "util.m"
id r=(objcT276=ParameterDef,(*_imp(objcT276,selTransTbl[12]))(objcT276,selTransTbl[12]));

if(specs)
(objcT277=r,(*_imp(objcT277,selTransTbl[30]))(objcT277,selTransTbl[30],specs));
(objcT278=r,(*_imp(objcT278,selTransTbl[36]))(objcT278,selTransTbl[36],decl));
return r;
}

# 22 "./parmlist.h"
extern id  ParameterList;

# 1193 "util.m"
id
mkparmdeflist(id idents,id parmdefs,BOOL varargs)
{
id objcT279,objcT280,objcT281,objcT282;

# 1196 "util.m"
id r=(objcT279=ParameterList,(*_imp(objcT279,selTransTbl[12]))(objcT279,selTransTbl[12]));

if(idents)
(objcT280=r,(*_imp(objcT280,selTransTbl[91]))(objcT280,selTransTbl[91],idents));
if(parmdefs)
(objcT281=r,(*_imp(objcT281,selTransTbl[92]))(objcT281,selTransTbl[92],parmdefs));
(objcT282=r,(*(id(*)(id,SEL,BOOL))_imp(objcT282,selTransTbl[88]))(objcT282,selTransTbl[88],varargs));
return r;
}

# 22 "./selector.h"
extern id  Selector;

# 1206 "util.m"
id
mkselarg(id sel,id usel,int ncols)
{
if(sel==(id)0){
id objcT283,objcT284;

# 1210 "util.m"
(void)0;
sel=(objcT283=Selector,(*(id(*)(id,SEL,STR))_imp(objcT283,selTransTbl[9]))(objcT283,selTransTbl[9],(objcT284=usel,(*(STR(*)(id,SEL))_imp(objcT284,selTransTbl[90]))(objcT284,selTransTbl[90]))));
}else{
id objcT285,objcT286;

# 1213 "util.m"
if(usel)
(objcT285=sel,(*_imp(objcT285,selTransTbl[31]))(objcT285,selTransTbl[31],usel));
while(ncols--)
(objcT286=sel,(*_imp(objcT286,selTransTbl[93]))(objcT286,selTransTbl[93]));
}
return sel;
}

# 22 "./selxpr.h"
extern id  SelectorExpr;

# 1221 "util.m"
id
mkselectorexpr(id expr)
{
id objcT287,objcT288;

# 1224 "util.m"
id r=(objcT287=SelectorExpr,(*_imp(objcT287,selTransTbl[12]))(objcT287,selTransTbl[12]));

(objcT288=r,(*_imp(objcT288,selTransTbl[94]))(objcT288,selTransTbl[94],expr));
return r;
}

id
mkfilesupermsg(id sel,id arg)
{
id objcT289,objcT290,objcT291,objcT292;

# 1233 "util.m"
id ksel,m;

m=(objcT289=MesgExpr,(*_imp(objcT289,selTransTbl[12]))(objcT289,selTransTbl[12]));
(objcT290=m,(*_imp(objcT290,selTransTbl[38]))(objcT290,selTransTbl[38],e_super));
ksel=(objcT291=OrdCltn,(*_imp(objcT291,selTransTbl[31]))(objcT291,selTransTbl[31],mkkeywarg(sel,arg)));
(objcT292=m,(*_imp(objcT292,selTransTbl[39]))(objcT292,selTransTbl[39],mkmethproto((id)0,(id)0,ksel,(BOOL)0)));
return mkexprstmtx(m);
}

id
mkfilemsg(id sel,id name)
{
id objcT293,objcT294,objcT295,objcT296,objcT297;

# 1245 "util.m"
id ksel,m;

m=(objcT293=MesgExpr,(*_imp(objcT293,selTransTbl[12]))(objcT293,selTransTbl[12]));
(objcT294=m,(*_imp(objcT294,selTransTbl[38]))(objcT294,selTransTbl[38],e_aFiler));
ksel=(objcT295=OrdCltn,(*_imp(objcT295,selTransTbl[31]))(objcT295,selTransTbl[31],mkkeywarg(sel,mkaddressof(mkidentexpr(name)))));
(objcT296=ksel,(*_imp(objcT296,selTransTbl[31]))(objcT296,selTransTbl[31],mkkeywarg(s_type,e_ft_id)));
(objcT297=m,(*_imp(objcT297,selTransTbl[39]))(objcT297,selTransTbl[39],mkmethproto((id)0,(id)0,ksel,(BOOL)0)));
return mkexprstmtx(m);
}

id
mkfileinoutmeth(id ssel,id fsel,id ivarnames,id ivartypes)
{
id objcT298,objcT299,objcT304,objcT305;

# 1258 "util.m"
id d,b,r;

r=(objcT298=MethodDef,(*_imp(objcT298,selTransTbl[12]))(objcT298,selTransTbl[12]));
if((d=(objcT299=Method,(*_imp(objcT299,selTransTbl[12]))(objcT299,selTransTbl[12])))){
id objcT300,objcT301,objcT302,objcT303;

# 1262 "util.m"
id ksel=(objcT300=OrdCltn,(*_imp(objcT300,selTransTbl[31]))(objcT300,selTransTbl[31],mkkeywdecl(ssel,(id)0,s_aFiler)));

(objcT301=d,(*_imp(objcT301,selTransTbl[87]))(objcT301,selTransTbl[87],ksel));
(objcT302=d,(*(id(*)(id,SEL,BOOL))_imp(objcT302,selTransTbl[95]))(objcT302,selTransTbl[95],(BOOL)0));
(objcT303=r,(*_imp(objcT303,selTransTbl[33]))(objcT303,selTransTbl[33],d));
}
(objcT304=r,(*_imp(objcT304,selTransTbl[34]))(objcT304,selTransTbl[34]));
if((b=(objcT305=CompoundStmt,(*_imp(objcT305,selTransTbl[12]))(objcT305,selTransTbl[12])))){
id objcT306,objcT307,objcT308,objcT313,objcT314;
id objcT315,objcT316;

# 1270 "util.m"
int i,n;
id s=(objcT306=OrdCltn,(*_imp(objcT306,selTransTbl[12]))(objcT306,selTransTbl[12]));

(objcT307=s,(*_imp(objcT307,selTransTbl[31]))(objcT307,selTransTbl[31],mkfilesupermsg(ssel,e_aFiler)));
for(i=0,n=(objcT308=ivartypes,(*(unsigned(*)(id,SEL))_imp(objcT308,selTransTbl[69]))(objcT308,selTransTbl[69]));i<n;i++){
id objcT309,objcT310;

# 1275 "util.m"
if((objcT309=(objcT310=ivartypes,(*(id(*)(id,SEL,unsigned))_imp(objcT310,selTransTbl[70]))(objcT310,selTransTbl[70],i)),(*(BOOL(*)(id,SEL))_imp(objcT309,selTransTbl[96]))(objcT309,selTransTbl[96]))){
id objcT311,objcT312;

# 1276 "util.m"
(objcT311=s,(*_imp(objcT311,selTransTbl[31]))(objcT311,selTransTbl[31],mkfilemsg(fsel,(objcT312=ivarnames,(*(id(*)(id,SEL,unsigned))_imp(objcT312,selTransTbl[70]))(objcT312,selTransTbl[70],i)))));
}
}
(objcT313=s,(*_imp(objcT313,selTransTbl[31]))(objcT313,selTransTbl[31],mkreturnx((objcT314=e_self,(*_imp(objcT314,selTransTbl[97]))(objcT314,selTransTbl[97])))));
(objcT315=b,(*_imp(objcT315,selTransTbl[52]))(objcT315,selTransTbl[52],s));
(objcT316=r,(*_imp(objcT316,selTransTbl[37]))(objcT316,selTransTbl[37],b));
}
return r;
}

id
mkfileinmeth(id classdef,id ivarnames,id ivartypes)
{
return mkfileinoutmeth(s_fileInIdsFrom,s_fileIn,ivarnames,ivartypes);
}

id
mkfileoutmeth(id classdef,id ivarnames,id ivartypes)
{
return mkfileinoutmeth(s_fileOutIdsFor,s_fileOut,ivarnames,ivartypes);
}

id
mkrefsupermsg(id sel)
{
id objcT317,objcT318,objcT319;

# 1301 "util.m"
id usel,m;

m=(objcT317=MesgExpr,(*_imp(objcT317,selTransTbl[12]))(objcT317,selTransTbl[12]));
(objcT318=m,(*_imp(objcT318,selTransTbl[38]))(objcT318,selTransTbl[38],e_super));
usel=sel;
(objcT319=m,(*_imp(objcT319,selTransTbl[39]))(objcT319,selTransTbl[39],mkmethproto((id)0,usel,(id)0,(BOOL)0)));
return mkexprstmtx(m);
}

id
mkrefmeth(id classdef,id ivarnames,id ivartypes,id ssel,id sfun)
{
id objcT320,objcT321,objcT322,objcT323,objcT327;
id objcT328;

# 1313 "util.m"
id d,b,r;
id usel=(objcT320=Selector,(*(id(*)(id,SEL,STR))_imp(objcT320,selTransTbl[9]))(objcT320,selTransTbl[9],(objcT321=ssel,(*(STR(*)(id,SEL))_imp(objcT321,selTransTbl[90]))(objcT321,selTransTbl[90]))));

r=(objcT322=MethodDef,(*_imp(objcT322,selTransTbl[12]))(objcT322,selTransTbl[12]));
if((d=(objcT323=Method,(*_imp(objcT323,selTransTbl[12]))(objcT323,selTransTbl[12])))){
id objcT324,objcT325,objcT326;

# 1318 "util.m"
(objcT324=d,(*_imp(objcT324,selTransTbl[86]))(objcT324,selTransTbl[86],usel));
(objcT325=d,(*(id(*)(id,SEL,BOOL))_imp(objcT325,selTransTbl[95]))(objcT325,selTransTbl[95],(BOOL)0));
(objcT326=r,(*_imp(objcT326,selTransTbl[33]))(objcT326,selTransTbl[33],d));
}
(objcT327=r,(*_imp(objcT327,selTransTbl[34]))(objcT327,selTransTbl[34]));
if((b=(objcT328=CompoundStmt,(*_imp(objcT328,selTransTbl[12]))(objcT328,selTransTbl[12])))){
id objcT329,objcT330,objcT331,objcT336,objcT337;
id objcT338,objcT339;

# 1324 "util.m"
int i,n;
id s=(objcT329=OrdCltn,(*_imp(objcT329,selTransTbl[12]))(objcT329,selTransTbl[12]));
id f=mkidentexpr(sfun);

(objcT330=s,(*_imp(objcT330,selTransTbl[31]))(objcT330,selTransTbl[31],mkrefsupermsg(usel)));
for(i=0,n=(objcT331=ivartypes,(*(unsigned(*)(id,SEL))_imp(objcT331,selTransTbl[69]))(objcT331,selTransTbl[69]));i<n;i++){
id objcT332,objcT333;

# 1330 "util.m"
if((objcT332=(objcT333=ivartypes,(*(id(*)(id,SEL,unsigned))_imp(objcT333,selTransTbl[70]))(objcT333,selTransTbl[70],i)),(*(BOOL(*)(id,SEL))_imp(objcT332,selTransTbl[71]))(objcT332,selTransTbl[71]))){
id objcT334,objcT335;

# 1331 "util.m"
id e=mkidentexpr((objcT334=ivarnames,(*(id(*)(id,SEL,unsigned))_imp(objcT334,selTransTbl[70]))(objcT334,selTransTbl[70],i)));

(objcT335=s,(*_imp(objcT335,selTransTbl[31]))(objcT335,selTransTbl[31],mkexprstmtx(mkassignexpr(e,"=",mkfuncall(f,mklist((id)0,e))))));
}
}
(objcT336=s,(*_imp(objcT336,selTransTbl[31]))(objcT336,selTransTbl[31],mkreturnx((objcT337=e_nil,(*_imp(objcT337,selTransTbl[97]))(objcT337,selTransTbl[97])))));
(objcT338=b,(*_imp(objcT338,selTransTbl[52]))(objcT338,selTransTbl[52],s));
(objcT339=r,(*_imp(objcT339,selTransTbl[37]))(objcT339,selTransTbl[37],b));
}
return r;
}

id
mkincrefsmeth(id classdef,id ivarnames,id ivartypes)
{
return mkrefmeth(classdef,ivarnames,ivartypes,s_increfs,s_idincref);
}

id
mkdecrefsmeth(id classdef,id ivarnames,id ivartypes)
{
return mkrefmeth(classdef,ivarnames,ivartypes,s_decrefs,s_iddecref);
}
static char *_selTransTbl[] ={
"synth",
"gen",
"st80",
"numidivars",
"synthfilermethods",
"synthrefcntmethods",
"isimpl",
"warnimplnotfound",
"chars:count:",
"str:",
"str",
"str:lineno:filename:",
"new",
"expr:",
"forcenewline:",
"label:",
"stmt:",
"keyw:",
"ekeyw:",
"estmt:",
"wkeyw:",
"begin:cond:step:",
"cast:",
"lhs:",
"rhs:",
"op:",
"funname:",
"funargs:",
"datadefs:",
"compound:",
"specs:",
"add:",
"factory:",
"method:",
"prototype",
"datadefspecs:",
"decl:",
"body:",
"receiver:",
"msg:",
"identifier:",
"typequals:",
"args:",
"prefix:",
"postfix:",
"pointer:",
"stringchain:",
"typequal:",
"asmop1:",
"asmop2:",
"clobbers:",
"lbrace:",
"stmts:",
"subblock:",
"rbrace:",
"superclassdef",
"addAll:",
"ivars",
"lookupclass:",
"parms:",
"classname",
"checksupername:",
"checkivars:",
"checkcvars:",
"classname:",
"supername:",
"ivars:",
"cvars:",
"forceimpl",
"size",
"at:",
"isid",
"isKindOf:",
"class",
"specs",
"initializer:",
"name:",
"enumtors:",
"value:",
"anyword:",
"exprlist:",
"attribs:",
"exprs:",
"defs:",
"arg:",
"restype:",
"unarysel:",
"keywsel:",
"varargs:",
"setbracedgroup:",
"strCopy",
"idents:",
"parmdefs:",
"addcol",
"selector:",
"canforward:",
"isrefcounted",
"copy",
0
};
struct modDescriptor util_modDesc = {
  "util",
  "objc3.3.19",
  0L,
  0,
  0,
  0,
  98,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_util(void)
{
  selTransTbl = _selTransTbl;
  return &util_modDesc;
}
int _OBJCPOSTLINK_util = 1;


