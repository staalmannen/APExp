# 1 "postlink.m"
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
extern struct modDescriptor  *_OBJCBIND_postlink(void);
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
extern struct modDescriptor postlink_modDesc;

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

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

# 38 "./../../include/objcrt/Block.h"
extern id newBlock(int n,IMP fn,void*data,IMP dtor);
# 31 "./../../include/objpak/ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 28 "./../../include/objpak/bag.h"
typedef struct objbag
{
int count;
int capacity;
id*ptr;
int*cnts;
}*
objbag_t;
# 28 "./../../include/objpak/set.h"
typedef struct objset
{
int count;
int capacity;
id*ptr;
}*
objset_t;
# 31 "./../../include/objpak/sortcltn.h"
typedef struct objbbt
{
struct objbbt*ulink;
struct objbbt*rlink;
struct objbbt*llink;
int balance;
id key;
}*
objbbt_t;
# 32 "./../../include/objpak/ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 28 "./../../include/objpak/idarray.h"
typedef struct idary
{
int capacity;
id*ptr;
}*
idary_t;
# 28 "./../../include/objpak/intarray.h"
typedef struct intary
{
int capacity;
int*ptr;
}*
intary_t;
# 53 "postlink.m"
id inFile;
id outFile;
id linkFormat;
id prefix;
id appendFiles;

# 40 "./../../include/objpak/ocstring.h"
extern id  String;

# 80 "postlink.m"
static int
watcomGrepLine(id set,char*buf)
{
int c=strlen("_OBJCBIND");
char*p,*delims=" .|\t";

while( *buf!=0){
if(strncmp(buf,"_OBJCBIND",c)==0){
id objcT0,objcT1;

# 88 "postlink.m"
id entry=(objcT0=String,(*(id(*)(id,SEL,STR,int))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],buf,strlen(buf)-1));

p=strtok((objcT1=entry,(*(STR(*)(id,SEL))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1])),delims);
if(p){
id objcT2;
c=strlen(p);
if(p[c-1]=='_')
p[c-1]=0;
(objcT2=set,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2],entry));
}
break;
}
buf++;
}

return 0;
}

# 120 "postlink.m"
static int
unixGrepLine(id set,char*buf)
{
char*p;
char*delims=" .|\t";
int c=strlen("_OBJCBIND");

while( *buf!=0){
if(strncmp(buf,"_OBJCBIND",c)==0){
id objcT3,objcT4,objcT5;
id entry=(objcT3=String,(*(id(*)(id,SEL,STR,int))_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0],buf,strlen(buf)-1));

p=strtok((objcT4=entry,(*(STR(*)(id,SEL))_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1])),delims);
if(p)
(objcT5=set,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2],entry));
break;
}
buf++;
}

return 0;
}

# 150 "postlink.m"
static int
grepLine(id set,char*buf)
{
id objcT6,objcT7,objcT8,objcT9,objcT10;
id objcT11;

# 153 "postlink.m"
if(linkFormat==(id)0)
return unixGrepLine(set,buf);
if((objcT6=linkFormat,(*(BOOL(*)(id,SEL,STR))_imp(objcT6,selTransTbl[3]))(objcT6,selTransTbl[3],"unix")))
return unixGrepLine(set,buf);
if((objcT7=linkFormat,(*(BOOL(*)(id,SEL,STR))_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3],"mpw")))
return unixGrepLine(set,buf);
if((objcT8=linkFormat,(*(BOOL(*)(id,SEL,STR))_imp(objcT8,selTransTbl[3]))(objcT8,selTransTbl[3],"watcom")))
return watcomGrepLine(set,buf);
if((objcT9=linkFormat,(*(BOOL(*)(id,SEL,STR))_imp(objcT9,selTransTbl[3]))(objcT9,selTransTbl[3],"metrowerks"))){
return unixGrepLine(set,buf);
}
if((objcT10=linkFormat,(*(BOOL(*)(id,SEL,STR))_imp(objcT10,selTransTbl[3]))(objcT10,selTransTbl[3],"ibmvac")))
return unixGrepLine(set,buf);
fprintf(stderr,"postlink: unknown format %s\n",(objcT11=linkFormat,(*(STR(*)(id,SEL))_imp(objcT11,selTransTbl[1]))(objcT11,selTransTbl[1])));
return 0;
}

static BOOL
grepMap(id set,FILE*file)
{
char buf[BUFSIZ];

while(fgets(buf, sizeof(buf),file)!=NULL)
grepLine(set,buf);
return ferror(file)==(BOOL)0;
}

# 184 "postlink.m"
static void
dumpFile(id set,FILE*f)
{
id objcT12,objcT13,objcT15,objcT16;

# 187 "postlink.m"
id elt,seq;

fprintf(f,"\n");
fprintf(f,"/* dummy def for compilers that require struct def */\n");
fprintf(f,"struct modDescriptor { int dummy; };\n");
fprintf(f,"\n");

seq=(objcT12=set,(*_imp(objcT12,selTransTbl[4]))(objcT12,selTransTbl[4]));
while((elt=(objcT13=seq,(*_imp(objcT13,selTransTbl[5]))(objcT13,selTransTbl[5])))){
id objcT14;

# 196 "postlink.m"
fprintf(f,"extern struct modDescriptor *%s();\n",(objcT14=elt,(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[1]))(objcT14,selTransTbl[1])));
}

fprintf(f,"\n");
fprintf(f,"/* this must match objcrt.m datatype */\n");
fprintf(f,"static struct modEntry {\n");
fprintf(f,"\tstruct modDescriptor *(*modLink)();\n");
fprintf(f,"\tstruct modDescriptor *modInfo;\n");
fprintf(f,"} _msgControl[] = {\n");

seq=(objcT15=set,(*_imp(objcT15,selTransTbl[4]))(objcT15,selTransTbl[4]));
while((elt=(objcT16=seq,(*_imp(objcT16,selTransTbl[5]))(objcT16,selTransTbl[5])))){
id objcT17;

# 208 "postlink.m"
fprintf(f,"\t{%s,0},\n",(objcT17=elt,(*(STR(*)(id,SEL))_imp(objcT17,selTransTbl[1]))(objcT17,selTransTbl[1])));
}

fprintf(f,"\t{0,0}\n");
fprintf(f,"};\n");
fprintf(f,"\n");
# 221 "postlink.m"
if(appendFiles==(id)0){
# 225 "postlink.m"
fprintf(f,"/* non-NULL _objcModules disables auto-init */\n");
if(prefix){
id objcT18;

# 227 "postlink.m"
STR s=(objcT18=prefix,(*(STR(*)(id,SEL))_imp(objcT18,selTransTbl[1]))(objcT18,selTransTbl[1]));

fprintf(f,"struct modEntry *%s_objcModules = _msgControl;\n",s);
}else{
fprintf(f,"struct modEntry *_objcModules = _msgControl;\n");
}
}else{
id objcT19,objcT20;

# 234 "postlink.m"
FILE*aFile;

seq=(objcT19=appendFiles,(*_imp(objcT19,selTransTbl[4]))(objcT19,selTransTbl[4]));
while((elt=(objcT20=seq,(*_imp(objcT20,selTransTbl[5]))(objcT20,selTransTbl[5])))){
id objcT21;

# 238 "postlink.m"
if((aFile=fopen((objcT21=elt,(*(STR(*)(id,SEL))_imp(objcT21,selTransTbl[1]))(objcT21,selTransTbl[1])),"r"))){
char aBuf[4096+1];

while(fgets(aBuf,4096,aFile))
fputs(aBuf,f);
fclose(aFile);
}else{
id objcT22;

# 245 "postlink.m"
fprintf(stderr,"can't open %s\n",(objcT22=elt,(*(STR(*)(id,SEL))_imp(objcT22,selTransTbl[1]))(objcT22,selTransTbl[1])));
}
}
}

fprintf(f,"\n");
}

# 257 "postlink.m"
static BOOL
isOption(id s)
{
id objcT23,objcT24;

# 260 "postlink.m"
return(objcT23=s,(*(unsigned(*)(id,SEL))_imp(objcT23,selTransTbl[6]))(objcT23,selTransTbl[6]))&&(objcT24=s,(*(char(*)(id,SEL,unsigned))_imp(objcT24,selTransTbl[7]))(objcT24,selTransTbl[7],0))=='-';
}

static void
unknownOption(id option)
{
id objcT25;

# 266 "postlink.m"
fprintf(stderr,"postlink: Illegal option %s\n",(objcT25=option,(*(STR(*)(id,SEL))_imp(objcT25,selTransTbl[1]))(objcT25,selTransTbl[1])));
exit(1);
}

static int
setLinkFormat(id option,int i,char*argv[])
{
id objcT26;

# 273 "postlink.m"
id arg=(objcT26=String,(*(id(*)(id,SEL,STR))_imp(objcT26,selTransTbl[8]))(objcT26,selTransTbl[8],argv[ ++i]));

if(isOption(arg))
unknownOption(arg);
linkFormat=arg;
return i;
}

static int
setPrefix(id option,int i,char*argv[])
{
id objcT27;

# 284 "postlink.m"
id arg=(objcT27=String,(*(id(*)(id,SEL,STR))_imp(objcT27,selTransTbl[8]))(objcT27,selTransTbl[8],argv[ ++i]));

if(isOption(arg))
unknownOption(arg);
prefix=arg;
return i;
}

# 39 "./../../include/objpak/ordcltn.h"
extern id  OrdCltn;

# 292 "postlink.m"
static int
appendFile(id option,int i,char*argv[])
{
id objcT28,objcT29,objcT30;

# 295 "postlink.m"
id arg=(objcT28=String,(*(id(*)(id,SEL,STR))_imp(objcT28,selTransTbl[8]))(objcT28,selTransTbl[8],argv[ ++i]));

if(isOption(arg))
unknownOption(arg);
if( !appendFiles)
appendFiles=(objcT29=OrdCltn,(*_imp(objcT29,selTransTbl[9]))(objcT29,selTransTbl[9]));
(objcT30=appendFiles,(*_imp(objcT30,selTransTbl[2]))(objcT30,selTransTbl[2],arg));
return i;
}

static int
setOutFile(id option,int i,char*argv[])
{
id objcT31;

# 308 "postlink.m"
id arg=(objcT31=String,(*(id(*)(id,SEL,STR))_imp(objcT31,selTransTbl[8]))(objcT31,selTransTbl[8],argv[ ++i]));

if(isOption(arg))
unknownOption(arg);
outFile=arg;
return i;
}

static void
setOptions(int argc,char*argv[])
{
int i;
int fileCount=0;
BOOL checkOption=(BOOL)1;

for(i=1;i<argc;i++){
id objcT32,objcT33,objcT34,objcT35,objcT36;
id objcT37,objcT38,objcT39,objcT40,objcT41;

# 324 "postlink.m"
id s=(objcT32=String,(*(id(*)(id,SEL,STR))_imp(objcT32,selTransTbl[8]))(objcT32,selTransTbl[8],argv[i]));

if((objcT33=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT33,selTransTbl[3]))(objcT33,selTransTbl[3],"-linkFormat"))){
i=setLinkFormat(s,i,argv);
}else if((objcT34=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT34,selTransTbl[3]))(objcT34,selTransTbl[3],"-f"))){
i=setLinkFormat(s,i,argv);
}else if((objcT35=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT35,selTransTbl[3]))(objcT35,selTransTbl[3],"-format"))){
i=setLinkFormat(s,i,argv);
}else if((objcT36=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT36,selTransTbl[3]))(objcT36,selTransTbl[3],"-p"))){
i=setPrefix(s,i,argv);
}else if((objcT37=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT37,selTransTbl[3]))(objcT37,selTransTbl[3],"-prefix"))){
i=setPrefix(s,i,argv);
}else if((objcT38=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT38,selTransTbl[3]))(objcT38,selTransTbl[3],"-a"))){
i=appendFile(s,i,argv);
}else if((objcT39=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT39,selTransTbl[3]))(objcT39,selTransTbl[3],"-append"))){
i=appendFile(s,i,argv);
}else if((objcT40=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT40,selTransTbl[3]))(objcT40,selTransTbl[3],"-o"))){
i=setOutFile(s,i,argv);
}else if((objcT41=s,(*(BOOL(*)(id,SEL,STR))_imp(objcT41,selTransTbl[3]))(objcT41,selTransTbl[3],"-"))){
checkOption=(BOOL)0;
}else if(checkOption&&isOption(s)){
unknownOption(s);
}else if(fileCount==0){
inFile=s;
fileCount++;
}else if(fileCount==1){
outFile=s;
fileCount++;
}else{
unknownOption(s);
}
}
}

# 36 "./../../include/objpak/set.h"
extern id  Set;

# 358 "postlink.m"
int objcmain(int argc,char*argv[])

{
id objcT42;

# 361 "postlink.m"
FILE*inIOD=NULL;
FILE*outIOD=NULL;
id functions=(objcT42=Set,(*_imp(objcT42,selTransTbl[9]))(objcT42,selTransTbl[9]));

setOptions(argc,argv);

if(inFile){
id objcT43,objcT44;

# 368 "postlink.m"
inIOD=fopen((objcT43=inFile,(*(STR(*)(id,SEL))_imp(objcT43,selTransTbl[1]))(objcT43,selTransTbl[1])),"r");
if( !inIOD)
fprintf(stderr,"postlink: can't open %s",(objcT44=inFile,(*(STR(*)(id,SEL))_imp(objcT44,selTransTbl[1]))(objcT44,selTransTbl[1])));
}
if(outFile){
id objcT45,objcT46;

# 373 "postlink.m"
outIOD=fopen((objcT45=outFile,(*(STR(*)(id,SEL))_imp(objcT45,selTransTbl[1]))(objcT45,selTransTbl[1])),"w");
if( !outIOD)
fprintf(stderr,"postlink: can't open %s",(objcT46=outFile,(*(STR(*)(id,SEL))_imp(objcT46,selTransTbl[1]))(objcT46,selTransTbl[1])));
}
grepMap(functions,(inIOD)?inIOD:stdin);
dumpFile(functions,(outIOD)?outIOD:stdout);

if(inIOD){
fclose(inIOD);
}
if(outIOD){
fclose(outIOD);
}
return 0;
}
extern int oc_objcInit(int debug,int traceInit);

# 358 "postlink.m"
int
main(int argc,char*argv[]){
oc_objcInit(0,0);
return objcmain(argc,argv);
}

static char *_selTransTbl[] ={
"chars:count:",
"str",
"add:",
"isEqualSTR:",
"eachElement",
"next",
"size",
"charAt:",
"str:",
"new",
0
};
struct modDescriptor postlink_modDesc = {
  "postlink",
  "objc3.3.19",
  0L,
  0,
  0,
  0,
  10,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_postlink(void)
{
  selTransTbl = _selTransTbl;
  return &postlink_modDesc;
}
int _OBJCPOSTLINK_postlink = 1;
struct useDescriptor *OCU_main = 0;


