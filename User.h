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
public:
	User() = default;
	User(string na, string pa);
	void saveUserToFile(const string& filename);
	string getName();
	string getPassword();
	static bool isUsernameExists(const std::string& username, const std::string& filename);
	bool isPasswordValid(const string& filename);
};

