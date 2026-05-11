/* Generated from chicken.port.import.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken.port.import.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -feature chicken-compile-shared -dynamic -no-trace -output-file chicken.port.import.c
   uses: eval library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[5];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,6),40,97,49,50,54,41,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_119)
static void C_ccall f_119(C_word c,C_word *av) C_noret;
C_noret_decl(f_122)
static void C_ccall f_122(C_word c,C_word *av) C_noret;
C_noret_decl(f_125)
static void C_ccall f_125(C_word c,C_word *av) C_noret;
C_noret_decl(f_127)
static void C_ccall f_127(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

/* k117 */
static void C_ccall f_119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_119,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_122,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k120 in k117 */
static void C_ccall f_122(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_122,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_125,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_127,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp);
/* chicken.port.import.scm:3: ##sys#with-environment */
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

/* k123 in k120 in k117 */
static void C_ccall f_125(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_125,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a126 in k120 in k117 */
static void C_ccall f_127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_127,c,av);}
/* chicken.port.import.scm:5: ##sys#register-compiled-module */
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
static C_TLS int toplevel_initialized=0;
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
if(C_unlikely(!C_demand_2(508))){
C_save(t1);
C_rereclaim2(508*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,5);
lf[0]=C_h_intern(&lf[0],30, C_text("##sys#register-compiled-module"));
lf[1]=C_h_intern(&lf[1],12, C_text("chicken.port"));
lf[2]=C_h_intern(&lf[2],4, C_text("port"));
lf[3]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001call-with-input-string\376\001\000\000#\001chicken.port#call-with-input-string\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001call-with-output-string\376\001\000\000$\001chicken.port#call-with-output-string"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001copy-port\376\001\000\000\026\001chicken.port#copy-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001make-input-"
"port\376\001\000\000\034\001chicken.port#make-input-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001make-output-port\376\001\000\000\035\001chic"
"ken.port#make-output-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001port-fold\376\001\000\000\026\001chicken.port#port-fold\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\015\001port-for-each\376\001\000\000\032\001chicken.port#port-for-each\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001port-"
"map\376\001\000\000\025\001chicken.port#port-map\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001port-name\376\001\000\000\026\001chicken.port#port-n"
"ame\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001port-position\376\001\000\000\032\001chicken.port#port-position\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001"
"make-bidirectional-port\376\001\000\000$\001chicken.port#make-bidirectional-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023"
"\001make-broadcast-port\376\001\000\000 \001chicken.port#make-broadcast-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001make-c"
"oncatenated-port\376\001\000\000#\001chicken.port#make-concatenated-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001set-buf"
"fering-mode!\376\001\000\000 \001chicken.port#set-buffering-mode!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001set-port-name!"
"\376\001\000\000\033\001chicken.port#set-port-name!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001terminal-name\376\001\000\000\032\001chicken.port"
"#terminal-name\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001terminal-port\077\376\001\000\000\033\001chicken.port#terminal-port\077\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\015\001terminal-size\376\001\000\000\032\001chicken.port#terminal-size\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001with-e"
"rror-output-to-port\376\001\000\000&\001chicken.port#with-error-output-to-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001w"
"ith-input-from-port\376\001\000\000!\001chicken.port#with-input-from-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001with-i"
"nput-from-string\376\001\000\000#\001chicken.port#with-input-from-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001with-ou"
"tput-to-port\376\001\000\000 \001chicken.port#with-output-to-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001with-output-to"
"-string\376\001\000\000\042\001chicken.port#with-output-to-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\033\001with-error-output"
"-to-string\376\001\000\000(\001chicken.port#with-error-output-to-string\376\377\016"));
lf[4]=C_h_intern(&lf[4],22, C_text("##sys#with-environment"));
C_register_lf2(lf,5,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_119,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[6] = {
{C_text("f_119:chicken_2eport_2eimport_2escm"),(void*)f_119},
{C_text("f_122:chicken_2eport_2eimport_2escm"),(void*)f_122},
{C_text("f_125:chicken_2eport_2eimport_2escm"),(void*)f_125},
{C_text("f_127:chicken_2eport_2eimport_2escm"),(void*)f_127},
{C_text("toplevel:chicken_2eport_2eimport_2escm"),(void*)C_toplevel},
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
o|contracted procedure: k133 
o|contracted procedure: k137 
o|contracted procedure: k141 
o|contracted procedure: k145 
o|removed binding forms: 4 
o|substituted constant variable: r134 
o|substituted constant variable: r138 
o|substituted constant variable: r142 
o|substituted constant variable: r146 
o|removed binding forms: 4 
*/
/* end of file */
