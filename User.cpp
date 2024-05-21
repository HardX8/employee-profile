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

// ���û���Ϣ�������ļ���
void User::saveUserToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios_base::app);
    if (!outFile.is_open()) {
        std::cerr << "�޷����ļ�: " << filename << std::endl;
        return;
    }

    // �򵥵ؽ��û���������д���ļ����м�������ض��ָ����ֿ�������֮�����
    outFile << name << "," << password << std::endl;
    outFile.close();
    std::cout << "�û������ѱ�����: " << filename << std::endl;
}

// �ж��Ƿ���ڸ��û���
bool User::isUsernameExists(const std::string& username, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "�޷����ļ�: " << filename << std::endl;
        return false; // �ļ������ڻ��޷��򿪣���Ϊ�û���������
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != std::string::npos && line.substr(0, pos) == username) {
            inFile.close();
            return true; // �û����Ѵ���
        }
    }
    inFile.close();
    return false; // ��ȡ�������У�δ�ҵ�ƥ����û���
}

// �ж��û����������Ƿ�ƥ��
bool User::isPasswordValid(const string& filename)
{
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "�޷����ļ�: " << filename << std::endl;
        return false; // �ļ������ڻ��޷��򿪣��޷���֤
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            std::string storedUsername = line.substr(0, pos);
            std::string storedPassword = line.substr(pos + 1);

            if (storedUsername == name && storedPassword == password) {
                inFile.close();
                return true; // �û���������ƥ��
            }
        }
    }
    inFile.close();
    return false; // δ�ҵ�ƥ����û����������
}
