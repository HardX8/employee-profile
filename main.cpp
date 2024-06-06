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
#include "Language.h"
#include "Chinese.h"
#include "English.h"
#include <memory>

#pragma comment(lib, "Winmm.lib")

using namespace std;

/**
 * @author XZH
 */
string EnString = "_ENGLISH";
string resultString = "";

// 工厂函数，根据需要返回相应的Language实例
shared_ptr<Language> createLanguage(const string& lang) {
    if (lang == "_ENGLISH") {
        return make_shared<English>();
    } else { 
		// 默认中文或其他逻辑
        return make_shared<Chinese>();
    }
}
// shared_ptr允许多个对象共享同一个资源的所有权，
// 当最后一个指向该资源的shared_ptr销毁时，资源会被自动释放
shared_ptr<Language> language;

bool login();
void myRegister();
void forgetPassword();
void selectMusic();
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
void videoPath(wstring basePath);
void tableTitle();

// 是否选择过语言
bool selectLanguage = false;
int main() {
	while (1) {
		// 如果还没选择语言
		if (!selectLanguage) {
			while (1) {
				cout << "请选择语言\tPlease select language" << endl
					<< "1.中文\t\t1.Chinese" << endl
					<< "2.英文\t\t2.English" << endl;
				int languageChoice =_getch();
				if (languageChoice == '1') {
					std::system("cls");
					selectLanguage = true;

					// 选择语言对象
					language = createLanguage(resultString);
					// 是否开启背景音乐
					selectMusic();

					std::system("cls");
					videoPath(L"video\\welcome");
					break;
				}
				else if (languageChoice == '2') {
					std::system("cls");
					resultString = EnString;
					selectLanguage = true;

					// 选择语言对象
					language = createLanguage(resultString);
					// 是否开启背景音乐
					selectMusic();

					std::system("cls");
					videoPath(L"video\\welcome");
					break;
				}
				else {	
					std::system("cls");
					cout << KEY_ERROR << endl;
					cout << KEY_ERROR_ENG << endl << endl;
				}
			}
		}

		// 将语言对象传递给User
		User user(language);
		// 将语言对象传递给Employee
		EmployeeProfile employee(language);

		// 设置黑窗口标题
		SetConsoleTitleA("职工档案管理系统-XZH");

		// 设置黑窗口和字体颜色
		system("color f0");
		// 显示日期
		system("date /T");
		// 显示时间
		system("TIME /T");

		cout << language->loginAndRegisterPage() << endl;

		char first;
		first = _getch();
		switch (first) {
		case '1':
			std::system("cls");
			cout << language->welcomeLogin << endl;
			// 如果登录成功，进入主界面
			if (login()) {
				// 设置黑窗口和字体颜色
				system("color 0B");
				menu();
				return 0;
			}
			break;
		case '2':
			std::system("cls");
			cout << language->welcomeRegister << endl;
			myRegister();
			break;
		case '3':
			std::system("cls");
			cout << language->forgetPassword << endl;
			forgetPassword();
			break;
		case 27:
			cout << language->isExit << endl << language->yesOrNo;
			if (_getch() == '1') {
				cout << language->exitSuccess << endl;
				videoPath(L"video\\bye");
				closeBlackWindow();
				// 用return 0 的话在meun()中调用main()之后还会再执行meun()
				// 虽然执行了关闭窗口函数，但是如果用户此时鼠标正在移动窗口
				// 则不会直接关闭窗口
				exit(0);
			}
			std::system("cls");
			break;
		default:
			system("cls");
			cout << language->KEY_ERROR << endl;
		}

	}

	return 0;
}

// 登录
bool login() {
	string name, password;
	string filename = USER_FILENAME;
	while (1) {
		cout << language->inputUserName;
		cin >> name;
		// 检查用户名是否存在
		bool nameExists = User::isUsernameExists(name, filename);
		if (!nameExists) {
			//std::system("cls");
			cout << language->userNameNotExist << endl;
			return false;
		}
		cout << language->inputPassword;
		password = User::inputPassword();
		User user(name, password);
		if (user.isPasswordValid(filename)) {
			std::system("cls");
			cout << language->loginSuccess << endl;
			videoPath(L"video\\login");
			return true;
		}
		else {
			cout << language->userNameOrPasswordError << endl;
		}

	}


}

// 注册
void myRegister() {
	string name, password, confirmPassword, phone;
	string filename = USER_FILENAME;
	while (1) {
		cout << language->inputUserName;
		cin >> name;
		// 检查用户名是否存在
		bool nameExists = User::isUsernameExists(name, filename);
		if (nameExists) {
			cout << language->userNameAlreadyExist << endl;
		}
		else {
			break;
		}

	}

	while (1) {
		cout << language->inputPhone;
		cin >> phone;

		// 如果手机号格式不正确
		if (!EmployeeProfile::verifyPhone(phone)) {
			continue;
		}

		// 检查手机号是否存在
		bool phoneExists = User::isPhoneExists(phone, filename);
		if (phoneExists) {
			cout << language->phoneAlreadyExist << endl;
		}
		else {
			break;
		}
	}

	while (1) {
		cout << language->inputPassword;
		password = User::inputPassword();
		cout << language->inputConfirmPassword;
		confirmPassword = User::inputPassword();
		if (password != confirmPassword) {
			cout << language->passwordDifferent << endl;
		}
		else {
			break;
		}
	}

	User user(name, password, phone);
	std::system("cls");
	// 保存用户信息
	user.saveUserToFile(filename);

	cout << language->registerSuccess << endl;

	videoPath(L"video\\register");
}

// 选择音乐
void selectMusic() {
	const wstring fileExtension = L".mp3 repeat";
	const wstring basePath = L"play video\\";

	cout << language->music << endl << language->yesOrNo2 << endl;
	int key = _getch();
	// 不开启背景音乐
	if (key == '2') {
		return;
	}

	int i;
	// 设置随机数生成器的种子
	srand(time(0)); 
	while (1) {
		i = rand() % 10;
		if (i <= 5 && i > 0) {
			break;
		}
	}

	// 拼接字符串
	wstring filePath = basePath + to_wstring(i) + fileExtension;
	mciSendString(filePath.c_str(), NULL, 0, NULL);
}

// 忘记密码
void forgetPassword() {
	string phone, code, VerificationCode;
	chrono::high_resolution_clock::time_point startTime, endTime;

	while (1) {
		cout << language->inputPhone;
		cin >> phone;
		if (!EmployeeProfile::verifyPhone(phone)) {
			continue;
		}
		sendVerificationCode:
		VerificationCode = User::findPhoneAndSendVerificationCode(phone, USER_FILENAME);
		// 记录开始时间
		startTime = chrono::high_resolution_clock::now();

		if (VerificationCode != "") {
			break;
		}
	}
	cout << language->inputCode;
	while (1) {
		cin >> code;
		// 记录结束时间
		endTime = chrono::high_resolution_clock::now();

		if (chrono::duration_cast<chrono::seconds>(endTime - startTime).count() > 3) {
			cout << language->overtime << endl << language->pressEnter << endl;
			int i = _getch();
			if (i == 13) {
				goto sendVerificationCode;
			}
			break;
		}

		if (VerificationCode == code) {
			User::updateUserByPhone(USER_FILENAME, phone);
			videoPath(L"video\\password");
			break;	
		}
		cout << language->codeError;
	}
}

// 功能菜单
void menu() {
	while (1) {
		language->menu();

		string filename = EMPLOYEE_FILENAME;

		char i;
		i = _getch();
		switch (i)
		{
		case 27:
			cout << language->isExit << endl << language->yesOrNo;
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
			cout << language->KEY_ERROR << endl;
			break;
		}
	}


}

// 显示所有职工信息，并提供排序、模糊查询等功能
void displayAllProfile() {
	// 窗口最大化
	fullScreen();

	vector<EmployeeProfile> employeeProfiles = loadEmployeeProfiles(EMPLOYEE_FILENAME);

	bool flag = true;

	while (flag) {

		cout << language->selectFunction << endl << endl;
		// 输出表头
		tableTitle();

		int startRow = pageNum > 0 ? (pageNum - 1) * pageSize : 0;
		int endRow = startRow + pageSize * (pageNum > 0 ? 1 : 0);
		int total = employeeProfiles.size();
		// 计算出来之后向上取整
		int sumNum = static_cast<int>(ceil(static_cast<double>(total) / pageSize));

		// 输出每一个数据
		for (int i = startRow; i < endRow && i < total; i++) {
			cout << employeeProfiles[i] << endl;
		}
		cout << language->currentPage << pageNum << "/" << sumNum << "\t" << pageSize << language->page <<
			language->leftOrRight << endl
			<< language->totalEmployee << total;

		int i = _getch();

		switch (i) {
		case '1':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				// 按工号升序
				return a.getId() < b.getId();
				});
			break;
		case '2':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				// 按工号降序
				return a.getId() > b.getId();
				});
			break;
		case '3':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				// 按年龄升序
				return a.getAge() < b.getAge();
				});
			break;
		case '4':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				// 按年龄序
				return a.getAge() > b.getAge();
				});
			break;
		case '5':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				// 按入职时间升序
				return a.getHireDate() < b.getHireDate();
				});
			break;
		case '6':
			std::system("cls");
			sort(employeeProfiles.begin(), employeeProfiles.end(), [](EmployeeProfile& a, EmployeeProfile& b) {
				// 按入职时间降序
				return a.getHireDate() > b.getHireDate();
				});
			break;
		case '7': {
			cout << language->inputPageNum;
			string inputStr;
			cin >> inputStr;

			std::system("cls");
			try {
				// 检测输入是否可以转成在范围内的数字
				int input = stoi(inputStr);
				// 如果输入页码小于等于0则为第一页
				if (input <= 0) {
					pageNum = 1;
				}
				// 如果大于最大页码最为最后一页
				else if (input > sumNum) {
					pageNum = sumNum;
				}
				else {
					pageNum = input;
				}
			}
			catch (const invalid_argument& e) {
				// 捕获输入不是数字的异常
				cerr << language->inputNum << endl;
			}
			catch (const out_of_range& e) {
				// 转换后的数字超出int范围
				cerr << language->numTooLong << endl;
			}
			break;
		}
		case '8':
			cout << language->inputNumPerPage;
			cin >> pageSize;
			std::system("cls");
			// 回到第一页
			pageNum = 1;
			break;
		case '9':
			fuzzyQuery(employeeProfiles);
			std::system("pause");
			std::system("cls");
			break;
		case 27: // ESC键
			std::system("cls");
			flag = false;
			break;
		case 77: // 右键
			std::system("cls");
			if (pageNum < sumNum) {
				pageNum++;
			}
			break;
		case 100: // D键
			std::system("cls");
			if (pageNum < sumNum) {
				pageNum++;
			}
			break;
		case 75: // 左键
			std::system("cls");
			if (pageNum > 1) {
				pageNum--;
			}
			break;
		case 97: // A键
			std::system("cls");
			if (pageNum > 1) {
				pageNum--;
			}
			break;
		default:
			std::system("cls");
			//cout << i;
			cout << language->KEY_ERROR << endl;
		}
	}
	// 重置为第一页
	pageNum = PAGE_NUM;
	// 重置每页展示数
	pageSize = PAGE_SIZE;
}

// 新增职工
void insertEmployeeProfile() {
	EmployeeProfile e;
	cin >> e;
	e.saveEmployeeToFile(EMPLOYEE_FILENAME);
}

// 修改职工信息
void updateEmployeeProfile(string filename) {
	while (1) {
		cout << language->updateByIdOrIdNumber << endl;
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
			cout << language->inputOneOrTwo << endl;
		}
	}
}

// 通过工号更新职工信息
void updateEmployeeProfileById(string filename) {
	EmployeeProfile::updateProfileById(filename);
}

// 通过身份证号更新职工信息
void updateEmployeeProfileByIdNumber(string filename) {
	EmployeeProfile::updateProfileByIdNumber(filename);
}

// 删除员工
void deleteEmployeeProfile() {
	while (1) {
		cout << language->deleteByIdOrIdNumber << endl;
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
			cout << language->inputOneOrTwo << endl;
		}
	}
}

// 通过工号删除
void deleteEmployeeProfileById(string filename) {
	EmployeeProfile::deleteProfileById(filename);
}

// 通过身份证号删除
void deleteEmployeeProfileByIdNumber(string filename) {
	EmployeeProfile::deleteProfileByIdNumber(filename);
}

// 模糊查询
void fuzzyQuery(vector<EmployeeProfile> employeeProfiles) {
	chrono::high_resolution_clock::time_point startTime, endTime;

	string content;
	// 记录查询结果数
	int count = 0;
	cout << language->inputSelectContent;
	cin >> content;
	std::system("cls");
	// 转义content中的特殊正则表达式字符
	string escapedContent = regex_replace(content, regex(R"([\^$.|?*+()])"), R"(\$&)");
	regex reg(escapedContent, regex_constants::icase);

	// 输出表头
	tableTitle();

	// 记录开始时间
	startTime = chrono::high_resolution_clock::now();

	// 逐一匹配
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
			// 打印匹配到的员工信息
			cout << employeeProfiles[i] << endl;
			count++;
		}
	}
	// 记录结束时间
	endTime = chrono::high_resolution_clock::now();

	cout << language->selectTime
		<< chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count() << " 毫秒" << endl
		<< language->totalEmployee << count << endl;
}

// 从文件中获取每一行的内容，并构建成一个EmployeeProfile对象数组
vector<EmployeeProfile> loadEmployeeProfiles(const string& filename) {
	vector<EmployeeProfile> profiles;
	ifstream inFile(filename);
	if (inFile.is_open()) {
		std::string line;
		while (std::getline(inFile, line)) {
			// 确保行不为空
			if (!line.empty()) {
				EmployeeProfile profile = createProfileFromLine(line);
				profiles.push_back(profile);
			}
		}
		inFile.close();
	}
	else {
		cerr << language->canNotOpen << filename << std::endl;
	}
	return profiles;
}

// 从一行数据中获取每个属性值，并构建EmployeeProfile对象
EmployeeProfile createProfileFromLine(const std::string& line) {
	istringstream iss(line);
	// 定义 EmployeeProfile 包含的成员变量
	string id, name, idNumber, gender, ageStr, phoneNumber, address, education, position, hireDate, department;
	int age;
	// 每行中的每个数据以逗号分隔，解析字符串
	getline(iss, id, ',');
	getline(iss, name, ',');
	getline(iss, idNumber, ',');
	getline(iss, gender, ',');
	// 对于整数非字符串类型，需要额外的转换
	getline(iss, ageStr, ',');
	getline(iss, phoneNumber, ',');
	getline(iss, address, ',');
	getline(iss, education, ',');
	getline(iss, position, ',');
	getline(iss, hireDate, ',');
	getline(iss, department);
	// 将字符串ageStr转化为int类型age
	age = stoi(ageStr);
	// 创建 EmployeeProfile 对象
	return EmployeeProfile(id, name, idNumber, gender, age, phoneNumber, address, education, position, hireDate, department);
}

// 窗口最大化
void fullScreen() {
	// 按下Alt键
	keybd_event(VK_MENU, 0, 0, 0);
	// 按下空格键
	keybd_event(VK_SPACE, 0, 0, 0);
	// 按下X键
	keybd_event(0x58, 0, 0, 0);

	// 释放X键
	keybd_event(0x58, 0, KEYEVENTF_KEYUP, 0);
	// 释放空格键
	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
	// 释放Alt键
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
}

// 关闭窗口
void closeBlackWindow() {
	cout << language->close;
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	
	// 按下Alt键
	keybd_event(VK_MENU, 0, 0, 0);
	// 按下F4键
	keybd_event(VK_F4, 0, 0, 0);

	// 释放Alt键
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
	// 释放F4键
	keybd_event(VK_F4, 0, KEYEVENTF_KEYUP, 0);
}

// 播放不同语言的音频
void videoPath(wstring basePath) {
	const wstring fileExtension = L".wav";

	// 拼接字符串
	wstring filePath = basePath 
		+ wstring(resultString.begin(), resultString.end()) 
		+ fileExtension;

	// 播放音频
	PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

// 打印表头
void tableTitle() {
	const int SHORT_WIDTH = 10; // 短列宽
	const int MIDDLE_WIDTH = 15; // 中列宽
	const int LONG_WIDTH = 20; // 长列宽
	const int LINE_LENGTH = 155; // 分割线长度

	// 输出表头
	language->tableTitle();
	cout << string(LINE_LENGTH, '-') << endl;
}
