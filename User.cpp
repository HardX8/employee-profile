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

// 初始化静态成员变量
shared_ptr<Language> User::userLanguage = nullptr;

// 通过第i项内容查询并更新
void User::updateUserByI(const string& filename, const string& phone, int i)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << userLanguage->canNotOpen << endl;
        return;
    }

    // 创建临时文件来保存修改后的数据
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

        // 读取每行的第i个字段（工号）
        int tempI = i;
        while (tempI--) {
            getline(iss, currentProperty, ',');
        }

        if (currentProperty != phone) {
            // 如果当前行的属性不是要修改的属性，则写入临时文件
            outFile << line << endl;
        }
        else {
            // 使用vector来动态存储分割后的字符串
            vector<string> userVector;
            stringstream ss(line);
            string item;

            // 使用getline按逗号分割字符串，直到读取完所有元素
            while (getline(ss, item, ',')) {
                // 将分割得到的元素添加到vector中
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

            // 拼接新的用户信息
            string newLine = "";
            for (int j = 0; j < userVector.size(); j++) {
                newLine += userVector[j] + ",";
            }
            // 写入文件
            outFile << newLine << endl;
        }
    }

    inFile.close();
    outFile.close();


    // 删除原文件
    remove(filename.c_str());
    // 将临时文件重命名为原文件名
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


// 将用户信息保存至文件中
void User::saveUserToFile(const string& filename) {
    ofstream outFile(filename, ios_base::app);
    if (!outFile.is_open()) {
        cerr << userLanguage->canNotOpen << filename << endl;
        return;
    }

    // 将用户名和密码写入文件，中间用逗号分开，便于之后解析
    outFile << name << "," << password << "," << phone << endl;
    outFile.close();
    cout << userLanguage->saveUser << filename << endl;
}

// 判断用户名和密码是否匹配
bool User::isPasswordValid(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << userLanguage->canNotOpen << filename << endl;
        // 文件不存在或无法打开，无法验证
        return false; 
    }

    string line;
    while (getline(inFile, line)) {
        // 查找第一个逗号的位置
        size_t pos1 = line.find(','); 
        if (pos1 != string::npos) {
            // 获取第一个数据（用户名）
            string storedUsername = line.substr(0, pos1);  

            // 从第一个逗号之后开始查找第二个逗号的位置
            size_t pos2 = line.find(',', pos1 + 1);  
            if (pos2 != string::npos) {
                // 获取第二个数据（密码）
                string storedPassword = line.substr(pos1 + 1, pos2 - pos1 - 1); 

                // 校验用户名和密码
                if (storedUsername == name && storedPassword == password) {
                    inFile.close();
                    // 用户名和密码匹配
                    return true;
                }
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
        cerr << userLanguage->canNotOpen << filename << endl;
        // 文件不存在或无法打开，视为用户名不存在
        return false; 
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

// 判断是否存在该手机号
bool User::isPhoneExists(const string& phone, const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << userLanguage->canNotOpen << filename << endl;
        return false; // 文件不存在或无法打开，视为用户名不存在
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentProperty;

        // 读取每行的phone属性
        int tempI = USER_PHONE_SERIAL_NUMBER;
        while (tempI--) {
            getline(iss, currentProperty, ',');
        }
        if (currentProperty == phone) {
            inFile.close();
            // 手机号已存在
            return true;
        }
    }
    inFile.close();
    // 读取完所有行，未找到匹配的用户名
    return false;
}

// 手机号存在时发送验证码
string User::findPhoneAndSendVerificationCode(const string& phone, const string& filename)
{
    if (isPhoneExists(phone, filename)) {
        srand(time(0));
        // 生成一个四位数的验证码
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

    // 未找到对应用户
    return "";  
}

// 根据手机号更新职工
void User::updateUserByPhone(const string& filename, const string& phone)
{
    updateUserByI(filename, phone, USER_PHONE_SERIAL_NUMBER);
}

// 输入密码
string User::inputPassword() {
    char password[21]; // 20位密码加上字符串结束符
    int index = 0;
    while (1) {
        char ch;
        ch = _getch();
        if (ch == 8) { // 退格键
            if (index != 0) {
                cout << "\b \b"; // 删除一个字符
                index--;
            }
        }
        else if (ch == '\r') { // 回车键
            password[index] = '\0';
            cout << endl;
            if (index < 6) {
                cout << userLanguage->passwordShort;
                index = 0; // 重置密码输入位置
            }
            else {
                break;
            }
        }
        else {
            if (index < 20) { // 密码长度限制为20位
                cout << "*";
                password[index++] = ch;
            }
            else {
                cout << userLanguage->passwordLong;
                index = 0; // 重置密码输入位置
            }
        }
    }
    string passwordStr(password);
    MD5 md5;
    return md5.calculate(passwordStr);
}
