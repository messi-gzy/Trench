/*
 * @file path.h
 * @authors { MaXin , Matebook13 , gzy }
 * @date 2023-04-22
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief .
 *
 */

#ifndef TRNECH_EXTRA_TOOLS_SYETM_PATH_H
#define TRNECH_EXTRA_TOOLS_SYETM_PATH_H

#include <direct.h>
#include <malloc.h>

#include <iostream>

class Path {
private:
    /* data */
public:
    Path() = default;
    virtual ~Path();

    char *GetExePath();

    void ExecuteShell(char *shell);
};

#endif  // TRNECH_EXTRA_TOOLS_SYETM_PATH_H