#include <iostream>
using namespace std;
#include "Employe.h"



//constructor

Employe::Employe(){
	salary = 0;
	exps = 0;

}
//set get salary
void Employe::setsalary(int s) {
	salary = s;
}

int Employe::getsalary() {
	return salary;
}

//set get salary
void Employe::setexperience(int s) {
	exps = s;
}

int Employe::getexperience() {
	return exps;
}

//virtual function
void Employe::PrintEmploye() {
	cout << "Name: " << getname();
	cout << "Surname: " << getsurname();
	cout << "City: " << getcity();
	cout << "Department: " << getdepartment();
	cout << "Position: " << getposition();
	cout << "Salary: " << getsalary();
	cout << "Branch: " << getbranch();
	cout << "Exp: " << getexperience();
}