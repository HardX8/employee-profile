#pragma once
#include <string>

using namespace std;

class Language
{
public:
    virtual ~Language() {}
    // 登录注册页面显示
    virtual string loginAndRegisterPage() const = 0;
    virtual string menu() const = 0;
    virtual string tableTitle() const = 0;

    string welcomeLogin;
    string welcomeRegister;
    string forgetPassword;
    string isExit;
    string yesOrNo;
    string selectFunction;
    string currentPage;
    string page;
    string leftOrRight;
    string totalEmployee;
    string updateByIdOrIdNumber;
    string deleteByIdOrIdNumber;
    string selectTime;
    string close;
    string userName;

    string exitSuccess;
    string loginSuccess;
    string registerSuccess;

    string inputUserName;
    string inputConfirmPassword;
    string inputPhone;
    string inputPassword;
    string inputCode;
    string inputPageNum;
    string inputNum;
    string inputNumPerPage;
    string inputOneOrTwo;
    string inputSelectContent;

    string userNameNotExist;
    string phoneAlreadyExist;
    string userNameAlreadyExist;

    string passwordDifferent;
    string userNameOrPasswordError;
    string overtime;
    string codeError;
    string numTooLong;
    string canNotOpen;

    string pressEnter;
    
    // -----------------------User------------------------

    string canCreateTemp;
    string inputNewPassword;
    string phone;
    string updatePasswordSuccess;
    string saveUser;
    string wait;
    string sending;
    string sended;
    string sendCode;
    string timeValid;
    string phoneNotRegister;
    string passwordShort;
    string passwordLong;

    // -----------------------EmployeeProfile------------------------

    string employeeId;
    string employeeAlreadyDel;
    string idNum;
    string employeeIdNotFound;
    string employeeRecord;
    string idNumNotFound;
    string inputEmployeeId;
    string inputIdNum;
    string employeeSaveTo;
    string ratainOldVal;
    string catNotUpdate;
    string oldVal;
    string newVal;
    string idNumFormatError;
    string idNumAlreadyExist;
    string reinputPhone;
    string 	employeePhoneAlreadyExist = "手机号已存在！\n请重新输入手机号：";
    string employeeUpdateSuccess;
    string phoneFormatError;
    string employeeIdFormat;
    string employeeIdFormatError;
    string employeeIdAlreadyExist;
    string employeeName;
    string inputIdNum2;
    string idNumFormatError2;
    string idNumAlreadyExist2;
    string gender;
    string age;
    string employeePhone;
    string phoneAlreadyExist2;
    string address;
    string education;
    string position;
    string hireDate;
    string department;

};

