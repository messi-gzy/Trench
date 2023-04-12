//
// Created by MateBook13 on 2023/4/11.
//
#include <iostream>
#include "md5.h"

int main() {
    std::cout << "Hello Test" << std::endl;
    std::cout << MD5("MaXin").ToStr();
    return 0;
}