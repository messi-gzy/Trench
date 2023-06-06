// Created by MaXin on 2023/4/11.
/**
 * @file encrypt.h
 * @brief Encryption class of the rsa cryptographic algorithm
 * @date 2023/4/11
 * @authors {@author MaXin @author gzy}
 */
#ifndef EXTRA_CRYPTO_RSA_ENCRYPT_H
#define EXTRA_CRYPTO_RSA_ENCRYPT_H

#include "key_pair.h"

/* Encryption class of the rsa cryptographic algorithm
 * Including prime number acquisition, encryption key and decryption key
 * generation */
class TRENCH_EXPORT Encrypt {
public:
    Encrypt() = default;

    virtual ~Encrypt() = default;

    /* Find the greatest common divisor */
    /* 找到最大公约数 */
    static int Gcd(int x, int y);

    /* Find the least common multiple */
    /* 找到最小公倍数 */
    static int Lcm(int x, int y);

    /* Param is an integer and return the largest prime less than that number
     * This number must be between 10 and 10000 */
    /* 参数是一个整数，并返回小于该数的最大素数
     * 这个数必须是10到10000 */
    static int GetPrime(int number);

    /* Find E in the public key cipher (E,N) */
    /* 在公钥密码( E , N)中查找E */
    static int GetNumberE(int number_L);

    /* Find D in the public key cipher (E,N) */
    /* 在公钥密码( E , N)中查找D */
    static int GetNumberD(int number_E, int number_L);

    /* encryption algorithm */
    /* 加密算法 */
    static bool EncryptAlgorithm(KeyPair &keyPair);

    /* decryption algorithm */
    /* 解密算法 */
    static bool DecryptAlgorithm(KeyPair &keyPair);

    /* Randomly generate a key pair
     * @return array point <int>{E,D,N} */
    /* 随机生成一个密钥对
     * @返回数组指针 <int>{E,D,N} */
    static bool RandomKeypair(int *arr);

private:
};

#endif  // EXTRA_CRYPTO_RSA_ENCRYPT_H