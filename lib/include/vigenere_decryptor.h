#ifndef CPP_VIGENERE_DECRYPTOR_VIGENERE_DECRYPTOR_H
#define CPP_VIGENERE_DECRYPTOR_VIGENERE_DECRYPTOR_H

#include <string>
#include <utility>

namespace vigenere_decryptor {

    /**
     * @brief Key-text pair
     *
     */
    using decrypt_result = std::pair<std::string, std::string>;

    /**
     * @brief Decrypts a text without key.
     * Limits:
     *  - Cipher text must not be empty
     *  - Cipher text must contain only lowercase letters(!)
     *  - Cipher text must contain alphabetical characters
     * @param text Text to decrypt. (Must be )
     * @param key Key to decrypt the text.
     * @return decrypt_result
     */
    decrypt_result decrypt(const std::string &cipher_text);

#ifdef TESTS_ENABLED
    std::string encrypt(const std::string &text, const std::string &key);
    std::string decrypt_with_key(const std::string &text, const std::string &key);
    decrypt_result decrypt(const std::string &cipher_text);
#endif

}// namespace vigenere_decryptor

#endif// CPP_VIGENERE_DECRYPTOR_VIGENERE_DECRYPTOR_H
