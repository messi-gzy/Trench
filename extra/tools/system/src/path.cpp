/*
 * @file path.cpp
 * @authors { MaXin , Matebook13 , gzy }
 * @date 2023-04-22
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief .
 *
 */

#include "path.h"


Path::~Path() {}

/*
 * 获取当前可执行的文件的绝对路径
 */
char *Path::GetExePath() {
    const int MAX_LENGTH = 512;
    char buffer[MAX_LENGTH];
    getcwd(buffer, 512);
    std::string cwd = buffer;
    int pos = cwd.find('\\');
    while (pos != cwd.npos) {
        cwd.replace(pos, 1, "/");
        pos = cwd.find('\\');
    }
    std::string cwdExe = cwd;
    char *path = new char[128];
    for (int i = 0; i < cwdExe.length(); ++i) {
        path[i] = cwdExe[i];
    }
    return path;
};

/*
 * 获取当前执行程序的路径并加上后置参数
 * ------------------------示例
 * char *a = new char[128];
 * string temp = "./test/test_class.exe come on";
 * for (int i = 0; i < temp.length(); ++i) {
 *     a[i] = temp[i];
 * }
 * ExecuteShell(a);
 */

void Path::ExecuteShell(char *shell) {
    char *path = this->GetExePath();
    char *exeShell = new char[256];
    int length = 0;
    for (int i = 0; i < _msize(path) / sizeof(char); ++i) {
        if (path[i] != '\u0000') {
            exeShell[i] = path[i];
            length++;
        }
    }
    int exeLength = length;
    for (int i = 0; i < _msize(shell) / sizeof(char); ++i) {
        if (shell[i] != '\u0000') {
            exeShell[i + exeLength] = shell[i];
            length++;
        }
    }
    system(exeShell);
}