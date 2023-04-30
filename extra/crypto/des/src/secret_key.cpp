/*
 * @file secret_key.cpp
 * @authors { MaXin , MateBook13 , gzy }
 * @date 2023-04-30
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief .
 *
 */
#include "secret_key.h"

SecretKey::SecretKey(const char str_secret_key[8]) {
    bitset<64> bit_temp;
    for (int i = 0; i < 8; i++) {
        bit_temp = str_secret_key[i] - '0';
        this->bit_initial_key <<= 8;
        this->bit_initial_key |= bit_temp;
    }
}

SecretKey::~SecretKey() {}

bool SecretKey::ReplaceOne() {
    bitset<64> bit_temp;
    for (int i = 0; i < 56; i++) {
        if (this->bit_initial_key[substitution_table::replaceOne[i]]) {
            
        }
    }

    return true;
}

void SecretKey::Printf() { cout << this->bit_initial_key << endl; }