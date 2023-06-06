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

#include <iostream>
#include <vector>

namespace trench {
    class Crypto {
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

        /* RSA 加密算法，明文和密钥对 (<E,D,N>)作为输入参数，返回加密结果 */
        static std::vector<int> EncryptStr(const std::string str, int number_E, int number_N);
        static std::vector<int> EncryptStr(const std::string str, int *arr);

        /* RSA encryption algorithm. Enter the ciphertext to be decrypted and the key pair(<E,D,N>), and return the plaintext */

        /* RSA 解密算法，密文和密钥对 (<E,D,N>)作为输入参数，返回解密结果 */
        static std::string DecryptStr(std::vector<int> buff, int number_D, int number_N);
        static std::string DecryptStr(std::vector<int> buff, int *arr);

        /*
         * Randomly generate a key pair
         * Pass an array pointer argument with three values and return it in order <int>{E,D,N}
         */
        /*
         * 随机生成密钥对
         * 参数为一个长度为3的数组指针，返回整数密钥对 (<E,D,N>)
         */
        static bool RandomKeypair(int *arr);

        /**
         * DES
         */


    };

}


#endif //TRENCH_CRYPTO_H
