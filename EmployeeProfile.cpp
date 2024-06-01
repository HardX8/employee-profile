#include "EmployeeProfile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <vector>
#include "Constant.h"
//#include <regex>
#include <ctime>

using namespace std;

shared_ptr<Language> EmployeeProfile::employeeLanguage = nullptr;

/**
 * @author XZH
 */
// 通过第i个属性删除职工
void EmployeeProfile::deleteProfileByI(const string& filename, int i)
{
    string id;
    cin >> id;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << employeeLanguage->canNotOpen << endl;
        return;
    }

    // 创建临时文件来保存修改后的数据
    string tempFilename = "temp_" + filename;
    // 创建的就是新的空文件，不用ios_base::app追加形式
    ofstream outFile(tempFilename);
    if (!outFile.is_open()) {
        cerr << employeeLanguage->canCreateTemp << endl;
        inFile.close();
        return;
    }

    string line;
    // 标记是否找到并删除了指定的记录
    bool found = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentId;

        // 读取每行的第i个字段
        int tempI = i;
        while (tempI--) {
            getline(iss, currentId, ',');
        }


        if (currentId != id) {
            // 如果当前行的属性不是要删除的属性，则写入临时文件
            outFile << line << endl;
        }
        else {
            // 找到了匹配的工号
            found = true;
            // 此处进行break的话会导致要删除职工后面的职工没有写入新文件
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        // 如果找到了匹配的属性，删除原文件
        remove(filename.c_str());
        // 将临时文件重命名为原文件名
        rename(tempFilename.c_str(), filename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << employeeLanguage->employeeId << id << employeeLanguage->employeeAlreadyDel << endl;
        }
        else {
            cout << employeeLanguage->idNum << id << employeeLanguage->employeeAlreadyDel << endl;
        }
    }
    else {
        // 如果没找到匹配项，删除临时文件
        remove(tempFilename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << employeeLanguage->employeeIdNotFound << id << employeeLanguage->employeeRecord << endl;
        }
        else {
            cout << employeeLanguage->idNumNotFound << id << employeeLanguage->employeeRecord << endl;
        }
    }
}

// 通过工号删除
void EmployeeProfile::deleteProfileById(const string& filename)
{
    cout << employeeLanguage->inputEmployeeId;
    deleteProfileByI(filename, EMPLOYEE_ID_SERIAL_NUMBER);
}

// 通过身份证号删除
void EmployeeProfile::deleteProfileByIdNumber(const string& filename)
{
    cout << employeeLanguage->inputIdNum;
    deleteProfileByI(filename, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER);
}

// 将信息存入文件
void EmployeeProfile::saveEmployeeToFile(const string& filename)
{
    // ios_base::app为追加模式打开文件
    ofstream outFile(filename, ios_base::app);
    if (!outFile.is_open()) {
        cerr << employeeLanguage->canNotOpen << filename << endl;
        return;
    }

    // 在此再次判断，如果工号存在则不保存到文件中
    if (EmployeeProfile::isPropertyExists(id, EMPLOYEE_FILENAME, EMPLOYEE_ID_SERIAL_NUMBER)) {
        return;
    }
    // 在此再次判断，如果身份证号存在则不保存到文件中
    if (EmployeeProfile::isPropertyExists(idNumber, EMPLOYEE_FILENAME, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER)) {
        return;
    }

    // 将职工信息写入文件，中间用逗号分开，便于之后解析
    outFile << id << "," << name << "," << idNumber << "," << gender << "," << age << ","
        << phoneNumber << "," << address << "," << education <<
        "," << position << "," << hireDate << "," << department << endl;
    outFile.close();
    cout << employeeLanguage->employeeSaveTo << filename << endl;
}

// 通过第i项内容查询并更新
void EmployeeProfile::updateProfileByI(const string& filename, int i)
{
    string id;
    cin >> id;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << employeeLanguage->canNotOpen << endl;
        return;
    }

    // 创建临时文件来保存修改后的数据
    string tempFilename = "temp_" + filename;
    // 创建的就是新的空文件，不用ios_base::app追加形式
    ofstream outFile(tempFilename);
    if (!outFile.is_open()) {
        cerr << employeeLanguage->canCreateTemp << endl;
        inFile.close();
        return;
    }

    string line;
    // 标记是否找到并修改了指定的记录
    bool found = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentId;

        // 读取每行的第i个字段（工号）
        int tempI = i;
        while (tempI--) {
            getline(iss, currentId, ',');
        }

        if (currentId != id) {
            // 如果当前行的属性不是要修改的属性，则写入临时文件
            outFile << line << endl;
        }
        else {
            // 找到了匹配的工号
            found = true;
            // 此处进行break的话会导致要删除职工后面的职工没有写入新文件
            
            // 使用vector来动态存储分割后的字符串
            vector<string> employeeVector;
            stringstream ss(line);
            string item;

            // 使用getline按逗号分割字符串，直到读取完所有元素
            while (getline(ss, item, ',')) {
                // 将分割得到的元素添加到vector中
                employeeVector.push_back(item);
            }

            string newE;
            for (int j = 0; j < employeeVector.size(); j++) {
                if (j == 0) {
                    cout << employeeLanguage->ratainOldVal << employeeVector[0] << endl 
                        << employeeLanguage->catNotUpdate << endl << endl;
                    j++;
                    // 清除输入缓冲区
                    cin.ignore();
                }
                cout << employeeLanguage->oldVal << employeeVector[j] << endl << employeeLanguage->newVal;
                // 读取用户输入的字符
                char input = cin.get(); 
                // 如果不是回车键
                if (input != '\n') { 
                    // 将读取的字符放回输入流
                    cin.unget(); 
                    // 进行输入操作
                    cin >> newE; 
                    if (j == EMPLOYEE_ID_NUMBER_SERIAL_NUMBER - 1) {
                        while (1) {
                            // 如果格式有误则重新输入
                            if (!regex_match(newE, idNumberPattern)) {
                                cout << employeeLanguage->idNumFormatError;
                                cin >> newE;
                                continue;
                            }
                            // 身份证号已存在
                            if (EmployeeProfile::isPropertyExists(newE, EMPLOYEE_FILENAME, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER)) {
                                cout <<employeeLanguage->idNumAlreadyExist;
                                cin >> newE;
                            }
                            else {
                                break;
                            }
                        }
                    }
                    if (j == EMPLOYEE_PHONE_SERIAL_NUMBER - 1) {
                        while (1) {
                            // 如果格式有误则重新输入
                            if (!verifyPhone(newE)){
                                cout << employeeLanguage->reinputPhone;
                                cin >> newE;
                                continue;
                            }
                            // 身份证号已存在
                            if (EmployeeProfile::isPropertyExists(newE, EMPLOYEE_FILENAME, EMPLOYEE_PHONE_SERIAL_NUMBER)) {
                                cout << employeeLanguage->employeePhoneAlreadyExist;
                                cin >> newE;
                            }
                            else {
                                break;
                            }
                        }
                    }
                    // 更新数据
                    employeeVector[j] = newE;
                    // 清除输入缓冲区
                    cin.ignore();
                    cout << endl;
                }
                else {
                    cout << endl;
                }
            }
            // 拼接新的职工信息
            string newLine = "";
            for (int j = 0; j < employeeVector.size(); j++) {
                // 如果不是最后一个则后面加逗号
                if (j != employeeVector.size() - 1) {
                    newLine += employeeVector[j] + ",";
                }
                else {
                    newLine += employeeVector[j];
                }
            }
            // 写入文件
            outFile << newLine << endl;
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        // 如果找到了匹配的属性，删除原文件
        remove(filename.c_str());
        // 将临时文件重命名为原文件名
        rename(tempFilename.c_str(), filename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << employeeLanguage->employeeId << id << employeeLanguage->employeeUpdateSuccess << endl;
        }
        else {
            cout << employeeLanguage->idNum << id << employeeLanguage->employeeUpdateSuccess << endl;
        }
    }
    else {
        // 如果没找到匹配项，删除临时文件
        remove(tempFilename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << employeeLanguage->employeeIdNotFound << id << employeeLanguage->employeeRecord << endl;
        }
        else {
            cout << employeeLanguage->employeeIdNotFound << id << employeeLanguage->employeeRecord << endl;
        }
    }
}

// 根据工号更新职工phonePattern
void EmployeeProfile::updateProfileById(const string& filename)
{
    cout << employeeLanguage->inputEmployeeId;
    updateProfileByI(filename, EMPLOYEE_ID_SERIAL_NUMBER);
}

// 根据身份证号更新职工
void EmployeeProfile::updateProfileByIdNumber(const string& filename)
{
    cout << employeeLanguage->inputIdNum;
    updateProfileByI(filename, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER);
}

// 判断某个成员变量是否存在，i表示要查询的成员变量的序号
bool EmployeeProfile::isPropertyExists(const string& property, const string& filename, const int i)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << employeeLanguage->canNotOpen << filename << endl;
        // 文件不存在或无法打开，视为用户名不存在
        return false; 
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentProperty;

        // 读取每行的第i个字段
        int tempI = i;
        while (tempI--) {
            getline(iss, currentProperty, ',');
        }
        if (currentProperty == property && i == EMPLOYEE_ID_SERIAL_NUMBER) {
            inFile.close();
            return true;
        }
        else if(currentProperty == property && i == EMPLOYEE_ID_NUMBER_SERIAL_NUMBER) {
            inFile.close();
            return true;
        }
        else if (currentProperty == property && i == EMPLOYEE_PHONE_SERIAL_NUMBER) {
            inFile.close();
            return true;
        }
    }
    inFile.close();
    // 读取完所有行，未找到匹配的工号
    return false;
}

// 验证手机号是否正确
bool EmployeeProfile::verifyPhone(string phone) {
    // 如果手机号格式不正确
    if (!regex_match(phone, phonePattern)) {
        cout << employeeLanguage->phoneFormatError << endl;
        return false;
    }
}

// 重载 >> 运算符
istream& operator>>(istream& in, EmployeeProfile& profile) {
    while (1) {
        cout << EmployeeProfile::employeeLanguage->employeeIdFormat;
        in >> profile.id;
        // 如果格式有误则重新输入
        if (profile.id.size() == 10) {
            // 提取前四位
            string yearStr = profile.id.substr(0, 4);
            // 转换为int
            int yearInt = stoi(yearStr);

            // 获取当前时间
            time_t now = time(0);
            // 定义一个tm结构体变量来保存转换后的时间
            tm localTimeStruct;
            // 使用localtime_s进行安全的转换
            localtime_s(&localTimeStruct, &now);
            // 获取年份，tm_year是从1900年开始的，所以需要加1900
            int currentYear = localTimeStruct.tm_year + 1900;

            if (yearInt < 1956 || yearInt > currentYear) {
                cout << EmployeeProfile::employeeLanguage->employeeIdFormatError << endl;
                continue;
            }
        }
        else {
            cout << EmployeeProfile::employeeLanguage->employeeIdFormatError << endl;
            continue;
        }
        // 工号已存在
        if (EmployeeProfile::isPropertyExists(profile.id, EMPLOYEE_FILENAME, EMPLOYEE_ID_SERIAL_NUMBER)) {
            cout << EmployeeProfile::employeeLanguage->employeeIdAlreadyExist << endl;
        }
        else {
            break;
        }
    }

    cout << EmployeeProfile::employeeLanguage->employeeName;
    in >> profile.name;

    while (1) {
        cout << EmployeeProfile::employeeLanguage->inputIdNum2;
        in >> profile.idNumber;
        // 如果格式有误则重新输入
        if (!regex_match(profile.idNumber, idNumberPattern)) {
            cout << EmployeeProfile::employeeLanguage->idNumFormatError2 << endl;
            continue;
        }
        // 身份证号已存在
        if (EmployeeProfile::isPropertyExists(profile.idNumber, EMPLOYEE_FILENAME, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER)) {
            cout << EmployeeProfile::employeeLanguage->idNumAlreadyExist2 << endl;
        }
        else {
            break;
        }
    }

    cout << EmployeeProfile::employeeLanguage->gender;
    in >> profile.gender;
    cout << EmployeeProfile::employeeLanguage->age;
    in >> profile.age;

    while (1) {
        cout << EmployeeProfile::employeeLanguage->employeePhone;
        in >> profile.phoneNumber;
        // 如果格式有误则重新输入
        if (!EmployeeProfile::verifyPhone(profile.phoneNumber)) {
            continue;
        }
        // 身份证号已存在
        if (EmployeeProfile::isPropertyExists(profile.phoneNumber, EMPLOYEE_FILENAME, EMPLOYEE_PHONE_SERIAL_NUMBER)) {
            cout << EmployeeProfile::employeeLanguage->phoneAlreadyExist2 << endl;
        }
        else {
            break;
        }
    }


    cout << EmployeeProfile::employeeLanguage->address;
    in >> profile.address;
    cout << EmployeeProfile::employeeLanguage->education;
    in >> profile.education;
    cout << EmployeeProfile::employeeLanguage->position;
    in >> profile.position;
    cout << EmployeeProfile::employeeLanguage->hireDate;
    in >> profile.hireDate;
    cout << EmployeeProfile::employeeLanguage->department;
    in >> profile.department;

    return in;
}

// 重载 << 运算符
ostream& operator<<(ostream& out, EmployeeProfile& profile)
{
    const int SHORT_WIDTH = 10; // 短列宽
    const int MIDDLE_WIDTH = 15; // 中列宽
    const int LONG_WIDTH = 20; // 长列宽
    const int LINE_LENGTH = 155; // 分割线长度

    // 输出数据行
    out << left << setw(MIDDLE_WIDTH) << profile.id
        << setw(SHORT_WIDTH) << profile.name
        << setw(LONG_WIDTH) << profile.idNumber
        << setw(SHORT_WIDTH) << profile.gender
        << setw(SHORT_WIDTH) << profile.age
        << setw(MIDDLE_WIDTH) << profile.phoneNumber
        << setw(LONG_WIDTH) << profile.address
        << setw(SHORT_WIDTH) << profile.education
        << setw(MIDDLE_WIDTH) << profile.position
        << setw(MIDDLE_WIDTH) << profile.hireDate
        << setw(MIDDLE_WIDTH) << profile.department << endl;
    out << string(LINE_LENGTH, '-');
    return out;
}


// 有参构造函数定义
EmployeeProfile::EmployeeProfile(
    string i,
    string n,
    string idN,
    string g,
    int a,
    string p,
    string addr,
    string e,
    string pos,
    string hd,
    string dep
) :
    id(i),
    name(n),
    idNumber(idN),
    gender(g),
    age(a),
    phoneNumber(p),
    address(addr),
    education(e),
    position(pos),
    hireDate(hd),
    department(dep)
{
}
EmployeeProfile::EmployeeProfile(shared_ptr<Language>& langPtr) {
    employeeLanguage = langPtr;
}

// 成员变量对应的get函数
string EmployeeProfile::getId()
{
    return id;
}

string EmployeeProfile::getName()
{
    return name;
}

string EmployeeProfile::getIdNumber()
{
    return idNumber;
}

string EmployeeProfile::getGender()
{
    return gender;
}

int EmployeeProfile::getAge()
{
    return age;
}

string EmployeeProfile::getPhoneNumber()
{
    return phoneNumber;
}

string EmployeeProfile::getAddress()
{
    return address;
}

string EmployeeProfile::getEducation()
{
    return education;
}

string EmployeeProfile::getPosition()
{
    return position;
}

string EmployeeProfile::getHireDate()
{
    return hireDate;
}

string EmployeeProfile::getDepartment()
{
    return department;
}

