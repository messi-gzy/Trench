//
// Created by MateBook13 on 2023/4/13.
//
#include <bitset>


#include "des.h"
#include "md5.h"
#include "rsa.h"


int main(int argc, char *argv[]) {
    /* test_rsa */
    {
        Decode decode;
        string s = "hello ���";
        cout << s << endl;
        int array[3] = {0, 0, 0};
        Encrypt::RandomKeypair(array);
        vector<int> temp = decode.EncryptStr(s, array[0], array[2]);
        cout << decode.DecryptStr(temp, array[1], array[2]) << endl;
    }

//    int num_P = rand() % 20 + 30, num_Q = rand() % 20 + 40;
//    cout << num_P << endl;
//    cout << num_Q << endl;
    /* test_md5 */
    /*{
        for (int i = 0; i < argc; ++i) {
            cout << "[ " << i << " ] " << argv[i] << endl;
        }
        cout << "Hello Test" << endl;
        cout << MD5("MaXin").ToStr();
    }*/
    /* test_des */
    /*{
        for (int i = 0; i < argc; ++i) {
            cout << "[ " << i << " ] " << argv[i] << endl;
        }
        char ch[8] = {'a','b','c','d','e','f','g','h'};
        SecretKey secretKey(ch);
        secretKey.Printf();
    }
    return 0;*/

    return 0;
}
