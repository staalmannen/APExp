/* Generated from debugger-client.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: debugger-client.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file debugger-client.c
   unit: debugger-client
*/
#include "chicken.h"

#include "dbg-stub.c"

static C_PTABLE_ENTRY *create_ptable(void);

static C_TLS C_word lf[1];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(C_debugger_2dclient_toplevel)
C_externexport void C_ccall C_debugger_2dclient_toplevel(C_word c,C_word *av) C_noret;

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_debugger_2dclient_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("debugger-client"));
C_check_nursery_minimum(C_calculate_demand(8,c,1));
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void*)C_debugger_2dclient_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(7))){
C_save(t1);
C_rereclaim2(7*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(8);
C_initialize_lf(lf,1);
lf[0]=C_h_intern(&lf[0],15, C_text("debugger-client"));
C_register_lf2(lf,1,create_ptable());{}
t2=C_a_i_provide(&a,1,lf[0]);
t3=connect_to_debugger();
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[2] = {
{C_text("toplevel:debugger_2dclient_2escm"),(void*)C_debugger_2dclient_toplevel},
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
*/
/* end of file */
