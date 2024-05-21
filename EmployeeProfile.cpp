#include "EmployeeProfile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

//void EmployeeProfile::displayAllProfile()
//{
//    const int SHORT_WIDTH = 10; // 职工姓名列宽
//    const int MIDDLE_WIDTH = 15; // 职工姓名列宽
//    const int LONG_WIDTH = 20; // 其他信息列宽
//
//    // 输出表头
//    cout << left << setw(SHORT_WIDTH) << "职工姓名:"
//        << setw(LONG_WIDTH) << "身份证号:"
//        << setw(SHORT_WIDTH) << "性别:"
//        << setw(SHORT_WIDTH) << "年龄:"
//        << setw(MIDDLE_WIDTH) << "联系电话:"
//        << setw(30) << "家庭地址:"
//        << setw(SHORT_WIDTH) << "学历:"
//        << setw(MIDDLE_WIDTH) << "职位:"
//        << setw(MIDDLE_WIDTH) << "入职日期:"
//        << setw(SHORT_WIDTH) << "所属部门:"
//        << endl;
//
//    // 分割线
//    cout << string(SHORT_WIDTH + LONG_WIDTH * 7, '-') << endl;
//
//    // 输出数据行
//    cout << left << setw(SHORT_WIDTH) << name
//        << setw(LONG_WIDTH) << idNumber
//        << setw(SHORT_WIDTH) << gender
//        << setw(SHORT_WIDTH) << age
//        << setw(MIDDLE_WIDTH) << phoneNumber
//        << setw(30) << address
//        << setw(SHORT_WIDTH) << education
//        << setw(MIDDLE_WIDTH) << position
//        << setw(MIDDLE_WIDTH) << hireDate
//        << setw(SHORT_WIDTH) << department
//        << endl;
//}

void EmployeeProfile::insertProfile()
{

}

void EmployeeProfile::deleteProfileByIdNumber(string idNumer)
{
}

void EmployeeProfile::updateProfile()
{
}

void EmployeeProfile::saveEmployeeToFile(const string& filename)
{
    std::ofstream outFile(filename, std::ios_base::app);
    if (!outFile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    // 简单地将用户名和密码写入文件，中间可以用特定分隔符分开，便于之后解析
    outFile << name << "," << idNumber << "," << gender << "," << age << "," 
        << phoneNumber << "," << address << "," << education <<
        "," << position << "," << hireDate << "," << department << std::endl;
    outFile.close();
    std::cout << "职工数据已保存至: " << filename << std::endl;
}

istream& operator>>(istream& in, EmployeeProfile& profile) {
    const int NAME_WIDTH = 15;
    const int INFO_WIDTH = 20;

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

    // 分割线
    out << string(SHORT_WIDTH + LONG_WIDTH * 7, '-') << endl;

    // 输出数据行
    out << left << setw(SHORT_WIDTH) << profile.name
        << setw(LONG_WIDTH) << profile.idNumber
        << setw(SHORT_WIDTH) << profile.gender
        << setw(SHORT_WIDTH) << profile.age
        << setw(MIDDLE_WIDTH) << profile.phoneNumber
        << setw(30) << profile.address
        << setw(SHORT_WIDTH) << profile.education
        << setw(MIDDLE_WIDTH) << profile.position
        << setw(MIDDLE_WIDTH) << profile.hireDate
        << setw(SHORT_WIDTH) << profile.department;

    return out;
}

// 构造函数定义
EmployeeProfile::EmployeeProfile(
    string n,
    string id,
    string g,
    int a,
    string p,
    string addr,
    string e,
    string pos,
    string hd,
    string dep
) :
    name(n),
    idNumber(id),
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

