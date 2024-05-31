#include "Chinese.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

string Chinese::loginAndRegisterPage() const {
	cout << "    ��ӭʹ��ְ����������ϵͳ     " << endl;
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
	return "";
}

string Chinese::menu() const
{
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
	return "";
}

string Chinese::tableTitle() const
{
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
	return "";
}

Chinese::Chinese()
{
	welcomeLogin = "  ��ӭ��¼ְ����������ϵͳ   ";
	welcomeRegister = "  ��ӭע��ְ����������ϵͳ   ";
	forgetPassword = "  ��������   ";
	isExit = "�Ƿ��˳�";
	yesOrNo = "1.ȷ��2.ȡ��";
	selectFunction = "\t    1.���������� 2.�����Ž��� 3.���������� 4.�����併��"
		"5.����ְʱ������ 6.����ְʱ�併�� 7.ǰ��ҳ�� 8.����ÿҳչʾ�� 9.ģ����ѯ ESC���˳�";
	currentPage = "\n��ǰҳ��";
	page = "/ҳ";
	leftOrRight = "\t����A/��\t���ң�D/��";
	totalEmployee = "��ְ������";
	updateByIdOrIdNumber = "1.ͨ�����Ÿ���ְ�� 2.ͨ�����֤�Ÿ���ְ�� ESC���˳�";
	deleteByIdOrIdNumber = "1.ͨ������ɾ�� 2.ͨ�����֤��ɾ�� ESC���˳�";
	selectTime = "���β�ѯʱ�䣺";
	close = "3���رմ���.";
	userName = "�û�����";

	exitSuccess = "\n�˳��ɹ���";
	loginSuccess = "��½�ɹ�";
	registerSuccess = "ע��ɹ�";

	inputUserName = "�������û�����";
	inputPassword = "���������룺";
	inputConfirmPassword = "���ٴ��������룺";
	inputPhone = "�������ֻ��ţ�";
	inputCode = "��������֤�룺";
	inputPageNum = "\n������ҳ�룺";
	inputNum = "���������֣�";
	inputNumPerPage = "\n������ÿҳչʾ����";
	inputOneOrTwo = "�밴1��2��";
	inputSelectContent = "\n�������ѯ�����ݣ�";

	userNameNotExist = "�û��������ڣ�����ע��";
	userNameAlreadyExist = "�û����Ѵ��ڣ�����������";
	phoneAlreadyExist = "�ֻ����Ѵ��ڣ�����������";

	passwordDifferent = "�������벻һ�£����������룡";
	userNameOrPasswordError = "�û�����������������ԣ�";
	overtime = "����60�룬������ʱ";
	codeError = "��֤��������������룺";
	numTooLong = "����̫�󣬳���������ķ�Χ��";
	canNotOpen = "�޷����ļ�: ";

	pressEnter = "���س������·���";

	// -----------------------User------------------------

	canCreateTemp = "�޷�������ʱ�ļ���";
	inputNewPassword = "�����������룺";
	phone = "�ֻ���Ϊ ";
	updatePasswordSuccess = " ���û������ѳɹ��޸ġ�";
	saveUser = "�û������ѱ�����: ";
	wait = "���Ե�...";
	sending = "���ڷ���";
	sended = "�����ֻ��� ";
	sendCode = " ������֤�룺";
	timeValid = "\t(60����Ч)";
	phoneNotRegister = "���ֻ���δע�ᣡ";
	passwordShort = "���볤�Ȳ�������6λ�����������룺";
	passwordLong = "\n���볤�Ȳ��ܳ���20λ�����������룺";
}

