#include <algorithm>
#include <iostream>

#include "utils.h"
#include "vigenere_decryptor.h"

// get path to the file from the command line
std::string get_file_path(const int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./vigenere_decryptor <file_path>" << std::endl;
        ::exit(1);
    }
    return argv[1];
}

int main(const int argc, char *argv[])
{
    try
    {
        std::cout << "Vigenere Cipher Decryption" << std::endl;
        auto encrypted_data = utils::read_all_file(get_file_path(argc, argv));
        std::transform(encrypted_data.cbegin(), encrypted_data.cend(), encrypted_data.begin(), ::tolower);

        const auto [key, text] = vigenere_decryptor::decrypt(encrypted_data);
        std::cout << "Key: " << key << std::endl;
        std::cout << "Text: " << text << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << std::endl;
    }
    return 0;
}
