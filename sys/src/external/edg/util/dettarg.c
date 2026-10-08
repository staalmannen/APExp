/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:16 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "util/dettarg.c"
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
#line 171 "util/dettarg.c"
enum int_kind {
ik_char,
ik_short,
ik_int,
ik_long,
ik_long_long};
#line 407
struct _ZZ4mainEUt_;
#line 413
struct _ZZ4mainEUt0_;
#line 419
struct _ZZ4mainEUt1_;
#line 434
struct _ZZ4mainEUt2_;
#line 441
struct _ZZ4mainEUt3_;
#line 447
struct _ZZ4mainEUt4_;
#line 454
struct _ZZ4mainEUt5_;
#line 467
struct _ZZ4mainEUt6_;
#line 488
struct _ZZ4mainEUt7_;
#line 508
struct _ZZ4mainEUt8_;
#line 573
struct _ZZ4mainENUt9_Ut_E; struct _ZZ4mainEUt9_;




struct _ZZ4mainEUt10_;
#line 4 "ape-arch/stddef_arch.h"
typedef long long _ptrdiff_t;
#line 10
typedef unsigned long long size_t;
#line 20 "ape-sys/stddef.h"
typedef _ptrdiff_t ptrdiff_t;
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 10 "ape-sys/setjmp.h"
typedef int jmp_buf[20];
#line 407 "util/dettarg.c"
struct _ZZ4mainEUt_ { char c; short s;};
#line 413
struct _ZZ4mainEUt0_ { char c; int s;};
#line 419
struct _ZZ4mainEUt1_ { char c; long s;};
#line 434
struct _ZZ4mainEUt2_ { char c; char *s;};
#line 441
struct _ZZ4mainEUt3_ { char c; float s;};
#line 447
struct _ZZ4mainEUt4_ { char c; double s;};
#line 454
struct _ZZ4mainEUt5_ { char c; long double s;};
#line 467
struct _ZZ4mainEUt6_ { char c; unsigned s;};
#line 488
struct _ZZ4mainEUt7_ { char c; size_t s;};
#line 508
struct _ZZ4mainEUt8_ { char c; ptrdiff_t s;};
#line 573
struct _ZZ4mainENUt9_Ut_E { char d;}; struct _ZZ4mainEUt9_ { char c; struct _ZZ4mainENUt9_Ut_E s;};




struct _ZZ4mainEUt10_ { char c; jmp_buf s;};
#line 71 "ape-sys/stdio.h"
extern int fprintf(FILE *, const char *, ...);

extern int printf(const char *, ...);
#line 19 "ape-sys/string.h"
extern int strcmp(const char *, const char *);
#line 145 "util/dettarg.c"
static unsigned long _ZN26_INTERNAL_9_dettarg_c_main8bit_maskEi(int nbits);
#line 157
static unsigned long _ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(char *p2, char *p1);
#line 180
static const char *_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi(enum int_kind kind, int is_signed);
#line 236
static unsigned long _ZN26_INTERNAL_9_dettarg_c_main16int_kind_to_sizeE8int_kind(enum int_kind kind);
#line 267
static enum int_kind _ZN26_INTERNAL_9_dettarg_c_main22int_kind_for_alignmentEmPi(unsigned long alignment, int *error);
#line 297
static const char *_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(unsigned long size, unsigned long alignment, int is_signed, int favor_long, int *error);
#line 342
static const char *_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(int size, int is_signed);
#line 365
extern int main(void);
#line 53 "ape-sys/stdio.h"
extern FILE *stderr;
#line 103 "util/dettarg.c"
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
#line 141
static int targ_char_bit;



static unsigned long _ZN26_INTERNAL_9_dettarg_c_main8bit_maskEi( int __1575_35_nbits)

{
auto unsigned long __1578_17_i; auto unsigned long __1578_20_j;
__1578_17_i = 1UL;
__1578_17_i <<= (__1575_35_nbits - 1);
__1578_20_j = (__1578_17_i - 1UL);
__1578_17_i |= __1578_20_j;
return __1578_17_i;
}


static unsigned long _ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_( char *__1587_38_p2,  char *__1587_48_p1)

{
auto unsigned long __1590_17_align;
auto unsigned long __1591_17_diff; __1591_17_diff = ((unsigned long)(__1587_38_p2 - __1587_48_p1));

for (__1590_17_align = 1UL; (__1591_17_diff & __1590_17_align) == 0UL; __1590_17_align *= 2UL) { }
return __1590_17_align;
}
#line 180
static const char *_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi( enum int_kind __1610_50_kind, 
int __1611_50_is_signed)
#line 187
{
auto const char *__1618_15_result;

switch ((int)__1610_50_kind) {
case 0:
if (__1611_50_is_signed == (-1)) {
__1618_15_result = ((const char *)"ik_char");
} else  { if (__1611_50_is_signed == 1) {
__1618_15_result = ((const char *)"ik_signed_char");
} else  {
__1618_15_result = ((const char *)"ik_unsigned_char");
} }
goto __T220279352;
case 1:
if (__1611_50_is_signed == 1) {
__1618_15_result = ((const char *)"ik_short");
} else  {
__1618_15_result = ((const char *)"ik_unsigned_short");
}
goto __T220279352;
case 2:
if (__1611_50_is_signed == 1) {
__1618_15_result = ((const char *)"ik_int");
} else  {
__1618_15_result = ((const char *)"ik_unsigned_int");
}
goto __T220279352;
case 3:
if (__1611_50_is_signed == 1) {
__1618_15_result = ((const char *)"ik_long");
} else  {
__1618_15_result = ((const char *)"ik_unsigned_long");
}
goto __T220279352;
case 4:
if (__1611_50_is_signed == 1) {
__1618_15_result = ((const char *)"ik_long_long");
} else  {
__1618_15_result = ((const char *)"ik_unsigned_long_long");
}
goto __T220279352;
default:
__1618_15_result = ((const char *)"<error>");
goto __T220279352;
} __T220279352:;
return __1618_15_result;
}


static unsigned long _ZN26_INTERNAL_9_dettarg_c_main16int_kind_to_sizeE8int_kind( enum int_kind __1666_48_kind)

{
auto unsigned long __1669_17_result;

switch ((int)__1666_48_kind) {
case 0:
__1669_17_result = 1UL;
goto __T220296136;
case 1:
__1669_17_result = targ_sizeof_short;
goto __T220296136;
case 2:
__1669_17_result = targ_sizeof_int;
goto __T220296136;
case 3:
__1669_17_result = targ_sizeof_long;
goto __T220296136;
#line 259
default:
__1669_17_result = 0UL;
goto __T220296136;
} __T220296136:;
return __1669_17_result;
}


static enum int_kind _ZN26_INTERNAL_9_dettarg_c_main22int_kind_for_alignmentEmPi( unsigned long __1697_54_alignment, 
int *__1698_55_error)




{
auto enum int_kind __1704_12_result;

(*__1698_55_error) = 0;
if (__1697_54_alignment == 1UL) {
__1704_12_result = ik_char;
} else  { if (__1697_54_alignment == targ_alignof_short) {
__1704_12_result = ik_short;
} else  { if (__1697_54_alignment == targ_alignof_int) {
__1704_12_result = ik_int;
} else  { if (__1697_54_alignment == targ_alignof_long) {
__1704_12_result = ik_long;




} else  {
(*__1698_55_error) = 1;
__1704_12_result = ik_int;
} } } }
return __1704_12_result;
}


static const char *_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi( unsigned long __1727_61_size, 
unsigned long __1728_61_alignment, 
int __1729_61_is_signed, 
int __1730_61_favor_long, 
int *__1731_62_error)
#line 309
{
auto const char *__1740_15_result;
auto enum int_kind __1741_14_kind;

(*__1731_62_error) = 0;
if ((__1727_61_size == 1UL) && (__1728_61_alignment == 1UL)) {
__1741_14_kind = ik_char;
} else  { if ((__1727_61_size == targ_sizeof_short) && (__1728_61_alignment == targ_alignof_short)) {
__1741_14_kind = ik_short;
} else  { if (((__1730_61_favor_long) && (__1727_61_size == targ_sizeof_long)) && (__1728_61_alignment == targ_alignof_long))
{
__1741_14_kind = ik_long;
} else  { if ((__1727_61_size == targ_sizeof_int) && (__1728_61_alignment == targ_alignof_int)) {
__1741_14_kind = ik_int;
} else  { if ((__1727_61_size == targ_sizeof_long) && (__1728_61_alignment == targ_alignof_long)) {
__1741_14_kind = ik_long;
#line 330
} else  {
(*__1731_62_error) = 1;
} } } } }
if (*__1731_62_error) {
__1740_15_result = ((const char *)"");
} else  {
__1740_15_result = (_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi(__1741_14_kind, __1729_61_is_signed));
}
return __1740_15_result;
}


static const char *_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii( int __1772_47_size, 
int __1773_47_is_signed)
#line 349
{
auto const char *__1780_15_result = ((const char *)0);

if (((unsigned long long)__1772_47_size) == (1ULL * ((unsigned long long)targ_char_bit))) {
__1780_15_result = ((__1773_47_is_signed) ? ((const char *)("signed char")) : ((const char *)("unsigned char")));
} else  { if (((unsigned long long)__1772_47_size) == (2ULL * ((unsigned long long)targ_char_bit))) {
__1780_15_result = ((__1773_47_is_signed) ? ((const char *)("short")) : ((const char *)("unsigned short")));
} else  { if (((unsigned long long)__1772_47_size) == (4ULL * ((unsigned long long)targ_char_bit))) {
__1780_15_result = ((__1773_47_is_signed) ? ((const char *)("int")) : ((const char *)("unsigned int")));
} else  { if (((unsigned long long)__1772_47_size) == (4ULL * ((unsigned long long)targ_char_bit))) {
__1780_15_result = ((__1773_47_is_signed) ? ((const char *)("long")) : ((const char *)("unsigned long")));
} } } }
return __1780_15_result;
}


int main(void) {
auto long __1796_8_i;
auto unsigned long __1797_17_ui;
auto unsigned char __1798_17_uch;
auto unsigned long __1799_17_targ_uchar_max;
auto unsigned long __1800_17_targ_minimum_struct_alignment;
auto char __1801_8_ch;

printf(((const char *)"/* Configuration definitions determined by dettarg.c: */\n"));

__1796_8_i = 1L;
if (((int)(*((char *)(&__1796_8_i)))) == 1) {
printf(((const char *)"#define TARG_LITTLE_ENDIAN TRUE\n"));
} else  {
printf(((const char *)"#define TARG_LITTLE_ENDIAN FALSE\n"));
}

for (targ_char_bit = 1; ; targ_char_bit++)

{
__1797_17_ui = (1UL << ((unsigned long)targ_char_bit));
__1798_17_uch = ((unsigned char)__1797_17_ui);
if (((unsigned long)__1798_17_uch) != __1797_17_ui) { goto __T220414456; }
} __T220414456:;
printf(((const char *)"#define TARG_CHAR_BIT %d\n"), targ_char_bit);
__1799_17_targ_uchar_max = (_ZN26_INTERNAL_9_dettarg_c_main8bit_maskEi(targ_char_bit));
__1801_8_ch = ((char)__1799_17_targ_uchar_max);
if (((int)__1801_8_ch) < 0) {

printf(((const char *)"#define TARG_HAS_SIGNED_CHARS TRUE\n"));
} else  {

printf(((const char *)"#define TARG_HAS_SIGNED_CHARS FALSE\n"));
}

__1796_8_i = 24930L;
if (__1796_8_i == ((long)((97 << targ_char_bit) | 98))) {
printf(((const char *)"#define TARG_CHAR_CONSTANT_FIRST_CHAR_MOST_SIGNIFICANT TRUE\n"));
} else  {
printf(((const char *)"#define TARG_CHAR_CONSTANT_FIRST_CHAR_MOST_SIGNIFICANT FALSE\n"));
}

{ auto struct _ZZ4mainEUt_ __1837_31_v;
targ_sizeof_short = 2UL;
targ_alignof_short = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1837_31_v.s))), ((char *)(&__1837_31_v))));
printf(((const char *)"#define TARG_SIZEOF_SHORT %lu\n"), targ_sizeof_short);
printf(((const char *)"#define TARG_ALIGNOF_SHORT %lu\n"), targ_alignof_short);
}
{ auto struct _ZZ4mainEUt0_ __1843_29_v;
targ_sizeof_int = 4UL;
targ_alignof_int = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1843_29_v.s))), ((char *)(&__1843_29_v))));
printf(((const char *)"#define TARG_SIZEOF_INT %lu\n"), targ_sizeof_int);
printf(((const char *)"#define TARG_ALIGNOF_INT %lu\n"), targ_alignof_int);
}
{ auto struct _ZZ4mainEUt1_ __1849_30_v;
targ_sizeof_long = 4UL;
targ_alignof_long = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1849_30_v.s))), ((char *)(&__1849_30_v))));
printf(((const char *)"#define TARG_SIZEOF_LONG %lu\n"), targ_sizeof_long);
printf(((const char *)"#define TARG_ALIGNOF_LONG %lu\n"), targ_alignof_long);
}
#line 434
{ auto struct _ZZ4mainEUt2_ __1864_31_v;
targ_sizeof_pointer = 8UL;
targ_alignof_pointer = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1864_31_v.s))), ((char *)(&__1864_31_v))));
printf(((const char *)"#define TARG_SIZEOF_POINTER %lu\n"), targ_sizeof_pointer);
printf(((const char *)"#define TARG_ALIGNOF_POINTER %lu\n"), targ_alignof_pointer);
}

{ auto struct _ZZ4mainEUt3_ __1871_31_v;
targ_sizeof_float = 4UL;
targ_alignof_float = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1871_31_v.s))), ((char *)(&__1871_31_v))));
printf(((const char *)"#define TARG_SIZEOF_FLOAT %lu\n"), targ_sizeof_float);
printf(((const char *)"#define TARG_ALIGNOF_FLOAT %lu\n"), targ_alignof_float);
}
{ auto struct _ZZ4mainEUt4_ __1877_32_v;
targ_sizeof_double = 8UL;
targ_alignof_double = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1877_32_v.s))), ((char *)(&__1877_32_v))));
printf(((const char *)"#define TARG_SIZEOF_DOUBLE %lu\n"), targ_sizeof_double);
printf(((const char *)"#define TARG_ALIGNOF_DOUBLE %lu\n"), targ_alignof_double);
}

{ auto struct _ZZ4mainEUt5_ __1884_37_v;
targ_sizeof_long_double = 8UL;
targ_alignof_long_double = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1884_37_v.s))), ((char *)(&__1884_37_v))));
printf(((const char *)"#define TARG_SIZEOF_LONG_DOUBLE %lu\n"), targ_sizeof_long_double);
printf(((const char *)"#define TARG_ALIGNOF_LONG_DOUBLE %lu\n"), targ_alignof_long_double);
}
#line 467
{ auto struct _ZZ4mainEUt6_ __1897_33_v;
auto const char *__1898_34_targ_wchar_t_int_kind;
auto int __1899_33_is_signed; auto int __1899_44_error;
targ_sizeof_wchar_t = 4UL;
targ_alignof_wchar_t = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1897_33_v.s))), ((char *)(&__1897_33_v))));
__1899_33_is_signed = 0;
__1898_34_targ_wchar_t_int_kind = (_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(targ_sizeof_wchar_t, targ_alignof_wchar_t, __1899_33_is_signed, 1, (&__1899_44_error)));




if (__1899_44_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_WCHAR_T_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
printf(((const char *)"#define TARG_WCHAR_T_INT_KIND ((an_integer_kind)%s)\n"), __1898_34_targ_wchar_t_int_kind);

}
}


{ auto struct _ZZ4mainEUt7_ __1918_32_v;
auto const char *__1919_34_targ_size_t_int_kind;
auto int __1920_33_error;
targ_sizeof_size_t = 8UL;
targ_alignof_size_t = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1918_32_v.s))), ((char *)(&__1918_32_v))));
__1919_34_targ_size_t_int_kind = (_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(targ_sizeof_size_t, targ_alignof_size_t, 0, 0, (&__1920_33_error)));




if (__1920_33_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_SIZE_T_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
printf(((const char *)"#define TARG_SIZE_T_INT_KIND ((an_integer_kind)%s)\n"), __1919_34_targ_size_t_int_kind);

}
}


{ auto struct _ZZ4mainEUt8_ __1938_35_v;
auto const char *__1939_34_targ_ptrdiff_t_int_kind;
auto int __1940_33_error;
targ_sizeof_ptrdiff_t = 8UL;
targ_alignof_ptrdiff_t = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__1938_35_v.s))), ((char *)(&__1938_35_v))));
__1939_34_targ_ptrdiff_t_int_kind = (_ZN26_INTERNAL_9_dettarg_c_main26int_kind_for_integral_typeEmmiiPi(targ_sizeof_ptrdiff_t, targ_alignof_ptrdiff_t, 1, 0, (&__1940_33_error)));
#line 519
if (__1940_33_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_PTRDIFF_T_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
printf(((const char *)"#define TARG_PTRDIFF_T_INT_KIND ((an_integer_kind)%s)\n"), __1939_34_targ_ptrdiff_t_int_kind);

}
}

{ auto unsigned long __1958_19_max_alignment = 1UL;
if (__1958_19_max_alignment < targ_alignof_short) { __1958_19_max_alignment = targ_alignof_short; }
if (__1958_19_max_alignment < targ_alignof_int) { __1958_19_max_alignment = targ_alignof_int; }
if (__1958_19_max_alignment < targ_alignof_long) { __1958_19_max_alignment = targ_alignof_long; }
if (__1958_19_max_alignment < targ_alignof_pointer) {
__1958_19_max_alignment = targ_alignof_pointer;
}
#line 544
printf(((const char *)"#define HOST_ALIGNMENT_REQUIRED %lu\n"), __1958_19_max_alignment);
}

if (0) {

printf(((const char *)"#define TARG_RIGHT_SHIFT_IS_ARITHMETIC FALSE\n"));
} else  {
printf(((const char *)"#define TARG_RIGHT_SHIFT_IS_ARITHMETIC TRUE\n"));
}

{ auto int __1984_9_i = 16;
auto int __1985_9_j; __1985_9_j = ((int)((targ_sizeof_int * ((unsigned long)targ_char_bit)) + 1UL));
if (__1985_9_j == 33) {


__1984_9_i = 0;
} else  {
__1984_9_i = (__1984_9_i >> __1985_9_j);
}
if (__1984_9_i == 8) {

printf(((const char *)"#define TARG_TOO_LARGE_SHIFT_COUNT_IS_TAKEN_MODULO_SIZE TRUE\n"));
} else  {


printf(((const char *)"#define TARG_TOO_LARGE_SHIFT_COUNT_IS_TAKEN_MODULO_SIZE FALSE\n"));

}
}
{ auto struct _ZZ4mainEUt9_ __2003_46_v;
__1800_17_targ_minimum_struct_alignment = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__2003_46_v.s))), ((char *)(&__2003_46_v))));
printf(((const char *)"#define TARG_MINIMUM_STRUCT_ALIGNMENT %lu\n"), __1800_17_targ_minimum_struct_alignment);

}
{ auto struct _ZZ4mainEUt10_ __2008_35_v;
auto unsigned long __2009_19_alignof_jmp_buf;
auto int __2010_19_error;
auto enum int_kind __2011_19_buffer_type;
#line 579
__2009_19_alignof_jmp_buf = (_ZN26_INTERNAL_9_dettarg_c_main9alignmentEPcS0_(((char *)(&(__2008_35_v.s))), ((char *)(&__2008_35_v))));



__2011_19_buffer_type = (_ZN26_INTERNAL_9_dettarg_c_main22int_kind_for_alignmentEmPi(__2009_19_alignof_jmp_buf, (&__2010_19_error)));
if (__2010_19_error) {
fprintf(stderr, ((const char *)"Unable to determine TARG_JMP_BUF_NUM_ELEMENTS.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
fprintf(stderr, ((const char *)"Unable to determine TARG_JMP_BUF_ELEMENT_INT_KIND.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  {
auto unsigned long __2020_21_buffer_element_size;
auto unsigned long __2021_21_buffer_element_count;

auto int __2023_16_buffer_overflow;
#line 590
__2020_21_buffer_element_size = (_ZN26_INTERNAL_9_dettarg_c_main16int_kind_to_sizeE8int_kind(__2011_19_buffer_type));
__2021_21_buffer_element_count = ((unsigned long)(80ULL / ((unsigned long long)__2020_21_buffer_element_size)));

__2023_16_buffer_overflow = ((int)((80ULL % ((unsigned long long)__2020_21_buffer_element_size)) != 0ULL));



if (__2023_16_buffer_overflow) {
++__2021_21_buffer_element_count;
}
printf(((const char *)"#define TARG_JMP_BUF_NUM_ELEMENTS %lu\n"), __2021_21_buffer_element_count);
printf(((const char *)"#define TARG_JMP_BUF_ELEMENTS_ARE_FLOAT 0\n"));
printf(((const char *)"#define TARG_JMP_BUF_ELEMENT_INT_KIND ((an_integer_kind)%s)\n"), (_ZN26_INTERNAL_9_dettarg_c_main20int_kind_to_type_strE8int_kindi(__2011_19_buffer_type, (-1))));

}
}
#line 631
printf(((const char *)"#define TARG_SETJMP_FUNC \"setjmp\"\n"));

{ auto const char *__2063_17_type_string;
__2063_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(8, 1));
if (__2063_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_INT8_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__2063_17_type_string, ((const char *)"signed char"))) == 0) {

} else  {
printf(((const char *)"#define EDG_INT8_T %s\n"), __2063_17_type_string);
} }
}
{ auto const char *__2074_17_type_string;
__2074_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(8, 0));
if (__2074_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_UINT8_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__2074_17_type_string, ((const char *)"unsigned char"))) == 0) {

} else  {
printf(((const char *)"#define EDG_UINT8_T %s\n"), __2074_17_type_string);
} }
}
{ auto const char *__2085_17_type_string;
__2085_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(16, 1));
if (__2085_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_INT16_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__2085_17_type_string, ((const char *)"short"))) == 0) {

} else  {
printf(((const char *)"#define EDG_INT16_T %s\n"), __2085_17_type_string);
} }
}
{ auto const char *__2096_17_type_string;
__2096_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(16, 0));
if (__2096_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_UINT16_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__2096_17_type_string, ((const char *)"unsigned short"))) == 0) {

} else  {
printf(((const char *)"#define EDG_UINT16_T %s\n"), __2096_17_type_string);
} }
}
{ auto const char *__2107_17_type_string;
__2107_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(32, 1));
if (__2107_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_INT32_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__2107_17_type_string, ((const char *)"int"))) == 0) {

} else  {
printf(((const char *)"#define EDG_INT32_T %s\n"), __2107_17_type_string);
} }
}
{ auto const char *__2118_17_type_string;
__2118_17_type_string = (_ZN26_INTERNAL_9_dettarg_c_main21type_for_integer_sizeEii(32, 0));
if (__2118_17_type_string == ((const char *)0)) {
fprintf(stderr, ((const char *)"Unable to determine EDG_UINT32_T.\n"));
fprintf(stderr, ((const char *)"(It will have to be done manually.)\n"));
} else  { if ((strcmp(__2118_17_type_string, ((const char *)"unsigned int"))) == 0) {

} else  {
printf(((const char *)"#define EDG_UINT32_T %s\n"), __2118_17_type_string);
} }
}
return 0;
}
