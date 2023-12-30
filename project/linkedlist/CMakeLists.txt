cmake_minimum_required(VERSION 3.10)
project(LINKEDLIST)

# Include directories
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TEST_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/test")


# Find all source files in the src directory
file(GLOB_RECURSE PROJECT_FILES
        "${INCLUDE_DIR}/*.h"
        "${TEST_DIR}/*.h"
        "${SOURCE_DIR}/*.cpp"
        )

# Add executable for this project
add_executable(LINKEDLIST ${PROJECT_FILES})

target_include_directories(LINKEDLIST PRIVATE ${INCLUDE_DIR})
target_include_directories(LINKEDLIST PRIVATE ${SOURCE_DIR})
