#ifndef CPP_VIGENERE_DECRYPTOR_CONSTANTS_H
#define CPP_VIGENERE_DECRYPTOR_CONSTANTS_H

namespace constants {

    /**
     * @brief Letter frequency is the number of times letters
     * of the alphabet appear on average in written language
     *
     */
    constexpr inline double ENGLISH_LETTER_FREQUENCY[] = {
            0.0749,
            0.0129,
            0.0354,
            0.0362,
            0.1400,
            0.0218,
            0.0174,
            0.0422,
            0.0665,
            0.0027,
            0.0047,
            0.0357,
            0.0339,
            0.0674,
            0.0737,
            0.0243,
            0.0026,
            0.0614,
            0.0695,
            0.0985,
            0.0300,
            0.0116,
            0.0169,
            0.0028,
            0.0164,
            0.0004,
    };

    constexpr inline auto ENGLISH_ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    constexpr inline auto ENGLISH_ALPHABET_LEN = 26u;

    constexpr inline auto MAX_PASSWORD_LEN = 12u;
    constexpr inline auto MIN_PASSWORD_LEN = 2u;

    /**
    * @brief Maximum file size in bytes.
    *
    */
    constexpr inline auto MAX_FILE_SIZE = 1024u * 1024u;// 1MB

}// namespace constants

#endif// CPP_VIGENERE_DECRYPTOR_CONSTANTS_H
