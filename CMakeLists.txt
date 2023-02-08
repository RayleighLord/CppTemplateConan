cmake_minimum_required(VERSION 3.16)

project(
    "Project"
    VERSION 0.1.0
    LANGUAGES C CXX)


# Global variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Options
option(ENABLE_WARNINGS "Enable compiler warnings." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Treat compiler warning as errors" OFF)

option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable a Code Coverage build." OFF)

option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)
option(ENABLE_CPPCHECK "Enable to add cppcheck." OFF)

option(ENABLE_SANITIZE_ADDR "Enable to sanitize address (Unix only)." ON)#Disable on release
option(ENABLE_SANITIZE_UNDEF "Enable to sanitize undefined (Unix only)." ON)

option(ENABLE_LTO "Enable to add Link Time Optimization." ON)


# Project / Library / Executable names
set(LIBRARY_NAME "lib")
set(UNIT_TEST_NAME "unit_tests")
set(EXECUTABLE_NAME "main") 


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(FetchContent)
include(Docs) 
include(Warnings) 
include(Tools)
include(LTO)


if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif()

if(ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

if(ENABLE_LTO)
    find_lto(CXX)
endif() 



# Add external libraries
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v2.13.9
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(Catch2)



# Testing
include(CTest)
enable_testing()



# Add subdirectories
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)