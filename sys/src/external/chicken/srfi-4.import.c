/* Generated from srfi-4.import.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: srfi-4.import.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -feature chicken-compile-shared -dynamic -no-trace -output-file srfi-4.import.c
   uses: eval library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[4];
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
/* srfi-4.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[3]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[3]+1);
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
/* srfi-4.import.scm:5: ##sys#register-compiled-module */
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
av2[3]=lf[1];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[2];
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
if(C_unlikely(!C_demand_2(2721))){
C_save(t1);
C_rereclaim2(2721*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,4);
lf[0]=C_h_intern(&lf[0],30, C_text("##sys#register-compiled-module"));
lf[1]=C_h_intern(&lf[1],6, C_text("srfi-4"));
lf[2]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->f32vector\376\001\000\000\026\001srfi-4#blob->f32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob-"
">f32vector/shared\376\001\000\000\035\001srfi-4#blob->f32vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->f64vec"
"tor\376\001\000\000\026\001srfi-4#blob->f64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->f64vector/shared\376\001\000\000\035\001srfi-"
"4#blob->f64vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->s16vector\376\001\000\000\026\001srfi-4#blob->s16vec"
"tor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->s16vector/shared\376\001\000\000\035\001srfi-4#blob->s16vector/shared\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\017\001blob->s32vector\376\001\000\000\026\001srfi-4#blob->s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->s32"
"vector/shared\376\001\000\000\035\001srfi-4#blob->s32vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->s64vector\376"
"\001\000\000\026\001srfi-4#blob->s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->s64vector/shared\376\001\000\000\035\001srfi-4#bl"
"ob->s64vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001blob->s8vector\376\001\000\000\025\001srfi-4#blob->s8vector\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\025\001blob->s8vector/shared\376\001\000\000\034\001srfi-4#blob->s8vector/shared\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\017\001blob->u16vector\376\001\000\000\026\001srfi-4#blob->u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->u16vector/s"
"hared\376\001\000\000\035\001srfi-4#blob->u16vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->u32vector\376\001\000\000\026\001srf"
"i-4#blob->u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->u32vector/shared\376\001\000\000\035\001srfi-4#blob->u32v"
"ector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->u64vector\376\001\000\000\026\001srfi-4#blob->u64vector\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\026\001blob->u64vector/shared\376\001\000\000\035\001srfi-4#blob->u64vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001"
"blob->u8vector\376\001\000\000\025\001srfi-4#blob->u8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001blob->u8vector/shared\376\001"
"\000\000\034\001srfi-4#blob->u8vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001f32vector\376\001\000\000\020\001srfi-4#f32vector\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f32vector->blob\376\001\000\000\026\001srfi-4#f32vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001f32vec"
"tor->blob/shared\376\001\000\000\035\001srfi-4#f32vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f32vector->li"
"st\376\001\000\000\026\001srfi-4#f32vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001f32vector-length\376\001\000\000\027\001srfi-4#f32ve"
"ctor-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001f32vector-ref\376\001\000\000\024\001srfi-4#f32vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\016\001f32vector-set!\376\001\000\000\025\001srfi-4#f32vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001f32vector\077\376\001\000\000\021\001srfi-"
"4#f32vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001f64vector\376\001\000\000\020\001srfi-4#f64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f64ve"
"ctor->blob\376\001\000\000\026\001srfi-4#f64vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001f64vector->blob/shared\376\001\000\000"
"\035\001srfi-4#f64vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f64vector->list\376\001\000\000\026\001srfi-4#f64ve"
"ctor->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001f64vector-length\376\001\000\000\027\001srfi-4#f64vector-length\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\015\001f64vector-ref\376\001\000\000\024\001srfi-4#f64vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001f64vector-set!\376\001\000\000"
"\025\001srfi-4#f64vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001f64vector\077\376\001\000\000\021\001srfi-4#f64vector\077\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\010\001s8vector\376\001\000\000\017\001srfi-4#s8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s8vector->blob\376\001\000\000\025\001srfi-4#"
"s8vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001s8vector->blob/shared\376\001\000\000\034\001srfi-4#s8vector->blob/s"
"hared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s8vector->list\376\001\000\000\025\001srfi-4#s8vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s8"
"vector-length\376\001\000\000\026\001srfi-4#s8vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001s8vector-ref\376\001\000\000\023\001srfi-"
"4#s8vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001s8vector-set!\376\001\000\000\024\001srfi-4#s8vector-set!\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\011\001s8vector\077\376\001\000\000\020\001srfi-4#s8vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001s16vector\376\001\000\000\020\001srfi-4#s16vec"
"tor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s16vector->blob\376\001\000\000\026\001srfi-4#s16vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001s1"
"6vector->blob/shared\376\001\000\000\035\001srfi-4#s16vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s16vector"
"->list\376\001\000\000\026\001srfi-4#s16vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001s16vector-length\376\001\000\000\027\001srfi-4#s"
"16vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001s16vector-ref\376\001\000\000\024\001srfi-4#s16vector-ref\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\016\001s16vector-set!\376\001\000\000\025\001srfi-4#s16vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001s16vector\077\376\001\000\000\021\001s"
"rfi-4#s16vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001s32vector\376\001\000\000\020\001srfi-4#s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s"
"32vector->blob\376\001\000\000\026\001srfi-4#s32vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001s32vector->blob/shared"
"\376\001\000\000\035\001srfi-4#s32vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s32vector->list\376\001\000\000\026\001srfi-4#s"
"32vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001s32vector-length\376\001\000\000\027\001srfi-4#s32vector-length\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\015\001s32vector-ref\376\001\000\000\024\001srfi-4#s32vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s32vector-set!"
"\376\001\000\000\025\001srfi-4#s32vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001s32vector\077\376\001\000\000\021\001srfi-4#s32vector\077\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\011\001s64vector\376\001\000\000\020\001srfi-4#s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s64vector->blob\376\001\000\000\026\001"
"srfi-4#s64vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001s64vector->blob/shared\376\001\000\000\035\001srfi-4#s64vect"
"or->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s64vector->list\376\001\000\000\026\001srfi-4#s64vector->list\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\020\001s64vector-length\376\001\000\000\027\001srfi-4#s64vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001s64vector"
"-ref\376\001\000\000\024\001srfi-4#s64vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s64vector-set!\376\001\000\000\025\001srfi-4#s64vect"
"or-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001s64vector\077\376\001\000\000\021\001srfi-4#s64vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001u8vector"
"\376\001\000\000\017\001srfi-4#u8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u8vector->blob\376\001\000\000\025\001srfi-4#u8vector->blob\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\025\001u8vector->blob/shared\376\001\000\000\034\001srfi-4#u8vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\016\001u8vector->list\376\001\000\000\025\001srfi-4#u8vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u8vector-length\376\001\000"
"\000\026\001srfi-4#u8vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001u8vector-ref\376\001\000\000\023\001srfi-4#u8vector-ref\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\015\001u8vector-set!\376\001\000\000\024\001srfi-4#u8vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u8vector\077\376\001"
"\000\000\020\001srfi-4#u8vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u16vector\376\001\000\000\020\001srfi-4#u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\017\001u16vector->blob\376\001\000\000\026\001srfi-4#u16vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001u16vector->blob/sh"
"ared\376\001\000\000\035\001srfi-4#u16vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u16vector->list\376\001\000\000\026\001srfi"
"-4#u16vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001u16vector-length\376\001\000\000\027\001srfi-4#u16vector-length\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001u16vector-ref\376\001\000\000\024\001srfi-4#u16vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u16vector-"
"set!\376\001\000\000\025\001srfi-4#u16vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001u16vector\077\376\001\000\000\021\001srfi-4#u16vector\077"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u32vector\376\001\000\000\020\001srfi-4#u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u32vector->blob\376\001"
"\000\000\026\001srfi-4#u32vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001u32vector->blob/shared\376\001\000\000\035\001srfi-4#u32"
"vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u32vector->list\376\001\000\000\026\001srfi-4#u32vector->list\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\020\001u32vector-length\376\001\000\000\027\001srfi-4#u32vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001u32ve"
"ctor-ref\376\001\000\000\024\001srfi-4#u32vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u32vector-set!\376\001\000\000\025\001srfi-4#u32"
"vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001u32vector\077\376\001\000\000\021\001srfi-4#u32vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u64v"
"ector\376\001\000\000\020\001srfi-4#u64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u64vector->blob\376\001\000\000\026\001srfi-4#u64vector"
"->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001u64vector->blob/shared\376\001\000\000\035\001srfi-4#u64vector->blob/shared\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u64vector->list\376\001\000\000\026\001srfi-4#u64vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001u64vec"
"tor-length\376\001\000\000\027\001srfi-4#u64vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001u64vector-ref\376\001\000\000\024\001srfi-4"
"#u64vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u64vector-set!\376\001\000\000\025\001srfi-4#u64vector-set!\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\012\001u64vector\077\376\001\000\000\021\001srfi-4#u64vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->f32vector\376\001\000\000\026\001srf"
"i-4#list->f32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->f64vector\376\001\000\000\026\001srfi-4#list->f64vector\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->s16vector\376\001\000\000\026\001srfi-4#list->s16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->s"
"32vector\376\001\000\000\026\001srfi-4#list->s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->s64vector\376\001\000\000\026\001srfi-4#"
"list->s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001list->s8vector\376\001\000\000\025\001srfi-4#list->s8vector\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\017\001list->u16vector\376\001\000\000\026\001srfi-4#list->u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->u32vect"
"or\376\001\000\000\026\001srfi-4#list->u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001list->u8vector\376\001\000\000\025\001srfi-4#list->u"
"8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->u64vector\376\001\000\000\026\001srfi-4#list->u64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\016\001make-f32vector\376\001\000\000\025\001srfi-4#make-f32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-f64vector\376\001\000\000\025\001s"
"rfi-4#make-f64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-s16vector\376\001\000\000\025\001srfi-4#make-s16vector\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\016\001make-s32vector\376\001\000\000\025\001srfi-4#make-s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-s64ve"
"ctor\376\001\000\000\025\001srfi-4#make-s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001make-s8vector\376\001\000\000\024\001srfi-4#make-s8"
"vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-u16vector\376\001\000\000\025\001srfi-4#make-u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001m"
"ake-u32vector\376\001\000\000\025\001srfi-4#make-u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-u64vector\376\001\000\000\025\001srfi"
"-4#make-u64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001make-u8vector\376\001\000\000\024\001srfi-4#make-u8vector\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\016\001number-vector\077\376\001\000\000\025\001srfi-4#number-vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001read-u8vector\376\001"
"\000\000\024\001srfi-4#read-u8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001read-u8vector!\376\001\000\000\025\001srfi-4#read-u8vector"
"!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001release-number-vector\376\001\000\000\034\001srfi-4#release-number-vector\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\014\001subf32vector\376\001\000\000\023\001srfi-4#subf32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subf64vector\376\001\000\000\023\001s"
"rfi-4#subf64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subs16vector\376\001\000\000\023\001srfi-4#subs16vector\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\014\001subs32vector\376\001\000\000\023\001srfi-4#subs32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subs64vector\376\001\000\000\023\001sr"
"fi-4#subs64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001subs8vector\376\001\000\000\022\001srfi-4#subs8vector\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\014\001subu16vector\376\001\000\000\023\001srfi-4#subu16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001subu8vector\376\001\000\000\022\001srfi-4"
"#subu8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subu32vector\376\001\000\000\023\001srfi-4#subu32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014"
"\001subu64vector\376\001\000\000\023\001srfi-4#subu64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001write-u8vector\376\001\000\000\025\001srfi-4"
"#write-u8vector\376\377\016"));
lf[3]=C_h_intern(&lf[3],22, C_text("##sys#with-environment"));
C_register_lf2(lf,4,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_119,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[6] = {
{C_text("f_119:srfi_2d4_2eimport_2escm"),(void*)f_119},
{C_text("f_122:srfi_2d4_2eimport_2escm"),(void*)f_122},
{C_text("f_125:srfi_2d4_2eimport_2escm"),(void*)f_125},
{C_text("f_127:srfi_2d4_2eimport_2escm"),(void*)f_127},
{C_text("toplevel:srfi_2d4_2eimport_2escm"),(void*)C_toplevel},
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
