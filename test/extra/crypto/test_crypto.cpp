//
// Created by MateBook13 on 2023/4/13.
//
#include "des.h"
#include "md5.h"
#include "rsa.h"
#include <bitset>

int main(int argc, char *argv[]) {
    /* test_rsa */
    /*{
        Decode decode;
        string s = "�治not����you��*&()<>";
        int array[3] = {0, 0, 0};
        Encrypt::RandomKeypair(array);
        vector<int> temp = decode.EncryptStr(s, array[0], array[2]);
        cout << decode.DecryptStr(temp, array[1], array[2]) << endl;
    }*/
    /* test_md5 */
    /*{
        for (int i = 0; i < argc; ++i) {
            cout << "[ " << i << " ] " << argv[i] << endl;
        }
        cout << "Hello Test" << endl;
        cout << MD5("MaXin").ToStr();
    }*/
    /* test_des */
    {
        for (int i = 0; i < argc; ++i) {
            cout << "[ " << i << " ] " << argv[i] << endl;
        }
    }
    return 0;
}
