# 1 "node.m"
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
extern struct modDescriptor  *_OBJCBIND_node(void);
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
extern struct modDescriptor node_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stddef.h"
#include <stddef.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//ctype.h"
#include <ctype.h>

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
# 39 "node.m"
FILE*gfile;
id infilename;
char*outfilename;
int exitstatus,inlineno,outlineno;
id loadedmodules;

static FILE*backupgfile;
static BOOL lastisalpha;

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 48 "node.m"
char*
browsepath(char*filename)
{
if( !o_browsedir){
fatal("browse dir not set");
return NULL;
}else{
id objcT0,objcT1,objcT2,objcT3;

# 55 "node.m"
id buf=(objcT0=String,(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],o_browsedir));
(objcT1=buf,(*(id(*)(id,SEL,STR))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],o_pathsep));
(objcT2=buf,(*(id(*)(id,SEL,STR))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1],filename));
return(objcT3=buf,(*(STR(*)(id,SEL))_imp(objcT3,selTransTbl[2]))(objcT3,selTransTbl[2]));
}
}

void
gstderr(void)
{
backupgfile=gfile;
o_nolinetags++;
gfile=stderr;
}

void
gnormal(void)
{
gfile=backupgfile;
o_nolinetags--;
}

BOOL
needspace(char c)
{
return isalnum(c)||c=='_'||c=='$';
}

void
gc(char c)
{
if(needspace(c)){
if(lastisalpha)
fputc(' ',gfile);
fputc(c,gfile);
lastisalpha=needspace(c);
}else{
if(c=='\n')
outlineno++;
fputc(c,gfile);
lastisalpha=(BOOL)0;
}
}

void
gextc(void)
{
if(o_cplus)
gs("extern \"C\" ");
}

void
g_otbvars(void)
{

gs("  struct OTB *previnst;\n");
gs("  struct OTB *nextinst;\n");
}

void
gs(char*s)
{
int i,n=strlen(s);

if(n&&lastisalpha&&needspace(s[0]))
fputc(' ',gfile);
for(i=0;i<n;i++)
if(s[i]=='\n')
outlineno++;
fputs(s,gfile);
if(n)
lastisalpha=needspace(s[n-1]);
}

void
gf(char*s,...)
{
va_list ap;
int i,n=strlen(s);

if(n&&lastisalpha&&needspace(s[0]))
fputc(' ',gfile);
for(i=0;i<n;i++)
if(s[i]=='\n')
outlineno++;
va_start(ap,s);
vfprintf(gfile,s,ap);
va_end(ap);
if(n)
lastisalpha=needspace(s[n-1]);
}

void
gcom(char*cm)
{
if(o_comments)
gs(cm);
gc('\n');
}

# 159 "node.m"
void
gvarlist(id c,char*cm,char*iz)
{
id objcT4;

# 162 "node.m"
int j,k,n;

for(k=0,n=(objcT4=c,(*(unsigned(*)(id,SEL))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3]));k<n;){
gs(cm);
for(j=0;j<5&&k<n;j++,k++){
id objcT5,objcT6;

# 167 "node.m"
if(j)
gc(',');
gs((objcT5=(objcT6=c,(*(id(*)(id,SEL,unsigned))_imp(objcT6,selTransTbl[4]))(objcT6,selTransTbl[4],k)),(*(STR(*)(id,SEL))_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2])));
gs(iz);
}
gc(';');
gc('\n');
}
}

void
gcommalist(id args)
{
id objcT7,objcT8,objcT9;

# 180 "node.m"
int i,n=(objcT7=args,(*(unsigned(*)(id,SEL))_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3]));

if(n)
(objcT8=(objcT9=args,(*(id(*)(id,SEL,unsigned))_imp(objcT9,selTransTbl[4]))(objcT9,selTransTbl[4],0)),(*_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5]));
for(i=1;i<n;i++){
id objcT10,objcT11;

# 185 "node.m"
gc(',');
(objcT10=(objcT11=args,(*(id(*)(id,SEL,unsigned))_imp(objcT11,selTransTbl[4]))(objcT11,selTransTbl[4],i)),(*_imp(objcT10,selTransTbl[5]))(objcT10,selTransTbl[5]));
}
}

void
gl(int no,char*fn)
{
int d=no-outlineno;

if(o_nolinetags||no==0||fn==NULL)
return;


if(0<d&&d<4&&outfilename==fn){
while(d--)
gc('\n');
outlineno=no;
}else{
if(d!=0||outfilename!=fn){
if(outlineno)
fputc('\n',gfile);
fprintf(gfile,o_tagformat,no,fn);
outlineno=no;
outfilename=fn;
}
}
}

void
vwarn(char*s,va_list ap)
{
int n;

vfprintf(stderr,s,ap);
if((n=strlen(s))&&s[n-1]!='\n')
fprintf(stderr,"\n");
}

void
warnat(id sym,char*s,...)
{
if(o_warnings){
id objcT12,objcT13,objcT14;

# 228 "node.m"
va_list ap;
int no=(objcT12=sym,(*(int(*)(id,SEL))_imp(objcT12,selTransTbl[6]))(objcT12,selTransTbl[6]));
char*fn=(objcT13=(objcT14=sym,(*_imp(objcT14,selTransTbl[7]))(objcT14,selTransTbl[7])),(*(STR(*)(id,SEL))_imp(objcT13,selTransTbl[2]))(objcT13,selTransTbl[2]));

va_start(ap,s);
if(no!=0&&fn!=NULL)
fprintf(stderr,"%s:%d: warning: ",fn,no);
vwarn(s,ap);
va_end(ap);
}
}

void
warn(char*s,...)
{
if(o_warnings){
id objcT15;

# 244 "node.m"
va_list ap;

va_start(ap,s);
fprintf(stderr,"%s:%d: warning: ",(objcT15=infilename,(*(STR(*)(id,SEL))_imp(objcT15,selTransTbl[2]))(objcT15,selTransTbl[2])),inlineno);
vwarn(s,ap);
va_end(ap);
}
}

void
vfatal(char*s,va_list ap)
{
int n;

vfprintf(stderr,s,ap);
if((n=strlen(s))&&s[n-1]!='\n')
fprintf(stderr,"\n");
exitstatus=1;
}

void
fatal(char*s,...)
{
id objcT16;

# 267 "node.m"
va_list ap;

va_start(ap,s);
fprintf(stderr,"%s:%d: fatal: ",(objcT16=infilename,(*(STR(*)(id,SEL))_imp(objcT16,selTransTbl[2]))(objcT16,selTransTbl[2])),inlineno);
vfatal(s,ap);
va_end(ap);
}

void
fatalat(id sym,char*s,...)
{
id objcT17,objcT18,objcT19;

# 278 "node.m"
va_list ap;
int no=(objcT17=sym,(*(int(*)(id,SEL))_imp(objcT17,selTransTbl[6]))(objcT17,selTransTbl[6]));
char*fn=(objcT18=(objcT19=sym,(*_imp(objcT19,selTransTbl[7]))(objcT19,selTransTbl[7])),(*(STR(*)(id,SEL))_imp(objcT18,selTransTbl[2]))(objcT18,selTransTbl[2]));

va_start(ap,s);
if(no!=0&&fn!=NULL)
fprintf(stderr,"%s:%d: fatal: ",fn,no);
vfatal(s,ap);
va_end(ap);
}
# 48 "./node.h"
struct Node_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;};

# 48 "./node.h"
extern id  Node;

# 48 "./node.h"
extern struct _SHARED _Node;
extern struct _SHARED __Node;


# 291 "node.m"
static id i_Node_synth(struct Node_PRIVATE *self,SEL _cmd)
{
id objcT20;

# 293 "node.m"
return(objcT20=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8],_cmd));
}

static id i_Node_sgen(struct Node_PRIVATE *self,SEL _cmd)
{
id objcT21;

# 298 "node.m"
o_nolinetags++;
(objcT21=(id)self,(*_imp(objcT21,selTransTbl[5]))(objcT21,selTransTbl[5]));
o_nolinetags--;
return(id)self;
}

static id i_Node_gen(struct Node_PRIVATE *self,SEL _cmd)
{
id objcT22;

# 306 "node.m"
return(objcT22=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT22,selTransTbl[8]))(objcT22,selTransTbl[8],_cmd));
}

static id i_Node_st80(struct Node_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

static BOOL i_Node_isstorageclass(struct Node_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Node_isscalartype(struct Node_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Node_isgnuattrib(struct Node_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Node_isid(struct Node_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static BOOL i_Node_isvoid(struct Node_PRIVATE *self,SEL _cmd)
{
return(BOOL)0;
}

static id i_Node_dot_(struct Node_PRIVATE *self,SEL _cmd,id sym)
{
return(id)0;
}

static id i_Node_go(struct Node_PRIVATE *self,SEL _cmd)
{
id objcT23;

# 346 "node.m"
fprintf(stderr,"vici>%s\n",(objcT23=(id)self,(*(STR(*)(id,SEL))_imp(objcT23,selTransTbl[9]))(objcT23,selTransTbl[9])));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Node_clsDispatchTbl[] ={
{(char*)0,(id (*)())0}
};
static struct _SLT _Node_nstDispatchTbl[] ={
{"synth",(id (*)())i_Node_synth},
{"sgen",(id (*)())i_Node_sgen},
{"gen",(id (*)())i_Node_gen},
{"st80",(id (*)())i_Node_st80},
{"isstorageclass",(id (*)())i_Node_isstorageclass},
{"isscalartype",(id (*)())i_Node_isscalartype},
{"isgnuattrib",(id (*)())i_Node_isgnuattrib},
{"isid",(id (*)())i_Node_isid},
{"isvoid",(id (*)())i_Node_isvoid},
{"dot:",(id (*)())i_Node_dot_},
{"go",(id (*)())i_Node_go},
{(char*)0,(id (*)())0}
};
id Node = (id)&_Node;
id  *OBJCCLASS_Node(void) { return &Node; }
struct _SHARED  _Node = {
  (id)&__Node,
  (id)&_Object,
  "Node",
  0,
  sizeof(struct Node_PRIVATE),
  11,
  _Node_nstDispatchTbl,
  41,
  &node_modDesc,
  0,
  (id)0,
  &Node,
};
id  OBJCCFUNC_Node(void) { return (id)&_Node; }
id  OBJCCSUPER_Node(void) { return _Node.clsSuper; }
struct _SHARED __Node = {
  (id)&__Object,
  (id)&__Object,
  "Node",
  0,
  sizeof(struct _SHARED),
  0,
  _Node_clsDispatchTbl,
  34,
  &node_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Node(void) { return (id)&__Node; }
id  OBJCMSUPER_Node(void) { return __Node.clsSuper; }
static char *_selTransTbl[] ={
"str:",
"concatSTR:",
"str",
"size",
"at:",
"gen",
"lineno",
"filename",
"subclassResponsibility:",
"name",
0
};
struct modDescriptor node_modDesc = {
  "node",
  "objc3.3.19",
  0L,
  0,
  0,
  &Node,
  10,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_node(void)
{
  selTransTbl = _selTransTbl;
  return &node_modDesc;
}
int _OBJCPOSTLINK_node = 1;


