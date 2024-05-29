#pragma once
#include <string>
#include <regex>

using namespace std;

/**
 * @author XZH
 */

const string EMPLOYEE_FILENAME = "employee.txt";
const string USER_FILENAME = "user.txt";
const string KEY_ERROR = "�밴��ȷ�İ�����";
static int pageNum = 1;
static int pageSize = 6;

// ���λ��������һ���е�λ�ã��� 1 ��ʼ
// ְ�� id �����
static int EMPLOYEE_ID_SERIAL_NUMBER = 1;
// ְ�� phone �����
static int EMPLOYEE_PHONE_SERIAL_NUMBER = 6;
// ְ�� idNumber �����
static int EMPLOYEE_ID_NUMBER_SERIAL_NUMBER = 3;

// �û� phone �����
static int USER_PHONE_SERIAL_NUMBER = 3;
// �û� password �����
static int USER_PASSWORD_SERIAL_NUMBER = 2;
// �û� name �����
static int USER_NAME_SERIAL_NUMBER = 1;

// ���֤������ʽ
static regex idNumberPattern("^([1-6][1-9]|[2-5]0)\\d{4}(18|19|20)\\d{2}(0[1-9]|1[0-2])(0[1-9]|[1-2]\\d|3[01])\\d{3}[0-9Xx]$");
// �ֻ���������ʽ
static regex phonePattern("^(13[0-9]|14[01456879]|15[0-35-9]|16[2567]|17[0-8]|18[0-9]|19[0-35-9])\\d{8}$");