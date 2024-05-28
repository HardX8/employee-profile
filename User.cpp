#include "User.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

User::User(string na, string pa, string ph) : name(na), password(pa), phone(ph)
{

}

string User::getName() {
    return name;
}
string User::getPassword() {
    return password;
}

// 将用户信息保存至文件中
void User::saveUserToFile(const string& filename) {
    ofstream outFile(filename, ios_base::app);
    if (!outFile.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        return;
    }

    // 将用户名和密码写入文件，中间用逗号分开，便于之后解析
    outFile << name << "," << password << phone << endl;
    outFile.close();
    cout << "用户数据已保存至: " << filename << endl;
}

// 判断用户名和密码是否匹配
bool User::isPasswordValid(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        // 文件不存在或无法打开，无法验证
        return false; 
    }

    string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            string storedUsername = line.substr(0, pos);
            string storedPassword = line.substr(pos + 1);

            if (storedUsername == name && storedPassword == password) {
                inFile.close();
                // 用户名和密码匹配
                return true; 
            }
        }
    }
    inFile.close();
    // 未找到匹配的用户名密码组合
    return false; 
}

// 判断是否存在该用户名
bool User::isUsernameExists(const string& username, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        return false; // 文件不存在或无法打开，视为用户名不存在
    }

    string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos && line.substr(0, pos) == username) {
            inFile.close();
            // 用户名已存在
            return true; 
        }
    }
    inFile.close();
    // 读取完所有行，未找到匹配的用户名
    return false; 
}

string User::findPhoneNumberAndSendVerificationCode(const std::string& phone)
{
    return string();
}
