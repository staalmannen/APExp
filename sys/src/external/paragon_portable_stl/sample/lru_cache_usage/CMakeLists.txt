cmake_minimum_required(VERSION 3.5)

project("lru_cache" C)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lru_cahce_usage.c)

target_link_libraries(${PROJECT_NAME} PRIVATE lru_cache_lib)