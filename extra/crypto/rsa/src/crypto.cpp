/*
 * @file crypto.cpp
 * @authors { MaXin , MateBook13 }
 * @date 2023/4/21
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief Implementation of the RSA password in the common header file <crypto.h>
 */

#include "crypto.h"
#include "rsa.h"

namespace trench {
    std::vector<int> Crypto::EncryptStr(const std::string str, int number_E, int number_N) {
        Decode decode;
        return decode.EncryptStr(str,number_E,number_N);
    }

    std::string Crypto::DecryptStr(std::vector<int> buff, int number_D, int number_N) {
        Decode decode;
        return decode.DecryptStr(buff,number_D,number_N);
    }

    bool Crypto::RandomKeypair(int *arr) {
        Encrypt::RandomKeypair(arr);
        return true;
    }
}
