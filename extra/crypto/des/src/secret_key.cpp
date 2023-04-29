/*
 * @file secret_key.cpp
 * @authors { MaXin , MateBook13 }
 * @date 2023/4/20
 * @brief ....
 *
 */
#include "secret_key.h"


SecretKey::SecretKey(const char secret_key[8]) {
    for (int i = 0; i < 8; i++) {
        bitset<8> bitChar(secret_key[i]);
        for (int j = 0; j < 8; j++) {
            this->ch_secret_key[i][j] = bitChar.test(j);
        }
    }
}

SecretKey::~SecretKey() {}

bool SecretKey::ReplaceOne() { return true; }

void SecretKey::Printf() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << this->ch_secret_key[i][j] << " ";
        }
        printf("\n");
    }
}