/*
 * @file IniConfig.cpp
 * @authors { MaXin , MateBook13 }
 * @date 2023/6/6
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief Implementation of header file IniConfig.h
 * 
 */

#include "IniConfig.h"

#include <fstream>


//************************************************************************
// ��������:    	TrimString
// ����Ȩ��:    	public
// ��������:		2017/01/05
// �� �� ��:
// ����˵��:		ȥ���ո�
// ��������: 	string & str	������ַ���
// �� �� ֵ:   	std::string &	����ַ���
//************************************************************************
string &TrimString(string &str) {
    string::size_type pos;
    while (str.npos != (pos = str.find(" "))) {
        str = str.replace(pos, pos + 1, "");
    }
    return str;
}

//************************************************************************
// ��������:    	ReadINI
// ����Ȩ��:    	public
// ��������:		2017/01/05
// �� �� ��:
// ����˵��:		��ȡINI�ļ��������䱣�浽map�ṹ��
// ��������: 	string path	INI�ļ���·��
// �� �� ֵ:   	int
//************************************************************************
int IniConfig::ReadINI(string path) {
    std::ifstream in_conf_file(path.c_str());
    if (!in_conf_file) {
        return 0;
    }
    string str_line = "";
    string str_root = "";
    vector<ININode> vec_ini;
    while (getline(in_conf_file, str_line)) {
        string::size_type left_pos;
        string::size_type right_pos;
        string::size_type equal_div_pos;
        string str_key = "";
        string str_value = "";
        if ((str_line.npos != (left_pos = str_line.find("["))) && (str_line.npos != (right_pos = str_line.find("]")))) {
//            str_root = str_line.substr(left_pos + 1, right_pos - 1);
            str_root = str_line.substr(left_pos + 1, right_pos - left_pos - 1);
        }

        if (str_line.npos != (equal_div_pos = str_line.find("="))) {
            str_key = str_line.substr(0, equal_div_pos);
//            str_value = str_line.substr(equal_div_pos + 1, str_line.size() - 1);
            str_value = str_line.substr(equal_div_pos + 1, str_line.size() - equal_div_pos - 1);
            str_key = TrimString(str_key);
            str_value = TrimString(str_value);
        }

        if ((!str_root.empty()) && (!str_key.empty()) && (!str_value.empty())) {
            ININode ini_node(str_root, str_key, str_value);
            vec_ini.push_back(ini_node);
        }
    }
    in_conf_file.close();
    in_conf_file.clear();

    //vector convert to map
    map<string, string> map_tmp;
    for (vector<ININode>::iterator itr = vec_ini.begin(); itr != vec_ini.end(); ++itr) {
        map_tmp.insert(pair<string, string>(itr->root, ""));
    }    //��ȡ�����ڵ�
    for (map<string, string>::iterator itr = map_tmp.begin(); itr != map_tmp.end(); ++itr) {
#ifdef INIDEBUG
        cout << "���ڵ㣺 " << itr->first << endl;
#endif    //INIDEBUG
        SubNode sn;
        for (vector<ININode>::iterator sub_itr = vec_ini.begin(); sub_itr != vec_ini.end(); ++sub_itr) {
            if (sub_itr->root == itr->first) {
#ifdef INIDEBUG
                cout << "��ֵ�ԣ� " << sub_itr->key << "=" << sub_itr->value << endl;
#endif    //INIDEBUG
                sn.InsertElement(sub_itr->key, sub_itr->value);
            }
        }
        map_ini.insert(pair<string, SubNode>(itr->first, sn));
    }
    return 1;
}

//************************************************************************
// ��������:    	GetValue
// ����Ȩ��:    	public
// ��������:		2017/01/05
// �� �� ��:
// ����˵��:		���ݸ����ĸ����ͼ�ֵ�����������ֵ
// ��������: 	string root		������ĸ����
// ��������: 	string key		������ļ�
// �� �� ֵ:   	std::string		�������ֵ
//************************************************************************
string IniConfig::GetValue(string root, string key) {
    map<string, SubNode>::iterator itr = map_ini.find(root);
    map<string, string>::iterator sub_itr = itr->second.sub_node.find(key);
    if (!(sub_itr->second).empty()) {
        return sub_itr->second;
    }
    return "";
}

//************************************************************************
// ��������:    	WriteINI
// ����Ȩ��:    	public
// ��������:		2017/01/05
// �� �� ��:
// ����˵��:		����XML����Ϣ���ļ���
// ��������: 	string path	INI�ļ��ı���·��
// �� �� ֵ:   	int
//************************************************************************
int IniConfig::WriteINI(string path) {
    std::ofstream out_conf_file(path.c_str());
    if (!out_conf_file) {
        return -1;
    }
    for (map<string, SubNode>::iterator itr = map_ini.begin(); itr != map_ini.end(); ++itr) {
        out_conf_file << "[" << itr->first << "]" << std::endl;
        for (map<string, string>::iterator sub_itr = itr->second.sub_node.begin();
             sub_itr != itr->second.sub_node.end(); ++sub_itr) {
            out_conf_file << sub_itr->first << "=" << sub_itr->second << std::endl;
        }
    }

    out_conf_file.close();
    out_conf_file.clear();

    return 1;
}


//************************************************************************
// ��������:    	SetValue
// ����Ȩ��:    	public
// ��������:		2017/01/05
// �� �� ��:
// ����˵��:		�����������ֵ
// ��������: 	string root		������ĸ��ڵ�
// ��������: 	string key		������ļ�
// ��������: 	string value	�������ֵ
// �� �� ֵ:   	std::vector<ININode>::size_type
//************************************************************************
vector<ININode>::size_type IniConfig::SetValue(string root, string key, string value) {
    map<string, SubNode>::iterator itr = map_ini.find(root);    //����
    if (map_ini.end() != itr) {
        itr->second.sub_node[key] = value;
    }    //���ڵ��Ѿ������ˣ�����ֵ
    else {
        SubNode sn;
        sn.InsertElement(key, value);
        map_ini.insert(pair<string, SubNode>(root, sn));
    }    //���ڵ㲻���ڣ����ֵ

    return map_ini.size();
}

//************************************************************************
// ��������:    	Travel
// ����Ȩ��:    	public
// ��������:		2017/01/05
// �� �� ��:
// ����˵��:		������ӡINI�ļ�
// �� �� ֵ:   	void
//************************************************************************
void IniConfig::Travel() {
    for (map<string, SubNode>::iterator itr = this->map_ini.begin(); itr != this->map_ini.end(); ++itr) {
        std::cout << "[" << itr->first << "]" << std::endl;
        for (map<string, string>::iterator itr1 = itr->second.sub_node.begin(); itr1 != itr->second.sub_node.end();
             ++itr1) {
            std::cout << "    " << itr1->first << " = " << itr1->second << std::endl;
        }
    }

}
