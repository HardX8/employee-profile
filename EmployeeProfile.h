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
public:
    EmployeeProfile() = default;
    // ���캯��
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

    int getAge();

    string getHireDate();

   // ��ѯ����ְ��������Ϣ
   //void displayAllProfile();

    // ����
    void insertProfile();

    // ͨ������ɾ��
    static void deleteProfileById(const string& filename);

    // ͨ�����֤��ɾ��
    static void deleteProfileByIdNumber(const string& filenamef);

    // �޸���Ϣ
    void updateProfile();

    // ���� >> �����������
    friend istream& operator>>(istream& in, EmployeeProfile& profile);

    // ���� << �����������
    friend ostream& operator<<(ostream& out, EmployeeProfile& profile);

    // ����Ϣ�����ļ�
    void saveEmployeeToFile(const string& filename);
};



