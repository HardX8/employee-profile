#pragma once
#include <string>
#include <regex>

using namespace std;

/**
 * @author XZH
 */

const string EMPLOYEE_FILENAME = "employee.txt";
const string USER_FILENAME = "user.txt";
const string KEY_ERROR = "请按正确的按键！";
const string KEY_ERROR_ENG = "Please press the correct KEY";
const int PAGE_NUM = 1;
const int PAGE_SIZE = 6;
static int pageNum = 1;
static int pageSize = 6;

// 序号为该属性在一行中的位置，从 1 开始
// 职工 id 的序号
static int EMPLOYEE_ID_SERIAL_NUMBER = 1;
// 职工 phone 的序号
static int EMPLOYEE_PHONE_SERIAL_NUMBER = 6;
// 职工 idNumber 的序号
static int EMPLOYEE_ID_NUMBER_SERIAL_NUMBER = 3;

// 用户 phone 的序号
static int USER_PHONE_SERIAL_NUMBER = 3;
// 用户 password 的序号
static int USER_PASSWORD_SERIAL_NUMBER = 2;
// 用户 name 的序号
static int USER_NAME_SERIAL_NUMBER = 1;

// 身份证正则表达式
static regex idNumberPattern("^[1-9]\\d{5}(?:18|19|20)\\d{2}(?:0\\d|10|11|12)(?:0[1-9]|[1-2]\\d|30|31)\\d{3}[\\dX]$");
// 手机号正则表达式
static regex phonePattern("^(?:(?:\\+|00)86)?1(?:(?:3[\\d])|(?:4[5-7|9])|(?:5[0-3|5-9])|(?:6[5-7])|(?:7[0-8])|(?:8[\\d])|(?:9[1|8|9]))\\d{8}$");