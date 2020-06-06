#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "User.h"
using namespace std;

//defining functions and constructors....

//constructor definition...assign all values to 0
User::User(){
	income = 0;
	outcome = 0;
	deposit = 0;
}

//set/get income

void User::setincome(float i) {
	income = i;
}

float User:: getincome() {
	return income;
}

//set get outcome

void User::setoutcome(float o) {
	outcome = o;
}

float User::getoutcome() {
	return outcome;
}

//set get deposit

void User::setdeposit(float d) {
	deposit=d;
}

float User::getdeposit() {
	return deposit;
}


//virtual functions polymorphism
void User::PrintUsers() {
	cout << "Name: "<<getname();
	cout << "SurName: " << getsurname();
	cout << "Income: " << getincome();
	cout << "Outcome: " << getoutcome();
	cout << "Deposit: " << getdeposit();
}