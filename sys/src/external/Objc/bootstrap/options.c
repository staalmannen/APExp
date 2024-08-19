# 1 "options.m"
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
extern struct modDescriptor  *_OBJCBIND_options(void);
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
extern struct modDescriptor options_modDesc;

# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 1 "../../util//assert.h"
#include <assert.h>

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
# 27 "options.m"
int o_warnings;
int o_gnu;
int o_darwin;
int o_vms;
int o_hpux;
int o_sunstudio;
int o_m64;
int o_refcnt;
int o_ppi;
int o_watcom;
int o_ibmvac;
int o_msdos;
int o_enableasm;
int o_nolinetags;
int o_buffered;
int o_quiet;
int o_outputcode;
int o_version;
int o_otb;
int o_llkeyw;
int o_comments;
int o_duptypedefs;
int o_seltranslation;
int o_categories;
int o_blocks;
int o_fwd;
int o_selptr;
int o_cache;
int o_filer;
int o_selfassign;
char*o_bind;
char*o_browsedir;
int o_refbind;
int o_inlinecache;
int o_cplus;
int o_gencode;
int o_st80;
int o_selfassign;
int o_nilrcvr;
int o_shareddata;
int o_oneperfile;
int o_cvars;
int o_warnlex;
int o_warnfwd;
int o_warnsuggest;
int o_warnintvar;
int o_warnclasstype;
int o_warntypeconflict;
int o_warnundefined;
int o_warnlocalnst;
int o_warnnotfound;
int o_warnmissingmethods;
int o_attrcommon;
int o_postlink;
char*o_infile;
char*o_outfile;
char*o_srcfilename;
char*o_initcall;
char*o_tagformat;
int o_linetag;
char*o_mainfun;
char*o_pathsep;
int o_debuginfo;
int o_checkbind;
int o_linemax;
int o_structassign;
id o_stepbreak;
int o_stepnext;

void
defoptions(void)
{
o_tagformat="#line %d \"%s\"\n";
o_quiet=0;
o_outputcode=1;
o_gencode=1;
o_st80=0;
o_otb=0;
o_fwd=1;
o_selptr=1;
o_version=0;
o_infile=NULL;
o_outfile=NULL;
o_srcfilename=NULL;
o_initcall=NULL;
o_mainfun="main";
o_seltranslation=1;
o_inlinecache=0;
o_nolinetags=0;
o_attrcommon=0;
o_postlink=0;
o_shareddata=1;
o_refbind=0;
o_browsedir=NULL;
o_checkbind=0;
o_warnlex=0;
o_warnfwd=0;
o_warnclasstype=1;
o_warntypeconflict=1;
o_warnundefined=1;
o_warnnotfound=1;
o_warnintvar=1;
o_warnmissingmethods=1;
o_warnlocalnst=1;
o_warnsuggest=1;
o_buffered=1;
o_comments=0;
o_duptypedefs=0;
o_msdos=0;
o_gnu=0;
o_darwin=0;
o_sunstudio=0;
o_m64=0;
o_warnings=1;
o_vms=0;
o_hpux=0;
o_refcnt=0;
o_cplus=0;
o_debuginfo=0;
o_ppi=0;
o_ibmvac=0;
o_pathsep=(char*)getenv("OBJCPATHSEP");
if( !o_pathsep)
o_pathsep="/";
o_oneperfile=0;
o_cvars=1;
o_enableasm=1;
o_llkeyw=1;
o_blocks=1;
o_filer=1;
o_bind="";
o_linemax=0;
o_structassign=1;
o_cache=1;
o_nilrcvr=1;
o_selfassign=1;
o_categories=1;
}
static char *_selTransTbl[] ={
0
};
struct modDescriptor options_modDesc = {
  "options",
  "objc3.3.19",
  0L,
  0,
  0,
  0,
  0,
  0,
  0
};
struct modDescriptor *_OBJCBIND_options(void)
{
  selTransTbl = _selTransTbl;
  return &options_modDesc;
}
int _OBJCPOSTLINK_options = 1;


