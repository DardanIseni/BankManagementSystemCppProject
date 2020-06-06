#include <iostream>
#include <string>
using namespace std;
#include "Department.h"

Department::Department() {
	department = " ";
	branch = " ";
	position = " ";
}

//set get Department

void Department::setdepartment() {
	int ask;
	cout << "1.Finance,2.Accounting,3.Loan Office,4.Executive" << endl;
	cin >> ask;
	switch (ask)
	{
	case 1:department = "Finance";
		break;
	case 2:department = "Accounting";
		break;
	case 3:department = "Loan Office";
		break;
	case 4:department = "Executive";
		break;

	default:
		cout << "Something went wrong...error ";
		break;
	}
}

std::string Department::getdepartment() {
	return department;
}

//set get position

void Department::setposition() {
	int ask;
	cout << "1.Intern,2.Associate,3.Senior,4.Head " << endl;
	cin >> ask;
	switch (ask)
	{
	case 1:position = "Intern";
		break;
	case 2:position = "Associate";
		break;
	case 3:position = "Senior";
		break;
	case 4:position = "Head";
		break;
	default:
		cout << "Something went wrong...error ";
		break;
	}
}

std::string Department::getposition() {
	return position;
}

//set get branch

void Department::setbranch(std::string a) {
	branch = a;
}

std::string Department::getbranch() {
	return branch;
}