#include "English.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

string English::loginAndRegisterPage() const {
	cout << "Welcome to use the employee file management system" << endl;
	cout << "   *************************************" << endl;
	cout << "   ****                            *****" << endl;
	cout << "   ****       1. login             *****" << endl;
	cout << "   ****                            *****" << endl;
	cout << "   ****       2. register          *****" << endl;
	cout << "   ****       	                   *****" << endl;
	cout << "   ****       3. forget password   *****" << endl;
	cout << "   ****       	                   *****" << endl;
	cout << "   ****       ESC.exit system      *****" << endl;
	cout << "   ****       	                   *****" << endl;
	cout << "   *************************************" << endl;
	return "";
}

string English::menu() const
{
	cout << "     欢迎使用职工档案管理系统   " << endl;
	cout << "————————————————————————————————————" << endl;
	cout << "|                                  |" << endl;
	cout << "|     1. 查询职工档案信息          |" << endl;
	cout << "|     2. 新增职工档案信息          |" << endl;
	cout << "|     3. 修改职工档案信息          |" << endl;
	cout << "|     4. 删除职工档案信息          |" << endl;
	cout << "|     ESC.退出登录                 |" << endl;
	cout << "|                                  |" << endl;
	cout << "————————————————————————————————————" << endl;
	return "";
}

string English::tableTitle() const
{
	const int SHORT_WIDTH = 10; // 短列宽
	const int MIDDLE_WIDTH = 15; // 中列宽
	const int LONG_WIDTH = 20; // 长列宽
	const int LINE_LENGTH = 155; // 分割线长度

	// 输出表头
	cout << left
		<< setw(MIDDLE_WIDTH) << "工号:"
		<< setw(SHORT_WIDTH) << "职工姓名:"
		<< setw(LONG_WIDTH) << "身份证号:"
		<< setw(SHORT_WIDTH) << "性别:"
		<< setw(SHORT_WIDTH) << "年龄:"
		<< setw(MIDDLE_WIDTH) << "联系电话:"
		<< setw(LONG_WIDTH) << "家庭地址:"
		<< setw(SHORT_WIDTH) << "学历:"
		<< setw(MIDDLE_WIDTH) << "职位:"
		<< setw(MIDDLE_WIDTH) << "入职日期:"
		<< setw(MIDDLE_WIDTH) << "所属部门:"
		<< endl;
	return "";
}

English::English()
{
	welcomeLogin = "Welcome to log in to the employee archive management system";
	userName = "user name:";
}

