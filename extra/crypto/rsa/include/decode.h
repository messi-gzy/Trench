// Created by MaXin on 2023/4/11.
/**
 * @file decode.h
 * @brief RSA encryption and decryption algorithm
 * @date 2023/4/11
 * @authors {@author MaXin @author gzy}
 */
#ifndef EXTRA_CRYPTO_RSA_DECODE_H
#define EXTRA_CRYPTO_RSA_DECODE_H

#include "encrypt.h"

class Decode {
public:
    Decode() = default;
    virtual ~Decode();
    /* Encryptographic string ,return vector<int>*/
    vector<int> EncryptStr(const string str, int number_E, int number_N);

    /* Decryptographic string */
    string DecryptStr(vector<int> buff, int number_D, int number_N);

private:
    /* <int>Vector to string */
    string TransfromStr(vector<int> array);

    /* string to <int>Vector */
    vector<int> TransfromVector(const string &str);
};

#endif