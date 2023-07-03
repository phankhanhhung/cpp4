cmake_minimum_required(VERSION 3.14)
project(cpp3 VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Find all source files for Module1
file(GLOB SORT_SOURCES "sort/*.cpp")
file(GLOB SORT_HEADERS "{SOURCE_DIR}/sort/*.h")


# Find all source files for MainApp
file(GLOB MAINAPP_SOURCES "main/*.cpp")
file(GLOB BASE_HEADERS "base/*.h")



# Create shared library for Module1
add_library(sort SHARED ${SORT_SOURCES})

# Set include directories for SORT
target_include_directories(sort PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/sort" "${CMAKE_CURRENT_SOURCE_DIR}/base")

# Set the output directory for the library
set_target_properties(sort PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Create the main executable
add_executable(MainApp ${MAINAPP_SOURCES})

# Set include directories for MainApp
target_include_directories(MainApp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/sort" "${CMAKE_CURRENT_SOURCE_DIR}/base")

# Link MainApp with SORT
target_link_libraries(MainApp sort)

# Set the output directory for the executable
set_target_properties(MainApp PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")



enable_testing()

add_executable(
  hello_test
  test/hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)