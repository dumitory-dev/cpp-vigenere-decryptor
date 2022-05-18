cmake_minimum_required(VERSION 3.14)
project(decrypt_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(decrypt_lib
        src/utils.cpp
        src/vigenere_decryptor.cpp
        include/vigenere_decryptor.h
        include/utils.h
        include/constants.h)

target_include_directories(decrypt_lib PUBLIC include)