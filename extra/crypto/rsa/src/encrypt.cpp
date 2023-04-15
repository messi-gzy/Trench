// Created by MaXin on 2023/4/11
/**
 * @file encrypt.h
 */
#include "encrypt.h"


Encrypt::Encrypt() {}

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

int Encrypt::Lcm(int x, int y) {
    return (x * y) / Encrypt::Gcd(x, y);
}

int Encrypt::GetPrime(int number) {
    const int maxNumber = 10000;
    int primes[maxNumber], cnt = 0;
    bool st[maxNumber];
    for (int i = 2; i <= number; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= number / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primes[--cnt];
}