/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:43 2026 */
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
a_base_class_traversal_block_ptr __3341_38_bctbp)



{
(__3341_38_bctbp->process_function) = ((a_base_class_process_function_ptr)0);
(__3341_38_bctbp->process_post_function) = ((a_base_class_process_function_ptr)0);
(__3341_38_bctbp->not_direct_only) = 0;
(__3341_38_bctbp->public_only) = 0;
(__3341_38_bctbp->terminate) = 0;

(__3341_38_bctbp->downcast_dest_tiip) = ((a_type_info_impl_ptr)0);
(__3341_38_bctbp->downcast_source_tiip) = ((a_type_info_impl_ptr)0);
(__3341_38_bctbp->downcast_source_ptr) = ((void *)0);
(__3341_38_bctbp->downcast_dest_ptr) = ((void *)0);
(__3341_38_bctbp->downcast_result) = ((void *)0); 
}


static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE( a_base_class_spec_ptr __3360_51_base_info)




{
auto a_boolean __3366_13_result = 0;

if (__3360_51_base_info != ((a_base_class_spec_ptr)0)) {

__3366_13_result = ((a_boolean)(((__3360_51_base_info->__offset_flags) & 1L) != 0L));



}
return __3366_13_result;
}



static void *_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE( void *__3380_62_ptr, 
a_base_class_spec_ptr __3381_61_bcsp)




{
auto a_vtbl_entry_ptr __3387_20_vtbl; auto a_vtbl_entry_ptr __3387_26_vbase_offset;

__3387_20_vtbl = (*((a_vtbl_entry_ptr *)__3380_62_ptr));
__3387_26_vbase_offset = ((a_vtbl_entry_ptr)(((char *)__3387_20_vtbl) + ((__3381_61_bcsp->__offset_flags) >> 8)));
return (void *)(((char *)__3380_62_ptr) + (*__3387_26_vbase_offset));
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__3397_14_ptr, 
a_type_info_impl_ptr __3398_27_class_info, 
a_base_class_traversal_block_ptr __3399_37_bctbp, 
a_base_class_spec_ptr __3400_28_curr_base_info)
#line 182
{ auto void *__T1051438152; auto a_type_info_impl_ptr __T1051438800; auto a_base_class_traversal_block_ptr __T1051439536; auto a_base_class_spec_ptr __T1051440272; auto void *__T1051453272; auto a_type_info_impl_ptr __T1051453920; auto a_base_class_traversal_block_ptr __T1051454656; auto 
#line 182
a_base_class_spec_ptr __T1051455392;


auto a_base_class_spec_ptr __3413_25_bcsp;
auto void *__3414_26_new_ptr;


((((__T1051438152 = __3397_14_ptr) , (__T1051438800 = __3398_27_class_info)) , (__T1051439536 = __3399_37_bctbp)) , (__T1051440272 = __3400_28_curr_base_info)) , ((__3399_37_bctbp->process_function)(__T1051438152, __T1051438800, __T1051439536, __T1051440272));
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3398_27_class_info) ? ((struct __EDG_type_info *)((__3398_27_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base
#line 190
))))) { auto void *__T1051443296; auto const struct _ZSt9type_info *__T1051444296; auto a_base_class_traversal_block_ptr __T1051445032;
auto struct _ZN10__cxxabiv120__si_class_type_infoE *__3419_32_si_obj_info; __3419_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__3398_27_class_info);


(((__T1051443296 = __3397_14_ptr) , (__T1051444296 = (&((__3419_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T1051445032 = __3399_37_bctbp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
#line 194
__T1051443296, __T1051444296, __T1051445032, ((a_base_class_spec_ptr)0)));

} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3398_27_class_info) ? ((struct __EDG_type_info *)((__3398_27_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE
#line 196
.base).base))))) { auto void *__T1051449888; auto const struct _ZSt9type_info *__T1051450888; auto a_base_class_traversal_block_ptr __T1051451624; auto a_base_class_spec_ptr __T1051452360;
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3425_33_vmi_obj_info; __3425_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3398_27_class_info);

for (__3413_25_bcsp = ((__3425_33_vmi_obj_info->__base_info)); __3413_25_bcsp < (((__3425_33_vmi_obj_info->__base_info)) + (__3425_33_vmi_obj_info->__base_count)); __3413_25_bcsp++)

{


if ((__3399_37_bctbp->public_only) && (((__3413_25_bcsp->__offset_flags) & 2L) == 0L)) {
goto __T1051431008;
}
if (_ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE(__3413_25_bcsp)) { auto void *__T1051448056; auto a_base_class_spec_ptr __T1051448976;
__3414_26_new_ptr = (((__T1051448056 = __3397_14_ptr) , (__T1051448976 = __3413_25_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T1051448056, __T1051448976)));
} else  {
__3414_26_new_ptr = ((void *)(((char *)__3397_14_ptr) + ((__3413_25_bcsp->__offset_flags) >> 8)));
}

((((__T1051449888 = __3414_26_new_ptr) , (__T1051450888 = (&((__3413_25_bcsp->__base_type)->__b_St9type_info)))) , (__T1051451624 = __3399_37_bctbp)) , (__T1051452360 = __3413_25_bcsp)) , (
#line 213
_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(__T1051449888, __T1051450888, __T1051451624, __T1051452360));

if (__3399_37_bctbp->terminate) { goto __3450_1_end_of_routine; } __T1051431008:;
}
} }

if ((__3399_37_bctbp->process_post_function) != ((a_base_class_process_function_ptr)0)) {
((((__T1051453272 = __3397_14_ptr) , (__T1051453920 = __3398_27_class_info)) , (__T1051454656 = __3399_37_bctbp)) , (__T1051455392 = __3400_28_curr_base_info)) , ((__3399_37_bctbp->process_post_function)(__T1051453272, __T1051453920, __T1051454656, __T1051455392));
}
__3450_1_end_of_routine:; ; 
#line 257
}




static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(
void *__3491_12_ptr, 
void **__3492_13_p_new_ptr, 
a_type_info_impl_ptr __3493_25_class_info, 
a_type_info_impl_ptr __3494_25_base_info, 
unsigned __3495_18_vmi_flags, 
a_boolean *__3496_16_p_is_ambiguous, 
a_boolean __3497_15_is_accessible, 
a_type_info_impl_ptr *__3498_29_p_virtual_class_above_result, 
enum a_result_virtuality *__3499_29_p_result_virtuality, 
a_boolean *__3500_16_result_is_accessible)
#line 297
{
auto a_boolean __3526_13_result = 0;
#line 309
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3493_25_class_info) ? ((struct __EDG_type_info *)((__3493_25_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base
#line 309
))))) {

auto struct _ZN10__cxxabiv120__si_class_type_infoE *__3539_32_si_obj_info; __3539_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__3493_25_class_info);

if (((&((__3539_32_si_obj_info->__base_type)->__b_St9type_info)) == __3494_25_base_info) || ((_ZNKSt9type_info4nameEv((&((__3539_32_si_obj_info->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3494_25_base_info)))) {
if (((((*__3492_13_p_new_ptr) != ((void *)0)) && ((*__3492_13_p_new_ptr) != __3491_12_ptr)) || (((int)(*__3499_29_p_result_virtuality)) == 2)) || (*__3496_16_p_is_ambiguous))

{

(*__3496_16_p_is_ambiguous) = 1;
(*__3492_13_p_new_ptr) = ((void *)0);
__3526_13_result = 0;
} else  {
(*__3499_29_p_result_virtuality) = rv_nonvirtual;
(*__3500_16_result_is_accessible) = __3497_15_is_accessible;
(*__3492_13_p_new_ptr) = __3491_12_ptr;
__3526_13_result = 1;
}
} else  { auto void *__T1051598408; auto void **__T1051599328; auto const struct _ZSt9type_info *__T1051600416; auto a_type_info_impl_ptr __T1051601152; auto unsigned __T1051601888; auto a_boolean *__T1051602624; auto a_boolean __T1051603360; auto a_type_info_impl_ptr *__T1051604096; auto enum 
#line 327
a_result_virtuality *__T1051604832; auto a_boolean *__T1051605568; if ((((((((((((__T1051598408 = __3491_12_ptr) , (__T1051599328 = __3492_13_p_new_ptr)) , (__T1051600416 = (&((__3539_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T1051601152 = __3494_25_base_info)) , (__T1051601888 = 
#line 327
__3495_18_vmi_flags)) , (__T1051602624 = __3496_16_p_is_ambiguous)) , (__T1051603360 = __3497_15_is_accessible)) , (__T1051604096 = __3498_29_p_virtual_class_above_result)) , (__T1051604832 = __3499_29_p_result_virtuality)) , (__T1051605568 = __3500_16_result_is_accessible)) , (
#line 327
_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T1051598408, __T1051599328, __T1051600416, __T1051601152, __T1051601888, __T1051602624, __T1051603360, __T1051604096, __T1051604832, __T1051605568))) || (*
#line 327
__3496_16_p_is_ambiguous))
#line 334
{
if (*__3496_16_p_is_ambiguous) {
__3526_13_result = 0;
} else  {
__3526_13_result = 1;
}
} }
} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3493_25_class_info) ? ((struct __EDG_type_info *)((__3493_25_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE
#line 341
.base).base))))) {

auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3571_33_vmi_obj_info;

auto a_base_class_spec_ptr __3573_32_bcsp;
auto void *__3574_33_base_ptr;
#line 343
__3571_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3493_25_class_info);




for (__3573_32_bcsp = ((__3571_33_vmi_obj_info->__base_info)); __3573_32_bcsp < (((__3571_33_vmi_obj_info->__base_info)) + (__3571_33_vmi_obj_info->__base_count)); __3573_32_bcsp++)

{ auto void *__T1051608592; auto a_base_class_spec_ptr __T1051609240;
auto a_boolean __3579_17_base_is_accessible;
auto a_boolean __3580_17_is_virtual; __3580_17_is_virtual = ((a_boolean)(((__3573_32_bcsp->__offset_flags) & 1L) != 0L));
if (__3491_12_ptr == ((void *)0)) {

__3574_33_base_ptr = ((void *)0);
} else  { if (__3580_17_is_virtual) {
__3574_33_base_ptr = (((__T1051608592 = __3491_12_ptr) , (__T1051609240 = __3573_32_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T1051608592, __T1051609240)));
} else  {
__3574_33_base_ptr = ((void *)(((char *)__3491_12_ptr) + ((__3573_32_bcsp->__offset_flags) >> 8)));
} }
__3579_17_base_is_accessible = ((a_boolean)((__3497_15_is_accessible) && ((__3573_32_bcsp->__offset_flags) & 2L)));

if (((&((__3573_32_bcsp->__base_type)->__b_St9type_info)) == __3494_25_base_info) || ((_ZNKSt9type_info4nameEv((&((__3573_32_bcsp->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3494_25_base_info)))) {

if (((((*__3492_13_p_new_ptr) != ((void *)0)) && (__3574_33_base_ptr != (*__3492_13_p_new_ptr))) || (((__3573_32_bcsp->__offset_flags) & 1L) && (((int)(*__3499_29_p_result_virtuality)) == 1))) || (*__3496_16_p_is_ambiguous))


{

(*__3496_16_p_is_ambiguous) = 1;
(*__3492_13_p_new_ptr) = ((void *)0);
__3526_13_result = 0;
goto __T1051566304;
} else  {

(*__3499_29_p_result_virtuality) = (((__3573_32_bcsp->__offset_flags) & 1L) ? rv_directvirtual : rv_nonvirtual);

(*__3500_16_result_is_accessible) = __3579_17_base_is_accessible;
(*__3492_13_p_new_ptr) = __3574_33_base_ptr;
__3526_13_result = 1;


if (*__3500_16_result_is_accessible) {
if ((__3580_17_is_virtual) ? (!((__3495_18_vmi_flags & 2U) != 0U)) : (!((__3495_18_vmi_flags & 1U) != 0U)))
{
goto __T1051566304;
}
}
}
} else  { auto void *__T1051610856; auto void **__T1051611504; auto const struct _ZSt9type_info *__T1051612592; auto a_type_info_impl_ptr __T1051613328; auto unsigned __T1051614064; auto a_boolean *__T1051614800; auto a_boolean __T1051615536; auto a_boolean *__T1051616272;
auto a_type_info_impl_ptr __3619_23_virtual_class_above_result_here = ((a_type_info_impl_ptr)0);
auto enum a_result_virtuality __3620_22_result_virtuality_here = rv_unknown;
if ((((((((((__T1051610856 = __3574_33_base_ptr) , (__T1051611504 = __3492_13_p_new_ptr)) , (__T1051612592 = (&((__3573_32_bcsp->__base_type)->__b_St9type_info)))) , (__T1051613328 = __3494_25_base_info)) , (__T1051614064 = __3495_18_vmi_flags)) , (__T1051614800 = __3496_16_p_is_ambiguous)) , (
#line 393
__T1051615536 = __3579_17_base_is_accessible)) , (__T1051616272 = __3500_16_result_is_accessible)) , (_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T1051610856, __T1051611504, __T1051612592, __T1051613328, __T1051614064, 
#line 393
__T1051614800, __T1051615536, (&__3619_23_virtual_class_above_result_here), (&__3620_22_result_virtuality_here), __T1051616272))) || (*__3496_16_p_is_ambiguous))
#line 401
{
if (*__3496_16_p_is_ambiguous) {
__3526_13_result = 0;
goto __T1051566304;
} else  {
if ((__3619_23_virtual_class_above_result_here == ((a_type_info_impl_ptr)0)) && (((__3573_32_bcsp->__offset_flags) & 1L) != 0L))
{
__3619_23_virtual_class_above_result_here = (&((__3573_32_bcsp->__base_type)->__b_St9type_info));
}
if (((((int)(*__3499_29_p_result_virtuality)) == 0) || ((((int)__3620_22_result_virtuality_here) == 2) && (((int)(*__3499_29_p_result_virtuality)) == 2))) || (((*__3498_29_p_virtual_class_above_result) != ((a_type_info_impl_ptr)0)) && ((*__3498_29_p_virtual_class_above_result) == 
#line 410
__3619_23_virtual_class_above_result_here)))
#line 419
{
(*__3499_29_p_result_virtuality) = __3620_22_result_virtuality_here;
(*__3498_29_p_virtual_class_above_result) = __3619_23_virtual_class_above_result_here;
__3526_13_result = 1;


if (*__3500_16_result_is_accessible) {
if ((__3580_17_is_virtual) ? (!((__3495_18_vmi_flags & 2U) != 0U)) : (!((__3495_18_vmi_flags & 1U) != 0U)))
{
goto __T1051566304;
}
}
} else  {
(*__3496_16_p_is_ambiguous) = 1;
__3526_13_result = 0;
goto __T1051566304;
}
}
}
}
} __T1051566304:;
} }
return __3526_13_result;
}
#line 451
a_boolean __derived_to_base_conversion( void **__3679_53_p_ptr, 
void **__3680_36_p_new_ptr, 
a_type_info_impl_ptr __3681_34_class_info, 
a_type_info_impl_ptr __3682_34_base_info, 
an_access_flag_string *__3683_35_access_flags, 
a_boolean __3684_34_use_access_flags)
#line 479
{
auto a_boolean __3708_14_result = 0;
auto void *__3709_26_ptr;
auto a_boolean __3710_14_is_ambiguous = 0;

auto a_boolean __3712_25_result_is_accessible = 1;
#line 491
__3709_26_ptr = ((__3679_53_p_ptr == ((void **)0)) ? ((void *)0) : (*__3679_53_p_ptr));
(*__3680_36_p_new_ptr) = ((void *)0);
#line 617
{ auto void *__T1051639992; auto void **__T1051640640; auto a_type_info_impl_ptr __T1051641376; auto a_type_info_impl_ptr __T1051642112; auto unsigned __T1051642848;
auto int __3846_9_vmi_flags;
#line 630
auto a_type_info_impl_ptr __3858_26_virtual_class_above_result;
auto enum a_result_virtuality __3859_25_result_virtuality;
#line 622
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3681_34_class_info) ? ((struct __EDG_type_info *)((__3681_34_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).
#line 622
base))))) {
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3851_35_vmi_obj_info; __3851_35_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3681_34_class_info);

__3846_9_vmi_flags = ((int)(__3851_35_vmi_obj_info->__flags));
} else  {
__3846_9_vmi_flags = 0x3;

}
__3858_26_virtual_class_above_result = ((a_type_info_impl_ptr)0);
__3859_25_result_virtuality = rv_unknown;
if (((((((__T1051639992 = __3709_26_ptr) , (__T1051640640 = __3680_36_p_new_ptr)) , (__T1051641376 = __3681_34_class_info)) , (__T1051642112 = __3682_34_base_info)) , (__T1051642848 = ((unsigned)__3846_9_vmi_flags))) , (
#line 632
_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T1051639992, __T1051640640, __T1051641376, __T1051642112, __T1051642848, (&__3710_14_is_ambiguous), 1, (&__3858_26_virtual_class_above_result), (&__3859_25_result_virtuality), (&
#line 632
__3712_25_result_is_accessible)))) && (__3712_25_result_is_accessible))
#line 638
{
__3708_14_result = 1;
}
}

return __3708_14_result;
}



static a_base_class_spec_ptr _ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(
void *__3877_14_obj_ptr, 
void *__3878_14_base_ptr, 
a_type_info_impl_ptr __3879_27_obj_info, 
a_type_info_impl_ptr __3880_27_base_info, 
a_boolean *__3881_66_found)
#line 661
{
auto a_base_class_spec_ptr __3890_25_bcsp;
auto void *__3891_26_ptr;
auto void *__3892_26_new_ptr;
auto a_base_class_spec_ptr __3893_25_result = ((a_base_class_spec_ptr)0);




__3891_26_ptr = __3877_14_obj_ptr;
#line 681
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3879_27_obj_info) ? ((struct __EDG_type_info *)((__3879_27_obj_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base))))
#line 681
) {
auto struct _ZN10__cxxabiv120__si_class_type_infoE *__3910_32_si_obj_info; __3910_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__3879_27_obj_info);

if ((__3891_26_ptr == __3878_14_base_ptr) && (((&((__3910_32_si_obj_info->__base_type)->__b_St9type_info)) == __3880_27_base_info) || ((_ZNKSt9type_info4nameEv((&((__3910_32_si_obj_info->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3880_27_base_info)))))
{

(*__3881_66_found) = 1;
} else  { auto void *__T1051675944; auto void *__T1051676864; auto const struct _ZSt9type_info *__T1051677952; auto a_type_info_impl_ptr __T1051678688; auto a_boolean *__T1051679424;


__3893_25_result = ((((((__T1051675944 = __3891_26_ptr) , (__T1051676864 = __3878_14_base_ptr)) , (__T1051677952 = (&((__3910_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T1051678688 = __3880_27_base_info)) , (__T1051679424 = __3881_66_found)) , (
#line 691
_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T1051675944, __T1051676864, __T1051677952, __T1051678688, __T1051679424)));


}
} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__3879_27_obj_info) ? ((struct __EDG_type_info *)((__3879_27_obj_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.
#line 695
base).base))))) { auto void *__T1051684984; auto void *__T1051685632; auto const struct _ZSt9type_info *__T1051686720; auto a_type_info_impl_ptr __T1051687456; auto a_boolean *__T1051688192;
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__3924_33_vmi_obj_info; __3924_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__3879_27_obj_info);

for (__3890_25_bcsp = ((__3924_33_vmi_obj_info->__base_info)); __3890_25_bcsp < (((__3924_33_vmi_obj_info->__base_info)) + (__3924_33_vmi_obj_info->__base_count)); __3890_25_bcsp++)

{
if ((__3890_25_bcsp->__offset_flags) & 1L) { auto void *__T1051682448; auto a_base_class_spec_ptr __T1051683368;
__3892_26_new_ptr = (((__T1051682448 = __3891_26_ptr) , (__T1051683368 = __3890_25_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T1051682448, __T1051683368)));
} else  {
__3892_26_new_ptr = ((void *)(((char *)__3891_26_ptr) + ((__3890_25_bcsp->__offset_flags) >> 8)));
}
if ((__3892_26_new_ptr == __3878_14_base_ptr) && (((&((__3890_25_bcsp->__base_type)->__b_St9type_info)) == __3880_27_base_info) || ((_ZNKSt9type_info4nameEv((&((__3890_25_bcsp->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__3880_27_base_info)))))
{


__3893_25_result = __3890_25_bcsp;
if ((__3890_25_bcsp->__offset_flags) & 2L) { (*__3881_66_found) = 1; }
goto __T1051668872;
}
if (((__3890_25_bcsp->__offset_flags) & 2L) != 0L) {

__3893_25_result = ((((((__T1051684984 = __3892_26_new_ptr) , (__T1051685632 = __3878_14_base_ptr)) , (__T1051686720 = (&((__3890_25_bcsp->__base_type)->__b_St9type_info)))) , (__T1051687456 = __3880_27_base_info)) , (__T1051688192 = __3881_66_found)) , (
#line 716
_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T1051684984, __T1051685632, __T1051686720, __T1051687456, __T1051688192)));



if (*__3881_66_found) { goto __T1051668872; }
}
} __T1051668872:;
} }
#line 754
return __3893_25_result;
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__3988_13_ptr, 
a_type_info_impl_ptr __3989_26_class_info, 
a_base_class_traversal_block_ptr __3990_36_bctbp, 
a_base_class_spec_ptr __3991_27_curr_base_info)
#line 774
{
if (((__3990_36_bctbp->downcast_dest_tiip) == __3989_26_class_info) || ((_ZNKSt9type_info4nameEv((__3990_36_bctbp->downcast_dest_tiip))) == (_ZNKSt9type_info4nameEv(__3989_26_class_info)))) {



(__3990_36_bctbp->downcast_dest_ptr) = __3988_13_ptr;
(__3990_36_bctbp->public_only) = 1;
#line 787
} else  { if ((((__3990_36_bctbp->downcast_dest_ptr) != ((void *)0)) && (__3988_13_ptr == (__3990_36_bctbp->downcast_source_ptr))) && ((__3989_26_class_info == (__3990_36_bctbp->downcast_source_tiip)) || ((_ZNKSt9type_info4nameEv(__3989_26_class_info)) == (_ZNKSt9type_info4nameEv((
#line 787
__3990_36_bctbp->downcast_source_tiip))))))

{

if ((__3990_36_bctbp->downcast_result) != ((void *)0)) {


(__3990_36_bctbp->downcast_result) = ((void *)0);
(__3990_36_bctbp->terminate) = 1;
} else  {

(__3990_36_bctbp->downcast_result) = (__3990_36_bctbp->downcast_dest_ptr);
}
} } 
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__4034_13_ptr, 
a_type_info_impl_ptr __4035_26_class_info, 
a_base_class_traversal_block_ptr __4036_36_bctbp, 
a_base_class_spec_ptr __4037_27_curr_base_info)
#line 816
{
if (((__4036_36_bctbp->downcast_dest_tiip) == __4035_26_class_info) || ((_ZNKSt9type_info4nameEv((__4036_36_bctbp->downcast_dest_tiip))) == (_ZNKSt9type_info4nameEv(__4035_26_class_info)))) {


(__4036_36_bctbp->downcast_dest_ptr) = ((void *)0);
(__4036_36_bctbp->public_only) = 0;
#line 828
} 
}


static void *_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_( void *__4060_35_complete_object_ptr, 
a_type_info_impl_ptr __4061_27_object_tiip, 
void *__4062_14_source_ptr, 
a_type_info_impl_ptr __4063_27_source_tiip, 
a_type_info_impl_ptr __4064_27_dest_tiip)
#line 854
{ auto void *__T1051715416; auto a_type_info_impl_ptr __T1051716064;
auto a_base_class_traversal_block __4083_32_block;

_ZN27_INTERNAL_6_rtti_c_066a44b032clear_base_class_traversal_blockEP28a_base_class_traversal_block((&__4083_32_block));
(__4083_32_block.process_function) = (&_ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE);
(__4083_32_block.process_post_function) = (&_ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE);
(__4083_32_block.downcast_dest_tiip) = __4064_27_dest_tiip;
(__4083_32_block.downcast_source_tiip) = __4063_27_source_tiip;
(__4083_32_block.downcast_source_ptr) = __4062_14_source_ptr;
((__T1051715416 = __4060_35_complete_object_ptr) , (__T1051716064 = __4061_27_object_tiip)) , (_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(__T1051715416, __T1051716064, (&__4083_32_block), ((
#line 863
a_base_class_spec_ptr)0)));

return __4083_32_block.downcast_result;
}
#line 872
void *__dynamic_cast( void *__4100_39_class_ptr, 
#line 881
a_type_info_impl_ptr __4109_57_source_tiip, 
a_type_info_impl_ptr __4110_57_dest_tiip, 
long long __4111_57_hint)
#line 926
{ auto void *__T1051740200; auto a_type_info_impl_ptr __T1051740848; auto void *__T1051741584; auto a_type_info_impl_ptr __T1051742320; auto a_type_info_impl_ptr __T1051743056;
auto void *__4155_11_complete_object_ptr;



auto void *__4159_26_source_ptr;

auto a_type_info_impl_ptr __4161_24_object_tiip;
auto void *__4162_11_result = ((void *)0);
#line 931
__4159_26_source_ptr = __4100_39_class_ptr;
#line 942
__4155_11_complete_object_ptr = ((void *)(((char *)__4100_39_class_ptr) + ((*((a_vtbl_entry_ptr *)__4100_39_class_ptr))[(-2)])));
#line 957
__4161_24_object_tiip = ((a_type_info_impl_ptr)((*((a_vtbl_entry_ptr *)__4100_39_class_ptr))[(-1)]));

if (__4110_57_dest_tiip == ((a_type_info_impl_ptr)0)) {



__4162_11_result = __4155_11_complete_object_ptr;

} else  {


__4162_11_result = ((((((__T1051740200 = __4155_11_complete_object_ptr) , (__T1051740848 = __4161_24_object_tiip)) , (__T1051741584 = __4159_26_source_ptr)) , (__T1051742320 = __4109_57_source_tiip)) , (__T1051743056 = __4110_57_dest_tiip)) , (
#line 968
_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_(__T1051740200, __T1051740848, __T1051741584, __T1051742320, __T1051743056)));



}


if (__4162_11_result == ((void *)0)) { auto void *__T1051743968; auto void *__T1051744616; auto a_type_info_impl_ptr __T1051745352; auto a_type_info_impl_ptr __T1051746088;
auto a_boolean __4204_15_access_okay = 1;
#line 986
if (__4161_24_object_tiip == __4109_57_source_tiip) {

__4204_15_access_okay = 1;
} else  {
__4204_15_access_okay = 0;
((((__T1051743968 = __4155_11_complete_object_ptr) , (__T1051744616 = __4159_26_source_ptr)) , (__T1051745352 = __4161_24_object_tiip)) , (__T1051746088 = __4109_57_source_tiip)) , (_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T1051743968, __T1051744616, 
#line 991
__T1051745352, __T1051746088, (&__4204_15_access_okay)));

}

if (__4204_15_access_okay) {
if ((__4161_24_object_tiip == __4110_57_dest_tiip) || ((_ZNKSt9type_info4nameEv(__4161_24_object_tiip)) == (_ZNKSt9type_info4nameEv(__4110_57_dest_tiip)))) {



__4162_11_result = __4155_11_complete_object_ptr;
} else  { auto a_type_info_impl_ptr __T1051747000; auto a_type_info_impl_ptr __T1051747648;

auto a_boolean __4231_19_conversion_done;
auto void *__4232_16_new_ptr = ((void *)0);
__4231_19_conversion_done = (((__T1051747000 = __4161_24_object_tiip) , (__T1051747648 = __4110_57_dest_tiip)) , (__derived_to_base_conversion((&__4155_11_complete_object_ptr), (&__4232_16_new_ptr), __T1051747000, __T1051747648, ((an_access_flag_string *)0), 0)));




if (__4231_19_conversion_done) { __4162_11_result = __4232_16_new_ptr; }
}
}
}
return __4162_11_result;
}
#line 1026
void __cxa_bad_cast(void)




{ auto struct _ZSt8bad_cast *__T1051749584;

(__T1051749584 = ((struct _ZSt8bad_cast *)(__throw_setup_dtor(((const void *)(&_ZTISt8bad_cast)), 8ULL, 0U, ((void (*)(void *))_ZNSt8bad_castD1Ev))))) , ((_ZNSt8bad_castC1Ev(__T1051749584)) , (__throw()));



}
#line 1046
void __cxa_bad_typeid(void)




{ auto struct _ZSt10bad_typeid *__T1051752576;

(__T1051752576 = ((struct _ZSt10bad_typeid *)(__throw_setup_dtor(((const void *)(&_ZTISt10bad_typeid)), 8ULL, 0U, ((void (*)(void *))_ZNSt10bad_typeidD1Ev))))) , ((_ZNSt10bad_typeidC1Ev(__T1051752576)) , (__throw()));



}
