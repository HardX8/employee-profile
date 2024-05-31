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

string English::tableTitle() const
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

English::English()
{
	welcomeLogin = "Welcome to log in to the employee archive management system";
	userName = "user name:";
}

