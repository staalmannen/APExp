# 1 "symbol.m"
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
extern struct modDescriptor  *_OBJCBIND_symbol(void);
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
extern struct modDescriptor symbol_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//assert.h"
#include <assert.h>

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

# 40 "symbol.m"
BOOL
istypeword(id sym)
{
id objcT0;

# 43 "symbol.m"
return(objcT0=trlunit,(*(BOOL(*)(id,SEL,id))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],sym));
}

BOOL
isbuiltinfun(id sym)
{
id objcT1;

# 49 "symbol.m"
return(objcT1=trlunit,(*(BOOL(*)(id,SEL,id))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],sym));
}

# 59 "./symbol.h"
extern id  Symbol;

# 52 "symbol.m"
void
definebuiltinfun(char*s)
{
id objcT2,objcT3,objcT4,objcT5;

# 55 "symbol.m"
id x=(objcT2=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],s));

x=(objcT3=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2],strtok((objcT4=x,(*(STR(*)(id,SEL))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]))," \t\n\r/")));
(objcT5=trlunit,(*_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4],x));
}

int
pragmatoggle(char*s)
{
id objcT6,objcT7;

# 64 "symbol.m"
id x=(objcT6=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2],s));
# 68 "symbol.m"
return atoi(strtok((objcT7=x,(*(STR(*)(id,SEL))_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3]))," \t\n\r/"));
}

void
definebuiltinvar(char*s)
{
id objcT8,objcT9,objcT10,objcT11;

# 74 "symbol.m"
id x=(objcT8=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT8,selTransTbl[2]))(objcT8,selTransTbl[2],s));

x=(objcT9=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT9,selTransTbl[2]))(objcT9,selTransTbl[2],strtok((objcT10=x,(*(STR(*)(id,SEL))_imp(objcT10,selTransTbl[3]))(objcT10,selTransTbl[3]))," \t\n\r/")));
(objcT11=trlunit,(*_imp(objcT11,selTransTbl[5]))(objcT11,selTransTbl[5],x,t_int));
}

void
definebuiltintype(char*s)
{
id objcT12,objcT13,objcT14,objcT15;

# 83 "symbol.m"
id x=(objcT12=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT12,selTransTbl[2]))(objcT12,selTransTbl[2],s));

x=(objcT13=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT13,selTransTbl[2]))(objcT13,selTransTbl[2],strtok((objcT14=x,(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[3]))(objcT14,selTransTbl[3]))," \t\n\r/")));
(objcT15=trlunit,(*_imp(objcT15,selTransTbl[6]))(objcT15,selTransTbl[6],x));
}
# 59 "./symbol.h"
struct Symbol_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./../../include/objpak/array.h"
unsigned capacity;
# 42 "./../../include/objpak/ocstring.h"
struct objstr value;
# 61 "./symbol.h"
int lineno;
id filename;
id type;};

# 59 "./symbol.h"
extern struct _SHARED _Symbol;
extern struct _SHARED __Symbol;

# 91 "symbol.m"
id s_void;
id s_char;
id s_bool;
id s_int;
id s_uns;
id s_long;
id s_double;
id s_str;
id s_sel;
id s_id;
id s_nil;
id s_self;
id s_cmd;
id s_super;
id s_newblock;
id s_main;
id s_objcmain;
id s_aFiler;
id s_type;
id s_fileIn;
id s_fileOut;
id s_fileInIdsFrom;
id s_fileOutIdsFor;
id s_returnval;
id s_returnflag;
id s_increfs;
id s_decrefs;
id s_idincref;
id s_iddecref;

static id c_Symbol_commonsymbols(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT16,objcT17,objcT18,objcT19,objcT20;
id objcT21,objcT22,objcT23,objcT24,objcT25;
id objcT26,objcT27,objcT28,objcT29,objcT30;
id objcT31,objcT32,objcT33,objcT34,objcT35;
id objcT36,objcT37,objcT38,objcT39,objcT40;
id objcT41,objcT42,objcT43,objcT44;

# 123 "symbol.m"
s_newblock=(objcT16=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT16,selTransTbl[2]))(objcT16,selTransTbl[2],"newBlock"));
# 135 "symbol.m"
s_main=(objcT17=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT17,selTransTbl[2]))(objcT17,selTransTbl[2],"main"));
s_objcmain=(objcT18=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT18,selTransTbl[2]))(objcT18,selTransTbl[2],"objcmain"));
s_void=(objcT19=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT19,selTransTbl[2]))(objcT19,selTransTbl[2],"void"));
s_char=(objcT20=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT20,selTransTbl[2]))(objcT20,selTransTbl[2],"char"));
s_bool=(objcT21=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT21,selTransTbl[2]))(objcT21,selTransTbl[2],"BOOL"));
s_int=(objcT22=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT22,selTransTbl[2]))(objcT22,selTransTbl[2],"int"));
s_uns=(objcT23=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT23,selTransTbl[2]))(objcT23,selTransTbl[2],"unsigned"));
s_long=(objcT24=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT24,selTransTbl[2]))(objcT24,selTransTbl[2],"long"));
s_double=(objcT25=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT25,selTransTbl[2]))(objcT25,selTransTbl[2],"double"));
s_str=(objcT26=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT26,selTransTbl[2]))(objcT26,selTransTbl[2],"STR"));
s_sel=(objcT27=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT27,selTransTbl[2]))(objcT27,selTransTbl[2],"SEL"));
s_id=(objcT28=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT28,selTransTbl[2]))(objcT28,selTransTbl[2],"id"));
s_nil=(objcT29=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT29,selTransTbl[2]))(objcT29,selTransTbl[2],"(id)0"));
s_self=(objcT30=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT30,selTransTbl[2]))(objcT30,selTransTbl[2],"self"));
s_cmd=(objcT31=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT31,selTransTbl[2]))(objcT31,selTransTbl[2],"_cmd"));
s_super=(objcT32=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT32,selTransTbl[2]))(objcT32,selTransTbl[2],"super"));
s_type=(objcT33=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT33,selTransTbl[2]))(objcT33,selTransTbl[2],"type"));
s_aFiler=(objcT34=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT34,selTransTbl[2]))(objcT34,selTransTbl[2],"aFiler"));
s_fileIn=(objcT35=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT35,selTransTbl[2]))(objcT35,selTransTbl[2],"fileIn"));
s_fileOut=(objcT36=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT36,selTransTbl[2]))(objcT36,selTransTbl[2],"fileOut"));
s_fileInIdsFrom=(objcT37=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT37,selTransTbl[2]))(objcT37,selTransTbl[2],"fileInIdsFrom"));
s_fileOutIdsFor=(objcT38=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT38,selTransTbl[2]))(objcT38,selTransTbl[2],"fileOutIdsFor"));
s_returnflag=(objcT39=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT39,selTransTbl[2]))(objcT39,selTransTbl[2],"_returnflag"));
s_returnval=(objcT40=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT40,selTransTbl[2]))(objcT40,selTransTbl[2],"_returnval"));
s_increfs=(objcT41=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT41,selTransTbl[2]))(objcT41,selTransTbl[2],"increfs"));
s_decrefs=(objcT42=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT42,selTransTbl[2]))(objcT42,selTransTbl[2],"decrefs"));
s_idincref=(objcT43=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT43,selTransTbl[2]))(objcT43,selTransTbl[2],"idincref"));
s_iddecref=(objcT44=Symbol,(*(id(*)(id,SEL,STR))_imp(objcT44,selTransTbl[2]))(objcT44,selTransTbl[2],"iddecref"));

return(id)self;
}

static id c_Symbol_str_lineno_filename_(struct Symbol_PRIVATE *self,SEL _cmd,char*s,int no,id fn)
{
id objcT45,objcT46;

# 169 "symbol.m"
return(objcT45=(objcT46=__Symbol.clsSuper,(*(id(*)(id,SEL,STR))_impSuper(objcT46,selTransTbl[2]))((id)self,selTransTbl[2],s)),(*(id(*)(id,SEL,int,id))_imp(objcT45,selTransTbl[7]))(objcT45,selTransTbl[7],no,fn));
}

static id i_Symbol_type(struct Symbol_PRIVATE *self,SEL _cmd)
{
return self->type;
}

static id i_Symbol_filename(struct Symbol_PRIVATE *self,SEL _cmd)
{
return self->filename;
}

static int i_Symbol_lineno(struct Symbol_PRIVATE *self,SEL _cmd)
{
return self->lineno;
}

static id i_Symbol_type_(struct Symbol_PRIVATE *self,SEL _cmd,id fn)
{self->
type=fn;
return(id)self;
}

static id i_Symbol_filename_(struct Symbol_PRIVATE *self,SEL _cmd,id fn)
{self->
filename=fn;
return(id)self;
}

static id i_Symbol_lineno_(struct Symbol_PRIVATE *self,SEL _cmd,int no)
{self->
lineno=no;
return(id)self;
}

static id i_Symbol_lineno_filename_(struct Symbol_PRIVATE *self,SEL _cmd,int no,id fn)
{self->
lineno=no;self->
filename=fn;
return(id)self;
}

static id i_Symbol_synth(struct Symbol_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Symbol_gen(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT47,objcT48;

# 219 "symbol.m"
gl(self->lineno,(objcT47=self->filename,(*(STR(*)(id,SEL))_imp(objcT47,selTransTbl[3]))(objcT47,selTransTbl[3])));
gs((objcT48=(id)self,(*(STR(*)(id,SEL))_imp(objcT48,selTransTbl[3]))(objcT48,selTransTbl[3])));
return(id)self;
}

static BOOL i_Symbol_canforward(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT49,objcT50,objcT51;

# 226 "symbol.m"
id d;


if((objcT49=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT49,selTransTbl[8]))(objcT49,selTransTbl[8])))
return(BOOL)0;
d=(objcT50=trlunit,(*_imp(objcT50,selTransTbl[9]))(objcT50,selTransTbl[9],(id)self));
return(d)?(objcT51=d,(*(BOOL(*)(id,SEL))_imp(objcT51,selTransTbl[10]))(objcT51,selTransTbl[10])):(BOOL)1;
}

static BOOL i_Symbol_isscalartype(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT52,objcT53,objcT54;

# 237 "symbol.m"
id d;

if((objcT52=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT52,selTransTbl[8]))(objcT52,selTransTbl[8])))
return(BOOL)0;
d=(objcT53=trlunit,(*_imp(objcT53,selTransTbl[9]))(objcT53,selTransTbl[9],(id)self));
return(d)?(objcT54=d,(*(BOOL(*)(id,SEL))_imp(objcT54,selTransTbl[11]))(objcT54,selTransTbl[11])):(BOOL)1;
}

static id i_Symbol_dot_(struct Symbol_PRIVATE *self,SEL _cmd,id sym)
{
id objcT55,objcT56;

# 247 "symbol.m"
id d=(objcT55=trlunit,(*_imp(objcT55,selTransTbl[9]))(objcT55,selTransTbl[9],(id)self));

return(d)?(objcT56=d,(*_imp(objcT56,selTransTbl[12]))(objcT56,selTransTbl[12],sym)):(id)0;
}

static id i_Symbol_star(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT57,objcT58;

# 254 "symbol.m"
id d=(objcT57=trlunit,(*_imp(objcT57,selTransTbl[9]))(objcT57,selTransTbl[9],(id)self));

return(d)?(objcT58=d,(*_imp(objcT58,selTransTbl[13]))(objcT58,selTransTbl[13])):(id)0;
}

static id i_Symbol_funcall(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT59,objcT60;

# 261 "symbol.m"
id d=(objcT59=trlunit,(*_imp(objcT59,selTransTbl[9]))(objcT59,selTransTbl[9],(id)self));

return(d)?(objcT60=d,(*_imp(objcT60,selTransTbl[14]))(objcT60,selTransTbl[14])):(id)0;
}

static BOOL i_Symbol_isselptr(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT61,objcT62,objcT63;

# 268 "symbol.m"
id d=(objcT61=trlunit,(*_imp(objcT61,selTransTbl[9]))(objcT61,selTransTbl[9],(id)self));

if((objcT62=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT62,selTransTbl[15]))(objcT62,selTransTbl[15])))
return(BOOL)1;
return(d)?(objcT63=d,(*(BOOL(*)(id,SEL))_imp(objcT63,selTransTbl[16]))(objcT63,selTransTbl[16])):(BOOL)0;
}

static BOOL i_Symbol_isid(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT64,objcT65,objcT66;

# 277 "symbol.m"
id d;
if((id)self==s_id)return(BOOL)1;
if(strcmp((objcT64=(id)self,(*(STR(*)(id,SEL))_imp(objcT64,selTransTbl[3]))(objcT64,selTransTbl[3])),"id")==0)return(BOOL)1;
d=(objcT65=trlunit,(*_imp(objcT65,selTransTbl[9]))(objcT65,selTransTbl[9],(id)self));
return(d)?(objcT66=d,(*(BOOL(*)(id,SEL))_imp(objcT66,selTransTbl[15]))(objcT66,selTransTbl[15])):(BOOL)0;
}

static BOOL i_Symbol_isvolatile(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT67;

# 286 "symbol.m"
return strcmp((objcT67=(id)self,(*(STR(*)(id,SEL))_imp(objcT67,selTransTbl[3]))(objcT67,selTransTbl[3])),"volatile")==0;
}

static BOOL i_Symbol_isrefcounted(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT68,objcT69,objcT70;

# 291 "symbol.m"
id d;
if((id)self==s_id)return(BOOL)1;
if(strcmp((objcT68=(id)self,(*(STR(*)(id,SEL))_imp(objcT68,selTransTbl[3]))(objcT68,selTransTbl[3])),"id")==0)return(BOOL)1;
d=(objcT69=trlunit,(*_imp(objcT69,selTransTbl[9]))(objcT69,selTransTbl[9],(id)self));
return(d)?(objcT70=d,(*(BOOL(*)(id,SEL))_imp(objcT70,selTransTbl[17]))(objcT70,selTransTbl[17])):(BOOL)0;
}

static BOOL i_Symbol_isvoid(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT71,objcT72,objcT73;

# 300 "symbol.m"
id d;
if((id)self==s_void)return(BOOL)1;
if(strcmp((objcT71=(id)self,(*(STR(*)(id,SEL))_imp(objcT71,selTransTbl[3]))(objcT71,selTransTbl[3])),"void")==0)return(BOOL)1;
d=(objcT72=trlunit,(*_imp(objcT72,selTransTbl[9]))(objcT72,selTransTbl[9],(id)self));
return(d)?(objcT73=d,(*(BOOL(*)(id,SEL))_imp(objcT73,selTransTbl[8]))(objcT73,selTransTbl[8])):(BOOL)0;
}

static BOOL i_Symbol_isstorageclass(struct Symbol_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Symbol_isgnuattrib(struct Symbol_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Symbol_isenumtor(struct Symbol_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Symbol_istypedef(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT74;

# 324 "symbol.m"
return strcmp((objcT74=(id)self,(*(STR(*)(id,SEL))_imp(objcT74,selTransTbl[3]))(objcT74,selTransTbl[3])),"typedef")==0;
}

static BOOL i_Symbol_isstatic(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT75;

# 329 "symbol.m"
return strcmp((objcT75=(id)self,(*(STR(*)(id,SEL))_imp(objcT75,selTransTbl[3]))(objcT75,selTransTbl[3])),"static")==0;
}

static BOOL i_Symbol_isextern(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT76,objcT77;
return(strcmp((objcT76=(id)self,(*(STR(*)(id,SEL))_imp(objcT76,selTransTbl[3]))(objcT76,selTransTbl[3])),"extern")==0)||(strstr((objcT77=(id)self,(*(STR(*)(id,SEL))_imp(objcT77,selTransTbl[3]))(objcT77,selTransTbl[3])),"extern")!=NULL);
}

static BOOL i_Symbol_isinline(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT78;

# 340 "symbol.m"
char*token=(objcT78=(id)self,(*(STR(*)(id,SEL))_imp(objcT78,selTransTbl[3]))(objcT78,selTransTbl[3]));

return(strcmp(token,"inline")==0)||(strcmp(token,"__inline")==0)||(strcmp(token,"__inline__")==0);
}

static id i_Symbol_toscores(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT79;

# 347 "symbol.m"
int c;
char*s=(objcT79=(id)self,(*(STR(*)(id,SEL))_imp(objcT79,selTransTbl[3]))(objcT79,selTransTbl[3]));

while((c=( *s))){
if(c==':') *
s='_';
s++;
}
return(id)self;
}

static id i_Symbol_unescape(struct Symbol_PRIVATE *self,SEL _cmd)
{
char c;
int n=0;
char*p=self->value.ptr;
char*q=self->value.ptr;
while((c= *p++)){
if(c=='\"')continue;
if(c=='\\'){
c= *p++;
switch(c){
case'n':c='\n';break;
case'r':c='\r';break;
default:break;
}
} *
q++=c;n++;
}self->
value.count=n; *
q++='\0';
return(id)self;
}

static id i_Symbol_unescapeChar(struct Symbol_PRIVATE *self,SEL _cmd)
{
char c;
int n=0;
char*p=self->value.ptr;
char*q=self->value.ptr;
while((c= *p++)){
if(c=='\'')continue;
if(c=='\\'){
c= *p++;
switch(c){
case'n':c='\n';break;
case'r':c='\r';break;
default:break;
}
} *
q++=c;n++;
}self->
value.count=n; *
q++='\0';
return(id)self;
}

static id i_Symbol_st80(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT80;

# 406 "symbol.m"
gs((objcT80=(id)self,(*(STR(*)(id,SEL))_imp(objcT80,selTransTbl[3]))(objcT80,selTransTbl[3])));
return(id)self;
}

static id i_Symbol_notrlunit(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT81;

# 412 "symbol.m"
return(objcT81=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT81,selTransTbl[18]))(objcT81,selTransTbl[18],"evaluation outside translation unit"));
}

# 24 "./scalar.h"
extern id  Scalar;

# 415 "symbol.m"
static id i_Symbol_zero(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT82,objcT83,objcT84,objcT85,objcT86;
id objcT87,objcT88,objcT89,objcT90,objcT91;
id objcT92,objcT93,objcT94;

# 417 "symbol.m"
id d;
if((objcT82=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT82,selTransTbl[15]))(objcT82,selTransTbl[15])))return(id)0;
if((objcT83=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT83,selTransTbl[19]))(objcT83,selTransTbl[19],s_int)))return(objcT84=(objcT85=Scalar,(*_imp(objcT85,selTransTbl[20]))(objcT85,selTransTbl[20])),(*(id(*)(id,SEL,int))_imp(objcT84,selTransTbl[21]))(objcT84,selTransTbl[21],0));
if((objcT86=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT86,selTransTbl[19]))(objcT86,selTransTbl[19],s_char)))return(objcT87=(objcT88=Scalar,(*_imp(objcT88,selTransTbl[20]))(objcT88,selTransTbl[20])),(*(id(*)(id,SEL,char))_imp(objcT87,selTransTbl[22]))(objcT87,selTransTbl[22],0));
if((objcT89=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT89,selTransTbl[19]))(objcT89,selTransTbl[19],s_str)))return(objcT90=(objcT91=Scalar,(*_imp(objcT91,selTransTbl[20]))(objcT91,selTransTbl[20])),(*(id(*)(id,SEL,char*))_imp(objcT90,selTransTbl[23]))(objcT90,selTransTbl[23],NULL));
if( !trlunit)(objcT92=(id)self,(*_imp(objcT92,selTransTbl[24]))(objcT92,selTransTbl[24]));
d=(objcT93=trlunit,(*_imp(objcT93,selTransTbl[9]))(objcT93,selTransTbl[9],(id)self));
return(d)?(objcT94=d,(*_imp(objcT94,selTransTbl[25]))(objcT94,selTransTbl[25])):(id)0;
}

static int i_Symbol_bytesize(struct Symbol_PRIVATE *self,SEL _cmd)
{
id objcT95,objcT96,objcT97,objcT98,objcT99;
id objcT100;

# 429 "symbol.m"
id d;
if((objcT95=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT95,selTransTbl[15]))(objcT95,selTransTbl[15])))return sizeof(id);
if((objcT96=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT96,selTransTbl[19]))(objcT96,selTransTbl[19],s_int)))return sizeof(int);
if((objcT97=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT97,selTransTbl[19]))(objcT97,selTransTbl[19],s_char)))return sizeof(char);
if((objcT98=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT98,selTransTbl[19]))(objcT98,selTransTbl[19],s_str)))return sizeof(STR);
if( !trlunit)(objcT99=(id)self,(*_imp(objcT99,selTransTbl[24]))(objcT99,selTransTbl[24]));
d=(objcT100=trlunit,(*_imp(objcT100,selTransTbl[9]))(objcT100,selTransTbl[9],(id)self));
if(d){
id objcT101;

# 437 "symbol.m"
return(objcT101=d,(*(int(*)(id,SEL))_imp(objcT101,selTransTbl[26]))(objcT101,selTransTbl[26]));
}else{
id objcT102,objcT103;

# 439 "symbol.m"
(objcT102=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT102,selTransTbl[18]))(objcT102,selTransTbl[18],"dont know how to compute bytesize of %s",(objcT103=(id)self,(*(STR(*)(id,SEL))_imp(objcT103,selTransTbl[3]))(objcT103,selTransTbl[3]))));
return 0;
}
}

static id i_Symbol_peekAt_(struct Symbol_PRIVATE *self,SEL _cmd,char*ptr)
{
id objcT104,objcT105,objcT106,objcT107,objcT108;
id objcT109,objcT110,objcT111,objcT112,objcT113;

# 446 "symbol.m"
id s;
id d;
if((objcT104=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT104,selTransTbl[15]))(objcT104,selTransTbl[15])))return *((id*)ptr);
s=(objcT105=Scalar,(*_imp(objcT105,selTransTbl[20]))(objcT105,selTransTbl[20]));
if((objcT106=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT106,selTransTbl[19]))(objcT106,selTransTbl[19],s_int)))return(objcT107=s,(*(id(*)(id,SEL,int))_imp(objcT107,selTransTbl[21]))(objcT107,selTransTbl[21], *((int*)ptr)));
if((objcT108=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT108,selTransTbl[19]))(objcT108,selTransTbl[19],s_char)))return(objcT109=s,(*(id(*)(id,SEL,char))_imp(objcT109,selTransTbl[22]))(objcT109,selTransTbl[22], *((char*)ptr)));
if((objcT110=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT110,selTransTbl[19]))(objcT110,selTransTbl[19],s_str)))return(objcT111=s,(*(id(*)(id,SEL,char*))_imp(objcT111,selTransTbl[23]))(objcT111,selTransTbl[23], *((char**)ptr)));
if( !trlunit)(objcT112=(id)self,(*_imp(objcT112,selTransTbl[24]))(objcT112,selTransTbl[24]));
d=(objcT113=trlunit,(*_imp(objcT113,selTransTbl[9]))(objcT113,selTransTbl[9],(id)self));
if(d){
id objcT114;

# 456 "symbol.m"
return(objcT114=d,(*(id(*)(id,SEL,char*))_imp(objcT114,selTransTbl[27]))(objcT114,selTransTbl[27],ptr));
}else{
id objcT115,objcT116;

# 458 "symbol.m"
(objcT115=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT115,selTransTbl[18]))(objcT115,selTransTbl[18],"dont know how to peek %s value from memory",(objcT116=(id)self,(*(STR(*)(id,SEL))_imp(objcT116,selTransTbl[3]))(objcT116,selTransTbl[3]))));
return 0;
}
}

static id i_Symbol_poke_at_(struct Symbol_PRIVATE *self,SEL _cmd,id v,char*ptr)
{
id objcT117,objcT118,objcT120,objcT122,objcT124;
id objcT125;

# 465 "symbol.m"
id d;
if((objcT117=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT117,selTransTbl[15]))(objcT117,selTransTbl[15]))){ *((id*)ptr)=v;return v;}
if((objcT118=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT118,selTransTbl[19]))(objcT118,selTransTbl[19],s_int))){
id objcT119;
 *
# 467 "symbol.m"
((int*)ptr)=(objcT119=v,(*(int(*)(id,SEL))_imp(objcT119,selTransTbl[28]))(objcT119,selTransTbl[28]));return v;}
if((objcT120=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT120,selTransTbl[19]))(objcT120,selTransTbl[19],s_char))){
id objcT121;
 *
# 468 "symbol.m"
((char*)ptr)=(objcT121=v,(*(char(*)(id,SEL))_imp(objcT121,selTransTbl[29]))(objcT121,selTransTbl[29]));return v;}
if((objcT122=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT122,selTransTbl[19]))(objcT122,selTransTbl[19],s_str))){
id objcT123;
 *
# 469 "symbol.m"
((char**)ptr)=(objcT123=v,(*(char*(*)(id,SEL))_imp(objcT123,selTransTbl[30]))(objcT123,selTransTbl[30]));return v;}
if( !trlunit)(objcT124=(id)self,(*_imp(objcT124,selTransTbl[24]))(objcT124,selTransTbl[24]));
d=(objcT125=trlunit,(*_imp(objcT125,selTransTbl[9]))(objcT125,selTransTbl[9],(id)self));
if(d){
id objcT126;

# 473 "symbol.m"
return(objcT126=d,(*(id(*)(id,SEL,id,char*))_imp(objcT126,selTransTbl[31]))(objcT126,selTransTbl[31],v,ptr));
}else{
id objcT127,objcT128;

# 475 "symbol.m"
(objcT127=(id)self,(*(id(*)(id,SEL,STR,...))_imp(objcT127,selTransTbl[18]))(objcT127,selTransTbl[18],"dont know how to poke %s value into memory",(objcT128=(id)self,(*(STR(*)(id,SEL))_imp(objcT128,selTransTbl[3]))(objcT128,selTransTbl[3]))));
return 0;
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  String;
extern struct _SHARED _String;
extern struct _SHARED __String;
static struct _SLT _Symbol_clsDispatchTbl[] ={
{"commonsymbols",(id (*)())c_Symbol_commonsymbols},
{"str:lineno:filename:",(id (*)())c_Symbol_str_lineno_filename_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Symbol_nstDispatchTbl[] ={
{"type",(id (*)())i_Symbol_type},
{"filename",(id (*)())i_Symbol_filename},
{"lineno",(id (*)())i_Symbol_lineno},
{"type:",(id (*)())i_Symbol_type_},
{"filename:",(id (*)())i_Symbol_filename_},
{"lineno:",(id (*)())i_Symbol_lineno_},
{"lineno:filename:",(id (*)())i_Symbol_lineno_filename_},
{"synth",(id (*)())i_Symbol_synth},
{"gen",(id (*)())i_Symbol_gen},
{"canforward",(id (*)())i_Symbol_canforward},
{"isscalartype",(id (*)())i_Symbol_isscalartype},
{"dot:",(id (*)())i_Symbol_dot_},
{"star",(id (*)())i_Symbol_star},
{"funcall",(id (*)())i_Symbol_funcall},
{"isselptr",(id (*)())i_Symbol_isselptr},
{"isid",(id (*)())i_Symbol_isid},
{"isvolatile",(id (*)())i_Symbol_isvolatile},
{"isrefcounted",(id (*)())i_Symbol_isrefcounted},
{"isvoid",(id (*)())i_Symbol_isvoid},
{"isstorageclass",(id (*)())i_Symbol_isstorageclass},
{"isgnuattrib",(id (*)())i_Symbol_isgnuattrib},
{"isenumtor",(id (*)())i_Symbol_isenumtor},
{"istypedef",(id (*)())i_Symbol_istypedef},
{"isstatic",(id (*)())i_Symbol_isstatic},
{"isextern",(id (*)())i_Symbol_isextern},
{"isinline",(id (*)())i_Symbol_isinline},
{"toscores",(id (*)())i_Symbol_toscores},
{"unescape",(id (*)())i_Symbol_unescape},
{"unescapeChar",(id (*)())i_Symbol_unescapeChar},
{"st80",(id (*)())i_Symbol_st80},
{"notrlunit",(id (*)())i_Symbol_notrlunit},
{"zero",(id (*)())i_Symbol_zero},
{"bytesize",(id (*)())i_Symbol_bytesize},
{"peekAt:",(id (*)())i_Symbol_peekAt_},
{"poke:at:",(id (*)())i_Symbol_poke_at_},
{(char*)0,(id (*)())0}
};
id Symbol = (id)&_Symbol;
id  *OBJCCLASS_Symbol(void) { return &Symbol; }
struct _SHARED  _Symbol = {
  (id)&__Symbol,
  (id)&_String,
  "Symbol",
  0,
  sizeof(struct Symbol_PRIVATE),
  35,
  _Symbol_nstDispatchTbl,
  41,
  &symbol_modDesc,
  0,
  (id)0,
  &Symbol,
};
id  OBJCCFUNC_Symbol(void) { return (id)&_Symbol; }
id  OBJCCSUPER_Symbol(void) { return _Symbol.clsSuper; }
struct _SHARED __Symbol = {
  (id)&__Object,
  (id)&__String,
  "Symbol",
  0,
  sizeof(struct _SHARED),
  2,
  _Symbol_clsDispatchTbl,
  34,
  &symbol_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Symbol(void) { return (id)&__Symbol; }
id  OBJCMSUPER_Symbol(void) { return __Symbol.clsSuper; }
static char *_selTransTbl[] ={
"istypeword:",
"isbuiltinfun:",
"str:",
"str",
"defbuiltinfun:",
"defdata:astype:",
"defbuiltintype:",
"lineno:filename:",
"isvoid",
"lookuptype:",
"canforward",
"isscalartype",
"dot:",
"star",
"funcall",
"isid",
"isselptr",
"isrefcounted",
"error:",
"isEqual:",
"new",
"u_int:",
"u_char:",
"u_str:",
"notrlunit",
"zero",
"bytesize",
"peekAt:",
"u_int",
"u_char",
"u_str",
"poke:at:",
0
};
struct modDescriptor symbol_modDesc = {
  "symbol",
  "objc3.3.19",
  0L,
  0,
  0,
  &Symbol,
  32,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_symbol(void)
{
  selTransTbl = _selTransTbl;
  return &symbol_modDesc;
}
int _OBJCPOSTLINK_symbol = 1;


