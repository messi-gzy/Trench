// Created by MaXin on 2023/4/11
/**
 * @file encrypt.cpp
 * @brief See the header file for the method description
 */
#include "encrypt.h"


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
    if (number <= 10 || number >= 10000) {
        return -1;
    } else {
        const int maxNumber = 10000;
        int cnt = 0;
        /* Use heap area to ease stack area */
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

bool Encrypt::DecryptAlgorithm(KeyPair &keyPair) {
    int plaintext = 0;
    plaintext = KeyPair::GetCountMod(
            KeyPair::GetCountExp(keyPair.GetCiphertext(), keyPair.GetNumberD()),
            keyPair.GetNumberN());
    keyPair.SetPlaintext(plaintext);
    return true;
}

bool Encrypt::RandomKeypair(int *arr) {
    // Initializes the random number seed
    srand(time(nullptr));

    /* rand()%a+b indicates that an integer ranging from b to (a+b-1) is
     * generated */
    /* num_p or num_q is randomly generated prime number ,the other numbers are
     * the temporary value needed to generate the key pair */

    int p = rand() % 20 + 30 , q = rand() % 20 + 40;
    int num_P = GetPrime(p), num_Q = GetPrime(q);
    cout << p << "\t" << q<< endl;
    cout << num_P << "\t" << num_Q << endl;
    int num_N = num_P * num_Q;
    int num_L = Encrypt::Lcm(num_P - 1, num_Q - 1);
    int num_E = Encrypt::GetNumberE(num_L);
    int num_D = Encrypt::GetNumberD(num_E, num_L);
    arr[0] = num_E;
    arr[1] = num_D;
    arr[2] = num_N;
    return true;
}