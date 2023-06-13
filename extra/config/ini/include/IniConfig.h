/*
 * @file IniConfig.h
 * @authors { MaXin , MateBook13 }
 * @date 2023/6/6
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief can modify Ini files
 * 
 */
#ifndef TRENCH_EXTRA_INICONFIG_H
#define TRENCH_EXTRA_INICONFIG_H

#include "export.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>

using std::map;
using std::string;
using std::vector;
using std::pair;

class ININode
{
public:
    ININode(string root, string key, string value)
    {
        this->root = root;
        this->key = key;
        this->value = value;
    }
public:
    string root;
    string key;
    string value;
};

//��ֵ�Խṹ��
class SubNode
{
public:
    void InsertElement(string key, string value)
    {
        sub_node.insert(pair<string, string>(key, value));
    }
public:
    map<string, string> sub_node;
};

//INI�ļ�������
class TRENCH_EXPORT IniConfig
{
public:
    IniConfig() = default;
    virtual ~IniConfig() = default;

public:
    int ReadINI(string path);													//��ȡINI�ļ�
    string GetValue(string root, string key);									//�ɸ����ͼ���ȡֵ
    vector<ININode>::size_type GetSize(){ return map_ini.size(); }				//��ȡINI�ļ��Ľ����
    vector<ININode>::size_type SetValue(string root, string key, string value);	//���ø����ͼ���ȡֵ
    int WriteINI(string path);			//д��INI�ļ�
    void Clear(){ map_ini.clear(); }	//���
    void Travel();						//������ӡINI�ļ�
private:
    map<string, SubNode> map_ini;		//INI�ļ����ݵĴ洢����
};


#endif //TRENCH_EXTRA_INICONFIG_H
