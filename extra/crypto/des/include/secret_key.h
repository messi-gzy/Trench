/*
 * @file secret_key.h
 * @authors { MaXin , MateBook13 }
 * @date 2023/4/20
 * @brief ....
 *
 */

#ifndef TRENCH_EXTRA_DES_SECRET_KEY_H
#define TRENCH_EXTRA_DES_SECRET_KEY_H

#include "substitution_table.h"

#include <bitset>
#include <iostream>

using std::bitset;
using std::string;
using std::cout;
using std::endl;

/* Generation of SecretKey */
class SecretKey {
private:
    int ch_secret_key[8][8];
    

public:
    SecretKey(const char secret_key[8]);
    virtual ~SecretKey();
    bool ReplaceOne();
    void Printf();
};


#endif  // TRENCH_EXTRA_DES_SECRET_KEY_H


