/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:15:23 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "util/decode.c"
#line 28 "ape-sys/ctype.h"
enum _ZN29_INTERNAL_8_decode_c_f78890d3Ut_E {
_ISupper = 0x1,
_ISlower = 0x2,
_ISdigit = 0x4,
_ISspace = 0x8,
_ISpunct = 0x10,
_IScntrl = 0x20,
_ISblank = 0x40,
_ISxdigit = 0x80};
#line 93 "util/decode.c"
struct a_decode_control_block;
#line 4371
struct a_func_block;
#line 4398
enum a_substitution_kind {
subk_unscoped_template_name,

subk_prefix,
subk_template_prefix,
subk_type,
subk_template_template_param};



struct a_substitution_location;
#line 6665
union _ZZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_blockEUt_;
#line 98 "ape-sys/stdint_generic.h"
typedef unsigned uint32_t;
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 92 "util/decode.c"
typedef struct a_decode_control_block *a_decode_control_block_ptr;
#line 541 "src/basics.h"
typedef size_t _ZN3edg8sizeof_tE;
#line 214
typedef _Bool _ZN3edg9a_booleanE;
#line 93 "util/decode.c"
struct a_decode_control_block {
char *output_id;


_ZN3edg8sizeof_tE output_id_len;


_ZN3edg8sizeof_tE output_id_size;

_ZN3edg9a_booleanE err_in_id;


_ZN3edg9a_booleanE output_overflow_err;


unsigned long suppress_id_output;



_ZN3edg8sizeof_tE uncompressed_length;
#line 129
unsigned long suppress_substitution_recording;

_ZN3edg9a_booleanE contains_conversion_operator;




_ZN3edg9a_booleanE parse_template_args_after_conversion_operator;
#line 142
unsigned long suppress_template_parameters;char __dummy[4];};
#line 148
typedef struct a_decode_control_block a_decode_control_block;
#line 4351
typedef int a_cv_qualifier_set;
#line 4360
typedef int a_ref_qualifier;
#line 515 "src/basics.h"
typedef const char _ZN3edg12a_const_charE;
#line 4371 "util/decode.c"
struct a_func_block {
_ZN3edg9a_booleanE no_return_type;



a_cv_qualifier_set cv_quals;



a_ref_qualifier ref_qual;


_ZN3edg12a_const_charE *ctor_dtor_kind;};
#line 4390
typedef struct a_func_block a_func_block;
#line 4408
struct a_substitution_location {
_ZN3edg12a_const_charE *start;

enum a_substitution_kind kind;
unsigned long num_levels;
#line 4422
_ZN3edg9a_booleanE parse_template_args;char __dummy[7];};
#line 4428
typedef struct a_substitution_location a_substitution_location;
#line 4489
typedef int a_demangle_name_option;
#line 4814
typedef int a_bare_function_type_option;
#line 6665
union _ZZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_blockEUt_ {

long double ld;

double d;
float f;};
#line 539 "src/basics.h"
typedef size_t _ZN3edg11true_size_tE;
#line 76 "ape-sys/stdio.h"
extern int snprintf(char *, size_t, const char *, ...);
#line 44 "ape-sys/stdlib.h"
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);
#line 11 "ape-sys/string.h"
extern void *memcpy(void *, const void *, size_t);


extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);



extern int strcmp(const char *, const char *);




extern int strncmp(const char *, const char *, size_t);


extern char *strchr(const char *, int);
#line 36
extern size_t strlen(const char *);
#line 151 "util/decode.c"
static void _ZN29_INTERNAL_8_decode_c_f78890d319clear_control_blockEP22a_decode_control_block(a_decode_control_block_ptr dctl);
#line 289
static void _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(char ch, a_decode_control_block_ptr dctl);
#line 317
static void _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *str, a_decode_control_block_ptr dctl);
#line 331
static void _ZN29_INTERNAL_8_decode_c_f78890d315write_id_numberEmP22a_decode_control_block(unsigned long num, a_decode_control_block_ptr dctl);
#line 346
static void _ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block(long num, a_decode_control_block_ptr dctl);
#line 361
static void _ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(a_decode_control_block_ptr dctl);
#line 377
static char _ZN29_INTERNAL_8_decode_c_f78890d38get_charEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 388
static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(_ZN3edg12a_const_charE *str, _ZN3edg12a_const_charE *id);
#line 450
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(const char ch, _ZN3edg12a_const_charE *p, a_decode_control_block_ptr dctl);
#line 467
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *p, a_decode_control_block_ptr dctl);
#line 487
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318demangle_module_idEPKcmS1_P22a_decode_control_block(_ZN3edg12a_const_charE *ptr, unsigned long num, _ZN3edg12a_const_charE *prefix, a_decode_control_block_ptr dctl);
#line 4531
static void _ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block(a_func_block *func_block);
#line 4543
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(_ZN3edg12a_const_charE *p, long *num, a_decode_control_block_ptr dctl);
#line 4573
static void _ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(_ZN3edg12a_const_charE *start, enum a_substitution_kind kind, unsigned long num_levels, _ZN3edg9a_booleanE parse_template_args, a_decode_control_block_ptr dctl);
#line 4620
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(_ZN3edg12a_const_charE *ptr, int type_pass_num, a_cv_qualifier_set cv_quals, _ZN3edg9a_booleanE under_lhs_declarator, _ZN3edg9a_booleanE need_trailing_space, 
#line 4620
_ZN3edg12a_const_charE **last_component_name, _ZN3edg12a_const_charE **substitution, a_decode_control_block_ptr dctl);
#line 4820
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE no_return_type, a_bare_function_type_option options, a_decode_control_block_ptr dctl);
#line 4900
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(_ZN3edg12a_const_charE *ptr, a_cv_qualifier_set *cv_quals);
#line 4930
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi(_ZN3edg12a_const_charE *ptr, a_ref_qualifier *ref_qual);
#line 4950
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d330demangle_vector_size_qualifierEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 4967
static void _ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(a_cv_qualifier_set cv_quals, _ZN3edg9a_booleanE trailing_space, a_decode_control_block_ptr dctl);
#line 4996
static void _ZN29_INTERNAL_8_decode_c_f78890d320output_ref_qualifierEiP22a_decode_control_block(a_ref_qualifier ref_qual, a_decode_control_block_ptr dctl);
#line 5010
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 5044
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d328demangle_parameter_referenceEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 5164
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323demangle_type_specifierEPKcbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE parse_template_args, a_decode_control_block_ptr dctl);
#line 5439
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324skip_extern_C_indicationEPKc(_ZN3edg12a_const_charE *ptr);
#line 5453
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_cv_qualifier_set cv_quals, _ZN3edg9a_booleanE under_lhs_declarator, _ZN3edg9a_booleanE need_trailing_space, _ZN3edg9a_booleanE 
#line 5453
parse_template_args, a_decode_control_block_ptr dctl);
#line 5699
static void _ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_cv_qualifier_set cv_quals, _ZN3edg9a_booleanE under_lhs_declarator, a_decode_control_block_ptr dctl);
#line 5880
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE parse_template_args, _ZN3edg9a_booleanE is_pack_expansion, a_decode_control_block_ptr dctl);
#line 5931
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(_ZN3edg12a_const_charE *ptr, int *num_operands, int *length, _ZN3edg12a_const_charE **close_str, a_decode_control_block_ptr dctl);
#line 6345
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE is_module_id, a_decode_control_block_ptr dctl);
#line 6413
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319get_instance_numberEPKcPmP22a_decode_control_block(_ZN3edg12a_const_charE *p, unsigned long *instance, a_decode_control_block_ptr dctl);
#line 6441
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_unnamed_typeEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6492
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d326demangle_abi_tag_attributeEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6536
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE *is_no_return_name, a_decode_control_block_ptr dctl);
#line 6632
static unsigned char _ZN29_INTERNAL_8_decode_c_f78890d313get_hex_digitEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6654
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6757
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_float_literalEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6784
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_complex_literalEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6827
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_expr_primaryEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6924
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 6974
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, char stop_char, char open_paren, char close_paren, _ZN3edg9a_booleanE is_braced_expr, a_decode_control_block_ptr dctl);
#line 7013
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, char stop_char, a_decode_control_block_ptr dctl);
#line 7028
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_initializerEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 7057
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 7490
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_template_argEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 7523
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 7558
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d331demangle_nested_name_componentsEPKcmPbS2_PS1_S3_P22a_decode_control_block(_ZN3edg12a_const_charE *ptr, unsigned long num_levels, _ZN3edg9a_booleanE *is_no_return_name, _ZN3edg9a_booleanE *has_templ_arg_list, _ZN3edg12a_const_charE **
#line 7558
ctor_dtor_kind, _ZN3edg12a_const_charE **last_component_name, a_decode_control_block_ptr dctl);
#line 7746
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_nested_nameEPKcP12a_func_blockP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_func_block *func_block, a_decode_control_block_ptr dctl);
#line 7807
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319demangle_local_nameEPKcP12a_func_blockP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_func_block *func_block, a_decode_control_block_ptr dctl);
#line 7892
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_unscoped_nameEPKcP12a_func_blockP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_func_block *func_block, a_decode_control_block_ptr dctl);
#line 7920
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_func_block *func_block, a_demangle_name_option options, a_decode_control_block_ptr dctl);
#line 8012
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 8030
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d329demangle_base_unresolved_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 8092
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 8209
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 8248
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_special_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
#line 8333
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d330demangle_function_or_data_nameEPKcbbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE include_func_params, _ZN3edg9a_booleanE first_scan, a_decode_control_block_ptr dctl);
#line 8475
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE include_func_params, a_decode_control_block_ptr dctl);
#line 8512
static void _ZN29_INTERNAL_8_decode_c_f78890d319init_demangle_stateEPcyP22a_decode_control_block(char *output_buffer, _ZN3edg8sizeof_tE output_buffer_size, a_decode_control_block_ptr dctl);
#line 8531
extern void _Z17decode_identifierPKcPcyPbS2_Py(_ZN3edg12a_const_charE *id, char *output_buffer, _ZN3edg8sizeof_tE output_buffer_size, _ZN3edg9a_booleanE *err, _ZN3edg9a_booleanE *buffer_overflow_err, _ZN3edg8sizeof_tE *required_buffer_size);
#line 8621
extern char *__cxa_demangle(char *mangled_name, char *user_buffer, _ZN3edg11true_size_tE *user_buffer_size, int *status);
#line 39 "ape-sys/ctype.h"
extern unsigned char _ctype[];
#line 4340 "util/decode.c"
extern _ZN3edg9a_booleanE emulate_gnu_abi_bugs;
#line 4346
_ZN3edg9a_booleanE host_little_endian = 0;
#line 4431
static a_substitution_location *substitutions;




static unsigned long num_substitutions;




static unsigned long allocated_substitutions;



static char *ud_suffix_buffer;




static unsigned long ud_suffix_buffer_length;
#line 6313
static char _ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name[22];
#line 4340
_ZN3edg9a_booleanE emulate_gnu_abi_bugs = ((_ZN3edg9a_booleanE)0);
#line 4431
static a_substitution_location *substitutions = ((a_substitution_location *)0);




static unsigned long num_substitutions = 0UL;




static unsigned long allocated_substitutions = 0UL;



static char *ud_suffix_buffer = ((char *)0);




static unsigned long ud_suffix_buffer_length = 0UL;
#line 6313
static char _ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name[22] = "builtin-operation-XXX";
#line 151
static void _ZN29_INTERNAL_8_decode_c_f78890d319clear_control_blockEP22a_decode_control_block( a_decode_control_block_ptr __27430_60_dctl)



{
(__27430_60_dctl->output_id) = ((char *)0);
(__27430_60_dctl->output_id_len) = 0ULL;
(__27430_60_dctl->output_id_size) = 0ULL;
(__27430_60_dctl->err_in_id) = ((_ZN3edg9a_booleanE)0);
(__27430_60_dctl->output_overflow_err) = ((_ZN3edg9a_booleanE)0);
(__27430_60_dctl->suppress_id_output) = 0UL;
(__27430_60_dctl->uncompressed_length) = 0ULL;




(__27430_60_dctl->suppress_substitution_recording) = 0UL;
(__27430_60_dctl->contains_conversion_operator) = ((_ZN3edg9a_booleanE)0);
(__27430_60_dctl->parse_template_args_after_conversion_operator) = ((_ZN3edg9a_booleanE)0);
(__27430_60_dctl->suppress_template_parameters) = 0UL; 

}
#line 289
static void _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block( char __27568_52_ch, 
a_decode_control_block_ptr __27569_52_dctl)



{
if (!(__27569_52_dctl->suppress_id_output)) {
if (!(__27569_52_dctl->output_overflow_err)) {

if (((__27569_52_dctl->output_id_len) + 1ULL) >= (__27569_52_dctl->output_id_size)) {

(__27569_52_dctl->output_overflow_err) = ((_ZN3edg9a_booleanE)1);

if ((__27569_52_dctl->output_id_size) != 0ULL) {
((__27569_52_dctl->output_id)[((__27569_52_dctl->output_id_size) - 1ULL)]) = ((char)0);
}
} else  {

((__27569_52_dctl->output_id)[(__27569_52_dctl->output_id_len)]) = __27568_52_ch;
}
}


(__27569_52_dctl->output_id_len)++;
} 
}


static void _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__27596_53_str, 
a_decode_control_block_ptr __27597_52_dctl)



{
auto _ZN3edg12a_const_charE *__27602_17_p; __27602_17_p = __27596_53_str;

if (!(__27597_52_dctl->suppress_id_output)) {
for (; ((int)(*__27602_17_p)) != 0; __27602_17_p++) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__27602_17_p), __27597_52_dctl); }
} 
}


static void _ZN29_INTERNAL_8_decode_c_f78890d315write_id_numberEmP22a_decode_control_block( unsigned long __27610_56_num, 
a_decode_control_block_ptr __27611_56_dctl)




{
auto char __27617_17_buffer[50];

snprintf((__27617_17_buffer), 50ULL, ((const char *)"%lu"), __27610_56_num);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__27617_17_buffer)), __27611_56_dctl); 
}



static void _ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block( long __27625_63_num, 
a_decode_control_block_ptr __27626_63_dctl)




{
auto char __27632_17_buffer[50];

snprintf((__27632_17_buffer), 50ULL, ((const char *)"%ld"), __27625_63_num);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__27632_17_buffer)), __27626_63_dctl); 
}



static void _ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block( a_decode_control_block_ptr __27640_57_dctl)



{
if (!(__27640_57_dctl->err_in_id)) {
(__27640_57_dctl->err_in_id) = ((_ZN3edg9a_booleanE)1);
(__27640_57_dctl->suppress_id_output)++;

(__27640_57_dctl->suppress_substitution_recording)++;

} 
}



static char _ZN29_INTERNAL_8_decode_c_f78890d38get_charEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__27656_61_ptr, 
a_decode_control_block_ptr __27657_60_dctl)




{
return *__27656_61_ptr;
}


static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_( _ZN3edg12a_const_charE *__27667_47_str, 
_ZN3edg12a_const_charE *__27668_47_id)



{
auto _ZN3edg9a_booleanE __27673_13_is_start = ((_ZN3edg9a_booleanE)0);

for (; ; ) {
auto char __27676_10_chs; __27676_10_chs = (*(__27667_47_str++));
if (((int)__27676_10_chs) == 0) {
__27673_13_is_start = ((_ZN3edg9a_booleanE)1);
goto __T800852760;
}
if (((int)__27676_10_chs) != ((int)(*(__27668_47_id++)))) { goto __T800852760; }
} __T800852760:;
return __27673_13_is_start;
}
#line 450
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block( const char __27729_62_ch, 
_ZN3edg12a_const_charE *__27730_63_p, 
a_decode_control_block_ptr __27731_62_dctl)




{
if (((int)(_ZN29_INTERNAL_8_decode_c_f78890d38get_charEPKcP22a_decode_control_block(__27730_63_p, __27731_62_dctl))) == ((int)__27729_62_ch)) {
__27730_63_p++;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__27731_62_dctl);
}
return __27730_63_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__27746_74_p, 
a_decode_control_block_ptr __27747_73_dctl)




{
return _ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __27746_74_p, __27747_73_dctl);
}
#line 487
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318demangle_module_idEPKcmS1_P22a_decode_control_block( _ZN3edg12a_const_charE *__27766_69_ptr, 
unsigned long __27767_68_num, 
_ZN3edg12a_const_charE *__27768_69_prefix, 
a_decode_control_block_ptr __27769_68_dctl)
#line 502
{

auto long __27783_9_num_chars_to_output;



auto _ZN3edg12a_const_charE *__27787_18_start;

if ((((int)(*__27766_69_ptr)) != 95) || (!(((int)((_ctype)[((unsigned char)((unsigned char)(__27766_69_ptr[1])))])) & 4))) {


if (__27768_69_prefix != ((_ZN3edg12a_const_charE *)0)) {
while (__27768_69_prefix != __27766_69_ptr) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*(__27768_69_prefix++)), __27769_68_dctl); }
}
__27783_9_num_chars_to_output = ((long)__27767_68_num);
__27787_18_start = __27766_69_ptr;
} else  {
__27787_18_start = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__27766_69_ptr + 1), (&__27783_9_num_chars_to_output), __27769_68_dctl));
if (!(__27769_68_dctl->err_in_id)) {
auto uint32_t __27800_16_prefix_len; __27800_16_prefix_len = ((uint32_t)((__27787_18_start - __27766_69_ptr) + 1LL));
if (((((int)(*__27787_18_start)) != 95) || (__27783_9_num_chars_to_output <= 0L)) || (__27767_68_num < (((unsigned long)__27783_9_num_chars_to_output) + ((unsigned long)__27800_16_prefix_len))))



{
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__27769_68_dctl);
} else  {

__27787_18_start++;
}
}
}
if (!(__27769_68_dctl->err_in_id)) {

while ((__27783_9_num_chars_to_output--) > 0L) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*(__27787_18_start++)), __27769_68_dctl); }
}
return __27766_69_ptr + __27767_68_num;
}
#line 4531
static void _ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block( a_func_block *__31810_44_func_block)



{
(__31810_44_func_block->no_return_type) = ((_ZN3edg9a_booleanE)0);
(__31810_44_func_block->cv_quals) = 0;
(__31810_44_func_block->ref_qual) = 0;
(__31810_44_func_block->ctor_dtor_kind) = ((_ZN3edg12a_const_charE *)0); 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block( _ZN3edg12a_const_charE *__31822_61_p, 
long *__31823_61_num, 
a_decode_control_block_ptr __31824_60_dctl)
#line 4551
{
auto long __31831_13_n = 0L;
auto _ZN3edg9a_booleanE __31832_13_negative = ((_ZN3edg9a_booleanE)0);

if (((int)(*__31822_61_p)) == 110) {
__31832_13_negative = ((_ZN3edg9a_booleanE)1);
__31822_61_p++;
}
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__31822_61_p)))])) & 4)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31824_60_dctl);
} else  {
do {
__31831_13_n = ((__31831_13_n * 10L) + ((long)(((int)(*__31822_61_p)) - 48)));
__31822_61_p++;
} while (((int)((_ctype)[((unsigned char)((unsigned char)(*__31822_61_p)))])) & 4);
}
if (__31832_13_negative) { __31831_13_n = (-__31831_13_n); }
(*__31823_61_num) = __31831_13_n;
return __31822_61_p;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(
_ZN3edg12a_const_charE *__31853_61_start, 
enum a_substitution_kind __31854_60_kind, 
unsigned long __31855_60_num_levels, 
_ZN3edg9a_booleanE __31856_60_parse_template_args, 
a_decode_control_block_ptr __31857_60_dctl)
#line 4589
{


if (!(__31857_60_dctl->suppress_substitution_recording)) {
auto unsigned long __31872_29_number;
auto a_substitution_location *__31873_30_subp;
#line 4593
__31872_29_number = (num_substitutions++);

if (num_substitutions > allocated_substitutions) {

auto _ZN3edg11true_size_tE __31876_19_new_size;
allocated_substitutions += 500UL;
__31876_19_new_size = (((unsigned long long)allocated_substitutions) * 24ULL);
if (substitutions == ((a_substitution_location *)0)) {
substitutions = ((a_substitution_location *)(malloc(__31876_19_new_size)));
} else  {
substitutions = ((a_substitution_location *)(realloc(((void *)substitutions), __31876_19_new_size)));

}
if (substitutions == ((a_substitution_location *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31857_60_dctl);
return;
}
}
__31873_30_subp = (substitutions + __31872_29_number);
(__31873_30_subp->start) = __31853_61_start;
(__31873_30_subp->kind) = __31854_60_kind;
(__31873_30_subp->num_levels) = __31855_60_num_levels;
(__31873_30_subp->parse_template_args) = __31856_60_parse_template_args;
} 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(
_ZN3edg12a_const_charE *__31900_58_ptr, 
int __31901_57_type_pass_num, 
a_cv_qualifier_set __31902_57_cv_quals, 
_ZN3edg9a_booleanE __31903_57_under_lhs_declarator, 
_ZN3edg9a_booleanE __31904_57_need_trailing_space, 
_ZN3edg12a_const_charE **__31905_59_last_component_name, 
_ZN3edg12a_const_charE **__31906_59_substitution, 
a_decode_control_block_ptr __31907_57_dctl)
#line 4664
{
auto char __31944_8_ch2; __31944_8_ch2 = (__31900_58_ptr[1]);

if (__31905_59_last_component_name != ((_ZN3edg12a_const_charE **)0)) { (*__31905_59_last_component_name) = ((_ZN3edg12a_const_charE *)0); }
if (__31906_59_substitution != ((_ZN3edg12a_const_charE **)0)) { (*__31906_59_substitution) = ((_ZN3edg12a_const_charE *)0); }
if (((int)((_ctype)[((unsigned char)((unsigned char)__31944_8_ch2))])) & 2) {

auto _ZN3edg12a_const_charE *__31950_19_str = ((const char *)"");
auto _ZN3edg12a_const_charE *__31951_19_last_name = ((const char *)"");
if (((int)__31944_8_ch2) == 116) {
__31950_19_str = ((const char *)"std");
__31951_19_last_name = ((const char *)"3std");
} else  { if (((int)__31944_8_ch2) == 97) {
__31950_19_str = ((const char *)"std::allocator");
__31951_19_last_name = ((const char *)"9allocator");
} else  { if (((int)__31944_8_ch2) == 98) {
__31950_19_str = ((const char *)"std::basic_string");
__31951_19_last_name = ((const char *)"12basic_string");
} else  { if (((int)__31944_8_ch2) == 115) {
__31950_19_str = ((const char *)"std::basic_string<char, std::char_traits<char>, std::allocator<char>>");

__31951_19_last_name = ((const char *)"12basic_string");
} else  { if (((int)__31944_8_ch2) == 105) {
__31950_19_str = ((const char *)"std::basic_istream<char, std::char_traits<char>>");
__31951_19_last_name = ((const char *)"13basic_istream");
} else  { if (((int)__31944_8_ch2) == 111) {
__31950_19_str = ((const char *)"std::basic_ostream<char, std::char_traits<char>>");
__31951_19_last_name = ((const char *)"13basic_ostream");
} else  { if (((int)__31944_8_ch2) == 100) {
__31950_19_str = ((const char *)"std::basic_iostream<char, std::char_traits<char>>");
__31951_19_last_name = ((const char *)"14basic_iostream");
} } } } } } }

if (__31901_57_type_pass_num != 2) {
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__31902_57_cv_quals, ((_ZN3edg9a_booleanE)1), __31907_57_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__31950_19_str, __31907_57_dctl);
}
__31900_58_ptr += 2;
if (__31905_59_last_component_name != ((_ZN3edg12a_const_charE **)0)) { (*__31905_59_last_component_name) = __31951_19_last_name; }
} else  {

auto uint32_t __31984_29_number = 0U;
auto a_substitution_location *__31985_30_subp;
auto _ZN3edg12a_const_charE *__31986_21_p;
__31900_58_ptr++;
if (((int)__31944_8_ch2) != 95) {
auto _ZN3edg12a_const_charE __31989_30_digits[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
do {
__31984_29_number *= 36U;
if (((int)(*__31900_58_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31907_57_dctl);
goto __T801074344;
}
__31986_21_p = ((_ZN3edg12a_const_charE *)(strchr((__31989_30_digits), ((int)(*__31900_58_ptr)))));
if (__31986_21_p == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31907_57_dctl);
goto __T801074344;
}
__31984_29_number += ((uint32_t)(__31986_21_p - (__31989_30_digits)));
__31900_58_ptr++;
} while (((int)(*__31900_58_ptr)) != 95); __T801074344:;
__31984_29_number++;
}
if (((unsigned long)__31984_29_number) >= num_substitutions) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31907_57_dctl);
} else  {
auto a_func_block __32009_20_func_block;
__31900_58_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__31900_58_ptr, __31907_57_dctl));
__31985_30_subp = (substitutions + __31984_29_number);
__31986_21_p = (__31985_30_subp->start);
if (__31906_59_substitution != ((_ZN3edg12a_const_charE **)0)) { (*__31906_59_substitution) = __31986_21_p; }



(__31907_57_dctl->suppress_substitution_recording)++;
if ((__31901_57_type_pass_num == 2) && (((int)(__31985_30_subp->kind)) != 3)) {




} else  {
switch ((int)(__31985_30_subp->kind)) {
case 0:
if ((__31901_57_type_pass_num == 1) || (__31901_57_type_pass_num == 0)) {


_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__31902_57_cv_quals, ((_ZN3edg9a_booleanE)1), __31907_57_dctl);
}
_ZN29_INTERNAL_8_decode_c_f78890d322demangle_unscoped_nameEPKcP12a_func_blockP22a_decode_control_block(__31986_21_p, (&__32009_20_func_block), __31907_57_dctl);
goto __T801091368;
case 1:
case 2:
{ auto _ZN3edg9a_booleanE __32035_25_is_no_return_name; auto _ZN3edg9a_booleanE __32035_44_has_templ_arg_list;
auto _ZN3edg12a_const_charE *__32036_29_ctor_dtor_kind;
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__31902_57_cv_quals, ((_ZN3edg9a_booleanE)1), __31907_57_dctl);



if ((__31985_30_subp->num_levels) > 0UL) {
__31986_21_p = (_ZN29_INTERNAL_8_decode_c_f78890d331demangle_nested_name_componentsEPKcmPbS2_PS1_S3_P22a_decode_control_block(__31986_21_p, (__31985_30_subp->num_levels), (&__32035_25_is_no_return_name), (&__32035_44_has_templ_arg_list), (&__32036_29_ctor_dtor_kind), 
#line 4763
__31905_59_last_component_name, __31907_57_dctl));
#line 4770
}
if (((int)(__31985_30_subp->kind)) == 2) {


if ((__31985_30_subp->num_levels) > 0UL) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __31907_57_dctl); }
__31986_21_p = (_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__31986_21_p, (&__32035_25_is_no_return_name), __31907_57_dctl));
}
}
goto __T801091368;
case 3:
if ((__31901_57_type_pass_num == 1) || (__31901_57_type_pass_num == 0)) {



_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__31986_21_p, __31902_57_cv_quals, __31903_57_under_lhs_declarator, __31904_57_need_trailing_space, (__31985_30_subp->parse_template_args), __31907_57_dctl);




}
if ((__31901_57_type_pass_num == 2) || (__31901_57_type_pass_num == 0)) {
_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__31986_21_p, __31902_57_cv_quals, __31903_57_under_lhs_declarator, __31907_57_dctl);

}
goto __T801091368;
case 4:
_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__31986_21_p, __31907_57_dctl);
goto __T801091368;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31907_57_dctl);
} __T801091368:;
}
(__31907_57_dctl->suppress_substitution_recording)--;
}
}
return __31900_58_ptr;
}
#line 4820
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(
_ZN3edg12a_const_charE *__32100_66_ptr, 
_ZN3edg9a_booleanE __32101_65_no_return_type, 
a_bare_function_type_option __32102_65_options, 
a_decode_control_block_ptr __32103_65_dctl)
#line 4845
{
#line 4852
if ((__32102_65_options & 0x1) == 0) { (__32103_65_dctl->suppress_id_output)++; }
if (!(__32101_65_no_return_type)) {

__32100_66_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32100_66_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32103_65_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32103_65_dctl);
}
if ((__32102_65_options & 0x1) == 0) { (__32103_65_dctl->suppress_id_output)--; }

if ((__32102_65_options & 0x2) == 0) { (__32103_65_dctl->suppress_id_output)++; }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32103_65_dctl);
if (((((int)(*__32100_66_ptr)) == 69) || (((int)(*__32100_66_ptr)) == 0)) || (((((int)(*__32100_66_ptr)) == 82) || (((int)(*__32100_66_ptr)) == 79)) && (((int)(*(__32100_66_ptr + 1))) == 69))) {



_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32103_65_dctl);
} else  { if ((((int)(*__32100_66_ptr)) == 118) && (((((int)(*(__32100_66_ptr + 1))) == 69) || (((int)(*(__32100_66_ptr + 1))) == 0)) || (((((int)(*(__32100_66_ptr + 1))) == 82) || (((int)(*(__32100_66_ptr + 1))) == 79)) && (((int)(*((__32100_66_ptr + 1) + 1))) == 69)))) {


__32100_66_ptr++;
} else  {
for (; ; ) {
if (((int)(*__32100_66_ptr)) == 122) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __32103_65_dctl);
__32100_66_ptr++;
if (!(((((int)(*__32100_66_ptr)) == 69) || (((int)(*__32100_66_ptr)) == 0)) || (((((int)(*__32100_66_ptr)) == 82) || (((int)(*__32100_66_ptr)) == 79)) && (((int)(*(__32100_66_ptr + 1))) == 69)))) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32103_65_dctl);
goto __T801148760;
}
} else  {

__32100_66_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32100_66_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32103_65_dctl));
}

if (((((int)(*__32100_66_ptr)) == 69) || (((int)(*__32100_66_ptr)) == 0)) || (((((int)(*__32100_66_ptr)) == 82) || (((int)(*__32100_66_ptr)) == 79)) && (((int)(*(__32100_66_ptr + 1))) == 69))) { goto __T801148760; }

if (__32103_65_dctl->err_in_id) { goto __T801148760; }

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __32103_65_dctl);
} __T801148760:;
} }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32103_65_dctl);
if ((__32102_65_options & 0x2) == 0) { (__32103_65_dctl->suppress_id_output)--; }
return __32100_66_ptr;

}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi( _ZN3edg12a_const_charE *__32179_60_ptr, 
a_cv_qualifier_set *__32180_60_cv_quals)
#line 4913
{
(*__32180_60_cv_quals) = 0;
for (; ; __32179_60_ptr++) {
if (((int)(*__32179_60_ptr)) == 75) {
(*__32180_60_cv_quals) |= 0x1;
} else  { if (((int)(*__32179_60_ptr)) == 86) {
(*__32180_60_cv_quals) |= 0x2;
} else  { if (((int)(*__32179_60_ptr)) == 114) {
(*__32180_60_cv_quals) |= 0x4;
} else  {
goto __T801172272;
} } }
} __T801172272:;
return __32179_60_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi( _ZN3edg12a_const_charE *__32209_57_ptr, 
a_ref_qualifier *__32210_57_ref_qual)
#line 4937
{
(*__32210_57_ref_qual) = 0;
if (((int)(*__32209_57_ptr)) == 82) {
(*__32210_57_ref_qual) = 0x1;
__32209_57_ptr++;
} else  { if (((int)(*__32209_57_ptr)) == 79) {
(*__32210_57_ref_qual) = 0x2;
__32209_57_ptr++;
} }
return __32209_57_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d330demangle_vector_size_qualifierEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__32230_76_ptr, 
a_decode_control_block_ptr __32231_75_dctl)
#line 4958
{
if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"U8__vector"), __32230_76_ptr)) {
__32230_76_ptr += 10;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__attribute__((vector_size(\?))) "), __32231_75_dctl);
}
return __32230_76_ptr;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block( a_cv_qualifier_set __32246_61_cv_quals, 
_ZN3edg9a_booleanE __32247_61_trailing_space, 
a_decode_control_block_ptr __32248_61_dctl)
#line 4975
{
auto _ZN3edg9a_booleanE __32255_13_any_previous = ((_ZN3edg9a_booleanE)0);

if (__32246_61_cv_quals & 0x1) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"const"), __32248_61_dctl);
__32255_13_any_previous = ((_ZN3edg9a_booleanE)1);
}
if (__32246_61_cv_quals & 0x2) {
if (__32255_13_any_previous) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32248_61_dctl); }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"volatile"), __32248_61_dctl);
__32255_13_any_previous = ((_ZN3edg9a_booleanE)1);
}
if (__32246_61_cv_quals & 0x4) {
if (__32255_13_any_previous) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32248_61_dctl); }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"restrict"), __32248_61_dctl);
__32255_13_any_previous = ((_ZN3edg9a_booleanE)1);
}
if ((__32255_13_any_previous) && (__32247_61_trailing_space)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32248_61_dctl); } 
}


static void _ZN29_INTERNAL_8_decode_c_f78890d320output_ref_qualifierEiP22a_decode_control_block( a_ref_qualifier __32275_61_ref_qual, 
a_decode_control_block_ptr __32276_61_dctl)



{
if (__32275_61_ref_qual == 0x1) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"&"), __32276_61_dctl);
} else  { if (__32275_61_ref_qual & 0x2) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"&&"), __32276_61_dctl);
} } 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__32289_74_ptr, 
a_decode_control_block_ptr __32290_73_dctl)
#line 5022
{
auto long __32302_8_num = 1L;
auto char __32303_8_buffer[50];


__32289_74_ptr++;
if (((int)(*__32289_74_ptr)) != 95) {
__32289_74_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32289_74_ptr, (&__32302_8_num), __32290_73_dctl));
if (__32302_8_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32290_73_dctl);
__32302_8_num = 0L;
} else  {
__32302_8_num += 2L;
}
}
__32289_74_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32289_74_ptr, __32290_73_dctl));
snprintf((__32303_8_buffer), 50ULL, ((const char *)"T%ld"), __32302_8_num);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__32303_8_buffer)), __32290_73_dctl);
return __32289_74_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d328demangle_parameter_referenceEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__32324_76_ptr, 
a_decode_control_block_ptr __32325_75_dctl)
#line 5069
{
auto long __32349_22_num = 1L; auto long __32349_31_level = (-1L);
auto char __32350_22_buffer[51];
auto a_cv_qualifier_set __32351_22_cv_quals;


__32324_76_ptr++;
if (((int)(*__32324_76_ptr)) == 76) {

__32324_76_ptr++;
__32324_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32324_76_ptr, (&__32349_31_level), __32325_75_dctl));
if (__32349_31_level < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32325_75_dctl);
goto __32404_1_end_of_routine;
} else  {
__32349_31_level += 1L;
}
}
if (((int)(*__32324_76_ptr)) != 112) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32325_75_dctl);
goto __32404_1_end_of_routine;
}
__32324_76_ptr++;
if (((int)(*__32324_76_ptr)) == 84) {

__32324_76_ptr++;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"this"), __32325_75_dctl);
} else  {
if ((((int)(*__32324_76_ptr)) != 95) && (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__32324_76_ptr)))])) & 4))) {

__32324_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__32324_76_ptr, (&__32351_22_cv_quals)));
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32351_22_cv_quals, ((_ZN3edg9a_booleanE)1), __32325_75_dctl);
}
if (((int)(*__32324_76_ptr)) != 95) {

__32324_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32324_76_ptr, (&__32349_22_num), __32325_75_dctl));
if (__32349_22_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32325_75_dctl);
goto __32404_1_end_of_routine;
} else  {
__32349_22_num += 2L;
}
}
__32324_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32324_76_ptr, __32325_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"param#"), __32325_75_dctl);
if (__32349_31_level == (-1L)) {
snprintf((__32350_22_buffer), 51ULL, ((const char *)"%ld"), __32349_22_num);
} else  {



snprintf((__32350_22_buffer), 51ULL, ((const char *)"%ld[up %ld level%s]"), __32349_22_num, __32349_31_level, ((__32349_31_level > 1L) ? ((const char *)("s")) : ((const char *)(""))));

}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__32350_22_buffer)), __32325_75_dctl);
}
__32404_1_end_of_routine:;
return __32324_76_ptr;
}
#line 5164
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323demangle_type_specifierEPKcbP22a_decode_control_block(
_ZN3edg12a_const_charE *__32444_61_ptr, 
_ZN3edg9a_booleanE __32445_60_parse_template_args, 
a_decode_control_block_ptr __32446_60_dctl)
#line 5192
{
auto _ZN3edg12a_const_charE *__32472_17_p; auto _ZN3edg12a_const_charE *__32472_27_s = ((const char *)"");
auto long __32473_16_num;
#line 5193
__32472_17_p = __32444_61_ptr;




if (!(((((int)((_ctype)[((unsigned char)((unsigned char)(*__32472_17_p)))])) & 2) && (((int)(*__32472_17_p)) != 114)) || ((((int)(*__32472_17_p)) == 68) && (!((((((((int)(__32472_17_p[1])) == 112) || (((int)(__32472_17_p[1])) == 114)) || (((int)(__32472_17_p[1])) == 84)) || (((int)(__32472_17_p[1])) 
#line 5198
== 116)) || (((int)(__32472_17_p[1])) == 89)) || (((int)(__32472_17_p[1])) == 121)))))) {
if (((int)(*__32472_17_p)) == 84) {

auto _ZN3edg12a_const_charE *__32480_21_tstart; __32480_21_tstart = __32472_17_p;
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__32472_17_p, __32446_60_dctl));
if ((((int)(*__32472_17_p)) == 73) && (__32445_60_parse_template_args)) {



_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__32480_21_tstart, subk_template_template_param, 0UL, ((_ZN3edg9a_booleanE)0), __32446_60_dctl);

__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__32472_17_p, __32446_60_dctl));
}
} else  { if ((((int)(*__32472_17_p)) == 68) && (((int)(__32472_17_p[1])) == 112)) {

__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__32472_17_p + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)1), __32446_60_dctl));

} else  { if ((((int)(*__32472_17_p)) == 68) && ((((int)(__32472_17_p[1])) == 116) || (((int)(__32472_17_p[1])) == 84)))
{




_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"decltype("), __32446_60_dctl);
if (((int)(__32472_17_p[1])) == 116) {
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32472_17_p + 2), __32446_60_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32446_60_dctl);
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32472_17_p + 2), __32446_60_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32446_60_dctl);
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32446_60_dctl);
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32472_17_p, __32446_60_dctl));
} else  { if ((((int)(*__32472_17_p)) == 68) && ((((int)(__32472_17_p[1])) == 121) || (((int)(__32472_17_p[1])) == 89)))
{
#line 5240
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"typeof("), __32446_60_dctl);
if (((int)(__32472_17_p[1])) == 121) {
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__32472_17_p + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32446_60_dctl));
} else  {
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32472_17_p + 2), __32446_60_dctl));
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32446_60_dctl);
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32472_17_p, __32446_60_dctl));
} else  { if ((((int)(*__32472_17_p)) == 68) && (((int)(__32472_17_p[1])) == 114)) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[:"), __32446_60_dctl);
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32472_17_p + 2), __32446_60_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)":]"), __32446_60_dctl);
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32472_17_p, __32446_60_dctl));
} else  {

auto a_func_block __32537_20_func_block;
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block(__32472_17_p, (&__32537_20_func_block), 0x3, __32446_60_dctl));
} } } } }
} else  {

switch ((int)(*(__32472_17_p++))) {
case 118:
__32472_27_s = ((const char *)"void");
goto __T801320496;
case 119:
__32472_27_s = ((const char *)"wchar_t");
goto __T801320496;
case 98:
__32472_27_s = ((const char *)"bool");
goto __T801320496;
case 99:
__32472_27_s = ((const char *)"char");
goto __T801320496;
case 97:
__32472_27_s = ((const char *)"signed char");
goto __T801320496;
case 104:
__32472_27_s = ((const char *)"unsigned char");
goto __T801320496;
case 115:
__32472_27_s = ((const char *)"short");
goto __T801320496;
case 116:
__32472_27_s = ((const char *)"unsigned short");
goto __T801320496;
case 105:
__32472_27_s = ((const char *)"int");
goto __T801320496;
case 106:
__32472_27_s = ((const char *)"unsigned int");
goto __T801320496;
case 108:
__32472_27_s = ((const char *)"long");
goto __T801320496;
case 109:
__32472_27_s = ((const char *)"unsigned long");
goto __T801320496;
case 120:
__32472_27_s = ((const char *)"long long");
goto __T801320496;
case 121:
__32472_27_s = ((const char *)"unsigned long long");
goto __T801320496;
case 110:
__32472_27_s = ((const char *)"__int128");
goto __T801320496;
case 111:
__32472_27_s = ((const char *)"unsigned __int128");
goto __T801320496;
case 102:
__32472_27_s = ((const char *)"float");
goto __T801320496;
case 100:
__32472_27_s = ((const char *)"double");
goto __T801320496;
case 101:

__32472_27_s = ((const char *)"long double");
goto __T801320496;
case 103:
__32472_27_s = ((const char *)"__float128");
goto __T801320496;
case 117:


__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__32472_17_p, ((_ZN3edg9a_booleanE)0), __32446_60_dctl));
if (((int)(*__32472_17_p)) == 73) {

__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__32472_17_p, __32446_60_dctl));
}
__32472_27_s = ((const char *)"");
goto __T801320496;
case 68:


switch ((int)(*(__32472_17_p++))) {
case 97:
__32472_27_s = ((const char *)"auto");
goto __T801359520;
case 99:
__32472_27_s = ((const char *)"decltype(auto)");
goto __T801359520;
case 70:




__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32472_17_p, (&__32473_16_num), __32446_60_dctl));
if ((((int)(*__32472_17_p)) == 98) && (__32473_16_num == 16L)) {
__32472_27_s = ((const char *)"std::bfloat16_t");
} else  { if (((int)(*__32472_17_p)) == 120) {
switch (__32473_16_num) {
case 32L: __32472_27_s = ((const char *)"_Float32x"); goto __T801369144;
case 64L: __32472_27_s = ((const char *)"_Float64x"); goto __T801369144;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32446_60_dctl);
goto __T801369144;
} __T801369144:;
} else  { if (((int)(*__32472_17_p)) == 95) {



switch (__32473_16_num) {
case 16L: __32472_27_s = ((const char *)"_Float16"); goto __T801375000;
case 32L: __32472_27_s = ((const char *)"_Float32"); goto __T801375000;
case 64L: __32472_27_s = ((const char *)"_Float64"); goto __T801375000;
case 128L: __32472_27_s = ((const char *)"_Float128"); goto __T801375000;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32446_60_dctl);
goto __T801375000;
} __T801375000:;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32446_60_dctl);
} } }
++__32472_17_p;
goto __T801359520;
case 104:
__32472_27_s = ((const char *)"__fp16");
goto __T801359520;
case 110:
__32472_27_s = ((const char *)"std::nullptr_t");
goto __T801359520;
case 78:

__32472_27_s = ((const char *)"__nullptr");
goto __T801359520;
case 117:
__32472_27_s = ((const char *)"char8_t");
goto __T801359520;
case 115:
__32472_27_s = ((const char *)"char16_t");
goto __T801359520;
case 105:
__32472_27_s = ((const char *)"char32_t");
goto __T801359520;
case 118:




{ auto _ZN3edg12a_const_charE *__32682_29_typep;
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32472_17_p, (&__32473_16_num), __32446_60_dctl));
if (((int)(*__32472_17_p)) != 95) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32446_60_dctl);
} else  {
__32472_17_p++;
__32682_29_typep = __32472_17_p;
__32472_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32472_17_p, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32446_60_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" __attribute((vector_size("), __32446_60_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block(__32473_16_num, __32446_60_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"*sizeof("), __32446_60_dctl);
(__32446_60_dctl->suppress_substitution_recording)++;
_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32682_29_typep, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32446_60_dctl);
(__32446_60_dctl->suppress_substitution_recording)--;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")))) "), __32446_60_dctl);
}
__32472_27_s = ((const char *)"");
}
goto __T801359520;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32446_60_dctl);
__32472_27_s = ((const char *)"");
} __T801359520:;
goto __T801320496;
case 122:

default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32446_60_dctl);
__32472_27_s = ((const char *)"");
} __T801320496:;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__32472_27_s, __32446_60_dctl);
}
return __32472_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324skip_extern_C_indicationEPKc( _ZN3edg12a_const_charE *__32718_61_ptr)
#line 5447
{
if (((int)(*__32718_61_ptr)) == 89) { __32718_61_ptr++; }
return __32718_61_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(
_ZN3edg12a_const_charE *__32733_60_ptr, 
a_cv_qualifier_set __32734_59_cv_quals, 
_ZN3edg9a_booleanE __32735_59_under_lhs_declarator, 
_ZN3edg9a_booleanE __32736_59_need_trailing_space, 
_ZN3edg9a_booleanE __32737_59_parse_template_args, 
a_decode_control_block_ptr __32738_59_dctl)
#line 5473
{
auto _ZN3edg12a_const_charE *__32753_23_p; auto _ZN3edg12a_const_charE *__32753_33_qualp; auto _ZN3edg12a_const_charE *__32753_45_unqualp;
auto char __32754_22_kind;
auto a_cv_qualifier_set __32755_22_local_cv_quals;
auto _ZN3edg9a_booleanE __32756_22_record_substitution = ((_ZN3edg9a_booleanE)1);
auto _ZN3edg9a_booleanE __32757_22_record_cv_qual_substitution = ((_ZN3edg9a_booleanE)1);
#line 5474
__32753_23_p = __32733_60_ptr; __32753_33_qualp = __32753_23_p;
#line 5481
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__32753_23_p, (&__32755_22_local_cv_quals)));
__32734_59_cv_quals |= __32755_22_local_cv_quals;
__32753_45_unqualp = __32753_23_p;
__32754_22_kind = (*__32753_23_p);
if ((((int)__32754_22_kind) == 83) && (((int)(__32753_23_p[1])) != 116))

{

__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__32753_23_p, 1, __32734_59_cv_quals, __32735_59_under_lhs_declarator, __32736_59_need_trailing_space, ((_ZN3edg12a_const_charE **)0), ((_ZN3edg12a_const_charE **)0), __32738_59_dctl));
#line 5495
__32756_22_record_substitution = ((_ZN3edg9a_booleanE)0);
if (((int)(*__32753_23_p)) == 73) {

__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__32753_23_p, __32738_59_dctl));
__32756_22_record_substitution = ((_ZN3edg9a_booleanE)1);
}
} else  { if (((((((int)__32754_22_kind) == 80) || (((int)__32754_22_kind) == 82)) || (((int)__32754_22_kind) == 79)) || (((int)__32754_22_kind) == 67)) || ((((int)__32754_22_kind) == 85) && (!(_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"U8__vector"), __32753_23_p)))))
{
auto _ZN3edg12a_const_charE *__32782_19_vendor_ext = ((_ZN3edg12a_const_charE *)0);
auto char *__32783_19_vendor_ext_buffer = ((char *)0);
auto _ZN3edg9a_booleanE __32784_18_need_space = ((_ZN3edg9a_booleanE)1);
#line 5514
__32753_23_p++;
if (((int)__32754_22_kind) == 85) {
#line 5522
auto long __32801_12_num;
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32753_23_p, (&__32801_12_num), __32738_59_dctl));
if ((__32801_12_num == 8L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__handle"), __32753_23_p))) {
__32782_19_vendor_ext = ((const char *)"^");
} else  { if ((__32801_12_num == 8L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__trkref"), __32753_23_p))) {
__32782_19_vendor_ext = ((const char *)"%");
} else  { if ((__32801_12_num == 8L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__vector"), __32753_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__attribute__((vector_size(\?))) "), __32738_59_dctl);
__32784_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32801_12_num == 14L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__interior_ptr"), __32753_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"interior_ptr<"), __32738_59_dctl);
__32782_19_vendor_ext = ((const char *)">");
__32784_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32801_12_num == 9L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__pin_ptr"), __32753_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"pin_ptr<"), __32738_59_dctl);
__32782_19_vendor_ext = ((const char *)">");
__32784_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32801_12_num == 3L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"eut"), __32753_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__underlying_type("), __32738_59_dctl);
__32782_19_vendor_ext = ((const char *)")");
__32784_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32801_12_num == 17L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"pass_object_size"), __32753_23_p))) {

} else  {


if (__32801_12_num >= ((long)(strlen(__32753_23_p)))) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32738_59_dctl);
goto __32840_1_no_increment;
} else  {
__32783_19_vendor_ext_buffer = ((char *)(malloc((((_ZN3edg11true_size_tE)__32801_12_num) + 1ULL))));
memcpy(((void *)__32783_19_vendor_ext_buffer), ((const void *)__32753_23_p), ((size_t)__32801_12_num));
(__32783_19_vendor_ext_buffer[__32801_12_num]) = ((char)0);
__32782_19_vendor_ext = ((_ZN3edg12a_const_charE *)__32783_19_vendor_ext_buffer);
}
} } } } } } }

__32753_23_p += __32801_12_num;
__32840_1_no_increment:; ;
}
if (((int)__32754_22_kind) == 67) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"_Complex "), __32738_59_dctl);
}
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32753_23_p, 0, ((_ZN3edg9a_booleanE)1), __32784_18_need_space, __32737_59_parse_template_args, __32738_59_dctl));

if (((int)__32754_22_kind) == 80) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)42), __32738_59_dctl);
} else  { if (((int)__32754_22_kind) == 82) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)38), __32738_59_dctl);
} else  { if (((int)__32754_22_kind) == 79) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"&&"), __32738_59_dctl);
} else  { if (__32782_19_vendor_ext != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__32782_19_vendor_ext, __32738_59_dctl);
if (__32783_19_vendor_ext_buffer != ((char *)0)) {
free(((void *)__32783_19_vendor_ext_buffer));
}
} } } }

_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32734_59_cv_quals, ((_ZN3edg9a_booleanE)1), __32738_59_dctl);
} else  { if (((int)__32754_22_kind) == 77) {

auto _ZN3edg12a_const_charE *__32863_19_classp; __32863_19_classp = (__32753_23_p + 1);


(__32738_59_dctl->suppress_id_output)++;
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32863_19_classp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32738_59_dctl));
(__32738_59_dctl->suppress_id_output)--;
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32753_23_p, 0, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)1), __32737_59_parse_template_args, __32738_59_dctl));



(__32738_59_dctl->suppress_substitution_recording)++;
_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32863_19_classp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32738_59_dctl);
(__32738_59_dctl->suppress_substitution_recording)--;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::*"), __32738_59_dctl);

_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32734_59_cv_quals, ((_ZN3edg9a_booleanE)1), __32738_59_dctl);
} else  { if ((((int)__32754_22_kind) == 70) || ((((int)__32754_22_kind) == 68) && ((((int)(__32753_23_p[1])) == 111) || (((int)(__32753_23_p[1])) == 79))))

{
auto a_ref_qualifier __32882_21_dummy;




if (((int)__32754_22_kind) == 68) {

switch ((int)(__32753_23_p[1])) {
case 111:
__32753_23_p += 2;
goto __T801586800;
case 79:
(__32738_59_dctl->suppress_id_output)++;
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32753_23_p + 2), __32738_59_dctl));
(__32738_59_dctl->suppress_id_output)--;
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32753_23_p, __32738_59_dctl));
goto __T801586800;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32738_59_dctl);
goto __T801586800;
} __T801586800:;
}
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324skip_extern_C_indicationEPKc((__32753_23_p + 1)));

__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32753_23_p, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)1), __32737_59_parse_template_args, __32738_59_dctl));




__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(__32753_23_p, ((_ZN3edg9a_booleanE)1), 0, __32738_59_dctl));


__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi(__32753_23_p, (&__32882_21_dummy)));
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32753_23_p, __32738_59_dctl));


if (__32735_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32738_59_dctl); }



__32757_22_record_cv_qual_substitution = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)__32754_22_kind) == 65) {




__32753_23_p++;
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__32753_23_p)))])) & 4)) {
if (((int)(*__32753_23_p)) != 95) {



(__32738_59_dctl->suppress_id_output)++;
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__32753_23_p, __32738_59_dctl));
(__32738_59_dctl->suppress_id_output)--;
}
} else  {


while (((int)((_ctype)[((unsigned char)((unsigned char)(*__32753_23_p)))])) & 4) { __32753_23_p++; }
}
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32753_23_p, __32738_59_dctl));

__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32753_23_p, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)1), __32737_59_parse_template_args, __32738_59_dctl));




if (__32735_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32738_59_dctl); }
} else  {

_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32734_59_cv_quals, ((_ZN3edg9a_booleanE)1), __32738_59_dctl);
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d330demangle_vector_size_qualifierEPKcP22a_decode_control_block(__32753_23_p, __32738_59_dctl));
__32753_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_type_specifierEPKcbP22a_decode_control_block(__32753_23_p, __32737_59_parse_template_args, __32738_59_dctl));
if (__32736_59_need_trailing_space) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32738_59_dctl); }
if (!(((!(((((int)((_ctype)[((unsigned char)((unsigned char)(*__32753_45_unqualp)))])) & 2) && (((int)(*__32753_45_unqualp)) != 114)) || ((((int)(*__32753_45_unqualp)) == 68) && (!((((((((int)(__32753_45_unqualp[1])) == 112) || (((int)(__32753_45_unqualp[1])) == 114)) || (((int)(
#line 5678
__32753_45_unqualp[1])) == 84)) || (((int)(__32753_45_unqualp[1])) == 116)) || (((int)(__32753_45_unqualp[1])) == 89)) || (((int)(__32753_45_unqualp[1])) == 121)))))) || (((int)(*__32753_45_unqualp)) == 117)) || ((((int)(*__32753_45_unqualp)) == 68) && (((int)(__32753_45_unqualp[1])) == 118)))) {

__32756_22_record_substitution = ((_ZN3edg9a_booleanE)0);
}
} } } } }
if (__32756_22_record_substitution) {


_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__32753_45_unqualp, subk_type, 0UL, __32737_59_parse_template_args, __32738_59_dctl);

}
if ((__32753_33_qualp != __32753_45_unqualp) && (__32757_22_record_cv_qual_substitution)) {


_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__32753_33_qualp, subk_type, 0UL, __32737_59_parse_template_args, __32738_59_dctl);

}
return __32753_23_p;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(
_ZN3edg12a_const_charE *__32979_60_ptr, 
a_cv_qualifier_set __32980_59_cv_quals, 
_ZN3edg9a_booleanE __32981_59_under_lhs_declarator, 
a_decode_control_block_ptr __32982_59_dctl)
#line 5716
{
auto _ZN3edg12a_const_charE *__32996_23_p;
auto char __32997_22_kind;
auto a_cv_qualifier_set __32998_22_local_cv_quals;
#line 5717
__32996_23_p = __32979_60_ptr;




__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__32996_23_p, (&__32998_22_local_cv_quals)));
__32980_59_cv_quals |= __32998_22_local_cv_quals;
__32997_22_kind = (*__32996_23_p);
if ((((int)__32997_22_kind) == 83) && (((int)(__32996_23_p[1])) != 116))

{

__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__32996_23_p, 2, __32980_59_cv_quals, __32981_59_under_lhs_declarator, ((_ZN3edg9a_booleanE)0), ((_ZN3edg12a_const_charE **)0), ((_ZN3edg12a_const_charE **)0), __32982_59_dctl));
#line 5737
} else  { if (((((((int)__32997_22_kind) == 80) || (((int)__32997_22_kind) == 82)) || (((int)__32997_22_kind) == 79)) || (((int)__32997_22_kind) == 67)) || (((int)__32997_22_kind) == 85))
{
#line 5747
__32996_23_p++;
if (((int)__32997_22_kind) == 85) {



if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"17pass_object_size"), __32996_23_p)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__attribute((pass_object_size("), __32982_59_dctl);

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((__32996_23_p[18]), __32982_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")))"), __32982_59_dctl);
} else  {
(__32982_59_dctl->suppress_id_output)++;
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__32996_23_p, ((_ZN3edg9a_booleanE)0), __32982_59_dctl));
(__32982_59_dctl->suppress_id_output)--;
}
}
_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__32996_23_p, 0, ((_ZN3edg9a_booleanE)1), __32982_59_dctl);

} else  { if (((int)__32997_22_kind) == 77) {


(__32982_59_dctl->suppress_id_output)++;
(__32982_59_dctl->suppress_substitution_recording)++;
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__32996_23_p + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32982_59_dctl));
(__32982_59_dctl->suppress_substitution_recording)--;
(__32982_59_dctl->suppress_id_output)--;
_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__32996_23_p, 0, ((_ZN3edg9a_booleanE)1), __32982_59_dctl);

} else  { if ((((int)__32997_22_kind) == 70) || ((((int)__32997_22_kind) == 68) && (((((int)(__32996_23_p[1])) == 111) || (((int)(__32996_23_p[1])) == 79)) || (((int)(__32996_23_p[1])) == 119))))

{
auto _ZN3edg12a_const_charE *__33057_19_returnt; auto _ZN3edg12a_const_charE *__33057_29_exception_spec = ((_ZN3edg12a_const_charE *)0);
auto _ZN3edg12a_const_charE *__33058_19_save_exception_expr = ((_ZN3edg12a_const_charE *)0);
auto a_ref_qualifier __33059_21_ref_qual;




if (((int)__32997_22_kind) == 68) {

switch ((int)(__32996_23_p[1])) {
case 111:
__33057_29_exception_spec = ((const char *)" noexcept");
__32996_23_p += 2;
goto __T801690880;
case 79:


__33058_19_save_exception_expr = (__32996_23_p + 2);
(__32982_59_dctl->suppress_id_output)++;
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__33058_19_save_exception_expr, __32982_59_dctl));
(__32982_59_dctl->suppress_id_output)--;
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32996_23_p, __32982_59_dctl));
goto __T801690880;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32982_59_dctl);
goto __T801690880;
} __T801690880:;
}


if (__32981_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32982_59_dctl); }
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324skip_extern_C_indicationEPKc((__32996_23_p + 1)));


__33057_19_returnt = __32996_23_p;
(__32982_59_dctl->suppress_substitution_recording)++;
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(__32996_23_p, ((_ZN3edg9a_booleanE)0), 0x2, __32982_59_dctl));

(__32982_59_dctl->suppress_substitution_recording)--;

__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi(__32996_23_p, (&__33059_21_ref_qual)));
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32996_23_p, __32982_59_dctl));
#line 5826
if (__32980_59_cv_quals != 0) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32982_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32980_59_cv_quals, ((_ZN3edg9a_booleanE)0), __32982_59_dctl);
}
if (__33059_21_ref_qual != 0) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32982_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_ref_qualifierEiP22a_decode_control_block(__33059_21_ref_qual, __32982_59_dctl);
}

_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__33057_19_returnt, 0, ((_ZN3edg9a_booleanE)0), __32982_59_dctl);

if (__33057_29_exception_spec != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__33057_29_exception_spec, __32982_59_dctl);
} else  { if (__33058_19_save_exception_expr != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" noexcept("), __32982_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__33058_19_save_exception_expr, __32982_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32982_59_dctl);
} }
} else  { if (((int)__32997_22_kind) == 65) {
#line 5852
if (__32981_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32982_59_dctl); }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __32982_59_dctl);
__32996_23_p++;
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__32996_23_p)))])) & 4)) {
if (((int)(*__32996_23_p)) != 95) {


(__32982_59_dctl->suppress_substitution_recording)++;
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__32996_23_p, __32982_59_dctl));
(__32982_59_dctl->suppress_substitution_recording)--;
}
} else  {


while (((int)((_ctype)[((unsigned char)((unsigned char)(*__32996_23_p)))])) & 4) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*(__32996_23_p++)), __32982_59_dctl); }
}
__32996_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32996_23_p, __32982_59_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __32982_59_dctl);

_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__32996_23_p, 0, ((_ZN3edg9a_booleanE)0), __32982_59_dctl);

} else  {


} } } } } 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(
_ZN3edg12a_const_charE *__33160_61_ptr, 
_ZN3edg9a_booleanE __33161_60_parse_template_args, 
_ZN3edg9a_booleanE __33162_60_is_pack_expansion, 
a_decode_control_block_ptr __33163_60_dctl)
#line 5911
{
auto _ZN3edg12a_const_charE *__33191_17_p;


__33191_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__33160_61_ptr, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), __33161_60_parse_template_args, __33163_60_dctl));


if (__33162_60_is_pack_expansion) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __33163_60_dctl);
}

_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__33160_61_ptr, 0, ((_ZN3edg9a_booleanE)0), __33163_60_dctl);

return __33191_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(
_ZN3edg12a_const_charE *__33211_67_ptr, 
int *__33212_67_num_operands, 
int *__33213_67_length, 
_ZN3edg12a_const_charE **__33214_68_close_str, 
a_decode_control_block_ptr __33215_66_dctl)
#line 5950
{
auto _ZN3edg12a_const_charE *__33230_17_str = ((_ZN3edg12a_const_charE *)0);

(*__33212_67_num_operands) = 2;
(*__33214_68_close_str) = ((const char *)"");
(*__33213_67_length) = 0;
if (((int)(*__33211_67_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33215_66_dctl);
} else  {
auto char __33238_10_ch2; __33238_10_ch2 = (__33211_67_ptr[1]);
switch ((int)(*__33211_67_ptr)) {
case 97:
if (((int)__33238_10_ch2) == 97) {
__33230_17_str = ((const char *)"&&");
} else  { if (((int)__33238_10_ch2) == 100) {
__33230_17_str = ((const char *)"&");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 110) {
__33230_17_str = ((const char *)"&");
} else  { if (((int)__33238_10_ch2) == 78) {
__33230_17_str = ((const char *)"&=");
} else  { if (((int)__33238_10_ch2) == 83) {
__33230_17_str = ((const char *)"=");
} else  { if (((int)__33238_10_ch2) == 116) {

__33230_17_str = ((const char *)"alignof(");
(*__33212_67_num_operands) = 0;
(*__33214_68_close_str) = ((const char *)")");
} else  { if (((int)__33238_10_ch2) == 119) {

__33230_17_str = ((const char *)"co_await");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 122) {

__33230_17_str = ((const char *)"alignof(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 1;
} } } } } } } }
goto __T801769520;
case 99:
if (((int)__33238_10_ch2) == 99) {
__33230_17_str = ((const char *)"const_cast");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 108) {
__33230_17_str = ((const char *)"()");
(*__33212_67_num_operands) = 0;
} else  { if (((int)__33238_10_ch2) == 109) {
__33230_17_str = ((const char *)",");
} else  { if (((int)__33238_10_ch2) == 111) {
__33230_17_str = ((const char *)"~");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 118) {
__33230_17_str = ((const char *)"cast");
(*__33212_67_num_operands) = 1;
} } } } }
goto __T801769520;
case 100:
if (((int)__33238_10_ch2) == 97) {
__33230_17_str = ((const char *)"delete[] ");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 99) {
__33230_17_str = ((const char *)"dynamic_cast");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 101) {
__33230_17_str = ((const char *)"*");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 108) {
__33230_17_str = ((const char *)"delete ");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 115) {
__33230_17_str = ((const char *)".*");
} else  { if (((int)__33238_10_ch2) == 118) {
__33230_17_str = ((const char *)"/");
} else  { if (((int)__33238_10_ch2) == 86) {
__33230_17_str = ((const char *)"/=");
} } } } } } }
goto __T801769520;
case 101:
if (((int)__33238_10_ch2) == 111) {
__33230_17_str = ((const char *)"^");
} else  { if (((int)__33238_10_ch2) == 79) {
__33230_17_str = ((const char *)"^=");
} else  { if (((int)__33238_10_ch2) == 113) {
__33230_17_str = ((const char *)"==");
} } }
goto __T801769520;
case 103:
if (((int)__33238_10_ch2) == 101) {
__33230_17_str = ((const char *)">=");
} else  { if (((int)__33238_10_ch2) == 116) {
__33230_17_str = ((const char *)">");
} }
goto __T801769520;
case 105:
if (((int)__33238_10_ch2) == 120) {
__33230_17_str = ((const char *)"[");
(*__33214_68_close_str) = ((const char *)"]");
}
goto __T801769520;
case 108:
if (((int)__33238_10_ch2) == 101) {
__33230_17_str = ((const char *)"<=");
} else  { if (((int)__33238_10_ch2) == 105) {




auto long __33336_25_ud_suffix_len;
auto _ZN3edg12a_const_charE *__33337_26_ud_suffix_ptr;
__33337_26_ud_suffix_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__33211_67_ptr + 2), (&__33336_25_ud_suffix_len), __33215_66_dctl));




(*__33212_67_num_operands) = 0;
__33230_17_str = ((_ZN3edg12a_const_charE *)0);
if (!(__33215_66_dctl->err_in_id)) {
if (__33336_25_ud_suffix_len <= 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33215_66_dctl);
} else  {
if (ud_suffix_buffer == ((char *)0)) {
ud_suffix_buffer_length = 128UL;
ud_suffix_buffer = ((char *)(malloc(((_ZN3edg11true_size_tE)ud_suffix_buffer_length))));

} else  { if (((((unsigned long)__33336_25_ud_suffix_len) + 3UL) + 1UL) > ud_suffix_buffer_length)
{
ud_suffix_buffer_length = ((unsigned long)((__33336_25_ud_suffix_len + 3L) + 1L));
ud_suffix_buffer = ((char *)(realloc(((void *)ud_suffix_buffer), ((_ZN3edg11true_size_tE)ud_suffix_buffer_length))));

} }
if (ud_suffix_buffer != ((char *)0)) {
if (((long)(strlen(__33337_26_ud_suffix_ptr))) < __33336_25_ud_suffix_len) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33215_66_dctl);
} else  {
strcpy(ud_suffix_buffer, ((const char *)"\"\""));
strncpy((ud_suffix_buffer + 2), __33337_26_ud_suffix_ptr, ((size_t)__33336_25_ud_suffix_len));
(ud_suffix_buffer[(2L + __33336_25_ud_suffix_len)]) = ((char)0);
__33230_17_str = ((_ZN3edg12a_const_charE *)ud_suffix_buffer);
(*__33213_67_length) = ((int)((__33337_26_ud_suffix_ptr + __33336_25_ud_suffix_len) - __33211_67_ptr));
}
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33215_66_dctl);
}
}
}
} else  { if (((int)__33238_10_ch2) == 115) {
__33230_17_str = ((const char *)"<<");
} else  { if (((int)__33238_10_ch2) == 83) {
__33230_17_str = ((const char *)"<<=");
} else  { if (((int)__33238_10_ch2) == 116) {
__33230_17_str = ((const char *)"<");
} } } } }
goto __T801769520;
case 109:
if (((int)__33238_10_ch2) == 105) {
__33230_17_str = ((const char *)"-");
} else  { if (((int)__33238_10_ch2) == 73) {
__33230_17_str = ((const char *)"-=");
} else  { if (((int)__33238_10_ch2) == 108) {
__33230_17_str = ((const char *)"*");
} else  { if (((int)__33238_10_ch2) == 76) {
__33230_17_str = ((const char *)"*=");
} else  { if (((int)__33238_10_ch2) == 109) {
__33230_17_str = ((const char *)"--");
(*__33212_67_num_operands) = 1;
} } } } }
goto __T801769520;
case 110:
if (((int)__33238_10_ch2) == 97) {
__33230_17_str = ((const char *)"new[] ");
} else  { if (((int)__33238_10_ch2) == 101) {
__33230_17_str = ((const char *)"!=");
} else  { if (((int)__33238_10_ch2) == 103) {
__33230_17_str = ((const char *)"-");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 116) {
__33230_17_str = ((const char *)"!");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 119) {
__33230_17_str = ((const char *)"new ");
} else  { if (((int)__33238_10_ch2) == 120) {
__33230_17_str = ((const char *)"noexcept(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 1;
} } } } } }
goto __T801769520;
case 111:
if (((int)__33238_10_ch2) == 111) {
__33230_17_str = ((const char *)"||");
} else  { if (((int)__33238_10_ch2) == 114) {
__33230_17_str = ((const char *)"|");
} else  { if (((int)__33238_10_ch2) == 82) {
__33230_17_str = ((const char *)"|=");
} } }
goto __T801769520;
case 112:
if (((int)__33238_10_ch2) == 108) {
__33230_17_str = ((const char *)"+");
} else  { if (((int)__33238_10_ch2) == 76) {
__33230_17_str = ((const char *)"+=");
} else  { if (((int)__33238_10_ch2) == 109) {
__33230_17_str = ((const char *)"->*");
} else  { if (((int)__33238_10_ch2) == 112) {
__33230_17_str = ((const char *)"++");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 115) {
__33230_17_str = ((const char *)"+");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 116) {
__33230_17_str = ((const char *)"->");
} } } } } }
goto __T801769520;
case 113:
if (((int)__33238_10_ch2) == 117) {
__33230_17_str = ((const char *)"\?");
(*__33212_67_num_operands) = 3;
}
goto __T801769520;
case 114:
if (((int)__33238_10_ch2) == 99) {
__33230_17_str = ((const char *)"reinterpret_cast");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 109) {
__33230_17_str = ((const char *)"%");
} else  { if (((int)__33238_10_ch2) == 77) {
__33230_17_str = ((const char *)"%=");
} else  { if (((int)__33238_10_ch2) == 115) {
__33230_17_str = ((const char *)">>");
} else  { if (((int)__33238_10_ch2) == 83) {
__33230_17_str = ((const char *)">>=");
} } } } }
goto __T801769520;
case 115:
if (((int)__33238_10_ch2) == 99) {
__33230_17_str = ((const char *)"static_cast");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 115) {
__33230_17_str = ((const char *)"<=>");
} else  { if (((int)__33238_10_ch2) == 116) {

__33230_17_str = ((const char *)"sizeof(");
(*__33212_67_num_operands) = 0;
(*__33214_68_close_str) = ((const char *)")");
} else  { if (((int)__33238_10_ch2) == 122) {

__33230_17_str = ((const char *)"sizeof(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 1;
} } } }
goto __T801769520;
case 116:
if (((int)__33238_10_ch2) == 101) {

__33230_17_str = ((const char *)"typeid(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 1;
} else  { if (((int)__33238_10_ch2) == 105) {

__33230_17_str = ((const char *)"typeid(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 0;
} else  { if (((int)__33238_10_ch2) == 114) {

__33230_17_str = ((const char *)"throw");
(*__33212_67_num_operands) = 0;
} else  { if (((int)__33238_10_ch2) == 119) {

__33230_17_str = ((const char *)"throw ");
(*__33212_67_num_operands) = 1;
} } } }
goto __T801769520;
case 118:

if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18alignofe"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"__alignof__(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 1;
(*__33213_67_length) = 11;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v17alignof"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"__alignof__(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 0;
(*__33213_67_length) = 10;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v19__uuidofe"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"__uuidof(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 1;
(*__33213_67_length) = 12;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18__uuidof"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"__uuidof(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 0;
(*__33213_67_length) = 11;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v17typeide"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"typeid(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 1;
(*__33213_67_length) = 10;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v16typeid"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"typeid(");
(*__33214_68_close_str) = ((const char *)")");
(*__33212_67_num_operands) = 0;
(*__33213_67_length) = 9;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v19clitypeid"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"::typeid");
(*__33212_67_num_operands) = 0;
(*__33213_67_length) = 12;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v23min"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"<\?");
(*__33213_67_length) = 6;
(*__33212_67_num_operands) = 2;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v23max"), __33211_67_ptr)) {

__33230_17_str = ((const char *)">\?");
(*__33213_67_length) = 6;
(*__33212_67_num_operands) = 2;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18__real__"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"__real(");
(*__33214_68_close_str) = ((const char *)")");
(*__33213_67_length) = 11;
(*__33212_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18__imag__"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"__imag(");
(*__33214_68_close_str) = ((const char *)")");
(*__33213_67_length) = 11;
(*__33212_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v19clihandle"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"%");
(*__33213_67_length) = 12;
(*__33212_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v112clisafe_cast"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"safe_cast");
(*__33213_67_length) = 16;
(*__33212_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v16splice"), __33211_67_ptr)) {

__33230_17_str = ((const char *)"[:");
(*__33214_68_close_str) = ((const char *)":]");
(*__33212_67_num_operands) = 1;
(*__33213_67_length) = 9;
} else  { if ((_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"9builtin"), (__33211_67_ptr + 2))) || (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"10builtin"), (__33211_67_ptr + 2))))
{
#line 6314
__33230_17_str = ((_ZN3edg12a_const_charE *)_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name);
(*__33212_67_num_operands) = (((int)(__33211_67_ptr[1])) - 48);
if (((int)(__33211_67_ptr[2])) == 57) {
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[18]) = (__33211_67_ptr[10]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[19]) = (__33211_67_ptr[11]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[20]) = ((char)0);
(*__33213_67_length) = 12;
} else  {
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[18]) = (__33211_67_ptr[11]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[19]) = (__33211_67_ptr[12]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[20]) = (__33211_67_ptr[13]);
(*__33213_67_length) = 14;
}
} else  { if (((_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"12clisubscript"), (__33211_67_ptr + 2))) && (((int)(__33211_67_ptr[1])) >= 48)) && (((int)(__33211_67_ptr[1])) <= 57))
{


__33230_17_str = ((const char *)"subscript");
(*__33213_67_length) = 16;
(*__33212_67_num_operands) = (((int)(__33211_67_ptr[1])) - 48);
} } } } } } } } } } } } } } } }
goto __T801769520;
default:
goto __T801769520;
} __T801769520:;
if ((*__33213_67_length) == 0) { (*__33213_67_length) = 2; }
}
return __33230_17_str;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(
_ZN3edg12a_const_charE *__33625_62_ptr, 
_ZN3edg9a_booleanE __33626_61_is_module_id, 
a_decode_control_block_ptr __33627_61_dctl)
#line 6363
{
auto long __33643_13_num;
auto _ZN3edg9a_booleanE __33644_13_output_chars = ((_ZN3edg9a_booleanE)1);

__33625_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__33625_62_ptr, (&__33643_13_num), __33627_61_dctl));
if (__33643_13_num <= 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33627_61_dctl);
} else  { if (__33626_61_is_module_id) {



__33625_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_module_idEPKcmS1_P22a_decode_control_block(__33625_62_ptr, ((unsigned long)__33643_13_num), ((_ZN3edg12a_const_charE *)0), __33627_61_dctl));
} else  { if ((__33643_13_num >= 9L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"_INTERNAL"), __33625_62_ptr))) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[local to "), __33627_61_dctl);
__33625_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_module_idEPKcmS1_P22a_decode_control_block((__33625_62_ptr + 9), (((unsigned long)__33643_13_num) - 9UL), __33625_62_ptr, __33627_61_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __33627_61_dctl);
} else  {
if ((__33643_13_num >= 11L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"_GLOBAL__N_"), __33625_62_ptr))) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"<unnamed>"), __33627_61_dctl);
__33644_13_output_chars = ((_ZN3edg9a_booleanE)0);
}
for (; __33643_13_num > 0L; (__33625_62_ptr++) , (__33643_13_num--)) {
if (((int)(*__33625_62_ptr)) == 0) {


_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33627_61_dctl);
goto __T802042624;
} else  { if (((!(((int)((_ctype)[((unsigned char)((unsigned char)(*__33625_62_ptr)))])) & 0x7)) && (((int)(*__33625_62_ptr)) != 95)) && (((int)(*__33625_62_ptr)) != 36)) {



if (__33644_13_output_chars) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33627_61_dctl);
goto __T802042624;
}
} else  { if (__33644_13_output_chars) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__33625_62_ptr), __33627_61_dctl);
} } }
} __T802042624:;
} } }
return __33625_62_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319get_instance_numberEPKcPmP22a_decode_control_block( _ZN3edg12a_const_charE *__33692_70_p, 
unsigned long *__33693_70_instance, 
a_decode_control_block_ptr __33694_69_dctl)
#line 6421
{
(*__33693_70_instance) = 1UL;
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__33692_70_p)))])) & 4) {
auto long __33703_10_num;
__33692_70_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__33692_70_p, (&__33703_10_num), __33694_69_dctl));
if (__33703_10_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33694_69_dctl);
} else  {
(*__33693_70_instance) = ((unsigned long)(__33703_10_num + 2L));
}
}
if (((int)(*__33692_70_p)) == 95) {
__33692_70_p += 1;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33694_69_dctl);
}
return __33692_70_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_unnamed_typeEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__33720_72_ptr, 
a_decode_control_block_ptr __33721_71_dctl)
#line 6455
{
auto unsigned long __33735_17_instance;

if ((((int)(*__33720_72_ptr)) == 85) && (((int)(__33720_72_ptr[1])) == 116)) {


__33720_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319get_instance_numberEPKcPmP22a_decode_control_block((__33720_72_ptr + 2), (&__33735_17_instance), __33721_71_dctl));
if (!(__33721_71_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[unnamed type (instance "), __33721_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d315write_id_numberEmP22a_decode_control_block(__33735_17_instance, __33721_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")]"), __33721_71_dctl);
}
} else  { if ((((int)(*__33720_72_ptr)) == 85) && (((int)(__33720_72_ptr[1])) == 108)) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[lambda"), __33721_71_dctl);
__33720_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block((__33720_72_ptr + 2), ((_ZN3edg9a_booleanE)1), 0x2, __33721_71_dctl));

if (((int)(*__33720_72_ptr)) == 69) {
__33720_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319get_instance_numberEPKcPmP22a_decode_control_block((__33720_72_ptr + 1), (&__33735_17_instance), __33721_71_dctl));
if (!(__33721_71_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __33721_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d315write_id_numberEmP22a_decode_control_block(__33735_17_instance, __33721_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")"), __33721_71_dctl);
}
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33721_71_dctl);
}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __33721_71_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33721_71_dctl);
} }
return __33720_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d326demangle_abi_tag_attributeEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__33772_76_ptr, 
a_decode_control_block_ptr __33773_75_dctl)
#line 6506
{
auto long __33786_8_num;

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[abi:"), __33773_75_dctl);
while (((int)(*__33772_76_ptr)) == 66) {
__33772_76_ptr++;
__33772_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__33772_76_ptr, (&__33786_8_num), __33773_75_dctl));
if (__33786_8_num <= 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33773_75_dctl);
goto __T802100544;
} else  {
for (; __33786_8_num > 0L; (__33772_76_ptr++) , (__33786_8_num--)) {
if (((int)(*__33772_76_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33773_75_dctl);
goto __T802104232;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__33772_76_ptr), __33773_75_dctl);
}
} __T802104232:;
if (((int)(*__33772_76_ptr)) == 66) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)44), __33773_75_dctl);
}
}
} __T802100544:;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __33773_75_dctl);
return __33772_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(
_ZN3edg12a_const_charE *__33816_62_ptr, 
_ZN3edg9a_booleanE *__33817_62_is_no_return_name, 
a_decode_control_block_ptr __33818_61_dctl)
#line 6558
{
if (__33817_62_is_no_return_name != ((_ZN3edg9a_booleanE *)0)) { (*__33817_62_is_no_return_name) = ((_ZN3edg9a_booleanE)0); }
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__33816_62_ptr)))])) & 4) {


__33816_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__33816_62_ptr, ((_ZN3edg9a_booleanE)0), __33818_61_dctl));
} else  { if ((((int)(*__33816_62_ptr)) == 85) && ((((int)(__33816_62_ptr[1])) == 116) || (((int)(__33816_62_ptr[1])) == 108)))

{

__33816_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_unnamed_typeEPKcP22a_decode_control_block(__33816_62_ptr, __33818_61_dctl));
} else  { if ((((int)(*__33816_62_ptr)) == 68) && (((int)(__33816_62_ptr[1])) == 67)) {

__33816_62_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[structured binding for "), __33818_61_dctl);
while ((((int)(*__33816_62_ptr)) != 69) && (((int)(*__33816_62_ptr)) != 0)) {
__33816_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__33816_62_ptr, ((_ZN3edg9a_booleanE)0), __33818_61_dctl));
if ((((int)(*__33816_62_ptr)) != 69) && (((int)(*__33816_62_ptr)) != 0)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)44), __33818_61_dctl); }
}
if (((int)(*__33816_62_ptr)) != 69) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33818_61_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __33818_61_dctl);
__33816_62_ptr++;
}
} else  {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __33818_61_dctl);
if ((((int)(*__33816_62_ptr)) == 99) && (((int)(__33816_62_ptr[1])) == 118)) {

if (__33817_62_is_no_return_name != ((_ZN3edg9a_booleanE *)0)) { (*__33817_62_is_no_return_name) = ((_ZN3edg9a_booleanE)1); }
#line 6603
__33816_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__33816_62_ptr + 2), (__33818_61_dctl->parse_template_args_after_conversion_operator), ((_ZN3edg9a_booleanE)0), __33818_61_dctl));



(__33818_61_dctl->contains_conversion_operator) = ((_ZN3edg9a_booleanE)1);
} else  {

auto int __33889_20_num_operands; auto int __33889_34_length;
auto _ZN3edg12a_const_charE *__33890_21_op_str; auto _ZN3edg12a_const_charE *__33890_30_close_str;
__33890_21_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__33816_62_ptr, (&__33889_20_num_operands), (&__33889_34_length), (&__33890_30_close_str), __33818_61_dctl));

if (__33890_21_op_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33818_61_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__33890_21_op_str, __33818_61_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__33890_30_close_str, __33818_61_dctl);
__33816_62_ptr += __33889_34_length;
}
}
} } }
if (((int)(*__33816_62_ptr)) == 66) {


__33816_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_abi_tag_attributeEPKcP22a_decode_control_block(__33816_62_ptr, __33818_61_dctl));
}
return __33816_62_ptr;
}


static unsigned char _ZN29_INTERNAL_8_decode_c_f78890d313get_hex_digitEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__33911_64_ptr, 
a_decode_control_block_ptr __33912_63_dctl)




{
auto unsigned char __33918_17_value;
auto unsigned char __33919_17_ch; __33919_17_ch = ((unsigned char)(__33911_64_ptr[0]));

if (((int)((_ctype)[((unsigned char)__33919_17_ch)])) & 4) {
__33918_17_value = ((unsigned char)(((int)__33919_17_ch) - 48));
} else  { if ((((int)((_ctype)[((unsigned char)__33919_17_ch)])) & 128) && (((int)((_ctype)[((unsigned char)__33919_17_ch)])) & 2)) {
__33918_17_value = ((unsigned char)((((int)__33919_17_ch) - 97) + 10));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33912_63_dctl);
__33918_17_value = ((unsigned char)0U);
} }
return __33918_17_value;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__33933_72_ptr, 
a_decode_control_block_ptr __33934_71_dctl)
#line 6662
{
auto _ZN3edg8sizeof_tE __33942_12_i; auto _ZN3edg8sizeof_tE __33942_15_length;
auto char *__33943_13_p;
#line 6671
auto union _ZZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_blockEUt_ __33950_5_x;



(__33950_5_x.ld) = (0.0L);
#line 6681
__33942_15_length = 0ULL;
__33943_13_p = ((char *)__33933_72_ptr);
while (((((int)(*__33943_13_p)) != 69) && (((int)(*__33943_13_p)) != 95)) && (((int)(*__33943_13_p)) != 0)) {
__33942_15_length++;
__33943_13_p++;
}
if ((__33942_15_length % 2ULL) != 0ULL) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33934_71_dctl);
__33942_15_length -= 1ULL;
}

__33942_15_length /= 2ULL;
if (__33942_15_length > 8ULL) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33934_71_dctl);
__33942_15_length = 8ULL;
}

for (__33942_12_i = 0ULL; __33942_12_i < __33942_15_length; (__33942_12_i++) , (__33933_72_ptr += 2)) {
auto unsigned char __33980_19_byte; __33980_19_byte = (_ZN29_INTERNAL_8_decode_c_f78890d313get_hex_digitEPKcP22a_decode_control_block(__33933_72_ptr, __33934_71_dctl));
if (__33934_71_dctl->err_in_id) { goto __T802185664; }
__33980_19_byte = ((unsigned char)((((int)__33980_19_byte) << 4) | ((int)(_ZN29_INTERNAL_8_decode_c_f78890d313get_hex_digitEPKcP22a_decode_control_block((__33933_72_ptr + 1), __33934_71_dctl)))));
if (__33934_71_dctl->err_in_id) { goto __T802185664; }
if (host_little_endian) {
(((unsigned char *)(&__33950_5_x))[((__33942_15_length - 1ULL) - __33942_12_i)]) = __33980_19_byte;
} else  {
(((unsigned char *)(&__33950_5_x))[__33942_12_i]) = __33980_19_byte;
}
} __T802185664:;
if (!(__33934_71_dctl->err_in_id)) {

auto char __33992_10_str[60];
auto int __33993_10_ndig;
if (__33942_12_i <= 4ULL) {

__33993_10_ndig = 6;



snprintf((__33992_10_str), 60ULL, ((const char *)"%.*g"), __33993_10_ndig, ((double)(__33950_5_x.f)));

} else  { if (__33942_12_i > 8ULL) {

__33993_10_ndig = 15;



snprintf((__33992_10_str), 60ULL, ((const char *)"%.*Lg"), __33993_10_ndig, (__33950_5_x.ld));

} else  {

__33993_10_ndig = 15;



snprintf((__33992_10_str), 60ULL, ((const char *)"%.*g"), __33993_10_ndig, (__33950_5_x.d));
} }



__33943_13_p = (((__33992_10_str) + (strlen(((const char *)(__33992_10_str))))) - 1);
if ((((strchr(((const char *)(__33992_10_str)), 46)) == ((char *)0)) && ((strchr(((const char *)(__33992_10_str)), 101)) == ((char *)0))) && (((int)((_ctype)[((unsigned char)((unsigned char)(*__33943_13_p)))])) & 4))

{
__33943_13_p++;
(*(__33943_13_p++)) = ((char)46);
(*(__33943_13_p++)) = ((char)48);
(*(__33943_13_p++)) = ((char)0);
}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__33992_10_str)), __33934_71_dctl);
}
return __33933_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_float_literalEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34036_73_ptr, 
a_decode_control_block_ptr __34037_72_dctl)
#line 6769
{

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34037_72_dctl);
__34036_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34036_73_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34037_72_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34037_72_dctl);
if (!(__34037_72_dctl->err_in_id)) {
__34036_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block(__34036_73_ptr, __34037_72_dctl));
if (!(__34037_72_dctl->err_in_id)) {
__34036_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34036_73_ptr, __34037_72_dctl));
}
}
return __34036_73_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_complex_literalEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34063_75_ptr, 
a_decode_control_block_ptr __34064_74_dctl)
#line 6796
{

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34064_74_dctl);
__34063_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34063_75_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34064_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")("), __34064_74_dctl);

if (!(__34064_74_dctl->err_in_id)) {
__34063_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block(__34063_75_ptr, __34064_74_dctl));
if (!(__34064_74_dctl->err_in_id)) {
__34063_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34063_75_ptr, __34064_74_dctl));
if (!(__34064_74_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)43), __34064_74_dctl);
__34063_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block(__34063_75_ptr, __34064_74_dctl));
if (!(__34064_74_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"i)"), __34064_74_dctl);
if (!(__34064_74_dctl->err_in_id)) {
__34063_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34063_75_ptr, __34064_74_dctl));
}
}
}
}
}
return __34063_75_ptr;
}
#line 6827
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_expr_primaryEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34106_72_ptr, 
a_decode_control_block_ptr __34107_71_dctl)
#line 6843
{
auto _ZN3edg12a_const_charE *__34123_17_sub = ((_ZN3edg12a_const_charE *)0);

if (((int)(__34106_72_ptr[1])) == 83) {



(__34107_71_dctl->suppress_id_output)++;
_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block((__34106_72_ptr + 1), 0, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), ((_ZN3edg12a_const_charE **)0), (&__34123_17_sub), __34107_71_dctl);
#line 6857
(__34107_71_dctl->suppress_id_output)--;
}
if (((int)(__34106_72_ptr[1])) == 95) {

if (((int)(__34106_72_ptr[2])) != 90) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34107_71_dctl);
} else  {
__34106_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__34106_72_ptr + 3), ((_ZN3edg9a_booleanE)0), __34107_71_dctl));
__34106_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34106_72_ptr, __34107_71_dctl));
}
} else  { if ((((((int)(__34106_72_ptr[1])) == 100) || (((int)(__34106_72_ptr[1])) == 101)) || (((int)(__34106_72_ptr[1])) == 102)) || (((int)(__34106_72_ptr[1])) == 103)) {



__34106_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_float_literalEPKcP22a_decode_control_block(__34106_72_ptr, __34107_71_dctl));
} else  { if (((((int)(__34106_72_ptr[1])) == 67) && ((((((int)(__34106_72_ptr[2])) == 100) || (((int)(__34106_72_ptr[2])) == 101)) || (((int)(__34106_72_ptr[2])) == 102)) || (((int)(__34106_72_ptr[2])) == 103))) || ((__34123_17_sub != ((_ZN3edg12a_const_charE *)0)) && ((((int)(__34123_17_sub[0])) 
#line 6872
== 67) && ((((((int)(__34123_17_sub[1])) == 100) || (((int)(__34123_17_sub[1])) == 101)) || (((int)(__34123_17_sub[1])) == 102)) || (((int)(__34123_17_sub[1])) == 103)))))

{

__34106_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_complex_literalEPKcP22a_decode_control_block(__34106_72_ptr, __34107_71_dctl));
} else  { if (((((int)(__34106_72_ptr[1])) == 68) && ((((int)(__34106_72_ptr[2])) == 110) || (((int)(__34106_72_ptr[2])) == 78))) && (((int)(__34106_72_ptr[3])) == 69))

{


(__34107_71_dctl->suppress_id_output)++;
_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34106_72_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34107_71_dctl);
(__34107_71_dctl->suppress_id_output)--;
if (((int)(__34106_72_ptr[2])) == 78) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__nullptr"), __34107_71_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"nullptr"), __34107_71_dctl);
}
__34106_72_ptr += 4;
} else  {


_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34107_71_dctl);
__34106_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34106_72_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34107_71_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34107_71_dctl);
if (((int)(*__34106_72_ptr)) == 69) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"\"...\""), __34107_71_dctl);
} else  {

if (((int)(*__34106_72_ptr)) == 110) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)45), __34107_71_dctl);
__34106_72_ptr++;
}



if ((!(((int)((_ctype)[((unsigned char)((unsigned char)(*__34106_72_ptr)))])) & 4)) && (!(emulate_gnu_abi_bugs))) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34107_71_dctl);
} else  {
while (((int)((_ctype)[((unsigned char)((unsigned char)(*__34106_72_ptr)))])) & 4) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__34106_72_ptr), __34107_71_dctl);
__34106_72_ptr++;
}
}
}
__34106_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34106_72_ptr, __34107_71_dctl));
} } } }
return __34106_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__34204_76_ptr, 
a_decode_control_block_ptr __34205_75_dctl)
#line 6942
{
if ((((int)(*__34204_76_ptr)) == 100) && (((int)(__34204_76_ptr[1])) == 105)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)46), __34205_75_dctl);
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block((__34204_76_ptr + 2), ((_ZN3edg9a_booleanE)0), __34205_75_dctl));
if ((((int)(*__34204_76_ptr)) == 100) && (((int)(__34204_76_ptr[1])) == 105)) {

} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)61), __34205_75_dctl);
}
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34204_76_ptr, __34205_75_dctl));
} else  { if ((((int)(*__34204_76_ptr)) == 100) && (((int)(__34204_76_ptr[1])) == 120)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __34205_75_dctl);
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34204_76_ptr + 2), __34205_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]="), __34205_75_dctl);
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34204_76_ptr, __34205_75_dctl));
} else  { if ((((int)(*__34204_76_ptr)) == 100) && (((int)(__34204_76_ptr[1])) == 88)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __34205_75_dctl);
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34204_76_ptr + 2), __34205_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" ... "), __34205_75_dctl);
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34204_76_ptr, __34205_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]="), __34205_75_dctl);
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34204_76_ptr, __34205_75_dctl));
} else  {
__34204_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34204_76_ptr, __34205_75_dctl));
} } }
return __34204_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block(
_ZN3edg12a_const_charE *__34254_62_ptr, 
char __34255_61_stop_char, 
char __34256_61_open_paren, 
char __34257_61_close_paren, 
_ZN3edg9a_booleanE __34258_61_is_braced_expr, 
a_decode_control_block_ptr __34259_61_dctl)
#line 6988
{
auto _ZN3edg9a_booleanE __34268_13_first_time = ((_ZN3edg9a_booleanE)1);

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(__34256_61_open_paren, __34259_61_dctl);
while ((((int)(*__34254_62_ptr)) != ((int)__34255_61_stop_char)) && (!(__34259_61_dctl->err_in_id))) {
if (((int)(*__34254_62_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34259_61_dctl);
goto __T802402128;
}
if (!(__34268_13_first_time)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34259_61_dctl);
} else  {
__34268_13_first_time = ((_ZN3edg9a_booleanE)0);
}
if (__34258_61_is_braced_expr) {
__34254_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34254_62_ptr, __34259_61_dctl));
} else  {
__34254_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34254_62_ptr, __34259_61_dctl));
}
} __T802402128:;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(__34257_61_close_paren, __34259_61_dctl);
return __34254_62_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(
_ZN3edg12a_const_charE *__34293_62_ptr, 
char __34294_61_stop_char, 
a_decode_control_block_ptr __34295_61_dctl)
#line 7022
{
return _ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block(__34293_62_ptr, __34294_61_stop_char, ((char)40), ((char)41), ((_ZN3edg9a_booleanE)0), __34295_61_dctl);

}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_initializerEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__34308_62_ptr, 
a_decode_control_block_ptr __34309_61_dctl)
#line 7038
{
if (((int)(*__34308_62_ptr)) == 69) {
__34308_62_ptr++;
} else  {
if ((((int)(*__34308_62_ptr)) == 112) && (((int)(__34308_62_ptr[1])) == 105)) {
__34308_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block((__34308_62_ptr + 2), ((char)69), __34309_61_dctl));
__34308_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34308_62_ptr, __34309_61_dctl));
} else  { if ((((int)(*__34308_62_ptr)) == 105) && (((int)(__34308_62_ptr[1])) == 108)) {
__34308_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block((__34308_62_ptr + 2), ((char)69), ((char)123), ((char)125), ((_ZN3edg9a_booleanE)1), __34309_61_dctl));

__34308_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34308_62_ptr, __34309_61_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34309_61_dctl);
} }
}
return __34308_62_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34336_70_ptr, 
a_decode_control_block_ptr __34337_69_dctl)
#line 7159
{
auto int __34439_16_num_operands; auto int __34439_30_length;
auto _ZN3edg12a_const_charE *__34440_17_op_str; auto _ZN3edg12a_const_charE *__34440_26_close_str;

if (((int)(*__34336_70_ptr)) == 76) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_expr_primaryEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  { if (((int)(*__34336_70_ptr)) == 84) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  { if (((int)(*__34336_70_ptr)) == 102) {
if ((((int)(__34336_70_ptr[1])) == 112) || ((((int)(__34336_70_ptr[1])) == 76) && (((int)((_ctype)[((unsigned char)((unsigned char)(__34336_70_ptr[2])))])) & 4)))
{

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d328demangle_parameter_referenceEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  {

auto _ZN3edg9a_booleanE __34455_20_unary; auto _ZN3edg9a_booleanE __34455_27_left;
switch ((int)(__34336_70_ptr[1])) {
case 108: __34455_20_unary = ((_ZN3edg9a_booleanE)1); __34455_27_left = ((_ZN3edg9a_booleanE)1); goto __T802446880;
case 76: __34455_20_unary = ((_ZN3edg9a_booleanE)0); __34455_27_left = ((_ZN3edg9a_booleanE)1); goto __T802446880;
case 114: __34455_20_unary = ((_ZN3edg9a_booleanE)1); __34455_27_left = ((_ZN3edg9a_booleanE)0); goto __T802446880;
case 82: __34455_20_unary = ((_ZN3edg9a_booleanE)0); __34455_27_left = ((_ZN3edg9a_booleanE)0); goto __T802446880;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34337_69_dctl);
goto __34764_1_bad_name;
} __T802446880:;
__34336_70_ptr += 2;
__34440_17_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__34336_70_ptr, (&__34439_16_num_operands), (&__34439_30_length), (&__34440_26_close_str), __34337_69_dctl));

if (__34440_17_op_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34337_69_dctl);
} else  {
__34336_70_ptr += __34439_30_length;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34337_69_dctl);
if (__34455_20_unary) {
if (__34455_27_left) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34337_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34337_69_dctl);
}
} else  {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34337_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl);
}
}
} else  { if ((((int)(*__34336_70_ptr)) == 99) && (((int)(__34336_70_ptr[1])) == 108)) {

__34336_70_ptr += 2;
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34336_70_ptr, ((char)69), __34337_69_dctl));
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34336_70_ptr, __34337_69_dctl));
} else  { if ((((int)(*__34336_70_ptr)) == 99) && (((int)(__34336_70_ptr[1])) == 112)) {

__34336_70_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34336_70_ptr, ((char)69), __34337_69_dctl));
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34336_70_ptr, __34337_69_dctl));
} else  { if ((((int)(*__34336_70_ptr)) == 99) && (((int)(__34336_70_ptr[1])) == 118)) {



auto _ZN3edg12a_const_charE *__34511_19_nptr;
auto _ZN3edg9a_booleanE __34512_15_one_argument = ((_ZN3edg9a_booleanE)0);


(__34337_69_dctl->suppress_id_output)++;
__34511_19_nptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34336_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
(__34337_69_dctl->suppress_id_output)--;
if ((!(__34337_69_dctl->err_in_id)) && (((int)(*__34511_19_nptr)) != 95)) {
__34512_15_one_argument = ((_ZN3edg9a_booleanE)1);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34337_69_dctl);
}


(__34337_69_dctl->suppress_substitution_recording)++;
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34336_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
(__34337_69_dctl->suppress_substitution_recording)--;
if (!(__34337_69_dctl->err_in_id)) {
if (__34512_15_one_argument) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  {

if (((int)(*__34336_70_ptr)) != 95) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34337_69_dctl);
} else  {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block((__34336_70_ptr + 1), ((char)69), __34337_69_dctl));
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34336_70_ptr, __34337_69_dctl));
}
}
}
} else  { if ((((int)(*__34336_70_ptr)) == 103) && (((int)(__34336_70_ptr[1])) == 115)) {


_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34336_70_ptr + 2), __34337_69_dctl));
} else  { if ((((int)(*__34336_70_ptr)) == 110) && ((((int)(__34336_70_ptr[1])) == 119) || (((int)(__34336_70_ptr[1])) == 97))) {

if (((int)(__34336_70_ptr[1])) == 119) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"new "), __34337_69_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"new[] "), __34337_69_dctl);
}
__34336_70_ptr += 2;

if (((int)(*__34336_70_ptr)) != 95) {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34336_70_ptr, ((char)95), __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __34337_69_dctl);
}
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34336_70_ptr, __34337_69_dctl));
if (!(__34337_69_dctl->err_in_id)) {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
if (!(__34337_69_dctl->err_in_id)) {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_initializerEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
}
}
} else  { if ((((int)(*__34336_70_ptr)) == 103) && (((int)(__34336_70_ptr[1])) == 99)) {

__34336_70_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"gcnew "), __34337_69_dctl);

if (((int)(*__34336_70_ptr)) != 95) {
auto _ZN3edg12a_const_charE *__34573_21_optr; auto _ZN3edg12a_const_charE *__34573_34_ptr2; __34573_21_optr = __34336_70_ptr;


(__34337_69_dctl->suppress_id_output)++;
(__34337_69_dctl->suppress_substitution_recording)++;
__34573_34_ptr2 = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34336_70_ptr, ((char)95), __34337_69_dctl));
(__34337_69_dctl->suppress_id_output)--;
(__34337_69_dctl->suppress_substitution_recording)--;
if (!(__34337_69_dctl->err_in_id)) {
__34573_34_ptr2 = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34573_34_ptr2, __34337_69_dctl));
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34573_34_ptr2, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34573_21_optr, ((char)95), __34337_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __34337_69_dctl);
}
} else  {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34336_70_ptr, __34337_69_dctl));
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
}
if (!(__34337_69_dctl->err_in_id)) {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_initializerEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
}
} else  { if ((((int)(*__34336_70_ptr)) == 100) && (((int)(__34336_70_ptr[1])) == 116)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34336_70_ptr + 2), __34337_69_dctl));
if (!(__34337_69_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)46), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl);
}
} else  { if ((((int)(*__34336_70_ptr)) == 112) && (((int)(__34336_70_ptr[1])) == 116)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34336_70_ptr + 2), __34337_69_dctl));
if (!(__34337_69_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"->"), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl);
}
} else  { if ((((int)(*__34336_70_ptr)) == 115) && (((int)(__34336_70_ptr[1])) == 90)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"sizeof...("), __34337_69_dctl);
__34336_70_ptr += 2;
if (((int)(*__34336_70_ptr)) == 84) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  { if (((int)(*__34336_70_ptr)) == 102) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d328demangle_parameter_referenceEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34337_69_dctl);
} }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl);
} else  { if ((((int)(*__34336_70_ptr)) == 115) && (((int)(__34336_70_ptr[1])) == 112)) {

__34336_70_ptr += 2;
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34337_69_dctl);
} else  { if (((((int)(*__34336_70_ptr)) == 116) || (((int)(*__34336_70_ptr)) == 105)) && (((int)(__34336_70_ptr[1])) == 108)) {

if (((int)(*__34336_70_ptr)) == 116) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34336_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
} else  {
__34336_70_ptr += 2;
}
if (!(__34337_69_dctl->err_in_id)) {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block(__34336_70_ptr, ((char)69), ((char)123), ((char)125), ((_ZN3edg9a_booleanE)1), __34337_69_dctl));

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34336_70_ptr, __34337_69_dctl));
}
} else  { if ((__34440_17_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__34336_70_ptr, (&__34439_16_num_operands), (&__34439_30_length), (&__34440_26_close_str), __34337_69_dctl))) != ((_ZN3edg12a_const_charE *)0))
{




auto _ZN3edg9a_booleanE __34650_15_needs_parens; __34650_15_needs_parens = ((_Bool)((strcmp(__34440_26_close_str, ((const char *)""))) == 0));
__34336_70_ptr += __34439_30_length;
if (__34650_15_needs_parens) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34337_69_dctl); }
if ((strncmp(__34440_17_op_str, ((const char *)"builtin-operation-"), 18ULL)) == 0) {

auto int __34655_11_i;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34337_69_dctl);
for (__34655_11_i = 1; __34655_11_i <= __34439_16_num_operands; __34655_11_i++) {
if ((((int)(*__34336_70_ptr)) == 84) && (((int)(__34336_70_ptr[1])) == 79)) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34336_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
} else  {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
}
if (__34655_11_i != __34439_16_num_operands) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34337_69_dctl); }
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl);
} else  { if ((strncmp(__34440_17_op_str, ((const char *)"subscript"), 9ULL)) == 0) {

auto int __34670_11_i;
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __34337_69_dctl);
for (__34670_11_i = 2; __34670_11_i <= __34439_16_num_operands; __34670_11_i++) {
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
if (__34670_11_i != __34439_16_num_operands) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34337_69_dctl); }
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __34337_69_dctl);
} else  { if (__34439_16_num_operands == 1) {
auto char __34679_12_cast_close = ((char)0);

if (((strcmp(__34440_17_op_str, ((const char *)"++"))) == 0) || ((strcmp(__34440_17_op_str, ((const char *)"--"))) == 0))
{
if (((int)(*__34336_70_ptr)) == 95) {

__34336_70_ptr++;
} else  {

__34440_26_close_str = __34440_17_op_str;
__34440_17_op_str = ((const char *)"");
}
}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
if ((((((strcmp(__34440_17_op_str, ((const char *)"static_cast"))) == 0) || ((strcmp(__34440_17_op_str, ((const char *)"dynamic_cast"))) == 0)) || ((strcmp(__34440_17_op_str, ((const char *)"const_cast"))) == 0)) || ((strcmp(__34440_17_op_str, ((const char *)"reinterpret_cast"))) == 0)) || ((strcmp(
#line 7414
__34440_17_op_str, ((const char *)"safe_cast"))) == 0))



{

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)60), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)">("), __34337_69_dctl);
__34679_12_cast_close = ((char)41);
}
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
if (((int)__34679_12_cast_close) != 0) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(__34679_12_cast_close, __34337_69_dctl); }
} else  { if (__34439_16_num_operands == 2) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  { if (__34439_16_num_operands == 3) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)":"), __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} else  {



if ((strcmp(__34440_17_op_str, ((const char *)"sizeof("))) == 0) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
} else  { if (((strcmp(__34440_17_op_str, ((const char *)"alignof("))) == 0) || ((strcmp(__34440_17_op_str, ((const char *)"__alignof__("))) == 0))
{

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
} else  { if ((strcmp(__34440_17_op_str, ((const char *)"__uuidof("))) == 0) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
} else  { if ((strcmp(__34440_17_op_str, ((const char *)"typeid("))) == 0) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
} else  { if ((strcmp(__34440_17_op_str, ((const char *)"::typeid"))) == 0) {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34336_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34337_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
} else  { if ((strcmp(__34440_17_op_str, ((const char *)"throw"))) == 0) {


_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
} else  { if ((strncmp(__34440_17_op_str, ((const char *)"\"\""), 2ULL)) == 0) {




_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __34337_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_17_op_str, __34337_69_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34337_69_dctl);
} } } } } } }
} } } } }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34440_26_close_str, __34337_69_dctl);
if (__34650_15_needs_parens) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34337_69_dctl); }
} else  {

__34336_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block(__34336_70_ptr, __34337_69_dctl));
} } } } } } } } } } } } } } }
__34764_1_bad_name:;
return __34336_70_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_template_argEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34769_72_ptr, 
a_decode_control_block_ptr __34770_71_dctl)
#line 7503
{
if (((int)(*__34769_72_ptr)) == 88) {

__34769_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34769_72_ptr + 1), __34770_71_dctl));
__34769_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34769_72_ptr, __34770_71_dctl));
} else  { if (((int)(*__34769_72_ptr)) == 76) {

__34769_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_expr_primaryEPKcP22a_decode_control_block(__34769_72_ptr, __34770_71_dctl));
} else  { if ((((int)(*__34769_72_ptr)) == 74) || ((((int)(*__34769_72_ptr)) == 73) && (emulate_gnu_abi_bugs)))
{

__34769_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__34769_72_ptr, __34770_71_dctl));
} else  {

__34769_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34769_72_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34770_71_dctl));
} } }
return __34769_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34802_73_ptr, 
a_decode_control_block_ptr __34803_72_dctl)
#line 7533
{
auto _ZN3edg9a_booleanE __34813_13_suppress = ((_ZN3edg9a_booleanE)0);

if (((int)(*__34802_73_ptr)) == 74) {

__34813_13_suppress = ((_ZN3edg9a_booleanE)1);
}

__34802_73_ptr++;
if (!(__34813_13_suppress)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)60), __34803_72_dctl); }
for (; ((int)(*__34802_73_ptr)) != 69; ) {
__34802_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_template_argEPKcP22a_decode_control_block(__34802_73_ptr, __34803_72_dctl));

if (((int)(*__34802_73_ptr)) == 69) { goto __T802704872; }

if (__34803_72_dctl->err_in_id) { goto __T802704872; }

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34803_72_dctl);
} __T802704872:;
__34802_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34802_73_ptr, __34803_72_dctl));
if (!(__34813_13_suppress)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)62), __34803_72_dctl); }
return __34802_73_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d331demangle_nested_name_componentsEPKcmPbS2_PS1_S3_P22a_decode_control_block(
_ZN3edg12a_const_charE *__34838_59_ptr, 
unsigned long __34839_58_num_levels, 
_ZN3edg9a_booleanE *__34840_59_is_no_return_name, 
_ZN3edg9a_booleanE *__34841_59_has_templ_arg_list, 
_ZN3edg12a_const_charE **__34842_60_ctor_dtor_kind, 
_ZN3edg12a_const_charE **__34843_60_last_component_name, 
a_decode_control_block_ptr __34844_58_dctl)
#line 7586
{
auto _ZN3edg12a_const_charE *__34866_18_prev_component_name = ((_ZN3edg12a_const_charE *)0);
auto _ZN3edg12a_const_charE *__34867_18_first_component_start;
auto unsigned long __34868_17_level_num = 0UL;
#line 7588
__34867_18_first_component_start = __34838_59_ptr;


(*__34840_59_is_no_return_name) = ((_ZN3edg9a_booleanE)0);
(*__34841_59_has_templ_arg_list) = ((_ZN3edg9a_booleanE)0);
(*__34842_60_ctor_dtor_kind) = ((_ZN3edg12a_const_charE *)0);
for (; ; ) {

auto _ZN3edg9a_booleanE __34875_15_is_substitution = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __34876_15_suppress_qualification = ((_ZN3edg9a_booleanE)0);
__34868_17_level_num++;
(*__34840_59_is_no_return_name) = ((_ZN3edg9a_booleanE)0);
(*__34841_59_has_templ_arg_list) = ((_ZN3edg9a_booleanE)0);
if ((((int)(*__34838_59_ptr)) == 69) || (((int)(*__34838_59_ptr)) == 0)) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34844_58_dctl);
} else  { if (((int)(*__34838_59_ptr)) == 83) {

__34875_15_is_substitution = ((_ZN3edg9a_booleanE)1);
__34838_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__34838_59_ptr, 0, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), (&__34866_18_prev_component_name), ((_ZN3edg12a_const_charE **)0), __34844_58_dctl));
#line 7615
if (((int)(*__34838_59_ptr)) == 69) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34844_58_dctl);
}
} else  { if (((int)(*__34838_59_ptr)) == 84) {

__34838_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__34838_59_ptr, __34844_58_dctl));
} else  { if ((((int)(*__34838_59_ptr)) == 68) && ((((int)(__34838_59_ptr[1])) == 116) || (((int)(__34838_59_ptr[1])) == 84))) {

__34838_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34838_59_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34844_58_dctl));
} else  {

if ((((int)(*__34838_59_ptr)) != 67) && ((((int)(*__34838_59_ptr)) != 68) || (((int)(__34838_59_ptr[1])) == 67))) {

__34866_18_prev_component_name = __34838_59_ptr;
__34838_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__34838_59_ptr, __34840_59_is_no_return_name, __34844_58_dctl));
} else  {



(*__34840_59_is_no_return_name) = ((_ZN3edg9a_booleanE)1);
if (((int)(*__34838_59_ptr)) == 68) {
if (((int)(__34838_59_ptr[1])) == 55) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)33), __34844_58_dctl);
} else  {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)126), __34844_58_dctl);
}
}
if ((__34866_18_prev_component_name == ((_ZN3edg12a_const_charE *)0)) || (((int)(*__34866_18_prev_component_name)) == 83))
{




_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34844_58_dctl);
} else  {
auto _ZN3edg9a_booleanE __34931_21_dummy;
#line 7668
if ((((((int)(__34838_59_ptr[1])) == 49) || (((int)(__34838_59_ptr[1])) == 50)) || (((int)(__34838_59_ptr[1])) == 57)) || ((((int)(__34838_59_ptr[0])) == 67) ? (((((int)(__34838_59_ptr[1])) == 51) || (((int)(__34838_59_ptr[1])) == 56)) || ((((int)(__34838_59_ptr[1])) == 73) && ((((int)(
#line 7668
__34838_59_ptr[2])) == 49) || (((int)(__34838_59_ptr[2])) == 50)))) : ((((int)(__34838_59_ptr[1])) == 48) || (((int)(__34838_59_ptr[1])) == 55))))



{

(*__34842_60_ctor_dtor_kind) = (__34838_59_ptr + 1);
if (((int)(__34838_59_ptr[1])) == 73) {




(__34844_58_dctl->suppress_template_parameters)++;
__34838_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34838_59_ptr + 3), ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), __34844_58_dctl));

(__34844_58_dctl->suppress_template_parameters)--;
} else  {


_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__34866_18_prev_component_name, (&__34931_21_dummy), __34844_58_dctl);

__34838_59_ptr += 2;
}
if (((int)(*__34838_59_ptr)) == 66) {


__34838_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_abi_tag_attributeEPKcP22a_decode_control_block(__34838_59_ptr, __34844_58_dctl));
}
} else  {


_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34844_58_dctl);
}
}
}
if (((int)(*__34838_59_ptr)) == 77) {


__34838_59_ptr++;
}
} } } }
if (((int)(*__34838_59_ptr)) == 73) {



if (!(__34875_15_is_substitution)) {
_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__34867_18_first_component_start, subk_template_prefix, (__34868_17_level_num - 1UL), ((_ZN3edg9a_booleanE)0), __34844_58_dctl);


}

__34838_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__34838_59_ptr, __34844_58_dctl));
(*__34841_59_has_templ_arg_list) = ((_ZN3edg9a_booleanE)1);
__34875_15_is_substitution = ((_ZN3edg9a_booleanE)0);
}

if (((int)(*__34838_59_ptr)) == 69) { goto __T802798712; }
if (!(__34875_15_is_substitution)) {



_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__34867_18_first_component_start, subk_prefix, __34868_17_level_num, ((_ZN3edg9a_booleanE)0), __34844_58_dctl);


}

if (__34844_58_dctl->err_in_id) { goto __T802798712; }

if ((__34839_58_num_levels != 0UL) && (__34868_17_level_num >= __34839_58_num_levels)) { goto __T802798712; }


if (!(__34876_15_suppress_qualification)) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __34844_58_dctl); }
} __T802798712:;
if (__34843_60_last_component_name != ((_ZN3edg12a_const_charE **)0)) { (*__34843_60_last_component_name) = __34866_18_prev_component_name; }
return __34838_59_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_nested_nameEPKcP12a_func_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__35026_69_ptr, 
a_func_block *__35027_69_func_block, 
a_decode_control_block_ptr __35028_68_dctl)
#line 7774
{
auto _ZN3edg9a_booleanE __35054_13_has_templ_arg_list;
auto _ZN3edg9a_booleanE __35055_13_is_no_return_name;

_ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block(__35027_69_func_block);

__35026_69_ptr++;

__35026_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__35026_69_ptr, (&(__35027_69_func_block->cv_quals))));

__35026_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi(__35026_69_ptr, (&(__35027_69_func_block->ref_qual))));

__35026_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d331demangle_nested_name_componentsEPKcmPbS2_PS1_S3_P22a_decode_control_block(__35026_69_ptr, 0UL, (&__35055_13_is_no_return_name), (&__35054_13_has_templ_arg_list), (&(__35027_69_func_block->ctor_dtor_kind)), ((_ZN3edg12a_const_charE **)0), 
#line 7786
__35028_68_dctl));
#line 7793
__35026_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35026_69_ptr, __35028_68_dctl));

if (!(__35054_13_has_templ_arg_list)) {
(__35027_69_func_block->no_return_type) = ((_ZN3edg9a_booleanE)1);
}


if (__35055_13_is_no_return_name) {
(__35027_69_func_block->no_return_type) = ((_ZN3edg9a_booleanE)1);
}
return __35026_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319demangle_local_nameEPKcP12a_func_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__35087_69_ptr, 
a_func_block *__35088_69_func_block, 
a_decode_control_block_ptr __35089_68_dctl)
#line 7826
{
_ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block(__35088_69_func_block);

__35087_69_ptr++;

__35087_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(__35087_69_ptr, ((_ZN3edg9a_booleanE)1), __35089_68_dctl));
__35087_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35087_69_ptr, __35089_68_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35089_68_dctl);
if (((int)(*__35087_69_ptr)) == 115) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"string"), __35089_68_dctl);
__35087_69_ptr++;
} else  {
if (((int)(*__35087_69_ptr)) == 100) {

auto long __35120_12_param = (-1L);
__35087_69_ptr += 1;
if (((int)(*__35087_69_ptr)) != 95) {
__35087_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__35087_69_ptr, (&__35120_12_param), __35089_68_dctl));
if ((__35120_12_param < 0L) || (((int)(*__35087_69_ptr)) != 95)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35089_68_dctl);
} else  {

__35087_69_ptr += 1;
}
} else  {

__35087_69_ptr += 1;
}
if (!(__35089_68_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[default argument "), __35089_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block((__35120_12_param + 2L), __35089_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" (from end)]::"), __35089_68_dctl);
}
}

__35087_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block(__35087_69_ptr, __35088_69_func_block, 0x3, __35089_68_dctl));
}
if ((!(__35089_68_dctl->err_in_id)) && (((int)(*__35087_69_ptr)) == 95)) {

auto long __35145_10_num = (-1L);
if (((int)((_ctype)[((unsigned char)((unsigned char)(__35087_69_ptr[1])))])) & 4) {

__35145_10_num = ((long)(((int)((char)(__35087_69_ptr[1]))) - 48));
__35087_69_ptr += 2;
} else  { if ((((int)(__35087_69_ptr[1])) == 95) && (((int)((_ctype)[((unsigned char)((unsigned char)(__35087_69_ptr[2])))])) & 4)) {

__35087_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__35087_69_ptr + 2), (&__35145_10_num), __35089_68_dctl));
if (((int)(*__35087_69_ptr)) == 95) {
__35087_69_ptr += 1;
} else  {
__35145_10_num = (-1L);
}
} }
if (__35145_10_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35089_68_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __35089_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block((__35145_10_num + 2L), __35089_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __35089_68_dctl);
}
}
return __35087_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_unscoped_nameEPKcP12a_func_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__35172_69_ptr, 
a_func_block *__35173_69_func_block, 
a_decode_control_block_ptr __35174_68_dctl)
#line 7906
{
auto _ZN3edg9a_booleanE __35186_13_is_no_return_name;

if ((((int)(*__35172_69_ptr)) == 83) && (((int)(__35172_69_ptr[1])) == 116)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"std::"), __35174_68_dctl);
__35172_69_ptr += 2;
}
__35172_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__35172_69_ptr, (&__35186_13_is_no_return_name), __35174_68_dctl));
(__35173_69_func_block->no_return_type) = __35186_13_is_no_return_name;
return __35172_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block( _ZN3edg12a_const_charE *__35199_64_ptr, 
a_func_block *__35200_64_func_block, 
a_demangle_name_option __35201_63_options, 
a_decode_control_block_ptr __35202_63_dctl)
#line 7947
{
_ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block(__35200_64_func_block);
if (((int)(*__35199_64_ptr)) == 66) {

if ((__35201_63_options & 0x1) == 0) { (__35202_63_dctl->suppress_id_output)++; }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[static from "), __35202_63_dctl);
__35199_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block((__35199_64_ptr + 1), ((_ZN3edg9a_booleanE)1), __35202_63_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"] "), __35202_63_dctl);
if ((__35201_63_options & 0x1) == 0) { (__35202_63_dctl->suppress_id_output)--; }
}
if ((__35201_63_options & 0x2) == 0) { (__35202_63_dctl->suppress_id_output)++; }
if (((int)(*__35199_64_ptr)) == 78) {

__35199_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_nested_nameEPKcP12a_func_blockP22a_decode_control_block(__35199_64_ptr, __35200_64_func_block, __35202_63_dctl));
} else  { if (((int)(*__35199_64_ptr)) == 90) {

__35199_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_local_nameEPKcP12a_func_blockP22a_decode_control_block(__35199_64_ptr, __35200_64_func_block, __35202_63_dctl));
} else  {

if (((((int)(*__35199_64_ptr)) == 83) && (((int)(__35199_64_ptr[1])) != 0)) && (((((int)(__35199_64_ptr[2])) == 73) || ((((int)(__35199_64_ptr[2])) == 95) && (((int)(__35199_64_ptr[3])) == 73))) || ((((((int)(__35199_64_ptr[2])) != 0) && (!(((int)((_ctype)[((unsigned char)((unsigned char)(
#line 7966
__35199_64_ptr[2])))])) & 4))) && (((int)(__35199_64_ptr[3])) == 95)) && (((int)(__35199_64_ptr[4])) == 73))))



{
#line 7978
__35199_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__35199_64_ptr, 0, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), ((_ZN3edg12a_const_charE **)0), ((_ZN3edg12a_const_charE **)0), __35202_63_dctl));
#line 7984
} else  {


auto _ZN3edg12a_const_charE *__35266_21_start; __35266_21_start = __35199_64_ptr;
__35199_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_unscoped_nameEPKcP12a_func_blockP22a_decode_control_block(__35199_64_ptr, __35200_64_func_block, __35202_63_dctl));
if (((int)(*__35199_64_ptr)) == 73) {


_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__35266_21_start, subk_unscoped_template_name, 0UL, ((_ZN3edg9a_booleanE)0), __35202_63_dctl);

}
}
if (((int)(*__35199_64_ptr)) == 73) {


if (__35202_63_dctl->suppress_template_parameters) { (__35202_63_dctl->suppress_id_output)++; }
__35199_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__35199_64_ptr, __35202_63_dctl));
if (__35202_63_dctl->suppress_template_parameters) { (__35202_63_dctl->suppress_id_output)--; }
} else  {

(__35200_64_func_block->no_return_type) = ((_ZN3edg9a_booleanE)1);
}
} }
if ((__35201_63_options & 0x2) == 0) { (__35202_63_dctl->suppress_id_output)--; }
return __35199_64_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35291_69_ptr, 
a_decode_control_block_ptr __35292_68_dctl)
#line 8020
{
__35291_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__35291_69_ptr, ((_ZN3edg9a_booleanE)0), __35292_68_dctl));
if ((!(__35292_68_dctl->err_in_id)) && (((int)(*__35291_69_ptr)) == 73)) {

__35291_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__35291_69_ptr, __35292_68_dctl));
}
return __35291_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d329demangle_base_unresolved_nameEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__35310_76_ptr, 
a_decode_control_block_ptr __35311_75_dctl)
#line 8050
{
auto int __35330_16_num_operands; auto int __35330_30_length;
auto _ZN3edg12a_const_charE *__35331_17_op_str; auto _ZN3edg12a_const_charE *__35331_26_close_str;

if ((((int)(*__35310_76_ptr)) == 111) && (((int)(__35310_76_ptr[1])) == 110)) {

__35310_76_ptr += 2;
__35331_17_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__35310_76_ptr, (&__35330_16_num_operands), (&__35330_30_length), (&__35331_26_close_str), __35311_75_dctl));

if (__35331_17_op_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35311_75_dctl);
} else  {
__35310_76_ptr += __35330_30_length;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __35311_75_dctl);
if ((strcmp(__35331_17_op_str, ((const char *)"cast"))) == 0) {

__35310_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35310_76_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35311_75_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__35331_17_op_str, __35311_75_dctl);
}
if ((!(__35311_75_dctl->err_in_id)) && (((int)(*__35310_76_ptr)) == 73)) {

__35310_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__35310_76_ptr, __35311_75_dctl));
}
}
} else  { if ((((int)(*__35310_76_ptr)) == 100) && (((int)(__35310_76_ptr[1])) == 110)) {

__35310_76_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)126), __35311_75_dctl);
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__35310_76_ptr)))])) & 4) {
__35310_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35310_76_ptr, __35311_75_dctl));
} else  {
__35310_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35310_76_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35311_75_dctl));
}
} else  {

__35310_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35310_76_ptr, __35311_75_dctl));
} }
return __35310_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35371_75_ptr, 
a_decode_control_block_ptr __35372_74_dctl)
#line 8117
{
auto _ZN3edg9a_booleanE __35397_16_gpp_qualified_name = ((_ZN3edg9a_booleanE)0);

if ((((int)(*__35371_75_ptr)) == 103) && (((int)(__35371_75_ptr[1])) == 115)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35372_74_dctl);
__35371_75_ptr += 2;
}
if ((((int)(*__35371_75_ptr)) == 115) && (((int)(__35371_75_ptr[1])) == 114)) {
#line 8137
__35371_75_ptr += 2;
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__35371_75_ptr)))])) & 4) {



while ((!(__35372_74_dctl->err_in_id)) && (((int)(*__35371_75_ptr)) != 69)) {
if (((int)(*__35371_75_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35372_74_dctl);
} else  {
__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35371_75_ptr, __35372_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35372_74_dctl);
}
}
__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35371_75_ptr, __35372_74_dctl));
} else  {
if (emulate_gnu_abi_bugs) {




auto _ZN3edg12a_const_charE *__35436_23_ptr2;
(__35372_74_dctl->suppress_id_output)++;
(__35372_74_dctl->suppress_substitution_recording)++;
__35436_23_ptr2 = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35371_75_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35372_74_dctl));
(__35372_74_dctl->suppress_id_output)--;
(__35372_74_dctl->suppress_substitution_recording)--;
if (((int)(*__35436_23_ptr2)) == 78) {
__35397_16_gpp_qualified_name = ((_ZN3edg9a_booleanE)1);

(__35372_74_dctl->suppress_id_output)++;
__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35371_75_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35372_74_dctl));
(__35372_74_dctl->suppress_id_output)--;
}
}
if (!(__35397_16_gpp_qualified_name)) {
#line 8178
if (((int)(*__35371_75_ptr)) == 78) {
__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35371_75_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35372_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35372_74_dctl);
while ((!(__35372_74_dctl->err_in_id)) && (((int)(*__35371_75_ptr)) != 69)) {
if (((int)(*__35371_75_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35372_74_dctl);
} else  {
__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35371_75_ptr, __35372_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35372_74_dctl);
}
}
__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35371_75_ptr, __35372_74_dctl));
} else  {
__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35371_75_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35372_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35372_74_dctl);
}
}
}
if (!(__35372_74_dctl->err_in_id)) {


__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_base_unresolved_nameEPKcP22a_decode_control_block(__35371_75_ptr, __35372_74_dctl));
}
} else  {

__35371_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_base_unresolved_nameEPKcP22a_decode_control_block(__35371_75_ptr, __35372_74_dctl));
}
return __35371_75_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35488_71_ptr, 
a_decode_control_block_ptr __35489_70_dctl)
#line 8224
{
auto long __35504_13_num;
auto _ZN3edg9a_booleanE __35505_13_v_form = ((_ZN3edg9a_booleanE)0);

if ((((int)(*__35488_71_ptr)) != 104) && (((int)(*__35488_71_ptr)) != 118)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35489_70_dctl);
} else  {
__35505_13_v_form = ((_Bool)(((int)(*__35488_71_ptr)) == 118));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"(offset "), __35489_70_dctl);
__35488_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__35488_71_ptr + 1), (&__35504_13_num), __35489_70_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block(__35504_13_num, __35489_70_dctl);
if (__35505_13_v_form) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", virtual offset "), __35489_70_dctl);
__35488_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__35488_71_ptr, __35489_70_dctl));
__35488_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__35488_71_ptr, (&__35504_13_num), __35489_70_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block(__35504_13_num, __35489_70_dctl);
}
__35488_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__35488_71_ptr, __35489_70_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)") "), __35489_70_dctl);
}
return __35488_71_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_special_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35527_72_ptr, 
a_decode_control_block_ptr __35528_71_dctl)
#line 8272
{
auto a_func_block __35552_16_func_block;

if (((int)(*__35527_72_ptr)) == 71) {
if (((int)(__35527_72_ptr[1])) == 86) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Initialization guard variable for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35527_72_ptr + 2), (&__35552_16_func_block), 0x3, __35528_71_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35528_71_dctl);
}
} else  { if (((int)(*__35527_72_ptr)) == 84) {
if (((int)(__35527_72_ptr[1])) == 86) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Virtual function table for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35527_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35528_71_dctl));
} else  { if (((int)(__35527_72_ptr[1])) == 84) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Virtual table table for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35527_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35528_71_dctl));
} else  { if (((int)(__35527_72_ptr[1])) == 73) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Typeinfo for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35527_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35528_71_dctl));
} else  { if (((int)(__35527_72_ptr[1])) == 83) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Typeinfo name for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35527_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35528_71_dctl));
} else  { if (((int)(__35527_72_ptr[1])) == 99) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Covariant thunk for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block((__35527_72_ptr + 2), __35528_71_dctl));
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block(__35527_72_ptr, __35528_71_dctl));
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(__35527_72_ptr, ((_ZN3edg9a_booleanE)1), __35528_71_dctl));
} else  { if ((((int)(__35527_72_ptr[1])) == 104) || (((int)(__35527_72_ptr[1])) == 118)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Thunk for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block((__35527_72_ptr + 1), __35528_71_dctl));
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(__35527_72_ptr, ((_ZN3edg9a_booleanE)1), __35528_71_dctl));
} else  { if (((int)(__35527_72_ptr[1])) == 72) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Thread-local initialization routine for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35527_72_ptr + 2), (&__35552_16_func_block), 0x3, __35528_71_dctl));
} else  { if (((int)(__35527_72_ptr[1])) == 87) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Thread-local wrapper routine for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35527_72_ptr + 2), (&__35552_16_func_block), 0x3, __35528_71_dctl));
} else  { if (((int)(__35527_72_ptr[1])) == 65) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"template parameter object for "), __35528_71_dctl);
__35527_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_template_argEPKcP22a_decode_control_block((__35527_72_ptr + 2), __35528_71_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35528_71_dctl);
} } } } } } } } }
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35528_71_dctl);
} }
return __35527_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d330demangle_function_or_data_nameEPKcbbP22a_decode_control_block(
_ZN3edg12a_const_charE *__35613_60_ptr, 
_ZN3edg9a_booleanE __35614_59_include_func_params, 
_ZN3edg9a_booleanE __35615_59_first_scan, 
a_decode_control_block_ptr __35616_59_dctl)
#line 8351
{
auto a_func_block __35631_31_func_block;
auto a_bare_function_type_option __35632_31_bft_option;
auto a_demangle_name_option __35633_31_dno_option;
#line 8371
if (__35615_59_first_scan) {



__35633_31_dno_option = 0x1;
__35632_31_bft_option = 0x1;
} else  {


__35633_31_dno_option = 0x2;
__35632_31_bft_option = 0x2;


(__35616_59_dctl->suppress_substitution_recording)++;
}
__35613_60_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block(__35613_60_ptr, (&__35631_31_func_block), __35633_31_dno_option, __35616_59_dctl));


if (__35615_59_first_scan) { (__35616_59_dctl->suppress_id_output)++; }

if ((((int)(*__35613_60_ptr)) != 0) && (((int)(*__35613_60_ptr)) != 69)) {


if (((int)(*__35613_60_ptr)) == 81) {
auto a_func_block __35674_20_dummy_func_block;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [overriding "), __35616_59_dctl);
__35613_60_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35613_60_ptr + 1), (&__35674_20_dummy_func_block), __35633_31_dno_option, __35616_59_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"] "), __35616_59_dctl);
}
if (__35615_59_first_scan) { (__35616_59_dctl->suppress_id_output)--; }
if (!(__35614_59_include_func_params)) { (__35616_59_dctl->suppress_id_output)++; }
__35613_60_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(__35613_60_ptr, (__35631_31_func_block.no_return_type), __35632_31_bft_option, __35616_59_dctl));

if (!(__35614_59_include_func_params)) { (__35616_59_dctl->suppress_id_output)--; }
if (__35615_59_first_scan) { (__35616_59_dctl->suppress_id_output)++; }
if ((__35631_31_func_block.cv_quals) != 0) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __35616_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block((__35631_31_func_block.cv_quals), ((_ZN3edg9a_booleanE)0), __35616_59_dctl);

}
if ((__35631_31_func_block.ref_qual) != 0) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __35616_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_ref_qualifierEiP22a_decode_control_block((__35631_31_func_block.ref_qual), __35616_59_dctl);
}
}
if ((__35631_31_func_block.ctor_dtor_kind) != ((_ZN3edg12a_const_charE *)0)) {

switch ((int)(*(__35631_31_func_block.ctor_dtor_kind))) {
case 48:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [deleting]"), __35616_59_dctl);
goto __T803173584;
case 49:

goto __T803173584;
case 50:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [subobject]"), __35616_59_dctl);
goto __T803173584;
case 51:

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [allocating]"), __35616_59_dctl);
goto __T803173584;
case 55:

goto __T803173584;
case 56:

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [static]"), __35616_59_dctl);
goto __T803173584;
case 57:



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [delegation]"), __35616_59_dctl);
goto __T803173584;
case 73:

switch ((int)((__35631_31_func_block.ctor_dtor_kind)[1])) {
case 49:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [complete inheriting]"), __35616_59_dctl);
goto __T803185808;
case 50:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [base inheriting]"), __35616_59_dctl);
goto __T803185808;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35616_59_dctl);
} __T803185808:;
goto __T803173584;
default:


_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35616_59_dctl);
} __T803173584:;
}
if (__35615_59_first_scan) {
(__35616_59_dctl->suppress_id_output)--;
} else  {
(__35616_59_dctl->suppress_substitution_recording)--;
}
return __35613_60_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(
_ZN3edg12a_const_charE *__35755_61_ptr, 
_ZN3edg9a_booleanE __35756_60_include_func_params, 
a_decode_control_block_ptr __35757_60_dctl)
#line 8491
{


if ((((int)(*__35755_61_ptr)) == 84) || ((((int)(*__35755_61_ptr)) == 71) && (((int)(__35755_61_ptr[1])) == 86))) {
__35755_61_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_special_nameEPKcP22a_decode_control_block(__35755_61_ptr, __35757_60_dctl));
} else  {




_ZN29_INTERNAL_8_decode_c_f78890d330demangle_function_or_data_nameEPKcbbP22a_decode_control_block(__35755_61_ptr, __35756_60_include_func_params, ((_ZN3edg9a_booleanE)1), __35757_60_dctl);

if (!(__35757_60_dctl->err_in_id)) {
__35755_61_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d330demangle_function_or_data_nameEPKcbbP22a_decode_control_block(__35755_61_ptr, __35756_60_include_func_params, ((_ZN3edg9a_booleanE)0), __35757_60_dctl));

}
}
return __35755_61_ptr;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d319init_demangle_stateEPcyP22a_decode_control_block( char *__35791_61_output_buffer, 
_ZN3edg8sizeof_tE __35792_60_output_buffer_size, 
a_decode_control_block_ptr __35793_60_dctl)



{
_ZN29_INTERNAL_8_decode_c_f78890d319clear_control_blockEP22a_decode_control_block(__35793_60_dctl);
(__35793_60_dctl->output_id) = __35791_61_output_buffer;
(__35793_60_dctl->output_id_size) = __35792_60_output_buffer_size;
num_substitutions = 0UL; 
}
#line 8531
void _Z17decode_identifierPKcPcyPbS2_Py( _ZN3edg12a_const_charE *__35810_38_id, 
char *__35811_38_output_buffer, 
_ZN3edg8sizeof_tE __35812_37_output_buffer_size, 
_ZN3edg9a_booleanE *__35813_38_err, 
_ZN3edg9a_booleanE *__35814_38_buffer_overflow_err, 
_ZN3edg8sizeof_tE *__35815_38_required_buffer_size)
#line 8553
{
auto _ZN3edg12a_const_charE *__35833_31_end_ptr;
auto a_decode_control_block __35834_30_control_block;
auto a_decode_control_block_ptr __35835_30_dctl; __35835_30_dctl = (&__35834_30_control_block);

_ZN29_INTERNAL_8_decode_c_f78890d319init_demangle_stateEPcyP22a_decode_control_block(__35811_38_output_buffer, __35812_37_output_buffer_size, __35835_30_dctl);
{

auto int __35840_9_i = 1;
host_little_endian = ((_Bool)(((int)(*((char *)(&__35840_9_i)))) == 1));
}
for (; ; ) {
if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"_Z"), __35810_38_id)) {

__35833_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__35810_38_id + 2), ((_ZN3edg9a_booleanE)1), __35835_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__b_"), __35810_38_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"base of type "), __35835_30_dctl);
__35833_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__35810_38_id + 4), ((_ZN3edg9a_booleanE)1), __35835_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__v_"), __35810_38_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"virtual base of type "), __35835_30_dctl);
__35833_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__35810_38_id + 4), ((_ZN3edg9a_booleanE)1), __35835_30_dctl));
} else  {

__35833_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35810_38_id, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35835_30_dctl));
} } }
if (((__35835_30_dctl->err_in_id) && (__35835_30_dctl->contains_conversion_operator)) && (!(__35835_30_dctl->parse_template_args_after_conversion_operator)))

{
#line 8586
_ZN29_INTERNAL_8_decode_c_f78890d319init_demangle_stateEPcyP22a_decode_control_block(__35811_38_output_buffer, __35812_37_output_buffer_size, __35835_30_dctl);
(__35835_30_dctl->parse_template_args_after_conversion_operator) = ((_ZN3edg9a_booleanE)1);
} else  {
goto __T803230136;
}
} __T803230136:;
if (__35835_30_dctl->output_overflow_err) {
(__35835_30_dctl->err_in_id) = ((_ZN3edg9a_booleanE)1);
} else  {

((__35835_30_dctl->output_id)[(__35835_30_dctl->output_id_len)]) = ((char)0);
}

if (((!(__35835_30_dctl->err_in_id)) && (__35833_31_end_ptr != ((_ZN3edg12a_const_charE *)0))) && (((int)(*__35833_31_end_ptr)) != 0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35835_30_dctl);
}
(*__35813_38_err) = (__35835_30_dctl->err_in_id);
(*__35814_38_buffer_overflow_err) = (__35835_30_dctl->output_overflow_err);
(*__35815_38_required_buffer_size) = ((__35835_30_dctl->output_id_len) + 1ULL); 
}
#line 8621
char *__cxa_demangle( char *__35900_40_mangled_name, 
char *__35901_19_user_buffer, 
_ZN3edg11true_size_tE *__35902_25_user_buffer_size, 
int *__35903_18_status)
#line 8632
{

auto int __35913_8_result_status = 0;
auto char *__35914_10_result_buffer;

if ((__35901_19_user_buffer != ((char *)0)) && (__35902_25_user_buffer_size == ((_ZN3edg11true_size_tE *)0))) {

__35913_8_result_status = (-3);
__35914_10_result_buffer = ((char *)0);
} else  {

auto char __35922_10_temp_buffer[256];
auto char *__35923_11_buf_to_use = ((char *)0);
auto _ZN3edg8sizeof_tE __35924_14_buf_size = 0ULL;
auto _ZN3edg9a_booleanE __35925_15_err;
auto _ZN3edg9a_booleanE __35926_15_buffer_overflow_err;
auto _ZN3edg8sizeof_tE __35927_14_required_buffer_size;

if (__35901_19_user_buffer == ((char *)0)) {
__35923_11_buf_to_use = (__35922_10_temp_buffer);
__35924_14_buf_size = 256ULL;
} else  {
__35923_11_buf_to_use = __35901_19_user_buffer;
__35924_14_buf_size = (*__35902_25_user_buffer_size);
}
do {
_Z17decode_identifierPKcPcyPbS2_Py(((_ZN3edg12a_const_charE *)__35900_40_mangled_name), __35923_11_buf_to_use, __35924_14_buf_size, (&__35925_15_err), (&__35926_15_buffer_overflow_err), (&__35927_14_required_buffer_size));

if (__35926_15_buffer_overflow_err) {

if ((__35923_11_buf_to_use == (__35922_10_temp_buffer)) || (__35923_11_buf_to_use == __35901_19_user_buffer)) {
#line 8668
__35923_11_buf_to_use = ((char *)(malloc(((_ZN3edg11true_size_tE)__35927_14_required_buffer_size))));
} else  {

__35923_11_buf_to_use = ((char *)(realloc(((void *)__35923_11_buf_to_use), ((_ZN3edg11true_size_tE)__35927_14_required_buffer_size))));

}
__35924_14_buf_size = __35927_14_required_buffer_size;
if (__35923_11_buf_to_use == ((char *)0)) {

__35913_8_result_status = (-1);
}
} else  { if (__35925_15_err) {

__35913_8_result_status = (-2);
} }


} while ((__35925_15_err) && (__35913_8_result_status == 0));

if ((__35913_8_result_status == 0) && (__35923_11_buf_to_use == (__35922_10_temp_buffer))) {


auto _ZN3edg11true_size_tE __35969_19_size; __35969_19_size = ((strlen(((const char *)(__35922_10_temp_buffer)))) + 1ULL);

__35923_11_buf_to_use = ((char *)(malloc(__35969_19_size)));
if (__35923_11_buf_to_use == ((char *)0)) {

__35913_8_result_status = (-1);
} else  {
strcpy(__35923_11_buf_to_use, ((const char *)(__35922_10_temp_buffer)));
}
}

if (__35913_8_result_status == 0) {


if ((__35901_19_user_buffer != ((char *)0)) && (__35923_11_buf_to_use != __35901_19_user_buffer)) {
free(((void *)__35901_19_user_buffer));

if (__35902_25_user_buffer_size != ((_ZN3edg11true_size_tE *)0)) {
(*__35902_25_user_buffer_size) = __35924_14_buf_size;
}
}
} else  {

if ((__35923_11_buf_to_use != (__35922_10_temp_buffer)) && (__35923_11_buf_to_use != __35901_19_user_buffer)) {
free(((void *)__35923_11_buf_to_use));
}
}

if (__35913_8_result_status == 0) {
__35914_10_result_buffer = __35923_11_buf_to_use;
} else  {
__35914_10_result_buffer = ((char *)0);
}
}

if (__35903_18_status != ((int *)0)) { (*__35903_18_status) = __35913_8_result_status; }



return __35914_10_result_buffer;


}
