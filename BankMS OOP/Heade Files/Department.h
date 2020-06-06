#pragma once
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
//Department class
class Department
{
private:
	std::string department, position, branch;
public:
	Department();
	//set and get
	void setdepartment();
	std::string getdepartment();
	void setposition();
	std::string getposition();
	void setbranch(std::string);
	std::string getbranch();
};
#endif // !DEPARTMENT_H
