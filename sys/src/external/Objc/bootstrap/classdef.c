# 1 "classdef.m"
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
extern struct modDescriptor  *_OBJCBIND_classdef(void);
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
extern struct modDescriptor classdef_modDesc;

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
# 22 "./classdef.h"
extern id curclassdef;
extern id curstruct;
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
# 22 "./def.h"
extern id curdef;
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
# 22 "./expr.h"
extern id e_nil;
extern id e_self;
extern id e_cmd;
extern id e_super;
extern id e_aFiler;
extern id e_ft_id;
# 22 "./msgxpr.h"
extern id msgwraps;
# 50 "classdef.m"
id curclassdef;
# 25 "./classdef.h"
struct ClassDef_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 27 "./classdef.h"
id unit;
id selftype;
id classname;
char*otbtypename;
char*privtypename;
char*shartypename;
char*clsdisptblname;
char*nstdisptblname;
char*globfunname;
char*_classname;
char*_classfunname;
char*_superfunname;
char*_m_classname;
char*_m_classfunname;
char*_m_superfunname;
id rootc;
id superc;
id supername;
id ivars,cvars;
BOOL emitintf;
BOOL emitimpl;
BOOL emitfwddecl;
BOOL isimpl;
BOOL iscategory;
id clsdispsels,nstdispsels;
id clsdisptbl;
id nstdisptbl;
id clssels;
id nstsels;
id compdic,compnames,comptypes;
id ivardic,ivarnames,ivartypes;
id cvardic,cvarnames,cvartypes;
id allivarnames,allcvarnames;
id fileinmethod,fileoutmethod;
id decrefsmethod,increfsmethod;
int offset;};

# 25 "./classdef.h"
extern id  ClassDef;

# 25 "./classdef.h"
extern struct _SHARED _ClassDef;
extern struct _SHARED __ClassDef;


# 54 "classdef.m"
static int i_ClassDef_compare_(struct ClassDef_PRIVATE *self,SEL _cmd,id b)
{
id objcT0,objcT1;

# 56 "classdef.m"
int c;
char*s1,*s2;
s1=(objcT0=(id)self,(*(char*(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
s2=(objcT1=b,(*(char*(*)(id,SEL))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0]));
c=strcmp(s1,s2);
return c;
}

static char*i_ClassDef_privtypename(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->privtypename;
}

# 34 "./type.h"
extern id  Type;

# 59 "./symbol.h"
extern id  Symbol;

# 22 "./pointer.h"
extern id  Pointer;

# 69 "classdef.m"
static id i_ClassDef_selftype(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if( !self->selftype){
id objcT2,objcT3,objcT4,objcT5,objcT6;

# 72 "classdef.m"
(void)0;self->
selftype=(objcT2=Type,(*_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1]));
(objcT3=self->selftype,(*_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],(objcT4=Symbol,(*(id(*)(id,SEL,STR,...))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3],"struct %s",self->privtypename))));
(objcT5=self->selftype,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4],(objcT6=Pointer,(*_imp(objcT6,selTransTbl[1]))(objcT6,selTransTbl[1]))));
}
return self->selftype;
}

static char*i_ClassDef_shartypename(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->shartypename;
}

static char*i_ClassDef_otbtypename(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->otbtypename;
}

static id i_ClassDef_shartypename_(struct ClassDef_PRIVATE *self,SEL _cmd,char*s)
{self->

shartypename=s;
return(id)self;
}

static id c_ClassDef_new(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT7,objcT8;

# 99 "classdef.m"
return(objcT7=(objcT8=__ClassDef.clsSuper,(*_impSuper(objcT8,selTransTbl[1]))((id)self,selTransTbl[1])),(*(id(*)(id,SEL,char*))_imp(objcT7,selTransTbl[5]))(objcT7,selTransTbl[5],"_SHARED"));
}

static id i_ClassDef_warnpending(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT9;

# 104 "classdef.m"
warn("definition of %s not properly ended.",(objcT9=(id)self,(*(char*(*)(id,SEL))_imp(objcT9,selTransTbl[0]))(objcT9,selTransTbl[0])));
return(id)self;
}

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 108 "classdef.m"
static id i_ClassDef_classname_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym)
{
id objcT10,objcT11,objcT18,objcT19,objcT20;
id objcT21,objcT22,objcT23,objcT24,objcT25;
id objcT26,objcT27,objcT28,objcT29,objcT30;
id objcT31;

# 110 "classdef.m"
char*s;

(void)0;self->
classname=sym;
s=(objcT10=self->classname,(*(STR(*)(id,SEL))_imp(objcT10,selTransTbl[6]))(objcT10,selTransTbl[6]));
(objcT11=trlunit,(*_imp(objcT11,selTransTbl[7]))(objcT11,selTransTbl[7],sym,(id)self));

if(o_oneperfile){self->
privtypename="_PRIVATE";self->
clsdisptblname="_clsDispatchTbl";self->
nstdisptblname="_nstDispatchTbl";
}else{
id objcT12,objcT13,objcT14,objcT15,objcT16;
id objcT17;
self->
# 122 "classdef.m"
privtypename=(objcT12=(objcT13=String,(*(id(*)(id,SEL,STR,...))_imp(objcT13,selTransTbl[3]))(objcT13,selTransTbl[3],"%s_PRIVATE",s)),(*(STR(*)(id,SEL))_imp(objcT12,selTransTbl[8]))(objcT12,selTransTbl[8]));self->
clsdisptblname=(objcT14=(objcT15=String,(*(id(*)(id,SEL,STR,...))_imp(objcT15,selTransTbl[3]))(objcT15,selTransTbl[3],"_%s_clsDispatchTbl",s)),(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8]));self->
nstdisptblname=(objcT16=(objcT17=String,(*(id(*)(id,SEL,STR,...))_imp(objcT17,selTransTbl[3]))(objcT17,selTransTbl[3],"_%s_nstDispatchTbl",s)),(*(STR(*)(id,SEL))_imp(objcT16,selTransTbl[8]))(objcT16,selTransTbl[8]));
}self->
globfunname=(objcT18=(objcT19=String,(*(id(*)(id,SEL,STR,...))_imp(objcT19,selTransTbl[3]))(objcT19,selTransTbl[3],"OBJCCLASS_%s",s)),(*(STR(*)(id,SEL))_imp(objcT18,selTransTbl[8]))(objcT18,selTransTbl[8]));self->
_classfunname=(objcT20=(objcT21=String,(*(id(*)(id,SEL,STR,...))_imp(objcT21,selTransTbl[3]))(objcT21,selTransTbl[3],"OBJCCFUNC_%s",s)),(*(STR(*)(id,SEL))_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8]));self->
_superfunname=(objcT22=(objcT23=String,(*(id(*)(id,SEL,STR,...))_imp(objcT23,selTransTbl[3]))(objcT23,selTransTbl[3],"OBJCCSUPER_%s",s)),(*(STR(*)(id,SEL))_imp(objcT22,selTransTbl[8]))(objcT22,selTransTbl[8]));self->
_m_classfunname=(objcT24=(objcT25=String,(*(id(*)(id,SEL,STR,...))_imp(objcT25,selTransTbl[3]))(objcT25,selTransTbl[3],"OBJCMFUNC_%s",s)),(*(STR(*)(id,SEL))_imp(objcT24,selTransTbl[8]))(objcT24,selTransTbl[8]));self->
_m_superfunname=(objcT26=(objcT27=String,(*(id(*)(id,SEL,STR,...))_imp(objcT27,selTransTbl[3]))(objcT27,selTransTbl[3],"OBJCMSUPER_%s",s)),(*(STR(*)(id,SEL))_imp(objcT26,selTransTbl[8]))(objcT26,selTransTbl[8]));self->
_classname=(objcT28=(objcT29=String,(*(id(*)(id,SEL,STR,...))_imp(objcT29,selTransTbl[3]))(objcT29,selTransTbl[3],"_%s",s)),(*(STR(*)(id,SEL))_imp(objcT28,selTransTbl[8]))(objcT28,selTransTbl[8]));self->
_m_classname=(objcT30=(objcT31=String,(*(id(*)(id,SEL,STR,...))_imp(objcT31,selTransTbl[3]))(objcT31,selTransTbl[3],"__%s",s)),(*(STR(*)(id,SEL))_imp(objcT30,selTransTbl[8]))(objcT30,selTransTbl[8]));
if(o_otb){
id objcT32,objcT33;
self->
# 134 "classdef.m"
otbtypename=(objcT32=(objcT33=String,(*(id(*)(id,SEL,STR,...))_imp(objcT33,selTransTbl[3]))(objcT33,selTransTbl[3],"%s_OTB",s)),(*(STR(*)(id,SEL))_imp(objcT32,selTransTbl[8]))(objcT32,selTransTbl[8]));
}
return(id)self;
}

static id i_ClassDef_checksupername_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym)
{
id objcT34,objcT36,objcT37,objcT38;

# 141 "classdef.m"
char*m="conflicting superclasses %s and %s for %s.";
char*n="conflicting superclass declarations for %s.";

if(sym==(id)0&&self->supername==(id)0)
return(id)self;
if(sym!=(id)0&&self->supername!=(id)0&&(objcT34=self->supername,(*(BOOL(*)(id,SEL,id))_imp(objcT34,selTransTbl[9]))(objcT34,selTransTbl[9],sym)))
return(id)self;
if(sym==(id)0||self->supername==(id)0){
id objcT35;

# 149 "classdef.m"
fatal(n,(objcT35=(id)self,(*(char*(*)(id,SEL))_imp(objcT35,selTransTbl[0]))(objcT35,selTransTbl[0])));
return(id)self;
}
fatalat(sym,m,(objcT36=sym,(*(STR(*)(id,SEL))_imp(objcT36,selTransTbl[6]))(objcT36,selTransTbl[6])),(objcT37=self->supername,(*(STR(*)(id,SEL))_imp(objcT37,selTransTbl[6]))(objcT37,selTransTbl[6])),(objcT38=(id)self,(*(char*(*)(id,SEL))_imp(objcT38,selTransTbl[0]))(objcT38,selTransTbl[0])));
return(id)self;
}

static id i_ClassDef_supername_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym)
{
id objcT39;
self->
# 158 "classdef.m"
supername=sym;
if(sym!=(id)0&&((self->superc=(objcT39=trlunit,(*_imp(objcT39,selTransTbl[10]))(objcT39,selTransTbl[10],sym)))==(id)0)){
id objcT40,objcT41;

# 160 "classdef.m"
fatal("cannot find %s superclass of %s",(objcT40=sym,(*(STR(*)(id,SEL))_imp(objcT40,selTransTbl[6]))(objcT40,selTransTbl[6])),(objcT41=(id)self,(*(char*(*)(id,SEL))_imp(objcT41,selTransTbl[0]))(objcT41,selTransTbl[0])));
}
return(id)self;
}

static char*i_ClassDef_classname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT42;

# 167 "classdef.m"
return(objcT42=self->classname,(*(STR(*)(id,SEL))_imp(objcT42,selTransTbl[6]))(objcT42,selTransTbl[6]));
}

static char*i_ClassDef_globfunname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->globfunname;
}

static char*i_ClassDef__classname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->_classname;
}

static char*i_ClassDef__m_classname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->_m_classname;
}

static char*i_ClassDef__classfunname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->_classfunname;
}

static char*i_ClassDef__m_classfunname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->_m_classfunname;
}

static char*i_ClassDef__superfunname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->_superfunname;
}

static char*i_ClassDef__m_superfunname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->_m_superfunname;
}

static char*i_ClassDef_supername(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT43;

# 207 "classdef.m"
return(self->supername)?(objcT43=self->supername,(*(STR(*)(id,SEL))_imp(objcT43,selTransTbl[6]))(objcT43,selTransTbl[6])):NULL;
}

static id i_ClassDef_superclassdef(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->superc;
}

static id i_ClassDef_rootclassdef(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if( !self->rootc){
id objcT44;

# 218 "classdef.m"
id p,q;

p=(id)self;
while((q=(objcT44=p,(*_imp(objcT44,selTransTbl[11]))(objcT44,selTransTbl[11])))){
p=q;
}self->
rootc=p;
}
return self->rootc;
}

static char*i_ClassDef_rootname(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT45,objcT46;

# 231 "classdef.m"
return(objcT45=(objcT46=(id)self,(*_imp(objcT46,selTransTbl[12]))(objcT46,selTransTbl[12])),(*(char*(*)(id,SEL))_imp(objcT45,selTransTbl[0]))(objcT45,selTransTbl[0]));
}

static int i_ClassDef_numidivars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT47;

# 236 "classdef.m"
int i,n;
int count=0;

if(self->ivars)
for(i=0,n=(objcT47=self->ivars,(*(unsigned(*)(id,SEL))_imp(objcT47,selTransTbl[13]))(objcT47,selTransTbl[13]));i<n;i++){
id objcT48,objcT49;

# 241 "classdef.m"
if((objcT48=(objcT49=self->ivartypes,(*(id(*)(id,SEL,unsigned))_imp(objcT49,selTransTbl[14]))(objcT49,selTransTbl[14],i)),(*(BOOL(*)(id,SEL))_imp(objcT48,selTransTbl[15]))(objcT48,selTransTbl[15])))
count++;
}
return count;
}

static id i_ClassDef_synthrefcntmethods(struct ClassDef_PRIVATE *self,SEL _cmd)
{

(void)0;
o_refcnt=0;

if(self->isimpl){
id objcT50,objcT52;

# 254 "classdef.m"
if( !self->nstdisptbl|| !(objcT50=self->nstdispsels,(*_imp(objcT50,selTransTbl[16]))(objcT50,selTransTbl[16],s_decrefs))){
id objcT51;
self->
# 255 "classdef.m"
decrefsmethod=mkdecrefsmeth(curclassdef,self->ivarnames,self->ivartypes);
(objcT51=self->decrefsmethod,(*_imp(objcT51,selTransTbl[17]))(objcT51,selTransTbl[17]));
}
if( !self->nstdisptbl|| !(objcT52=self->nstdispsels,(*_imp(objcT52,selTransTbl[16]))(objcT52,selTransTbl[16],s_increfs))){
id objcT53;
self->
# 259 "classdef.m"
increfsmethod=mkincrefsmeth(curclassdef,self->ivarnames,self->ivartypes);
(objcT53=self->increfsmethod,(*_imp(objcT53,selTransTbl[17]))(objcT53,selTransTbl[17]));
}
}
o_refcnt++;
return(id)self;
}

static id i_ClassDef_synthfilermethods(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(self->isimpl){
id objcT54,objcT56;

# 270 "classdef.m"
if( !self->nstdisptbl|| !(objcT54=self->nstdispsels,(*_imp(objcT54,selTransTbl[16]))(objcT54,selTransTbl[16],s_fileInIdsFrom))){
id objcT55;
self->
# 271 "classdef.m"
fileinmethod=mkfileinmeth(curclassdef,self->ivarnames,self->ivartypes);
(objcT55=self->fileinmethod,(*_imp(objcT55,selTransTbl[17]))(objcT55,selTransTbl[17]));
}
if( !self->nstdisptbl|| !(objcT56=self->nstdispsels,(*_imp(objcT56,selTransTbl[16]))(objcT56,selTransTbl[16],s_fileOutIdsFor))){
id objcT57;
self->
# 275 "classdef.m"
fileoutmethod=mkfileoutmeth(curclassdef,self->ivarnames,self->ivartypes);
(objcT57=self->fileoutmethod,(*_imp(objcT57,selTransTbl[17]))(objcT57,selTransTbl[17]));
}
}
return(id)self;
}

static id i_ClassDef_ivars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->ivars;
}

static id i_ClassDef_ivars_(struct ClassDef_PRIVATE *self,SEL _cmd,id aList)
{self->
ivars=aList;
return(id)self;
}

static id i_ClassDef_cvars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->cvars;
}

static id i_ClassDef_cvars_(struct ClassDef_PRIVATE *self,SEL _cmd,id aList)
{
if( !o_cvars)
fatal("class variables not allowed");self->
cvars=aList;
return(id)self;
}

static id i_ClassDef_checkvars____(struct ClassDef_PRIVATE *self,SEL _cmd,char*what,id names,id types,id aList)
{
if( !names){
id objcT58;

# 309 "classdef.m"
char*me=(objcT58=(id)self,(*(char*(*)(id,SEL))_imp(objcT58,selTransTbl[0]))(objcT58,selTransTbl[0]));

fatal("'%s' was previously declared without %s variables",me,what);
}else{
id objcT59,objcT60,objcT74,objcT76;

# 313 "classdef.m"
int i,n;
id outerstruct=curstruct;

curstruct=(id)self;
(void)0;
(objcT59=aList,(*(id(*)(id,SEL,SEL))_imp(objcT59,selTransTbl[18]))(objcT59,selTransTbl[18],selTransTbl[17]));
(void)0;
curstruct=outerstruct;
for(i=0,n=(objcT60=self->compnames,(*(unsigned(*)(id,SEL))_imp(objcT60,selTransTbl[13]))(objcT60,selTransTbl[13]));i<n;i++){
id objcT61;

# 322 "classdef.m"
if(i<(objcT61=names,(*(unsigned(*)(id,SEL))_imp(objcT61,selTransTbl[13]))(objcT61,selTransTbl[13]))){
id objcT62,objcT63,objcT64,objcT65,objcT66;
id objcT67;

# 323 "classdef.m"
id a=(objcT62=self->compnames,(*(id(*)(id,SEL,unsigned))_imp(objcT62,selTransTbl[14]))(objcT62,selTransTbl[14],i));
id b=(objcT63=self->comptypes,(*(id(*)(id,SEL,unsigned))_imp(objcT63,selTransTbl[14]))(objcT63,selTransTbl[14],i));


if( !(objcT64=a,(*(BOOL(*)(id,SEL,id))_imp(objcT64,selTransTbl[9]))(objcT64,selTransTbl[9],(objcT65=names,(*(id(*)(id,SEL,unsigned))_imp(objcT65,selTransTbl[14]))(objcT65,selTransTbl[14],i))))|| !(objcT66=b,(*(BOOL(*)(id,SEL,id))_imp(objcT66,selTransTbl[9]))(objcT66,selTransTbl[9],(objcT67=types,(*(id(*)(id,SEL,unsigned))_imp(objcT67,selTransTbl[14]))(objcT67,selTransTbl[14],i))))){
id objcT68,objcT69,objcT70,objcT71,objcT72;
id objcT73;

# 328 "classdef.m"
int no=(objcT68=(objcT69=names,(*(id(*)(id,SEL,unsigned))_imp(objcT69,selTransTbl[14]))(objcT69,selTransTbl[14],i)),(*(int(*)(id,SEL))_imp(objcT68,selTransTbl[19]))(objcT68,selTransTbl[19]));
char*fn=(objcT70=(objcT71=(objcT72=names,(*(id(*)(id,SEL,unsigned))_imp(objcT72,selTransTbl[14]))(objcT72,selTransTbl[14],i)),(*_imp(objcT71,selTransTbl[20]))(objcT71,selTransTbl[20])),(*(STR(*)(id,SEL))_imp(objcT70,selTransTbl[6]))(objcT70,selTransTbl[6]));
char*msg="%s variable '%s' conflicts with definition at %s:%d";

fatalat(a,msg,what,(objcT73=a,(*(STR(*)(id,SEL))_imp(objcT73,selTransTbl[6]))(objcT73,selTransTbl[6])),fn,no);
}
}
}
if(n!=(objcT74=names,(*(unsigned(*)(id,SEL))_imp(objcT74,selTransTbl[13]))(objcT74,selTransTbl[13]))){
id objcT75;

# 337 "classdef.m"
char*me=(objcT75=(id)self,(*(char*(*)(id,SEL))_imp(objcT75,selTransTbl[0]))(objcT75,selTransTbl[0]));

fatal("list of %s variables doesn't match '%s' interface",what,me);
}
(objcT76=(id)self,(*_imp(objcT76,selTransTbl[21]))(objcT76,selTransTbl[21]));
}
return(id)self;
}

static id i_ClassDef_checkivars_(struct ClassDef_PRIVATE *self,SEL _cmd,id aList)
{
id objcT77;

# 348 "classdef.m"
return(objcT77=(id)self,(*(id(*)(id,SEL,char*,id,id,id))_imp(objcT77,selTransTbl[22]))(objcT77,selTransTbl[22],"instance",self->ivarnames,self->ivartypes,aList));
}

static id i_ClassDef_checkcvars_(struct ClassDef_PRIVATE *self,SEL _cmd,id aList)
{
id objcT78;

# 353 "classdef.m"
return(objcT78=(id)self,(*(id(*)(id,SEL,char*,id,id,id))_imp(objcT78,selTransTbl[22]))(objcT78,selTransTbl[22],"class",self->cvarnames,self->cvartypes,aList));
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 36 "./../../include/objpak/set.h"
extern id  Set;

# 356 "classdef.m"
static id i_ClassDef_addclsdisp_(struct ClassDef_PRIVATE *self,SEL _cmd,id method)
{
id objcT81,objcT82,objcT83;

# 358 "classdef.m"
if( !self->clsdisptbl){
id objcT79,objcT80;
self->
# 359 "classdef.m"
clsdisptbl=(objcT79=OrdCltn,(*_imp(objcT79,selTransTbl[1]))(objcT79,selTransTbl[1]));self->
clsdispsels=(objcT80=Set,(*_imp(objcT80,selTransTbl[1]))(objcT80,selTransTbl[1]));
}
(void)0;
(objcT81=self->clsdisptbl,(*_imp(objcT81,selTransTbl[23]))(objcT81,selTransTbl[23],method));
(objcT82=self->clsdispsels,(*_imp(objcT82,selTransTbl[23]))(objcT82,selTransTbl[23],(objcT83=method,(*_imp(objcT83,selTransTbl[24]))(objcT83,selTransTbl[24]))));
return(id)self;
}

static id i_ClassDef_addclssel_(struct ClassDef_PRIVATE *self,SEL _cmd,id method)
{
id objcT84,objcT85;

# 370 "classdef.m"
if( !self->clssels)self->
clssels=(objcT84=OrdCltn,(*_imp(objcT84,selTransTbl[1]))(objcT84,selTransTbl[1]));
(objcT85=self->clssels,(*_imp(objcT85,selTransTbl[23]))(objcT85,selTransTbl[23],method));
(void)0;
return(id)self;
}

static id i_ClassDef_addnstdisp_(struct ClassDef_PRIVATE *self,SEL _cmd,id method)
{
id objcT88,objcT89,objcT90;

# 379 "classdef.m"
if( !self->nstdisptbl){
id objcT86,objcT87;
self->
# 380 "classdef.m"
nstdisptbl=(objcT86=OrdCltn,(*_imp(objcT86,selTransTbl[1]))(objcT86,selTransTbl[1]));self->
nstdispsels=(objcT87=Set,(*_imp(objcT87,selTransTbl[1]))(objcT87,selTransTbl[1]));
}
(void)0;
(objcT88=self->nstdisptbl,(*_imp(objcT88,selTransTbl[23]))(objcT88,selTransTbl[23],method));
(objcT89=self->nstdispsels,(*_imp(objcT89,selTransTbl[23]))(objcT89,selTransTbl[23],(objcT90=method,(*_imp(objcT90,selTransTbl[24]))(objcT90,selTransTbl[24]))));
return(id)self;
}

static id i_ClassDef_addnstsel_(struct ClassDef_PRIVATE *self,SEL _cmd,id method)
{
id objcT91,objcT92;

# 391 "classdef.m"
if( !self->nstsels)self->
nstsels=(objcT91=OrdCltn,(*_imp(objcT91,selTransTbl[1]))(objcT91,selTransTbl[1]));
(objcT92=self->nstsels,(*_imp(objcT92,selTransTbl[23]))(objcT92,selTransTbl[23],method));
(void)0;
return(id)self;
}

static id i_ClassDef_check_includedin_factory_(struct ClassDef_PRIVATE *self,SEL _cmd,id sels,id impls,BOOL f)
{
id objcT93;

# 400 "classdef.m"
int i,n;

for(i=0,n=(objcT93=sels,(*(unsigned(*)(id,SEL))_imp(objcT93,selTransTbl[13]))(objcT93,selTransTbl[13]));i<n;i++){
id objcT94,objcT95;

# 403 "classdef.m"
id t=(objcT94=sels,(*(id(*)(id,SEL,unsigned))_imp(objcT94,selTransTbl[14]))(objcT94,selTransTbl[14],i));

if( !(objcT95=impls,(*(BOOL(*)(id,SEL,id))_imp(objcT95,selTransTbl[25]))(objcT95,selTransTbl[25],t))){
id objcT96;

# 406 "classdef.m"
warn("can't find implementation of %s%s",(f)?"+":"-",(objcT96=t,(*(STR(*)(id,SEL))_imp(objcT96,selTransTbl[6]))(objcT96,selTransTbl[6])));
}
}
return(id)self;
}

static id i_ClassDef_warnimplnotfound(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT97,objcT98;

# 414 "classdef.m"
(objcT97=(id)self,(*(id(*)(id,SEL,id,id,BOOL))_imp(objcT97,selTransTbl[26]))(objcT97,selTransTbl[26],self->clssels,self->clsdispsels,(BOOL)1));
(objcT98=(id)self,(*(id(*)(id,SEL,id,id,BOOL))_imp(objcT98,selTransTbl[26]))(objcT98,selTransTbl[26],self->nstsels,self->nstdispsels,(BOOL)0));
return(id)self;
}

static id i_ClassDef_undefcomps(struct ClassDef_PRIVATE *self,SEL _cmd)
{self->
compdic=(id)0;self->
compnames=(id)0;self->
comptypes=(id)0;
return(id)self;
}

static id i_ClassDef_defivars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT99;
self->
# 429 "classdef.m"
ivardic=self->compdic;self->
ivarnames=self->compnames;self->
ivartypes=self->comptypes;
return(objcT99=(id)self,(*_imp(objcT99,selTransTbl[21]))(objcT99,selTransTbl[21]));
}

static id i_ClassDef_defcvars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT100;
self->
# 437 "classdef.m"
cvardic=self->compdic;self->
cvarnames=self->compnames;self->
cvartypes=self->comptypes;
return(objcT100=(id)self,(*_imp(objcT100,selTransTbl[21]))(objcT100,selTransTbl[21]));
}

static id i_ClassDef_ivarnames(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->ivarnames;
}

static id i_ClassDef_cvarnames(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->cvarnames;
}

static id i_ClassDef_synth(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT101,objcT102,objcT103,objcT104,objcT105;

# 455 "classdef.m"
id outerstruct;
char*s=(objcT101=(id)self,(*(char*(*)(id,SEL))_imp(objcT101,selTransTbl[0]))(objcT101,selTransTbl[0]));self->

unit=trlunit;

(objcT102=(id)self,(*_imp(objcT102,selTransTbl[12]))(objcT102,selTransTbl[12]));
if(self->superc)self->
shartypename=(objcT103=self->superc,(*(char*(*)(id,SEL))_imp(objcT103,selTransTbl[27]))(objcT103,selTransTbl[27]));
if(self->cvars)self->
shartypename=(objcT104=(objcT105=String,(*(id(*)(id,SEL,STR,...))_imp(objcT105,selTransTbl[3]))(objcT105,selTransTbl[3],"%s_SHARED",s)),(*(STR(*)(id,SEL))_imp(objcT104,selTransTbl[8]))(objcT104,selTransTbl[8]));
outerstruct=curstruct;
curstruct=(id)self;
if(self->ivars){
id objcT106,objcT107;

# 468 "classdef.m"
(objcT106=self->ivars,(*(id(*)(id,SEL,SEL))_imp(objcT106,selTransTbl[18]))(objcT106,selTransTbl[18],_cmd));
(objcT107=(id)self,(*_imp(objcT107,selTransTbl[28]))(objcT107,selTransTbl[28]));
}
if(self->cvars){
id objcT108,objcT109;

# 472 "classdef.m"
(objcT108=self->cvars,(*(id(*)(id,SEL,SEL))_imp(objcT108,selTransTbl[18]))(objcT108,selTransTbl[18],_cmd));
(objcT109=(id)self,(*_imp(objcT109,selTransTbl[29]))(objcT109,selTransTbl[29]));
}
curstruct=outerstruct;
return(id)self;
}

static id i_ClassDef_genlineno(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT110,objcT111,objcT112;

# 481 "classdef.m"
gl((objcT110=self->classname,(*(int(*)(id,SEL))_imp(objcT110,selTransTbl[19]))(objcT110,selTransTbl[19])),(objcT111=(objcT112=self->classname,(*_imp(objcT112,selTransTbl[20]))(objcT112,selTransTbl[20])),(*(STR(*)(id,SEL))_imp(objcT111,selTransTbl[6]))(objcT111,selTransTbl[6])));
return(id)self;
}

static id i_ClassDef_genivars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT113,objcT114;

# 487 "classdef.m"
if(self->superc)
(objcT113=self->superc,(*_imp(objcT113,selTransTbl[30]))(objcT113,selTransTbl[30]));
if(self->ivars)
(objcT114=self->ivars,(*(id(*)(id,SEL,SEL))_imp(objcT114,selTransTbl[18]))(objcT114,selTransTbl[18],selTransTbl[31]));
return(id)self;
}

static id i_ClassDef_gencvars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT115,objcT116;

# 496 "classdef.m"
if(self->superc)
(objcT115=self->superc,(*_imp(objcT115,selTransTbl[32]))(objcT115,selTransTbl[32]));
if(self->cvars)
(objcT116=self->cvars,(*(id(*)(id,SEL,SEL))_imp(objcT116,selTransTbl[18]))(objcT116,selTransTbl[18],selTransTbl[31]));
return(id)self;
}

static id i_ClassDef_genprivtype(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT117,objcT118,objcT119,objcT120,objcT121;

# 505 "classdef.m"
id s=(objcT117=String,(*(id(*)(id,SEL,STR))_imp(objcT117,selTransTbl[33]))(objcT117,selTransTbl[33],self->privtypename));

if((objcT118=trlunit,(*(BOOL(*)(id,SEL,id))_imp(objcT118,selTransTbl[34]))(objcT118,selTransTbl[34],s)))
return(id)self;
(objcT119=trlunit,(*_imp(objcT119,selTransTbl[35]))(objcT119,selTransTbl[35],s));

(objcT120=(id)self,(*_imp(objcT120,selTransTbl[36]))(objcT120,selTransTbl[36]));
gf("struct %s {\n",self->privtypename);
(objcT121=(id)self,(*_imp(objcT121,selTransTbl[30]))(objcT121,selTransTbl[30]));
gs("};\n");
if(o_otb){
gf("struct %s {\n",self->otbtypename);
gf("  struct %s *ptr;\n",self->privtypename);
g_otbvars();
gs("};\n");
}
return(id)self;
}

static id i_ClassDef_genshartype(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT122,objcT123,objcT124,objcT125;

# 526 "classdef.m"
id s=(objcT122=String,(*(id(*)(id,SEL,STR))_imp(objcT122,selTransTbl[33]))(objcT122,selTransTbl[33],self->shartypename));

if((objcT123=trlunit,(*(BOOL(*)(id,SEL,id))_imp(objcT123,selTransTbl[34]))(objcT123,selTransTbl[34],s)))
return(id)self;
(objcT124=trlunit,(*_imp(objcT124,selTransTbl[35]))(objcT124,selTransTbl[35],s));


gf("struct %s {\n",self->shartypename);
gs("  id isa;\n");
if(o_refcnt){
gs("  unsigned int _refcnt;\n");
}
gs("  id clsSuper;\n");
gs("  char *clsName;\n");
gs("  char *clsTypes;\n");
gs("  short clsSizInstance;\n");
gs("  short clsSizDict;\n");
gs("  struct _SLT *clsDispTable;\n");
gs("  long clsStatus;\n");
gs("  struct modDescriptor *clsMod;\n");

gs("  unsigned clsVersion;\n");

gs("  id clsCats;\n");
gs("  id *clsGlbl;\n");
(objcT125=(id)self,(*_imp(objcT125,selTransTbl[32]))(objcT125,selTransTbl[32]));
gs("};\n");
return(id)self;
}

static id i_ClassDef_genslt_(struct ClassDef_PRIVATE *self,SEL _cmd,id methdef)
{
if(o_cplus){
id objcT126,objcT127;

# 559 "classdef.m"
gf("\n{\"%s\",(id (*)(...))%s},",(objcT126=methdef,(*(char*(*)(id,SEL))_imp(objcT126,selTransTbl[37]))(objcT126,selTransTbl[37])),(objcT127=methdef,(*(char*(*)(id,SEL))_imp(objcT127,selTransTbl[38]))(objcT127,selTransTbl[38])));
}else{
id objcT128,objcT129;

# 561 "classdef.m"
gf("\n{\"%s\",(id (*)())%s},",(objcT128=methdef,(*(char*(*)(id,SEL))_imp(objcT128,selTransTbl[37]))(objcT128,selTransTbl[37])),(objcT129=methdef,(*(char*(*)(id,SEL))_imp(objcT129,selTransTbl[38]))(objcT129,selTransTbl[38])));
}
return(id)self;
}

static id i_ClassDef_gennilslt(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(o_cplus){
gs("\n{(char*)0,(id (*)(...))0}");
}else{
gs("\n{(char*)0,(id (*)())0}");
}
return(id)self;
}

static id i_ClassDef_genclsdisptbl(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT130,objcT133;

# 578 "classdef.m"
int i,n;

n=(self->clsdisptbl)?(objcT130=self->clsdisptbl,(*(unsigned(*)(id,SEL))_imp(objcT130,selTransTbl[13]))(objcT130,selTransTbl[13])):0;
gf("static struct _SLT %s[] ={",self->clsdisptblname);
for(i=0;i<n;i++){
id objcT131,objcT132;

# 583 "classdef.m"
(objcT131=(id)self,(*_imp(objcT131,selTransTbl[39]))(objcT131,selTransTbl[39],(objcT132=self->clsdisptbl,(*(id(*)(id,SEL,unsigned))_imp(objcT132,selTransTbl[14]))(objcT132,selTransTbl[14],i))));
}
(objcT133=(id)self,(*_imp(objcT133,selTransTbl[40]))(objcT133,selTransTbl[40]));
gs("\n};\n");
return(id)self;
}

static id i_ClassDef_gennstdisptbl(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT134,objcT137;

# 592 "classdef.m"
int i,n;

n=(self->nstdisptbl)?(objcT134=self->nstdisptbl,(*(unsigned(*)(id,SEL))_imp(objcT134,selTransTbl[13]))(objcT134,selTransTbl[13])):0;
gf("static struct _SLT %s[] ={",self->nstdisptblname);
for(i=0;i<n;i++){
id objcT135,objcT136;

# 597 "classdef.m"
(objcT135=(id)self,(*_imp(objcT135,selTransTbl[39]))(objcT135,selTransTbl[39],(objcT136=self->nstdisptbl,(*(id(*)(id,SEL,unsigned))_imp(objcT136,selTransTbl[14]))(objcT136,selTransTbl[14],i))));
}
(objcT137=(id)self,(*_imp(objcT137,selTransTbl[40]))(objcT137,selTransTbl[40]));
gs("\n};\n");
return(id)self;
}

# 615 "classdef.m"
static id i_ClassDef_genclassimpl(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT139,objcT140,objcT141,objcT142;

# 617 "classdef.m"
long st;

if( !self->iscategory){
st=0x1L|0x8L|0x20L;
}else{
st=0x1L|0x8L|0x20L|0x40L;
}
if(o_refcnt){
st|=0x80L;
}
gf("struct %s ",self->shartypename);

if( !o_otb){
gf(" %s = {\n",self->_classname);
}else{
gf(" %s_OTB = {\n",self->_classname);
}

gf("  (id)&%s,",self->_m_classname);
gcom("/* isa */");

if(o_refcnt){
gs("  1,");
gcom("/* _refcnt */");
}

if(self->superc!=(id)0&&o_shareddata){
id objcT138;

# 644 "classdef.m"
gf("  (id)&%s,",(objcT138=self->superc,(*(char*(*)(id,SEL))_imp(objcT138,selTransTbl[41]))(objcT138,selTransTbl[41])));
gcom("/* clsSuper */");
}else{
gf("  0,");
gcom("/* clsSuper */");
}

gf("  \"%s\",",(objcT139=(id)self,(*(char*(*)(id,SEL))_imp(objcT139,selTransTbl[0]))(objcT139,selTransTbl[0])));
gcom("/* clsName */");
gs("  0,");
gcom("/* clsTypes */");
gf("  sizeof(struct %s),",self->privtypename);
gcom("/* clsSizInstance */");
gf("  %d,",(self->nstdisptbl)?(objcT140=self->nstdisptbl,(*(unsigned(*)(id,SEL))_imp(objcT140,selTransTbl[13]))(objcT140,selTransTbl[13])):0);
gcom("/* clsSizDict */");
gf("  %s,",self->nstdisptblname);
gcom("/* _nstDispatchTbl */");
gf("  %d,",st);
gcom("/* clsStatus */");
gf("  &%s,",(objcT141=trlunit,(*(char*(*)(id,SEL))_imp(objcT141,selTransTbl[42]))(objcT141,selTransTbl[42])));
gcom("/* clsMod */");
gs("  0,");
gcom("/* clsVersion */");
gs("  (id)0,");
gcom("/* OBSOLETE - clsCats */");
gf("  &%s,",(objcT142=(id)self,(*(char*(*)(id,SEL))_imp(objcT142,selTransTbl[0]))(objcT142,selTransTbl[0])));
gcom("/* clsGlbl */");
gs("};\n");

if(o_otb){
char*z=self->_classname;

gf("struct OTB %s={ (struct _PRIVATE*)&%s_OTB,0,0 };\n",z,z);
}
gf("id %s %s(void)",o_bind,self->_classfunname);
gf(" { return (id)&%s; }\n",self->_classname);

gf("id %s %s(void)",o_bind,self->_superfunname);
if( !o_otb){
gf(" { return %s.clsSuper; }\n",self->_classname);
}else{
gf(" { return %s_OTB.clsSuper; }\n",self->_classname);
}

return(id)self;
}

static id i_ClassDef_genmetaimpl(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT146,objcT147,objcT148;

# 693 "classdef.m"
long st=0x2L|0x20L;

if(o_refcnt){
st|=0x80L;
}
if( !o_otb){
gf("struct _SHARED %s = {\n",self->_m_classname);
}else{
gf("struct _SHARED %s_OTB = {\n",self->_m_classname);
}

if(o_shareddata){
id objcT143;

# 705 "classdef.m"
gf("  (id)&%s,",(objcT143=self->rootc,(*(char*(*)(id,SEL))_imp(objcT143,selTransTbl[43]))(objcT143,selTransTbl[43])));
gcom("/* isa */");
}else{
gs("  (id)0,");
gcom("/* isa */");
}

if(o_refcnt){
gs("  1,");
gcom("/* _refcnt */");
}
if(o_shareddata){
if(self->superc){
id objcT144;

# 718 "classdef.m"
gf("  (id)&%s,",(objcT144=self->superc,(*(char*(*)(id,SEL))_imp(objcT144,selTransTbl[43]))(objcT144,selTransTbl[43])));
gcom("/* clsSuper */");
}else{
id objcT145;
gf("  (id)&%s,",(objcT145=self->rootc,(*(char*(*)(id,SEL))_imp(objcT145,selTransTbl[41]))(objcT145,selTransTbl[41])));
gcom("/* clsSuper */");
}
}else{
gs("  (id)0,");
gcom("/* clsSuper */");
}

gf("  \"%s\",",(objcT146=(id)self,(*(char*(*)(id,SEL))_imp(objcT146,selTransTbl[0]))(objcT146,selTransTbl[0])));
gcom("/* clsName */");
gs("  0,");
gcom("/* clsTypes */");
gf("  sizeof(struct %s),",self->shartypename);
gcom("/* clsSizInstance */");
gf("  %d,",(self->clsdisptbl)?(objcT147=self->clsdisptbl,(*(unsigned(*)(id,SEL))_imp(objcT147,selTransTbl[13]))(objcT147,selTransTbl[13])):0);
gcom("/* clsSizDict */");
gf("  %s,",self->clsdisptblname);
gcom("/* _clsDispatchTbl */");
gf("  %d,",st);
gcom("/* clsStatus */");
gf("  &%s,",(objcT148=trlunit,(*(char*(*)(id,SEL))_imp(objcT148,selTransTbl[42]))(objcT148,selTransTbl[42])));
gcom("/* clsMod */");
gs("  0,");
gcom("/* clsVersion */");
gs("  (id)0,");
gcom("/* OBSOLETE clsCats */");
gs("  0,");
gcom("/* clsGlbl */");
gs("};\n");

if(o_otb){
char*z=self->_m_classname;

gf("struct OTB %s={ (struct _PRIVATE*)&%s_OTB,0,0 };\n",z,z);
}
gf("id %s %s(void)",o_bind,self->_m_classfunname);
gf(" { return (id)&%s; }\n",self->_m_classname);

gf("id %s %s(void)",o_bind,self->_m_superfunname);
if( !o_otb){
gf(" { return %s.clsSuper; }\n",self->_m_classname);
}else{
gf(" { return %s_OTB.clsSuper; }\n",self->_m_classname);
}

return(id)self;
}

static id i_ClassDef_genclassglobal(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT149;

# 772 "classdef.m"
char*s=(objcT149=(id)self,(*(char*(*)(id,SEL))_imp(objcT149,selTransTbl[0]))(objcT149,selTransTbl[0]));

if( !o_shareddata)
gs("static");
gf("id %s = (id)&%s;\n",s,self->_classname);
gf("id %s *%s(void) { return &%s; }\n",o_bind,self->globfunname,s);
return(id)self;
}

static id i_ClassDef_genclassref(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if( !o_shareddata){
(void)0;
gf("*%s()",self->globfunname);
}else{
id objcT150;

# 787 "classdef.m"
gs((objcT150=(id)self,(*(char*(*)(id,SEL))_imp(objcT150,selTransTbl[0]))(objcT150,selTransTbl[0])));
}
return(id)self;
}


static id i_ClassDef_genglobfuncall(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT152,objcT153,objcT154;

# 795 "classdef.m"
char*s;

if(self->superc){
id objcT151;

# 798 "classdef.m"
s=(objcT151=self->superc,(*(char*(*)(id,SEL))_imp(objcT151,selTransTbl[44]))(objcT151,selTransTbl[44]));
if( !o_otb){
gf("  %s.clsSuper = %s();\n",self->_classname,s);
}else{
gf("  %s_OTB.clsSuper = %s();\n",self->_classname,s);
}
}
s=(objcT152=self->rootc,(*(char*(*)(id,SEL))_imp(objcT152,selTransTbl[45]))(objcT152,selTransTbl[45]));
if( !o_otb){
gf("  %s.isa = %s();\n",self->_m_classname,s);
}else{
gf("  %s_OTB.isa = %s();\n",self->_m_classname,s);
}

s=(self->superc)?(objcT153=self->superc,(*(char*(*)(id,SEL))_imp(objcT153,selTransTbl[45]))(objcT153,selTransTbl[45])):(objcT154=self->rootc,(*(char*(*)(id,SEL))_imp(objcT154,selTransTbl[44]))(objcT154,selTransTbl[44]));
if( !o_otb){
gf("  %s.clsSuper = %s();\n",self->_m_classname,s);
}else{
gf("  %s_OTB.clsSuper = %s();\n",self->_m_classname,s);
}

return(id)self;
}

static id i_ClassDef_gen(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(self->isimpl){
id objcT155,objcT156,objcT157;

# 825 "classdef.m"
(objcT155=(id)self,(*_imp(objcT155,selTransTbl[46]))(objcT155,selTransTbl[46]));
(objcT156=(id)self,(*_imp(objcT156,selTransTbl[47]))(objcT156,selTransTbl[47]));
(objcT157=(id)self,(*_imp(objcT157,selTransTbl[48]))(objcT157,selTransTbl[48]));
}
return(id)self;
}

static id i_ClassDef_gensuper(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(o_otb|| !o_shareddata){
gf("%s()",self->_superfunname);
}else{
gf("%s.clsSuper",self->_classname);
}
return(id)self;
}

static id i_ClassDef_genmetasuper(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(o_otb|| !o_shareddata){
gf("%s()",self->_m_superfunname);
}else{
gf("%s.clsSuper",self->_m_classname);
}
return(id)self;
}

static id i_ClassDef_use(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT158;

# 854 "classdef.m"
if( !o_postlink)
(objcT158=trlunit,(*_imp(objcT158,selTransTbl[49]))(objcT158,selTransTbl[49],self->classname));
return(id)self;
}

static id i_ClassDef_define(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT159,objcT160;

# 861 "classdef.m"
(objcT159=trlunit,(*_imp(objcT159,selTransTbl[50]))(objcT159,selTransTbl[50],(id)self));
if( !o_postlink)
(objcT160=trlunit,(*_imp(objcT160,selTransTbl[51]))(objcT160,selTransTbl[51],self->classname));
return(id)self;
}

static BOOL i_ClassDef_isimpl(struct ClassDef_PRIVATE *self,SEL _cmd)
{
return self->isimpl;
}

static id i_ClassDef_forceimpl(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(self->isimpl){
return(id)self;
}else{
id objcT161,objcT162;
self->
# 877 "classdef.m"
isimpl=(BOOL)1;
(objcT161=(id)self,(*_imp(objcT161,selTransTbl[52]))(objcT161,selTransTbl[52]));
(objcT162=self->superc,(*_imp(objcT162,selTransTbl[53]))(objcT162,selTransTbl[53]));
return(id)self;
}
}

static id i_ClassDef_genintf(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(self->emitintf){
return(id)self;
}else{
id objcT163;
self->
# 889 "classdef.m"
emitintf=(BOOL)1;
(objcT163=(id)self,(*_imp(objcT163,selTransTbl[36]))(objcT163,selTransTbl[36]));
if(o_shareddata){
id objcT164;

# 892 "classdef.m"
gf("extern id %s %s;\n",o_bind,(objcT164=(id)self,(*(char*(*)(id,SEL))_imp(objcT164,selTransTbl[0]))(objcT164,selTransTbl[0])));
}else{

gf("extern id %s *%s(void);\n",o_bind,self->globfunname);
}
return(id)self;
}
}

static id i_ClassDef_genfwddecl(struct ClassDef_PRIVATE *self,SEL _cmd)
{

if(self->emitfwddecl){
return(id)self;
}else{
id objcT165,objcT166;
self->
# 907 "classdef.m"
emitfwddecl=(BOOL)1;
(objcT165=(id)self,(*_imp(objcT165,selTransTbl[54]))(objcT165,selTransTbl[54]));
(objcT166=(id)self,(*_imp(objcT166,selTransTbl[36]))(objcT166,selTransTbl[36]));
if( !o_otb){
gf("extern struct %s %s;\n",self->shartypename,self->_classname);
gf("extern struct _SHARED %s;\n",self->_m_classname);
}else{
(void)0;
gf("extern struct OTB %s;\n",self->_classname);
gf("extern struct %s %s_OTB;\n",self->shartypename,self->_classname);
gf("extern struct OTB %s;\n",self->_m_classname);
gf("extern struct _SHARED %s_OTB;\n",self->_m_classname);
}
if( !o_shareddata){
gf("extern id %s %s(void);\n",o_bind,self->_classfunname);
gf("extern id %s %s(void);\n",o_bind,self->_superfunname);
gf("extern id %s %s(void);\n",o_bind,self->_m_classfunname);
gf("extern id %s %s(void);\n",o_bind,self->_m_superfunname);
}
return(id)self;
}
}

static id i_ClassDef_genimpl(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(self->emitimpl){
return(id)self;
}else{
id objcT167,objcT168,objcT169,objcT170,objcT171;
id objcT176,objcT177,objcT178,objcT179,objcT180;
self->
# 935 "classdef.m"
emitimpl=(BOOL)1;
(objcT167=self->rootc,(*_imp(objcT167,selTransTbl[48]))(objcT167,selTransTbl[48]));
if(self->superc)
(objcT168=self->superc,(*_imp(objcT168,selTransTbl[48]))(objcT168,selTransTbl[48]));
(objcT169=(id)self,(*_imp(objcT169,selTransTbl[48]))(objcT169,selTransTbl[48]));
(objcT170=(id)self,(*_imp(objcT170,selTransTbl[46]))(objcT170,selTransTbl[46]));
(objcT171=(id)self,(*_imp(objcT171,selTransTbl[47]))(objcT171,selTransTbl[47]));
o_nolinetags++;
if(self->fileinmethod){
id objcT172;

# 944 "classdef.m"
(objcT172=self->fileinmethod,(*_imp(objcT172,selTransTbl[31]))(objcT172,selTransTbl[31]));
gc('\n');
}
if(self->fileoutmethod){
id objcT173;

# 948 "classdef.m"
(objcT173=self->fileoutmethod,(*_imp(objcT173,selTransTbl[31]))(objcT173,selTransTbl[31]));
gc('\n');
}
if(self->decrefsmethod){
id objcT174;

# 952 "classdef.m"
(objcT174=self->decrefsmethod,(*_imp(objcT174,selTransTbl[31]))(objcT174,selTransTbl[31]));
gc('\n');
}
if(self->increfsmethod){
id objcT175;

# 956 "classdef.m"
(objcT175=self->increfsmethod,(*_imp(objcT175,selTransTbl[31]))(objcT175,selTransTbl[31]));
gc('\n');
}
(objcT176=(id)self,(*_imp(objcT176,selTransTbl[55]))(objcT176,selTransTbl[55]));
(objcT177=(id)self,(*_imp(objcT177,selTransTbl[56]))(objcT177,selTransTbl[56]));
(objcT178=(id)self,(*_imp(objcT178,selTransTbl[57]))(objcT178,selTransTbl[57]));
(objcT179=(id)self,(*_imp(objcT179,selTransTbl[58]))(objcT179,selTransTbl[58]));
(objcT180=(id)self,(*_imp(objcT180,selTransTbl[59]))(objcT180,selTransTbl[59]));
o_nolinetags--;
return(id)self;
}
}

# 32 "./../../include/objpak/dictnary.h"
extern id  Dictionary;

# 969 "classdef.m"
static id i_ClassDef_defcomp_astype_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym,id t)
{
id objcT184,objcT185;

# 971 "classdef.m"
if( !self->compdic){
id objcT181,objcT182,objcT183;
self->
# 972 "classdef.m"
compdic=(objcT181=Dictionary,(*_imp(objcT181,selTransTbl[1]))(objcT181,selTransTbl[1]));self->
compnames=(objcT182=OrdCltn,(*_imp(objcT182,selTransTbl[1]))(objcT182,selTransTbl[1]));self->
comptypes=(objcT183=OrdCltn,(*_imp(objcT183,selTransTbl[1]))(objcT183,selTransTbl[1]));
}
if(self->superc&&((objcT184=self->superc,(*(BOOL(*)(id,SEL,id))_imp(objcT184,selTransTbl[60]))(objcT184,selTransTbl[60],sym))||(objcT185=self->superc,(*(BOOL(*)(id,SEL,id))_imp(objcT185,selTransTbl[61]))(objcT185,selTransTbl[61],sym)))){
id objcT186,objcT189,objcT190;

# 977 "classdef.m"
id which,next;

for(which=self->superc,next=(objcT186=which,(*_imp(objcT186,selTransTbl[11]))(objcT186,selTransTbl[11]));next;which=next){
id objcT187,objcT188;

# 980 "classdef.m"
if( !((objcT187=next,(*(BOOL(*)(id,SEL,id))_imp(objcT187,selTransTbl[60]))(objcT187,selTransTbl[60],sym))||(objcT188=next,(*(BOOL(*)(id,SEL,id))_imp(objcT188,selTransTbl[61]))(objcT188,selTransTbl[61],sym))))
break;
}
fatalat(sym,"'%s' previously declared by '%s'",(objcT189=sym,(*(STR(*)(id,SEL))_imp(objcT189,selTransTbl[6]))(objcT189,selTransTbl[6])),(objcT190=which,(*(char*(*)(id,SEL))_imp(objcT190,selTransTbl[0]))(objcT190,selTransTbl[0])));
}else{
id objcT191,objcT192,objcT193;

# 985 "classdef.m"
(objcT191=self->compdic,(*_imp(objcT191,selTransTbl[62]))(objcT191,selTransTbl[62],sym,t));
(objcT192=self->compnames,(*_imp(objcT192,selTransTbl[23]))(objcT192,selTransTbl[23],sym));
(objcT193=self->comptypes,(*_imp(objcT193,selTransTbl[23]))(objcT193,selTransTbl[23],t));
}
return(id)self;
}

static id i_ClassDef_lookupivar_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym)
{
id objcT194,objcT195;

# 994 "classdef.m"
id t;

if(self->ivardic&&(t=(objcT194=self->ivardic,(*_imp(objcT194,selTransTbl[63]))(objcT194,selTransTbl[63],sym))))
return t;
return(self->superc)?(objcT195=self->superc,(*_imp(objcT195,selTransTbl[64]))(objcT195,selTransTbl[64],sym)):(id)0;
}

static id i_ClassDef_lookupcvar_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym)
{
id objcT196,objcT197;

# 1003 "classdef.m"
id t;

if(self->cvardic&&(t=(objcT196=self->cvardic,(*_imp(objcT196,selTransTbl[63]))(objcT196,selTransTbl[63],sym))))
return t;
return(self->superc)?(objcT197=self->superc,(*_imp(objcT197,selTransTbl[65]))(objcT197,selTransTbl[65],sym)):(id)0;
}

static BOOL i_ClassDef_isivar_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym)
{
id objcT202;

# 1012 "classdef.m"
if( !self->allivarnames){
id objcT198,objcT199;

# 1013 "classdef.m"
id x,c;self->

allivarnames=(objcT198=Set,(*_imp(objcT198,selTransTbl[1]))(objcT198,selTransTbl[1]));
for(c=(id)self;c;c=(objcT199=c,(*_imp(objcT199,selTransTbl[11]))(objcT199,selTransTbl[11]))){
id objcT200,objcT201;

# 1017 "classdef.m"
if((x=(objcT200=c,(*_imp(objcT200,selTransTbl[66]))(objcT200,selTransTbl[66]))))
(objcT201=self->allivarnames,(*_imp(objcT201,selTransTbl[67]))(objcT201,selTransTbl[67],x));
}
}
return(objcT202=self->allivarnames,(*(BOOL(*)(id,SEL,id))_imp(objcT202,selTransTbl[68]))(objcT202,selTransTbl[68],sym));
}

static BOOL i_ClassDef_iscvar_(struct ClassDef_PRIVATE *self,SEL _cmd,id sym)
{
id objcT207,objcT208;

# 1026 "classdef.m"
BOOL iscvar;

if( !self->allcvarnames){
id objcT203,objcT204;

# 1029 "classdef.m"
id x,c;self->

allcvarnames=(objcT203=Set,(*_imp(objcT203,selTransTbl[1]))(objcT203,selTransTbl[1]));
for(c=(id)self;c;c=(objcT204=c,(*_imp(objcT204,selTransTbl[11]))(objcT204,selTransTbl[11]))){
id objcT205,objcT206;

# 1033 "classdef.m"
if((x=(objcT205=c,(*_imp(objcT205,selTransTbl[69]))(objcT205,selTransTbl[69]))))
(objcT206=self->allcvarnames,(*_imp(objcT206,selTransTbl[67]))(objcT206,selTransTbl[67],x));
}
}
iscvar=(objcT207=self->allcvarnames,(*(BOOL(*)(id,SEL,id))_imp(objcT207,selTransTbl[68]))(objcT207,selTransTbl[68],sym));
if(iscvar&&(objcT208=trlunit,(*(BOOL(*)(id,SEL))_imp(objcT208,selTransTbl[70]))(objcT208,selTransTbl[70]))){
if(o_warnsuggest){
warnat(sym,"suggest using -noSelfAssign when using class variables");
}
}
return iscvar;
}

static id i_ClassDef_st80(struct ClassDef_PRIVATE *self,SEL _cmd)
{
if(self->isimpl&& !self->emitimpl){
id objcT209,objcT210,objcT211,objcT212;

# 1049 "classdef.m"
char*sn;

gs("\f\n");self->
emitimpl++;
sn=(self->superc)?(objcT209=self->superc,(*(char*(*)(id,SEL))_imp(objcT209,selTransTbl[0]))(objcT209,selTransTbl[0])):"Meta";
gf("%s subclass: #%s\n",(objcT210=(id)self,(*(char*(*)(id,SEL))_imp(objcT210,selTransTbl[0]))(objcT210,selTransTbl[0])),sn);
gs("\tinstanceVariableNames: '");
(objcT211=self->ivarnames,(*(id(*)(id,SEL,SEL))_imp(objcT211,selTransTbl[18]))(objcT211,selTransTbl[18],_cmd));
gs("'\n");
gs("\tclassVariableNames: '");
(objcT212=self->cvarnames,(*(id(*)(id,SEL,SEL))_imp(objcT212,selTransTbl[18]))(objcT212,selTransTbl[18],_cmd));
gs("'\n");
gs("\tpoolDictionaries: ''\n");
gs("\tcategory: 'POC Generated'!\n");
gc('\n');
}
return(id)self;
}

static IMP i_ClassDef_methodFor_cls_methdef_(struct ClassDef_PRIVATE *self,SEL _cmd,SEL x,id c,id m)
{
id objcT213;

# 1070 "classdef.m"
(objcT213=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT213,selTransTbl[71]))(objcT213,selTransTbl[71],_cmd));
return NULL;
}

static int i_ClassDef_bytesizeOf_(struct ClassDef_PRIVATE *self,SEL _cmd,id c)
{
id objcT214;

# 1076 "classdef.m"
int i,n;
int bs=0;
for(i=0,n=(objcT214=c,(*(unsigned(*)(id,SEL))_imp(objcT214,selTransTbl[13]))(objcT214,selTransTbl[13]));i<n;i++){
id objcT215,objcT216;

# 1079 "classdef.m"
bs+=(objcT215=(objcT216=c,(*(id(*)(id,SEL,unsigned))_imp(objcT216,selTransTbl[14]))(objcT216,selTransTbl[14],i)),(*(int(*)(id,SEL))_imp(objcT215,selTransTbl[72]))(objcT215,selTransTbl[72]));
}
return bs;
}

static int i_ClassDef_ivarbytesize(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT217;

# 1086 "classdef.m"
return(self->ivartypes)?(objcT217=(id)self,(*(int(*)(id,SEL,id))_imp(objcT217,selTransTbl[73]))(objcT217,selTransTbl[73],self->ivartypes)):0;
}

static int i_ClassDef_cvarbytesize(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT218;

# 1091 "classdef.m"
return(self->cvartypes)?(objcT218=(id)self,(*(int(*)(id,SEL,id))_imp(objcT218,selTransTbl[73]))(objcT218,selTransTbl[73],self->cvartypes)):0;
}

static id i_ClassDef_go(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT219,objcT220,objcT221,objcT223,objcT224;
id objcT225,objcT226,objcT227,objcT228,objcT229;
id objcT239;

# 1100 "classdef.m"
id c;
int j;
id tab;
struct _SHARED*shar;

trlunit=self->unit;

if( !self->superc)(objcT219=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT219,selTransTbl[74]))(objcT219,selTransTbl[74],"root classes not yet supported"));
if((c=(objcT220=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT220,selTransTbl[75]))(objcT220,selTransTbl[75],(objcT221=(id)self,(*(char*(*)(id,SEL))_imp(objcT221,selTransTbl[0]))(objcT221,selTransTbl[0])))))){
id objcT222;

# 1109 "classdef.m"
(objcT222=c,(*_imp(objcT222,selTransTbl[76]))(objcT222,selTransTbl[76]));
}
c=(objcT223=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT223,selTransTbl[75]))(objcT223,selTransTbl[75],(objcT224=self->superc,(*(char*(*)(id,SEL))_imp(objcT224,selTransTbl[0]))(objcT224,selTransTbl[0]))));
if( !c)(objcT225=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT225,selTransTbl[74]))(objcT225,selTransTbl[74],"superclass not loaded into interpreter!"));
shar=(struct _SHARED*)c;self->

offset=shar->clsSizInstance;

c=(objcT226=c,(*(id(*)(id,SEL,STR,int,int))_imp(objcT226,selTransTbl[77]))(objcT226,selTransTbl[77],(objcT227=(id)self,(*(char*(*)(id,SEL))_imp(objcT227,selTransTbl[0]))(objcT227,selTransTbl[0])),(objcT228=(id)self,(*(int(*)(id,SEL))_imp(objcT228,selTransTbl[78]))(objcT228,selTransTbl[78])),(objcT229=(id)self,(*(int(*)(id,SEL))_imp(objcT229,selTransTbl[79]))(objcT229,selTransTbl[79]))));
# 1121 "classdef.m"
tab=self->nstdisptbl;
shar=(struct _SHARED*)c;

j=2;while(j--){
id objcT230;

# 1125 "classdef.m"
int i,n;
struct _SLT*disptab;

n=(objcT230=tab,(*(unsigned(*)(id,SEL))_imp(objcT230,selTransTbl[13]))(objcT230,selTransTbl[13]));
disptab=OC_Malloc(sizeof(struct _SLT)*(n+1));

for(i=0;i<n;i++){
id objcT231,objcT232,objcT233,objcT234,objcT236;

# 1132 "classdef.m"
SEL s;
id sel,t,m;
m=(objcT231=tab,(*(id(*)(id,SEL,unsigned))_imp(objcT231,selTransTbl[14]))(objcT231,selTransTbl[14],i));
sel=(objcT232=m,(*_imp(objcT232,selTransTbl[24]))(objcT232,selTransTbl[24]));
if( !(s=(objcT233=(id)self,(*(SEL(*)(id,SEL,STR))_imp(objcT233,selTransTbl[80]))(objcT233,selTransTbl[80],(objcT234=sel,(*(STR(*)(id,SEL))_imp(objcT234,selTransTbl[6]))(objcT234,selTransTbl[6])))))){
id objcT235;

# 1137 "classdef.m"
s=(objcT235=sel,(*(STR(*)(id,SEL))_imp(objcT235,selTransTbl[8]))(objcT235,selTransTbl[8]));
}


t=(objcT236=msgwraps,(*_imp(objcT236,selTransTbl[16]))(objcT236,selTransTbl[16],m));

if(t){
id objcT237;

# 1144 "classdef.m"
disptab[i]._cmd=s;
disptab[i]._imp=(objcT237=t,(*(IMP(*)(id,SEL,SEL,id,id))_imp(objcT237,selTransTbl[81]))(objcT237,selTransTbl[81],s,c,m));
}else{
id objcT238;
(objcT238=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT238,selTransTbl[74]))(objcT238,selTransTbl[74],"(%s): can't send this type of message",s));
}
}

disptab[n]._cmd=NULL;
disptab[n]._imp=NULL;
# 1158 "classdef.m"
shar->clsSizDict=n;
shar->clsDispTable=disptab;

tab=self->clsdisptbl;
shar=(struct _SHARED*)shar->isa;
}

(objcT239=c,(*_imp(objcT239,selTransTbl[82]))(objcT239,selTransTbl[82]));
# 1170 "classdef.m"
return(id)self;
}

static id i_ClassDef_getivarval___(struct ClassDef_PRIVATE *self,SEL _cmd,id instance,BOOL infactory,id varname)
{
id objcT240,objcT246;

# 1180 "classdef.m"
char*p;
int i,n;
p=(char*)instance+self->offset;
for(i=0,n=(objcT240=self->ivarnames,(*(unsigned(*)(id,SEL))_imp(objcT240,selTransTbl[13]))(objcT240,selTransTbl[13]));i<n;i++){
id objcT241,objcT242,objcT243,objcT245;

# 1184 "classdef.m"
id t=(objcT241=self->ivartypes,(*(id(*)(id,SEL,unsigned))_imp(objcT241,selTransTbl[14]))(objcT241,selTransTbl[14],i));
if((objcT242=varname,(*(BOOL(*)(id,SEL,id))_imp(objcT242,selTransTbl[9]))(objcT242,selTransTbl[9],(objcT243=self->ivarnames,(*(id(*)(id,SEL,unsigned))_imp(objcT243,selTransTbl[14]))(objcT243,selTransTbl[14],i))))){
id objcT244;

# 1186 "classdef.m"
return(objcT244=t,(*(id(*)(id,SEL,char*))_imp(objcT244,selTransTbl[83]))(objcT244,selTransTbl[83],p));
}
p+=(objcT245=t,(*(int(*)(id,SEL))_imp(objcT245,selTransTbl[72]))(objcT245,selTransTbl[72]));
}
(objcT246=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT246,selTransTbl[84]))(objcT246,selTransTbl[84],_cmd));
return(id)0;
# 1196 "classdef.m"
}

static id i_ClassDef_setivarval____(struct ClassDef_PRIVATE *self,SEL _cmd,id instance,BOOL infactory,id varname,id value)
{
id objcT247,objcT253;

# 1204 "classdef.m"
char*p;
int i,n;
p=(char*)instance+self->offset;
for(i=0,n=(objcT247=self->ivarnames,(*(unsigned(*)(id,SEL))_imp(objcT247,selTransTbl[13]))(objcT247,selTransTbl[13]));i<n;i++){
id objcT248,objcT249,objcT250,objcT252;

# 1208 "classdef.m"
id t=(objcT248=self->ivartypes,(*(id(*)(id,SEL,unsigned))_imp(objcT248,selTransTbl[14]))(objcT248,selTransTbl[14],i));
if((objcT249=varname,(*(BOOL(*)(id,SEL,id))_imp(objcT249,selTransTbl[9]))(objcT249,selTransTbl[9],(objcT250=self->ivarnames,(*(id(*)(id,SEL,unsigned))_imp(objcT250,selTransTbl[14]))(objcT250,selTransTbl[14],i))))){
id objcT251;

# 1210 "classdef.m"
return(objcT251=t,(*(id(*)(id,SEL,id,char*))_imp(objcT251,selTransTbl[85]))(objcT251,selTransTbl[85],value,p));
}
p+=(objcT252=t,(*(int(*)(id,SEL))_imp(objcT252,selTransTbl[72]))(objcT252,selTransTbl[72]));
}
(objcT253=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT253,selTransTbl[84]))(objcT253,selTransTbl[84],_cmd));
return value;
# 1219 "classdef.m"
}

static id i_ClassDef_browsevars(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT254,objcT255,objcT256,objcT258,objcT259;
id objcT263;

# 1223 "classdef.m"
id fn;
FILE*f;
int i,n;

fn=(objcT254=String,(*(id(*)(id,SEL,STR,...))_imp(objcT254,selTransTbl[3]))(objcT254,selTransTbl[3],"Menu.vars%s",(objcT255=(id)self,(*(char*(*)(id,SEL))_imp(objcT255,selTransTbl[0]))(objcT255,selTransTbl[0]))));
f=freopen(browsepath((objcT256=fn,(*(STR(*)(id,SEL))_imp(objcT256,selTransTbl[6]))(objcT256,selTransTbl[6]))),"w",stderr);
if( !f){
id objcT257;

# 1230 "classdef.m"
fatal("cannot open %s for writing\n",(objcT257=fn,(*(STR(*)(id,SEL))_imp(objcT257,selTransTbl[6]))(objcT257,selTransTbl[6])));
return(id)self;
}

gstderr();

fprintf(f,"menu=%s variables\n",(objcT258=(id)self,(*(char*(*)(id,SEL))_imp(objcT258,selTransTbl[0]))(objcT258,selTransTbl[0])));
for(i=0,n=(objcT259=self->ivarnames,(*(unsigned(*)(id,SEL))_imp(objcT259,selTransTbl[13]))(objcT259,selTransTbl[13]));i<n;i++){
id objcT260,objcT261,objcT262;

# 1238 "classdef.m"
fprintf(f,"name='");
(objcT260=(objcT261=self->ivartypes,(*(id(*)(id,SEL,unsigned))_imp(objcT261,selTransTbl[14]))(objcT261,selTransTbl[14],i)),(*_imp(objcT260,selTransTbl[86]))(objcT260,selTransTbl[86],(objcT262=self->ivarnames,(*(id(*)(id,SEL,unsigned))_imp(objcT262,selTransTbl[14]))(objcT262,selTransTbl[14],i))));
fprintf(f,"'\n");
fprintf(f,"action=none\n");
}
for(i=0,n=(objcT263=self->cvarnames,(*(unsigned(*)(id,SEL))_imp(objcT263,selTransTbl[13]))(objcT263,selTransTbl[13]));i<n;i++){
id objcT264,objcT265,objcT266;

# 1244 "classdef.m"
fprintf(f,"name='");
(objcT264=(objcT265=self->cvartypes,(*(id(*)(id,SEL,unsigned))_imp(objcT265,selTransTbl[14]))(objcT265,selTransTbl[14],i)),(*_imp(objcT264,selTransTbl[86]))(objcT264,selTransTbl[86],(objcT266=self->cvarnames,(*(id(*)(id,SEL,unsigned))_imp(objcT266,selTransTbl[14]))(objcT266,selTransTbl[14],i))));
fprintf(f,"'\n");
fprintf(f,"action=none\n");
}

fclose(f);
gnormal();

return(id)self;
}

static id i_ClassDef_browsemethods(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT267,objcT268,objcT269,objcT271,objcT272;
id objcT275;

# 1258 "classdef.m"
id fn;
FILE*f;
int i,n;

fn=(objcT267=String,(*(id(*)(id,SEL,STR,...))_imp(objcT267,selTransTbl[3]))(objcT267,selTransTbl[3],"Menu.methods%s",(objcT268=(id)self,(*(char*(*)(id,SEL))_imp(objcT268,selTransTbl[0]))(objcT268,selTransTbl[0]))));
f=freopen(browsepath((objcT269=fn,(*(STR(*)(id,SEL))_imp(objcT269,selTransTbl[6]))(objcT269,selTransTbl[6]))),"w",stdout);
if( !f){
id objcT270;

# 1265 "classdef.m"
fatal("cannot open %s for writing\n",(objcT270=fn,(*(STR(*)(id,SEL))_imp(objcT270,selTransTbl[6]))(objcT270,selTransTbl[6])));
return(id)self;
}

printf("menu=%s methods\n",(objcT271=(id)self,(*(char*(*)(id,SEL))_imp(objcT271,selTransTbl[0]))(objcT271,selTransTbl[0])));
for(i=0,n=(objcT272=self->clssels,(*(unsigned(*)(id,SEL))_imp(objcT272,selTransTbl[13]))(objcT272,selTransTbl[13]));i<n;i++){
id objcT273,objcT274;

# 1271 "classdef.m"
printf("name=%s\n",(objcT273=(objcT274=self->clssels,(*(id(*)(id,SEL,unsigned))_imp(objcT274,selTransTbl[14]))(objcT274,selTransTbl[14],i)),(*(STR(*)(id,SEL))_imp(objcT273,selTransTbl[6]))(objcT273,selTransTbl[6])));
printf("action=none\n");
}
for(i=0,n=(objcT275=self->nstsels,(*(unsigned(*)(id,SEL))_imp(objcT275,selTransTbl[13]))(objcT275,selTransTbl[13]));i<n;i++){
id objcT276,objcT277;

# 1275 "classdef.m"
printf("name=%s\n",(objcT276=(objcT277=self->nstsels,(*(id(*)(id,SEL,unsigned))_imp(objcT277,selTransTbl[14]))(objcT277,selTransTbl[14],i)),(*(STR(*)(id,SEL))_imp(objcT276,selTransTbl[6]))(objcT276,selTransTbl[6])));
printf("action=none\n");
}

fclose(f);
return(id)self;
}

static id i_ClassDef_browse(struct ClassDef_PRIVATE *self,SEL _cmd)
{
id objcT278,objcT279,objcT280,objcT282,objcT283;
id objcT284,objcT285,objcT286,objcT287,objcT288;
id objcT289;

# 1285 "classdef.m"
id fn;
FILE*f;

fn=(objcT278=String,(*(id(*)(id,SEL,STR,...))_imp(objcT278,selTransTbl[3]))(objcT278,selTransTbl[3],"Menu.%s",(objcT279=(id)self,(*(char*(*)(id,SEL))_imp(objcT279,selTransTbl[0]))(objcT279,selTransTbl[0]))));
f=freopen(browsepath((objcT280=fn,(*(STR(*)(id,SEL))_imp(objcT280,selTransTbl[6]))(objcT280,selTransTbl[6]))),"w",stdout);
if( !f){
id objcT281;

# 1291 "classdef.m"
fatal("cannot open %s for writing\n",(objcT281=fn,(*(STR(*)(id,SEL))_imp(objcT281,selTransTbl[6]))(objcT281,selTransTbl[6])));
return(id)self;
}

printf("menu=%s\n",(objcT282=(id)self,(*(char*(*)(id,SEL))_imp(objcT282,selTransTbl[0]))(objcT282,selTransTbl[0])));
printf("name=Spawn hierarchy\n");
printf("action=open Menu.super%s\n",(objcT283=(id)self,(*(char*(*)(id,SEL))_imp(objcT283,selTransTbl[0]))(objcT283,selTransTbl[0])));
printf("name=Inspect variables\n");
printf("action=open Menu.vars%s\n",(objcT284=(id)self,(*(char*(*)(id,SEL))_imp(objcT284,selTransTbl[0]))(objcT284,selTransTbl[0])));
printf("name=Method categories\n");
printf("action=open Menu.categories%s\n",(objcT285=(id)self,(*(char*(*)(id,SEL))_imp(objcT285,selTransTbl[0]))(objcT285,selTransTbl[0])));
printf("name=Show methods\n");
printf("action=open Menu.methods%s\n",(objcT286=(id)self,(*(char*(*)(id,SEL))_imp(objcT286,selTransTbl[0]))(objcT286,selTransTbl[0])));
printf("name=Spawn protocol\n");
printf("action=open Menu.protocol%s\n",(objcT287=(id)self,(*(char*(*)(id,SEL))_imp(objcT287,selTransTbl[0]))(objcT287,selTransTbl[0])));
fclose(f);

(objcT288=(id)self,(*_imp(objcT288,selTransTbl[87]))(objcT288,selTransTbl[87]));
(objcT289=(id)self,(*_imp(objcT289,selTransTbl[88]))(objcT289,selTransTbl[88]));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _ClassDef_clsDispatchTbl[] ={
{"new",(id (*)())c_ClassDef_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _ClassDef_nstDispatchTbl[] ={
{"compare:",(id (*)())i_ClassDef_compare_},
{"privtypename",(id (*)())i_ClassDef_privtypename},
{"selftype",(id (*)())i_ClassDef_selftype},
{"shartypename",(id (*)())i_ClassDef_shartypename},
{"otbtypename",(id (*)())i_ClassDef_otbtypename},
{"shartypename:",(id (*)())i_ClassDef_shartypename_},
{"warnpending",(id (*)())i_ClassDef_warnpending},
{"classname:",(id (*)())i_ClassDef_classname_},
{"checksupername:",(id (*)())i_ClassDef_checksupername_},
{"supername:",(id (*)())i_ClassDef_supername_},
{"classname",(id (*)())i_ClassDef_classname},
{"globfunname",(id (*)())i_ClassDef_globfunname},
{"_classname",(id (*)())i_ClassDef__classname},
{"_m_classname",(id (*)())i_ClassDef__m_classname},
{"_classfunname",(id (*)())i_ClassDef__classfunname},
{"_m_classfunname",(id (*)())i_ClassDef__m_classfunname},
{"_superfunname",(id (*)())i_ClassDef__superfunname},
{"_m_superfunname",(id (*)())i_ClassDef__m_superfunname},
{"supername",(id (*)())i_ClassDef_supername},
{"superclassdef",(id (*)())i_ClassDef_superclassdef},
{"rootclassdef",(id (*)())i_ClassDef_rootclassdef},
{"rootname",(id (*)())i_ClassDef_rootname},
{"numidivars",(id (*)())i_ClassDef_numidivars},
{"synthrefcntmethods",(id (*)())i_ClassDef_synthrefcntmethods},
{"synthfilermethods",(id (*)())i_ClassDef_synthfilermethods},
{"ivars",(id (*)())i_ClassDef_ivars},
{"ivars:",(id (*)())i_ClassDef_ivars_},
{"cvars",(id (*)())i_ClassDef_cvars},
{"cvars:",(id (*)())i_ClassDef_cvars_},
{"checkvars::::",(id (*)())i_ClassDef_checkvars____},
{"checkivars:",(id (*)())i_ClassDef_checkivars_},
{"checkcvars:",(id (*)())i_ClassDef_checkcvars_},
{"addclsdisp:",(id (*)())i_ClassDef_addclsdisp_},
{"addclssel:",(id (*)())i_ClassDef_addclssel_},
{"addnstdisp:",(id (*)())i_ClassDef_addnstdisp_},
{"addnstsel:",(id (*)())i_ClassDef_addnstsel_},
{"check:includedin:factory:",(id (*)())i_ClassDef_check_includedin_factory_},
{"warnimplnotfound",(id (*)())i_ClassDef_warnimplnotfound},
{"undefcomps",(id (*)())i_ClassDef_undefcomps},
{"defivars",(id (*)())i_ClassDef_defivars},
{"defcvars",(id (*)())i_ClassDef_defcvars},
{"ivarnames",(id (*)())i_ClassDef_ivarnames},
{"cvarnames",(id (*)())i_ClassDef_cvarnames},
{"synth",(id (*)())i_ClassDef_synth},
{"genlineno",(id (*)())i_ClassDef_genlineno},
{"genivars",(id (*)())i_ClassDef_genivars},
{"gencvars",(id (*)())i_ClassDef_gencvars},
{"genprivtype",(id (*)())i_ClassDef_genprivtype},
{"genshartype",(id (*)())i_ClassDef_genshartype},
{"genslt:",(id (*)())i_ClassDef_genslt_},
{"gennilslt",(id (*)())i_ClassDef_gennilslt},
{"genclsdisptbl",(id (*)())i_ClassDef_genclsdisptbl},
{"gennstdisptbl",(id (*)())i_ClassDef_gennstdisptbl},
{"genclassimpl",(id (*)())i_ClassDef_genclassimpl},
{"genmetaimpl",(id (*)())i_ClassDef_genmetaimpl},
{"genclassglobal",(id (*)())i_ClassDef_genclassglobal},
{"genclassref",(id (*)())i_ClassDef_genclassref},
{"genglobfuncall",(id (*)())i_ClassDef_genglobfuncall},
{"gen",(id (*)())i_ClassDef_gen},
{"gensuper",(id (*)())i_ClassDef_gensuper},
{"genmetasuper",(id (*)())i_ClassDef_genmetasuper},
{"use",(id (*)())i_ClassDef_use},
{"define",(id (*)())i_ClassDef_define},
{"isimpl",(id (*)())i_ClassDef_isimpl},
{"forceimpl",(id (*)())i_ClassDef_forceimpl},
{"genintf",(id (*)())i_ClassDef_genintf},
{"genfwddecl",(id (*)())i_ClassDef_genfwddecl},
{"genimpl",(id (*)())i_ClassDef_genimpl},
{"defcomp:astype:",(id (*)())i_ClassDef_defcomp_astype_},
{"lookupivar:",(id (*)())i_ClassDef_lookupivar_},
{"lookupcvar:",(id (*)())i_ClassDef_lookupcvar_},
{"isivar:",(id (*)())i_ClassDef_isivar_},
{"iscvar:",(id (*)())i_ClassDef_iscvar_},
{"st80",(id (*)())i_ClassDef_st80},
{"methodFor:cls:methdef:",(id (*)())i_ClassDef_methodFor_cls_methdef_},
{"bytesizeOf:",(id (*)())i_ClassDef_bytesizeOf_},
{"ivarbytesize",(id (*)())i_ClassDef_ivarbytesize},
{"cvarbytesize",(id (*)())i_ClassDef_cvarbytesize},
{"go",(id (*)())i_ClassDef_go},
{"getivarval:::",(id (*)())i_ClassDef_getivarval___},
{"setivarval::::",(id (*)())i_ClassDef_setivarval____},
{"browsevars",(id (*)())i_ClassDef_browsevars},
{"browsemethods",(id (*)())i_ClassDef_browsemethods},
{"browse",(id (*)())i_ClassDef_browse},
{(char*)0,(id (*)())0}
};
id ClassDef = (id)&_ClassDef;
id  *OBJCCLASS_ClassDef(void) { return &ClassDef; }
struct _SHARED  _ClassDef = {
  (id)&__ClassDef,
  (id)&_Node,
  "ClassDef",
  0,
  sizeof(struct ClassDef_PRIVATE),
  84,
  _ClassDef_nstDispatchTbl,
  41,
  &classdef_modDesc,
  0,
  (id)0,
  &ClassDef,
};
id  OBJCCFUNC_ClassDef(void) { return (id)&_ClassDef; }
id  OBJCCSUPER_ClassDef(void) { return _ClassDef.clsSuper; }
struct _SHARED __ClassDef = {
  (id)&__Object,
  (id)&__Node,
  "ClassDef",
  0,
  sizeof(struct _SHARED),
  1,
  _ClassDef_clsDispatchTbl,
  34,
  &classdef_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_ClassDef(void) { return (id)&__ClassDef; }
id  OBJCMSUPER_ClassDef(void) { return __ClassDef.clsSuper; }
static char *_selTransTbl[] ={
"classname",
"new",
"addspec:",
"sprintf:",
"decl:",
"shartypename:",
"str",
"def:asclass:",
"strCopy",
"isEqual:",
"lookupclass:",
"superclassdef",
"rootclassdef",
"size",
"at:",
"isid",
"find:",
"synth",
"elementsPerform:",
"lineno",
"filename",
"undefcomps",
"checkvars::::",
"add:",
"selector",
"includes:",
"check:includedin:factory:",
"shartypename",
"defivars",
"defcvars",
"genivars",
"gen",
"gencvars",
"str:",
"isgentype:",
"addgentype:",
"genlineno",
"selname",
"impname",
"genslt:",
"gennilslt",
"_classname",
"moddescname",
"_m_classname",
"_classfunname",
"_m_classfunname",
"genprivtype",
"genshartype",
"genfwddecl",
"usesentry:",
"addclsimpl:",
"definesentry:",
"define",
"use",
"genintf",
"genclsdisptbl",
"gennstdisptbl",
"genclassglobal",
"genclassimpl",
"genmetaimpl",
"isivar:",
"iscvar:",
"atKey:put:",
"atKey:",
"lookupivar:",
"lookupcvar:",
"ivarnames",
"addAll:",
"contains:",
"cvarnames",
"usingselfassign",
"shouldNotImplement:",
"bytesize",
"bytesizeOf:",
"error:",
"findClass:",
"unload",
"subclass:::",
"ivarbytesize",
"cvarbytesize",
"findSel:",
"methodFor:cls:methdef:",
"load",
"peekAt:",
"notImplemented:",
"poke:at:",
"gendef:",
"browsevars",
"browsemethods",
0
};
struct modDescriptor classdef_modDesc = {
  "classdef",
  "objc3.3.19",
  0L,
  0,
  0,
  &ClassDef,
  89,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_classdef(void)
{
  selTransTbl = _selTransTbl;
  return &classdef_modDesc;
}
int _OBJCPOSTLINK_classdef = 1;


