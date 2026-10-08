/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:16 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "util/edg_munch.c"
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
#line 28 "ape-sys/ctype.h"
enum _ZN31_INTERNAL_11_edg_munch_c_optindUt_E {
_ISupper = 0x1,
_ISlower = 0x2,
_ISdigit = 0x4,
_ISspace = 0x8,
_ISpunct = 0x10,
_IScntrl = 0x20,
_ISblank = 0x40,
_ISxdigit = 0x80};
#line 53 "util/edg_munch.c"
struct a_list_entry;
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 51 "util/edg_munch.c"
typedef struct a_list_entry *a_list_entry_ptr;

struct a_list_entry {
a_list_entry_ptr next;
char *name;};
#line 214 "src/basics.h"
typedef _Bool _ZN3edg9a_booleanE;
#line 499
typedef void *_ZN3edg10a_void_ptrE;
#line 515
typedef const char _ZN3edg12a_const_charE;
#line 541
typedef size_t _ZN3edg8sizeof_tE;
#line 71 "ape-sys/stdio.h"
extern int fprintf(FILE *, const char *, ...);

extern int printf(const char *, ...);
#line 87
extern int getc(FILE *);
#line 42 "ape-sys/stdlib.h"
extern int atoi(const char *);
#line 67
extern void *malloc(size_t);



extern void exit(int);
#line 15 "ape-sys/string.h"
extern char *strncpy(char *, const char *, size_t);
#line 24
extern int strncmp(const char *, const char *, size_t);


extern char *strchr(const char *, int);
#line 36
extern size_t strlen(const char *);
#line 57 "util/getopt.h"
extern int getopt(int argc, char *const *argv, const char *optstring);
#line 81 "util/edg_munch.c"
static void _ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(_ZN3edg12a_const_charE *error_string);
#line 91
static void _ZN31_INTERNAL_11_edg_munch_c_optind19internal_error_utilEPKc(_ZN3edg12a_const_charE *error_string);
#line 102
static _ZN3edg10a_void_ptrE _ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEy(_ZN3edg8sizeof_tE size);
#line 117
static int _ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv(void);
#line 149
static int _ZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPb(char **name_pos, int *name_length, _ZN3edg9a_booleanE *is_ctor);
#line 237
static void _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc(a_list_entry_ptr list_ptr, _ZN3edg12a_const_charE *array_name);
#line 267
extern int main(int argc, char **argv);
#line 51 "ape-sys/stdio.h"
extern FILE *stdin;

extern FILE *stderr;
#line 39 "ape-sys/ctype.h"
extern unsigned char _ctype[];
#line 45 "util/getopt.h"
char *optarg = 0;


extern int optind;

extern int opterr;
#line 76
static char *_ZZ6getoptE7optchar;
#line 63 "util/edg_munch.c"
static char input_line_buffer[32767];
static int line_size;
#line 70
static _ZN3edg9a_booleanE skip_underscore_prefix;
#line 165
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18ctor_prefix_length;
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18dtor_prefix_length;
#line 48 "util/getopt.h"
int optind = 1;

int opterr = 1;
#line 76
static char *_ZZ6getoptE7optchar = ((char *)0);
#line 70 "util/edg_munch.c"
static _ZN3edg9a_booleanE skip_underscore_prefix = ((_ZN3edg9a_booleanE)0);
#line 165
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18ctor_prefix_length = 0ULL;
static _ZN3edg8sizeof_tE _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18dtor_prefix_length = 0ULL;
#line 57 "util/getopt.h"
int getopt( int __27533_16_argc,  char *const *__27533_37_argv,  const char *__27533_55_optstring)
#line 73
{
auto int __27550_15_return_value;
auto char *__27551_16_optpos;
#line 83
if (_ZZ6getoptE7optchar == ((char *)0)) {
__27560_1_start_new_argument:;
if (optind >= __27533_16_argc) {

__27550_15_return_value = (-1);
goto __27638_1_end_of_routine;
} else  {
_ZZ6getoptE7optchar = (__27533_37_argv[optind]);
if (((int)(*_ZZ6getoptE7optchar)) != 45) {

__27550_15_return_value = (-1);
goto __27638_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 45) {
if (((int)(*(_ZZ6getoptE7optchar + 2))) == 0) {


optind++;
__27550_15_return_value = (-1);
} else  {

__27550_15_return_value = 63;
}
goto __27638_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


__27550_15_return_value = (-1);
goto __27638_1_end_of_routine;
} } }

_ZZ6getoptE7optchar++;
}
}


if (((int)(*_ZZ6getoptE7optchar)) == 0) {

optind++;
goto __27560_1_start_new_argument;
}

__27551_16_optpos = (strchr(((const char *)((char *)__27533_55_optstring)), ((int)(*_ZZ6getoptE7optchar))));
if (__27551_16_optpos == ((char *)0)) {

if (opterr) { fprintf(stderr, ((const char *)"%s: illegal option -- %c\n"), (__27533_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27550_15_return_value = 63;
goto __27638_1_end_of_routine;
}

__27550_15_return_value = ((int)(*_ZZ6getoptE7optchar));

if (((int)(*(__27551_16_optpos + 1))) == 58) {
if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


optind++;
if (optind >= __27533_16_argc) {


if (opterr) { fprintf(stderr, ((const char *)"%s: option requires an argument -- %c\n"), (__27533_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27550_15_return_value = 63;
goto __27638_1_end_of_routine;
}
optarg = (__27533_37_argv[optind]);
} else  {


optarg = (_ZZ6getoptE7optchar + 1);
}

_ZZ6getoptE7optchar = ((char *)0);
optind++;
} else  {

_ZZ6getoptE7optchar++;
optarg = ((char *)0);
}
__27638_1_end_of_routine:;
return __27550_15_return_value;
}
#line 81 "util/edg_munch.c"
static void _ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc( _ZN3edg12a_const_charE *__27676_38_error_string)



{
fprintf(stderr, ((const char *)"edg_munch: %s\n"), __27676_38_error_string);
exit(2); 
}


static void _ZN31_INTERNAL_11_edg_munch_c_optind19internal_error_utilEPKc( _ZN3edg12a_const_charE *__27686_47_error_string)




{
fprintf(stderr, ((const char *)"edg_munch: %s\n"), __27686_47_error_string);
exit(4); 
}


static _ZN3edg10a_void_ptrE _ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEy( _ZN3edg8sizeof_tE __27697_46_size)




{
auto _ZN3edg10a_void_ptrE __27703_14_ptr;

if ((__27703_14_ptr = ((_ZN3edg10a_void_ptrE)(malloc(__27697_46_size)))) == ((_ZN3edg10a_void_ptrE)0)) {
_ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(((const char *)"out of memory"));
}
return __27703_14_ptr;
}


static int _ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv(void)
#line 123
{
auto char *__27719_10_buffer_pos = input_line_buffer;
auto int __27720_10_size = 0;
auto int __27721_10_ch;
auto int __27722_10_result;

while ((__27721_10_ch = (getc(stdin))) , ((__27721_10_ch != (-1)) && (__27721_10_ch != 10))) {
if ((++__27720_10_size) > 32767) {
_ZN31_INTERNAL_11_edg_munch_c_optind19internal_error_utilEPKc(((const char *)"read_input_line: input line too long."));
}
(*(__27719_10_buffer_pos++)) = ((char)__27721_10_ch);
}


(*(__27719_10_buffer_pos++)) = ((char)0);


__27722_10_result = 1;
if ((__27721_10_ch == (-1)) && (__27720_10_size == 0)) { __27722_10_result = 0; }


line_size = __27720_10_size;
return __27722_10_result;
}


static int _ZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPb( char **__27744_46_name_pos, 
int *__27745_47_name_length, 
_ZN3edg9a_booleanE *__27746_47_is_ctor)
#line 159
{
auto int __27755_19_result = 0;
auto char *__27756_19_pos = input_line_buffer;
auto char __27757_19_ch;
auto char *__27758_19_local_name_pos;
auto char __27759_19_type;




if (_ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18ctor_prefix_length == 0ULL) {
_ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18ctor_prefix_length = 7ULL;
_ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18dtor_prefix_length = 7ULL;
}


if (line_size < 12) { goto __27824_1_invalid_input; }



while ((__27757_19_ch = (*__27756_19_pos)) , ((((int)__27757_19_ch) != 32) && (((int)__27757_19_ch) != 0))) { __27756_19_pos++; }


if (((int)(*(__27756_19_pos++))) != 32) { goto __27824_1_invalid_input; }


while (((int)(*__27756_19_pos)) == 32) { __27756_19_pos++; }


__27759_19_type = (*(__27756_19_pos++));
if (!(((int)((_ctype)[((unsigned char)((unsigned char)__27759_19_type))])) & 0x3)) { goto __27824_1_invalid_input; }


if (((int)(*(__27756_19_pos++))) != 32) { goto __27824_1_invalid_input; }


while (((int)(*__27756_19_pos)) == 32) { __27756_19_pos++; }



if ((skip_underscore_prefix) && (((int)(*__27756_19_pos)) == 95)) { __27756_19_pos++; }


__27758_19_local_name_pos = __27756_19_pos;


if (((int)__27759_19_type) == 84) {


if ((strncmp(((const char *)__27756_19_pos), ((const char *)"__sti__"), _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18ctor_prefix_length)) == 0) {
__27755_19_result = 1;
(*__27746_47_is_ctor) = ((_ZN3edg9a_booleanE)1);
} else  { if ((strncmp(((const char *)__27756_19_pos), ((const char *)"__std__"), _ZZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPbE18dtor_prefix_length)) == 0) {
__27755_19_result = 1;
(*__27746_47_is_ctor) = ((_ZN3edg9a_booleanE)0);
} }


if (__27755_19_result) {

auto int __27814_11_length = 0;
while ((__27757_19_ch = (*(__27756_19_pos++))) , (((((int)__27757_19_ch) != 32) && (((int)__27757_19_ch) != 9)) && (((int)__27757_19_ch) != 0))) { ++__27814_11_length; }
(*__27745_47_name_length) = __27814_11_length;

(*__27744_46_name_pos) = __27758_19_local_name_pos;
}
}

return __27755_19_result;

__27824_1_invalid_input:;
_ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(((const char *)"invalid input format"));

return 0;
}



static void _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc( a_list_entry_ptr __27832_44_list_ptr, 
_ZN3edg12a_const_charE *__27833_45_array_name)



{
auto a_list_entry_ptr __27838_23_entry;


__27838_23_entry = __27832_44_list_ptr;
while (__27838_23_entry) {
printf(((const char *)"%s %s();\n"), ((const char *)("void")), (__27838_23_entry->name));
__27838_23_entry = (__27838_23_entry->next);
}
printf(((const char *)"\n"));


printf(((const char *)"%s %s[] = {\n"), ((const char *)("func_ptr")), __27833_45_array_name);
__27838_23_entry = __27832_44_list_ptr;
while (__27838_23_entry) {
printf(((const char *)"\t%s,\n"), (__27838_23_entry->name));
__27838_23_entry = (__27838_23_entry->next);
}


printf(((const char *)"\t0\n};\n")); 
}



int main( int __27862_14_argc,  char **__27862_26_argv)
{
auto a_list_entry_ptr __27864_24_ctor_list = ((a_list_entry_ptr)0);
auto a_list_entry_ptr __27865_24_dtor_list = ((a_list_entry_ptr)0);
auto a_list_entry_ptr __27866_24_entry;
auto a_list_entry_ptr __27867_24_last_entry = ((a_list_entry_ptr)0);
auto char *__27868_24_name_pos;
auto char *__27869_24_name_string;
auto int __27870_24_name_length;
auto _ZN3edg9a_booleanE __27871_24_is_ctor;
auto int __27872_15_optchar;
auto int __27873_15_lines_to_skip = 0;



opterr = 0;

while ((__27872_15_optchar = (getopt(__27862_14_argc, ((char *const *)__27862_26_argv), ((const char *)"ui:")))) != (-1)) {
switch (__27872_15_optchar) {
case 105:



__27873_15_lines_to_skip = (atoi(((const char *)optarg)));
goto __T147801296;
case 117:


skip_underscore_prefix = ((_ZN3edg9a_booleanE)1);
goto __T147801296;
default:
if (optind >= __27862_14_argc) { optind = (__27862_14_argc - 1); }
optarg = (__27862_26_argv[optind]);
fprintf(stderr, ((const char *)"Unrecognized option: %s\n"), optarg);
_ZN31_INTERNAL_11_edg_munch_c_optind10error_utilEPKc(((const char *)"command line error"));
goto __T147801296;
} __T147801296:;
}

for (; __27873_15_lines_to_skip > 0; __27873_15_lines_to_skip--) { _ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv(); }
while (_ZN31_INTERNAL_11_edg_munch_c_optind15read_input_lineEv()) {

if (line_size == 0) { goto __T147809928; }
if (_ZN31_INTERNAL_11_edg_munch_c_optind23check_type_and_get_nameEPPcPiPb((&__27868_24_name_pos), (&__27870_24_name_length), (&__27871_24_is_ctor))) {


if (((__27867_24_last_entry != ((a_list_entry_ptr)0)) && (__27870_24_name_length == ((int)(strlen(((const char *)(__27867_24_last_entry->name))))))) && ((strncmp(((const char *)(__27867_24_last_entry->name)), ((const char *)__27868_24_name_pos), ((size_t)__27870_24_name_length))) == 0)) {

goto __T147809928; }

__27869_24_name_string = ((char *)(_ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEy(((size_t)(__27870_24_name_length + 1)))));
strncpy(__27869_24_name_string, ((const char *)__27868_24_name_pos), ((size_t)__27870_24_name_length));

(__27869_24_name_string[__27870_24_name_length]) = ((char)0);

__27866_24_entry = ((a_list_entry_ptr)(_ZN31_INTERNAL_11_edg_munch_c_optind17malloc_with_checkEy(16ULL)));
(__27866_24_entry->name) = __27869_24_name_string;
(__27866_24_entry->next) = ((a_list_entry_ptr)0);
__27867_24_last_entry = __27866_24_entry;



if (__27871_24_is_ctor) {

(__27866_24_entry->next) = __27864_24_ctor_list;
__27864_24_ctor_list = __27866_24_entry;
} else  {

(__27866_24_entry->next) = __27865_24_dtor_list;
__27865_24_dtor_list = __27866_24_entry;
}
} __T147809928:;
}
#line 351
printf(((const char *)"typedef %s (*%s)();\n"), ((const char *)("void")), ((const char *)("func_ptr")));



if (__27864_24_ctor_list) { _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc(__27864_24_ctor_list, ((const char *)"_ctors")); }
printf(((const char *)"\n"));


if (__27865_24_dtor_list) { _ZN31_INTERNAL_11_edg_munch_c_optind13create_outputEP12a_list_entryPKc(__27865_24_dtor_list, ((const char *)"_dtors")); }

return 0;
}
