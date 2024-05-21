#pragma once
#include <string>

using namespace std;

class EmployeeProfile
{
private:
    // ��Ա����
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
public:
    EmployeeProfile() = default;
    // ���캯��
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



    // ... ���Լ������setter��getter�ȳ�Ա����
    
   // ��ѯ����ְ��������Ϣ
   //void displayAllProfile();

    // ����
    void insertProfile();

    // ͨ�����֤��ɾ��
    void deleteProfileByIdNumber(string idNumer);

    // �޸���Ϣ
    void updateProfile();

    // ���� >> �����������
    friend istream& operator>>(istream& in, EmployeeProfile& profile);

    // ���� << �����������
    friend ostream& operator<<(ostream& out, EmployeeProfile& profile);

    // ����Ϣ�����ļ�
    void saveEmployeeToFile(const string& filename);
};



