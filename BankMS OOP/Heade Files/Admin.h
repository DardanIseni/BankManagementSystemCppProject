//Admin class header file
#pragma once
#ifndef BANKADMIN_H
#define BANKADMIN_H
#include "User.h"//agregattion
#include "Employe.h"//agregattion
class Admin: public User,public Employe
{
private:
	int numofusers,numofemployes;//icrements
	User user[100];//user array
	Employe employee[100];//employers array

public:
	Admin();//constructor
	void AddUsers();//adding users
	void AddCredit();//adding credit to any of our users in system
	void MoneyTransfer();//transfering money
	
	//virtual function
	virtual void PrintUsers();//printing users

	void SearchUsers();//search for users
	void SortFilterUsers();//sorting algorithm for users
	void AddEmployee();//adding employers
	void CalculateSalary();//calculating salary based on department and position
	
	//virtual function
	virtual void PrintEmploye();//printing empl

	void SortFilterEmployers();//sorting and filtering users
	void SearchEmployers();//employers search
	void sum();//This function will calculate the sum depositet to our bank


	//overloaded functions
	void AddFromMain(std::string, std::string, std::string,int,float,float,float);//help us add users from script
	// add employers from script
	void AddFromMain(std::string, std::string, std::string, int, std::string, std::string, std::string, int,float); 
	
	

};
#endif // !BANKADMIN_H

