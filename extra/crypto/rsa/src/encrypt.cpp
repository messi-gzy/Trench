// Created by MaXin on 2023/4/11
/**
 * @file encrypt.cpp
 */
#include "encrypt.h"

// Encrypt::Encrypt() {}

Encrypt::~Encrypt() {}

int Encrypt::Gcd(int x, int y) {
    int z = y;
    while (x % y != 0) {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

int Encrypt::Lcm(int x, int y) { return (x * y) / Encrypt::Gcd(x, y); }

int Encrypt::GetPrime(int number) {
    if (number <= 10) {
        return -1;
    } else {
        const int maxNumber = 10000;
        int cnt = 0;
        int *primes = new int[number];
        bool *status = new bool[number];
        for (size_t i = 0; i < number; i++) {
            primes[i] = 0;
            status[i] = false;
        }
        for (int i = 2; i <= number; i++) {
            if (!status[i]) {
                primes[cnt++] = i;
            }
            for (int j = 0; primes[j] <= number / i; j++) {
                status[primes[j] * i] = true;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        int result = primes[--cnt];
        delete[] primes;
        primes = nullptr;
        delete[] status;
        status = nullptr;
        return result;
    }
}

int Encrypt::GetNumberE(int number_L) {
    int number_E = 0;
    for (int i = 2; i < number_L; i++) {
        if (Encrypt::Gcd(i, number_L) == 1) {
            number_E = i;
            break;
        }
    }
    return number_E;
}

int Encrypt::GetNumberD(int number_E, int number_L) {
    int number_D = 0;
    for (int i = 2; i < number_L; i++) {
        if ((number_E * i) % number_L == 1) {
            number_D = i;
            break;
        }
    }
    return number_D;
}

bool Encrypt::EncryptAlgorithm(KeyPair &keyPair) { 
    int ciphertext = 0;
    ciphertext = KeyPair::GetCountMod(
        KeyPair::GetCountExp(keyPair.GetPlaintext(), keyPair.GetNumberE()),
        keyPair.GetNumberN());
    keyPair.SetCiphertext(ciphertext); 
    return true;
}