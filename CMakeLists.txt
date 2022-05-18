cmake_minimum_required(VERSION 3.14)
project(cpp_vigenere_decryptor)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_subdirectory(tests)
set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(cpp_vigenere_decryptor main.cpp)
target_link_libraries(cpp_vigenere_decryptor PUBLIC decrypt_lib)