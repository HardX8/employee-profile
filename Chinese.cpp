#include "Chinese.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

string Chinese::loginAndRegisterPage() const {
	cout << "    欢迎使用职工档案管理系统     " << endl;
	cout << "********************************" << endl;
	cout << "****                       *****" << endl;
	cout << "****       1. 登录         *****" << endl;
	cout << "****       	           *****" << endl;
	cout << "****       2. 注册         *****" << endl;
	cout << "****       	           *****" << endl;
	cout << "****       3. 忘记密码	   *****" << endl;
	cout << "****       	           *****" << endl;
	cout << "****       ESC.退出系统    *****" << endl;
	cout << "****       	           *****" << endl;
	cout << "********************************" << endl;
	return "";
}

string Chinese::menu() const
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

string Chinese::tableTitle() const
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

Chinese::Chinese()
{
	welcomeLogin = "  欢迎登录职工档案管理系统   ";
	welcomeRegister = "  欢迎注册职工档案管理系统   ";
	forgetPassword = "  忘记密码   ";
	isExit = "是否退出";
	yesOrNo = "1.确认2.取消";
	selectFunction = "\t    1.按工号升序 2.按工号降序 3.按年龄升序 4.按年龄降序"
		"5.按入职时间升序 6.按入职时间降序 7.前往页码 8.更改每页展示数 9.模糊查询 ESC键退出";
	currentPage = "\n当前页：";
	page = "/页";
	leftOrRight = "\t向左：A/←\t向右：D/→";
	totalEmployee = "总职工数：";
	updateByIdOrIdNumber = "1.通过工号更新职工 2.通过身份证号更新职工 ESC键退出";
	deleteByIdOrIdNumber = "1.通过工号删除 2.通过身份证号删除 ESC键退出";
	selectTime = "本次查询时间：";
	close = "3秒后关闭窗口.";
	userName = "用户名：";

	exitSuccess = "\n退出成功！";
	loginSuccess = "登陆成功";
	registerSuccess = "注册成功";

	inputUserName = "请输入用户名：";
	inputPassword = "请输入密码：";
	inputConfirmPassword = "请再次输入密码：";
	inputPhone = "请输入手机号：";
	inputCode = "请输入验证码：";
	inputPageNum = "\n请输入页码：";
	inputNum = "请输入数字！";
	inputNumPerPage = "\n请输入每页展示数：";
	inputOneOrTwo = "请按1或2键";
	inputSelectContent = "\n请输入查询的内容：";

	userNameNotExist = "用户名不存在，请先注册";
	userNameAlreadyExist = "用户名已存在，请重新输入";
	phoneAlreadyExist = "手机号已存在，请重新输入";

	passwordDifferent = "两次密码不一致，请重新输入！";
	userNameOrPasswordError = "用户名或密码错误，请重试！";
	overtime = "超过60秒，操作超时";
	codeError = "验证码错误，请重新输入：";
	numTooLong = "数字太大，超出了允许的范围！";
	canNotOpen = "无法打开文件: ";

	pressEnter = "按回车键重新发送";

	// -----------------------User------------------------

	canCreateTemp = "无法创建临时文件！";
	inputNewPassword = "请输入新密码：";
	phone = "手机号为 ";
	updatePasswordSuccess = " 的用户密码已成功修改。";
	saveUser = "用户数据已保存至: ";
	wait = "请稍等...";
	sending = "正在发送";
	sended = "已向手机号 ";
	sendCode = " 发送验证码：";
	timeValid = "\t(60秒有效)";
	phoneNotRegister = "该手机号未注册！";
	passwordShort = "密码长度不能少于6位，请重新输入：";
	passwordLong = "\n密码长度不能超过20位，请重新输入：";
}

