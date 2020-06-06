//header qe do na ndihmoje te caktojme kredi per userin
#pragma once
#ifndef KREDI_H
#define KREDI_H
class Kredi
{
private://variabla private
	float ValueOfCredit, MonthsToPay, interest, MonthlyRate;
public://funksione publike
	Kredi();//constructor
	//Set and get functions
	void setinterest();
	float getinterest();
	void setvalueofcredit(float);
	float getvalueofcredit();
	void setinstallments(float);
	float getinstallments();
	void setMonthlyInstallmentRate(float);
	float getMonthlyInstallmentRate();

	void calculateCredit();//function for calculating the credit
};
#endif // !KREDI_H

