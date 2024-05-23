//#include <easyx.h>
#include <string>
#include "EmployeeProfile.h"
#include <iostream>
#include <conio.h>
#include "User.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <iomanip>
#include "Constant.h"

using namespace std;
bool login();
void myRegister();
void menu();
void displayAllProfile();
void insertEmployeeProfile();
void updateEmployeeProfile();
void deleteEmployeeProfile();
void deleteEmployeeProfileById(string filename);
void deleteEmployeeProfileByIdNumber(string filename);
vector<EmployeeProfile> loadEmployeeProfiles(const string& filename);
EmployeeProfile createProfileFromLine(const std::string& line);
void tableTitle();
int main() {
	while (1) {

		cout << "  ��ӭʹ��ְ����������ϵͳ   " << endl;
		cout << "******************************" << endl;
		cout << "****                     *****" << endl;
		cout << "****       1. ��¼       *****" << endl;
		cout << "****       	         *****" << endl;
		cout << "****       2. ע��       *****" << endl;
		cout << "****       	         *****" << endl;
		cout << "******************************" << endl;

		char first;
		while (1) {
			
			first = _getch();
			if (first == '1') {
				system("cls");
				//cout << "  ��ӭ��¼ְ����������ϵͳ   " << endl;
				//// �����¼�ɹ�������������
				//if (login()) {
				//	menu();
				//	return 0;// TODO �д�����
				//}
				menu(); return 0;// ���д�����ڵ��ԣ�����ɾ��
				break;
			}
			else if (first == '2') {
				system("cls");
				cout << "  ��ӭע��ְ����������ϵͳ   " << endl;
				myRegister();
				break;
			}
			else if (first == 27) {
				cout << "�˳��ɹ���";
				return 0;
			}
			else {
				cout << "�밴1��2������ESC�����˳�ϵͳ��" << endl;
			}
			

		}

	}

	return 0;
}
bool login() {
	string name, password;
	string filename = USER_FILENAME;
	while (1) {
		cout << "�������û�����";
		cin >> name;
		// ����û����Ƿ����
		bool nameExists = User::isUsernameExists(name, filename);
		if (!nameExists) {
			cout << "�û��������ڣ�����ע��" << endl;
			return false;
		}
		cout << "���������룺";
		cin >> password;
		User user(name, password);
		if (user.isPasswordValid(filename)) {
			system("cls");
			cout << "��½�ɹ�" << endl;
			return true;
		}
		else {
			cout << "�û�����������������ԣ�" << endl;
		}

	}


}
void myRegister() {
	string name, password, confirmPassword;
	string filename = USER_FILENAME;
	while (1) {
		cout << "�������û�����";
		cin >> name;
		// ����û����Ƿ����
		bool nameExists = User::isUsernameExists(name, filename);
		if (nameExists) {
			cout << "�û����Ѵ��ڣ�����������" << endl;
		}
		else {
			break;
		}

	}


	while (1) {
		cout << "���������룺";
		cin >> password;
		cout << "���ٴ��������룺";
		cin >> confirmPassword;
		if (password != confirmPassword) {
			cout << "�������벻һ�£����������룡" << endl;
		}
		else {
			break;
		}
	}
	User user(name, password);
	system("cls");
	// �����û���Ϣ
	user.saveUserToFile(filename);

	cout << "ע��ɹ�" << endl;
}
void menu() {
	while (1) {
		cout << "     ��ӭʹ��ְ����������ϵͳ   " << endl;
		cout << "������������������������������������������������������������������������" << endl;
		cout << "|                                  |" << endl;
		cout << "|     1. ��ѯ����ְ��������Ϣ      |" << endl;
		cout << "|     2. ����ְ��������Ϣ          |" << endl;
		cout << "|     3. �޸�ְ��������Ϣ          |" << endl;
		cout << "|     4. ɾ��ְ��������Ϣ          |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "������������������������������������������������������������������������" << endl;

		//EmployeeProfile employee("����", "330112199001010010", "��", 33, "13800138000", "������������XX�ֵ�123��", "����", "�������ʦ", "2015-03-01", "�з���");
		//cout << employee;
		//EmployeeProfile e;
		//insert(e);
		//cin >> e;

		string filename = EMPLOYEE_FILENAME;

		char i;
		i = _getch();
		switch (i)
		{
		case '1':
			system("cls");
			displayAllProfile();
			break;
		case '2':
			system("cls");

			insertEmployeeProfile();
			break;
		case '3':
			system("cls");
			updateEmployeeProfile();
			break;
		case '4':
			system("cls");
			deleteEmployeeProfile();
			break;
		default:
			cout << "��������ȷ�����֣�" << endl;
			break;
		}
	}


}

void displayAllProfile() {
	string filename = EMPLOYEE_FILENAME;
	vector<EmployeeProfile> employeeProfiles = loadEmployeeProfiles(filename);
	// �����ͷ
	tableTitle();
	// ���ÿһ������
	for (EmployeeProfile& employeeProfile : employeeProfiles) {
		cout << employeeProfile << endl;
	}

	// �ȴ��û��������ⰴ��
	system("pause");
	system("cls");

}
void insertEmployeeProfile() {
	EmployeeProfile e;
	cin >> e;
	e.saveEmployeeToFile(EMPLOYEE_FILENAME);
}
void updateEmployeeProfile() {
	cout << "updateEmployeeProfile" << endl;
}

// ɾ��Ա��
void deleteEmployeeProfile() {
	while (1) {
		cout << "1.ͨ������ɾ�� 2.ͨ�����֤��ɾ��" << endl;
		char i = _getch();
		if (i == '1') {
			system("cls");
			deleteEmployeeProfileById(EMPLOYEE_FILENAME);
		}
		else if (i == '2') {
			system("cls");
			deleteEmployeeProfileByIdNumber(EMPLOYEE_FILENAME);
		}
		else {
			cout << "�밴1��2��" << endl;
		}
	}
}

// ͨ������ɾ��
void deleteEmployeeProfileById(string filename) {
	EmployeeProfile::deleteProfileById(filename);
}

// ͨ�����֤��ɾ��
void deleteEmployeeProfileByIdNumber(string filename) {
	EmployeeProfile::deleteProfileByIdNumber(filename);
}

// ���ļ��л�ȡÿһ�е����ݣ���������һ��EmployeeProfile��������
vector<EmployeeProfile> loadEmployeeProfiles(const string& filename) {
	vector<EmployeeProfile> profiles;
	ifstream inFile(filename);
	if (inFile.is_open()) {
		std::string line;
		while (std::getline(inFile, line)) {
			if (!line.empty()) { // ȷ���в�Ϊ��
				EmployeeProfile profile = createProfileFromLine(line);
				profiles.push_back(profile);
			}
		}
		inFile.close();
	}
	else {
		cerr << "�޷����ļ�: " << filename << std::endl;
	}
	return profiles;
}

// ��һ�������л�ȡÿ������ֵ��������EmployeeProfile����
EmployeeProfile createProfileFromLine(const std::string& line) {
	istringstream iss(line);
	// ���� EmployeeProfile �����ĳ�Ա����
	string id, name, idNumber, gender, ageStr, phoneNumber, address, education, position, hireDate, department;
	int age;
	// ÿ���е�ÿ�������Զ��ŷָ��������ַ���
	getline(iss, id, ',');
	getline(iss, name, ',');
	getline(iss, idNumber, ',');
	getline(iss, gender, ',');
	// ���������ȷ��ַ������ͣ���Ҫ�����ת��
	getline(iss, ageStr, ',');
	getline(iss, phoneNumber, ',');
	getline(iss, address, ',');
	getline(iss, education, ',');
	getline(iss, position, ',');
	getline(iss, hireDate, ',');
	getline(iss, department);
	// ���ַ���ageStrת��Ϊint����
	age = stoi(ageStr);
	// ���� EmployeeProfile ����
	return EmployeeProfile(id, name, idNumber, gender, age, phoneNumber, address, education, position, hireDate, department);
}

// ��ӡ��ͷ
void tableTitle() {
	const int SHORT_WIDTH = 10; // ���п�
	const int MIDDLE_WIDTH = 15; // ���п�
	const int LONG_WIDTH = 20; // ���п�
	const int LINE_LENGTH = 155; // �ָ��߳���

	// �����ͷ
	cout << left 
		<< setw(MIDDLE_WIDTH) << "����:"
		<< setw(SHORT_WIDTH) << "ְ������:"
		<< setw(LONG_WIDTH) << "���֤��:"
		<< setw(SHORT_WIDTH) << "�Ա�:"
		<< setw(SHORT_WIDTH) << "����:"
		<< setw(MIDDLE_WIDTH) << "��ϵ�绰:"
		<< setw(25) << "��ͥ��ַ:"
		<< setw(SHORT_WIDTH) << "ѧ��:"
		<< setw(MIDDLE_WIDTH) << "ְλ:"
		<< setw(MIDDLE_WIDTH) << "��ְ����:"
		<< setw(SHORT_WIDTH) << "��������:"
		<< endl;
	cout << string(LINE_LENGTH, '-') << endl;
}
