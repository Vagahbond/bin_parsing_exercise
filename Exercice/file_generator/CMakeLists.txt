cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
cmake_policy(VERSION 3.2)


project(bin_rickroll_generator
    VERSION "1.0.0"
    DESCRIPTION "Generate binary rick roll"
)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

set(INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)