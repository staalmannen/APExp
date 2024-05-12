# 1 "octext.m"
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
extern struct modDescriptor  *_OBJCBIND_octext(void);
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
extern struct modDescriptor octext_modDesc;

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
# 32 "./octext.h"
struct Text_PRIVATE {

# 42 "./../../include/objcrt/Object.h"
id isa;
# 46 "./../../include/objcrt/Object.h"
unsigned short attr;
unsigned short objID;
# 34 "./octext.h"
id string;
id runs;};

# 32 "./octext.h"
extern id  Text;

# 32 "./octext.h"
extern struct _SHARED _Text;
extern struct _SHARED __Text;


# 38 "octext.m"
static id i_Text_check(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT0;

# 40 "octext.m"
(objcT0=self->runs,(*_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0]));
(void)0;
return(id)self;
}

# 40 "./ocstring.h"
extern id  String;

# 45 "octext.m"
static id c_Text_new(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT1,objcT2;

# 47 "octext.m"
return(objcT1=(id)self,(*_imp(objcT1,selTransTbl[1]))(objcT1,selTransTbl[1],(objcT2=String,(*_imp(objcT2,selTransTbl[2]))(objcT2,selTransTbl[2]))));
}

static id c_Text_new_(struct Text_PRIVATE *self,SEL _cmd,unsigned nChars)
{
id objcT3,objcT4;

# 52 "octext.m"
return(objcT3=(id)self,(*_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1],(objcT4=String,(*(id(*)(id,SEL,unsigned))_imp(objcT4,selTransTbl[3]))(objcT4,selTransTbl[3],nChars))));
}

static id c_Text_vsprintf__(struct Text_PRIVATE *self,SEL _cmd,STR format,va_list*ap)
{
id objcT5;

# 57 "octext.m"
char aBuffer[(2048)];
# 66 "octext.m"
vsprintf(aBuffer,format, *ap);


return(objcT5=(id)self,(*(id(*)(id,SEL,STR))_imp(objcT5,selTransTbl[4]))(objcT5,selTransTbl[4],aBuffer));
}

static id c_Text_str_(struct Text_PRIVATE *self,SEL _cmd,STR aString)
{
id objcT6,objcT7;

# 74 "octext.m"
return(objcT6=(id)self,(*_imp(objcT6,selTransTbl[1]))(objcT6,selTransTbl[1],(objcT7=String,(*(id(*)(id,SEL,STR))_imp(objcT7,selTransTbl[4]))(objcT7,selTransTbl[4],aString))));;
}

static id c_Text_sprintf_(struct Text_PRIVATE *self,SEL _cmd,STR format,...)
{
id objcT8;

# 79 "octext.m"
id newtext;


va_list ap;
va_start(ap,format);
newtext=(objcT8=(id)self,(*(id(*)(id,SEL,STR,va_list*))_imp(objcT8,selTransTbl[5]))(objcT8,selTransTbl[5],format, &ap));
va_end(ap);
return newtext;
}

# 28 "./runarray.h"
extern id  RunArray;

# 89 "octext.m"
static id c_Text_fromString_(struct Text_PRIVATE *self,SEL _cmd,id aString)
{
id objcT9,objcT10,objcT11;

# 91 "octext.m"
return(objcT9=(objcT10=__Text.clsSuper,(*_impSuper(objcT10,selTransTbl[2]))((id)self,selTransTbl[2])),(*_imp(objcT9,selTransTbl[6]))(objcT9,selTransTbl[6],aString,(objcT11=RunArray,(*_imp(objcT11,selTransTbl[2]))(objcT11,selTransTbl[2]))));
}

static id c_Text_string_attribute_(struct Text_PRIVATE *self,SEL _cmd,id aString,id attrib)
{
id objcT12,objcT13;

# 96 "octext.m"
return(objcT12=(objcT13=(id)self,(*_imp(objcT13,selTransTbl[1]))(objcT13,selTransTbl[1],aString)),(*_imp(objcT12,selTransTbl[7]))(objcT12,selTransTbl[7],attrib));
}

static id i_Text_string_runs_(struct Text_PRIVATE *self,SEL _cmd,id aString,id anArray)
{self->
string=aString;self->
runs=anArray;
return(id)self;
}

static id i_Text_copy(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT14,objcT15,objcT16,objcT17;

# 108 "octext.m"
return(objcT14=(objcT15=self->isa,(*_imp(objcT15,selTransTbl[2]))(objcT15,selTransTbl[2])),(*_imp(objcT14,selTransTbl[6]))(objcT14,selTransTbl[6],(objcT16=self->string,(*_imp(objcT16,selTransTbl[8]))(objcT16,selTransTbl[8])),(objcT17=self->runs,(*_imp(objcT17,selTransTbl[8]))(objcT17,selTransTbl[8]))));
}

static id i_Text_free(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT18,objcT19,objcT20;
self->
# 113 "octext.m"
string=(objcT18=self->string,(*_imp(objcT18,selTransTbl[9]))(objcT18,selTransTbl[9]));self->
runs=(objcT19=self->runs,(*_imp(objcT19,selTransTbl[9]))(objcT19,selTransTbl[9]));
return(objcT20=_Text.clsSuper,(*_impSuper(objcT20,selTransTbl[9]))((id)self,selTransTbl[9]));
}


static unsigned i_Text_hash(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT21;

# 121 "octext.m"
return(objcT21=self->string,(*(unsigned(*)(id,SEL))_imp(objcT21,selTransTbl[10]))(objcT21,selTransTbl[10]));
}

static BOOL i_Text_isEqual_(struct Text_PRIVATE *self,SEL _cmd,id aStr)
{
id objcT22,objcT23;

# 126 "octext.m"
(objcT22=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT22,selTransTbl[11]))(objcT22,selTransTbl[11],(objcT23=self->string,(*(unsigned(*)(id,SEL))_imp(objcT23,selTransTbl[12]))(objcT23,selTransTbl[12]))));
if((id)self==aStr)
{
return(BOOL)1;
}
else
{
id objcT24,objcT25,objcT26,objcT27;

# 133 "octext.m"
return(objcT24=self->string,(*(BOOL(*)(id,SEL,id))_imp(objcT24,selTransTbl[13]))(objcT24,selTransTbl[13],(objcT25=aStr,(*_imp(objcT25,selTransTbl[14]))(objcT25,selTransTbl[14]))))&&(objcT26=self->runs,(*(BOOL(*)(id,SEL,id))_imp(objcT26,selTransTbl[13]))(objcT26,selTransTbl[13],(objcT27=aStr,(*_imp(objcT27,selTransTbl[15]))(objcT27,selTransTbl[15]))));
}
}


static id i_Text_string(struct Text_PRIVATE *self,SEL _cmd)
{
return self->string;
}

static id i_Text_runs(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT28,objcT29;

# 145 "octext.m"
(objcT28=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT28,selTransTbl[11]))(objcT28,selTransTbl[11],(objcT29=self->string,(*(unsigned(*)(id,SEL))_imp(objcT29,selTransTbl[12]))(objcT29,selTransTbl[12]))));
return self->runs;
}

static STR i_Text_str(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT30;

# 151 "octext.m"
return(objcT30=self->string,(*(STR(*)(id,SEL))_imp(objcT30,selTransTbl[16]))(objcT30,selTransTbl[16]));
}

static unsigned i_Text_size(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT31;

# 156 "octext.m"
return(objcT31=self->string,(*(unsigned(*)(id,SEL))_imp(objcT31,selTransTbl[12]))(objcT31,selTransTbl[12]));
}

static char i_Text_charAt_(struct Text_PRIVATE *self,SEL _cmd,unsigned anOffset)
{
id objcT32;

# 161 "octext.m"
return(objcT32=self->string,(*(char(*)(id,SEL,unsigned))_imp(objcT32,selTransTbl[17]))(objcT32,selTransTbl[17],anOffset));
}

static char i_Text_charAt_put_(struct Text_PRIVATE *self,SEL _cmd,unsigned anOffset,char aChar)
{
id objcT33;

# 166 "octext.m"
return(objcT33=self->string,(*(char(*)(id,SEL,unsigned,char))_imp(objcT33,selTransTbl[18]))(objcT33,selTransTbl[18],anOffset,aChar));
}

static id i_Text_at_insert_(struct Text_PRIVATE *self,SEL _cmd,unsigned anOffset,id aString)
{
id objcT34,objcT35,objcT36;

# 171 "octext.m"
return(objcT34=(id)self,(*(id(*)(id,SEL,unsigned,char*,int))_imp(objcT34,selTransTbl[19]))(objcT34,selTransTbl[19],anOffset,(objcT35=aString,(*(STR(*)(id,SEL))_imp(objcT35,selTransTbl[16]))(objcT35,selTransTbl[16])),(objcT36=aString,(*(unsigned(*)(id,SEL))_imp(objcT36,selTransTbl[12]))(objcT36,selTransTbl[12]))));
}

static id i_Text_at_insert_count_(struct Text_PRIVATE *self,SEL _cmd,unsigned anOffset,char*aString,int size)
{
id objcT37,objcT38;

# 176 "octext.m"
(objcT37=self->string,(*(id(*)(id,SEL,unsigned,char*,int))_imp(objcT37,selTransTbl[19]))(objcT37,selTransTbl[19],anOffset,aString,size));
(objcT38=self->runs,(*(id(*)(id,SEL,unsigned,char*,int))_imp(objcT38,selTransTbl[19]))(objcT38,selTransTbl[19],anOffset,aString,size));
return(id)self;
}

static id i_Text_deleteFrom_to_(struct Text_PRIVATE *self,SEL _cmd,unsigned p,unsigned q)
{
id objcT39,objcT40;

# 183 "octext.m"
(objcT39=self->string,(*(id(*)(id,SEL,unsigned,unsigned))_imp(objcT39,selTransTbl[20]))(objcT39,selTransTbl[20],p,q));
(objcT40=self->runs,(*(id(*)(id,SEL,unsigned,unsigned))_imp(objcT40,selTransTbl[20]))(objcT40,selTransTbl[20],p,q));
return(id)self;
}

static id i_Text_concat_(struct Text_PRIVATE *self,SEL _cmd,id b)
{
id objcT41,objcT42,objcT43,objcT44;

# 190 "octext.m"
(objcT41=self->string,(*_imp(objcT41,selTransTbl[21]))(objcT41,selTransTbl[21],(objcT42=b,(*_imp(objcT42,selTransTbl[14]))(objcT42,selTransTbl[14]))));
(objcT43=self->runs,(*_imp(objcT43,selTransTbl[21]))(objcT43,selTransTbl[21],(objcT44=b,(*_imp(objcT44,selTransTbl[15]))(objcT44,selTransTbl[15]))));
return(id)self;
}

static id i_Text_concatSTR_(struct Text_PRIVATE *self,SEL _cmd,STR b)
{
id objcT45,objcT46,objcT47;

# 197 "octext.m"
(objcT45=self->string,(*(id(*)(id,SEL,STR))_imp(objcT45,selTransTbl[22]))(objcT45,selTransTbl[22],b));
(objcT46=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT46,selTransTbl[11]))(objcT46,selTransTbl[11],(objcT47=self->string,(*(unsigned(*)(id,SEL))_imp(objcT47,selTransTbl[12]))(objcT47,selTransTbl[12]))));
return(id)self;
}

# 32 "./txtattr.h"
extern id  TextAttribute;

# 203 "octext.m"
static id i_Text_allBold(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT48,objcT49;

# 205 "octext.m"
(objcT48=(id)self,(*_imp(objcT48,selTransTbl[7]))(objcT48,selTransTbl[7],(objcT49=TextAttribute,(*_imp(objcT49,selTransTbl[23]))(objcT49,selTransTbl[23]))));
return(id)self;
}

static id i_Text_makeBoldFrom_to_(struct Text_PRIVATE *self,SEL _cmd,unsigned p,unsigned q)
{
id objcT50,objcT51;

# 211 "octext.m"
(objcT50=(id)self,(*(id(*)(id,SEL,id,unsigned,unsigned))_imp(objcT50,selTransTbl[24]))(objcT50,selTransTbl[24],(objcT51=TextAttribute,(*_imp(objcT51,selTransTbl[23]))(objcT51,selTransTbl[23])),p,q));
return(id)self;
}

static id i_Text_addAttribute_(struct Text_PRIVATE *self,SEL _cmd,id attribute)
{
id objcT52,objcT53;

# 217 "octext.m"
unsigned n=(objcT52=self->string,(*(unsigned(*)(id,SEL))_imp(objcT52,selTransTbl[12]))(objcT52,selTransTbl[12]));
(objcT53=self->runs,(*(id(*)(id,SEL,id,unsigned,unsigned))_imp(objcT53,selTransTbl[25]))(objcT53,selTransTbl[25],attribute,0,n));
return(id)self;
}

# 28 "./outofbnd.h"
extern id  OutOfBounds;

# 222 "octext.m"
static id i_Text_addAttribute_from_to_(struct Text_PRIVATE *self,SEL _cmd,id attribute,unsigned p,unsigned q)
{
id objcT54,objcT56;

# 224 "octext.m"
unsigned n=(objcT54=self->string,(*(unsigned(*)(id,SEL))_imp(objcT54,selTransTbl[12]))(objcT54,selTransTbl[12]));
if(p>q||q>=n)
{
id objcT55;

# 227 "octext.m"
(objcT55=OutOfBounds,(*_imp(objcT55,selTransTbl[26]))(objcT55,selTransTbl[26]));
return(id)self;
}
(objcT56=self->runs,(*(id(*)(id,SEL,id,unsigned,unsigned))_imp(objcT56,selTransTbl[25]))(objcT56,selTransTbl[25],attribute,p,q-p+1));
(void)0;
return(id)self;
}

static id i_Text_attributesAt_(struct Text_PRIVATE *self,SEL _cmd,unsigned i)
{
id objcT57,objcT58,objcT59;

# 237 "octext.m"
(objcT57=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT57,selTransTbl[11]))(objcT57,selTransTbl[11],(objcT58=self->string,(*(unsigned(*)(id,SEL))_imp(objcT58,selTransTbl[12]))(objcT58,selTransTbl[12]))));
return(objcT59=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT59,selTransTbl[27]))(objcT59,selTransTbl[27],i));
}

static unsigned i_Text_runLengthFor_(struct Text_PRIVATE *self,SEL _cmd,unsigned i)
{
id objcT60,objcT61,objcT62;

# 243 "octext.m"
(objcT60=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT60,selTransTbl[11]))(objcT60,selTransTbl[11],(objcT61=self->string,(*(unsigned(*)(id,SEL))_imp(objcT61,selTransTbl[12]))(objcT61,selTransTbl[12]))));
return(objcT62=self->runs,(*(unsigned(*)(id,SEL,unsigned))_imp(objcT62,selTransTbl[28]))(objcT62,selTransTbl[28],i));
}

static unsigned i_Text_fontNumberAt_(struct Text_PRIVATE *self,SEL _cmd,unsigned i)
{
id objcT63,objcT64,objcT65;

# 249 "octext.m"
(objcT63=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT63,selTransTbl[11]))(objcT63,selTransTbl[11],(objcT64=self->string,(*(unsigned(*)(id,SEL))_imp(objcT64,selTransTbl[12]))(objcT64,selTransTbl[12]))));
return(objcT65=self->runs,(*(unsigned(*)(id,SEL,unsigned))_imp(objcT65,selTransTbl[29]))(objcT65,selTransTbl[29],i));
}

static id i_Text_fontAt_withStyle_(struct Text_PRIVATE *self,SEL _cmd,unsigned i,id textStyle)
{
id objcT66,objcT67,objcT68;

# 255 "octext.m"
(objcT66=self->runs,(*(id(*)(id,SEL,unsigned))_imp(objcT66,selTransTbl[11]))(objcT66,selTransTbl[11],(objcT67=self->string,(*(unsigned(*)(id,SEL))_imp(objcT67,selTransTbl[12]))(objcT67,selTransTbl[12]))));
return(objcT68=self->runs,(*(id(*)(id,SEL,unsigned,id))_imp(objcT68,selTransTbl[30]))(objcT68,selTransTbl[30],i,textStyle));
}


static id i_Text_asString(struct Text_PRIVATE *self,SEL _cmd)
{
return self->string;
}

static id i_Text_asText(struct Text_PRIVATE *self,SEL _cmd)
{
return(id)self;
}

# 32 "./paragrph.h"
extern id  Paragraph;

# 270 "octext.m"
static id i_Text_asParagraph(struct Text_PRIVATE *self,SEL _cmd)
{
id objcT69;

# 272 "octext.m"
return(objcT69=Paragraph,(*_imp(objcT69,selTransTbl[31]))(objcT69,selTransTbl[31],(id)self));
}


static id i_Text_printOn_(struct Text_PRIVATE *self,SEL _cmd,IOD aFile)
{
id objcT70;

# 278 "octext.m"
fprintf(aFile,"Text for ");
(objcT70=self->string,(*(id(*)(id,SEL,IOD))_imp(objcT70,selTransTbl[32]))(objcT70,selTransTbl[32],aFile));
return(id)self;
}
extern id  Object;
extern struct _SHARED _Object;
extern struct _SHARED __Object;
static struct _SLT _Text_clsDispatchTbl[] ={
{"new",(id (*)())c_Text_new},
{"new:",(id (*)())c_Text_new_},
{"vsprintf::",(id (*)())c_Text_vsprintf__},
{"str:",(id (*)())c_Text_str_},
{"sprintf:",(id (*)())c_Text_sprintf_},
{"fromString:",(id (*)())c_Text_fromString_},
{"string:attribute:",(id (*)())c_Text_string_attribute_},
{(char*)0,(id (*)())0}
};
static struct _SLT _Text_nstDispatchTbl[] ={
{"check",(id (*)())i_Text_check},
{"string:runs:",(id (*)())i_Text_string_runs_},
{"copy",(id (*)())i_Text_copy},
{"free",(id (*)())i_Text_free},
{"hash",(id (*)())i_Text_hash},
{"isEqual:",(id (*)())i_Text_isEqual_},
{"string",(id (*)())i_Text_string},
{"runs",(id (*)())i_Text_runs},
{"str",(id (*)())i_Text_str},
{"size",(id (*)())i_Text_size},
{"charAt:",(id (*)())i_Text_charAt_},
{"charAt:put:",(id (*)())i_Text_charAt_put_},
{"at:insert:",(id (*)())i_Text_at_insert_},
{"at:insert:count:",(id (*)())i_Text_at_insert_count_},
{"deleteFrom:to:",(id (*)())i_Text_deleteFrom_to_},
{"concat:",(id (*)())i_Text_concat_},
{"concatSTR:",(id (*)())i_Text_concatSTR_},
{"allBold",(id (*)())i_Text_allBold},
{"makeBoldFrom:to:",(id (*)())i_Text_makeBoldFrom_to_},
{"addAttribute:",(id (*)())i_Text_addAttribute_},
{"addAttribute:from:to:",(id (*)())i_Text_addAttribute_from_to_},
{"attributesAt:",(id (*)())i_Text_attributesAt_},
{"runLengthFor:",(id (*)())i_Text_runLengthFor_},
{"fontNumberAt:",(id (*)())i_Text_fontNumberAt_},
{"fontAt:withStyle:",(id (*)())i_Text_fontAt_withStyle_},
{"asString",(id (*)())i_Text_asString},
{"asText",(id (*)())i_Text_asText},
{"asParagraph",(id (*)())i_Text_asParagraph},
{"printOn:",(id (*)())i_Text_printOn_},
{(char*)0,(id (*)())0}
};
id Text = (id)&_Text;
id  *OBJCCLASS_Text(void) { return &Text; }
struct _SHARED  _Text = {
  (id)&__Text,
  (id)&_Object,
  "Text",
  0,
  sizeof(struct Text_PRIVATE),
  29,
  _Text_nstDispatchTbl,
  41,
  &octext_modDesc,
  0,
  (id)0,
  &Text,
};
id  OBJCCFUNC_Text(void) { return (id)&_Text; }
id  OBJCCSUPER_Text(void) { return _Text.clsSuper; }
struct _SHARED __Text = {
  (id)&__Object,
  (id)&__Object,
  "Text",
  0,
  sizeof(struct _SHARED),
  7,
  _Text_clsDispatchTbl,
  34,
  &octext_modDesc,
  0,
  (id)0,
  0,
};
id  OBJCMFUNC_Text(void) { return (id)&__Text; }
id  OBJCMSUPER_Text(void) { return __Text.clsSuper; }
static char *_selTransTbl[] ={
"check",
"fromString:",
"new",
"new:",
"str:",
"vsprintf::",
"string:runs:",
"addAttribute:",
"copy",
"free",
"hash",
"setsize:",
"size",
"isEqual:",
"string",
"runs",
"str",
"charAt:",
"charAt:put:",
"at:insert:count:",
"deleteFrom:to:",
"concat:",
"concatSTR:",
"bold",
"addAttribute:from:to:",
"addAttribute:from:size:",
"signal",
"at:",
"runLengthAt:",
"fontNumberAt:",
"fontAt:withStyle:",
"withText:",
"printOn:",
0
};
struct modDescriptor octext_modDesc = {
  "octext",
  "objc3.3.19",
  0L,
  0,
  0,
  &Text,
  33,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_octext(void)
{
  selTransTbl = _selTransTbl;
  return &octext_modDesc;
}
int _OBJCPOSTLINK_octext = 1;


