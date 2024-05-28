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
    // 通过第i项内容查询并更新
    static void updateProfileByI(const string& filename, int i);

public:
    // 无参构造函数
    EmployeeProfile() = default;
    // 有参构造函数
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

    // 成员变量对应的get函数
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


    // 重载 >> 运算符
    friend istream& operator>>(istream& in, EmployeeProfile& profile);

    // 重载 << 运算符
    friend ostream& operator<<(ostream& out, EmployeeProfile& profile);

    // 将信息存入文件
    void saveEmployeeToFile(const string& filename);

    // ---------------------------static---------------------------

    // 通过工号删除
    static void deleteProfileById(const string& filename);

    // 通过身份证号删除
    static void deleteProfileByIdNumber(const string& filenamef);

    // 根据工号更新职工
    static void updateProfileById(const string& filename);

    // 根据身份证号更新职工
    static void updateProfileByIdNumber(const string& filename);

    // 判断某个成员变量是否存在，i表示要查询的成员变量的序号
    static bool isPropertyExists(const string& property, const string& filename, const int i);


};



