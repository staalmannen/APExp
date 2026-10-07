/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:53 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "util/edg_munch.c"
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
# 53 "util/edg_munch.c"
struct a_list_entry;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 51 "util/edg_munch.c"
typedef struct a_list_entry *a_list_entry_ptr;

struct a_list_entry {
a_list_entry_ptr next;
char *name;};
# 219 "src/basics.h"
typedef int _ZN3edg9a_booleanE;
# 499
typedef void *_ZN3edg10a_void_ptrE;
# 515
typedef const char _ZN3edg12a_const_charE;
# 541
typedef size_t _ZN3edg8sizeof_tE;
# 357 "/usr/include/stdio.h" 3
extern int fprintf(FILE *__stream, const char *__format, ...);
# 363
extern int printf(const char *__format, ...);
# 582
extern int getchar(void);
# 105 "/usr/include/stdlib.h" 3
extern __attribute__((__pure__)) __attribute__((__nothrow__)) int atoi(const char *__nptr);
# 672
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 756
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void exit(int __status);
# 144 "/usr/include/string.h" 3
extern __attribute__((__nothrow__)) char *strncpy(char *__dest, const char *__src, size_t __n);
# 159
extern __attribute__((__pure__)) __attribute__((__nothrow__)) int strncmp(const char *__s1, const char *__s2, size_t __n);
# 226
extern __attribute__((__pure__)) __attribute__((__nothrow__)) char *_Z6strchrPci(char *__s, int __c) __asm__("strchr");
# 407
extern __attribute__((__pure__)) __attribute__((__nothrow__)) size_t strlen(const char *__s);
# 109 "/usr/include/ctype.h" 3
extern __attribute__((__nothrow__)) int isalpha(int);
# 57 "util/getopt.h"
extern int _Z6getoptiPKPcPKc(int argc, char *const *argv, const char *optstring);
# 81 "util/edg_munch.c"
static void _ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(_ZN3edg12a_const_charE *error_string);
# 91
static void _ZN31_INTERNAL_11_edg_munch_c_optind19internal_error_utilEPKc(_ZN3edg12a_const_charE *error_string);
# 102
static _ZN3edg10a_void_ptrE _ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEm(_ZN3edg8sizeof_tE size);
# 117
static int _ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv(void);
# 149
static int _ZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_(char **name_pos, int *name_length, _ZN3edg9a_booleanE *is_ctor);
# 237
static void _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc(a_list_entry_ptr list_ptr, _ZN3edg12a_const_charE *array_name);
# 267
extern int main(int argc, char **argv);
# 151 "/usr/include/stdio.h" 3
extern FILE *stderr;
# 45 "util/getopt.h"
char *optarg = 0;


extern int optind;

extern int opterr;
# 76
static char *_ZZ6getoptiPKPcPKcE7optchar;
# 63 "util/edg_munch.c"
static char input_line_buffer[32767];
static int line_size;
# 70
static _ZN3edg9a_booleanE skip_underscore_prefix;
# 165
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18ctor_prefix_length;
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18dtor_prefix_length;
# 48 "util/getopt.h"
int optind = 1;

int opterr = 1;
# 76
static char *_ZZ6getoptiPKPcPKcE7optchar = ((char *)0);
# 70 "util/edg_munch.c"
static _ZN3edg9a_booleanE skip_underscore_prefix = 0;
# 165
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18ctor_prefix_length = 0UL;
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18dtor_prefix_length = 0UL;
# 57 "util/getopt.h"
int _Z6getoptiPKPcPKc( int __35356_16_argc,  char *const *__35356_37_argv,  const char *__35356_55_optstring)
# 73
{
auto int __35373_15_return_value;
auto char *__35374_16_optpos;
# 83
if (_ZZ6getoptiPKPcPKcE7optchar == ((char *)0)) {
__35383_1_start_new_argument:;
if (optind >= __35356_16_argc) {

__35373_15_return_value = (-1);
goto __35461_1_end_of_routine;
} else  {
_ZZ6getoptiPKPcPKcE7optchar = (__35356_37_argv[optind]);
if (((int)(*_ZZ6getoptiPKPcPKcE7optchar)) != 45) {

__35373_15_return_value = (-1);
goto __35461_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 1))) == 45) {
if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 2))) == 0) {


optind++;
__35373_15_return_value = (-1);
} else  {

__35373_15_return_value = 63;
}
goto __35461_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 1))) == 0) {


__35373_15_return_value = (-1);
goto __35461_1_end_of_routine;
} } }

_ZZ6getoptiPKPcPKcE7optchar++;
}
}


if (((int)(*_ZZ6getoptiPKPcPKcE7optchar)) == 0) {

optind++;
goto __35383_1_start_new_argument;
}

__35374_16_optpos = (_Z6strchrPci(((char *)__35356_55_optstring), ((int)(*_ZZ6getoptiPKPcPKcE7optchar))));
if (__35374_16_optpos == ((char *)0)) {

if (opterr) { fprintf(stderr, ((const char *)"%s: illegal option -- %c\n"), (__35356_37_argv[0]), ((int)(*_ZZ6getoptiPKPcPKcE7optchar))); }

__35373_15_return_value = 63;
goto __35461_1_end_of_routine;
}

__35373_15_return_value = ((int)(*_ZZ6getoptiPKPcPKcE7optchar));

if (((int)(*(__35374_16_optpos + 1))) == 58) {
if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 1))) == 0) {


optind++;
if (optind >= __35356_16_argc) {


if (opterr) { fprintf(stderr, ((const char *)"%s: option requires an argument -- %c\n"), (__35356_37_argv[0]), ((int)(*_ZZ6getoptiPKPcPKcE7optchar))); }

__35373_15_return_value = 63;
goto __35461_1_end_of_routine;
}
optarg = (__35356_37_argv[optind]);
} else  {


optarg = (_ZZ6getoptiPKPcPKcE7optchar + 1);
}

_ZZ6getoptiPKPcPKcE7optchar = ((char *)0);
optind++;
} else  {

_ZZ6getoptiPKPcPKcE7optchar++;
optarg = ((char *)0);
}
__35461_1_end_of_routine:;
return __35373_15_return_value;
}
# 81 "util/edg_munch.c"
static void _ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc( _ZN3edg12a_const_charE *__35499_38_error_string)



{
fprintf(stderr, ((const char *)"edg_munch: %s\n"), __35499_38_error_string);
exit(2); 
}


static void _ZN31_INTERNAL_11_edg_munch_c_optind19internal_error_utilEPKc( _ZN3edg12a_const_charE *__35509_47_error_string)




{
fprintf(stderr, ((const char *)"edg_munch: %s\n"), __35509_47_error_string);
exit(4); 
}


static _ZN3edg10a_void_ptrE _ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEm( _ZN3edg8sizeof_tE __35520_46_size)




{
auto _ZN3edg10a_void_ptrE __35526_14_ptr;

if ((__35526_14_ptr = ((_ZN3edg10a_void_ptrE)(malloc(__35520_46_size)))) == ((_ZN3edg10a_void_ptrE)0)) {
_ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(((const char *)"out of memory"));
}
return __35526_14_ptr;
}


static int _ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv(void)
# 123
{
auto char *__35542_10_buffer_pos = input_line_buffer;
auto int __35543_10_size = 0;
auto int __35544_10_ch;
auto int __35545_10_result;

while ((__35544_10_ch = (getchar())) , ((__35544_10_ch != (-1)) && (__35544_10_ch != 10))) {
if ((++__35543_10_size) > 32767) {
_ZN31_INTERNAL_11_edg_munch_c_optind19internal_error_utilEPKc(((const char *)"read_input_line: input line too long."));
}
(*(__35542_10_buffer_pos++)) = ((char)__35544_10_ch);
}


(*(__35542_10_buffer_pos++)) = ((char)0);


__35545_10_result = 1;
if ((__35544_10_ch == (-1)) && (__35543_10_size == 0)) { __35545_10_result = 0; }


line_size = __35543_10_size;
return __35545_10_result;
}


static int _ZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_( char **__35567_46_name_pos, 
int *__35568_47_name_length, 
_ZN3edg9a_booleanE *__35569_47_is_ctor)
# 159
{
auto int __35578_19_result = 0;
auto char *__35579_19_pos = input_line_buffer;
auto char __35580_19_ch;
auto char *__35581_19_local_name_pos;
auto char __35582_19_type;




if (_ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18ctor_prefix_length == 0UL) {
_ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18ctor_prefix_length = 7UL;
_ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18dtor_prefix_length = 7UL;
}


if (line_size < 12) { goto __35647_1_invalid_input; }



while ((__35580_19_ch = (*__35579_19_pos)) , ((((int)__35580_19_ch) != 32) && (((int)__35580_19_ch) != 0))) { __35579_19_pos++; }


if (((int)(*(__35579_19_pos++))) != 32) { goto __35647_1_invalid_input; }


while (((int)(*__35579_19_pos)) == 32) { __35579_19_pos++; }


__35582_19_type = (*(__35579_19_pos++));
if (!(isalpha(((int)((unsigned char)__35582_19_type))))) { goto __35647_1_invalid_input; }


if (((int)(*(__35579_19_pos++))) != 32) { goto __35647_1_invalid_input; }


while (((int)(*__35579_19_pos)) == 32) { __35579_19_pos++; }



if ((skip_underscore_prefix) && (((int)(*__35579_19_pos)) == 95)) { __35579_19_pos++; }


__35581_19_local_name_pos = __35579_19_pos;


if (((int)__35582_19_type) == 84) {


if ((strncmp(((const char *)__35579_19_pos), ((const char *)"__sti__"), _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18ctor_prefix_length)) == 0) {
__35578_19_result = 1;
(*__35569_47_is_ctor) = 1;
} else  { if ((strncmp(((const char *)__35579_19_pos), ((const char *)"__std__"), _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_E18dtor_prefix_length)) == 0) {
__35578_19_result = 1;
(*__35569_47_is_ctor) = 0;
} }


if (__35578_19_result) {

auto int __35637_11_length = 0;
while ((__35580_19_ch = (*(__35579_19_pos++))) , (((((int)__35580_19_ch) != 32) && (((int)__35580_19_ch) != 9)) && (((int)__35580_19_ch) != 0))) { ++__35637_11_length; }
(*__35568_47_name_length) = __35637_11_length;

(*__35567_46_name_pos) = __35581_19_local_name_pos;
}
}

return __35578_19_result;

__35647_1_invalid_input:;
_ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(((const char *)"invalid input format"));

return 0;
}



static void _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc( a_list_entry_ptr __35655_44_list_ptr, 
_ZN3edg12a_const_charE *__35656_45_array_name)



{
auto a_list_entry_ptr __35661_23_entry;


__35661_23_entry = __35655_44_list_ptr;
while (__35661_23_entry) {
printf(((const char *)"%s %s();\n"), ((const char *)("void")), (__35661_23_entry->name));
__35661_23_entry = (__35661_23_entry->next);
}
printf(((const char *)"\n"));


printf(((const char *)"%s %s[] = {\n"), ((const char *)("func_ptr")), __35656_45_array_name);
__35661_23_entry = __35655_44_list_ptr;
while (__35661_23_entry) {
printf(((const char *)"\t%s,\n"), (__35661_23_entry->name));
__35661_23_entry = (__35661_23_entry->next);
}


printf(((const char *)"\t0\n};\n")); 
}



int main( int __35685_14_argc,  char **__35685_26_argv)
{
auto a_list_entry_ptr __35687_24_ctor_list = ((a_list_entry_ptr)0);
auto a_list_entry_ptr __35688_24_dtor_list = ((a_list_entry_ptr)0);
auto a_list_entry_ptr __35689_24_entry;
auto a_list_entry_ptr __35690_24_last_entry = ((a_list_entry_ptr)0);
auto char *__35691_24_name_pos;
auto char *__35692_24_name_string;
auto int __35693_24_name_length;
auto _ZN3edg9a_booleanE __35694_24_is_ctor;
auto int __35695_15_optchar;
auto int __35696_15_lines_to_skip = 0;



opterr = 0;

while ((__35695_15_optchar = (_Z6getoptiPKPcPKc(__35685_14_argc, ((char *const *)__35685_26_argv), ((const char *)"ui:")))) != (-1)) {
switch (__35695_15_optchar) {
case 105:



__35696_15_lines_to_skip = (atoi(((const char *)optarg)));
goto __T212963408;
case 117:


skip_underscore_prefix = 1;
goto __T212963408;
default:
if (optind >= __35685_14_argc) { optind = (__35685_14_argc - 1); }
optarg = (__35685_26_argv[optind]);
fprintf(stderr, ((const char *)"Unrecognized option: %s\n"), optarg);
_ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(((const char *)"command line error"));
goto __T212963408;
} __T212963408:;
}

for (; __35696_15_lines_to_skip > 0; __35696_15_lines_to_skip--) { _ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv(); }
while (_ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv()) {

if (line_size == 0) { goto __T212972432; }
if (_ZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiS2_((&__35691_24_name_pos), (&__35693_24_name_length), (&__35694_24_is_ctor))) {


if (((__35690_24_last_entry != ((a_list_entry_ptr)0)) && (__35693_24_name_length == ((int)(strlen(((const char *)(__35690_24_last_entry->name))))))) && ((strncmp(((const char *)(__35690_24_last_entry->name)), ((const char *)__35691_24_name_pos), ((size_t)__35693_24_name_length))) == 0)) {

goto __T212972432; }

__35692_24_name_string = ((char *)(_ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEm(((size_t)(__35693_24_name_length + 1)))));
strncpy(__35692_24_name_string, ((const char *)__35691_24_name_pos), ((size_t)__35693_24_name_length));

(__35692_24_name_string[__35693_24_name_length]) = ((char)0);

__35689_24_entry = ((a_list_entry_ptr)(_ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEm(16UL)));
(__35689_24_entry->name) = __35692_24_name_string;
(__35689_24_entry->next) = ((a_list_entry_ptr)0);
__35690_24_last_entry = __35689_24_entry;



if (__35694_24_is_ctor) {

(__35689_24_entry->next) = __35687_24_ctor_list;
__35687_24_ctor_list = __35689_24_entry;
} else  {

(__35689_24_entry->next) = __35688_24_dtor_list;
__35688_24_dtor_list = __35689_24_entry;
}
} __T212972432:;
}
# 351
printf(((const char *)"typedef %s (*%s)();\n"), ((const char *)("void")), ((const char *)("func_ptr")));



if (__35687_24_ctor_list) { _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc(__35687_24_ctor_list, ((const char *)"_ctors")); }
printf(((const char *)"\n"));


if (__35688_24_dtor_list) { _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc(__35688_24_dtor_list, ((const char *)"_dtors")); }

return 0;
}
