//
// Created by MateBook13 on 2023/4/13.
//
#include "rsa.h"

int main() {
    Decode decode;
    string s = "�治not����you��*&()<>";
    vector<int> temp = decode.EncryptStr(s, 7, 1643);
    cout << decode.DecryptStr(temp, 223, 1643) << endl;
    return 0;
}
