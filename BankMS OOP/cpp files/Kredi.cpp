#include <iostream>
using namespace std;
#include "kredi.h"


//constructor
Kredi::Kredi() {
	ValueOfCredit = 0;
	MonthsToPay = 0;
	MonthlyRate = 0;
	interest = 0;
}


//set for months of credits
void Kredi::setinstallments(float n) {
	MonthsToPay = n;
}

float Kredi::getinstallments() {
	return MonthsToPay;
}

//set/get for value of credit
void Kredi::setvalueofcredit(float n) {
	ValueOfCredit = n;
}
float Kredi::getvalueofcredit() {
	return ValueOfCredit;
}


//set get total credit(monthlyinstallments
void Kredi::setMonthlyInstallmentRate(float n) {
	MonthlyRate = n;
}
float Kredi::getMonthlyInstallmentRate() {
	return MonthlyRate;
}

//Set get the interest of credit
void Kredi::setinterest() {
	cout << "Set interest of credit in % : ";
	cin >> interest;
}
float Kredi::getinterest() {
	return interest / 100;
}

//calculating the credit
void Kredi::calculateCredit() {
	cout << "Set the total value of Credit in $ : ";
	cin >> ValueOfCredit;
	cout << "For how many installments do you want to pay the credit: ";
	cin >> MonthsToPay;
	MonthlyRate = (ValueOfCredit / MonthsToPay)*getinterest();//calculating the monthly rate
	//setting all variables to their positions
	setMonthlyInstallmentRate(MonthlyRate);
	setinstallments(MonthsToPay);
	setvalueofcredit(ValueOfCredit);
}
