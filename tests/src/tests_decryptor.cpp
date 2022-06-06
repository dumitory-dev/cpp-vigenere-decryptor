#include "test_data.h"
#include "vigenere_decryptor.h"
#include <gtest/gtest.h>

TEST(VigenereDecryptor, PassText_ReturnEcryptedText) {
    const auto text = "c plus plus is the best language on the planet, baby!";
    const auto key = "cryptii";
    const auto expected_result = "e gjjl xtwj gh mpm dvqi eivilyvx wv vyc eeivgk, zpug!";
    const auto result = vigenere_decryptor::encrypt(text, key);

    EXPECT_EQ(result, expected_result);
    EXPECT_THROW(vigenere_decryptor::encrypt(text, ""), std::invalid_argument);
}

TEST(VigenereDecryptor, PassEncryptedTextWithKey_ReturnDecryptedText) {
    const auto encrypted_text = "xzetgmzg tgeamz kj y bxbpqu mu xvktpnibvo ccnwtjmvza ixfb. "
                                "kk shxa i uzkeem nqik dy xwnpyaipidvrxv acdjrxmcbkfl. "
                                "p iwtarjeaijgkgr vqxjvp xl iva tgeamz drqtw wv ulzhmqbwkgdg, cakee bntbkgjt lcjukginbqqe yaipidvrh. "
                                "mpm geagrxbkfl dy bpg fpxzqvcc rtqb qu umcx cakee iam dkxccxzm uhspkm wt mgvxvmtv rputm.";

    const auto expected_result = "vigenere cipher is a method of encrypting alphabetic text. "
                                 "it uses a simple form of polyalphabetic substitution. a polyalphabetic cipher is "
                                 "any cipher based on substitution, using multiple substitution alphabets. "
                                 "the encryption of the original text is done using the vigenere square or vigenere table.";

    const auto key = "cryptii";

    const auto result = vigenere_decryptor::decrypt_with_key(encrypted_text, key);

    EXPECT_EQ(result, expected_result);
}

TEST(VigenereDecryptor, PassSmallEncryptedTextWithoutKey_ReturnDecryptedText) {
    // Small size text
    // With our method, small texts may not be supported
    const auto encrypted_text = "jfutomz, tvatgbta kft vwuorls aia dvcc lcxgiqtwml dp y bhzm hzlt zzikecs txxtfyra";
    // most suitable key
    const auto expected_key = "idgaahzpg";

    auto [key, text] = vigenere_decryptor::decrypt(encrypted_text);
    EXPECT_EQ(expected_key, key);
}

TEST(VigenereDecryptor, PassMediumEncryptedTextWithoutKey_ReturnDecryptedText) {
    const auto encrypted_text = "xzetgmzg tgeamz kj y bxbpqu mu xvktpnibvo ccnwtjmvza ixfb. "
                                "kk shxa i uzkeem nqik dy xwnpyaipidvrxv acdjrxmcbkfl. "
                                "p iwtarjeaijgkgr vqxjvp xl iva tgeamz drqtw wv ulzhmqbwkgdg, cakee bntbkgjt lcjukginbqqe yaipidvrh. "
                                "mpm geagrxbkfl dy bpg fpxzqvcc rtqb qu umcx cakee iam dkxccxzm uhspkm wt mgvxvmtv rputm.";

    const auto expected_text = "vigenere cipher is a method of encrypting alphabetic text. "
                               "it uses a simple form of polyalphabetic substitution. a polyalphabetic cipher is "
                               "any cipher based on substitution, using multiple substitution alphabets. "
                               "the encryption of the original text is done using the vigenere square or vigenere table.";

    const auto expected_key = "cryptii";

    const auto [key, text] = vigenere_decryptor::decrypt(encrypted_text);

    EXPECT_EQ(expected_key, key);
    EXPECT_EQ(expected_text, text);
}

TEST(VigenereDecryptor, PassBigEncryptedTextWithoutKey_ReturnDecryptedText) {
    const auto expected_text = test_data::big_text;
    const auto encrypted_text = test_data::encrypted_big_text;

    const auto expected_key = "cryptii";

    const auto [key, text] = vigenere_decryptor::decrypt(encrypted_text);

    EXPECT_EQ(expected_key, key);
    EXPECT_EQ(expected_text, text);
}

TEST(VigenereDecryptor, PassInvalidText_ThrowInvalidArgument) {
    // Without alphabet letters
    std::string invalid_text = "12312312334452345";
    EXPECT_THROW(vigenere_decryptor::decrypt(invalid_text);, std::invalid_argument);

    // Not lower case text
    invalid_text = "HELLO";
    EXPECT_THROW(vigenere_decryptor::decrypt(invalid_text);, std::invalid_argument);
}


TEST(VigenereDecryptor, PassEmptyTextToEncryptOrDecrypt_ThrowInvalidArgument) {
    EXPECT_THROW(vigenere_decryptor::decrypt_with_key("", ""), std::invalid_argument);
    EXPECT_THROW(vigenere_decryptor::decrypt(""), std::invalid_argument);
    EXPECT_THROW(vigenere_decryptor::encrypt("", ""), std::invalid_argument);
}
