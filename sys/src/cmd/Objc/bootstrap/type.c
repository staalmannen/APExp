# 1 "type.m"
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
extern struct modDescriptor  *_OBJCBIND_type(void);
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
extern struct modDescriptor type_modDesc;

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
# 22 "./structsp.h"
extern id curstruct;
# 46 "type.m"
id t_unknown;
id t_void;
id t_char;
id t_bool;
id t_int;
id t_uns;
id t_long;
id t_double;
id t_str;
id t_sel;
id t_id;
# 34 "./type.h"
struct Type_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 36 "./type.h"
id specs,decl;
BOOL isstatic;
BOOL isextern;
BOOL haslistinit;};

# 34 "./type.h"
extern id  Type;

# 34 "./type.h"
extern struct _SHARED _Type;
extern struct _SHARED __Type;


# 60 "type.m"
static id c_Type_commontypes(struct Type_PRIVATE *self,SEL _cmd)
{
if( !t_unknown){
id objcT0,objcT1,objcT2,objcT3,objcT4;
id objcT5,objcT6,objcT7,objcT8,objcT9;
id objcT10,objcT11,objcT12,objcT13,objcT14;
id objcT15,objcT16,objcT17,objcT18,objcT19;
id objcT20;

# 63 "type.m"
t_unknown=(objcT0=Type,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
t_void=(objcT1=(objcT2=Type,(*_imp(objcT2,selTransTbl[0]))(objcT2,selTransTbl[0])),(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],s_void));
t_char=(objcT3=(objcT4=Type,(*_imp(objcT4,selTransTbl[0]))(objcT4,selTransTbl[0])),(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1],s_char));
t_bool=(objcT5=(objcT6=Type,(*_imp(objcT6,selTransTbl[0]))(objcT6,selTransTbl[0])),(*_imp(objcT5,selTransTbl[1]))(objcT5,selTransTbl[1],s_bool));
t_int=(objcT7=(objcT8=Type,(*_imp(objcT8,selTransTbl[0]))(objcT8,selTransTbl[0])),(*_imp(objcT7,selTransTbl[1]))(objcT7,selTransTbl[1],s_int));
t_uns=(objcT9=(objcT10=Type,(*_imp(objcT10,selTransTbl[0]))(objcT10,selTransTbl[0])),(*_imp(objcT9,selTransTbl[1]))(objcT9,selTransTbl[1],s_uns));
t_long=(objcT11=(objcT12=Type,(*_imp(objcT12,selTransTbl[0]))(objcT12,selTransTbl[0])),(*_imp(objcT11,selTransTbl[1]))(objcT11,selTransTbl[1],s_long));
t_double=(objcT13=(objcT14=Type,(*_imp(objcT14,selTransTbl[0]))(objcT14,selTransTbl[0])),(*_imp(objcT13,selTransTbl[1]))(objcT13,selTransTbl[1],s_double));
t_str=(objcT15=(objcT16=Type,(*_imp(objcT16,selTransTbl[0]))(objcT16,selTransTbl[0])),(*_imp(objcT15,selTransTbl[1]))(objcT15,selTransTbl[1],s_str));
t_sel=(objcT17=(objcT18=Type,(*_imp(objcT18,selTransTbl[0]))(objcT18,selTransTbl[0])),(*_imp(objcT17,selTransTbl[1]))(objcT17,selTransTbl[1],s_sel));
t_id=(objcT19=(objcT20=Type,(*_imp(objcT20,selTransTbl[0]))(objcT20,selTransTbl[0])),(*_imp(objcT19,selTransTbl[1]))(objcT19,selTransTbl[1],s_id));
}
return(id)self;
}

static id i_Type_specs(struct Type_PRIVATE *self,SEL _cmd)
{
return self->specs;
}

static id i_Type_decl(struct Type_PRIVATE *self,SEL _cmd)
{
return self->decl;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 88 "type.m"
static id i_Type_abstrspecs_(struct Type_PRIVATE *self,SEL _cmd,id aList)
{
if(aList){self->
specs=aList;
}else{
id objcT21,objcT22;
self->
# 93 "type.m"
specs=(objcT21=OrdCltn,(*_imp(objcT21,selTransTbl[0]))(objcT21,selTransTbl[0]));
(objcT22=self->specs,(*_imp(objcT22,selTransTbl[2]))(objcT22,selTransTbl[2],s_int));
}
return(id)self;
}

# 59 "./symbol.h"
extern id  Symbol;

# 24 "./structsp.h"
extern id  StructSpec;

# 22 "./enumsp.h"
extern id  EnumSpec;

# 99 "type.m"
static id i_Type_checkspec_(struct Type_PRIVATE *self,SEL _cmd,id s)
{
id objcT23,objcT24,objcT25,objcT26,objcT27;
id objcT28,objcT29;

# 101 "type.m"
if((objcT23=s,(*(BOOL(*)(id,SEL,id))_imp(objcT23,selTransTbl[3]))(objcT23,selTransTbl[3],(id)(objcT24=Symbol,(*_imp(objcT24,selTransTbl[4]))(objcT24,selTransTbl[4])))))
return(id)self;
if((objcT25=s,(*(BOOL(*)(id,SEL,id))_imp(objcT25,selTransTbl[3]))(objcT25,selTransTbl[3],(id)(objcT26=StructSpec,(*_imp(objcT26,selTransTbl[4]))(objcT26,selTransTbl[4])))))
return(id)self;
if((objcT27=s,(*(BOOL(*)(id,SEL,id))_imp(objcT27,selTransTbl[3]))(objcT27,selTransTbl[3],(id)(objcT28=EnumSpec,(*_imp(objcT28,selTransTbl[4]))(objcT28,selTransTbl[4])))))
return(id)self;
fprintf(stderr,"%s\n",(objcT29=s,(*(STR(*)(id,SEL))_imp(objcT29,selTransTbl[5]))(objcT29,selTransTbl[5])));
return(id)0;
}

static int i_Type_lineno(struct Type_PRIVATE *self,SEL _cmd)
{
if(self->specs){
id objcT30;

# 114 "type.m"
int i,n=(objcT30=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT30,selTransTbl[6]))(objcT30,selTransTbl[6]));
for(i=0;i<n;i++){
id objcT31,objcT32;

# 116 "type.m"
int no=(objcT31=(objcT32=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT32,selTransTbl[7]))(objcT32,selTransTbl[7],i)),(*(int(*)(id,SEL))_imp(objcT31,selTransTbl[8]))(objcT31,selTransTbl[8]));if(no)return no;
}
}
return 0;
}

static id i_Type_filename(struct Type_PRIVATE *self,SEL _cmd)
{
if(self->specs){
id objcT33;

# 125 "type.m"
int i,n=(objcT33=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT33,selTransTbl[6]))(objcT33,selTransTbl[6]));
for(i=0;i<n;i++){
id objcT34,objcT35;

# 127 "type.m"
id no=(objcT34=(objcT35=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT35,selTransTbl[7]))(objcT35,selTransTbl[7],i)),(*_imp(objcT34,selTransTbl[9]))(objcT34,selTransTbl[9]));if(no)return no;
}
}
return(id)0;
}

static id i_Type_specs_(struct Type_PRIVATE *self,SEL _cmd,id aList)
{
if(aList){
id objcT36,objcT37,objcT42;

# 136 "type.m"
int i,n;
id typespecs=(objcT36=OrdCltn,(*_imp(objcT36,selTransTbl[0]))(objcT36,selTransTbl[0]));

for(i=0,n=(objcT37=aList,(*(unsigned(*)(id,SEL))_imp(objcT37,selTransTbl[6]))(objcT37,selTransTbl[6]));i<n;i++){
id objcT38,objcT39,objcT40,objcT41;

# 140 "type.m"
id s=(objcT38=aList,(*(id(*)(id,SEL,unsigned))_imp(objcT38,selTransTbl[7]))(objcT38,selTransTbl[7],i));

(void)0;

if( !(objcT39=s,(*(BOOL(*)(id,SEL))_imp(objcT39,selTransTbl[10]))(objcT39,selTransTbl[10]))&& !(objcT40=s,(*(BOOL(*)(id,SEL))_imp(objcT40,selTransTbl[11]))(objcT40,selTransTbl[11])))
(objcT41=typespecs,(*_imp(objcT41,selTransTbl[2]))(objcT41,selTransTbl[2],s));
}
return(objcT42=(id)self,(*_imp(objcT42,selTransTbl[12]))(objcT42,selTransTbl[12],typespecs));
}else{
id objcT43;

# 149 "type.m"
return(objcT43=(id)self,(*_imp(objcT43,selTransTbl[1]))(objcT43,selTransTbl[1],s_int));
}
}

static id i_Type_addspec_(struct Type_PRIVATE *self,SEL _cmd,id aSpec)
{
id objcT44;

# 155 "type.m"
if( !self->specs)self->
specs=(objcT44=OrdCltn,(*_imp(objcT44,selTransTbl[0]))(objcT44,selTransTbl[0]));
if(aSpec){
id objcT45;

# 158 "type.m"
(void)0;
(void)0;
(objcT45=self->specs,(*_imp(objcT45,selTransTbl[2]))(objcT45,selTransTbl[2],aSpec));
}
return(id)self;
}

static id i_Type_abstrdecl_(struct Type_PRIVATE *self,SEL _cmd,id aDecl)
{self->
decl=aDecl;
return(id)self;
}

static id i_Type_decl_(struct Type_PRIVATE *self,SEL _cmd,id aDecl)
{
id objcT46,objcT47;

# 173 "type.m"
return(objcT46=(id)self,(*_imp(objcT46,selTransTbl[13]))(objcT46,selTransTbl[13],(aDecl)?(objcT47=aDecl,(*_imp(objcT47,selTransTbl[14]))(objcT47,selTransTbl[14])):(id)0));
}

static BOOL i_Type_haslistinit(struct Type_PRIVATE *self,SEL _cmd)
{
return self->haslistinit;
}

static BOOL i_Type_isstatic(struct Type_PRIVATE *self,SEL _cmd)
{
return self->isstatic;
}

static BOOL i_Type_isextern(struct Type_PRIVATE *self,SEL _cmd)
{
return self->isextern;
}

static BOOL i_Type_definesocu(struct Type_PRIVATE *self,SEL _cmd)
{
return !self->isstatic;
}

static id i_Type_isstatic_(struct Type_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
isstatic=flag;
return(id)self;
}

static id i_Type_isextern_(struct Type_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
isextern=flag;
return(id)self;
}

static id i_Type_haslistinit_(struct Type_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
haslistinit=flag;
return(id)self;
}

static id i_Type_max_(struct Type_PRIVATE *self,SEL _cmd,id aType)
{
if((id)self==t_unknown||aType==t_unknown)
return t_unknown;
return(id)self;
}

static unsigned i_Type_hash(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT51;

# 223 "type.m"
unsigned h=0;

if(self->specs){
id objcT48,objcT49,objcT50;

# 226 "type.m"
int i,n;

h=(n=(objcT48=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT48,selTransTbl[6]))(objcT48,selTransTbl[6])));
for(i=0;i<n;i++)
h=(h<<1)^((objcT49=(objcT50=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT50,selTransTbl[7]))(objcT50,selTransTbl[7],i)),(*(unsigned(*)(id,SEL))_imp(objcT49,selTransTbl[15]))(objcT49,selTransTbl[15])));
}
if(self->decl)
h^=(objcT51=self->decl,(*(unsigned(*)(id,SEL))_imp(objcT51,selTransTbl[15]))(objcT51,selTransTbl[15]));
return h;
}

static BOOL i_Type_isEqual_(struct Type_PRIVATE *self,SEL _cmd,id x)
{
if((id)self==x){
return(BOOL)1;
}else{
id objcT52,objcT53,objcT54,objcT55;

# 242 "type.m"
id y,z;

y=(objcT52=x,(*_imp(objcT52,selTransTbl[16]))(objcT52,selTransTbl[16]));
if(self->specs&&y&& !(objcT53=self->specs,(*(BOOL(*)(id,SEL,id))_imp(objcT53,selTransTbl[17]))(objcT53,selTransTbl[17],y)))
return(BOOL)0;
if(( !self->specs|| !y)&&self->specs!=y)
return(BOOL)0;
z=(objcT54=x,(*_imp(objcT54,selTransTbl[18]))(objcT54,selTransTbl[18]));
if(self->decl&&z&& !(objcT55=self->decl,(*(BOOL(*)(id,SEL,id))_imp(objcT55,selTransTbl[17]))(objcT55,selTransTbl[17],z)))
return(BOOL)0;
if(( !self->decl|| !z)&&self->decl!=z)
return(BOOL)0;
return(BOOL)1;
}
}

static BOOL i_Type_isvoid(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT56,objcT57,objcT58;

# 260 "type.m"
if((id)self==t_void)
return(BOOL)1;
return self->decl==(id)0&&(objcT56=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT56,selTransTbl[6]))(objcT56,selTransTbl[6]))==1&&(objcT57=(objcT58=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT58,selTransTbl[7]))(objcT58,selTransTbl[7],0)),(*(BOOL(*)(id,SEL))_imp(objcT57,selTransTbl[19]))(objcT57,selTransTbl[19]));
}

static BOOL i_Type_isid(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT59,objcT60,objcT61;

# 267 "type.m"
if((id)self==t_id)
return(BOOL)1;
return self->decl==(id)0&&(objcT59=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT59,selTransTbl[6]))(objcT59,selTransTbl[6]))==1&&(objcT60=(objcT61=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT61,selTransTbl[7]))(objcT61,selTransTbl[7],0)),(*(BOOL(*)(id,SEL))_imp(objcT60,selTransTbl[20]))(objcT60,selTransTbl[20]));
}

static BOOL i_Type_isrefcounted(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT62;

# 274 "type.m"
int n;
if((id)self==t_id){
return(BOOL)1;
}
if(self->decl==(id)0&&(n=(objcT62=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT62,selTransTbl[6]))(objcT62,selTransTbl[6])))>0){
id objcT65,objcT66;

# 279 "type.m"
int i;
for(i=0;i<n;i++){
id objcT63,objcT64;

# 281 "type.m"
if((objcT63=(objcT64=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT64,selTransTbl[7]))(objcT64,selTransTbl[7],i)),(*(BOOL(*)(id,SEL))_imp(objcT63,selTransTbl[21]))(objcT63,selTransTbl[21])))return(BOOL)0;
}
return(objcT65=(objcT66=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT66,selTransTbl[7]))(objcT66,selTransTbl[7],n-1)),(*(BOOL(*)(id,SEL))_imp(objcT65,selTransTbl[22]))(objcT65,selTransTbl[22]));
}
return(BOOL)0;
}

static BOOL i_Type_isscalartype(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT67;
if((objcT67=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT67,selTransTbl[23]))(objcT67,selTransTbl[23]))){
return(BOOL)1;
}else{
id objcT68;

# 294 "type.m"
if(self->decl==(id)0||(objcT68=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT68,selTransTbl[24]))(objcT68,selTransTbl[24]))){
id objcT69;

# 295 "type.m"
int i,n;


for(i=0,n=(objcT69=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT69,selTransTbl[6]))(objcT69,selTransTbl[6]));i<n;i++){
id objcT70,objcT71,objcT72;

# 299 "type.m"
id sp=(objcT70=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT70,selTransTbl[7]))(objcT70,selTransTbl[7],i));

if((objcT71=sp,(*(BOOL(*)(id,SEL))_imp(objcT71,selTransTbl[10]))(objcT71,selTransTbl[10])))
continue;
if( !(objcT72=sp,(*(BOOL(*)(id,SEL))_imp(objcT72,selTransTbl[24]))(objcT72,selTransTbl[24])))
return(BOOL)0;
}
return(BOOL)1;
}else{
return(BOOL)0;
}
}
}

static BOOL i_Type_canforward(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT73;

# 315 "type.m"
if((objcT73=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT73,selTransTbl[23]))(objcT73,selTransTbl[23]))){
return(BOOL)1;
}else{
id objcT74;

# 318 "type.m"
if(self->decl==(id)0||(objcT74=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT74,selTransTbl[25]))(objcT74,selTransTbl[25]))){
id objcT75;

# 319 "type.m"
int i,n;


for(i=0,n=(objcT75=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT75,selTransTbl[6]))(objcT75,selTransTbl[6]));i<n;i++){
id objcT76,objcT77,objcT78;

# 323 "type.m"
id sp=(objcT76=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT76,selTransTbl[7]))(objcT76,selTransTbl[7],i));

if((objcT77=sp,(*(BOOL(*)(id,SEL))_imp(objcT77,selTransTbl[10]))(objcT77,selTransTbl[10])))
continue;
if( !(objcT78=sp,(*(BOOL(*)(id,SEL))_imp(objcT78,selTransTbl[25]))(objcT78,selTransTbl[25])))
return(BOOL)0;
}
return(BOOL)1;
}else{
return(BOOL)0;
}
}
}

static BOOL i_Type_isselptr(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT79;

# 339 "type.m"
if((objcT79=self->decl,(*(BOOL(*)(id,SEL))_imp(objcT79,selTransTbl[23]))(objcT79,selTransTbl[23]))){
return(BOOL)1;
}else{
if(self->decl==(id)0){
id objcT80;

# 343 "type.m"
int i,n;


for(i=0,n=(objcT80=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT80,selTransTbl[6]))(objcT80,selTransTbl[6]));i<n;i++){
id objcT81,objcT82,objcT83;

# 347 "type.m"
id sp=(objcT81=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT81,selTransTbl[7]))(objcT81,selTransTbl[7],i));

if((objcT82=sp,(*(BOOL(*)(id,SEL))_imp(objcT82,selTransTbl[10]))(objcT82,selTransTbl[10])))
continue;
if( !(objcT83=sp,(*(BOOL(*)(id,SEL))_imp(objcT83,selTransTbl[26]))(objcT83,selTransTbl[26])))
return(BOOL)0;
}
return(BOOL)1;
}else{
return(BOOL)0;
}
}
}

static id i_Type_synth(struct Type_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Type_gen(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT84,objcT85;

# 368 "type.m"
if(self->specs)
(objcT84=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT84,selTransTbl[27]))(objcT84,selTransTbl[27],selTransTbl[28]));
if(self->decl)
(objcT85=self->decl,(*_imp(objcT85,selTransTbl[28]))(objcT85,selTransTbl[28]));
return(id)self;
}

static id i_Type_genabstrtype(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT86;

# 377 "type.m"
return(objcT86=(id)self,(*_imp(objcT86,selTransTbl[29]))(objcT86,selTransTbl[29],(id)0));
}

static id i_Type_gendef_(struct Type_PRIVATE *self,SEL _cmd,id sym)
{
id objcT87;

# 382 "type.m"
o_nolinetags++;
if(self->specs)
(objcT87=self->specs,(*(id(*)(id,SEL,SEL))_imp(objcT87,selTransTbl[27]))(objcT87,selTransTbl[27],selTransTbl[28]));
if(self->decl){
id objcT88;

# 386 "type.m"
(objcT88=self->decl,(*_imp(objcT88,selTransTbl[29]))(objcT88,selTransTbl[29],sym));
}else{
id objcT89;

# 388 "type.m"
if(sym)
(objcT89=sym,(*_imp(objcT89,selTransTbl[28]))(objcT89,selTransTbl[28]));
}
o_nolinetags--;
return(id)self;
}

static id i_Type_dot_(struct Type_PRIVATE *self,SEL _cmd,id sym)
{
id objcT90,objcT91,objcT92;

# 397 "type.m"
if(self->decl)
return(id)0;
if((objcT90=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT90,selTransTbl[6]))(objcT90,selTransTbl[6]))!=1)
return(id)0;
return(objcT91=(objcT92=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT92,selTransTbl[7]))(objcT92,selTransTbl[7],0)),(*_imp(objcT91,selTransTbl[30]))(objcT91,selTransTbl[30],sym));
}

static id i_Type_star(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT93,objcT94,objcT95,objcT96,objcT97;
id objcT98,objcT99;

# 406 "type.m"
if(self->decl==(id)0&&(objcT93=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT93,selTransTbl[6]))(objcT93,selTransTbl[6]))==1)
return(objcT94=(objcT95=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT95,selTransTbl[7]))(objcT95,selTransTbl[7],0)),(*_imp(objcT94,selTransTbl[31]))(objcT94,selTransTbl[31]));
if(self->decl==(id)0&&(objcT96=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT96,selTransTbl[6]))(objcT96,selTransTbl[6]))!=1)
return(id)0;
return(objcT97=(objcT98=(id)self,(*_imp(objcT98,selTransTbl[32]))(objcT98,selTransTbl[32])),(*_imp(objcT97,selTransTbl[13]))(objcT97,selTransTbl[13],(objcT99=self->decl,(*_imp(objcT99,selTransTbl[31]))(objcT99,selTransTbl[31]))));
}

# 22 "./pointer.h"
extern id  Pointer;

# 22 "./stardecl.h"
extern id  StarDecl;

# 413 "type.m"
static id i_Type_ampersand(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT100,objcT101,objcT102,objcT103,objcT104;
id objcT105;

# 415 "type.m"
id s,p;

p=(objcT100=Pointer,(*_imp(objcT100,selTransTbl[0]))(objcT100,selTransTbl[0]));
s=(objcT101=(objcT102=(objcT103=StarDecl,(*_imp(objcT103,selTransTbl[0]))(objcT103,selTransTbl[0])),(*_imp(objcT102,selTransTbl[33]))(objcT102,selTransTbl[33],p)),(*_imp(objcT101,selTransTbl[34]))(objcT101,selTransTbl[34],self->decl));
return(objcT104=(objcT105=(id)self,(*_imp(objcT105,selTransTbl[32]))(objcT105,selTransTbl[32])),(*_imp(objcT104,selTransTbl[13]))(objcT104,selTransTbl[13],s));
}

static id i_Type_funcall(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT106,objcT107,objcT108,objcT109,objcT110;
id objcT111,objcT112;

# 424 "type.m"
if(self->decl==(id)0&&(objcT106=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT106,selTransTbl[6]))(objcT106,selTransTbl[6]))==1)
return(objcT107=(objcT108=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT108,selTransTbl[7]))(objcT108,selTransTbl[7],0)),(*_imp(objcT107,selTransTbl[35]))(objcT107,selTransTbl[35]));
if(self->decl==(id)0&&(objcT109=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT109,selTransTbl[6]))(objcT109,selTransTbl[6]))!=1)
return(id)0;
return(objcT110=(objcT111=(id)self,(*_imp(objcT111,selTransTbl[32]))(objcT111,selTransTbl[32])),(*_imp(objcT110,selTransTbl[13]))(objcT110,selTransTbl[13],(objcT112=self->decl,(*_imp(objcT112,selTransTbl[35]))(objcT112,selTransTbl[35]))));
}

# 24 "./scalar.h"
extern id  Scalar;

# 22 "./arydecl.h"
extern id  ArrayDecl;

# 431 "type.m"
static id i_Type_zero(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT113,objcT114,objcT115,objcT116,objcT117;
id objcT118,objcT119,objcT126;

# 433 "type.m"
if((objcT113=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT113,selTransTbl[17]))(objcT113,selTransTbl[17],t_id)))return(id)0;
if((objcT114=(id)self,(*(BOOL(*)(id,SEL,id))_imp(objcT114,selTransTbl[17]))(objcT114,selTransTbl[17],t_str)))return(objcT115=(objcT116=Scalar,(*_imp(objcT116,selTransTbl[0]))(objcT116,selTransTbl[0])),(*(id(*)(id,SEL,char*))_imp(objcT115,selTransTbl[36]))(objcT115,selTransTbl[36],NULL));
if((objcT117=self->decl,(*(BOOL(*)(id,SEL,id))_imp(objcT117,selTransTbl[3]))(objcT117,selTransTbl[3],(id)(objcT118=ArrayDecl,(*_imp(objcT118,selTransTbl[4]))(objcT118,selTransTbl[4]))))&&(objcT119=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT119,selTransTbl[6]))(objcT119,selTransTbl[6]))==1){
id objcT120,objcT121,objcT122,objcT123,objcT124;
id objcT125;

# 436 "type.m"
id s;
int n=(objcT120=(objcT121=self->decl,(*_imp(objcT121,selTransTbl[37]))(objcT121,selTransTbl[37])),(*(int(*)(id,SEL))_imp(objcT120,selTransTbl[38]))(objcT120,selTransTbl[38]));
s=(objcT122=Symbol,(*(id(*)(id,SEL,unsigned))_imp(objcT122,selTransTbl[39]))(objcT122,selTransTbl[39],n));
return(objcT123=(objcT124=Scalar,(*_imp(objcT124,selTransTbl[0]))(objcT124,selTransTbl[0])),(*(id(*)(id,SEL,char*))_imp(objcT123,selTransTbl[36]))(objcT123,selTransTbl[36],(objcT125=s,(*(STR(*)(id,SEL))_imp(objcT125,selTransTbl[40]))(objcT125,selTransTbl[40]))));
}
if(self->decl==(id)0&&(objcT126=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT126,selTransTbl[6]))(objcT126,selTransTbl[6]))==1){
id objcT127,objcT128;

# 442 "type.m"
return(objcT127=(objcT128=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT128,selTransTbl[7]))(objcT128,selTransTbl[7],0)),(*_imp(objcT127,selTransTbl[41]))(objcT127,selTransTbl[41]));
}
return(id)0;
}

static id i_Type_peekAt_(struct Type_PRIVATE *self,SEL _cmd,char*ptr)
{
id objcT129;

# 449 "type.m"
if(self->decl==(id)0&&(objcT129=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT129,selTransTbl[6]))(objcT129,selTransTbl[6]))==1){
id objcT130,objcT131;

# 450 "type.m"
return(objcT130=(objcT131=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT131,selTransTbl[7]))(objcT131,selTransTbl[7],0)),(*(id(*)(id,SEL,char*))_imp(objcT130,selTransTbl[42]))(objcT130,selTransTbl[42],ptr));
}else{
id objcT132;

# 452 "type.m"
(objcT132=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT132,selTransTbl[43]))(objcT132,selTransTbl[43],_cmd));
return 0;
}
}

static id i_Type_poke_at_(struct Type_PRIVATE *self,SEL _cmd,id v,char*ptr)
{
id objcT133;

# 459 "type.m"
if(self->decl==(id)0&&(objcT133=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT133,selTransTbl[6]))(objcT133,selTransTbl[6]))==1){
id objcT134,objcT135;

# 460 "type.m"
return(objcT134=(objcT135=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT135,selTransTbl[7]))(objcT135,selTransTbl[7],0)),(*(id(*)(id,SEL,id,char*))_imp(objcT134,selTransTbl[44]))(objcT134,selTransTbl[44],v,ptr));
}else{
id objcT136;

# 462 "type.m"
(objcT136=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT136,selTransTbl[43]))(objcT136,selTransTbl[43],_cmd));
return 0;
}
}

static int i_Type_bytesize(struct Type_PRIVATE *self,SEL _cmd)
{
id objcT137;

# 469 "type.m"
if(self->decl==(id)0&&(objcT137=self->specs,(*(unsigned(*)(id,SEL))_imp(objcT137,selTransTbl[6]))(objcT137,selTransTbl[6]))==1){
id objcT138,objcT139;

# 470 "type.m"
return(objcT138=(objcT139=self->specs,(*(id(*)(id,SEL,unsigned))_imp(objcT139,selTransTbl[7]))(objcT139,selTransTbl[7],0)),(*(int(*)(id,SEL))_imp(objcT138,selTransTbl[45]))(objcT138,selTransTbl[45]));
}else{
id objcT140;

# 472 "type.m"
(objcT140=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT140,selTransTbl[43]))(objcT140,selTransTbl[43],_cmd));
return 0;
}
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _Type_clsDispatchTbl[] ={
{"commontypes",(id (*)())c_Type_commontypes},
{(char*)0,(id (*)())0}
};
static struct _SLT _Type_nstDispatchTbl[] ={
{"specs",(id (*)())i_Type_specs},
{"decl",(id (*)())i_Type_decl},
{"abstrspecs:",(id (*)())i_Type_abstrspecs_},
{"checkspec:",(id (*)())i_Type_checkspec_},
{"lineno",(id (*)())i_Type_lineno},
{"filename",(id (*)())i_Type_filename},
{"specs:",(id (*)())i_Type_specs_},
{"addspec:",(id (*)())i_Type_addspec_},
{"abstrdecl:",(id (*)())i_Type_abstrdecl_},
{"decl:",(id (*)())i_Type_decl_},
{"haslistinit",(id (*)())i_Type_haslistinit},
{"isstatic",(id (*)())i_Type_isstatic},
{"isextern",(id (*)())i_Type_isextern},
{"definesocu",(id (*)())i_Type_definesocu},
{"isstatic:",(id (*)())i_Type_isstatic_},
{"isextern:",(id (*)())i_Type_isextern_},
{"haslistinit:",(id (*)())i_Type_haslistinit_},
{"max:",(id (*)())i_Type_max_},
{"hash",(id (*)())i_Type_hash},
{"isEqual:",(id (*)())i_Type_isEqual_},
{"isvoid",(id (*)())i_Type_isvoid},
{"isid",(id (*)())i_Type_isid},
{"isrefcounted",(id (*)())i_Type_isrefcounted},
{"isscalartype",(id (*)())i_Type_isscalartype},
{"canforward",(id (*)())i_Type_canforward},
{"isselptr",(id (*)())i_Type_isselptr},
{"synth",(id (*)())i_Type_synth},
{"gen",(id (*)())i_Type_gen},
{"genabstrtype",(id (*)())i_Type_genabstrtype},
{"gendef:",(id (*)())i_Type_gendef_},
{"dot:",(id (*)())i_Type_dot_},
{"star",(id (*)())i_Type_star},
{"ampersand",(id (*)())i_Type_ampersand},
{"funcall",(id (*)())i_Type_funcall},
{"zero",(id (*)())i_Type_zero},
{"peekAt:",(id (*)())i_Type_peekAt_},
{"poke:at:",(id (*)())i_Type_poke_at_},
{"bytesize",(id (*)())i_Type_bytesize},
{(char*)0,(id (*)())0}
};
id Type = (id)&_Type;
id  *OBJCCLASS_Type(void) { return &Type; }
struct _SHARED  _Type = {
  (id)&__Type,
  (id)&_Node,
  "Type",
  0,
  sizeof(struct Type_PRIVATE),
  38,
  _Type_nstDispatchTbl,
  41,
  &type_modDesc,
  0,
  (id)0,
  &Type,
};
id  OBJCCFUNC_Type(void) { return (id)&_Type; }
id  OBJCCSUPER_Type(void) { return _Type.clsSuper; }
struct _SHARED __Type = {
  (id)&__Object,
  (id)&__Node,
  "Type",
  0,
  sizeof(struct _SHARED),
  1,
  _Type_clsDispatchTbl,
  34,
  &type_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Type(void) { return (id)&__Type; }
id  OBJCMSUPER_Type(void) { return __Type.clsSuper; }
static char *_selTransTbl[] ={
"new",
"addspec:",
"add:",
"isKindOf:",
"class",
"name",
"size",
"at:",
"lineno",
"filename",
"isstorageclass",
"isgnuattrib",
"abstrspecs:",
"abstrdecl:",
"abstrdecl",
"hash",
"specs",
"isEqual:",
"decl",
"isvoid",
"isid",
"isvolatile",
"isrefcounted",
"ispointer",
"isscalartype",
"canforward",
"isselptr",
"elementsPerform:",
"gen",
"gendef:",
"dot:",
"star",
"copy",
"pointer:",
"decl:",
"funcall",
"u_str:",
"expr",
"asInt",
"new:",
"strCopy",
"zero",
"peekAt:",
"notImplemented:",
"poke:at:",
"bytesize",
0
};
struct modDescriptor type_modDesc = {
  "type",
  "objc3.3.19",
  0L,
  0,
  0,
  &Type,
  46,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_type(void)
{
  selTransTbl = _selTransTbl;
  return &type_modDesc;
}
int _OBJCPOSTLINK_type = 1;


