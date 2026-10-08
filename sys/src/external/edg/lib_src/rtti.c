/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/rtti.c"
struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info;
#line 42
struct a_base_class_traversal_block;
#line 107
enum a_result_virtuality { rv_unknown, rv_nonvirtual, rv_directvirtual};
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception;
#line 32 "include_c++/typeinfo.stdh"
struct _ZSt9type_info;
#line 54
struct _ZSt8bad_cast;
#line 63
struct _ZSt10bad_typeid;
#line 52 "include_c++/cxxabi.h"
struct _ZN10__cxxabiv117__class_type_infoE;
#line 58
struct _ZN10__cxxabiv120__si_class_type_infoE;
#line 68
enum _ZN10__cxxabiv122__base_class_type_info20__offset_flags_masksE {
_ZN10__cxxabiv122__base_class_type_info14__virtual_maskE = 0x1,
_ZN10__cxxabiv122__base_class_type_info13__public_maskE = 0x2,
_ZN10__cxxabiv122__base_class_type_info14__offset_shiftE = 8};
#line 64
struct _ZN10__cxxabiv122__base_class_type_infoE;
#line 83
enum _ZN10__cxxabiv121__vmi_class_type_info13__flags_masksE {
_ZN10__cxxabiv121__vmi_class_type_info25__non_diamond_repeat_maskE = 0x1,
_ZN10__cxxabiv121__vmi_class_type_info21__diamond_shaped_maskE = 0x2};
#line 76
struct _ZN10__cxxabiv121__vmi_class_type_infoE; struct __EDG_type_info { const long long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;};
#line 69 "lib_src/basics.h"
typedef int a_boolean;
#line 93 "lib_src/rtti.h"
typedef const struct _ZSt9type_info *a_type_info_impl_ptr;
#line 174
typedef struct _ZN10__cxxabiv122__base_class_type_infoE *a_base_class_spec_ptr;



typedef char *an_access_flag_string;
#line 46 "lib_src/vtbl.h"
typedef long long a_vtbl_entry;



typedef a_vtbl_entry *a_vtbl_entry_ptr;
#line 25 "lib_src/rtti.c"
typedef struct a_base_class_traversal_block *a_base_class_traversal_block_ptr;




typedef void a_base_class_process_function(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
#line 37
typedef a_base_class_process_function *a_base_class_process_function_ptr;




struct a_base_class_traversal_block {

a_base_class_process_function_ptr process_function;




a_base_class_process_function_ptr process_post_function;




a_boolean not_direct_only;



a_boolean public_only;


a_boolean terminate;



a_type_info_impl_ptr downcast_dest_tiip;


a_type_info_impl_ptr downcast_source_tiip;

void *downcast_source_ptr;

void *downcast_dest_ptr;




void *downcast_result;};


typedef struct a_base_class_traversal_block a_base_class_traversal_block;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception { const long long *__vptr;};
#line 35
typedef _Bool _ZSt6__bool;
#line 32 "include_c++/typeinfo.stdh"
struct _ZSt9type_info { const long long *__vptr;
#line 50
const char *__type_name;};



struct _ZSt8bad_cast { struct _ZSt9exception __b_St9exception;};
#line 63
struct _ZSt10bad_typeid { struct _ZSt9exception __b_St9exception;};
#line 52 "include_c++/cxxabi.h"
struct _ZN10__cxxabiv117__class_type_infoE { struct _ZSt9type_info __b_St9type_info;};
#line 58
struct _ZN10__cxxabiv120__si_class_type_infoE { struct _ZN10__cxxabiv117__class_type_infoE __b_N10__cxxabiv117__class_type_infoE;


const struct _ZN10__cxxabiv117__class_type_infoE *__base_type;};


struct _ZN10__cxxabiv122__base_class_type_infoE {
const struct _ZN10__cxxabiv117__class_type_infoE *__base_type;
long __offset_flags;char __dummy[4];};
#line 76
struct _ZN10__cxxabiv121__vmi_class_type_infoE { struct _ZN10__cxxabiv117__class_type_infoE __b_N10__cxxabiv117__class_type_infoE;


unsigned __flags;
unsigned __base_count;
struct _ZN10__cxxabiv122__base_class_type_infoE __base_info[1];};
#line 112 "lib_src/rtti.c"
static void _ZN27_INTERNAL_6_rtti_c_066a44b032clear_base_class_traversal_blockEP28a_base_class_traversal_block(a_base_class_traversal_block_ptr bctbp);
#line 132
static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE(a_base_class_spec_ptr base_info);
#line 152
static void *_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_base_class_spec_ptr bcsp);
#line 168
static void _ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
#line 262
static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(void *ptr, void **p_new_ptr, a_type_info_impl_ptr class_info, a_type_info_impl_ptr base_info, unsigned vmi_flags, a_boolean *p_is_ambiguous, a_boolean 
#line 262
is_accessible, a_type_info_impl_ptr *p_virtual_class_above_result, enum a_result_virtuality *p_result_virtuality, a_boolean *result_is_accessible);
#line 451
extern a_boolean __derived_to_base_conversion(void **p_ptr, void **p_new_ptr, a_type_info_impl_ptr class_info, a_type_info_impl_ptr base_info, an_access_flag_string *access_flags, a_boolean use_access_flags);
#line 648
static a_base_class_spec_ptr _ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(void *obj_ptr, void *base_ptr, a_type_info_impl_ptr obj_info, a_type_info_impl_ptr base_info, a_boolean *found);
#line 759
static void _ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
#line 805
static void _ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
#line 832
static void *_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_(void *complete_object_ptr, a_type_info_impl_ptr object_tiip, void *source_ptr, a_type_info_impl_ptr source_tiip, a_type_info_impl_ptr dest_tiip);
#line 872
extern void *__dynamic_cast(void *class_ptr, a_type_info_impl_ptr source_tiip, a_type_info_impl_ptr dest_tiip, long long hint);
#line 1026
extern void __cxa_bad_cast(void); extern void *__throw_setup_dtor(const void *, unsigned long long, unsigned, void (*)(void *)); extern void __throw(void);
#line 1046
extern void __cxa_bad_typeid(void);
#line 35 "include_c++/typeinfo.stdh"
extern _ZSt6__bool _ZNKSt9type_infoeqERKS_(const struct _ZSt9type_info *const, const struct _ZSt9type_info *);


extern const char *_ZNKSt9type_info4nameEv(const struct _ZSt9type_info *const);
#line 56
extern void _ZNSt8bad_castC1Ev(struct _ZSt8bad_cast *const);


extern void _ZNSt8bad_castD1Ev(struct _ZSt8bad_cast *const);
#line 65
extern void _ZNSt10bad_typeidC1Ev(struct _ZSt10bad_typeid *const);


extern void _ZNSt10bad_typeidD1Ev(struct _ZSt10bad_typeid *const); extern const struct __si_class_type_info _ZTIN10__cxxabiv120__si_class_type_infoE; extern const struct __si_class_type_info _ZTIN10__cxxabiv121__vmi_class_type_infoE; extern const struct __si_class_type_info _ZTISt8bad_cast; extern 
#line 68
const struct __si_class_type_info _ZTISt10bad_typeid;
#line 112 "lib_src/rtti.c"
static void _ZN27_INTERNAL_6_rtti_c_066a44b032clear_base_class_traversal_blockEP28a_base_class_traversal_block(
a_base_class_traversal_block_ptr __3369_38_bctbp)



{
(__3369_38_bctbp->process_function) = ((a_base_class_process_function_ptr)0);
(__3369_38_bctbp->process_post_function) = ((a_base_class_process_function_ptr)0);
(__3369_38_bctbp->not_direct_only) = 0;
(__3369_38_bctbp->public_only) = 0;
(__3369_38_bctbp->terminate) = 0;

(__3369_38_bctbp->downcast_dest_tiip) = ((a_type_info_impl_ptr)0);
(__3369_38_bctbp->downcast_source_tiip) = ((a_type_info_impl_ptr)0);
(__3369_38_bctbp->downcast_source_ptr) = ((void *)0);
(__3369_38_bctbp->downcast_dest_ptr) = ((void *)0);
(__3369_38_bctbp->downcast_result) = ((void *)0); 
}


static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE( a_base_class_spec_ptr __3388_51_base_info)




{
auto a_boolean __3394_13_result = 0;

if (__3388_51_base_info != ((a_base_class_spec_ptr)0)) {

__3394_13_result = ((a_boolean)(((__3388_51_base_info->__offset_flags) & 1L) != 0L));



}
return __3394_13_result;
}



static void *_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE( void *__3408_62_ptr, 
a_base_class_spec_ptr __3409_61_bcsp)




{
auto a_vtbl_entry_ptr __3415_20_vtbl; auto a_vtbl_entry_ptr __3415_26_vbase_offset;

__3415_20_vtbl = (*((a_vtbl_entry_ptr *)__3408_62_ptr));
__3415_26_vbase_offset = ((a_vtbl_entry_ptr)(((char *)__3415_20_vtbl) + ((__3409_61_bcsp->__offset_flags) >> 8)));
return (void *)(((char *)__3408_62_ptr) + (*__3415_26_vbase_offset));
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__3425_14_ptr, 
a_type_info_impl_ptr __3426_27_class_info, 
a_base_class_traversal_block_ptr __3427_37_bctbp, 
a_base_class_spec_ptr __3428_28_curr_base_info)
#line 182
{ auto void *__T890432952; auto a_type_info_impl_ptr __T890433600; auto a_base_class_traversal_block_ptr __T890434336; auto a_base_class_spec_ptr __T890435072; auto void *__T890448072; auto a_type_info_impl_ptr __T890448720; auto a_base_class_traversal_block_ptr __T890449456; auto 
#line 182
a_base_class_spec_ptr __T890450192;


auto a_base_class_spec_ptr __3441_25_bcsp;
auto void *__3442_26_new_ptr;


((((__T890432952 = __3425_14_ptr) , (__T890433600 = __3426_27_class_info)) , (__T890434336 = __3427_37_bctbp)) , (__T890435072 = __3428_28_curr_base_info)) , ((__3427_37_bctbp->process_function)(__T890432952, __T890433600, __T890434336, __T890435072));
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3426_27_class_info) ? ((struct __EDG_type_info *)((__3426_27_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base
#line 190
))))) { auto void *__T890438096; auto const struct _ZSt9type_info *__T890439096; auto a_base_class_traversal_block_ptr __T890439832;
auto struct _ZN10__cxxabiv120__si_class_type_infoE *__3447_32_si_obj_info; __3447_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__3426_27_class_info);


(((__T890438096 = __3425_14_ptr) , (__T890439096 = (&((__3447_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T890439832 = __3427_37_bctbp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
#line 194
__T890438096, __T890439096, __T890439832, ((a_base_class_spec_ptr)0)));

} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3426_27_class_info) ? ((struct __EDG_type_info *)((__3426_27_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE
#line 196
.base).base))))) { auto void *__T890444688; auto const struct _ZSt9type_info *__T890445688; auto a_base_class_traversal_block_ptr __T890446424; auto a_base_class_spec_ptr __T890447160;
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3453_33_vmi_obj_info; __3453_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3426_27_class_info);

for (__3441_25_bcsp = ((__3453_33_vmi_obj_info->__base_info)); __3441_25_bcsp < (((__3453_33_vmi_obj_info->__base_info)) + (__3453_33_vmi_obj_info->__base_count)); __3441_25_bcsp++)

{


if ((__3427_37_bctbp->public_only) && (((__3441_25_bcsp->__offset_flags) & 2L) == 0L)) {
goto __T890425808;
}
if (_ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE(__3441_25_bcsp)) { auto void *__T890442856; auto a_base_class_spec_ptr __T890443776;
__3442_26_new_ptr = (((__T890442856 = __3425_14_ptr) , (__T890443776 = __3441_25_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T890442856, __T890443776)));
} else  {
__3442_26_new_ptr = ((void *)(((char *)__3425_14_ptr) + ((__3441_25_bcsp->__offset_flags) >> 8)));
}

((((__T890444688 = __3442_26_new_ptr) , (__T890445688 = (&((__3441_25_bcsp->__base_type)->__b_St9type_info)))) , (__T890446424 = __3427_37_bctbp)) , (__T890447160 = __3441_25_bcsp)) , (
#line 213
_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(__T890444688, __T890445688, __T890446424, __T890447160));

if (__3427_37_bctbp->terminate) { goto __3478_1_end_of_routine; } __T890425808:;
}
} }

if ((__3427_37_bctbp->process_post_function) != ((a_base_class_process_function_ptr)0)) {
((((__T890448072 = __3425_14_ptr) , (__T890448720 = __3426_27_class_info)) , (__T890449456 = __3427_37_bctbp)) , (__T890450192 = __3428_28_curr_base_info)) , ((__3427_37_bctbp->process_post_function)(__T890448072, __T890448720, __T890449456, __T890450192));
}
__3478_1_end_of_routine:; ; 
#line 257
}




static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(
void *__3519_12_ptr, 
void **__3520_13_p_new_ptr, 
a_type_info_impl_ptr __3521_25_class_info, 
a_type_info_impl_ptr __3522_25_base_info, 
unsigned __3523_18_vmi_flags, 
a_boolean *__3524_16_p_is_ambiguous, 
a_boolean __3525_15_is_accessible, 
a_type_info_impl_ptr *__3526_29_p_virtual_class_above_result, 
enum a_result_virtuality *__3527_29_p_result_virtuality, 
a_boolean *__3528_16_result_is_accessible)
#line 297
{
auto a_boolean __3554_13_result = 0;
#line 309
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3521_25_class_info) ? ((struct __EDG_type_info *)((__3521_25_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base
#line 309
))))) {

auto struct _ZN10__cxxabiv120__si_class_type_infoE *__3567_32_si_obj_info; __3567_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__3521_25_class_info);

if (((&((__3567_32_si_obj_info->__base_type)->__b_St9type_info)) == __3522_25_base_info) || ((_ZNKSt9type_info4nameEv((&((__3567_32_si_obj_info->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3522_25_base_info)))) {
if (((((*__3520_13_p_new_ptr) != ((void *)0)) && ((*__3520_13_p_new_ptr) != __3519_12_ptr)) || (((int)(*__3527_29_p_result_virtuality)) == 2)) || (*__3524_16_p_is_ambiguous))

{

(*__3524_16_p_is_ambiguous) = 1;
(*__3520_13_p_new_ptr) = ((void *)0);
__3554_13_result = 0;
} else  {
(*__3527_29_p_result_virtuality) = rv_nonvirtual;
(*__3528_16_result_is_accessible) = __3525_15_is_accessible;
(*__3520_13_p_new_ptr) = __3519_12_ptr;
__3554_13_result = 1;
}
} else  { auto void *__T890598024; auto void **__T890598944; auto const struct _ZSt9type_info *__T890600032; auto a_type_info_impl_ptr __T890600768; auto unsigned __T890601504; auto a_boolean *__T890602240; auto a_boolean __T890602976; auto a_type_info_impl_ptr *__T890603712; auto enum 
#line 327
a_result_virtuality *__T890604448; auto a_boolean *__T890605184; if ((((((((((((__T890598024 = __3519_12_ptr) , (__T890598944 = __3520_13_p_new_ptr)) , (__T890600032 = (&((__3567_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T890600768 = __3522_25_base_info)) , (__T890601504 = 
#line 327
__3523_18_vmi_flags)) , (__T890602240 = __3524_16_p_is_ambiguous)) , (__T890602976 = __3525_15_is_accessible)) , (__T890603712 = __3526_29_p_virtual_class_above_result)) , (__T890604448 = __3527_29_p_result_virtuality)) , (__T890605184 = __3528_16_result_is_accessible)) , (
#line 327
_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T890598024, __T890598944, __T890600032, __T890600768, __T890601504, __T890602240, __T890602976, __T890603712, __T890604448, __T890605184))) || (*__3524_16_p_is_ambiguous))
#line 334
{
if (*__3524_16_p_is_ambiguous) {
__3554_13_result = 0;
} else  {
__3554_13_result = 1;
}
} }
} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3521_25_class_info) ? ((struct __EDG_type_info *)((__3521_25_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE
#line 341
.base).base))))) {

auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3599_33_vmi_obj_info;

auto a_base_class_spec_ptr __3601_32_bcsp;
auto void *__3602_33_base_ptr;
#line 343
__3599_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3521_25_class_info);




for (__3601_32_bcsp = ((__3599_33_vmi_obj_info->__base_info)); __3601_32_bcsp < (((__3599_33_vmi_obj_info->__base_info)) + (__3599_33_vmi_obj_info->__base_count)); __3601_32_bcsp++)

{ auto void *__T890608208; auto a_base_class_spec_ptr __T890608856;
auto a_boolean __3607_17_base_is_accessible;
auto a_boolean __3608_17_is_virtual; __3608_17_is_virtual = ((a_boolean)(((__3601_32_bcsp->__offset_flags) & 1L) != 0L));
if (__3519_12_ptr == ((void *)0)) {

__3602_33_base_ptr = ((void *)0);
} else  { if (__3608_17_is_virtual) {
__3602_33_base_ptr = (((__T890608208 = __3519_12_ptr) , (__T890608856 = __3601_32_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T890608208, __T890608856)));
} else  {
__3602_33_base_ptr = ((void *)(((char *)__3519_12_ptr) + ((__3601_32_bcsp->__offset_flags) >> 8)));
} }
__3607_17_base_is_accessible = ((a_boolean)((__3525_15_is_accessible) && ((__3601_32_bcsp->__offset_flags) & 2L)));

if (((&((__3601_32_bcsp->__base_type)->__b_St9type_info)) == __3522_25_base_info) || ((_ZNKSt9type_info4nameEv((&((__3601_32_bcsp->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3522_25_base_info)))) {

if (((((*__3520_13_p_new_ptr) != ((void *)0)) && (__3602_33_base_ptr != (*__3520_13_p_new_ptr))) || (((__3601_32_bcsp->__offset_flags) & 1L) && (((int)(*__3527_29_p_result_virtuality)) == 1))) || (*__3524_16_p_is_ambiguous))


{

(*__3524_16_p_is_ambiguous) = 1;
(*__3520_13_p_new_ptr) = ((void *)0);
__3554_13_result = 0;
goto __T890565920;
} else  {

(*__3527_29_p_result_virtuality) = (((__3601_32_bcsp->__offset_flags) & 1L) ? rv_directvirtual : rv_nonvirtual);

(*__3528_16_result_is_accessible) = __3607_17_base_is_accessible;
(*__3520_13_p_new_ptr) = __3602_33_base_ptr;
__3554_13_result = 1;


if (*__3528_16_result_is_accessible) {
if ((__3608_17_is_virtual) ? (!((__3523_18_vmi_flags & 2U) != 0U)) : (!((__3523_18_vmi_flags & 1U) != 0U)))
{
goto __T890565920;
}
}
}
} else  { auto void *__T890610472; auto void **__T890611120; auto const struct _ZSt9type_info *__T890612208; auto a_type_info_impl_ptr __T890612944; auto unsigned __T890613680; auto a_boolean *__T890614416; auto a_boolean __T890615152; auto a_boolean *__T890615888;
auto a_type_info_impl_ptr __3647_23_virtual_class_above_result_here = ((a_type_info_impl_ptr)0);
auto enum a_result_virtuality __3648_22_result_virtuality_here = rv_unknown;
if ((((((((((__T890610472 = __3602_33_base_ptr) , (__T890611120 = __3520_13_p_new_ptr)) , (__T890612208 = (&((__3601_32_bcsp->__base_type)->__b_St9type_info)))) , (__T890612944 = __3522_25_base_info)) , (__T890613680 = __3523_18_vmi_flags)) , (__T890614416 = __3524_16_p_is_ambiguous)) , (
#line 393
__T890615152 = __3607_17_base_is_accessible)) , (__T890615888 = __3528_16_result_is_accessible)) , (_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T890610472, __T890611120, __T890612208, __T890612944, __T890613680, 
#line 393
__T890614416, __T890615152, (&__3647_23_virtual_class_above_result_here), (&__3648_22_result_virtuality_here), __T890615888))) || (*__3524_16_p_is_ambiguous))
#line 401
{
if (*__3524_16_p_is_ambiguous) {
__3554_13_result = 0;
goto __T890565920;
} else  {
if ((__3647_23_virtual_class_above_result_here == ((a_type_info_impl_ptr)0)) && (((__3601_32_bcsp->__offset_flags) & 1L) != 0L))
{
__3647_23_virtual_class_above_result_here = (&((__3601_32_bcsp->__base_type)->__b_St9type_info));
}
if (((((int)(*__3527_29_p_result_virtuality)) == 0) || ((((int)__3648_22_result_virtuality_here) == 2) && (((int)(*__3527_29_p_result_virtuality)) == 2))) || (((*__3526_29_p_virtual_class_above_result) != ((a_type_info_impl_ptr)0)) && ((*__3526_29_p_virtual_class_above_result) == 
#line 410
__3647_23_virtual_class_above_result_here)))
#line 419
{
(*__3527_29_p_result_virtuality) = __3648_22_result_virtuality_here;
(*__3526_29_p_virtual_class_above_result) = __3647_23_virtual_class_above_result_here;
__3554_13_result = 1;


if (*__3528_16_result_is_accessible) {
if ((__3608_17_is_virtual) ? (!((__3523_18_vmi_flags & 2U) != 0U)) : (!((__3523_18_vmi_flags & 1U) != 0U)))
{
goto __T890565920;
}
}
} else  {
(*__3524_16_p_is_ambiguous) = 1;
__3554_13_result = 0;
goto __T890565920;
}
}
}
}
} __T890565920:;
} }
return __3554_13_result;
}
#line 451
a_boolean __derived_to_base_conversion( void **__3707_53_p_ptr, 
void **__3708_36_p_new_ptr, 
a_type_info_impl_ptr __3709_34_class_info, 
a_type_info_impl_ptr __3710_34_base_info, 
an_access_flag_string *__3711_35_access_flags, 
a_boolean __3712_34_use_access_flags)
#line 479
{
auto a_boolean __3736_14_result = 0;
auto void *__3737_26_ptr;
auto a_boolean __3738_14_is_ambiguous = 0;

auto a_boolean __3740_25_result_is_accessible = 1;
#line 491
__3737_26_ptr = ((__3707_53_p_ptr == ((void **)0)) ? ((void *)0) : (*__3707_53_p_ptr));
(*__3708_36_p_new_ptr) = ((void *)0);
#line 617
{ auto void *__T890639608; auto void **__T890640256; auto a_type_info_impl_ptr __T890640992; auto a_type_info_impl_ptr __T890641728; auto unsigned __T890642464;
auto int __3874_9_vmi_flags;
#line 630
auto a_type_info_impl_ptr __3886_26_virtual_class_above_result;
auto enum a_result_virtuality __3887_25_result_virtuality;
#line 622
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3709_34_class_info) ? ((struct __EDG_type_info *)((__3709_34_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).
#line 622
base))))) {
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3879_35_vmi_obj_info; __3879_35_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3709_34_class_info);

__3874_9_vmi_flags = ((int)(__3879_35_vmi_obj_info->__flags));
} else  {
__3874_9_vmi_flags = 0x3;

}
__3886_26_virtual_class_above_result = ((a_type_info_impl_ptr)0);
__3887_25_result_virtuality = rv_unknown;
if (((((((__T890639608 = __3737_26_ptr) , (__T890640256 = __3708_36_p_new_ptr)) , (__T890640992 = __3709_34_class_info)) , (__T890641728 = __3710_34_base_info)) , (__T890642464 = ((unsigned)__3874_9_vmi_flags))) , (
#line 632
_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T890639608, __T890640256, __T890640992, __T890641728, __T890642464, (&__3738_14_is_ambiguous), 1, (&__3886_26_virtual_class_above_result), (&__3887_25_result_virtuality), (&
#line 632
__3740_25_result_is_accessible)))) && (__3740_25_result_is_accessible))
#line 638
{
__3736_14_result = 1;
}
}

return __3736_14_result;
}



static a_base_class_spec_ptr _ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(
void *__3905_14_obj_ptr, 
void *__3906_14_base_ptr, 
a_type_info_impl_ptr __3907_27_obj_info, 
a_type_info_impl_ptr __3908_27_base_info, 
a_boolean *__3909_66_found)
#line 661
{
auto a_base_class_spec_ptr __3918_25_bcsp;
auto void *__3919_26_ptr;
auto void *__3920_26_new_ptr;
auto a_base_class_spec_ptr __3921_25_result = ((a_base_class_spec_ptr)0);




__3919_26_ptr = __3905_14_obj_ptr;
#line 681
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3907_27_obj_info) ? ((struct __EDG_type_info *)((__3907_27_obj_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base))))
#line 681
) {
auto struct _ZN10__cxxabiv120__si_class_type_infoE *__3938_32_si_obj_info; __3938_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__3907_27_obj_info);

if ((__3919_26_ptr == __3906_14_base_ptr) && (((&((__3938_32_si_obj_info->__base_type)->__b_St9type_info)) == __3908_27_base_info) || ((_ZNKSt9type_info4nameEv((&((__3938_32_si_obj_info->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3908_27_base_info)))))
{

(*__3909_66_found) = 1;
} else  { auto void *__T890675560; auto void *__T890676480; auto const struct _ZSt9type_info *__T890677568; auto a_type_info_impl_ptr __T890678304; auto a_boolean *__T890679040;


__3921_25_result = ((((((__T890675560 = __3919_26_ptr) , (__T890676480 = __3906_14_base_ptr)) , (__T890677568 = (&((__3938_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T890678304 = __3908_27_base_info)) , (__T890679040 = __3909_66_found)) , (
#line 691
_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T890675560, __T890676480, __T890677568, __T890678304, __T890679040)));


}
} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3907_27_obj_info) ? ((struct __EDG_type_info *)((__3907_27_obj_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.
#line 695
base).base))))) { auto void *__T890684600; auto void *__T890685248; auto const struct _ZSt9type_info *__T890686336; auto a_type_info_impl_ptr __T890687072; auto a_boolean *__T890687808;
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3952_33_vmi_obj_info; __3952_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3907_27_obj_info);

for (__3918_25_bcsp = ((__3952_33_vmi_obj_info->__base_info)); __3918_25_bcsp < (((__3952_33_vmi_obj_info->__base_info)) + (__3952_33_vmi_obj_info->__base_count)); __3918_25_bcsp++)

{
if ((__3918_25_bcsp->__offset_flags) & 1L) { auto void *__T890682064; auto a_base_class_spec_ptr __T890682984;
__3920_26_new_ptr = (((__T890682064 = __3919_26_ptr) , (__T890682984 = __3918_25_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T890682064, __T890682984)));
} else  {
__3920_26_new_ptr = ((void *)(((char *)__3919_26_ptr) + ((__3918_25_bcsp->__offset_flags) >> 8)));
}
if ((__3920_26_new_ptr == __3906_14_base_ptr) && (((&((__3918_25_bcsp->__base_type)->__b_St9type_info)) == __3908_27_base_info) || ((_ZNKSt9type_info4nameEv((&((__3918_25_bcsp->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3908_27_base_info)))))
{


__3921_25_result = __3918_25_bcsp;
if ((__3918_25_bcsp->__offset_flags) & 2L) { (*__3909_66_found) = 1; }
goto __T890668488;
}
if (((__3918_25_bcsp->__offset_flags) & 2L) != 0L) {

__3921_25_result = ((((((__T890684600 = __3920_26_new_ptr) , (__T890685248 = __3906_14_base_ptr)) , (__T890686336 = (&((__3918_25_bcsp->__base_type)->__b_St9type_info)))) , (__T890687072 = __3908_27_base_info)) , (__T890687808 = __3909_66_found)) , (
#line 716
_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T890684600, __T890685248, __T890686336, __T890687072, __T890687808)));



if (*__3909_66_found) { goto __T890668488; }
}
} __T890668488:;
} }
#line 754
return __3921_25_result;
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__4016_13_ptr, 
a_type_info_impl_ptr __4017_26_class_info, 
a_base_class_traversal_block_ptr __4018_36_bctbp, 
a_base_class_spec_ptr __4019_27_curr_base_info)
#line 774
{
if (((__4018_36_bctbp->downcast_dest_tiip) == __4017_26_class_info) || ((_ZNKSt9type_info4nameEv((__4018_36_bctbp->downcast_dest_tiip))) == (_ZNKSt9type_info4nameEv(__4017_26_class_info)))) {



(__4018_36_bctbp->downcast_dest_ptr) = __4016_13_ptr;
(__4018_36_bctbp->public_only) = 1;
#line 787
} else  { if ((((__4018_36_bctbp->downcast_dest_ptr) != ((void *)0)) && (__4016_13_ptr == (__4018_36_bctbp->downcast_source_ptr))) && ((__4017_26_class_info == (__4018_36_bctbp->downcast_source_tiip)) || ((_ZNKSt9type_info4nameEv(__4017_26_class_info)) == (_ZNKSt9type_info4nameEv((
#line 787
__4018_36_bctbp->downcast_source_tiip))))))

{

if ((__4018_36_bctbp->downcast_result) != ((void *)0)) {


(__4018_36_bctbp->downcast_result) = ((void *)0);
(__4018_36_bctbp->terminate) = 1;
} else  {

(__4018_36_bctbp->downcast_result) = (__4018_36_bctbp->downcast_dest_ptr);
}
} } 
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__4062_13_ptr, 
a_type_info_impl_ptr __4063_26_class_info, 
a_base_class_traversal_block_ptr __4064_36_bctbp, 
a_base_class_spec_ptr __4065_27_curr_base_info)
#line 816
{
if (((__4064_36_bctbp->downcast_dest_tiip) == __4063_26_class_info) || ((_ZNKSt9type_info4nameEv((__4064_36_bctbp->downcast_dest_tiip))) == (_ZNKSt9type_info4nameEv(__4063_26_class_info)))) {


(__4064_36_bctbp->downcast_dest_ptr) = ((void *)0);
(__4064_36_bctbp->public_only) = 0;
#line 828
} 
}


static void *_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_( void *__4088_35_complete_object_ptr, 
a_type_info_impl_ptr __4089_27_object_tiip, 
void *__4090_14_source_ptr, 
a_type_info_impl_ptr __4091_27_source_tiip, 
a_type_info_impl_ptr __4092_27_dest_tiip)
#line 854
{ auto void *__T890715032; auto a_type_info_impl_ptr __T890715680;
auto a_base_class_traversal_block __4111_32_block;

_ZN27_INTERNAL_6_rtti_c_066a44b032clear_base_class_traversal_blockEP28a_base_class_traversal_block((&__4111_32_block));
(__4111_32_block.process_function) = (&_ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE);
(__4111_32_block.process_post_function) = (&_ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE);
(__4111_32_block.downcast_dest_tiip) = __4092_27_dest_tiip;
(__4111_32_block.downcast_source_tiip) = __4091_27_source_tiip;
(__4111_32_block.downcast_source_ptr) = __4090_14_source_ptr;
((__T890715032 = __4088_35_complete_object_ptr) , (__T890715680 = __4089_27_object_tiip)) , (_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(__T890715032, __T890715680, (&__4111_32_block), ((
#line 863
a_base_class_spec_ptr)0)));

return __4111_32_block.downcast_result;
}
#line 872
void *__dynamic_cast( void *__4128_39_class_ptr, 
#line 881
a_type_info_impl_ptr __4137_57_source_tiip, 
a_type_info_impl_ptr __4138_57_dest_tiip, 
long long __4139_57_hint)
#line 926
{ auto void *__T890739816; auto a_type_info_impl_ptr __T890740464; auto void *__T890741200; auto a_type_info_impl_ptr __T890741936; auto a_type_info_impl_ptr __T890742672;
auto void *__4183_11_complete_object_ptr;



auto void *__4187_26_source_ptr;

auto a_type_info_impl_ptr __4189_24_object_tiip;
auto void *__4190_11_result = ((void *)0);
#line 931
__4187_26_source_ptr = __4128_39_class_ptr;
#line 942
__4183_11_complete_object_ptr = ((void *)(((char *)__4128_39_class_ptr) + ((*((a_vtbl_entry_ptr *)__4128_39_class_ptr))[(-2)])));
#line 957
__4189_24_object_tiip = ((a_type_info_impl_ptr)((*((a_vtbl_entry_ptr *)__4128_39_class_ptr))[(-1)]));

if (__4138_57_dest_tiip == ((a_type_info_impl_ptr)0)) {



__4190_11_result = __4183_11_complete_object_ptr;

} else  {


__4190_11_result = ((((((__T890739816 = __4183_11_complete_object_ptr) , (__T890740464 = __4189_24_object_tiip)) , (__T890741200 = __4187_26_source_ptr)) , (__T890741936 = __4137_57_source_tiip)) , (__T890742672 = __4138_57_dest_tiip)) , (
#line 968
_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_(__T890739816, __T890740464, __T890741200, __T890741936, __T890742672)));



}


if (__4190_11_result == ((void *)0)) { auto void *__T890743584; auto void *__T890744232; auto a_type_info_impl_ptr __T890744968; auto a_type_info_impl_ptr __T890745704;
auto a_boolean __4232_15_access_okay = 1;
#line 986
if (__4189_24_object_tiip == __4137_57_source_tiip) {

__4232_15_access_okay = 1;
} else  {
__4232_15_access_okay = 0;
((((__T890743584 = __4183_11_complete_object_ptr) , (__T890744232 = __4187_26_source_ptr)) , (__T890744968 = __4189_24_object_tiip)) , (__T890745704 = __4137_57_source_tiip)) , (_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T890743584, __T890744232, 
#line 991
__T890744968, __T890745704, (&__4232_15_access_okay)));

}

if (__4232_15_access_okay) {
if ((__4189_24_object_tiip == __4138_57_dest_tiip) || ((_ZNKSt9type_info4nameEv(__4189_24_object_tiip)) == (_ZNKSt9type_info4nameEv(__4138_57_dest_tiip)))) {



__4190_11_result = __4183_11_complete_object_ptr;
} else  { auto a_type_info_impl_ptr __T890746616; auto a_type_info_impl_ptr __T890747264;

auto a_boolean __4259_19_conversion_done;
auto void *__4260_16_new_ptr = ((void *)0);
__4259_19_conversion_done = (((__T890746616 = __4189_24_object_tiip) , (__T890747264 = __4138_57_dest_tiip)) , (__derived_to_base_conversion((&__4183_11_complete_object_ptr), (&__4260_16_new_ptr), __T890746616, __T890747264, ((an_access_flag_string *)0), 0)));




if (__4259_19_conversion_done) { __4190_11_result = __4260_16_new_ptr; }
}
}
}
return __4190_11_result;
}
#line 1026
void __cxa_bad_cast(void)




{ auto struct _ZSt8bad_cast *__T890749200;

(__T890749200 = ((struct _ZSt8bad_cast *)(__throw_setup_dtor(((const void *)(&_ZTISt8bad_cast)), 8ULL, 0U, ((void (*)(void *))_ZNSt8bad_castD1Ev))))) , ((_ZNSt8bad_castC1Ev(__T890749200)) , (__throw()));



}
#line 1046
void __cxa_bad_typeid(void)




{ auto struct _ZSt10bad_typeid *__T890752192;

(__T890752192 = ((struct _ZSt10bad_typeid *)(__throw_setup_dtor(((const void *)(&_ZTISt10bad_typeid)), 8ULL, 0U, ((void (*)(void *))_ZNSt10bad_typeidD1Ev))))) , ((_ZNSt10bad_typeidC1Ev(__T890752192)) , (__throw()));



}
