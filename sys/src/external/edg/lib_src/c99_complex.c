/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:41 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/c99_complex.c"
#line 21
struct _Complex_float;
#line 27
struct _Complex_double;
#line 33
struct _Complex_long_double;
#line 40
struct _Complex_float16;
#line 48
struct _Complex_bfloat16;
#line 56
struct _Complex_float80;
#line 63
struct _Complex_float128;
#line 21
struct _Complex_float {

float _Vals[2];};
typedef struct _Complex_float _Complex_float;


struct _Complex_double {

double _Vals[2];};
typedef struct _Complex_double _Complex_double;


struct _Complex_long_double {

long double _Vals[2];};
typedef struct _Complex_long_double _Complex_long_double;



struct _Complex_float16 {

_Float16 _Vals[2];};
typedef struct _Complex_float16 _Complex_float16;



typedef __bf16 _EDG_bfloat16_t;
struct _Complex_bfloat16 {


_EDG_bfloat16_t _Vals[2];};
typedef struct _Complex_bfloat16 _Complex_bfloat16;



struct _Complex_float80 {

__float80 _Vals[2];};
typedef struct _Complex_float80 _Complex_float80;



struct _Complex_float128 {

__float128 _Vals[2];};
typedef struct _Complex_float128 _Complex_float128;
#line 214
extern _Complex_float16 __c99_complex_float16_negate(_Complex_float16 z);
extern _Complex_float16 __c99_complex_float16_conj(_Complex_float16 z);
extern _Complex_float16 __c99_complex_float16_add(_Complex_float16 z1, _Complex_float16 z2);

extern _Complex_float16 __c99_complex_float16_subtract(_Complex_float16 z1, _Complex_float16 z2);

extern _Complex_float16 __c99_complex_float16_multiply(_Complex_float16 z1, _Complex_float16 z2);

extern _Complex_float16 __c99_complex_float16_divide(_Complex_float16 z1, _Complex_float16 z2);

extern int __c99_complex_float16_eq(_Complex_float16 z1, _Complex_float16 z2);
extern int __c99_complex_float16_ne(_Complex_float16 z1, _Complex_float16 z2);
extern _Complex_float16 __c99_ifloat16_to_cfloat16(_Float16 j);
extern _Complex_float16 __c99_float16_to_cfloat16(_Float16 j);
extern _Float16 __c99_cfloat16_to_ifloat16(_Complex_float16 z);
extern _Float16 __c99_cfloat16_to_float16(_Complex_float16 z);

extern _Complex_bfloat16 __c99_cfloat16_to_cbfloat16(_Complex_float16 z);


extern _Complex_float __c99_cfloat16_to_cfloat(_Complex_float16 z);
extern _Complex_double __c99_cfloat16_to_cdouble(_Complex_float16 z);
extern _Complex_long_double __c99_cfloat16_to_clong_double(_Complex_float16 z);
#line 242
extern _Complex_bfloat16 __c99_complex_bfloat16_negate(_Complex_bfloat16 z);
extern _Complex_bfloat16 __c99_complex_bfloat16_conj(_Complex_bfloat16 z);
extern _Complex_bfloat16 __c99_complex_bfloat16_add(_Complex_bfloat16 z1, _Complex_bfloat16 z2);

extern _Complex_bfloat16 __c99_complex_bfloat16_subtract(_Complex_bfloat16 z1, _Complex_bfloat16 z2);

extern _Complex_bfloat16 __c99_complex_bfloat16_multiply(_Complex_bfloat16 z1, _Complex_bfloat16 z2);

extern _Complex_bfloat16 __c99_complex_bfloat16_divide(_Complex_bfloat16 z1, _Complex_bfloat16 z2);

extern int __c99_complex_bfloat16_eq(_Complex_bfloat16 z1, _Complex_bfloat16 z2);
extern int __c99_complex_bfloat16_ne(_Complex_bfloat16 z1, _Complex_bfloat16 z2);
extern _Complex_bfloat16 __c99_ibfloat16_to_cbfloat16(_EDG_bfloat16_t j);
extern _Complex_bfloat16 __c99_bfloat16_to_cbfloat16(_EDG_bfloat16_t j);
extern _EDG_bfloat16_t __c99_cbfloat16_to_ibfloat16(_Complex_bfloat16 z);
extern _EDG_bfloat16_t __c99_cbfloat16_to_bfloat16(_Complex_bfloat16 z);

extern _Complex_float16 __c99_cbfloat16_to_cfloat16(_Complex_bfloat16 z);


extern _Complex_float __c99_cbfloat16_to_cfloat(_Complex_bfloat16 z);
extern _Complex_double __c99_cbfloat16_to_cdouble(_Complex_bfloat16 z);

extern _Complex_long_double __c99_cbfloat16_to_clong_double(_Complex_bfloat16 z);
#line 271
extern _Complex_float80 __c99_cbfloat16_to_cfloat80(_Complex_bfloat16 z);
#line 277
extern _Complex_float128 __c99_cbfloat16_to_cfloat128(_Complex_bfloat16 z);
#line 283
extern _Complex_float __c99_complex_float_negate(_Complex_float z);
extern _Complex_float __c99_complex_float_conj(_Complex_float z);
extern _Complex_float __c99_complex_float_add(_Complex_float z1, _Complex_float z2);

extern _Complex_float __c99_complex_float_subtract(_Complex_float z1, _Complex_float z2);

extern _Complex_float __c99_complex_float_multiply(_Complex_float z1, _Complex_float z2);

extern _Complex_float __c99_complex_float_divide(_Complex_float z1, _Complex_float z2);

extern int __c99_complex_float_eq(_Complex_float z1, _Complex_float z2);
extern int __c99_complex_float_ne(_Complex_float z1, _Complex_float z2);
extern _Complex_float __c99_ifloat_to_cfloat(float j);
extern _Complex_float __c99_float_to_cfloat(float j);
extern float __c99_cfloat_to_ifloat(_Complex_float z);
extern float __c99_cfloat_to_float(_Complex_float z);

extern _Complex_float16 __c99_cfloat_to_cfloat16(_Complex_float z);


extern _Complex_bfloat16 __c99_cfloat_to_cbfloat16(_Complex_float z);


extern _Complex_double __c99_cfloat_to_cdouble(_Complex_float z);
extern _Complex_long_double __c99_cfloat_to_clong_double(_Complex_float z);


extern _Complex_float80 __c99_cfloat_to_cfloat80(_Complex_float z);


extern _Complex_float128 __c99_cfloat_to_cfloat128(_Complex_float z);




extern _Complex_double __c99_complex_double_negate(_Complex_double z);
extern _Complex_double __c99_complex_double_conj(_Complex_double z);
extern _Complex_double __c99_complex_double_add(_Complex_double z1, _Complex_double z2);

extern _Complex_double __c99_complex_double_subtract(_Complex_double z1, _Complex_double z2);

extern _Complex_double __c99_complex_double_multiply(_Complex_double z1, _Complex_double z2);

extern _Complex_double __c99_complex_double_divide(_Complex_double z1, _Complex_double z2);

extern int __c99_complex_double_eq(_Complex_double z1, _Complex_double z2);
extern int __c99_complex_double_ne(_Complex_double z1, _Complex_double z2);
extern _Complex_double __c99_idouble_to_cdouble(double j);
extern _Complex_double __c99_double_to_cdouble(double j);
extern double __c99_cdouble_to_idouble(_Complex_double z);
extern double __c99_cdouble_to_double(_Complex_double z);

extern _Complex_float16 __c99_cdouble_to_cfloat16(_Complex_double z);



extern _Complex_bfloat16 __c99_cdouble_to_cbfloat16(_Complex_double z);


extern _Complex_float __c99_cdouble_to_cfloat(_Complex_double z);
extern _Complex_long_double __c99_cdouble_to_clong_double(_Complex_double z);


extern _Complex_float80 __c99_cdouble_to_cfloat80(_Complex_double z);



extern _Complex_float128 __c99_cdouble_to_cfloat128(_Complex_double z);




extern _Complex_long_double __c99_complex_long_double_negate(_Complex_long_double z);

extern _Complex_long_double __c99_complex_long_double_conj(_Complex_long_double z);

extern _Complex_long_double __c99_complex_long_double_add(_Complex_long_double z1, _Complex_long_double z2);


extern _Complex_long_double __c99_complex_long_double_subtract(_Complex_long_double z1, _Complex_long_double z2);


extern _Complex_long_double __c99_complex_long_double_multiply(_Complex_long_double z1, _Complex_long_double z2);


extern _Complex_long_double __c99_complex_long_double_divide(_Complex_long_double z1, _Complex_long_double z2);


extern int __c99_complex_long_double_eq(_Complex_long_double z1, _Complex_long_double z2);

extern int __c99_complex_long_double_ne(_Complex_long_double z1, _Complex_long_double z2);

extern _Complex_long_double __c99_ilong_double_to_clong_double(long double j);
extern _Complex_long_double __c99_long_double_to_clong_double(long double j);
extern long double __c99_clong_double_to_ilong_double(_Complex_long_double z);
extern long double __c99_clong_double_to_long_double(_Complex_long_double z);

extern _Complex_float16 __c99_clong_double_to_cfloat16(_Complex_long_double z);



extern _Complex_bfloat16 __c99_clong_double_to_cbfloat16(_Complex_long_double z);



extern _Complex_float __c99_clong_double_to_cfloat(_Complex_long_double z);

extern _Complex_double __c99_clong_double_to_cdouble(_Complex_long_double z);


extern _Complex_float80 __c99_clong_double_to_cfloat80(_Complex_long_double z);



extern _Complex_float128 __c99_clong_double_to_cfloat128(_Complex_long_double z);
#line 403
extern _Complex_float80 __c99_complex_float80_negate(_Complex_float80 z);
extern _Complex_float80 __c99_complex_float80_conj(_Complex_float80 z);
extern _Complex_float80 __c99_complex_float80_add(_Complex_float80 z1, _Complex_float80 z2);

extern _Complex_float80 __c99_complex_float80_subtract(_Complex_float80 z1, _Complex_float80 z2);

extern _Complex_float80 __c99_complex_float80_multiply(_Complex_float80 z1, _Complex_float80 z2);

extern _Complex_float80 __c99_complex_float80_divide(_Complex_float80 z1, _Complex_float80 z2);

extern int __c99_complex_float80_eq(_Complex_float80 z1, _Complex_float80 z2);
extern int __c99_complex_float80_ne(_Complex_float80 z1, _Complex_float80 z2);
extern _Complex_float80 __c99_ifloat80_to_cfloat80(__float80 j);
extern _Complex_float80 __c99_float80_to_cfloat80(__float80 j);
extern __float80 __c99_cfloat80_to_ifloat80(_Complex_float80 z);
extern __float80 __c99_cfloat80_to_float80(_Complex_float80 z);

extern _Complex_float16 __c99_cfloat80_to_cfloat16(_Complex_float80 z);



extern _Complex_bfloat16 __c99_cfloat80_to_cbfloat16(_Complex_float80 z);


extern _Complex_float __c99_cfloat80_to_cfloat(_Complex_float80 z);
extern _Complex_double __c99_cfloat80_to_cdouble(_Complex_float80 z);
extern _Complex_long_double __c99_cfloat80_to_clong_double(_Complex_float80 z);


extern _Complex_float128 __c99_cfloat80_to_cfloat128(_Complex_float80 z);
#line 439
extern _Complex_float128 __c99_complex_float128_negate(_Complex_float128 z);
extern _Complex_float128 __c99_complex_float128_conj(_Complex_float128 z);
extern _Complex_float128 __c99_complex_float128_add(_Complex_float128 z1, _Complex_float128 z2);

extern _Complex_float128 __c99_complex_float128_subtract(_Complex_float128 z1, _Complex_float128 z2);

extern _Complex_float128 __c99_complex_float128_multiply(_Complex_float128 z1, _Complex_float128 z2);

extern _Complex_float128 __c99_complex_float128_divide(_Complex_float128 z1, _Complex_float128 z2);

extern int __c99_complex_float128_eq(_Complex_float128 z1, _Complex_float128 z2);
extern int __c99_complex_float128_ne(_Complex_float128 z1, _Complex_float128 z2);
extern _Complex_float128 __c99_ifloat128_to_cfloat128(__float128 j);
extern _Complex_float128 __c99_float128_to_cfloat128(__float128 j);
extern __float128 __c99_cfloat128_to_ifloat128(_Complex_float128 z);
extern __float128 __c99_cfloat128_to_float128(_Complex_float128 z);

extern _Complex_float16 __c99_cfloat128_to_cfloat16(_Complex_float128 z);



extern _Complex_bfloat16 __c99_cfloat128_to_cbfloat16(_Complex_float128 z);


extern _Complex_float __c99_cfloat128_to_cfloat(_Complex_float128 z);
extern _Complex_double __c99_cfloat128_to_cdouble(_Complex_float128 z);

extern _Complex_long_double __c99_cfloat128_to_clong_double(_Complex_float128 z);


extern _Complex_float80 __c99_cfloat128_to_cfloat80(_Complex_float128 z);
#line 214
_Complex_float16 __c99_complex_float16_negate( _Complex_float16 __332_1_z) { auto struct _Complex_float16 __T377679352; (((__332_1_z._Vals))[0]) = (-(((__332_1_z._Vals))[0])); (((__332_1_z._Vals))[1]) = (-(((__332_1_z._Vals))[1])); { __T377679352 = __332_1_z; return __T377679352; } }
_Complex_float16 __c99_complex_float16_conj( _Complex_float16 __333_1_z) { auto struct _Complex_float16 __T377683144; (((__333_1_z._Vals))[1]) = (-(((__333_1_z._Vals))[1])); { __T377683144 = __333_1_z; return __T377683144; } }
_Complex_float16 __c99_complex_float16_add( _Complex_float16 __334_1_z1,  _Complex_float16 __334_1_z2) { auto struct _Complex_float16 __T377752048; auto _Complex_float16 __334_1_r; (((__334_1_r._Vals))[0]) = ((((__334_1_z1._Vals))[0]) + (((__334_1_z2._Vals))[0])); (((__334_1_r._Vals))[1]) = ((((
#line 216
__334_1_z1._Vals))[1]) + (((__334_1_z2._Vals))[1])); { __T377752048 = __334_1_r; return __T377752048; } }

_Complex_float16 __c99_complex_float16_subtract( _Complex_float16 __336_1_z1,  _Complex_float16 __336_1_z2) { auto struct _Complex_float16 __T377759920; auto _Complex_float16 __336_1_r; (((__336_1_r._Vals))[0]) = ((((__336_1_z1._Vals))[0]) - (((__336_1_z2._Vals))[0])); (((__336_1_r._Vals))[1]) = (((
#line 218
(__336_1_z1._Vals))[1]) - (((__336_1_z2._Vals))[1])); { __T377759920 = __336_1_r; return __T377759920; } }

_Complex_float16 __c99_complex_float16_multiply( _Complex_float16 __338_1_z1,  _Complex_float16 __338_1_z2) { auto struct _Complex_float16 __T377771120; auto _Complex_float16 __338_1_r; (((__338_1_r._Vals))[0]) = (((((__338_1_z1._Vals))[0]) * (((__338_1_z2._Vals))[0])) - ((((__338_1_z1._Vals))[1]) * 
#line 220
(((__338_1_z2._Vals))[1]))); (((__338_1_r._Vals))[1]) = (((((__338_1_z1._Vals))[0]) * (((__338_1_z2._Vals))[1])) + ((((__338_1_z1._Vals))[1]) * (((__338_1_z2._Vals))[0]))); { __T377771120 = __338_1_r; return __T377771120; } }

_Complex_float16 __c99_complex_float16_divide( _Complex_float16 __340_1_z1,  _Complex_float16 __340_1_z2) { auto struct _Complex_float16 __T377787840; auto _Complex_float16 __340_1_r; auto _Float16 __340_1_d; __340_1_d = (((((__340_1_z2._Vals))[0]) * (((__340_1_z2._Vals))[0])) + ((((__340_1_z2._Vals
#line 222
))[1]) * (((__340_1_z2._Vals))[1]))); (((__340_1_r._Vals))[0]) = ((((((__340_1_z1._Vals))[0]) * (((__340_1_z2._Vals))[0])) + ((((__340_1_z1._Vals))[1]) * (((__340_1_z2._Vals))[1]))) / __340_1_d); (((__340_1_r._Vals))[1]) = ((((((__340_1_z1._Vals))[1]) * (((__340_1_z2._Vals))[0])) - ((((
#line 222
__340_1_z1._Vals))[0]) * (((__340_1_z2._Vals))[1]))) / __340_1_d); { __T377787840 = __340_1_r; return __T377787840; } }

int __c99_complex_float16_eq( _Complex_float16 __342_1_z1,  _Complex_float16 __342_1_z2) { return (int)(((((__342_1_z1._Vals))[0]) == (((__342_1_z2._Vals))[0])) && ((((__342_1_z1._Vals))[1]) == (((__342_1_z2._Vals))[1]))); }
int __c99_complex_float16_ne( _Complex_float16 __343_1_z1,  _Complex_float16 __343_1_z2) { return (int)(((((__343_1_z1._Vals))[0]) != (((__343_1_z2._Vals))[0])) || ((((__343_1_z1._Vals))[1]) != (((__343_1_z2._Vals))[1]))); }
_Complex_float16 __c99_ifloat16_to_cfloat16( _Float16 __344_1_j) { auto struct _Complex_float16 __T377802784; auto _Complex_float16 __344_1_r; (((__344_1_r._Vals))[0]) = (0.0F16); (((__344_1_r._Vals))[1]) = ((_Float16)__344_1_j); { __T377802784 = __344_1_r; return __T377802784; } }
_Complex_float16 __c99_float16_to_cfloat16( _Float16 __345_1_j) { auto struct _Complex_float16 __T377808016; auto _Complex_float16 __345_1_r; (((__345_1_r._Vals))[0]) = ((_Float16)__345_1_j); (((__345_1_r._Vals))[1]) = (0.0F16); { __T377808016 = __345_1_r; return __T377808016; } }
_Float16 __c99_cfloat16_to_ifloat16( _Complex_float16 __346_1_z) { return ((__346_1_z._Vals))[1]; }
_Float16 __c99_cfloat16_to_float16( _Complex_float16 __347_1_z) { return ((__347_1_z._Vals))[0]; }

_Complex_bfloat16 __c99_cfloat16_to_cbfloat16( _Complex_float16 __349_1_z) { auto struct _Complex_bfloat16 __T377951336; auto _Complex_bfloat16 __349_1_r; (((__349_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__349_1_z._Vals))[0])); (((__349_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__349_1_z._Vals))[1])); { 
#line 231
__T377951336 = __349_1_r; return __T377951336; } }


_Complex_float __c99_cfloat16_to_cfloat( _Complex_float16 __352_1_z) { auto struct _Complex_float __T377957360; auto _Complex_float __352_1_r; (((__352_1_r._Vals))[0]) = ((float)(((__352_1_z._Vals))[0])); (((__352_1_r._Vals))[1]) = ((float)(((__352_1_z._Vals))[1])); { __T377957360 = __352_1_r; 
#line 234
return __T377957360; } }
_Complex_double __c99_cfloat16_to_cdouble( _Complex_float16 __353_1_z) { auto struct _Complex_double __T377963384; auto _Complex_double __353_1_r; (((__353_1_r._Vals))[0]) = ((double)(((__353_1_z._Vals))[0])); (((__353_1_r._Vals))[1]) = ((double)(((__353_1_z._Vals))[1])); { __T377963384 = 
#line 235
__353_1_r; return __T377963384; } }
_Complex_long_double __c99_cfloat16_to_clong_double( _Complex_float16 __354_1_z) { auto struct _Complex_long_double __T377969408; auto _Complex_long_double __354_1_r; (((__354_1_r._Vals))[0]) = ((long double)(((__354_1_z._Vals))[0])); (((__354_1_r._Vals))[1]) = ((long double)(((__354_1_z._Vals))[1])
#line 236
); { __T377969408 = __354_1_r; return __T377969408; } }
#line 242
_Complex_bfloat16 __c99_complex_bfloat16_negate( _Complex_bfloat16 __360_1_z) { auto struct _Complex_bfloat16 __T377974952; (((__360_1_z._Vals))[0]) = (-(((__360_1_z._Vals))[0])); (((__360_1_z._Vals))[1]) = (-(((__360_1_z._Vals))[1])); { __T377974952 = __360_1_z; return __T377974952; } }
_Complex_bfloat16 __c99_complex_bfloat16_conj( _Complex_bfloat16 __361_1_z) { auto struct _Complex_bfloat16 __T377978744; (((__361_1_z._Vals))[1]) = (-(((__361_1_z._Vals))[1])); { __T377978744 = __361_1_z; return __T377978744; } }
_Complex_bfloat16 __c99_complex_bfloat16_add( _Complex_bfloat16 __362_1_z1,  _Complex_bfloat16 __362_1_z2) { auto struct _Complex_bfloat16 __T377986616; auto _Complex_bfloat16 __362_1_r; (((__362_1_r._Vals))[0]) = ((((__362_1_z1._Vals))[0]) + (((__362_1_z2._Vals))[0])); (((__362_1_r._Vals))[1]) = ((
#line 244
((__362_1_z1._Vals))[1]) + (((__362_1_z2._Vals))[1])); { __T377986616 = __362_1_r; return __T377986616; } }

_Complex_bfloat16 __c99_complex_bfloat16_subtract( _Complex_bfloat16 __364_1_z1,  _Complex_bfloat16 __364_1_z2) { auto struct _Complex_bfloat16 __T377994488; auto _Complex_bfloat16 __364_1_r; (((__364_1_r._Vals))[0]) = ((((__364_1_z1._Vals))[0]) - (((__364_1_z2._Vals))[0])); (((__364_1_r._Vals))[1]) 
#line 246
= ((((__364_1_z1._Vals))[1]) - (((__364_1_z2._Vals))[1])); { __T377994488 = __364_1_r; return __T377994488; } }

_Complex_bfloat16 __c99_complex_bfloat16_multiply( _Complex_bfloat16 __366_1_z1,  _Complex_bfloat16 __366_1_z2) { auto struct _Complex_bfloat16 __T378005688; auto _Complex_bfloat16 __366_1_r; (((__366_1_r._Vals))[0]) = (((((__366_1_z1._Vals))[0]) * (((__366_1_z2._Vals))[0])) - ((((__366_1_z1._Vals))
#line 248
[1]) * (((__366_1_z2._Vals))[1]))); (((__366_1_r._Vals))[1]) = (((((__366_1_z1._Vals))[0]) * (((__366_1_z2._Vals))[1])) + ((((__366_1_z1._Vals))[1]) * (((__366_1_z2._Vals))[0]))); { __T378005688 = __366_1_r; return __T378005688; } }

_Complex_bfloat16 __c99_complex_bfloat16_divide( _Complex_bfloat16 __368_1_z1,  _Complex_bfloat16 __368_1_z2) { auto struct _Complex_bfloat16 __T378026640; auto _Complex_bfloat16 __368_1_r; auto _EDG_bfloat16_t __368_1_d; __368_1_d = (((((__368_1_z2._Vals))[0]) * (((__368_1_z2._Vals))[0])) + ((((
#line 250
__368_1_z2._Vals))[1]) * (((__368_1_z2._Vals))[1]))); (((__368_1_r._Vals))[0]) = ((((((__368_1_z1._Vals))[0]) * (((__368_1_z2._Vals))[0])) + ((((__368_1_z1._Vals))[1]) * (((__368_1_z2._Vals))[1]))) / __368_1_d); (((__368_1_r._Vals))[1]) = ((((((__368_1_z1._Vals))[1]) * (((__368_1_z2._Vals))[0])) - (
#line 250
(((__368_1_z1._Vals))[0]) * (((__368_1_z2._Vals))[1]))) / __368_1_d); { __T378026640 = __368_1_r; return __T378026640; } }

int __c99_complex_bfloat16_eq( _Complex_bfloat16 __370_1_z1,  _Complex_bfloat16 __370_1_z2) { return (int)(((((__370_1_z1._Vals))[0]) == (((__370_1_z2._Vals))[0])) && ((((__370_1_z1._Vals))[1]) == (((__370_1_z2._Vals))[1]))); }
int __c99_complex_bfloat16_ne( _Complex_bfloat16 __371_1_z1,  _Complex_bfloat16 __371_1_z2) { return (int)(((((__371_1_z1._Vals))[0]) != (((__371_1_z2._Vals))[0])) || ((((__371_1_z1._Vals))[1]) != (((__371_1_z2._Vals))[1]))); }
_Complex_bfloat16 __c99_ibfloat16_to_cbfloat16( _EDG_bfloat16_t __372_1_j) { auto struct _Complex_bfloat16 __T378041584; auto _Complex_bfloat16 __372_1_r; (((__372_1_r._Vals))[0]) = (0.0bf16); (((__372_1_r._Vals))[1]) = ((_EDG_bfloat16_t)__372_1_j); { __T378041584 = __372_1_r; return __T378041584; } 
#line 254
}
_Complex_bfloat16 __c99_bfloat16_to_cbfloat16( _EDG_bfloat16_t __373_1_j) { auto struct _Complex_bfloat16 __T378046816; auto _Complex_bfloat16 __373_1_r; (((__373_1_r._Vals))[0]) = ((_EDG_bfloat16_t)__373_1_j); (((__373_1_r._Vals))[1]) = (0.0bf16); { __T378046816 = __373_1_r; return __T378046816; } 
#line 255
}
_EDG_bfloat16_t __c99_cbfloat16_to_ibfloat16( _Complex_bfloat16 __374_1_z) { return ((__374_1_z._Vals))[1]; }
_EDG_bfloat16_t __c99_cbfloat16_to_bfloat16( _Complex_bfloat16 __375_1_z) { return ((__375_1_z._Vals))[0]; }

_Complex_float16 __c99_cbfloat16_to_cfloat16( _Complex_bfloat16 __377_1_z) { auto struct _Complex_float16 __T378056408; auto _Complex_float16 __377_1_r; (((__377_1_r._Vals))[0]) = ((_Float16)(((__377_1_z._Vals))[0])); (((__377_1_r._Vals))[1]) = ((_Float16)(((__377_1_z._Vals))[1])); { __T378056408 = 
#line 259
__377_1_r; return __T378056408; } }


_Complex_float __c99_cbfloat16_to_cfloat( _Complex_bfloat16 __380_1_z) { auto struct _Complex_float __T378062432; auto _Complex_float __380_1_r; (((__380_1_r._Vals))[0]) = ((float)(((__380_1_z._Vals))[0])); (((__380_1_r._Vals))[1]) = ((float)(((__380_1_z._Vals))[1])); { __T378062432 = 
#line 262
__380_1_r; return __T378062432; } }
_Complex_double __c99_cbfloat16_to_cdouble( _Complex_bfloat16 __381_1_z) { auto struct _Complex_double __T378068456; auto _Complex_double __381_1_r; (((__381_1_r._Vals))[0]) = ((double)(((__381_1_z._Vals))[0])); (((__381_1_r._Vals))[1]) = ((double)(((__381_1_z._Vals))[1])); { __T378068456 = 
#line 263
__381_1_r; return __T378068456; } }

_Complex_long_double __c99_cbfloat16_to_clong_double( _Complex_bfloat16 __383_1_z) { auto struct _Complex_long_double __T378074480; auto _Complex_long_double __383_1_r; (((__383_1_r._Vals))[0]) = ((long double)(((__383_1_z._Vals))[0])); (((__383_1_r._Vals))[1]) = ((long double)(((__383_1_z._Vals))[1
#line 265
])); { __T378074480 = __383_1_r; return __T378074480; } }
#line 271
_Complex_float80 __c99_cbfloat16_to_cfloat80( _Complex_bfloat16 __389_1_z) { auto struct _Complex_float80 __T378081496; auto _Complex_float80 __389_1_r; (((__389_1_r._Vals))[0]) = ((__float80)(((__389_1_z._Vals))[0])); (((__389_1_r._Vals))[1]) = ((__float80)(((__389_1_z._Vals))[1])); { __T378081496 
#line 271
= __389_1_r; return __T378081496; } }
#line 277
_Complex_float128 __c99_cbfloat16_to_cfloat128( _Complex_bfloat16 __395_1_z) { auto struct _Complex_float128 __T378087520; auto _Complex_float128 __395_1_r; (((__395_1_r._Vals))[0]) = ((__float128)(((__395_1_z._Vals))[0])); (((__395_1_r._Vals))[1]) = ((__float128)(((__395_1_z._Vals))[1])); { 
#line 277
__T378087520 = __395_1_r; return __T378087520; } }
#line 283
_Complex_float __c99_complex_float_negate( _Complex_float __401_1_z) { auto struct _Complex_float __T378093064; (((__401_1_z._Vals))[0]) = (-(((__401_1_z._Vals))[0])); (((__401_1_z._Vals))[1]) = (-(((__401_1_z._Vals))[1])); { __T378093064 = __401_1_z; return __T378093064; } }
_Complex_float __c99_complex_float_conj( _Complex_float __402_1_z) { auto struct _Complex_float __T378096856; (((__402_1_z._Vals))[1]) = (-(((__402_1_z._Vals))[1])); { __T378096856 = __402_1_z; return __T378096856; } }
_Complex_float __c99_complex_float_add( _Complex_float __403_1_z1,  _Complex_float __403_1_z2) { auto struct _Complex_float __T378104728; auto _Complex_float __403_1_r; (((__403_1_r._Vals))[0]) = ((((__403_1_z1._Vals))[0]) + (((__403_1_z2._Vals))[0])); (((__403_1_r._Vals))[1]) = ((((__403_1_z1._Vals
#line 285
))[1]) + (((__403_1_z2._Vals))[1])); { __T378104728 = __403_1_r; return __T378104728; } }

_Complex_float __c99_complex_float_subtract( _Complex_float __405_1_z1,  _Complex_float __405_1_z2) { auto struct _Complex_float __T378112600; auto _Complex_float __405_1_r; (((__405_1_r._Vals))[0]) = ((((__405_1_z1._Vals))[0]) - (((__405_1_z2._Vals))[0])); (((__405_1_r._Vals))[1]) = ((((
#line 287
__405_1_z1._Vals))[1]) - (((__405_1_z2._Vals))[1])); { __T378112600 = __405_1_r; return __T378112600; } }

_Complex_float __c99_complex_float_multiply( _Complex_float __407_1_z1,  _Complex_float __407_1_z2) { auto struct _Complex_float __T378123800; auto _Complex_float __407_1_r; (((__407_1_r._Vals))[0]) = (((((__407_1_z1._Vals))[0]) * (((__407_1_z2._Vals))[0])) - ((((__407_1_z1._Vals))[1]) * (((
#line 289
__407_1_z2._Vals))[1]))); (((__407_1_r._Vals))[1]) = (((((__407_1_z1._Vals))[0]) * (((__407_1_z2._Vals))[1])) + ((((__407_1_z1._Vals))[1]) * (((__407_1_z2._Vals))[0]))); { __T378123800 = __407_1_r; return __T378123800; } }

_Complex_float __c99_complex_float_divide( _Complex_float __409_1_z1,  _Complex_float __409_1_z2) { auto struct _Complex_float __T378140520; auto _Complex_float __409_1_r; auto float __409_1_d; __409_1_d = (((((__409_1_z2._Vals))[0]) * (((__409_1_z2._Vals))[0])) + ((((__409_1_z2._Vals))[1]) * (((
#line 291
__409_1_z2._Vals))[1]))); (((__409_1_r._Vals))[0]) = ((((((__409_1_z1._Vals))[0]) * (((__409_1_z2._Vals))[0])) + ((((__409_1_z1._Vals))[1]) * (((__409_1_z2._Vals))[1]))) / __409_1_d); (((__409_1_r._Vals))[1]) = ((((((__409_1_z1._Vals))[1]) * (((__409_1_z2._Vals))[0])) - ((((__409_1_z1._Vals))[0]) * 
#line 291
(((__409_1_z2._Vals))[1]))) / __409_1_d); { __T378140520 = __409_1_r; return __T378140520; } }

int __c99_complex_float_eq( _Complex_float __411_1_z1,  _Complex_float __411_1_z2) { return (int)(((((__411_1_z1._Vals))[0]) == (((__411_1_z2._Vals))[0])) && ((((__411_1_z1._Vals))[1]) == (((__411_1_z2._Vals))[1]))); }
int __c99_complex_float_ne( _Complex_float __412_1_z1,  _Complex_float __412_1_z2) { return (int)(((((__412_1_z1._Vals))[0]) != (((__412_1_z2._Vals))[0])) || ((((__412_1_z1._Vals))[1]) != (((__412_1_z2._Vals))[1]))); }
_Complex_float __c99_ifloat_to_cfloat( float __413_1_j) { auto struct _Complex_float __T378155968; auto _Complex_float __413_1_r; (((__413_1_r._Vals))[0]) = (0.0F); (((__413_1_r._Vals))[1]) = ((float)__413_1_j); { __T378155968 = __413_1_r; return __T378155968; } }
_Complex_float __c99_float_to_cfloat( float __414_1_j) { auto struct _Complex_float __T378161200; auto _Complex_float __414_1_r; (((__414_1_r._Vals))[0]) = ((float)__414_1_j); (((__414_1_r._Vals))[1]) = (0.0F); { __T378161200 = __414_1_r; return __T378161200; } }
float __c99_cfloat_to_ifloat( _Complex_float __415_1_z) { return ((__415_1_z._Vals))[1]; }
float __c99_cfloat_to_float( _Complex_float __416_1_z) { return ((__416_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat_to_cfloat16( _Complex_float __418_1_z) { auto struct _Complex_float16 __T378170792; auto _Complex_float16 __418_1_r; (((__418_1_r._Vals))[0]) = ((_Float16)(((__418_1_z._Vals))[0])); (((__418_1_r._Vals))[1]) = ((_Float16)(((__418_1_z._Vals))[1])); { __T378170792 = 
#line 300
__418_1_r; return __T378170792; } }


_Complex_bfloat16 __c99_cfloat_to_cbfloat16( _Complex_float __421_1_z) { auto struct _Complex_bfloat16 __T378176816; auto _Complex_bfloat16 __421_1_r; (((__421_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__421_1_z._Vals))[0])); (((__421_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__421_1_z._Vals))[1])); { 
#line 303
__T378176816 = __421_1_r; return __T378176816; } }


_Complex_double __c99_cfloat_to_cdouble( _Complex_float __424_1_z) { auto struct _Complex_double __T378182840; auto _Complex_double __424_1_r; (((__424_1_r._Vals))[0]) = ((double)(((__424_1_z._Vals))[0])); (((__424_1_r._Vals))[1]) = ((double)(((__424_1_z._Vals))[1])); { __T378182840 = 
#line 306
__424_1_r; return __T378182840; } }
_Complex_long_double __c99_cfloat_to_clong_double( _Complex_float __425_1_z) { auto struct _Complex_long_double __T378188864; auto _Complex_long_double __425_1_r; (((__425_1_r._Vals))[0]) = ((long double)(((__425_1_z._Vals))[0])); (((__425_1_r._Vals))[1]) = ((long double)(((__425_1_z._Vals))[1])); { 
#line 307
__T378188864 = __425_1_r; return __T378188864; } }


_Complex_float80 __c99_cfloat_to_cfloat80( _Complex_float __428_1_z) { auto struct _Complex_float80 __T378194888; auto _Complex_float80 __428_1_r; (((__428_1_r._Vals))[0]) = ((__float80)(((__428_1_z._Vals))[0])); (((__428_1_r._Vals))[1]) = ((__float80)(((__428_1_z._Vals))[1])); { __T378194888 = 
#line 310
__428_1_r; return __T378194888; } }


_Complex_float128 __c99_cfloat_to_cfloat128( _Complex_float __431_1_z) { auto struct _Complex_float128 __T378200912; auto _Complex_float128 __431_1_r; (((__431_1_r._Vals))[0]) = ((__float128)(((__431_1_z._Vals))[0])); (((__431_1_r._Vals))[1]) = ((__float128)(((__431_1_z._Vals))[1])); { __T378200912 
#line 313
= __431_1_r; return __T378200912; } }




_Complex_double __c99_complex_double_negate( _Complex_double __436_1_z) { auto struct _Complex_double __T378206456; (((__436_1_z._Vals))[0]) = (-(((__436_1_z._Vals))[0])); (((__436_1_z._Vals))[1]) = (-(((__436_1_z._Vals))[1])); { __T378206456 = __436_1_z; return __T378206456; } }
_Complex_double __c99_complex_double_conj( _Complex_double __437_1_z) { auto struct _Complex_double __T378275920; (((__437_1_z._Vals))[1]) = (-(((__437_1_z._Vals))[1])); { __T378275920 = __437_1_z; return __T378275920; } }
_Complex_double __c99_complex_double_add( _Complex_double __438_1_z1,  _Complex_double __438_1_z2) { auto struct _Complex_double __T378283792; auto _Complex_double __438_1_r; (((__438_1_r._Vals))[0]) = ((((__438_1_z1._Vals))[0]) + (((__438_1_z2._Vals))[0])); (((__438_1_r._Vals))[1]) = ((((
#line 320
__438_1_z1._Vals))[1]) + (((__438_1_z2._Vals))[1])); { __T378283792 = __438_1_r; return __T378283792; } }

_Complex_double __c99_complex_double_subtract( _Complex_double __440_1_z1,  _Complex_double __440_1_z2) { auto struct _Complex_double __T378345552; auto _Complex_double __440_1_r; (((__440_1_r._Vals))[0]) = ((((__440_1_z1._Vals))[0]) - (((__440_1_z2._Vals))[0])); (((__440_1_r._Vals))[1]) = ((((
#line 322
__440_1_z1._Vals))[1]) - (((__440_1_z2._Vals))[1])); { __T378345552 = __440_1_r; return __T378345552; } }

_Complex_double __c99_complex_double_multiply( _Complex_double __442_1_z1,  _Complex_double __442_1_z2) { auto struct _Complex_double __T378356752; auto _Complex_double __442_1_r; (((__442_1_r._Vals))[0]) = (((((__442_1_z1._Vals))[0]) * (((__442_1_z2._Vals))[0])) - ((((__442_1_z1._Vals))[1]) * (((
#line 324
__442_1_z2._Vals))[1]))); (((__442_1_r._Vals))[1]) = (((((__442_1_z1._Vals))[0]) * (((__442_1_z2._Vals))[1])) + ((((__442_1_z1._Vals))[1]) * (((__442_1_z2._Vals))[0]))); { __T378356752 = __442_1_r; return __T378356752; } }

_Complex_double __c99_complex_double_divide( _Complex_double __444_1_z1,  _Complex_double __444_1_z2) { auto struct _Complex_double __T378373472; auto _Complex_double __444_1_r; auto double __444_1_d; __444_1_d = (((((__444_1_z2._Vals))[0]) * (((__444_1_z2._Vals))[0])) + ((((__444_1_z2._Vals))[1]) * 
#line 326
(((__444_1_z2._Vals))[1]))); (((__444_1_r._Vals))[0]) = ((((((__444_1_z1._Vals))[0]) * (((__444_1_z2._Vals))[0])) + ((((__444_1_z1._Vals))[1]) * (((__444_1_z2._Vals))[1]))) / __444_1_d); (((__444_1_r._Vals))[1]) = ((((((__444_1_z1._Vals))[1]) * (((__444_1_z2._Vals))[0])) - ((((__444_1_z1._Vals))[0]) 
#line 326
* (((__444_1_z2._Vals))[1]))) / __444_1_d); { __T378373472 = __444_1_r; return __T378373472; } }

int __c99_complex_double_eq( _Complex_double __446_1_z1,  _Complex_double __446_1_z2) { return (int)(((((__446_1_z1._Vals))[0]) == (((__446_1_z2._Vals))[0])) && ((((__446_1_z1._Vals))[1]) == (((__446_1_z2._Vals))[1]))); }
int __c99_complex_double_ne( _Complex_double __447_1_z1,  _Complex_double __447_1_z2) { return (int)(((((__447_1_z1._Vals))[0]) != (((__447_1_z2._Vals))[0])) || ((((__447_1_z1._Vals))[1]) != (((__447_1_z2._Vals))[1]))); }
_Complex_double __c99_idouble_to_cdouble( double __448_1_j) { auto struct _Complex_double __T378388416; auto _Complex_double __448_1_r; (((__448_1_r._Vals))[0]) = (0.0); (((__448_1_r._Vals))[1]) = ((double)__448_1_j); { __T378388416 = __448_1_r; return __T378388416; } }
_Complex_double __c99_double_to_cdouble( double __449_1_j) { auto struct _Complex_double __T378393648; auto _Complex_double __449_1_r; (((__449_1_r._Vals))[0]) = ((double)__449_1_j); (((__449_1_r._Vals))[1]) = (0.0); { __T378393648 = __449_1_r; return __T378393648; } }
double __c99_cdouble_to_idouble( _Complex_double __450_1_z) { return ((__450_1_z._Vals))[1]; }
double __c99_cdouble_to_double( _Complex_double __451_1_z) { return ((__451_1_z._Vals))[0]; }

_Complex_float16 __c99_cdouble_to_cfloat16( _Complex_double __453_1_z) { auto struct _Complex_float16 __T378403240; auto _Complex_float16 __453_1_r; (((__453_1_r._Vals))[0]) = ((_Float16)(((__453_1_z._Vals))[0])); (((__453_1_r._Vals))[1]) = ((_Float16)(((__453_1_z._Vals))[1])); { __T378403240 = 
#line 335
__453_1_r; return __T378403240; } }



_Complex_bfloat16 __c99_cdouble_to_cbfloat16( _Complex_double __457_1_z) { auto struct _Complex_bfloat16 __T378409392; auto _Complex_bfloat16 __457_1_r; (((__457_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__457_1_z._Vals))[0])); (((__457_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__457_1_z._Vals))[1])); { 
#line 339
__T378409392 = __457_1_r; return __T378409392; } }


_Complex_float __c99_cdouble_to_cfloat( _Complex_double __460_1_z) { auto struct _Complex_float __T378415416; auto _Complex_float __460_1_r; (((__460_1_r._Vals))[0]) = ((float)(((__460_1_z._Vals))[0])); (((__460_1_r._Vals))[1]) = ((float)(((__460_1_z._Vals))[1])); { __T378415416 = __460_1_r; return 
#line 342
__T378415416; } }
_Complex_long_double __c99_cdouble_to_clong_double( _Complex_double __461_1_z) { auto struct _Complex_long_double __T378421440; auto _Complex_long_double __461_1_r; (((__461_1_r._Vals))[0]) = ((long double)(((__461_1_z._Vals))[0])); (((__461_1_r._Vals))[1]) = ((long double)(((__461_1_z._Vals))[1])); 
#line 343
{ __T378421440 = __461_1_r; return __T378421440; } }


_Complex_float80 __c99_cdouble_to_cfloat80( _Complex_double __464_1_z) { auto struct _Complex_float80 __T378427464; auto _Complex_float80 __464_1_r; (((__464_1_r._Vals))[0]) = ((__float80)(((__464_1_z._Vals))[0])); (((__464_1_r._Vals))[1]) = ((__float80)(((__464_1_z._Vals))[1])); { __T378427464 = 
#line 346
__464_1_r; return __T378427464; } }



_Complex_float128 __c99_cdouble_to_cfloat128( _Complex_double __468_1_z) { auto struct _Complex_float128 __T378433488; auto _Complex_float128 __468_1_r; (((__468_1_r._Vals))[0]) = ((__float128)(((__468_1_z._Vals))[0])); (((__468_1_r._Vals))[1]) = ((__float128)(((__468_1_z._Vals))[1])); { 
#line 350
__T378433488 = __468_1_r; return __T378433488; } }




_Complex_long_double __c99_complex_long_double_negate( _Complex_long_double __473_1_z) { auto struct _Complex_long_double __T378439032; (((__473_1_z._Vals))[0]) = (-(((__473_1_z._Vals))[0])); (((__473_1_z._Vals))[1]) = (-(((__473_1_z._Vals))[1])); { __T378439032 = __473_1_z; return __T378439032; } }

_Complex_long_double __c99_complex_long_double_conj( _Complex_long_double __475_1_z) { auto struct _Complex_long_double __T378442824; (((__475_1_z._Vals))[1]) = (-(((__475_1_z._Vals))[1])); { __T378442824 = __475_1_z; return __T378442824; } }

_Complex_long_double __c99_complex_long_double_add( _Complex_long_double __477_1_z1,  _Complex_long_double __477_1_z2) { auto struct _Complex_long_double __T378450696; auto _Complex_long_double __477_1_r; (((__477_1_r._Vals))[0]) = ((((__477_1_z1._Vals))[0]) + (((__477_1_z2._Vals))[0])); (((
#line 359
__477_1_r._Vals))[1]) = ((((__477_1_z1._Vals))[1]) + (((__477_1_z2._Vals))[1])); { __T378450696 = __477_1_r; return __T378450696; } }


_Complex_long_double __c99_complex_long_double_subtract( _Complex_long_double __480_1_z1,  _Complex_long_double __480_1_z2) { auto struct _Complex_long_double __T378458568; auto _Complex_long_double __480_1_r; (((__480_1_r._Vals))[0]) = ((((__480_1_z1._Vals))[0]) - (((__480_1_z2._Vals))[0])); (((
#line 362
__480_1_r._Vals))[1]) = ((((__480_1_z1._Vals))[1]) - (((__480_1_z2._Vals))[1])); { __T378458568 = __480_1_r; return __T378458568; } }


_Complex_long_double __c99_complex_long_double_multiply( _Complex_long_double __483_1_z1,  _Complex_long_double __483_1_z2) { auto struct _Complex_long_double __T378469920; auto _Complex_long_double __483_1_r; (((__483_1_r._Vals))[0]) = (((((__483_1_z1._Vals))[0]) * (((__483_1_z2._Vals))[0])) - ((((
#line 365
__483_1_z1._Vals))[1]) * (((__483_1_z2._Vals))[1]))); (((__483_1_r._Vals))[1]) = (((((__483_1_z1._Vals))[0]) * (((__483_1_z2._Vals))[1])) + ((((__483_1_z1._Vals))[1]) * (((__483_1_z2._Vals))[0]))); { __T378469920 = __483_1_r; return __T378469920; } }


_Complex_long_double __c99_complex_long_double_divide( _Complex_long_double __486_1_z1,  _Complex_long_double __486_1_z2) { auto struct _Complex_long_double __T378486640; auto _Complex_long_double __486_1_r; auto long double __486_1_d; __486_1_d = (((((__486_1_z2._Vals))[0]) * (((__486_1_z2._Vals))[0
#line 368
])) + ((((__486_1_z2._Vals))[1]) * (((__486_1_z2._Vals))[1]))); (((__486_1_r._Vals))[0]) = ((((((__486_1_z1._Vals))[0]) * (((__486_1_z2._Vals))[0])) + ((((__486_1_z1._Vals))[1]) * (((__486_1_z2._Vals))[1]))) / __486_1_d); (((__486_1_r._Vals))[1]) = ((((((__486_1_z1._Vals))[1]) * (((__486_1_z2._Vals)
#line 368
)[0])) - ((((__486_1_z1._Vals))[0]) * (((__486_1_z2._Vals))[1]))) / __486_1_d); { __T378486640 = __486_1_r; return __T378486640; } }


int __c99_complex_long_double_eq( _Complex_long_double __489_1_z1,  _Complex_long_double __489_1_z2) { return (int)(((((__489_1_z1._Vals))[0]) == (((__489_1_z2._Vals))[0])) && ((((__489_1_z1._Vals))[1]) == (((__489_1_z2._Vals))[1]))); }

int __c99_complex_long_double_ne( _Complex_long_double __491_1_z1,  _Complex_long_double __491_1_z2) { return (int)(((((__491_1_z1._Vals))[0]) != (((__491_1_z2._Vals))[0])) || ((((__491_1_z1._Vals))[1]) != (((__491_1_z2._Vals))[1]))); }

_Complex_long_double __c99_ilong_double_to_clong_double( long double __493_1_j) { auto struct _Complex_long_double __T378501584; auto _Complex_long_double __493_1_r; (((__493_1_r._Vals))[0]) = (0.0L); (((__493_1_r._Vals))[1]) = ((long double)__493_1_j); { __T378501584 = __493_1_r; return 
#line 375
__T378501584; } }
_Complex_long_double __c99_long_double_to_clong_double( long double __494_1_j) { auto struct _Complex_long_double __T378506816; auto _Complex_long_double __494_1_r; (((__494_1_r._Vals))[0]) = ((long double)__494_1_j); (((__494_1_r._Vals))[1]) = (0.0L); { __T378506816 = __494_1_r; return __T378506816
#line 376
; } }
long double __c99_clong_double_to_ilong_double( _Complex_long_double __495_1_z) { return ((__495_1_z._Vals))[1]; }
long double __c99_clong_double_to_long_double( _Complex_long_double __496_1_z) { return ((__496_1_z._Vals))[0]; }

_Complex_float16 __c99_clong_double_to_cfloat16( _Complex_long_double __498_1_z) { auto struct _Complex_float16 __T378516408; auto _Complex_float16 __498_1_r; (((__498_1_r._Vals))[0]) = ((_Float16)(((__498_1_z._Vals))[0])); (((__498_1_r._Vals))[1]) = ((_Float16)(((__498_1_z._Vals))[1])); { 
#line 380
__T378516408 = __498_1_r; return __T378516408; } }



_Complex_bfloat16 __c99_clong_double_to_cbfloat16( _Complex_long_double __502_1_z) { auto struct _Complex_bfloat16 __T378522432; auto _Complex_bfloat16 __502_1_r; (((__502_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__502_1_z._Vals))[0])); (((__502_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__502_1_z._Vals))
#line 384
[1])); { __T378522432 = __502_1_r; return __T378522432; } }



_Complex_float __c99_clong_double_to_cfloat( _Complex_long_double __506_1_z) { auto struct _Complex_float __T378528456; auto _Complex_float __506_1_r; (((__506_1_r._Vals))[0]) = ((float)(((__506_1_z._Vals))[0])); (((__506_1_r._Vals))[1]) = ((float)(((__506_1_z._Vals))[1])); { __T378528456 = 
#line 388
__506_1_r; return __T378528456; } }

_Complex_double __c99_clong_double_to_cdouble( _Complex_long_double __508_1_z) { auto struct _Complex_double __T378534480; auto _Complex_double __508_1_r; (((__508_1_r._Vals))[0]) = ((double)(((__508_1_z._Vals))[0])); (((__508_1_r._Vals))[1]) = ((double)(((__508_1_z._Vals))[1])); { __T378534480 = 
#line 390
__508_1_r; return __T378534480; } }


_Complex_float80 __c99_clong_double_to_cfloat80( _Complex_long_double __511_1_z) { auto struct _Complex_float80 __T378540584; auto _Complex_float80 __511_1_r; (((__511_1_r._Vals))[0]) = ((__float80)(((__511_1_z._Vals))[0])); (((__511_1_r._Vals))[1]) = ((__float80)(((__511_1_z._Vals))[1])); { 
#line 393
__T378540584 = __511_1_r; return __T378540584; } }



_Complex_float128 __c99_clong_double_to_cfloat128( _Complex_long_double __515_1_z) { auto struct _Complex_float128 __T378546608; auto _Complex_float128 __515_1_r; (((__515_1_r._Vals))[0]) = ((__float128)(((__515_1_z._Vals))[0])); (((__515_1_r._Vals))[1]) = ((__float128)(((__515_1_z._Vals))[1])); { 
#line 397
__T378546608 = __515_1_r; return __T378546608; } }
#line 403
_Complex_float80 __c99_complex_float80_negate( _Complex_float80 __521_1_z) { auto struct _Complex_float80 __T378552152; (((__521_1_z._Vals))[0]) = (-(((__521_1_z._Vals))[0])); (((__521_1_z._Vals))[1]) = (-(((__521_1_z._Vals))[1])); { __T378552152 = __521_1_z; return __T378552152; } }
_Complex_float80 __c99_complex_float80_conj( _Complex_float80 __522_1_z) { auto struct _Complex_float80 __T378555944; (((__522_1_z._Vals))[1]) = (-(((__522_1_z._Vals))[1])); { __T378555944 = __522_1_z; return __T378555944; } }
_Complex_float80 __c99_complex_float80_add( _Complex_float80 __523_1_z1,  _Complex_float80 __523_1_z2) { auto struct _Complex_float80 __T378563816; auto _Complex_float80 __523_1_r; (((__523_1_r._Vals))[0]) = ((((__523_1_z1._Vals))[0]) + (((__523_1_z2._Vals))[0])); (((__523_1_r._Vals))[1]) = ((((
#line 405
__523_1_z1._Vals))[1]) + (((__523_1_z2._Vals))[1])); { __T378563816 = __523_1_r; return __T378563816; } }

_Complex_float80 __c99_complex_float80_subtract( _Complex_float80 __525_1_z1,  _Complex_float80 __525_1_z2) { auto struct _Complex_float80 __T378571688; auto _Complex_float80 __525_1_r; (((__525_1_r._Vals))[0]) = ((((__525_1_z1._Vals))[0]) - (((__525_1_z2._Vals))[0])); (((__525_1_r._Vals))[1]) = (((
#line 407
(__525_1_z1._Vals))[1]) - (((__525_1_z2._Vals))[1])); { __T378571688 = __525_1_r; return __T378571688; } }

_Complex_float80 __c99_complex_float80_multiply( _Complex_float80 __527_1_z1,  _Complex_float80 __527_1_z2) { auto struct _Complex_float80 __T378582888; auto _Complex_float80 __527_1_r; (((__527_1_r._Vals))[0]) = (((((__527_1_z1._Vals))[0]) * (((__527_1_z2._Vals))[0])) - ((((__527_1_z1._Vals))[1]) * 
#line 409
(((__527_1_z2._Vals))[1]))); (((__527_1_r._Vals))[1]) = (((((__527_1_z1._Vals))[0]) * (((__527_1_z2._Vals))[1])) + ((((__527_1_z1._Vals))[1]) * (((__527_1_z2._Vals))[0]))); { __T378582888 = __527_1_r; return __T378582888; } }

_Complex_float80 __c99_complex_float80_divide( _Complex_float80 __529_1_z1,  _Complex_float80 __529_1_z2) { auto struct _Complex_float80 __T378599608; auto _Complex_float80 __529_1_r; auto __float80 __529_1_d; __529_1_d = (((((__529_1_z2._Vals))[0]) * (((__529_1_z2._Vals))[0])) + ((((
#line 411
__529_1_z2._Vals))[1]) * (((__529_1_z2._Vals))[1]))); (((__529_1_r._Vals))[0]) = ((((((__529_1_z1._Vals))[0]) * (((__529_1_z2._Vals))[0])) + ((((__529_1_z1._Vals))[1]) * (((__529_1_z2._Vals))[1]))) / __529_1_d); (((__529_1_r._Vals))[1]) = ((((((__529_1_z1._Vals))[1]) * (((__529_1_z2._Vals))[0])) - (
#line 411
(((__529_1_z1._Vals))[0]) * (((__529_1_z2._Vals))[1]))) / __529_1_d); { __T378599608 = __529_1_r; return __T378599608; } }

int __c99_complex_float80_eq( _Complex_float80 __531_1_z1,  _Complex_float80 __531_1_z2) { return (int)(((((__531_1_z1._Vals))[0]) == (((__531_1_z2._Vals))[0])) && ((((__531_1_z1._Vals))[1]) == (((__531_1_z2._Vals))[1]))); }
int __c99_complex_float80_ne( _Complex_float80 __532_1_z1,  _Complex_float80 __532_1_z2) { return (int)(((((__532_1_z1._Vals))[0]) != (((__532_1_z2._Vals))[0])) || ((((__532_1_z1._Vals))[1]) != (((__532_1_z2._Vals))[1]))); }
_Complex_float80 __c99_ifloat80_to_cfloat80( __float80 __533_1_j) { auto struct _Complex_float80 __T378614832; auto _Complex_float80 __533_1_r; (((__533_1_r._Vals))[0]) = (0.0L); (((__533_1_r._Vals))[1]) = ((__float80)__533_1_j); { __T378614832 = __533_1_r; return __T378614832; } }
_Complex_float80 __c99_float80_to_cfloat80( __float80 __534_1_j) { auto struct _Complex_float80 __T378620064; auto _Complex_float80 __534_1_r; (((__534_1_r._Vals))[0]) = ((__float80)__534_1_j); (((__534_1_r._Vals))[1]) = (0.0L); { __T378620064 = __534_1_r; return __T378620064; } }
__float80 __c99_cfloat80_to_ifloat80( _Complex_float80 __535_1_z) { return ((__535_1_z._Vals))[1]; }
__float80 __c99_cfloat80_to_float80( _Complex_float80 __536_1_z) { return ((__536_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat80_to_cfloat16( _Complex_float80 __538_1_z) { auto struct _Complex_float16 __T378629656; auto _Complex_float16 __538_1_r; (((__538_1_r._Vals))[0]) = ((_Float16)(((__538_1_z._Vals))[0])); (((__538_1_r._Vals))[1]) = ((_Float16)(((__538_1_z._Vals))[1])); { __T378629656 = 
#line 420
__538_1_r; return __T378629656; } }



_Complex_bfloat16 __c99_cfloat80_to_cbfloat16( _Complex_float80 __542_1_z) { auto struct _Complex_bfloat16 __T378635680; auto _Complex_bfloat16 __542_1_r; (((__542_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__542_1_z._Vals))[0])); (((__542_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__542_1_z._Vals))[1])); { 
#line 424
__T378635680 = __542_1_r; return __T378635680; } }


_Complex_float __c99_cfloat80_to_cfloat( _Complex_float80 __545_1_z) { auto struct _Complex_float __T378641704; auto _Complex_float __545_1_r; (((__545_1_r._Vals))[0]) = ((float)(((__545_1_z._Vals))[0])); (((__545_1_r._Vals))[1]) = ((float)(((__545_1_z._Vals))[1])); { __T378641704 = __545_1_r; 
#line 427
return __T378641704; } }
_Complex_double __c99_cfloat80_to_cdouble( _Complex_float80 __546_1_z) { auto struct _Complex_double __T378647728; auto _Complex_double __546_1_r; (((__546_1_r._Vals))[0]) = ((double)(((__546_1_z._Vals))[0])); (((__546_1_r._Vals))[1]) = ((double)(((__546_1_z._Vals))[1])); { __T378647728 = 
#line 428
__546_1_r; return __T378647728; } }
_Complex_long_double __c99_cfloat80_to_clong_double( _Complex_float80 __547_1_z) { auto struct _Complex_long_double __T378653752; auto _Complex_long_double __547_1_r; (((__547_1_r._Vals))[0]) = ((long double)(((__547_1_z._Vals))[0])); (((__547_1_r._Vals))[1]) = ((long double)(((__547_1_z._Vals))[1])
#line 429
); { __T378653752 = __547_1_r; return __T378653752; } }


_Complex_float128 __c99_cfloat80_to_cfloat128( _Complex_float80 __550_1_z) { auto struct _Complex_float128 __T378659776; auto _Complex_float128 __550_1_r; (((__550_1_r._Vals))[0]) = ((__float128)(((__550_1_z._Vals))[0])); (((__550_1_r._Vals))[1]) = ((__float128)(((__550_1_z._Vals))[1])); { 
#line 432
__T378659776 = __550_1_r; return __T378659776; } }
#line 439
_Complex_float128 __c99_complex_float128_negate( _Complex_float128 __557_1_z) { auto struct _Complex_float128 __T378665320; (((__557_1_z._Vals))[0]) = (-(((__557_1_z._Vals))[0])); (((__557_1_z._Vals))[1]) = (-(((__557_1_z._Vals))[1])); { __T378665320 = __557_1_z; return __T378665320; } }
_Complex_float128 __c99_complex_float128_conj( _Complex_float128 __558_1_z) { auto struct _Complex_float128 __T378669232; (((__558_1_z._Vals))[1]) = (-(((__558_1_z._Vals))[1])); { __T378669232 = __558_1_z; return __T378669232; } }
_Complex_float128 __c99_complex_float128_add( _Complex_float128 __559_1_z1,  _Complex_float128 __559_1_z2) { auto struct _Complex_float128 __T378677104; auto _Complex_float128 __559_1_r; (((__559_1_r._Vals))[0]) = ((((__559_1_z1._Vals))[0]) + (((__559_1_z2._Vals))[0])); (((__559_1_r._Vals))[1]) = ((
#line 441
((__559_1_z1._Vals))[1]) + (((__559_1_z2._Vals))[1])); { __T378677104 = __559_1_r; return __T378677104; } }

_Complex_float128 __c99_complex_float128_subtract( _Complex_float128 __561_1_z1,  _Complex_float128 __561_1_z2) { auto struct _Complex_float128 __T378684976; auto _Complex_float128 __561_1_r; (((__561_1_r._Vals))[0]) = ((((__561_1_z1._Vals))[0]) - (((__561_1_z2._Vals))[0])); (((__561_1_r._Vals))[1]) 
#line 443
= ((((__561_1_z1._Vals))[1]) - (((__561_1_z2._Vals))[1])); { __T378684976 = __561_1_r; return __T378684976; } }

_Complex_float128 __c99_complex_float128_multiply( _Complex_float128 __563_1_z1,  _Complex_float128 __563_1_z2) { auto struct _Complex_float128 __T378696176; auto _Complex_float128 __563_1_r; (((__563_1_r._Vals))[0]) = (((((__563_1_z1._Vals))[0]) * (((__563_1_z2._Vals))[0])) - ((((__563_1_z1._Vals))
#line 445
[1]) * (((__563_1_z2._Vals))[1]))); (((__563_1_r._Vals))[1]) = (((((__563_1_z1._Vals))[0]) * (((__563_1_z2._Vals))[1])) + ((((__563_1_z1._Vals))[1]) * (((__563_1_z2._Vals))[0]))); { __T378696176 = __563_1_r; return __T378696176; } }

_Complex_float128 __c99_complex_float128_divide( _Complex_float128 __565_1_z1,  _Complex_float128 __565_1_z2) { auto struct _Complex_float128 __T378712896; auto _Complex_float128 __565_1_r; auto __float128 __565_1_d; __565_1_d = (((((__565_1_z2._Vals))[0]) * (((__565_1_z2._Vals))[0])) + ((((
#line 447
__565_1_z2._Vals))[1]) * (((__565_1_z2._Vals))[1]))); (((__565_1_r._Vals))[0]) = ((((((__565_1_z1._Vals))[0]) * (((__565_1_z2._Vals))[0])) + ((((__565_1_z1._Vals))[1]) * (((__565_1_z2._Vals))[1]))) / __565_1_d); (((__565_1_r._Vals))[1]) = ((((((__565_1_z1._Vals))[1]) * (((__565_1_z2._Vals))[0])) - (
#line 447
(((__565_1_z1._Vals))[0]) * (((__565_1_z2._Vals))[1]))) / __565_1_d); { __T378712896 = __565_1_r; return __T378712896; } }

int __c99_complex_float128_eq( _Complex_float128 __567_1_z1,  _Complex_float128 __567_1_z2) { return (int)(((((__567_1_z1._Vals))[0]) == (((__567_1_z2._Vals))[0])) && ((((__567_1_z1._Vals))[1]) == (((__567_1_z2._Vals))[1]))); }
int __c99_complex_float128_ne( _Complex_float128 __568_1_z1,  _Complex_float128 __568_1_z2) { return (int)(((((__568_1_z1._Vals))[0]) != (((__568_1_z2._Vals))[0])) || ((((__568_1_z1._Vals))[1]) != (((__568_1_z2._Vals))[1]))); }
_Complex_float128 __c99_ifloat128_to_cfloat128( __float128 __569_1_j) { auto struct _Complex_float128 __T378727840; auto _Complex_float128 __569_1_r; (((__569_1_r._Vals))[0]) = (0.0Q); (((__569_1_r._Vals))[1]) = ((__float128)__569_1_j); { __T378727840 = __569_1_r; return __T378727840; } }
_Complex_float128 __c99_float128_to_cfloat128( __float128 __570_1_j) { auto struct _Complex_float128 __T378733216; auto _Complex_float128 __570_1_r; (((__570_1_r._Vals))[0]) = ((__float128)__570_1_j); (((__570_1_r._Vals))[1]) = (0.0Q); { __T378733216 = __570_1_r; return __T378733216; } }
__float128 __c99_cfloat128_to_ifloat128( _Complex_float128 __571_1_z) { return ((__571_1_z._Vals))[1]; }
__float128 __c99_cfloat128_to_float128( _Complex_float128 __572_1_z) { return ((__572_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat128_to_cfloat16( _Complex_float128 __574_1_z) { auto struct _Complex_float16 __T378806136; auto _Complex_float16 __574_1_r; (((__574_1_r._Vals))[0]) = ((_Float16)(((__574_1_z._Vals))[0])); (((__574_1_r._Vals))[1]) = ((_Float16)(((__574_1_z._Vals))[1])); { __T378806136 = 
#line 456
__574_1_r; return __T378806136; } }



_Complex_bfloat16 __c99_cfloat128_to_cbfloat16( _Complex_float128 __578_1_z) { auto struct _Complex_bfloat16 __T378812160; auto _Complex_bfloat16 __578_1_r; (((__578_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__578_1_z._Vals))[0])); (((__578_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__578_1_z._Vals))[1])); 
#line 460
{ __T378812160 = __578_1_r; return __T378812160; } }


_Complex_float __c99_cfloat128_to_cfloat( _Complex_float128 __581_1_z) { auto struct _Complex_float __T378818184; auto _Complex_float __581_1_r; (((__581_1_r._Vals))[0]) = ((float)(((__581_1_z._Vals))[0])); (((__581_1_r._Vals))[1]) = ((float)(((__581_1_z._Vals))[1])); { __T378818184 = 
#line 463
__581_1_r; return __T378818184; } }
_Complex_double __c99_cfloat128_to_cdouble( _Complex_float128 __582_1_z) { auto struct _Complex_double __T378824208; auto _Complex_double __582_1_r; (((__582_1_r._Vals))[0]) = ((double)(((__582_1_z._Vals))[0])); (((__582_1_r._Vals))[1]) = ((double)(((__582_1_z._Vals))[1])); { __T378824208 = 
#line 464
__582_1_r; return __T378824208; } }

_Complex_long_double __c99_cfloat128_to_clong_double( _Complex_float128 __584_1_z) { auto struct _Complex_long_double __T378830232; auto _Complex_long_double __584_1_r; (((__584_1_r._Vals))[0]) = ((long double)(((__584_1_z._Vals))[0])); (((__584_1_r._Vals))[1]) = ((long double)(((__584_1_z._Vals))[1
#line 466
])); { __T378830232 = __584_1_r; return __T378830232; } }


_Complex_float80 __c99_cfloat128_to_cfloat80( _Complex_float128 __587_1_z) { auto struct _Complex_float80 __T378836256; auto _Complex_float80 __587_1_r; (((__587_1_r._Vals))[0]) = ((__float80)(((__587_1_z._Vals))[0])); (((__587_1_r._Vals))[1]) = ((__float80)(((__587_1_z._Vals))[1])); { __T378836256 
#line 469
= __587_1_r; return __T378836256; } }
