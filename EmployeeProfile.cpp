#include "EmployeeProfile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

//void EmployeeProfile::displayAllProfile()
//{
//    const int SHORT_WIDTH = 10; // ְ�������п�
//    const int MIDDLE_WIDTH = 15; // ְ�������п�
//    const int LONG_WIDTH = 20; // ������Ϣ�п�
//
//    // �����ͷ
//    cout << left << setw(SHORT_WIDTH) << "ְ������:"
//        << setw(LONG_WIDTH) << "���֤��:"
//        << setw(SHORT_WIDTH) << "�Ա�:"
//        << setw(SHORT_WIDTH) << "����:"
//        << setw(MIDDLE_WIDTH) << "��ϵ�绰:"
//        << setw(30) << "��ͥ��ַ:"
//        << setw(SHORT_WIDTH) << "ѧ��:"
//        << setw(MIDDLE_WIDTH) << "ְλ:"
//        << setw(MIDDLE_WIDTH) << "��ְ����:"
//        << setw(SHORT_WIDTH) << "��������:"
//        << endl;
//
//    // �ָ���
//    cout << string(SHORT_WIDTH + LONG_WIDTH * 7, '-') << endl;
//
//    // ���������
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
        std::cerr << "�޷����ļ�: " << filename << std::endl;
        return;
    }

    // �򵥵ؽ��û���������д���ļ����м�������ض��ָ����ֿ�������֮�����
    outFile << name << "," << idNumber << "," << gender << "," << age << "," 
        << phoneNumber << "," << address << "," << education <<
        "," << position << "," << hireDate << "," << department << std::endl;
    outFile.close();
    std::cout << "ְ�������ѱ�����: " << filename << std::endl;
}

istream& operator>>(istream& in, EmployeeProfile& profile) {
    const int NAME_WIDTH = 15;
    const int INFO_WIDTH = 20;

    cout << "ְ������:";
    in >> profile.name;
    cout << "���֤��:";
    in >> profile.idNumber;
    cout << "�Ա�:";
    in >> profile.gender;
    cout << "����:";
    in >> profile.age;
    cout << "��ϵ�绰:";
    in >> profile.phoneNumber;
    cout << "��ͥ��ַ:";
    in >> profile.address;
    cout << "��������:";
    in >> profile.education;
    cout << "ְλ:";
    in >> profile.position;
    cout << "��ְ����:";
    in >> profile.hireDate;
    cout << "��������:";
    in >> profile.department;

    return in;
}

ostream& operator<<(ostream& out, EmployeeProfile& profile)
{
    const int SHORT_WIDTH = 10; // ���п�
    const int MIDDLE_WIDTH = 15; // ���п�
    const int LONG_WIDTH = 20; // ���п�

    // �ָ���
    out << string(SHORT_WIDTH + LONG_WIDTH * 7, '-') << endl;

    // ���������
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

// ���캯������
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

