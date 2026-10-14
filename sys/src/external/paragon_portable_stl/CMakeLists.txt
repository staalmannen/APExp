#
# Copyright (c) 2024 Paragon Software Group.
#
cmake_minimum_required(VERSION 3.5)

set(HUNTER_PACKAGES GTest)

include(FetchContent)
fetchcontent_declare(SetupHunter GIT_REPOSITORY https://github.com/cpp-pm/gate)
fetchcontent_makeavailable(SetupHunter)

project(portable_stl CXX)

find_package(GTest CONFIG REQUIRED)

add_executable( ${PROJECT_NAME}
    unit_test/algorithm.cpp
    unit_test/array.cpp
    unit_test/common.cpp
    unit_test/common/common_helper.cpp
    unit_test/compare.cpp
    unit_test/concepts.cpp
    unit_test/forward_list/forward_list_access.cpp
    unit_test/forward_list/forward_list_construction.cpp
    unit_test/forward_list/forward_list_modifiers.cpp
    unit_test/forward_list/forward_list_operations.cpp
    unit_test/forward_list/forward_list.cpp
    unit_test/iterator_basic_const.cpp
    unit_test/iterator_concepts.cpp
    unit_test/iterator_insert.cpp
    unit_test/iterator_move.cpp
    unit_test/iterator_reverse.cpp
    unit_test/iterator_traits.cpp
    unit_test/iterator.cpp
    unit_test/language_support.cpp
    unit_test/list/list_access.cpp
    unit_test/list/list_construction.cpp
    unit_test/list/list_modifiers.cpp
    unit_test/list/list_operations.cpp
    unit_test/list/list.cpp
    unit_test/map/map_access.cpp
    unit_test/map/map_construction.cpp
    unit_test/map/map_insert.cpp
    unit_test/map/map_lookup.cpp
    unit_test/map/map_modify.cpp
    unit_test/map/map.cpp
    unit_test/map/tree.cpp
    unit_test/memory_pointer_traits.cpp
    unit_test/memory_to_address.cpp
    unit_test/memory.cpp
    unit_test/metaprogramming_array_modifications.cpp
    unit_test/metaprogramming_composite_type.cpp
    unit_test/metaprogramming_constant_evaluation.cpp
    unit_test/metaprogramming_cv_modifications.cpp
    unit_test/metaprogramming_helper.cpp
    unit_test/metaprogramming_integer_sequence.cpp
    unit_test/metaprogramming_logical_operator.cpp
    unit_test/metaprogramming_member_relationships.cpp
    unit_test/metaprogramming_other_transformations.cpp
    unit_test/metaprogramming_pointer_modifications.cpp
    unit_test/metaprogramming_primary_type.cpp
    unit_test/metaprogramming_reference_modifications.cpp
    unit_test/metaprogramming_sign_modifications.cpp
    unit_test/metaprogramming_type_properties.cpp
    unit_test/metaprogramming_type_property_queries.cpp
    unit_test/metaprogramming_type_relations.cpp
    unit_test/multimap/multimap_access.cpp
    unit_test/multimap/multimap_construction.cpp
    unit_test/multimap/multimap_insert.cpp
    unit_test/multimap/multimap_lookup.cpp
    unit_test/multimap/multimap_modify.cpp
    unit_test/multimap/multimap.cpp
    unit_test/ranges_concepts.cpp
    unit_test/ranges.cpp
    unit_test/set/set_access.cpp
    unit_test/set/set_construction.cpp
    unit_test/set/set_insert.cpp
    unit_test/set/set_lookup.cpp
    unit_test/set/set_modify.cpp
    unit_test/string/basic_string_access.cpp
    unit_test/string/basic_string_append.cpp
    unit_test/string/basic_string_assign.cpp
    unit_test/string/basic_string_capacity.cpp
    unit_test/string/basic_string_compare.cpp
    unit_test/string/basic_string_concatenate.cpp
    unit_test/string/basic_string_insert.cpp
    unit_test/string/basic_string_replace.cpp
    unit_test/string/basic_string_search.cpp
    unit_test/string/basic_string_view_compare_op.cpp
    unit_test/string/basic_string_view_compare.cpp
    unit_test/string/basic_string_view_find_first.cpp
    unit_test/string/basic_string_view_find.cpp
    unit_test/string/basic_string_view.cpp
    unit_test/string/basic_string.cpp
    unit_test/string/char_traits_char.cpp
    unit_test/string/char_traits_char8_t.cpp
    unit_test/string/char_traits_char16_t.cpp
    unit_test/string/char_traits_char32_t.cpp
    unit_test/string/char_traits_wchar_t.cpp
    unit_test/string/convert.cpp
    unit_test/string/to_string.cpp
    unit_test/tuple_assignment.cpp
    unit_test/tuple_constructor_alloc.cpp
    unit_test/tuple_constructor.cpp
    unit_test/tuple_creation.cpp
    unit_test/tuple_element.cpp
    unit_test/tuple_test_helper.cpp
    unit_test/tuple.cpp
    unit_test/utility_expected.cpp
    unit_test/utility_general_functional.cpp
    unit_test/utility_general.cpp
    unit_test/variant.cpp
    unit_test/vector/vector_bool_constructor.cpp
    unit_test/vector/vector_bool_insert.cpp
    unit_test/vector/vector_bool_iterators.cpp
    unit_test/vector/vector_bool_modify.cpp
    unit_test/vector/vector_bool.cpp
    unit_test/vector/vector_constructor.cpp
    unit_test/vector/vector_insert.cpp
    unit_test/vector/vector_iterators.cpp
    unit_test/vector/vector_modify.cpp
    unit_test/vector/vector_test_helper.cpp
    unit_test/vector/vector.cpp
)

set_target_properties(${PROJECT_NAME}
            PROPERTIES
            CXX_STANDARD 14
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
            LINKER_LANGUAGE CXX
            )

target_include_directories(
        ${PROJECT_NAME} AFTER
        PRIVATE "include"
)

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE

    "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>" # add '/utf-8' option for MSVC to prevent: error C2015: too many characters in constant
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE "GTest::gmock_main"
)

add_test(${PROJECT_NAME} ${PROJECT_NAME} "")

add_subdirectory(sample)
