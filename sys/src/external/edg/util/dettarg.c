/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:52 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "util/dettarg.c"
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t;
# 26 "/usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h" 3
struct __jmp_buf_tag;
# 171 "util/dettarg.c"
enum int_kind {
ik_char,
ik_short,
ik_int,
ik_long,
ik_long_long};
# 407
struct _ZZ4mainEUt_;
# 413
struct _ZZ4mainEUt0_;
# 419
struct _ZZ4mainEUt1_;
# 434
struct _ZZ4mainEUt2_;
# 441
struct _ZZ4mainEUt3_;
# 447
struct _ZZ4mainEUt4_;
# 454
struct _ZZ4mainEUt5_;
# 467
struct _ZZ4mainEUt6_;
# 488
struct _ZZ4mainEUt7_;
# 508
struct _ZZ4mainEUt8_;
# 573
struct _ZZ4mainENUt9_Ut_E; struct _ZZ4mainEUt9_;




struct _ZZ4mainEUt10_;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 31 "/usr/include/x86_64-linux-gnu/bits/setjmp.h" 3
typedef long __jmp_buf[8];
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t {
unsigned long __val[16];};
typedef struct __sigset_t __sigset_t;
# 26 "/usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h" 3
struct __jmp_buf_tag {
# 32
__jmp_buf __jmpbuf;
int __mask_was_saved;
__sigset_t __saved_mask;};
# 32 "/usr/include/setjmp.h" 3
typedef struct __jmp_buf_tag jmp_buf[1];
# 145 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef long ptrdiff_t;
# 407 "util/dettarg.c"
struct _ZZ4mainEUt_ { char c; short s;};
# 413
struct _ZZ4mainEUt0_ { char c; int s;};
# 419
struct _ZZ4mainEUt1_ { char c; long s;};
# 434
struct _ZZ4mainEUt2_ { char c; char *s;};
# 441
struct _ZZ4mainEUt3_ { char c; float s;};
# 447
struct _ZZ4mainEUt4_ { char c; double s;};
# 454
struct _ZZ4mainEUt5_ { char c; long double s;};
# 467
struct _ZZ4mainEUt6_ { char c; int s;};
# 488
struct _ZZ4mainEUt7_ { char c; size_t s;};
# 508
struct _ZZ4mainEUt8_ { char c; ptrdiff_t s;};
# 573
struct _ZZ4mainENUt9_Ut_E { char d;}; struct _ZZ4mainEUt9_ { char c; struct _ZZ4mainENUt9_Ut_E s;};




struct _ZZ4mainEUt10_ { char c; jmp_buf s;};
# 357 "/usr/include/stdio.h" 3
extern int fprintf(FILE *__stream, const char *__format, ...);
# 363
extern int printf(const char *__format, ...);
# 156 "/usr/include/string.h" 3
extern __attribute__((__pure__)) __attribute__((__nothrow__)) int strcmp(const char *__s1, const char *__s2);
# 145 "util/dettarg.c"
static unsigned long _ZN26_INTERNAL_9_dettarg_c_main8bit_maskEi(int nbits);
# 157
static unsigned long _ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(char *p2, char *p1);
# 180
static const char *_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi(enum int_kind kind, int is_signed);
# 236
static unsigned long _ZN26_INTERNAL_9_dettarg_c_main16int_kind_to_sizeE8int_kind(enum int_kind kind);
# 267
static enum int_kind _ZN26_INTERNAL_9_dettarg_c_main22int_kind_for_alignmentEmPi(unsigned long alignment, int *error);
# 297
static const char *_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(unsigned long size, unsigned long alignment, int is_signed, int favor_long, int *error);
# 342
static const char *_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(int size, int is_signed);
# 365
extern int main(void);
# 151 "/usr/include/stdio.h" 3
extern FILE *stderr;
# 103 "util/dettarg.c"
unsigned long targ_sizeof_short = 0;
unsigned long targ_sizeof_int = 0;
unsigned long targ_sizeof_long = 0;
unsigned long targ_sizeof_float = 0;
unsigned long targ_sizeof_double = 0;
unsigned long targ_sizeof_pointer = 0;
unsigned long targ_alignof_short = 0;
unsigned long targ_alignof_int = 0;
unsigned long targ_alignof_long = 0;
unsigned long targ_alignof_float = 0;
unsigned long targ_alignof_double = 0;
unsigned long targ_alignof_pointer = 0;

unsigned long targ_sizeof_long_double = 0;
unsigned long targ_alignof_long_double = 0;


unsigned long targ_sizeof_wchar_t = 0;
unsigned long targ_alignof_wchar_t = 0;


unsigned long targ_sizeof_size_t = 0;
unsigned long targ_alignof_size_t = 0;


unsigned long targ_sizeof_ptrdiff_t = 0;
unsigned long targ_alignof_ptrdiff_t = 0;
# 141
static int targ_char_bit;



static unsigned long _ZN26_INTERNAL_9_dettarg_c_main8bit_maskEi( int __7897_35_nbits)

{
auto unsigned long __7900_17_i; auto unsigned long __7900_20_j;
__7900_17_i = 1UL;
__7900_17_i <<= (__7897_35_nbits - 1);
__7900_20_j = (__7900_17_i - 1UL);
__7900_17_i |= __7900_20_j;
return __7900_17_i;
}


static unsigned long _ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_( char *__7909_38_p2,  char *__7909_48_p1)

{
auto unsigned long __7912_17_align;
auto unsigned long __7913_17_diff; __7913_17_diff = ((unsigned long)(__7909_38_p2 - __7909_48_p1));

for (__7912_17_align = 1UL; (__7913_17_diff & __7912_17_align) == 0UL; __7912_17_align *= 2UL) { }
return __7912_17_align;
}
# 180
static const char *_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi( enum int_kind __7932_50_kind, 
int __7933_50_is_signed)
# 187
{
auto const char *__7940_15_result;

switch ((int)__7932_50_kind) {
case 0:
if (__7933_50_is_signed == (-1)) {
__7940_15_result = ((const char *)"ik_char");
} else  { if (__7933_50_is_signed == 1) {
__7940_15_result = ((const char *)"ik_signed_char");
} else  {
__7940_15_result = ((const char *)"ik_unsigned_char");
} }
goto __T828635976;
case 1:
if (__7933_50_is_signed == 1) {
__7940_15_result = ((const char *)"ik_short");
} else  {
__7940_15_result = ((const char *)"ik_unsigned_short");
}
goto __T828635976;
case 2:
if (__7933_50_is_signed == 1) {
__7940_15_result = ((const char *)"ik_int");
} else  {
__7940_15_result = ((const char *)"ik_unsigned_int");
}
goto __T828635976;
case 3:
if (__7933_50_is_signed == 1) {
__7940_15_result = ((const char *)"ik_long");
} else  {
__7940_15_result = ((const char *)"ik_unsigned_long");
}
goto __T828635976;
case 4:
if (__7933_50_is_signed == 1) {
__7940_15_result = ((const char *)"ik_long_long");
} else  {
__7940_15_result = ((const char *)"ik_unsigned_long_long");
}
goto __T828635976;
default:
__7940_15_result = ((const char *)"<error>");
goto __T828635976;
} __T828635976:;
return __7940_15_result;
}


static unsigned long _ZN26_INTERNAL_9_dettarg_c_main16int_kind_to_sizeE8int_kind( enum int_kind __7988_48_kind)

{
auto unsigned long __7991_17_result;

switch ((int)__7988_48_kind) {
case 0:
__7991_17_result = 1UL;
goto __T828652760;
case 1:
__7991_17_result = targ_sizeof_short;
goto __T828652760;
case 2:
__7991_17_result = targ_sizeof_int;
goto __T828652760;
case 3:
__7991_17_result = targ_sizeof_long;
goto __T828652760;
# 259
default:
__7991_17_result = 0UL;
goto __T828652760;
} __T828652760:;
return __7991_17_result;
}


static enum int_kind _ZN26_INTERNAL_9_dettarg_c_main22int_kind_for_alignmentEmPi( unsigned long __8019_54_alignment, 
int *__8020_55_error)




{
auto enum int_kind __8026_12_result;

(*__8020_55_error) = 0;
if (__8019_54_alignment == 1UL) {
__8026_12_result = ik_char;
} else  { if (__8019_54_alignment == targ_alignof_short) {
__8026_12_result = ik_short;
} else  { if (__8019_54_alignment == targ_alignof_int) {
__8026_12_result = ik_int;
} else  { if (__8019_54_alignment == targ_alignof_long) {
__8026_12_result = ik_long;




} else  {
(*__8020_55_error) = 1;
__8026_12_result = ik_int;
} } } }
return __8026_12_result;
}


static const char *_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi( unsigned long __8049_61_size, 
unsigned long __8050_61_alignment, 
int __8051_61_is_signed, 
int __8052_61_favor_long, 
int *__8053_62_error)
# 309
{
auto const char *__8062_15_result;
auto enum int_kind __8063_14_kind;

(*__8053_62_error) = 0;
if ((__8049_61_size == 1UL) && (__8050_61_alignment == 1UL)) {
__8063_14_kind = ik_char;
} else  { if ((__8049_61_size == targ_sizeof_short) && (__8050_61_alignment == targ_alignof_short)) {
__8063_14_kind = ik_short;
} else  { if (((__8052_61_favor_long) && (__8049_61_size == targ_sizeof_long)) && (__8050_61_alignment == targ_alignof_long))
{
__8063_14_kind = ik_long;
} else  { if ((__8049_61_size == targ_sizeof_int) && (__8050_61_alignment == targ_alignof_int)) {
__8063_14_kind = ik_int;
} else  { if ((__8049_61_size == targ_sizeof_long) && (__8050_61_alignment == targ_alignof_long)) {
__8063_14_kind = ik_long;
# 330
} else  {
(*__8053_62_error) = 1;
} } } } }
if (*__8053_62_error) {
__8062_15_result = ((const char *)"");
} else  {
__8062_15_result = (_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi(__8063_14_kind, __8051_61_is_signed));
}
return __8062_15_result;
}


static const char *_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii( int __8094_47_size, 
int __8095_47_is_signed)
# 349
{
auto const char *__8102_15_result = ((const char *)0);

if (((unsigned long)__8094_47_size) == (1UL * ((unsigned long)targ_char_bit))) {
__8102_15_result = ((__8095_47_is_signed) ? ((const char *)("signed char")) : ((const char *)("unsigned char")));
} else  { if (((unsigned long)__8094_47_size) == (2UL * ((unsigned long)targ_char_bit))) {
__8102_15_result = ((__8095_47_is_signed) ? ((const char *)("short")) : ((const char *)("unsigned short")));
} else  { if (((unsigned long)__8094_47_size) == (4UL * ((unsigned long)targ_char_bit))) {
__8102_15_result = ((__8095_47_is_signed) ? ((const char *)("int")) : ((const char *)("unsigned int")));
} else  { if (((unsigned long)__8094_47_size) == (8UL * ((unsigned long)targ_char_bit))) {
__8102_15_result = ((__8095_47_is_signed) ? ((const char *)("long")) : ((const char *)("unsigned long")));
} } } }
return __8102_15_result;
}


int main(void) {
auto long __8118_8_i;
auto unsigned long __8119_17_ui;
auto unsigned char __8120_17_uch;
auto unsigned long __8121_17_targ_uchar_max;
auto unsigned long __8122_17_targ_minimum_struct_alignment;
auto char __8123_8_ch;

printf(((const char *)"/* Configuration definitions determined by dettarg.c: */\n"));

__8118_8_i = 1L;
if (((int)(*((char *)(&__8118_8_i)))) == 1) {
printf(((const char *)"#define TARG_LITTLE_ENDIAN TRUE\n"));
} else  {
printf(((const char *)"#define TARG_LITTLE_ENDIAN FALSE\n"));
}

for (targ_char_bit = 1; ; targ_char_bit++)

{
__8119_17_ui = (1UL << ((unsigned long)targ_char_bit));
__8120_17_uch = ((unsigned char)__8119_17_ui);
if (((unsigned long)__8120_17_uch) != __8119_17_ui) { goto __T828842752; }
} __T828842752:;
printf(((const char *)"#define TARG_CHAR_BIT %d\n"), targ_char_bit);
__8121_17_targ_uchar_max = (_ZN26_INTERNAL_9_dettarg_c_main8bit_maskEi(targ_char_bit));
__8123_8_ch = ((char)__8121_17_targ_uchar_max);
if (((int)__8123_8_ch) < 0) {

printf(((const char *)"#define TARG_HAS_SIGNED_CHARS TRUE\n"));
} else  {

printf(((const char *)"#define TARG_HAS_SIGNED_CHARS FALSE\n"));
}

__8118_8_i = 24930L;
if (__8118_8_i == ((long)((97 << targ_char_bit) | 98))) {
printf(((const char *)"#define TARG_CHAR_CONSTANT_FIRST_CHAR_MOST_SIGNIFICANT TRUE\n"));
} else  {
printf(((const char *)"#define TARG_CHAR_CONSTANT_FIRST_CHAR_MOST_SIGNIFICANT FALSE\n"));
}

{ auto struct _ZZ4mainEUt_ __8159_31_v;
targ_sizeof_short = 2UL;
targ_alignof_short = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8159_31_v.s))), ((char *)(&__8159_31_v))));
printf(((const char *)"#define TARG_SIZEOF_SHORT %lu\n"), targ_sizeof_short);
printf(((const char *)"#define TARG_ALIGNOF_SHORT %lu\n"), targ_alignof_short);
}
{ auto struct _ZZ4mainEUt0_ __8165_29_v;
targ_sizeof_int = 4UL;
targ_alignof_int = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8165_29_v.s))), ((char *)(&__8165_29_v))));
printf(((const char *)"#define TARG_SIZEOF_INT %lu\n"), targ_sizeof_int);
printf(((const char *)"#define TARG_ALIGNOF_INT %lu\n"), targ_alignof_int);
}
{ auto struct _ZZ4mainEUt1_ __8171_30_v;
targ_sizeof_long = 8UL;
targ_alignof_long = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8171_30_v.s))), ((char *)(&__8171_30_v))));
printf(((const char *)"#define TARG_SIZEOF_LONG %lu\n"), targ_sizeof_long);
printf(((const char *)"#define TARG_ALIGNOF_LONG %lu\n"), targ_alignof_long);
}
# 434
{ auto struct _ZZ4mainEUt2_ __8186_31_v;
targ_sizeof_pointer = 8UL;
targ_alignof_pointer = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8186_31_v.s))), ((char *)(&__8186_31_v))));
printf(((const char *)"#define TARG_SIZEOF_POINTER %lu\n"), targ_sizeof_pointer);
printf(((const char *)"#define TARG_ALIGNOF_POINTER %lu\n"), targ_alignof_pointer);
}

{ auto struct _ZZ4mainEUt3_ __8193_31_v;
targ_sizeof_float = 4UL;
targ_alignof_float = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8193_31_v.s))), ((char *)(&__8193_31_v))));
printf(((const char *)"#define TARG_SIZEOF_FLOAT %lu\n"), targ_sizeof_float);
printf(((const char *)"#define TARG_ALIGNOF_FLOAT %lu\n"), targ_alignof_float);
}
{ auto struct _ZZ4mainEUt4_ __8199_32_v;
targ_sizeof_double = 8UL;
targ_alignof_double = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8199_32_v.s))), ((char *)(&__8199_32_v))));
printf(((const char *)"#define TARG_SIZEOF_DOUBLE %lu\n"), targ_sizeof_double);
printf(((const char *)"#define TARG_ALIGNOF_DOUBLE %lu\n"), targ_alignof_double);
}

{ auto struct _ZZ4mainEUt5_ __8206_37_v;
targ_sizeof_long_double = 16UL;
targ_alignof_long_double = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8206_37_v.s))), ((char *)(&__8206_37_v))));
printf(((const char *)"#define TARG_SIZEOF_LONG_DOUBLE %lu\n"), targ_sizeof_long_double);
printf(((const char *)"#define TARG_ALIGNOF_LONG_DOUBLE %lu\n"), targ_alignof_long_double);
}
# 467
{ auto struct _ZZ4mainEUt6_ __8219_33_v;
auto const char *__8220_34_targ_wchar_t_int_kind;
auto int __8221_33_is_signed; auto int __8221_44_error;
targ_sizeof_wchar_t = 4UL;
targ_alignof_wchar_t = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8219_33_v.s))), ((char *)(&__8219_33_v))));
__8221_33_is_signed = 1;
__8220_34_targ_wchar_t_int_kind = (_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(targ_sizeof_wchar_t, targ_alignof_wchar_t, __8221_33_is_signed, 1, (&__8221_44_error)));




if (__8221_44_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_WCHAR_T_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
printf(((const char *)"#define TARG_WCHAR_T_INT_KIND ((an_integer_kind)%s)\n"), __8220_34_targ_wchar_t_int_kind);

}
}


{ auto struct _ZZ4mainEUt7_ __8240_32_v;
auto const char *__8241_34_targ_size_t_int_kind;
auto int __8242_33_error;
targ_sizeof_size_t = 8UL;
targ_alignof_size_t = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8240_32_v.s))), ((char *)(&__8240_32_v))));
__8241_34_targ_size_t_int_kind = (_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(targ_sizeof_size_t, targ_alignof_size_t, 0, 0, (&__8242_33_error)));




if (__8242_33_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_SIZE_T_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
printf(((const char *)"#define TARG_SIZE_T_INT_KIND ((an_integer_kind)%s)\n"), __8241_34_targ_size_t_int_kind);

}
}


{ auto struct _ZZ4mainEUt8_ __8260_35_v;
auto const char *__8261_34_targ_ptrdiff_t_int_kind;
auto int __8262_33_error;
targ_sizeof_ptrdiff_t = 8UL;
targ_alignof_ptrdiff_t = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8260_35_v.s))), ((char *)(&__8260_35_v))));
__8261_34_targ_ptrdiff_t_int_kind = (_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(targ_sizeof_ptrdiff_t, targ_alignof_ptrdiff_t, 1, 0, (&__8262_33_error)));
# 519
if (__8262_33_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_PTRDIFF_T_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
printf(((const char *)"#define TARG_PTRDIFF_T_INT_KIND ((an_integer_kind)%s)\n"), __8261_34_targ_ptrdiff_t_int_kind);

}
}

{ auto unsigned long __8280_19_max_alignment = 1UL;
if (__8280_19_max_alignment < targ_alignof_short) { __8280_19_max_alignment = targ_alignof_short; }
if (__8280_19_max_alignment < targ_alignof_int) { __8280_19_max_alignment = targ_alignof_int; }
if (__8280_19_max_alignment < targ_alignof_long) { __8280_19_max_alignment = targ_alignof_long; }
if (__8280_19_max_alignment < targ_alignof_pointer) {
__8280_19_max_alignment = targ_alignof_pointer;
}
# 544
printf(((const char *)"#define HOST_ALIGNMENT_REQUIRED %lu\n"), __8280_19_max_alignment);
}

if (0) {

printf(((const char *)"#define TARG_RIGHT_SHIFT_IS_ARITHMETIC FALSE\n"));
} else  {
printf(((const char *)"#define TARG_RIGHT_SHIFT_IS_ARITHMETIC TRUE\n"));
}

{ auto int __8306_9_i = 16;
auto int __8307_9_j; __8307_9_j = ((int)((targ_sizeof_int * ((unsigned long)targ_char_bit)) + 1UL));
if (__8307_9_j == 33) {


__8306_9_i = 0;
} else  {
__8306_9_i = (__8306_9_i >> __8307_9_j);
}
if (__8306_9_i == 8) {

printf(((const char *)"#define TARG_TOO_LARGE_SHIFT_COUNT_IS_TAKEN_MODULO_SIZE TRUE\n"));
} else  {


printf(((const char *)"#define TARG_TOO_LARGE_SHIFT_COUNT_IS_TAKEN_MODULO_SIZE FALSE\n"));

}
}
{ auto struct _ZZ4mainEUt9_ __8325_46_v;
__8122_17_targ_minimum_struct_alignment = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8325_46_v.s))), ((char *)(&__8325_46_v))));
printf(((const char *)"#define TARG_MINIMUM_STRUCT_ALIGNMENT %lu\n"), __8122_17_targ_minimum_struct_alignment);

}
{ auto struct _ZZ4mainEUt10_ __8330_35_v;
auto unsigned long __8331_19_alignof_jmp_buf;
auto int __8332_19_error;
auto enum int_kind __8333_19_buffer_type;
# 579
__8331_19_alignof_jmp_buf = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__8330_35_v.s))), ((char *)(&__8330_35_v))));



__8333_19_buffer_type = (_ZN26_INTERNAL_9_dettarg_c_main22int_kind_for_alignmentEmPi(__8331_19_alignof_jmp_buf, (&__8332_19_error)));
if (__8332_19_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_JMP_BUF_NUM_ELEMENTS.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
fprintf(stderr, ((const char *)"Unable to determine TARG_JMP_BUF_ELEMENT_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
auto unsigned long __8342_21_buffer_element_size;
auto unsigned long __8343_21_buffer_element_count;

auto int __8345_16_buffer_overflow;
# 590
__8342_21_buffer_element_size = (_ZN26_INTERNAL_9_dettarg_c_main16int_kind_to_sizeE8int_kind(__8333_19_buffer_type));
__8343_21_buffer_element_count = (200UL / __8342_21_buffer_element_size);

__8345_16_buffer_overflow = ((int)((200UL % __8342_21_buffer_element_size) != 0UL));



if (__8345_16_buffer_overflow) {
++__8343_21_buffer_element_count;
}
printf(((const char *)"#define TARG_JMP_BUF_NUM_ELEMENTS %lu\n"), __8343_21_buffer_element_count);
printf(((const char *)"#define TARG_JMP_BUF_ELEMENTS_ARE_FLOAT 0\n"));
printf(((const char *)"#define TARG_JMP_BUF_ELEMENT_INT_KIND ((an_integer_kind)%s)\n"), (_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi(__8333_19_buffer_type, (-1))));

}
}
# 614
{ auto const char __8366_16_func_call_expanded[14] = "_setjmp (foo)";
auto char __8367_10_func_call_result[14]; {

auto unsigned __8369_19_i; auto unsigned __8369_26_k; __8369_19_i = 0U; __8369_26_k = 0U; for (; ((unsigned long)__8369_19_i) < 14UL; ++__8369_19_i) {
auto char __8370_12_curr_char; __8370_12_curr_char = ((__8366_16_func_call_expanded)[__8369_19_i]);

if ((((int)__8370_12_curr_char) == 32) || (((int)__8370_12_curr_char) == 40)) {
((__8367_10_func_call_result)[__8369_26_k]) = ((char)0);
goto __T829092664;
}
((__8367_10_func_call_result)[(__8369_26_k++)]) = __8370_12_curr_char;
} __T829092664:; }
printf(((const char *)"#define TARG_SETJMP_FUNC \"%s\"\n"), (__8367_10_func_call_result));
}
# 633
{ auto const char *__8385_17_type_string;
__8385_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(8, 1));
if (__8385_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_INT8_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__8385_17_type_string, ((const char *)"signed char"))) == 0) {

} else  {
printf(((const char *)"#define EDG_INT8_T %s\n"), __8385_17_type_string);
} }
}
{ auto const char *__8396_17_type_string;
__8396_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(8, 0));
if (__8396_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_UINT8_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__8396_17_type_string, ((const char *)"unsigned char"))) == 0) {

} else  {
printf(((const char *)"#define EDG_UINT8_T %s\n"), __8396_17_type_string);
} }
}
{ auto const char *__8407_17_type_string;
__8407_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(16, 1));
if (__8407_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_INT16_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__8407_17_type_string, ((const char *)"short"))) == 0) {

} else  {
printf(((const char *)"#define EDG_INT16_T %s\n"), __8407_17_type_string);
} }
}
{ auto const char *__8418_17_type_string;
__8418_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(16, 0));
if (__8418_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_UINT16_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__8418_17_type_string, ((const char *)"unsigned short"))) == 0) {

} else  {
printf(((const char *)"#define EDG_UINT16_T %s\n"), __8418_17_type_string);
} }
}
{ auto const char *__8429_17_type_string;
__8429_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(32, 1));
if (__8429_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_INT32_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__8429_17_type_string, ((const char *)"int"))) == 0) {

} else  {
printf(((const char *)"#define EDG_INT32_T %s\n"), __8429_17_type_string);
} }
}
{ auto const char *__8440_17_type_string;
__8440_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(32, 0));
if (__8440_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_UINT32_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__8440_17_type_string, ((const char *)"unsigned int"))) == 0) {

} else  {
printf(((const char *)"#define EDG_UINT32_T %s\n"), __8440_17_type_string);
} }
}
return 0;
}
