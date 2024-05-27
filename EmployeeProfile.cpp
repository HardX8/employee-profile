#include "EmployeeProfile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <vector>

using namespace std;


// 通过第i个属性删除职工
void EmployeeProfile::deleteProfileByI(const string& filename, int i)
{
    string id;
    cin >> id;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "无法打开文件！" << endl;
        return;
    }

    // 创建临时文件来保存修改后的数据
    string tempFilename = "temp_" + filename;
    ofstream outFile(tempFilename);
    if (!outFile.is_open()) {
        cerr << "无法创建临时文件！" << endl;
        inFile.close();
        return;
    }

    string line;
    // 标记是否找到并删除了指定的记录
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
        cout << "工号为 " << id << " 的员工记录已成功删除。" << endl;
    }
    else {
        // 如果没找到匹配项，删除临时文件
        remove(tempFilename.c_str());
        cout << "未找到工号为 " << id << " 的员工记录。" << endl;
    }
}

void EmployeeProfile::deleteProfileById(const string& filename)
{
    cout << "请输入工号：";
    deleteProfileByI(filename, 1);
}

void EmployeeProfile::deleteProfileByIdNumber(const string& filename)
{
    cout << "请输入身份证号：";
    deleteProfileByI(filename, 3);
}

void EmployeeProfile::saveEmployeeToFile(const string& filename)
{
    std::ofstream outFile(filename, std::ios_base::app);
    if (!outFile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    // 简单地将用户名和密码写入文件，中间可以用特定分隔符分开，便于之后解析
    outFile << id << "," << name << "," << idNumber << "," << gender << "," << age << ","
        << phoneNumber << "," << address << "," << education <<
        "," << position << "," << hireDate << "," << department << std::endl;
    outFile.close();
    std::cout << "职工数据已保存至: " << filename << std::endl;
}

void EmployeeProfile::updateProfileByI(const string& filename, int i)
{
    string id;
    cin >> id;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "无法打开文件！" << endl;
        return;
    }

    // 创建临时文件来保存修改后的数据
    string tempFilename = "temp_" + filename;
    ofstream outFile(tempFilename);
    if (!outFile.is_open()) {
        cerr << "无法创建临时文件！" << endl;
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
                    cout << "按回车键则保留旧数据\n\n旧值：" << employeeVector[0] << endl << "不可修改" << endl << endl;
                    j++;
                    // 清除输入缓冲区
                    cin.ignore();
                }
                cout << "旧值：" << employeeVector[j] << endl << "新值：";
                // 读取用户输入的字符
                char input = cin.get(); 
                // 如果不是回车键
                if (input != '\n') { 
                    // 将读取的字符放回输入流
                    cin.unget(); 
                    // 进行输入操作
                    cin >> newE; 
                    employeeVector[j] = newE;
                    // 清除输入缓冲区
                    cin.ignore();
                    cout << endl;
                }
                else {
                    cout << endl;
                }
            }
            string newLine = "";
            for (int j = 0; j < employeeVector.size(); j++) {
                newLine += employeeVector[j] + ",";
            }
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
        cout << "工号为 " << id << " 的员工记录已成功修改。" << endl;
    }
    else {
        // 如果没找到匹配项，删除临时文件
        remove(tempFilename.c_str());
        cout << "未找到工号为 " << id << " 的员工记录。" << endl;
    }
}

void EmployeeProfile::updateProfileById(const string& filename)
{
    cout << "请输入工号：";
    updateProfileByI(filename, 1);
}

void EmployeeProfile::updateProfileByIdNumber(const string& filename)
{
    cout << "请输入身份证号：";
    updateProfileByI(filename, 3);
}

istream& operator>>(istream& in, EmployeeProfile& profile) {
    const int NAME_WIDTH = 15;
    const int INFO_WIDTH = 20;

    cout << "工号:";
    in >> profile.id;
    cout << "职工姓名:";
    in >> profile.name;
    cout << "身份证号:";
    in >> profile.idNumber;
    cout << "性别:";
    in >> profile.gender;
    cout << "年龄:";
    in >> profile.age;
    cout << "联系电话:";
    in >> profile.phoneNumber;
    cout << "家庭地址:";
    in >> profile.address;
    cout << "教育背景:";
    in >> profile.education;
    cout << "职位:";
    in >> profile.position;
    cout << "入职日期:";
    in >> profile.hireDate;
    cout << "所属部门:";
    in >> profile.department;

    return in;
}

ostream& operator<<(ostream& out, EmployeeProfile& profile)
{
    const int SHORT_WIDTH = 10; // 短列宽
    const int MIDDLE_WIDTH = 15; // 中列宽
    const int LONG_WIDTH = 20; // 长列宽
    const int LINE_LENGTH = 155; // 分割线长度


    // 分割线
    //out << string(SHORT_WIDTH + LONG_WIDTH * 7 + 3, '-') << endl;

    // 输出数据行
    out << left << setw(MIDDLE_WIDTH) << profile.id
        << setw(SHORT_WIDTH) << profile.name
        << setw(LONG_WIDTH) << profile.idNumber
        << setw(SHORT_WIDTH) << profile.gender
        << setw(SHORT_WIDTH) << profile.age
        << setw(MIDDLE_WIDTH) << profile.phoneNumber
        << setw(25) << profile.address
        << setw(SHORT_WIDTH) << profile.education
        << setw(MIDDLE_WIDTH) << profile.position
        << setw(MIDDLE_WIDTH) << profile.hireDate
        << setw(SHORT_WIDTH) << profile.department << endl;
    out << string(LINE_LENGTH, '-');
    return out;
}


// 构造函数定义
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

