# 1 "ocstring.m"
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
extern struct modDescriptor  *_OBJCBIND_ocstring(void);
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
extern struct modDescriptor ocstring_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//ctype.h"
#include <ctype.h>

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

# 32 "./ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 34 "ocstring.m"
typedef struct
{
# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./array.h"
unsigned capacity;
# 42 "./ocstring.h"
struct objstr value;
# 37 "ocstring.m"
}
TFString;
# 40 "./ocstring.h"
struct String_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./array.h"
unsigned capacity;
# 42 "./ocstring.h"
struct objstr value;};

# 40 "./ocstring.h"
extern id  String;

# 40 "./ocstring.h"
extern struct _SHARED _String;
extern struct _SHARED __String;


# 48 "ocstring.m"
static int
str_len(char*s)
{
int len=0;
while( *s++)
len++;
return len;
}

static void
str_ncpy(char*dst,char*src,int n)
{
int c=0;
while(n--&&(c= *src++))
{ *
dst++=c;
} *
dst++='\0';
}

static void
str_cpy(char*dst,char*src)
{
int c=0;
while((c= *src++))
{ *
dst++=c;
} *
dst++='\0';
}

static void
init(objstr_t self,char*s,int n,int c)
{
(void)0;

self->count=n;
self->capacity=c;
self->ptr=(char*)OC_MallocAtomic(c);

str_ncpy(self->ptr,s,n);
self->ptr[n]='\0';
}

static id c_String_new(struct String_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 94 "ocstring.m"
return(objcT0=(id)self,(*(id(*)(id,SEL,unsigned))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],(16)));
}

static id c_String_new_(struct String_PRIVATE *self,SEL _cmd,unsigned nChars)
{
id objcT1,objcT2;

# 99 "ocstring.m"
id newObj=(objcT1=__String.clsSuper,(*_impSuper(objcT1,selTransTbl[1]))((id)self,selTransTbl[1]));
init((objcT2=newObj,(*(objstr_t(*)(id,SEL))_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2])),"",0,nChars);
return newObj;
}

static void
initstr(objstr_t self,char*s,int n)
{
init(self,s,n,n+1);
}

static id c_String_str_(struct String_PRIVATE *self,SEL _cmd,STR aString)
{
if(aString)
{
id objcT3;

# 114 "ocstring.m"
id newObj=(objcT3=__String.clsSuper,(*_impSuper(objcT3,selTransTbl[1]))((id)self,selTransTbl[1]));
int n=str_len(aString);
# 121 "ocstring.m"
initstr( &(((TFString*)newObj)->value),aString,n);

return newObj;
}
else
{
id objcT4;

# 127 "ocstring.m"
return(objcT4=(id)self,(*_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1]));
}
}

static id c_String_chars_count_(struct String_PRIVATE *self,SEL _cmd,STR aString,int n)
{
if(aString)
{
id objcT5;

# 135 "ocstring.m"
id newObj=(objcT5=__String.clsSuper,(*_impSuper(objcT5,selTransTbl[1]))((id)self,selTransTbl[1]));
# 141 "ocstring.m"
initstr( &(((TFString*)newObj)->value),aString,n);

return newObj;
}
else
{
id objcT6;

# 147 "ocstring.m"
return(objcT6=(id)self,(*_imp(objcT6,selTransTbl[1]))(objcT6,selTransTbl[1]));
}
}

static id c_String_vsprintf__(struct String_PRIVATE *self,SEL _cmd,STR format,va_list*ap)
{
id objcT7;

# 153 "ocstring.m"
char aBuffer[(2048)];
# 162 "ocstring.m"
vsprintf(aBuffer,format, *ap);


return(objcT7=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT7,selTransTbl[3]))(objcT7,selTransTbl[3],aBuffer));
}

static id c_String_sprintf_(struct String_PRIVATE *self,SEL _cmd,STR format,...)
{
id objcT8;

# 170 "ocstring.m"
id newString;


va_list ap;
va_start(ap,format);
newString=(objcT8=(id)self,(*(id(*)(id,SEL,STR,va_list*))_imp(objcT8,selTransTbl[4]))(objcT8,selTransTbl[4],format, &ap));
va_end(ap);
return newString;
}

static void
copy(objstr_t dst,objstr_t src)
{
int n=src->count;

(void)0;

dst->count=n;
dst->capacity=n+1;
dst->ptr=(char*)OC_MallocAtomic(n+1);
str_cpy(dst->ptr,src->ptr);
}

static id i_String_copy(struct String_PRIVATE *self,SEL _cmd)
{
id objcT9,objcT10;

# 195 "ocstring.m"
id aCopy=(objcT9=_String.clsSuper,(*_impSuper(objcT9,selTransTbl[5]))((id)self,selTransTbl[5]));
copy((objcT10=aCopy,(*(objstr_t(*)(id,SEL))_imp(objcT10,selTransTbl[2]))(objcT10,selTransTbl[2])),( &self->value));
return aCopy;
}

static id i_String_deepCopy(struct String_PRIVATE *self,SEL _cmd)
{
id objcT11;

# 202 "ocstring.m"
return(objcT11=(id)self,(*_imp(objcT11,selTransTbl[5]))(objcT11,selTransTbl[5]));
}

static void
clear(objstr_t self)
{
OC_Free(self->ptr);
self->ptr=NULL;
}

static id i_String_free(struct String_PRIVATE *self,SEL _cmd)
{
id objcT12;

# 214 "ocstring.m"
clear(( &self->value));
return(objcT12=_String.clsSuper,(*_impSuper(objcT12,selTransTbl[6]))((id)self,selTransTbl[6]));
}

static id i_String_release(struct String_PRIVATE *self,SEL _cmd)
{
id objcT13;

# 224 "ocstring.m"
return(objcT13=(id)self,(*(id(*)(id,SEL,SEL))_imp(objcT13,selTransTbl[7]))(objcT13,selTransTbl[7],_cmd));

}

# 234 "ocstring.m"
static int
str_cmp(char*s1,char*s2)
{
int r;
int c1,c2;

while(1)
{
c1= *s1++;
c2= *s2++;
if(c1=='\0')
return(c2==0)?0: -1;
if(c2=='\0')
return 1;
if((r=c1-c2))
return r;
}
}

static int
cmpstr(objstr_t a,char*b)
{
return str_cmp(a->ptr,b);
}

static int i_String_compare_(struct String_PRIVATE *self,SEL _cmd,id aStr)
{
id objcT14;

# 261 "ocstring.m"
return((id)self==aStr)?0:cmpstr(( &self->value),(objcT14=aStr,(*(STR(*)(id,SEL))_imp(objcT14,selTransTbl[8]))(objcT14,selTransTbl[8])));
}

static int i_String_compareSTR_(struct String_PRIVATE *self,SEL _cmd,STR aString)
{
return cmpstr(( &self->value),aString);
}

static unsigned
str_hash(char*s)
{
unsigned hash=0;

while(1)
{
if( *s=='\0')
break;
else
hash^= *s++;
if( *s=='\0')
break;
else
hash^=( *s++<<8);
if( *s=='\0')
break;
else
hash^=( *s++<<16);
if( *s=='\0')
break;
else
hash^=( *s++<<24);
}

return hash;
}

static unsigned
hash(objstr_t self)
{
return str_hash(self->ptr);
}

static unsigned i_String_hash(struct String_PRIVATE *self,SEL _cmd)
{
return hash(( &self->value));
}

static int
str_dictcmp(char*s1,char*s2)
{
int r;
int c1,c2;

while(1)
{
while((c1= *s1++)&& !isalnum(c1));

while((c2= *s2++)&& !isalnum(c2));

if(c1=='\0')
return(c2==0)?0: -1;
if(c2=='\0')
return 1;
if(isupper(c1))
c1=tolower(c1);
if(isupper(c2))
c2=tolower(c2);
if((r=c1-c2))
return r;
}
}

static int
dictcmp(objstr_t a,objstr_t b)
{
return str_dictcmp(a->ptr,b->ptr);
}

static int i_String_dictCompare_(struct String_PRIVATE *self,SEL _cmd,id aStr)
{
id objcT15;

# 341 "ocstring.m"
return dictcmp(( &self->value),(objcT15=aStr,(*(objstr_t(*)(id,SEL))_imp(objcT15,selTransTbl[2]))(objcT15,selTransTbl[2])));
}

static BOOL i_String_isEqual_(struct String_PRIVATE *self,SEL _cmd,id aStr)
{
id objcT16;

# 346 "ocstring.m"
return((id)self==aStr)?(BOOL)1:((objcT16=(id)self,(*(int(*)(id,SEL,id))_imp(objcT16,selTransTbl[9]))(objcT16,selTransTbl[9],aStr))==0);
}

static BOOL i_String_isEqualSTR_(struct String_PRIVATE *self,SEL _cmd,STR aString)
{
id objcT17;

# 351 "ocstring.m"
return(objcT17=(id)self,(*(int(*)(id,SEL,STR))_imp(objcT17,selTransTbl[10]))(objcT17,selTransTbl[10],aString))==0;
}

# 360 "ocstring.m"
static objstr_t i_String_objstrvalue(struct String_PRIVATE *self,SEL _cmd)
{
return &self->value;
}

static unsigned i_String_size(struct String_PRIVATE *self,SEL _cmd)
{
return( &self->value)->count;
}

static char
charat(objstr_t self,int i)
{
if(0<=i&&i<self->count)
{
return(self->ptr)[i];
}
else
{
return 0;
}
}

static char i_String_charAt_(struct String_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
return charat(( &self->value),anOffset);
}

static char
strputchar(char*self,char c)
{
char r= *self; *
self=c;
return r;
}

static char
putcharat(objstr_t self,int i,char c)
{
if(0<=i&&i<self->count)
{
return strputchar(self->ptr+i,c);
}
else
{
return 0;
}
}

static char i_String_charAt_put_(struct String_PRIVATE *self,SEL _cmd,unsigned anOffset,char aChar)
{
return putcharat(( &self->value),anOffset,aChar);
}

# 420 "ocstring.m"
static STR i_String_strcat_(struct String_PRIVATE *self,SEL _cmd,STR aBuffer)
{
id objcT18;

# 422 "ocstring.m"
str_cpy(aBuffer+str_len(aBuffer),(objcT18=(id)self,(*(STR(*)(id,SEL))_imp(objcT18,selTransTbl[8]))(objcT18,selTransTbl[8])));
return aBuffer;
}

static void
expand(objstr_t self)
{
(void)0;
self->capacity=1+self->capacity*2;
self->ptr=(char*)OC_Realloc(self->ptr,self->capacity);
}

static void
concat(objstr_t self,char*s,int n)
{
(void)0;
while(self->count+n+1>self->capacity)
expand(self);
str_cpy(self->ptr+self->count,s);
self->count+=n;
}



static void
concat_self(objstr_t self)
{
while(2*self->count+1>self->capacity)
expand(self);
str_ncpy(self->ptr+self->count,self->ptr,self->count);
self->count*=2;
}

static id i_String_concat_(struct String_PRIVATE *self,SEL _cmd,id aString)
{
if(aString==(id)self)
{
concat_self( &self->value);
}
else
{
id objcT19,objcT20;

# 463 "ocstring.m"
(objcT19=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT19,selTransTbl[11]))(objcT19,selTransTbl[11],(objcT20=aString,(*(STR(*)(id,SEL))_imp(objcT20,selTransTbl[8]))(objcT20,selTransTbl[8]))));
}
return(id)self;
}

static id i_String_concatSTR_(struct String_PRIVATE *self,SEL _cmd,STR aString)
{
concat(( &self->value),aString,str_len(aString));
return(id)self;
}

static id i_String_concatenateSTR_(struct String_PRIVATE *self,SEL _cmd,STR aString)
{
id objcT21;

# 476 "ocstring.m"
return(objcT21=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT21,selTransTbl[11]))(objcT21,selTransTbl[11],aString));
}

static void
atinsert(objstr_t self,int i,char*s,int n)
{
int j;
char*p;

while(self->count+n+1>self->capacity)
expand(self);
j=self->count;
p=self->ptr;
while(( --j)>=i)
{
p[j+n]=p[j];
}
for(j=i;j<i+n;j++)
{
p[j]= *s++;
}
self->count+=n;
(self->ptr)[self->count]='\0';
}

static id i_String_at_insert_count_(struct String_PRIVATE *self,SEL _cmd,unsigned anOffset,char*aString,int n)
{
if(n)
atinsert(( &self->value),anOffset,aString,n);
return(id)self;
}

static id i_String_at_insert_(struct String_PRIVATE *self,SEL _cmd,unsigned anOffset,id aString)
{
id objcT22,objcT23,objcT24,objcT25,objcT26;

# 510 "ocstring.m"
id res,tmpString;

tmpString=(aString==(id)self)?(objcT22=aString,(*_imp(objcT22,selTransTbl[5]))(objcT22,selTransTbl[5])):aString;
res=(objcT23=(id)self,(*(id(*)(id,SEL,unsigned,char*,int))_imp(objcT23,selTransTbl[12]))(objcT23,selTransTbl[12],anOffset,(objcT24=tmpString,(*(STR(*)(id,SEL))_imp(objcT24,selTransTbl[8]))(objcT24,selTransTbl[8])),(objcT25=tmpString,(*(unsigned(*)(id,SEL))_imp(objcT25,selTransTbl[13]))(objcT25,selTransTbl[13]))));
if(tmpString!=aString)
(objcT26=tmpString,(*_imp(objcT26,selTransTbl[6]))(objcT26,selTransTbl[6]));
return res;
}

static void
deleteat(objstr_t self,int p,int n)
{
int i,m;
char*ptr;

ptr=self->ptr;
m=self->count;
for(i=p+n;i<m;i++)
{
ptr[i-n]=ptr[i];
}

self->count-=n;
(self->ptr)[self->count]='\0';
}

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 536 "ocstring.m"
static id i_String_deleteFrom_to_(struct String_PRIVATE *self,SEL _cmd,unsigned p,unsigned q)
{
id objcT27;

# 538 "ocstring.m"
if(q>=(objcT27=(id)self,(*(unsigned(*)(id,SEL))_imp(objcT27,selTransTbl[13]))(objcT27,selTransTbl[13]))||p>q)
{
id objcT28;

# 540 "ocstring.m"
(objcT28=OutOfBounds,(*_imp(objcT28,selTransTbl[14]))(objcT28,selTransTbl[14]));
return(id)self;
}
else
{
deleteat(( &self->value),p,q-p+1);
return(id)self;
}
}

static void
assign(objstr_t self,char*s,int n)
{
(void)0;
while(n+1>self->capacity)
expand(self);
str_ncpy(self->ptr,s,n);
(self->ptr)[n]='\0';
self->count=n;
}

static id i_String_assignSTR_(struct String_PRIVATE *self,SEL _cmd,STR aString)
{
assign(( &self->value),aString,str_len(aString));
return(id)self;
}

static id i_String_assignSTR_length_(struct String_PRIVATE *self,SEL _cmd,STR aString,unsigned nChars)
{
assign(( &self->value),aString,nChars);
return(id)self;
}

# 579 "ocstring.m"
static double i_String_asDouble(struct String_PRIVATE *self,SEL _cmd)
{
id objcT29;

# 581 "ocstring.m"
return atof((objcT29=(id)self,(*(STR(*)(id,SEL))_imp(objcT29,selTransTbl[8]))(objcT29,selTransTbl[8])));
}

static int i_String_asInt(struct String_PRIVATE *self,SEL _cmd)
{
id objcT30;

# 586 "ocstring.m"
return atoi((objcT30=(id)self,(*(STR(*)(id,SEL))_imp(objcT30,selTransTbl[8]))(objcT30,selTransTbl[8])));
}

static long i_String_asLong(struct String_PRIVATE *self,SEL _cmd)
{
id objcT31;

# 591 "ocstring.m"
return atol((objcT31=(id)self,(*(STR(*)(id,SEL))_imp(objcT31,selTransTbl[8]))(objcT31,selTransTbl[8])));
}

static id i_String_asSTR_maxSize_(struct String_PRIVATE *self,SEL _cmd,STR aBuffer,int aSize)
{
id objcT32;

# 596 "ocstring.m"
str_ncpy(aBuffer,(objcT32=(id)self,(*(STR(*)(id,SEL))_imp(objcT32,selTransTbl[8]))(objcT32,selTransTbl[8])),aSize);
return(id)self;
}

static STR i_String_str(struct String_PRIVATE *self,SEL _cmd)
{
return( &self->value)->ptr;
}

static STR i_String_strCopy(struct String_PRIVATE *self,SEL _cmd)
{
struct objstr aCopy;
copy( &aCopy,( &self->value));
return aCopy.ptr;
}

# 618 "ocstring.m"
static void
strtolower(char*s)
{
char c;
while((c= *s))
{ *
s++=tolower(c);
}
}

static void
objtolower(objstr_t self)
{
strtolower(self->ptr);
}

static id i_String_toLower(struct String_PRIVATE *self,SEL _cmd)
{
objtolower(( &self->value));
return(id)self;
}

static void
strtoupper(char*s)
{
char c;
while((c= *s))
{ *
s++=toupper(c);
}
}

static void
objtoupper(objstr_t self)
{
strtoupper(self->ptr);
}

static id i_String_toUpper(struct String_PRIVATE *self,SEL _cmd)
{
objtoupper(( &self->value));
return(id)self;
}

# 668 "ocstring.m"
static id i_String_printOn_(struct String_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT33;

# 670 "ocstring.m"
fprintf(aFile,"%s",(objcT33=(id)self,(*(STR(*)(id,SEL))_imp(objcT33,selTransTbl[8]))(objcT33,selTransTbl[8])));
return(id)self;
}

# 681 "ocstring.m"
static void
fileout(id aFiler,objstr_t self)
{
id objcT34,objcT35,objcT36;

# 684 "ocstring.m"
(objcT34=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT34,selTransTbl[15]))(objcT34,selTransTbl[15], &self->count,'i'));
(objcT35=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT35,selTransTbl[15]))(objcT35,selTransTbl[15], &self->capacity,'i'));
(objcT36=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT36,selTransTbl[15]))(objcT36,selTransTbl[15], &self->ptr,'*'));
}

static void
filein(id aFiler,objstr_t self)
{
id objcT37,objcT38,objcT39;

# 692 "ocstring.m"
int c;

(objcT37=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT37,selTransTbl[16]))(objcT37,selTransTbl[16], &self->count,'i'));
(objcT38=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT38,selTransTbl[16]))(objcT38,selTransTbl[16], &c,'i'));
(objcT39=aFiler,(*(id(*)(id,SEL,void*,char))_imp(objcT39,selTransTbl[16]))(objcT39,selTransTbl[16], &self->ptr,'*'));

self->capacity=self->count+1;
}

static id i_String_fileOutOn_(struct String_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT40;

# 703 "ocstring.m"
(objcT40=_String.clsSuper,(*_impSuper(objcT40,selTransTbl[17]))((id)self,selTransTbl[17],aFiler));
fileout(aFiler, &self->value);
return(id)self;
}

static id i_String_fileInFrom_(struct String_PRIVATE *self,SEL _cmd,id aFiler)
{
id objcT41;

# 710 "ocstring.m"
(objcT41=_String.clsSuper,(*_impSuper(objcT41,selTransTbl[18]))((id)self,selTransTbl[18],aFiler));
filein(aFiler, &self->value);
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
extern id  Array;
extern struct _SHARED _Array;
extern struct _SHARED __Array;
static struct _SLT _String_clsDispatchTbl[] ={
{"new",(id (*)())c_String_new},
{"new:",(id (*)())c_String_new_},
{"str:",(id (*)())c_String_str_},
{"chars:count:",(id (*)())c_String_chars_count_},
{"vsprintf::",(id (*)())c_String_vsprintf__},
{"sprintf:",(id (*)())c_String_sprintf_},
{(char*)0,(id (*)())0}
};
static struct _SLT _String_nstDispatchTbl[] ={
{"copy",(id (*)())i_String_copy},
{"deepCopy",(id (*)())i_String_deepCopy},
{"free",(id (*)())i_String_free},
{"release",(id (*)())i_String_release},
{"compare:",(id (*)())i_String_compare_},
{"compareSTR:",(id (*)())i_String_compareSTR_},
{"hash",(id (*)())i_String_hash},
{"dictCompare:",(id (*)())i_String_dictCompare_},
{"isEqual:",(id (*)())i_String_isEqual_},
{"isEqualSTR:",(id (*)())i_String_isEqualSTR_},
{"objstrvalue",(id (*)())i_String_objstrvalue},
{"size",(id (*)())i_String_size},
{"charAt:",(id (*)())i_String_charAt_},
{"charAt:put:",(id (*)())i_String_charAt_put_},
{"strcat:",(id (*)())i_String_strcat_},
{"concat:",(id (*)())i_String_concat_},
{"concatSTR:",(id (*)())i_String_concatSTR_},
{"concatenateSTR:",(id (*)())i_String_concatenateSTR_},
{"at:insert:count:",(id (*)())i_String_at_insert_count_},
{"at:insert:",(id (*)())i_String_at_insert_},
{"deleteFrom:to:",(id (*)())i_String_deleteFrom_to_},
{"assignSTR:",(id (*)())i_String_assignSTR_},
{"assignSTR:length:",(id (*)())i_String_assignSTR_length_},
{"asDouble",(id (*)())i_String_asDouble},
{"asInt",(id (*)())i_String_asInt},
{"asLong",(id (*)())i_String_asLong},
{"asSTR:maxSize:",(id (*)())i_String_asSTR_maxSize_},
{"str",(id (*)())i_String_str},
{"strCopy",(id (*)())i_String_strCopy},
{"toLower",(id (*)())i_String_toLower},
{"toUpper",(id (*)())i_String_toUpper},
{"printOn:",(id (*)())i_String_printOn_},
{"fileOutOn:",(id (*)())i_String_fileOutOn_},
{"fileInFrom:",(id (*)())i_String_fileInFrom_},
{(char*)0,(id (*)())0}
};
id String = (id)&_String;
id  *OBJCCLASS_String(void) { return &String; }
struct _SHARED  _String = {
  (id)&__String,
  (id)&_Array,
  "String",
  0,
  sizeof(struct String_PRIVATE),
  34,
  _String_nstDispatchTbl,
  41,
  &ocstring_modDesc,
  0,
  (id)0,
  &String,
};
id  OBJCCFUNC_String(void) { return (id)&_String; }
id  OBJCCSUPER_String(void) { return _String.clsSuper; }
struct _SHARED __String = {
  (id)&__Object,
  (id)&__Array,
  "String",
  0,
  sizeof(struct _SHARED),
  6,
  _String_clsDispatchTbl,
  34,
  &ocstring_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_String(void) { return (id)&__String; }
id  OBJCMSUPER_String(void) { return __String.clsSuper; }
static char *_selTransTbl[] ={
"new:",
"new",
"objstrvalue",
"str:",
"vsprintf::",
"copy",
"free",
"notImplemented:",
"str",
"compare:",
"compareSTR:",
"concatSTR:",
"at:insert:count:",
"size",
"signal",
"fileOut:type:",
"fileIn:type:",
"fileOutOn:",
"fileInFrom:",
0
};
struct modDescriptor ocstring_modDesc = {
  "ocstring",
  "objc3.3.19",
  0L,
  0,
  0,
  &String,
  19,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_ocstring(void)
{
  selTransTbl = _selTransTbl;
  return &ocstring_modDesc;
}
int _OBJCPOSTLINK_ocstring = 1;


