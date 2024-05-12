# 1 "ascfiler.m"
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
extern struct modDescriptor  *_OBJCBIND_ascfiler(void);
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
extern struct modDescriptor ascfiler_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

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

# 31 "./ordcltn.h"
typedef struct objcol
{
int count;
int capacity;
id*ptr;
}*
objcol_t;
# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 34 "./ascfiler.h"
struct AsciiFiler_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 36 "./ascfiler.h"
FILE*file;
BOOL ownFile;
BOOL inSecondPass;
id toc;
void**patchPointers;
int patchSize;
int patchCapacity;};

# 34 "./ascfiler.h"
extern id  AsciiFiler;

# 34 "./ascfiler.h"
extern struct _SHARED _AsciiFiler;
extern struct _SHARED __AsciiFiler;


# 43 "ascfiler.m"
static BOOL
asciiFileOut(FILE*f,id anObject)
{
id objcT0,objcT1,objcT2;

# 46 "ascfiler.m"
BOOL r;
id aFiler=(objcT0=AsciiFiler,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
r=(objcT1=aFiler,(*(BOOL(*)(id,SEL,id,FILE*))_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],anObject,f));

(objcT2=aFiler,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]));

return r;
}

static id
asciiFileIn(FILE*f)
{
id objcT3,objcT4,objcT5;

# 58 "ascfiler.m"
id r;
id aFiler=(objcT3=AsciiFiler,(*_imp(objcT3,selTransTbl[0]))(objcT3,selTransTbl[0]));
r=(objcT4=aFiler,(*(id(*)(id,SEL,FILE*))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3],f));

(objcT5=aFiler,(*_imp(objcT5,selTransTbl[2]))(objcT5,selTransTbl[2]));

return r;
}

static id c_AsciiFiler_initialize(struct AsciiFiler_PRIVATE *self,SEL _cmd)
{
setfilein(asciiFileIn);
setfileout(asciiFileOut);
return(id)self;
}

# 81 "ascfiler.m"
static id c_AsciiFiler_new(struct AsciiFiler_PRIVATE *self,SEL _cmd)
{
id objcT6;

# 83 "ascfiler.m"
return(objcT6=__AsciiFiler.clsSuper,(*_impSuper(objcT6,selTransTbl[0]))((id)self,selTransTbl[0]));
}

static id i_AsciiFiler_free(struct AsciiFiler_PRIVATE *self,SEL _cmd)
{
id objcT7;

# 88 "ascfiler.m"
if(self->ownFile)
{
fclose(self->file);
}
return(objcT7=_AsciiFiler.clsSuper,(*_impSuper(objcT7,selTransTbl[2]))((id)self,selTransTbl[2]));
}

# 102 "ascfiler.m"
static BOOL i_AsciiFiler_store_on_(struct AsciiFiler_PRIVATE *self,SEL _cmd,id anObject,STR aFileName)
{
BOOL r;

if((self->file=fopen(aFileName,"w")))
{
id objcT8;
self->
# 108 "ascfiler.m"
ownFile=(BOOL)1;
r=(objcT8=(id)self,(*(BOOL(*)(id,SEL,id,FILE*))_imp(objcT8,selTransTbl[1]))(objcT8,selTransTbl[1],anObject,self->file));
if(self->ownFile)
{self->
ownFile=(BOOL)0;
fclose(self->file);
}
}
else
{
r=(BOOL)0;
}

return r;
}

static id i_AsciiFiler_readFrom_(struct AsciiFiler_PRIVATE *self,SEL _cmd,STR aFileName)
{
id r;

if((self->file=fopen(aFileName,"r")))
{
id objcT9;
self->
# 130 "ascfiler.m"
ownFile=(BOOL)1;
r=(objcT9=(id)self,(*(id(*)(id,SEL,FILE*))_imp(objcT9,selTransTbl[3]))(objcT9,selTransTbl[3],self->file));
if(self->ownFile)
{self->
ownFile=(BOOL)0;
fclose(self->file);
}
}
else
{
r=(id)0;
}

return r;
}

# 165 "ascfiler.m"
static BOOL
isClass(id anObject)
{
id objcT10;

# 168 "ascfiler.m"
return anObject!=(id)0&&(objcT10=anObject,(*_imp(objcT10,selTransTbl[4]))(objcT10,selTransTbl[4]))==anObject;
}

# 39 "./ordcltn.h"
extern id  OrdCltn;

# 171 "ascfiler.m"
static BOOL i_AsciiFiler_store_onFile_(struct AsciiFiler_PRIVATE *self,SEL _cmd,id anObject,FILE*aFile)
{
id objcT11,objcT12,objcT13,objcT14,objcT17;

# 173 "ascfiler.m"
int i,n;self->

file=aFile;


fprintf(self->file,"#%s i%d \n",(objcT11=(id)self,(*(STR(*)(id,SEL))_imp(objcT11,selTransTbl[5]))(objcT11,selTransTbl[5])),325);self->


inSecondPass=(BOOL)0;self->
toc=(objcT12=OrdCltn,(*_imp(objcT12,selTransTbl[0]))(objcT12,selTransTbl[0]));
(objcT13=(id)self,(*_imp(objcT13,selTransTbl[6]))(objcT13,selTransTbl[6],anObject));self->
# 187 "ascfiler.m"
inSecondPass=(BOOL)1;
for(i=0,n=(objcT14=self->toc,(*(unsigned(*)(id,SEL))_imp(objcT14,selTransTbl[7]))(objcT14,selTransTbl[7]));i<n;i++)
{
id objcT15,objcT16;

# 193 "ascfiler.m"
fprintf(self->file,"%i ",i+1);

(objcT15=(objcT16=self->toc,(*(id(*)(id,SEL,unsigned))_imp(objcT16,selTransTbl[8]))(objcT16,selTransTbl[8],i)),(*_imp(objcT15,selTransTbl[9]))(objcT15,selTransTbl[9],(id)self));
fprintf(self->file,"\n");
}self->


inSecondPass=(BOOL)0;self->

toc=(objcT17=self->toc,(*_imp(objcT17,selTransTbl[2]))(objcT17,selTransTbl[2]));
# 207 "ascfiler.m"
return(BOOL)1;
}

static void
outClass(FILE*file,void*value)
{
id objcT18;

# 213 "ascfiler.m"
id aClass= *((id*)value);
fprintf(file,"#%s ",(objcT18=aClass,(*(STR(*)(id,SEL))_imp(objcT18,selTransTbl[5]))(objcT18,selTransTbl[5])));
}

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 217 "ascfiler.m"
static void
outObject(id self,FILE*file,id toc,void*value)
{
id anObject= *((id*)value);


if(isClass(anObject))
{
id objcT19;

# 225 "ascfiler.m"
(objcT19=self,(*(id(*)(id,SEL,void*,char))_imp(objcT19,selTransTbl[10]))(objcT19,selTransTbl[10],value,'#'));
return;
}

if(anObject)
{
id objcT20;

# 231 "ascfiler.m"
int offset=(objcT20=toc,(*(unsigned(*)(id,SEL,id))_imp(objcT20,selTransTbl[11]))(objcT20,selTransTbl[11],anObject));
if(offset== -1)
{
id objcT21,objcT22,objcT23,objcT24;

# 234 "ascfiler.m"
(objcT21=(objcT22=(objcT23=OutOfBounds,(*(id(*)(id,SEL,unsigned))_imp(objcT23,selTransTbl[12]))(objcT23,selTransTbl[12],(objcT24=toc,(*(unsigned(*)(id,SEL))_imp(objcT24,selTransTbl[7]))(objcT24,selTransTbl[7])))),(*(id(*)(id,SEL,unsigned))_imp(objcT22,selTransTbl[8]))(objcT22,selTransTbl[8], -1)),(*_imp(objcT21,selTransTbl[13]))(objcT21,selTransTbl[13]));
}
else
{
fprintf(file,"@%i ",offset+1);
}
}
else
{
fprintf(file,"@0 ");
}
}

static void
outChar(FILE*file,void*value)
{
char c= *((char*)value);
fprintf(file,"c%c ",c);
}

static void
outInt(FILE*file,void*value)
{
int i= *((int*)value);
fprintf(file,"i%i ",i);
}

static void
outUShort(FILE*file,void*value)
{
unsigned i= *((unsigned short*)value);
fprintf(file,"S%u ",i);
}

static void
outShort(FILE*file,void*value)
{
int i= *((short*)value);
fprintf(file,"s%i ",i);
}

static void
outfloat(FILE*file,void*value)
{
float f= *((float*)value);
fprintf(file,"f%f ",f);
}

static void
outdouble(FILE*file,void*value)
{
double d= *((double*)value);
fprintf(file,"d%f ",d);
}

# 293 "ascfiler.m"
static void
outSTR(FILE*file,void*value)
{
STR s;
int len;

s= *((STR*)value);

if(s)
{
len=strlen(s);
fprintf(file,"*%i\"%s ",len,s);
}
else
{
fprintf(file,"%c0 ",044);
}
}

# 28 "./unknownt.h"
extern id  UnknownType;

# 312 "ascfiler.m"
static id i_AsciiFiler_fileOut2_type_(struct AsciiFiler_PRIVATE *self,SEL _cmd,void*value,char typeDesc)
{
switch(typeDesc)
{
case'#':outClass(self->file,value);
break;
case'@':
outObject((id)self,self->file,self->toc,value);
break;
case'c':
outChar(self->file,value);
break;
case'i':
outInt(self->file,value);
break;
case's':
outShort(self->file,value);
break;
case'S':
outUShort(self->file,value);
break;
case'f':
outfloat(self->file,value);
break;
case'd':
outdouble(self->file,value);
break;
case'*':
outSTR(self->file,value);
break;
case 044:
fprintf(self->file,"%c0 ",044);
break;
default:
{
id objcT25,objcT26,objcT27;

# 347 "ascfiler.m"
(objcT25=(objcT26=(objcT27=UnknownType,(*_imp(objcT27,selTransTbl[0]))(objcT27,selTransTbl[0])),(*(id(*)(id,SEL,char))_imp(objcT26,selTransTbl[14]))(objcT26,selTransTbl[14],typeDesc)),(*_imp(objcT25,selTransTbl[13]))(objcT25,selTransTbl[13]));
break;
}
}

return(id)self;
}

static id i_AsciiFiler_fileOutObject_(struct AsciiFiler_PRIVATE *self,SEL _cmd,id anObject)
{
id objcT28;

# 357 "ascfiler.m"
if(anObject!=(id)0&& !isClass(anObject)&&(objcT28=self->toc,(*_imp(objcT28,selTransTbl[15]))(objcT28,selTransTbl[15],anObject))==(id)0)
{
id objcT29,objcT30;

# 359 "ascfiler.m"
(objcT29=self->toc,(*_imp(objcT29,selTransTbl[16]))(objcT29,selTransTbl[16],anObject));
(objcT30=anObject,(*_imp(objcT30,selTransTbl[9]))(objcT30,selTransTbl[9],(id)self));
}

return(id)self;
}

static id i_AsciiFiler_fileOut_type_(struct AsciiFiler_PRIVATE *self,SEL _cmd,void*value,char typeDesc)
{
id objcT31;

# 368 "ascfiler.m"
if(self->inSecondPass)
return(objcT31=(id)self,(*(id(*)(id,SEL,void*,char))_imp(objcT31,selTransTbl[10]))(objcT31,selTransTbl[10],value,typeDesc));

if(typeDesc=='@')
{
id objcT32;

# 373 "ascfiler.m"
id anObject= *((id*)value);
return(objcT32=(id)self,(*_imp(objcT32,selTransTbl[6]))(objcT32,selTransTbl[6],anObject));
}

return(id)self;
}

# 387 "ascfiler.m"
static int
nextCode(FILE*file)
{
int code;
do
{
code=getc(file);
}
while(code==' '||code=='\t');
return code;
}

# 28 "./typeinc.h"
extern id  TypeInconsistency;

# 401 "ascfiler.m"
static int
lex(id self,FILE*file,int expected,char*buffer)
{
int code=nextCode(file);
char*q=buffer;

switch(code)
{
case'c':
case'i':
case's':
case'S':
case'f':
case'd':
case'@':
case'#':
{
int c;
while((c=getc(file))!=' ') *
q++=c; *
q=0;
break;
}
default:
break;
}

if(code==044)
return code;

if(code==expected)
{
# 447 "ascfiler.m"
return code;
}
else
{
id objcT33,objcT34,objcT35;

# 451 "ascfiler.m"
(objcT33=(objcT34=(objcT35=TypeInconsistency,(*_imp(objcT35,selTransTbl[0]))(objcT35,selTransTbl[0])),(*(id(*)(id,SEL,char,char))_imp(objcT34,selTransTbl[17]))(objcT34,selTransTbl[17],code,expected)),(*_imp(objcT33,selTransTbl[13]))(objcT33,selTransTbl[13]));
return 0;
}
}

static int
a_to_i(char*s)
{
return atoi(s);
}

static double
a_to_f(char*s)
{
return atof(s);
}

static int
skipIX(FILE*file)
{
int c;
while(feof(file)==0&&(c=getc(file))!=' ')
{
# 477 "ascfiler.m"
}
return 0==feof(file);
}

static STR
lexSTR(id self,FILE*file)
{
int expected='*';
int code=nextCode(file);

if(code==044)
{
skipIX(file);
return NULL;
}

if(code!=expected)
{
id objcT36,objcT37,objcT38;

# 495 "ascfiler.m"
(objcT36=(objcT37=(objcT38=TypeInconsistency,(*_imp(objcT38,selTransTbl[0]))(objcT38,selTransTbl[0])),(*(id(*)(id,SEL,char,char))_imp(objcT37,selTransTbl[17]))(objcT37,selTransTbl[17],code,expected)),(*_imp(objcT36,selTransTbl[13]))(objcT36,selTransTbl[13]));
return NULL;
}
else
{
STR q;
STR s;
int c,len;
char buffer[32];

q=buffer;
while((c=getc(file))!='\"') *
q++=c; *
q=0;
len=a_to_i(buffer);
s=OC_Malloc(len+1);
q=s;
while(len--) *
q++=getc(file); *
q++=0;
# 519 "ascfiler.m"
return s;
}
}

static id
lexClass(id self,FILE*file)
{
id objcT39;

# 526 "ascfiler.m"
char buffer[1024];
lex(self,file,'#',buffer);
return(objcT39=self,(*(id(*)(id,SEL,STR))_imp(objcT39,selTransTbl[18]))(objcT39,selTransTbl[18],buffer));
}

static int
lexObjectOffset(id self,FILE*file)
{
char buffer[32];
lex(self,file,'@',buffer);
return a_to_i(buffer);
}

static int
lexChar(id self,FILE*file)
{
char buffer[8];
lex(self,file,'c',buffer);
return buffer[0];
}

static short int
lexShort(id self,FILE*file)
{
char buffer[32];
lex(self,file,'s',buffer);
return a_to_i(buffer);
}

static unsigned short int
lexUShort(id self,FILE*file)
{
char buffer[32];
lex(self,file,'S',buffer);
return a_to_i(buffer);
}

static int
lexInt(id self,FILE*file)
{
char buffer[32];
lex(self,file,'i',buffer);
return a_to_i(buffer);
}

static float
lexfloat(id self,FILE*file)
{
char buffer[32];
lex(self,file,'f',buffer);
return a_to_f(buffer);
}

static float
lexdouble(id self,FILE*file)
{
char buffer[32];
lex(self,file,'d',buffer);
return a_to_f(buffer);
}


static void
skipNL(id self,FILE*file)
{
lex(self,file,'\n',NULL);
}

# 28 "./badvers.h"
extern id  BadVersion;

# 594 "ascfiler.m"
static id i_AsciiFiler_readFromFile_(struct AsciiFiler_PRIVATE *self,SEL _cmd,FILE*aFile)
{
id objcT44,objcT53,objcT54,objcT55,objcT56;
id objcT57;

# 596 "ascfiler.m"
id anObject;
int i,n,version;self->

file=aFile;


if(self->isa!=lexClass((id)self,self->file))
{
id objcT40;

# 604 "ascfiler.m"
(objcT40=BadVersion,(*_imp(objcT40,selTransTbl[13]))(objcT40,selTransTbl[13]));
return(id)0;
}
version=lexInt((id)self,self->file);
if(version!=325)
{
id objcT41,objcT42,objcT43;

# 610 "ascfiler.m"
id e=(objcT41=BadVersion,(*_imp(objcT41,selTransTbl[0]))(objcT41,selTransTbl[0]));
(objcT42=(objcT43=e,(*(id(*)(id,SEL,int,int))_imp(objcT43,selTransTbl[19]))(objcT43,selTransTbl[19],325,version)),(*_imp(objcT42,selTransTbl[13]))(objcT42,selTransTbl[13]));
return(id)0;
}

skipNL((id)self,self->file);self->

toc=(objcT44=OrdCltn,(*_imp(objcT44,selTransTbl[0]))(objcT44,selTransTbl[0]));self->
patchSize=0;self->
patchCapacity=64;self->
patchPointers=(void**)OC_Malloc(sizeof(void*)*self->patchCapacity);
# 628 "ascfiler.m"
while(feof(self->file)==0&&skipIX(self->file))
{
id objcT45,objcT46;

# 630 "ascfiler.m"
id tmpObject;
id aClass=lexClass((id)self,self->file);
tmpObject=(objcT45=aClass,(*_imp(objcT45,selTransTbl[20]))(objcT45,selTransTbl[20],(id)self));
(objcT46=self->toc,(*_imp(objcT46,selTransTbl[16]))(objcT46,selTransTbl[16],tmpObject));
skipNL((id)self,self->file);
}
# 639 "ascfiler.m"
for(i=0;i<self->patchSize;i++)
{
id objcT47;

# 641 "ascfiler.m"
int offset;
void*value=self->patchPointers[i];
offset= *((int*)value);
if(offset>(objcT47=self->toc,(*(unsigned(*)(id,SEL))_imp(objcT47,selTransTbl[7]))(objcT47,selTransTbl[7])))
{
id objcT48,objcT49,objcT50,objcT51;

# 646 "ascfiler.m"
(objcT48=(objcT49=(objcT50=OutOfBounds,(*(id(*)(id,SEL,unsigned))_imp(objcT50,selTransTbl[12]))(objcT50,selTransTbl[12],(objcT51=self->toc,(*(unsigned(*)(id,SEL))_imp(objcT51,selTransTbl[7]))(objcT51,selTransTbl[7])))),(*(id(*)(id,SEL,unsigned))_imp(objcT49,selTransTbl[8]))(objcT49,selTransTbl[8],offset)),(*_imp(objcT48,selTransTbl[13]))(objcT48,selTransTbl[13]));
}
else
{
id objcT52;

# 650 "ascfiler.m"
id realObject=(offset)?(objcT52=self->toc,(*(id(*)(id,SEL,unsigned))_imp(objcT52,selTransTbl[8]))(objcT52,selTransTbl[8],offset-1)):(id)0; *
# 654 "ascfiler.m"
(void**)value=NULL; *
((id*)value)=realObject;
}
}
# 661 "ascfiler.m"
for(i=0,n=(objcT53=self->toc,(*(unsigned(*)(id,SEL))_imp(objcT53,selTransTbl[7]))(objcT53,selTransTbl[7]));i<n;i++)
(objcT54=(objcT55=self->toc,(*(id(*)(id,SEL,unsigned))_imp(objcT55,selTransTbl[8]))(objcT55,selTransTbl[8],i)),(*_imp(objcT54,selTransTbl[21]))(objcT54,selTransTbl[21],(id)self));
# 666 "ascfiler.m"
anObject=(objcT56=self->toc,(*_imp(objcT56,selTransTbl[22]))(objcT56,selTransTbl[22]));
OC_Free(self->patchPointers);self->
patchPointers=NULL;self->

toc=(objcT57=self->toc,(*_imp(objcT57,selTransTbl[2]))(objcT57,selTransTbl[2]));
# 675 "ascfiler.m"
return anObject;
}

static id i_AsciiFiler_fileIn_type_(struct AsciiFiler_PRIVATE *self,SEL _cmd,void*value,char typeDesc)
{
switch(typeDesc)
{
case'#':
{ *
((id*)value)=lexClass((id)self,self->file);
break;
}
case'@':
{
id objcT58;

# 689 "ascfiler.m"
int offset;
offset=lexObjectOffset((id)self,self->file);
if(offset<=(objcT58=self->toc,(*(unsigned(*)(id,SEL))_imp(objcT58,selTransTbl[7]))(objcT58,selTransTbl[7])))
{
id objcT59;
 *
# 693 "ascfiler.m"
((id*)value)=(offset)?(objcT59=self->toc,(*(id(*)(id,SEL,unsigned))_imp(objcT59,selTransTbl[8]))(objcT59,selTransTbl[8],offset-1)):(id)0;
}
else
{ *

((int*)value)=offset;
if(self->patchSize+1==self->patchCapacity)
{self->
patchCapacity=self->patchCapacity*2+1;self->
patchPointers=(void**)OC_Realloc(self->patchPointers,self->patchCapacity);
}self->

patchPointers[self->patchSize]=value;self->
patchSize++;
}
break;
}
case'c':
{ *
((char*)value)=lexChar((id)self,self->file);
break;
}
case'i':
{ *
((int*)value)=lexInt((id)self,self->file);
break;
}
case's':
{ *
((short*)value)=lexShort((id)self,self->file);
break;
}
case'S':
{ *
((unsigned short*)value)=lexUShort((id)self,self->file);
break;
}
case'f':
{ *
((float*)value)=lexfloat((id)self,self->file);
break;
}
case'd':
{ *
((double*)value)=lexdouble((id)self,self->file);
break;
}
case'*':
{ *
((STR*)value)=lexSTR((id)self,self->file);
break;
}
case 044:
{ *
((void**)value)=NULL;
skipIX(self->file);
break;
}
default:
{
id objcT60,objcT61,objcT62;

# 753 "ascfiler.m"
(objcT60=(objcT61=(objcT62=UnknownType,(*_imp(objcT62,selTransTbl[0]))(objcT62,selTransTbl[0])),(*(id(*)(id,SEL,char))_imp(objcT61,selTransTbl[14]))(objcT61,selTransTbl[14],typeDesc)),(*_imp(objcT60,selTransTbl[13]))(objcT60,selTransTbl[13]));
break;
}
}

return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _AsciiFiler_clsDispatchTbl[] ={
{"initialize",(id (*)())c_AsciiFiler_initialize},
{"new",(id (*)())c_AsciiFiler_new},
{(char*)0,(id (*)())0}
};
static struct _SLT _AsciiFiler_nstDispatchTbl[] ={
{"free",(id (*)())i_AsciiFiler_free},
{"store:on:",(id (*)())i_AsciiFiler_store_on_},
{"readFrom:",(id (*)())i_AsciiFiler_readFrom_},
{"store:onFile:",(id (*)())i_AsciiFiler_store_onFile_},
{"fileOut2:type:",(id (*)())i_AsciiFiler_fileOut2_type_},
{"fileOutObject:",(id (*)())i_AsciiFiler_fileOutObject_},
{"fileOut:type:",(id (*)())i_AsciiFiler_fileOut_type_},
{"readFromFile:",(id (*)())i_AsciiFiler_readFromFile_},
{"fileIn:type:",(id (*)())i_AsciiFiler_fileIn_type_},
{(char*)0,(id (*)())0}
};
id AsciiFiler = (id)&_AsciiFiler;
id  *OBJCCLASS_AsciiFiler(void) { return &AsciiFiler; }
struct _SHARED  _AsciiFiler = {
  (id)&__AsciiFiler,
  (id)&_Object,
  "AsciiFiler",
  0,
  sizeof(struct AsciiFiler_PRIVATE),
  9,
  _AsciiFiler_nstDispatchTbl,
  41,
  &ascfiler_modDesc,
  0,
  (id)0,
  &AsciiFiler,
};
id  OBJCCFUNC_AsciiFiler(void) { return (id)&_AsciiFiler; }
id  OBJCCSUPER_AsciiFiler(void) { return _AsciiFiler.clsSuper; }
struct _SHARED __AsciiFiler = {
  (id)&__Object,
  (id)&__Object,
  "AsciiFiler",
  0,
  sizeof(struct _SHARED),
  2,
  _AsciiFiler_clsDispatchTbl,
  34,
  &ascfiler_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_AsciiFiler(void) { return (id)&__AsciiFiler; }
id  OBJCMSUPER_AsciiFiler(void) { return __AsciiFiler.clsSuper; }
static char *_selTransTbl[] ={
"new",
"store:onFile:",
"free",
"readFromFile:",
"class",
"name",
"fileOutObject:",
"size",
"at:",
"fileOutOn:",
"fileOut2:type:",
"offsetOf:",
"new:",
"signal",
"typeDesc:",
"find:",
"add:",
"got:wanted:",
"idOfSTR:",
"goodVersion:badVersion:",
"fileInFrom:",
"awakeFrom:",
"firstElement",
0
};
struct modDescriptor ascfiler_modDesc = {
  "ascfiler",
  "objc3.3.19",
  0L,
  0,
  0,
  &AsciiFiler,
  23,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_ascfiler(void)
{
  selTransTbl = _selTransTbl;
  return &ascfiler_modDesc;
}
int _OBJCPOSTLINK_ascfiler = 1;


