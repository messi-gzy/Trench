//
// Created by MateBook13 on 2023/4/13.
//
#include <bitset>

#include "des.h"
#include "md5.h"
#include "rsa.h"

#include "gtest/gtest.h"

TEST(add, add1) {
    EXPECT_EQ(1, 1);
    bitset<8> bit1(0b10110);
    bitset<8> bit2(0b10111);
    bit1 |= bit2;
    EXPECT_EQ(bit1,0b00010110);
}

int main(int argc, char *argv[]) {
    /* test_rsa */
    /* {
        Decode decode;
        string s = "hello 你好";
        int array[3] = {0, 0, 0};
        Encrypt::RandomKeypair(array);
        vector<int> temp = decode.EncryptStr(s, array[0], array[2]);
        cout << decode.DecryptStr(temp, array[1], array[2]) << endl;
    } */
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
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}