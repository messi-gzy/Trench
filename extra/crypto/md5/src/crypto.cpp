/*
 * @file crypto.cpp
 * @authors { MaXin , MateBook13 }
 * @date 2023/4/21
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief Implementation of the MD5 password in the common header file <crypto.h>
 */

#include "crypto.h"
#include "md5.h"

namespace trench {
    std::string Crypto::TrenchMD5(const std::string &message) {
        return MD5(message).ToStr();
    }
}
