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
    static int Gcd(int x, int y);

    /* Find the least common multiple */
    static int Lcm(int x, int y);

    /* Param is an integer and return the largest prime less than that number
     * This number must be between 10 and 10000 */
    static int GetPrime(int number);

    /* Find E in the public key cipher (E,N) */
    static int GetNumberE(int number_L);

    /* Find D in the public key cipher (E,N) */
    static int GetNumberD(int number_E, int number_L);

    /* encryption algorithm */
    static bool EncryptAlgorithm(KeyPair &keyPair);

    /* decryption algorithm */
    static bool DecryptAlgorithm(KeyPair &keyPair);

    /* Randomly generate a key pair
     * @return array point <int>{E,D,N} */
    static bool RandomKeypair(int *arr);

private:
};

#endif  // EXTRA_CRYPTO_RSA_ENCRYPT_H