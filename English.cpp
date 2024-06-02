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
	cout << "     Welcome to the Employee Profile Management System   " << endl;
	cout << "！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
	cout << "|                                  |" << endl;
	cout << "|     1. Query Employee Profiles   |" << endl;
	cout << "|     2. Add Employee Profile      |" << endl;
	cout << "|     3. Update Employee Profile   |" << endl;
	cout << "|     4. Delete Employee Profile   |" << endl;
	cout << "|     ESC. Logout                  |" << endl;
	cout << "|                                  |" << endl;
	cout << "！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！" << endl;

	return "";
}

string English::tableTitle() const
{
	const int SHORT_WIDTH = 10; // 玉双錐
	const int MIDDLE_WIDTH = 15; // 嶄双錐
	const int LONG_WIDTH = 20; // 海双錐
	const int LINE_LENGTH = 155; // 蛍護�潦ざ�

	// 補竃燕遊
	cout << left
		<< setw(MIDDLE_WIDTH) << "Employee ID:"
		<< setw(SHORT_WIDTH) << "Name:"
		<< setw(LONG_WIDTH) << "ID Number:"
		<< setw(SHORT_WIDTH) << "Gender:"
		<< setw(SHORT_WIDTH) << "Age:"
		<< setw(MIDDLE_WIDTH) << "Phone:"
		<< setw(LONG_WIDTH) << "Address:"
		<< setw(SHORT_WIDTH) << "Education:"
		<< setw(MIDDLE_WIDTH) << "Position:"
		<< setw(MIDDLE_WIDTH) << "Hire Date:"
		<< setw(MIDDLE_WIDTH) << "Department:"
		<< endl;
	return "";
}

English::English()
{
	welcomeLogin = "  Welcome to Login the Employee Profile Management System   ";
	welcomeRegister = "  Welcome to Register in the Employee Profile Management System   ";
	forgetPassword = "  Forgot Password   ";
	isExit = "Exit?";
	yesOrNo = "1. Yes 2. No";
	selectFunction = "\t    1. Ascending by Employee ID 2. Descending by Employee ID 3. Ascending by Age 4. Descending by Age"
		"5. Ascending by Hire Date 6. Descending by Hire Date 7. Go to Page 8. Change Items Per Page 9. Fuzzy Query Press \t\tESC to Exit";
	currentPage = "\nCurrent Page: ";
	page = "/Page";
	leftOrRight = "\tLeft: A/○\tRight: D/★";
	totalEmployee = "Total Employees: ";
	updateByIdOrIdNumber = "1. Update Employee by ID 2. Update Employee by ID Number Press \t\tESC to Exit";
	deleteByIdOrIdNumber = "1. Delete Employee by ID 2. Delete Employee by ID Number Press \t\tESC to Exit";
	selectTime = "Current Query Time: ";
	close = "Window will close in 3 seconds.";
	userName = "Username: ";

	exitSuccess = "\nExit successful!";
	loginSuccess = "Login successful";
	registerSuccess = "Registration successful";

	inputUserName = "Please enter username: ";
	inputPassword = "Please enter password: ";
	inputConfirmPassword = "Please enter password again: ";
	inputPhone = "Please enter phone number: ";
	inputCode = "Please enter verification code: ";
	inputPageNum = "\nPlease enter page number: ";
	inputNum = "Please enter a number!";
	inputNumPerPage = "\nPlease enter items per page: ";
	inputOneOrTwo = "Please press 1 or 2";
	inputSelectContent = "\nPlease enter query content: ";

	userNameNotExist = "Username does not exist, please register first";
	userNameAlreadyExist = "Username already exists, please enter a different one";
	phoneAlreadyExist = "Phone number already exists, please enter a different one";

	passwordDifferent = "Passwords do not match, please try again!";
	userNameOrPasswordError = "Incorrect username or password, please try again!";
	overtime = "Operation timed out, over 60 seconds";
	codeError = "Incorrect verification code, please try again: ";
	numTooLong = "Number is too large, exceeds the allowed range!";
	canNotOpen = "Cannot open file: ";

	pressEnter = "Press Enter to resend";

	KEY_ERROR = "Please press the correct KEY!";

	// -----------------------User------------------------

	canCreateTemp = "Cannot create temporary file!";
	inputNewPassword = "Please enter new password: ";
	phone = "Phone number is ";
	updatePasswordSuccess = " user's password has been successfully updated.";
	saveUser = "User data saved to: ";
	wait = "Please wait...";
	sending = "Sending";
	sended = "Code has been sent to phone number ";
	sendCode = " Send code: ";
	timeValid = "\t(Valid for 60 seconds)";
	phoneNotRegister = "This phone number is not registered!";
	passwordShort = "Password length should be at least 6 characters, please try again: ";
	passwordLong = "\nPassword length should not exceed 20 characters, please try again: ";

	// -----------------------EmployeeProfile------------------------

	employeeId = "Employee ID is ";
	employeeAlreadyDel = " employee record has been successfully deleted.";
	idNum = "ID number is ";
	employeeIdNotFound = "Employee record with ID ";
	employeeRecord = " not found.";
	idNumNotFound = "Employee record with ID number ";
	inputEmployeeId = "Please enter employee ID: ";
	inputIdNum = "Please enter ID number: ";
	employeeSaveTo = "Employee data saved to: ";
	ratainOldVal = "Press Enter to retain old data\n\nOld value: ";
	catNotUpdate = "Cannot update";
	oldVal = "Old value: ";
	newVal = "New value: ";
	idNumFormatError = "Invalid ID number format!\nPlease enter ID number again: ";
	idNumAlreadyExist = "ID number already exists!\nPlease enter ID number again: ";
	reinputPhone = "Please re-enter phone number: ";
	employeePhoneAlreadyExist = "Phone number already exists!\nPlease enter phone number again: ";
	employeeUpdateSuccess = " employee record has been successfully updated.";
	phoneFormatError = "Invalid phone number format!";
	employeeIdFormat = "Employee ID (length is 10 digits, first four digits are between 1956 and the current year):";
	employeeIdFormatError = "Invalid employee ID format!";
	employeeIdAlreadyExist = "Employee ID already exists!";
	employeeName = "Employee name: ";
	inputIdNum2 = "ID number (X is uppercase): ";
	idNumFormatError2 = "Invalid ID number format!";
	idNumAlreadyExist2 = "ID number already exists!";
	gender = "Gender: ";
	age = "Age: ";
	employeePhone = "Phone: ";
	phoneAlreadyExist2 = "Phone number already exists!";
	address = "Address: ";
	education = "Education: ";
	position = "Position: ";
	hireDate = "Hire Date: ";
	department = "Department: ";

}

