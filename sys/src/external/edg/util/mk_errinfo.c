/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:53 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "util/mk_errinfo.c"
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
# 277 "util/mk_errinfo.c"
struct an_error_info;
# 288
struct a_tag_info;
# 523
enum a_font_kind {
fk_none,
fk_normal,
fk_tt,
fk_em};
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 948 "/usr/include/stdlib.h" 3
typedef int (*__compar_fn_t)(const void *, const void *);
# 67 "util/mk_errinfo.c"
typedef char a_me_input_line[32767];
# 276
typedef struct an_error_info *an_error_info_ptr;
# 515 "src/basics.h"
typedef const char _ZN3edg12a_const_charE;
# 277 "util/mk_errinfo.c"
struct an_error_info {
_ZN3edg12a_const_charE *text;
_ZN3edg12a_const_charE *enumerator;
_ZN3edg12a_const_charE *tag;};
typedef struct an_error_info an_error_info;
# 287
typedef struct a_tag_info *a_tag_info_ptr;
struct a_tag_info {
char *enumerator;
char *tag;};
typedef struct a_tag_info a_tag_info;
# 536
typedef void a_doc_string_output_routine(_ZN3edg12a_const_charE *, int, enum a_font_kind);
# 994
typedef void a_write_item_header_routine(int dummy, _ZN3edg12a_const_charE *);
# 219 "src/basics.h"
typedef int _ZN3edg9a_booleanE;
# 499
typedef void *_ZN3edg10a_void_ptrE;
typedef const void *_ZN3edg16a_const_void_ptrE;
# 541
typedef size_t _ZN3edg8sizeof_tE;
# 4166 "src/host_envir.h"
typedef _ZN3edg16a_const_void_ptrE _ZN3edg18a_bsearch_arg_typeE;
# 4174
typedef _ZN3edg8sizeof_tE _ZN3edg16qsort_nmemb_typeE;
# 184 "/usr/include/stdio.h" 3
extern int fclose(FILE *__stream);
# 264
extern __attribute__((__malloc__)) FILE *fopen(const char *__filename, const char *__modes);
# 357
extern int fprintf(FILE *__stream, const char *__format, ...);
# 365
extern __attribute__((__nothrow__)) int sprintf(char *__s, const char *__format, ...);
# 385
extern __attribute__((__nothrow__)) int snprintf(char *__s, size_t __maxlen, const char *__format, ...);
# 576
extern int getc(FILE *__stream);
# 612
extern int putc(int __c, FILE *__stream);
# 717
extern int fputs(const char *__s, FILE *__stream);
# 672 "/usr/include/stdlib.h" 3
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 756
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void exit(int __status);
# 960
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
# 970
extern void qsort(void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
# 43 "/usr/include/string.h" 3
extern __attribute__((__nothrow__)) void *memcpy(void *__dest, const void *__src, size_t __n);
# 61
extern __attribute__((__nothrow__)) void *memset(void *__s, int __c, size_t __n);
# 141
extern __attribute__((__nothrow__)) char *strcpy(char *__dest, const char *__src);
# 156
extern __attribute__((__pure__)) __attribute__((__nothrow__)) int strcmp(const char *__s1, const char *__s2);
# 226
extern __attribute__((__pure__)) __attribute__((__nothrow__)) char *_Z6strchrPci(char *__s, int __c) __asm__("strchr");

extern __attribute__((__pure__)) __attribute__((__nothrow__)) const char *_Z6strchrPKci(const char *__s, int __c) __asm__("strchr");
# 407
extern __attribute__((__pure__)) __attribute__((__nothrow__)) size_t strlen(const char *__s);
# 108 "/usr/include/ctype.h" 3
extern __attribute__((__nothrow__)) int isalnum(int);
# 85 "util/mk_errinfo.c"
static __attribute__((__noreturn__)) void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(_ZN3edg12a_const_charE *error_string);
# 96
static void _ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(_ZN3edg12a_const_charE *error_text, _ZN3edg12a_const_charE *insertion_string);
# 113
static _ZN3edg10a_void_ptrE _ZN30_INTERNAL_12_mk_errinfo_c_main20me_malloc_with_checkEm(_ZN3edg8sizeof_tE size);
# 128
static _ZN3edg9a_booleanE _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE(FILE *input_file);
# 158
static char *_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(char *source);
# 171
static void _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(void);
# 177
static void _ZN30_INTERNAL_12_mk_errinfo_c_main21me_command_line_errorEv(void);
# 205
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_file_headerEP8_IO_FILE(FILE *file);
# 230
static void _ZN30_INTERNAL_12_mk_errinfo_c_main23me_write_open_namespaceEP8_IO_FILE(FILE *file);
# 242
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_close_namespaceEP8_IO_FILE(FILE *file);
# 251
static void _ZN30_INTERNAL_12_mk_errinfo_c_main27me_write_include_guard_testEP8_IO_FILEPKc(FILE *file, _ZN3edg12a_const_charE *guard_name);
# 262
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_include_guard_endEP8_IO_FILEPKc(FILE *file, _ZN3edg12a_const_charE *guard_name);
# 298
static int _ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_(_ZN3edg16a_const_void_ptrE arg1, _ZN3edg16a_const_void_ptrE arg2);
# 314
static int _ZN30_INTERNAL_12_mk_errinfo_c_main16compare_tag_infoEPKvS1_(_ZN3edg16a_const_void_ptrE arg1, _ZN3edg16a_const_void_ptrE arg2);
# 358
static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_fileEv(void);
# 458
static void _ZN30_INTERNAL_12_mk_errinfo_c_main16me_read_tag_fileEv(void);
# 506
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_error_codesEv(void);
# 545
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kind(_ZN3edg12a_const_charE *string, int length, enum a_font_kind font);
# 607
static void _ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib(_ZN3edg12a_const_charE *str, int len, _Bool font_setting);
# 683
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(_ZN3edg12a_const_charE *string, int length, enum a_font_kind font);
# 726
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_rst_item_headerEiPKc(int number, _ZN3edg12a_const_charE *tag);
# 749
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_mml_doc_stringEPKci11a_font_kind(_ZN3edg12a_const_charE *string, int length, enum a_font_kind font);
# 785
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_create_doc_fillinEPPKc(_ZN3edg12a_const_charE **ptr_to_ptr);
# 929
static void _ZN30_INTERNAL_12_mk_errinfo_c_main19me_write_error_textEv(void);
# 967
static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_write_tag_tableEv(void);
# 1003
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_latex_item_headerEiPKc(int number, _ZN3edg12a_const_charE *tag);
# 1030
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKc(int number, _ZN3edg12a_const_charE *tag);
# 1063
static void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_write_doc_fileEv(void);
# 1103
extern int main(int argc, char **argv);
# 151 "/usr/include/stdio.h" 3
extern FILE *stderr;
# 68 "util/mk_errinfo.c"
static a_me_input_line me_input_line;
# 81
static _ZN3edg12a_const_charE *message_prefix;
# 190
static _ZN3edg12a_const_charE *header_comments[10];
# 217
static _ZN3edg12a_const_charE *open_namespace[8];
# 338
static an_error_info error_info[10001];

static a_tag_info tag_info[10000];



static char *message_input_file_name;
static FILE *message_input_file;
static char *tag_input_file_name;
static FILE *tag_input_file;
static char *codes_output_file_name;
static FILE *codes_output_file;
static char *data_output_file_name;
static FILE *data_output_file;
static char *doc_output_file_name;
static FILE *doc_output_file;
static int number_of_errors;
static int number_of_tags;
# 531
static enum a_font_kind curr_font;
# 539
static a_doc_string_output_routine *output_doc_string;
# 926
static const char *char_type;
# 998
static a_write_item_header_routine *write_item_header;
# 555
static _ZN3edg9a_booleanE _ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars;
# 620
static char _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer[80];
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos;
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank;
# 1038
static _ZN3edg9a_booleanE _ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first;
# 81
static _ZN3edg12a_const_charE *message_prefix = ((_ZN3edg12a_const_charE *)"mk_errinfo");
# 190
static _ZN3edg12a_const_charE *header_comments[10] = {((const char *)"/*"),((const char *)""),((const char *)"DO NOT UPDATE THIS FILE!"),((const char *)""),((const char *)"This file is generated by the mk_errinfo program from the information"),((const char *)"specified in the error_msg.txt and error_tag.txt files."
# 190
),((const char *)""),((const char *)"*/"),((const char *)""),((_ZN3edg12a_const_charE *)0)};
# 217
static _ZN3edg12a_const_charE *open_namespace[8] = {((const char *)"#ifndef BEGIN_EDG_NAMESPACE"),((const char *)"#define BEGIN_EDG_NAMESPACE /* nothing */"),((const char *)"#endif  /* BEGIN_EDG_NAMESPACE */"),((const char *)"#ifndef END_EDG_NAMESPACE"),((const char *)"#define END_EDG_NAMESPACE /* nothing */"
# 217
),((const char *)"#endif  /* END_EDG_NAMESPACE */"),((const char *)"BEGIN_EDG_NAMESPACE"),((_ZN3edg12a_const_charE *)0)};
# 354
static int number_of_errors = 0;
static int number_of_tags = 0;
# 926
static const char *char_type = ((const char *)"a_const_char");
# 621
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = 0;
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = 0;
# 1038
static _ZN3edg9a_booleanE _ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first = 1;
# 85
static __attribute__((__noreturn__)) void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc( _ZN3edg12a_const_charE *__28743_54_error_string)




{
fprintf(stderr, ((const char *)"%s: %s\n"), message_prefix, __28743_54_error_string);
exit(4); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_( _ZN3edg12a_const_charE *__28754_36_error_text, 
_ZN3edg12a_const_charE *__28755_36_insertion_string)
# 105
{
fprintf(stderr, ((const char *)"%s: "), message_prefix);
fprintf(stderr, __28754_36_error_text, __28755_36_insertion_string);
fprintf(stderr, ((const char *)"\n"));
exit(2); 
}


static _ZN3edg10a_void_ptrE _ZN30_INTERNAL_12_mk_errinfo_c_main20me_malloc_with_checkEm( _ZN3edg8sizeof_tE __28771_49_size)




{
auto _ZN3edg10a_void_ptrE __28777_14_ptr;

if ((__28777_14_ptr = ((_ZN3edg10a_void_ptrE)(malloc(__28771_49_size)))) == ((_ZN3edg10a_void_ptrE)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"out of memory"), ((_ZN3edg12a_const_charE *)0));
}
return __28777_14_ptr;
}


static _ZN3edg9a_booleanE _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE( FILE *__28786_43_input_file)
# 134
{
auto char *__28793_13_buffer_pos = me_input_line;
auto int __28794_13_size = 0;
auto int __28795_13_ch;
auto _ZN3edg9a_booleanE __28796_13_result;

while ((__28795_13_ch = (getc(__28786_43_input_file))) , ((__28795_13_ch != (-1)) && (__28795_13_ch != 10))) {
if ((++__28794_13_size) > 32766) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"me_read_input_line: input line too long."));
}
(*(__28793_13_buffer_pos++)) = ((char)__28795_13_ch);
}


(*(__28793_13_buffer_pos++)) = ((char)0);


__28796_13_result = 1;
if ((__28795_13_ch == (-1)) && (__28794_13_size == 0)) { __28796_13_result = 0; }

return __28796_13_result;
}


static char *_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc( char *__28816_35_source)




{
auto char *__28822_9_dest;
__28822_9_dest = ((char *)(_ZN30_INTERNAL_12_mk_errinfo_c_main20me_malloc_with_checkEm(((_ZN3edg8sizeof_tE)((strlen(((const char *)__28816_35_source))) + 1UL)))));
strcpy(__28822_9_dest, ((const char *)__28816_35_source));
return __28822_9_dest;
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(void)
{
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"invalid input line: %s"), ((_ZN3edg12a_const_charE *)me_input_line)); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main21me_command_line_errorEv(void)
{
fprintf(stderr, ((const char *)"usage:\n"));
fprintf(stderr, ((const char *)"  %s \\\n\t\t%s\n"), ((const char *)("mk_errinfo [-cch] message_input_file_name tag_input_file_name")), ((const char *)("codes_output_file data_output_file")));


fprintf(stderr, ((const char *)"  %s \\\n\t\t%s\n"), ((const char *)("mk_errinfo {-d|-mml|-rst} message_input_file_name tag_input_file_name")), ((const char *)("documentation_output_file")));



_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"command line error"), ((_ZN3edg12a_const_charE *)0)); 
}
# 205
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_file_headerEP8_IO_FILE( FILE *__28863_40_file)



{
auto int __28868_7_i;
for (__28868_7_i = 0; ((header_comments)[__28868_7_i]) != ((_ZN3edg12a_const_charE *)0); ++__28868_7_i) {
fprintf(__28863_40_file, ((const char *)"%s\n"), ((header_comments)[__28868_7_i]));
} 
}
# 230
static void _ZN30_INTERNAL_12_mk_errinfo_c_main23me_write_open_namespaceEP8_IO_FILE( FILE *__28888_43_file)



{
auto int __28893_7_i;
for (__28893_7_i = 0; ((open_namespace)[__28893_7_i]) != ((_ZN3edg12a_const_charE *)0); ++__28893_7_i) {
fprintf(__28888_43_file, ((const char *)"%s\n"), ((open_namespace)[__28893_7_i]));
} 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_close_namespaceEP8_IO_FILE( FILE *__28900_44_file)



{
fprintf(__28900_44_file, ((const char *)"END_EDG_NAMESPACE\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main27me_write_include_guard_testEP8_IO_FILEPKc( FILE *__28909_55_file, 
_ZN3edg12a_const_charE *__28910_55_guard_name)




{
fprintf(__28909_55_file, ((const char *)"#ifndef %s\n#define %s 1\n"), __28910_55_guard_name, __28910_55_guard_name); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_include_guard_endEP8_IO_FILEPKc( FILE *__28920_54_file, 
_ZN3edg12a_const_charE *__28921_54_guard_name)




{
fprintf(__28920_54_file, ((const char *)"#endif /* #ifndef %s */\n"), __28921_54_guard_name); 
}
# 298
static int _ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_( _ZN3edg16a_const_void_ptrE __28956_48_arg1, 
_ZN3edg16a_const_void_ptrE __28957_48_arg2)




{
auto an_error_info_ptr __28963_21_eip1;
auto an_error_info_ptr __28964_21_eip2;

__28963_21_eip1 = ((an_error_info_ptr)__28956_48_arg1);
__28964_21_eip2 = ((an_error_info_ptr)__28957_48_arg2);
return strcmp((__28963_21_eip1->enumerator), (__28964_21_eip2->enumerator));
}


static int _ZN30_INTERNAL_12_mk_errinfo_c_main16compare_tag_infoEPKvS1_( _ZN3edg16a_const_void_ptrE __28972_46_arg1, 
_ZN3edg16a_const_void_ptrE __28973_46_arg2)




{
auto a_tag_info_ptr __28979_18_eip1;
auto a_tag_info_ptr __28980_18_eip2;

__28979_18_eip1 = ((a_tag_info_ptr)__28972_46_arg1);
__28980_18_eip2 = ((a_tag_info_ptr)__28973_46_arg2);
return strcmp(((const char *)(__28979_18_eip1->tag)), ((const char *)(__28980_18_eip2->tag)));
}
# 358
static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_fileEv(void)



{
while (_ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE(message_input_file)) { {




auto char *__29026_11_ptr;
auto char *__29027_11_enumerator_start;
auto char *__29028_11_tag_start;
auto char *__29029_11_text_start;
auto char *__29030_11_copy_of_enumerator;
auto char *__29031_11_copy_of_tag;

__29026_11_ptr = me_input_line;
{ while (((int)(*__29026_11_ptr)) == 32) { __29026_11_ptr++; } } ;


if ((((int)(*__29026_11_ptr)) == 35) || (((int)(*__29026_11_ptr)) == 0)) { goto __T694255120; }
if (number_of_errors >= 10000) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"too many error messages -- increase MAX_ERRORS"));
}
__29027_11_enumerator_start = __29026_11_ptr;
__29026_11_ptr = (_Z6strchrPci(__29027_11_enumerator_start, 59));
if (__29026_11_ptr == ((char *)0)) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }
(*(__29026_11_ptr++)) = ((char)0);
{ while (((int)(*__29026_11_ptr)) == 32) { __29026_11_ptr++; } } ;
__29028_11_tag_start = __29026_11_ptr;

__29026_11_ptr = (_Z6strchrPci(__29026_11_ptr, 59));
if (__29026_11_ptr == ((char *)0)) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }
(*(__29026_11_ptr++)) = ((char)0);
{ while (((int)(*__29026_11_ptr)) == 32) { __29026_11_ptr++; } } ;
if ((strcmp(((const char *)__29027_11_enumerator_start), ((const char *)"REMOVED"))) == 0) {




snprintf(me_input_line, 32767UL, ((const char *)"ec_removed_%0d"), number_of_errors);

(((error_info)[number_of_errors]).enumerator) = ((_ZN3edg12a_const_charE *)(_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(me_input_line)));
(((error_info)[number_of_errors]).text) = ((_ZN3edg12a_const_charE *)0);
number_of_errors++;
goto __T694255120;
}

if (((int)(*__29026_11_ptr)) != 34) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }

__29029_11_text_start = (__29026_11_ptr++);

for (; ; ) {
auto char __29070_12_ch; __29070_12_ch = (*__29026_11_ptr);
if ((((int)__29070_12_ch) == 34) || (((int)__29070_12_ch) == 0)) { goto __T694279488; }

if (((int)__29070_12_ch) == 92) { __29026_11_ptr++; }
__29026_11_ptr++;
} __T694279488:;

if (((int)(*__29026_11_ptr)) != 34) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }

__29026_11_ptr++;
if (((int)(*__29026_11_ptr)) != 0) {
auto char *__29081_13_after_quote; __29081_13_after_quote = __29026_11_ptr;
{ while (((int)(*__29026_11_ptr)) == 32) { __29026_11_ptr++; } } ;
if (((int)(*__29026_11_ptr)) != 0) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }

(*__29081_13_after_quote) = ((char)0);
}
(((error_info)[number_of_errors]).text) = ((_ZN3edg12a_const_charE *)(_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__29029_11_text_start)));
__29030_11_copy_of_enumerator = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__29027_11_enumerator_start));
(((error_info)[number_of_errors]).enumerator) = ((_ZN3edg12a_const_charE *)__29030_11_copy_of_enumerator);


if (((int)(*__29028_11_tag_start)) == 0) { __29028_11_tag_start = (me_input_line + 3); }
if ((strcmp(((const char *)__29028_11_tag_start), ((const char *)"INTERNAL"))) == 0) {

(((error_info)[number_of_errors]).tag) = ((_ZN3edg12a_const_charE *)0);
} else  {
if (number_of_tags >= 10000) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"too many tags -- increase MAX_TAGS"));
}
__29031_11_copy_of_tag = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__29028_11_tag_start));
(((error_info)[number_of_errors]).tag) = ((_ZN3edg12a_const_charE *)__29031_11_copy_of_tag);
(((tag_info)[number_of_tags]).enumerator) = __29030_11_copy_of_enumerator;
(((tag_info)[number_of_tags]).tag) = __29031_11_copy_of_tag;
number_of_tags++;
}
number_of_errors++;
} __T694255120:; }
fclose(message_input_file);

(((error_info)[number_of_errors]).enumerator) = ((const char *)"ec_last");
(((error_info)[number_of_errors]).text) = ((_ZN3edg12a_const_charE *)0);
number_of_errors++; 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main16me_read_tag_fileEv(void)
# 469
{
while (_ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE(tag_input_file)) { {
auto char *__29129_12_ptr;
auto char *__29130_12_tag_start;
auto char *__29131_12_enumerator_start;
auto an_error_info __29132_19_error_info_to_find;
__29129_12_ptr = me_input_line;
{ while (((int)(*__29129_12_ptr)) == 32) { __29129_12_ptr++; } } ;


if ((((int)(*__29129_12_ptr)) == 35) || (((int)(*__29129_12_ptr)) == 0)) { goto __T694324224; }
__29131_12_enumerator_start = __29129_12_ptr;

__29129_12_ptr = (_Z6strchrPci(__29131_12_enumerator_start, 59));
if (__29129_12_ptr == ((char *)0)) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }
(*(__29129_12_ptr++)) = ((char)0);
{ while (((int)(*__29129_12_ptr)) == 32) { __29129_12_ptr++; } } ;
__29130_12_tag_start = __29129_12_ptr;

(__29132_19_error_info_to_find.enumerator) = ((_ZN3edg12a_const_charE *)__29131_12_enumerator_start);
if (!(bsearch(((_ZN3edg18a_bsearch_arg_typeE)(&__29132_19_error_info_to_find)), ((const void *)(&error_info)), ((_ZN3edg8sizeof_tE)number_of_errors), 24UL, (&_ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_))))


{
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"%s is not a valid error code"), ((_ZN3edg12a_const_charE *)__29131_12_enumerator_start));
}
(((tag_info)[number_of_tags]).enumerator) = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__29131_12_enumerator_start));
(((tag_info)[number_of_tags]).tag) = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__29130_12_tag_start));
number_of_tags++;
if (number_of_tags >= 10000) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"too many tags -- increase MAX_TAGS"));
}
} __T694324224:; }
fclose(tag_input_file); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_error_codesEv(void)



{
auto int __29169_7_i;

fprintf(codes_output_file, ((const char *)"enum an_error_code {\n"));
for (__29169_7_i = 0; __29169_7_i < number_of_errors; ++__29169_7_i) {

if (__29169_7_i != 0) { fprintf(codes_output_file, ((const char *)",\n")); }
fprintf(codes_output_file, ((const char *)"  %s /* = %0d */"), (((error_info)[__29169_7_i]).enumerator), __29169_7_i);

}
fprintf(codes_output_file, ((const char *)"\n};\n\n")); 
}
# 545
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kind( _ZN3edg12a_const_charE *__29203_47_string, 
int __29204_42_length, 
enum a_font_kind __29205_25_font)
# 554
{

auto int __29214_7_i;

if (((int)curr_font) != ((int)__29205_25_font)) {
auto _ZN3edg12a_const_charE *__29217_19_start_string;

if (((int)curr_font) == 1) {

} else  { if (((int)curr_font) == 3) {

fprintf(doc_output_file, ((const char *)"%s"), ((const char *)("\\/}")));
} else  {

fprintf(doc_output_file, ((const char *)"%s"), ((const char *)("}")));
} }

_ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars = 0;
switch ((int)__29205_25_font) {
case 1: __29217_19_start_string = ((const char *)""); goto __T694355920;
case 2: __29217_19_start_string = ((const char *)"{\\tt "); goto __T694355920;
case 3: __29217_19_start_string = ((const char *)"{\\em "); goto __T694355920;
case 0: __29217_19_start_string = ((const char *)""); goto __T694355920;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T694355920:;
fprintf(doc_output_file, ((const char *)"%s"), __29217_19_start_string);
curr_font = __29205_25_font;
}
if (__29204_42_length == 0) { __29204_42_length = ((int)(strlen(__29203_47_string))); }
for (__29214_7_i = 0; __29214_7_i < __29204_42_length; ++__29214_7_i) {
auto char __29242_10_ch; __29242_10_ch = (__29203_47_string[__29214_7_i]);

if ((_Z6strchrPKci(((const char *)"_#&${}%"), ((int)__29242_10_ch))) != ((const char *)0)) { putc(92, doc_output_file); }
if ((((int)curr_font) != 2) && ((_Z6strchrPKci(((const char *)"\"<>"), ((int)__29242_10_ch))) != ((const char *)0))) {


if ((((int)curr_font) == 3) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars)) { fprintf(doc_output_file, ((const char *)"\\/")); }
fprintf(doc_output_file, ((const char *)"{\\tt %c}"), ((int)__29242_10_ch));
} else  {

putc(((int)__29242_10_ch), doc_output_file);
}
if (((int)curr_font) == 3) { _ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars = 1; }
} 
}
# 607
static void _ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib( _ZN3edg12a_const_charE *__29265_39_str, 
int __29266_38_len, 
_Bool __29267_38_font_setting)
# 619
{




if (__29266_38_len == 0) { __29266_38_len = ((int)(strlen(__29265_39_str))); } {
auto int __29283_12_i; __29283_12_i = 0; for (; __29283_12_i < __29266_38_len; ++__29283_12_i) {
auto char __29284_10_ch; __29284_10_ch = (__29265_39_str[__29283_12_i]);
if (((int)__29284_10_ch) == 10) {

((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)[_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos]) = ((char)0);
fprintf(doc_output_file, ((const char *)"%s\n"), (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer));
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = 0;
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = 0;
} else  {
if (((((((int)__29284_10_ch) == 42) || ((((int)__29284_10_ch) == 95) && (((int)(__29265_39_str[(__29283_12_i + 1)])) == 95))) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos > 7)) && (!(__29267_38_font_setting))) && (((int)curr_font) != 2))

{




((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)[(_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos++)]) = ((char)92);
}
if (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos >= 77) {


if (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank == 0) {



_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos;
}
((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)[_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank]) = ((char)0);
fprintf(doc_output_file, ((const char *)"%s\n"), (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer));
if (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank < _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos) {


auto int __29315_15_leftover_len; __29315_15_leftover_len = ((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos - _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank) - 1);
memcpy(((void *)(_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer + 7)), ((const void *)(((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer) + _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank) + 1)), ((size_t)__29315_15_leftover_len));

_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = (7 + __29315_15_leftover_len);
} else  {
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = 7;
}
memset(((void *)(&_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)), 32, 7UL);
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = 0;
}
((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)[_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos]) = __29284_10_ch;
if (((((int)__29284_10_ch) == 32) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos > 7)) && (!(__29267_38_font_setting))) {
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos;
}
if (!((((int)__29284_10_ch) == 32) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos == 7))) {



++_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos;
}
}
} } 
}



static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind( _ZN3edg12a_const_charE *__29341_45_string, 
int __29342_44_length, 
enum a_font_kind __29343_44_font)
# 692
{
auto int __29351_16_i;
auto _ZN3edg12a_const_charE *__29352_17_font_str;

if (((int)curr_font) != ((int)__29343_44_font)) {

switch ((int)curr_font) {
case 1: __29352_17_font_str = ((const char *)""); goto __T694484160;
case 2: __29352_17_font_str = ((const char *)"``\\ "); goto __T694484160;
case 3: __29352_17_font_str = ((const char *)"*\\ "); goto __T694484160;
case 0: __29352_17_font_str = ((const char *)""); goto __T694484160;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T694484160:;
_ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib(__29352_17_font_str, 0, ((_Bool)0x1));

switch ((int)__29343_44_font) {
case 1: __29352_17_font_str = ((const char *)""); goto __T694492256;
case 2: __29352_17_font_str = ((const char *)"``"); goto __T694492256;
case 3: __29352_17_font_str = ((const char *)"*"); goto __T694492256;
case 0: __29352_17_font_str = ((const char *)""); goto __T694492256;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T694492256:;
_ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib(__29352_17_font_str, 0, ((_Bool)0x1));
curr_font = __29343_44_font;
}
if (__29342_44_length == 0) {
__29342_44_length = ((int)(strlen(__29341_45_string)));
}
for (__29351_16_i = 0; __29351_16_i < __29342_44_length; ++__29351_16_i) {
_ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib((__29341_45_string + __29351_16_i), 1, ((_Bool)0x0));
} 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_rst_item_headerEiPKc( int __29384_51_number, 
_ZN3edg12a_const_charE *__29385_52_tag)




{
auto char __29391_16_buffer[8];


_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((const char *)" * - "), 0, fk_normal);
sprintf((__29391_16_buffer), ((const char *)"%04d"), __29384_51_number);
_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((_ZN3edg12a_const_charE *)(__29391_16_buffer)), 4, fk_tt);

_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((const char *)"\n   - | "), 0, fk_normal);

_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(__29385_52_tag, 0, fk_tt);

_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((const char *)":\n     | "), 0, fk_normal); 
}



static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_mml_doc_stringEPKci11a_font_kind( _ZN3edg12a_const_charE *__29407_45_string, 
int __29408_44_length, 
enum a_font_kind __29409_44_font)
# 758
{
auto int __29417_7_i;

if (((int)curr_font) != ((int)__29409_44_font)) {
auto _ZN3edg12a_const_charE *__29420_19_start_string;


switch ((int)__29409_44_font) {
case 1: __29420_19_start_string = ((const char *)"<rm>"); goto __T694525816;
case 2: __29420_19_start_string = ((const char *)"<tt>"); goto __T694525816;
case 3: __29420_19_start_string = ((const char *)"<em>"); goto __T694525816;
case 0: __29420_19_start_string = ((const char *)""); goto __T694525816;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T694525816:;
fprintf(doc_output_file, ((const char *)"%s"), __29420_19_start_string);
curr_font = __29409_44_font;
}
if (__29408_44_length == 0) { __29408_44_length = ((int)(strlen(__29407_45_string))); }
for (__29417_7_i = 0; __29417_7_i < __29408_44_length; ++__29417_7_i) {
auto char __29435_10_ch; __29435_10_ch = (__29407_45_string[__29417_7_i]);

if ((_Z6strchrPKci(((const char *)"<>"), ((int)__29435_10_ch))) != ((const char *)0)) { putc(92, doc_output_file); }
putc(((int)__29435_10_ch), doc_output_file);
} 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_create_doc_fillinEPPKc( _ZN3edg12a_const_charE **__29443_49_ptr_to_ptr)


{
auto _ZN3edg12a_const_charE *__29447_17_ptr;
auto _ZN3edg12a_const_charE *__29448_17_orig_ptr;
auto char __29449_9_ch;
auto _ZN3edg12a_const_charE *__29450_17_fill_in = ((_ZN3edg12a_const_charE *)0);
auto char __29451_9_fill_in_specifier[100];
auto char *__29452_10_fis_ptr;
auto _ZN3edg12a_const_charE *__29453_17_fill_in_override = ((_ZN3edg12a_const_charE *)0);
# 789
__29447_17_ptr = (*__29443_49_ptr_to_ptr);
__29448_17_orig_ptr = __29447_17_ptr;
# 798
__29452_10_fis_ptr = (__29451_9_fill_in_specifier);
if (((int)(*__29447_17_ptr)) == 91) {


(*(__29452_10_fis_ptr++)) = (*(__29447_17_ptr++));
while ((((int)(*__29447_17_ptr)) != 0) && (((int)(*__29447_17_ptr)) != 93)) {
(*(__29452_10_fis_ptr++)) = (*(__29447_17_ptr++));
}
if (((int)(*__29447_17_ptr)) != 0) { (*(__29452_10_fis_ptr++)) = (*(__29447_17_ptr++)); }
} else  {


(*(__29452_10_fis_ptr++)) = (*(__29447_17_ptr++));
while (isalnum(((int)((unsigned char)(*__29447_17_ptr))))) {
(*(__29452_10_fis_ptr++)) = (*(__29447_17_ptr++));
}
}
(*__29452_10_fis_ptr) = ((char)0);
# 822
if (((((int)(*__29447_17_ptr)) == 92) && (((int)(__29447_17_ptr[1])) == 61)) && (((int)(__29447_17_ptr[2])) == 39)) {

__29447_17_ptr += 3;
__29453_17_fill_in_override = __29447_17_ptr;
while ((((int)(*__29447_17_ptr)) != 39) && (((int)(*__29447_17_ptr)) != 0)) { __29447_17_ptr++; }

(*((char *)__29447_17_ptr)) = ((char)0);
__29447_17_ptr++;
}
if (__29453_17_fill_in_override != ((_ZN3edg12a_const_charE *)0)) {
output_doc_string(__29453_17_fill_in_override, 0, fk_normal);
} else  {
__29452_10_fis_ptr = (__29451_9_fill_in_specifier);
__29449_9_ch = (*(__29452_10_fis_ptr++));
switch ((int)__29449_9_ch) {
case 115:
if (((int)(*__29452_10_fis_ptr)) == 113) {
__29450_17_fill_in = ((const char *)"\"xxxx\"");
__29452_10_fis_ptr++;
} else  {
__29450_17_fill_in = ((const char *)"xxxx");
}
output_doc_string(__29450_17_fill_in, 0, fk_em);
goto __T694573104;
case 116:
output_doc_string(((const char *)"\"type\""), 0, fk_em);
goto __T694573104;
case 109:
output_doc_string(((const char *)"module \"module name\""), 0, fk_em);
goto __T694573104;
case 84:
output_doc_string(((const char *)"\"<templ-args>\""), 0, fk_em);
goto __T694573104;
case 112:
__29450_17_fill_in = ((const char *)"at line {\\em xxxx\\/}");
output_doc_string(((const char *)"at line "), 0, fk_normal);
output_doc_string(((const char *)"xxxx"), 0, fk_em);
goto __T694573104;
case 37:
output_doc_string(((const char *)"%"), 0, fk_normal);
goto __T694573104;
case 110:
{
auto _ZN3edg9a_booleanE __29523_21_name_only = 0;
auto _ZN3edg9a_booleanE __29524_21_template_args = 0;
auto _ZN3edg9a_booleanE __29525_21_decl_pos = 0;
while (isalnum(((int)((unsigned char)(*__29452_10_fis_ptr))))) {
__29449_9_ch = (*(__29452_10_fis_ptr++));
switch ((int)__29449_9_ch) {
case 102: goto __T694592480;
case 111: __29523_21_name_only = 1; goto __T694592480;
case 97: __29524_21_template_args = 1; goto __T694592480;
case 100: __29525_21_decl_pos = 1; goto __T694592480;
case 117: __29525_21_decl_pos = 1; goto __T694592480;
case 116: goto __T694592480;
case 84: goto __T694592480;
case 112: goto __T694592480;
case 49: goto __T694592480;
case 50: goto __T694592480;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"unexpected symbol fill-in %s\n"), ((_ZN3edg12a_const_charE *)(__29452_10_fis_ptr - 1)));
} __T694592480:;
}
if (!(__29523_21_name_only)) { output_doc_string(((const char *)"entity-kind "), 0, fk_em); }
output_doc_string(((const char *)"\"entity\""), 0, fk_em);
if (__29524_21_template_args) { output_doc_string(((const char *)"<args>"), 0, fk_em); }
if (__29525_21_decl_pos) {
output_doc_string(((const char *)" (declared at line "), 0, fk_normal);
output_doc_string(((const char *)"xxxx"), 0, fk_em);
output_doc_string(((const char *)")"), 0, fk_normal);
}
}
goto __T694573104;
case 91:

while (((int)(*__29452_10_fis_ptr)) != 0) {
if (((int)(*__29452_10_fis_ptr)) == 93) { goto __T694615800; } else  {
output_doc_string(((_ZN3edg12a_const_charE *)__29452_10_fis_ptr), 1, curr_font); }
__29452_10_fis_ptr++;
} __T694615800:;
if (((int)(*__29452_10_fis_ptr)) != 93) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"unterminated label fill-in: %s"), __29448_17_orig_ptr);
}
goto __T694573104;
case 100:
case 117:
output_doc_string(((const char *)"n"), 0, fk_em);
goto __T694573104;
case 114:
output_doc_string(((const char *)"reflection-description"), 0, fk_em);
goto __T694573104;
default:
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"unexpected message fill-in: %s"), __29448_17_orig_ptr);
} __T694573104:;
}
(*__29443_49_ptr_to_ptr) = __29447_17_ptr; 
}
# 929
static void _ZN30_INTERNAL_12_mk_errinfo_c_main19me_write_error_textEv(void)



{
auto int __29592_7_i;

fprintf(data_output_file, ((const char *)"static %s *message_text[(int)ec_last + 1] = {\n"), char_type);

for (__29592_7_i = 0; __29592_7_i < number_of_errors; ++__29592_7_i) {
auto _ZN3edg12a_const_charE *__29597_19_ptr;

if (__29592_7_i != 0) { fprintf(data_output_file, ((const char *)",\n")); }
fprintf(data_output_file, ((const char *)"  /* %s */\n"), (((error_info)[__29592_7_i]).enumerator));
putc(32, data_output_file);
putc(32, data_output_file);
__29597_19_ptr = (((error_info)[__29592_7_i]).text);
if (__29597_19_ptr == ((_ZN3edg12a_const_charE *)0)) {

fprintf(data_output_file, ((const char *)"(%s *)NULL"), char_type);
} else  {
for (; ((int)(*__29597_19_ptr)) != 0; ++__29597_19_ptr) { {
auto char __29609_14_ch; __29609_14_ch = (*__29597_19_ptr);
if ((((int)__29609_14_ch) == 92) && (((int)(__29597_19_ptr[1])) == 61)) {


__29597_19_ptr += 3;
while ((((int)(*__29597_19_ptr)) != 39) && (((int)(*__29597_19_ptr)) != 0)) { __29597_19_ptr++; }
goto __T694646880;
}
putc(((int)__29609_14_ch), data_output_file);
} __T694646880:; }
}
}
fprintf(data_output_file, ((const char *)"\n};\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_write_tag_tableEv(void)



{
auto int __29630_7_i;

fprintf(data_output_file, ((const char *)"#define NUMBER_OF_ERROR_TAGS %0d\n"), number_of_tags);


fprintf(data_output_file, ((const char *)"static an_error_tag_entry error_tags[NUMBER_OF_ERROR_TAGS]\n"));

fprintf(data_output_file, ((const char *)"#ifndef _lint\n= {\n"));
for (__29630_7_i = 0; __29630_7_i < number_of_tags; ++__29630_7_i) {

if (__29630_7_i != 0) { fprintf(data_output_file, ((const char *)",\n")); }
fprintf(data_output_file, ((const char *)"  { \"%s\", %s }"), (((tag_info)[__29630_7_i]).tag), (((tag_info)[__29630_7_i]).enumerator));

}
fprintf(data_output_file, ((const char *)"\n}\n"));
fprintf(data_output_file, ((const char *)"#else /* ifdef _lint */\n"));
fprintf(data_output_file, ((const char *)"/*lint -esym(728,*error_tags)*/\n"));
fprintf(data_output_file, ((const char *)"#endif /* ifndef _lint */\n"));
fprintf(data_output_file, ((const char *)";\n")); 
}
# 1003
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_latex_item_headerEiPKc( int __29661_53_number, 
_ZN3edg12a_const_charE *__29662_40_tag)




{
auto _ZN3edg12a_const_charE *__29668_17_ptr;


fprintf(doc_output_file, ((const char *)"\\item[\\tt %04d "), __29661_53_number);

__29668_17_ptr = __29662_40_tag;
while (((int)(*__29668_17_ptr)) != 0) {
if (((int)(*__29668_17_ptr)) == 95) { putc(92, doc_output_file); }
putc(((int)(*__29668_17_ptr)), doc_output_file);
__29668_17_ptr++;
}

fprintf(doc_output_file, ((const char *)":]\n"));

fprintf(doc_output_file, ((const char *)"\\item[]\n"));

fprintf(doc_output_file, ((const char *)"\\parskip 0pt\n\\itemsep 0pt\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKc( int __29688_51_number, 
_ZN3edg12a_const_charE *__29689_38_tag)




{
auto _ZN3edg12a_const_charE *__29695_18_ptr;


if (_ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first) {
_ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first = 0;
} else  {

fprintf(doc_output_file, ((const char *)"\n"));
}

fprintf(doc_output_file, ((const char *)"<ErrorItem>\n"));

fprintf(doc_output_file, ((const char *)"<tt>%04d<tab>"), __29688_51_number);

__29695_18_ptr = __29689_38_tag;
while (((int)(*__29695_18_ptr)) != 0) {
putc(((int)(*__29695_18_ptr)), doc_output_file);
__29695_18_ptr++;
}

fprintf(doc_output_file, ((const char *)":\n\n"));

fprintf(doc_output_file, ((const char *)"<ErrorText>\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_write_doc_fileEv(void)



{
auto int __29726_7_i;


for (__29726_7_i = 1; __29726_7_i < number_of_errors; ++__29726_7_i) { {
auto _ZN3edg12a_const_charE *__29730_19_ptr;

if ((((error_info)[__29726_7_i]).text) == ((_ZN3edg12a_const_charE *)0)) { goto __T694734104; }

if ((((error_info)[__29726_7_i]).tag) == ((_ZN3edg12a_const_charE *)0)) { goto __T694734104; }

curr_font = fk_normal;
write_item_header(__29726_7_i, (((error_info)[__29726_7_i]).tag));


__29730_19_ptr = (((error_info)[__29726_7_i]).text);
++__29730_19_ptr;
for (; ; ) {
auto char __29743_12_ch; __29743_12_ch = (*__29730_19_ptr);
if (((int)__29743_12_ch) == 37) {
++__29730_19_ptr;
_ZN30_INTERNAL_12_mk_errinfo_c_main20me_create_doc_fillinEPPKc((&__29730_19_ptr));
} else  {

if (((int)__29743_12_ch) == 34) { goto __T694742760; }
if (((int)__29743_12_ch) == 92) { ++__29730_19_ptr; }

output_doc_string(__29730_19_ptr, 1, fk_normal);
++__29730_19_ptr;
}
} __T694742760:;
output_doc_string(((const char *)"\n"), 0, fk_normal);
} __T694734104:; } 
}


int main( int __29761_14_argc,  char **__29761_26_argv)
{
auto int __29763_8_argpos = 1;
auto _ZN3edg9a_booleanE __29764_13_doc_mode = 0;
auto _ZN3edg9a_booleanE __29765_13_rst_doc = 0;

if (__29761_14_argc < 5) { _ZN30_INTERNAL_12_mk_errinfo_c_main21me_command_line_errorEv(); }
if ((strcmp(((const char *)(__29761_26_argv[__29763_8_argpos])), ((const char *)"-d"))) == 0) {

__29764_13_doc_mode = 1;
output_doc_string = (&_ZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kind);
write_item_header = (&_ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_latex_item_headerEiPKc);
__29763_8_argpos++;
} else  { if ((strcmp(((const char *)(__29761_26_argv[__29763_8_argpos])), ((const char *)"-rst"))) == 0) {

__29764_13_doc_mode = 1;
__29765_13_rst_doc = 1;
output_doc_string = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind);
write_item_header = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_rst_item_headerEiPKc);
__29763_8_argpos++;
} else  { if ((strcmp(((const char *)(__29761_26_argv[__29763_8_argpos])), ((const char *)"-mml"))) == 0) {

__29764_13_doc_mode = 1;
output_doc_string = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_mml_doc_stringEPKci11a_font_kind);
write_item_header = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKc);
__29763_8_argpos++;
} else  { if ((strcmp(((const char *)(__29761_26_argv[__29763_8_argpos])), ((const char *)"-cch"))) == 0) {


char_type = ((const char *)"const char");
__29763_8_argpos++;
} } } }
message_input_file_name = (__29761_26_argv[(__29763_8_argpos++)]);
tag_input_file_name = (__29761_26_argv[(__29763_8_argpos++)]);
if (__29764_13_doc_mode) {
doc_output_file_name = (__29761_26_argv[(__29763_8_argpos++)]);
} else  {
codes_output_file_name = (__29761_26_argv[(__29763_8_argpos++)]);
data_output_file_name = (__29761_26_argv[(__29763_8_argpos++)]);
}
if (__29763_8_argpos != __29761_14_argc) {
_ZN30_INTERNAL_12_mk_errinfo_c_main21me_command_line_errorEv();
}

message_input_file = (fopen(((const char *)message_input_file_name), ((const char *)"r")));
if (message_input_file == ((FILE *)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"cannot open %s"), ((_ZN3edg12a_const_charE *)message_input_file_name));
}
if (__29764_13_doc_mode) {

doc_output_file = (fopen(((const char *)doc_output_file_name), ((const char *)"w")));
if (doc_output_file == ((FILE *)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"cannot open %s"), ((_ZN3edg12a_const_charE *)doc_output_file_name));
}
if (__29765_13_rst_doc) {
fputs(((const char *)".. _error-messages:\n\n"), doc_output_file);
fputs(((const char *)"==============\nError Messages\n==============\n\n.. list-table::\n\n"), doc_output_file);


}
} else  {

tag_input_file = (fopen(((const char *)tag_input_file_name), ((const char *)"r")));
if (tag_input_file == ((FILE *)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"cannot open %s"), ((_ZN3edg12a_const_charE *)tag_input_file_name));
}
codes_output_file = (fopen(((const char *)codes_output_file_name), ((const char *)"w")));
if (codes_output_file == ((FILE *)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"cannot open %s"), ((_ZN3edg12a_const_charE *)codes_output_file_name));
}
data_output_file = (fopen(((const char *)data_output_file_name), ((const char *)"w")));
if (data_output_file == ((FILE *)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"cannot open %s"), ((_ZN3edg12a_const_charE *)data_output_file_name));
}

_ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_file_headerEP8_IO_FILE(codes_output_file);
_ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_file_headerEP8_IO_FILE(data_output_file);

_ZN30_INTERNAL_12_mk_errinfo_c_main27me_write_include_guard_testEP8_IO_FILEPKc(codes_output_file, ((const char *)"ERR_CODES_H"));
_ZN30_INTERNAL_12_mk_errinfo_c_main27me_write_include_guard_testEP8_IO_FILEPKc(data_output_file, ((const char *)"ERR_DATA_H"));

_ZN30_INTERNAL_12_mk_errinfo_c_main23me_write_open_namespaceEP8_IO_FILE(codes_output_file);
_ZN30_INTERNAL_12_mk_errinfo_c_main23me_write_open_namespaceEP8_IO_FILE(data_output_file);
}

_ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_fileEv();
if (__29764_13_doc_mode) {

_ZN30_INTERNAL_12_mk_errinfo_c_main17me_write_doc_fileEv();
fclose(doc_output_file);
} else  {

_ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_error_codesEv();

_ZN30_INTERNAL_12_mk_errinfo_c_main19me_write_error_textEv();


qsort(((void *)(&error_info)), ((_ZN3edg16qsort_nmemb_typeE)number_of_errors), 24UL, (&_ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_));


_ZN30_INTERNAL_12_mk_errinfo_c_main16me_read_tag_fileEv();

qsort(((void *)(&tag_info)), ((_ZN3edg16qsort_nmemb_typeE)number_of_tags), 16UL, (&_ZN30_INTERNAL_12_mk_errinfo_c_main16compare_tag_infoEPKvS1_));


_ZN30_INTERNAL_12_mk_errinfo_c_main18me_write_tag_tableEv();

_ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_close_namespaceEP8_IO_FILE(codes_output_file);
_ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_close_namespaceEP8_IO_FILE(data_output_file);

_ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_include_guard_endEP8_IO_FILEPKc(codes_output_file, ((const char *)"ERR_CODES_H"));
_ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_include_guard_endEP8_IO_FILEPKc(data_output_file, ((const char *)"ERR_DATA_H"));
fclose(codes_output_file);
fclose(data_output_file);
}
return 0;
}
