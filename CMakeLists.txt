cmake_minimum_required(VERSION 3.1)
project(zhclib)
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)

file(GLOB zhclib_SRC
        "src/*.h"
        "src/*.c"
        )

add_library(zhclib
        ${zhclib_SRC}
        )
target_link_libraries(zhclib readline)

add_executable(zhclib_test
        test/first.c
        ${zhclib_SRC}
        )

target_include_directories(zhclib_test PRIVATE src)
target_link_libraries(zhclib_test readline)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-modules)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_TEST_NAME} coverage)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"