# The Vigenere Decryptor

The program allows you to decrypt the Vigenere cipher without knowing the key.

Frequency analysis method is used for decoding.

[Wiki](https://en.wikipedia.org/wiki/Frequency_analysis)

## Limitation

- Only English text
- The key must also consist of English letters
- Maximum file size 1 megabyte
- The method is NOT effective for small texts. (It is recommended that the length of the cipher is more than 500 characters)
- Key length from 2 to 12 characters


## Build

You need a compiler that supports C++ 17.

The project uses the CMake build system, version 3.14 or higher.

For build project:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

For run test(after build):
```bash
cd build
ctest
```

## Usage

```bash
cd build/bin
./vigenere_decryptor[.exe] <file_path>
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
