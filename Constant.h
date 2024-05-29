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
static int pageNum = 1;
static int pageSize = 6;

// 序号位该属性在一行中的位置，从 1 开始
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
static regex idNumberPattern("^([1-6][1-9]|[2-5]0)\\d{4}(18|19|20)\\d{2}(0[1-9]|1[0-2])(0[1-9]|[1-2]\\d|3[01])\\d{3}[0-9Xx]$");
// 手机号正则表达式
static regex phonePattern("^(13[0-9]|14[01456879]|15[0-35-9]|16[2567]|17[0-8]|18[0-9]|19[0-35-9])\\d{8}$");