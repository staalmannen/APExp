# 1 "method.m"
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
extern struct modDescriptor  *_OBJCBIND_method(void);
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
extern struct modDescriptor method_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//string.h"
#include <string.h>

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
# 22 "./method.h"
struct Method_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 24 "./method.h"
int lineno;
id filename;
id restype;
id usel;
id ksel;
id selector;
BOOL varargs;
BOOL haveneedscast;
BOOL needscast;
BOOL havecanforward;
BOOL canforward;
BOOL haveisselptr;
BOOL isselptr;
BOOL havehash;
unsigned typehash;};

# 22 "./method.h"
extern id  Method;

# 22 "./method.h"
extern struct _SHARED _Method;
extern struct _SHARED __Method;


# 50 "method.m"
static id i_Method_usel(struct Method_PRIVATE *self,SEL _cmd)
{
return self->usel;
}

static id i_Method_ksel(struct Method_PRIVATE *self,SEL _cmd)
{
return self->ksel;
}

static id i_Method_canforward_(struct Method_PRIVATE *self,SEL _cmd,BOOL f)
{self->
havecanforward=(BOOL)1;self->
canforward=f;
return(id)self;
}

static id i_Method_calccanforward(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT0,objcT1,objcT2,objcT3;
self->
# 69 "method.m"
havecanforward=(BOOL)1;self->
canforward=(BOOL)1;

if(self->varargs){self->
canforward=(BOOL)0;
return(id)self;
}
if((objcT0=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]))==(BOOL)0||(objcT1=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1]))){self->
canforward=(BOOL)1;
return(id)self;
}


if(self->restype&& !((objcT2=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]))||(objcT3=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT3,selTransTbl[3]))(objcT3,selTransTbl[3])))){self->
canforward=(BOOL)0;
return(id)self;
}
if(self->ksel){
id objcT4;

# 87 "method.m"
int i,n;

for(i=0,n=(objcT4=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT4,selTransTbl[4]))(objcT4,selTransTbl[4]));i<n;i++){
id objcT5,objcT6;

# 90 "method.m"
if( !(objcT5=(objcT6=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT6,selTransTbl[5]))(objcT6,selTransTbl[5],i)),(*(BOOL(*)(id,SEL))_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]))){self->
canforward=(BOOL)0;
return(id)self;
}
}
}
return(id)self;
}

static id i_Method_calcisselptr(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT7;
self->
# 101 "method.m"
haveisselptr=(BOOL)1;self->
isselptr=(BOOL)1;

if((objcT7=(id)self,(*(BOOL(*)(id,SEL))_imp(objcT7,selTransTbl[0]))(objcT7,selTransTbl[0]))==(BOOL)0){
id objcT8;

# 105 "method.m"
if(self->ksel&&(objcT8=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4]))>3)self->
isselptr=(BOOL)0;
}else{
if(self->usel){
id objcT9;

# 109 "method.m"
if(self->restype&& !(objcT9=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT9,selTransTbl[1]))(objcT9,selTransTbl[1])))self->
isselptr=(BOOL)0;
}
if(self->ksel){
id objcT10;

# 113 "method.m"
int i,n=(objcT10=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT10,selTransTbl[4]))(objcT10,selTransTbl[4]));

if(n>3){self->
isselptr=(BOOL)0;
}else{
id objcT11;

# 118 "method.m"
if(self->restype&& !(objcT11=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT11,selTransTbl[1]))(objcT11,selTransTbl[1]))){self->
isselptr=(BOOL)0;
return(id)self;
}
for(i=0;i<n;i++){
id objcT12,objcT13;

# 123 "method.m"
if( !(objcT12=(objcT13=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT13,selTransTbl[5]))(objcT13,selTransTbl[5],i)),(*(BOOL(*)(id,SEL))_imp(objcT12,selTransTbl[1]))(objcT12,selTransTbl[1]))){self->
isselptr=(BOOL)0;
return(id)self;
}
}
}
}
}
return(id)self;
}

static id i_Method_calchash(struct Method_PRIVATE *self,SEL _cmd)
{self->
havehash=(BOOL)1;
# 141 "method.m"
if(self->usel){
id objcT14,objcT15;
self->
# 142 "method.m"
typehash=(self->restype)?(objcT14=self->restype,(*(unsigned(*)(id,SEL))_imp(objcT14,selTransTbl[6]))(objcT14,selTransTbl[6])):(objcT15=t_id,(*(unsigned(*)(id,SEL))_imp(objcT15,selTransTbl[6]))(objcT15,selTransTbl[6]));
}
if(self->ksel){
id objcT16,objcT17,objcT18;

# 145 "method.m"
int i,n;self->

typehash=(self->restype)?(objcT16=self->restype,(*(unsigned(*)(id,SEL))_imp(objcT16,selTransTbl[6]))(objcT16,selTransTbl[6])):(objcT17=t_id,(*(unsigned(*)(id,SEL))_imp(objcT17,selTransTbl[6]))(objcT17,selTransTbl[6]));
for(i=0,n=(objcT18=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT18,selTransTbl[4]))(objcT18,selTransTbl[4]));i<n;i++){
id objcT19,objcT20;
self->
# 149 "method.m"
typehash=(self->typehash<<1)^(objcT19=(objcT20=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT20,selTransTbl[5]))(objcT20,selTransTbl[5],i)),(*(unsigned(*)(id,SEL))_imp(objcT19,selTransTbl[7]))(objcT19,selTransTbl[7]));
}
}
return(id)self;
}

static unsigned i_Method_typehash(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT21;

# 157 "method.m"
if( !self->havehash)
(objcT21=(id)self,(*_imp(objcT21,selTransTbl[8]))(objcT21,selTransTbl[8]));
return self->typehash;
}

static BOOL i_Method_typeEqual_(struct Method_PRIVATE *self,SEL _cmd,id that)
{
if((id)self==that){
return(BOOL)1;
}else{
id objcT22,objcT23,objcT24,objcT25;

# 167 "method.m"
id y;
id a=self->restype;
id b=(objcT22=that,(*_imp(objcT22,selTransTbl[9]))(objcT22,selTransTbl[9]));

if( !a)
a=t_id;
if( !b)
b=t_id;
if( !(objcT23=a,(*(BOOL(*)(id,SEL,id))_imp(objcT23,selTransTbl[10]))(objcT23,selTransTbl[10],b)))
return(BOOL)0;
if(self->usel&&(y=(objcT24=that,(*_imp(objcT24,selTransTbl[11]))(objcT24,selTransTbl[11])))){
return(BOOL)1;
}
if(self->ksel&&(y=(objcT25=that,(*_imp(objcT25,selTransTbl[12]))(objcT25,selTransTbl[12])))){
id objcT26,objcT27;

# 181 "method.m"
int i,n=(objcT26=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT26,selTransTbl[4]))(objcT26,selTransTbl[4]));

if(n!=(objcT27=y,(*(unsigned(*)(id,SEL))_imp(objcT27,selTransTbl[4]))(objcT27,selTransTbl[4])))
return(BOOL)0;
for(i=0;i<n;i++){
id objcT28,objcT29,objcT30;

# 186 "method.m"
if( !(objcT28=(objcT29=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT29,selTransTbl[5]))(objcT29,selTransTbl[5],i)),(*(BOOL(*)(id,SEL,id))_imp(objcT28,selTransTbl[13]))(objcT28,selTransTbl[13],(objcT30=y,(*(id(*)(id,SEL,unsigned))_imp(objcT30,selTransTbl[5]))(objcT30,selTransTbl[5],i)))))
return(BOOL)0;
}
return(BOOL)1;
}
return(BOOL)0;
}
}

static id i_Method_calcneedscast(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT31;
self->
# 197 "method.m"
haveneedscast++;

if(o_inlinecache){self->
needscast=(BOOL)1;
return(id)self;
}
if(self->restype!=(id)0&& !(objcT31=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT31,selTransTbl[14]))(objcT31,selTransTbl[14]))){self->
needscast=(BOOL)1;
return(id)self;
}
if(self->ksel){
id objcT32;

# 208 "method.m"
int i,n;

for(i=0,n=(objcT32=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT32,selTransTbl[4]))(objcT32,selTransTbl[4]));i<n;i++){
id objcT33,objcT34;

# 211 "method.m"
if( !(objcT33=(objcT34=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT34,selTransTbl[5]))(objcT34,selTransTbl[5],i)),(*(BOOL(*)(id,SEL))_imp(objcT33,selTransTbl[14]))(objcT33,selTransTbl[14]))){self->
needscast=(BOOL)1;
break;
}
}
}
return(id)self;
}

static BOOL i_Method_needscast(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT35;

# 222 "method.m"
if( !self->haveneedscast)
(objcT35=(id)self,(*_imp(objcT35,selTransTbl[15]))(objcT35,selTransTbl[15]));
return self->needscast;
}

static BOOL i_Method_isselptr(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT36;

# 229 "method.m"
if( !self->haveisselptr)
(objcT36=(id)self,(*_imp(objcT36,selTransTbl[16]))(objcT36,selTransTbl[16]));
return self->isselptr;
}

static BOOL i_Method_canforward(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT37;

# 236 "method.m"
if( !self->havecanforward)
(objcT37=(id)self,(*_imp(objcT37,selTransTbl[17]))(objcT37,selTransTbl[17]));
return self->canforward;
}

static id i_Method_restype(struct Method_PRIVATE *self,SEL _cmd)
{
return self->restype;
}

static id i_Method_restype_(struct Method_PRIVATE *self,SEL _cmd,id t)
{self->
restype=t;
return(id)self;
}

static int i_Method_lineno(struct Method_PRIVATE *self,SEL _cmd)
{
if(self->lineno)
return self->lineno;
if(self->usel){
id objcT38;
self->
# 257 "method.m"
lineno=(objcT38=self->usel,(*(int(*)(id,SEL))_imp(objcT38,selTransTbl[18]))(objcT38,selTransTbl[18]));
}else{
id objcT39,objcT40,objcT41;

# 259 "method.m"
id fkeyw=(objcT39=(objcT40=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT40,selTransTbl[5]))(objcT40,selTransTbl[5],0)),(*_imp(objcT39,selTransTbl[19]))(objcT39,selTransTbl[19]));self->

lineno=(objcT41=fkeyw,(*(int(*)(id,SEL))_imp(objcT41,selTransTbl[18]))(objcT41,selTransTbl[18]));
}
return self->lineno;
}

static id i_Method_filename(struct Method_PRIVATE *self,SEL _cmd)
{
if(self->filename)
return self->filename;
if(self->usel){
id objcT42;
self->
# 271 "method.m"
filename=(objcT42=self->usel,(*_imp(objcT42,selTransTbl[20]))(objcT42,selTransTbl[20]));
}else{
id objcT43,objcT44,objcT45;

# 273 "method.m"
id fkeyw=(objcT43=(objcT44=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT44,selTransTbl[5]))(objcT44,selTransTbl[5],0)),(*_imp(objcT43,selTransTbl[19]))(objcT43,selTransTbl[19]));self->

filename=(objcT45=fkeyw,(*_imp(objcT45,selTransTbl[20]))(objcT45,selTransTbl[20]));
}
return self->filename;
}

static id i_Method_unarysel_(struct Method_PRIVATE *self,SEL _cmd,id aSel)
{self->
usel=aSel;
return(id)self;
}

static id i_Method_keywsel_(struct Method_PRIVATE *self,SEL _cmd,id aList)
{self->
ksel=aList;
return(id)self;
}

# 22 "./selector.h"
extern id  Selector;

# 292 "method.m"
static id i_Method_selector(struct Method_PRIVATE *self,SEL _cmd)
{
if(self->selector){
return self->selector;
}else{
if(self->usel){
id objcT46,objcT47;
self->
# 298 "method.m"
selector=(objcT46=Selector,(*(id(*)(id,SEL,STR))_imp(objcT46,selTransTbl[21]))(objcT46,selTransTbl[21],(objcT47=self->usel,(*(STR(*)(id,SEL))_imp(objcT47,selTransTbl[22]))(objcT47,selTransTbl[22]))));
}else{
id objcT48,objcT49;
self->
# 300 "method.m"
selector=(objcT48=Selector,(*_imp(objcT48,selTransTbl[23]))(objcT48,selTransTbl[23]));
(objcT49=self->ksel,(*(id(*)(id,SEL,SEL,id))_imp(objcT49,selTransTbl[24]))(objcT49,selTransTbl[24],selTransTbl[25],self->selector));
}
return self->selector;
}
}

static BOOL i_Method_varargs(struct Method_PRIVATE *self,SEL _cmd)
{
return self->varargs;
}

static id i_Method_varargs_(struct Method_PRIVATE *self,SEL _cmd,BOOL flag)
{self->
varargs=flag;
return(id)self;
}

static id i_Method_cvtcommalist(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT50,objcT51;
if(self->ksel)
(objcT50=(objcT51=self->ksel,(*_imp(objcT51,selTransTbl[26]))(objcT51,selTransTbl[26])),(*_imp(objcT50,selTransTbl[27]))(objcT50,selTransTbl[27]));
return(id)self;
}

static id i_Method_warnforwithmethod(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT52,objcT53;

# 328 "method.m"
char*s=(objcT52=(objcT53=(id)self,(*_imp(objcT53,selTransTbl[28]))(objcT53,selTransTbl[28])),(*(STR(*)(id,SEL))_imp(objcT52,selTransTbl[22]))(objcT52,selTransTbl[22]));
if( !strcmp(s,"with:")){
id objcT54,objcT55;

if(self->ksel)
(objcT54=(objcT55=self->ksel,(*_imp(objcT55,selTransTbl[26]))(objcT55,selTransTbl[26])),(*_imp(objcT54,selTransTbl[29]))(objcT54,selTransTbl[29]));
}
return(id)self;
}

static id i_Method_gencast(struct Method_PRIVATE *self,SEL _cmd)
{
if(self->restype){
id objcT56;

# 341 "method.m"
(objcT56=self->restype,(*_imp(objcT56,selTransTbl[30]))(objcT56,selTransTbl[30]));
}else{
gs("id");
}

gs("(*)");

gc('(');
gs("id,SEL");
if(self->ksel){
id objcT57;

# 351 "method.m"
int i,n;

for(i=0,n=(objcT57=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT57,selTransTbl[4]))(objcT57,selTransTbl[4]));i<n;i++){
id objcT58,objcT59;

# 354 "method.m"
gc(',');
(objcT58=(objcT59=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT59,selTransTbl[5]))(objcT59,selTransTbl[5],i)),(*_imp(objcT58,selTransTbl[30]))(objcT58,selTransTbl[30]));
}
if(self->varargs){
gs(",...");
}
}
gc(')');
return(id)self;
}

static id i_Method_genrestype(struct Method_PRIVATE *self,SEL _cmd)
{
if(self->restype){
id objcT60;

# 368 "method.m"
(objcT60=self->restype,(*_imp(objcT60,selTransTbl[31]))(objcT60,selTransTbl[31]));
}else{
gs("id");
}
return(id)self;
}

static id i_Method_genargstruct(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT61;

# 377 "method.m"
if(self->restype==(id)0|| !(objcT61=self->restype,(*(BOOL(*)(id,SEL))_imp(objcT61,selTransTbl[3]))(objcT61,selTransTbl[3]))){
id objcT62;

# 378 "method.m"
(objcT62=(id)self,(*_imp(objcT62,selTransTbl[32]))(objcT62,selTransTbl[32]));
gs("_retval;\n");
}else{
gs("int _retval;\n");
}
if(self->ksel){
id objcT63;

# 384 "method.m"
int i,n;

for(i=0,n=(objcT63=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT63,selTransTbl[4]))(objcT63,selTransTbl[4]));i<n;i++){
id objcT64,objcT65;

# 387 "method.m"
(objcT64=(objcT65=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT65,selTransTbl[5]))(objcT65,selTransTbl[5],i)),(*_imp(objcT64,selTransTbl[33]))(objcT64,selTransTbl[33]));
gs(";\n");
}
}
return(id)self;
}

static id i_Method_genparmlist(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT66;

# 396 "method.m"
if(self->ksel)
(objcT66=self->ksel,(*(id(*)(id,SEL,SEL))_imp(objcT66,selTransTbl[34]))(objcT66,selTransTbl[34],selTransTbl[35]));
if(self->varargs){
gc(',');
gs("...");
}
return(id)self;
}

static id i_Method_genmsgargs(struct Method_PRIVATE *self,SEL _cmd)
{
if(self->ksel){
id objcT67;

# 408 "method.m"
int i,n=(objcT67=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT67,selTransTbl[4]))(objcT67,selTransTbl[4]));

for(i=0;i<n;i++){
id objcT68,objcT69;

# 411 "method.m"
gc(',');
(objcT68=(objcT69=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT69,selTransTbl[5]))(objcT69,selTransTbl[5],i)),(*_imp(objcT68,selTransTbl[36]))(objcT68,selTransTbl[36]));
}
}
return(id)self;
}

static id i_Method_gendispargs(struct Method_PRIVATE *self,SEL _cmd)
{
if(self->ksel){
id objcT70;

# 421 "method.m"
int i,n=(objcT70=self->ksel,(*(unsigned(*)(id,SEL))_imp(objcT70,selTransTbl[4]))(objcT70,selTransTbl[4]));

for(i=0;i<n;i++){
id objcT71,objcT72;

# 424 "method.m"
gc(',');
(objcT71=(objcT72=self->ksel,(*(id(*)(id,SEL,unsigned))_imp(objcT72,selTransTbl[5]))(objcT72,selTransTbl[5],i)),(*_imp(objcT71,selTransTbl[37]))(objcT71,selTransTbl[37]));
}
}
return(id)self;
}

static id i_Method_gendispargsintostruct(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT73;

# 433 "method.m"
if(self->ksel)
(objcT73=self->ksel,(*(id(*)(id,SEL,SEL))_imp(objcT73,selTransTbl[34]))(objcT73,selTransTbl[34],_cmd));
return(id)self;
}

static id i_Method_synth(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT74;

# 440 "method.m"
if(self->ksel)
(objcT74=self->ksel,(*(id(*)(id,SEL,SEL))_imp(objcT74,selTransTbl[34]))(objcT74,selTransTbl[34],_cmd));
return(id)self;
}

static id i_Method_gen(struct Method_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static id i_Method_st80(struct Method_PRIVATE *self,SEL _cmd)
{
id objcT75,objcT76;

# 452 "method.m"
if(self->usel)
(objcT75=self->usel,(*_imp(objcT75,selTransTbl[38]))(objcT75,selTransTbl[38]));
if(self->ksel)
(objcT76=self->ksel,(*(id(*)(id,SEL,SEL))_imp(objcT76,selTransTbl[34]))(objcT76,selTransTbl[34],_cmd));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Node;
extern struct _SHARED _Node;
extern struct _SHARED __Node;
static struct _SLT _Method_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Method_nstDispatchTbl[] ={
{"usel",(id (*)())i_Method_usel},
{"ksel",(id (*)())i_Method_ksel},
{"canforward:",(id (*)())i_Method_canforward_},
{"calccanforward",(id (*)())i_Method_calccanforward},
{"calcisselptr",(id (*)())i_Method_calcisselptr},
{"calchash",(id (*)())i_Method_calchash},
{"typehash",(id (*)())i_Method_typehash},
{"typeEqual:",(id (*)())i_Method_typeEqual_},
{"calcneedscast",(id (*)())i_Method_calcneedscast},
{"needscast",(id (*)())i_Method_needscast},
{"isselptr",(id (*)())i_Method_isselptr},
{"canforward",(id (*)())i_Method_canforward},
{"restype",(id (*)())i_Method_restype},
{"restype:",(id (*)())i_Method_restype_},
{"lineno",(id (*)())i_Method_lineno},
{"filename",(id (*)())i_Method_filename},
{"unarysel:",(id (*)())i_Method_unarysel_},
{"keywsel:",(id (*)())i_Method_keywsel_},
{"selector",(id (*)())i_Method_selector},
{"varargs",(id (*)())i_Method_varargs},
{"varargs:",(id (*)())i_Method_varargs_},
{"cvtcommalist",(id (*)())i_Method_cvtcommalist},
{"warnforwithmethod",(id (*)())i_Method_warnforwithmethod},
{"gencast",(id (*)())i_Method_gencast},
{"genrestype",(id (*)())i_Method_genrestype},
{"genargstruct",(id (*)())i_Method_genargstruct},
{"genparmlist",(id (*)())i_Method_genparmlist},
{"genmsgargs",(id (*)())i_Method_genmsgargs},
{"gendispargs",(id (*)())i_Method_gendispargs},
{"gendispargsintostruct",(id (*)())i_Method_gendispargsintostruct},
{"synth",(id (*)())i_Method_synth},
{"gen",(id (*)())i_Method_gen},
{"st80",(id (*)())i_Method_st80},
{(char*)0,(id (*)())0}
};
id Method = (id)&_Method;
id  *OBJCCLASS_Method(void) { return &Method; }
struct _SHARED  _Method = {
  (id)&__Method,
  (id)&_Node,
  "Method",
  0,
  sizeof(struct Method_PRIVATE),
  33,
  _Method_nstDispatchTbl,
  41,
  &method_modDesc,
  0,
  (id)0,
  &Method,
};
id  OBJCCFUNC_Method(void) { return (id)&_Method; }
id  OBJCCSUPER_Method(void) { return _Method.clsSuper; }
struct _SHARED __Method = {
  (id)&__Object,
  (id)&__Node,
  "Method",
  0,
  sizeof(struct _SHARED),
  0,
  _Method_clsDispatchTbl,
  34,
  &method_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Method(void) { return (id)&__Method; }
id  OBJCMSUPER_Method(void) { return __Method.clsSuper; }
static char *_selTransTbl[] ={
"needscast",
"isselptr",
"canforward",
"isvoid",
"size",
"at:",
"hash",
"typehash",
"calchash",
"restype",
"isEqual:",
"usel",
"ksel",
"typeEqual:",
"isid",
"calcneedscast",
"calcisselptr",
"calccanforward",
"lineno",
"keyw",
"filename",
"str:",
"str",
"new",
"elementsPerform:with:",
"selcons:",
"lastElement",
"cvtcommalist",
"selector",
"warnforwithmethod",
"genabstrtype",
"gen",
"genrestype",
"genparm",
"elementsPerform:",
"gencommaparm",
"genarg",
"gendisparg",
"st80",
0
};
struct modDescriptor method_modDesc = {
  "method",
  "objc3.3.19",
  0L,
  0,
  0,
  &Method,
  39,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_method(void)
{
  selTransTbl = _selTransTbl;
  return &method_modDesc;
}
int _OBJCPOSTLINK_method = 1;


