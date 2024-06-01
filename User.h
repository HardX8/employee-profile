#pragma once
#include <string>
#include "Language.h"
#include <memory>


using namespace std;

/**
 * @author XZH
 */
class User
{
private:
	// 用户名
	string name;
	// 密码
	string password;
	// 手机号
	string phone;
	// userLanguage是一个智能指针，用于管理Language类的对象
	static shared_ptr<Language> userLanguage;

	// 通过第i项内容查询并更新
	static void updateUserByI(const string& filename, const string& phone, int i);
public:
	// 无参构造函数
	User() = default;
	// 有参构造函数
	User(string na, string pa, string ph);
	User(string na, string pa);
	// 用于初始化语言的构造函数
	User(shared_ptr<Language>& langPtr);


	// 成员变量对应的get函数
	string getName();
	string getPassword();

	// 将用户信息保存至文件中
	void saveUserToFile(const string& filename);

	// 判断用户名和密码是否匹配
	bool isPasswordValid(const string& filename);

	// ---------------------------static---------------------------

	// 判断是否存在该用户名
	static bool isUsernameExists(const std::string& username, const std::string& filename);

	// 判断是否存在该手机号
	static bool isPhoneExists(const std::string& phone, const string& filename);

	// 手机号存在时发送验证码
	static string findPhoneAndSendVerificationCode(const string& phone, const string& filename);

	// 根据手机号更新职工
	static void updateUserByPhone(const string& filename, const string& phone);

	// 输入密码
	static string inputPassword();

};

