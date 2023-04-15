//
// Created by MateBook13 on 2023/4/13.
//
#include "rsa.h"

int main() {
    Encrypt encrypt;
    std::cout << encrypt.GetPrime(14) << std::endl;
    std::cout << Encrypt::Lcm(16,18);
    return 0;
}
