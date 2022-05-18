// Module for various utility functions
#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>

#include "constants.h"

namespace utils {

    std::string read_all_file(const std::string &path_to_file) {
        std::ifstream file{path_to_file};
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + path_to_file);
        }

        const auto get_file_size = [](std::ifstream &file) {
            file.seekg(0, std::ios::end);
            const auto size = file.tellg();
            file.seekg(0, std::ios::beg);
            return size;
        };

        if (get_file_size(file) > constants::MAX_FILE_SIZE) {
            throw std::runtime_error("File is too large: " + path_to_file);
        }
        // Read file into string
        return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{}};
    }


    double get_english_frequency_index(const std::string &text) {
        if (text.empty())
            return 0.0;

        std::array<std::uint32_t, constants::ENGLISH_ALPHABET_LEN> freq{};

        double total_symbols = 0;
        for (const char &c: text) {
            if (!std::isalpha(c))
                continue;
            freq[c - 'a']++;
            total_symbols++;
        }

        if (total_symbols == 0)
            return 0.0;

        auto sum = 0.0;
        for (decltype(freq.size()) i = 0; i < freq.size(); i++)
            sum += std::fabs(freq[i] / total_symbols - constants::ENGLISH_LETTER_FREQUENCY[i]);

        return sum;
    }


    std::string remove_non_alphabet_characters(const std::string &text) {
        std::string result;
        for (const char &c: text) {
            if (std::isalpha(c))
                result += c;
        }
        return result;
    }

    std::string convert_to_lowercase(const std::string &text) {
        std::string lower_case_str(text.size(), 0);
        std::transform(text.begin(),
                       text.end(),
                       lower_case_str.begin(),
                       ::tolower);
        return lower_case_str;
    }

    bool is_lowercase(const std::string &text) noexcept {
        for (const char &c: text) {
            if (!std::isalpha(c))
                continue;
            if (!std::islower(c))
                return false;
        }
        return true;
    }


}// namespace utils
