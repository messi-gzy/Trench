// Created by MaXin on 2023/4/11.
/**
 * @file crypto.h
 * @brief Cryptographic library 
 * [ MD5 , RSA , DES ....]
 * @date 2023/4/11
 * @authors {@author MaXin @author gzy}
 */

#ifndef TRENCH_CRYPTO_H
#define TRENCH_CRYPTO_H

#include "export.h"

#include <iostream>
#include <vector>

namespace trench {
    class TRENCH_EXPORT Crypto {
    public:
        /**
         * MD5
         */

        /* MD5 Algorithm,Enter character information and return a summary */
        static std::string TrenchMD5(const std::string &message);

        /**
         * RSA
         */

        /* RSA encryption algorithm. The plaintext and key pair (<E,D,N>) to be encrypted are entered, and the ciphertext is returned */

        static std::vector<int> EncryptStr(const std::string str, int number_E, int number_N);

        static std::vector<int> EncryptStr(const std::string str, int *arr);

        /* RSA encryption algorithm. Enter the ciphertext to be decrypted and the key pair(<E,D,N>), and return the plaintext */

        static std::string DecryptStr(std::vector<int> buff, int number_D, int number_N);

        static std::string DecryptStr(std::vector<int> buff, int *arr);

        /* Randomly generate a key pair
         * Pass an array pointer argument with three values and return it in order <int>{E,D,N} */
        static bool RandomKeypair(int *arr);

        /**
         * DES
         */


    };

}


#endif //TRENCH_CRYPTO_H
