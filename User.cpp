#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Constant.h"
#include <sstream>
#include <vector>
#include "MD5.h"
#include <conio.h>
#include <windows.h>


using namespace std;

/**
 * @author XZH
 */

// ��ʼ����̬��Ա����
shared_ptr<Language> User::userLanguage = nullptr;

// ͨ����i�����ݲ�ѯ������
void User::updateUserByI(const string& filename, const string& phone, int i)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << userLanguage->canNotOpen << endl;
        return;
    }

    // ������ʱ�ļ��������޸ĺ������
    string tempFilename = "temp_" + filename;
    ofstream outFile(tempFilename);
    if (!outFile.is_open()) {
        cerr << userLanguage->canCreateTemp << endl;
        inFile.close();
        return;
    }

    string line;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentProperty;

        // ��ȡÿ�еĵ�i���ֶΣ����ţ�
        int tempI = i;
        while (tempI--) {
            getline(iss, currentProperty, ',');
        }

        if (currentProperty != phone) {
            // �����ǰ�е����Բ���Ҫ�޸ĵ����ԣ���д����ʱ�ļ�
            outFile << line << endl;
        }
        else {
            // ʹ��vector����̬�洢�ָ����ַ���
            vector<string> userVector;
            stringstream ss(line);
            string item;

            // ʹ��getline�����ŷָ��ַ�����ֱ����ȡ������Ԫ��
            while (getline(ss, item, ',')) {
                // ���ָ�õ���Ԫ����ӵ�vector��
                userVector.push_back(item);
            }

            cout << userLanguage->userName << userVector[USER_NAME_SERIAL_NUMBER - 1] << endl;
             
            string password, confirmPassword;
            while (1) {
                cout << userLanguage->inputNewPassword;
                password = inputPassword();
                cout << userLanguage->inputConfirmPassword;
                confirmPassword = inputPassword();
                if (password != confirmPassword) {
                    cout << userLanguage->passwordDifferent << endl;
                }
                else {
                    break;
                }
            }
            
            userVector[USER_PASSWORD_SERIAL_NUMBER - 1] = password;

            // ƴ���µ��û���Ϣ
            string newLine = "";
            for (int j = 0; j < userVector.size(); j++) {
                newLine += userVector[j] + ",";
            }
            // д���ļ�
            outFile << newLine << endl;
        }
    }

    inFile.close();
    outFile.close();


    // ɾ��ԭ�ļ�
    remove(filename.c_str());
    // ����ʱ�ļ�������Ϊԭ�ļ���
    rename(tempFilename.c_str(), filename.c_str());
    cout << userLanguage->phone << phone << userLanguage->updatePasswordSuccess << endl;
}

User::User(string na, string pa, string ph) : name(na), password(pa), phone(ph)
{

}
User::User(string na, string pa) : name(na), password(pa)
{

}

User::User(shared_ptr<Language>& langPtr)
{
    userLanguage = langPtr;
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
        cerr << userLanguage->canNotOpen << filename << endl;
        return;
    }

    // ���û���������д���ļ����м��ö��ŷֿ�������֮�����
    outFile << name << "," << password << "," << phone << endl;
    outFile.close();
    cout << userLanguage->saveUser << filename << endl;
}

// �ж��û����������Ƿ�ƥ��
bool User::isPasswordValid(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << userLanguage->canNotOpen << filename << endl;
        // �ļ������ڻ��޷��򿪣��޷���֤
        return false; 
    }

    string line;
    while (getline(inFile, line)) {
        // ���ҵ�һ�����ŵ�λ��
        size_t pos1 = line.find(','); 
        if (pos1 != string::npos) {
            // ��ȡ��һ�����ݣ��û�����
            string storedUsername = line.substr(0, pos1);  

            // �ӵ�һ������֮��ʼ���ҵڶ������ŵ�λ��
            size_t pos2 = line.find(',', pos1 + 1);  
            if (pos2 != string::npos) {
                // ��ȡ�ڶ������ݣ����룩
                string storedPassword = line.substr(pos1 + 1, pos2 - pos1 - 1); 

                // У���û���������
                if (storedUsername == name && storedPassword == password) {
                    inFile.close();
                    // �û���������ƥ��
                    return true;
                }
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
        cerr << userLanguage->canNotOpen << filename << endl;
        // �ļ������ڻ��޷��򿪣���Ϊ�û���������
        return false; 
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

// �ж��Ƿ���ڸ��ֻ���
bool User::isPhoneExists(const string& phone, const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << userLanguage->canNotOpen << filename << endl;
        return false; // �ļ������ڻ��޷��򿪣���Ϊ�û���������
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentProperty;

        // ��ȡÿ�е�phone����
        int tempI = USER_PHONE_SERIAL_NUMBER;
        while (tempI--) {
            getline(iss, currentProperty, ',');
        }
        if (currentProperty == phone) {
            inFile.close();
            // �ֻ����Ѵ���
            return true;
        }
    }
    inFile.close();
    // ��ȡ�������У�δ�ҵ�ƥ����û���
    return false;
}

// �ֻ��Ŵ���ʱ������֤��
string User::findPhoneAndSendVerificationCode(const string& phone, const string& filename)
{
    if (isPhoneExists(phone, filename)) {
        srand(time(0));
        // ����һ����λ������֤��
        int verificationCode = rand() % 9000 + 1000;
        cout << userLanguage->wait << endl;
        Sleep(1000);
        cout << userLanguage->sending << endl;
        Sleep(1000);
        cout << userLanguage->sended << phone << userLanguage->sendCode << 
            verificationCode << userLanguage->timeValid << endl;
        return to_string(verificationCode);
    }
    else {
        cout << userLanguage->phoneNotRegister << endl;
    }

    // δ�ҵ���Ӧ�û�
    return "";  
}

// �����ֻ��Ÿ���ְ��
void User::updateUserByPhone(const string& filename, const string& phone)
{
    updateUserByI(filename, phone, USER_PHONE_SERIAL_NUMBER);
}

// ��������
string User::inputPassword() {
    char password[21]; // 20λ��������ַ���������
    int index = 0;
    while (1) {
        char ch;
        ch = _getch();
        if (ch == 8) { // �˸��
            if (index != 0) {
                cout << "\b \b"; // ɾ��һ���ַ�
                index--;
            }
        }
        else if (ch == '\r') { // �س���
            password[index] = '\0';
            cout << endl;
            if (index < 6) {
                cout << userLanguage->passwordShort;
                index = 0; // ������������λ��
            }
            else {
                break;
            }
        }
        else {
            if (index < 20) { // ���볤������Ϊ20λ
                cout << "*";
                password[index++] = ch;
            }
            else {
                cout << userLanguage->passwordLong;
                index = 0; // ������������λ��
            }
        }
    }
    string passwordStr(password);
    MD5 md5;
    return md5.calculate(passwordStr);
}
