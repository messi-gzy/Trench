#include "key_pair.h"

KeyPair::KeyPair(int num_plaintext, int num_E, int num_N) {
    this->num_plaintext = num_plaintext;
    this->num_ciphertext = 0;
    this->num_E = num_E;
    this->num_D = 0;
    this->num_N = num_N;
};
KeyPair::KeyPair(bool status, int num_ciphertext, int num_D, int num_N) {
    this->num_ciphertext = num_ciphertext;
    this->num_plaintext = 0;
    this->num_D = num_D;
    this->num_E = 0;
    this->num_N = num_N;
};

KeyPair::~KeyPair(){};

bool KeyPair::SetPlaintext(int plaintext) {
    this->num_plaintext = plaintext;
    return true;
};
bool KeyPair::SetCiphertext(int ciphertext) {
    this->num_ciphertext = ciphertext;
    return true;
};

int KeyPair::GetPlaintext() { return this->num_plaintext; }
int KeyPair::Getciphertext() { return this->num_ciphertext; }
int KeyPair::GetNumberE() { return this->num_E; }
int KeyPair::GetNumberD() { return this->num_D; }
int KeyPair::GetNumberN() { return this->num_N; }


string KeyPair::GetCountAdd(string a, string b) {
        string c = "";
        int bit = -1;  // 判断是否进位 -1为否，其他为进位数
        int i = a.length() - 1;  // 获得a字符串长度
        int j = b.length() - 1;  // 获得b字符串长度
        // 第一种情况 两者都处理完
        while (i != -1 && j != -1) {
            int t1 = a[i] - 48;
            int t2 = b[j] - 48;
            // 不存在进位
            if (bit == -1) {
                if (t1 + t2 >= 10) {
                    int d = (t1 + t2) % 10;
                    c.insert(0, 1, d + 48);
                    bit = (t1 + t2) / 10;
                } else {
                    c.insert(0, 1, t1 + t2 + 48);
                }
            }
            // 存在进位
            else {
                if (t1 + t2 + bit >= 10) {
                    int d = (t1 + t2 + bit) % 10;
                    c.insert(0, 1, d + 48);
                    bit = (t1 + t2 + bit) / 10;
                } else {
                    c.insert(0, 1, t1 + t2 + bit + 48);
                    bit = -1;
                }
            }
            i--;
            j--;
        }
        // 第二种情况 前者处理完
        while (i == -1 && j != -1) {
            int t2 = b[j] - 48;
            if (bit == -1) {
                c.insert(0, 1, b[j]);
            } else {
                if (t2 + bit >= 10) {
                    int d = (t2 + bit) % 10;
                    c.insert(0, 1, d + 48);
                    bit = (t2 + bit) / 10;
                } else {
                    c.insert(0, 1, t2 + bit + 48);
                    bit = -1;
                }
            }
            j--;
        }
        // 第三种情况 后者处理完
        while (i != -1 && j == -1) {
            int t1 = a[i] - 48;
            if (bit == -1) {
                c.insert(0, 1, a[i]);
            } else {
                if (t1 + bit >= 10) {
                    int d = (t1 + bit) % 10;
                    c.insert(0, 1, d + 48);
                    bit = (t1 + bit) / 10;
                } else {
                    c.insert(0, 1, t1 + bit + 48);
                    bit = -1;
                }
            }
            i--;
        }
        // 最后再判断是否存在进位
        if (bit != -1) {
            c.insert(0, 1, bit + 48);
        }
        bit = -1;
        return c;
}

string KeyPair::GetCountExp(int x, int y) {
        string a1 = std::to_string(x);
        int i = a1.length() - 1;  // a的最后下角标
        // m位数*n位数长度不会超过m+n位
        string temp = a1;  // temp一直变化
        string temp_2 = "0";
        int bitcount = 0;                       // 判断当前位数
        int bit = -1;                           // 判断是否存在进位
        string* arr = new string[a1.length()];  // 保存每次计算的数
        int arr_i = 0;
        for (int x = 1; x < y; x++)  // 几次方就循环几次
        {
            while (i != -1)  // 乘数的位数
            {
                // temp * a1
                int t1 = a1[i] - 48;
                int j = temp.length() - 1;  // temp的最后下角标
                for (int z = 0; z < bitcount; z++) {
                    arr[arr_i].insert(0, 1, '0');
                }
                while (j != -1)  // temp的位数
                {
                    int t2 = temp[j] - 48;
                    if (bit == -1)  // 判断是否有进位
                    {
                        if (t1 * t2 >= 10) {
                            int d = (t1 * t2) % 10;
                            arr[arr_i].insert(0, 1, d + 48);
                            int d_2 = (t1 * t2) / 10;
                            bit = d_2;
                        } else {
                            int d = t1 * t2;
                            arr[arr_i].insert(0, 1, d + 48);
                        }
                    } else {
                        if ((t1 * t2) + bit >= 10) {
                            int d = ((t1 * t2) + bit) % 10;
                            arr[arr_i].insert(0, 1, d + 48);
                            int d_2 = ((t1 * t2) + bit) / 10;
                            bit = d_2;
                        } else {
                            int d = (t1 * t2) + bit;
                            arr[arr_i].insert(0, 1, d + 48);
                            bit = -1;
                        }
                    }
                    j--;
                }
                if (bit != -1) {
                    arr[arr_i].insert(0, 1, bit + 48);
                    bit = -1;
                }
                // 走完一圈
                // 计算每一位的数，最后相加
                // temp_2=temp_2+arr[arr_i];
                temp_2 = GetCountAdd(temp_2, arr[arr_i]);
                bitcount++;
                arr_i++;
                i--;
            }
            bitcount = 0;
            temp = temp_2;
            temp_2 = "0";
            // temp_2 = "0";
            for (int z = 0; z < arr_i; z++) {
                arr[z] = "";
            }
            arr_i = 0;
            i = a1.length() - 1;  // a的最后下角标
        }
        return temp;
}

int KeyPair::GetCountMod(string a, int b) {
        int bit = -1;  // 判断是否需要进位
        // 例如4255%5
        int i = 0;
        while (i < a.length()) {
            int t1 = a[i] - 48;
            if (bit == -1) {
                if (t1 % b > 0) {
                    bit = t1 % b;
                }
            } else {
                if (((bit * 10) + t1) % b >= 0) {
                    bit = ((bit * 10) + t1) % b;
                }
            }
            i++;
        }
        if (bit != -1) {
            return bit;
        } else {
            return 0;
        }
        return 0;
}
