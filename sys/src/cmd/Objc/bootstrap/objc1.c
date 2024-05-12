# 1 "objc1.m"
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
extern struct modDescriptor  *_OBJCBIND_objc1(void);
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
extern struct modDescriptor objc1_modDesc;

# 1 "../../util//string.h"
#include <string.h>

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
# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 22 "./../oclib/node.h"
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
# 22 "./../oclib/trlunit.h"
extern id trlunit;
# 22 "./../oclib/options.h"
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
# 23 "./../oclib/util.h"
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
# 22 "./../oclib/symbol.h"
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

# 38 "objc1.m"
void printversion(void)
{
printf("%s\n","3.3.38");
exit(0);
}

void printcopyright(void)
{
printf("Portable Object Compiler %s (c) 1997-2023.\n","3.3.38");
printf("Distributed under the terms of the GNU LGPL.\n");
}

void unknownoption(char*arg)
{
STR msg="%s: unknown option %s\n";
STR name=(o_cplus)?"objcpls1":"objc1";
fprintf(stderr,msg,name,arg);
exit(1);
}

void badarg(id option,id arg)
{
id objcT0,objcT1;

# 60 "objc1.m"
STR msg="%s: illegal argument %s for %s\n";
STR name=(o_cplus)?"objcpls1":"objc1";
fprintf(stderr,msg,name,(objcT0=arg,(*(STR(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0])),(objcT1=option,(*(STR(*)(id,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0])));
exit(1);
}

BOOL isoption(char*s)
{
return s!=NULL&&s[0]=='-';
}

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 71 "objc1.m"
id optionstok(id aCltn,char*s)
{
id objcT2,objcT3;

# 73 "objc1.m"
char*p;
char*delims=" \t\n\r";
id buffer=(objcT2=String,(*(id(*)(id,SEL,STR))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1],s));

p=strtok((objcT3=buffer,(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0])),delims);

while(p!=NULL){
id objcT4,objcT5;

# 80 "objc1.m"
(objcT4=aCltn,(*_imp(objcT4,selTransTbl[2]))(objcT4,selTransTbl[2],(objcT5=String,(*(id(*)(id,SEL,STR))_imp(objcT5,selTransTbl[1]))(objcT5,selTransTbl[1],p))));
p=strtok(NULL,delims);
}

return aCltn;
}

id optsfromfile(id aCltn,FILE*f)
{
char buf[BUFSIZ+1];

while( !feof(f)){
if(fgets(buf,BUFSIZ,f)){

optionstok(aCltn,buf);
}
}

return aCltn;
}



id optsnamed(id aCltn,STR s)
{
STR t;
FILE*f;


if((t=getenv(s)))
return optionstok(aCltn,t);


if((f=fopen(s,"r"))){
aCltn=optsfromfile(aCltn,f);
fclose(f);
return aCltn;
}

return(id)0;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 122 "objc1.m"
id cmdlineopts(int argc,char*argv[])
{
id objcT6;

# 124 "objc1.m"
int i;
id aCltn=(objcT6=OrdCltn,(*_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3]));

for(i=1;i<argc;i++){
id objcT7,objcT8;

# 128 "objc1.m"
(objcT7=aCltn,(*_imp(objcT7,selTransTbl[2]))(objcT7,selTransTbl[2],(objcT8=String,(*(id(*)(id,SEL,STR))_imp(objcT8,selTransTbl[1]))(objcT8,selTransTbl[1],argv[i]))));
}

return aCltn;
}

# 139 "objc1.m"
int setfilename(id option,id args)
{
id objcT9,objcT10;

# 141 "objc1.m"
id arg=(objcT9=args,(*_imp(objcT9,selTransTbl[4]))(objcT9,selTransTbl[4]));
char*t=(objcT10=arg,(*(STR(*)(id,SEL))_imp(objcT10,selTransTbl[0]))(objcT10,selTransTbl[0]));

if(isoption(t))badarg(option,arg);
o_srcfilename=t;

return 0;
}

int setinitcall(id option,id args)
{
id objcT11,objcT12;

# 152 "objc1.m"
id arg=(objcT11=args,(*_imp(objcT11,selTransTbl[4]))(objcT11,selTransTbl[4]));
char*t=(objcT12=arg,(*(STR(*)(id,SEL))_imp(objcT12,selTransTbl[0]))(objcT12,selTransTbl[0]));

if(isoption(t))badarg(option,arg);
o_initcall=t;

return 0;
}

int setbrowsedir(id option,id args)
{
id objcT13,objcT14;

# 163 "objc1.m"
id arg=(objcT13=args,(*_imp(objcT13,selTransTbl[4]))(objcT13,selTransTbl[4]));
char*t=(objcT14=arg,(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[0]))(objcT14,selTransTbl[0]));

if(isoption(t))badarg(option,arg);
o_browsedir=t;

return 0;
}

int setmainfun(id option,id args)
{
id objcT15,objcT16,objcT17;

# 174 "objc1.m"
id arg=(objcT15=args,(*_imp(objcT15,selTransTbl[4]))(objcT15,selTransTbl[4]));
if(isoption((objcT16=arg,(*(STR(*)(id,SEL))_imp(objcT16,selTransTbl[0]))(objcT16,selTransTbl[0]))))badarg(option,arg);
o_mainfun=(objcT17=arg,(*(STR(*)(id,SEL))_imp(objcT17,selTransTbl[0]))(objcT17,selTransTbl[0]));
return 0;
}

int setbind(id option,id args)
{
id objcT18,objcT19,objcT20;

# 182 "objc1.m"
id arg=(objcT18=args,(*_imp(objcT18,selTransTbl[4]))(objcT18,selTransTbl[4]));
if(isoption((objcT19=arg,(*(STR(*)(id,SEL))_imp(objcT19,selTransTbl[0]))(objcT19,selTransTbl[0]))))badarg(option,arg);
o_bind=(objcT20=arg,(*(STR(*)(id,SEL))_imp(objcT20,selTransTbl[0]))(objcT20,selTransTbl[0]));
return 0;
}

# 192 "objc1.m"
int setlinemax(id option,id args)
{
id objcT21,objcT22,objcT23;

# 194 "objc1.m"
id arg=(objcT21=args,(*_imp(objcT21,selTransTbl[4]))(objcT21,selTransTbl[4]));
if(isoption((objcT22=arg,(*(STR(*)(id,SEL))_imp(objcT22,selTransTbl[0]))(objcT22,selTransTbl[0]))))badarg(option,arg);
o_linemax=(objcT23=arg,(*(int(*)(id,SEL))_imp(objcT23,selTransTbl[5]))(objcT23,selTransTbl[5]));
return 0;
}
# 205 "objc1.m"
void setoptions(id aCltn);

int setoptsfromfile(id option,id args)
{
id objcT24,objcT25,objcT26,objcT27;

# 209 "objc1.m"
id arg=(objcT24=args,(*_imp(objcT24,selTransTbl[4]))(objcT24,selTransTbl[4]));

if(isoption((objcT25=arg,(*(STR(*)(id,SEL))_imp(objcT25,selTransTbl[0]))(objcT25,selTransTbl[0]))))badarg(option,arg);
setoptions(optsnamed((objcT26=OrdCltn,(*_imp(objcT26,selTransTbl[3]))(objcT26,selTransTbl[3])),(objcT27=arg,(*(STR(*)(id,SEL))_imp(objcT27,selTransTbl[0]))(objcT27,selTransTbl[0]))));
return 0;
}

# 220 "objc1.m"
int addbuiltintype(id option,id args)
{
id objcT28,objcT29,objcT30;

# 222 "objc1.m"
id arg=(objcT28=args,(*_imp(objcT28,selTransTbl[4]))(objcT28,selTransTbl[4]));
if(isoption((objcT29=arg,(*(STR(*)(id,SEL))_imp(objcT29,selTransTbl[0]))(objcT29,selTransTbl[0]))))badarg(option,arg);
definebuiltintype((objcT30=arg,(*(STR(*)(id,SEL))_imp(objcT30,selTransTbl[0]))(objcT30,selTransTbl[0])));
return 0;
}

int addbuiltinfun(id option,id args)
{
id objcT31,objcT32,objcT33;

# 230 "objc1.m"
id arg=(objcT31=args,(*_imp(objcT31,selTransTbl[4]))(objcT31,selTransTbl[4]));
if(isoption((objcT32=arg,(*(STR(*)(id,SEL))_imp(objcT32,selTransTbl[0]))(objcT32,selTransTbl[0]))))badarg(option,arg);
definebuiltinfun((objcT33=arg,(*(STR(*)(id,SEL))_imp(objcT33,selTransTbl[0]))(objcT33,selTransTbl[0])));
return 0;
}

void setoptions(id aCltn)
{
id objcT34,objcT35;

# 238 "objc1.m"
id args,s;
int filecount=0;
BOOL checkoption=(BOOL)1;

args=(objcT34=aCltn,(*_imp(objcT34,selTransTbl[6]))(objcT34,selTransTbl[6]));

while((s=(objcT35=args,(*_imp(objcT35,selTransTbl[4]))(objcT35,selTransTbl[4])))){
id objcT36;

# 245 "objc1.m"
char*t=(objcT36=s,(*(STR(*)(id,SEL))_imp(objcT36,selTransTbl[0]))(objcT36,selTransTbl[0]));
if( !strcmp(t,"-quiet")){ ++
o_quiet;
}else if( !strcmp(t,"-z")){ ++
o_outputcode;
}else if( !strcmp(t,"@")){
setoptsfromfile(s,args);
}else if( !strcmp(t,"-u")){
o_buffered=0;
}else if( !strcmp(t,"-version")){
o_version++;
}else if( !strcmp(t,"-otb")){
o_otb++;
o_shareddata=0;
}else if( !strcmp(t,"-gnu")){
o_gnu++;
}else if( !strcmp(t,"-darwin")){
o_darwin++;
}else if( !strcmp(t,"-vms")){
o_vms++;
}else if( !strcmp(t,"-hpux")){
o_hpux++;
}else if( !strcmp(t,"-sunstudio")){
o_sunstudio++;
}else if( !strcmp(t,"-m64")){
o_m64++;
}else if( !strcmp(t,"-refcnt")){
o_refcnt++;
o_selfassign=0;
}else if( !strcmp(t,"-noasm")){
o_enableasm=0;
}else if( !strcmp(t,"-nolonglong")){
o_llkeyw=0;
}else if( !strcmp(t,"-msdos")){
# 284 "objc1.m"
o_msdos++;
}else if( !strcmp(t,"-watcom")){
o_watcom++;
}else if( !strcmp(t,"-comments")){
o_comments++;
}else if( !strcmp(t,"-duptypedefs")){
o_duptypedefs++;
}else if( !strcmp(t,"-ibmvac")){
o_ibmvac++;
}else if( !strcmp(t,"-noSelTbl")){
o_seltranslation=0;
}else if( !strcmp(t,"-noCategories")){
o_categories=0;
}else if( !strcmp(t,"-noBlocks")){
o_blocks=0;
}else if( !strcmp(t,"-st80")){
o_st80++;
o_nolinetags++;
o_outputcode=0;
}else if( !strcmp(t,"-fwd")){
o_fwd++;
}else if( !strcmp(t,"-noSelPtr")){
o_selptr=0;
}else if( !strcmp(t,"-noFwd")){
o_fwd=0;
}else if( !strcmp(t,"-noCache")){
o_cache=0;
}else if( !strcmp(t,"-noFiler")){
o_filer=0;
}else if( !strcmp(t,"-noSelfAssign")){
o_selfassign=0;
}else if( !strcmp(t,"-noNilRcvr")){
o_nilrcvr=0;
}else if( !strcmp(t,"-objc")){
o_gencode=0;
}else if( !strcmp(t,"-cplus")){
o_cplus++;
}else if( !strcmp(t,"-inlinecache")){
o_inlinecache++;
}else if( !strcmp(t,"-refBind")){
o_refbind++;
}else if( !strcmp(t,"-export")){
setbind(s,args);
}else if( !strcmp(t,"-dllexport")){
o_bind="__declspec(dllexport)";
}else if( !strcmp(t,"-traditional")){
}else if( !strcmp(t,"-filename")){
setfilename(s,args);
}else if( !strcmp(t,"-longlinetag")){
}else if( !strcmp(t,"-shortTags")){
o_tagformat="# %d \"%s\"\n";
}else if( !strcmp(t,"-init")){
setinitcall(s,args);
}else if( !strcmp(t,"-browse")){
setbrowsedir(s,args);
o_nolinetags++;
o_outputcode=0;
}else if( !strcmp(t,"-noShared")){
o_shareddata=0;
}else if( !strcmp(t,"-main")){
setmainfun(s,args);
}else if( !strcmp(t,"-linemax")){
setlinemax(s,args);
}else if( !strcmp(t,"-builtinfunction")){
addbuiltinfun(s,args);
}else if( !strcmp(t,"-builtintype")){
addbuiltintype(s,args);
}else if( !strcmp(t,"-nolinetags")){
o_nolinetags++;
}else if( !strcmp(t,"-oneperfile")){
o_oneperfile++;
}else if( !strcmp(t,"-w")){
o_warnings=0;
}else if( !strcmp(t,"-wClassUsedAsType")){
o_warnclasstype=0;
}else if( !strcmp(t,"-wMissing")){
o_warnmissingmethods=0;
}else if( !strcmp(t,"-wTypeConflict")){
o_warntypeconflict=0;
}else if( !strcmp(t,"-wLocalInstance")){
o_warnlocalnst=0;
}else if( !strcmp(t,"-wUndefinedMethod")){
o_warnundefined=0;
}else if( !strcmp(t,"-wInterfaceNotFound")){
o_warnnotfound=0;
}else if( !strcmp(t,"-WLex")){
o_warnlex++;
}else if( !strcmp(t,"-WFwd")){
o_warnfwd++;
}else if( !strcmp(t,"-postlink")){
o_postlink++;
}else if( !strcmp(t,"-attrcommon")){
o_attrcommon++;
}else if( !strcmp(t,"-checkbindfunction")){
o_checkbind++;
}else if( !strcmp(t,"-debugInfo")){
o_debuginfo++;
}else if( !strcmp(t,"-ppi")){
o_ppi++;
}else if( !strcmp(t,"-")){
checkoption=0;
}else if(checkoption&&isoption(t)){
unknownoption(t);
}else if(filecount==0){
o_infile=t;
filecount++;
}else if(filecount==1){
o_outfile=t;
filecount++;
}else{
unknownoption(t);
}
}
}

# 404 "objc1.m"
void openinfile(void)
{
if(o_infile){
yyin=openfile(o_infile,"r");
}else{

}
}

void setfirstlinetag(void)
{
id objcT41,objcT42,objcT43;

inlineno=1;
if(o_srcfilename){
id objcT37;

# 419 "objc1.m"
infilename=(objcT37=String,(*(id(*)(id,SEL,STR))_imp(objcT37,selTransTbl[1]))(objcT37,selTransTbl[1],o_srcfilename));
}else{
if(o_infile){
id objcT38;

# 422 "objc1.m"
infilename=(objcT38=String,(*(id(*)(id,SEL,STR))_imp(objcT38,selTransTbl[1]))(objcT38,selTransTbl[1],o_infile));
}else{
id objcT39;

# 424 "objc1.m"
infilename=(objcT39=String,(*(id(*)(id,SEL,STR))_imp(objcT39,selTransTbl[1]))(objcT39,selTransTbl[1],"-=stdin=-"));
}
}

if( !o_nolinetags){
id objcT40;

# 429 "objc1.m"
gl(inlineno,(objcT40=infilename,(*(STR(*)(id,SEL))_imp(objcT40,selTransTbl[0]))(objcT40,selTransTbl[0])));
}

(void)0;
(objcT41=trlunit,(*(id(*)(id,SEL,char*))_imp(objcT41,selTransTbl[7]))(objcT41,selTransTbl[7],"objc3.3.38"));
(objcT42=trlunit,(*(id(*)(id,SEL,char*))_imp(objcT42,selTransTbl[8]))(objcT42,selTransTbl[8],(objcT43=infilename,(*(STR(*)(id,SEL))_imp(objcT43,selTransTbl[0]))(objcT43,selTransTbl[0]))));

if(o_vms){
definebuiltinfun("__VA_START_BUILTIN");
definebuiltinfun("__IS_X_FLOAT_BUILTIN");
definebuiltintype("__int64");
}

if(o_hpux){
definebuiltinfun("__va_start__");
definebuiltinfun("__va_arg__");
definebuiltintype("__va_list__");
definebuiltintype("__fpreg");
definebuiltintype("__float80");
}

if(o_darwin){


definebuiltinvar("message");
definebuiltinvar("ios");
definebuiltinvar("tvos");
definebuiltinvar("watchos");
definebuiltinvar("swift");
definebuiltinvar("macos");
definebuiltinvar("macosx");
definebuiltinvar("introduced");
definebuiltinvar("unavailable");
}

if(o_gnu){
definebuiltintype("__float128");
definebuiltinfun("__builtin_bswap16");
definebuiltinfun("__builtin_saveregs");
definebuiltinfun("__builtin_classify_type");
definebuiltinfun("__builtin_isfloat");
definebuiltinfun("__builtin_classof");
definebuiltinfun("__alignof");
definebuiltinfun("_Alignof");
definebuiltinfun("__alignof__");
definebuiltinfun("__ALIGNOF__");
definebuiltinfun("__builtin_alignof");
definebuiltinfun("__builtin_next_arg");

definebuiltinfun("__builtin_memcpy");
definebuiltinfun("__builtin_memset");
definebuiltinfun("__builtin_fabs");
definebuiltinfun("__builtin_fabsl");
definebuiltinfun("__builtin_fabsf");
definebuiltinfun("__builtin_constant_p");
definebuiltinvar("__func__");
definebuiltinvar("__FUNCTION__");
definebuiltinvar("__PRETTY_FUNCTION__");
definebuiltinvar("_VA_FP_SAVE_AREA");
definebuiltintype("__builtin_va_list");
definebuiltinfun("__builtin_stdarg_start");
definebuiltinfun("__builtin_va_end");
definebuiltinfun("__builtin_va_arg");

if( !(o_sunstudio&&o_m64))definebuiltinfun("__builtin_va_start");
definebuiltinfun("__builtin_expect");
definebuiltinfun("__builtin_strchr");
definebuiltinfun("__builtin_strcmp");
definebuiltinfun("__builtin_strncmp");
definebuiltinfun("__builtin_offsetof");
definebuiltinfun("__builtin_strncpy");


definebuiltinfun("__builtin_strlen");
definebuiltinfun("__builtin_object_size");
definebuiltinfun("__builtin_va_arg_pack");
definebuiltinfun("__builtin___sprintf_chk");
definebuiltinfun("__builtin___vsprintf_chk");
definebuiltinfun("__builtin___snprintf_chk");
definebuiltinfun("__builtin___vsnprintf_chk");
definebuiltinfun("__builtin___strcpy_chk");
definebuiltinfun("__builtin___strncpy_chk");
definebuiltinfun("__builtin___strcat_chk");
definebuiltinfun("__builtin___strncat_chk");
definebuiltinfun("__builtin___memmove_chk");
definebuiltinfun("__builtin___memset_chk");
definebuiltinfun("__builtin___memcpy_chk");


definebuiltinfun("__builtin_bswap32");
definebuiltinfun("__builtin_bswap64");
# 523 "objc1.m"
definebuiltinfun("__builtin___stpcpy_chk");
# 527 "objc1.m"
definebuiltinvar("__builtin_va_alist");
if( !(o_sunstudio&&o_m64))definebuiltinfun("__builtin_va_arg_incr");
}
}

void closeinfile(void)
{
if(o_infile){
fclose(yyin);
}else{

}
}

void openoutfile(void)
{
if(o_outfile){
gfile=openfile(o_outfile,"w");
}else{
gfile=stdout;
}


if( !o_buffered)setbuf(gfile,NULL);
}

void closeoutfile(void)
{
if(o_outfile)fclose(gfile);
}

# 24 "./../oclib/trlunit.h"
extern id  TranslationUnit;

# 558 "objc1.m"
int objcmain(int argc,char*argv[])
{
id objcT44,objcT45,objcT46,objcT47;
trlunit=(objcT44=TranslationUnit,(*_imp(objcT44,selTransTbl[3]))(objcT44,selTransTbl[3]));

defoptions();
setoptions(cmdlineopts(argc,argv));

if(o_version)printversion();
if( !o_quiet)printcopyright();

openinfile();
openoutfile();

setfirstlinetag();

if(o_outputcode)(objcT45=trlunit,(*_imp(objcT45,selTransTbl[9]))(objcT45,selTransTbl[9]));
if(yyparse())exit(1);
if(o_outputcode)(objcT46=trlunit,(*_imp(objcT46,selTransTbl[10]))(objcT46,selTransTbl[10]));

closeinfile();
closeoutfile();

if(o_browsedir)(objcT47=trlunit,(*_imp(objcT47,selTransTbl[11]))(objcT47,selTransTbl[11]));

exit(exitstatus);
return 0;
}
extern int oc_objcInit(int debug,int traceInit);

# 558 "objc1.m"
int main(int argc,char*argv[]){
oc_objcInit(0,0);
return objcmain(argc,argv);
}

static char *_selTransTbl[] ={
"str",
"str:",
"add:",
"new",
"next",
"asInt",
"eachElement",
"setmodversion:",
"setmodname:",
"prologue",
"epilogue",
"browse",
0
};
struct modDescriptor objc1_modDesc = {
  "objc1",
  "objc3.3.19",
  0L,
  0,
  0,
  0,
  12,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_objc1(void)
{
  selTransTbl = _selTransTbl;
  return &objc1_modDesc;
}
int _OBJCPOSTLINK_objc1 = 1;
struct useDescriptor *OCU_main = 0;


