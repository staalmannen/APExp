cmake_minimum_required(VERSION 3.5)

project("lru_cache_lib" CXX)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/lru_cache.cpp)

set_target_properties(${PROJECT_NAME}
            PROPERTIES
            CXX_STANDARD 14
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
            LINKER_LANGUAGE CXX
            )

if(MSVC)
    target_compile_options(
        ${PROJECT_NAME} PRIVATE /GR- /EHsc
    )
else()
    target_compile_options(
        ${PROJECT_NAME} PRIVATE -fno-rtti -fno-exceptions
    )
endif()

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
