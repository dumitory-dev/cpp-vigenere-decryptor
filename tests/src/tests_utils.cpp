#include "utils.h"
#include <gtest/gtest.h>

TEST(UtilsModuleTests, PassInvalidPathToFile_ThrowException) {
    EXPECT_THROW(utils::read_all_file(""), std::runtime_error);
}


TEST(UtilsModuleTests, PassText_ReturnLowerCaseText) {
    const std::string text = "HELLO World!";
    const std::string expected = "hello world!";
    const auto result = utils::convert_to_lowercase(text);
    EXPECT_EQ(expected, result);
}

TEST(UtilsModuleTests, PassWithNonAlphabetText_ReturnOnlyAlphabetText) {
    std::string text = "HELLO World!@#$%^&*()";
    std::string expected = "HELLOWorld";
    auto result = utils::remove_non_alphabet_characters(text);
    EXPECT_EQ(expected, result);

    text = "!@#$%^&*()";
    result = utils::remove_non_alphabet_characters(text);
    EXPECT_EQ(std::string(), result);
}

TEST(UtilsModuleTests, PassText_ReturnEnglishFrequencyIndex) {
    // Text with non-English letters
    std::string text = "@#$%^&*()";
    const double expected = 0.0;
    auto result = utils::get_english_frequency_index(text);
    EXPECT_DOUBLE_EQ(expected, result);

    // All English letters in the text
    text = "helloworld";
    result = utils::get_english_frequency_index(text);
    EXPECT_TRUE(result > 1.0);

    // Empty text
    EXPECT_DOUBLE_EQ(utils::get_english_frequency_index(std::string()), 0.0);

    // Encrypted text
    text = "vyg hwzeb diqnp wqo llogu fxvt 13 ccqa uqxu.";
    result = utils::get_english_frequency_index(text);
    EXPECT_TRUE(result < 1.0);
}

TEST(UtilsModuleTests, PassNotLowercaseText_ReturnLowercaseText) {
    // Not lowercase text
    const std::string text = "HELLO WORLD!";

    // Lowercase text
    const std::string expected = "hello world!";

    // Result
    auto result = utils::convert_to_lowercase(text);

    EXPECT_EQ(expected, result);
}

TEST(UtilsModuleTests, PassNotLowercaseText_ReturnFalse) {
    // Not lowercase text
    std::string text = "HELLo WOrld!";

    // Result
    auto result = utils::is_lowercase(text);
    EXPECT_FALSE(result);
}

TEST(UtilsModuleTests, PassLowercaseText_ReturnTrue) {
    // Lowercase text
    std::string text = "hello 1wor2ld!";

    // Result
    auto result = utils::is_lowercase(text);
    EXPECT_TRUE(result);
}
