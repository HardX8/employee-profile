#include "User.h"
#include <fstream>
#include <iostream>
#include <string>

User::User(string na, string pa) : name(na), password(pa)
{

}

string User::getName() {
    return name;
}
string User::getPassword() {
    return password;
}

// 将用户信息保存至文件中
void User::saveUserToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios_base::app);
    if (!outFile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    // 简单地将用户名和密码写入文件，中间可以用特定分隔符分开，便于之后解析
    outFile << name << "," << password << std::endl;
    outFile.close();
    std::cout << "用户数据已保存至: " << filename << std::endl;
}

// 判断是否存在该用户名
bool User::isUsernameExists(const std::string& username, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false; // 文件不存在或无法打开，视为用户名不存在
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != std::string::npos && line.substr(0, pos) == username) {
            inFile.close();
            return true; // 用户名已存在
        }
    }
    inFile.close();
    return false; // 读取完所有行，未找到匹配的用户名
}

// 判断用户名和密码是否匹配
bool User::isPasswordValid(const string& filename)
{
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false; // 文件不存在或无法打开，无法验证
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            std::string storedUsername = line.substr(0, pos);
            std::string storedPassword = line.substr(pos + 1);

            if (storedUsername == name && storedPassword == password) {
                inFile.close();
                return true; // 用户名和密码匹配
            }
        }
    }
    inFile.close();
    return false; // 未找到匹配的用户名密码组合
}
