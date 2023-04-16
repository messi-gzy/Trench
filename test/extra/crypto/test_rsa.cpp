//
// Created by MateBook13 on 2023/4/13.
//
#include "rsa.h"

int main() {
    Encrypt encrypt;
    // std::cout << Encrypt::Lcm(16,18);
    // std::cout << encrypt.GetNumberE(144) << std::endl;
    // std::cout << encrypt.GetNumberD(5, 144) << std::endl;
    KeyPair keypair(123,17,41989);
    Encrypt::EncryptAlgorithm(keypair);
    std::cout << keypair.Getciphertext() << std::endl;
   /* std::cout << KeyPair::GetCountMod(KeyPair::GetCountExp(123, 17),41989)
              << std::endl;
    */
    return 0;
}
