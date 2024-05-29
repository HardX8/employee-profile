#include "EmployeeProfile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <vector>
#include "Constant.h"
//#include <regex>
#include <ctime>

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

        // ��ȡÿ�еĵ�i���ֶ�
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
            // �˴�����break�Ļ��ᵼ��Ҫɾ��ְ�������ְ��û��д�����ļ�
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        // ����ҵ���ƥ������ԣ�ɾ��ԭ�ļ�
        remove(filename.c_str());
        // ����ʱ�ļ�������Ϊԭ�ļ���
        rename(tempFilename.c_str(), filename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << "����Ϊ " << id << " ��Ա����¼�ѳɹ�ɾ����" << endl;
        }
        else {
            cout << "���֤Ϊ " << id << " ��Ա����¼�ѳɹ�ɾ����" << endl;
        }
    }
    else {
        // ���û�ҵ�ƥ���ɾ����ʱ�ļ�
        remove(tempFilename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << "δ�ҵ�����Ϊ " << id << " ��Ա����¼��" << endl;
        }
        else {
            cout << "δ�ҵ����֤��Ϊ " << id << " ��Ա����¼��" << endl;
        }
    }
}

// ͨ������ɾ��
void EmployeeProfile::deleteProfileById(const string& filename)
{
    cout << "�����빤�ţ�";
    deleteProfileByI(filename, EMPLOYEE_ID_SERIAL_NUMBER);
}

// ͨ�����֤��ɾ��
void EmployeeProfile::deleteProfileByIdNumber(const string& filename)
{
    cout << "���������֤�ţ�";
    deleteProfileByI(filename, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER);
}

// ����Ϣ�����ļ�
void EmployeeProfile::saveEmployeeToFile(const string& filename)
{
    ofstream outFile(filename, ios_base::app);
    if (!outFile.is_open()) {
        cerr << "�޷����ļ�: " << filename << endl;
        return;
    }

    // �ڴ��ٴ��жϣ�������Ŵ����򲻱��浽�ļ���
    if (EmployeeProfile::isPropertyExists(id, EMPLOYEE_FILENAME, EMPLOYEE_ID_SERIAL_NUMBER)) {
        return;
    }
    // �ڴ��ٴ��жϣ�������֤�Ŵ����򲻱��浽�ļ���
    if (EmployeeProfile::isPropertyExists(idNumber, EMPLOYEE_FILENAME, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER)) {
        return;
    }

    // ��ְ����Ϣд���ļ����м��ö��ŷֿ�������֮�����
    outFile << id << "," << name << "," << idNumber << "," << gender << "," << age << ","
        << phoneNumber << "," << address << "," << education <<
        "," << position << "," << hireDate << "," << department << endl;
    outFile.close();
    cout << "ְ�������ѱ�����: " << filename << endl;
}

// ͨ����i�����ݲ�ѯ������
void EmployeeProfile::updateProfileByI(const string& filename, int i)
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
    // ����Ƿ��ҵ����޸���ָ���ļ�¼
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
            // �����ǰ�е����Բ���Ҫ�޸ĵ����ԣ���д����ʱ�ļ�
            outFile << line << endl;
        }
        else {
            // �ҵ���ƥ��Ĺ���
            found = true;
            // �˴�����break�Ļ��ᵼ��Ҫɾ��ְ�������ְ��û��д�����ļ�
            
            // ʹ��vector����̬�洢�ָ����ַ���
            vector<string> employeeVector;
            stringstream ss(line);
            string item;

            // ʹ��getline�����ŷָ��ַ�����ֱ����ȡ������Ԫ��
            while (getline(ss, item, ',')) {
                // ���ָ�õ���Ԫ����ӵ�vector��
                employeeVector.push_back(item);
            }

            string newE;
            for (int j = 0; j < employeeVector.size(); j++) {
                if (j == 0) {
                    cout << "���س�������������\n\n��ֵ��" << employeeVector[0] << endl << "�����޸�" << endl << endl;
                    j++;
                    // ������뻺����
                    cin.ignore();
                }
                cout << "��ֵ��" << employeeVector[j] << endl << "��ֵ��";
                // ��ȡ�û�������ַ�
                char input = cin.get(); 
                // ������ǻس���
                if (input != '\n') { 
                    // ����ȡ���ַ��Ż�������
                    cin.unget(); 
                    // �����������
                    cin >> newE; 
                    if (j == EMPLOYEE_ID_NUMBER_SERIAL_NUMBER - 1) {
                        while (1) {
                            // �����ʽ��������������
                            if (!regex_match(newE, idNumberPattern)) {
                                cout << "���֤�Ÿ�ʽ����\n�������������֤�ţ�";
                                cin >> newE;
                                continue;
                            }
                            // ���֤���Ѵ���
                            if (EmployeeProfile::isPropertyExists(newE, EMPLOYEE_FILENAME, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER)) {
                                cout << "���֤���Ѵ��ڣ�\n�������������֤�ţ�";
                                cin >> newE;
                            }
                            else {
                                break;
                            }
                        }
                    }
                    if (j == EMPLOYEE_PHONE_SERIAL_NUMBER - 1) {
                        while (1) {
                            // �����ʽ��������������
                            if (!verifyPhone(newE)){
                                cout << "�����������ֻ��ţ�";
                                cin >> newE;
                                continue;
                            }
                            // ���֤���Ѵ���
                            if (EmployeeProfile::isPropertyExists(newE, EMPLOYEE_FILENAME, EMPLOYEE_PHONE_SERIAL_NUMBER)) {
                                cout << "�ֻ����Ѵ��ڣ�\n�����������ֻ��ţ�";
                                cin >> newE;
                            }
                            else {
                                break;
                            }
                        }
                    }
                    // ��������
                    employeeVector[j] = newE;
                    // ������뻺����
                    cin.ignore();
                    cout << endl;
                }
                else {
                    cout << endl;
                }
            }
            // ƴ���µ�ְ����Ϣ
            string newLine = "";
            for (int j = 0; j < employeeVector.size(); j++) {
                newLine += employeeVector[j] + ",";
            }
            // д���ļ�
            outFile << newLine << endl;
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        // ����ҵ���ƥ������ԣ�ɾ��ԭ�ļ�
        remove(filename.c_str());
        // ����ʱ�ļ�������Ϊԭ�ļ���
        rename(tempFilename.c_str(), filename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << "����Ϊ " << id << " ��Ա����¼�ѳɹ��޸ġ�" << endl;
        }
        else {
            cout << "���֤��Ϊ " << id << " ��Ա����¼�ѳɹ��޸ġ�" << endl;
        }
    }
    else {
        // ���û�ҵ�ƥ���ɾ����ʱ�ļ�
        remove(tempFilename.c_str());
        if (i == EMPLOYEE_ID_SERIAL_NUMBER) {
            cout << "δ�ҵ�����Ϊ " << id << " ��Ա����¼��" << endl;
        }
        else {
            cout << "δ�ҵ����֤��Ϊ " << id << " ��Ա����¼��" << endl;
        }
    }
}

// ���ݹ��Ÿ���ְ��phonePattern
void EmployeeProfile::updateProfileById(const string& filename)
{
    cout << "�����빤�ţ�";
    updateProfileByI(filename, EMPLOYEE_ID_SERIAL_NUMBER);
}

// �������֤�Ÿ���ְ��
void EmployeeProfile::updateProfileByIdNumber(const string& filename)
{
    cout << "���������֤�ţ�";
    updateProfileByI(filename, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER);
}

// �ж�ĳ����Ա�����Ƿ���ڣ�i��ʾҪ��ѯ�ĳ�Ա���������
bool EmployeeProfile::isPropertyExists(const string& property, const string& filename, const int i)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "�޷����ļ�: " << filename << endl;
        // �ļ������ڻ��޷��򿪣���Ϊ�û���������
        return false; 
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string currentProperty;

        // ��ȡÿ�еĵ�i���ֶ�
        int tempI = i;
        while (tempI--) {
            getline(iss, currentProperty, ',');
        }
        if (currentProperty == property && i == EMPLOYEE_ID_SERIAL_NUMBER) {
            inFile.close();
            return true;
        }
        else if(currentProperty == property && i == EMPLOYEE_ID_NUMBER_SERIAL_NUMBER) {
            inFile.close();
            return true;
        }
        else if (currentProperty == property && i == EMPLOYEE_PHONE_SERIAL_NUMBER) {
            inFile.close();
            return true;
        }
    }
    inFile.close();
    // ��ȡ�������У�δ�ҵ�ƥ��Ĺ���
    return false;
}

// ��֤�ֻ����Ƿ���ȷ
bool EmployeeProfile::verifyPhone(string phone) {
    // ����ֻ��Ÿ�ʽ����ȷ
    if (!regex_match(phone, phonePattern)) {
        cout << "�ֻ��Ÿ�ʽ����" << endl;
        return false;
    }
}

// ���� >> �����
istream& operator>>(istream& in, EmployeeProfile& profile) {
    while (1) {
        cout << "����(����Ϊ10λ,ǰ��λ����1956~��ǰ���֮��):";
        in >> profile.id;
        // �����ʽ��������������
        if (profile.id.size() == 10) {
            // ��ȡǰ��λ
            string yearStr = profile.id.substr(0, 4);
            // ת��Ϊint
            int yearInt = stoi(yearStr);

            // ��ȡ��ǰʱ��
            time_t now = time(0);
            // ����һ��tm�ṹ�����������ת�����ʱ��
            tm localTimeStruct;
            // ʹ��localtime_s���а�ȫ��ת��
            localtime_s(&localTimeStruct, &now);
            // ��ȡ��ݣ�tm_year�Ǵ�1900�꿪ʼ�ģ�������Ҫ��1900
            int currentYear = localTimeStruct.tm_year + 1900;

            if (yearInt < 1956 || yearInt > currentYear) {
                cout << "���Ÿ�ʽ����" << endl;
                continue;
            }
        }
        else {
            cout << "���Ÿ�ʽ����" << endl;
            continue;
        }
        // �����Ѵ���
        if (EmployeeProfile::isPropertyExists(profile.id, EMPLOYEE_FILENAME, EMPLOYEE_ID_SERIAL_NUMBER)) {
            cout << "�����Ѵ��ڣ�" << endl;
        }
        else {
            break;
        }
    }

    cout << "ְ������:";
    in >> profile.name;

    while (1) {
        cout << "���֤��:";
        in >> profile.idNumber;
        // �����ʽ��������������
        if (!regex_match(profile.idNumber, idNumberPattern)) {
            cout << "���֤�Ÿ�ʽ����" << endl;
            continue;
        }
        // ���֤���Ѵ���
        if (EmployeeProfile::isPropertyExists(profile.idNumber, EMPLOYEE_FILENAME, EMPLOYEE_ID_NUMBER_SERIAL_NUMBER)) {
            cout << "���֤���Ѵ��ڣ�" << endl;
        }
        else {
            break;
        }
    }

    cout << "�Ա�:";
    in >> profile.gender;
    cout << "����:";
    in >> profile.age;

    while (1) {
        cout << "��ϵ�绰:";
        in >> profile.phoneNumber;
        // �����ʽ��������������
        if (!EmployeeProfile::verifyPhone(profile.phoneNumber)) {
            continue;
        }
        // ���֤���Ѵ���
        if (EmployeeProfile::isPropertyExists(profile.phoneNumber, EMPLOYEE_FILENAME, EMPLOYEE_PHONE_SERIAL_NUMBER)) {
            cout << "�ֻ����Ѵ��ڣ�" << endl;
        }
        else {
            break;
        }
    }


    cout << "��ͥ��ַ:";
    in >> profile.address;
    cout << "ѧ��:";
    in >> profile.education;
    cout << "ְλ:";
    in >> profile.position;
    cout << "��ְ����:";
    in >> profile.hireDate;
    cout << "��������:";
    in >> profile.department;

    return in;
}

// ���� << �����
ostream& operator<<(ostream& out, EmployeeProfile& profile)
{
    const int SHORT_WIDTH = 10; // ���п�
    const int MIDDLE_WIDTH = 15; // ���п�
    const int LONG_WIDTH = 20; // ���п�
    const int LINE_LENGTH = 155; // �ָ��߳���

    // ���������
    out << left << setw(MIDDLE_WIDTH) << profile.id
        << setw(SHORT_WIDTH) << profile.name
        << setw(LONG_WIDTH) << profile.idNumber
        << setw(SHORT_WIDTH) << profile.gender
        << setw(SHORT_WIDTH) << profile.age
        << setw(MIDDLE_WIDTH) << profile.phoneNumber
        << setw(LONG_WIDTH) << profile.address
        << setw(SHORT_WIDTH) << profile.education
        << setw(MIDDLE_WIDTH) << profile.position
        << setw(MIDDLE_WIDTH) << profile.hireDate
        << setw(MIDDLE_WIDTH) << profile.department << endl;
    out << string(LINE_LENGTH, '-');
    return out;
}


// �вι��캯������
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

// ��Ա������Ӧ��get����
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

