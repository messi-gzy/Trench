// Created by MaXin on 2023/4/11.
/**
 * @file decode.cpp
 * @brief RSA encryption and decryption algorithm
 * See the header file for the method description
 * @date 2023/4/11
 * @authors {@author MaXin @author gzy}
 */

#include "decode.h"

Decode::Decode() {}

Decode::~Decode() {}

vector<unsigned char> Decode::EncodeGBK(const string str) {
    vector<unsigned char> buff;
    int len = str.length();
    buff.resize(len);
    memcpy(&buff[0], str.c_str(), len);
    return buff;
};

string Decode::DecodeGBK(vector<unsigned char> buff) {
    vector<unsigned char> debuf = buff;
    debuf.resize(buff.size() + 1);
    string str = (char *)&debuf[0];
    return str;
};

vector<int> Decode::EncryptStr(const string str,int number_E, int number_N) {
    vector<int> vector_ciphertext;
    for (int i = 0; i < str.size(); i++) {
        int temp = str.at(i) - '0';
        if (temp <= 0) {
            KeyPair keypair(temp + 500, number_E, number_N);
            Encrypt::EncryptAlgorithm(keypair);
            vector_ciphertext.push_back(keypair.Getciphertext());
        } else {
            KeyPair keypair(temp, 7, 1643);
            Encrypt::EncryptAlgorithm(keypair);
            vector_ciphertext.push_back(keypair.Getciphertext());
        }
    }
    return vector_ciphertext;
}
string Decode::DecryptStr(vector<int> buff, int number_D, int number_N) {
    string str_plaintext;
    for (size_t i = 0; i < buff.size(); i++) {
        KeyPair keypair(true, buff.at(i), number_D, number_N);
        Encrypt::DecryptAlgorithm(keypair);
        int temp = keypair.GetPlaintext();
        if (temp >= 225) {
            str_plaintext.push_back((temp - 500) + '0');
        } else {
            str_plaintext.push_back(temp + '0');
        }
    }
    return str_plaintext;
}