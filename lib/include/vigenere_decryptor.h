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
    decrypt_result decrypt(std::string_view cipher_text);

#ifdef TESTS_ENABLED
    std::string encrypt(std::string_view text, std::string_view key);
    std::string decrypt_with_key(std::string_view text, std::string_view key);
    decrypt_result decrypt(std::string_view cipher_text);
#endif

}// namespace vigenere_decryptor

#endif// CPP_VIGENERE_DECRYPTOR_VIGENERE_DECRYPTOR_H
