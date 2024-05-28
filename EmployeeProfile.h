#pragma once
#include <string>

using namespace std;

class EmployeeProfile
{
private:
    // ��Ա����
    string id;              // ����
    string name;            // ����
    string idNumber;        // ���֤��
    string gender;          // �Ա�
    int age;                // ����
    string phoneNumber;     // ��ϵ�绰
    string address;         // ��ͥ��ַ
    string education;       // ѧ��
    string position;        // ְλ
    string hireDate;        // ��ְ����
    string department;      // ��������

    // ͨ����i������ɾ��
    static void deleteProfileByI(const string& filename, int i);
    // ͨ����i�����ݲ�ѯ������
    static void updateProfileByI(const string& filename, int i);

public:
    // �޲ι��캯��
    EmployeeProfile() = default;
    // �вι��캯��
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

    // ��Ա������Ӧ��get����
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


    // ���� >> �����
    friend istream& operator>>(istream& in, EmployeeProfile& profile);

    // ���� << �����
    friend ostream& operator<<(ostream& out, EmployeeProfile& profile);

    // ����Ϣ�����ļ�
    void saveEmployeeToFile(const string& filename);

    // ---------------------------static---------------------------

    // ͨ������ɾ��
    static void deleteProfileById(const string& filename);

    // ͨ�����֤��ɾ��
    static void deleteProfileByIdNumber(const string& filenamef);

    // ���ݹ��Ÿ���ְ��
    static void updateProfileById(const string& filename);

    // �������֤�Ÿ���ְ��
    static void updateProfileByIdNumber(const string& filename);

    // �ж�ĳ����Ա�����Ƿ���ڣ�i��ʾҪ��ѯ�ĳ�Ա���������
    static bool isPropertyExists(const string& property, const string& filename, const int i);


};



