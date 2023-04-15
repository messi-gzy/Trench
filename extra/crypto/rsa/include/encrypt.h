// Created by MaXin on 2023/4/11.
/**
 * @file encrypt.h
 * @brief Encryption class of the rsa cryptographic algorithm
 * @date 2023/4/11
 * @authors {@author MaXin @author gzy}
 */
#ifndef EXTRA_CRYPTO_ENCRYPT_H
#define EXTRA_CRYPTO_ENCRYPT_H

#include <algorithm>
#include <iostream>

/* Encryption class of the rsa cryptographic algorithm
 * Including prime number acquisition, encryption key and decryption key generation */
class Encrypt {
public:
    Encrypt();

    virtual ~Encrypt();

/* Find the greatest common divisor */
    static int Gcd(int x, int y);

/* Find the least common multiple */
    static int Lcm(int x, int y);

/* Param is an integer and return the largest prime less than that number
 * This number is limited to a maximum of 10,000 */
    static int GetPrime(int number);

private:
};


#endif  // EXTRA_CRYPTO_ENCRYPT_H