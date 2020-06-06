#pragma once
#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "human.h"
#include "Department.h"
class Employe :public Human,public Department
{
private://private elements that an employer class will contain
	int salary, exps;
public:
	Employe();
	void setsalary(int);
	int getsalary();
	void setexperience(int);
	int getexperience();
	
	//virtual function
	virtual void PrintEmploye();
};
#endif // !1

