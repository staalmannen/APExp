/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:53 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "util/edg_decode.c"
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 219 "src/basics.h"
typedef int _ZN3edg9a_booleanE;
# 515
typedef const char _ZN3edg12a_const_charE;
# 541
typedef size_t _ZN3edg8sizeof_tE;
# 357 "/usr/include/stdio.h" 3
extern int fprintf(FILE *__stream, const char *__format, ...);
# 582
extern int getchar(void);
# 618
extern int putchar(int __c);
# 717
extern int fputs(const char *__s, FILE *__stream);
# 878
extern __attribute__((__cold__)) void perror(const char *__s);
# 672 "/usr/include/stdlib.h" 3
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 687
extern __attribute__((__nothrow__)) void free(void *__ptr);
# 756
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void exit(int __status);
# 226 "/usr/include/string.h" 3
extern __attribute__((__pure__)) __attribute__((__nothrow__)) char *_Z6strchrPci(char *__s, int __c) __asm__("strchr");
# 109 "/usr/include/ctype.h" 3
extern __attribute__((__nothrow__)) int isalpha(int);

extern __attribute__((__nothrow__)) int isdigit(int);
# 57 "util/getopt.h"
extern int _Z6getoptiPKPcPKc(int argc, char *const *argv, const char *optstring);
# 16 "util/decode.h"
extern void _Z17decode_identifierPKcPcmPiS2_Pm(_ZN3edg12a_const_charE *id, char *output_buffer, _ZN3edg8sizeof_tE output_buffer_size, _ZN3edg9a_booleanE *err, _ZN3edg9a_booleanE *buffer_overflow_err, _ZN3edg8sizeof_tE *required_buffer_size);
# 83 "util/edg_decode.c"
static void _ZN32_INTERNAL_12_edg_decode_c_optind18process_identifierEv(void);
# 198
extern int main(int argc, char **argv);
# 150 "/usr/include/stdio.h" 3
extern FILE *stdout;
extern FILE *stderr;
# 45 "util/getopt.h"
char *optarg = 0;


extern int optind;

extern int opterr;
# 76
static char *_ZZ6getoptiPKPcPKcE7optchar;
# 39 "util/edg_decode.c"
static _ZN3edg9a_booleanE skip_underscore_prefix;
# 51
static int ch;



static char orig_id[15000];

static char *demangled_id;


static _ZN3edg8sizeof_tE demangled_id_size;
# 48 "util/getopt.h"
int optind = 1;

int opterr = 1;
# 76
static char *_ZZ6getoptiPKPcPKcE7optchar = ((char *)0);
# 39 "util/edg_decode.c"
static _ZN3edg9a_booleanE skip_underscore_prefix = 0;
# 60
static _ZN3edg8sizeof_tE demangled_id_size = 15000UL;
# 57 "util/getopt.h"
int _Z6getoptiPKPcPKc( int __35291_16_argc,  char *const *__35291_37_argv,  const char *__35291_55_optstring)
# 73
{
auto int __35308_15_return_value;
auto char *__35309_16_optpos;
# 83
if (_ZZ6getoptiPKPcPKcE7optchar == ((char *)0)) {
__35318_1_start_new_argument:;
if (optind >= __35291_16_argc) {

__35308_15_return_value = (-1);
goto __35396_1_end_of_routine;
} else  {
_ZZ6getoptiPKPcPKcE7optchar = (__35291_37_argv[optind]);
if (((int)(*_ZZ6getoptiPKPcPKcE7optchar)) != 45) {

__35308_15_return_value = (-1);
goto __35396_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 1))) == 45) {
if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 2))) == 0) {


optind++;
__35308_15_return_value = (-1);
} else  {

__35308_15_return_value = 63;
}
goto __35396_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 1))) == 0) {


__35308_15_return_value = (-1);
goto __35396_1_end_of_routine;
} } }

_ZZ6getoptiPKPcPKcE7optchar++;
}
}


if (((int)(*_ZZ6getoptiPKPcPKcE7optchar)) == 0) {

optind++;
goto __35318_1_start_new_argument;
}

__35309_16_optpos = (_Z6strchrPci(((char *)__35291_55_optstring), ((int)(*_ZZ6getoptiPKPcPKcE7optchar))));
if (__35309_16_optpos == ((char *)0)) {

if (opterr) { fprintf(stderr, ((const char *)"%s: illegal option -- %c\n"), (__35291_37_argv[0]), ((int)(*_ZZ6getoptiPKPcPKcE7optchar))); }

__35308_15_return_value = 63;
goto __35396_1_end_of_routine;
}

__35308_15_return_value = ((int)(*_ZZ6getoptiPKPcPKcE7optchar));

if (((int)(*(__35309_16_optpos + 1))) == 58) {
if (((int)(*(_ZZ6getoptiPKPcPKcE7optchar + 1))) == 0) {


optind++;
if (optind >= __35291_16_argc) {


if (opterr) { fprintf(stderr, ((const char *)"%s: option requires an argument -- %c\n"), (__35291_37_argv[0]), ((int)(*_ZZ6getoptiPKPcPKcE7optchar))); }

__35308_15_return_value = 63;
goto __35396_1_end_of_routine;
}
optarg = (__35291_37_argv[optind]);
} else  {


optarg = (_ZZ6getoptiPKPcPKcE7optchar + 1);
}

_ZZ6getoptiPKPcPKcE7optchar = ((char *)0);
optind++;
} else  {

_ZZ6getoptiPKPcPKcE7optchar++;
optarg = ((char *)0);
}
__35396_1_end_of_routine:;
return __35308_15_return_value;
}
# 83 "util/edg_decode.c"
static void _ZN32_INTERNAL_12_edg_decode_c_optind18process_identifierEv(void)
# 89
{
auto _ZN3edg9a_booleanE __35492_17_is_mangled_name = 0; auto _ZN3edg9a_booleanE __35492_42_too_long_err = 0;
auto unsigned long __35493_17_i; auto unsigned long __35493_20_orig_id_len;

__35493_20_orig_id_len = 1UL;
((orig_id)[0]) = ((char)ch);

for (; ; ) {

ch = (getchar());
if (!((ch != (-1)) && (((ch != (-1)) && (((isalpha(((int)((unsigned char)ch)))) || (ch == 95)) || (ch == 36))) || (isdigit(((int)((unsigned char)ch))))))) { goto __T715314248; }
if (__35493_20_orig_id_len >= 14999UL) {

if (!(__35492_42_too_long_err)) {


for (__35493_17_i = 0UL; __35493_17_i < __35493_20_orig_id_len; __35493_17_i++) { putchar(((int)((orig_id)[__35493_17_i]))); }
__35492_42_too_long_err = 1;
}


putchar(ch);
} else  {

((orig_id)[__35493_20_orig_id_len]) = ((char)ch);


if (((ch == 95) && (__35493_20_orig_id_len > 0UL)) && (((int)((orig_id)[(__35493_20_orig_id_len - 1UL)])) == 95)) {
__35492_17_is_mangled_name = 1;
}

__35493_20_orig_id_len++;
}
} __T715314248:;

if (__35492_42_too_long_err) {

} else  {
auto char *__35529_11_id = orig_id;

((orig_id)[__35493_20_orig_id_len]) = ((char)0);



if (skip_underscore_prefix) {
if (((int)(__35529_11_id[0])) == 95) {
__35529_11_id++;
__35493_20_orig_id_len--;
} else  {
__35492_17_is_mangled_name = 0;
}
}
# 153
if (__35492_17_is_mangled_name) {
auto _ZN3edg9a_booleanE __35556_17_err; auto _ZN3edg9a_booleanE __35556_22_buffer_overflow_err;
auto _ZN3edg8sizeof_tE __35557_17_required_buffer_size;
do {

_Z17decode_identifierPKcPcmPiS2_Pm(((_ZN3edg12a_const_charE *)__35529_11_id), demangled_id, demangled_id_size, (&__35556_17_err), (&__35556_22_buffer_overflow_err), (&__35557_17_required_buffer_size));

if ((__35556_17_err) && (__35556_22_buffer_overflow_err)) {


if (__35557_17_required_buffer_size <= demangled_id_size) {

fprintf(stderr, ((const char *)"Request to allocate smaller buffer\n"));
exit(4);
}


demangled_id_size *= 2UL;
if (demangled_id_size < __35557_17_required_buffer_size) {
demangled_id_size = __35557_17_required_buffer_size;
}

free(((void *)demangled_id));
demangled_id = ((char *)(malloc(demangled_id_size)));
if (demangled_id == ((char *)0)) {
perror(((const char *)0));
exit(4);
}
}
} while (__35556_22_buffer_overflow_err);

if (__35556_17_err) { __35492_17_is_mangled_name = 0; }
}
if (!(__35492_17_is_mangled_name)) {

fputs(((const char *)orig_id), stdout);
} else  {

fputs(((const char *)demangled_id), stdout);
}
} 

}


int main( int __35600_14_argc,  char **__35600_26_argv)



{
auto int __35605_7_optchar;



opterr = 0;
# 215
demangled_id = ((char *)(malloc(demangled_id_size)));
if (demangled_id == ((char *)0)) {
perror(((const char *)0));
return 4;
}
while ((__35605_7_optchar = (_Z6getoptiPKPcPKc(__35600_14_argc, ((char *const *)__35600_26_argv), ((const char *)"u")))) != (-1)) {
switch (__35605_7_optchar) {
case 117:


skip_underscore_prefix = 1;
goto __T715422072;
# 234
default:
if (optind >= __35600_14_argc) { optind = (__35600_14_argc - 1); }
optarg = (__35600_26_argv[optind]);
fprintf(stderr, ((const char *)"Unrecognized option: %s\n"), optarg);
return 2;
} __T715422072:;
}


while ((ch = (getchar())) != (-1)) {

if ((ch != (-1)) && (((isalpha(((int)((unsigned char)ch)))) || (ch == 95)) || (ch == 36))) {
_ZN32_INTERNAL_12_edg_decode_c_optind18process_identifierEv();


if (ch == (-1)) { goto __T715432024; }
}
putchar(ch);
} __T715432024:;
return 0;
}
