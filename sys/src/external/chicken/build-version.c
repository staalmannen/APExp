/* Generated from build-version.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: build-version.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file build-version.c
   unit: build-version
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);

static C_TLS C_word lf[6];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(C_build_2dversion_toplevel)
C_externexport void C_ccall C_build_2dversion_toplevel(C_word c,C_word *av) C_noret;

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_build_2dversion_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("build-version"));
C_check_nursery_minimum(C_calculate_demand(8,c,1));
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void*)C_build_2dversion_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(28))){
C_save(t1);
C_rereclaim2(28*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(8);
C_initialize_lf(lf,6);
lf[0]=C_h_intern(&lf[0],13, C_text("build-version"));
lf[1]=C_h_intern(&lf[1],14, C_text("##sys#build-id"));
lf[2]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0101a1d1495"));
lf[3]=C_h_intern(&lf[3],18, C_text("##sys#build-branch"));
lf[4]=C_h_intern(&lf[4],19, C_text("##sys#build-version"));
lf[5]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0055.4.0"));
C_register_lf2(lf,6,create_ptable());{}
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_mutate((C_word*)lf[1]+1 /* (set! ##sys#build-id ...) */,lf[2]);
t4=C_set_block_item(lf[3] /* ##sys#build-branch */,0,C_SCHEME_FALSE);
t5=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#build-version ...) */,lf[5]);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[2] = {
{C_text("toplevel:build_2dversion_2escm"),(void*)C_build_2dversion_toplevel},
{NULL,NULL}};
#endif

static C_PTABLE_ENTRY *create_ptable(void){
#ifdef C_ENABLE_PTABLES
return ptable;
#else
return NULL;
#endif
}

/*
o|safe globals: (##sys#build-version ##sys#build-branch ##sys#build-id) 
o|removed binding forms: 3 
*/
/* end of file */
