#pragma once
#include <string>

using namespace std;

class EmployeeProfile
{
private:
    // 成员变量
    string name;            // 姓名
    string idNumber;        // 身份证号
    string gender;          // 性别
    int age;                // 年龄
    string phoneNumber;     // 联系电话
    string address;         // 家庭地址
    string education;       // 学历
    string position;        // 职位
    string hireDate;        // 入职日期
    string department;      // 所属部门
public:
    EmployeeProfile() = default;
    // 构造函数
    EmployeeProfile(
        string name,
        string idNumber,
        string gender,
        int age,
        string phoneNumber,
        string address,
        string education,
        string position,
        string hireDate,
        string department
    );



    // ... 可以继续添加setter和getter等成员函数
    
   // 查询所有职工档案信息
   //void displayAllProfile();

    // 新增
    void insertProfile();

    // 通过身份证号删除
    void deleteProfileByIdNumber(string idNumer);

    // 修改信息
    void updateProfile();

    // 重载 >> 运算符的声明
    friend istream& operator>>(istream& in, EmployeeProfile& profile);

    // 重载 << 运算符的声明
    friend ostream& operator<<(ostream& out, EmployeeProfile& profile);

    // 将信息存入文件
    void saveEmployeeToFile(const string& filename);
};



