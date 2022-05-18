cmake_minimum_required(VERSION 3.14)
project(tests)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(TESTS_ENABLED)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


include_directories(include)

add_executable(
        tests
        src/tests_utils.cpp
        src/tests_decryptor.cpp include/test_data.h)

target_link_libraries(
        tests
        gtest_main
        decrypt_lib
)

include(GoogleTest)
gtest_discover_tests(tests)