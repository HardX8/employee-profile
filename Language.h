#pragma once
#include <string>

using namespace std;

class Language
{
public:
    virtual ~Language() {}
    // µÇÂ¼×¢²áÒ³ÃæÏÔÊ¾
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
};

