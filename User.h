#pragma once
#include <string>
using namespace std;
class User
{
private:
	// �û���
	string name;
	// ����
	string password;
	// �ֻ���
	string phone;
public:
	// �޲ι��캯��
	User() = default;
	// �вι��캯��
	User(string na, string pa, string ph);

	// ��Ա������Ӧ��get����
	string getName();
	string getPassword();

	// ���û���Ϣ�������ļ���
	void saveUserToFile(const string& filename);

	// �ж��û����������Ƿ�ƥ��
	bool isPasswordValid(const string& filename);

	// �ж��Ƿ���ڸ��û���
	static bool isUsernameExists(const std::string& username, const std::string& filename);

	// 
	string findPhoneNumberAndSendVerificationCode(const std::string& phone);
};

