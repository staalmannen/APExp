/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:16 2026 */
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
#line 66 "ape-sys/stdlib.h"
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
static void _ZN29_INTERNAL_8_decode_c_f78890d319clear_control_blockEP22a_decode_control_block( a_decode_control_block_ptr __27562_60_dctl)



{
(__27562_60_dctl->output_id) = ((char *)0);
(__27562_60_dctl->output_id_len) = 0ULL;
(__27562_60_dctl->output_id_size) = 0ULL;
(__27562_60_dctl->err_in_id) = ((_ZN3edg9a_booleanE)0);
(__27562_60_dctl->output_overflow_err) = ((_ZN3edg9a_booleanE)0);
(__27562_60_dctl->suppress_id_output) = 0UL;
(__27562_60_dctl->uncompressed_length) = 0ULL;




(__27562_60_dctl->suppress_substitution_recording) = 0UL;
(__27562_60_dctl->contains_conversion_operator) = ((_ZN3edg9a_booleanE)0);
(__27562_60_dctl->parse_template_args_after_conversion_operator) = ((_ZN3edg9a_booleanE)0);
(__27562_60_dctl->suppress_template_parameters) = 0UL; 

}
#line 289
static void _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block( char __27700_52_ch, 
a_decode_control_block_ptr __27701_52_dctl)



{
if (!(__27701_52_dctl->suppress_id_output)) {
if (!(__27701_52_dctl->output_overflow_err)) {

if (((__27701_52_dctl->output_id_len) + 1ULL) >= (__27701_52_dctl->output_id_size)) {

(__27701_52_dctl->output_overflow_err) = ((_ZN3edg9a_booleanE)1);

if ((__27701_52_dctl->output_id_size) != 0ULL) {
((__27701_52_dctl->output_id)[((__27701_52_dctl->output_id_size) - 1ULL)]) = ((char)0);
}
} else  {

((__27701_52_dctl->output_id)[(__27701_52_dctl->output_id_len)]) = __27700_52_ch;
}
}


(__27701_52_dctl->output_id_len)++;
} 
}


static void _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__27728_53_str, 
a_decode_control_block_ptr __27729_52_dctl)



{
auto _ZN3edg12a_const_charE *__27734_17_p; __27734_17_p = __27728_53_str;

if (!(__27729_52_dctl->suppress_id_output)) {
for (; ((int)(*__27734_17_p)) != 0; __27734_17_p++) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__27734_17_p), __27729_52_dctl); }
} 
}


static void _ZN29_INTERNAL_8_decode_c_f78890d315write_id_numberEmP22a_decode_control_block( unsigned long __27742_56_num, 
a_decode_control_block_ptr __27743_56_dctl)




{
auto char __27749_17_buffer[50];

snprintf((__27749_17_buffer), 50ULL, ((const char *)"%lu"), __27742_56_num);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__27749_17_buffer)), __27743_56_dctl); 
}



static void _ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block( long __27757_63_num, 
a_decode_control_block_ptr __27758_63_dctl)




{
auto char __27764_17_buffer[50];

snprintf((__27764_17_buffer), 50ULL, ((const char *)"%ld"), __27757_63_num);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__27764_17_buffer)), __27758_63_dctl); 
}



static void _ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block( a_decode_control_block_ptr __27772_57_dctl)



{
if (!(__27772_57_dctl->err_in_id)) {
(__27772_57_dctl->err_in_id) = ((_ZN3edg9a_booleanE)1);
(__27772_57_dctl->suppress_id_output)++;

(__27772_57_dctl->suppress_substitution_recording)++;

} 
}



static char _ZN29_INTERNAL_8_decode_c_f78890d38get_charEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__27788_61_ptr, 
a_decode_control_block_ptr __27789_60_dctl)




{
return *__27788_61_ptr;
}


static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_( _ZN3edg12a_const_charE *__27799_47_str, 
_ZN3edg12a_const_charE *__27800_47_id)



{
auto _ZN3edg9a_booleanE __27805_13_is_start = ((_ZN3edg9a_booleanE)0);

for (; ; ) {
auto char __27808_10_chs; __27808_10_chs = (*(__27799_47_str++));
if (((int)__27808_10_chs) == 0) {
__27805_13_is_start = ((_ZN3edg9a_booleanE)1);
goto __T747995208;
}
if (((int)__27808_10_chs) != ((int)(*(__27800_47_id++)))) { goto __T747995208; }
} __T747995208:;
return __27805_13_is_start;
}
#line 450
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block( const char __27861_62_ch, 
_ZN3edg12a_const_charE *__27862_63_p, 
a_decode_control_block_ptr __27863_62_dctl)




{
if (((int)(_ZN29_INTERNAL_8_decode_c_f78890d38get_charEPKcP22a_decode_control_block(__27862_63_p, __27863_62_dctl))) == ((int)__27861_62_ch)) {
__27862_63_p++;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__27863_62_dctl);
}
return __27862_63_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__27878_74_p, 
a_decode_control_block_ptr __27879_73_dctl)




{
return _ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __27878_74_p, __27879_73_dctl);
}
#line 487
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318demangle_module_idEPKcmS1_P22a_decode_control_block( _ZN3edg12a_const_charE *__27898_69_ptr, 
unsigned long __27899_68_num, 
_ZN3edg12a_const_charE *__27900_69_prefix, 
a_decode_control_block_ptr __27901_68_dctl)
#line 502
{

auto long __27915_9_num_chars_to_output;



auto _ZN3edg12a_const_charE *__27919_18_start;

if ((((int)(*__27898_69_ptr)) != 95) || (!(((int)((_ctype)[((unsigned char)((unsigned char)(__27898_69_ptr[1])))])) & 4))) {


if (__27900_69_prefix != ((_ZN3edg12a_const_charE *)0)) {
while (__27900_69_prefix != __27898_69_ptr) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*(__27900_69_prefix++)), __27901_68_dctl); }
}
__27915_9_num_chars_to_output = ((long)__27899_68_num);
__27919_18_start = __27898_69_ptr;
} else  {
__27919_18_start = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__27898_69_ptr + 1), (&__27915_9_num_chars_to_output), __27901_68_dctl));
if (!(__27901_68_dctl->err_in_id)) {
auto uint32_t __27932_16_prefix_len; __27932_16_prefix_len = ((uint32_t)((__27919_18_start - __27898_69_ptr) + 1LL));
if (((((int)(*__27919_18_start)) != 95) || (__27915_9_num_chars_to_output <= 0L)) || (__27899_68_num < (((unsigned long)__27915_9_num_chars_to_output) + ((unsigned long)__27932_16_prefix_len))))



{
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__27901_68_dctl);
} else  {

__27919_18_start++;
}
}
}
if (!(__27901_68_dctl->err_in_id)) {

while ((__27915_9_num_chars_to_output--) > 0L) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*(__27919_18_start++)), __27901_68_dctl); }
}
return __27898_69_ptr + __27899_68_num;
}
#line 4531
static void _ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block( a_func_block *__31942_44_func_block)



{
(__31942_44_func_block->no_return_type) = ((_ZN3edg9a_booleanE)0);
(__31942_44_func_block->cv_quals) = 0;
(__31942_44_func_block->ref_qual) = 0;
(__31942_44_func_block->ctor_dtor_kind) = ((_ZN3edg12a_const_charE *)0); 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block( _ZN3edg12a_const_charE *__31954_61_p, 
long *__31955_61_num, 
a_decode_control_block_ptr __31956_60_dctl)
#line 4551
{
auto long __31963_13_n = 0L;
auto _ZN3edg9a_booleanE __31964_13_negative = ((_ZN3edg9a_booleanE)0);

if (((int)(*__31954_61_p)) == 110) {
__31964_13_negative = ((_ZN3edg9a_booleanE)1);
__31954_61_p++;
}
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__31954_61_p)))])) & 4)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31956_60_dctl);
} else  {
do {
__31963_13_n = ((__31963_13_n * 10L) + ((long)(((int)(*__31954_61_p)) - 48)));
__31954_61_p++;
} while (((int)((_ctype)[((unsigned char)((unsigned char)(*__31954_61_p)))])) & 4);
}
if (__31964_13_negative) { __31963_13_n = (-__31963_13_n); }
(*__31955_61_num) = __31963_13_n;
return __31954_61_p;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(
_ZN3edg12a_const_charE *__31985_61_start, 
enum a_substitution_kind __31986_60_kind, 
unsigned long __31987_60_num_levels, 
_ZN3edg9a_booleanE __31988_60_parse_template_args, 
a_decode_control_block_ptr __31989_60_dctl)
#line 4589
{


if (!(__31989_60_dctl->suppress_substitution_recording)) {
auto unsigned long __32004_29_number;
auto a_substitution_location *__32005_30_subp;
#line 4593
__32004_29_number = (num_substitutions++);

if (num_substitutions > allocated_substitutions) {

auto _ZN3edg11true_size_tE __32008_19_new_size;
allocated_substitutions += 500UL;
__32008_19_new_size = (((unsigned long long)allocated_substitutions) * 24ULL);
if (substitutions == ((a_substitution_location *)0)) {
substitutions = ((a_substitution_location *)(malloc(__32008_19_new_size)));
} else  {
substitutions = ((a_substitution_location *)(realloc(((void *)substitutions), __32008_19_new_size)));

}
if (substitutions == ((a_substitution_location *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__31989_60_dctl);
return;
}
}
__32005_30_subp = (substitutions + __32004_29_number);
(__32005_30_subp->start) = __31985_61_start;
(__32005_30_subp->kind) = __31986_60_kind;
(__32005_30_subp->num_levels) = __31987_60_num_levels;
(__32005_30_subp->parse_template_args) = __31988_60_parse_template_args;
} 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(
_ZN3edg12a_const_charE *__32032_58_ptr, 
int __32033_57_type_pass_num, 
a_cv_qualifier_set __32034_57_cv_quals, 
_ZN3edg9a_booleanE __32035_57_under_lhs_declarator, 
_ZN3edg9a_booleanE __32036_57_need_trailing_space, 
_ZN3edg12a_const_charE **__32037_59_last_component_name, 
_ZN3edg12a_const_charE **__32038_59_substitution, 
a_decode_control_block_ptr __32039_57_dctl)
#line 4664
{
auto char __32076_8_ch2; __32076_8_ch2 = (__32032_58_ptr[1]);

if (__32037_59_last_component_name != ((_ZN3edg12a_const_charE **)0)) { (*__32037_59_last_component_name) = ((_ZN3edg12a_const_charE *)0); }
if (__32038_59_substitution != ((_ZN3edg12a_const_charE **)0)) { (*__32038_59_substitution) = ((_ZN3edg12a_const_charE *)0); }
if (((int)((_ctype)[((unsigned char)((unsigned char)__32076_8_ch2))])) & 2) {

auto _ZN3edg12a_const_charE *__32082_19_str = ((const char *)"");
auto _ZN3edg12a_const_charE *__32083_19_last_name = ((const char *)"");
if (((int)__32076_8_ch2) == 116) {
__32082_19_str = ((const char *)"std");
__32083_19_last_name = ((const char *)"3std");
} else  { if (((int)__32076_8_ch2) == 97) {
__32082_19_str = ((const char *)"std::allocator");
__32083_19_last_name = ((const char *)"9allocator");
} else  { if (((int)__32076_8_ch2) == 98) {
__32082_19_str = ((const char *)"std::basic_string");
__32083_19_last_name = ((const char *)"12basic_string");
} else  { if (((int)__32076_8_ch2) == 115) {
__32082_19_str = ((const char *)"std::basic_string<char, std::char_traits<char>, std::allocator<char>>");

__32083_19_last_name = ((const char *)"12basic_string");
} else  { if (((int)__32076_8_ch2) == 105) {
__32082_19_str = ((const char *)"std::basic_istream<char, std::char_traits<char>>");
__32083_19_last_name = ((const char *)"13basic_istream");
} else  { if (((int)__32076_8_ch2) == 111) {
__32082_19_str = ((const char *)"std::basic_ostream<char, std::char_traits<char>>");
__32083_19_last_name = ((const char *)"13basic_ostream");
} else  { if (((int)__32076_8_ch2) == 100) {
__32082_19_str = ((const char *)"std::basic_iostream<char, std::char_traits<char>>");
__32083_19_last_name = ((const char *)"14basic_iostream");
} } } } } } }

if (__32033_57_type_pass_num != 2) {
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32034_57_cv_quals, ((_ZN3edg9a_booleanE)1), __32039_57_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__32082_19_str, __32039_57_dctl);
}
__32032_58_ptr += 2;
if (__32037_59_last_component_name != ((_ZN3edg12a_const_charE **)0)) { (*__32037_59_last_component_name) = __32083_19_last_name; }
} else  {

auto uint32_t __32116_29_number = 0U;
auto a_substitution_location *__32117_30_subp;
auto _ZN3edg12a_const_charE *__32118_21_p;
__32032_58_ptr++;
if (((int)__32076_8_ch2) != 95) {
auto _ZN3edg12a_const_charE __32121_30_digits[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
do {
__32116_29_number *= 36U;
if (((int)(*__32032_58_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32039_57_dctl);
goto __T748222360;
}
__32118_21_p = ((_ZN3edg12a_const_charE *)(strchr((__32121_30_digits), ((int)(*__32032_58_ptr)))));
if (__32118_21_p == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32039_57_dctl);
goto __T748222360;
}
__32116_29_number += ((uint32_t)(__32118_21_p - (__32121_30_digits)));
__32032_58_ptr++;
} while (((int)(*__32032_58_ptr)) != 95); __T748222360:;
__32116_29_number++;
}
if (((unsigned long)__32116_29_number) >= num_substitutions) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32039_57_dctl);
} else  {
auto a_func_block __32141_20_func_block;
__32032_58_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32032_58_ptr, __32039_57_dctl));
__32117_30_subp = (substitutions + __32116_29_number);
__32118_21_p = (__32117_30_subp->start);
if (__32038_59_substitution != ((_ZN3edg12a_const_charE **)0)) { (*__32038_59_substitution) = __32118_21_p; }



(__32039_57_dctl->suppress_substitution_recording)++;
if ((__32033_57_type_pass_num == 2) && (((int)(__32117_30_subp->kind)) != 3)) {




} else  {
switch ((int)(__32117_30_subp->kind)) {
case 0:
if ((__32033_57_type_pass_num == 1) || (__32033_57_type_pass_num == 0)) {


_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32034_57_cv_quals, ((_ZN3edg9a_booleanE)1), __32039_57_dctl);
}
_ZN29_INTERNAL_8_decode_c_f78890d322demangle_unscoped_nameEPKcP12a_func_blockP22a_decode_control_block(__32118_21_p, (&__32141_20_func_block), __32039_57_dctl);
goto __T748239384;
case 1:
case 2:
{ auto _ZN3edg9a_booleanE __32167_25_is_no_return_name; auto _ZN3edg9a_booleanE __32167_44_has_templ_arg_list;
auto _ZN3edg12a_const_charE *__32168_29_ctor_dtor_kind;
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32034_57_cv_quals, ((_ZN3edg9a_booleanE)1), __32039_57_dctl);



if ((__32117_30_subp->num_levels) > 0UL) {
__32118_21_p = (_ZN29_INTERNAL_8_decode_c_f78890d331demangle_nested_name_componentsEPKcmPbS2_PS1_S3_P22a_decode_control_block(__32118_21_p, (__32117_30_subp->num_levels), (&__32167_25_is_no_return_name), (&__32167_44_has_templ_arg_list), (&__32168_29_ctor_dtor_kind), 
#line 4763
__32037_59_last_component_name, __32039_57_dctl));
#line 4770
}
if (((int)(__32117_30_subp->kind)) == 2) {


if ((__32117_30_subp->num_levels) > 0UL) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __32039_57_dctl); }
__32118_21_p = (_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__32118_21_p, (&__32167_25_is_no_return_name), __32039_57_dctl));
}
}
goto __T748239384;
case 3:
if ((__32033_57_type_pass_num == 1) || (__32033_57_type_pass_num == 0)) {



_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32118_21_p, __32034_57_cv_quals, __32035_57_under_lhs_declarator, __32036_57_need_trailing_space, (__32117_30_subp->parse_template_args), __32039_57_dctl);




}
if ((__32033_57_type_pass_num == 2) || (__32033_57_type_pass_num == 0)) {
_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__32118_21_p, __32034_57_cv_quals, __32035_57_under_lhs_declarator, __32039_57_dctl);

}
goto __T748239384;
case 4:
_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__32118_21_p, __32039_57_dctl);
goto __T748239384;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32039_57_dctl);
} __T748239384:;
}
(__32039_57_dctl->suppress_substitution_recording)--;
}
}
return __32032_58_ptr;
}
#line 4820
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(
_ZN3edg12a_const_charE *__32232_66_ptr, 
_ZN3edg9a_booleanE __32233_65_no_return_type, 
a_bare_function_type_option __32234_65_options, 
a_decode_control_block_ptr __32235_65_dctl)
#line 4845
{
#line 4852
if ((__32234_65_options & 0x1) == 0) { (__32235_65_dctl->suppress_id_output)++; }
if (!(__32233_65_no_return_type)) {

__32232_66_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32232_66_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32235_65_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32235_65_dctl);
}
if ((__32234_65_options & 0x1) == 0) { (__32235_65_dctl->suppress_id_output)--; }

if ((__32234_65_options & 0x2) == 0) { (__32235_65_dctl->suppress_id_output)++; }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32235_65_dctl);
if (((((int)(*__32232_66_ptr)) == 69) || (((int)(*__32232_66_ptr)) == 0)) || (((((int)(*__32232_66_ptr)) == 82) || (((int)(*__32232_66_ptr)) == 79)) && (((int)(*(__32232_66_ptr + 1))) == 69))) {



_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32235_65_dctl);
} else  { if ((((int)(*__32232_66_ptr)) == 118) && (((((int)(*(__32232_66_ptr + 1))) == 69) || (((int)(*(__32232_66_ptr + 1))) == 0)) || (((((int)(*(__32232_66_ptr + 1))) == 82) || (((int)(*(__32232_66_ptr + 1))) == 79)) && (((int)(*((__32232_66_ptr + 1) + 1))) == 69)))) {


__32232_66_ptr++;
} else  {
for (; ; ) {
if (((int)(*__32232_66_ptr)) == 122) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __32235_65_dctl);
__32232_66_ptr++;
if (!(((((int)(*__32232_66_ptr)) == 69) || (((int)(*__32232_66_ptr)) == 0)) || (((((int)(*__32232_66_ptr)) == 82) || (((int)(*__32232_66_ptr)) == 79)) && (((int)(*(__32232_66_ptr + 1))) == 69)))) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32235_65_dctl);
goto __T748296840;
}
} else  {

__32232_66_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32232_66_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32235_65_dctl));
}

if (((((int)(*__32232_66_ptr)) == 69) || (((int)(*__32232_66_ptr)) == 0)) || (((((int)(*__32232_66_ptr)) == 82) || (((int)(*__32232_66_ptr)) == 79)) && (((int)(*(__32232_66_ptr + 1))) == 69))) { goto __T748296840; }

if (__32235_65_dctl->err_in_id) { goto __T748296840; }

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __32235_65_dctl);
} __T748296840:;
} }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32235_65_dctl);
if ((__32234_65_options & 0x2) == 0) { (__32235_65_dctl->suppress_id_output)--; }
return __32232_66_ptr;

}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi( _ZN3edg12a_const_charE *__32311_60_ptr, 
a_cv_qualifier_set *__32312_60_cv_quals)
#line 4913
{
(*__32312_60_cv_quals) = 0;
for (; ; __32311_60_ptr++) {
if (((int)(*__32311_60_ptr)) == 75) {
(*__32312_60_cv_quals) |= 0x1;
} else  { if (((int)(*__32311_60_ptr)) == 86) {
(*__32312_60_cv_quals) |= 0x2;
} else  { if (((int)(*__32311_60_ptr)) == 114) {
(*__32312_60_cv_quals) |= 0x4;
} else  {
goto __T748320352;
} } }
} __T748320352:;
return __32311_60_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi( _ZN3edg12a_const_charE *__32341_57_ptr, 
a_ref_qualifier *__32342_57_ref_qual)
#line 4937
{
(*__32342_57_ref_qual) = 0;
if (((int)(*__32341_57_ptr)) == 82) {
(*__32342_57_ref_qual) = 0x1;
__32341_57_ptr++;
} else  { if (((int)(*__32341_57_ptr)) == 79) {
(*__32342_57_ref_qual) = 0x2;
__32341_57_ptr++;
} }
return __32341_57_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d330demangle_vector_size_qualifierEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__32362_76_ptr, 
a_decode_control_block_ptr __32363_75_dctl)
#line 4958
{
if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"U8__vector"), __32362_76_ptr)) {
__32362_76_ptr += 10;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__attribute__((vector_size(\?))) "), __32363_75_dctl);
}
return __32362_76_ptr;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block( a_cv_qualifier_set __32378_61_cv_quals, 
_ZN3edg9a_booleanE __32379_61_trailing_space, 
a_decode_control_block_ptr __32380_61_dctl)
#line 4975
{
auto _ZN3edg9a_booleanE __32387_13_any_previous = ((_ZN3edg9a_booleanE)0);

if (__32378_61_cv_quals & 0x1) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"const"), __32380_61_dctl);
__32387_13_any_previous = ((_ZN3edg9a_booleanE)1);
}
if (__32378_61_cv_quals & 0x2) {
if (__32387_13_any_previous) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32380_61_dctl); }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"volatile"), __32380_61_dctl);
__32387_13_any_previous = ((_ZN3edg9a_booleanE)1);
}
if (__32378_61_cv_quals & 0x4) {
if (__32387_13_any_previous) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32380_61_dctl); }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"restrict"), __32380_61_dctl);
__32387_13_any_previous = ((_ZN3edg9a_booleanE)1);
}
if ((__32387_13_any_previous) && (__32379_61_trailing_space)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32380_61_dctl); } 
}


static void _ZN29_INTERNAL_8_decode_c_f78890d320output_ref_qualifierEiP22a_decode_control_block( a_ref_qualifier __32407_61_ref_qual, 
a_decode_control_block_ptr __32408_61_dctl)



{
if (__32407_61_ref_qual == 0x1) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"&"), __32408_61_dctl);
} else  { if (__32407_61_ref_qual & 0x2) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"&&"), __32408_61_dctl);
} } 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__32421_74_ptr, 
a_decode_control_block_ptr __32422_73_dctl)
#line 5022
{
auto long __32434_8_num = 1L;
auto char __32435_8_buffer[50];


__32421_74_ptr++;
if (((int)(*__32421_74_ptr)) != 95) {
__32421_74_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32421_74_ptr, (&__32434_8_num), __32422_73_dctl));
if (__32434_8_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32422_73_dctl);
__32434_8_num = 0L;
} else  {
__32434_8_num += 2L;
}
}
__32421_74_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32421_74_ptr, __32422_73_dctl));
snprintf((__32435_8_buffer), 50ULL, ((const char *)"T%ld"), __32434_8_num);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__32435_8_buffer)), __32422_73_dctl);
return __32421_74_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d328demangle_parameter_referenceEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__32456_76_ptr, 
a_decode_control_block_ptr __32457_75_dctl)
#line 5069
{
auto long __32481_22_num = 1L; auto long __32481_31_level = (-1L);
auto char __32482_22_buffer[51];
auto a_cv_qualifier_set __32483_22_cv_quals;


__32456_76_ptr++;
if (((int)(*__32456_76_ptr)) == 76) {

__32456_76_ptr++;
__32456_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32456_76_ptr, (&__32481_31_level), __32457_75_dctl));
if (__32481_31_level < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32457_75_dctl);
goto __32536_1_end_of_routine;
} else  {
__32481_31_level += 1L;
}
}
if (((int)(*__32456_76_ptr)) != 112) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32457_75_dctl);
goto __32536_1_end_of_routine;
}
__32456_76_ptr++;
if (((int)(*__32456_76_ptr)) == 84) {

__32456_76_ptr++;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"this"), __32457_75_dctl);
} else  {
if ((((int)(*__32456_76_ptr)) != 95) && (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__32456_76_ptr)))])) & 4))) {

__32456_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__32456_76_ptr, (&__32483_22_cv_quals)));
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32483_22_cv_quals, ((_ZN3edg9a_booleanE)1), __32457_75_dctl);
}
if (((int)(*__32456_76_ptr)) != 95) {

__32456_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32456_76_ptr, (&__32481_22_num), __32457_75_dctl));
if (__32481_22_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32457_75_dctl);
goto __32536_1_end_of_routine;
} else  {
__32481_22_num += 2L;
}
}
__32456_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32456_76_ptr, __32457_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"param#"), __32457_75_dctl);
if (__32481_31_level == (-1L)) {
snprintf((__32482_22_buffer), 51ULL, ((const char *)"%ld"), __32481_22_num);
} else  {



snprintf((__32482_22_buffer), 51ULL, ((const char *)"%ld[up %ld level%s]"), __32481_22_num, __32481_31_level, ((__32481_31_level > 1L) ? ((const char *)("s")) : ((const char *)(""))));

}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__32482_22_buffer)), __32457_75_dctl);
}
__32536_1_end_of_routine:;
return __32456_76_ptr;
}
#line 5164
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d323demangle_type_specifierEPKcbP22a_decode_control_block(
_ZN3edg12a_const_charE *__32576_61_ptr, 
_ZN3edg9a_booleanE __32577_60_parse_template_args, 
a_decode_control_block_ptr __32578_60_dctl)
#line 5192
{
auto _ZN3edg12a_const_charE *__32604_17_p; auto _ZN3edg12a_const_charE *__32604_27_s = ((const char *)"");
auto long __32605_16_num;
#line 5193
__32604_17_p = __32576_61_ptr;




if (!(((((int)((_ctype)[((unsigned char)((unsigned char)(*__32604_17_p)))])) & 2) && (((int)(*__32604_17_p)) != 114)) || ((((int)(*__32604_17_p)) == 68) && (!((((((((int)(__32604_17_p[1])) == 112) || (((int)(__32604_17_p[1])) == 114)) || (((int)(__32604_17_p[1])) == 84)) || (((int)(__32604_17_p[1])) 
#line 5198
== 116)) || (((int)(__32604_17_p[1])) == 89)) || (((int)(__32604_17_p[1])) == 121)))))) {
if (((int)(*__32604_17_p)) == 84) {

auto _ZN3edg12a_const_charE *__32612_21_tstart; __32612_21_tstart = __32604_17_p;
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__32604_17_p, __32578_60_dctl));
if ((((int)(*__32604_17_p)) == 73) && (__32577_60_parse_template_args)) {



_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__32612_21_tstart, subk_template_template_param, 0UL, ((_ZN3edg9a_booleanE)0), __32578_60_dctl);

__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__32604_17_p, __32578_60_dctl));
}
} else  { if ((((int)(*__32604_17_p)) == 68) && (((int)(__32604_17_p[1])) == 112)) {

__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__32604_17_p + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)1), __32578_60_dctl));

} else  { if ((((int)(*__32604_17_p)) == 68) && ((((int)(__32604_17_p[1])) == 116) || (((int)(__32604_17_p[1])) == 84)))
{




_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"decltype("), __32578_60_dctl);
if (((int)(__32604_17_p[1])) == 116) {
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32604_17_p + 2), __32578_60_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32578_60_dctl);
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32604_17_p + 2), __32578_60_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32578_60_dctl);
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32578_60_dctl);
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32604_17_p, __32578_60_dctl));
} else  { if ((((int)(*__32604_17_p)) == 68) && ((((int)(__32604_17_p[1])) == 121) || (((int)(__32604_17_p[1])) == 89)))
{
#line 5240
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"typeof("), __32578_60_dctl);
if (((int)(__32604_17_p[1])) == 121) {
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__32604_17_p + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32578_60_dctl));
} else  {
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32604_17_p + 2), __32578_60_dctl));
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __32578_60_dctl);
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32604_17_p, __32578_60_dctl));
} else  { if ((((int)(*__32604_17_p)) == 68) && (((int)(__32604_17_p[1])) == 114)) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[:"), __32578_60_dctl);
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32604_17_p + 2), __32578_60_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)":]"), __32578_60_dctl);
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32604_17_p, __32578_60_dctl));
} else  {

auto a_func_block __32669_20_func_block;
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block(__32604_17_p, (&__32669_20_func_block), 0x3, __32578_60_dctl));
} } } } }
} else  {

switch ((int)(*(__32604_17_p++))) {
case 118:
__32604_27_s = ((const char *)"void");
goto __T748468632;
case 119:
__32604_27_s = ((const char *)"wchar_t");
goto __T748468632;
case 98:
__32604_27_s = ((const char *)"bool");
goto __T748468632;
case 99:
__32604_27_s = ((const char *)"char");
goto __T748468632;
case 97:
__32604_27_s = ((const char *)"signed char");
goto __T748468632;
case 104:
__32604_27_s = ((const char *)"unsigned char");
goto __T748468632;
case 115:
__32604_27_s = ((const char *)"short");
goto __T748468632;
case 116:
__32604_27_s = ((const char *)"unsigned short");
goto __T748468632;
case 105:
__32604_27_s = ((const char *)"int");
goto __T748468632;
case 106:
__32604_27_s = ((const char *)"unsigned int");
goto __T748468632;
case 108:
__32604_27_s = ((const char *)"long");
goto __T748468632;
case 109:
__32604_27_s = ((const char *)"unsigned long");
goto __T748468632;
case 120:
__32604_27_s = ((const char *)"long long");
goto __T748468632;
case 121:
__32604_27_s = ((const char *)"unsigned long long");
goto __T748468632;
case 110:
__32604_27_s = ((const char *)"__int128");
goto __T748468632;
case 111:
__32604_27_s = ((const char *)"unsigned __int128");
goto __T748468632;
case 102:
__32604_27_s = ((const char *)"float");
goto __T748468632;
case 100:
__32604_27_s = ((const char *)"double");
goto __T748468632;
case 101:

__32604_27_s = ((const char *)"long double");
goto __T748468632;
case 103:
__32604_27_s = ((const char *)"__float128");
goto __T748468632;
case 117:


__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__32604_17_p, ((_ZN3edg9a_booleanE)0), __32578_60_dctl));
if (((int)(*__32604_17_p)) == 73) {

__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__32604_17_p, __32578_60_dctl));
}
__32604_27_s = ((const char *)"");
goto __T748468632;
case 68:


switch ((int)(*(__32604_17_p++))) {
case 97:
__32604_27_s = ((const char *)"auto");
goto __T748507416;
case 99:
__32604_27_s = ((const char *)"decltype(auto)");
goto __T748507416;
case 70:




__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32604_17_p, (&__32605_16_num), __32578_60_dctl));
if ((((int)(*__32604_17_p)) == 98) && (__32605_16_num == 16L)) {
__32604_27_s = ((const char *)"std::bfloat16_t");
} else  { if (((int)(*__32604_17_p)) == 120) {
switch (__32605_16_num) {
case 32L: __32604_27_s = ((const char *)"_Float32x"); goto __T748517040;
case 64L: __32604_27_s = ((const char *)"_Float64x"); goto __T748517040;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32578_60_dctl);
goto __T748517040;
} __T748517040:;
} else  { if (((int)(*__32604_17_p)) == 95) {



switch (__32605_16_num) {
case 16L: __32604_27_s = ((const char *)"_Float16"); goto __T748522896;
case 32L: __32604_27_s = ((const char *)"_Float32"); goto __T748522896;
case 64L: __32604_27_s = ((const char *)"_Float64"); goto __T748522896;
case 128L: __32604_27_s = ((const char *)"_Float128"); goto __T748522896;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32578_60_dctl);
goto __T748522896;
} __T748522896:;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32578_60_dctl);
} } }
++__32604_17_p;
goto __T748507416;
case 104:
__32604_27_s = ((const char *)"__fp16");
goto __T748507416;
case 110:
__32604_27_s = ((const char *)"std::nullptr_t");
goto __T748507416;
case 78:

__32604_27_s = ((const char *)"__nullptr");
goto __T748507416;
case 117:
__32604_27_s = ((const char *)"char8_t");
goto __T748507416;
case 115:
__32604_27_s = ((const char *)"char16_t");
goto __T748507416;
case 105:
__32604_27_s = ((const char *)"char32_t");
goto __T748507416;
case 118:




{ auto _ZN3edg12a_const_charE *__32814_29_typep;
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32604_17_p, (&__32605_16_num), __32578_60_dctl));
if (((int)(*__32604_17_p)) != 95) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32578_60_dctl);
} else  {
__32604_17_p++;
__32814_29_typep = __32604_17_p;
__32604_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32604_17_p, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32578_60_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" __attribute((vector_size("), __32578_60_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block(__32605_16_num, __32578_60_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"*sizeof("), __32578_60_dctl);
(__32578_60_dctl->suppress_substitution_recording)++;
_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32814_29_typep, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32578_60_dctl);
(__32578_60_dctl->suppress_substitution_recording)--;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")))) "), __32578_60_dctl);
}
__32604_27_s = ((const char *)"");
}
goto __T748507416;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32578_60_dctl);
__32604_27_s = ((const char *)"");
} __T748507416:;
goto __T748468632;
case 122:

default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32578_60_dctl);
__32604_27_s = ((const char *)"");
} __T748468632:;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__32604_27_s, __32578_60_dctl);
}
return __32604_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324skip_extern_C_indicationEPKc( _ZN3edg12a_const_charE *__32850_61_ptr)
#line 5447
{
if (((int)(*__32850_61_ptr)) == 89) { __32850_61_ptr++; }
return __32850_61_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(
_ZN3edg12a_const_charE *__32865_60_ptr, 
a_cv_qualifier_set __32866_59_cv_quals, 
_ZN3edg9a_booleanE __32867_59_under_lhs_declarator, 
_ZN3edg9a_booleanE __32868_59_need_trailing_space, 
_ZN3edg9a_booleanE __32869_59_parse_template_args, 
a_decode_control_block_ptr __32870_59_dctl)
#line 5473
{
auto _ZN3edg12a_const_charE *__32885_23_p; auto _ZN3edg12a_const_charE *__32885_33_qualp; auto _ZN3edg12a_const_charE *__32885_45_unqualp;
auto char __32886_22_kind;
auto a_cv_qualifier_set __32887_22_local_cv_quals;
auto _ZN3edg9a_booleanE __32888_22_record_substitution = ((_ZN3edg9a_booleanE)1);
auto _ZN3edg9a_booleanE __32889_22_record_cv_qual_substitution = ((_ZN3edg9a_booleanE)1);
#line 5474
__32885_23_p = __32865_60_ptr; __32885_33_qualp = __32885_23_p;
#line 5481
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__32885_23_p, (&__32887_22_local_cv_quals)));
__32866_59_cv_quals |= __32887_22_local_cv_quals;
__32885_45_unqualp = __32885_23_p;
__32886_22_kind = (*__32885_23_p);
if ((((int)__32886_22_kind) == 83) && (((int)(__32885_23_p[1])) != 116))

{

__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__32885_23_p, 1, __32866_59_cv_quals, __32867_59_under_lhs_declarator, __32868_59_need_trailing_space, ((_ZN3edg12a_const_charE **)0), ((_ZN3edg12a_const_charE **)0), __32870_59_dctl));
#line 5495
__32888_22_record_substitution = ((_ZN3edg9a_booleanE)0);
if (((int)(*__32885_23_p)) == 73) {

__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__32885_23_p, __32870_59_dctl));
__32888_22_record_substitution = ((_ZN3edg9a_booleanE)1);
}
} else  { if (((((((int)__32886_22_kind) == 80) || (((int)__32886_22_kind) == 82)) || (((int)__32886_22_kind) == 79)) || (((int)__32886_22_kind) == 67)) || ((((int)__32886_22_kind) == 85) && (!(_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"U8__vector"), __32885_23_p)))))
{
auto _ZN3edg12a_const_charE *__32914_19_vendor_ext = ((_ZN3edg12a_const_charE *)0);
auto char *__32915_19_vendor_ext_buffer = ((char *)0);
auto _ZN3edg9a_booleanE __32916_18_need_space = ((_ZN3edg9a_booleanE)1);
#line 5514
__32885_23_p++;
if (((int)__32886_22_kind) == 85) {
#line 5522
auto long __32933_12_num;
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__32885_23_p, (&__32933_12_num), __32870_59_dctl));
if ((__32933_12_num == 8L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__handle"), __32885_23_p))) {
__32914_19_vendor_ext = ((const char *)"^");
} else  { if ((__32933_12_num == 8L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__trkref"), __32885_23_p))) {
__32914_19_vendor_ext = ((const char *)"%");
} else  { if ((__32933_12_num == 8L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__vector"), __32885_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__attribute__((vector_size(\?))) "), __32870_59_dctl);
__32916_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32933_12_num == 14L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__interior_ptr"), __32885_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"interior_ptr<"), __32870_59_dctl);
__32914_19_vendor_ext = ((const char *)">");
__32916_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32933_12_num == 9L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__pin_ptr"), __32885_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"pin_ptr<"), __32870_59_dctl);
__32914_19_vendor_ext = ((const char *)">");
__32916_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32933_12_num == 3L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"eut"), __32885_23_p))) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__underlying_type("), __32870_59_dctl);
__32914_19_vendor_ext = ((const char *)")");
__32916_18_need_space = ((_ZN3edg9a_booleanE)0);
} else  { if ((__32933_12_num == 17L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"pass_object_size"), __32885_23_p))) {

} else  {


if (__32933_12_num >= ((long)(strlen(__32885_23_p)))) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32870_59_dctl);
goto __32972_1_no_increment;
} else  {
__32915_19_vendor_ext_buffer = ((char *)(malloc((((_ZN3edg11true_size_tE)__32933_12_num) + 1ULL))));
memcpy(((void *)__32915_19_vendor_ext_buffer), ((const void *)__32885_23_p), ((size_t)__32933_12_num));
(__32915_19_vendor_ext_buffer[__32933_12_num]) = ((char)0);
__32914_19_vendor_ext = ((_ZN3edg12a_const_charE *)__32915_19_vendor_ext_buffer);
}
} } } } } } }

__32885_23_p += __32933_12_num;
__32972_1_no_increment:; ;
}
if (((int)__32886_22_kind) == 67) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"_Complex "), __32870_59_dctl);
}
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32885_23_p, 0, ((_ZN3edg9a_booleanE)1), __32916_18_need_space, __32869_59_parse_template_args, __32870_59_dctl));

if (((int)__32886_22_kind) == 80) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)42), __32870_59_dctl);
} else  { if (((int)__32886_22_kind) == 82) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)38), __32870_59_dctl);
} else  { if (((int)__32886_22_kind) == 79) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"&&"), __32870_59_dctl);
} else  { if (__32914_19_vendor_ext != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__32914_19_vendor_ext, __32870_59_dctl);
if (__32915_19_vendor_ext_buffer != ((char *)0)) {
free(((void *)__32915_19_vendor_ext_buffer));
}
} } } }

_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32866_59_cv_quals, ((_ZN3edg9a_booleanE)1), __32870_59_dctl);
} else  { if (((int)__32886_22_kind) == 77) {

auto _ZN3edg12a_const_charE *__32995_19_classp; __32995_19_classp = (__32885_23_p + 1);


(__32870_59_dctl->suppress_id_output)++;
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32995_19_classp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32870_59_dctl));
(__32870_59_dctl->suppress_id_output)--;
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32885_23_p, 0, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)1), __32869_59_parse_template_args, __32870_59_dctl));



(__32870_59_dctl->suppress_substitution_recording)++;
_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__32995_19_classp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __32870_59_dctl);
(__32870_59_dctl->suppress_substitution_recording)--;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::*"), __32870_59_dctl);

_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32866_59_cv_quals, ((_ZN3edg9a_booleanE)1), __32870_59_dctl);
} else  { if ((((int)__32886_22_kind) == 70) || ((((int)__32886_22_kind) == 68) && ((((int)(__32885_23_p[1])) == 111) || (((int)(__32885_23_p[1])) == 79))))

{
auto a_ref_qualifier __33014_21_dummy;




if (((int)__32886_22_kind) == 68) {

switch ((int)(__32885_23_p[1])) {
case 111:
__32885_23_p += 2;
goto __T748735112;
case 79:
(__32870_59_dctl->suppress_id_output)++;
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__32885_23_p + 2), __32870_59_dctl));
(__32870_59_dctl->suppress_id_output)--;
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32885_23_p, __32870_59_dctl));
goto __T748735112;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__32870_59_dctl);
goto __T748735112;
} __T748735112:;
}
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324skip_extern_C_indicationEPKc((__32885_23_p + 1)));

__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32885_23_p, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)1), __32869_59_parse_template_args, __32870_59_dctl));




__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(__32885_23_p, ((_ZN3edg9a_booleanE)1), 0, __32870_59_dctl));


__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi(__32885_23_p, (&__33014_21_dummy)));
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __32885_23_p, __32870_59_dctl));


if (__32867_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32870_59_dctl); }



__32889_22_record_cv_qual_substitution = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)__32886_22_kind) == 65) {




__32885_23_p++;
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__32885_23_p)))])) & 4)) {
if (((int)(*__32885_23_p)) != 95) {



(__32870_59_dctl->suppress_id_output)++;
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__32885_23_p, __32870_59_dctl));
(__32870_59_dctl->suppress_id_output)--;
}
} else  {


while (((int)((_ctype)[((unsigned char)((unsigned char)(*__32885_23_p)))])) & 4) { __32885_23_p++; }
}
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__32885_23_p, __32870_59_dctl));

__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__32885_23_p, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)1), __32869_59_parse_template_args, __32870_59_dctl));




if (__32867_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __32870_59_dctl); }
} else  {

_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__32866_59_cv_quals, ((_ZN3edg9a_booleanE)1), __32870_59_dctl);
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d330demangle_vector_size_qualifierEPKcP22a_decode_control_block(__32885_23_p, __32870_59_dctl));
__32885_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_type_specifierEPKcbP22a_decode_control_block(__32885_23_p, __32869_59_parse_template_args, __32870_59_dctl));
if (__32868_59_need_trailing_space) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __32870_59_dctl); }
if (!(((!(((((int)((_ctype)[((unsigned char)((unsigned char)(*__32885_45_unqualp)))])) & 2) && (((int)(*__32885_45_unqualp)) != 114)) || ((((int)(*__32885_45_unqualp)) == 68) && (!((((((((int)(__32885_45_unqualp[1])) == 112) || (((int)(__32885_45_unqualp[1])) == 114)) || (((int)(
#line 5678
__32885_45_unqualp[1])) == 84)) || (((int)(__32885_45_unqualp[1])) == 116)) || (((int)(__32885_45_unqualp[1])) == 89)) || (((int)(__32885_45_unqualp[1])) == 121)))))) || (((int)(*__32885_45_unqualp)) == 117)) || ((((int)(*__32885_45_unqualp)) == 68) && (((int)(__32885_45_unqualp[1])) == 118)))) {

__32888_22_record_substitution = ((_ZN3edg9a_booleanE)0);
}
} } } } }
if (__32888_22_record_substitution) {


_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__32885_45_unqualp, subk_type, 0UL, __32869_59_parse_template_args, __32870_59_dctl);

}
if ((__32885_33_qualp != __32885_45_unqualp) && (__32889_22_record_cv_qual_substitution)) {


_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__32885_33_qualp, subk_type, 0UL, __32869_59_parse_template_args, __32870_59_dctl);

}
return __32885_23_p;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(
_ZN3edg12a_const_charE *__33111_60_ptr, 
a_cv_qualifier_set __33112_59_cv_quals, 
_ZN3edg9a_booleanE __33113_59_under_lhs_declarator, 
a_decode_control_block_ptr __33114_59_dctl)
#line 5716
{
auto _ZN3edg12a_const_charE *__33128_23_p;
auto char __33129_22_kind;
auto a_cv_qualifier_set __33130_22_local_cv_quals;
#line 5717
__33128_23_p = __33111_60_ptr;




__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__33128_23_p, (&__33130_22_local_cv_quals)));
__33112_59_cv_quals |= __33130_22_local_cv_quals;
__33129_22_kind = (*__33128_23_p);
if ((((int)__33129_22_kind) == 83) && (((int)(__33128_23_p[1])) != 116))

{

__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__33128_23_p, 2, __33112_59_cv_quals, __33113_59_under_lhs_declarator, ((_ZN3edg9a_booleanE)0), ((_ZN3edg12a_const_charE **)0), ((_ZN3edg12a_const_charE **)0), __33114_59_dctl));
#line 5737
} else  { if (((((((int)__33129_22_kind) == 80) || (((int)__33129_22_kind) == 82)) || (((int)__33129_22_kind) == 79)) || (((int)__33129_22_kind) == 67)) || (((int)__33129_22_kind) == 85))
{
#line 5747
__33128_23_p++;
if (((int)__33129_22_kind) == 85) {



if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"17pass_object_size"), __33128_23_p)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__attribute((pass_object_size("), __33114_59_dctl);

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((__33128_23_p[18]), __33114_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")))"), __33114_59_dctl);
} else  {
(__33114_59_dctl->suppress_id_output)++;
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__33128_23_p, ((_ZN3edg9a_booleanE)0), __33114_59_dctl));
(__33114_59_dctl->suppress_id_output)--;
}
}
_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__33128_23_p, 0, ((_ZN3edg9a_booleanE)1), __33114_59_dctl);

} else  { if (((int)__33129_22_kind) == 77) {


(__33114_59_dctl->suppress_id_output)++;
(__33114_59_dctl->suppress_substitution_recording)++;
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__33128_23_p + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __33114_59_dctl));
(__33114_59_dctl->suppress_substitution_recording)--;
(__33114_59_dctl->suppress_id_output)--;
_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__33128_23_p, 0, ((_ZN3edg9a_booleanE)1), __33114_59_dctl);

} else  { if ((((int)__33129_22_kind) == 70) || ((((int)__33129_22_kind) == 68) && (((((int)(__33128_23_p[1])) == 111) || (((int)(__33128_23_p[1])) == 79)) || (((int)(__33128_23_p[1])) == 119))))

{
auto _ZN3edg12a_const_charE *__33189_19_returnt; auto _ZN3edg12a_const_charE *__33189_29_exception_spec = ((_ZN3edg12a_const_charE *)0);
auto _ZN3edg12a_const_charE *__33190_19_save_exception_expr = ((_ZN3edg12a_const_charE *)0);
auto a_ref_qualifier __33191_21_ref_qual;




if (((int)__33129_22_kind) == 68) {

switch ((int)(__33128_23_p[1])) {
case 111:
__33189_29_exception_spec = ((const char *)" noexcept");
__33128_23_p += 2;
goto __T748839064;
case 79:


__33190_19_save_exception_expr = (__33128_23_p + 2);
(__33114_59_dctl->suppress_id_output)++;
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__33190_19_save_exception_expr, __33114_59_dctl));
(__33114_59_dctl->suppress_id_output)--;
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __33128_23_p, __33114_59_dctl));
goto __T748839064;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33114_59_dctl);
goto __T748839064;
} __T748839064:;
}


if (__33113_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __33114_59_dctl); }
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d324skip_extern_C_indicationEPKc((__33128_23_p + 1)));


__33189_19_returnt = __33128_23_p;
(__33114_59_dctl->suppress_substitution_recording)++;
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(__33128_23_p, ((_ZN3edg9a_booleanE)0), 0x2, __33114_59_dctl));

(__33114_59_dctl->suppress_substitution_recording)--;

__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi(__33128_23_p, (&__33191_21_ref_qual)));
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __33128_23_p, __33114_59_dctl));
#line 5826
if (__33112_59_cv_quals != 0) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __33114_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block(__33112_59_cv_quals, ((_ZN3edg9a_booleanE)0), __33114_59_dctl);
}
if (__33191_21_ref_qual != 0) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __33114_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_ref_qualifierEiP22a_decode_control_block(__33191_21_ref_qual, __33114_59_dctl);
}

_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__33189_19_returnt, 0, ((_ZN3edg9a_booleanE)0), __33114_59_dctl);

if (__33189_29_exception_spec != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__33189_29_exception_spec, __33114_59_dctl);
} else  { if (__33190_19_save_exception_expr != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" noexcept("), __33114_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__33190_19_save_exception_expr, __33114_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __33114_59_dctl);
} }
} else  { if (((int)__33129_22_kind) == 65) {
#line 5852
if (__33113_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __33114_59_dctl); }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __33114_59_dctl);
__33128_23_p++;
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__33128_23_p)))])) & 4)) {
if (((int)(*__33128_23_p)) != 95) {


(__33114_59_dctl->suppress_substitution_recording)++;
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__33128_23_p, __33114_59_dctl));
(__33114_59_dctl->suppress_substitution_recording)--;
}
} else  {


while (((int)((_ctype)[((unsigned char)((unsigned char)(*__33128_23_p)))])) & 4) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*(__33128_23_p++)), __33114_59_dctl); }
}
__33128_23_p = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__33128_23_p, __33114_59_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __33114_59_dctl);

_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__33128_23_p, 0, ((_ZN3edg9a_booleanE)0), __33114_59_dctl);

} else  {


} } } } } 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(
_ZN3edg12a_const_charE *__33292_61_ptr, 
_ZN3edg9a_booleanE __33293_60_parse_template_args, 
_ZN3edg9a_booleanE __33294_60_is_pack_expansion, 
a_decode_control_block_ptr __33295_60_dctl)
#line 5911
{
auto _ZN3edg12a_const_charE *__33323_17_p;


__33323_17_p = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_type_first_partEPKcibbbP22a_decode_control_block(__33292_61_ptr, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), __33293_60_parse_template_args, __33295_60_dctl));


if (__33294_60_is_pack_expansion) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __33295_60_dctl);
}

_ZN29_INTERNAL_8_decode_c_f78890d325demangle_type_second_partEPKcibP22a_decode_control_block(__33292_61_ptr, 0, ((_ZN3edg9a_booleanE)0), __33295_60_dctl);

return __33323_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(
_ZN3edg12a_const_charE *__33343_67_ptr, 
int *__33344_67_num_operands, 
int *__33345_67_length, 
_ZN3edg12a_const_charE **__33346_68_close_str, 
a_decode_control_block_ptr __33347_66_dctl)
#line 5950
{
auto _ZN3edg12a_const_charE *__33362_17_str = ((_ZN3edg12a_const_charE *)0);

(*__33344_67_num_operands) = 2;
(*__33346_68_close_str) = ((const char *)"");
(*__33345_67_length) = 0;
if (((int)(*__33343_67_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33347_66_dctl);
} else  {
auto char __33370_10_ch2; __33370_10_ch2 = (__33343_67_ptr[1]);
switch ((int)(*__33343_67_ptr)) {
case 97:
if (((int)__33370_10_ch2) == 97) {
__33362_17_str = ((const char *)"&&");
} else  { if (((int)__33370_10_ch2) == 100) {
__33362_17_str = ((const char *)"&");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 110) {
__33362_17_str = ((const char *)"&");
} else  { if (((int)__33370_10_ch2) == 78) {
__33362_17_str = ((const char *)"&=");
} else  { if (((int)__33370_10_ch2) == 83) {
__33362_17_str = ((const char *)"=");
} else  { if (((int)__33370_10_ch2) == 116) {

__33362_17_str = ((const char *)"alignof(");
(*__33344_67_num_operands) = 0;
(*__33346_68_close_str) = ((const char *)")");
} else  { if (((int)__33370_10_ch2) == 119) {

__33362_17_str = ((const char *)"co_await");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 122) {

__33362_17_str = ((const char *)"alignof(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 1;
} } } } } } } }
goto __T748917696;
case 99:
if (((int)__33370_10_ch2) == 99) {
__33362_17_str = ((const char *)"const_cast");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 108) {
__33362_17_str = ((const char *)"()");
(*__33344_67_num_operands) = 0;
} else  { if (((int)__33370_10_ch2) == 109) {
__33362_17_str = ((const char *)",");
} else  { if (((int)__33370_10_ch2) == 111) {
__33362_17_str = ((const char *)"~");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 118) {
__33362_17_str = ((const char *)"cast");
(*__33344_67_num_operands) = 1;
} } } } }
goto __T748917696;
case 100:
if (((int)__33370_10_ch2) == 97) {
__33362_17_str = ((const char *)"delete[] ");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 99) {
__33362_17_str = ((const char *)"dynamic_cast");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 101) {
__33362_17_str = ((const char *)"*");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 108) {
__33362_17_str = ((const char *)"delete ");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 115) {
__33362_17_str = ((const char *)".*");
} else  { if (((int)__33370_10_ch2) == 118) {
__33362_17_str = ((const char *)"/");
} else  { if (((int)__33370_10_ch2) == 86) {
__33362_17_str = ((const char *)"/=");
} } } } } } }
goto __T748917696;
case 101:
if (((int)__33370_10_ch2) == 111) {
__33362_17_str = ((const char *)"^");
} else  { if (((int)__33370_10_ch2) == 79) {
__33362_17_str = ((const char *)"^=");
} else  { if (((int)__33370_10_ch2) == 113) {
__33362_17_str = ((const char *)"==");
} } }
goto __T748917696;
case 103:
if (((int)__33370_10_ch2) == 101) {
__33362_17_str = ((const char *)">=");
} else  { if (((int)__33370_10_ch2) == 116) {
__33362_17_str = ((const char *)">");
} }
goto __T748917696;
case 105:
if (((int)__33370_10_ch2) == 120) {
__33362_17_str = ((const char *)"[");
(*__33346_68_close_str) = ((const char *)"]");
}
goto __T748917696;
case 108:
if (((int)__33370_10_ch2) == 101) {
__33362_17_str = ((const char *)"<=");
} else  { if (((int)__33370_10_ch2) == 105) {




auto long __33468_25_ud_suffix_len;
auto _ZN3edg12a_const_charE *__33469_26_ud_suffix_ptr;
__33469_26_ud_suffix_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__33343_67_ptr + 2), (&__33468_25_ud_suffix_len), __33347_66_dctl));




(*__33344_67_num_operands) = 0;
__33362_17_str = ((_ZN3edg12a_const_charE *)0);
if (!(__33347_66_dctl->err_in_id)) {
if (__33468_25_ud_suffix_len <= 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33347_66_dctl);
} else  {
if (ud_suffix_buffer == ((char *)0)) {
ud_suffix_buffer_length = 128UL;
ud_suffix_buffer = ((char *)(malloc(((_ZN3edg11true_size_tE)ud_suffix_buffer_length))));

} else  { if (((((unsigned long)__33468_25_ud_suffix_len) + 3UL) + 1UL) > ud_suffix_buffer_length)
{
ud_suffix_buffer_length = ((unsigned long)((__33468_25_ud_suffix_len + 3L) + 1L));
ud_suffix_buffer = ((char *)(realloc(((void *)ud_suffix_buffer), ((_ZN3edg11true_size_tE)ud_suffix_buffer_length))));

} }
if (ud_suffix_buffer != ((char *)0)) {
if (((long)(strlen(__33469_26_ud_suffix_ptr))) < __33468_25_ud_suffix_len) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33347_66_dctl);
} else  {
strcpy(ud_suffix_buffer, ((const char *)"\"\""));
strncpy((ud_suffix_buffer + 2), __33469_26_ud_suffix_ptr, ((size_t)__33468_25_ud_suffix_len));
(ud_suffix_buffer[(2L + __33468_25_ud_suffix_len)]) = ((char)0);
__33362_17_str = ((_ZN3edg12a_const_charE *)ud_suffix_buffer);
(*__33345_67_length) = ((int)((__33469_26_ud_suffix_ptr + __33468_25_ud_suffix_len) - __33343_67_ptr));
}
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33347_66_dctl);
}
}
}
} else  { if (((int)__33370_10_ch2) == 115) {
__33362_17_str = ((const char *)"<<");
} else  { if (((int)__33370_10_ch2) == 83) {
__33362_17_str = ((const char *)"<<=");
} else  { if (((int)__33370_10_ch2) == 116) {
__33362_17_str = ((const char *)"<");
} } } } }
goto __T748917696;
case 109:
if (((int)__33370_10_ch2) == 105) {
__33362_17_str = ((const char *)"-");
} else  { if (((int)__33370_10_ch2) == 73) {
__33362_17_str = ((const char *)"-=");
} else  { if (((int)__33370_10_ch2) == 108) {
__33362_17_str = ((const char *)"*");
} else  { if (((int)__33370_10_ch2) == 76) {
__33362_17_str = ((const char *)"*=");
} else  { if (((int)__33370_10_ch2) == 109) {
__33362_17_str = ((const char *)"--");
(*__33344_67_num_operands) = 1;
} } } } }
goto __T748917696;
case 110:
if (((int)__33370_10_ch2) == 97) {
__33362_17_str = ((const char *)"new[] ");
} else  { if (((int)__33370_10_ch2) == 101) {
__33362_17_str = ((const char *)"!=");
} else  { if (((int)__33370_10_ch2) == 103) {
__33362_17_str = ((const char *)"-");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 116) {
__33362_17_str = ((const char *)"!");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 119) {
__33362_17_str = ((const char *)"new ");
} else  { if (((int)__33370_10_ch2) == 120) {
__33362_17_str = ((const char *)"noexcept(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 1;
} } } } } }
goto __T748917696;
case 111:
if (((int)__33370_10_ch2) == 111) {
__33362_17_str = ((const char *)"||");
} else  { if (((int)__33370_10_ch2) == 114) {
__33362_17_str = ((const char *)"|");
} else  { if (((int)__33370_10_ch2) == 82) {
__33362_17_str = ((const char *)"|=");
} } }
goto __T748917696;
case 112:
if (((int)__33370_10_ch2) == 108) {
__33362_17_str = ((const char *)"+");
} else  { if (((int)__33370_10_ch2) == 76) {
__33362_17_str = ((const char *)"+=");
} else  { if (((int)__33370_10_ch2) == 109) {
__33362_17_str = ((const char *)"->*");
} else  { if (((int)__33370_10_ch2) == 112) {
__33362_17_str = ((const char *)"++");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 115) {
__33362_17_str = ((const char *)"+");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 116) {
__33362_17_str = ((const char *)"->");
} } } } } }
goto __T748917696;
case 113:
if (((int)__33370_10_ch2) == 117) {
__33362_17_str = ((const char *)"\?");
(*__33344_67_num_operands) = 3;
}
goto __T748917696;
case 114:
if (((int)__33370_10_ch2) == 99) {
__33362_17_str = ((const char *)"reinterpret_cast");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 109) {
__33362_17_str = ((const char *)"%");
} else  { if (((int)__33370_10_ch2) == 77) {
__33362_17_str = ((const char *)"%=");
} else  { if (((int)__33370_10_ch2) == 115) {
__33362_17_str = ((const char *)">>");
} else  { if (((int)__33370_10_ch2) == 83) {
__33362_17_str = ((const char *)">>=");
} } } } }
goto __T748917696;
case 115:
if (((int)__33370_10_ch2) == 99) {
__33362_17_str = ((const char *)"static_cast");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 115) {
__33362_17_str = ((const char *)"<=>");
} else  { if (((int)__33370_10_ch2) == 116) {

__33362_17_str = ((const char *)"sizeof(");
(*__33344_67_num_operands) = 0;
(*__33346_68_close_str) = ((const char *)")");
} else  { if (((int)__33370_10_ch2) == 122) {

__33362_17_str = ((const char *)"sizeof(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 1;
} } } }
goto __T748917696;
case 116:
if (((int)__33370_10_ch2) == 101) {

__33362_17_str = ((const char *)"typeid(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 1;
} else  { if (((int)__33370_10_ch2) == 105) {

__33362_17_str = ((const char *)"typeid(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 0;
} else  { if (((int)__33370_10_ch2) == 114) {

__33362_17_str = ((const char *)"throw");
(*__33344_67_num_operands) = 0;
} else  { if (((int)__33370_10_ch2) == 119) {

__33362_17_str = ((const char *)"throw ");
(*__33344_67_num_operands) = 1;
} } } }
goto __T748917696;
case 118:

if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18alignofe"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"__alignof__(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 1;
(*__33345_67_length) = 11;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v17alignof"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"__alignof__(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 0;
(*__33345_67_length) = 10;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v19__uuidofe"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"__uuidof(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 1;
(*__33345_67_length) = 12;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18__uuidof"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"__uuidof(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 0;
(*__33345_67_length) = 11;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v17typeide"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"typeid(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 1;
(*__33345_67_length) = 10;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v16typeid"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"typeid(");
(*__33346_68_close_str) = ((const char *)")");
(*__33344_67_num_operands) = 0;
(*__33345_67_length) = 9;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v19clitypeid"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"::typeid");
(*__33344_67_num_operands) = 0;
(*__33345_67_length) = 12;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v23min"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"<\?");
(*__33345_67_length) = 6;
(*__33344_67_num_operands) = 2;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v23max"), __33343_67_ptr)) {

__33362_17_str = ((const char *)">\?");
(*__33345_67_length) = 6;
(*__33344_67_num_operands) = 2;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18__real__"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"__real(");
(*__33346_68_close_str) = ((const char *)")");
(*__33345_67_length) = 11;
(*__33344_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v18__imag__"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"__imag(");
(*__33346_68_close_str) = ((const char *)")");
(*__33345_67_length) = 11;
(*__33344_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v19clihandle"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"%");
(*__33345_67_length) = 12;
(*__33344_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v112clisafe_cast"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"safe_cast");
(*__33345_67_length) = 16;
(*__33344_67_num_operands) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"v16splice"), __33343_67_ptr)) {

__33362_17_str = ((const char *)"[:");
(*__33346_68_close_str) = ((const char *)":]");
(*__33344_67_num_operands) = 1;
(*__33345_67_length) = 9;
} else  { if ((_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"9builtin"), (__33343_67_ptr + 2))) || (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"10builtin"), (__33343_67_ptr + 2))))
{
#line 6314
__33362_17_str = ((_ZN3edg12a_const_charE *)_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name);
(*__33344_67_num_operands) = (((int)(__33343_67_ptr[1])) - 48);
if (((int)(__33343_67_ptr[2])) == 57) {
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[18]) = (__33343_67_ptr[10]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[19]) = (__33343_67_ptr[11]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[20]) = ((char)0);
(*__33345_67_length) = 12;
} else  {
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[18]) = (__33343_67_ptr[11]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[19]) = (__33343_67_ptr[12]);
((_ZZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_blockE12builtin_name)[20]) = (__33343_67_ptr[13]);
(*__33345_67_length) = 14;
}
} else  { if (((_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"12clisubscript"), (__33343_67_ptr + 2))) && (((int)(__33343_67_ptr[1])) >= 48)) && (((int)(__33343_67_ptr[1])) <= 57))
{


__33362_17_str = ((const char *)"subscript");
(*__33345_67_length) = 16;
(*__33344_67_num_operands) = (((int)(__33343_67_ptr[1])) - 48);
} } } } } } } } } } } } } } } }
goto __T748917696;
default:
goto __T748917696;
} __T748917696:;
if ((*__33345_67_length) == 0) { (*__33345_67_length) = 2; }
}
return __33362_17_str;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(
_ZN3edg12a_const_charE *__33757_62_ptr, 
_ZN3edg9a_booleanE __33758_61_is_module_id, 
a_decode_control_block_ptr __33759_61_dctl)
#line 6363
{
auto long __33775_13_num;
auto _ZN3edg9a_booleanE __33776_13_output_chars = ((_ZN3edg9a_booleanE)1);

__33757_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__33757_62_ptr, (&__33775_13_num), __33759_61_dctl));
if (__33775_13_num <= 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33759_61_dctl);
} else  { if (__33758_61_is_module_id) {



__33757_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_module_idEPKcmS1_P22a_decode_control_block(__33757_62_ptr, ((unsigned long)__33775_13_num), ((_ZN3edg12a_const_charE *)0), __33759_61_dctl));
} else  { if ((__33775_13_num >= 9L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"_INTERNAL"), __33757_62_ptr))) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[local to "), __33759_61_dctl);
__33757_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_module_idEPKcmS1_P22a_decode_control_block((__33757_62_ptr + 9), (((unsigned long)__33775_13_num) - 9UL), __33757_62_ptr, __33759_61_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __33759_61_dctl);
} else  {
if ((__33775_13_num >= 11L) && (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"_GLOBAL__N_"), __33757_62_ptr))) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"<unnamed>"), __33759_61_dctl);
__33776_13_output_chars = ((_ZN3edg9a_booleanE)0);
}
for (; __33775_13_num > 0L; (__33757_62_ptr++) , (__33775_13_num--)) {
if (((int)(*__33757_62_ptr)) == 0) {


_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33759_61_dctl);
goto __T749200496;
} else  { if (((!(((int)((_ctype)[((unsigned char)((unsigned char)(*__33757_62_ptr)))])) & 0x7)) && (((int)(*__33757_62_ptr)) != 95)) && (((int)(*__33757_62_ptr)) != 36)) {



if (__33776_13_output_chars) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33759_61_dctl);
goto __T749200496;
}
} else  { if (__33776_13_output_chars) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__33757_62_ptr), __33759_61_dctl);
} } }
} __T749200496:;
} } }
return __33757_62_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319get_instance_numberEPKcPmP22a_decode_control_block( _ZN3edg12a_const_charE *__33824_70_p, 
unsigned long *__33825_70_instance, 
a_decode_control_block_ptr __33826_69_dctl)
#line 6421
{
(*__33825_70_instance) = 1UL;
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__33824_70_p)))])) & 4) {
auto long __33835_10_num;
__33824_70_p = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__33824_70_p, (&__33835_10_num), __33826_69_dctl));
if (__33835_10_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33826_69_dctl);
} else  {
(*__33825_70_instance) = ((unsigned long)(__33835_10_num + 2L));
}
}
if (((int)(*__33824_70_p)) == 95) {
__33824_70_p += 1;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33826_69_dctl);
}
return __33824_70_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_unnamed_typeEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__33852_72_ptr, 
a_decode_control_block_ptr __33853_71_dctl)
#line 6455
{
auto unsigned long __33867_17_instance;

if ((((int)(*__33852_72_ptr)) == 85) && (((int)(__33852_72_ptr[1])) == 116)) {


__33852_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319get_instance_numberEPKcPmP22a_decode_control_block((__33852_72_ptr + 2), (&__33867_17_instance), __33853_71_dctl));
if (!(__33853_71_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[unnamed type (instance "), __33853_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d315write_id_numberEmP22a_decode_control_block(__33867_17_instance, __33853_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")]"), __33853_71_dctl);
}
} else  { if ((((int)(*__33852_72_ptr)) == 85) && (((int)(__33852_72_ptr[1])) == 108)) {



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[lambda"), __33853_71_dctl);
__33852_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block((__33852_72_ptr + 2), ((_ZN3edg9a_booleanE)1), 0x2, __33853_71_dctl));

if (((int)(*__33852_72_ptr)) == 69) {
__33852_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319get_instance_numberEPKcPmP22a_decode_control_block((__33852_72_ptr + 1), (&__33867_17_instance), __33853_71_dctl));
if (!(__33853_71_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __33853_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d315write_id_numberEmP22a_decode_control_block(__33867_17_instance, __33853_71_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")"), __33853_71_dctl);
}
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33853_71_dctl);
}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __33853_71_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33853_71_dctl);
} }
return __33852_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d326demangle_abi_tag_attributeEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__33904_76_ptr, 
a_decode_control_block_ptr __33905_75_dctl)
#line 6506
{
auto long __33918_8_num;

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[abi:"), __33905_75_dctl);
while (((int)(*__33904_76_ptr)) == 66) {
__33904_76_ptr++;
__33904_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__33904_76_ptr, (&__33918_8_num), __33905_75_dctl));
if (__33918_8_num <= 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33905_75_dctl);
goto __T749271352;
} else  {
for (; __33918_8_num > 0L; (__33904_76_ptr++) , (__33918_8_num--)) {
if (((int)(*__33904_76_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33905_75_dctl);
goto __T749275040;
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__33904_76_ptr), __33905_75_dctl);
}
} __T749275040:;
if (((int)(*__33904_76_ptr)) == 66) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)44), __33905_75_dctl);
}
}
} __T749271352:;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __33905_75_dctl);
return __33904_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(
_ZN3edg12a_const_charE *__33948_62_ptr, 
_ZN3edg9a_booleanE *__33949_62_is_no_return_name, 
a_decode_control_block_ptr __33950_61_dctl)
#line 6558
{
if (__33949_62_is_no_return_name != ((_ZN3edg9a_booleanE *)0)) { (*__33949_62_is_no_return_name) = ((_ZN3edg9a_booleanE)0); }
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__33948_62_ptr)))])) & 4) {


__33948_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__33948_62_ptr, ((_ZN3edg9a_booleanE)0), __33950_61_dctl));
} else  { if ((((int)(*__33948_62_ptr)) == 85) && ((((int)(__33948_62_ptr[1])) == 116) || (((int)(__33948_62_ptr[1])) == 108)))

{

__33948_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_unnamed_typeEPKcP22a_decode_control_block(__33948_62_ptr, __33950_61_dctl));
} else  { if ((((int)(*__33948_62_ptr)) == 68) && (((int)(__33948_62_ptr[1])) == 67)) {

__33948_62_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[structured binding for "), __33950_61_dctl);
while ((((int)(*__33948_62_ptr)) != 69) && (((int)(*__33948_62_ptr)) != 0)) {
__33948_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__33948_62_ptr, ((_ZN3edg9a_booleanE)0), __33950_61_dctl));
if ((((int)(*__33948_62_ptr)) != 69) && (((int)(*__33948_62_ptr)) != 0)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)44), __33950_61_dctl); }
}
if (((int)(*__33948_62_ptr)) != 69) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33950_61_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __33950_61_dctl);
__33948_62_ptr++;
}
} else  {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __33950_61_dctl);
if ((((int)(*__33948_62_ptr)) == 99) && (((int)(__33948_62_ptr[1])) == 118)) {

if (__33949_62_is_no_return_name != ((_ZN3edg9a_booleanE *)0)) { (*__33949_62_is_no_return_name) = ((_ZN3edg9a_booleanE)1); }
#line 6603
__33948_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__33948_62_ptr + 2), (__33950_61_dctl->parse_template_args_after_conversion_operator), ((_ZN3edg9a_booleanE)0), __33950_61_dctl));



(__33950_61_dctl->contains_conversion_operator) = ((_ZN3edg9a_booleanE)1);
} else  {

auto int __34021_20_num_operands; auto int __34021_34_length;
auto _ZN3edg12a_const_charE *__34022_21_op_str; auto _ZN3edg12a_const_charE *__34022_30_close_str;
__34022_21_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__33948_62_ptr, (&__34021_20_num_operands), (&__34021_34_length), (&__34022_30_close_str), __33950_61_dctl));

if (__34022_21_op_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__33950_61_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34022_21_op_str, __33950_61_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34022_30_close_str, __33950_61_dctl);
__33948_62_ptr += __34021_34_length;
}
}
} } }
if (((int)(*__33948_62_ptr)) == 66) {


__33948_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_abi_tag_attributeEPKcP22a_decode_control_block(__33948_62_ptr, __33950_61_dctl));
}
return __33948_62_ptr;
}


static unsigned char _ZN29_INTERNAL_8_decode_c_f78890d313get_hex_digitEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34043_64_ptr, 
a_decode_control_block_ptr __34044_63_dctl)




{
auto unsigned char __34050_17_value;
auto unsigned char __34051_17_ch; __34051_17_ch = ((unsigned char)(__34043_64_ptr[0]));

if (((int)((_ctype)[((unsigned char)__34051_17_ch)])) & 4) {
__34050_17_value = ((unsigned char)(((int)__34051_17_ch) - 48));
} else  { if ((((int)((_ctype)[((unsigned char)__34051_17_ch)])) & 128) && (((int)((_ctype)[((unsigned char)__34051_17_ch)])) & 2)) {
__34050_17_value = ((unsigned char)((((int)__34051_17_ch) - 97) + 10));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34044_63_dctl);
__34050_17_value = ((unsigned char)0U);
} }
return __34050_17_value;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34065_72_ptr, 
a_decode_control_block_ptr __34066_71_dctl)
#line 6662
{
auto _ZN3edg8sizeof_tE __34074_12_i; auto _ZN3edg8sizeof_tE __34074_15_length;
auto char *__34075_13_p;
#line 6671
auto union _ZZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_blockEUt_ __34082_5_x;



(__34082_5_x.ld) = (0.0L);
#line 6681
__34074_15_length = 0ULL;
__34075_13_p = ((char *)__34065_72_ptr);
while (((((int)(*__34075_13_p)) != 69) && (((int)(*__34075_13_p)) != 95)) && (((int)(*__34075_13_p)) != 0)) {
__34074_15_length++;
__34075_13_p++;
}
if ((__34074_15_length % 2ULL) != 0ULL) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34066_71_dctl);
__34074_15_length -= 1ULL;
}

__34074_15_length /= 2ULL;
if (__34074_15_length > 8ULL) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34066_71_dctl);
__34074_15_length = 8ULL;
}

for (__34074_12_i = 0ULL; __34074_12_i < __34074_15_length; (__34074_12_i++) , (__34065_72_ptr += 2)) {
auto unsigned char __34112_19_byte; __34112_19_byte = (_ZN29_INTERNAL_8_decode_c_f78890d313get_hex_digitEPKcP22a_decode_control_block(__34065_72_ptr, __34066_71_dctl));
if (__34066_71_dctl->err_in_id) { goto __T749356472; }
__34112_19_byte = ((unsigned char)((((int)__34112_19_byte) << 4) | ((int)(_ZN29_INTERNAL_8_decode_c_f78890d313get_hex_digitEPKcP22a_decode_control_block((__34065_72_ptr + 1), __34066_71_dctl)))));
if (__34066_71_dctl->err_in_id) { goto __T749356472; }
if (host_little_endian) {
(((unsigned char *)(&__34082_5_x))[((__34074_15_length - 1ULL) - __34074_12_i)]) = __34112_19_byte;
} else  {
(((unsigned char *)(&__34082_5_x))[__34074_12_i]) = __34112_19_byte;
}
} __T749356472:;
if (!(__34066_71_dctl->err_in_id)) {

auto char __34124_10_str[60];
auto int __34125_10_ndig;
if (__34074_12_i <= 4ULL) {

__34125_10_ndig = 6;



snprintf((__34124_10_str), 60ULL, ((const char *)"%.*g"), __34125_10_ndig, ((double)(__34082_5_x.f)));

} else  { if (__34074_12_i > 8ULL) {

__34125_10_ndig = 15;



snprintf((__34124_10_str), 60ULL, ((const char *)"%.*Lg"), __34125_10_ndig, (__34082_5_x.ld));

} else  {

__34125_10_ndig = 15;



snprintf((__34124_10_str), 60ULL, ((const char *)"%.*g"), __34125_10_ndig, (__34082_5_x.d));
} }



__34075_13_p = (((__34124_10_str) + (strlen(((const char *)(__34124_10_str))))) - 1);
if ((((strchr(((const char *)(__34124_10_str)), 46)) == ((char *)0)) && ((strchr(((const char *)(__34124_10_str)), 101)) == ((char *)0))) && (((int)((_ctype)[((unsigned char)((unsigned char)(*__34075_13_p)))])) & 4))

{
__34075_13_p++;
(*(__34075_13_p++)) = ((char)46);
(*(__34075_13_p++)) = ((char)48);
(*(__34075_13_p++)) = ((char)0);
}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__34124_10_str)), __34066_71_dctl);
}
return __34065_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_float_literalEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34168_73_ptr, 
a_decode_control_block_ptr __34169_72_dctl)
#line 6769
{

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34169_72_dctl);
__34168_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34168_73_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34169_72_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34169_72_dctl);
if (!(__34169_72_dctl->err_in_id)) {
__34168_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block(__34168_73_ptr, __34169_72_dctl));
if (!(__34169_72_dctl->err_in_id)) {
__34168_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34168_73_ptr, __34169_72_dctl));
}
}
return __34168_73_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_complex_literalEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34195_75_ptr, 
a_decode_control_block_ptr __34196_74_dctl)
#line 6796
{

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34196_74_dctl);
__34195_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34195_75_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34196_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)")("), __34196_74_dctl);

if (!(__34196_74_dctl->err_in_id)) {
__34195_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block(__34195_75_ptr, __34196_74_dctl));
if (!(__34196_74_dctl->err_in_id)) {
__34195_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34195_75_ptr, __34196_74_dctl));
if (!(__34196_74_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)43), __34196_74_dctl);
__34195_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_float_numberEPKcP22a_decode_control_block(__34195_75_ptr, __34196_74_dctl));
if (!(__34196_74_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"i)"), __34196_74_dctl);
if (!(__34196_74_dctl->err_in_id)) {
__34195_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34195_75_ptr, __34196_74_dctl));
}
}
}
}
}
return __34195_75_ptr;
}
#line 6827
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_expr_primaryEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34238_72_ptr, 
a_decode_control_block_ptr __34239_71_dctl)
#line 6843
{
auto _ZN3edg12a_const_charE *__34255_17_sub = ((_ZN3edg12a_const_charE *)0);

if (((int)(__34238_72_ptr[1])) == 83) {



(__34239_71_dctl->suppress_id_output)++;
_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block((__34238_72_ptr + 1), 0, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), ((_ZN3edg12a_const_charE **)0), (&__34255_17_sub), __34239_71_dctl);
#line 6857
(__34239_71_dctl->suppress_id_output)--;
}
if (((int)(__34238_72_ptr[1])) == 95) {

if (((int)(__34238_72_ptr[2])) != 90) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34239_71_dctl);
} else  {
__34238_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__34238_72_ptr + 3), ((_ZN3edg9a_booleanE)0), __34239_71_dctl));
__34238_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34238_72_ptr, __34239_71_dctl));
}
} else  { if ((((((int)(__34238_72_ptr[1])) == 100) || (((int)(__34238_72_ptr[1])) == 101)) || (((int)(__34238_72_ptr[1])) == 102)) || (((int)(__34238_72_ptr[1])) == 103)) {



__34238_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_float_literalEPKcP22a_decode_control_block(__34238_72_ptr, __34239_71_dctl));
} else  { if (((((int)(__34238_72_ptr[1])) == 67) && ((((((int)(__34238_72_ptr[2])) == 100) || (((int)(__34238_72_ptr[2])) == 101)) || (((int)(__34238_72_ptr[2])) == 102)) || (((int)(__34238_72_ptr[2])) == 103))) || ((__34255_17_sub != ((_ZN3edg12a_const_charE *)0)) && ((((int)(__34255_17_sub[0])) 
#line 6872
== 67) && ((((((int)(__34255_17_sub[1])) == 100) || (((int)(__34255_17_sub[1])) == 101)) || (((int)(__34255_17_sub[1])) == 102)) || (((int)(__34255_17_sub[1])) == 103)))))

{

__34238_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_complex_literalEPKcP22a_decode_control_block(__34238_72_ptr, __34239_71_dctl));
} else  { if (((((int)(__34238_72_ptr[1])) == 68) && ((((int)(__34238_72_ptr[2])) == 110) || (((int)(__34238_72_ptr[2])) == 78))) && (((int)(__34238_72_ptr[3])) == 69))

{


(__34239_71_dctl->suppress_id_output)++;
_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34238_72_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34239_71_dctl);
(__34239_71_dctl->suppress_id_output)--;
if (((int)(__34238_72_ptr[2])) == 78) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"__nullptr"), __34239_71_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"nullptr"), __34239_71_dctl);
}
__34238_72_ptr += 4;
} else  {


_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34239_71_dctl);
__34238_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34238_72_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34239_71_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34239_71_dctl);
if (((int)(*__34238_72_ptr)) == 69) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"\"...\""), __34239_71_dctl);
} else  {

if (((int)(*__34238_72_ptr)) == 110) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)45), __34239_71_dctl);
__34238_72_ptr++;
}



if ((!(((int)((_ctype)[((unsigned char)((unsigned char)(*__34238_72_ptr)))])) & 4)) && (!(emulate_gnu_abi_bugs))) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34239_71_dctl);
} else  {
while (((int)((_ctype)[((unsigned char)((unsigned char)(*__34238_72_ptr)))])) & 4) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block((*__34238_72_ptr), __34239_71_dctl);
__34238_72_ptr++;
}
}
}
__34238_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34238_72_ptr, __34239_71_dctl));
} } } }
return __34238_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__34336_76_ptr, 
a_decode_control_block_ptr __34337_75_dctl)
#line 6942
{
if ((((int)(*__34336_76_ptr)) == 100) && (((int)(__34336_76_ptr[1])) == 105)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)46), __34337_75_dctl);
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block((__34336_76_ptr + 2), ((_ZN3edg9a_booleanE)0), __34337_75_dctl));
if ((((int)(*__34336_76_ptr)) == 100) && (((int)(__34336_76_ptr[1])) == 105)) {

} else  {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)61), __34337_75_dctl);
}
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34336_76_ptr, __34337_75_dctl));
} else  { if ((((int)(*__34336_76_ptr)) == 100) && (((int)(__34336_76_ptr[1])) == 120)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __34337_75_dctl);
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34336_76_ptr + 2), __34337_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]="), __34337_75_dctl);
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34336_76_ptr, __34337_75_dctl));
} else  { if ((((int)(*__34336_76_ptr)) == 100) && (((int)(__34336_76_ptr[1])) == 88)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __34337_75_dctl);
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34336_76_ptr + 2), __34337_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" ... "), __34337_75_dctl);
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_76_ptr, __34337_75_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"]="), __34337_75_dctl);
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34336_76_ptr, __34337_75_dctl));
} else  {
__34336_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34336_76_ptr, __34337_75_dctl));
} } }
return __34336_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block(
_ZN3edg12a_const_charE *__34386_62_ptr, 
char __34387_61_stop_char, 
char __34388_61_open_paren, 
char __34389_61_close_paren, 
_ZN3edg9a_booleanE __34390_61_is_braced_expr, 
a_decode_control_block_ptr __34391_61_dctl)
#line 6988
{
auto _ZN3edg9a_booleanE __34400_13_first_time = ((_ZN3edg9a_booleanE)1);

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(__34388_61_open_paren, __34391_61_dctl);
while ((((int)(*__34386_62_ptr)) != ((int)__34387_61_stop_char)) && (!(__34391_61_dctl->err_in_id))) {
if (((int)(*__34386_62_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34391_61_dctl);
goto __T749534784;
}
if (!(__34400_13_first_time)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34391_61_dctl);
} else  {
__34400_13_first_time = ((_ZN3edg9a_booleanE)0);
}
if (__34390_61_is_braced_expr) {
__34386_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_braced_expressionEPKcP22a_decode_control_block(__34386_62_ptr, __34391_61_dctl));
} else  {
__34386_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34386_62_ptr, __34391_61_dctl));
}
} __T749534784:;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(__34389_61_close_paren, __34391_61_dctl);
return __34386_62_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(
_ZN3edg12a_const_charE *__34425_62_ptr, 
char __34426_61_stop_char, 
a_decode_control_block_ptr __34427_61_dctl)
#line 7022
{
return _ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block(__34425_62_ptr, __34426_61_stop_char, ((char)40), ((char)41), ((_ZN3edg9a_booleanE)0), __34427_61_dctl);

}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_initializerEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__34440_62_ptr, 
a_decode_control_block_ptr __34441_61_dctl)
#line 7038
{
if (((int)(*__34440_62_ptr)) == 69) {
__34440_62_ptr++;
} else  {
if ((((int)(*__34440_62_ptr)) == 112) && (((int)(__34440_62_ptr[1])) == 105)) {
__34440_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block((__34440_62_ptr + 2), ((char)69), __34441_61_dctl));
__34440_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34440_62_ptr, __34441_61_dctl));
} else  { if ((((int)(*__34440_62_ptr)) == 105) && (((int)(__34440_62_ptr[1])) == 108)) {
__34440_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block((__34440_62_ptr + 2), ((char)69), ((char)123), ((char)125), ((_ZN3edg9a_booleanE)1), __34441_61_dctl));

__34440_62_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34440_62_ptr, __34441_61_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34441_61_dctl);
} }
}
return __34440_62_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34468_70_ptr, 
a_decode_control_block_ptr __34469_69_dctl)
#line 7159
{
auto int __34571_16_num_operands; auto int __34571_30_length;
auto _ZN3edg12a_const_charE *__34572_17_op_str; auto _ZN3edg12a_const_charE *__34572_26_close_str;

if (((int)(*__34468_70_ptr)) == 76) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_expr_primaryEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  { if (((int)(*__34468_70_ptr)) == 84) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  { if (((int)(*__34468_70_ptr)) == 102) {
if ((((int)(__34468_70_ptr[1])) == 112) || ((((int)(__34468_70_ptr[1])) == 76) && (((int)((_ctype)[((unsigned char)((unsigned char)(__34468_70_ptr[2])))])) & 4)))
{

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d328demangle_parameter_referenceEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  {

auto _ZN3edg9a_booleanE __34587_20_unary; auto _ZN3edg9a_booleanE __34587_27_left;
switch ((int)(__34468_70_ptr[1])) {
case 108: __34587_20_unary = ((_ZN3edg9a_booleanE)1); __34587_27_left = ((_ZN3edg9a_booleanE)1); goto __T749579536;
case 76: __34587_20_unary = ((_ZN3edg9a_booleanE)0); __34587_27_left = ((_ZN3edg9a_booleanE)1); goto __T749579536;
case 114: __34587_20_unary = ((_ZN3edg9a_booleanE)1); __34587_27_left = ((_ZN3edg9a_booleanE)0); goto __T749579536;
case 82: __34587_20_unary = ((_ZN3edg9a_booleanE)0); __34587_27_left = ((_ZN3edg9a_booleanE)0); goto __T749579536;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34469_69_dctl);
goto __34896_1_bad_name;
} __T749579536:;
__34468_70_ptr += 2;
__34572_17_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__34468_70_ptr, (&__34571_16_num_operands), (&__34571_30_length), (&__34572_26_close_str), __34469_69_dctl));

if (__34572_17_op_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34469_69_dctl);
} else  {
__34468_70_ptr += __34571_30_length;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34469_69_dctl);
if (__34587_20_unary) {
if (__34587_27_left) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34469_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34469_69_dctl);
}
} else  {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34469_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl);
}
}
} else  { if ((((int)(*__34468_70_ptr)) == 99) && (((int)(__34468_70_ptr[1])) == 108)) {

__34468_70_ptr += 2;
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34468_70_ptr, ((char)69), __34469_69_dctl));
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34468_70_ptr, __34469_69_dctl));
} else  { if ((((int)(*__34468_70_ptr)) == 99) && (((int)(__34468_70_ptr[1])) == 112)) {

__34468_70_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34468_70_ptr, ((char)69), __34469_69_dctl));
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34468_70_ptr, __34469_69_dctl));
} else  { if ((((int)(*__34468_70_ptr)) == 99) && (((int)(__34468_70_ptr[1])) == 118)) {



auto _ZN3edg12a_const_charE *__34643_19_nptr;
auto _ZN3edg9a_booleanE __34644_15_one_argument = ((_ZN3edg9a_booleanE)0);


(__34469_69_dctl->suppress_id_output)++;
__34643_19_nptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34468_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
(__34469_69_dctl->suppress_id_output)--;
if ((!(__34469_69_dctl->err_in_id)) && (((int)(*__34643_19_nptr)) != 95)) {
__34644_15_one_argument = ((_ZN3edg9a_booleanE)1);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34469_69_dctl);
}


(__34469_69_dctl->suppress_substitution_recording)++;
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34468_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
(__34469_69_dctl->suppress_substitution_recording)--;
if (!(__34469_69_dctl->err_in_id)) {
if (__34644_15_one_argument) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  {

if (((int)(*__34468_70_ptr)) != 95) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34469_69_dctl);
} else  {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block((__34468_70_ptr + 1), ((char)69), __34469_69_dctl));
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34468_70_ptr, __34469_69_dctl));
}
}
}
} else  { if ((((int)(*__34468_70_ptr)) == 103) && (((int)(__34468_70_ptr[1])) == 115)) {


_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34468_70_ptr + 2), __34469_69_dctl));
} else  { if ((((int)(*__34468_70_ptr)) == 110) && ((((int)(__34468_70_ptr[1])) == 119) || (((int)(__34468_70_ptr[1])) == 97))) {

if (((int)(__34468_70_ptr[1])) == 119) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"new "), __34469_69_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"new[] "), __34469_69_dctl);
}
__34468_70_ptr += 2;

if (((int)(*__34468_70_ptr)) != 95) {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34468_70_ptr, ((char)95), __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __34469_69_dctl);
}
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34468_70_ptr, __34469_69_dctl));
if (!(__34469_69_dctl->err_in_id)) {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
if (!(__34469_69_dctl->err_in_id)) {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_initializerEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
}
}
} else  { if ((((int)(*__34468_70_ptr)) == 103) && (((int)(__34468_70_ptr[1])) == 99)) {

__34468_70_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"gcnew "), __34469_69_dctl);

if (((int)(*__34468_70_ptr)) != 95) {
auto _ZN3edg12a_const_charE *__34705_21_optr; auto _ZN3edg12a_const_charE *__34705_34_ptr2; __34705_21_optr = __34468_70_ptr;


(__34469_69_dctl->suppress_id_output)++;
(__34469_69_dctl->suppress_substitution_recording)++;
__34705_34_ptr2 = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34468_70_ptr, ((char)95), __34469_69_dctl));
(__34469_69_dctl->suppress_id_output)--;
(__34469_69_dctl->suppress_substitution_recording)--;
if (!(__34469_69_dctl->err_in_id)) {
__34705_34_ptr2 = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34705_34_ptr2, __34469_69_dctl));
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34705_34_ptr2, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d324demangle_expression_listEPKccP22a_decode_control_block(__34705_21_optr, ((char)95), __34469_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __34469_69_dctl);
}
} else  {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)95), __34468_70_ptr, __34469_69_dctl));
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
}
if (!(__34469_69_dctl->err_in_id)) {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_initializerEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
}
} else  { if ((((int)(*__34468_70_ptr)) == 100) && (((int)(__34468_70_ptr[1])) == 116)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34468_70_ptr + 2), __34469_69_dctl));
if (!(__34469_69_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)46), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl);
}
} else  { if ((((int)(*__34468_70_ptr)) == 112) && (((int)(__34468_70_ptr[1])) == 116)) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34468_70_ptr + 2), __34469_69_dctl));
if (!(__34469_69_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"->"), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl);
}
} else  { if ((((int)(*__34468_70_ptr)) == 115) && (((int)(__34468_70_ptr[1])) == 90)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"sizeof...("), __34469_69_dctl);
__34468_70_ptr += 2;
if (((int)(*__34468_70_ptr)) == 84) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  { if (((int)(*__34468_70_ptr)) == 102) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d328demangle_parameter_referenceEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34469_69_dctl);
} }
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl);
} else  { if ((((int)(*__34468_70_ptr)) == 115) && (((int)(__34468_70_ptr[1])) == 112)) {

__34468_70_ptr += 2;
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __34469_69_dctl);
} else  { if (((((int)(*__34468_70_ptr)) == 116) || (((int)(*__34468_70_ptr)) == 105)) && (((int)(__34468_70_ptr[1])) == 108)) {

if (((int)(*__34468_70_ptr)) == 116) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34468_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
} else  {
__34468_70_ptr += 2;
}
if (!(__34469_69_dctl->err_in_id)) {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_expression_list_fullEPKccccbP22a_decode_control_block(__34468_70_ptr, ((char)69), ((char)123), ((char)125), ((_ZN3edg9a_booleanE)1), __34469_69_dctl));

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34468_70_ptr, __34469_69_dctl));
}
} else  { if ((__34572_17_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__34468_70_ptr, (&__34571_16_num_operands), (&__34571_30_length), (&__34572_26_close_str), __34469_69_dctl))) != ((_ZN3edg12a_const_charE *)0))
{




auto _ZN3edg9a_booleanE __34782_15_needs_parens; __34782_15_needs_parens = ((_Bool)((strcmp(__34572_26_close_str, ((const char *)""))) == 0));
__34468_70_ptr += __34571_30_length;
if (__34782_15_needs_parens) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34469_69_dctl); }
if ((strncmp(__34572_17_op_str, ((const char *)"builtin-operation-"), 18ULL)) == 0) {

auto int __34787_11_i;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)40), __34469_69_dctl);
for (__34787_11_i = 1; __34787_11_i <= __34571_16_num_operands; __34787_11_i++) {
if ((((int)(*__34468_70_ptr)) == 84) && (((int)(__34468_70_ptr[1])) == 79)) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34468_70_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
} else  {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
}
if (__34787_11_i != __34571_16_num_operands) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34469_69_dctl); }
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl);
} else  { if ((strncmp(__34572_17_op_str, ((const char *)"subscript"), 9ULL)) == 0) {

auto int __34802_11_i;
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)91), __34469_69_dctl);
for (__34802_11_i = 2; __34802_11_i <= __34571_16_num_operands; __34802_11_i++) {
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
if (__34802_11_i != __34571_16_num_operands) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34469_69_dctl); }
}
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)93), __34469_69_dctl);
} else  { if (__34571_16_num_operands == 1) {
auto char __34811_12_cast_close = ((char)0);

if (((strcmp(__34572_17_op_str, ((const char *)"++"))) == 0) || ((strcmp(__34572_17_op_str, ((const char *)"--"))) == 0))
{
if (((int)(*__34468_70_ptr)) == 95) {

__34468_70_ptr++;
} else  {

__34572_26_close_str = __34572_17_op_str;
__34572_17_op_str = ((const char *)"");
}
}
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
if ((((((strcmp(__34572_17_op_str, ((const char *)"static_cast"))) == 0) || ((strcmp(__34572_17_op_str, ((const char *)"dynamic_cast"))) == 0)) || ((strcmp(__34572_17_op_str, ((const char *)"const_cast"))) == 0)) || ((strcmp(__34572_17_op_str, ((const char *)"reinterpret_cast"))) == 0)) || ((strcmp(
#line 7414
__34572_17_op_str, ((const char *)"safe_cast"))) == 0))



{

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)60), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)">("), __34469_69_dctl);
__34811_12_cast_close = ((char)41);
}
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
if (((int)__34811_12_cast_close) != 0) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(__34811_12_cast_close, __34469_69_dctl); }
} else  { if (__34571_16_num_operands == 2) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  { if (__34571_16_num_operands == 3) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)":"), __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} else  {



if ((strcmp(__34572_17_op_str, ((const char *)"sizeof("))) == 0) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
} else  { if (((strcmp(__34572_17_op_str, ((const char *)"alignof("))) == 0) || ((strcmp(__34572_17_op_str, ((const char *)"__alignof__("))) == 0))
{

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
} else  { if ((strcmp(__34572_17_op_str, ((const char *)"__uuidof("))) == 0) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
} else  { if ((strcmp(__34572_17_op_str, ((const char *)"typeid("))) == 0) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
} else  { if ((strcmp(__34572_17_op_str, ((const char *)"::typeid"))) == 0) {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34468_70_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34469_69_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
} else  { if ((strcmp(__34572_17_op_str, ((const char *)"throw"))) == 0) {


_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
} else  { if ((strncmp(__34572_17_op_str, ((const char *)"\"\""), 2ULL)) == 0) {




_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __34469_69_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_17_op_str, __34469_69_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34469_69_dctl);
} } } } } } }
} } } } }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__34572_26_close_str, __34469_69_dctl);
if (__34782_15_needs_parens) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __34469_69_dctl); }
} else  {

__34468_70_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block(__34468_70_ptr, __34469_69_dctl));
} } } } } } } } } } } } } } }
__34896_1_bad_name:;
return __34468_70_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_template_argEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34901_72_ptr, 
a_decode_control_block_ptr __34902_71_dctl)
#line 7503
{
if (((int)(*__34901_72_ptr)) == 88) {

__34901_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_expressionEPKcP22a_decode_control_block((__34901_72_ptr + 1), __34902_71_dctl));
__34901_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34901_72_ptr, __34902_71_dctl));
} else  { if (((int)(*__34901_72_ptr)) == 76) {

__34901_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_expr_primaryEPKcP22a_decode_control_block(__34901_72_ptr, __34902_71_dctl));
} else  { if ((((int)(*__34901_72_ptr)) == 74) || ((((int)(*__34901_72_ptr)) == 73) && (emulate_gnu_abi_bugs)))
{

__34901_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__34901_72_ptr, __34902_71_dctl));
} else  {

__34901_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34901_72_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34902_71_dctl));
} } }
return __34901_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__34934_73_ptr, 
a_decode_control_block_ptr __34935_72_dctl)
#line 7533
{
auto _ZN3edg9a_booleanE __34945_13_suppress = ((_ZN3edg9a_booleanE)0);

if (((int)(*__34934_73_ptr)) == 74) {

__34945_13_suppress = ((_ZN3edg9a_booleanE)1);
}

__34934_73_ptr++;
if (!(__34945_13_suppress)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)60), __34935_72_dctl); }
for (; ((int)(*__34934_73_ptr)) != 69; ) {
__34934_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_template_argEPKcP22a_decode_control_block(__34934_73_ptr, __34935_72_dctl));

if (((int)(*__34934_73_ptr)) == 69) { goto __T749837696; }

if (__34935_72_dctl->err_in_id) { goto __T749837696; }

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", "), __34935_72_dctl);
} __T749837696:;
__34934_73_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __34934_73_ptr, __34935_72_dctl));
if (!(__34945_13_suppress)) { _ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)62), __34935_72_dctl); }
return __34934_73_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d331demangle_nested_name_componentsEPKcmPbS2_PS1_S3_P22a_decode_control_block(
_ZN3edg12a_const_charE *__34970_59_ptr, 
unsigned long __34971_58_num_levels, 
_ZN3edg9a_booleanE *__34972_59_is_no_return_name, 
_ZN3edg9a_booleanE *__34973_59_has_templ_arg_list, 
_ZN3edg12a_const_charE **__34974_60_ctor_dtor_kind, 
_ZN3edg12a_const_charE **__34975_60_last_component_name, 
a_decode_control_block_ptr __34976_58_dctl)
#line 7586
{
auto _ZN3edg12a_const_charE *__34998_18_prev_component_name = ((_ZN3edg12a_const_charE *)0);
auto _ZN3edg12a_const_charE *__34999_18_first_component_start;
auto unsigned long __35000_17_level_num = 0UL;
#line 7588
__34999_18_first_component_start = __34970_59_ptr;


(*__34972_59_is_no_return_name) = ((_ZN3edg9a_booleanE)0);
(*__34973_59_has_templ_arg_list) = ((_ZN3edg9a_booleanE)0);
(*__34974_60_ctor_dtor_kind) = ((_ZN3edg12a_const_charE *)0);
for (; ; ) {

auto _ZN3edg9a_booleanE __35007_15_is_substitution = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __35008_15_suppress_qualification = ((_ZN3edg9a_booleanE)0);
__35000_17_level_num++;
(*__34972_59_is_no_return_name) = ((_ZN3edg9a_booleanE)0);
(*__34973_59_has_templ_arg_list) = ((_ZN3edg9a_booleanE)0);
if ((((int)(*__34970_59_ptr)) == 69) || (((int)(*__34970_59_ptr)) == 0)) {

_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34976_58_dctl);
} else  { if (((int)(*__34970_59_ptr)) == 83) {

__35007_15_is_substitution = ((_ZN3edg9a_booleanE)1);
__34970_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__34970_59_ptr, 0, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), (&__34998_18_prev_component_name), ((_ZN3edg12a_const_charE **)0), __34976_58_dctl));
#line 7615
if (((int)(*__34970_59_ptr)) == 69) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34976_58_dctl);
}
} else  { if (((int)(*__34970_59_ptr)) == 84) {

__34970_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323demangle_template_paramEPKcP22a_decode_control_block(__34970_59_ptr, __34976_58_dctl));
} else  { if ((((int)(*__34970_59_ptr)) == 68) && ((((int)(__34970_59_ptr[1])) == 116) || (((int)(__34970_59_ptr[1])) == 84))) {

__34970_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__34970_59_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __34976_58_dctl));
} else  {

if ((((int)(*__34970_59_ptr)) != 67) && ((((int)(*__34970_59_ptr)) != 68) || (((int)(__34970_59_ptr[1])) == 67))) {

__34998_18_prev_component_name = __34970_59_ptr;
__34970_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__34970_59_ptr, __34972_59_is_no_return_name, __34976_58_dctl));
} else  {



(*__34972_59_is_no_return_name) = ((_ZN3edg9a_booleanE)1);
if (((int)(*__34970_59_ptr)) == 68) {
if (((int)(__34970_59_ptr[1])) == 55) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)33), __34976_58_dctl);
} else  {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)126), __34976_58_dctl);
}
}
if ((__34998_18_prev_component_name == ((_ZN3edg12a_const_charE *)0)) || (((int)(*__34998_18_prev_component_name)) == 83))
{




_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34976_58_dctl);
} else  {
auto _ZN3edg9a_booleanE __35063_21_dummy;
#line 7668
if ((((((int)(__34970_59_ptr[1])) == 49) || (((int)(__34970_59_ptr[1])) == 50)) || (((int)(__34970_59_ptr[1])) == 57)) || ((((int)(__34970_59_ptr[0])) == 67) ? (((((int)(__34970_59_ptr[1])) == 51) || (((int)(__34970_59_ptr[1])) == 56)) || ((((int)(__34970_59_ptr[1])) == 73) && ((((int)(
#line 7668
__34970_59_ptr[2])) == 49) || (((int)(__34970_59_ptr[2])) == 50)))) : ((((int)(__34970_59_ptr[1])) == 48) || (((int)(__34970_59_ptr[1])) == 55))))



{

(*__34974_60_ctor_dtor_kind) = (__34970_59_ptr + 1);
if (((int)(__34970_59_ptr[1])) == 73) {




(__34976_58_dctl->suppress_template_parameters)++;
__34970_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__34970_59_ptr + 3), ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), __34976_58_dctl));

(__34976_58_dctl->suppress_template_parameters)--;
} else  {


_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__34998_18_prev_component_name, (&__35063_21_dummy), __34976_58_dctl);

__34970_59_ptr += 2;
}
if (((int)(*__34970_59_ptr)) == 66) {


__34970_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d326demangle_abi_tag_attributeEPKcP22a_decode_control_block(__34970_59_ptr, __34976_58_dctl));
}
} else  {


_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__34976_58_dctl);
}
}
}
if (((int)(*__34970_59_ptr)) == 77) {


__34970_59_ptr++;
}
} } } }
if (((int)(*__34970_59_ptr)) == 73) {



if (!(__35007_15_is_substitution)) {
_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__34999_18_first_component_start, subk_template_prefix, (__35000_17_level_num - 1UL), ((_ZN3edg9a_booleanE)0), __34976_58_dctl);


}

__34970_59_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__34970_59_ptr, __34976_58_dctl));
(*__34973_59_has_templ_arg_list) = ((_ZN3edg9a_booleanE)1);
__35007_15_is_substitution = ((_ZN3edg9a_booleanE)0);
}

if (((int)(*__34970_59_ptr)) == 69) { goto __T749931568; }
if (!(__35007_15_is_substitution)) {



_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__34999_18_first_component_start, subk_prefix, __35000_17_level_num, ((_ZN3edg9a_booleanE)0), __34976_58_dctl);


}

if (__34976_58_dctl->err_in_id) { goto __T749931568; }

if ((__34971_58_num_levels != 0UL) && (__35000_17_level_num >= __34971_58_num_levels)) { goto __T749931568; }


if (!(__35008_15_suppress_qualification)) { _ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __34976_58_dctl); }
} __T749931568:;
if (__34975_60_last_component_name != ((_ZN3edg12a_const_charE **)0)) { (*__34975_60_last_component_name) = __34998_18_prev_component_name; }
return __34970_59_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_nested_nameEPKcP12a_func_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__35158_69_ptr, 
a_func_block *__35159_69_func_block, 
a_decode_control_block_ptr __35160_68_dctl)
#line 7774
{
auto _ZN3edg9a_booleanE __35186_13_has_templ_arg_list;
auto _ZN3edg9a_booleanE __35187_13_is_no_return_name;

_ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block(__35159_69_func_block);

__35158_69_ptr++;

__35158_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317get_cv_qualifiersEPKcPi(__35158_69_ptr, (&(__35159_69_func_block->cv_quals))));

__35158_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317get_ref_qualifierEPKcPi(__35158_69_ptr, (&(__35159_69_func_block->ref_qual))));

__35158_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d331demangle_nested_name_componentsEPKcmPbS2_PS1_S3_P22a_decode_control_block(__35158_69_ptr, 0UL, (&__35187_13_is_no_return_name), (&__35186_13_has_templ_arg_list), (&(__35159_69_func_block->ctor_dtor_kind)), ((_ZN3edg12a_const_charE **)0), 
#line 7786
__35160_68_dctl));
#line 7793
__35158_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35158_69_ptr, __35160_68_dctl));

if (!(__35186_13_has_templ_arg_list)) {
(__35159_69_func_block->no_return_type) = ((_ZN3edg9a_booleanE)1);
}


if (__35187_13_is_no_return_name) {
(__35159_69_func_block->no_return_type) = ((_ZN3edg9a_booleanE)1);
}
return __35158_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d319demangle_local_nameEPKcP12a_func_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__35219_69_ptr, 
a_func_block *__35220_69_func_block, 
a_decode_control_block_ptr __35221_68_dctl)
#line 7826
{
_ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block(__35220_69_func_block);

__35219_69_ptr++;

__35219_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(__35219_69_ptr, ((_ZN3edg9a_booleanE)1), __35221_68_dctl));
__35219_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35219_69_ptr, __35221_68_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35221_68_dctl);
if (((int)(*__35219_69_ptr)) == 115) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"string"), __35221_68_dctl);
__35219_69_ptr++;
} else  {
if (((int)(*__35219_69_ptr)) == 100) {

auto long __35252_12_param = (-1L);
__35219_69_ptr += 1;
if (((int)(*__35219_69_ptr)) != 95) {
__35219_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__35219_69_ptr, (&__35252_12_param), __35221_68_dctl));
if ((__35252_12_param < 0L) || (((int)(*__35219_69_ptr)) != 95)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35221_68_dctl);
} else  {

__35219_69_ptr += 1;
}
} else  {

__35219_69_ptr += 1;
}
if (!(__35221_68_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[default argument "), __35221_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block((__35252_12_param + 2L), __35221_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" (from end)]::"), __35221_68_dctl);
}
}

__35219_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block(__35219_69_ptr, __35220_69_func_block, 0x3, __35221_68_dctl));
}
if ((!(__35221_68_dctl->err_in_id)) && (((int)(*__35219_69_ptr)) == 95)) {

auto long __35277_10_num = (-1L);
if (((int)((_ctype)[((unsigned char)((unsigned char)(__35219_69_ptr[1])))])) & 4) {

__35277_10_num = ((long)(((int)((char)(__35219_69_ptr[1]))) - 48));
__35219_69_ptr += 2;
} else  { if ((((int)(__35219_69_ptr[1])) == 95) && (((int)((_ctype)[((unsigned char)((unsigned char)(__35219_69_ptr[2])))])) & 4)) {

__35219_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__35219_69_ptr + 2), (&__35277_10_num), __35221_68_dctl));
if (((int)(*__35219_69_ptr)) == 95) {
__35219_69_ptr += 1;
} else  {
__35277_10_num = (-1L);
}
} }
if (__35277_10_num < 0L) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35221_68_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __35221_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block((__35277_10_num + 2L), __35221_68_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)41), __35221_68_dctl);
}
}
return __35219_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d322demangle_unscoped_nameEPKcP12a_func_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__35304_69_ptr, 
a_func_block *__35305_69_func_block, 
a_decode_control_block_ptr __35306_68_dctl)
#line 7906
{
auto _ZN3edg9a_booleanE __35318_13_is_no_return_name;

if ((((int)(*__35304_69_ptr)) == 83) && (((int)(__35304_69_ptr[1])) == 116)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"std::"), __35306_68_dctl);
__35304_69_ptr += 2;
}
__35304_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d325demangle_unqualified_nameEPKcPbP22a_decode_control_block(__35304_69_ptr, (&__35318_13_is_no_return_name), __35306_68_dctl));
(__35305_69_func_block->no_return_type) = __35318_13_is_no_return_name;
return __35304_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block( _ZN3edg12a_const_charE *__35331_64_ptr, 
a_func_block *__35332_64_func_block, 
a_demangle_name_option __35333_63_options, 
a_decode_control_block_ptr __35334_63_dctl)
#line 7947
{
_ZN29_INTERNAL_8_decode_c_f78890d316clear_func_blockEP12a_func_block(__35332_64_func_block);
if (((int)(*__35331_64_ptr)) == 66) {

if ((__35333_63_options & 0x1) == 0) { (__35334_63_dctl->suppress_id_output)++; }
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"[static from "), __35334_63_dctl);
__35331_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block((__35331_64_ptr + 1), ((_ZN3edg9a_booleanE)1), __35334_63_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"] "), __35334_63_dctl);
if ((__35333_63_options & 0x1) == 0) { (__35334_63_dctl->suppress_id_output)--; }
}
if ((__35333_63_options & 0x2) == 0) { (__35334_63_dctl->suppress_id_output)++; }
if (((int)(*__35331_64_ptr)) == 78) {

__35331_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_nested_nameEPKcP12a_func_blockP22a_decode_control_block(__35331_64_ptr, __35332_64_func_block, __35334_63_dctl));
} else  { if (((int)(*__35331_64_ptr)) == 90) {

__35331_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d319demangle_local_nameEPKcP12a_func_blockP22a_decode_control_block(__35331_64_ptr, __35332_64_func_block, __35334_63_dctl));
} else  {

if (((((int)(*__35331_64_ptr)) == 83) && (((int)(__35331_64_ptr[1])) != 0)) && (((((int)(__35331_64_ptr[2])) == 73) || ((((int)(__35331_64_ptr[2])) == 95) && (((int)(__35331_64_ptr[3])) == 73))) || ((((((int)(__35331_64_ptr[2])) != 0) && (!(((int)((_ctype)[((unsigned char)((unsigned char)(
#line 7966
__35331_64_ptr[2])))])) & 4))) && (((int)(__35331_64_ptr[3])) == 95)) && (((int)(__35331_64_ptr[4])) == 73))))



{
#line 7978
__35331_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_substitutionEPKciibbPS1_S2_P22a_decode_control_block(__35331_64_ptr, 0, 0, ((_ZN3edg9a_booleanE)0), ((_ZN3edg9a_booleanE)0), ((_ZN3edg12a_const_charE **)0), ((_ZN3edg12a_const_charE **)0), __35334_63_dctl));
#line 7984
} else  {


auto _ZN3edg12a_const_charE *__35398_21_start; __35398_21_start = __35331_64_ptr;
__35331_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_unscoped_nameEPKcP12a_func_blockP22a_decode_control_block(__35331_64_ptr, __35332_64_func_block, __35334_63_dctl));
if (((int)(*__35331_64_ptr)) == 73) {


_ZN29_INTERNAL_8_decode_c_f78890d327record_substitutable_entityEPKc19a_substitution_kindmbP22a_decode_control_block(__35398_21_start, subk_unscoped_template_name, 0UL, ((_ZN3edg9a_booleanE)0), __35334_63_dctl);

}
}
if (((int)(*__35331_64_ptr)) == 73) {


if (__35334_63_dctl->suppress_template_parameters) { (__35334_63_dctl->suppress_id_output)++; }
__35331_64_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__35331_64_ptr, __35334_63_dctl));
if (__35334_63_dctl->suppress_template_parameters) { (__35334_63_dctl->suppress_id_output)--; }
} else  {

(__35332_64_func_block->no_return_type) = ((_ZN3edg9a_booleanE)1);
}
} }
if ((__35333_63_options & 0x2) == 0) { (__35334_63_dctl->suppress_id_output)--; }
return __35331_64_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35423_69_ptr, 
a_decode_control_block_ptr __35424_68_dctl)
#line 8020
{
__35423_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_source_nameEPKcbP22a_decode_control_block(__35423_69_ptr, ((_ZN3edg9a_booleanE)0), __35424_68_dctl));
if ((!(__35424_68_dctl->err_in_id)) && (((int)(*__35423_69_ptr)) == 73)) {

__35423_69_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__35423_69_ptr, __35424_68_dctl));
}
return __35423_69_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d329demangle_base_unresolved_nameEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__35442_76_ptr, 
a_decode_control_block_ptr __35443_75_dctl)
#line 8050
{
auto int __35462_16_num_operands; auto int __35462_30_length;
auto _ZN3edg12a_const_charE *__35463_17_op_str; auto _ZN3edg12a_const_charE *__35463_26_close_str;

if ((((int)(*__35442_76_ptr)) == 111) && (((int)(__35442_76_ptr[1])) == 110)) {

__35442_76_ptr += 2;
__35463_17_op_str = (_ZN29_INTERNAL_8_decode_c_f78890d317get_operator_nameEPKcPiS2_PS1_P22a_decode_control_block(__35442_76_ptr, (&__35462_16_num_operands), (&__35462_30_length), (&__35463_26_close_str), __35443_75_dctl));

if (__35463_17_op_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35443_75_dctl);
} else  {
__35442_76_ptr += __35462_30_length;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __35443_75_dctl);
if ((strcmp(__35463_17_op_str, ((const char *)"cast"))) == 0) {

__35442_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35442_76_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35443_75_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(__35463_17_op_str, __35443_75_dctl);
}
if ((!(__35443_75_dctl->err_in_id)) && (((int)(*__35442_76_ptr)) == 73)) {

__35442_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d322demangle_template_argsEPKcP22a_decode_control_block(__35442_76_ptr, __35443_75_dctl));
}
}
} else  { if ((((int)(*__35442_76_ptr)) == 100) && (((int)(__35442_76_ptr[1])) == 110)) {

__35442_76_ptr += 2;
_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)126), __35443_75_dctl);
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__35442_76_ptr)))])) & 4) {
__35442_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35442_76_ptr, __35443_75_dctl));
} else  {
__35442_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35442_76_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35443_75_dctl));
}
} else  {

__35442_76_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35442_76_ptr, __35443_75_dctl));
} }
return __35442_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d324demangle_unresolved_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35503_75_ptr, 
a_decode_control_block_ptr __35504_74_dctl)
#line 8117
{
auto _ZN3edg9a_booleanE __35529_16_gpp_qualified_name = ((_ZN3edg9a_booleanE)0);

if ((((int)(*__35503_75_ptr)) == 103) && (((int)(__35503_75_ptr[1])) == 115)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35504_74_dctl);
__35503_75_ptr += 2;
}
if ((((int)(*__35503_75_ptr)) == 115) && (((int)(__35503_75_ptr[1])) == 114)) {
#line 8137
__35503_75_ptr += 2;
if (((int)((_ctype)[((unsigned char)((unsigned char)(*__35503_75_ptr)))])) & 4) {



while ((!(__35504_74_dctl->err_in_id)) && (((int)(*__35503_75_ptr)) != 69)) {
if (((int)(*__35503_75_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35504_74_dctl);
} else  {
__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35503_75_ptr, __35504_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35504_74_dctl);
}
}
__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35503_75_ptr, __35504_74_dctl));
} else  {
if (emulate_gnu_abi_bugs) {




auto _ZN3edg12a_const_charE *__35568_23_ptr2;
(__35504_74_dctl->suppress_id_output)++;
(__35504_74_dctl->suppress_substitution_recording)++;
__35568_23_ptr2 = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35503_75_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35504_74_dctl));
(__35504_74_dctl->suppress_id_output)--;
(__35504_74_dctl->suppress_substitution_recording)--;
if (((int)(*__35568_23_ptr2)) == 78) {
__35529_16_gpp_qualified_name = ((_ZN3edg9a_booleanE)1);

(__35504_74_dctl->suppress_id_output)++;
__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35503_75_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35504_74_dctl));
(__35504_74_dctl->suppress_id_output)--;
}
}
if (!(__35529_16_gpp_qualified_name)) {
#line 8178
if (((int)(*__35503_75_ptr)) == 78) {
__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35503_75_ptr + 1), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35504_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35504_74_dctl);
while ((!(__35504_74_dctl->err_in_id)) && (((int)(*__35503_75_ptr)) != 69)) {
if (((int)(*__35503_75_ptr)) == 0) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35504_74_dctl);
} else  {
__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318demangle_simple_idEPKcP22a_decode_control_block(__35503_75_ptr, __35504_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35504_74_dctl);
}
}
__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d312advance_pastEcPKcP22a_decode_control_block(((char)69), __35503_75_ptr, __35504_74_dctl));
} else  {
__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35503_75_ptr, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35504_74_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __35504_74_dctl);
}
}
}
if (!(__35504_74_dctl->err_in_id)) {


__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_base_unresolved_nameEPKcP22a_decode_control_block(__35503_75_ptr, __35504_74_dctl));
}
} else  {

__35503_75_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d329demangle_base_unresolved_nameEPKcP22a_decode_control_block(__35503_75_ptr, __35504_74_dctl));
}
return __35503_75_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35620_71_ptr, 
a_decode_control_block_ptr __35621_70_dctl)
#line 8224
{
auto long __35636_13_num;
auto _ZN3edg9a_booleanE __35637_13_v_form = ((_ZN3edg9a_booleanE)0);

if ((((int)(*__35620_71_ptr)) != 104) && (((int)(*__35620_71_ptr)) != 118)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35621_70_dctl);
} else  {
__35637_13_v_form = ((_Bool)(((int)(*__35620_71_ptr)) == 118));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"(offset "), __35621_70_dctl);
__35620_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block((__35620_71_ptr + 1), (&__35636_13_num), __35621_70_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block(__35636_13_num, __35621_70_dctl);
if (__35637_13_v_form) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)", virtual offset "), __35621_70_dctl);
__35620_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__35620_71_ptr, __35621_70_dctl));
__35620_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d310get_numberEPKcPlP22a_decode_control_block(__35620_71_ptr, (&__35636_13_num), __35621_70_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d322write_id_signed_numberElP22a_decode_control_block(__35636_13_num, __35621_70_dctl);
}
__35620_71_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d323advance_past_underscoreEPKcP22a_decode_control_block(__35620_71_ptr, __35621_70_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)") "), __35621_70_dctl);
}
return __35620_71_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d321demangle_special_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__35659_72_ptr, 
a_decode_control_block_ptr __35660_71_dctl)
#line 8272
{
auto a_func_block __35684_16_func_block;

if (((int)(*__35659_72_ptr)) == 71) {
if (((int)(__35659_72_ptr[1])) == 86) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Initialization guard variable for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35659_72_ptr + 2), (&__35684_16_func_block), 0x3, __35660_71_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35660_71_dctl);
}
} else  { if (((int)(*__35659_72_ptr)) == 84) {
if (((int)(__35659_72_ptr[1])) == 86) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Virtual function table for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35659_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35660_71_dctl));
} else  { if (((int)(__35659_72_ptr[1])) == 84) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Virtual table table for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35659_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35660_71_dctl));
} else  { if (((int)(__35659_72_ptr[1])) == 73) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Typeinfo for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35659_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35660_71_dctl));
} else  { if (((int)(__35659_72_ptr[1])) == 83) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Typeinfo name for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block((__35659_72_ptr + 2), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35660_71_dctl));
} else  { if (((int)(__35659_72_ptr[1])) == 99) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Covariant thunk for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block((__35659_72_ptr + 2), __35660_71_dctl));
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block(__35659_72_ptr, __35660_71_dctl));
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(__35659_72_ptr, ((_ZN3edg9a_booleanE)1), __35660_71_dctl));
} else  { if ((((int)(__35659_72_ptr[1])) == 104) || (((int)(__35659_72_ptr[1])) == 118)) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Thunk for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d320demangle_call_offsetEPKcP22a_decode_control_block((__35659_72_ptr + 1), __35660_71_dctl));
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(__35659_72_ptr, ((_ZN3edg9a_booleanE)1), __35660_71_dctl));
} else  { if (((int)(__35659_72_ptr[1])) == 72) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Thread-local initialization routine for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35659_72_ptr + 2), (&__35684_16_func_block), 0x3, __35660_71_dctl));
} else  { if (((int)(__35659_72_ptr[1])) == 87) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"Thread-local wrapper routine for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35659_72_ptr + 2), (&__35684_16_func_block), 0x3, __35660_71_dctl));
} else  { if (((int)(__35659_72_ptr[1])) == 65) {

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"template parameter object for "), __35660_71_dctl);
__35659_72_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_template_argEPKcP22a_decode_control_block((__35659_72_ptr + 2), __35660_71_dctl));
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35660_71_dctl);
} } } } } } } } }
} else  {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35660_71_dctl);
} }
return __35659_72_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d330demangle_function_or_data_nameEPKcbbP22a_decode_control_block(
_ZN3edg12a_const_charE *__35745_60_ptr, 
_ZN3edg9a_booleanE __35746_59_include_func_params, 
_ZN3edg9a_booleanE __35747_59_first_scan, 
a_decode_control_block_ptr __35748_59_dctl)
#line 8351
{
auto a_func_block __35763_31_func_block;
auto a_bare_function_type_option __35764_31_bft_option;
auto a_demangle_name_option __35765_31_dno_option;
#line 8371
if (__35747_59_first_scan) {



__35765_31_dno_option = 0x1;
__35764_31_bft_option = 0x1;
} else  {


__35765_31_dno_option = 0x2;
__35764_31_bft_option = 0x2;


(__35748_59_dctl->suppress_substitution_recording)++;
}
__35745_60_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block(__35745_60_ptr, (&__35763_31_func_block), __35765_31_dno_option, __35748_59_dctl));


if (__35747_59_first_scan) { (__35748_59_dctl->suppress_id_output)++; }

if ((((int)(*__35745_60_ptr)) != 0) && (((int)(*__35745_60_ptr)) != 69)) {


if (((int)(*__35745_60_ptr)) == 81) {
auto a_func_block __35806_20_dummy_func_block;
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [overriding "), __35748_59_dctl);
__35745_60_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d313demangle_nameEPKcP12a_func_blockiP22a_decode_control_block((__35745_60_ptr + 1), (&__35806_20_dummy_func_block), __35765_31_dno_option, __35748_59_dctl));
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"] "), __35748_59_dctl);
}
if (__35747_59_first_scan) { (__35748_59_dctl->suppress_id_output)--; }
if (!(__35746_59_include_func_params)) { (__35748_59_dctl->suppress_id_output)++; }
__35745_60_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d327demangle_bare_function_typeEPKcbiP22a_decode_control_block(__35745_60_ptr, (__35763_31_func_block.no_return_type), __35764_31_bft_option, __35748_59_dctl));

if (!(__35746_59_include_func_params)) { (__35748_59_dctl->suppress_id_output)--; }
if (__35747_59_first_scan) { (__35748_59_dctl->suppress_id_output)++; }
if ((__35763_31_func_block.cv_quals) != 0) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __35748_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_cv_qualifiersEibP22a_decode_control_block((__35763_31_func_block.cv_quals), ((_ZN3edg9a_booleanE)0), __35748_59_dctl);

}
if ((__35763_31_func_block.ref_qual) != 0) {

_ZN29_INTERNAL_8_decode_c_f78890d311write_id_chEcP22a_decode_control_block(((char)32), __35748_59_dctl);
_ZN29_INTERNAL_8_decode_c_f78890d320output_ref_qualifierEiP22a_decode_control_block((__35763_31_func_block.ref_qual), __35748_59_dctl);
}
}
if ((__35763_31_func_block.ctor_dtor_kind) != ((_ZN3edg12a_const_charE *)0)) {

switch ((int)(*(__35763_31_func_block.ctor_dtor_kind))) {
case 48:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [deleting]"), __35748_59_dctl);
goto __T750369904;
case 49:

goto __T750369904;
case 50:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [subobject]"), __35748_59_dctl);
goto __T750369904;
case 51:

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [allocating]"), __35748_59_dctl);
goto __T750369904;
case 55:

goto __T750369904;
case 56:

_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [static]"), __35748_59_dctl);
goto __T750369904;
case 57:



_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [delegation]"), __35748_59_dctl);
goto __T750369904;
case 73:

switch ((int)((__35763_31_func_block.ctor_dtor_kind)[1])) {
case 49:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [complete inheriting]"), __35748_59_dctl);
goto __T750382344;
case 50:
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)" [base inheriting]"), __35748_59_dctl);
goto __T750382344;
default:
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35748_59_dctl);
} __T750382344:;
goto __T750369904;
default:


_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35748_59_dctl);
} __T750369904:;
}
if (__35747_59_first_scan) {
(__35748_59_dctl->suppress_id_output)--;
} else  {
(__35748_59_dctl->suppress_substitution_recording)--;
}
return __35745_60_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block(
_ZN3edg12a_const_charE *__35887_61_ptr, 
_ZN3edg9a_booleanE __35888_60_include_func_params, 
a_decode_control_block_ptr __35889_60_dctl)
#line 8491
{


if ((((int)(*__35887_61_ptr)) == 84) || ((((int)(*__35887_61_ptr)) == 71) && (((int)(__35887_61_ptr[1])) == 86))) {
__35887_61_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d321demangle_special_nameEPKcP22a_decode_control_block(__35887_61_ptr, __35889_60_dctl));
} else  {




_ZN29_INTERNAL_8_decode_c_f78890d330demangle_function_or_data_nameEPKcbbP22a_decode_control_block(__35887_61_ptr, __35888_60_include_func_params, ((_ZN3edg9a_booleanE)1), __35889_60_dctl);

if (!(__35889_60_dctl->err_in_id)) {
__35887_61_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d330demangle_function_or_data_nameEPKcbbP22a_decode_control_block(__35887_61_ptr, __35888_60_include_func_params, ((_ZN3edg9a_booleanE)0), __35889_60_dctl));

}
}
return __35887_61_ptr;
}


static void _ZN29_INTERNAL_8_decode_c_f78890d319init_demangle_stateEPcyP22a_decode_control_block( char *__35923_61_output_buffer, 
_ZN3edg8sizeof_tE __35924_60_output_buffer_size, 
a_decode_control_block_ptr __35925_60_dctl)



{
_ZN29_INTERNAL_8_decode_c_f78890d319clear_control_blockEP22a_decode_control_block(__35925_60_dctl);
(__35925_60_dctl->output_id) = __35923_61_output_buffer;
(__35925_60_dctl->output_id_size) = __35924_60_output_buffer_size;
num_substitutions = 0UL; 
}
#line 8531
void _Z17decode_identifierPKcPcyPbS2_Py( _ZN3edg12a_const_charE *__35942_38_id, 
char *__35943_38_output_buffer, 
_ZN3edg8sizeof_tE __35944_37_output_buffer_size, 
_ZN3edg9a_booleanE *__35945_38_err, 
_ZN3edg9a_booleanE *__35946_38_buffer_overflow_err, 
_ZN3edg8sizeof_tE *__35947_38_required_buffer_size)
#line 8553
{
auto _ZN3edg12a_const_charE *__35965_31_end_ptr;
auto a_decode_control_block __35966_30_control_block;
auto a_decode_control_block_ptr __35967_30_dctl; __35967_30_dctl = (&__35966_30_control_block);

_ZN29_INTERNAL_8_decode_c_f78890d319init_demangle_stateEPcyP22a_decode_control_block(__35943_38_output_buffer, __35944_37_output_buffer_size, __35967_30_dctl);
{

auto int __35972_9_i = 1;
host_little_endian = ((_Bool)(((int)(*((char *)(&__35972_9_i)))) == 1));
}
for (; ; ) {
if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"_Z"), __35942_38_id)) {

__35965_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__35942_38_id + 2), ((_ZN3edg9a_booleanE)1), __35967_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__b_"), __35942_38_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"base of type "), __35967_30_dctl);
__35965_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__35942_38_id + 4), ((_ZN3edg9a_booleanE)1), __35967_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_f78890d314start_of_id_isEPKcS1_(((const char *)"__v_"), __35942_38_id)) {
_ZN29_INTERNAL_8_decode_c_f78890d312write_id_strEPKcP22a_decode_control_block(((const char *)"virtual base of type "), __35967_30_dctl);
__35965_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d317demangle_encodingEPKcbP22a_decode_control_block((__35942_38_id + 4), ((_ZN3edg9a_booleanE)1), __35967_30_dctl));
} else  {

__35965_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_f78890d318full_demangle_typeEPKcbbP22a_decode_control_block(__35942_38_id, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE)0), __35967_30_dctl));
} } }
if (((__35967_30_dctl->err_in_id) && (__35967_30_dctl->contains_conversion_operator)) && (!(__35967_30_dctl->parse_template_args_after_conversion_operator)))

{
#line 8586
_ZN29_INTERNAL_8_decode_c_f78890d319init_demangle_stateEPcyP22a_decode_control_block(__35943_38_output_buffer, __35944_37_output_buffer_size, __35967_30_dctl);
(__35967_30_dctl->parse_template_args_after_conversion_operator) = ((_ZN3edg9a_booleanE)1);
} else  {
goto __T750426672;
}
} __T750426672:;
if (__35967_30_dctl->output_overflow_err) {
(__35967_30_dctl->err_in_id) = ((_ZN3edg9a_booleanE)1);
} else  {

((__35967_30_dctl->output_id)[(__35967_30_dctl->output_id_len)]) = ((char)0);
}

if (((!(__35967_30_dctl->err_in_id)) && (__35965_31_end_ptr != ((_ZN3edg12a_const_charE *)0))) && (((int)(*__35965_31_end_ptr)) != 0)) {
_ZN29_INTERNAL_8_decode_c_f78890d316bad_mangled_nameEP22a_decode_control_block(__35967_30_dctl);
}
(*__35945_38_err) = (__35967_30_dctl->err_in_id);
(*__35946_38_buffer_overflow_err) = (__35967_30_dctl->output_overflow_err);
(*__35947_38_required_buffer_size) = ((__35967_30_dctl->output_id_len) + 1ULL); 
}
#line 8621
char *__cxa_demangle( char *__36032_40_mangled_name, 
char *__36033_19_user_buffer, 
_ZN3edg11true_size_tE *__36034_25_user_buffer_size, 
int *__36035_18_status)
#line 8632
{

auto int __36045_8_result_status = 0;
auto char *__36046_10_result_buffer;

if ((__36033_19_user_buffer != ((char *)0)) && (__36034_25_user_buffer_size == ((_ZN3edg11true_size_tE *)0))) {

__36045_8_result_status = (-3);
__36046_10_result_buffer = ((char *)0);
} else  {

auto char __36054_10_temp_buffer[256];
auto char *__36055_11_buf_to_use = ((char *)0);
auto _ZN3edg8sizeof_tE __36056_14_buf_size = 0ULL;
auto _ZN3edg9a_booleanE __36057_15_err;
auto _ZN3edg9a_booleanE __36058_15_buffer_overflow_err;
auto _ZN3edg8sizeof_tE __36059_14_required_buffer_size;

if (__36033_19_user_buffer == ((char *)0)) {
__36055_11_buf_to_use = (__36054_10_temp_buffer);
__36056_14_buf_size = 256ULL;
} else  {
__36055_11_buf_to_use = __36033_19_user_buffer;
__36056_14_buf_size = (*__36034_25_user_buffer_size);
}
do {
_Z17decode_identifierPKcPcyPbS2_Py(((_ZN3edg12a_const_charE *)__36032_40_mangled_name), __36055_11_buf_to_use, __36056_14_buf_size, (&__36057_15_err), (&__36058_15_buffer_overflow_err), (&__36059_14_required_buffer_size));

if (__36058_15_buffer_overflow_err) {

if ((__36055_11_buf_to_use == (__36054_10_temp_buffer)) || (__36055_11_buf_to_use == __36033_19_user_buffer)) {
#line 8668
__36055_11_buf_to_use = ((char *)(malloc(((_ZN3edg11true_size_tE)__36059_14_required_buffer_size))));
} else  {

__36055_11_buf_to_use = ((char *)(realloc(((void *)__36055_11_buf_to_use), ((_ZN3edg11true_size_tE)__36059_14_required_buffer_size))));

}
__36056_14_buf_size = __36059_14_required_buffer_size;
if (__36055_11_buf_to_use == ((char *)0)) {

__36045_8_result_status = (-1);
}
} else  { if (__36057_15_err) {

__36045_8_result_status = (-2);
} }


} while ((__36057_15_err) && (__36045_8_result_status == 0));

if ((__36045_8_result_status == 0) && (__36055_11_buf_to_use == (__36054_10_temp_buffer))) {


auto _ZN3edg11true_size_tE __36101_19_size; __36101_19_size = ((strlen(((const char *)(__36054_10_temp_buffer)))) + 1ULL);

__36055_11_buf_to_use = ((char *)(malloc(__36101_19_size)));
if (__36055_11_buf_to_use == ((char *)0)) {

__36045_8_result_status = (-1);
} else  {
strcpy(__36055_11_buf_to_use, ((const char *)(__36054_10_temp_buffer)));
}
}

if (__36045_8_result_status == 0) {


if ((__36033_19_user_buffer != ((char *)0)) && (__36055_11_buf_to_use != __36033_19_user_buffer)) {
free(((void *)__36033_19_user_buffer));

if (__36034_25_user_buffer_size != ((_ZN3edg11true_size_tE *)0)) {
(*__36034_25_user_buffer_size) = __36056_14_buf_size;
}
}
} else  {

if ((__36055_11_buf_to_use != (__36054_10_temp_buffer)) && (__36055_11_buf_to_use != __36033_19_user_buffer)) {
free(((void *)__36055_11_buf_to_use));
}
}

if (__36045_8_result_status == 0) {
__36046_10_result_buffer = __36055_11_buf_to_use;
} else  {
__36046_10_result_buffer = ((char *)0);
}
}

if (__36035_18_status != ((int *)0)) { (*__36035_18_status) = __36045_8_result_status; }



return __36046_10_result_buffer;


}
