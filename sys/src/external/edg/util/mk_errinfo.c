/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:16 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "util/mk_errinfo.c"
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
#line 28 "ape-sys/ctype.h"
enum _ZN30_INTERNAL_12_mk_errinfo_c_mainUt_E {
_ISupper = 0x1,
_ISlower = 0x2,
_ISdigit = 0x4,
_ISspace = 0x8,
_ISpunct = 0x10,
_IScntrl = 0x20,
_ISblank = 0x40,
_ISxdigit = 0x80};
#line 277 "util/mk_errinfo.c"
struct an_error_info;
#line 288
struct a_tag_info;
#line 523
enum a_font_kind {
fk_none,
fk_normal,
fk_tt,
fk_em};
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 67 "util/mk_errinfo.c"
typedef char a_me_input_line[32767];
#line 276
typedef struct an_error_info *an_error_info_ptr;
#line 515 "src/basics.h"
typedef const char _ZN3edg12a_const_charE;
#line 277 "util/mk_errinfo.c"
struct an_error_info {
_ZN3edg12a_const_charE *text;
_ZN3edg12a_const_charE *enumerator;
_ZN3edg12a_const_charE *tag;};
typedef struct an_error_info an_error_info;
#line 287
typedef struct a_tag_info *a_tag_info_ptr;
struct a_tag_info {
char *enumerator;
char *tag;};
typedef struct a_tag_info a_tag_info;
#line 536
typedef void a_doc_string_output_routine(_ZN3edg12a_const_charE *, int, enum a_font_kind);
#line 994
typedef void a_write_item_header_routine(int dummy, _ZN3edg12a_const_charE *);
#line 214 "src/basics.h"
typedef _Bool _ZN3edg9a_booleanE;
#line 499
typedef void *_ZN3edg10a_void_ptrE;
typedef const void *_ZN3edg16a_const_void_ptrE;
#line 541
typedef size_t _ZN3edg8sizeof_tE;
#line 4166 "src/host_envir.h"
typedef _ZN3edg16a_const_void_ptrE _ZN3edg18a_bsearch_arg_typeE;
#line 4174
typedef _ZN3edg8sizeof_tE _ZN3edg16qsort_nmemb_typeE;
#line 65 "ape-sys/stdio.h"
extern int fclose(FILE *);

extern FILE *fopen(const char *, const char *);



extern int fprintf(FILE *, const char *, ...);



extern int sprintf(char *, const char *, ...);
extern int snprintf(char *, size_t, const char *, ...);
#line 86
extern int fputs(const char *, FILE *);
extern int getc(FILE *);



extern int putc(int, FILE *);
#line 67 "ape-sys/stdlib.h"
extern void *malloc(size_t);



extern void exit(int);



extern void *bsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
#line 11 "ape-sys/string.h"
extern void *memcpy(void *, const void *, size_t);


extern char *strcpy(char *, const char *);




extern int strcmp(const char *, const char *);
#line 27
extern char *strchr(const char *, int);
#line 34
extern void *memset(void *, int, size_t);

extern size_t strlen(const char *);
#line 85 "util/mk_errinfo.c"
static void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(_ZN3edg12a_const_charE *error_string);
#line 96
static void _ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(_ZN3edg12a_const_charE *error_text, _ZN3edg12a_const_charE *insertion_string);
#line 113
static _ZN3edg10a_void_ptrE _ZN30_INTERNAL_12_mk_errinfo_c_main20me_malloc_with_checkEy(_ZN3edg8sizeof_tE size);
#line 128
static _ZN3edg9a_booleanE _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE(FILE *input_file);
#line 158
static char *_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(char *source);
#line 171
static void _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(void);
#line 177
static void _ZN30_INTERNAL_12_mk_errinfo_c_main21me_command_line_errorEv(void);
#line 205
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_file_headerEP8_IO_FILE(FILE *file);
#line 230
static void _ZN30_INTERNAL_12_mk_errinfo_c_main23me_write_open_namespaceEP8_IO_FILE(FILE *file);
#line 242
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_close_namespaceEP8_IO_FILE(FILE *file);
#line 251
static void _ZN30_INTERNAL_12_mk_errinfo_c_main27me_write_include_guard_testEP8_IO_FILEPKc(FILE *file, _ZN3edg12a_const_charE *guard_name);
#line 262
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_include_guard_endEP8_IO_FILEPKc(FILE *file, _ZN3edg12a_const_charE *guard_name);
#line 298
static int _ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_(_ZN3edg16a_const_void_ptrE arg1, _ZN3edg16a_const_void_ptrE arg2);
#line 314
static int _ZN30_INTERNAL_12_mk_errinfo_c_main16compare_tag_infoEPKvS1_(_ZN3edg16a_const_void_ptrE arg1, _ZN3edg16a_const_void_ptrE arg2);
#line 358
static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_fileEv(void);
#line 458
static void _ZN30_INTERNAL_12_mk_errinfo_c_main16me_read_tag_fileEv(void);
#line 506
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_error_codesEv(void);
#line 545
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kind(_ZN3edg12a_const_charE *string, int length, enum a_font_kind font);
#line 607
static void _ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib(_ZN3edg12a_const_charE *str, int len, _Bool font_setting);
#line 683
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(_ZN3edg12a_const_charE *string, int length, enum a_font_kind font);
#line 726
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_rst_item_headerEiPKc(int number, _ZN3edg12a_const_charE *tag);
#line 749
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_mml_doc_stringEPKci11a_font_kind(_ZN3edg12a_const_charE *string, int length, enum a_font_kind font);
#line 785
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_create_doc_fillinEPPKc(_ZN3edg12a_const_charE **ptr_to_ptr);
#line 929
static void _ZN30_INTERNAL_12_mk_errinfo_c_main19me_write_error_textEv(void);
#line 967
static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_write_tag_tableEv(void);
#line 1003
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_latex_item_headerEiPKc(int number, _ZN3edg12a_const_charE *tag);
#line 1030
static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKc(int number, _ZN3edg12a_const_charE *tag);
#line 1063
static void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_write_doc_fileEv(void);
#line 1103
extern int main(int argc, char **argv);
#line 53 "ape-sys/stdio.h"
extern FILE *stderr;
#line 39 "ape-sys/ctype.h"
extern unsigned char _ctype[];
#line 68 "util/mk_errinfo.c"
static a_me_input_line me_input_line;
#line 81
static _ZN3edg12a_const_charE *message_prefix;
#line 190
static _ZN3edg12a_const_charE *header_comments[10];
#line 217
static _ZN3edg12a_const_charE *open_namespace[8];
#line 338
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
#line 531
static enum a_font_kind curr_font;
#line 539
static a_doc_string_output_routine *output_doc_string;
#line 926
static const char *char_type;
#line 998
static a_write_item_header_routine *write_item_header;
#line 555
static _ZN3edg9a_booleanE _ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars;
#line 620
static char _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer[80];
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos;
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank;
#line 1038
static _ZN3edg9a_booleanE _ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first;
#line 81
static _ZN3edg12a_const_charE *message_prefix = ((_ZN3edg12a_const_charE *)"mk_errinfo");
#line 190
static _ZN3edg12a_const_charE *header_comments[10] = {((const char *)"/*"),((const char *)""),((const char *)"DO NOT UPDATE THIS FILE!"),((const char *)""),((const char *)"This file is generated by the mk_errinfo program from the information"),((const char *)"specified in the error_msg.txt and error_tag.txt files."
#line 190
),((const char *)""),((const char *)"*/"),((const char *)""),((_ZN3edg12a_const_charE *)0)};
#line 217
static _ZN3edg12a_const_charE *open_namespace[8] = {((const char *)"#ifndef BEGIN_EDG_NAMESPACE"),((const char *)"#define BEGIN_EDG_NAMESPACE /* nothing */"),((const char *)"#endif  /* BEGIN_EDG_NAMESPACE */"),((const char *)"#ifndef END_EDG_NAMESPACE"),((const char *)"#define END_EDG_NAMESPACE /* nothing */"
#line 217
),((const char *)"#endif  /* END_EDG_NAMESPACE */"),((const char *)"BEGIN_EDG_NAMESPACE"),((_ZN3edg12a_const_charE *)0)};
#line 354
static int number_of_errors = 0;
static int number_of_tags = 0;
#line 926
static const char *char_type = ((const char *)"a_const_char");
#line 621
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = 0;
static int _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = 0;
#line 1038
static _ZN3edg9a_booleanE _ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first = ((_ZN3edg9a_booleanE)1);
#line 85
static void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc( _ZN3edg12a_const_charE *__21321_54_error_string)




{
fprintf(stderr, ((const char *)"%s: %s\n"), message_prefix, __21321_54_error_string);
exit(4); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_( _ZN3edg12a_const_charE *__21332_36_error_text, 
_ZN3edg12a_const_charE *__21333_36_insertion_string)
#line 105
{
fprintf(stderr, ((const char *)"%s: "), message_prefix);
fprintf(stderr, __21332_36_error_text, __21333_36_insertion_string);
fprintf(stderr, ((const char *)"\n"));
exit(2); 
}


static _ZN3edg10a_void_ptrE _ZN30_INTERNAL_12_mk_errinfo_c_main20me_malloc_with_checkEy( _ZN3edg8sizeof_tE __21349_49_size)




{
auto _ZN3edg10a_void_ptrE __21355_14_ptr;

if ((__21355_14_ptr = ((_ZN3edg10a_void_ptrE)(malloc(__21349_49_size)))) == ((_ZN3edg10a_void_ptrE)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"out of memory"), ((_ZN3edg12a_const_charE *)0));
}
return __21355_14_ptr;
}


static _ZN3edg9a_booleanE _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE( FILE *__21364_43_input_file)
#line 134
{
auto char *__21371_13_buffer_pos = me_input_line;
auto int __21372_13_size = 0;
auto int __21373_13_ch;
auto _ZN3edg9a_booleanE __21374_13_result;

while ((__21373_13_ch = (getc(__21364_43_input_file))) , ((__21373_13_ch != (-1)) && (__21373_13_ch != 10))) {
if ((++__21372_13_size) > 32766) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"me_read_input_line: input line too long."));
}
(*(__21371_13_buffer_pos++)) = ((char)__21373_13_ch);
}


(*(__21371_13_buffer_pos++)) = ((char)0);


__21374_13_result = ((_ZN3edg9a_booleanE)1);
if ((__21373_13_ch == (-1)) && (__21372_13_size == 0)) { __21374_13_result = ((_ZN3edg9a_booleanE)0); }

return __21374_13_result;
}


static char *_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc( char *__21394_35_source)




{
auto char *__21400_9_dest;
__21400_9_dest = ((char *)(_ZN30_INTERNAL_12_mk_errinfo_c_main20me_malloc_with_checkEy(((_ZN3edg8sizeof_tE)((strlen(((const char *)__21394_35_source))) + 1ULL)))));
strcpy(__21400_9_dest, ((const char *)__21394_35_source));
return __21400_9_dest;
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
#line 205
static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_file_headerEP8_IO_FILE( FILE *__21441_40_file)



{
auto int __21446_7_i;
for (__21446_7_i = 0; ((header_comments)[__21446_7_i]) != ((_ZN3edg12a_const_charE *)0); ++__21446_7_i) {
fprintf(__21441_40_file, ((const char *)"%s\n"), ((header_comments)[__21446_7_i]));
} 
}
#line 230
static void _ZN30_INTERNAL_12_mk_errinfo_c_main23me_write_open_namespaceEP8_IO_FILE( FILE *__21466_43_file)



{
auto int __21471_7_i;
for (__21471_7_i = 0; ((open_namespace)[__21471_7_i]) != ((_ZN3edg12a_const_charE *)0); ++__21471_7_i) {
fprintf(__21466_43_file, ((const char *)"%s\n"), ((open_namespace)[__21471_7_i]));
} 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_close_namespaceEP8_IO_FILE( FILE *__21478_44_file)



{
fprintf(__21478_44_file, ((const char *)"END_EDG_NAMESPACE\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main27me_write_include_guard_testEP8_IO_FILEPKc( FILE *__21487_55_file, 
_ZN3edg12a_const_charE *__21488_55_guard_name)




{
fprintf(__21487_55_file, ((const char *)"#ifndef %s\n#define %s 1\n"), __21488_55_guard_name, __21488_55_guard_name); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_include_guard_endEP8_IO_FILEPKc( FILE *__21498_54_file, 
_ZN3edg12a_const_charE *__21499_54_guard_name)




{
fprintf(__21498_54_file, ((const char *)"#endif /* #ifndef %s */\n"), __21499_54_guard_name); 
}
#line 298
static int _ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_( _ZN3edg16a_const_void_ptrE __21534_48_arg1, 
_ZN3edg16a_const_void_ptrE __21535_48_arg2)




{
auto an_error_info_ptr __21541_21_eip1;
auto an_error_info_ptr __21542_21_eip2;

__21541_21_eip1 = ((an_error_info_ptr)__21534_48_arg1);
__21542_21_eip2 = ((an_error_info_ptr)__21535_48_arg2);
return strcmp((__21541_21_eip1->enumerator), (__21542_21_eip2->enumerator));
}


static int _ZN30_INTERNAL_12_mk_errinfo_c_main16compare_tag_infoEPKvS1_( _ZN3edg16a_const_void_ptrE __21550_46_arg1, 
_ZN3edg16a_const_void_ptrE __21551_46_arg2)




{
auto a_tag_info_ptr __21557_18_eip1;
auto a_tag_info_ptr __21558_18_eip2;

__21557_18_eip1 = ((a_tag_info_ptr)__21550_46_arg1);
__21558_18_eip2 = ((a_tag_info_ptr)__21551_46_arg2);
return strcmp(((const char *)(__21557_18_eip1->tag)), ((const char *)(__21558_18_eip2->tag)));
}
#line 358
static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_fileEv(void)



{
while (_ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE(message_input_file)) { {




auto char *__21604_11_ptr;
auto char *__21605_11_enumerator_start;
auto char *__21606_11_tag_start;
auto char *__21607_11_text_start;
auto char *__21608_11_copy_of_enumerator;
auto char *__21609_11_copy_of_tag;

__21604_11_ptr = me_input_line;
{ while (((int)(*__21604_11_ptr)) == 32) { __21604_11_ptr++; } } ;


if ((((int)(*__21604_11_ptr)) == 35) || (((int)(*__21604_11_ptr)) == 0)) { goto __T137370920; }
if (number_of_errors >= 10000) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"too many error messages -- increase MAX_ERRORS"));
}
__21605_11_enumerator_start = __21604_11_ptr;
__21604_11_ptr = (strchr(((const char *)__21605_11_enumerator_start), 59));
if (__21604_11_ptr == ((char *)0)) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }
(*(__21604_11_ptr++)) = ((char)0);
{ while (((int)(*__21604_11_ptr)) == 32) { __21604_11_ptr++; } } ;
__21606_11_tag_start = __21604_11_ptr;

__21604_11_ptr = (strchr(((const char *)__21604_11_ptr), 59));
if (__21604_11_ptr == ((char *)0)) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }
(*(__21604_11_ptr++)) = ((char)0);
{ while (((int)(*__21604_11_ptr)) == 32) { __21604_11_ptr++; } } ;
if ((strcmp(((const char *)__21605_11_enumerator_start), ((const char *)"REMOVED"))) == 0) {




snprintf(me_input_line, 32767ULL, ((const char *)"ec_removed_%0d"), number_of_errors);

(((error_info)[number_of_errors]).enumerator) = ((_ZN3edg12a_const_charE *)(_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(me_input_line)));
(((error_info)[number_of_errors]).text) = ((_ZN3edg12a_const_charE *)0);
number_of_errors++;
goto __T137370920;
}

if (((int)(*__21604_11_ptr)) != 34) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }

__21607_11_text_start = (__21604_11_ptr++);

for (; ; ) {
auto char __21648_12_ch; __21648_12_ch = (*__21604_11_ptr);
if ((((int)__21648_12_ch) == 34) || (((int)__21648_12_ch) == 0)) { goto __T137395808; }

if (((int)__21648_12_ch) == 92) { __21604_11_ptr++; }
__21604_11_ptr++;
} __T137395808:;

if (((int)(*__21604_11_ptr)) != 34) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }

__21604_11_ptr++;
if (((int)(*__21604_11_ptr)) != 0) {
auto char *__21659_13_after_quote; __21659_13_after_quote = __21604_11_ptr;
{ while (((int)(*__21604_11_ptr)) == 32) { __21604_11_ptr++; } } ;
if (((int)(*__21604_11_ptr)) != 0) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }

(*__21659_13_after_quote) = ((char)0);
}
(((error_info)[number_of_errors]).text) = ((_ZN3edg12a_const_charE *)(_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__21607_11_text_start)));
__21608_11_copy_of_enumerator = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__21605_11_enumerator_start));
(((error_info)[number_of_errors]).enumerator) = ((_ZN3edg12a_const_charE *)__21608_11_copy_of_enumerator);


if (((int)(*__21606_11_tag_start)) == 0) { __21606_11_tag_start = (me_input_line + 3); }
if ((strcmp(((const char *)__21606_11_tag_start), ((const char *)"INTERNAL"))) == 0) {

(((error_info)[number_of_errors]).tag) = ((_ZN3edg12a_const_charE *)0);
} else  {
if (number_of_tags >= 10000) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"too many tags -- increase MAX_TAGS"));
}
__21609_11_copy_of_tag = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__21606_11_tag_start));
(((error_info)[number_of_errors]).tag) = ((_ZN3edg12a_const_charE *)__21609_11_copy_of_tag);
(((tag_info)[number_of_tags]).enumerator) = __21608_11_copy_of_enumerator;
(((tag_info)[number_of_tags]).tag) = __21609_11_copy_of_tag;
number_of_tags++;
}
number_of_errors++;
} __T137370920:; }
fclose(message_input_file);

(((error_info)[number_of_errors]).enumerator) = ((const char *)"ec_last");
(((error_info)[number_of_errors]).text) = ((_ZN3edg12a_const_charE *)0);
number_of_errors++; 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main16me_read_tag_fileEv(void)
#line 469
{
while (_ZN30_INTERNAL_12_mk_errinfo_c_main18me_read_input_lineEP8_IO_FILE(tag_input_file)) { {
auto char *__21707_12_ptr;
auto char *__21708_12_tag_start;
auto char *__21709_12_enumerator_start;
auto an_error_info __21710_19_error_info_to_find;
__21707_12_ptr = me_input_line;
{ while (((int)(*__21707_12_ptr)) == 32) { __21707_12_ptr++; } } ;


if ((((int)(*__21707_12_ptr)) == 35) || (((int)(*__21707_12_ptr)) == 0)) { goto __T137496744; }
__21709_12_enumerator_start = __21707_12_ptr;

__21707_12_ptr = (strchr(((const char *)__21709_12_enumerator_start), 59));
if (__21707_12_ptr == ((char *)0)) { _ZN30_INTERNAL_12_mk_errinfo_c_main16me_invalid_inputEv(); }
(*(__21707_12_ptr++)) = ((char)0);
{ while (((int)(*__21707_12_ptr)) == 32) { __21707_12_ptr++; } } ;
__21708_12_tag_start = __21707_12_ptr;

(__21710_19_error_info_to_find.enumerator) = ((_ZN3edg12a_const_charE *)__21709_12_enumerator_start);
if (!(bsearch(((_ZN3edg18a_bsearch_arg_typeE)(&__21710_19_error_info_to_find)), ((const void *)(&error_info)), ((_ZN3edg8sizeof_tE)number_of_errors), 24ULL, (&_ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_))))


{
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"%s is not a valid error code"), ((_ZN3edg12a_const_charE *)__21709_12_enumerator_start));
}
(((tag_info)[number_of_tags]).enumerator) = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__21709_12_enumerator_start));
(((tag_info)[number_of_tags]).tag) = (_ZN30_INTERNAL_12_mk_errinfo_c_main14me_copy_stringEPc(__21708_12_tag_start));
number_of_tags++;
if (number_of_tags >= 10000) {
_ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"too many tags -- increase MAX_TAGS"));
}
} __T137496744:; }
fclose(tag_input_file); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_error_codesEv(void)



{
auto int __21747_7_i;

fprintf(codes_output_file, ((const char *)"enum an_error_code {\n"));
for (__21747_7_i = 0; __21747_7_i < number_of_errors; ++__21747_7_i) {

if (__21747_7_i != 0) { fprintf(codes_output_file, ((const char *)",\n")); }
fprintf(codes_output_file, ((const char *)"  %s /* = %0d */"), (((error_info)[__21747_7_i]).enumerator), __21747_7_i);

}
fprintf(codes_output_file, ((const char *)"\n};\n\n")); 
}
#line 545
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kind( _ZN3edg12a_const_charE *__21781_47_string, 
int __21782_42_length, 
enum a_font_kind __21783_25_font)
#line 554
{

auto int __21792_7_i;

if (((int)curr_font) != ((int)__21783_25_font)) {
auto _ZN3edg12a_const_charE *__21795_19_start_string;

if (((int)curr_font) == 1) {

} else  { if (((int)curr_font) == 3) {

fprintf(doc_output_file, ((const char *)"%s"), ((const char *)("\\/}")));
} else  {

fprintf(doc_output_file, ((const char *)"%s"), ((const char *)("}")));
} }

_ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars = ((_ZN3edg9a_booleanE)0);
switch ((int)__21783_25_font) {
case 1: __21795_19_start_string = ((const char *)""); goto __T137529440;
case 2: __21795_19_start_string = ((const char *)"{\\tt "); goto __T137529440;
case 3: __21795_19_start_string = ((const char *)"{\\em "); goto __T137529440;
case 0: __21795_19_start_string = ((const char *)""); goto __T137529440;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T137529440:;
fprintf(doc_output_file, ((const char *)"%s"), __21795_19_start_string);
curr_font = __21783_25_font;
}
if (__21782_42_length == 0) { __21782_42_length = ((int)(strlen(__21781_47_string))); }
for (__21792_7_i = 0; __21792_7_i < __21782_42_length; ++__21792_7_i) {
auto char __21820_10_ch; __21820_10_ch = (__21781_47_string[__21792_7_i]);

if ((strchr(((const char *)"_#&${}%"), ((int)__21820_10_ch))) != ((char *)0)) { putc(92, doc_output_file); }
if ((((int)curr_font) != 2) && ((strchr(((const char *)"\"<>"), ((int)__21820_10_ch))) != ((char *)0))) {


if ((((int)curr_font) == 3) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars)) { fprintf(doc_output_file, ((const char *)"\\/")); }
fprintf(doc_output_file, ((const char *)"{\\tt %c}"), ((int)__21820_10_ch));
} else  {

putc(((int)__21820_10_ch), doc_output_file);
}
if (((int)curr_font) == 3) { _ZZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kindE12any_em_chars = ((_ZN3edg9a_booleanE)1); }
} 
}
#line 607
static void _ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib( _ZN3edg12a_const_charE *__21843_39_str, 
int __21844_38_len, 
_Bool __21845_38_font_setting)
#line 619
{




if (__21844_38_len == 0) { __21844_38_len = ((int)(strlen(__21843_39_str))); } {
auto int __21861_12_i; __21861_12_i = 0; for (; __21861_12_i < __21844_38_len; ++__21861_12_i) {
auto char __21862_10_ch; __21862_10_ch = (__21843_39_str[__21861_12_i]);
if (((int)__21862_10_ch) == 10) {

((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)[_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos]) = ((char)0);
fprintf(doc_output_file, ((const char *)"%s\n"), (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer));
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = 0;
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = 0;
} else  {
if (((((((int)__21862_10_ch) == 42) || ((((int)__21862_10_ch) == 95) && (((int)(__21843_39_str[(__21861_12_i + 1)])) == 95))) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos > 7)) && (!(__21845_38_font_setting))) && (((int)curr_font) != 2))

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


auto int __21893_15_leftover_len; __21893_15_leftover_len = ((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos - _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank) - 1);
memcpy(((void *)(_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer + 7)), ((const void *)(((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer) + _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank) + 1)), ((size_t)__21893_15_leftover_len));

_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = (7 + __21893_15_leftover_len);
} else  {
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos = 7;
}
memset(((void *)(&_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)), 32, 7ULL);
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = 0;
}
((_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE6buffer)[_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos]) = __21862_10_ch;
if (((((int)__21862_10_ch) == 32) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos > 7)) && (!(__21845_38_font_setting))) {
_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE10last_blank = _ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos;
}
if (!((((int)__21862_10_ch) == 32) && (_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos == 7))) {



++_ZZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcibE7buf_pos;
}
}
} } 
}



static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind( _ZN3edg12a_const_charE *__21919_45_string, 
int __21920_44_length, 
enum a_font_kind __21921_44_font)
#line 692
{
auto int __21929_16_i;
auto _ZN3edg12a_const_charE *__21930_17_font_str;

if (((int)curr_font) != ((int)__21921_44_font)) {

switch ((int)curr_font) {
case 1: __21930_17_font_str = ((const char *)""); goto __T137592928;
case 2: __21930_17_font_str = ((const char *)"``\\ "); goto __T137592928;
case 3: __21930_17_font_str = ((const char *)"*\\ "); goto __T137592928;
case 0: __21930_17_font_str = ((const char *)""); goto __T137592928;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T137592928:;
_ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib(__21930_17_font_str, 0, ((_Bool)0x1));

switch ((int)__21921_44_font) {
case 1: __21930_17_font_str = ((const char *)""); goto __T137601024;
case 2: __21930_17_font_str = ((const char *)"``"); goto __T137601024;
case 3: __21930_17_font_str = ((const char *)"*"); goto __T137601024;
case 0: __21930_17_font_str = ((const char *)""); goto __T137601024;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T137601024:;
_ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib(__21930_17_font_str, 0, ((_Bool)0x1));
curr_font = __21921_44_font;
}
if (__21920_44_length == 0) {
__21920_44_length = ((int)(strlen(__21919_45_string)));
}
for (__21929_16_i = 0; __21929_16_i < __21920_44_length; ++__21929_16_i) {
_ZN30_INTERNAL_12_mk_errinfo_c_main11put_rst_strEPKcib((__21919_45_string + __21929_16_i), 1, ((_Bool)0x0));
} 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_rst_item_headerEiPKc( int __21962_51_number, 
_ZN3edg12a_const_charE *__21963_52_tag)




{
auto char __21969_16_buffer[8];


_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((const char *)" * - "), 0, fk_normal);
sprintf((__21969_16_buffer), ((const char *)"%04d"), __21962_51_number);
_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((_ZN3edg12a_const_charE *)(__21969_16_buffer)), 4, fk_tt);

_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((const char *)"\n   - | "), 0, fk_normal);

_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(__21963_52_tag, 0, fk_tt);

_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind(((const char *)":\n     | "), 0, fk_normal); 
}



static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_mml_doc_stringEPKci11a_font_kind( _ZN3edg12a_const_charE *__21985_45_string, 
int __21986_44_length, 
enum a_font_kind __21987_44_font)
#line 758
{
auto int __21995_7_i;

if (((int)curr_font) != ((int)__21987_44_font)) {
auto _ZN3edg12a_const_charE *__21998_19_start_string;


switch ((int)__21987_44_font) {
case 1: __21998_19_start_string = ((const char *)"<rm>"); goto __T137625064;
case 2: __21998_19_start_string = ((const char *)"<tt>"); goto __T137625064;
case 3: __21998_19_start_string = ((const char *)"<em>"); goto __T137625064;
case 0: __21998_19_start_string = ((const char *)""); goto __T137625064;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main17me_internal_errorEPKc(((const char *)"unexpected font"));
} __T137625064:;
fprintf(doc_output_file, ((const char *)"%s"), __21998_19_start_string);
curr_font = __21987_44_font;
}
if (__21986_44_length == 0) { __21986_44_length = ((int)(strlen(__21985_45_string))); }
for (__21995_7_i = 0; __21995_7_i < __21986_44_length; ++__21995_7_i) {
auto char __22013_10_ch; __22013_10_ch = (__21985_45_string[__21995_7_i]);

if ((strchr(((const char *)"<>"), ((int)__22013_10_ch))) != ((char *)0)) { putc(92, doc_output_file); }
putc(((int)__22013_10_ch), doc_output_file);
} 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main20me_create_doc_fillinEPPKc( _ZN3edg12a_const_charE **__22021_49_ptr_to_ptr)


{
auto _ZN3edg12a_const_charE *__22025_17_ptr;
auto _ZN3edg12a_const_charE *__22026_17_orig_ptr;
auto char __22027_9_ch;
auto _ZN3edg12a_const_charE *__22028_17_fill_in = ((_ZN3edg12a_const_charE *)0);
auto char __22029_9_fill_in_specifier[100];
auto char *__22030_10_fis_ptr;
auto _ZN3edg12a_const_charE *__22031_17_fill_in_override = ((_ZN3edg12a_const_charE *)0);
#line 789
__22025_17_ptr = (*__22021_49_ptr_to_ptr);
__22026_17_orig_ptr = __22025_17_ptr;
#line 798
__22030_10_fis_ptr = (__22029_9_fill_in_specifier);
if (((int)(*__22025_17_ptr)) == 91) {


(*(__22030_10_fis_ptr++)) = (*(__22025_17_ptr++));
while ((((int)(*__22025_17_ptr)) != 0) && (((int)(*__22025_17_ptr)) != 93)) {
(*(__22030_10_fis_ptr++)) = (*(__22025_17_ptr++));
}
if (((int)(*__22025_17_ptr)) != 0) { (*(__22030_10_fis_ptr++)) = (*(__22025_17_ptr++)); }
} else  {


(*(__22030_10_fis_ptr++)) = (*(__22025_17_ptr++));
while (((int)((_ctype)[((unsigned char)((unsigned char)(*__22025_17_ptr)))])) & 0x7) {
(*(__22030_10_fis_ptr++)) = (*(__22025_17_ptr++));
}
}
(*__22030_10_fis_ptr) = ((char)0);
#line 822
if (((((int)(*__22025_17_ptr)) == 92) && (((int)(__22025_17_ptr[1])) == 61)) && (((int)(__22025_17_ptr[2])) == 39)) {

__22025_17_ptr += 3;
__22031_17_fill_in_override = __22025_17_ptr;
while ((((int)(*__22025_17_ptr)) != 39) && (((int)(*__22025_17_ptr)) != 0)) { __22025_17_ptr++; }

(*((char *)__22025_17_ptr)) = ((char)0);
__22025_17_ptr++;
}
if (__22031_17_fill_in_override != ((_ZN3edg12a_const_charE *)0)) {
output_doc_string(__22031_17_fill_in_override, 0, fk_normal);
} else  {
__22030_10_fis_ptr = (__22029_9_fill_in_specifier);
__22027_9_ch = (*(__22030_10_fis_ptr++));
switch ((int)__22027_9_ch) {
case 115:
if (((int)(*__22030_10_fis_ptr)) == 113) {
__22028_17_fill_in = ((const char *)"\"xxxx\"");
__22030_10_fis_ptr++;
} else  {
__22028_17_fill_in = ((const char *)"xxxx");
}
output_doc_string(__22028_17_fill_in, 0, fk_em);
goto __T137675704;
case 116:
output_doc_string(((const char *)"\"type\""), 0, fk_em);
goto __T137675704;
case 109:
output_doc_string(((const char *)"module \"module name\""), 0, fk_em);
goto __T137675704;
case 84:
output_doc_string(((const char *)"\"<templ-args>\""), 0, fk_em);
goto __T137675704;
case 112:
__22028_17_fill_in = ((const char *)"at line {\\em xxxx\\/}");
output_doc_string(((const char *)"at line "), 0, fk_normal);
output_doc_string(((const char *)"xxxx"), 0, fk_em);
goto __T137675704;
case 37:
output_doc_string(((const char *)"%"), 0, fk_normal);
goto __T137675704;
case 110:
{
auto _ZN3edg9a_booleanE __22101_21_name_only = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __22102_21_template_args = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __22103_21_decl_pos = ((_ZN3edg9a_booleanE)0);
while (((int)((_ctype)[((unsigned char)((unsigned char)(*__22030_10_fis_ptr)))])) & 0x7) {
__22027_9_ch = (*(__22030_10_fis_ptr++));
switch ((int)__22027_9_ch) {
case 102: goto __T137699872;
case 111: __22101_21_name_only = ((_ZN3edg9a_booleanE)1); goto __T137699872;
case 97: __22102_21_template_args = ((_ZN3edg9a_booleanE)1); goto __T137699872;
case 100: __22103_21_decl_pos = ((_ZN3edg9a_booleanE)1); goto __T137699872;
case 117: __22103_21_decl_pos = ((_ZN3edg9a_booleanE)1); goto __T137699872;
case 116: goto __T137699872;
case 84: goto __T137699872;
case 112: goto __T137699872;
case 49: goto __T137699872;
case 50: goto __T137699872;
default: _ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"unexpected symbol fill-in %s\n"), ((_ZN3edg12a_const_charE *)(__22030_10_fis_ptr - 1)));
} __T137699872:;
}
if (!(__22101_21_name_only)) { output_doc_string(((const char *)"entity-kind "), 0, fk_em); }
output_doc_string(((const char *)"\"entity\""), 0, fk_em);
if (__22102_21_template_args) { output_doc_string(((const char *)"<args>"), 0, fk_em); }
if (__22103_21_decl_pos) {
output_doc_string(((const char *)" (declared at line "), 0, fk_normal);
output_doc_string(((const char *)"xxxx"), 0, fk_em);
output_doc_string(((const char *)")"), 0, fk_normal);
}
}
goto __T137675704;
case 91:

while (((int)(*__22030_10_fis_ptr)) != 0) {
if (((int)(*__22030_10_fis_ptr)) == 93) { goto __T137725712; } else  {
output_doc_string(((_ZN3edg12a_const_charE *)__22030_10_fis_ptr), 1, curr_font); }
__22030_10_fis_ptr++;
} __T137725712:;
if (((int)(*__22030_10_fis_ptr)) != 93) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"unterminated label fill-in: %s"), __22026_17_orig_ptr);
}
goto __T137675704;
case 100:
case 117:
output_doc_string(((const char *)"n"), 0, fk_em);
goto __T137675704;
case 114:
output_doc_string(((const char *)"reflection-description"), 0, fk_em);
goto __T137675704;
default:
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"unexpected message fill-in: %s"), __22026_17_orig_ptr);
} __T137675704:;
}
(*__22021_49_ptr_to_ptr) = __22025_17_ptr; 
}
#line 929
static void _ZN30_INTERNAL_12_mk_errinfo_c_main19me_write_error_textEv(void)



{
auto int __22170_7_i;

fprintf(data_output_file, ((const char *)"static %s *message_text[(int)ec_last + 1] = {\n"), char_type);

for (__22170_7_i = 0; __22170_7_i < number_of_errors; ++__22170_7_i) {
auto _ZN3edg12a_const_charE *__22175_19_ptr;

if (__22170_7_i != 0) { fprintf(data_output_file, ((const char *)",\n")); }
fprintf(data_output_file, ((const char *)"  /* %s */\n"), (((error_info)[__22170_7_i]).enumerator));
putc(32, data_output_file);
putc(32, data_output_file);
__22175_19_ptr = (((error_info)[__22170_7_i]).text);
if (__22175_19_ptr == ((_ZN3edg12a_const_charE *)0)) {

fprintf(data_output_file, ((const char *)"(%s *)NULL"), char_type);
} else  {
for (; ((int)(*__22175_19_ptr)) != 0; ++__22175_19_ptr) { {
auto char __22187_14_ch; __22187_14_ch = (*__22175_19_ptr);
if ((((int)__22187_14_ch) == 92) && (((int)(__22175_19_ptr[1])) == 61)) {


__22175_19_ptr += 3;
while ((((int)(*__22175_19_ptr)) != 39) && (((int)(*__22175_19_ptr)) != 0)) { __22175_19_ptr++; }
goto __T137756944;
}
putc(((int)__22187_14_ch), data_output_file);
} __T137756944:; }
}
}
fprintf(data_output_file, ((const char *)"\n};\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main18me_write_tag_tableEv(void)



{
auto int __22208_7_i;

fprintf(data_output_file, ((const char *)"#define NUMBER_OF_ERROR_TAGS %0d\n"), number_of_tags);


fprintf(data_output_file, ((const char *)"static an_error_tag_entry error_tags[NUMBER_OF_ERROR_TAGS]\n"));

fprintf(data_output_file, ((const char *)"#ifndef _lint\n= {\n"));
for (__22208_7_i = 0; __22208_7_i < number_of_tags; ++__22208_7_i) {

if (__22208_7_i != 0) { fprintf(data_output_file, ((const char *)",\n")); }
fprintf(data_output_file, ((const char *)"  { \"%s\", %s }"), (((tag_info)[__22208_7_i]).tag), (((tag_info)[__22208_7_i]).enumerator));

}
fprintf(data_output_file, ((const char *)"\n}\n"));
fprintf(data_output_file, ((const char *)"#else /* ifdef _lint */\n"));
fprintf(data_output_file, ((const char *)"/*lint -esym(728,*error_tags)*/\n"));
fprintf(data_output_file, ((const char *)"#endif /* ifndef _lint */\n"));
fprintf(data_output_file, ((const char *)";\n")); 
}
#line 1003
static void _ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_latex_item_headerEiPKc( int __22239_53_number, 
_ZN3edg12a_const_charE *__22240_40_tag)




{
auto _ZN3edg12a_const_charE *__22246_17_ptr;


fprintf(doc_output_file, ((const char *)"\\item[\\tt %04d "), __22239_53_number);

__22246_17_ptr = __22240_40_tag;
while (((int)(*__22246_17_ptr)) != 0) {
if (((int)(*__22246_17_ptr)) == 95) { putc(92, doc_output_file); }
putc(((int)(*__22246_17_ptr)), doc_output_file);
__22246_17_ptr++;
}

fprintf(doc_output_file, ((const char *)":]\n"));

fprintf(doc_output_file, ((const char *)"\\item[]\n"));

fprintf(doc_output_file, ((const char *)"\\parskip 0pt\n\\itemsep 0pt\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKc( int __22266_51_number, 
_ZN3edg12a_const_charE *__22267_38_tag)




{
auto _ZN3edg12a_const_charE *__22273_18_ptr;


if (_ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first) {
_ZZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKcE5first = ((_ZN3edg9a_booleanE)0);
} else  {

fprintf(doc_output_file, ((const char *)"\n"));
}

fprintf(doc_output_file, ((const char *)"<ErrorItem>\n"));

fprintf(doc_output_file, ((const char *)"<tt>%04d<tab>"), __22266_51_number);

__22273_18_ptr = __22267_38_tag;
while (((int)(*__22273_18_ptr)) != 0) {
putc(((int)(*__22273_18_ptr)), doc_output_file);
__22273_18_ptr++;
}

fprintf(doc_output_file, ((const char *)":\n\n"));

fprintf(doc_output_file, ((const char *)"<ErrorText>\n")); 
}


static void _ZN30_INTERNAL_12_mk_errinfo_c_main17me_write_doc_fileEv(void)



{
auto int __22304_7_i;


for (__22304_7_i = 1; __22304_7_i < number_of_errors; ++__22304_7_i) { {
auto _ZN3edg12a_const_charE *__22308_19_ptr;

if ((((error_info)[__22304_7_i]).text) == ((_ZN3edg12a_const_charE *)0)) { goto __T137798088; }

if ((((error_info)[__22304_7_i]).tag) == ((_ZN3edg12a_const_charE *)0)) { goto __T137798088; }

curr_font = fk_normal;
write_item_header(__22304_7_i, (((error_info)[__22304_7_i]).tag));


__22308_19_ptr = (((error_info)[__22304_7_i]).text);
++__22308_19_ptr;
for (; ; ) {
auto char __22321_12_ch; __22321_12_ch = (*__22308_19_ptr);
if (((int)__22321_12_ch) == 37) {
++__22308_19_ptr;
_ZN30_INTERNAL_12_mk_errinfo_c_main20me_create_doc_fillinEPPKc((&__22308_19_ptr));
} else  {

if (((int)__22321_12_ch) == 34) { goto __T137806960; }
if (((int)__22321_12_ch) == 92) { ++__22308_19_ptr; }

output_doc_string(__22308_19_ptr, 1, fk_normal);
++__22308_19_ptr;
}
} __T137806960:;
output_doc_string(((const char *)"\n"), 0, fk_normal);
} __T137798088:; } 
}


int main( int __22339_14_argc,  char **__22339_26_argv)
{
auto int __22341_8_argpos = 1;
auto _ZN3edg9a_booleanE __22342_13_doc_mode = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __22343_13_rst_doc = ((_ZN3edg9a_booleanE)0);

if (__22339_14_argc < 5) { _ZN30_INTERNAL_12_mk_errinfo_c_main21me_command_line_errorEv(); }
if ((strcmp(((const char *)(__22339_26_argv[__22341_8_argpos])), ((const char *)"-d"))) == 0) {

__22342_13_doc_mode = ((_ZN3edg9a_booleanE)1);
output_doc_string = (&_ZN30_INTERNAL_12_mk_errinfo_c_main26me_output_latex_doc_stringEPKci11a_font_kind);
write_item_header = (&_ZN30_INTERNAL_12_mk_errinfo_c_main26me_write_latex_item_headerEiPKc);
__22341_8_argpos++;
} else  { if ((strcmp(((const char *)(__22339_26_argv[__22341_8_argpos])), ((const char *)"-rst"))) == 0) {

__22342_13_doc_mode = ((_ZN3edg9a_booleanE)1);
__22343_13_rst_doc = ((_ZN3edg9a_booleanE)1);
output_doc_string = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_rst_doc_stringEPKci11a_font_kind);
write_item_header = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_rst_item_headerEiPKc);
__22341_8_argpos++;
} else  { if ((strcmp(((const char *)(__22339_26_argv[__22341_8_argpos])), ((const char *)"-mml"))) == 0) {

__22342_13_doc_mode = ((_ZN3edg9a_booleanE)1);
output_doc_string = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_output_mml_doc_stringEPKci11a_font_kind);
write_item_header = (&_ZN30_INTERNAL_12_mk_errinfo_c_main24me_write_mml_item_headerEiPKc);
__22341_8_argpos++;
} else  { if ((strcmp(((const char *)(__22339_26_argv[__22341_8_argpos])), ((const char *)"-cch"))) == 0) {


char_type = ((const char *)"const char");
__22341_8_argpos++;
} } } }
message_input_file_name = (__22339_26_argv[(__22341_8_argpos++)]);
tag_input_file_name = (__22339_26_argv[(__22341_8_argpos++)]);
if (__22342_13_doc_mode) {
doc_output_file_name = (__22339_26_argv[(__22341_8_argpos++)]);
} else  {
codes_output_file_name = (__22339_26_argv[(__22341_8_argpos++)]);
data_output_file_name = (__22339_26_argv[(__22341_8_argpos++)]);
}
if (__22341_8_argpos != __22339_14_argc) {
_ZN30_INTERNAL_12_mk_errinfo_c_main21me_command_line_errorEv();
}

message_input_file = (fopen(((const char *)message_input_file_name), ((const char *)"r")));
if (message_input_file == ((FILE *)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"cannot open %s"), ((_ZN3edg12a_const_charE *)message_input_file_name));
}
if (__22342_13_doc_mode) {

doc_output_file = (fopen(((const char *)doc_output_file_name), ((const char *)"w")));
if (doc_output_file == ((FILE *)0)) {
_ZN30_INTERNAL_12_mk_errinfo_c_main8me_errorEPKcS1_(((const char *)"cannot open %s"), ((_ZN3edg12a_const_charE *)doc_output_file_name));
}
if (__22343_13_rst_doc) {
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
if (__22342_13_doc_mode) {

_ZN30_INTERNAL_12_mk_errinfo_c_main17me_write_doc_fileEv();
fclose(doc_output_file);
} else  {

_ZN30_INTERNAL_12_mk_errinfo_c_main20me_write_error_codesEv();

_ZN30_INTERNAL_12_mk_errinfo_c_main19me_write_error_textEv();


qsort(((void *)(&error_info)), ((_ZN3edg16qsort_nmemb_typeE)number_of_errors), 24ULL, (&_ZN30_INTERNAL_12_mk_errinfo_c_main18compare_error_infoEPKvS1_));


_ZN30_INTERNAL_12_mk_errinfo_c_main16me_read_tag_fileEv();

qsort(((void *)(&tag_info)), ((_ZN3edg16qsort_nmemb_typeE)number_of_tags), 16ULL, (&_ZN30_INTERNAL_12_mk_errinfo_c_main16compare_tag_infoEPKvS1_));


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
