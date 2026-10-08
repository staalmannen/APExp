/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
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
_Complex_float16 __c99_complex_float16_negate( _Complex_float16 __332_1_z) { auto struct _Complex_float16 __T679781448; (((__332_1_z._Vals))[0]) = (-(((__332_1_z._Vals))[0])); (((__332_1_z._Vals))[1]) = (-(((__332_1_z._Vals))[1])); { __T679781448 = __332_1_z; return __T679781448; } }
_Complex_float16 __c99_complex_float16_conj( _Complex_float16 __333_1_z) { auto struct _Complex_float16 __T679785240; (((__333_1_z._Vals))[1]) = (-(((__333_1_z._Vals))[1])); { __T679785240 = __333_1_z; return __T679785240; } }
_Complex_float16 __c99_complex_float16_add( _Complex_float16 __334_1_z1,  _Complex_float16 __334_1_z2) { auto struct _Complex_float16 __T679854144; auto _Complex_float16 __334_1_r; (((__334_1_r._Vals))[0]) = ((((__334_1_z1._Vals))[0]) + (((__334_1_z2._Vals))[0])); (((__334_1_r._Vals))[1]) = ((((
#line 216
__334_1_z1._Vals))[1]) + (((__334_1_z2._Vals))[1])); { __T679854144 = __334_1_r; return __T679854144; } }

_Complex_float16 __c99_complex_float16_subtract( _Complex_float16 __336_1_z1,  _Complex_float16 __336_1_z2) { auto struct _Complex_float16 __T679862016; auto _Complex_float16 __336_1_r; (((__336_1_r._Vals))[0]) = ((((__336_1_z1._Vals))[0]) - (((__336_1_z2._Vals))[0])); (((__336_1_r._Vals))[1]) = (((
#line 218
(__336_1_z1._Vals))[1]) - (((__336_1_z2._Vals))[1])); { __T679862016 = __336_1_r; return __T679862016; } }

_Complex_float16 __c99_complex_float16_multiply( _Complex_float16 __338_1_z1,  _Complex_float16 __338_1_z2) { auto struct _Complex_float16 __T679873216; auto _Complex_float16 __338_1_r; (((__338_1_r._Vals))[0]) = (((((__338_1_z1._Vals))[0]) * (((__338_1_z2._Vals))[0])) - ((((__338_1_z1._Vals))[1]) * 
#line 220
(((__338_1_z2._Vals))[1]))); (((__338_1_r._Vals))[1]) = (((((__338_1_z1._Vals))[0]) * (((__338_1_z2._Vals))[1])) + ((((__338_1_z1._Vals))[1]) * (((__338_1_z2._Vals))[0]))); { __T679873216 = __338_1_r; return __T679873216; } }

_Complex_float16 __c99_complex_float16_divide( _Complex_float16 __340_1_z1,  _Complex_float16 __340_1_z2) { auto struct _Complex_float16 __T679889936; auto _Complex_float16 __340_1_r; auto _Float16 __340_1_d; __340_1_d = (((((__340_1_z2._Vals))[0]) * (((__340_1_z2._Vals))[0])) + ((((__340_1_z2._Vals
#line 222
))[1]) * (((__340_1_z2._Vals))[1]))); (((__340_1_r._Vals))[0]) = ((((((__340_1_z1._Vals))[0]) * (((__340_1_z2._Vals))[0])) + ((((__340_1_z1._Vals))[1]) * (((__340_1_z2._Vals))[1]))) / __340_1_d); (((__340_1_r._Vals))[1]) = ((((((__340_1_z1._Vals))[1]) * (((__340_1_z2._Vals))[0])) - ((((
#line 222
__340_1_z1._Vals))[0]) * (((__340_1_z2._Vals))[1]))) / __340_1_d); { __T679889936 = __340_1_r; return __T679889936; } }

int __c99_complex_float16_eq( _Complex_float16 __342_1_z1,  _Complex_float16 __342_1_z2) { return (int)(((((__342_1_z1._Vals))[0]) == (((__342_1_z2._Vals))[0])) && ((((__342_1_z1._Vals))[1]) == (((__342_1_z2._Vals))[1]))); }
int __c99_complex_float16_ne( _Complex_float16 __343_1_z1,  _Complex_float16 __343_1_z2) { return (int)(((((__343_1_z1._Vals))[0]) != (((__343_1_z2._Vals))[0])) || ((((__343_1_z1._Vals))[1]) != (((__343_1_z2._Vals))[1]))); }
_Complex_float16 __c99_ifloat16_to_cfloat16( _Float16 __344_1_j) { auto struct _Complex_float16 __T679904880; auto _Complex_float16 __344_1_r; (((__344_1_r._Vals))[0]) = (0.0F16); (((__344_1_r._Vals))[1]) = ((_Float16)__344_1_j); { __T679904880 = __344_1_r; return __T679904880; } }
_Complex_float16 __c99_float16_to_cfloat16( _Float16 __345_1_j) { auto struct _Complex_float16 __T679910112; auto _Complex_float16 __345_1_r; (((__345_1_r._Vals))[0]) = ((_Float16)__345_1_j); (((__345_1_r._Vals))[1]) = (0.0F16); { __T679910112 = __345_1_r; return __T679910112; } }
_Float16 __c99_cfloat16_to_ifloat16( _Complex_float16 __346_1_z) { return ((__346_1_z._Vals))[1]; }
_Float16 __c99_cfloat16_to_float16( _Complex_float16 __347_1_z) { return ((__347_1_z._Vals))[0]; }

_Complex_bfloat16 __c99_cfloat16_to_cbfloat16( _Complex_float16 __349_1_z) { auto struct _Complex_bfloat16 __T680052616; auto _Complex_bfloat16 __349_1_r; (((__349_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__349_1_z._Vals))[0])); (((__349_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__349_1_z._Vals))[1])); { 
#line 231
__T680052616 = __349_1_r; return __T680052616; } }


_Complex_float __c99_cfloat16_to_cfloat( _Complex_float16 __352_1_z) { auto struct _Complex_float __T680058640; auto _Complex_float __352_1_r; (((__352_1_r._Vals))[0]) = ((float)(((__352_1_z._Vals))[0])); (((__352_1_r._Vals))[1]) = ((float)(((__352_1_z._Vals))[1])); { __T680058640 = __352_1_r; 
#line 234
return __T680058640; } }
_Complex_double __c99_cfloat16_to_cdouble( _Complex_float16 __353_1_z) { auto struct _Complex_double __T680064664; auto _Complex_double __353_1_r; (((__353_1_r._Vals))[0]) = ((double)(((__353_1_z._Vals))[0])); (((__353_1_r._Vals))[1]) = ((double)(((__353_1_z._Vals))[1])); { __T680064664 = 
#line 235
__353_1_r; return __T680064664; } }
_Complex_long_double __c99_cfloat16_to_clong_double( _Complex_float16 __354_1_z) { auto struct _Complex_long_double __T680070688; auto _Complex_long_double __354_1_r; (((__354_1_r._Vals))[0]) = ((long double)(((__354_1_z._Vals))[0])); (((__354_1_r._Vals))[1]) = ((long double)(((__354_1_z._Vals))[1])
#line 236
); { __T680070688 = __354_1_r; return __T680070688; } }
#line 242
_Complex_bfloat16 __c99_complex_bfloat16_negate( _Complex_bfloat16 __360_1_z) { auto struct _Complex_bfloat16 __T680076232; (((__360_1_z._Vals))[0]) = (-(((__360_1_z._Vals))[0])); (((__360_1_z._Vals))[1]) = (-(((__360_1_z._Vals))[1])); { __T680076232 = __360_1_z; return __T680076232; } }
_Complex_bfloat16 __c99_complex_bfloat16_conj( _Complex_bfloat16 __361_1_z) { auto struct _Complex_bfloat16 __T680080024; (((__361_1_z._Vals))[1]) = (-(((__361_1_z._Vals))[1])); { __T680080024 = __361_1_z; return __T680080024; } }
_Complex_bfloat16 __c99_complex_bfloat16_add( _Complex_bfloat16 __362_1_z1,  _Complex_bfloat16 __362_1_z2) { auto struct _Complex_bfloat16 __T680087896; auto _Complex_bfloat16 __362_1_r; (((__362_1_r._Vals))[0]) = ((((__362_1_z1._Vals))[0]) + (((__362_1_z2._Vals))[0])); (((__362_1_r._Vals))[1]) = ((
#line 244
((__362_1_z1._Vals))[1]) + (((__362_1_z2._Vals))[1])); { __T680087896 = __362_1_r; return __T680087896; } }

_Complex_bfloat16 __c99_complex_bfloat16_subtract( _Complex_bfloat16 __364_1_z1,  _Complex_bfloat16 __364_1_z2) { auto struct _Complex_bfloat16 __T680095768; auto _Complex_bfloat16 __364_1_r; (((__364_1_r._Vals))[0]) = ((((__364_1_z1._Vals))[0]) - (((__364_1_z2._Vals))[0])); (((__364_1_r._Vals))[1]) 
#line 246
= ((((__364_1_z1._Vals))[1]) - (((__364_1_z2._Vals))[1])); { __T680095768 = __364_1_r; return __T680095768; } }

_Complex_bfloat16 __c99_complex_bfloat16_multiply( _Complex_bfloat16 __366_1_z1,  _Complex_bfloat16 __366_1_z2) { auto struct _Complex_bfloat16 __T680106968; auto _Complex_bfloat16 __366_1_r; (((__366_1_r._Vals))[0]) = (((((__366_1_z1._Vals))[0]) * (((__366_1_z2._Vals))[0])) - ((((__366_1_z1._Vals))
#line 248
[1]) * (((__366_1_z2._Vals))[1]))); (((__366_1_r._Vals))[1]) = (((((__366_1_z1._Vals))[0]) * (((__366_1_z2._Vals))[1])) + ((((__366_1_z1._Vals))[1]) * (((__366_1_z2._Vals))[0]))); { __T680106968 = __366_1_r; return __T680106968; } }

_Complex_bfloat16 __c99_complex_bfloat16_divide( _Complex_bfloat16 __368_1_z1,  _Complex_bfloat16 __368_1_z2) { auto struct _Complex_bfloat16 __T680130672; auto _Complex_bfloat16 __368_1_r; auto _EDG_bfloat16_t __368_1_d; __368_1_d = (((((__368_1_z2._Vals))[0]) * (((__368_1_z2._Vals))[0])) + ((((
#line 250
__368_1_z2._Vals))[1]) * (((__368_1_z2._Vals))[1]))); (((__368_1_r._Vals))[0]) = ((((((__368_1_z1._Vals))[0]) * (((__368_1_z2._Vals))[0])) + ((((__368_1_z1._Vals))[1]) * (((__368_1_z2._Vals))[1]))) / __368_1_d); (((__368_1_r._Vals))[1]) = ((((((__368_1_z1._Vals))[1]) * (((__368_1_z2._Vals))[0])) - (
#line 250
(((__368_1_z1._Vals))[0]) * (((__368_1_z2._Vals))[1]))) / __368_1_d); { __T680130672 = __368_1_r; return __T680130672; } }

int __c99_complex_bfloat16_eq( _Complex_bfloat16 __370_1_z1,  _Complex_bfloat16 __370_1_z2) { return (int)(((((__370_1_z1._Vals))[0]) == (((__370_1_z2._Vals))[0])) && ((((__370_1_z1._Vals))[1]) == (((__370_1_z2._Vals))[1]))); }
int __c99_complex_bfloat16_ne( _Complex_bfloat16 __371_1_z1,  _Complex_bfloat16 __371_1_z2) { return (int)(((((__371_1_z1._Vals))[0]) != (((__371_1_z2._Vals))[0])) || ((((__371_1_z1._Vals))[1]) != (((__371_1_z2._Vals))[1]))); }
_Complex_bfloat16 __c99_ibfloat16_to_cbfloat16( _EDG_bfloat16_t __372_1_j) { auto struct _Complex_bfloat16 __T680145616; auto _Complex_bfloat16 __372_1_r; (((__372_1_r._Vals))[0]) = (0.0bf16); (((__372_1_r._Vals))[1]) = ((_EDG_bfloat16_t)__372_1_j); { __T680145616 = __372_1_r; return __T680145616; } 
#line 254
}
_Complex_bfloat16 __c99_bfloat16_to_cbfloat16( _EDG_bfloat16_t __373_1_j) { auto struct _Complex_bfloat16 __T680150848; auto _Complex_bfloat16 __373_1_r; (((__373_1_r._Vals))[0]) = ((_EDG_bfloat16_t)__373_1_j); (((__373_1_r._Vals))[1]) = (0.0bf16); { __T680150848 = __373_1_r; return __T680150848; } 
#line 255
}
_EDG_bfloat16_t __c99_cbfloat16_to_ibfloat16( _Complex_bfloat16 __374_1_z) { return ((__374_1_z._Vals))[1]; }
_EDG_bfloat16_t __c99_cbfloat16_to_bfloat16( _Complex_bfloat16 __375_1_z) { return ((__375_1_z._Vals))[0]; }

_Complex_float16 __c99_cbfloat16_to_cfloat16( _Complex_bfloat16 __377_1_z) { auto struct _Complex_float16 __T680160440; auto _Complex_float16 __377_1_r; (((__377_1_r._Vals))[0]) = ((_Float16)(((__377_1_z._Vals))[0])); (((__377_1_r._Vals))[1]) = ((_Float16)(((__377_1_z._Vals))[1])); { __T680160440 = 
#line 259
__377_1_r; return __T680160440; } }


_Complex_float __c99_cbfloat16_to_cfloat( _Complex_bfloat16 __380_1_z) { auto struct _Complex_float __T680166464; auto _Complex_float __380_1_r; (((__380_1_r._Vals))[0]) = ((float)(((__380_1_z._Vals))[0])); (((__380_1_r._Vals))[1]) = ((float)(((__380_1_z._Vals))[1])); { __T680166464 = 
#line 262
__380_1_r; return __T680166464; } }
_Complex_double __c99_cbfloat16_to_cdouble( _Complex_bfloat16 __381_1_z) { auto struct _Complex_double __T680172488; auto _Complex_double __381_1_r; (((__381_1_r._Vals))[0]) = ((double)(((__381_1_z._Vals))[0])); (((__381_1_r._Vals))[1]) = ((double)(((__381_1_z._Vals))[1])); { __T680172488 = 
#line 263
__381_1_r; return __T680172488; } }

_Complex_long_double __c99_cbfloat16_to_clong_double( _Complex_bfloat16 __383_1_z) { auto struct _Complex_long_double __T680178512; auto _Complex_long_double __383_1_r; (((__383_1_r._Vals))[0]) = ((long double)(((__383_1_z._Vals))[0])); (((__383_1_r._Vals))[1]) = ((long double)(((__383_1_z._Vals))[1
#line 265
])); { __T680178512 = __383_1_r; return __T680178512; } }
#line 271
_Complex_float80 __c99_cbfloat16_to_cfloat80( _Complex_bfloat16 __389_1_z) { auto struct _Complex_float80 __T680185528; auto _Complex_float80 __389_1_r; (((__389_1_r._Vals))[0]) = ((__float80)(((__389_1_z._Vals))[0])); (((__389_1_r._Vals))[1]) = ((__float80)(((__389_1_z._Vals))[1])); { __T680185528 
#line 271
= __389_1_r; return __T680185528; } }
#line 277
_Complex_float128 __c99_cbfloat16_to_cfloat128( _Complex_bfloat16 __395_1_z) { auto struct _Complex_float128 __T680191552; auto _Complex_float128 __395_1_r; (((__395_1_r._Vals))[0]) = ((__float128)(((__395_1_z._Vals))[0])); (((__395_1_r._Vals))[1]) = ((__float128)(((__395_1_z._Vals))[1])); { 
#line 277
__T680191552 = __395_1_r; return __T680191552; } }
#line 283
_Complex_float __c99_complex_float_negate( _Complex_float __401_1_z) { auto struct _Complex_float __T680197096; (((__401_1_z._Vals))[0]) = (-(((__401_1_z._Vals))[0])); (((__401_1_z._Vals))[1]) = (-(((__401_1_z._Vals))[1])); { __T680197096 = __401_1_z; return __T680197096; } }
_Complex_float __c99_complex_float_conj( _Complex_float __402_1_z) { auto struct _Complex_float __T680200888; (((__402_1_z._Vals))[1]) = (-(((__402_1_z._Vals))[1])); { __T680200888 = __402_1_z; return __T680200888; } }
_Complex_float __c99_complex_float_add( _Complex_float __403_1_z1,  _Complex_float __403_1_z2) { auto struct _Complex_float __T680208760; auto _Complex_float __403_1_r; (((__403_1_r._Vals))[0]) = ((((__403_1_z1._Vals))[0]) + (((__403_1_z2._Vals))[0])); (((__403_1_r._Vals))[1]) = ((((__403_1_z1._Vals
#line 285
))[1]) + (((__403_1_z2._Vals))[1])); { __T680208760 = __403_1_r; return __T680208760; } }

_Complex_float __c99_complex_float_subtract( _Complex_float __405_1_z1,  _Complex_float __405_1_z2) { auto struct _Complex_float __T680216632; auto _Complex_float __405_1_r; (((__405_1_r._Vals))[0]) = ((((__405_1_z1._Vals))[0]) - (((__405_1_z2._Vals))[0])); (((__405_1_r._Vals))[1]) = ((((
#line 287
__405_1_z1._Vals))[1]) - (((__405_1_z2._Vals))[1])); { __T680216632 = __405_1_r; return __T680216632; } }

_Complex_float __c99_complex_float_multiply( _Complex_float __407_1_z1,  _Complex_float __407_1_z2) { auto struct _Complex_float __T680227832; auto _Complex_float __407_1_r; (((__407_1_r._Vals))[0]) = (((((__407_1_z1._Vals))[0]) * (((__407_1_z2._Vals))[0])) - ((((__407_1_z1._Vals))[1]) * (((
#line 289
__407_1_z2._Vals))[1]))); (((__407_1_r._Vals))[1]) = (((((__407_1_z1._Vals))[0]) * (((__407_1_z2._Vals))[1])) + ((((__407_1_z1._Vals))[1]) * (((__407_1_z2._Vals))[0]))); { __T680227832 = __407_1_r; return __T680227832; } }

_Complex_float __c99_complex_float_divide( _Complex_float __409_1_z1,  _Complex_float __409_1_z2) { auto struct _Complex_float __T680244552; auto _Complex_float __409_1_r; auto float __409_1_d; __409_1_d = (((((__409_1_z2._Vals))[0]) * (((__409_1_z2._Vals))[0])) + ((((__409_1_z2._Vals))[1]) * (((
#line 291
__409_1_z2._Vals))[1]))); (((__409_1_r._Vals))[0]) = ((((((__409_1_z1._Vals))[0]) * (((__409_1_z2._Vals))[0])) + ((((__409_1_z1._Vals))[1]) * (((__409_1_z2._Vals))[1]))) / __409_1_d); (((__409_1_r._Vals))[1]) = ((((((__409_1_z1._Vals))[1]) * (((__409_1_z2._Vals))[0])) - ((((__409_1_z1._Vals))[0]) * 
#line 291
(((__409_1_z2._Vals))[1]))) / __409_1_d); { __T680244552 = __409_1_r; return __T680244552; } }

int __c99_complex_float_eq( _Complex_float __411_1_z1,  _Complex_float __411_1_z2) { return (int)(((((__411_1_z1._Vals))[0]) == (((__411_1_z2._Vals))[0])) && ((((__411_1_z1._Vals))[1]) == (((__411_1_z2._Vals))[1]))); }
int __c99_complex_float_ne( _Complex_float __412_1_z1,  _Complex_float __412_1_z2) { return (int)(((((__412_1_z1._Vals))[0]) != (((__412_1_z2._Vals))[0])) || ((((__412_1_z1._Vals))[1]) != (((__412_1_z2._Vals))[1]))); }
_Complex_float __c99_ifloat_to_cfloat( float __413_1_j) { auto struct _Complex_float __T680260000; auto _Complex_float __413_1_r; (((__413_1_r._Vals))[0]) = (0.0F); (((__413_1_r._Vals))[1]) = ((float)__413_1_j); { __T680260000 = __413_1_r; return __T680260000; } }
_Complex_float __c99_float_to_cfloat( float __414_1_j) { auto struct _Complex_float __T680265232; auto _Complex_float __414_1_r; (((__414_1_r._Vals))[0]) = ((float)__414_1_j); (((__414_1_r._Vals))[1]) = (0.0F); { __T680265232 = __414_1_r; return __T680265232; } }
float __c99_cfloat_to_ifloat( _Complex_float __415_1_z) { return ((__415_1_z._Vals))[1]; }
float __c99_cfloat_to_float( _Complex_float __416_1_z) { return ((__416_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat_to_cfloat16( _Complex_float __418_1_z) { auto struct _Complex_float16 __T680274824; auto _Complex_float16 __418_1_r; (((__418_1_r._Vals))[0]) = ((_Float16)(((__418_1_z._Vals))[0])); (((__418_1_r._Vals))[1]) = ((_Float16)(((__418_1_z._Vals))[1])); { __T680274824 = 
#line 300
__418_1_r; return __T680274824; } }


_Complex_bfloat16 __c99_cfloat_to_cbfloat16( _Complex_float __421_1_z) { auto struct _Complex_bfloat16 __T680280848; auto _Complex_bfloat16 __421_1_r; (((__421_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__421_1_z._Vals))[0])); (((__421_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__421_1_z._Vals))[1])); { 
#line 303
__T680280848 = __421_1_r; return __T680280848; } }


_Complex_double __c99_cfloat_to_cdouble( _Complex_float __424_1_z) { auto struct _Complex_double __T680286872; auto _Complex_double __424_1_r; (((__424_1_r._Vals))[0]) = ((double)(((__424_1_z._Vals))[0])); (((__424_1_r._Vals))[1]) = ((double)(((__424_1_z._Vals))[1])); { __T680286872 = 
#line 306
__424_1_r; return __T680286872; } }
_Complex_long_double __c99_cfloat_to_clong_double( _Complex_float __425_1_z) { auto struct _Complex_long_double __T680292896; auto _Complex_long_double __425_1_r; (((__425_1_r._Vals))[0]) = ((long double)(((__425_1_z._Vals))[0])); (((__425_1_r._Vals))[1]) = ((long double)(((__425_1_z._Vals))[1])); { 
#line 307
__T680292896 = __425_1_r; return __T680292896; } }


_Complex_float80 __c99_cfloat_to_cfloat80( _Complex_float __428_1_z) { auto struct _Complex_float80 __T680298920; auto _Complex_float80 __428_1_r; (((__428_1_r._Vals))[0]) = ((__float80)(((__428_1_z._Vals))[0])); (((__428_1_r._Vals))[1]) = ((__float80)(((__428_1_z._Vals))[1])); { __T680298920 = 
#line 310
__428_1_r; return __T680298920; } }


_Complex_float128 __c99_cfloat_to_cfloat128( _Complex_float __431_1_z) { auto struct _Complex_float128 __T680304944; auto _Complex_float128 __431_1_r; (((__431_1_r._Vals))[0]) = ((__float128)(((__431_1_z._Vals))[0])); (((__431_1_r._Vals))[1]) = ((__float128)(((__431_1_z._Vals))[1])); { __T680304944 
#line 313
= __431_1_r; return __T680304944; } }




_Complex_double __c99_complex_double_negate( _Complex_double __436_1_z) { auto struct _Complex_double __T680310488; (((__436_1_z._Vals))[0]) = (-(((__436_1_z._Vals))[0])); (((__436_1_z._Vals))[1]) = (-(((__436_1_z._Vals))[1])); { __T680310488 = __436_1_z; return __T680310488; } }
_Complex_double __c99_complex_double_conj( _Complex_double __437_1_z) { auto struct _Complex_double __T680379952; (((__437_1_z._Vals))[1]) = (-(((__437_1_z._Vals))[1])); { __T680379952 = __437_1_z; return __T680379952; } }
_Complex_double __c99_complex_double_add( _Complex_double __438_1_z1,  _Complex_double __438_1_z2) { auto struct _Complex_double __T680387824; auto _Complex_double __438_1_r; (((__438_1_r._Vals))[0]) = ((((__438_1_z1._Vals))[0]) + (((__438_1_z2._Vals))[0])); (((__438_1_r._Vals))[1]) = ((((
#line 320
__438_1_z1._Vals))[1]) + (((__438_1_z2._Vals))[1])); { __T680387824 = __438_1_r; return __T680387824; } }

_Complex_double __c99_complex_double_subtract( _Complex_double __440_1_z1,  _Complex_double __440_1_z2) { auto struct _Complex_double __T680449584; auto _Complex_double __440_1_r; (((__440_1_r._Vals))[0]) = ((((__440_1_z1._Vals))[0]) - (((__440_1_z2._Vals))[0])); (((__440_1_r._Vals))[1]) = ((((
#line 322
__440_1_z1._Vals))[1]) - (((__440_1_z2._Vals))[1])); { __T680449584 = __440_1_r; return __T680449584; } }

_Complex_double __c99_complex_double_multiply( _Complex_double __442_1_z1,  _Complex_double __442_1_z2) { auto struct _Complex_double __T680460784; auto _Complex_double __442_1_r; (((__442_1_r._Vals))[0]) = (((((__442_1_z1._Vals))[0]) * (((__442_1_z2._Vals))[0])) - ((((__442_1_z1._Vals))[1]) * (((
#line 324
__442_1_z2._Vals))[1]))); (((__442_1_r._Vals))[1]) = (((((__442_1_z1._Vals))[0]) * (((__442_1_z2._Vals))[1])) + ((((__442_1_z1._Vals))[1]) * (((__442_1_z2._Vals))[0]))); { __T680460784 = __442_1_r; return __T680460784; } }

_Complex_double __c99_complex_double_divide( _Complex_double __444_1_z1,  _Complex_double __444_1_z2) { auto struct _Complex_double __T680477504; auto _Complex_double __444_1_r; auto double __444_1_d; __444_1_d = (((((__444_1_z2._Vals))[0]) * (((__444_1_z2._Vals))[0])) + ((((__444_1_z2._Vals))[1]) * 
#line 326
(((__444_1_z2._Vals))[1]))); (((__444_1_r._Vals))[0]) = ((((((__444_1_z1._Vals))[0]) * (((__444_1_z2._Vals))[0])) + ((((__444_1_z1._Vals))[1]) * (((__444_1_z2._Vals))[1]))) / __444_1_d); (((__444_1_r._Vals))[1]) = ((((((__444_1_z1._Vals))[1]) * (((__444_1_z2._Vals))[0])) - ((((__444_1_z1._Vals))[0]) 
#line 326
* (((__444_1_z2._Vals))[1]))) / __444_1_d); { __T680477504 = __444_1_r; return __T680477504; } }

int __c99_complex_double_eq( _Complex_double __446_1_z1,  _Complex_double __446_1_z2) { return (int)(((((__446_1_z1._Vals))[0]) == (((__446_1_z2._Vals))[0])) && ((((__446_1_z1._Vals))[1]) == (((__446_1_z2._Vals))[1]))); }
int __c99_complex_double_ne( _Complex_double __447_1_z1,  _Complex_double __447_1_z2) { return (int)(((((__447_1_z1._Vals))[0]) != (((__447_1_z2._Vals))[0])) || ((((__447_1_z1._Vals))[1]) != (((__447_1_z2._Vals))[1]))); }
_Complex_double __c99_idouble_to_cdouble( double __448_1_j) { auto struct _Complex_double __T680492448; auto _Complex_double __448_1_r; (((__448_1_r._Vals))[0]) = (0.0); (((__448_1_r._Vals))[1]) = ((double)__448_1_j); { __T680492448 = __448_1_r; return __T680492448; } }
_Complex_double __c99_double_to_cdouble( double __449_1_j) { auto struct _Complex_double __T680497680; auto _Complex_double __449_1_r; (((__449_1_r._Vals))[0]) = ((double)__449_1_j); (((__449_1_r._Vals))[1]) = (0.0); { __T680497680 = __449_1_r; return __T680497680; } }
double __c99_cdouble_to_idouble( _Complex_double __450_1_z) { return ((__450_1_z._Vals))[1]; }
double __c99_cdouble_to_double( _Complex_double __451_1_z) { return ((__451_1_z._Vals))[0]; }

_Complex_float16 __c99_cdouble_to_cfloat16( _Complex_double __453_1_z) { auto struct _Complex_float16 __T680507272; auto _Complex_float16 __453_1_r; (((__453_1_r._Vals))[0]) = ((_Float16)(((__453_1_z._Vals))[0])); (((__453_1_r._Vals))[1]) = ((_Float16)(((__453_1_z._Vals))[1])); { __T680507272 = 
#line 335
__453_1_r; return __T680507272; } }



_Complex_bfloat16 __c99_cdouble_to_cbfloat16( _Complex_double __457_1_z) { auto struct _Complex_bfloat16 __T680513424; auto _Complex_bfloat16 __457_1_r; (((__457_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__457_1_z._Vals))[0])); (((__457_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__457_1_z._Vals))[1])); { 
#line 339
__T680513424 = __457_1_r; return __T680513424; } }


_Complex_float __c99_cdouble_to_cfloat( _Complex_double __460_1_z) { auto struct _Complex_float __T680519448; auto _Complex_float __460_1_r; (((__460_1_r._Vals))[0]) = ((float)(((__460_1_z._Vals))[0])); (((__460_1_r._Vals))[1]) = ((float)(((__460_1_z._Vals))[1])); { __T680519448 = __460_1_r; return 
#line 342
__T680519448; } }
_Complex_long_double __c99_cdouble_to_clong_double( _Complex_double __461_1_z) { auto struct _Complex_long_double __T680525472; auto _Complex_long_double __461_1_r; (((__461_1_r._Vals))[0]) = ((long double)(((__461_1_z._Vals))[0])); (((__461_1_r._Vals))[1]) = ((long double)(((__461_1_z._Vals))[1])); 
#line 343
{ __T680525472 = __461_1_r; return __T680525472; } }


_Complex_float80 __c99_cdouble_to_cfloat80( _Complex_double __464_1_z) { auto struct _Complex_float80 __T680531496; auto _Complex_float80 __464_1_r; (((__464_1_r._Vals))[0]) = ((__float80)(((__464_1_z._Vals))[0])); (((__464_1_r._Vals))[1]) = ((__float80)(((__464_1_z._Vals))[1])); { __T680531496 = 
#line 346
__464_1_r; return __T680531496; } }



_Complex_float128 __c99_cdouble_to_cfloat128( _Complex_double __468_1_z) { auto struct _Complex_float128 __T680537520; auto _Complex_float128 __468_1_r; (((__468_1_r._Vals))[0]) = ((__float128)(((__468_1_z._Vals))[0])); (((__468_1_r._Vals))[1]) = ((__float128)(((__468_1_z._Vals))[1])); { 
#line 350
__T680537520 = __468_1_r; return __T680537520; } }




_Complex_long_double __c99_complex_long_double_negate( _Complex_long_double __473_1_z) { auto struct _Complex_long_double __T680543064; (((__473_1_z._Vals))[0]) = (-(((__473_1_z._Vals))[0])); (((__473_1_z._Vals))[1]) = (-(((__473_1_z._Vals))[1])); { __T680543064 = __473_1_z; return __T680543064; } }

_Complex_long_double __c99_complex_long_double_conj( _Complex_long_double __475_1_z) { auto struct _Complex_long_double __T680546856; (((__475_1_z._Vals))[1]) = (-(((__475_1_z._Vals))[1])); { __T680546856 = __475_1_z; return __T680546856; } }

_Complex_long_double __c99_complex_long_double_add( _Complex_long_double __477_1_z1,  _Complex_long_double __477_1_z2) { auto struct _Complex_long_double __T680554728; auto _Complex_long_double __477_1_r; (((__477_1_r._Vals))[0]) = ((((__477_1_z1._Vals))[0]) + (((__477_1_z2._Vals))[0])); (((
#line 359
__477_1_r._Vals))[1]) = ((((__477_1_z1._Vals))[1]) + (((__477_1_z2._Vals))[1])); { __T680554728 = __477_1_r; return __T680554728; } }


_Complex_long_double __c99_complex_long_double_subtract( _Complex_long_double __480_1_z1,  _Complex_long_double __480_1_z2) { auto struct _Complex_long_double __T680562600; auto _Complex_long_double __480_1_r; (((__480_1_r._Vals))[0]) = ((((__480_1_z1._Vals))[0]) - (((__480_1_z2._Vals))[0])); (((
#line 362
__480_1_r._Vals))[1]) = ((((__480_1_z1._Vals))[1]) - (((__480_1_z2._Vals))[1])); { __T680562600 = __480_1_r; return __T680562600; } }


_Complex_long_double __c99_complex_long_double_multiply( _Complex_long_double __483_1_z1,  _Complex_long_double __483_1_z2) { auto struct _Complex_long_double __T680573952; auto _Complex_long_double __483_1_r; (((__483_1_r._Vals))[0]) = (((((__483_1_z1._Vals))[0]) * (((__483_1_z2._Vals))[0])) - ((((
#line 365
__483_1_z1._Vals))[1]) * (((__483_1_z2._Vals))[1]))); (((__483_1_r._Vals))[1]) = (((((__483_1_z1._Vals))[0]) * (((__483_1_z2._Vals))[1])) + ((((__483_1_z1._Vals))[1]) * (((__483_1_z2._Vals))[0]))); { __T680573952 = __483_1_r; return __T680573952; } }


_Complex_long_double __c99_complex_long_double_divide( _Complex_long_double __486_1_z1,  _Complex_long_double __486_1_z2) { auto struct _Complex_long_double __T680590672; auto _Complex_long_double __486_1_r; auto long double __486_1_d; __486_1_d = (((((__486_1_z2._Vals))[0]) * (((__486_1_z2._Vals))[0
#line 368
])) + ((((__486_1_z2._Vals))[1]) * (((__486_1_z2._Vals))[1]))); (((__486_1_r._Vals))[0]) = ((((((__486_1_z1._Vals))[0]) * (((__486_1_z2._Vals))[0])) + ((((__486_1_z1._Vals))[1]) * (((__486_1_z2._Vals))[1]))) / __486_1_d); (((__486_1_r._Vals))[1]) = ((((((__486_1_z1._Vals))[1]) * (((__486_1_z2._Vals)
#line 368
)[0])) - ((((__486_1_z1._Vals))[0]) * (((__486_1_z2._Vals))[1]))) / __486_1_d); { __T680590672 = __486_1_r; return __T680590672; } }


int __c99_complex_long_double_eq( _Complex_long_double __489_1_z1,  _Complex_long_double __489_1_z2) { return (int)(((((__489_1_z1._Vals))[0]) == (((__489_1_z2._Vals))[0])) && ((((__489_1_z1._Vals))[1]) == (((__489_1_z2._Vals))[1]))); }

int __c99_complex_long_double_ne( _Complex_long_double __491_1_z1,  _Complex_long_double __491_1_z2) { return (int)(((((__491_1_z1._Vals))[0]) != (((__491_1_z2._Vals))[0])) || ((((__491_1_z1._Vals))[1]) != (((__491_1_z2._Vals))[1]))); }

_Complex_long_double __c99_ilong_double_to_clong_double( long double __493_1_j) { auto struct _Complex_long_double __T680605616; auto _Complex_long_double __493_1_r; (((__493_1_r._Vals))[0]) = (0.0L); (((__493_1_r._Vals))[1]) = ((long double)__493_1_j); { __T680605616 = __493_1_r; return 
#line 375
__T680605616; } }
_Complex_long_double __c99_long_double_to_clong_double( long double __494_1_j) { auto struct _Complex_long_double __T680610848; auto _Complex_long_double __494_1_r; (((__494_1_r._Vals))[0]) = ((long double)__494_1_j); (((__494_1_r._Vals))[1]) = (0.0L); { __T680610848 = __494_1_r; return __T680610848
#line 376
; } }
long double __c99_clong_double_to_ilong_double( _Complex_long_double __495_1_z) { return ((__495_1_z._Vals))[1]; }
long double __c99_clong_double_to_long_double( _Complex_long_double __496_1_z) { return ((__496_1_z._Vals))[0]; }

_Complex_float16 __c99_clong_double_to_cfloat16( _Complex_long_double __498_1_z) { auto struct _Complex_float16 __T680620440; auto _Complex_float16 __498_1_r; (((__498_1_r._Vals))[0]) = ((_Float16)(((__498_1_z._Vals))[0])); (((__498_1_r._Vals))[1]) = ((_Float16)(((__498_1_z._Vals))[1])); { 
#line 380
__T680620440 = __498_1_r; return __T680620440; } }



_Complex_bfloat16 __c99_clong_double_to_cbfloat16( _Complex_long_double __502_1_z) { auto struct _Complex_bfloat16 __T680626464; auto _Complex_bfloat16 __502_1_r; (((__502_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__502_1_z._Vals))[0])); (((__502_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__502_1_z._Vals))
#line 384
[1])); { __T680626464 = __502_1_r; return __T680626464; } }



_Complex_float __c99_clong_double_to_cfloat( _Complex_long_double __506_1_z) { auto struct _Complex_float __T680632488; auto _Complex_float __506_1_r; (((__506_1_r._Vals))[0]) = ((float)(((__506_1_z._Vals))[0])); (((__506_1_r._Vals))[1]) = ((float)(((__506_1_z._Vals))[1])); { __T680632488 = 
#line 388
__506_1_r; return __T680632488; } }

_Complex_double __c99_clong_double_to_cdouble( _Complex_long_double __508_1_z) { auto struct _Complex_double __T680638512; auto _Complex_double __508_1_r; (((__508_1_r._Vals))[0]) = ((double)(((__508_1_z._Vals))[0])); (((__508_1_r._Vals))[1]) = ((double)(((__508_1_z._Vals))[1])); { __T680638512 = 
#line 390
__508_1_r; return __T680638512; } }


_Complex_float80 __c99_clong_double_to_cfloat80( _Complex_long_double __511_1_z) { auto struct _Complex_float80 __T680644616; auto _Complex_float80 __511_1_r; (((__511_1_r._Vals))[0]) = ((__float80)(((__511_1_z._Vals))[0])); (((__511_1_r._Vals))[1]) = ((__float80)(((__511_1_z._Vals))[1])); { 
#line 393
__T680644616 = __511_1_r; return __T680644616; } }



_Complex_float128 __c99_clong_double_to_cfloat128( _Complex_long_double __515_1_z) { auto struct _Complex_float128 __T680650640; auto _Complex_float128 __515_1_r; (((__515_1_r._Vals))[0]) = ((__float128)(((__515_1_z._Vals))[0])); (((__515_1_r._Vals))[1]) = ((__float128)(((__515_1_z._Vals))[1])); { 
#line 397
__T680650640 = __515_1_r; return __T680650640; } }
#line 403
_Complex_float80 __c99_complex_float80_negate( _Complex_float80 __521_1_z) { auto struct _Complex_float80 __T680656184; (((__521_1_z._Vals))[0]) = (-(((__521_1_z._Vals))[0])); (((__521_1_z._Vals))[1]) = (-(((__521_1_z._Vals))[1])); { __T680656184 = __521_1_z; return __T680656184; } }
_Complex_float80 __c99_complex_float80_conj( _Complex_float80 __522_1_z) { auto struct _Complex_float80 __T680659976; (((__522_1_z._Vals))[1]) = (-(((__522_1_z._Vals))[1])); { __T680659976 = __522_1_z; return __T680659976; } }
_Complex_float80 __c99_complex_float80_add( _Complex_float80 __523_1_z1,  _Complex_float80 __523_1_z2) { auto struct _Complex_float80 __T680667848; auto _Complex_float80 __523_1_r; (((__523_1_r._Vals))[0]) = ((((__523_1_z1._Vals))[0]) + (((__523_1_z2._Vals))[0])); (((__523_1_r._Vals))[1]) = ((((
#line 405
__523_1_z1._Vals))[1]) + (((__523_1_z2._Vals))[1])); { __T680667848 = __523_1_r; return __T680667848; } }

_Complex_float80 __c99_complex_float80_subtract( _Complex_float80 __525_1_z1,  _Complex_float80 __525_1_z2) { auto struct _Complex_float80 __T680675720; auto _Complex_float80 __525_1_r; (((__525_1_r._Vals))[0]) = ((((__525_1_z1._Vals))[0]) - (((__525_1_z2._Vals))[0])); (((__525_1_r._Vals))[1]) = (((
#line 407
(__525_1_z1._Vals))[1]) - (((__525_1_z2._Vals))[1])); { __T680675720 = __525_1_r; return __T680675720; } }

_Complex_float80 __c99_complex_float80_multiply( _Complex_float80 __527_1_z1,  _Complex_float80 __527_1_z2) { auto struct _Complex_float80 __T680686920; auto _Complex_float80 __527_1_r; (((__527_1_r._Vals))[0]) = (((((__527_1_z1._Vals))[0]) * (((__527_1_z2._Vals))[0])) - ((((__527_1_z1._Vals))[1]) * 
#line 409
(((__527_1_z2._Vals))[1]))); (((__527_1_r._Vals))[1]) = (((((__527_1_z1._Vals))[0]) * (((__527_1_z2._Vals))[1])) + ((((__527_1_z1._Vals))[1]) * (((__527_1_z2._Vals))[0]))); { __T680686920 = __527_1_r; return __T680686920; } }

_Complex_float80 __c99_complex_float80_divide( _Complex_float80 __529_1_z1,  _Complex_float80 __529_1_z2) { auto struct _Complex_float80 __T680703640; auto _Complex_float80 __529_1_r; auto __float80 __529_1_d; __529_1_d = (((((__529_1_z2._Vals))[0]) * (((__529_1_z2._Vals))[0])) + ((((
#line 411
__529_1_z2._Vals))[1]) * (((__529_1_z2._Vals))[1]))); (((__529_1_r._Vals))[0]) = ((((((__529_1_z1._Vals))[0]) * (((__529_1_z2._Vals))[0])) + ((((__529_1_z1._Vals))[1]) * (((__529_1_z2._Vals))[1]))) / __529_1_d); (((__529_1_r._Vals))[1]) = ((((((__529_1_z1._Vals))[1]) * (((__529_1_z2._Vals))[0])) - (
#line 411
(((__529_1_z1._Vals))[0]) * (((__529_1_z2._Vals))[1]))) / __529_1_d); { __T680703640 = __529_1_r; return __T680703640; } }

int __c99_complex_float80_eq( _Complex_float80 __531_1_z1,  _Complex_float80 __531_1_z2) { return (int)(((((__531_1_z1._Vals))[0]) == (((__531_1_z2._Vals))[0])) && ((((__531_1_z1._Vals))[1]) == (((__531_1_z2._Vals))[1]))); }
int __c99_complex_float80_ne( _Complex_float80 __532_1_z1,  _Complex_float80 __532_1_z2) { return (int)(((((__532_1_z1._Vals))[0]) != (((__532_1_z2._Vals))[0])) || ((((__532_1_z1._Vals))[1]) != (((__532_1_z2._Vals))[1]))); }
_Complex_float80 __c99_ifloat80_to_cfloat80( __float80 __533_1_j) { auto struct _Complex_float80 __T680718864; auto _Complex_float80 __533_1_r; (((__533_1_r._Vals))[0]) = (0.0L); (((__533_1_r._Vals))[1]) = ((__float80)__533_1_j); { __T680718864 = __533_1_r; return __T680718864; } }
_Complex_float80 __c99_float80_to_cfloat80( __float80 __534_1_j) { auto struct _Complex_float80 __T680724096; auto _Complex_float80 __534_1_r; (((__534_1_r._Vals))[0]) = ((__float80)__534_1_j); (((__534_1_r._Vals))[1]) = (0.0L); { __T680724096 = __534_1_r; return __T680724096; } }
__float80 __c99_cfloat80_to_ifloat80( _Complex_float80 __535_1_z) { return ((__535_1_z._Vals))[1]; }
__float80 __c99_cfloat80_to_float80( _Complex_float80 __536_1_z) { return ((__536_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat80_to_cfloat16( _Complex_float80 __538_1_z) { auto struct _Complex_float16 __T680733688; auto _Complex_float16 __538_1_r; (((__538_1_r._Vals))[0]) = ((_Float16)(((__538_1_z._Vals))[0])); (((__538_1_r._Vals))[1]) = ((_Float16)(((__538_1_z._Vals))[1])); { __T680733688 = 
#line 420
__538_1_r; return __T680733688; } }



_Complex_bfloat16 __c99_cfloat80_to_cbfloat16( _Complex_float80 __542_1_z) { auto struct _Complex_bfloat16 __T680739712; auto _Complex_bfloat16 __542_1_r; (((__542_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__542_1_z._Vals))[0])); (((__542_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__542_1_z._Vals))[1])); { 
#line 424
__T680739712 = __542_1_r; return __T680739712; } }


_Complex_float __c99_cfloat80_to_cfloat( _Complex_float80 __545_1_z) { auto struct _Complex_float __T680745736; auto _Complex_float __545_1_r; (((__545_1_r._Vals))[0]) = ((float)(((__545_1_z._Vals))[0])); (((__545_1_r._Vals))[1]) = ((float)(((__545_1_z._Vals))[1])); { __T680745736 = __545_1_r; 
#line 427
return __T680745736; } }
_Complex_double __c99_cfloat80_to_cdouble( _Complex_float80 __546_1_z) { auto struct _Complex_double __T680751760; auto _Complex_double __546_1_r; (((__546_1_r._Vals))[0]) = ((double)(((__546_1_z._Vals))[0])); (((__546_1_r._Vals))[1]) = ((double)(((__546_1_z._Vals))[1])); { __T680751760 = 
#line 428
__546_1_r; return __T680751760; } }
_Complex_long_double __c99_cfloat80_to_clong_double( _Complex_float80 __547_1_z) { auto struct _Complex_long_double __T680757784; auto _Complex_long_double __547_1_r; (((__547_1_r._Vals))[0]) = ((long double)(((__547_1_z._Vals))[0])); (((__547_1_r._Vals))[1]) = ((long double)(((__547_1_z._Vals))[1])
#line 429
); { __T680757784 = __547_1_r; return __T680757784; } }


_Complex_float128 __c99_cfloat80_to_cfloat128( _Complex_float80 __550_1_z) { auto struct _Complex_float128 __T680763808; auto _Complex_float128 __550_1_r; (((__550_1_r._Vals))[0]) = ((__float128)(((__550_1_z._Vals))[0])); (((__550_1_r._Vals))[1]) = ((__float128)(((__550_1_z._Vals))[1])); { 
#line 432
__T680763808 = __550_1_r; return __T680763808; } }
#line 439
_Complex_float128 __c99_complex_float128_negate( _Complex_float128 __557_1_z) { auto struct _Complex_float128 __T680769352; (((__557_1_z._Vals))[0]) = (-(((__557_1_z._Vals))[0])); (((__557_1_z._Vals))[1]) = (-(((__557_1_z._Vals))[1])); { __T680769352 = __557_1_z; return __T680769352; } }
_Complex_float128 __c99_complex_float128_conj( _Complex_float128 __558_1_z) { auto struct _Complex_float128 __T680773264; (((__558_1_z._Vals))[1]) = (-(((__558_1_z._Vals))[1])); { __T680773264 = __558_1_z; return __T680773264; } }
_Complex_float128 __c99_complex_float128_add( _Complex_float128 __559_1_z1,  _Complex_float128 __559_1_z2) { auto struct _Complex_float128 __T680781136; auto _Complex_float128 __559_1_r; (((__559_1_r._Vals))[0]) = ((((__559_1_z1._Vals))[0]) + (((__559_1_z2._Vals))[0])); (((__559_1_r._Vals))[1]) = ((
#line 441
((__559_1_z1._Vals))[1]) + (((__559_1_z2._Vals))[1])); { __T680781136 = __559_1_r; return __T680781136; } }

_Complex_float128 __c99_complex_float128_subtract( _Complex_float128 __561_1_z1,  _Complex_float128 __561_1_z2) { auto struct _Complex_float128 __T680789008; auto _Complex_float128 __561_1_r; (((__561_1_r._Vals))[0]) = ((((__561_1_z1._Vals))[0]) - (((__561_1_z2._Vals))[0])); (((__561_1_r._Vals))[1]) 
#line 443
= ((((__561_1_z1._Vals))[1]) - (((__561_1_z2._Vals))[1])); { __T680789008 = __561_1_r; return __T680789008; } }

_Complex_float128 __c99_complex_float128_multiply( _Complex_float128 __563_1_z1,  _Complex_float128 __563_1_z2) { auto struct _Complex_float128 __T680800208; auto _Complex_float128 __563_1_r; (((__563_1_r._Vals))[0]) = (((((__563_1_z1._Vals))[0]) * (((__563_1_z2._Vals))[0])) - ((((__563_1_z1._Vals))
#line 445
[1]) * (((__563_1_z2._Vals))[1]))); (((__563_1_r._Vals))[1]) = (((((__563_1_z1._Vals))[0]) * (((__563_1_z2._Vals))[1])) + ((((__563_1_z1._Vals))[1]) * (((__563_1_z2._Vals))[0]))); { __T680800208 = __563_1_r; return __T680800208; } }

_Complex_float128 __c99_complex_float128_divide( _Complex_float128 __565_1_z1,  _Complex_float128 __565_1_z2) { auto struct _Complex_float128 __T680816928; auto _Complex_float128 __565_1_r; auto __float128 __565_1_d; __565_1_d = (((((__565_1_z2._Vals))[0]) * (((__565_1_z2._Vals))[0])) + ((((
#line 447
__565_1_z2._Vals))[1]) * (((__565_1_z2._Vals))[1]))); (((__565_1_r._Vals))[0]) = ((((((__565_1_z1._Vals))[0]) * (((__565_1_z2._Vals))[0])) + ((((__565_1_z1._Vals))[1]) * (((__565_1_z2._Vals))[1]))) / __565_1_d); (((__565_1_r._Vals))[1]) = ((((((__565_1_z1._Vals))[1]) * (((__565_1_z2._Vals))[0])) - (
#line 447
(((__565_1_z1._Vals))[0]) * (((__565_1_z2._Vals))[1]))) / __565_1_d); { __T680816928 = __565_1_r; return __T680816928; } }

int __c99_complex_float128_eq( _Complex_float128 __567_1_z1,  _Complex_float128 __567_1_z2) { return (int)(((((__567_1_z1._Vals))[0]) == (((__567_1_z2._Vals))[0])) && ((((__567_1_z1._Vals))[1]) == (((__567_1_z2._Vals))[1]))); }
int __c99_complex_float128_ne( _Complex_float128 __568_1_z1,  _Complex_float128 __568_1_z2) { return (int)(((((__568_1_z1._Vals))[0]) != (((__568_1_z2._Vals))[0])) || ((((__568_1_z1._Vals))[1]) != (((__568_1_z2._Vals))[1]))); }
_Complex_float128 __c99_ifloat128_to_cfloat128( __float128 __569_1_j) { auto struct _Complex_float128 __T680831872; auto _Complex_float128 __569_1_r; (((__569_1_r._Vals))[0]) = (0.0Q); (((__569_1_r._Vals))[1]) = ((__float128)__569_1_j); { __T680831872 = __569_1_r; return __T680831872; } }
_Complex_float128 __c99_float128_to_cfloat128( __float128 __570_1_j) { auto struct _Complex_float128 __T680837248; auto _Complex_float128 __570_1_r; (((__570_1_r._Vals))[0]) = ((__float128)__570_1_j); (((__570_1_r._Vals))[1]) = (0.0Q); { __T680837248 = __570_1_r; return __T680837248; } }
__float128 __c99_cfloat128_to_ifloat128( _Complex_float128 __571_1_z) { return ((__571_1_z._Vals))[1]; }
__float128 __c99_cfloat128_to_float128( _Complex_float128 __572_1_z) { return ((__572_1_z._Vals))[0]; }

_Complex_float16 __c99_cfloat128_to_cfloat16( _Complex_float128 __574_1_z) { auto struct _Complex_float16 __T680910168; auto _Complex_float16 __574_1_r; (((__574_1_r._Vals))[0]) = ((_Float16)(((__574_1_z._Vals))[0])); (((__574_1_r._Vals))[1]) = ((_Float16)(((__574_1_z._Vals))[1])); { __T680910168 = 
#line 456
__574_1_r; return __T680910168; } }



_Complex_bfloat16 __c99_cfloat128_to_cbfloat16( _Complex_float128 __578_1_z) { auto struct _Complex_bfloat16 __T680916192; auto _Complex_bfloat16 __578_1_r; (((__578_1_r._Vals))[0]) = ((_EDG_bfloat16_t)(((__578_1_z._Vals))[0])); (((__578_1_r._Vals))[1]) = ((_EDG_bfloat16_t)(((__578_1_z._Vals))[1])); 
#line 460
{ __T680916192 = __578_1_r; return __T680916192; } }


_Complex_float __c99_cfloat128_to_cfloat( _Complex_float128 __581_1_z) { auto struct _Complex_float __T680922216; auto _Complex_float __581_1_r; (((__581_1_r._Vals))[0]) = ((float)(((__581_1_z._Vals))[0])); (((__581_1_r._Vals))[1]) = ((float)(((__581_1_z._Vals))[1])); { __T680922216 = 
#line 463
__581_1_r; return __T680922216; } }
_Complex_double __c99_cfloat128_to_cdouble( _Complex_float128 __582_1_z) { auto struct _Complex_double __T680928240; auto _Complex_double __582_1_r; (((__582_1_r._Vals))[0]) = ((double)(((__582_1_z._Vals))[0])); (((__582_1_r._Vals))[1]) = ((double)(((__582_1_z._Vals))[1])); { __T680928240 = 
#line 464
__582_1_r; return __T680928240; } }

_Complex_long_double __c99_cfloat128_to_clong_double( _Complex_float128 __584_1_z) { auto struct _Complex_long_double __T680934264; auto _Complex_long_double __584_1_r; (((__584_1_r._Vals))[0]) = ((long double)(((__584_1_z._Vals))[0])); (((__584_1_r._Vals))[1]) = ((long double)(((__584_1_z._Vals))[1
#line 466
])); { __T680934264 = __584_1_r; return __T680934264; } }


_Complex_float80 __c99_cfloat128_to_cfloat80( _Complex_float128 __587_1_z) { auto struct _Complex_float80 __T680940288; auto _Complex_float80 __587_1_r; (((__587_1_r._Vals))[0]) = ((__float80)(((__587_1_z._Vals))[0])); (((__587_1_r._Vals))[1]) = ((__float80)(((__587_1_z._Vals))[1])); { __T680940288 
#line 469
= __587_1_r; return __T680940288; } }
