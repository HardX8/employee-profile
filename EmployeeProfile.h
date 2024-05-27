#pragma once
#include <string>

using namespace std;

class EmployeeProfile
{
private:
    // 成员变量
    string id;              // 工号
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
    // 通过第i项内容删除
    static void deleteProfileByI(const string& filename, int i);
public:
    EmployeeProfile() = default;
    // 构造函数
    EmployeeProfile(
        string id,
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

    string getId();
    string getName();
    string getIdNumber();
    string getGender();
    int getAge();
    string getPhoneNumber();
    string getAddress();
    string getEducation();
    string getPosition();
    string getHireDate();
    string getDepartment();




    // 通过工号删除
    static void deleteProfileById(const string& filename);

    // 通过身份证号删除
    static void deleteProfileByIdNumber(const string& filenamef);

    // 修改信息
    void updateProfile();

    // 重载 >> 运算符的声明
    friend istream& operator>>(istream& in, EmployeeProfile& profile);

    // 重载 << 运算符的声明
    friend ostream& operator<<(ostream& out, EmployeeProfile& profile);

    // 将信息存入文件
    void saveEmployeeToFile(const string& filename);
};



