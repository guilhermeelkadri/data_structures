cmake_minimum_required(VERSION 3.0)
project(circular_queue LANGUAGES C CXX)

# Set C standart 
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include(CTest)
enable_testing()

# Add source files
set(SOURCES
    src/circular_queue.c
)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Include the "inc" directory for header files
target_include_directories(${PROJECT_NAME} PRIVATE inc)

# Check the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Running on Windows")
    # Add a test that do memory analysis with Intel Inspector
    add_test(NAME Intel_inspector COMMAND inspxe-cl -collect mi1 -- ./${PROJECT_NAME})
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Running on Linux")
    # Add a test that do memory analysis with Valgrind
    add_test(NAME Valgrind COMMAND valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./${PROJECT_NAME})
else()
    message("Unknown operating system: ${CMAKE_SYSTEM_NAME}")
endif()
