// Module for various utility functions
#include "constants.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iterator>

namespace utils {

    std::string read_all_file(std::string_view path_to_file) {
        std::ifstream file{path_to_file.data()};
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + std::string(path_to_file));
        }

        const auto file_size = std::filesystem::file_size(path_to_file);

        if (file_size > constants::max_file_size) {
            throw std::runtime_error("File is too large: " + std::string(path_to_file));
        }

        return {std::istreambuf_iterator{file}, std::istreambuf_iterator<char>{}};
    }


    double get_english_frequency_index(std::string_view text) {
        if (text.empty())
            return 0.0;

        std::array<std::uint32_t, constants::english_alphabet_len> freq{};

        double total_symbols = 0;
        for (const char &c: text) {
            if (!std::isalpha(c))
                continue;
            freq[c - 'a']++;
            total_symbols++;
        }

        if (static_cast<int>(total_symbols) == 0)
            return 0.0;

        auto sum = 0.0;
        for (decltype(freq.size()) i = 0; i < freq.size(); i++)
            sum += std::fabs(freq[i] / total_symbols - constants::english_letter_frequency[i]);

        return sum;
    }


    std::string remove_non_alphabet_characters(std::string_view text) {
        std::string result;
        for (const char c: text) {
            if (std::isalpha(c))
                result += c;
        }
        return result;
    }

    std::string convert_to_lowercase(std::string_view text) {
        std::string lower_case_str(text.size(), 0);
        std::transform(text.begin(),
                       text.end(),
                       lower_case_str.begin(),
                       ::tolower);
        return lower_case_str;
    }

    bool is_lowercase(std::string_view text) {
        return std::all_of(text.begin(), text.end(), [](const char &c) {
            return !std::isalpha(c) || std::islower(c);
        });
    }

}// namespace utils
