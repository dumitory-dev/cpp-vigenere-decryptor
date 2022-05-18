#ifndef CPP_VIGENERE_DECRYPTOR_UTILS_H
#define CPP_VIGENERE_DECRYPTOR_UTILS_H

#include <string>

namespace utils {

    /**
    * @brief Read file from path. Returns a string containing the file contents. Max length of file is MAX_FILE_SIZE (1 MB by default). 
	* 
    * @param path_to_file Path to file
    * @return A string containing the file contents.
    **/
    std::string read_all_file(const std::string &file_name);

    /**
     * @brief Remove all non-alphabetic characters from a string.
     * 
     * @param text text to be cleaned
     * @return std::string 
     */
    std::string remove_non_alphabet_characters(const std::string &text);


    /**
     * @brief Convert a string to lowercase.
     * 
     * @param text text to convert
     * @return std::string 
     */
    std::string convert_to_lowercase(const std::string &text);

    /**
    * @brief Calculate the frequency of the english frequency from text.
	The function does the following:
	1. Counts the number of occurrences of each letter in the text.
	2. Calculates the absolute difference between the frequencies of each letter and the English frequency.
	3. Returns the sum of all differences.

    Limitations:
    - The function only works with English text with lowercase letters.
    * @param text String to calculate the english frequency.
    * @return double type, English frequency from text.  
    **/
    double get_english_frequency_index(const std::string &text);

    /**
     * @brief Check if a text is lowercase.
     *
     * @param text  text to check
     * @return true if text is lowercase, false otherwise
     */
    bool is_lowercase(const std::string &text) noexcept;

}// namespace utils

#endif
