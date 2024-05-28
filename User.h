#pragma once
#include <string>
using namespace std;
class User
{
private:
	// 用户名
	string name;
	// 密码
	string password;
	// 手机号
	string phone;
public:
	// 无参构造函数
	User() = default;
	// 有参构造函数
	User(string na, string pa, string ph);

	// 成员变量对应的get函数
	string getName();
	string getPassword();

	// 将用户信息保存至文件中
	void saveUserToFile(const string& filename);

	// 判断用户名和密码是否匹配
	bool isPasswordValid(const string& filename);

	// 判断是否存在该用户名
	static bool isUsernameExists(const std::string& username, const std::string& filename);

	// 
	string findPhoneNumberAndSendVerificationCode(const std::string& phone);
};

