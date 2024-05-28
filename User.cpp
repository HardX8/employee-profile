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

// ���û���Ϣ�������ļ���
void User::saveUserToFile(const string& filename) {
    ofstream outFile(filename, ios_base::app);
    if (!outFile.is_open()) {
        cerr << "�޷����ļ�: " << filename << endl;
        return;
    }

    // ���û���������д���ļ����м��ö��ŷֿ�������֮�����
    outFile << name << "," << password << phone << endl;
    outFile.close();
    cout << "�û������ѱ�����: " << filename << endl;
}

// �ж��û����������Ƿ�ƥ��
bool User::isPasswordValid(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "�޷����ļ�: " << filename << endl;
        // �ļ������ڻ��޷��򿪣��޷���֤
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
                // �û���������ƥ��
                return true; 
            }
        }
    }
    inFile.close();
    // δ�ҵ�ƥ����û����������
    return false; 
}

// �ж��Ƿ���ڸ��û���
bool User::isUsernameExists(const string& username, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "�޷����ļ�: " << filename << endl;
        return false; // �ļ������ڻ��޷��򿪣���Ϊ�û���������
    }

    string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos && line.substr(0, pos) == username) {
            inFile.close();
            // �û����Ѵ���
            return true; 
        }
    }
    inFile.close();
    // ��ȡ�������У�δ�ҵ�ƥ����û���
    return false; 
}

string User::findPhoneNumberAndSendVerificationCode(const std::string& phone)
{
    return string();
}
