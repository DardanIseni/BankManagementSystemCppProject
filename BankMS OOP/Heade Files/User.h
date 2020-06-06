#pragma once
#ifndef USERADMIN_H
#define USERADMIN_H
#include <string>
#include <cstdlib>
#include "human.h"
#include "kredi.h"
class User:public Human,public Kredi//inheritance from Human and Credit
{
private://private members
	float income, outcome, deposit;
public:
	//constructor
	User();
	//set/get functions
	void setincome(float);
	float getincome();
	void setoutcome(float);
	float getoutcome();
	void setdeposit(float);
	float getdeposit();
	//Polymorphysm
	virtual void PrintUsers();
};


#endif // !USER_H
