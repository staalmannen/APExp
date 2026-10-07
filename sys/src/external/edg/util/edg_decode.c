/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:15:23 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "util/edg_decode.c"
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
#line 28 "ape-sys/ctype.h"
enum _ZN32_INTERNAL_12_edg_decode_c_optindUt_E {
_ISupper = 0x1,
_ISlower = 0x2,
_ISdigit = 0x4,
_ISspace = 0x8,
_ISpunct = 0x10,
_IScntrl = 0x20,
_ISblank = 0x40,
_ISxdigit = 0x80};
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 214 "src/basics.h"
typedef _Bool _ZN3edg9a_booleanE;
#line 515
typedef const char _ZN3edg12a_const_charE;
#line 541
typedef size_t _ZN3edg8sizeof_tE;
#line 71 "ape-sys/stdio.h"
extern int fprintf(FILE *, const char *, ...);
#line 86
extern int fputs(const char *, FILE *);
extern int getc(FILE *);



extern int putc(int, FILE *);
#line 110
extern void perror(const char *);
#line 44 "ape-sys/stdlib.h"
extern void free(void *);
extern void *malloc(size_t);



extern void exit(int);
#line 27 "ape-sys/string.h"
extern char *strchr(const char *, int);
#line 57 "util/getopt.h"
extern int getopt(int argc, char *const *argv, const char *optstring);
#line 16 "util/decode.h"
extern void _Z17decode_identifierPKcPcyPbS2_Py(_ZN3edg12a_const_charE *id, char *output_buffer, _ZN3edg8sizeof_tE output_buffer_size, _ZN3edg9a_booleanE *err, _ZN3edg9a_booleanE *buffer_overflow_err, _ZN3edg8sizeof_tE *required_buffer_size);
#line 83 "util/edg_decode.c"
static void _ZN32_INTERNAL_12_edg_decode_c_optind18process_identifierEv(void);
#line 198
extern int main(int argc, char **argv);
#line 51 "ape-sys/stdio.h"
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
#line 39 "ape-sys/ctype.h"
extern unsigned char _ctype[];
#line 45 "util/getopt.h"
char *optarg = 0;


extern int optind;

extern int opterr;
#line 76
static char *_ZZ6getoptE7optchar;
#line 39 "util/edg_decode.c"
static _ZN3edg9a_booleanE skip_underscore_prefix;
#line 48
extern _ZN3edg9a_booleanE emulate_gnu_abi_bugs;


static int ch;



static char orig_id[15000];

static char *demangled_id;


static _ZN3edg8sizeof_tE demangled_id_size;
#line 48 "util/getopt.h"
int optind = 1;

int opterr = 1;
#line 76
static char *_ZZ6getoptE7optchar = ((char *)0);
#line 39 "util/edg_decode.c"
static _ZN3edg9a_booleanE skip_underscore_prefix = ((_ZN3edg9a_booleanE)0);
#line 60
static _ZN3edg8sizeof_tE demangled_id_size = 15000ULL;
#line 57 "util/getopt.h"
int getopt( int __27336_16_argc,  char *const *__27336_37_argv,  const char *__27336_55_optstring)
#line 73
{
auto int __27353_15_return_value;
auto char *__27354_16_optpos;
#line 83
if (_ZZ6getoptE7optchar == ((char *)0)) {
__27363_1_start_new_argument:;
if (optind >= __27336_16_argc) {

__27353_15_return_value = (-1);
goto __27441_1_end_of_routine;
} else  {
_ZZ6getoptE7optchar = (__27336_37_argv[optind]);
if (((int)(*_ZZ6getoptE7optchar)) != 45) {

__27353_15_return_value = (-1);
goto __27441_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 45) {
if (((int)(*(_ZZ6getoptE7optchar + 2))) == 0) {


optind++;
__27353_15_return_value = (-1);
} else  {

__27353_15_return_value = 63;
}
goto __27441_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


__27353_15_return_value = (-1);
goto __27441_1_end_of_routine;
} } }

_ZZ6getoptE7optchar++;
}
}


if (((int)(*_ZZ6getoptE7optchar)) == 0) {

optind++;
goto __27363_1_start_new_argument;
}

__27354_16_optpos = (strchr(((const char *)((char *)__27336_55_optstring)), ((int)(*_ZZ6getoptE7optchar))));
if (__27354_16_optpos == ((char *)0)) {

if (opterr) { fprintf(stderr, ((const char *)"%s: illegal option -- %c\n"), (__27336_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27353_15_return_value = 63;
goto __27441_1_end_of_routine;
}

__27353_15_return_value = ((int)(*_ZZ6getoptE7optchar));

if (((int)(*(__27354_16_optpos + 1))) == 58) {
if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


optind++;
if (optind >= __27336_16_argc) {


if (opterr) { fprintf(stderr, ((const char *)"%s: option requires an argument -- %c\n"), (__27336_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27353_15_return_value = 63;
goto __27441_1_end_of_routine;
}
optarg = (__27336_37_argv[optind]);
} else  {


optarg = (_ZZ6getoptE7optchar + 1);
}

_ZZ6getoptE7optchar = ((char *)0);
optind++;
} else  {

_ZZ6getoptE7optchar++;
optarg = ((char *)0);
}
__27441_1_end_of_routine:;
return __27353_15_return_value;
}
#line 83 "util/edg_decode.c"
static void _ZN32_INTERNAL_12_edg_decode_c_optind18process_identifierEv(void)
#line 89
{
auto _ZN3edg9a_booleanE __27537_17_is_mangled_name = ((_ZN3edg9a_booleanE)0); auto _ZN3edg9a_booleanE __27537_42_too_long_err = ((_ZN3edg9a_booleanE)0);
auto unsigned long __27538_17_i; auto unsigned long __27538_20_orig_id_len;

__27538_20_orig_id_len = 1UL;
((orig_id)[0]) = ((char)ch);

for (; ; ) {

ch = (getc(stdin));
if (!((ch != (-1)) && (((ch != (-1)) && (((((int)((_ctype)[((unsigned char)((unsigned char)ch))])) & 0x3) || (ch == 95)) || (ch == 36))) || (((int)((_ctype)[((unsigned char)((unsigned char)ch))])) & 4)))) { goto __T813365544; }
if (__27538_20_orig_id_len >= 14999UL) {

if (!(__27537_42_too_long_err)) {


for (__27538_17_i = 0UL; __27538_17_i < __27538_20_orig_id_len; __27538_17_i++) { putc(((int)((orig_id)[__27538_17_i])), stdout); }
__27537_42_too_long_err = ((_ZN3edg9a_booleanE)1);
}


putc(ch, stdout);
} else  {

((orig_id)[__27538_20_orig_id_len]) = ((char)ch);
#line 120
__27538_20_orig_id_len++;
}
} __T813365544:;

if (__27537_42_too_long_err) {

} else  {
auto char *__27574_11_id = orig_id;

((orig_id)[__27538_20_orig_id_len]) = ((char)0);



if (skip_underscore_prefix) {
if (((int)(__27574_11_id[0])) == 95) {
__27574_11_id++;
__27538_20_orig_id_len--;
} else  {
__27537_17_is_mangled_name = ((_ZN3edg9a_booleanE)0);
}
}


if (((__27538_20_orig_id_len > 2UL) && (((int)(__27574_11_id[0])) == 95)) && (((int)(__27574_11_id[1])) == 90)) {
__27537_17_is_mangled_name = ((_ZN3edg9a_booleanE)1);
} else  { if (((((__27538_20_orig_id_len > 4UL) && (((int)(__27574_11_id[0])) == 95)) && (((int)(__27574_11_id[1])) == 95)) && ((((int)(__27574_11_id[2])) == 98) || (((int)(__27574_11_id[2])) == 118))) && (((int)(__27574_11_id[3])) == 95))


{

__27537_17_is_mangled_name = ((_ZN3edg9a_booleanE)1);
} }

if (__27537_17_is_mangled_name) {
auto _ZN3edg9a_booleanE __27601_17_err; auto _ZN3edg9a_booleanE __27601_22_buffer_overflow_err;
auto _ZN3edg8sizeof_tE __27602_17_required_buffer_size;
do {

_Z17decode_identifierPKcPcyPbS2_Py(((_ZN3edg12a_const_charE *)__27574_11_id), demangled_id, demangled_id_size, (&__27601_17_err), (&__27601_22_buffer_overflow_err), (&__27602_17_required_buffer_size));

if ((__27601_17_err) && (__27601_22_buffer_overflow_err)) {


if (__27602_17_required_buffer_size <= demangled_id_size) {

fprintf(stderr, ((const char *)"Request to allocate smaller buffer\n"));
exit(4);
}


demangled_id_size *= 2ULL;
if (demangled_id_size < __27602_17_required_buffer_size) {
demangled_id_size = __27602_17_required_buffer_size;
}

free(((void *)demangled_id));
demangled_id = ((char *)(malloc(demangled_id_size)));
if (demangled_id == ((char *)0)) {
perror(((const char *)0));
exit(4);
}
}
} while (__27601_22_buffer_overflow_err);

if (__27601_17_err) { __27537_17_is_mangled_name = ((_ZN3edg9a_booleanE)0); }
}
if (!(__27537_17_is_mangled_name)) {

fputs(((const char *)orig_id), stdout);
} else  {

fputs(((const char *)demangled_id), stdout);
}
} 

}


int main( int __27645_14_argc,  char **__27645_26_argv)



{
auto int __27650_7_optchar;



opterr = 0;
#line 215
demangled_id = ((char *)(malloc(demangled_id_size)));
if (demangled_id == ((char *)0)) {
perror(((const char *)0));
return 4;
}
while ((__27650_7_optchar = (getopt(__27645_14_argc, ((char *const *)__27645_26_argv), ((const char *)"ug")))) != (-1)) {
switch (__27650_7_optchar) {
case 117:


skip_underscore_prefix = ((_ZN3edg9a_booleanE)1);
goto __T813419880;

case 103:


emulate_gnu_abi_bugs = ((_ZN3edg9a_booleanE)1);
goto __T813419880;

default:
if (optind >= __27645_14_argc) { optind = (__27645_14_argc - 1); }
optarg = (__27645_26_argv[optind]);
fprintf(stderr, ((const char *)"Unrecognized option: %s\n"), optarg);
return 2;
} __T813419880:;
}


while ((ch = (getc(stdin))) != (-1)) {

if ((ch != (-1)) && (((((int)((_ctype)[((unsigned char)((unsigned char)ch))])) & 0x3) || (ch == 95)) || (ch == 36))) {
_ZN32_INTERNAL_12_edg_decode_c_optind18process_identifierEv();


if (ch == (-1)) { goto __T813434056; }
}
putc(ch, stdout);
} __T813434056:;
return 0;
}
