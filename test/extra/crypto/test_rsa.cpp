//
// Created by MateBook13 on 2023/4/13.
//
#include "rsa.h"

int main() {
    Decode decode;
    string s = "�治not����you��*&()<>";
    int array[3] = {0, 0, 0};
    Encrypt::RandomKeypair(array);
    vector<int> temp = decode.EncryptStr(s, array[0], array[2]);
    cout << decode.DecryptStr(temp, array[1], array[2]) << endl;
    return 0;
}
