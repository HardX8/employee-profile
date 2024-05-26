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
#include <algorithm>
#include <cctype>

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
				std::system("cls");
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
				std::system("cls");
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
			std::system("cls");
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
	std::system("cls");
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
		case 27:
			std::system("cls");
			// TODO ��һ��ȷ��ѡ��
			main();
			break;
		case '1':
			std::system("cls");
			displayAllProfile();
			break;
		case '2':
			std::system("cls");

			insertEmployeeProfile();
			break;
		case '3':
			std::system("cls");
			updateEmployeeProfile();
			break;
		case '4':
			std::system("cls");
			deleteEmployeeProfile();
			break;
		default:
		std:system("cls");
			cout << KEY_ERROR << endl;
			break;
		}
	}


}

// ��ʾ����ְ����Ϣ�����ṩ������
void displayAllProfile() {
	vector<EmployeeProfile> employeeProfiles = loadEmployeeProfiles(EMPLOYEE_FILENAME);

	//cout << "1.���������� 2.�����Ž��� 3.���������� 4.�����併�� 5.����ְʱ������ 6.����ְʱ�併�� ���ఴ��Ĭ�ϲ�ѯ";

	bool flag = true;
	// �����ݽ��д���
	//char i;
	//i = _getch();
	while (flag) {

		cout << "\t\t\t1.���������� 2.�����Ž��� 3.���������� 4.�����併��"
			"5.����ְʱ������ 6.����ְʱ�併�� 7.ǰ��ҳ�� ESC���˳� ���ఴ���ظ���ǰ��ѯ" << endl << endl;
		// �����ͷ
		tableTitle();

		int startRow = pageNum > 0 ? (pageNum - 1) * pageSize : 0;
		int endRow = startRow + pageSize * (pageNum > 0 ? 1 : 0);
		int total = employeeProfiles.size();
		int sumNum = total / pageSize + 1;

		// ���ÿһ������
		for (int i = startRow; i < endRow && i < total; i++) {
			cout << employeeProfiles[i] << endl;
		}
		cout << "��ǰҳ��" << pageNum << "/" << sumNum << endl
			<< "�ܹ���" << total;

		// �ȴ��û��������ⰴ��
		//std::system("pause");
		int i = _getch();
		std::system("cls");

		switch (i) {
		case '1':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				return a.getId() < b.getId();
				});
			break;
		case '2':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				return a.getId() > b.getId();
				});
			break;
		case '3':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				return a.getAge() < b.getAge();
				});
			break;
		case '4':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				return a.getAge() > b.getAge();
				});
			break;
		case '5':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				return a.getHireDate() < b.getHireDate();
				});
			break;
		case '6':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				return a.getHireDate() > b.getHireDate();
				});
			break;
		case '7': {
			cout << "������ҳ�룺";
			string inputStr;

			cin >> inputStr;
			try {
				int input = stoi(inputStr);
				if (input < 0) {
					pageNum = 1;
				}
				else if (input > sumNum) {
					pageNum = sumNum;
				}
				else {
					pageNum = input;
				}
			}
			catch (const invalid_argument& e) {
				// �������벻�����ֵ��쳣
				cerr << "���������֣�" << endl;
			}
			catch (const out_of_range& e) { // ת��������ֳ���int��Χ
				cerr << "����̫�󣬳���������ķ�Χ��" << endl;
			}
			break;
		}
		case 27: // ESC��
			std::system("cls");
			flag = false;
			break;
		case 77: // �Ҽ�
			std::system("cls");
			if (pageNum <= total / pageSize) {
				pageNum++;
			}
			break;
		case 75: // ���
			std::system("cls");
			if (pageNum > 1) {
				pageNum--;
			}
			break;
		default:
			std::system("cls");
			cout << KEY_ERROR << endl;
		}

	}
}

// ����ְ��
void insertEmployeeProfile() {
	EmployeeProfile e;
	cin >> e;
	e.saveEmployeeToFile(EMPLOYEE_FILENAME);
}

// �޸�ְ����Ϣ
void updateEmployeeProfile() {
	cout << "updateEmployeeProfile" << endl;
}

// ɾ��Ա��
void deleteEmployeeProfile() {
	while (1) {
		cout << "1.ͨ������ɾ�� 2.ͨ�����֤��ɾ�� ESC���˳�" << endl;
		char i = _getch();
		if (i == '1') {
			std::system("cls");
			deleteEmployeeProfileById(EMPLOYEE_FILENAME);
		}
		else if (i == '2') {
			std::system("cls");
			deleteEmployeeProfileByIdNumber(EMPLOYEE_FILENAME);
		}
		else if (i == 27) {
			std::system("cls");
			break;
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
