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
	// �û���
	string name;
	// ����
	string password;
	// �ֻ���
	string phone;
	// userLanguage��һ������ָ�룬���ڹ���Language��Ķ���
	static shared_ptr<Language> userLanguage;

	// ͨ����i�����ݲ�ѯ������
	static void updateUserByI(const string& filename, const string& phone, int i);
public:
	// �޲ι��캯��
	User() = default;
	// �вι��캯��
	User(string na, string pa, string ph);
	User(string na, string pa);
	// ���ڳ�ʼ�����ԵĹ��캯��
	User(shared_ptr<Language>& langPtr);


	// ��Ա������Ӧ��get����
	string getName();
	string getPassword();

	// ���û���Ϣ�������ļ���
	void saveUserToFile(const string& filename);

	// �ж��û����������Ƿ�ƥ��
	bool isPasswordValid(const string& filename);

	// ---------------------------static---------------------------

	// �ж��Ƿ���ڸ��û���
	static bool isUsernameExists(const std::string& username, const std::string& filename);

	// �ж��Ƿ���ڸ��ֻ���
	static bool isPhoneExists(const std::string& phone, const string& filename);

	// �ֻ��Ŵ���ʱ������֤��
	static string findPhoneAndSendVerificationCode(const string& phone, const string& filename);

	// �����ֻ��Ÿ���ְ��
	static void updateUserByPhone(const string& filename, const string& phone);

	// ��������
	static string inputPassword();

};

