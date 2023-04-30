/*
 * @file secret_key.h
 * @authors { MaXin , MateBook13 }
 * @date 2023/4/20
 * @brief ....
 *
 */

#ifndef TRENCH_EXTRA_DES_SECRET_KEY_H
#define TRENCH_EXTRA_DES_SECRET_KEY_H

#include <bitset>
#include <iostream>

#include "substitution_table.h"

using std::bitset;
using std::cout;
using std::endl;
using std::string;

/* Generation of SecretKey */
class SecretKey {
private:
    // int ch_secret_key[8][8];
    bitset<64> bit_initial_key;    // initial key
    bitset<48> bit_sub_key[16];    // sub key
    bitset<28> bit_left_sub_key;   // left sub key
    bitset<28> bit_right_sub_key;  // right sub key

public:
    SecretKey(const char str_secret_key[8]);
    virtual ~SecretKey();
    bool ReplaceOne();
    void Printf();
};

#endif  // TRENCH_EXTRA_DES_SECRET_KEY_H
