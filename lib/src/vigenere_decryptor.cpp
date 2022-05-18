#include <algorithm>
#include <cstdint>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "constants.h"
#include "utils.h"
#include "vigenere_decryptor.h"

using namespace std;

namespace vigenere_decryptor {


    /**
     * @brief The function encrypts text using the vigenera algorithm 
     * Limitations:
     * - The key and text must be a string of lowercase letters
     * @param text Text to encrypt.
     * @param key Key to encrypt the text.
     * @return std::string encrypt_result 
     */
    std::string encrypt(const std::string &text, const std::string &key) {
        if (text.empty() || key.empty())
            throw std::invalid_argument("Encrypt: Text and key must not be empty!");

        std::vector<uint8_t> key_with_alphabet_index(key.size());

        // character conversion to the alphabet index (0-25)
        std::transform(key.cbegin(), key.cend(), key_with_alphabet_index.begin(), [](const auto c) { return c - 'a'; });

        std::string result{};
        for (const char letter: text) {
            if (isalpha(letter)) {
                result += static_cast<char>((letter - 'a' + key_with_alphabet_index[0]) % 26 + 'a');
                std::rotate(key_with_alphabet_index.begin(), key_with_alphabet_index.begin() + 1,
                            key_with_alphabet_index.end());
            } else
                result += letter;
        }

        return result;
    }

    /** 
     * @brief The function:
     * 1. Gets the inverse key from the normal key
     * 2. It calls the encrypt method with the inverse key 
     * (so we get the decrypted text, decryption is encryption with the inverse key)   
     *  @param text Text to decrypt.
     *  @param key Key to decrypt the text. 
     * 
     *  @return std::string decrypt_result 
     */
    std::string decrypt_with_key(const std::string &text, const std::string &key) {
        if (text.empty() || key.empty())
            throw std::invalid_argument("Decrypt: Text and key must not be empty!");

        const auto get_inverse_key = [](const std::string &normal_key) {
            std::string inverse_key{};
            for (const char symbol: normal_key)
                inverse_key.push_back('a' + (26 - (symbol - 'a')) % 26);
            return inverse_key;
        };

        return encrypt(text, get_inverse_key(key));
    }

    decrypt_result decrypt(const std::string &cipher_text) {
        /*
        Algorithm:
            1. Converts cipher text to lowercase and removes any non-alphabetic characters
            3. For each key length (MIN_PASSWORD_LEN to MAX_PASSWORD_LEN) calculates the frequency of each letter in the cipher text
            with the given key length
            4. Compares the frequency of each letter in the cipher text with the frequency of each letter in the
            english alphabet
            5. Selects the key length that minimizes the difference between the frequency of each letter in the cipher
            text and the frequency of each letter in the english alphabet
            6. Creates a key of the selected length and fills it with the most frequent letter from the cipher text
            with respect to the key length
            7. Decrypts the cipher text using the best key and returns the result
        */

        if (cipher_text.empty())
            throw std::invalid_argument("Decrypt: Cipher text must not be empty!");

        if (!utils::is_lowercase(cipher_text))
            throw std::invalid_argument("Decrypt: Cipher text must be lowercase!");

        auto text_with_only_alpha_chars = utils::remove_non_alphabet_characters(cipher_text);

        if (text_with_only_alpha_chars.empty())
            throw std::invalid_argument("Decrypt: Unsupported text!");

        std::vector<string> best_keys{};

        for (auto key_length = constants::MIN_PASSWORD_LEN; key_length <= constants::MAX_PASSWORD_LEN; ++key_length) {
            auto key = std::string(key_length, '\0');

            for (auto key_index = 0u; key_index < key_length; ++key_index) {
                auto letters = std::string{};
                for (auto letter_index = key_index; letter_index < text_with_only_alpha_chars.size();
                     letter_index += key_length) {
                    letters += text_with_only_alpha_chars[letter_index];
                }

                auto shifts = std::map<char, double>{};
                for (auto key_char: std::string_view{constants::ENGLISH_ALPHABET}) {
                    shifts[key_char] = utils::get_english_frequency_index(decrypt_with_key(letters, std::string(1, key_char)));
                }

                key[key_index] = std::min_element(shifts.cbegin(), shifts.cend(), [](const auto &lhs, const auto &rhs) {
                                     return lhs.second < rhs.second;
                                 })->first;
            }
            best_keys.emplace_back(std::move(key));
        }


        std::sort(best_keys.begin(), best_keys.end(), [&](const auto &key1, const auto &key2) {
            return utils::get_english_frequency_index(decrypt_with_key(text_with_only_alpha_chars, key1)) <
                   utils::get_english_frequency_index(decrypt_with_key(text_with_only_alpha_chars, key2));
        });

        return {best_keys[0], decrypt_with_key(cipher_text, best_keys[0])};
    }

}// namespace vigenere_decryptor