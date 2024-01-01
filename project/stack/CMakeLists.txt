cmake_minimum_required(VERSION 3.10)
project(STACK)

# Include directories
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/src")


# Find all source files in the src directory
file(GLOB_RECURSE PROJECT_FILES
        "${INCLUDE_DIR}/*.h"
        "${SOURCE_DIR}/*.cpp"
        )

# Add executable for this project
add_executable(STACK ${PROJECT_FILES})

target_include_directories(STACK PRIVATE ${INCLUDE_DIR})
target_include_directories(STACK PRIVATE ${SOURCE_DIR})
