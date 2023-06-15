cmake_minimum_required(VERSION 3.0.0)
project(doubly_linked_list_c++ LANGUAGES CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} 
    src/dll.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE inc)

# Link the test program with the Google Test libraries
target_link_libraries(${PROJECT_NAME}  gtest gtest_main pthread)
    
# Add a test that runs the test executable with Google Test framework
add_test(NAME Google_test COMMAND ./${PROJECT_NAME})
add_test(NAME Valgrind COMMAND valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./${PROJECT_NAME})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
