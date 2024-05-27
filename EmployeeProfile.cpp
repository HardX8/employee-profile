#include "EmployeeProfile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <sstream>

using namespace std;


// ͨ����i������ɾ��ְ��
void EmployeeProfile::deleteProfileByI(const string& filename, int i)
{
    string id;
    cin >> id;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "�޷����ļ���" << endl;
        return;
    }

    // ������ʱ�ļ��������޸ĺ������
    string tempFilename = "temp_" + filename;
    ofstream outFile(tempFilename);
    if (!outFile.is_open()) {
        cerr << "�޷�������ʱ�ļ���" << endl;
        inFile.close();
        return;
    }

    string line;
    // ����Ƿ��ҵ���ɾ����ָ���ļ�¼
    bool found = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentId;

        // ��ȡÿ�еĵ�i���ֶΣ����ţ�
        int tempI = i;
        while (tempI--) {
            getline(iss, currentId, ',');
        }


        if (currentId != id) {
            // �����ǰ�е����Բ���Ҫɾ�������ԣ���д����ʱ�ļ�
            outFile << line << endl;
        }
        else {
            // �ҵ���ƥ��Ĺ���
            found = true;
            // �˴������������������¿��Բ�����break��
            // �����������ְ��ʱ������ظ�����
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        // ����ҵ���ƥ������ԣ�ɾ��ԭ�ļ�
        remove(filename.c_str());
        // ����ʱ�ļ�������Ϊԭ�ļ���
        rename(tempFilename.c_str(), filename.c_str());
        cout << "����Ϊ " << id << " ��Ա����¼�ѳɹ�ɾ����" << endl;
    }
    else {
        // ���û�ҵ�ƥ���ɾ����ʱ�ļ�
        remove(tempFilename.c_str());
        cout << "δ�ҵ�����Ϊ " << id << " ��Ա����¼��" << endl;
    }
}

void EmployeeProfile::deleteProfileById(const string& filename)
{
    cout << "�����빤�ţ�";
    deleteProfileByI(filename, 1);
}

void EmployeeProfile::deleteProfileByIdNumber(const string& filename)
{
    cout << "���������֤�ţ�";
    deleteProfileByI(filename, 3);
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
    outFile << id << "," << name << "," << idNumber << "," << gender << "," << age << ","
        << phoneNumber << "," << address << "," << education <<
        "," << position << "," << hireDate << "," << department << std::endl;
    outFile.close();
    std::cout << "ְ�������ѱ�����: " << filename << std::endl;
}

istream& operator>>(istream& in, EmployeeProfile& profile) {
    const int NAME_WIDTH = 15;
    const int INFO_WIDTH = 20;

    cout << "����:";
    in >> profile.id;
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
    const int LINE_LENGTH = 155; // �ָ��߳���


    // �ָ���
    //out << string(SHORT_WIDTH + LONG_WIDTH * 7 + 3, '-') << endl;

    // ���������
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


// ���캯������
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

