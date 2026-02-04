cmake_minimum_required(VERSION 3.12)

find_package(miniocpp CONFIG REQUIRED)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/impl CORE_IMPL_SOURCES)

add_library(Core STATIC ${CORE_IMPL_SOURCES})

target_include_directories(Core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/impl
)

target_link_libraries(Core
    PUBLIC
        miniocpp::miniocpp
)
