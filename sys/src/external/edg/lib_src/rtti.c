/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:06 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/rtti.c"
struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info;
# 42
struct a_base_class_traversal_block;
# 107
enum a_result_virtuality { rv_unknown, rv_nonvirtual, rv_directvirtual};
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception;
# 32 "include_c++/typeinfo.stdh" 3
struct _ZSt9type_info;
# 54
struct _ZSt8bad_cast;
# 63
struct _ZSt10bad_typeid;
# 52 "include_c++/cxxabi.h" 3
struct _ZN10__cxxabiv117__class_type_infoE;
# 58
struct _ZN10__cxxabiv120__si_class_type_infoE;
# 68
enum _ZN10__cxxabiv122__base_class_type_info20__offset_flags_masksE {
_ZN10__cxxabiv122__base_class_type_info14__virtual_maskE = 0x1,
_ZN10__cxxabiv122__base_class_type_info13__public_maskE = 0x2,
_ZN10__cxxabiv122__base_class_type_info14__offset_shiftE = 8};
# 64
struct _ZN10__cxxabiv122__base_class_type_infoE;
# 83
enum _ZN10__cxxabiv121__vmi_class_type_info13__flags_masksE {
_ZN10__cxxabiv121__vmi_class_type_info25__non_diamond_repeat_maskE = 0x1,
_ZN10__cxxabiv121__vmi_class_type_info21__diamond_shaped_maskE = 0x2};
# 76
struct _ZN10__cxxabiv121__vmi_class_type_infoE; struct __EDG_type_info { const long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;};
# 69 "lib_src/basics.h"
typedef int a_boolean;
# 93 "lib_src/rtti.h"
typedef const struct _ZSt9type_info *a_type_info_impl_ptr;
# 174
typedef struct _ZN10__cxxabiv122__base_class_type_infoE *a_base_class_spec_ptr;



typedef char *an_access_flag_string;
# 46 "lib_src/vtbl.h"
typedef long a_vtbl_entry;



typedef a_vtbl_entry *a_vtbl_entry_ptr;
# 25 "lib_src/rtti.c"
typedef struct a_base_class_traversal_block *a_base_class_traversal_block_ptr;




typedef void a_base_class_process_function(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
# 37
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
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception { const long *__vptr;};
# 35
typedef _Bool _ZSt6__bool;
# 32 "include_c++/typeinfo.stdh" 3
struct _ZSt9type_info { const long *__vptr;
# 50
const char *__type_name;};



struct _ZSt8bad_cast { struct _ZSt9exception __b_St9exception;};
# 63
struct _ZSt10bad_typeid { struct _ZSt9exception __b_St9exception;};
# 52 "include_c++/cxxabi.h" 3
struct _ZN10__cxxabiv117__class_type_infoE { struct _ZSt9type_info __b_St9type_info;};
# 58
struct _ZN10__cxxabiv120__si_class_type_infoE { struct _ZN10__cxxabiv117__class_type_infoE __b_N10__cxxabiv117__class_type_infoE;


const struct _ZN10__cxxabiv117__class_type_infoE *__base_type;};


struct _ZN10__cxxabiv122__base_class_type_infoE {
const struct _ZN10__cxxabiv117__class_type_infoE *__base_type;
long __offset_flags;};
# 76
struct _ZN10__cxxabiv121__vmi_class_type_infoE { struct _ZN10__cxxabiv117__class_type_infoE __b_N10__cxxabiv117__class_type_infoE;


unsigned __flags;
unsigned __base_count;
struct _ZN10__cxxabiv122__base_class_type_infoE __base_info[1];};
# 112 "lib_src/rtti.c"
static void _ZN27_INTERNAL_6_rtti_c_066a44b032clear_base_class_traversal_blockEP28a_base_class_traversal_block(a_base_class_traversal_block_ptr bctbp);
# 132
static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE(a_base_class_spec_ptr base_info);
# 152
static void *_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_base_class_spec_ptr bcsp);
# 168
static void _ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
# 262
static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(void *ptr, void **p_new_ptr, a_type_info_impl_ptr class_info, a_type_info_impl_ptr base_info, unsigned vmi_flags, a_boolean *p_is_ambiguous, a_boolean 
# 262
is_accessible, a_type_info_impl_ptr *p_virtual_class_above_result, enum a_result_virtuality *p_result_virtuality, a_boolean *result_is_accessible);
# 451
extern a_boolean __derived_to_base_conversion(void **p_ptr, void **p_new_ptr, a_type_info_impl_ptr class_info, a_type_info_impl_ptr base_info, an_access_flag_string *access_flags, a_boolean use_access_flags);
# 648
static a_base_class_spec_ptr _ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(void *obj_ptr, void *base_ptr, a_type_info_impl_ptr obj_info, a_type_info_impl_ptr base_info, a_boolean *found);
# 759
static void _ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
# 805
static void _ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(void *ptr, a_type_info_impl_ptr class_info, a_base_class_traversal_block_ptr bctbp, a_base_class_spec_ptr curr_base_info);
# 832
static void *_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_(void *complete_object_ptr, a_type_info_impl_ptr object_tiip, void *source_ptr, a_type_info_impl_ptr source_tiip, a_type_info_impl_ptr dest_tiip);
# 872
extern void *__dynamic_cast(void *class_ptr, a_type_info_impl_ptr source_tiip, a_type_info_impl_ptr dest_tiip, long hint);
# 1026
extern void __cxa_bad_cast(void); extern void *__throw_setup_dtor(const void *, unsigned long, unsigned, void (*)(void *)); extern __attribute__((__noreturn__)) void __throw(void);
# 1046
extern void __cxa_bad_typeid(void);
# 35 "include_c++/typeinfo.stdh" 3
extern _ZSt6__bool _ZNKSt9type_infoeqERKS_(const struct _ZSt9type_info *const, const struct _ZSt9type_info *);


extern const char *_ZNKSt9type_info4nameEv(const struct _ZSt9type_info *const);
# 56
extern __attribute__((__nothrow__)) void _ZNSt8bad_castC1Ev(struct _ZSt8bad_cast *const);


extern __attribute__((__nothrow__)) void _ZNSt8bad_castD1Ev(struct _ZSt8bad_cast *const);
# 65
extern __attribute__((__nothrow__)) void _ZNSt10bad_typeidC1Ev(struct _ZSt10bad_typeid *const);


extern __attribute__((__nothrow__)) void _ZNSt10bad_typeidD1Ev(struct _ZSt10bad_typeid *const); extern const struct __si_class_type_info _ZTIN10__cxxabiv120__si_class_type_infoE; extern const struct __si_class_type_info _ZTIN10__cxxabiv121__vmi_class_type_infoE; extern const struct 
# 68
__si_class_type_info _ZTISt8bad_cast; extern const struct __si_class_type_info _ZTISt10bad_typeid;
# 112 "lib_src/rtti.c"
static void _ZN27_INTERNAL_6_rtti_c_066a44b032clear_base_class_traversal_blockEP28a_base_class_traversal_block(
a_base_class_traversal_block_ptr __11360_38_bctbp)



{
(__11360_38_bctbp->process_function) = ((a_base_class_process_function_ptr)0);
(__11360_38_bctbp->process_post_function) = ((a_base_class_process_function_ptr)0);
(__11360_38_bctbp->not_direct_only) = 0;
(__11360_38_bctbp->public_only) = 0;
(__11360_38_bctbp->terminate) = 0;

(__11360_38_bctbp->downcast_dest_tiip) = ((a_type_info_impl_ptr)0);
(__11360_38_bctbp->downcast_source_tiip) = ((a_type_info_impl_ptr)0);
(__11360_38_bctbp->downcast_source_ptr) = ((void *)0);
(__11360_38_bctbp->downcast_dest_ptr) = ((void *)0);
(__11360_38_bctbp->downcast_result) = ((void *)0); 
}


static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE( a_base_class_spec_ptr __11379_51_base_info)




{
auto a_boolean __11385_13_result = 0;

if (__11379_51_base_info != ((a_base_class_spec_ptr)0)) {

__11385_13_result = ((a_boolean)(((__11379_51_base_info->__offset_flags) & 1L) != 0L));



}
return __11385_13_result;
}



static void *_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE( void *__11399_62_ptr, 
a_base_class_spec_ptr __11400_61_bcsp)




{
auto a_vtbl_entry_ptr __11406_20_vtbl; auto a_vtbl_entry_ptr __11406_26_vbase_offset;

__11406_20_vtbl = (*((a_vtbl_entry_ptr *)__11399_62_ptr));
__11406_26_vbase_offset = ((a_vtbl_entry_ptr)(((char *)__11406_20_vtbl) + ((__11400_61_bcsp->__offset_flags) >> 8)));
return (void *)(((char *)__11399_62_ptr) + (*__11406_26_vbase_offset));
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__11416_14_ptr, 
a_type_info_impl_ptr __11417_27_class_info, 
a_base_class_traversal_block_ptr __11418_37_bctbp, 
a_base_class_spec_ptr __11419_28_curr_base_info)
# 182
{ auto void *__T510531656; auto a_type_info_impl_ptr __T510532304; auto a_base_class_traversal_block_ptr __T510533040; auto a_base_class_spec_ptr __T510533776; auto void *__T510546776; auto a_type_info_impl_ptr __T510547424; auto a_base_class_traversal_block_ptr __T510548160; auto 
# 182
a_base_class_spec_ptr __T510548896;


auto a_base_class_spec_ptr __11432_25_bcsp;
auto void *__11433_26_new_ptr;


((((__T510531656 = __11416_14_ptr) , (__T510532304 = __11417_27_class_info)) , (__T510533040 = __11418_37_bctbp)) , (__T510533776 = __11419_28_curr_base_info)) , ((__11418_37_bctbp->process_function)(__T510531656, __T510532304, __T510533040, __T510533776));
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__11417_27_class_info) ? ((struct __EDG_type_info *)((__11417_27_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).
# 190
base))))) { auto void *__T510536800; auto const struct _ZSt9type_info *__T510537800; auto a_base_class_traversal_block_ptr __T510538536;
auto struct _ZN10__cxxabiv120__si_class_type_infoE *__11438_32_si_obj_info; __11438_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__11417_27_class_info);


(((__T510536800 = __11416_14_ptr) , (__T510537800 = (&((__11438_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T510538536 = __11418_37_bctbp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
# 194
__T510536800, __T510537800, __T510538536, ((a_base_class_spec_ptr)0)));

} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__11417_27_class_info) ? ((struct __EDG_type_info *)((__11417_27_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((
# 196
_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).base))))) { auto void *__T510543392; auto const struct _ZSt9type_info *__T510544392; auto a_base_class_traversal_block_ptr __T510545128; auto a_base_class_spec_ptr __T510545864;
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__11444_33_vmi_obj_info; __11444_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__11417_27_class_info);

for (__11432_25_bcsp = ((__11444_33_vmi_obj_info->__base_info)); __11432_25_bcsp < (((__11444_33_vmi_obj_info->__base_info)) + (__11444_33_vmi_obj_info->__base_count)); __11432_25_bcsp++)

{


if ((__11418_37_bctbp->public_only) && (((__11432_25_bcsp->__offset_flags) & 2L) == 0L)) {
goto __T510524512;
}
if (_ZN27_INTERNAL_6_rtti_c_066a44b010is_virtualEPN10__cxxabiv122__base_class_type_infoE(__11432_25_bcsp)) { auto void *__T510541560; auto a_base_class_spec_ptr __T510542480;
__11433_26_new_ptr = (((__T510541560 = __11416_14_ptr) , (__T510542480 = __11432_25_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T510541560, __T510542480)));
} else  {
__11433_26_new_ptr = ((void *)(((char *)__11416_14_ptr) + ((__11432_25_bcsp->__offset_flags) >> 8)));
}

((((__T510543392 = __11433_26_new_ptr) , (__T510544392 = (&((__11432_25_bcsp->__base_type)->__b_St9type_info)))) , (__T510545128 = __11418_37_bctbp)) , (__T510545864 = __11432_25_bcsp)) , (
# 213
_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(__T510543392, __T510544392, __T510545128, __T510545864));

if (__11418_37_bctbp->terminate) { goto __11469_1_end_of_routine; } __T510524512:;
}
} }

if ((__11418_37_bctbp->process_post_function) != ((a_base_class_process_function_ptr)0)) {
((((__T510546776 = __11416_14_ptr) , (__T510547424 = __11417_27_class_info)) , (__T510548160 = __11418_37_bctbp)) , (__T510548896 = __11419_28_curr_base_info)) , ((__11418_37_bctbp->process_post_function)(__T510546776, __T510547424, __T510548160, __T510548896));
}
__11469_1_end_of_routine:; ; 
# 257
}




static a_boolean _ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(
void *__11510_12_ptr, 
void **__11511_13_p_new_ptr, 
a_type_info_impl_ptr __11512_25_class_info, 
a_type_info_impl_ptr __11513_25_base_info, 
unsigned __11514_18_vmi_flags, 
a_boolean *__11515_16_p_is_ambiguous, 
a_boolean __11516_15_is_accessible, 
a_type_info_impl_ptr *__11517_29_p_virtual_class_above_result, 
enum a_result_virtuality *__11518_29_p_result_virtuality, 
a_boolean *__11519_16_result_is_accessible)
# 297
{
auto a_boolean __11545_13_result = 0;
# 309
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__11512_25_class_info) ? ((struct __EDG_type_info *)((__11512_25_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).
# 309
base))))) {

auto struct _ZN10__cxxabiv120__si_class_type_infoE *__11558_32_si_obj_info; __11558_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__11512_25_class_info);

if (((&((__11558_32_si_obj_info->__base_type)->__b_St9type_info)) == __11513_25_base_info) || ((_ZNKSt9type_info4nameEv((&((__11558_32_si_obj_info->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__11513_25_base_info)))) {
if (((((*__11511_13_p_new_ptr) != ((void *)0)) && ((*__11511_13_p_new_ptr) != __11510_12_ptr)) || (((int)(*__11518_29_p_result_virtuality)) == 2)) || (*__11515_16_p_is_ambiguous))

{

(*__11515_16_p_is_ambiguous) = 1;
(*__11511_13_p_new_ptr) = ((void *)0);
__11545_13_result = 0;
} else  {
(*__11518_29_p_result_virtuality) = rv_nonvirtual;
(*__11519_16_result_is_accessible) = __11516_15_is_accessible;
(*__11511_13_p_new_ptr) = __11510_12_ptr;
__11545_13_result = 1;
}
} else  { auto void *__T510626360; auto void **__T510627280; auto const struct _ZSt9type_info *__T510628368; auto a_type_info_impl_ptr __T510629104; auto unsigned __T510629840; auto a_boolean *__T510630576; auto a_boolean __T510631312; auto a_type_info_impl_ptr *__T510632048; auto enum 
# 327
a_result_virtuality *__T510632784; auto a_boolean *__T510633520; if ((((((((((((__T510626360 = __11510_12_ptr) , (__T510627280 = __11511_13_p_new_ptr)) , (__T510628368 = (&((__11558_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T510629104 = __11513_25_base_info)) , (__T510629840 = 
# 327
__11514_18_vmi_flags)) , (__T510630576 = __11515_16_p_is_ambiguous)) , (__T510631312 = __11516_15_is_accessible)) , (__T510632048 = __11517_29_p_virtual_class_above_result)) , (__T510632784 = __11518_29_p_result_virtuality)) , (__T510633520 = __11519_16_result_is_accessible)) , (
# 327
_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T510626360, __T510627280, __T510628368, __T510629104, __T510629840, __T510630576, __T510631312, __T510632048, __T510632784, __T510633520))) || (*__11515_16_p_is_ambiguous))
# 334
{
if (*__11515_16_p_is_ambiguous) {
__11545_13_result = 0;
} else  {
__11545_13_result = 1;
}
} }
} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__11512_25_class_info) ? ((struct __EDG_type_info *)((__11512_25_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((
# 341
_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).base))))) {

auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__11590_33_vmi_obj_info;

auto a_base_class_spec_ptr __11592_32_bcsp;
auto void *__11593_33_base_ptr;
# 343
__11590_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__11512_25_class_info);




for (__11592_32_bcsp = ((__11590_33_vmi_obj_info->__base_info)); __11592_32_bcsp < (((__11590_33_vmi_obj_info->__base_info)) + (__11590_33_vmi_obj_info->__base_count)); __11592_32_bcsp++)

{ auto void *__T510636544; auto a_base_class_spec_ptr __T510637192;
auto a_boolean __11598_17_base_is_accessible;
auto a_boolean __11599_17_is_virtual; __11599_17_is_virtual = ((a_boolean)(((__11592_32_bcsp->__offset_flags) & 1L) != 0L));
if (__11510_12_ptr == ((void *)0)) {

__11593_33_base_ptr = ((void *)0);
} else  { if (__11599_17_is_virtual) {
__11593_33_base_ptr = (((__T510636544 = __11510_12_ptr) , (__T510637192 = __11592_32_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T510636544, __T510637192)));
} else  {
__11593_33_base_ptr = ((void *)(((char *)__11510_12_ptr) + ((__11592_32_bcsp->__offset_flags) >> 8)));
} }
__11598_17_base_is_accessible = ((a_boolean)((__11516_15_is_accessible) && ((__11592_32_bcsp->__offset_flags) & 2L)));

if (((&((__11592_32_bcsp->__base_type)->__b_St9type_info)) == __11513_25_base_info) || ((_ZNKSt9type_info4nameEv((&((__11592_32_bcsp->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__11513_25_base_info)))) {

if (((((*__11511_13_p_new_ptr) != ((void *)0)) && (__11593_33_base_ptr != (*__11511_13_p_new_ptr))) || (((__11592_32_bcsp->__offset_flags) & 1L) && (((int)(*__11518_29_p_result_virtuality)) == 1))) || (*__11515_16_p_is_ambiguous))


{

(*__11515_16_p_is_ambiguous) = 1;
(*__11511_13_p_new_ptr) = ((void *)0);
__11545_13_result = 0;
goto __T510594256;
} else  {

(*__11518_29_p_result_virtuality) = (((__11592_32_bcsp->__offset_flags) & 1L) ? rv_directvirtual : rv_nonvirtual);

(*__11519_16_result_is_accessible) = __11598_17_base_is_accessible;
(*__11511_13_p_new_ptr) = __11593_33_base_ptr;
__11545_13_result = 1;


if (*__11519_16_result_is_accessible) {
if ((__11599_17_is_virtual) ? (!((__11514_18_vmi_flags & 2U) != 0U)) : (!((__11514_18_vmi_flags & 1U) != 0U)))
{
goto __T510594256;
}
}
}
} else  { auto void *__T510638808; auto void **__T510639456; auto const struct _ZSt9type_info *__T510640544; auto a_type_info_impl_ptr __T510641280; auto unsigned __T510642016; auto a_boolean *__T510642752; auto a_boolean __T510643488; auto a_boolean *__T510644224;
auto a_type_info_impl_ptr __11638_23_virtual_class_above_result_here = ((a_type_info_impl_ptr)0);
auto enum a_result_virtuality __11639_22_result_virtuality_here = rv_unknown;
if ((((((((((__T510638808 = __11593_33_base_ptr) , (__T510639456 = __11511_13_p_new_ptr)) , (__T510640544 = (&((__11592_32_bcsp->__base_type)->__b_St9type_info)))) , (__T510641280 = __11513_25_base_info)) , (__T510642016 = __11514_18_vmi_flags)) , (__T510642752 = __11515_16_p_is_ambiguous)) , (
# 393
__T510643488 = __11598_17_base_is_accessible)) , (__T510644224 = __11519_16_result_is_accessible)) , (_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T510638808, __T510639456, __T510640544, __T510641280, __T510642016, 
# 393
__T510642752, __T510643488, (&__11638_23_virtual_class_above_result_here), (&__11639_22_result_virtuality_here), __T510644224))) || (*__11515_16_p_is_ambiguous))
# 401
{
if (*__11515_16_p_is_ambiguous) {
__11545_13_result = 0;
goto __T510594256;
} else  {
if ((__11638_23_virtual_class_above_result_here == ((a_type_info_impl_ptr)0)) && (((__11592_32_bcsp->__offset_flags) & 1L) != 0L))
{
__11638_23_virtual_class_above_result_here = (&((__11592_32_bcsp->__base_type)->__b_St9type_info));
}
if (((((int)(*__11518_29_p_result_virtuality)) == 0) || ((((int)__11639_22_result_virtuality_here) == 2) && (((int)(*__11518_29_p_result_virtuality)) == 2))) || (((*__11517_29_p_virtual_class_above_result) != ((a_type_info_impl_ptr)0)) && ((*__11517_29_p_virtual_class_above_result) == 
# 410
__11638_23_virtual_class_above_result_here)))
# 419
{
(*__11518_29_p_result_virtuality) = __11639_22_result_virtuality_here;
(*__11517_29_p_virtual_class_above_result) = __11638_23_virtual_class_above_result_here;
__11545_13_result = 1;


if (*__11519_16_result_is_accessible) {
if ((__11599_17_is_virtual) ? (!((__11514_18_vmi_flags & 2U) != 0U)) : (!((__11514_18_vmi_flags & 1U) != 0U)))
{
goto __T510594256;
}
}
} else  {
(*__11515_16_p_is_ambiguous) = 1;
__11545_13_result = 0;
goto __T510594256;
}
}
}
}
} __T510594256:;
} }
return __11545_13_result;
}
# 451
a_boolean __derived_to_base_conversion( void **__11698_53_p_ptr, 
void **__11699_36_p_new_ptr, 
a_type_info_impl_ptr __11700_34_class_info, 
a_type_info_impl_ptr __11701_34_base_info, 
an_access_flag_string *__11702_35_access_flags, 
a_boolean __11703_34_use_access_flags)
# 479
{
auto a_boolean __11727_14_result = 0;
auto void *__11728_26_ptr;
auto a_boolean __11729_14_is_ambiguous = 0;

auto a_boolean __11731_25_result_is_accessible = 1;
# 491
__11728_26_ptr = ((__11698_53_p_ptr == ((void **)0)) ? ((void *)0) : (*__11698_53_p_ptr));
(*__11699_36_p_new_ptr) = ((void *)0);
# 617
{ auto void *__T510707008; auto void **__T510707656; auto a_type_info_impl_ptr __T510708392; auto a_type_info_impl_ptr __T510709128; auto unsigned __T510709864;
auto int __11865_9_vmi_flags;
# 630
auto a_type_info_impl_ptr __11877_26_virtual_class_above_result;
auto enum a_result_virtuality __11878_25_result_virtuality;
# 622
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__11700_34_class_info) ? ((struct __EDG_type_info *)((__11700_34_class_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).
# 622
base))))) {
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__11870_35_vmi_obj_info; __11870_35_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__11700_34_class_info);

__11865_9_vmi_flags = ((int)(__11870_35_vmi_obj_info->__flags));
} else  {
__11865_9_vmi_flags = 0x3;

}
__11877_26_virtual_class_above_result = ((a_type_info_impl_ptr)0);
__11878_25_result_virtuality = rv_unknown;
if (((((((__T510707008 = __11728_26_ptr) , (__T510707656 = __11699_36_p_new_ptr)) , (__T510708392 = __11700_34_class_info)) , (__T510709128 = __11701_34_base_info)) , (__T510709864 = ((unsigned)__11865_9_vmi_flags))) , (
# 632
_ZN27_INTERNAL_6_rtti_c_066a44b028derived_to_base_conversion_rEPvPS0_PKSt9type_infoS4_jPiiPS4_P19a_result_virtualityS5_(__T510707008, __T510707656, __T510708392, __T510709128, __T510709864, (&__11729_14_is_ambiguous), 1, (&__11877_26_virtual_class_above_result), (&__11878_25_result_virtuality), (&
# 632
__11731_25_result_is_accessible)))) && (__11731_25_result_is_accessible))
# 638
{
__11727_14_result = 1;
}
}

return __11727_14_result;
}



static a_base_class_spec_ptr _ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(
void *__11896_14_obj_ptr, 
void *__11897_14_base_ptr, 
a_type_info_impl_ptr __11898_27_obj_info, 
a_type_info_impl_ptr __11899_27_base_info, 
a_boolean *__11900_66_found)
# 661
{
auto a_base_class_spec_ptr __11909_25_bcsp;
auto void *__11910_26_ptr;
auto void *__11911_26_new_ptr;
auto a_base_class_spec_ptr __11912_25_result = ((a_base_class_spec_ptr)0);




__11910_26_ptr = __11896_14_obj_ptr;
# 681
if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__11898_27_obj_info) ? ((struct __EDG_type_info *)((__11898_27_obj_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base))
# 681
))) {
auto struct _ZN10__cxxabiv120__si_class_type_infoE *__11929_32_si_obj_info; __11929_32_si_obj_info = ((struct _ZN10__cxxabiv120__si_class_type_infoE *)__11898_27_obj_info);

if ((__11910_26_ptr == __11897_14_base_ptr) && (((&((__11929_32_si_obj_info->__base_type)->__b_St9type_info)) == __11899_27_base_info) || ((_ZNKSt9type_info4nameEv((&((__11929_32_si_obj_info->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__11899_27_base_info)))))
{

(*__11900_66_found) = 1;
} else  { auto void *__T510742840; auto void *__T510743760; auto const struct _ZSt9type_info *__T510744848; auto a_type_info_impl_ptr __T510745584; auto a_boolean *__T510746320;


__11912_25_result = ((((((__T510742840 = __11910_26_ptr) , (__T510743760 = __11897_14_base_ptr)) , (__T510744848 = (&((__11929_32_si_obj_info->__base_type)->__b_St9type_info)))) , (__T510745584 = __11899_27_base_info)) , (__T510746320 = __11900_66_found)) , (
# 691
_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T510742840, __T510743760, __T510744848, __T510745584, __T510746320)));


}
} else  { if (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__11898_27_obj_info) ? ((struct __EDG_type_info *)((__11898_27_obj_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.
# 695
base).base))))) { auto void *__T510817584; auto void *__T510818232; auto const struct _ZSt9type_info *__T510819320; auto a_type_info_impl_ptr __T510820056; auto a_boolean *__T510820792;
auto struct _ZN10__cxxabiv121__vmi_class_type_infoE *__11943_33_vmi_obj_info; __11943_33_vmi_obj_info = ((struct _ZN10__cxxabiv121__vmi_class_type_infoE *)__11898_27_obj_info);

for (__11909_25_bcsp = ((__11943_33_vmi_obj_info->__base_info)); __11909_25_bcsp < (((__11943_33_vmi_obj_info->__base_info)) + (__11943_33_vmi_obj_info->__base_count)); __11909_25_bcsp++)

{
if ((__11909_25_bcsp->__offset_flags) & 1L) { auto void *__T510749344; auto a_base_class_spec_ptr __T510815968;
__11911_26_new_ptr = (((__T510749344 = __11910_26_ptr) , (__T510815968 = __11909_25_bcsp)) , (_ZN27_INTERNAL_6_rtti_c_066a44b024get_virtual_base_pointerEPvPN10__cxxabiv122__base_class_type_infoE(__T510749344, __T510815968)));
} else  {
__11911_26_new_ptr = ((void *)(((char *)__11910_26_ptr) + ((__11909_25_bcsp->__offset_flags) >> 8)));
}
if ((__11911_26_new_ptr == __11897_14_base_ptr) && (((&((__11909_25_bcsp->__base_type)->__b_St9type_info)) == __11899_27_base_info) || ((_ZNKSt9type_info4nameEv((&((__11909_25_bcsp->__base_type)->__b_St9type_info)))) == (_ZNKSt9type_info4nameEv(__11899_27_base_info)))))
{


__11912_25_result = __11909_25_bcsp;
if ((__11909_25_bcsp->__offset_flags) & 2L) { (*__11900_66_found) = 1; }
goto __T510735768;
}
if (((__11909_25_bcsp->__offset_flags) & 2L) != 0L) {

__11912_25_result = ((((((__T510817584 = __11911_26_new_ptr) , (__T510818232 = __11897_14_base_ptr)) , (__T510819320 = (&((__11909_25_bcsp->__base_type)->__b_St9type_info)))) , (__T510820056 = __11899_27_base_info)) , (__T510820792 = __11900_66_found)) , (
# 716
_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T510817584, __T510818232, __T510819320, __T510820056, __T510820792)));



if (*__11900_66_found) { goto __T510735768; }
}
} __T510735768:;
} }
# 754
return __11912_25_result;
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__12007_13_ptr, 
a_type_info_impl_ptr __12008_26_class_info, 
a_base_class_traversal_block_ptr __12009_36_bctbp, 
a_base_class_spec_ptr __12010_27_curr_base_info)
# 774
{
if (((__12009_36_bctbp->downcast_dest_tiip) == __12008_26_class_info) || ((_ZNKSt9type_info4nameEv((__12009_36_bctbp->downcast_dest_tiip))) == (_ZNKSt9type_info4nameEv(__12008_26_class_info)))) {



(__12009_36_bctbp->downcast_dest_ptr) = __12007_13_ptr;
(__12009_36_bctbp->public_only) = 1;
# 787
} else  { if ((((__12009_36_bctbp->downcast_dest_ptr) != ((void *)0)) && (__12007_13_ptr == (__12009_36_bctbp->downcast_source_ptr))) && ((__12008_26_class_info == (__12009_36_bctbp->downcast_source_tiip)) || ((_ZNKSt9type_info4nameEv(__12008_26_class_info)) == (_ZNKSt9type_info4nameEv((
# 787
__12009_36_bctbp->downcast_source_tiip))))))

{

if ((__12009_36_bctbp->downcast_result) != ((void *)0)) {


(__12009_36_bctbp->downcast_result) = ((void *)0);
(__12009_36_bctbp->terminate) = 1;
} else  {

(__12009_36_bctbp->downcast_result) = (__12009_36_bctbp->downcast_dest_ptr);
}
} } 
}



static void _ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(
void *__12053_13_ptr, 
a_type_info_impl_ptr __12054_26_class_info, 
a_base_class_traversal_block_ptr __12055_36_bctbp, 
a_base_class_spec_ptr __12056_27_curr_base_info)
# 816
{
if (((__12055_36_bctbp->downcast_dest_tiip) == __12054_26_class_info) || ((_ZNKSt9type_info4nameEv((__12055_36_bctbp->downcast_dest_tiip))) == (_ZNKSt9type_info4nameEv(__12054_26_class_info)))) {


(__12055_36_bctbp->downcast_dest_ptr) = ((void *)0);
(__12055_36_bctbp->public_only) = 0;
# 828
} 
}


static void *_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_( void *__12079_35_complete_object_ptr, 
a_type_info_impl_ptr __12080_27_object_tiip, 
void *__12081_14_source_ptr, 
a_type_info_impl_ptr __12082_27_source_tiip, 
a_type_info_impl_ptr __12083_27_dest_tiip)
# 854
{ auto void *__T510848016; auto a_type_info_impl_ptr __T510848664;
auto a_base_class_traversal_block __12102_32_block;

_ZN27_INTERNAL_6_rtti_c_066a44b032clear_base_class_traversal_blockEP28a_base_class_traversal_block((&__12102_32_block));
(__12102_32_block.process_function) = (&_ZN27_INTERNAL_6_rtti_c_066a44b012tbc_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE);
(__12102_32_block.process_post_function) = (&_ZN27_INTERNAL_6_rtti_c_066a44b017tbc_post_downcastEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE);
(__12102_32_block.downcast_dest_tiip) = __12083_27_dest_tiip;
(__12102_32_block.downcast_source_tiip) = __12082_27_source_tiip;
(__12102_32_block.downcast_source_ptr) = __12081_14_source_ptr;
((__T510848016 = __12079_35_complete_object_ptr) , (__T510848664 = __12080_27_object_tiip)) , (_ZN27_INTERNAL_6_rtti_c_066a44b021traverse_base_classesEPvPKSt9type_infoP28a_base_class_traversal_blockPN10__cxxabiv122__base_class_type_infoE(__T510848016, __T510848664, (&__12102_32_block), ((
# 863
a_base_class_spec_ptr)0)));

return __12102_32_block.downcast_result;
}
# 872
void *__dynamic_cast( void *__12119_39_class_ptr, 
# 881
a_type_info_impl_ptr __12128_57_source_tiip, 
a_type_info_impl_ptr __12129_57_dest_tiip, 
long __12130_57_hint)
# 926
{ auto void *__T510872656; auto a_type_info_impl_ptr __T510873304; auto void *__T510874040; auto a_type_info_impl_ptr __T510874776; auto a_type_info_impl_ptr __T510875512;
auto void *__12174_11_complete_object_ptr;



auto void *__12178_26_source_ptr;

auto a_type_info_impl_ptr __12180_24_object_tiip;
auto void *__12181_11_result = ((void *)0);
# 931
__12178_26_source_ptr = __12119_39_class_ptr;
# 942
__12174_11_complete_object_ptr = ((void *)(((char *)__12119_39_class_ptr) + ((*((a_vtbl_entry_ptr *)__12119_39_class_ptr))[(-2)])));
# 957
__12180_24_object_tiip = ((a_type_info_impl_ptr)((*((a_vtbl_entry_ptr *)__12119_39_class_ptr))[(-1)]));

if (__12129_57_dest_tiip == ((a_type_info_impl_ptr)0)) {



__12181_11_result = __12174_11_complete_object_ptr;

} else  {


__12181_11_result = ((((((__T510872656 = __12174_11_complete_object_ptr) , (__T510873304 = __12180_24_object_tiip)) , (__T510874040 = __12178_26_source_ptr)) , (__T510874776 = __12128_57_source_tiip)) , (__T510875512 = __12129_57_dest_tiip)) , (
# 968
_ZN27_INTERNAL_6_rtti_c_066a44b012try_downcastEPvPKSt9type_infoS0_S3_S3_(__T510872656, __T510873304, __T510874040, __T510874776, __T510875512)));



}


if (__12181_11_result == ((void *)0)) { auto void *__T510876424; auto void *__T510877072; auto a_type_info_impl_ptr __T510877808; auto a_type_info_impl_ptr __T510878544;
auto a_boolean __12223_15_access_okay = 1;
# 986
if (__12180_24_object_tiip == __12128_57_source_tiip) {

__12223_15_access_okay = 1;
} else  {
__12223_15_access_okay = 0;
((((__T510876424 = __12174_11_complete_object_ptr) , (__T510877072 = __12178_26_source_ptr)) , (__T510877808 = __12180_24_object_tiip)) , (__T510878544 = __12128_57_source_tiip)) , (_ZN27_INTERNAL_6_rtti_c_066a44b023find_base_class_at_addrEPvS0_PKSt9type_infoS3_Pi(__T510876424, __T510877072, 
# 991
__T510877808, __T510878544, (&__12223_15_access_okay)));

}

if (__12223_15_access_okay) {
if ((__12180_24_object_tiip == __12129_57_dest_tiip) || ((_ZNKSt9type_info4nameEv(__12180_24_object_tiip)) == (_ZNKSt9type_info4nameEv(__12129_57_dest_tiip)))) {



__12181_11_result = __12174_11_complete_object_ptr;
} else  { auto a_type_info_impl_ptr __T510879456; auto a_type_info_impl_ptr __T510880104;

auto a_boolean __12250_19_conversion_done;
auto void *__12251_16_new_ptr = ((void *)0);
__12250_19_conversion_done = (((__T510879456 = __12180_24_object_tiip) , (__T510880104 = __12129_57_dest_tiip)) , (__derived_to_base_conversion((&__12174_11_complete_object_ptr), (&__12251_16_new_ptr), __T510879456, __T510880104, ((an_access_flag_string *)0), 0)));




if (__12250_19_conversion_done) { __12181_11_result = __12251_16_new_ptr; }
}
}
}
return __12181_11_result;
}
# 1026
void __cxa_bad_cast(void)




{ auto struct _ZSt8bad_cast *__T510882232;

(__T510882232 = ((struct _ZSt8bad_cast *)(__throw_setup_dtor(((const void *)(&_ZTISt8bad_cast)), 8UL, 0U, ((void (*)(void *))_ZNSt8bad_castD1Ev))))) , ((_ZNSt8bad_castC1Ev(__T510882232)) , (__throw()));



}
# 1046
void __cxa_bad_typeid(void)




{ auto struct _ZSt10bad_typeid *__T510885224;

(__T510885224 = ((struct _ZSt10bad_typeid *)(__throw_setup_dtor(((const void *)(&_ZTISt10bad_typeid)), 8UL, 0U, ((void (*)(void *))_ZNSt10bad_typeidD1Ev))))) , ((_ZNSt10bad_typeidC1Ev(__T510885224)) , (__throw()));



}
