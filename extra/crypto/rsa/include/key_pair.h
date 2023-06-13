// Created by MaXin on 2023/4/11.
/**
 * @file key_pair.h
 * @brief Details about the key pair
 * @date 2023/4/11
 * @authors {@author MaXin @author gzy}
 */
#ifndef EXTRA_CRYPTO_RSA_KEYPAIR_H
#define EXTRA_CRYPTO_RSA_KEYPAIR_H

#include "export.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class TRENCH_EXPORT KeyPair {
public:
    /* encrypt */
    KeyPair(int num_plaintext, int num_E, int num_N);

    /* decrypt */
    KeyPair(bool status, int num_ciphertext, int num_D, int num_N);

    virtual ~KeyPair();

    bool SetPlaintext(int plaintext);

    bool SetCiphertext(int ciphertext);

    int GetPlaintext();

    int GetCiphertext();

    int GetNumberE();

    int GetNumberD();

    int GetNumberN();

    /* Sum of large numbers */
    static string GetCountAdd(string a, string b);

    /* Exponents of large numbers */
    static string GetCountExp(int x, int y);

    /* Take the remainder of a large number */
    static int GetCountMod(string a, int b);


private:
    int num_plaintext;
    int num_ciphertext;
    int num_E;
    int num_D;
    int num_N;
};

#endif