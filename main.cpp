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
#include <regex>
#include <functional>
#include <chrono>

using namespace std;

/**
 * @author XZH
 */
bool login();
void myRegister();
void forgetPassword();
void menu();
void displayAllProfile();
void insertEmployeeProfile();
void updateEmployeeProfile(string filename);
void updateEmployeeProfileById(string filename);
void updateEmployeeProfileByIdNumber(string filename);
void deleteEmployeeProfile();
void deleteEmployeeProfileById(string filename);
void deleteEmployeeProfileByIdNumber(string filename);
void fuzzyQuery(vector<EmployeeProfile> employeeProfiles);
vector<EmployeeProfile> loadEmployeeProfiles(const string& filename);
EmployeeProfile createProfileFromLine(const std::string& line);
void fullScreen();
void closeBlackWindow();
void tableTitle();
int main() {
	while (1) {
		// ���úڴ��ڱ���
		SetConsoleTitleA("ְ����������ϵͳ-XZH");
		// ���úڴ��ں�������ɫ
		system("color f0");
		// ��ʾ����
		system("date /T");
		// ��ʾʱ��
		system("TIME /T");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ
		cout << "  ��ӭʹ��ְ����������ϵͳ   " << endl;
		cout << "********************************" << endl;
		cout << "****                       *****" << endl;
		cout << "****       1. ��¼         *****" << endl;
		cout << "****       	           *****" << endl;
		cout << "****       2. ע��         *****" << endl;
		cout << "****       	           *****" << endl;
		cout << "****       3. ��������	   *****" << endl;
		cout << "****       	           *****" << endl;
		cout << "****       ESC.�˳�ϵͳ    *****" << endl;
		cout << "****       	           *****" << endl;
		cout << "********************************" << endl;

		char first;

		first = _getch();
		switch (first) {
		case '1':
			std::system("cls");
			cout << "  ��ӭ��¼ְ����������ϵͳ   " << endl;
			// �����¼�ɹ�������������
			if (login()) {
				// ���úڴ��ں�������ɫ
				system("color 0B");
				menu();
				return 0;
			}
			//menu(); return 0;// ���д�����ڵ��ԣ�����ɾ��
			break;
		case '2':
			std::system("cls");
			cout << "  ��ӭע��ְ����������ϵͳ   " << endl;
			myRegister();
			break;
		case '3':
			std::system("cls");
			cout << "  ��������   " << endl;
			forgetPassword();
			break;
		case 27:
			cout << "�Ƿ��˳�" << endl << "1.ȷ��2.ȡ��";
			if (_getch() == '1') {
				cout << "\n�˳��ɹ���" << endl;
				closeBlackWindow();
				// ��return 0 �Ļ���meun()�е���main()֮�󻹻���ִ��meun()
				exit(0);
			}
			std::system("cls");
			break;
		default:
			system("cls");
			cout << KEY_ERROR << endl;
		}

	}

	return 0;
}

// ��¼
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
		password = User::inputPassword();
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

// ע��
void myRegister() {
	string name, password, confirmPassword, phone;
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
		cout << "�������ֻ��ţ�";
		cin >> phone;

		// ����ֻ��Ÿ�ʽ����ȷ
		if (!EmployeeProfile::verifyPhone(phone)) {
			continue;
		}

		// ����ֻ����Ƿ����
		bool phoneExists = User::isPhoneExists(phone, filename);
		if (phoneExists) {
			cout << "�ֻ����Ѵ��ڣ�����������" << endl;
		}
		else {
			break;
		}
	}

	while (1) {
		cout << "���������룺";
		password = User::inputPassword();
		cout << "���ٴ��������룺";
		confirmPassword = User::inputPassword();
		if (password != confirmPassword) {
			cout << "�������벻һ�£����������룡" << endl;
		}
		else {
			break;
		}
	}

	User user(name, password, phone);
	std::system("cls");
	// �����û���Ϣ
	user.saveUserToFile(filename);

	cout << "ע��ɹ�" << endl;
}

// ��������
void forgetPassword() {
	string phone, code, VerificationCode;
	chrono::high_resolution_clock::time_point startTime, endTime;

	while (1) {
		cout << "�������ֻ��ţ�";
		cin >> phone;
		if (!EmployeeProfile::verifyPhone(phone)) {
			continue;
		}
		sendVerificationCode:
		VerificationCode = User::findPhoneAndSendVerificationCode(phone, USER_FILENAME);
		// ��¼��ʼʱ��
		startTime = chrono::high_resolution_clock::now();

		if (VerificationCode != "") {
			break;
		}
	}
	cout << "��������֤�룺";
	while (1) {
		cin >> code;
		// ��¼����ʱ��
		endTime = chrono::high_resolution_clock::now();

		if (chrono::duration_cast<chrono::seconds>(endTime - startTime).count() > 60) {
			cout << "����60�룬������ʱ" << endl << "���س������·���" << endl;
			int i = _getch();
			if (i == 13) {
				goto sendVerificationCode;
			}
			break;
		}

		if (VerificationCode == code) {
			User::updateUserByPhone(USER_FILENAME, phone);
			break;	
		}
		cout << "��֤��������������룺";
	}
}

// ���ܲ˵�
void menu() {
	while (1) {
		cout << "     ��ӭʹ��ְ����������ϵͳ   " << endl;
		cout << "������������������������������������������������������������������������" << endl;
		cout << "|                                  |" << endl;
		cout << "|     1. ��ѯְ��������Ϣ          |" << endl;
		cout << "|     2. ����ְ��������Ϣ          |" << endl;
		cout << "|     3. �޸�ְ��������Ϣ          |" << endl;
		cout << "|     4. ɾ��ְ��������Ϣ          |" << endl;
		cout << "|     ESC.�˳���¼                 |" << endl;
		cout << "|                                  |" << endl;
		cout << "������������������������������������������������������������������������" << endl;

		string filename = EMPLOYEE_FILENAME;

		char i;
		i = _getch();
		switch (i)
		{
		case 27:
			cout << "�Ƿ��˳�" << endl << "1.ȷ��2.ȡ��";
			if (_getch() == '1') {
				std::system("cls");
				main();
			}
			std::system("cls");
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
			updateEmployeeProfile(filename);
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

// ��ʾ����ְ����Ϣ�����ṩ����ģ����ѯ�ȹ���
void displayAllProfile() {
	// �������
	fullScreen();

	vector<EmployeeProfile> employeeProfiles = loadEmployeeProfiles(EMPLOYEE_FILENAME);

	bool flag = true;

	while (flag) {

		cout << "\t    1.���������� 2.�����Ž��� 3.���������� 4.�����併��"
			"5.����ְʱ������ 6.����ְʱ�併�� 7.ǰ��ҳ�� 8.����ÿҳչʾ�� 9.ģ����ѯ ESC���˳�" << endl << endl;
		// �����ͷ
		tableTitle();

		int startRow = pageNum > 0 ? (pageNum - 1) * pageSize : 0;
		int endRow = startRow + pageSize * (pageNum > 0 ? 1 : 0);
		int total = employeeProfiles.size();
		// �������֮������ȡ��
		int sumNum = static_cast<int>(ceil(static_cast<double>(total) / pageSize));

		// ���ÿһ������
		for (int i = startRow; i < endRow && i < total; i++) {
			cout << employeeProfiles[i] << endl;
		}
		cout << "\n��ǰҳ��" << pageNum << "/" << sumNum << "\t" << pageSize << "/ҳ" <<
			"\t����A/��\t���ң�D/��" << endl
			<< "��ְ������" << total;

		int i = _getch();

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
			cout << "\n������ҳ�룺";
			string inputStr;
			cin >> inputStr;

			std::system("cls");
			try {
				// ��������Ƿ����ת���ڷ�Χ�ڵ�����
				int input = stoi(inputStr);
				// �������ҳ��С�ڵ���0��Ϊ��һҳ
				if (input <= 0) {
					pageNum = 1;
				}
				// ����������ҳ����Ϊ���һҳ
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
			catch (const out_of_range& e) {
				// ת��������ֳ���int��Χ
				cerr << "����̫�󣬳���������ķ�Χ��" << endl;
			}
			break;
		}
		case '8':
			cout << "\n������ÿҳչʾ����";
			cin >> pageSize;
			std::system("cls");
			// �ص���һҳ
			pageNum = 1;
			break;
		case '9':
			fuzzyQuery(employeeProfiles);
			std::system("pause");
			std::system("cls");
			break;
		case 27: // ESC��
			std::system("cls");
			flag = false;
			break;
		case 77: // �Ҽ�
			std::system("cls");
			if (pageNum < sumNum) {
				pageNum++;
			}
			break;
		case 100: // D��
			std::system("cls");
			if (pageNum < sumNum) {
				pageNum++;
			}
			break;
		case 75: // ���
			std::system("cls");
			if (pageNum > 1) {
				pageNum--;
			}
			break;
		case 97: // A��
			std::system("cls");
			if (pageNum > 1) {
				pageNum--;
			}
			break;
		default:
			std::system("cls");
			//cout << i;
			cout << KEY_ERROR << endl;
		}
	}
	// ����Ϊ��һҳ
	pageNum = PAGE_NUM;
	// ����ÿҳչʾ��
	pageSize = PAGE_SIZE;
}

// ����ְ��
void insertEmployeeProfile() {
	EmployeeProfile e;
	cin >> e;
	e.saveEmployeeToFile(EMPLOYEE_FILENAME);
}

// �޸�ְ����Ϣ
void updateEmployeeProfile(string filename) {
	while (1) {
		cout << "1.ͨ�����Ų�ѯְ�� 2.ͨ�����֤�Ų�ѯְ�� ESC���˳�" << endl;
		char i = _getch();
		if (i == '1') {
			std::system("cls");
			updateEmployeeProfileById(EMPLOYEE_FILENAME);
		}
		else if (i == '2') {
			std::system("cls");
			updateEmployeeProfileByIdNumber(EMPLOYEE_FILENAME);
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

// ͨ�����Ÿ���ְ����Ϣ
void updateEmployeeProfileById(string filename) {
	EmployeeProfile::updateProfileById(filename);
}

// ͨ�����֤�Ÿ���ְ����Ϣ
void updateEmployeeProfileByIdNumber(string filename) {
	EmployeeProfile::updateProfileByIdNumber(filename);
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

// ģ����ѯ
void fuzzyQuery(vector<EmployeeProfile> employeeProfiles) {
	chrono::high_resolution_clock::time_point startTime, endTime;

	string content;
	// ��¼��ѯ�����
	int count = 0;
	cout << "\n�������ѯ�����ݣ�";
	cin >> content;
	std::system("cls");
	// ת��content�е�����������ʽ�ַ�
	string escapedContent = regex_replace(content, regex(R"([\^$.|?*+()])"), R"(\$&)");
	regex reg(escapedContent, regex_constants::icase);

	// �����ͷ
	tableTitle();

	// ��¼��ʼʱ��
	startTime = chrono::high_resolution_clock::now();

	// ��һƥ��
	for (int i = 0; i < employeeProfiles.size(); i++) {
		if (regex_search(employeeProfiles[i].getId(), reg) ||
			regex_search(employeeProfiles[i].getName(), reg) ||
			regex_search(employeeProfiles[i].getIdNumber(), reg) ||
			regex_search(employeeProfiles[i].getGender(), reg) ||
			regex_search(to_string(employeeProfiles[i].getAge()), reg) ||
			regex_search(employeeProfiles[i].getPhoneNumber(), reg) ||
			regex_search(employeeProfiles[i].getAddress(), reg) ||
			regex_search(employeeProfiles[i].getEducation(), reg) ||
			regex_search(employeeProfiles[i].getPosition(), reg) ||
			regex_search(employeeProfiles[i].getHireDate(), reg) ||
			regex_search(employeeProfiles[i].getDepartment(), reg)) {
			// ��ӡƥ�䵽��Ա����Ϣ
			cout << employeeProfiles[i] << endl;
			count++;
		}
	}
	// ��¼����ʱ��
	endTime = chrono::high_resolution_clock::now();

	cout << "���β�ѯʱ�䣺" 
		<< chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count() << " ����" << endl
		<< "��ְ������" << count << endl;
}

// ���ļ��л�ȡÿһ�е����ݣ���������һ��EmployeeProfile��������
vector<EmployeeProfile> loadEmployeeProfiles(const string& filename) {
	vector<EmployeeProfile> profiles;
	ifstream inFile(filename);
	if (inFile.is_open()) {
		std::string line;
		while (std::getline(inFile, line)) {
			// ȷ���в�Ϊ��
			if (!line.empty()) {
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
	// �����������ַ������ͣ���Ҫ�����ת��
	getline(iss, ageStr, ',');
	getline(iss, phoneNumber, ',');
	getline(iss, address, ',');
	getline(iss, education, ',');
	getline(iss, position, ',');
	getline(iss, hireDate, ',');
	getline(iss, department);
	// ���ַ���ageStrת��Ϊint����age
	age = stoi(ageStr);
	// ���� EmployeeProfile ����
	return EmployeeProfile(id, name, idNumber, gender, age, phoneNumber, address, education, position, hireDate, department);
}

// �������
void fullScreen() {
	// ����Alt��
	keybd_event(VK_MENU, 0, 0, 0);
	// ���¿ո��
	keybd_event(VK_SPACE, 0, 0, 0);
	// ����X��
	keybd_event(0x58, 0, 0, 0);

	// �ͷ�X��
	keybd_event(0x58, 0, KEYEVENTF_KEYUP, 0);
	// �ͷſո��
	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
	// �ͷ�Alt��
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
}

// �رմ���
void closeBlackWindow() {
	cout << "3���رմ���.";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	
	// ����Alt��
	keybd_event(VK_MENU, 0, 0, 0);
	// ����F4��
	keybd_event(VK_F4, 0, 0, 0);

	// ����Alt��
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
	// ����F4��
	keybd_event(VK_F4, 0, KEYEVENTF_KEYUP, 0);
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
		<< setw(LONG_WIDTH) << "��ͥ��ַ:"
		<< setw(SHORT_WIDTH) << "ѧ��:"
		<< setw(MIDDLE_WIDTH) << "ְλ:"
		<< setw(MIDDLE_WIDTH) << "��ְ����:"
		<< setw(MIDDLE_WIDTH) << "��������:"
		<< endl;
	cout << string(LINE_LENGTH, '-') << endl;
}
