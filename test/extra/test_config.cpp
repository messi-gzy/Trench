/*
 * @file test_config.
 * @authors { MaXin , MateBook13 }
 * @date 2023/6/8
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief ....
 * 
 */

#include "IniConfig.h"


int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << *argv << std::endl;
        argv++;
    }

    IniConfig *p = new IniConfig();
    p->ReadINI("..\\conf\\config.ini");
    std::string version = p->GetValue("setting","version");
    std::cout << version << std::endl;
    delete p;


    /*IniConfig *p = new IniConfig();
    p->ReadINI("..\\conf\\config.ini");
    std::cout << "\nԭʼINI�ļ����ݣ�" << std::endl;
    p->Travel();
    p->SetValue("setting", "version", "1.0.0");
    std::cout << "\n���ӽڵ�֮������ݣ�" << std::endl;
    p->Travel();
    std::cout << "\n�޸Ľڵ�֮������ݣ�" << std::endl;
    p->SetValue("kk", "kk", "2");
    p->Travel();
    p->WriteINI("..\\conf\\config.ini");
    delete p;*/

    return 0;
}