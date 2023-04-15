//
// Created by MateBook13 on 2023/4/12.
//
#include "md5.h"

#include <iostream>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << "[ " << i << " ] " << argv[i] << std::endl;
    }
    std::cout << "Hello Test" << std::endl;
    std::cout << MD5("MaXin").ToStr();
    return 0;
}