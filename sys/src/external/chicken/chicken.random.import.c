/* Generated from chicken.random.import.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 6.0.0 (utf+r7rs) (rev 6e4e5fa7)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken.random.import.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -feature chicken-compile-shared -dynamic -no-trace -output-file chicken.random.import.c
   uses: eval library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_extern void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_extern void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_word lf[5];
static double C_possibly_force_alignment;
static C_char li0[] C_aligned={C_lihdr(0,0,6),40,97,49,50,55,41,0,0};
static C_char li1[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_120)
static void C_ccall f_120(C_word c,C_word *av) C_noret;
C_noret_decl(f_123)
static void C_ccall f_123(C_word c,C_word *av) C_noret;
C_noret_decl(f_126)
static void C_ccall f_126(C_word c,C_word *av) C_noret;
C_noret_decl(f_128)
static void C_ccall f_128(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_extern void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

/* k118 */
static void C_ccall f_120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_120,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_123,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k121 in k118 */
static void C_ccall f_123(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_123,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_126,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_128,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp);
/* chicken.random.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[4]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[4]+1);
av2[1]=t2;
av2[2]=t3;
tp(3,av2);}}

/* k124 in k121 in k118 */
static void C_ccall f_126(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_126,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a127 in k121 in k118 */
static void C_ccall f_128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_128,c,av);}
/* chicken.random.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[0]);
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[0]+1);
av2[1]=t1;
av2[2]=lf[1];
av2[3]=lf[2];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[3];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* toplevel */
static int toplevel_initialized=0;
C_main_entry_point

void C_ccall C_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("toplevel"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(108))){
C_save(t1);
C_rereclaim2(108*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,5);
lf[0]=C_h_intern(&lf[0],30, C_text("##sys#register-compiled-module"));
lf[1]=C_h_intern(&lf[1],14, C_text("chicken.random"));
lf[2]=C_h_intern(&lf[2],6, C_text("extras"));
lf[3]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001\163\145\164\055\160\163\145\165\144\157\055\162\141\156\144\157\155\055\163\145\145\144\041\376\001\000\000\046\001\143\150\151\143\153\145\156\056\162\141\156\144\157\155\043\163\145\164\055\160\163\145\165\144\157\055\162\141\156\144\157\155\055\163\145\145\144\041\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001\160\163\145\165\144\157\055\162\141\156\144\157\155\055\151\156\164\145\147\145\162\376\001\000\000\044\001\143\150\151\143\153\145\156\056\162\141\156\144\157\155\043\160\163\145\165\144\157\055\162\141\156\144\157\155\055\151\156\164\145\147\145\162\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001\160\163\145\165\144\157\055\162\141\156\144\157\155\055\162\145\141\154\376\001\000\000\041\001\143\150\151\143\153\145\156\056\162\141\156\144\157\155\043\160\163\145\165\144\157\055\162\141\156\144\157\155\055\162\145\141\154\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001\162\141\156\144\157\155\055\142\171\164\145\163\376\001\000\000\033\001\143\150\151\143\153\145\156\056\162\141\156\144\157\155\043\162\141\156\144\157\155\055\142\171\164\145\163\376\377\016"));
lf[4]=C_h_intern(&lf[4],22, C_text("##sys#with-environment"));
C_register_lf2(lf,5,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_120,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[6] = {
{C_text("f_120:chicken_2erandom_2eimport_2escm"),(void*)f_120},
{C_text("f_123:chicken_2erandom_2eimport_2escm"),(void*)f_123},
{C_text("f_126:chicken_2erandom_2eimport_2escm"),(void*)f_126},
{C_text("f_128:chicken_2erandom_2eimport_2escm"),(void*)f_128},
{C_text("toplevel:chicken_2erandom_2eimport_2escm"),(void*)C_toplevel},
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
(o e)|safe calls: 4 
o|replaced variables: 5 
o|removed binding forms: 3 
o|removed binding forms: 5 
o|simplifications: ((##core#call . 4)) 
o|  call simplifications:
o|    scheme#list	4
o|contracted procedure: k134 
o|contracted procedure: k138 
o|contracted procedure: k142 
o|contracted procedure: k146 
o|removed binding forms: 4 
o|substituted constant variable: r135 
o|substituted constant variable: r139 
o|substituted constant variable: r143 
o|substituted constant variable: r147 
o|removed binding forms: 4 
*/
/* end of file */
