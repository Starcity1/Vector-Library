/*
C++ Encryption Generation Library
GitHub: StarCity1
Date: 6/11/2022
Description:
A library that contains various encryption generators and able to produce various encryptions. Hopefully I (Starcity1)
will constantly update this library, please read the README.md file to learn more about this library.
*/

/*
TODO List:
- Add ceasar cipher and decipher
- Add substitution cipher and decipher
- Add transposition cipher and decipher
- Add ascii-character encryption and decryption
- Add RSA encryption and decryption
- Add AES encryption and decryption

NOTE: All encryptions and decryptions methods will be stored on the same class generators.
*/

#include <iostream>
#include <string>

#ifndef EZENCRYPT_H
#define EZENCRYPT_H

    class CeasarGen {
    private:
        int offset;
    public:
        CeasarGen();
        void test();
};

#endif // EZENCRYPT_H