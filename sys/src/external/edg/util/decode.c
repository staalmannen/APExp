/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:52 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "util/decode.c"
# 93
struct a_decode_control_block;
# 181
struct a_template_param_block;
# 42 "/usr/include/x86_64-linux-gnu/bits/types.h" 3
typedef unsigned __uint32_t;
# 26 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 3
typedef __uint32_t uint32_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 92 "util/decode.c"
typedef struct a_decode_control_block *a_decode_control_block_ptr;
# 541 "src/basics.h"
typedef size_t _ZN3edg8sizeof_tE;
# 219
typedef int _ZN3edg9a_booleanE;
# 515
typedef const char _ZN3edg12a_const_charE;
# 93 "util/decode.c"
struct a_decode_control_block {
char *output_id;


_ZN3edg8sizeof_tE output_id_len;


_ZN3edg8sizeof_tE output_id_size;

_ZN3edg9a_booleanE err_in_id;


_ZN3edg9a_booleanE output_overflow_err;


unsigned long suppress_id_output;



_ZN3edg8sizeof_tE uncompressed_length;




_ZN3edg12a_const_charE *end_of_name;




unsigned long mangling_nesting_level;};
# 148
typedef struct a_decode_control_block a_decode_control_block;
# 180
typedef struct a_template_param_block *a_template_param_block_ptr;
struct a_template_param_block {
unsigned long nesting_level;


_ZN3edg12a_const_charE *final_specialization;




_ZN3edg9a_booleanE set_final_specialization;


_ZN3edg9a_booleanE actual_template_args_until_final_specialization;



_ZN3edg9a_booleanE output_only_correspondences;
# 204
_ZN3edg9a_booleanE first_correspondence;


_ZN3edg9a_booleanE use_old_form_for_template_output;char __dummy[4];};



typedef struct a_template_param_block a_template_param_block;
# 385 "/usr/include/stdio.h" 3
extern __attribute__((__nothrow__)) int snprintf(char *__s, size_t __maxlen, const char *__format, ...);
# 156 "/usr/include/string.h" 3
extern __attribute__((__pure__)) __attribute__((__nothrow__)) int strcmp(const char *__s1, const char *__s2);
# 228
extern __attribute__((__pure__)) __attribute__((__nothrow__)) const char *_Z6strchrPKci(const char *__s, int __c) __asm__("strchr");
# 109 "/usr/include/ctype.h" 3
extern __attribute__((__nothrow__)) int isalpha(int);

extern __attribute__((__nothrow__)) int isdigit(int);
# 151 "util/decode.c"
static void _ZN29_INTERNAL_8_decode_c_e6cffa8819clear_control_blockEP22a_decode_control_block(a_decode_control_block_ptr dctl);
# 289
static void _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(char ch, a_decode_control_block_ptr dctl);
# 317
static void _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *str, a_decode_control_block_ptr dctl);
# 331
static void _ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block(unsigned long num, a_decode_control_block_ptr dctl);
# 361
static void _ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(a_decode_control_block_ptr dctl);
# 409
static char _ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 428
static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(_ZN3edg12a_const_charE *str, _ZN3edg12a_const_charE *id, a_decode_control_block_ptr dctl);
# 450
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8812advance_pastEcPKcP22a_decode_control_block(const char ch, _ZN3edg12a_const_charE *p, a_decode_control_block_ptr dctl);
# 467
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *p, a_decode_control_block_ptr dctl);
# 487
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8818demangle_module_idEPKcmS1_P22a_decode_control_block(_ZN3edg12a_const_charE *ptr, unsigned long num, _ZN3edg12a_const_charE *prefix, a_decode_control_block_ptr dctl);
# 543
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(_ZN3edg12a_const_charE *p, unsigned long *num, _ZN3edg12a_const_charE **prev_end, a_decode_control_block_ptr dctl);
# 582
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(_ZN3edg12a_const_charE *p, unsigned long *num, a_decode_control_block_ptr dctl);
# 609
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_numberEPKcPmP22a_decode_control_block(_ZN3edg12a_const_charE *p, unsigned long *num, a_decode_control_block_ptr dctl);
# 633
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_lengthEPKcPmPS1_P22a_decode_control_block(_ZN3edg12a_const_charE *p, unsigned long *num, _ZN3edg12a_const_charE **prev_end, a_decode_control_block_ptr dctl);
# 658
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8835get_length_with_optional_underscoreEPKcPmPS1_P22a_decode_control_block(_ZN3edg12a_const_charE *p, unsigned long *num, _ZN3edg12a_const_charE **prev_end, a_decode_control_block_ptr dctl);
# 704
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8835get_number_with_optional_underscoreEPKcPmP22a_decode_control_block(_ZN3edg12a_const_charE *p, unsigned long *num, a_decode_control_block_ptr dctl);
# 748
static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8827is_immediate_type_qualifierEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *p, a_decode_control_block_ptr dctl);
# 767
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8832remove_immediate_type_qualifiersEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *p, a_decode_control_block_ptr dctl);
# 788
static void _ZN29_INTERNAL_8_decode_c_e6cffa8829write_template_parameter_nameEmmiP22a_decode_control_block(unsigned long depth, unsigned long position, _ZN3edg9a_booleanE nontype, a_decode_control_block_ptr dctl);
# 835
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8832demangle_template_parameter_nameEPKciP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE nontype, a_decode_control_block_ptr dctl);
# 885
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_constant_valueEPKciiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE is_bool, _ZN3edg9a_booleanE is_nullptr, a_decode_control_block_ptr dctl);
# 956
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE suppress_address_of, _ZN3edg9a_booleanE need_parens, a_decode_control_block_ptr dctl);
# 1179
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8828demangle_parameter_referenceEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 1235
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE need_parens, a_decode_control_block_ptr dctl);
# 1305
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8818demangle_operationEPKciP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE need_parens, a_decode_control_block_ptr dctl);
# 1681
static void _ZN29_INTERNAL_8_decode_c_e6cffa8826clear_template_param_blockEP22a_template_param_block(a_template_param_block_ptr tpbp);
# 1696
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8827demangle_template_argumentsEPKciiP22a_template_param_blockP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE emit_arg_values, _ZN3edg9a_booleanE suppress_angle_brackets, a_template_param_block_ptr temp_par_info
# 1696
, a_decode_control_block_ptr dctl);
# 1836
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_operatorEPKcPiS2_S2_S2_S2_S2_S2_P22a_decode_control_block(_ZN3edg12a_const_charE *ptr, int *mangled_length, _ZN3edg9a_booleanE *takes_type, _ZN3edg9a_booleanE *is_new_style_cast, _ZN3edg9a_booleanE *is_postfix, 
# 1836
_ZN3edg9a_booleanE *need_adl_parens, _ZN3edg9a_booleanE *is_initializer_list, _ZN3edg9a_booleanE *ud_suffix_follows, a_decode_control_block_ptr dctl);
# 2093
static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8825is_operator_function_nameEPKcPS1_PiS3_P22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg12a_const_charE **demangled_name, int *mangled_length, _ZN3edg9a_booleanE *ud_suffix_follows, a_decode_control_block_ptr dctl);
# 2148
static void _ZN29_INTERNAL_8_decode_c_e6cffa8819note_specializationEPKcP22a_template_param_block(_ZN3edg12a_const_charE *ptr, a_template_param_block_ptr temp_par_info);
# 2170
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8834demangle_function_local_indicationEPKcmPmP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, unsigned long nchars, unsigned long *instance, a_decode_control_block_ptr dctl);
# 2219
static void _ZN29_INTERNAL_8_decode_c_e6cffa8813emit_instanceEmP22a_decode_control_block(unsigned long instance, a_decode_control_block_ptr dctl);
# 2236
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, unsigned long nchars, _ZN3edg9a_booleanE stop_on_underscores, unsigned long *nchars_left, _ZN3edg12a_const_charE *mclass, 
# 2236
a_template_param_block_ptr temp_par_info, _ZN3edg9a_booleanE *instance_emitted, a_decode_control_block_ptr dctl);
# 2666
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8840demangle_type_name_with_preceding_lengthEPKcimPmP22a_template_param_blockP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE base_name_only, unsigned long nchars, unsigned long *nchars_left, 
# 2666
a_template_param_block_ptr temp_par_info, a_decode_control_block_ptr dctl);
# 2761
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8835demangle_name_with_preceding_lengthEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 2780
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_simple_type_nameEPKciP22a_template_param_blockP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE base_name_only, a_template_param_block_ptr temp_par_info, a_decode_control_block_ptr dctl);
# 2819
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE base_name_only, a_template_param_block_ptr temp_par_info, _ZN3edg9a_booleanE is_destructor_name, 
# 2819
a_decode_control_block_ptr dctl);
# 2872
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_vtbl_class_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 2959
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE trailing_space, a_decode_control_block_ptr dctl);
# 2994
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_ref_qualifiersEPKcPS1_P22a_decode_control_block(_ZN3edg12a_const_charE *p, _ZN3edg12a_const_charE **ref_qual, a_decode_control_block_ptr dctl);
# 3017
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_type_specifierEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 3217
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8828demangle_function_parametersEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 3299
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824skip_extern_C_indicationEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 3314
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE under_lhs_declarator, _ZN3edg9a_booleanE need_trailing_space, a_decode_control_block_ptr dctl);
# 3483
static void _ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE under_lhs_declarator, a_decode_control_block_ptr dctl);
# 3628
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 3646
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8841demangle_identifier_with_preceding_lengthEPKciP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, _ZN3edg9a_booleanE suppress_parent_and_local_info, a_decode_control_block_ptr dctl);
# 3672
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, unsigned long nchars, _ZN3edg9a_booleanE suppress_parent_and_local_info, a_decode_control_block_ptr dctl);
# 3919
static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8820is_mangled_type_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 3961
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8829demangle_static_variable_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 3991
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_local_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *ptr, a_decode_control_block_ptr dctl);
# 4038
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823uncompress_mangled_nameEPKcP22a_decode_control_block(_ZN3edg12a_const_charE *id, a_decode_control_block_ptr dctl);
# 4148
extern void _Z17decode_identifierPKcPcmPiS2_Pm(_ZN3edg12a_const_charE *id, char *output_buffer, _ZN3edg8sizeof_tE output_buffer_size, _ZN3edg9a_booleanE *err, _ZN3edg9a_booleanE *buffer_overflow_err, _ZN3edg8sizeof_tE *required_buffer_size);
# 151
static void _ZN29_INTERNAL_8_decode_c_e6cffa8819clear_control_blockEP22a_decode_control_block( a_decode_control_block_ptr __28834_60_dctl)



{
(__28834_60_dctl->output_id) = ((char *)0);
(__28834_60_dctl->output_id_len) = 0UL;
(__28834_60_dctl->output_id_size) = 0UL;
(__28834_60_dctl->err_in_id) = 0;
(__28834_60_dctl->output_overflow_err) = 0;
(__28834_60_dctl->suppress_id_output) = 0UL;
(__28834_60_dctl->uncompressed_length) = 0UL;

(__28834_60_dctl->end_of_name) = ((_ZN3edg12a_const_charE *)0);
(__28834_60_dctl->mangling_nesting_level) = 0UL; 
# 172
}
# 289
static void _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block( char __28972_52_ch, 
a_decode_control_block_ptr __28973_52_dctl)



{
if (!(__28973_52_dctl->suppress_id_output)) {
if (!(__28973_52_dctl->output_overflow_err)) {

if (((__28973_52_dctl->output_id_len) + 1UL) >= (__28973_52_dctl->output_id_size)) {

(__28973_52_dctl->output_overflow_err) = 1;

if ((__28973_52_dctl->output_id_size) != 0UL) {
((__28973_52_dctl->output_id)[((__28973_52_dctl->output_id_size) - 1UL)]) = ((char)0);
}
} else  {

((__28973_52_dctl->output_id)[(__28973_52_dctl->output_id_len)]) = __28972_52_ch;
}
}


(__28973_52_dctl->output_id_len)++;
} 
}


static void _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__29000_53_str, 
a_decode_control_block_ptr __29001_52_dctl)



{
auto _ZN3edg12a_const_charE *__29006_17_p; __29006_17_p = __29000_53_str;

if (!(__29001_52_dctl->suppress_id_output)) {
for (; ((int)(*__29006_17_p)) != 0; __29006_17_p++) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*__29006_17_p), __29001_52_dctl); }
} 
}


static void _ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block( unsigned long __29014_56_num, 
a_decode_control_block_ptr __29015_56_dctl)




{
auto char __29021_17_buffer[50];

snprintf((__29021_17_buffer), 50UL, ((const char *)"%lu"), __29014_56_num);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__29021_17_buffer)), __29015_56_dctl); 
}
# 361
static void _ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block( a_decode_control_block_ptr __29044_57_dctl)



{
if (!(__29044_57_dctl->err_in_id)) {
(__29044_57_dctl->err_in_id) = 1;
(__29044_57_dctl->suppress_id_output)++;



} 
}
# 409
static char _ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__29092_50_ptr, 
a_decode_control_block_ptr __29093_49_dctl)
# 416
{
auto char __29100_8_ch;

if (__29092_50_ptr >= (__29093_49_dctl->end_of_name)) {
__29100_8_ch = ((char)0);
} else  {
__29100_8_ch = (*__29092_50_ptr);
}
return __29100_8_ch;
}


static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block( _ZN3edg12a_const_charE *__29111_61_str, 
_ZN3edg12a_const_charE *__29112_61_id, 
a_decode_control_block_ptr __29113_60_dctl)



{
auto _ZN3edg9a_booleanE __29118_13_is_start = 0;

for (; ; ) {
auto char __29121_10_chs; __29121_10_chs = (*(__29111_61_str++));
if (((int)__29121_10_chs) == 0) {
__29118_13_is_start = 1;
goto __T235215432;
}
if (((int)__29121_10_chs) != ((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29112_61_id++), __29113_60_dctl)))) { goto __T235215432; }
} __T235215432:;
return __29118_13_is_start;
}



static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8812advance_pastEcPKcP22a_decode_control_block( const char __29133_62_ch, 
_ZN3edg12a_const_charE *__29134_63_p, 
a_decode_control_block_ptr __29135_62_dctl)




{
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29134_63_p, __29135_62_dctl))) == ((int)__29133_62_ch)) {
__29134_63_p++;
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29135_62_dctl);
}
return __29134_63_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__29150_74_p, 
a_decode_control_block_ptr __29151_73_dctl)




{
return _ZN29_INTERNAL_8_decode_c_e6cffa8812advance_pastEcPKcP22a_decode_control_block(((char)95), __29150_74_p, __29151_73_dctl);
}
# 487
static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8818demangle_module_idEPKcmS1_P22a_decode_control_block( _ZN3edg12a_const_charE *__29170_69_ptr, 
unsigned long __29171_68_num, 
_ZN3edg12a_const_charE *__29172_69_prefix, 
a_decode_control_block_ptr __29173_68_dctl)
# 502
{



auto unsigned long __29189_17_num_chars_to_output;

auto _ZN3edg12a_const_charE *__29191_18_start;

if ((((int)(*__29170_69_ptr)) != 95) || (!(isdigit(((int)((unsigned char)(__29170_69_ptr[1]))))))) {


if (__29172_69_prefix != ((_ZN3edg12a_const_charE *)0)) {
while (__29172_69_prefix != __29170_69_ptr) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*(__29172_69_prefix++)), __29173_68_dctl); }
}
__29189_17_num_chars_to_output = __29171_68_num;
__29191_18_start = __29170_69_ptr;
} else  {
__29191_18_start = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block((__29170_69_ptr + 1), (&__29189_17_num_chars_to_output), __29173_68_dctl));
if (!(__29173_68_dctl->err_in_id)) {
auto uint32_t __29204_16_prefix_len; __29204_16_prefix_len = ((uint32_t)((__29191_18_start - __29170_69_ptr) + 1L));
if ((((int)(*__29191_18_start)) != 95) || (__29171_68_num < (((unsigned long)__29189_17_num_chars_to_output) + ((unsigned long)__29204_16_prefix_len))))



{
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29173_68_dctl);
} else  {

__29191_18_start++;
}
}
}
if (!(__29173_68_dctl->err_in_id)) {

while ((__29189_17_num_chars_to_output--) > 0UL) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*(__29191_18_start++)), __29173_68_dctl); }
}
return __29170_69_ptr + __29171_68_num;
}



static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block( _ZN3edg12a_const_charE *__29226_61_p, 
unsigned long *__29227_61_num, 
_ZN3edg12a_const_charE **__29228_62_prev_end, 
a_decode_control_block_ptr __29229_60_dctl)
# 554
{
auto unsigned long __29238_17_n = 0UL;
auto char __29239_12_ch;

(*__29228_62_prev_end) = (__29229_60_dctl->end_of_name);
__29239_12_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29226_61_p, __29229_60_dctl));
if (!(isdigit(((int)((unsigned char)__29239_12_ch))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29229_60_dctl);
goto __29259_1_end_of_routine;
}
do {
__29238_17_n = ((__29238_17_n * 10UL) + ((unsigned long)(((int)__29239_12_ch) - 48)));
if (__29238_17_n > ((unsigned long)(((__29229_60_dctl->end_of_name) - __29226_61_p) - 1L))) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29229_60_dctl);
__29238_17_n = ((unsigned long)(((__29229_60_dctl->end_of_name) - __29226_61_p) - 1L));
goto __29259_1_end_of_routine;
}
__29226_61_p++;
__29239_12_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29226_61_p, __29229_60_dctl));
} while (isdigit(((int)((unsigned char)__29239_12_ch))));
(__29229_60_dctl->end_of_name) = (__29226_61_p + __29238_17_n);
__29259_1_end_of_routine:;
(*__29227_61_num) = __29238_17_n;
return __29226_61_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block( _ZN3edg12a_const_charE *__29265_61_p, 
unsigned long *__29266_61_num, 
a_decode_control_block_ptr __29267_60_dctl)




{
auto unsigned long __29273_17_n = 0UL;
auto char __29274_12_ch;

__29274_12_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29265_61_p, __29267_60_dctl));
if (!(isdigit(((int)((unsigned char)__29274_12_ch))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29267_60_dctl);
goto __29286_1_end_of_routine;
}
do {
__29273_17_n = ((__29273_17_n * 10UL) + ((unsigned long)(((int)__29274_12_ch) - 48)));
__29265_61_p++;
__29274_12_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29265_61_p, __29267_60_dctl));
} while (isdigit(((int)((unsigned char)__29274_12_ch))));
__29286_1_end_of_routine:;
(*__29266_61_num) = __29273_17_n;
return __29265_61_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_numberEPKcPmP22a_decode_control_block( _ZN3edg12a_const_charE *__29292_74_p, 
unsigned long *__29293_74_num, 
a_decode_control_block_ptr __29294_73_dctl)
# 617
{
auto char __29301_8_ch;

(*__29293_74_num) = 0UL;
__29301_8_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29292_74_p, __29294_73_dctl));
if (!(isdigit(((int)((unsigned char)__29301_8_ch))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29294_73_dctl);
goto __29311_1_end_of_routine;
}
(*__29293_74_num) = ((unsigned long)(((int)__29301_8_ch) - 48));
__29292_74_p++;
__29311_1_end_of_routine:;
return __29292_74_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_lengthEPKcPmPS1_P22a_decode_control_block(
_ZN3edg12a_const_charE *__29317_70_p, 
unsigned long *__29318_70_num, 
_ZN3edg12a_const_charE **__29319_71_prev_end, 
a_decode_control_block_ptr __29320_69_dctl)
# 645
{
__29317_70_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_numberEPKcPmP22a_decode_control_block(__29317_70_p, __29318_70_num, __29320_69_dctl));
(*__29319_71_prev_end) = (__29320_69_dctl->end_of_name);
if ((*__29318_70_num) > ((unsigned long)((__29320_69_dctl->end_of_name) - __29317_70_p))) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29320_69_dctl);
} else  {
(__29320_69_dctl->end_of_name) = (__29317_70_p + (*__29318_70_num));
}
return __29317_70_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8835get_length_with_optional_underscoreEPKcPmPS1_P22a_decode_control_block(
_ZN3edg12a_const_charE *__29342_70_p, 
unsigned long *__29343_70_num, 
_ZN3edg12a_const_charE **__29344_71_prev_end, 
a_decode_control_block_ptr __29345_69_dctl)
# 672
{
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29342_70_p, __29345_69_dctl))) == 95) {



__29342_70_p++;

__29342_70_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__29342_70_p, __29343_70_num, __29344_71_prev_end, __29345_69_dctl));
__29342_70_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29342_70_p, __29345_69_dctl));
(__29345_69_dctl->end_of_name)++;
} else  { if (((isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29342_70_p, __29345_69_dctl)))))) && (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29342_70_p + 1), 
# 682
__29345_69_dctl))))))) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29342_70_p + 2), __29345_69_dctl))) == 95))

{
# 693
__29342_70_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__29342_70_p, __29343_70_num, __29344_71_prev_end, __29345_69_dctl));
__29342_70_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29342_70_p, __29345_69_dctl));
(__29345_69_dctl->end_of_name)++;
} else  {

__29342_70_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_lengthEPKcPmPS1_P22a_decode_control_block(__29342_70_p, __29343_70_num, __29344_71_prev_end, __29345_69_dctl));
} }
return __29342_70_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8835get_number_with_optional_underscoreEPKcPmP22a_decode_control_block(
_ZN3edg12a_const_charE *__29388_76_p, 
unsigned long *__29389_76_num, 
a_decode_control_block_ptr __29390_75_dctl)
# 718
{
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29388_76_p, __29390_75_dctl))) == 95) {



__29388_76_p++;

__29388_76_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__29388_76_p, __29389_76_num, __29390_75_dctl));
__29388_76_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29388_76_p, __29390_75_dctl));
} else  { if (((isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29388_76_p, __29390_75_dctl)))))) && (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29388_76_p + 1), 
# 727
__29390_75_dctl))))))) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29388_76_p + 2), __29390_75_dctl))) == 95))

{
# 738
__29388_76_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__29388_76_p, __29389_76_num, __29390_75_dctl));
__29388_76_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29388_76_p, __29390_75_dctl));
} else  {

__29388_76_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_numberEPKcPmP22a_decode_control_block(__29388_76_p, __29389_76_num, __29390_75_dctl));
} }
return __29388_76_p;
}


static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8827is_immediate_type_qualifierEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__29431_74_p, 
a_decode_control_block_ptr __29432_73_dctl)




{
auto _ZN3edg9a_booleanE __29438_13_is_type_qual = 0;
auto char __29439_13_ch;

__29439_13_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29431_74_p, __29432_73_dctl));
if (((((int)__29439_13_ch) == 67) || (((int)__29439_13_ch) == 86)) || ((((int)__29439_13_ch) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29431_74_p + 1), __29432_73_dctl))) == 114))) {

__29438_13_is_type_qual = 1;
}
return __29438_13_is_type_qual;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8832remove_immediate_type_qualifiersEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__29451_75_p, 
a_decode_control_block_ptr __29452_74_dctl)




{
while (_ZN29_INTERNAL_8_decode_c_e6cffa8827is_immediate_type_qualifierEPKcP22a_decode_control_block(__29451_75_p, __29452_74_dctl)) {
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29451_75_p, __29452_74_dctl))) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29451_75_p + 1), __29452_74_dctl))) == 114)) {

__29451_75_p += 2;
} else  {

__29451_75_p++;
}
}
return __29451_75_p;
}


static void _ZN29_INTERNAL_8_decode_c_e6cffa8829write_template_parameter_nameEmmiP22a_decode_control_block( unsigned long __29471_70_depth, 
unsigned long __29472_70_position, 
_ZN3edg9a_booleanE __29473_70_nontype, 
a_decode_control_block_ptr __29474_70_dctl)




{
auto char __29480_8_buffer[100];
auto char __29481_8_letter = ((char)0);

if (__29473_70_nontype) {


if (__29471_70_depth == 1UL) {
__29481_8_letter = ((char)78);
} else  { if (__29471_70_depth == 2UL) {
__29481_8_letter = ((char)79);
} else  { if (__29471_70_depth == 3UL) {
__29481_8_letter = ((char)80);
} } }
if (((int)__29481_8_letter) != 0) {
snprintf((__29480_8_buffer), 100UL, ((const char *)"%c%lu"), ((int)__29481_8_letter), __29472_70_position);
} else  {
snprintf((__29480_8_buffer), 100UL, ((const char *)"N_%lu_%lu"), __29471_70_depth, __29472_70_position);
}
} else  {


if (__29471_70_depth == 1UL) {
__29481_8_letter = ((char)84);
} else  { if (__29471_70_depth == 2UL) {
__29481_8_letter = ((char)85);
} else  { if (__29471_70_depth == 3UL) {
__29481_8_letter = ((char)86);
} } }
if (((int)__29481_8_letter) != 0) {
snprintf((__29480_8_buffer), 100UL, ((const char *)"%c%lu"), ((int)__29481_8_letter), __29472_70_position);
} else  {
snprintf((__29480_8_buffer), 100UL, ((const char *)"T_%lu_%lu"), __29471_70_depth, __29472_70_position);
}
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__29480_8_buffer)), __29474_70_dctl); 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8832demangle_template_parameter_nameEPKciP22a_decode_control_block(
_ZN3edg12a_const_charE *__29519_73_ptr, 
_ZN3edg9a_booleanE __29520_72_nontype, 
a_decode_control_block_ptr __29521_72_dctl)
# 844
{
auto _ZN3edg12a_const_charE *__29528_18_p;
auto unsigned long __29529_17_position; auto unsigned long __29529_27_depth = 1UL;
# 845
__29528_18_p = __29519_73_ptr;
# 851
__29528_18_p++;

__29528_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__29528_18_p, (&__29529_17_position), __29521_72_dctl));
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29528_18_p, __29521_72_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29528_18_p + 1), __29521_72_dctl))) != 95)) {

__29528_18_p++;
__29528_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__29528_18_p, (&__29529_27_depth), __29521_72_dctl));
}

_ZN29_INTERNAL_8_decode_c_e6cffa8829write_template_parameter_nameEmmiP22a_decode_control_block(__29529_27_depth, __29529_17_position, __29520_72_nontype, __29521_72_dctl);
if ((((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29528_18_p, __29521_72_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29528_18_p + 1), __29521_72_dctl))) == 95)) && (((int)(
# 861
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29528_18_p + 2), __29521_72_dctl))) == 116)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29528_18_p + 3), __29521_72_dctl))) == 109)) && (((int)(
# 861
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29528_18_p + 4), __29521_72_dctl))) == 95)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29528_18_p + 5), __29521_72_dctl))) == 95))




{


__29528_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8827demangle_template_argumentsEPKciiP22a_template_param_blockP22a_decode_control_block((__29528_18_p + 6), 0, 0, ((a_template_param_block_ptr)0), __29521_72_dctl));


}



if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29528_18_p, __29521_72_dctl))) != 90) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29521_72_dctl);
} else  {
__29528_18_p++;
}
return __29528_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_constant_valueEPKciiP22a_decode_control_block(
_ZN3edg12a_const_charE *__29569_70_ptr, 
_ZN3edg9a_booleanE __29570_69_is_bool, 
_ZN3edg9a_booleanE __29571_69_is_nullptr, 
a_decode_control_block_ptr __29572_69_dctl)
# 905
{
auto _ZN3edg12a_const_charE *__29589_18_p; auto _ZN3edg12a_const_charE *__29589_28_prev_end;
auto char __29590_17_ch;
auto unsigned long __29591_17_nchars;
auto _ZN3edg9a_booleanE __29592_17_is_nonzero = 0;
# 906
__29589_18_p = __29569_70_ptr;
# 912
__29589_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8835get_length_with_optional_underscoreEPKcPmPS1_P22a_decode_control_block(__29589_18_p, (&__29591_17_nchars), (&__29589_28_prev_end), __29572_69_dctl));

for (; __29591_17_nchars > 0UL; (__29591_17_nchars--) , (__29589_18_p++)) {

__29590_17_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29589_18_p, __29572_69_dctl));
switch ((int)__29590_17_ch) {
case 0:
case 95:

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29572_69_dctl);
goto __29634_1_end_of_routine;
case 112:
__29590_17_ch = ((char)43);
goto __T235646416;
case 110:
__29590_17_ch = ((char)45);
goto __T235646416;
case 100:
__29590_17_ch = ((char)46);
goto __T235646416;
} __T235646416:;
if (__29570_69_is_bool) {


if (((int)__29590_17_ch) != 48) { __29592_17_is_nonzero = 1; }
} else  { if (__29571_69_is_nullptr) {

} else  {


_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(__29590_17_ch, __29572_69_dctl);
} }
}
(__29572_69_dctl->end_of_name) = __29589_28_prev_end;
if (__29570_69_is_bool) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)((char *)((__29592_17_is_nonzero) ? ((const char *)("true")) : ((const char *)("false"))))), __29572_69_dctl);
}
if (__29571_69_is_nullptr) { _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"nullptr"), __29572_69_dctl); }
__29634_1_end_of_routine:;
return __29589_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(
_ZN3edg12a_const_charE *__29640_61_ptr, 
_ZN3edg9a_booleanE __29641_60_suppress_address_of, 
_ZN3edg9a_booleanE __29642_60_need_parens, 
a_decode_control_block_ptr __29643_60_dctl)
# 970
{
auto _ZN3edg12a_const_charE *__29654_18_p; auto _ZN3edg12a_const_charE *__29654_28_type = ((_ZN3edg12a_const_charE *)0); auto _ZN3edg12a_const_charE *__29654_42_index; auto _ZN3edg12a_const_charE *__29654_50_prev_end; auto _ZN3edg12a_const_charE *__29654_61_quals;
auto unsigned long __29655_17_nchars;
auto char __29656_17_ch;
# 971
__29654_18_p = __29640_61_ptr;
# 985
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl))) == 67) {

__29654_28_type = __29654_18_p;
(__29643_60_dctl->suppress_id_output)++;
__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl));
(__29643_60_dctl->suppress_id_output)--;
}
# 1002
__29656_17_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl));
if (isdigit(((int)((unsigned char)__29656_17_ch)))) {

if (!(__29641_60_suppress_address_of)) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)38), __29643_60_dctl); }

__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8841demangle_identifier_with_preceding_lengthEPKciP22a_decode_control_block(__29654_18_p, 0, __29643_60_dctl));



} else  { if (((int)__29656_17_ch) == 76) {

if (__29642_60_need_parens) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29643_60_dctl); }
if (__29654_28_type == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29643_60_dctl);
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29654_18_p + 1), __29643_60_dctl))) == 77) {
# 1028
__29654_18_p += 2;

while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl)))))) { __29654_18_p++; }
__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl));

if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl))) != 76) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29643_60_dctl);
goto __29858_1_end_of_routine;
}
__29654_18_p++;
# 1043
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl))) == 95) {

__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8835get_length_with_optional_underscoreEPKcPmPS1_P22a_decode_control_block(__29654_18_p, (&__29655_17_nchars), (&__29654_50_prev_end), __29643_60_dctl));
} else  {
__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_lengthEPKcPmPS1_P22a_decode_control_block(__29654_18_p, (&__29655_17_nchars), (&__29654_50_prev_end), __29643_60_dctl));
}

__29654_42_index = __29654_18_p;

while ((isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl)))))) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl))) == 110)) {
__29654_18_p++; }
(__29643_60_dctl->end_of_name) = __29654_50_prev_end;
__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl));


if (((int)(*__29654_42_index)) == 110) {




_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)38), __29643_60_dctl);


__29654_61_quals = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block((__29654_28_type + 2), 0, ((a_template_param_block_ptr)0), 0, __29643_60_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __29643_60_dctl);

__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8841demangle_identifier_with_preceding_lengthEPKciP22a_decode_control_block(__29654_18_p, 1, __29643_60_dctl));



if (_ZN29_INTERNAL_8_decode_c_e6cffa8827is_immediate_type_qualifierEPKcP22a_decode_control_block(__29654_61_quals, __29643_60_dctl)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __29643_60_dctl);
__29654_61_quals = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(__29654_61_quals, 0, __29643_60_dctl));

}
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_61_quals, __29643_60_dctl))) == 70) {

auto _ZN3edg12a_const_charE *__29764_25_ref_qual;
_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_ref_qualifiersEPKcPS1_P22a_decode_control_block((__29654_61_quals + 1), (&__29764_25_ref_qual), __29643_60_dctl);
if (__29764_25_ref_qual != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29764_25_ref_qual, __29643_60_dctl);
}
}
} else  {


if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29654_18_p, __29643_60_dctl))) != 48) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29643_60_dctl);
goto __29858_1_end_of_routine;
}
__29654_18_p++;
if ((__29655_17_nchars == 1UL) && (((int)(*__29654_42_index)) == 48)) {


_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29643_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29654_28_type, __29643_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")0"), __29643_60_dctl);
} else  {



_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)38), __29643_60_dctl);


_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block((__29654_28_type + 2), 0, ((a_template_param_block_ptr)0), 0, __29643_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __29643_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"virtual-function-"), __29643_60_dctl);

for (; __29655_17_nchars > 0UL; (__29655_17_nchars--) , (__29654_42_index++)) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*__29654_42_index), __29643_60_dctl); }
}
}
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29654_18_p + 1), __29643_60_dctl))) == 83) {

__29654_18_p += 2;


_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29643_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__29654_28_type + 1), __29643_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")\"...\""), __29643_60_dctl);
} else  {
# 1136
auto _ZN3edg9a_booleanE __29819_17_is_bool;
auto _ZN3edg9a_booleanE __29820_17_is_managed_nullptr;
auto _ZN3edg9a_booleanE __29821_17_is_nullptr;

auto _ZN3edg9a_booleanE __29823_17_is_complex;
# 1136
__29819_17_is_bool = ((_ZN3edg9a_booleanE)(((__29654_28_type + 2) == __29654_18_p) && (((int)(*(__29654_28_type + 1))) == 98)));
__29820_17_is_managed_nullptr = ((_ZN3edg9a_booleanE)(((__29654_28_type + 2) == __29654_18_p) && (((int)(*(__29654_28_type + 1))) == 106)));
__29821_17_is_nullptr = ((_ZN3edg9a_booleanE)((((__29654_28_type + 2) == __29654_18_p) && (((int)(*(__29654_28_type + 1))) == 110)) || (__29820_17_is_managed_nullptr)));

__29823_17_is_complex = ((_ZN3edg9a_booleanE)(((__29654_28_type + 3) == __29654_18_p) && (((int)(*(__29654_28_type + 1))) == 120)));

if (!((__29819_17_is_bool) || (__29821_17_is_nullptr))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29643_60_dctl);

_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__29654_28_type + 1), __29643_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __29643_60_dctl);
}
if (__29823_17_is_complex) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29643_60_dctl); }
__29654_18_p++;
if (__29820_17_is_managed_nullptr) {


_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"__"), __29643_60_dctl);
}
__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_constant_valueEPKciiP22a_decode_control_block(__29654_18_p, __29819_17_is_bool, __29821_17_is_nullptr, __29643_60_dctl));
if ((!(__29643_60_dctl->err_in_id)) && (__29823_17_is_complex)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)43), __29643_60_dctl);
__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_constant_valueEPKciiP22a_decode_control_block(__29654_18_p, 0, 0, __29643_60_dctl));

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"i)"), __29643_60_dctl);
}
} } }
if (__29642_60_need_parens) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __29643_60_dctl); }
} else  { if (((int)__29656_17_ch) == 90) {

__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8832demangle_template_parameter_nameEPKciP22a_decode_control_block(__29654_18_p, 1, __29643_60_dctl));
} else  { if (((int)__29656_17_ch) == 79) {

__29654_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8818demangle_operationEPKciP22a_decode_control_block(__29654_18_p, __29642_60_need_parens, __29643_60_dctl));
} else  {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29643_60_dctl);
} } } }
__29858_1_end_of_routine:;
return __29654_18_p;
}

static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8828demangle_parameter_referenceEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__29863_76_ptr, 
a_decode_control_block_ptr __29864_75_dctl)
# 1196
{
auto _ZN3edg12a_const_charE *__29880_18_p;
auto unsigned long __29881_17_num; auto unsigned long __29881_22_level = 0UL;
auto char __29882_17_buffer[60];
# 1197
__29880_18_p = __29863_76_ptr;




__29880_18_p++;
if (_ZN29_INTERNAL_8_decode_c_e6cffa8827is_immediate_type_qualifierEPKcP22a_decode_control_block(__29880_18_p, __29864_75_dctl)) {

__29880_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(__29880_18_p, 1, __29864_75_dctl));
}
__29880_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__29880_18_p, (&__29881_17_num), __29864_75_dctl));
if (!(__29864_75_dctl->err_in_id)) {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29880_18_p, __29864_75_dctl))) != 73) {
__29880_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29880_18_p, __29864_75_dctl));
if (!(__29864_75_dctl->err_in_id)) {
__29880_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__29880_18_p, (&__29881_22_level), __29864_75_dctl));
}
}
}
if (!(__29864_75_dctl->err_in_id)) {
if (__29881_17_num == 0UL) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"this"), __29864_75_dctl);
} else  {
if (__29881_22_level == 0UL) {
snprintf((__29882_17_buffer), 60UL, ((const char *)"param#%ld"), __29881_17_num);
} else  {
snprintf((__29882_17_buffer), 60UL, ((const char *)"param#%ld[up %ld level%s]"), __29881_17_num, __29881_22_level, ((__29881_22_level > 1UL) ? ((const char *)("s")) : ((const char *)(""))));

}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((_ZN3edg12a_const_charE *)(__29882_17_buffer)), __29864_75_dctl);
}
__29880_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8812advance_pastEcPKcP22a_decode_control_block(((char)73), __29880_18_p, __29864_75_dctl));
}
return __29880_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(
_ZN3edg12a_const_charE *__29919_69_ptr, 
_ZN3edg9a_booleanE __29920_68_need_parens, 
a_decode_control_block_ptr __29921_68_dctl)
# 1244
{
auto _ZN3edg12a_const_charE *__29928_18_p; __29928_18_p = __29919_69_ptr;

if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29928_18_p, __29921_68_dctl))) == 73) {

__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8828demangle_parameter_referenceEPKcP22a_decode_control_block(__29928_18_p, __29921_68_dctl));
} else  { if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29928_18_p, __29921_68_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29928_18_p + 1), __29921_68_dctl))) == 95)) {


__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(__29928_18_p, 0UL, 1, ((unsigned long *)0), ((_ZN3edg12a_const_charE *)0), ((a_template_param_block_ptr)0), ((_ZN3edg9a_booleanE *)0), __29921_68_dctl));



if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29928_18_p, __29921_68_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29928_18_p + 1), __29921_68_dctl))) == 95)) {
__29928_18_p += 2;
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29921_68_dctl);
}
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29928_18_p, __29921_68_dctl))) == 100) {
# 1272
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29928_18_p + 1), __29921_68_dctl))) == 105) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)46), __29921_68_dctl);
__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8835demangle_name_with_preceding_lengthEPKcP22a_decode_control_block((__29928_18_p + 2), __29921_68_dctl));
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29928_18_p, __29921_68_dctl))) == 100) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29928_18_p + 1), __29921_68_dctl))) == 105)) {

} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)61), __29921_68_dctl);
}
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29928_18_p + 1), __29921_68_dctl))) == 120) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)91), __29921_68_dctl);
__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block((__29928_18_p + 2), 0, __29921_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"]="), __29921_68_dctl);
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29928_18_p + 1), __29921_68_dctl))) == 88) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)91), __29921_68_dctl);
__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block((__29928_18_p + 2), 0, __29921_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" ... "), __29921_68_dctl);
__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block((__29928_18_p + 2), 0, __29921_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"]="), __29921_68_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29921_68_dctl);
} } }
if (!(__29921_68_dctl->err_in_id)) {
__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29928_18_p, 0, __29921_68_dctl));
}
} else  {


__29928_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(__29928_18_p, 1, __29920_68_need_parens, __29921_68_dctl));
} } }
return __29928_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8818demangle_operationEPKciP22a_decode_control_block( _ZN3edg12a_const_charE *__29988_69_ptr, 
_ZN3edg9a_booleanE __29989_68_need_parens, 
a_decode_control_block_ptr __29990_68_dctl)
# 1315
{
auto _ZN3edg12a_const_charE *__29999_18_p; auto _ZN3edg12a_const_charE *__29999_28_operator_str; auto _ZN3edg12a_const_charE *__29999_43_close_str = ((const char *)"");
auto int __30000_17_op_length;
auto unsigned long __30001_17_num_operands; auto unsigned long __30001_31_i; auto unsigned long __30001_34_num_dimensions;
auto _ZN3edg9a_booleanE __30002_17_takes_type; auto _ZN3edg9a_booleanE __30002_29_is_new_style_cast; auto _ZN3edg9a_booleanE __30002_48_is_postfix; auto _ZN3edg9a_booleanE __30002_60_need_adl_parens;
auto _ZN3edg9a_booleanE __30003_17_has_variable_number_of_operands = 0; auto _ZN3edg9a_booleanE __30003_58_is_initializer_list;
auto _ZN3edg9a_booleanE __30004_17_is_call = 0; auto _ZN3edg9a_booleanE __30004_34_is_cli_subscript = 0;
auto _ZN3edg9a_booleanE __30005_17_ud_suffix_follows;
# 1316
__29999_18_p = __29988_69_ptr;
# 1335
__29999_18_p++;

__29999_28_operator_str = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_operatorEPKcPiS2_S2_S2_S2_S2_S2_P22a_decode_control_block(__29999_18_p, (&__30000_17_op_length), (&__30002_17_takes_type), (&__30002_29_is_new_style_cast), (&__30002_48_is_postfix), (&__30002_60_need_adl_parens), (&
# 1337
__30003_58_is_initializer_list), (&__30005_17_ud_suffix_follows), __29990_68_dctl));



if (__29999_28_operator_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29990_68_dctl);
} else  {

if (__29989_68_need_parens) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl); }
if ((((int)(*__29999_28_operator_str)) == 102) && ((strcmp(__29999_28_operator_str, ((const char *)"fold-ex"))) == 0)) {


auto _ZN3edg9a_booleanE __30032_20_unary; auto _ZN3edg9a_booleanE __30032_27_left; auto _ZN3edg9a_booleanE __30032_33_bad_fold_mangle = 0;
__29999_18_p++;
switch ((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) {
case 108: __30032_20_unary = 1; __30032_27_left = 1; goto __T235835032;
case 76: __30032_20_unary = 0; __30032_27_left = 1; goto __T235835032;
case 114: __30032_20_unary = 1; __30032_27_left = 0; goto __T235835032;
case 82: __30032_20_unary = 0; __30032_27_left = 0; goto __T235835032;
default:
__30032_33_bad_fold_mangle = 1;
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29990_68_dctl);
goto __T235835032;
} __T235835032:;
if (!(__30032_33_bad_fold_mangle)) {
__29999_18_p++;
__29999_28_operator_str = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_operatorEPKcPiS2_S2_S2_S2_S2_S2_P22a_decode_control_block(__29999_18_p, (&__30000_17_op_length), (&__30002_17_takes_type), (&__30002_29_is_new_style_cast), (&__30002_48_is_postfix), (&__30002_60_need_adl_parens), (&
# 1363
__30003_58_is_initializer_list), (&__30005_17_ud_suffix_follows), __29990_68_dctl));




if (__29999_28_operator_str == ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29990_68_dctl);
} else  {
__29999_18_p += __30000_17_op_length;
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl);
if (__30032_20_unary) {
if (__30032_27_left) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __29990_68_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 0, __29990_68_dctl));
} else  {
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 0, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __29990_68_dctl);
}
} else  {
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 0, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __29990_68_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 0, __29990_68_dctl));
}
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __29990_68_dctl);
}
}
goto __30351_1_skip_operand_loop;
}
__29999_18_p += __30000_17_op_length;
if (__30003_58_is_initializer_list) {

if (__30002_17_takes_type) {
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
__30003_17_has_variable_number_of_operands = 1;
__29999_43_close_str = ((const char *)"}");
} else  { if (__30002_17_takes_type) {


if ((strcmp(__29999_28_operator_str, ((const char *)"cast"))) == 0) {
auto _ZN3edg12a_const_charE *__30091_23_num_args_ptr;
# 1414
(__29990_68_dctl->suppress_id_output)++;
__30091_23_num_args_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
(__29990_68_dctl->suppress_id_output)--;
_ZN29_INTERNAL_8_decode_c_e6cffa8835get_number_with_optional_underscoreEPKcPmP22a_decode_control_block(__30091_23_num_args_ptr, (&__30001_17_num_operands), __29990_68_dctl);

if (!(__29990_68_dctl->err_in_id)) {
__29999_28_operator_str = ((const char *)"");
if (__30001_17_num_operands == 1UL) {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl);
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __29990_68_dctl);
} else  {

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl);
__30003_17_has_variable_number_of_operands = 1;
__29999_43_close_str = ((const char *)")");
}
}
} else  { if ((((((strcmp(__29999_28_operator_str, ((const char *)"sizeof("))) == 0) || ((strcmp(__29999_28_operator_str, ((const char *)"__alignof__("))) == 0)) || ((strcmp(__29999_28_operator_str, ((const char *)"__uuidof("))) == 0)) || ((strcmp(__29999_28_operator_str, ((const char *)"typeid("))) 
# 1434
== 0)) || ((strcmp(__29999_28_operator_str, ((const char *)"sizeof...("))) == 0))



{



_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
__29999_28_operator_str = ((const char *)"");
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) == 101) {



_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"expr)"), __29990_68_dctl);
__29999_18_p++;
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) == 88) {


__29999_43_close_str = ((const char *)")");
__29999_18_p++;
} else  {


__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __29990_68_dctl);
} }
} else  { if ((strcmp(__29999_28_operator_str, ((const char *)"::typeid"))) == 0) {

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
} else  {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
if (__30002_29_is_new_style_cast) {



__29999_28_operator_str = ((const char *)"");
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)">("), __29990_68_dctl);
__29999_43_close_str = ((const char *)")");
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __29990_68_dctl);
}
} } }
} else  { if ((strcmp(__29999_28_operator_str, ((const char *)"builtin-operation"))) == 0) {
auto unsigned long __30164_21_kind;

__30003_17_has_variable_number_of_operands = 1;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"builtin-operation-"), __29990_68_dctl);

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__29999_18_p, (&__30164_21_kind), __29990_68_dctl));
if (__30164_21_kind > 99UL) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29990_68_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block(__30164_21_kind, __29990_68_dctl);
}
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl);
__29999_43_close_str = ((const char *)")");
} else  { if ((((strcmp(__29999_28_operator_str, ((const char *)"__real("))) == 0) || ((strcmp(__29999_28_operator_str, ((const char *)"__imag("))) == 0)) || ((strcmp(__29999_28_operator_str, ((const char *)"noexcept("))) == 0))

{

__29999_43_close_str = ((const char *)")");
} else  { if ((strcmp(__29999_28_operator_str, ((const char *)"()"))) == 0) {


__29999_28_operator_str = ((const char *)"");
__30004_17_is_call = 1;
__30003_17_has_variable_number_of_operands = 1;
} else  { if (((strcmp(__29999_28_operator_str, ((const char *)"new"))) == 0) || ((strcmp(__29999_28_operator_str, ((const char *)"new[]"))) == 0))
{
# 1515
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) == 103) {
__29999_18_p++;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __29990_68_dctl);
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __29990_68_dctl);
__29999_28_operator_str = ((const char *)"");
__30003_17_has_variable_number_of_operands = 1;

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8835get_number_with_optional_underscoreEPKcPmP22a_decode_control_block(__29999_18_p, (&__30001_17_num_operands), __29990_68_dctl));
if (__30001_17_num_operands != 0UL) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl);
for (__30001_31_i = 1UL; __30001_31_i <= __30001_17_num_operands; __30001_31_i++) {
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 0, __29990_68_dctl));
if (__30001_31_i != __30001_17_num_operands) { _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __29990_68_dctl); }
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)") "), __29990_68_dctl);
}
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
__30217_1_handle_new_operands:;
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) == 79) {

goto __30351_1_skip_operand_loop;
}
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) == 98) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__29999_18_p + 1), __29990_68_dctl))) == 105)) {

__29999_18_p += 2;
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)123), __29990_68_dctl);
__29999_43_close_str = ((const char *)"}");
} else  {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl);
__29999_43_close_str = ((const char *)")");
}
} else  { if ((strcmp(__29999_28_operator_str, ((const char *)"gcnew"))) == 0) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __29990_68_dctl);
__29999_28_operator_str = ((const char *)"");
__30003_17_has_variable_number_of_operands = 1;

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8835get_number_with_optional_underscoreEPKcPmP22a_decode_control_block(__29999_18_p, (&__30001_34_num_dimensions), __29990_68_dctl));
if (__30001_34_num_dimensions == 0UL) {

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
} else  {
auto _ZN3edg12a_const_charE *__30244_23_dim_p; __30244_23_dim_p = __29999_18_p;

(__29990_68_dctl->suppress_id_output)++;
for (__30001_31_i = 1UL; __30001_31_i <= __30001_34_num_dimensions; __30001_31_i++) {
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 0, __29990_68_dctl));
}
(__29990_68_dctl->suppress_id_output)--;
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __29990_68_dctl);
for (__30001_31_i = 1UL; __30001_31_i <= __30001_34_num_dimensions; __30001_31_i++) {
__30244_23_dim_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__30244_23_dim_p, 0, __29990_68_dctl));
if (__30001_31_i != __30001_34_num_dimensions) { _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __29990_68_dctl); }
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)") "), __29990_68_dctl);
}
goto __30217_1_handle_new_operands;
} else  { if (((strcmp(__29999_28_operator_str, ((const char *)"delete"))) == 0) || ((strcmp(__29999_28_operator_str, ((const char *)"delete[]"))) == 0))
{

if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) == 103) {
__29999_18_p++;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __29990_68_dctl);
}
} else  { if ((strcmp(__29999_28_operator_str, ((const char *)"subscript"))) == 0) {

__30003_17_has_variable_number_of_operands = 1;
__30004_34_is_cli_subscript = 1;
} else  { if ((strcmp(__29999_28_operator_str, ((const char *)"splice"))) == 0) {

__29999_28_operator_str = ((const char *)"[:");
__29999_43_close_str = ((const char *)":]");
} } } } } } } } } }

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8835get_number_with_optional_underscoreEPKcPmP22a_decode_control_block(__29999_18_p, (&__30001_17_num_operands), __29990_68_dctl));


if (__30001_17_num_operands != 0UL) {
if (__30003_17_has_variable_number_of_operands) {


for (__30001_31_i = 1UL; __30001_31_i <= __30001_17_num_operands; __30001_31_i++) {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) == 84) {

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__29999_18_p + 1), __29990_68_dctl));
} else  {
__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, __30002_60_need_adl_parens, __29990_68_dctl));
}
if (__30004_17_is_call) {


_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"("), __29990_68_dctl);
__29999_43_close_str = ((const char *)")");
__30004_17_is_call = 0;
} else  { if (__30004_34_is_cli_subscript) {


_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"["), __29990_68_dctl);
__29999_43_close_str = ((const char *)"]");
__30004_34_is_cli_subscript = 0;
} else  { if (__30001_31_i != __30001_17_num_operands) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __29990_68_dctl);
} } }
}
} else  {



if ((__30001_17_num_operands == 1UL) && (!(__30002_48_is_postfix))) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
if (((strcmp(__29999_28_operator_str, ((const char *)"delete"))) == 0) || ((strcmp(__29999_28_operator_str, ((const char *)"delete[]"))) == 0))
{

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __29990_68_dctl);
}
}

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 1, __29990_68_dctl));
if ((__30001_17_num_operands == 1UL) && (__30002_48_is_postfix)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
}
if (__30001_17_num_operands > 1UL) {


if ((strcmp(__29999_28_operator_str, ((const char *)"[]"))) == 0) {


__29999_28_operator_str = ((const char *)"[");
__29999_43_close_str = ((const char *)"]");
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 1, __29990_68_dctl));
if (__30001_17_num_operands > 2UL) {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)58), __29990_68_dctl);

__29999_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__29999_18_p, 1, __29990_68_dctl));
}
}
}
} else  { if ((strcmp(__29999_28_operator_str, ((const char *)"throw "))) == 0) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_28_operator_str, __29990_68_dctl);
} }
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__29999_43_close_str, __29990_68_dctl);
__30351_1_skip_operand_loop:;
if (__29989_68_need_parens) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __29990_68_dctl); }

if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__29999_18_p, __29990_68_dctl))) != 79) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__29990_68_dctl);
} else  {
__29999_18_p++;
}
}
return __29999_18_p;
}


static void _ZN29_INTERNAL_8_decode_c_e6cffa8826clear_template_param_blockEP22a_template_param_block( a_template_param_block_ptr __30364_67_tpbp)



{
(__30364_67_tpbp->nesting_level) = 0UL;
(__30364_67_tpbp->final_specialization) = ((_ZN3edg12a_const_charE *)0);
(__30364_67_tpbp->set_final_specialization) = 0;
(__30364_67_tpbp->actual_template_args_until_final_specialization) = 0;
(__30364_67_tpbp->output_only_correspondences) = 0;
(__30364_67_tpbp->first_correspondence) = 0;
(__30364_67_tpbp->use_old_form_for_template_output) = 0; 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8827demangle_template_argumentsEPKciiP22a_template_param_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__30380_57_ptr, 
_ZN3edg9a_booleanE __30381_56_emit_arg_values, 
_ZN3edg9a_booleanE __30382_56_suppress_angle_brackets, 
a_template_param_block_ptr __30383_56_temp_par_info, 
a_decode_control_block_ptr __30384_56_dctl)
# 1714
{
auto _ZN3edg12a_const_charE *__30398_18_p; auto _ZN3edg12a_const_charE *__30398_28_arg_base; auto _ZN3edg12a_const_charE *__30398_39_prev_end;
auto char __30399_17_ch;
auto unsigned long __30400_17_nchars; auto unsigned long __30400_25_position;
auto _ZN3edg9a_booleanE __30401_17_nontype; auto _ZN3edg9a_booleanE __30401_26_skipped; auto _ZN3edg9a_booleanE __30401_35_unskipped; auto _ZN3edg9a_booleanE __30401_46_is_pack;
# 1715
__30398_18_p = __30380_57_ptr;




if ((__30383_56_temp_par_info != ((a_template_param_block_ptr)0)) && (!(__30381_56_emit_arg_values))) {
(__30383_56_temp_par_info->nesting_level)++;
}
# 1734
if (!(__30382_56_suppress_angle_brackets)) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)60), __30384_56_dctl); }

__30398_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__30398_18_p, (&__30400_17_nchars), (&__30398_39_prev_end), __30384_56_dctl));
__30398_28_arg_base = __30398_18_p;
__30398_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__30398_18_p, __30384_56_dctl));

for (__30400_25_position = 1UL; ; __30400_25_position++) {

if (((unsigned long)(__30398_18_p - __30398_28_arg_base)) >= __30400_17_nchars) { goto __T236089264; }
if (__30384_56_dctl->err_in_id) { goto __T236089264; }
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__pk__"), __30398_18_p, __30384_56_dctl)) {
# 1751
__30401_46_is_pack = 1;
__30398_18_p += 6;
} else  {
__30401_46_is_pack = 0;
}
__30399_17_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30398_18_p, __30384_56_dctl));
if ((((int)__30399_17_ch) == 0) || ((((int)__30399_17_ch) == 95) && (!(__30401_46_is_pack)))) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30384_56_dctl);
goto __T236089264;
}

__30401_17_nontype = ((_ZN3edg9a_booleanE)(((int)__30399_17_ch) == 88));
__30401_26_skipped = (__30401_35_unskipped = 0);
if ((((!(__30381_56_emit_arg_values)) && (__30383_56_temp_par_info != ((a_template_param_block_ptr)0))) && (!(__30383_56_temp_par_info->use_old_form_for_template_output))) && (!(__30383_56_temp_par_info->actual_template_args_until_final_specialization)))

{

if (__30383_56_temp_par_info->output_only_correspondences) {



(__30384_56_dctl->suppress_id_output)--;
__30401_35_unskipped = 1;


if (__30383_56_temp_par_info->first_correspondence) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" [with "), __30384_56_dctl);
(__30383_56_temp_par_info->first_correspondence) = 0;
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __30384_56_dctl);
}
}

_ZN29_INTERNAL_8_decode_c_e6cffa8829write_template_parameter_nameEmmiP22a_decode_control_block(((__30383_56_temp_par_info->nesting_level) + (__30384_56_dctl->mangling_nesting_level)), __30400_25_position, __30401_17_nontype, __30384_56_dctl);



if (__30383_56_temp_par_info->output_only_correspondences) {


if (__30401_46_is_pack) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __30384_56_dctl);
}
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)61), __30384_56_dctl);
} else  {




(__30384_56_dctl->suppress_id_output)++;
__30401_26_skipped = 1;
}
}

if (__30401_17_nontype) {

__30398_18_p++;
__30398_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(__30398_18_p, 0, 0, __30384_56_dctl));

} else  { if (__30401_46_is_pack) {

auto a_template_param_block __30497_30_pack_temp_par_info;
_ZN29_INTERNAL_8_decode_c_e6cffa8826clear_template_param_blockEP22a_template_param_block((&__30497_30_pack_temp_par_info));

__30398_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8827demangle_template_argumentsEPKciiP22a_template_param_blockP22a_decode_control_block(__30398_18_p, 1, 1, (&__30497_30_pack_temp_par_info), __30384_56_dctl));


} else  {

__30398_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__30398_18_p, __30384_56_dctl));
} }
if (__30401_26_skipped) { (__30384_56_dctl->suppress_id_output)--; }
if (__30401_35_unskipped) { (__30384_56_dctl->suppress_id_output)++; }

if (((unsigned long)(__30398_18_p - __30398_28_arg_base)) >= __30400_17_nchars) { goto __T236089264; }
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __30384_56_dctl);
} __T236089264:;
(__30384_56_dctl->end_of_name) = __30398_39_prev_end;
if (!(__30382_56_suppress_angle_brackets)) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)62), __30384_56_dctl); }
return __30398_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_operatorEPKcPiS2_S2_S2_S2_S2_S2_P22a_decode_control_block(
_ZN3edg12a_const_charE *__30520_60_ptr, 
int *__30521_60_mangled_length, 
_ZN3edg9a_booleanE *__30522_60_takes_type, 
_ZN3edg9a_booleanE *__30523_60_is_new_style_cast, 
_ZN3edg9a_booleanE *__30524_60_is_postfix, 
_ZN3edg9a_booleanE *__30525_60_need_adl_parens, 
_ZN3edg9a_booleanE *__30526_60_is_initializer_list, 
_ZN3edg9a_booleanE *__30527_60_ud_suffix_follows, 
a_decode_control_block_ptr __30528_59_dctl)
# 1862
{
auto _ZN3edg12a_const_charE *__30546_17_s;
auto int __30547_8_len = 2;

(*__30522_60_takes_type) = 0;
(*__30523_60_is_new_style_cast) = 0;
(*__30524_60_is_postfix) = 0;
(*__30525_60_need_adl_parens) = 0;
(*__30526_60_is_initializer_list) = 0;
(*__30527_60_ud_suffix_follows) = 0;


if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"apl"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"+=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ami"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"-=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"amu"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"*=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"adv"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"/=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"amd"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"%=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"aer"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"^=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"aad"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"&=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"aor"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"|=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ars"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)">>=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"als"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"<<=");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ppe"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"++");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"mme"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"--");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"nwa"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"new[]");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"dla"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"delete[]");
__30547_8_len = 3;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"nw"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"new");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"gc"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"gcnew");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"dl"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"delete");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"pl"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"+");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"mi"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"-");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ml"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"*");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"dv"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"/");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"md"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"%");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"er"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"^");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ad"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"&");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"or"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"|");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"co"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"~");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"nt"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"!");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"as"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"=");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"lt"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"<");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"gt"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)">");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ls"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"<<");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"rs"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)">>");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"eq"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"==");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ne"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"!=");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"le"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"<=");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ge"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)">=");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"aa"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"&&");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"oo"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"||");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"pp"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"++");
(*__30524_60_is_postfix) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"mm"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"--");
(*__30524_60_is_postfix) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"cm"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)",");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"rm"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"->*");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"rf"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"->");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"cl"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"()");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"cp"), __30520_60_ptr, __30528_59_dctl)) {
(*__30525_60_need_adl_parens) = 1;
__30546_17_s = ((const char *)"()");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"vc"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"[]");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"qs"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"\?");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"mn"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"<\?");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"mx"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)">\?");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ds"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)".*");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"dt"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)".");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ps"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"+");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ng"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"-");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"de"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"*");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ao"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"&");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ss"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"<=>");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"rl"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"__real(");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"im"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"__imag(");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"dc"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"dynamic_cast<");
(*__30523_60_is_new_style_cast) = 1;
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"sc"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"static_cast<");
(*__30523_60_is_new_style_cast) = 1;
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"cc"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"const_cast<");
(*__30523_60_is_new_style_cast) = 1;
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"rc"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"reinterpret_cast<");
(*__30523_60_is_new_style_cast) = 1;
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"sf"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"safe_cast<");
(*__30523_60_is_new_style_cast) = 1;
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"tw"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"throw ");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"sz"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"sizeof(");
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"cs"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"cast");
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"af"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"__alignof__(");
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"uu"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"__uuidof(");
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ty"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"typeid(");
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ct"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"::typeid");
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"bi"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"builtin-operation");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"sp"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"...");
(*__30524_60_is_postfix) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"sk"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"sizeof...(");
(*__30522_60_takes_type) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ht"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"%");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"sb"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"subscript");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"il"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"{");
(*__30526_60_is_initializer_list) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"tl"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"{");
(*__30522_60_takes_type) = 1;
(*__30526_60_is_initializer_list) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"nx"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"noexcept(");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"li"), __30520_60_ptr, __30528_59_dctl)) {


__30546_17_s = ((const char *)"\"\"");
(*__30527_60_ud_suffix_follows) = 1;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"aw"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"co_await");
} else  { if ((((_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"fr"), __30520_60_ptr, __30528_59_dctl)) || (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"fl"), __30520_60_ptr, __30528_59_dctl)))
# 2075
 || (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"fR"), __30520_60_ptr, __30528_59_dctl))) || (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"fL"), __30520_60_ptr, __30528_59_dctl)))


{



__30546_17_s = ((const char *)"fold-ex");
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"SP"), __30520_60_ptr, __30528_59_dctl)) {
__30546_17_s = ((const char *)"splice");
} else  {
__30546_17_s = ((_ZN3edg12a_const_charE *)0);
} } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } } }
(*__30521_60_mangled_length) = __30547_8_len;
return __30546_17_s;
}


static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8825is_operator_function_nameEPKcPS1_PiS3_P22a_decode_control_block(
_ZN3edg12a_const_charE *__30777_62_ptr, 
_ZN3edg12a_const_charE **__30778_63_demangled_name, 
int *__30779_62_mangled_length, 
_ZN3edg9a_booleanE *__30780_62_ud_suffix_follows, 
a_decode_control_block_ptr __30781_61_dctl)
# 2107
{
auto _ZN3edg12a_const_charE *__30791_17_s; auto _ZN3edg12a_const_charE *__30791_21_end_ptr;
auto int __30792_15_len;
auto _ZN3edg9a_booleanE __30793_15_takes_type; auto _ZN3edg9a_booleanE __30793_27_is_new_style_cast; auto _ZN3edg9a_booleanE __30793_46_is_postfix; auto _ZN3edg9a_booleanE __30793_58_need_adl_parens;
auto _ZN3edg9a_booleanE __30794_15_is_initializer_list;


__30791_17_s = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_operatorEPKcPiS2_S2_S2_S2_S2_S2_P22a_decode_control_block(__30777_62_ptr, (&__30792_15_len), (&__30793_15_takes_type), (&__30793_27_is_new_style_cast), (&__30793_46_is_postfix), (&__30793_58_need_adl_parens), (&
# 2114
__30794_15_is_initializer_list), __30780_62_ud_suffix_follows, __30781_61_dctl));


if (__30791_17_s != ((_ZN3edg12a_const_charE *)0)) {

__30791_21_end_ptr = (__30777_62_ptr + __30792_15_len);
if ((((*__30780_62_ud_suffix_follows) && (__30791_21_end_ptr != ((_ZN3edg12a_const_charE *)0))) && (!(__30781_61_dctl->err_in_id))) && (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30791_21_end_ptr, __30781_61_dctl)))))))
{



auto unsigned long __30808_22_num;
auto _ZN3edg12a_const_charE *__30809_23_prev_end;
__30791_21_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__30791_21_end_ptr, (&__30808_22_num), (&__30809_23_prev_end), __30781_61_dctl));
__30791_21_end_ptr = (__30791_21_end_ptr + __30808_22_num);


(__30781_61_dctl->end_of_name) = __30809_23_prev_end;
(__30781_61_dctl->err_in_id) = 0;
}
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30791_21_end_ptr, __30781_61_dctl))) == 0) || ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30791_21_end_ptr, __30781_61_dctl))) == 95) && (((int)(
# 2134
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30791_21_end_ptr + 1), __30781_61_dctl))) == 95)))
{

} else  {
__30791_17_s = ((_ZN3edg12a_const_charE *)0);
(*__30780_62_ud_suffix_follows) = 0;
}
}
(*__30778_63_demangled_name) = __30791_17_s;
(*__30779_62_mangled_length) = __30792_15_len;
return (_ZN3edg9a_booleanE)(__30791_17_s != ((_ZN3edg12a_const_charE *)0));
}


static void _ZN29_INTERNAL_8_decode_c_e6cffa8819note_specializationEPKcP22a_template_param_block( _ZN3edg12a_const_charE *__30831_61_ptr, 
a_template_param_block_ptr __30832_60_temp_par_info)
# 2155
{
if (__30832_60_temp_par_info != ((a_template_param_block_ptr)0)) {
if (__30832_60_temp_par_info->set_final_specialization) {

(__30832_60_temp_par_info->final_specialization) = __30831_61_ptr;
} else  { if ((__30832_60_temp_par_info->actual_template_args_until_final_specialization) && (__30831_61_ptr == (__30832_60_temp_par_info->final_specialization)))
{


(__30832_60_temp_par_info->actual_template_args_until_final_specialization) = 0;
} }
} 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8834demangle_function_local_indicationEPKcmPmP22a_decode_control_block(
_ZN3edg12a_const_charE *__30854_71_ptr, 
unsigned long __30855_70_nchars, 
unsigned long *__30856_71_instance, 
a_decode_control_block_ptr __30857_70_dctl)
# 2193
{
auto _ZN3edg12a_const_charE *__30877_18_p; auto _ZN3edg12a_const_charE *__30877_28_prev_end = ((_ZN3edg12a_const_charE *)0); __30877_18_p = __30854_71_ptr;

if (__30855_70_nchars != 0UL) {
__30877_28_prev_end = (__30857_70_dctl->end_of_name);
(__30857_70_dctl->end_of_name) = (__30854_71_ptr + __30855_70_nchars);
}

__30877_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__30854_71_ptr, __30856_71_instance, __30857_70_dctl));



if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30877_18_p, __30857_70_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30877_18_p + 1), __30857_70_dctl))) == 95)) {
__30877_18_p += 2;

if (__30855_70_nchars != 0UL) { __30855_70_nchars -= ((unsigned long)(__30877_18_p - __30854_71_ptr)); }
__30877_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(__30877_18_p, __30855_70_nchars, 0, __30857_70_dctl));


_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __30857_70_dctl);
}
if (__30877_28_prev_end != ((_ZN3edg12a_const_charE *)0)) { (__30857_70_dctl->end_of_name) = __30877_28_prev_end; }
return __30877_18_p;
}


static void _ZN29_INTERNAL_8_decode_c_e6cffa8813emit_instanceEmP22a_decode_control_block( unsigned long __30902_54_instance, 
a_decode_control_block_ptr __30903_54_dctl)
# 2227
{
if (!(__30903_54_dctl->err_in_id)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __30903_54_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block(__30902_54_instance, __30903_54_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")"), __30903_54_dctl);
} 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(
_ZN3edg12a_const_charE *__30920_61_ptr, 
unsigned long __30921_60_nchars, 
_ZN3edg9a_booleanE __30922_60_stop_on_underscores, 
unsigned long *__30923_61_nchars_left, 
_ZN3edg12a_const_charE *__30924_61_mclass, 
a_template_param_block_ptr __30925_60_temp_par_info, 
_ZN3edg9a_booleanE *__30926_61_instance_emitted, 
a_decode_control_block_ptr __30927_60_dctl)
# 2272
{
auto _ZN3edg12a_const_charE *__30956_18_p; auto _ZN3edg12a_const_charE *__30956_22_end_ptr = ((_ZN3edg12a_const_charE *)0); auto _ZN3edg12a_const_charE *__30956_39_prev_end = ((_ZN3edg12a_const_charE *)0);
auto _ZN3edg9a_booleanE __30957_17_is_special_name = 0; auto _ZN3edg9a_booleanE __30957_42_is_pt; auto _ZN3edg9a_booleanE __30957_49_is_partial_spec = 0;
auto _ZN3edg9a_booleanE __30958_17_partial_spec_output_suppressed = 0; auto _ZN3edg9a_booleanE __30958_57_ud_suffix_follows;
auto _ZN3edg12a_const_charE *__30959_18_demangled_name;
auto int __30960_17_mangled_length;
auto unsigned long __30961_17_discriminator;

if (__30926_61_instance_emitted != ((_ZN3edg9a_booleanE *)0)) { (*__30926_61_instance_emitted) = 0; }
if (__30921_60_nchars != 0UL) {
__30956_39_prev_end = (__30927_60_dctl->end_of_name);
(__30927_60_dctl->end_of_name) = (__30920_61_ptr + __30921_60_nchars);
}
if (__30923_61_nchars_left != ((unsigned long *)0)) { (*__30923_61_nchars_left) = 0UL; }

if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30920_61_ptr, __30927_60_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30920_61_ptr + 1), __30927_60_dctl))) == 95)) {

__30956_18_p = (__30920_61_ptr + 2);
if ((_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ct__"), __30956_18_p, __30927_60_dctl)) || (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"st__"), __30956_18_p, __30927_60_dctl)))
{

__30956_22_end_ptr = (__30956_18_p + 2);
if (__30924_61_mclass == ((_ZN3edg12a_const_charE *)0)) {


} else  {

__30957_17_is_special_name = 1;
_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__30924_61_mclass, 1, ((a_template_param_block_ptr)0), 0, __30927_60_dctl);




if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"st__"), __30956_18_p, __30927_60_dctl)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"[static]"), __30927_60_dctl);
}
}
} else  { if ((_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"dt__"), __30956_18_p, __30927_60_dctl)) || (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"df__"), __30956_18_p, __30927_60_dctl)))
{

__30956_22_end_ptr = (__30956_18_p + 2);
if (__30924_61_mclass == ((_ZN3edg12a_const_charE *)0)) {


} else  {


__30957_17_is_special_name = 1;
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"df__"), __30956_18_p, __30927_60_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)33), __30927_60_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)126), __30927_60_dctl);
}
_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__30924_61_mclass, 1, ((a_template_param_block_ptr)0), 0, __30927_60_dctl);




}
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"dn__"), __30956_18_p, __30927_60_dctl)) {
# 2341
__30957_17_is_special_name = 1;
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 4), __30927_60_dctl))) == 81) {

__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block((__30956_18_p + 4), 0, ((a_template_param_block_ptr)0), 1, __30927_60_dctl));




} else  {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)126), __30927_60_dctl);
__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__30956_18_p + 4), __30927_60_dctl));
}
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"op"), __30956_18_p, __30927_60_dctl)) {


__30957_17_is_special_name = 1;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __30927_60_dctl);
__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__30956_18_p + 2), __30927_60_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8825is_operator_function_nameEPKcPS1_PiS3_P22a_decode_control_block(__30956_18_p, (&__30959_18_demangled_name), (&__30960_17_mangled_length), (&__30958_57_ud_suffix_follows), __30927_60_dctl))

{

__30957_17_is_special_name = 1;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"operator "), __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__30959_18_demangled_name, __30927_60_dctl);
__30956_22_end_ptr = (__30956_18_p + __30960_17_mangled_length);
if (__30958_57_ud_suffix_follows) {

__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8835demangle_name_with_preceding_lengthEPKcP22a_decode_control_block(__30956_22_end_ptr, __30927_60_dctl));
}
} else  { if ((__30921_60_nchars != 0UL) && (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"N"), __30956_18_p, __30927_60_dctl))) {



__30957_17_is_special_name = 1;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"<unnamed>"), __30927_60_dctl);
__30956_22_end_ptr = ((__30956_18_p + __30921_60_nchars) - 2);
} else  { if ((__30921_60_nchars != 0UL) && (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"INTERNAL"), __30956_18_p, __30927_60_dctl))) {

__30957_17_is_special_name = 1;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"[local to "), __30927_60_dctl);
__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8818demangle_module_idEPKcmS1_P22a_decode_control_block((__30956_18_p + 8), (__30921_60_nchars - 10UL), (__30956_18_p - 2), __30927_60_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __30927_60_dctl);
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"Ut"), __30956_18_p, __30927_60_dctl)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"[unnamed type"), __30927_60_dctl);
__30956_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block((__30956_18_p + 2), (&__30961_17_discriminator), __30927_60_dctl));
if (__30961_17_discriminator > 0UL) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block(__30961_17_discriminator, __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")"), __30927_60_dctl);
__30957_17_is_special_name = 1;
__30956_22_end_ptr = __30956_18_p;
if (__30926_61_instance_emitted != ((_ZN3edg9a_booleanE *)0)) { (*__30926_61_instance_emitted) = 1; }
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __30927_60_dctl);
} else  { if ((_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"Ul"), __30956_18_p, __30927_60_dctl)) || (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"Um"), __30956_18_p, __30927_60_dctl)))
{




__30956_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block((__30956_18_p + 2), (&__30961_17_discriminator), __30927_60_dctl));
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30956_18_p, __30927_60_dctl))) == 95) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"[lambda"), __30927_60_dctl);
__30956_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__30956_18_p + 1), __30927_60_dctl));
if (__30961_17_discriminator > 0UL) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block(__30961_17_discriminator, __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")"), __30927_60_dctl);
__30957_17_is_special_name = 1;
__30956_22_end_ptr = __30956_18_p;
if (__30926_61_instance_emitted != ((_ZN3edg9a_booleanE *)0)) { (*__30926_61_instance_emitted) = 1; }
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __30927_60_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
}
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"Ud"), __30956_18_p, __30927_60_dctl)) {



auto unsigned long __31111_21_param_num;
__30956_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block((__30956_18_p + 2), (&__30961_17_discriminator), __30927_60_dctl));
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30956_18_p, __30927_60_dctl))) == 95) {
__30956_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block((__30956_18_p + 1), (&__31111_21_param_num), __30927_60_dctl));
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30956_18_p, __30927_60_dctl))) == 95) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"[lambda"), __30927_60_dctl);
__30956_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__30956_18_p + 1), __30927_60_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" in default argument "), __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block(__31111_21_param_num, __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" (from end)"), __30927_60_dctl);
if (__30961_17_discriminator > 0UL) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" (instance "), __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8815write_id_numberEmP22a_decode_control_block(__30961_17_discriminator, __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")"), __30927_60_dctl);
__30957_17_is_special_name = 1;
__30956_22_end_ptr = __30956_18_p;
if (__30926_61_instance_emitted != ((_ZN3edg9a_booleanE *)0)) { (*__30926_61_instance_emitted) = 1; }
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"]"), __30927_60_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
}
}
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"ab"), __30956_18_p, __30927_60_dctl)) {


auto unsigned long __31139_21_count;
__30956_18_p = (__30956_18_p + 2);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"[abi:"), __30927_60_dctl);
for (; ; ) {
__30956_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__30956_18_p, (&__31139_21_count), __30927_60_dctl));
if ((__31139_21_count == 0UL) || ((__30956_18_p + __31139_21_count) > (__30927_60_dctl->end_of_name))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
goto __T236696320;
}
while (__31139_21_count--) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*(__30956_18_p++)), __30927_60_dctl);
}
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__ab"), __30956_18_p, __30927_60_dctl)) {
__30956_18_p = (__30956_18_p + 4);
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)44), __30927_60_dctl);
} else  {
goto __T236696320;
}
} __T236696320:;
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)93), __30927_60_dctl);
if (!(__30927_60_dctl->err_in_id)) {



if (__30921_60_nchars != 0UL) {
if (__30921_60_nchars > ((unsigned long)(__30956_18_p - __30920_61_ptr))) {
__30921_60_nchars -= ((unsigned long)(__30956_18_p - __30920_61_ptr));
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
}
}
__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(__30956_18_p, __30921_60_nchars, __30922_60_stop_on_underscores, __30923_61_nchars_left, __30924_61_mclass, __30925_60_temp_par_info, __30926_61_instance_emitted, 
# 2487
__30927_60_dctl));

} else  {
__30956_22_end_ptr = __30956_18_p;
}
goto __31343_1_end_of_routine;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"SBC__"), __30956_18_p, __30927_60_dctl)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"structured binding for ["), __30927_60_dctl);
for (__30956_18_p = (__30956_18_p + 5); ((int)(*__30956_18_p)) != 0; ) {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30956_18_p, __30927_60_dctl))) == 95) {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 1), __30927_60_dctl))) == 95) {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 2), __30927_60_dctl))) == 95) {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 3), __30927_60_dctl))) == 95) {

__30956_18_p += 4;
} else  {
__30956_18_p += 3;
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
}
goto __T236719496;
} else  {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)44), __30927_60_dctl);
__30956_18_p += 2;
}
} else  {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)95), __30927_60_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((__30956_18_p[1]), __30927_60_dctl);
__30956_18_p += 2;
}
} else  {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*__30956_18_p), __30927_60_dctl);
__30956_18_p += 1;
}
} __T236719496:;
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)93), __30927_60_dctl);
__30956_22_end_ptr = __30956_18_p;
goto __31343_1_end_of_routine;
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"TPO__"), __30956_18_p, __30927_60_dctl)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"template parameter object for "), __30927_60_dctl);
__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block((__30956_18_p + 5), 1, 0, __30927_60_dctl));

goto __31343_1_end_of_routine;
} else  {

} } } } } } } } } } } } }
}


if (__30956_22_end_ptr == ((_ZN3edg12a_const_charE *)0)) {



for (__30956_18_p = __30920_61_ptr; ; __30956_18_p++) {
auto char __31228_12_ch; __31228_12_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30956_18_p, __30927_60_dctl));

if (((int)__31228_12_ch) == 0) { goto __T236734144; }




if (((((((int)__31228_12_ch) == 95) && (__30956_18_p != __30920_61_ptr)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 1), __30927_60_dctl))) == 95)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((
# 2552
__30956_18_p + 2), __30927_60_dctl))) != 95)) && (((((__30922_60_stop_on_underscores) || ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 2), __30927_60_dctl))) == 116) && (((int)(
# 2552
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 3), __30927_60_dctl))) == 109)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 4), __30927_60_dctl))) == 95)) && (((int)(
# 2552
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 5), __30927_60_dctl))) == 95))) || ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 2), __30927_60_dctl))) == 112) && (((int)(
# 2552
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 3), __30927_60_dctl))) == 115)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 4), __30927_60_dctl))) == 95)) && (((int)(
# 2552
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 5), __30927_60_dctl))) == 95))) || ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 2), __30927_60_dctl))) == 112) && (((int)(
# 2552
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 3), __30927_60_dctl))) == 116)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 4), __30927_60_dctl))) == 95)) && (((int)(
# 2552
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 5), __30927_60_dctl))) == 95))) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_18_p + 2), __30927_60_dctl))) == 83)))
# 2572
{
goto __T236734144;
}
} __T236734144:;
__30956_22_end_ptr = __30956_18_p;
}


if (!(__30957_17_is_special_name)) {

for (__30956_18_p = __30920_61_ptr; __30956_18_p < __30956_22_end_ptr; __30956_18_p++) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*__30956_18_p), __30927_60_dctl); }
}


if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__ps__"), __30956_22_end_ptr, __30927_60_dctl)) {
# 2597
__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8827demangle_template_argumentsEPKciiP22a_template_param_blockP22a_decode_control_block((__30956_22_end_ptr + 6), 1, 0, __30925_60_temp_par_info, __30927_60_dctl));


_ZN29_INTERNAL_8_decode_c_e6cffa8819note_specializationEPKcP22a_template_param_block(__30956_22_end_ptr, __30925_60_temp_par_info);
__30957_49_is_partial_spec = 1;
}

if ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30956_22_end_ptr, __30927_60_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 1), __30927_60_dctl))) == 95)) && (((int)(
# 2604
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 2), __30927_60_dctl))) == 83)) && (((!(__30922_60_stop_on_underscores)) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 3), __30927_60_dctl))) == 0
# 2604
)) || ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 3), __30927_60_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 4), __30927_60_dctl))) == 95))))
# 2610
{
_ZN29_INTERNAL_8_decode_c_e6cffa8819note_specializationEPKcP22a_template_param_block(__30956_22_end_ptr, __30925_60_temp_par_info);
__30956_22_end_ptr += 3;
}


if (((__30957_42_is_pt = (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__pt__"), __30956_22_end_ptr, __30927_60_dctl)))) || (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__tm__"), 
# 2616
__30956_22_end_ptr, __30927_60_dctl)))
{

if ((__30957_42_is_pt) && (__30925_60_temp_par_info != ((a_template_param_block_ptr)0))) {
(__30925_60_temp_par_info->use_old_form_for_template_output) = 1;
}


if (((__30957_49_is_partial_spec) && (__30925_60_temp_par_info != ((a_template_param_block_ptr)0))) && (!(__30925_60_temp_par_info->output_only_correspondences)))
{
(__30927_60_dctl->suppress_id_output)++;
__30958_17_partial_spec_output_suppressed = 1;
}

__30956_22_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8827demangle_template_argumentsEPKciiP22a_template_param_blockP22a_decode_control_block((__30956_22_end_ptr + 6), 0, 0, __30925_60_temp_par_info, __30927_60_dctl));


if (__30958_17_partial_spec_output_suppressed) { (__30927_60_dctl->suppress_id_output)--; }

if ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__30956_22_end_ptr, __30927_60_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 1), __30927_60_dctl))) == 95)) && (((int)(
# 2635
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 2), __30927_60_dctl))) == 83)) && (((!(__30922_60_stop_on_underscores)) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 3), __30927_60_dctl))) == 0
# 2635
)) || ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 3), __30927_60_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 4), __30927_60_dctl))) == 95))))
# 2641
{
_ZN29_INTERNAL_8_decode_c_e6cffa8819note_specializationEPKcP22a_template_param_block(__30956_22_end_ptr, __30925_60_temp_par_info);
__30956_22_end_ptr += 3;
}
}

if (__30923_61_nchars_left != ((unsigned long *)0)) {


(*__30923_61_nchars_left) = (__30921_60_nchars - ((unsigned long)(__30956_22_end_ptr - __30920_61_ptr)));
} else  { if (((__30921_60_nchars != 0UL) ? (((unsigned long)(__30956_22_end_ptr - __30920_61_ptr)) == __30921_60_nchars) : (((int)(*__30956_22_end_ptr)) == 0)) || (((__30922_60_stop_on_underscores) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(
# 2651
__30956_22_end_ptr, __30927_60_dctl))) == 95)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__30956_22_end_ptr + 1), __30927_60_dctl))) == 95)))



{

} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__30927_60_dctl);
} }
__31343_1_end_of_routine:;
if (__30956_39_prev_end != ((_ZN3edg12a_const_charE *)0)) { (__30927_60_dctl->end_of_name) = __30956_39_prev_end; }
return __30956_22_end_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8840demangle_type_name_with_preceding_lengthEPKcimPmP22a_template_param_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__31350_64_ptr, 
_ZN3edg9a_booleanE __31351_63_base_name_only, 
unsigned long __31352_63_nchars, 
unsigned long *__31353_64_nchars_left, 
a_template_param_block_ptr __31354_63_temp_par_info, 
a_decode_control_block_ptr __31355_63_dctl)
# 2685
{
auto _ZN3edg12a_const_charE *__31369_18_p; auto _ZN3edg12a_const_charE *__31369_28_orig_end; auto _ZN3edg12a_const_charE *__31369_39_prev_end;
auto _ZN3edg12a_const_charE *__31370_18_p2;
auto unsigned long __31371_17_nchars2; auto unsigned long __31371_26_instance;
auto _ZN3edg9a_booleanE __31372_17_has_function_local_info = 0;
auto _ZN3edg9a_booleanE __31373_17_instance_emitted;
auto _ZN3edg9a_booleanE __31374_17_stop_on_underscores;
# 2686
__31369_18_p = __31350_64_ptr;
# 2693
if (__31352_63_nchars == 0UL) {

__31369_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__31369_18_p, (&__31352_63_nchars), (&__31369_39_prev_end), __31355_63_dctl));
__31369_28_orig_end = ((_ZN3edg12a_const_charE *)0);
__31353_64_nchars_left = ((unsigned long *)0);
__31374_17_stop_on_underscores = 0;
} else  {

if (__31353_64_nchars_left != ((unsigned long *)0)) { (*__31353_64_nchars_left) = 0UL; }
__31369_39_prev_end = (__31355_63_dctl->end_of_name);
(__31355_63_dctl->end_of_name) = (__31369_28_orig_end = (__31350_64_ptr + __31352_63_nchars));
__31374_17_stop_on_underscores = 1;
}
if (__31352_63_nchars >= 8UL) {


for (__31370_18_p2 = (__31369_18_p + 1); (__31370_18_p2 + 6) < (__31369_18_p + __31352_63_nchars); __31370_18_p2++) {
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31370_18_p2, __31355_63_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31370_18_p2 + 1), __31355_63_dctl))) == 95))
{
if ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31370_18_p2 + 2), __31355_63_dctl))) == 116) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31370_18_p2 + 3), __31355_63_dctl))) == 109)) && (((int)(
# 2712
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31370_18_p2 + 4), __31355_63_dctl))) == 95)) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31370_18_p2 + 5), __31355_63_dctl))) == 95))


{



auto unsigned long __31402_25_skip;
auto _ZN3edg12a_const_charE *__31403_26_dummy; auto _ZN3edg12a_const_charE *__31403_34_save_end_of_name;
__31403_34_save_end_of_name = (__31355_63_dctl->end_of_name);
__31370_18_p2 = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block((__31370_18_p2 + 6), (&__31402_25_skip), (&__31403_26_dummy), __31355_63_dctl));
(__31355_63_dctl->end_of_name) = __31403_34_save_end_of_name;
__31370_18_p2 += __31402_25_skip;
}
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31370_18_p2 + 2), __31355_63_dctl))) == 76) {
__31372_17_has_function_local_info = 1;
__31371_17_nchars2 = __31352_63_nchars;

__31352_63_nchars = ((unsigned long)(__31370_18_p2 - __31369_18_p));
__31370_18_p2 += 3;
__31371_17_nchars2 -= ((unsigned long)(__31370_18_p2 - __31369_18_p));

if (__31351_63_base_name_only) { (__31355_63_dctl->suppress_id_output)++; }
__31370_18_p2 = (_ZN29_INTERNAL_8_decode_c_e6cffa8834demangle_function_local_indicationEPKcmPmP22a_decode_control_block(__31370_18_p2, __31371_17_nchars2, (&__31371_26_instance), __31355_63_dctl));

if (__31351_63_base_name_only) { (__31355_63_dctl->suppress_id_output)--; }
goto __T236851952;
}
}
} __T236851952:;
}

__31369_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(__31369_18_p, __31352_63_nchars, __31374_17_stop_on_underscores, __31353_64_nchars_left, ((_ZN3edg12a_const_charE *)0), __31354_63_temp_par_info, (&
# 2744
__31373_17_instance_emitted), __31355_63_dctl));


if (__31372_17_has_function_local_info) {


if ((!(__31373_17_instance_emitted)) && (!(__31351_63_base_name_only))) { _ZN29_INTERNAL_8_decode_c_e6cffa8813emit_instanceEmP22a_decode_control_block(__31371_26_instance, __31355_63_dctl); }
__31369_18_p = __31370_18_p2;
if ((__31353_64_nchars_left != ((unsigned long *)0)) && (__31369_28_orig_end != ((_ZN3edg12a_const_charE *)0))) {
(*__31353_64_nchars_left) = ((unsigned long)(__31369_28_orig_end - __31370_18_p2));
}
}
(__31355_63_dctl->end_of_name) = __31369_39_prev_end;
return __31369_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8835demangle_name_with_preceding_lengthEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__31445_76_ptr, 
a_decode_control_block_ptr __31446_75_dctl)




{
__31445_76_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8840demangle_type_name_with_preceding_lengthEPKcimPmP22a_template_param_blockP22a_decode_control_block(__31445_76_ptr, 1, 0UL, ((unsigned long *)0), ((a_template_param_block_ptr)0), __31446_75_dctl));
# 2776
return __31445_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_simple_type_nameEPKciP22a_template_param_blockP22a_decode_control_block(
_ZN3edg12a_const_charE *__31464_64_ptr, 
_ZN3edg9a_booleanE __31465_63_base_name_only, 
a_template_param_block_ptr __31466_63_temp_par_info, 
a_decode_control_block_ptr __31467_63_dctl)
# 2793
{
auto _ZN3edg12a_const_charE *__31477_17_p; __31477_17_p = __31464_64_ptr;

if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31477_17_p, __31467_63_dctl))) == 90) {

__31477_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8832demangle_template_parameter_nameEPKciP22a_decode_control_block(__31477_17_p, 0, __31467_63_dctl));
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31477_17_p, __31467_63_dctl))) == 71) {



__31477_17_p++;
} else  { if (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31477_17_p, __31467_63_dctl)))))) {


__31477_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8840demangle_type_name_with_preceding_lengthEPKcimPmP22a_template_param_blockP22a_decode_control_block(__31477_17_p, __31465_63_base_name_only, 0UL, ((unsigned long *)0), __31466_63_temp_par_info, __31467_63_dctl));



} else  {

__31477_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__31477_17_p, __31467_63_dctl));
} } }
return __31477_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(
_ZN3edg12a_const_charE *__31503_62_ptr, 
_ZN3edg9a_booleanE __31504_61_base_name_only, 
a_template_param_block_ptr __31505_61_temp_par_info, 
_ZN3edg9a_booleanE __31506_61_is_destructor_name, 
a_decode_control_block_ptr __31507_61_dctl)
# 2839
{
auto _ZN3edg12a_const_charE *__31523_18_p;
auto unsigned long __31524_17_nquals;
# 2840
__31523_18_p = __31503_62_ptr;


if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31523_18_p, __31507_61_dctl))) == 81) {
# 2850
__31523_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block((__31523_18_p + 1), (&__31524_17_nquals), __31507_61_dctl));
__31523_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__31523_18_p, __31507_61_dctl));

for (; __31524_17_nquals > 0UL; __31524_17_nquals--) {
if (__31507_61_dctl->err_in_id) { goto __T236883568; }


if ((__31504_61_base_name_only) && (__31524_17_nquals != 1UL)) { (__31507_61_dctl->suppress_id_output)++; }
if ((__31506_61_is_destructor_name) && (__31524_17_nquals == 1UL)) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)126), __31507_61_dctl); }
__31523_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_simple_type_nameEPKciP22a_template_param_blockP22a_decode_control_block(__31523_18_p, __31504_61_base_name_only, __31505_61_temp_par_info, __31507_61_dctl));
if (__31524_17_nquals != 1UL) { _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __31507_61_dctl); }
if ((__31504_61_base_name_only) && (__31524_17_nquals != 1UL)) { (__31507_61_dctl->suppress_id_output)--; }
} __T236883568:;
} else  {

if (__31506_61_is_destructor_name) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)126), __31507_61_dctl); }
__31523_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_simple_type_nameEPKciP22a_template_param_blockP22a_decode_control_block(__31523_18_p, __31504_61_base_name_only, __31505_61_temp_par_info, __31507_61_dctl));
}
return __31523_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_vtbl_class_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__31555_75_ptr, 
a_decode_control_block_ptr __31556_74_dctl)
# 2879
{
auto _ZN3edg12a_const_charE *__31563_18_p; auto _ZN3edg12a_const_charE *__31563_28_prev_end;
auto unsigned long __31564_17_nchars; auto unsigned long __31564_25_nchars_left;
# 2880
__31563_18_p = __31555_75_ptr;
# 2895
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31563_18_p, __31556_74_dctl))) == 81) {



__31563_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__31563_18_p, 0, ((a_template_param_block_ptr)0), 0, __31556_74_dctl));
} else  {

__31563_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__31563_18_p, (&__31564_17_nchars), (&__31563_28_prev_end), __31556_74_dctl));
while (!(__31556_74_dctl->err_in_id)) {
auto _ZN3edg9a_booleanE __31587_17_nested_name_case = 0;
# 2910
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31563_18_p, __31556_74_dctl))) == 81) {
auto _ZN3edg12a_const_charE *__31594_23_p2; __31594_23_p2 = (__31563_18_p + 1);
if (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31594_23_p2, __31556_74_dctl)))))) {
do { __31594_23_p2++; } while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31594_23_p2, __31556_74_dctl))))));
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31594_23_p2, __31556_74_dctl))) == 95) {
__31587_17_nested_name_case = 1;
}
}
}
if (__31587_17_nested_name_case) {

auto _ZN3edg12a_const_charE *__31604_24_end_ptr;
auto unsigned long __31605_23_chars_taken;
# 2921
__31604_24_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__31563_18_p, 0, ((a_template_param_block_ptr)0), 0, __31556_74_dctl));
__31605_23_chars_taken = ((unsigned long)(__31604_24_end_ptr - __31563_18_p));
__31564_17_nchars -= __31605_23_chars_taken;
__31563_18_p = __31604_24_end_ptr;
} else  {

__31563_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8840demangle_type_name_with_preceding_lengthEPKcimPmP22a_template_param_blockP22a_decode_control_block(__31563_18_p, 0, __31564_17_nchars, (&__31564_25_nchars_left), ((a_template_param_block_ptr)0), __31556_74_dctl));




__31564_17_nchars = __31564_25_nchars_left;
}


if ((__31564_17_nchars < 3UL) || (!(_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__"), __31563_18_p, __31556_74_dctl)))) { goto __T236920640; }
__31563_18_p += 2;
__31564_17_nchars -= 2UL;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" in "), __31556_74_dctl);
} __T236920640:;

if (__31564_17_nchars != 0UL) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__31556_74_dctl);
}
(__31556_74_dctl->end_of_name) = __31563_28_prev_end;
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__A"), __31563_18_p, __31556_74_dctl)) {


_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" (ambiguous)"), __31556_74_dctl);
__31563_18_p += 3;

while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31563_18_p, __31556_74_dctl)))))) { __31563_18_p++; }
}
}
return __31563_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(
_ZN3edg12a_const_charE *__31643_66_ptr, 
_ZN3edg9a_booleanE __31644_65_trailing_space, 
a_decode_control_block_ptr __31645_65_dctl)
# 2969
{
auto _ZN3edg12a_const_charE *__31653_17_p;
auto _ZN3edg9a_booleanE __31654_16_any_quals = 0;
# 2970
__31653_17_p = __31643_66_ptr;


for (; ; __31653_17_p++) {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31653_17_p, __31645_65_dctl))) == 67) {
if (__31654_16_any_quals) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __31645_65_dctl); }
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"const"), __31645_65_dctl);
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31653_17_p, __31645_65_dctl))) == 86) {
if (__31654_16_any_quals) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __31645_65_dctl); }
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"volatile"), __31645_65_dctl);
} else  { if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31653_17_p, __31645_65_dctl))) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31653_17_p + 1), __31645_65_dctl))) == 114)) {
if (__31654_16_any_quals) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __31645_65_dctl); }
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"restrict"), __31645_65_dctl);
__31653_17_p++;
} else  {
goto __T236945760;
} } }
__31654_16_any_quals = 1;
} __T236945760:;
if ((__31654_16_any_quals) && (__31644_65_trailing_space)) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __31645_65_dctl); }
return __31653_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_ref_qualifiersEPKcPS1_P22a_decode_control_block(
_ZN3edg12a_const_charE *__31678_70_p, 
_ZN3edg12a_const_charE **__31679_71_ref_qual, 
a_decode_control_block_ptr __31680_69_dctl)
# 3004
{
(*__31679_71_ref_qual) = ((_ZN3edg12a_const_charE *)0);
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31678_70_p, __31680_69_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31678_70_p + 1), __31680_69_dctl))) == 82)) {
__31678_70_p += 2;
(*__31679_71_ref_qual) = ((const char *)"&");
} else  { if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31678_70_p, __31680_69_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31678_70_p + 1), __31680_69_dctl))) == 69)) {
__31678_70_p += 2;
(*__31679_71_ref_qual) = ((const char *)"&&");
} }
return __31678_70_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_type_specifierEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__31700_74_ptr, 
a_decode_control_block_ptr __31701_73_dctl)




{
auto _ZN3edg12a_const_charE *__31707_17_p; auto _ZN3edg12a_const_charE *__31707_27_s;
auto char __31708_16_ch;
# 3024
__31707_17_p = __31700_74_ptr;



__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(__31707_17_p, 1, __31701_73_dctl));
__31708_16_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31707_17_p, __31701_73_dctl));
if (((isdigit(((int)((unsigned char)__31708_16_ch)))) || (((int)__31708_16_ch) == 81)) || (((int)__31708_16_ch) == 90)) {

__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__31707_17_p, 0, ((a_template_param_block_ptr)0), 0, __31701_73_dctl));
} else  {

if (((int)__31708_16_ch) == 97) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"__attribute__((vector_size("), __31701_73_dctl);
__31707_17_p++;

while ((__31708_16_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31707_17_p, __31701_73_dctl))) , (isdigit(((int)((unsigned char)__31708_16_ch))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(__31708_16_ch, __31701_73_dctl);
__31707_17_p++;
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"))) "), __31701_73_dctl);

__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__31707_17_p, __31701_73_dctl));
__31708_16_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31707_17_p, __31701_73_dctl));
}

if (((int)__31708_16_ch) == 83) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"signed "), __31701_73_dctl);
__31707_17_p++;
} else  { if (((int)__31708_16_ch) == 85) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"unsigned "), __31701_73_dctl);
__31707_17_p++;
} else  { if (((int)__31708_16_ch) == 120) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"_Complex "), __31701_73_dctl);
__31707_17_p++;
} } }
switch ((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31707_17_p++), __31701_73_dctl))) {
case 118:
__31707_27_s = ((const char *)"void");
goto __T236985416;
case 99:
__31707_27_s = ((const char *)"char");
goto __T236985416;
case 119:
__31707_27_s = ((const char *)"wchar_t");
goto __T236985416;
case 98:
__31707_27_s = ((const char *)"bool");
goto __T236985416;
case 115:
__31707_27_s = ((const char *)"short");
goto __T236985416;
case 105:
__31707_27_s = ((const char *)"int");
goto __T236985416;
case 108:
__31707_27_s = ((const char *)"long");
goto __T236985416;
case 76:
__31707_27_s = ((const char *)"long long");
goto __T236985416;
case 102:
__31707_27_s = ((const char *)"float");
goto __T236985416;
case 100:
__31707_27_s = ((const char *)"double");
goto __T236985416;
case 114:
__31707_27_s = ((const char *)"long double");
goto __T236985416;
case 109:


switch ((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31707_17_p++), __31701_73_dctl))) {
case 49:
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31707_17_p, __31701_73_dctl))) == 54) {
__31707_27_s = ((const char *)"__int128");
__31707_17_p++;
} else  {
__31707_27_s = ((const char *)"__int8");
}
goto __T237007616;
case 50:
__31707_27_s = ((const char *)"__int16");
goto __T237007616;
case 52:
__31707_27_s = ((const char *)"__int32");
goto __T237007616;
case 56:
__31707_27_s = ((const char *)"__int64");
goto __T237007616;
case 102:
__31708_16_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31707_17_p++), __31701_73_dctl));
if (((int)__31708_16_ch) == 49) {
switch ((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31707_17_p++), __31701_73_dctl))) {
case 48:
__31707_27_s = ((const char *)"__float80");
goto __T237017696;
case 54:
__31707_27_s = ((const char *)"__float128");
goto __T237017696;
default:
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__31701_73_dctl);
__31707_27_s = ((const char *)"");
} __T237017696:;
} else  { if (((int)__31708_16_ch) == 50) {
__31707_27_s = ((const char *)"_Float16");
} else  { if (((int)__31708_16_ch) == 52) {
__31707_27_s = ((const char *)"_Float32x");
} else  { if (((int)__31708_16_ch) == 54) {
__31707_27_s = ((const char *)"__fp16");
} else  { if (((int)__31708_16_ch) == 56) {
__31707_27_s = ((const char *)"_Float64x");
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__31701_73_dctl);
__31707_27_s = ((const char *)"");
} } } } }
goto __T237007616;
default:
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__31701_73_dctl);
__31707_27_s = ((const char *)"");
} __T237007616:;
goto __T236985416;
case 110:
__31707_27_s = ((const char *)"std::nullptr_t");
goto __T236985416;
case 106:
__31707_27_s = ((const char *)"__nullptr");
goto __T236985416;
case 117:
__31707_27_s = ((const char *)"auto");
goto __T236985416;
case 113:
__31707_27_s = ((const char *)"decltype(auto)");
goto __T236985416;
case 103:
__31707_27_s = ((const char *)"char16_t");
goto __T236985416;
case 107:
__31707_27_s = ((const char *)"char32_t");
goto __T236985416;
case 116:

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"typeof("), __31701_73_dctl);
__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__31707_17_p, __31701_73_dctl));
__31707_27_s = ((const char *)")");
goto __T236985416;
case 112:

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"typeof("), __31701_73_dctl);
__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__31707_17_p, 0, __31701_73_dctl));
__31707_27_s = ((const char *)")");
goto __T236985416;
case 121:

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"decltype("), __31701_73_dctl);
__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__31707_17_p, 0, __31701_73_dctl));
__31707_27_s = ((const char *)")");
goto __T236985416;
case 89:

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"decltype(("), __31701_73_dctl);
__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__31707_17_p, 0, __31701_73_dctl));
__31707_27_s = ((const char *)"))");
goto __T236985416;
case 111:

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"__underlying_type("), __31701_73_dctl);
__31707_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__31707_17_p, __31701_73_dctl));
__31707_27_s = ((const char *)")");
goto __T236985416;
case 68:

switch ((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31707_17_p++), __31701_73_dctl))) {
case 56:

__31707_27_s = ((const char *)"char8_t");
goto __T237061104;
default:
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__31701_73_dctl);
__31707_27_s = ((const char *)"");
} __T237061104:;
goto __T236985416;
default:
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__31701_73_dctl);
__31707_27_s = ((const char *)"");
} __T236985416:;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__31707_27_s, __31701_73_dctl);
}
return __31707_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8828demangle_function_parametersEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__31901_76_ptr, 
a_decode_control_block_ptr __31902_75_dctl)




{
auto _ZN3edg12a_const_charE *__31908_18_p;
auto _ZN3edg12a_const_charE *__31909_18_param_pos[10];
auto unsigned long __31910_17_curr_param_num; auto unsigned long __31910_33_param_num; auto unsigned long __31910_44_nreps;
auto _ZN3edg9a_booleanE __31911_17_any_params = 0;
# 3225
__31908_18_p = __31901_76_ptr;




_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __31902_75_dctl);
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31908_18_p, __31902_75_dctl))) == 118) {

__31908_18_p++;
} else  {
__31911_17_any_params = 1;

__31910_17_curr_param_num = 1UL;
for (; ; ) {
auto char __31922_12_ch;
if (__31902_75_dctl->err_in_id) { goto __T237075592; }
__31922_12_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31908_18_p, __31902_75_dctl));
if (((((int)__31922_12_ch) == 84) && (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31908_18_p + 1), __31902_75_dctl))))))) || (((int)__31922_12_ch) == 78))
{
# 3253
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__31908_18_p++), __31902_75_dctl))) == 78) {

__31908_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_numberEPKcPmP22a_decode_control_block(__31908_18_p, (&__31910_44_nreps), __31902_75_dctl));
} else  {
__31910_44_nreps = 1UL;
}

__31908_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823get_single_digit_numberEPKcPmP22a_decode_control_block(__31908_18_p, (&__31910_33_param_num), __31902_75_dctl));
if (((__31910_33_param_num < 1UL) || (__31910_33_param_num >= __31910_17_curr_param_num)) || (((__31909_18_param_pos)[__31910_33_param_num]) == ((_ZN3edg12a_const_charE *)0)))
{

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__31902_75_dctl);
goto __31977_1_end_of_routine;
}

for (; __31910_44_nreps > 0UL; __31910_44_nreps--) {
if (__31902_75_dctl->err_in_id) { goto __T237089184; }
if (__31910_17_curr_param_num < 10UL) { ((__31909_18_param_pos)[__31910_17_curr_param_num]) = ((_ZN3edg12a_const_charE *)0); }
_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(((__31909_18_param_pos)[__31910_33_param_num]), __31902_75_dctl);
if (__31910_44_nreps != 1UL) { _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __31902_75_dctl); }
__31910_17_curr_param_num++;
} __T237089184:;
} else  {

if (__31910_17_curr_param_num < 10UL) { ((__31909_18_param_pos)[__31910_17_curr_param_num]) = __31908_18_p; }
__31908_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block(__31908_18_p, __31902_75_dctl));
__31910_17_curr_param_num++;
}

__31922_12_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31908_18_p, __31902_75_dctl));
if ((((((int)__31922_12_ch) == 0) || (((int)__31922_12_ch) == 101)) || (((int)__31922_12_ch) == 95)) || (((int)__31922_12_ch) == 70)) { goto __T237075592; }
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __31902_75_dctl);
} __T237075592:;
}
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31908_18_p, __31902_75_dctl))) == 101) {

if (__31911_17_any_params) { _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)", "), __31902_75_dctl); }
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __31902_75_dctl);
__31908_18_p++;
}
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __31902_75_dctl);
__31977_1_end_of_routine:;
return __31908_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824skip_extern_C_indicationEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__31982_75_ptr, 
a_decode_control_block_ptr __31983_74_dctl)
# 3308
{
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__31982_75_ptr, __31983_74_dctl))) == 75) { __31982_75_ptr++; }
return __31982_75_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block(
_ZN3edg12a_const_charE *__31998_60_ptr, 
_ZN3edg9a_booleanE __31999_59_under_lhs_declarator, 
_ZN3edg9a_booleanE __32000_59_need_trailing_space, 
a_decode_control_block_ptr __32001_59_dctl)
# 3329
{
auto _ZN3edg12a_const_charE *__32013_17_p; auto _ZN3edg12a_const_charE *__32013_27_qualp;
auto char __32014_16_kind;
# 3330
__32013_17_p = __31998_60_ptr; __32013_27_qualp = __32013_17_p;



__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8832remove_immediate_type_qualifiersEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl));
__32014_16_kind = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl));
if ((((((int)__32014_16_kind) == 80) || (((int)__32014_16_kind) == 82)) || (((int)__32014_16_kind) == 69)) || (((int)__32014_16_kind) == 72)) {
auto _ZN3edg9a_booleanE __32020_15_need_space = 1;
auto char __32021_15_ext_kind = ((char)0);



if (((int)__32014_16_kind) == 72) {


__32013_17_p++;
__32021_15_ext_kind = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl));
if (((int)__32021_15_ext_kind) == 105) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"interior_ptr<"), __32001_59_dctl);
__32020_15_need_space = 0;
} else  { if (((int)__32021_15_ext_kind) == 112) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"pin_ptr<"), __32001_59_dctl);
__32020_15_need_space = 0;
} }
}
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block((__32013_17_p + 1), 1, __32020_15_need_space, __32001_59_dctl));



if (((int)__32014_16_kind) == 82) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)38), __32001_59_dctl);
} else  { if (((int)__32014_16_kind) == 69) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"&&"), __32001_59_dctl);
} else  { if (((int)__32014_16_kind) == 72) {
if (((int)__32021_15_ext_kind) == 104) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)94), __32001_59_dctl);
} else  { if (((int)__32021_15_ext_kind) == 116) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)37), __32001_59_dctl);
} else  { if (((int)__32021_15_ext_kind) == 105) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)62), __32001_59_dctl);
} else  { if (((int)__32021_15_ext_kind) == 112) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)62), __32001_59_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32001_59_dctl);
} } } }
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)42), __32001_59_dctl);
} } }

_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(__32013_27_qualp, __32000_59_need_trailing_space, __32001_59_dctl);
} else  { if (((int)__32014_16_kind) == 77) {


auto _ZN3edg12a_const_charE *__32066_19_classp; __32066_19_classp = (__32013_17_p + 1);

(__32001_59_dctl->suppress_id_output)++;
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__32066_19_classp, 0, ((a_template_param_block_ptr)0), 0, __32001_59_dctl));
(__32001_59_dctl->suppress_id_output)--;
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block(__32013_17_p, 1, 1, __32001_59_dctl));


_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__32066_19_classp, 0, ((a_template_param_block_ptr)0), 0, __32001_59_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::*"), __32001_59_dctl);

_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(__32013_27_qualp, __32000_59_need_trailing_space, __32001_59_dctl);
} else  { if (((int)__32014_16_kind) == 70) {



__32013_17_p++;


if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl))) == 95) && ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 82) || (((int)(
# 3402
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 69)))
{
__32013_17_p += 2;
}

if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl))) == 68) && ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 111) || (((int)(
# 3407
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 79)))
{
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 79) {
(__32001_59_dctl->suppress_id_output)++;
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block((__32013_17_p + 2), 0, 0, __32001_59_dctl));

(__32001_59_dctl->suppress_id_output)--;
} else  {
__32013_17_p += 2;
}
}
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824skip_extern_C_indicationEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl));

(__32001_59_dctl->suppress_id_output)++;
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8828demangle_function_parametersEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl));
(__32001_59_dctl->suppress_id_output)--;
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) != 95)) {

__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block((__32013_17_p + 1), 0, 1, __32001_59_dctl));

}


if (__31999_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __32001_59_dctl); }
} else  { if (((int)__32014_16_kind) == 65) {

__32013_17_p++;
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl))) == 95) {


__32013_17_p++;
(__32001_59_dctl->suppress_id_output)++;
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(__32013_17_p, 0, 0, __32001_59_dctl));

(__32001_59_dctl->suppress_id_output)--;
} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl))) == 79) {

(__32001_59_dctl->suppress_id_output)++;
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__32013_17_p, 0, __32001_59_dctl));
(__32001_59_dctl->suppress_id_output)--;
} else  {


while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl)))))) { __32013_17_p++; }
} }
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__32013_17_p, __32001_59_dctl));

__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block(__32013_17_p, 0, 1, __32001_59_dctl));



if (__31999_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)40), __32001_59_dctl); }
} else  { if ((((int)__32014_16_kind) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 112)) {

__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block((__32013_17_p + 2), 0, 0, __32001_59_dctl));

} else  { if ((((int)__32014_16_kind) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 82)) {

(__32001_59_dctl->suppress_id_output)++;
__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block((__32013_17_p + 2), 0, __32001_59_dctl));
(__32001_59_dctl->suppress_id_output)--;
} else  {
if ((((int)__32014_16_kind) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32013_17_p + 1), __32001_59_dctl))) == 88)) {


__32013_17_p += 3;
__32013_27_qualp = __32013_17_p;
}

__32013_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_type_specifierEPKcP22a_decode_control_block(__32013_27_qualp, __32001_59_dctl));
if (__32000_59_need_trailing_space) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __32001_59_dctl); }
} } } } } }
return __32013_17_p;
}


static void _ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block(
_ZN3edg12a_const_charE *__32167_60_ptr, 
_ZN3edg9a_booleanE __32168_59_under_lhs_declarator, 
a_decode_control_block_ptr __32169_59_dctl)
# 3497
{
auto _ZN3edg12a_const_charE *__32181_17_p; auto _ZN3edg12a_const_charE *__32181_27_qualp;
auto char __32182_16_kind;
# 3498
__32181_17_p = __32167_60_ptr; __32181_27_qualp = __32181_17_p;



__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8832remove_immediate_type_qualifiersEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl));
__32182_16_kind = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl));
if ((((((int)__32182_16_kind) == 80) || (((int)__32182_16_kind) == 82)) || (((int)__32182_16_kind) == 69)) || (((int)__32182_16_kind) == 72)) {




if (((int)__32182_16_kind) == 72) { __32181_17_p++; }
_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block((__32181_17_p + 1), 1, __32169_59_dctl);
} else  { if (((int)__32182_16_kind) == 77) {



(__32169_59_dctl->suppress_id_output)++;
__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block((__32181_17_p + 1), 0, ((a_template_param_block_ptr)0), 0, __32169_59_dctl));
(__32169_59_dctl->suppress_id_output)--;
_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block(__32181_17_p, 1, __32169_59_dctl);
} else  { if (((int)__32182_16_kind) == 70) {
auto _ZN3edg12a_const_charE *__32203_19_ref_qual; auto _ZN3edg12a_const_charE *__32203_30_save_noexcept_constant = ((_ZN3edg12a_const_charE *)0);
auto _ZN3edg9a_booleanE __32204_18_is_noexcept = 0;
# 3527
if (__32168_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __32169_59_dctl); }
__32181_17_p++;


__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823demangle_ref_qualifiersEPKcPS1_P22a_decode_control_block(__32181_17_p, (&__32203_19_ref_qual), __32169_59_dctl));

if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl))) == 68) && ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) == 111) || (((int)(
# 3533
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) == 79)))
{
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) == 79) {
(__32169_59_dctl->suppress_id_output)++;
__32203_30_save_noexcept_constant = (__32181_17_p + 2);
__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(__32203_30_save_noexcept_constant, 0, 0, __32169_59_dctl));


(__32169_59_dctl->suppress_id_output)--;
} else  {
__32204_18_is_noexcept = 1;
__32181_17_p += 2;
}
}
__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824skip_extern_C_indicationEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl));

__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8828demangle_function_parametersEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl));
# 3556
if (((int)(*__32181_27_qualp)) != 70) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)32), __32169_59_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_qualifiersEPKciP22a_decode_control_block(__32181_27_qualp, 0, __32169_59_dctl);
}
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) != 95)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block((__32181_17_p + 1), 0, __32169_59_dctl);
}
if (__32203_19_ref_qual != ((_ZN3edg12a_const_charE *)0)) { _ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(__32203_19_ref_qual, __32169_59_dctl); }
if (__32204_18_is_noexcept) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" noexcept"), __32169_59_dctl);
} else  { if (__32203_30_save_noexcept_constant != ((_ZN3edg12a_const_charE *)0)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" noexcept("), __32169_59_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(__32203_30_save_noexcept_constant, 0, 0, __32169_59_dctl);


_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __32169_59_dctl);
} }
} else  { if (((int)__32182_16_kind) == 65) {



if (__32168_59_under_lhs_declarator) { _ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)41), __32169_59_dctl); }
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)91), __32169_59_dctl);
__32181_17_p++;
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl))) == 95) {


__32181_17_p++;
__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8817demangle_constantEPKciiP22a_decode_control_block(__32181_17_p, 0, 0, __32169_59_dctl));

} else  { if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl))) == 79) {

__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block(__32181_17_p, 0, __32169_59_dctl));
} else  {

if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl))) == 48) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) == 95)) {

__32181_17_p++;
} else  {

while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl)))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*(__32181_17_p++)), __32169_59_dctl);
}
}
} }
__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8823advance_past_underscoreEPKcP22a_decode_control_block(__32181_17_p, __32169_59_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)93), __32169_59_dctl);

_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block(__32181_17_p, 0, __32169_59_dctl);
} else  { if ((((int)__32182_16_kind) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) == 112)) {

__32181_17_p += 2;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"..."), __32169_59_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block(__32181_17_p, 0, __32169_59_dctl);
} else  { if ((((int)__32182_16_kind) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) == 82)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"[:"), __32169_59_dctl);
__32181_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_expressionEPKciP22a_decode_control_block((__32181_17_p + 2), 0, __32169_59_dctl));
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)":]"), __32169_59_dctl);
} else  { if ((((int)__32182_16_kind) == 68) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32181_17_p + 1), __32169_59_dctl))) == 88)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" __attribute((pass_object_size("), __32169_59_dctl);

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((__32181_17_p[2]), __32169_59_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")))"), __32169_59_dctl);
} else  {


} } } } } } } 
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__32311_64_ptr, 
a_decode_control_block_ptr __32312_63_dctl)




{
auto _ZN3edg12a_const_charE *__32318_17_p;


__32318_17_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block(__32311_64_ptr, 0, 0, __32312_63_dctl));


_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block(__32311_64_ptr, 0, __32312_63_dctl);
return __32318_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8841demangle_identifier_with_preceding_lengthEPKciP22a_decode_control_block(
_ZN3edg12a_const_charE *__32330_50_ptr, 
_ZN3edg9a_booleanE __32331_49_suppress_parent_and_local_info, 
a_decode_control_block_ptr __32332_49_dctl)
# 3658
{
auto _ZN3edg12a_const_charE *__32342_18_p; auto _ZN3edg12a_const_charE *__32342_28_prev_end;
auto unsigned long __32343_17_nchars;
# 3659
__32342_18_p = __32330_50_ptr;


__32342_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__32342_18_p, (&__32343_17_nchars), (&__32342_28_prev_end), __32332_49_dctl));
(__32332_49_dctl->mangling_nesting_level)++;
__32342_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(__32342_18_p, __32343_17_nchars, __32331_49_suppress_parent_and_local_info, __32332_49_dctl));

(__32332_49_dctl->mangling_nesting_level)--;
(__32332_49_dctl->end_of_name) = __32342_28_prev_end;
return __32342_18_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(
_ZN3edg12a_const_charE *__32356_50_ptr, 
unsigned long __32357_49_nchars, 
_ZN3edg9a_booleanE __32358_49_suppress_parent_and_local_info, 
a_decode_control_block_ptr __32359_49_dctl)
# 3686
{
auto _ZN3edg12a_const_charE *__32370_18_p; auto _ZN3edg12a_const_charE *__32370_28_pname; auto _ZN3edg12a_const_charE *__32370_36_end_ptr; auto _ZN3edg12a_const_charE *__32370_46_function_local_end_ptr = ((_ZN3edg12a_const_charE *)0);
auto _ZN3edg12a_const_charE *__32371_18_final_specialization; auto _ZN3edg12a_const_charE *__32371_41_end_ptr_first_scan; auto _ZN3edg12a_const_charE *__32371_62_prev_end = ((_ZN3edg12a_const_charE *)0);
auto char __32372_17_ch;
auto _ZN3edg12a_const_charE *__32373_18_oname;
auto _ZN3edg9a_booleanE __32374_17_is_function = 1;

auto a_template_param_block __32376_17_temp_par_info;
auto _ZN3edg9a_booleanE __32377_17_is_externalized_static = 0;
auto _ZN3edg9a_booleanE __32378_17_has_function_local_info = 0;
auto unsigned long __32379_17_instance;
# 3687
__32370_18_p = __32356_50_ptr;
# 3698
_ZN29_INTERNAL_8_decode_c_e6cffa8826clear_template_param_blockEP22a_template_param_block((&__32376_17_temp_par_info));
if (__32357_49_nchars != 0UL) {
__32371_62_prev_end = (__32359_49_dctl->end_of_name);
(__32359_49_dctl->end_of_name) = (__32356_50_ptr + __32357_49_nchars);
}
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__STF__"), __32356_50_ptr, __32359_49_dctl)) {


__32377_17_is_externalized_static = 1;

__32356_50_ptr += 7;
if (__32357_49_nchars != 0UL) { __32357_49_nchars -= 7UL; }
}
# 3716
(__32376_17_temp_par_info.set_final_specialization) = 1;
(__32359_49_dctl->suppress_id_output)++;
__32370_18_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(__32356_50_ptr, __32357_49_nchars, 1, ((unsigned long *)0), ((_ZN3edg12a_const_charE *)0), (&__32376_17_temp_par_info), ((_ZN3edg9a_booleanE *)0), __32359_49_dctl));



(__32359_49_dctl->suppress_id_output)--;
__32371_18_final_specialization = (__32376_17_temp_par_info.final_specialization);
_ZN29_INTERNAL_8_decode_c_e6cffa8826clear_template_param_blockEP22a_template_param_block((&__32376_17_temp_par_info));
(__32376_17_temp_par_info.final_specialization) = __32371_18_final_specialization;
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32370_18_p, __32359_49_dctl))) == 0) {




__32370_36_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(__32356_50_ptr, __32357_49_nchars, 1, ((unsigned long *)0), ((_ZN3edg12a_const_charE *)0), ((a_template_param_block_ptr)0), ((_ZN3edg9a_booleanE *)0), 
# 3731
__32359_49_dctl));
# 3737
} else  {


if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32370_18_p, __32359_49_dctl))) != 95) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32370_18_p + 1), __32359_49_dctl))) != 95)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32359_49_dctl);
__32370_36_end_ptr = __32370_18_p;
goto __32585_1_end_of_routine;
}
__32370_36_end_ptr = (__32370_18_p + 2);
# 3760
__32370_18_p = __32370_36_end_ptr;
__32370_28_pname = ((_ZN3edg12a_const_charE *)0);
if (__32358_49_suppress_parent_and_local_info) { (__32359_49_dctl->suppress_id_output)++; }
__32372_17_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32370_36_end_ptr, __32359_49_dctl));
if (((int)__32372_17_ch) == 76) {
auto unsigned long __32448_21_nchars2; __32448_21_nchars2 = __32357_49_nchars;
# 3773
__32357_49_nchars = ((unsigned long)((__32370_18_p - 2) - __32356_50_ptr));

__32370_18_p++;
if (__32448_21_nchars2 != 0UL) { __32448_21_nchars2 -= ((unsigned long)(__32370_18_p - __32356_50_ptr)); }
__32370_46_function_local_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8834demangle_function_local_indicationEPKcmPmP22a_decode_control_block(__32370_18_p, __32448_21_nchars2, (&__32379_17_instance), __32359_49_dctl));

__32378_17_has_function_local_info = 1;
__32370_18_p = (__32370_36_end_ptr = (__32356_50_ptr + __32357_49_nchars));
__32374_17_is_function = 0;

} else  { if (((int)__32372_17_ch) != 70) {


__32370_28_pname = __32370_36_end_ptr;




(__32359_49_dctl->suppress_id_output)++;
if ((__32376_17_temp_par_info.final_specialization) == ((_ZN3edg12a_const_charE *)0)) {
(__32376_17_temp_par_info.set_final_specialization) = 1;
}
__32370_36_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__32370_28_pname, 0, (&__32376_17_temp_par_info), 0, __32359_49_dctl));



(__32376_17_temp_par_info.set_final_specialization) = 0;
(__32359_49_dctl->suppress_id_output)--;


__32372_17_ch = (_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32370_36_end_ptr, __32359_49_dctl));
if ((((int)__32372_17_ch) == 0) || ((((int)__32372_17_ch) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32370_36_end_ptr + 1), __32359_49_dctl))) == 95)))
{
__32374_17_is_function = 0;
}
} }
if (__32358_49_suppress_parent_and_local_info) { (__32359_49_dctl->suppress_id_output)--; }
__32373_18_oname = ((_ZN3edg12a_const_charE *)0);
if (__32374_17_is_function) {

if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32370_36_end_ptr, __32359_49_dctl))) == 83) { __32370_36_end_ptr++; }


if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32370_36_end_ptr, __32359_49_dctl))) == 79) {


__32373_18_oname = (++__32370_36_end_ptr);
(__32359_49_dctl->suppress_id_output)++;
__32370_36_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__32373_18_oname, 0, ((a_template_param_block_ptr)0), 0, __32359_49_dctl));
(__32359_49_dctl->suppress_id_output)--;
}

__32371_41_end_ptr_first_scan = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_type_first_partEPKciiP22a_decode_control_block(__32370_36_end_ptr, 0, 1, __32359_49_dctl));



}
(__32376_17_temp_par_info.nesting_level) = 0UL;
if ((__32370_28_pname != ((_ZN3edg12a_const_charE *)0)) && (!(__32358_49_suppress_parent_and_local_info)))
{

if ((__32376_17_temp_par_info.final_specialization) != ((_ZN3edg12a_const_charE *)0)) {


(__32376_17_temp_par_info.actual_template_args_until_final_specialization) = 1;
}
_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__32370_28_pname, 0, (&__32376_17_temp_par_info), 0, __32359_49_dctl);
# 3845
(__32376_17_temp_par_info.actual_template_args_until_final_specialization) = 0;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"::"), __32359_49_dctl);
}

_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(__32356_50_ptr, __32357_49_nchars, 1, ((unsigned long *)0), __32370_28_pname, (&__32376_17_temp_par_info), ((_ZN3edg9a_booleanE *)0), __32359_49_dctl);



if (__32373_18_oname != ((_ZN3edg12a_const_charE *)0)) {


_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" [overriding function in "), __32359_49_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__32373_18_oname, 0, ((a_template_param_block_ptr)0), 0, __32359_49_dctl);
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"] "), __32359_49_dctl);
}
if (__32374_17_is_function) {

_ZN29_INTERNAL_8_decode_c_e6cffa8825demangle_type_second_partEPKciP22a_decode_control_block(__32370_36_end_ptr, 0, __32359_49_dctl);

__32370_36_end_ptr = __32371_41_end_ptr_first_scan;
}
if ((!(__32376_17_temp_par_info.use_old_form_for_template_output)) && ((__32376_17_temp_par_info.nesting_level) != 0UL))
{

(__32376_17_temp_par_info.nesting_level) = 0UL;
(__32376_17_temp_par_info.first_correspondence) = 1;
(__32376_17_temp_par_info.output_only_correspondences) = 1;


(__32359_49_dctl->suppress_id_output)++;
if (__32370_28_pname != ((_ZN3edg12a_const_charE *)0)) {

if ((__32376_17_temp_par_info.final_specialization) != ((_ZN3edg12a_const_charE *)0)) {


(__32376_17_temp_par_info.actual_template_args_until_final_specialization) = 1;
}
_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block(__32370_28_pname, 0, (&__32376_17_temp_par_info), 0, __32359_49_dctl);



}


(__32376_17_temp_par_info.actual_template_args_until_final_specialization) = 0;

_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_nameEPKcmiPmS1_P22a_template_param_blockPiP22a_decode_control_block(__32356_50_ptr, __32357_49_nchars, 1, ((unsigned long *)0), __32370_28_pname, (&__32376_17_temp_par_info), ((_ZN3edg9a_booleanE *)0), __32359_49_dctl);



(__32359_49_dctl->suppress_id_output)--;
if (!(__32376_17_temp_par_info.first_correspondence)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block(((char)93), __32359_49_dctl);
}
}
}
__32585_1_end_of_routine:;


if (__32378_17_has_function_local_info) { _ZN29_INTERNAL_8_decode_c_e6cffa8813emit_instanceEmP22a_decode_control_block(__32379_17_instance, __32359_49_dctl); }



if (__32370_46_function_local_end_ptr != ((_ZN3edg12a_const_charE *)0)) { __32370_36_end_ptr = __32370_46_function_local_end_ptr; }
if (__32377_17_is_externalized_static) {

while (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32370_36_end_ptr, __32359_49_dctl))) != 0) { __32370_36_end_ptr++; }
}
if (__32371_62_prev_end != ((_ZN3edg12a_const_charE *)0)) { (__32359_49_dctl->end_of_name) = __32371_62_prev_end; }
return __32370_36_end_ptr;
}


static _ZN3edg9a_booleanE _ZN29_INTERNAL_8_decode_c_e6cffa8820is_mangled_type_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__32602_67_ptr, 
a_decode_control_block_ptr __32603_66_dctl)
# 3928
{
auto _ZN3edg9a_booleanE __32612_16_is_type_name = 0;
auto _ZN3edg12a_const_charE *__32613_17_p; __32613_17_p = __32602_67_ptr;

if (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32613_17_p, __32603_66_dctl)))))) {

do { __32613_17_p++; } while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32613_17_p, __32603_66_dctl))))));

if (isalpha(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32613_17_p, __32603_66_dctl)))))) {



for (__32613_17_p++; ((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32613_17_p, __32603_66_dctl))) != 0; __32613_17_p++) {
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32613_17_p, __32603_66_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32613_17_p + 1), __32603_66_dctl))) == 95)) {
__32612_16_is_type_name = 1;
goto __T237416200;
}
} __T237416200:;
} else  { if ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32613_17_p, __32603_66_dctl))) == 95) && (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32613_17_p + 1), __32603_66_dctl))) == 95)) && (((int)(
# 3946
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32613_17_p + 2), __32603_66_dctl))) == 85)) && ((((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32613_17_p + 3), __32603_66_dctl))) == 116) || (((int)(
# 3946
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32613_17_p + 3), __32603_66_dctl))) == 108)) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32613_17_p + 3), __32603_66_dctl))) == 109)) || (((int)(
# 3946
_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32613_17_p + 3), __32603_66_dctl))) == 100)))
# 3952
{

__32612_16_is_type_name = 1;
} }
}
return __32612_16_is_type_name;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8829demangle_static_variable_nameEPKcP22a_decode_control_block(
_ZN3edg12a_const_charE *__32645_76_ptr, 
a_decode_control_block_ptr __32646_75_dctl)
# 3969
{
auto _ZN3edg12a_const_charE *__32653_17_start_ptr;

__32645_76_ptr += 7;

__32653_17_start_ptr = __32645_76_ptr;
while (((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32645_76_ptr, __32646_75_dctl))) != 95) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32645_76_ptr + 1), __32646_75_dctl))) != 95)) || (__32645_76_ptr == 
# 3975
__32653_17_start_ptr))

{
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32645_76_ptr, __32646_75_dctl))) == 0) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32646_75_dctl);
goto __T237437200;
}
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*__32645_76_ptr), __32646_75_dctl);
__32645_76_ptr++;
} __T237437200:;

while (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32645_76_ptr, __32646_75_dctl))) != 0) { __32645_76_ptr++; }
return __32645_76_ptr;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_local_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__32674_70_ptr, 
a_decode_control_block_ptr __32675_69_dctl)
# 4003
{
auto _ZN3edg12a_const_charE *__32687_17_p; __32687_17_p = (__32674_70_ptr + 2);



do { __32687_17_p++; } while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32687_17_p, __32675_69_dctl))))));
if (isalpha(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32687_17_p, __32675_69_dctl)))))) {

} else  {
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32687_17_p, __32675_69_dctl))) != 95) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32675_69_dctl);
goto __32716_1_end_of_routine;
}
__32687_17_p++;
if (!(isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32687_17_p, __32675_69_dctl))))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32675_69_dctl);
goto __32716_1_end_of_routine;
}
do { __32687_17_p++; } while (isdigit(((int)((unsigned char)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32687_17_p, __32675_69_dctl))))));
if (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32687_17_p, __32675_69_dctl))) != 95) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32675_69_dctl);
goto __32716_1_end_of_routine;
}
__32687_17_p++;
}

while (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32687_17_p, __32675_69_dctl))) != 0) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*__32687_17_p), __32675_69_dctl);
__32687_17_p++;
}
__32716_1_end_of_routine:;
return __32687_17_p;
}


static _ZN3edg12a_const_charE *_ZN29_INTERNAL_8_decode_c_e6cffa8823uncompress_mangled_nameEPKcP22a_decode_control_block( _ZN3edg12a_const_charE *__32721_74_id, 
a_decode_control_block_ptr __32722_73_dctl)




{
auto _ZN3edg12a_const_charE *__32728_18_uncompressed_name; auto _ZN3edg12a_const_charE *__32728_43_src_end;
auto unsigned long __32729_17_length;
# 4045
__32728_18_uncompressed_name = __32721_74_id; __32728_43_src_end = (__32722_73_dctl->end_of_name);



__32721_74_id += 5;

if (!(isdigit(((int)((unsigned char)(*__32721_74_id)))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}
__32721_74_id = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__32721_74_id, (&__32729_17_length), __32722_73_dctl));

if ((((int)(__32721_74_id[0])) != 95) || (((int)(__32721_74_id[1])) != 95)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}


(__32722_73_dctl->uncompressed_length) = __32729_17_length;
__32721_74_id += 2;
if ((__32729_17_length + 1UL) >= (__32722_73_dctl->output_id_size)) {


(__32722_73_dctl->output_overflow_err) = 1;
goto __32826_1_end_of_routine;
} else  {
auto _ZN3edg12a_const_charE *__32754_19_src; auto _ZN3edg12a_const_charE *__32754_25_dst_end;
auto char *__32755_19_dst;
# 4071
__32754_25_dst_end = ((_ZN3edg12a_const_charE *)((__32722_73_dctl->output_id) + (__32722_73_dctl->output_id_size)));



__32728_18_uncompressed_name = (__32754_25_dst_end - (__32729_17_length + 1UL));
(__32722_73_dctl->output_id_size) -= (__32729_17_length + 1UL);
__32755_19_dst = ((char *)__32728_18_uncompressed_name);
for (__32754_19_src = __32721_74_id; ((int)(*__32754_19_src)) != 0; ) {
auto char __32762_12_ch; __32762_12_ch = (*(__32754_19_src++));
if (((int)__32762_12_ch) != 74) {

if (((const char *)__32755_19_dst) >= __32754_25_dst_end) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}
(*(__32755_19_dst++)) = __32762_12_ch;
} else  {
if (((int)(*__32754_19_src)) == 74) {


if (((const char *)__32755_19_dst) >= __32754_25_dst_end) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}
(*(__32755_19_dst++)) = ((char)74);
} else  {


auto unsigned long __32784_25_pos; auto unsigned long __32784_30_prev_len;
auto _ZN3edg12a_const_charE *__32785_26_prev_str; auto _ZN3edg12a_const_charE *__32785_37_prev_str2; auto _ZN3edg12a_const_charE *__32785_49_prev_end;
(__32722_73_dctl->end_of_name) = __32728_43_src_end;
__32754_19_src = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_numberEPKcPmP22a_decode_control_block(__32754_19_src, (&__32784_25_pos), __32722_73_dctl));
if ((((int)(*__32754_19_src)) != 74) || (__32784_25_pos > __32729_17_length)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}
__32785_26_prev_str = (__32728_18_uncompressed_name + __32784_25_pos);
if (!(isdigit(((int)(*__32785_26_prev_str))))) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}

(__32722_73_dctl->end_of_name) = (__32728_18_uncompressed_name + __32729_17_length);
__32785_37_prev_str2 = (_ZN29_INTERNAL_8_decode_c_e6cffa8810get_lengthEPKcPmPS1_P22a_decode_control_block(__32785_26_prev_str, (&__32784_30_prev_len), (&__32785_49_prev_end), __32722_73_dctl));

__32785_37_prev_str2 += __32784_30_prev_len;
if (((const char *)(__32755_19_dst + __32784_30_prev_len)) >= __32754_25_dst_end) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}
while (__32785_26_prev_str < __32785_37_prev_str2) { (*(__32755_19_dst++)) = (*(__32785_26_prev_str++)); }
}

__32754_19_src++;
}
}
if (((unsigned long)(__32755_19_dst - __32728_18_uncompressed_name)) != __32729_17_length) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
}
if (((const char *)__32755_19_dst) >= __32754_25_dst_end) {

_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32722_73_dctl);
goto __32826_1_end_of_routine;
}

(*(__32755_19_dst++)) = ((char)0);
(__32722_73_dctl->end_of_name) = (__32728_18_uncompressed_name + __32729_17_length);
}
__32826_1_end_of_routine:; ;
return __32728_18_uncompressed_name;
}


void _Z17decode_identifierPKcPcmPiS2_Pm( _ZN3edg12a_const_charE *__32831_38_id, 
char *__32832_38_output_buffer, 
_ZN3edg8sizeof_tE __32833_37_output_buffer_size, 
_ZN3edg9a_booleanE *__32834_38_err, 
_ZN3edg9a_booleanE *__32835_38_buffer_overflow_err, 
_ZN3edg8sizeof_tE *__32836_38_required_buffer_size)
# 4168
{
auto _ZN3edg12a_const_charE *__32852_31_end_ptr = ((_ZN3edg12a_const_charE *)0); auto _ZN3edg12a_const_charE *__32852_48_p;
auto a_decode_control_block __32853_30_control_block;
auto a_decode_control_block_ptr __32854_30_dctl; __32854_30_dctl = (&__32853_30_control_block);

_ZN29_INTERNAL_8_decode_c_e6cffa8819clear_control_blockEP22a_decode_control_block(__32854_30_dctl);
(__32854_30_dctl->end_of_name) = (_Z6strchrPKci(__32831_38_id, 0));
(__32854_30_dctl->output_id) = __32832_38_output_buffer;
(__32854_30_dctl->output_id_size) = __32833_37_output_buffer_size;
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__CPR"), __32831_38_id, __32854_30_dctl)) {

__32831_38_id = (_ZN29_INTERNAL_8_decode_c_e6cffa8823uncompress_mangled_nameEPKcP22a_decode_control_block(__32831_38_id, __32854_30_dctl));
}

if (__32854_30_dctl->output_overflow_err) {

} else  { if (__32854_30_dctl->err_in_id) {

} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__vtbl__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"virtual function table for "), __32854_30_dctl);
# 4194
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_vtbl_class_nameEPKcP22a_decode_control_block((__32831_38_id + 8), __32854_30_dctl));
while (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__"), __32852_31_end_ptr, __32854_30_dctl)) {

__32852_31_end_ptr += 2;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" in "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824demangle_vtbl_class_nameEPKcP22a_decode_control_block(__32852_31_end_ptr, __32854_30_dctl));
}
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__CBI__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"can-be-instantiated flag for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 7), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__DNI__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"do-not-instantiate flag for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 7), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__TIR__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"template-instantiation-request flag for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 7), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__LSG__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"initialization guard variable for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 7), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__THI__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"thread_local initialization routine for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 7), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__IFV__"), __32831_38_id, __32854_30_dctl)) {
__32831_38_id += 7;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"ifunc variable for "), __32854_30_dctl);
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__IFC__"), __32831_38_id, __32854_30_dctl)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"ifunc function for "), __32854_30_dctl);
__32831_38_id += 7;
}
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(__32831_38_id, 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__RES__"), __32831_38_id, __32854_30_dctl)) {
__32831_38_id += 7;
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"resolver function for "), __32854_30_dctl);
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__IFC__"), __32831_38_id, __32854_30_dctl)) {

_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"ifunc function for "), __32854_30_dctl);
__32831_38_id += 7;
}
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(__32831_38_id, 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__IFC__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"ifunc function for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 7), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__TGT__"), __32831_38_id, __32854_30_dctl)) {

auto _ZN3edg12a_const_charE *__32922_19_target_attr; auto _ZN3edg12a_const_charE *__32922_33_target_attr_end;
__32831_38_id += 7;
__32922_19_target_attr = __32831_38_id;
while (__32831_38_id < (__32854_30_dctl->end_of_name)) {
if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__"), __32831_38_id, __32854_30_dctl)) {
__32922_33_target_attr_end = __32831_38_id;
__32831_38_id += 2;
goto __T237570344;
}
__32831_38_id++;
} __T237570344:;
if (__32831_38_id < (__32854_30_dctl->end_of_name)) {
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(__32831_38_id, 0UL, 0, __32854_30_dctl));



_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" __attribute__((target("), __32854_30_dctl);
while (__32922_19_target_attr < __32922_33_target_attr_end) {
_ZN29_INTERNAL_8_decode_c_e6cffa8811write_id_chEcP22a_decode_control_block((*(__32922_19_target_attr++)), __32854_30_dctl);
}
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)")))"), __32854_30_dctl);
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32854_30_dctl);
__32852_31_end_ptr = __32831_38_id;
}
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__TWR__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"thread_local wrapper for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 7), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__TID_"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"type identifier for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__32831_38_id + 6), __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__T_"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"typeinfo for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__32831_38_id + 4), __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__VFE__"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"surrogate in class "), __32854_30_dctl);
__32852_48_p = (_ZN29_INTERNAL_8_decode_c_e6cffa8813demangle_typeEPKcP22a_decode_control_block((__32831_38_id + 7), __32854_30_dctl));
if ((((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block(__32852_48_p, __32854_30_dctl))) != 95) || (((int)(_ZN29_INTERNAL_8_decode_c_e6cffa888get_charEPKcP22a_decode_control_block((__32852_48_p + 1), __32854_30_dctl))) != 95)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32854_30_dctl);
__32852_31_end_ptr = __32852_48_p;
} else  {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)" for "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32852_48_p + 2), 0UL, 0, __32854_30_dctl));
}
} else  { if ((_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__Q"), __32831_38_id, __32854_30_dctl)) || ((_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__"), __32831_38_id, __32854_30_dctl)) && 
# 4283
(_ZN29_INTERNAL_8_decode_c_e6cffa8820is_mangled_type_nameEPKcP22a_decode_control_block((__32831_38_id + 2), __32854_30_dctl))))

{

__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8823full_demangle_type_nameEPKciP22a_template_param_blockiP22a_decode_control_block((__32831_38_id + 2), 0, ((a_template_param_block_ptr)0), 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__STV__"), __32831_38_id, __32854_30_dctl)) {


__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8829demangle_static_variable_nameEPKcP22a_decode_control_block(__32831_38_id, __32854_30_dctl));
} else  { if ((_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__"), __32831_38_id, __32854_30_dctl)) && (isdigit(((int)((unsigned char)(__32831_38_id[2])))))) {


__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8819demangle_local_nameEPKcP22a_decode_control_block(__32831_38_id, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__b_"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"base of type "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 4), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__v_"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"virtual base of type "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 4), 0UL, 0, __32854_30_dctl));
} else  { if (_ZN29_INTERNAL_8_decode_c_e6cffa8814start_of_id_isEPKcS1_P22a_decode_control_block(((const char *)"__p_"), __32831_38_id, __32854_30_dctl)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8812write_id_strEPKcP22a_decode_control_block(((const char *)"pointer to virtual base of type "), __32854_30_dctl);
__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block((__32831_38_id + 4), 0UL, 0, __32854_30_dctl));
} else  {


__32852_31_end_ptr = (_ZN29_INTERNAL_8_decode_c_e6cffa8824full_demangle_identifierEPKcmiP22a_decode_control_block(__32831_38_id, 0UL, 0, __32854_30_dctl));
} } } } } } } } } } } } } } } } } } } } } }
if (__32854_30_dctl->output_overflow_err) {
(__32854_30_dctl->err_in_id) = 1;
} else  {

((__32854_30_dctl->output_id)[(__32854_30_dctl->output_id_len)]) = ((char)0);
}

if (((!(__32854_30_dctl->err_in_id)) && (__32852_31_end_ptr != ((_ZN3edg12a_const_charE *)0))) && (((int)(*__32852_31_end_ptr)) != 0)) {
_ZN29_INTERNAL_8_decode_c_e6cffa8816bad_mangled_nameEP22a_decode_control_block(__32854_30_dctl);
}
(*__32834_38_err) = (__32854_30_dctl->err_in_id);
(*__32835_38_buffer_overflow_err) = (__32854_30_dctl->output_overflow_err);
(*__32836_38_required_buffer_size) = ((__32854_30_dctl->output_id_len) + 1UL);


if ((__32854_30_dctl->uncompressed_length) != 0UL) {
(*__32836_38_required_buffer_size) += ((__32854_30_dctl->uncompressed_length) + 1UL);
} 
}
