/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/c99_complex.c"
# 21
struct _Complex_float;
# 27
struct _Complex_double;
# 33
struct _Complex_long_double;
# 40
struct _Complex_float16;
# 48
struct _Complex_bfloat16;
# 56
struct _Complex_float80;
# 63
struct _Complex_float128;
# 21
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
# 214
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
# 242
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
# 271
extern _Complex_float80 __c99_cbfloat16_to_cfloat80(_Complex_bfloat16 z);
# 277
extern _Complex_float128 __c99_cbfloat16_to_cfloat128(_Complex_bfloat16 z);
# 283
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
# 403
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
# 439
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
# 214
_Complex_float16 __c99_complex_float16_negate( _Complex_float16 __332_1_z) { auto struct _Complex_float16 __T240171032; (((__332_1_z._Vals))[0]) = (-(((__332_1_z._Vals))[0])); (((__332_1_z._Vals))[1]) = (-(((__332_1_z._Vals))[1])); { __T240171032 = __332_1_z; return __T240171032; } }
_Complex_float16 __c99_complex_float16_conj( _Complex_float16 __333_1_z) { auto struct _Complex_float16 __T240174824; (((__333_1_z._Vals))[1]) = (-(((__333_1_z._Vals))[1])); { __T240174824 = __333_1_z; return __T240174824; } }
_Complex_float16 __c99_complex_float16_add( _Complex_float16 __334_1_z1,  _Complex_float16 __334_1_z2) { auto struct _Complex_float16 __T240182696; auto _Complex_float16 __334_1_r; (((__334_1_r._Vals))[0]) = ((((__334_1_z1._Vals))[0]) + (((__334_1_z2._Vals))[0])); (((__334_1_r._Vals))[1]) = ((((
# 216
__334_1_z1._Vals))[1]) + (((__334_1_z2._Vals))[1])); { __T240182696 = __334_1_r; return __T240182696; } }

_Complex_float16 __c99_complex_float16_subtract( _Complex_float16 __336_1_z1,  _Complex_float16 __336_1_z2) { auto struct _Complex_float16 __T240190568; auto _Complex_float16 __336_1_r; (((__336_1_r._Vals))[0]) = ((((__336_1_z1._Vals))[0]) - (((__336_1_z2._Vals))[0])); (((__336_1_r._Vals))[1]) = (((
# 218
(__336_1_z1._Vals))[1]) - (((__336_1_z2._Vals))[1])); { __T240190568 = __336_1_r; return __T240190568; } }

_Complex_float16 __c99_complex_float16_multiply( _Complex_float16 __338_1_z1,  _Complex_float16 __338_1_z2) { auto struct _Complex_float16 __T240201768; auto _Complex_float16 __338_1_r; (((__338_1_r._Vals))[0]) = (((((__338_1_z1._Vals))[0]) * (((__338_1_z2._Vals))[0])) - ((((__338_1_z1._Vals))[1]) * 
# 220
(((__338_1_z2._Vals))[1]))); (((__338_1_r._Vals))[1]) = (((((__338_1_z1._Vals))[0]) * (((__338_1_z2._Vals))[1])) + ((((__338_1_z1._Vals))[1]) * (((__338_1_z2._Vals))[0]))); { __T240201768 = __338_1_r; return __T240201768; } }

_Complex_float16 __c99_complex_float16_divide( _Complex_float16 __340_1_z1,  _Complex_float16 __340_1_z2) { auto struct _Complex_float16 __T240218488; auto _Complex_float16 __340_1_r; auto _Float16 __340_1_d; __340_1_d = (((((__340_1_z2._Vals))[0]) * (((__340_1_z2._Vals))[0])) + ((((__340_1_z2._Vals
# 222
))[1]) * (((__340_1_z2._Vals))[1]))); (((__340_1_r._Vals))[0]) = ((((((__340_1_z1._Vals))[0]) * (((__340_1_z2._Vals))[0])) + ((((__340_1_z1._Vals))[1]) * (((__340_1_z2._Vals))[1]))) / __340_1_d); (((__340_1_r._Vals))[1]) = ((((((__340_1_z1._Vals))[1]) * (((__340_1_z2._Vals))[0])) - ((((
# 222
__340_1_z1._Vals))[0]) * (((__340_1_z2._Vals))[1]))) / __340_1_d); { __T240218488 = __340_1_r; return __T240218488; } }

int __c99_complex_float16_eq( _Complex_float16 __342_1_z1,  _Complex_float16 __342_1_z2) { return (int)(((((__342_1_z1._Vals))[0]) == (((__342_1_z2._Vals))[0])) && ((((__342_1_z1._Vals))[1]) == (((__342_1_z2._Vals))[1]))); }
int __c99_complex_float16_ne( _Complex_float16 __343_1_z1,  _Complex_float16 __343_1_z2) { return (int)(((((__343_1_z1._Vals))[0]) != (((__343_1_z2._Vals))[0])) || ((((__343_1_z1._Vals))[1]) != (((__343_1_z2._Vals))[1]))); }
_Complex_float16 __c99_ifloat16_to_cfloat16( _Float16 __344_1_j) { auto struct _Complex_float16 __T240369592; auto _Complex_float16 __344_1_r; (((__344_1_r._Vals))[0]) = (0.0F16); (((__344_1_r._Vals))[1]) = ((_Float16)__344_1_j); { __T240369592 = __344_1_r; return __T240369592; } }
_Complex_float16 __c99_float16_to_cfloat16( _Float16 __345_1_j) { auto struct _Complex_float16 __T240374824; auto _Complex_float16 __345_1_r; (((__345_1_r._Vals))[0]) = ((_Float16)__345_1_j); (((__345_1_r._Vals))[1]) = (0.0F16); { __T240374824 = __345_1_r; return __T240374824; } }
_Float16 __c99_cfloat16_to_ifloat16( _Complex_float16 __346_1_z) { return ((__346_1_z._Vals))[1]; }
_Float16 __c99_cfloat16_to_float16( _Complex_float16 __347_1_z) { return ((__347_1_z._Vals))[0]; }

_Complex_bfloat16 __c99_cfloat16_to_cbfloat16( _Complex_float16 __349_1_z) { auto struct _Complex_bfloat16 __T240384416; auto _Complex_bfloat16 __349_1_r; (((__349_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__349_1_z._Vals))[0])); (((__349_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__349_1_z._Vals))[1])); { 
# 231
__T240384416 = __349_1_r; return __T240384416; } }


_Complex_float __c99_cfloat16_to_cfloat( _Complex_float16 __352_1_z) { auto struct _Complex_float __T240390440; auto _Complex_float __352_1_r; (((__352_1_r._Vals))[0]) = ((float)(((__352_1_z._Vals))[0])); (((__352_1_r._Vals))[1]) = ((float)(((__352_1_z._Vals))[1])); { __T240390440 = __352_1_r; 
# 234
return __T240390440; } }
_Complex_double __c99_cfloat16_to_cdouble( _Complex_float16 __353_1_z) { auto struct _Complex_double __T240396464; auto _Complex_double __353_1_r; (((__353_1_r._Vals))[0]) = ((double)(((__353_1_z._Vals))[0])); (((__353_1_r._Vals))[1]) = ((double)(((__353_1_z._Vals))[1])); { __T240396464 = 
# 235
__353_1_r; return __T240396464; } }
_Complex_long_double __c99_cfloat16_to_clong_double( _Complex_float16 __354_1_z) { auto struct _Complex_long_double __T240402488; auto _Complex_long_double __354_1_r; (((__354_1_r._Vals))[0]) = ((long double)(((__354_1_z._Vals))[0])); (((__354_1_r._Vals))[1]) = ((long double)(((__354_1_z._Vals))[1])
# 236
); { __T240402488 = __354_1_r; return __T240402488; } }
# 242
_Complex_bfloat16 __c99_complex_bfloat16_negate( _Complex_bfloat16 __360_1_z) { auto struct _Complex_bfloat16 __T240408032; (((__360_1_z._Vals))[0]) = (-(((__360_1_z._Vals))[0])); (((__360_1_z._Vals))[1]) = (-(((__360_1_z._Vals))[1])); { __T240408032 = __360_1_z; return __T240408032; } }
_Complex_bfloat16 __c99_complex_bfloat16_conj( _Complex_bfloat16 __361_1_z) { auto struct _Complex_bfloat16 __T240411824; (((__361_1_z._Vals))[1]) = (-(((__361_1_z._Vals))[1])); { __T240411824 = __361_1_z; return __T240411824; } }
_Complex_bfloat16 __c99_complex_bfloat16_add( _Complex_bfloat16 __362_1_z1,  _Complex_bfloat16 __362_1_z2) { auto struct _Complex_bfloat16 __T240419696; auto _Complex_bfloat16 __362_1_r; (((__362_1_r._Vals))[0]) = ((((__362_1_z1._Vals))[0]) + (((__362_1_z2._Vals))[0])); (((__362_1_r._Vals))[1]) = ((
# 244
((__362_1_z1._Vals))[1]) + (((__362_1_z2._Vals))[1])); { __T240419696 = __362_1_r; return __T240419696; } }

_Complex_bfloat16 __c99_complex_bfloat16_subtract( _Complex_bfloat16 __364_1_z1,  _Complex_bfloat16 __364_1_z2) { auto struct _Complex_bfloat16 __T240427568; auto _Complex_bfloat16 __364_1_r; (((__364_1_r._Vals))[0]) = ((((__364_1_z1._Vals))[0]) - (((__364_1_z2._Vals))[0])); (((__364_1_r._Vals))[1]) 
# 246
= ((((__364_1_z1._Vals))[1]) - (((__364_1_z2._Vals))[1])); { __T240427568 = __364_1_r; return __T240427568; } }

_Complex_bfloat16 __c99_complex_bfloat16_multiply( _Complex_bfloat16 __366_1_z1,  _Complex_bfloat16 __366_1_z2) { auto struct _Complex_bfloat16 __T240444336; auto _Complex_bfloat16 __366_1_r; (((__366_1_r._Vals))[0]) = (((((__366_1_z1._Vals))[0]) * (((__366_1_z2._Vals))[0])) - ((((__366_1_z1._Vals))
# 248
[1]) * (((__366_1_z2._Vals))[1]))); (((__366_1_r._Vals))[1]) = (((((__366_1_z1._Vals))[0]) * (((__366_1_z2._Vals))[1])) + ((((__366_1_z1._Vals))[1]) * (((__366_1_z2._Vals))[0]))); { __T240444336 = __366_1_r; return __T240444336; } }

_Complex_bfloat16 __c99_complex_bfloat16_divide( _Complex_bfloat16 __368_1_z1,  _Complex_bfloat16 __368_1_z2) { auto struct _Complex_bfloat16 __T240520304; auto _Complex_bfloat16 __368_1_r; auto _EDG_bfloat16_t __368_1_d; __368_1_d = (((((__368_1_z2._Vals))[0]) * (((__368_1_z2._Vals))[0])) + ((((
# 250
__368_1_z2._Vals))[1]) * (((__368_1_z2._Vals))[1]))); (((__368_1_r._Vals))[0]) = ((((((__368_1_z1._Vals))[0]) * (((__368_1_z2._Vals))[0])) + ((((__368_1_z1._Vals))[1]) * (((__368_1_z2._Vals))[1]))) / __368_1_d); (((__368_1_r._Vals))[1]) = ((((((__368_1_z1._Vals))[1]) * (((__368_1_z2._Vals))[0])) - (
# 250
(((__368_1_z1._Vals))[0]) * (((__368_1_z2._Vals))[1]))) / __368_1_d); { __T240520304 = __368_1_r; return __T240520304; } }

int __c99_complex_bfloat16_eq( _Complex_bfloat16 __370_1_z1,  _Complex_bfloat16 __370_1_z2) { return (int)(((((__370_1_z1._Vals))[0]) == (((__370_1_z2._Vals))[0])) && ((((__370_1_z1._Vals))[1]) == (((__370_1_z2._Vals))[1]))); }
int __c99_complex_bfloat16_ne( _Complex_bfloat16 __371_1_z1,  _Complex_bfloat16 __371_1_z2) { return (int)(((((__371_1_z1._Vals))[0]) != (((__371_1_z2._Vals))[0])) || ((((__371_1_z1._Vals))[1]) != (((__371_1_z2._Vals))[1]))); }
_Complex_bfloat16 __c99_ibfloat16_to_cbfloat16( _EDG_bfloat16_t __372_1_j) { auto struct _Complex_bfloat16 __T240535248; auto _Complex_bfloat16 __372_1_r; (((__372_1_r._Vals))[0]) = (0.0bf16); (((__372_1_r._Vals))[1]) = ((_EDG_bfloat16_t)__372_1_j); { __T240535248 = __372_1_r; return __T240535248; } 
# 254
}
_Complex_bfloat16 __c99_bfloat16_to_cbfloat16( _EDG_bfloat16_t __373_1_j) { auto struct _Complex_bfloat16 __T240540480; auto _Complex_bfloat16 __373_1_r; (((__373_1_r._Vals))[0]) = ((_EDG_bfloat16_t)__373_1_j); (((__373_1_r._Vals))[1]) = (0.0bf16); { __T240540480 = __373_1_r; return __T240540480; } 
# 255
}
_EDG_bfloat16_t __c99_cbfloat16_to_ibfloat16( _Complex_bfloat16 __374_1_z) { return ((__374_1_z._Vals))[1]; }
_EDG_bfloat16_t __c99_cbfloat16_to_bfloat16( _Complex_bfloat16 __375_1_z) { return ((__375_1_z._Vals))[0]; }

_Complex_float16 __c99_cbfloat16_to_cfloat16( _Complex_bfloat16 __377_1_z) { auto struct _Complex_float16 __T240550072; auto _Complex_float16 __377_1_r; (((__377_1_r._Vals))[0]) = ((_Float16)(((__377_1_z._Vals))[0])); (((__377_1_r._Vals))[1]) = ((_Float16)(((__377_1_z._Vals))[1])); { __T240550072 = 
# 259
__377_1_r; return __T240550072; } }


_Complex_float __c99_cbfloat16_to_cfloat( _Complex_bfloat16 __380_1_z) { auto struct _Complex_float __T240556096; auto _Complex_float __380_1_r; (((__380_1_r._Vals))[0]) = ((float)(((__380_1_z._Vals))[0])); (((__380_1_r._Vals))[1]) = ((float)(((__380_1_z._Vals))[1])); { __T240556096 = 
# 262
__380_1_r; return __T240556096; } }
_Complex_double __c99_cbfloat16_to_cdouble( _Complex_bfloat16 __381_1_z) { auto struct _Complex_double __T240562120; auto _Complex_double __381_1_r; (((__381_1_r._Vals))[0]) = ((double)(((__381_1_z._Vals))[0])); (((__381_1_r._Vals))[1]) = ((double)(((__381_1_z._Vals))[1])); { __T240562120 = 
# 263
__381_1_r; return __T240562120; } }

_Complex_long_double __c99_cbfloat16_to_clong_double( _Complex_bfloat16 __383_1_z) { auto struct _Complex_long_double __T240568144; auto _Complex_long_double __383_1_r; (((__383_1_r._Vals))[0]) = ((long double)(((__383_1_z._Vals))[0])); (((__383_1_r._Vals))[1]) = ((long double)(((__383_1_z._Vals))[1
# 265
])); { __T240568144 = __383_1_r; return __T240568144; } }
# 271
_Complex_float80 __c99_cbfloat16_to_cfloat80( _Complex_bfloat16 __389_1_z) { auto struct _Complex_float80 __T240575160; auto _Complex_float80 __389_1_r; (((__389_1_r._Vals))[0]) = ((__float80)(((__389_1_z._Vals))[0])); (((__389_1_r._Vals))[1]) = ((__float80)(((__389_1_z._Vals))[1])); { __T240575160 
# 271
= __389_1_r; return __T240575160; } }
# 277
_Complex_float128 __c99_cbfloat16_to_cfloat128( _Complex_bfloat16 __395_1_z) { auto struct _Complex_float128 __T240581184; auto _Complex_float128 __395_1_r; (((__395_1_r._Vals))[0]) = ((__float128)(((__395_1_z._Vals))[0])); (((__395_1_r._Vals))[1]) = ((__float128)(((__395_1_z._Vals))[1])); { 
# 277
__T240581184 = __395_1_r; return __T240581184; } }
# 283
_Complex_float __c99_complex_float_negate( _Complex_float __401_1_z) { auto struct _Complex_float __T240586728; (((__401_1_z._Vals))[0]) = (-(((__401_1_z._Vals))[0])); (((__401_1_z._Vals))[1]) = (-(((__401_1_z._Vals))[1])); { __T240586728 = __401_1_z; return __T240586728; } }
_Complex_float __c99_complex_float_conj( _Complex_float __402_1_z) { auto struct _Complex_float __T240590520; (((__402_1_z._Vals))[1]) = (-(((__402_1_z._Vals))[1])); { __T240590520 = __402_1_z; return __T240590520; } }
_Complex_float __c99_complex_float_add( _Complex_float __403_1_z1,  _Complex_float __403_1_z2) { auto struct _Complex_float __T240598392; auto _Complex_float __403_1_r; (((__403_1_r._Vals))[0]) = ((((__403_1_z1._Vals))[0]) + (((__403_1_z2._Vals))[0])); (((__403_1_r._Vals))[1]) = ((((__403_1_z1._Vals
# 285
))[1]) + (((__403_1_z2._Vals))[1])); { __T240598392 = __403_1_r; return __T240598392; } }

_Complex_float __c99_complex_float_subtract( _Complex_float __405_1_z1,  _Complex_float __405_1_z2) { auto struct _Complex_float __T240606264; auto _Complex_float __405_1_r; (((__405_1_r._Vals))[0]) = ((((__405_1_z1._Vals))[0]) - (((__405_1_z2._Vals))[0])); (((__405_1_r._Vals))[1]) = ((((
# 287
__405_1_z1._Vals))[1]) - (((__405_1_z2._Vals))[1])); { __T240606264 = __405_1_r; return __T240606264; } }

_Complex_float __c99_complex_float_multiply( _Complex_float __407_1_z1,  _Complex_float __407_1_z2) { auto struct _Complex_float __T240645888; auto _Complex_float __407_1_r; (((__407_1_r._Vals))[0]) = (((((__407_1_z1._Vals))[0]) * (((__407_1_z2._Vals))[0])) - ((((__407_1_z1._Vals))[1]) * (((
# 289
__407_1_z2._Vals))[1]))); (((__407_1_r._Vals))[1]) = (((((__407_1_z1._Vals))[0]) * (((__407_1_z2._Vals))[1])) + ((((__407_1_z1._Vals))[1]) * (((__407_1_z2._Vals))[0]))); { __T240645888 = __407_1_r; return __T240645888; } }

_Complex_float __c99_complex_float_divide( _Complex_float __409_1_z1,  _Complex_float __409_1_z2) { auto struct _Complex_float __T240662608; auto _Complex_float __409_1_r; auto float __409_1_d; __409_1_d = (((((__409_1_z2._Vals))[0]) * (((__409_1_z2._Vals))[0])) + ((((__409_1_z2._Vals))[1]) * (((
# 291
__409_1_z2._Vals))[1]))); (((__409_1_r._Vals))[0]) = ((((((__409_1_z1._Vals))[0]) * (((__409_1_z2._Vals))[0])) + ((((__409_1_z1._Vals))[1]) * (((__409_1_z2._Vals))[1]))) / __409_1_d); (((__409_1_r._Vals))[1]) = ((((((__409_1_z1._Vals))[1]) * (((__409_1_z2._Vals))[0])) - ((((__409_1_z1._Vals))[0]) * 
# 291
(((__409_1_z2._Vals))[1]))) / __409_1_d); { __T240662608 = __409_1_r; return __T240662608; } }

int __c99_complex_float_eq( _Complex_float __411_1_z1,  _Complex_float __411_1_z2) { return (int)(((((__411_1_z1._Vals))[0]) == (((__411_1_z2._Vals))[0])) && ((((__411_1_z1._Vals))[1]) == (((__411_1_z2._Vals))[1]))); }
int __c99_complex_float_ne( _Complex_float __412_1_z1,  _Complex_float __412_1_z2) { return (int)(((((__412_1_z1._Vals))[0]) != (((__412_1_z2._Vals))[0])) || ((((__412_1_z1._Vals))[1]) != (((__412_1_z2._Vals))[1]))); }
_Complex_float __c99_ifloat_to_cfloat( float __413_1_j) { auto struct _Complex_float __T240677552; auto _Complex_float __413_1_r; (((__413_1_r._Vals))[0]) = (0.0F); (((__413_1_r._Vals))[1]) = ((float)__413_1_j); { __T240677552 = __413_1_r; return __T240677552; } }
_Complex_float __c99_float_to_cfloat( float __414_1_j) { auto struct _Complex_float __T240682784; auto _Complex_float __414_1_r; (((__414_1_r._Vals))[0]) = ((float)__414_1_j); (((__414_1_r._Vals))[1]) = (0.0F); { __T240682784 = __414_1_r; return __T240682784; } }
float __c99_cfloat_to_ifloat( _Complex_float __415_1_z) { return ((__415_1_z._Vals))[1]; }
float __c99_cfloat_to_float( _Complex_float __416_1_z) { return ((__416_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat_to_cfloat16( _Complex_float __418_1_z) { auto struct _Complex_float16 __T240692376; auto _Complex_float16 __418_1_r; (((__418_1_r._Vals))[0]) = ((_Float16)(((__418_1_z._Vals))[0])); (((__418_1_r._Vals))[1]) = ((_Float16)(((__418_1_z._Vals))[1])); { __T240692376 = 
# 300
__418_1_r; return __T240692376; } }


_Complex_bfloat16 __c99_cfloat_to_cbfloat16( _Complex_float __421_1_z) { auto struct _Complex_bfloat16 __T240698400; auto _Complex_bfloat16 __421_1_r; (((__421_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__421_1_z._Vals))[0])); (((__421_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__421_1_z._Vals))[1])); { 
# 303
__T240698400 = __421_1_r; return __T240698400; } }


_Complex_double __c99_cfloat_to_cdouble( _Complex_float __424_1_z) { auto struct _Complex_double __T240706264; auto _Complex_double __424_1_r; (((__424_1_r._Vals))[0]) = ((double)(((__424_1_z._Vals))[0])); (((__424_1_r._Vals))[1]) = ((double)(((__424_1_z._Vals))[1])); { __T240706264 = 
# 306
__424_1_r; return __T240706264; } }
_Complex_long_double __c99_cfloat_to_clong_double( _Complex_float __425_1_z) { auto struct _Complex_long_double __T240712288; auto _Complex_long_double __425_1_r; (((__425_1_r._Vals))[0]) = ((long double)(((__425_1_z._Vals))[0])); (((__425_1_r._Vals))[1]) = ((long double)(((__425_1_z._Vals))[1])); { 
# 307
__T240712288 = __425_1_r; return __T240712288; } }


_Complex_float80 __c99_cfloat_to_cfloat80( _Complex_float __428_1_z) { auto struct _Complex_float80 __T240718312; auto _Complex_float80 __428_1_r; (((__428_1_r._Vals))[0]) = ((__float80)(((__428_1_z._Vals))[0])); (((__428_1_r._Vals))[1]) = ((__float80)(((__428_1_z._Vals))[1])); { __T240718312 = 
# 310
__428_1_r; return __T240718312; } }


_Complex_float128 __c99_cfloat_to_cfloat128( _Complex_float __431_1_z) { auto struct _Complex_float128 __T240724336; auto _Complex_float128 __431_1_r; (((__431_1_r._Vals))[0]) = ((__float128)(((__431_1_z._Vals))[0])); (((__431_1_r._Vals))[1]) = ((__float128)(((__431_1_z._Vals))[1])); { __T240724336 
# 313
= __431_1_r; return __T240724336; } }




_Complex_double __c99_complex_double_negate( _Complex_double __436_1_z) { auto struct _Complex_double __T240729880; (((__436_1_z._Vals))[0]) = (-(((__436_1_z._Vals))[0])); (((__436_1_z._Vals))[1]) = (-(((__436_1_z._Vals))[1])); { __T240729880 = __436_1_z; return __T240729880; } }
_Complex_double __c99_complex_double_conj( _Complex_double __437_1_z) { auto struct _Complex_double __T240733672; (((__437_1_z._Vals))[1]) = (-(((__437_1_z._Vals))[1])); { __T240733672 = __437_1_z; return __T240733672; } }
_Complex_double __c99_complex_double_add( _Complex_double __438_1_z1,  _Complex_double __438_1_z2) { auto struct _Complex_double __T240741544; auto _Complex_double __438_1_r; (((__438_1_r._Vals))[0]) = ((((__438_1_z1._Vals))[0]) + (((__438_1_z2._Vals))[0])); (((__438_1_r._Vals))[1]) = ((((
# 320
__438_1_z1._Vals))[1]) + (((__438_1_z2._Vals))[1])); { __T240741544 = __438_1_r; return __T240741544; } }

_Complex_double __c99_complex_double_subtract( _Complex_double __440_1_z1,  _Complex_double __440_1_z2) { auto struct _Complex_double __T240749416; auto _Complex_double __440_1_r; (((__440_1_r._Vals))[0]) = ((((__440_1_z1._Vals))[0]) - (((__440_1_z2._Vals))[0])); (((__440_1_r._Vals))[1]) = ((((
# 322
__440_1_z1._Vals))[1]) - (((__440_1_z2._Vals))[1])); { __T240749416 = __440_1_r; return __T240749416; } }

_Complex_double __c99_complex_double_multiply( _Complex_double __442_1_z1,  _Complex_double __442_1_z2) { auto struct _Complex_double __T240760616; auto _Complex_double __442_1_r; (((__442_1_r._Vals))[0]) = (((((__442_1_z1._Vals))[0]) * (((__442_1_z2._Vals))[0])) - ((((__442_1_z1._Vals))[1]) * (((
# 324
__442_1_z2._Vals))[1]))); (((__442_1_r._Vals))[1]) = (((((__442_1_z1._Vals))[0]) * (((__442_1_z2._Vals))[1])) + ((((__442_1_z1._Vals))[1]) * (((__442_1_z2._Vals))[0]))); { __T240760616 = __442_1_r; return __T240760616; } }

_Complex_double __c99_complex_double_divide( _Complex_double __444_1_z1,  _Complex_double __444_1_z2) { auto struct _Complex_double __T240777464; auto _Complex_double __444_1_r; auto double __444_1_d; __444_1_d = (((((__444_1_z2._Vals))[0]) * (((__444_1_z2._Vals))[0])) + ((((__444_1_z2._Vals))[1]) * 
# 326
(((__444_1_z2._Vals))[1]))); (((__444_1_r._Vals))[0]) = ((((((__444_1_z1._Vals))[0]) * (((__444_1_z2._Vals))[0])) + ((((__444_1_z1._Vals))[1]) * (((__444_1_z2._Vals))[1]))) / __444_1_d); (((__444_1_r._Vals))[1]) = ((((((__444_1_z1._Vals))[1]) * (((__444_1_z2._Vals))[0])) - ((((__444_1_z1._Vals))[0]) 
# 326
* (((__444_1_z2._Vals))[1]))) / __444_1_d); { __T240777464 = __444_1_r; return __T240777464; } }

int __c99_complex_double_eq( _Complex_double __446_1_z1,  _Complex_double __446_1_z2) { return (int)(((((__446_1_z1._Vals))[0]) == (((__446_1_z2._Vals))[0])) && ((((__446_1_z1._Vals))[1]) == (((__446_1_z2._Vals))[1]))); }
int __c99_complex_double_ne( _Complex_double __447_1_z1,  _Complex_double __447_1_z2) { return (int)(((((__447_1_z1._Vals))[0]) != (((__447_1_z2._Vals))[0])) || ((((__447_1_z1._Vals))[1]) != (((__447_1_z2._Vals))[1]))); }
_Complex_double __c99_idouble_to_cdouble( double __448_1_j) { auto struct _Complex_double __T240792408; auto _Complex_double __448_1_r; (((__448_1_r._Vals))[0]) = (0.0); (((__448_1_r._Vals))[1]) = ((double)__448_1_j); { __T240792408 = __448_1_r; return __T240792408; } }
_Complex_double __c99_double_to_cdouble( double __449_1_j) { auto struct _Complex_double __T240797640; auto _Complex_double __449_1_r; (((__449_1_r._Vals))[0]) = ((double)__449_1_j); (((__449_1_r._Vals))[1]) = (0.0); { __T240797640 = __449_1_r; return __T240797640; } }
double __c99_cdouble_to_idouble( _Complex_double __450_1_z) { return ((__450_1_z._Vals))[1]; }
double __c99_cdouble_to_double( _Complex_double __451_1_z) { return ((__451_1_z._Vals))[0]; }

_Complex_float16 __c99_cdouble_to_cfloat16( _Complex_double __453_1_z) { auto struct _Complex_float16 __T240807232; auto _Complex_float16 __453_1_r; (((__453_1_r._Vals))[0]) = ((_Float16)(((__453_1_z._Vals))[0])); (((__453_1_r._Vals))[1]) = ((_Float16)(((__453_1_z._Vals))[1])); { __T240807232 = 
# 335
__453_1_r; return __T240807232; } }



_Complex_bfloat16 __c99_cdouble_to_cbfloat16( _Complex_double __457_1_z) { auto struct _Complex_bfloat16 __T240837368; auto _Complex_bfloat16 __457_1_r; (((__457_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__457_1_z._Vals))[0])); (((__457_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__457_1_z._Vals))[1])); { 
# 339
__T240837368 = __457_1_r; return __T240837368; } }


_Complex_float __c99_cdouble_to_cfloat( _Complex_double __460_1_z) { auto struct _Complex_float __T240843392; auto _Complex_float __460_1_r; (((__460_1_r._Vals))[0]) = ((float)(((__460_1_z._Vals))[0])); (((__460_1_r._Vals))[1]) = ((float)(((__460_1_z._Vals))[1])); { __T240843392 = __460_1_r; return 
# 342
__T240843392; } }
_Complex_long_double __c99_cdouble_to_clong_double( _Complex_double __461_1_z) { auto struct _Complex_long_double __T240849416; auto _Complex_long_double __461_1_r; (((__461_1_r._Vals))[0]) = ((long double)(((__461_1_z._Vals))[0])); (((__461_1_r._Vals))[1]) = ((long double)(((__461_1_z._Vals))[1])); 
# 343
{ __T240849416 = __461_1_r; return __T240849416; } }


_Complex_float80 __c99_cdouble_to_cfloat80( _Complex_double __464_1_z) { auto struct _Complex_float80 __T240855440; auto _Complex_float80 __464_1_r; (((__464_1_r._Vals))[0]) = ((__float80)(((__464_1_z._Vals))[0])); (((__464_1_r._Vals))[1]) = ((__float80)(((__464_1_z._Vals))[1])); { __T240855440 = 
# 346
__464_1_r; return __T240855440; } }



_Complex_float128 __c99_cdouble_to_cfloat128( _Complex_double __468_1_z) { auto struct _Complex_float128 __T240861464; auto _Complex_float128 __468_1_r; (((__468_1_r._Vals))[0]) = ((__float128)(((__468_1_z._Vals))[0])); (((__468_1_r._Vals))[1]) = ((__float128)(((__468_1_z._Vals))[1])); { 
# 350
__T240861464 = __468_1_r; return __T240861464; } }




_Complex_long_double __c99_complex_long_double_negate( _Complex_long_double __473_1_z) { auto struct _Complex_long_double __T240867008; (((__473_1_z._Vals))[0]) = (-(((__473_1_z._Vals))[0])); (((__473_1_z._Vals))[1]) = (-(((__473_1_z._Vals))[1])); { __T240867008 = __473_1_z; return __T240867008; } }

_Complex_long_double __c99_complex_long_double_conj( _Complex_long_double __475_1_z) { auto struct _Complex_long_double __T240870800; (((__475_1_z._Vals))[1]) = (-(((__475_1_z._Vals))[1])); { __T240870800 = __475_1_z; return __T240870800; } }

_Complex_long_double __c99_complex_long_double_add( _Complex_long_double __477_1_z1,  _Complex_long_double __477_1_z2) { auto struct _Complex_long_double __T240878672; auto _Complex_long_double __477_1_r; (((__477_1_r._Vals))[0]) = ((((__477_1_z1._Vals))[0]) + (((__477_1_z2._Vals))[0])); (((
# 359
__477_1_r._Vals))[1]) = ((((__477_1_z1._Vals))[1]) + (((__477_1_z2._Vals))[1])); { __T240878672 = __477_1_r; return __T240878672; } }


_Complex_long_double __c99_complex_long_double_subtract( _Complex_long_double __480_1_z1,  _Complex_long_double __480_1_z2) { auto struct _Complex_long_double __T240886544; auto _Complex_long_double __480_1_r; (((__480_1_r._Vals))[0]) = ((((__480_1_z1._Vals))[0]) - (((__480_1_z2._Vals))[0])); (((
# 362
__480_1_r._Vals))[1]) = ((((__480_1_z1._Vals))[1]) - (((__480_1_z2._Vals))[1])); { __T240886544 = __480_1_r; return __T240886544; } }


_Complex_long_double __c99_complex_long_double_multiply( _Complex_long_double __483_1_z1,  _Complex_long_double __483_1_z2) { auto struct _Complex_long_double __T240897944; auto _Complex_long_double __483_1_r; (((__483_1_r._Vals))[0]) = (((((__483_1_z1._Vals))[0]) * (((__483_1_z2._Vals))[0])) - ((((
# 365
__483_1_z1._Vals))[1]) * (((__483_1_z2._Vals))[1]))); (((__483_1_r._Vals))[1]) = (((((__483_1_z1._Vals))[0]) * (((__483_1_z2._Vals))[1])) + ((((__483_1_z1._Vals))[1]) * (((__483_1_z2._Vals))[0]))); { __T240897944 = __483_1_r; return __T240897944; } }


_Complex_long_double __c99_complex_long_double_divide( _Complex_long_double __486_1_z1,  _Complex_long_double __486_1_z2) { auto struct _Complex_long_double __T240914664; auto _Complex_long_double __486_1_r; auto long double __486_1_d; __486_1_d = (((((__486_1_z2._Vals))[0]) * (((__486_1_z2._Vals))[0
# 368
])) + ((((__486_1_z2._Vals))[1]) * (((__486_1_z2._Vals))[1]))); (((__486_1_r._Vals))[0]) = ((((((__486_1_z1._Vals))[0]) * (((__486_1_z2._Vals))[0])) + ((((__486_1_z1._Vals))[1]) * (((__486_1_z2._Vals))[1]))) / __486_1_d); (((__486_1_r._Vals))[1]) = ((((((__486_1_z1._Vals))[1]) * (((__486_1_z2._Vals)
# 368
)[0])) - ((((__486_1_z1._Vals))[0]) * (((__486_1_z2._Vals))[1]))) / __486_1_d); { __T240914664 = __486_1_r; return __T240914664; } }


int __c99_complex_long_double_eq( _Complex_long_double __489_1_z1,  _Complex_long_double __489_1_z2) { return (int)(((((__489_1_z1._Vals))[0]) == (((__489_1_z2._Vals))[0])) && ((((__489_1_z1._Vals))[1]) == (((__489_1_z2._Vals))[1]))); }

int __c99_complex_long_double_ne( _Complex_long_double __491_1_z1,  _Complex_long_double __491_1_z2) { return (int)(((((__491_1_z1._Vals))[0]) != (((__491_1_z2._Vals))[0])) || ((((__491_1_z1._Vals))[1]) != (((__491_1_z2._Vals))[1]))); }

_Complex_long_double __c99_ilong_double_to_clong_double( long double __493_1_j) { auto struct _Complex_long_double __T240929608; auto _Complex_long_double __493_1_r; (((__493_1_r._Vals))[0]) = (0.0L); (((__493_1_r._Vals))[1]) = ((long double)__493_1_j); { __T240929608 = __493_1_r; return 
# 375
__T240929608; } }
_Complex_long_double __c99_long_double_to_clong_double( long double __494_1_j) { auto struct _Complex_long_double __T240934840; auto _Complex_long_double __494_1_r; (((__494_1_r._Vals))[0]) = ((long double)__494_1_j); (((__494_1_r._Vals))[1]) = (0.0L); { __T240934840 = __494_1_r; return __T240934840
# 376
; } }
long double __c99_clong_double_to_ilong_double( _Complex_long_double __495_1_z) { return ((__495_1_z._Vals))[1]; }
long double __c99_clong_double_to_long_double( _Complex_long_double __496_1_z) { return ((__496_1_z._Vals))[0]; }

_Complex_float16 __c99_clong_double_to_cfloat16( _Complex_long_double __498_1_z) { auto struct _Complex_float16 __T240944432; auto _Complex_float16 __498_1_r; (((__498_1_r._Vals))[0]) = ((_Float16)(((__498_1_z._Vals))[0])); (((__498_1_r._Vals))[1]) = ((_Float16)(((__498_1_z._Vals))[1])); { 
# 380
__T240944432 = __498_1_r; return __T240944432; } }



_Complex_bfloat16 __c99_clong_double_to_cbfloat16( _Complex_long_double __502_1_z) { auto struct _Complex_bfloat16 __T240950456; auto _Complex_bfloat16 __502_1_r; (((__502_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__502_1_z._Vals))[0])); (((__502_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__502_1_z._Vals))
# 384
[1])); { __T240950456 = __502_1_r; return __T240950456; } }



_Complex_float __c99_clong_double_to_cfloat( _Complex_long_double __506_1_z) { auto struct _Complex_float __T240956480; auto _Complex_float __506_1_r; (((__506_1_r._Vals))[0]) = ((float)(((__506_1_z._Vals))[0])); (((__506_1_r._Vals))[1]) = ((float)(((__506_1_z._Vals))[1])); { __T240956480 = 
# 388
__506_1_r; return __T240956480; } }

_Complex_double __c99_clong_double_to_cdouble( _Complex_long_double __508_1_z) { auto struct _Complex_double __T240962504; auto _Complex_double __508_1_r; (((__508_1_r._Vals))[0]) = ((double)(((__508_1_z._Vals))[0])); (((__508_1_r._Vals))[1]) = ((double)(((__508_1_z._Vals))[1])); { __T240962504 = 
# 390
__508_1_r; return __T240962504; } }


_Complex_float80 __c99_clong_double_to_cfloat80( _Complex_long_double __511_1_z) { auto struct _Complex_float80 __T240968608; auto _Complex_float80 __511_1_r; (((__511_1_r._Vals))[0]) = ((__float80)(((__511_1_z._Vals))[0])); (((__511_1_r._Vals))[1]) = ((__float80)(((__511_1_z._Vals))[1])); { 
# 393
__T240968608 = __511_1_r; return __T240968608; } }



_Complex_float128 __c99_clong_double_to_cfloat128( _Complex_long_double __515_1_z) { auto struct _Complex_float128 __T240974632; auto _Complex_float128 __515_1_r; (((__515_1_r._Vals))[0]) = ((__float128)(((__515_1_z._Vals))[0])); (((__515_1_r._Vals))[1]) = ((__float128)(((__515_1_z._Vals))[1])); { 
# 397
__T240974632 = __515_1_r; return __T240974632; } }
# 403
_Complex_float80 __c99_complex_float80_negate( _Complex_float80 __521_1_z) { auto struct _Complex_float80 __T240980176; (((__521_1_z._Vals))[0]) = (-(((__521_1_z._Vals))[0])); (((__521_1_z._Vals))[1]) = (-(((__521_1_z._Vals))[1])); { __T240980176 = __521_1_z; return __T240980176; } }
_Complex_float80 __c99_complex_float80_conj( _Complex_float80 __522_1_z) { auto struct _Complex_float80 __T241031792; (((__522_1_z._Vals))[1]) = (-(((__522_1_z._Vals))[1])); { __T241031792 = __522_1_z; return __T241031792; } }
_Complex_float80 __c99_complex_float80_add( _Complex_float80 __523_1_z1,  _Complex_float80 __523_1_z2) { auto struct _Complex_float80 __T241039664; auto _Complex_float80 __523_1_r; (((__523_1_r._Vals))[0]) = ((((__523_1_z1._Vals))[0]) + (((__523_1_z2._Vals))[0])); (((__523_1_r._Vals))[1]) = ((((
# 405
__523_1_z1._Vals))[1]) + (((__523_1_z2._Vals))[1])); { __T241039664 = __523_1_r; return __T241039664; } }

_Complex_float80 __c99_complex_float80_subtract( _Complex_float80 __525_1_z1,  _Complex_float80 __525_1_z2) { auto struct _Complex_float80 __T241047536; auto _Complex_float80 __525_1_r; (((__525_1_r._Vals))[0]) = ((((__525_1_z1._Vals))[0]) - (((__525_1_z2._Vals))[0])); (((__525_1_r._Vals))[1]) = (((
# 407
(__525_1_z1._Vals))[1]) - (((__525_1_z2._Vals))[1])); { __T241047536 = __525_1_r; return __T241047536; } }

_Complex_float80 __c99_complex_float80_multiply( _Complex_float80 __527_1_z1,  _Complex_float80 __527_1_z2) { auto struct _Complex_float80 __T241058736; auto _Complex_float80 __527_1_r; (((__527_1_r._Vals))[0]) = (((((__527_1_z1._Vals))[0]) * (((__527_1_z2._Vals))[0])) - ((((__527_1_z1._Vals))[1]) * 
# 409
(((__527_1_z2._Vals))[1]))); (((__527_1_r._Vals))[1]) = (((((__527_1_z1._Vals))[0]) * (((__527_1_z2._Vals))[1])) + ((((__527_1_z1._Vals))[1]) * (((__527_1_z2._Vals))[0]))); { __T241058736 = __527_1_r; return __T241058736; } }

_Complex_float80 __c99_complex_float80_divide( _Complex_float80 __529_1_z1,  _Complex_float80 __529_1_z2) { auto struct _Complex_float80 __T241075456; auto _Complex_float80 __529_1_r; auto __float80 __529_1_d; __529_1_d = (((((__529_1_z2._Vals))[0]) * (((__529_1_z2._Vals))[0])) + ((((
# 411
__529_1_z2._Vals))[1]) * (((__529_1_z2._Vals))[1]))); (((__529_1_r._Vals))[0]) = ((((((__529_1_z1._Vals))[0]) * (((__529_1_z2._Vals))[0])) + ((((__529_1_z1._Vals))[1]) * (((__529_1_z2._Vals))[1]))) / __529_1_d); (((__529_1_r._Vals))[1]) = ((((((__529_1_z1._Vals))[1]) * (((__529_1_z2._Vals))[0])) - (
# 411
(((__529_1_z1._Vals))[0]) * (((__529_1_z2._Vals))[1]))) / __529_1_d); { __T241075456 = __529_1_r; return __T241075456; } }

int __c99_complex_float80_eq( _Complex_float80 __531_1_z1,  _Complex_float80 __531_1_z2) { return (int)(((((__531_1_z1._Vals))[0]) == (((__531_1_z2._Vals))[0])) && ((((__531_1_z1._Vals))[1]) == (((__531_1_z2._Vals))[1]))); }
int __c99_complex_float80_ne( _Complex_float80 __532_1_z1,  _Complex_float80 __532_1_z2) { return (int)(((((__532_1_z1._Vals))[0]) != (((__532_1_z2._Vals))[0])) || ((((__532_1_z1._Vals))[1]) != (((__532_1_z2._Vals))[1]))); }
_Complex_float80 __c99_ifloat80_to_cfloat80( __float80 __533_1_j) { auto struct _Complex_float80 __T241090400; auto _Complex_float80 __533_1_r; (((__533_1_r._Vals))[0]) = (0.0L); (((__533_1_r._Vals))[1]) = ((__float80)__533_1_j); { __T241090400 = __533_1_r; return __T241090400; } }
_Complex_float80 __c99_float80_to_cfloat80( __float80 __534_1_j) { auto struct _Complex_float80 __T241095776; auto _Complex_float80 __534_1_r; (((__534_1_r._Vals))[0]) = ((__float80)__534_1_j); (((__534_1_r._Vals))[1]) = (0.0L); { __T241095776 = __534_1_r; return __T241095776; } }
__float80 __c99_cfloat80_to_ifloat80( _Complex_float80 __535_1_z) { return ((__535_1_z._Vals))[1]; }
__float80 __c99_cfloat80_to_float80( _Complex_float80 __536_1_z) { return ((__536_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat80_to_cfloat16( _Complex_float80 __538_1_z) { auto struct _Complex_float16 __T241105368; auto _Complex_float16 __538_1_r; (((__538_1_r._Vals))[0]) = ((_Float16)(((__538_1_z._Vals))[0])); (((__538_1_r._Vals))[1]) = ((_Float16)(((__538_1_z._Vals))[1])); { __T241105368 = 
# 420
__538_1_r; return __T241105368; } }



_Complex_bfloat16 __c99_cfloat80_to_cbfloat16( _Complex_float80 __542_1_z) { auto struct _Complex_bfloat16 __T241111392; auto _Complex_bfloat16 __542_1_r; (((__542_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__542_1_z._Vals))[0])); (((__542_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__542_1_z._Vals))[1])); { 
# 424
__T241111392 = __542_1_r; return __T241111392; } }


_Complex_float __c99_cfloat80_to_cfloat( _Complex_float80 __545_1_z) { auto struct _Complex_float __T241117416; auto _Complex_float __545_1_r; (((__545_1_r._Vals))[0]) = ((float)(((__545_1_z._Vals))[0])); (((__545_1_r._Vals))[1]) = ((float)(((__545_1_z._Vals))[1])); { __T241117416 = __545_1_r; 
# 427
return __T241117416; } }
_Complex_double __c99_cfloat80_to_cdouble( _Complex_float80 __546_1_z) { auto struct _Complex_double __T241123440; auto _Complex_double __546_1_r; (((__546_1_r._Vals))[0]) = ((double)(((__546_1_z._Vals))[0])); (((__546_1_r._Vals))[1]) = ((double)(((__546_1_z._Vals))[1])); { __T241123440 = 
# 428
__546_1_r; return __T241123440; } }
_Complex_long_double __c99_cfloat80_to_clong_double( _Complex_float80 __547_1_z) { auto struct _Complex_long_double __T241129464; auto _Complex_long_double __547_1_r; (((__547_1_r._Vals))[0]) = ((long double)(((__547_1_z._Vals))[0])); (((__547_1_r._Vals))[1]) = ((long double)(((__547_1_z._Vals))[1])
# 429
); { __T241129464 = __547_1_r; return __T241129464; } }


_Complex_float128 __c99_cfloat80_to_cfloat128( _Complex_float80 __550_1_z) { auto struct _Complex_float128 __T241135488; auto _Complex_float128 __550_1_r; (((__550_1_r._Vals))[0]) = ((__float128)(((__550_1_z._Vals))[0])); (((__550_1_r._Vals))[1]) = ((__float128)(((__550_1_z._Vals))[1])); { 
# 432
__T241135488 = __550_1_r; return __T241135488; } }
# 439
_Complex_float128 __c99_complex_float128_negate( _Complex_float128 __557_1_z) { auto struct _Complex_float128 __T241141032; (((__557_1_z._Vals))[0]) = (-(((__557_1_z._Vals))[0])); (((__557_1_z._Vals))[1]) = (-(((__557_1_z._Vals))[1])); { __T241141032 = __557_1_z; return __T241141032; } }
_Complex_float128 __c99_complex_float128_conj( _Complex_float128 __558_1_z) { auto struct _Complex_float128 __T241144824; (((__558_1_z._Vals))[1]) = (-(((__558_1_z._Vals))[1])); { __T241144824 = __558_1_z; return __T241144824; } }
_Complex_float128 __c99_complex_float128_add( _Complex_float128 __559_1_z1,  _Complex_float128 __559_1_z2) { auto struct _Complex_float128 __T241152696; auto _Complex_float128 __559_1_r; (((__559_1_r._Vals))[0]) = ((((__559_1_z1._Vals))[0]) + (((__559_1_z2._Vals))[0])); (((__559_1_r._Vals))[1]) = ((
# 441
((__559_1_z1._Vals))[1]) + (((__559_1_z2._Vals))[1])); { __T241152696 = __559_1_r; return __T241152696; } }

_Complex_float128 __c99_complex_float128_subtract( _Complex_float128 __561_1_z1,  _Complex_float128 __561_1_z2) { auto struct _Complex_float128 __T241226272; auto _Complex_float128 __561_1_r; (((__561_1_r._Vals))[0]) = ((((__561_1_z1._Vals))[0]) - (((__561_1_z2._Vals))[0])); (((__561_1_r._Vals))[1]) 
# 443
= ((((__561_1_z1._Vals))[1]) - (((__561_1_z2._Vals))[1])); { __T241226272 = __561_1_r; return __T241226272; } }

_Complex_float128 __c99_complex_float128_multiply( _Complex_float128 __563_1_z1,  _Complex_float128 __563_1_z2) { auto struct _Complex_float128 __T241237472; auto _Complex_float128 __563_1_r; (((__563_1_r._Vals))[0]) = (((((__563_1_z1._Vals))[0]) * (((__563_1_z2._Vals))[0])) - ((((__563_1_z1._Vals))
# 445
[1]) * (((__563_1_z2._Vals))[1]))); (((__563_1_r._Vals))[1]) = (((((__563_1_z1._Vals))[0]) * (((__563_1_z2._Vals))[1])) + ((((__563_1_z1._Vals))[1]) * (((__563_1_z2._Vals))[0]))); { __T241237472 = __563_1_r; return __T241237472; } }

_Complex_float128 __c99_complex_float128_divide( _Complex_float128 __565_1_z1,  _Complex_float128 __565_1_z2) { auto struct _Complex_float128 __T241254192; auto _Complex_float128 __565_1_r; auto __float128 __565_1_d; __565_1_d = (((((__565_1_z2._Vals))[0]) * (((__565_1_z2._Vals))[0])) + ((((
# 447
__565_1_z2._Vals))[1]) * (((__565_1_z2._Vals))[1]))); (((__565_1_r._Vals))[0]) = ((((((__565_1_z1._Vals))[0]) * (((__565_1_z2._Vals))[0])) + ((((__565_1_z1._Vals))[1]) * (((__565_1_z2._Vals))[1]))) / __565_1_d); (((__565_1_r._Vals))[1]) = ((((((__565_1_z1._Vals))[1]) * (((__565_1_z2._Vals))[0])) - (
# 447
(((__565_1_z1._Vals))[0]) * (((__565_1_z2._Vals))[1]))) / __565_1_d); { __T241254192 = __565_1_r; return __T241254192; } }

int __c99_complex_float128_eq( _Complex_float128 __567_1_z1,  _Complex_float128 __567_1_z2) { return (int)(((((__567_1_z1._Vals))[0]) == (((__567_1_z2._Vals))[0])) && ((((__567_1_z1._Vals))[1]) == (((__567_1_z2._Vals))[1]))); }
int __c99_complex_float128_ne( _Complex_float128 __568_1_z1,  _Complex_float128 __568_1_z2) { return (int)(((((__568_1_z1._Vals))[0]) != (((__568_1_z2._Vals))[0])) || ((((__568_1_z1._Vals))[1]) != (((__568_1_z2._Vals))[1]))); }
_Complex_float128 __c99_ifloat128_to_cfloat128( __float128 __569_1_j) { auto struct _Complex_float128 __T241269136; auto _Complex_float128 __569_1_r; (((__569_1_r._Vals))[0]) = (0.0Q); (((__569_1_r._Vals))[1]) = ((__float128)__569_1_j); { __T241269136 = __569_1_r; return __T241269136; } }
_Complex_float128 __c99_float128_to_cfloat128( __float128 __570_1_j) { auto struct _Complex_float128 __T241274368; auto _Complex_float128 __570_1_r; (((__570_1_r._Vals))[0]) = ((__float128)__570_1_j); (((__570_1_r._Vals))[1]) = (0.0Q); { __T241274368 = __570_1_r; return __T241274368; } }
__float128 __c99_cfloat128_to_ifloat128( _Complex_float128 __571_1_z) { return ((__571_1_z._Vals))[1]; }
__float128 __c99_cfloat128_to_float128( _Complex_float128 __572_1_z) { return ((__572_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat128_to_cfloat16( _Complex_float128 __574_1_z) { auto struct _Complex_float16 __T241283960; auto _Complex_float16 __574_1_r; (((__574_1_r._Vals))[0]) = ((_Float16)(((__574_1_z._Vals))[0])); (((__574_1_r._Vals))[1]) = ((_Float16)(((__574_1_z._Vals))[1])); { __T241283960 = 
# 456
__574_1_r; return __T241283960; } }



_Complex_bfloat16 __c99_cfloat128_to_cbfloat16( _Complex_float128 __578_1_z) { auto struct _Complex_bfloat16 __T241289984; auto _Complex_bfloat16 __578_1_r; (((__578_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__578_1_z._Vals))[0])); (((__578_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__578_1_z._Vals))[1])); 
# 460
{ __T241289984 = __578_1_r; return __T241289984; } }


_Complex_float __c99_cfloat128_to_cfloat( _Complex_float128 __581_1_z) { auto struct _Complex_float __T241296232; auto _Complex_float __581_1_r; (((__581_1_r._Vals))[0]) = ((float)(((__581_1_z._Vals))[0])); (((__581_1_r._Vals))[1]) = ((float)(((__581_1_z._Vals))[1])); { __T241296232 = 
# 463
__581_1_r; return __T241296232; } }
_Complex_double __c99_cfloat128_to_cdouble( _Complex_float128 __582_1_z) { auto struct _Complex_double __T241302256; auto _Complex_double __582_1_r; (((__582_1_r._Vals))[0]) = ((double)(((__582_1_z._Vals))[0])); (((__582_1_r._Vals))[1]) = ((double)(((__582_1_z._Vals))[1])); { __T241302256 = 
# 464
__582_1_r; return __T241302256; } }

_Complex_long_double __c99_cfloat128_to_clong_double( _Complex_float128 __584_1_z) { auto struct _Complex_long_double __T241308280; auto _Complex_long_double __584_1_r; (((__584_1_r._Vals))[0]) = ((long double)(((__584_1_z._Vals))[0])); (((__584_1_r._Vals))[1]) = ((long double)(((__584_1_z._Vals))[1
# 466
])); { __T241308280 = __584_1_r; return __T241308280; } }


_Complex_float80 __c99_cfloat128_to_cfloat80( _Complex_float128 __587_1_z) { auto struct _Complex_float80 __T241314304; auto _Complex_float80 __587_1_r; (((__587_1_r._Vals))[0]) = ((__float80)(((__587_1_z._Vals))[0])); (((__587_1_r._Vals))[1]) = ((__float80)(((__587_1_z._Vals))[1])); { __T241314304 
# 469
= __587_1_r; return __T241314304; } }
