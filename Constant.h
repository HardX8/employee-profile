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
const string KEY_ERROR_ENG = "Please press the correct KEY";
const int PAGE_NUM = 1;
const int PAGE_SIZE = 6;
static int pageNum = 1;
static int pageSize = 6;

// ���Ϊ��������һ���е�λ�ã��� 1 ��ʼ
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
static regex idNumberPattern("^[1-9]\\d{5}(?:18|19|20)\\d{2}(?:0\\d|10|11|12)(?:0[1-9]|[1-2]\\d|30|31)\\d{3}[\\dX]$");
// �ֻ���������ʽ
static regex phonePattern("^(?:(?:\\+|00)86)?1(?:(?:3[\\d])|(?:4[5-7|9])|(?:5[0-3|5-9])|(?:6[5-7])|(?:7[0-8])|(?:8[\\d])|(?:9[1|8|9]))\\d{8}$");