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

using namespace std;
bool login();
void myRegister();
void menu();
void displayAllProfile();
void insertEmployeeProfile();
void updateEmployeeProfile();
void deleteEmployeeProfile();
vector<EmployeeProfile> loadEmployeeProfiles(const string& filename);
EmployeeProfile createProfileFromLine(const std::string& line);
void tableTitle();
int main() {
	while (1) {

		cout << "  欢迎使用职工档案管理系统   " << endl;
		cout << "******************************" << endl;
		cout << "****                     *****" << endl;
		cout << "****       1. 登录       *****" << endl;
		cout << "****       	         *****" << endl;
		cout << "****       2. 注册       *****" << endl;
		cout << "****       	         *****" << endl;
		cout << "******************************" << endl;

		char first;
		while (1) {
			
			first = _getch();
			if (first == '1') {
				system("cls");
				//cout << "  欢迎登录职工档案管理系统   " << endl;
				//// 如果登录成功，进入主界面
				//if (login()) {
				//	menu();
				//	return 0;// TODO 有待考虑
				//}
				menu(); return 0;// 此行代码便于调试，后期删除
				break;
			}
			else if (first == '2') {
				system("cls");
				cout << "  欢迎注册职工档案管理系统   " << endl;
				myRegister();
				break;
			}
			else if (first == 27) {
				cout << "退出成功！";
				return 0;
			}
			else {
				cout << "请按1或2键（按ESC键可退出系统）" << endl;
			}
			

		}

	}

	return 0;
}
bool login() {
	string name, password;
	string filename = "user.txt";
	while (1) {
		cout << "请输入用户名：";
		cin >> name;
		// 检查用户名是否存在
		bool nameExists = User::isUsernameExists(name, filename);
		if (!nameExists) {
			cout << "用户名不存在，请先注册" << endl;
			return false;
		}
		cout << "请输入密码：";
		cin >> password;
		User user(name, password);
		if (user.isPasswordValid(filename)) {
			system("cls");
			cout << "登陆成功" << endl;
			return true;
		}
		else {
			cout << "用户名或密码错误，请重试！" << endl;
		}

	}


}
void myRegister() {
	string name, password, confirmPassword;
	string filename = "user.txt";
	while (1) {
		cout << "请输入用户名：";
		cin >> name;
		// 检查用户名是否存在
		bool nameExists = User::isUsernameExists(name, filename);
		if (nameExists) {
			cout << "用户名已存在，请重新输入" << endl;
		}
		else {
			break;
		}

	}


	while (1) {
		cout << "请输入密码：";
		cin >> password;
		cout << "请再次输入密码：";
		cin >> confirmPassword;
		if (password != confirmPassword) {
			cout << "两次密码不一致，请重新输入！" << endl;
		}
		else {
			break;
		}
	}
	User user(name, password);
	system("cls");
	// 保存用户信息
	user.saveUserToFile(filename);

	cout << "注册成功" << endl;
}
void menu() {
	while (1) {
		cout << "     欢迎使用职工档案管理系统   " << endl;
		cout << "————————————————————————————————————" << endl;
		cout << "|                                  |" << endl;
		cout << "|     1. 查询所有职工档案信息      |" << endl;
		cout << "|     2. 新增职工档案信息          |" << endl;
		cout << "|     3. 修改职工档案信息          |" << endl;
		cout << "|     4. 删除职工档案信息          |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "|                                  |" << endl;
		cout << "————————————————————————————————————" << endl;

		//EmployeeProfile employee("张三", "330112199001010010", "男", 33, "13800138000", "杭州市西湖区XX街道123号", "本科", "软件工程师", "2015-03-01", "研发部");
		//cout << employee;
		//EmployeeProfile e;
		//insert(e);
		//cin >> e;

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
			cout << "请输入正确的数字！" << endl;
			break;
		}
	}


}

void displayAllProfile() {
	string filename = "employee.txt";
	vector<EmployeeProfile> employeeProfiles = loadEmployeeProfiles(filename);
	// 输出表头
	tableTitle();
	// 输出每一个数据
	for (EmployeeProfile& employeeProfile : employeeProfiles) {
		cout << employeeProfile << endl;
	}

	// 等待用户按下任意按键
	system("pause");
	system("cls");

}
void insertEmployeeProfile() {



	EmployeeProfile e;
	cin >> e;
	string filename = "employee.txt";
	e.saveEmployeeToFile(filename);


}
void updateEmployeeProfile() {
	cout << "updateEmployeeProfile" << endl;
}
void deleteEmployeeProfile() {
	cout << "deleteEmployeeProfile" << endl;
}

// 从文件中获取每一行的内容，并构建成一个EmployeeProfile对象数组
vector<EmployeeProfile> loadEmployeeProfiles(const string& filename) {
	vector<EmployeeProfile> profiles;
	ifstream inFile(filename);
	if (inFile.is_open()) {
		std::string line;
		while (std::getline(inFile, line)) {
			if (!line.empty()) { // 确保行不为空
				EmployeeProfile profile = createProfileFromLine(line);
				profiles.push_back(profile);
			}
		}
		inFile.close();
	}
	else {
		cerr << "无法打开文件: " << filename << std::endl;
	}
	return profiles;
}

// 从一行数据中获取每个属性值，并构建EmployeeProfile对象
EmployeeProfile createProfileFromLine(const std::string& line) {
	istringstream iss(line);
	// 定义 EmployeeProfile 包含的成员变量
	string name, idNumber, gender, ageStr, phoneNumber, address, education, position, hireDate, department;
	int age;
	// 每行中的每个数据以逗号分隔，解析字符串
	getline(iss, name, ',');
	getline(iss, idNumber, ',');
	getline(iss, gender, ',');
	// 对于整数等非字符串类型，需要额外的转换
	getline(iss, ageStr, ',');
	getline(iss, phoneNumber, ',');
	getline(iss, address, ',');
	getline(iss, education, ',');
	getline(iss, position, ',');
	getline(iss, hireDate, ',');
	getline(iss, department);
	// 将字符串ageStr转化为int类型
	age = stoi(ageStr);
	// 创建 EmployeeProfile 对象
	return EmployeeProfile(name, idNumber, gender, age, phoneNumber, address, education, position, hireDate, department);
}

// 表头
void tableTitle() {
	const int SHORT_WIDTH = 10; // 短列宽
	const int MIDDLE_WIDTH = 15; // 中列宽
	const int LONG_WIDTH = 20; // 长列宽

	// 输出表头
	cout << left << setw(SHORT_WIDTH) << "职工姓名:"
		<< setw(LONG_WIDTH) << "身份证号:"
		<< setw(SHORT_WIDTH) << "性别:"
		<< setw(SHORT_WIDTH) << "年龄:"
		<< setw(MIDDLE_WIDTH) << "联系电话:"
		<< setw(30) << "家庭地址:"
		<< setw(SHORT_WIDTH) << "学历:"
		<< setw(MIDDLE_WIDTH) << "职位:"
		<< setw(MIDDLE_WIDTH) << "入职日期:"
		<< setw(SHORT_WIDTH) << "所属部门:"
		<< endl;
}
