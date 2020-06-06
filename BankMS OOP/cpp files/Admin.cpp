#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Admin.h"

//constructor
Admin::Admin() {
	numofemployes = 0;
	numofusers = 0;
}

//Add user function definition
void Admin::AddUsers() {
	char ask;//a variable that will help us to make a decision at switch 
	//some friend variables
	string namee,surnamee,cityy;
	int id;
	float income, outcome, deposit;
	//start

	cout << "Name: ";
	cin >> namee;
	user[numofusers].setname(namee);//assign name to setname function

	cout << "Surname: ";
	cin >> surnamee;
	user[numofusers].setsurname(surnamee); //assign variable to setfunction

	cout << "City: ";
	cin >> cityy;
	user[numofusers].setcity(cityy);//assign variable to setfunction

	cout << "ID: ";
	cin >> id;
	user[numofusers].setID(id);

	cout << "Income: ";
	cin >> income;
	user[numofusers].setincome(income);

	cout << "Outcome: ";
	cin >> outcome;
	user[numofusers].setoutcome(outcome);

	cout << "Deposit: ";
	cin >> deposit;
	user[numofusers].setdeposit(deposit);

	//Asking for credit and making a decision
	cout << "Does the user wants to get credit?Y/N : " ;
	cin >> ask;
	ask=tolower(ask);//convertin input to lower
	switch (ask)//making  a decision
	{
	case'y'://if yes do...
		user[numofusers].setinterest();//calculating the interest rate of a credit
		user[numofusers].calculateCredit();//calculating credit
		break;
	case 'n'://if no do nothing.....skip
		break;
	default:
		cout << "An error ocurred,we added the client to system without credit"<<endl;
		break;
	}
	//increasing the icrement for one
	numofusers +=1;
}
//Adding credit to a user
void Admin::AddCredit() {
	char ask;
	int id;
	std::string name;
	cout << endl;
	cout << "Choose with what do you want to search a user 1/2: " << endl;
	cout << "1.ID" << endl;
	cout << "2.Name/surname/city "<<endl;
	cin >> ask;
	switch (ask)
	{
	case '1':
		cout << "Enter the ID ";
		cin >> id;
		for (int i = 0; i < numofusers; i++)
			if (user[i].getID() == id) {
				user[i].setinterest();//calculating the interest rate of a credit
				user[i].calculateCredit();//calculating credit
				cout << "You added succesfully credit to the user: " << user[i].getname() << " " << user[i].getsurname()<<endl;
			}
		break;
	case '2':
		cout << "Enter name,surname or city: ";
		cin >> name;
		for (int i = 0; i < numofusers; i++)
			if(name==user[i].getname() || name== user[i].getsurname() || name==user[i].getcity()){
				user[i].setinterest();//calculating the interest rate of a credit
				user[i].calculateCredit();//calculating credit
				cout << "You added succesfully credit to the user: " << user[i].getname() << " " << user[i].getsurname();
				cout << endl;
			}
			else
				cout << "You dont have a user with thoose informations please try again later" << endl;
		break;
	default:
		cout << "Something went wrong "<<endl;
		break;
	}
}
//Transfering money function definiton
void Admin::MoneyTransfer() {
	int ask;
	cout << "Choose "
		<< "1.For transfering money inside our bank "
		<< "2.For transfering outside of the bank "
		<< "3.For paying online: ";
	cin >> ask;
	switch (ask)
	{
	case 1:
		int id,secondID;//first id is the id of the client that we will get money from and the secondID is the user that will receive
		float money,newdeposit,change;//newdeposit will be the variable to help us do some math
		cout << "Give the id of the account from where you want to transfer: ";
		cin >> id;
		cout << "Give the id of the account where you want to transfer: ";
		cin >> secondID;
		cout << "Enter the value in $: ";
		cin >> money;
	
				//making the difference
		for (int i = 0; i < numofusers; i++)
			if (user[i].getID() == id) {
				change = user[i].getdeposit() - money; //making changes to the user that will send moneys
				user[i].setdeposit(change);

			}
		//transferring the money
		for (int i = 0; i < numofusers; i++)
			if (user[i].getID() == secondID) {
				newdeposit = user[i].getdeposit() + money;
				user[i].setdeposit(newdeposit);
			}
		break;
	case 2:
		int  iban;
		cout << "Give the id of the account from where you want to transfer: ";
		cin >> id;
		cout << "Give the iban of the account where you want to transfer: ";
		cin >> iban;
		cout << "Enter the value in $: ";
		cin >> money;
		//transferring the money
		for (int i = 0; i < numofusers; i++)
			if (user[i].getID() == id) {
				newdeposit = user[i].getdeposit() - money;
				user[i].setdeposit(newdeposit);
			}
		break;
	case 3:
		int TransactionID;
		cout << "Give the id of the account from where you want to transfer: ";
		cin >> id;
		cout << "Give the transaction ID to make the payment: ";
		cin >> TransactionID;
		cout << "Enter the value in $: ";
		cin >> money;
		//transferring the money
		for (int i = 0; i < numofusers; i++)
			if (user[i].getID() == id) {
				newdeposit = user[i].getdeposit() - money;
				user[i].setdeposit(newdeposit);
			}
		break;
	default:
		cout << "Something went wrong please try again later"<<endl;
		break;
	}
}

//printing users
void Admin::PrintUsers() {
	//some iomanip
	cout << endl;
	cout << "The list of the users: " << endl;
	cout << setw(4) << "ID:  " << setw(1) << "|"
		<< setw(15) << "Firstname" << setw(1) << "|"
		<< setw(15) << "Lastname" << setw(1) << "|"
		<< setw(15) << "City" << setw(1) << "|"
		<< setw(15) << "Income" << setw(1) << "|"
		<< setw(15) << "Outcome" << setw(1) << "|"
		<< setw(15) << "Deposit" << setw(1) << "|"
		<< setw(15) << "ValueOfCredit" << setw(1) << "|"
		<< setw(15) << "Installments" << setw(1) << "|"
		<< setw(15) << "MonthlyRate" << setw(1) << "|" << endl;
	//looping throw users from 0 to num of users and getting values from their get functions
	for (int i = 0; i < numofusers; i++) {
		cout << setw(4) << user[i].getID() << setw(1) << "|";
		cout << setw(15) << user[i].getname() << setw(1) << "|";
		cout << setw(15) << user[i].getsurname() << setw(1) << "|";
		cout << setw(15) << user[i].getcity() << setw(1) << "|";
		cout << setw(15) << user[i].getincome() << setw(1) << "|";
		cout << setw(15) << user[i].getoutcome() << setw(1) << "|";
		cout << setw(15) << user[i].getdeposit() << setw(1) << "|";
		cout << setw(15) << user[i].getvalueofcredit() << setw(1) << "|";
		cout << setw(15) << user[i].getinstallments() << setw(1) << "|";
		cout << setw(15) << user[i].getMonthlyInstallmentRate() << setw(1) << "|";

		cout << endl;
	}
}
//search user function definition
void Admin::SearchUsers() {
	string text;
	cout << "Enter text: ";
	cin >> text;
	cout << setw(4) << "ID:  " << setw(1) << "|"
		<< setw(15) << "Firstname" << setw(1) << "|"
		<< setw(15) << "Lastname" << setw(1) << "|"
		<< setw(15) << "City" << setw(1) << "|"
		<< setw(15) << "Income" << setw(1) << "|"
		<< setw(15) << "Outcome" << setw(1) << "|"
		<< setw(15) << "Deposit" << setw(1) << "|"
		<< setw(15) << "ValueOfCredit" << setw(1) << "|"
		<< setw(15) << "Installments" << setw(1) << "|"
		<< setw(15) << "MonthlyRate" << setw(1) << "|" << endl;
	for (int i = 0; i < numofusers; i++)
		if (text == user[i].getname() || text == user[i].getsurname() || text == user[i].getcity()) {
			cout << setw(4) << user[i].getID() << setw(1) << "|";
			cout << setw(15) << user[i].getname() << setw(1) << "|";
			cout << setw(15) << user[i].getsurname() << setw(1) << "|";
			cout << setw(15) << user[i].getcity() << setw(1) << "|";
			cout << setw(15) << user[i].getincome() << setw(1) << "|";
			cout << setw(15) << user[i].getoutcome() << setw(1) << "|";
			cout << setw(15) << user[i].getdeposit() << setw(1) << "|";
			cout << setw(15) << user[i].getvalueofcredit() << setw(1) << "|";
			cout << setw(15) << user[i].getinstallments() << setw(1) << "|";
			cout << setw(15) << user[i].getMonthlyInstallmentRate() << setw(1) << "|";

			cout << endl;
		}
			
}
//sorting for users
void Admin::SortFilterUsers() {
	User hold;
	int ask;
	cout << "Choce what do you want to do"<<endl;
	cout << "1.Sort by deposit amount 2.Sort by Value of credit 3.Filter with credit 4.Filter without credit";
	cin >> ask;
	switch (ask)
	{
	case 1:
		cout << setw(4) << "ID:  " << setw(1) << "|"
			<< setw(15) << "Firstname" << setw(1) << "|"
			<< setw(15) << "Lastname" << setw(1) << "|"
			<< setw(15) << "City" << setw(1) << "|"
			<< setw(15) << "Income" << setw(1) << "|"
			<< setw(15) << "Outcome" << setw(1) << "|"
			<< setw(15) << "Deposit" << setw(1) << "|"
			<< setw(15) << "ValueOfCredit" << setw(1) << "|"
			<< setw(15) << "Installments" << setw(1) << "|"
			<< setw(15) << "MonthlyRate" << setw(1) << "|" << endl << endl;
		for(int i=0;i<numofusers;i++)
			for(int j=i+1;j<numofusers;j++)
				if (user[i].getdeposit() < user[j].getdeposit()) {
					hold = user[i];
					user[i] = user[j];
					user[j] = hold;
					
				}
		for (int i = 0; i < numofusers; i++) {
			cout << setw(4) << user[i].getID() << setw(1) << "|";
			cout << setw(15) << user[i].getname() << setw(1) << "|";
			cout << setw(15) << user[i].getsurname() << setw(1) << "|";
			cout << setw(15) << user[i].getcity() << setw(1) << "|";
			cout << setw(15) << user[i].getincome() << setw(1) << "|";
			cout << setw(15) << user[i].getoutcome() << setw(1) << "|";
			cout << setw(15) << user[i].getdeposit() << setw(1) << "|";
			cout << setw(15) << user[i].getvalueofcredit() << setw(1) << "|";
			cout << setw(15) << user[i].getinstallments() << setw(1) << "|";
			cout << setw(15) << user[i].getMonthlyInstallmentRate() << setw(1) << "|";

			cout << endl;
		}
		break;
	case 2:
		cout << setw(4) << "ID:  " << setw(1) << "|"
			<< setw(15) << "Firstname" << setw(1) << "|"
			<< setw(15) << "Lastname" << setw(1) << "|"
			<< setw(15) << "City" << setw(1) << "|"
			<< setw(15) << "Income" << setw(1) << "|"
			<< setw(15) << "Outcome" << setw(1) << "|"
			<< setw(15) << "Deposit" << setw(1) << "|"
			<< setw(15) << "ValueOfCredit" << setw(1) << "|"
			<< setw(15) << "Installments" << setw(1) << "|"
			<< setw(15) << "MonthlyRate" << setw(1) << "|" << endl << endl;
		for (int i = 0; i < numofusers; i++)
			for (int j = i + 1; j < numofusers-1; j++)
				if (user[i].getvalueofcredit() < user[j].getvalueofcredit()) {
					hold = user[i];
					user[i] = user[j];
					user[j] = hold;
					
				}
		for (int i = 0; i < numofusers; i++) {
			cout << setw(4) << user[i].getID() << setw(1) << "|";
			cout << setw(15) << user[i].getname() << setw(1) << "|";
			cout << setw(15) << user[i].getsurname() << setw(1) << "|";
			cout << setw(15) << user[i].getcity() << setw(1) << "|";
			cout << setw(15) << user[i].getincome() << setw(1) << "|";
			cout << setw(15) << user[i].getoutcome() << setw(1) << "|";
			cout << setw(15) << user[i].getdeposit() << setw(1) << "|";
			cout << setw(15) << user[i].getvalueofcredit() << setw(1) << "|";
			cout << setw(15) << user[i].getinstallments() << setw(1) << "|";
			cout << setw(15) << user[i].getMonthlyInstallmentRate() << setw(1) << "|";

			cout << endl;
		}
		break;
	case 3:
		cout << setw(4) << "ID:  " << setw(1) << "|"
			<< setw(15) << "Firstname" << setw(1) << "|"
			<< setw(15) << "Lastname" << setw(1) << "|"
			<< setw(15) << "City" << setw(1) << "|"
			<< setw(15) << "Income" << setw(1) << "|"
			<< setw(15) << "Outcome" << setw(1) << "|"
			<< setw(15) << "Deposit" << setw(1) << "|"
			<< setw(15) << "ValueOfCredit" << setw(1) << "|"
			<< setw(15) << "Installments" << setw(1) << "|"
			<< setw(15) << "MonthlyRate" << setw(1) << "|" << endl << endl;
		for(int i=0;i<numofusers;i++)
			if (user[i].getvalueofcredit() > 0) {
				cout << setw(4) << user[i].getID() << setw(1) << "|";
				cout << setw(15) << user[i].getname() << setw(1) << "|";
				cout << setw(15) << user[i].getsurname() << setw(1) << "|";
				cout << setw(15) << user[i].getcity() << setw(1) << "|";
				cout << setw(15) << user[i].getincome() << setw(1) << "|";
				cout << setw(15) << user[i].getoutcome() << setw(1) << "|";
				cout << setw(15) << user[i].getdeposit() << setw(1) << "|";
				cout << setw(15) << user[i].getvalueofcredit() << setw(1) << "|";
				cout << setw(15) << user[i].getinstallments() << setw(1) << "|";
				cout << setw(15) << user[i].getMonthlyInstallmentRate() << setw(1) << "|";
				cout << endl;
			}
		break;
	case 4:
		cout << setw(4) << "ID:  " << setw(1) << "|"
			<< setw(15) << "Firstname" << setw(1) << "|"
			<< setw(15) << "Lastname" << setw(1) << "|"
			<< setw(15) << "City" << setw(1) << "|"
			<< setw(15) << "Income" << setw(1) << "|"
			<< setw(15) << "Outcome" << setw(1) << "|"
			<< setw(15) << "Deposit" << setw(1) << "|"
			<< setw(15) << "ValueOfCredit" << setw(1) << "|"
			<< setw(15) << "Installments" << setw(1) << "|"
			<< setw(15) << "MonthlyRate" << setw(1) << "|" << endl << endl;
		for (int i = 0; i < numofusers; i++)
			if (user[i].getvalueofcredit() == 0) {
				cout << setw(4) << user[i].getID() << setw(1) << "|";
				cout << setw(15) << user[i].getname() << setw(1) << "|";
				cout << setw(15) << user[i].getsurname() << setw(1) << "|";
				cout << setw(15) << user[i].getcity() << setw(1) << "|";
				cout << setw(15) << user[i].getincome() << setw(1) << "|";
				cout << setw(15) << user[i].getoutcome() << setw(1) << "|";
				cout << setw(15) << user[i].getdeposit() << setw(1) << "|";
				cout << setw(15) << user[i].getvalueofcredit() << setw(1) << "|";
				cout << setw(15) << user[i].getinstallments() << setw(1) << "|";
				cout << setw(15) << user[i].getMonthlyInstallmentRate() << setw(1) << "|";
				cout << endl;
			}
		break;
	default:
		cout << "Something went wrong " << endl;
		break;
	}
}

//Salary calculator function for users
void Admin::CalculateSalary() {
	if (employee[numofemployes].getposition() == "Intern" && (employee[numofemployes].getdepartment() == "Finance"
		|| employee[numofemployes].getdepartment() == "Accounting"
		|| employee[numofemployes].getdepartment() == "Loan Office"
		|| employee[numofemployes].getdepartment() == "Executive"
		))
		employee[numofemployes].setsalary(0);//every intern will have 0$ salary

		//end 1st if for interns salary...optimized with some Boolean skills

	else if (employee[numofemployes].getposition() == "Associate" && (employee[numofemployes].getdepartment() == "Finance"
		|| employee[numofemployes].getdepartment() == "Accounting"
		|| employee[numofemployes].getdepartment() == "Loan Office"
		|| employee[numofemployes].getdepartment() == "Executive"
		))
		employee[numofemployes].setsalary(750);//setting the salary
	//end 2nd if for Associate positions salary...optimized with some Boolean skills

	else if (employee[numofemployes].getposition() == "Senior" && (employee[numofemployes].getdepartment() == "Finance"
		|| employee[numofemployes].getdepartment() == "Accounting"
		|| employee[numofemployes].getdepartment() == "Loan Office"
		|| employee[numofemployes].getdepartment() == "Executive"
		))
		employee[numofemployes].setsalary(1000);//setting the salary
	//end 3rd if for Senior positions salary...optimized with some Boolean skills

	else if (employee[numofemployes].getposition() == "Head" && (employee[numofemployes].getdepartment() == "Finance"
		|| employee[numofemployes].getdepartment() == "Accounting"
		|| employee[numofemployes].getdepartment() == "Loan Office"
		|| employee[numofemployes].getdepartment() == "Executive"
		))
		employee[numofemployes].setsalary(1500);//setting the salary
	//end 4th if for Head positions salary...optimized with some Boolean skills
}

//adding employeers
void Admin::AddEmployee() {
	//helping variables
	string name, surname, city,branchh;
	int id,exxp;
	cout << "Name: ";
	cin >> name;
	employee[numofemployes].setname(name);//assign name to setname function

	cout << "Surname: ";
	cin >> surname;
	employee[numofemployes].setsurname(surname);//assign variable to setfunction

	cout << "City: ";
	cin >> city;
	employee[numofemployes].setcity(city);//assign variable to setfunction

	cout << "ID: ";
	cin >> id;
	employee[numofemployes].setID(id);//assign variable to setfunction

	cout << "Department: "<<endl;
	employee[numofemployes].setdepartment();

	cout << "Position: "<<endl;
	employee[numofemployes].setposition();

	cout << "Branch: ";
	cin >> branchh;
	employee[numofemployes].setbranch(branchh);//assign variable to setfunction

	cout << "Experience in years: ";
	cin >> exxp;
	employee[numofemployes].setexperience(exxp);//assign variable to setfunction



	CalculateSalary();

	//increasing the icrement
	numofemployes+=1;
}
//Printing Employers
void Admin::PrintEmploye() {
	cout << "The list of the employees: " << endl;
	cout << setw(4) << "ID:  " << setw(1) << "|"
		<< setw(15) << "Firstname" << setw(1) << "|"
		<< setw(15) << "Lastname" << setw(1) << "|"
		<< setw(15) << "City" << setw(1) << "|" 
		<< setw(15) << "Department" << setw(1) << "|"
		<< setw(15) << "Position" << setw(1) << "|"
		<< setw(15) << "Branch" << setw(1) << "|"
		<< setw(15) << "Experience" << setw(1) << "|"
		<< setw(15) << "Salary" << setw(1) << "|" << endl;
	//looping throw employers from 0 to num of employers and getring values from their get functions
	for (int i = 0; i < numofemployes; i++) {
		cout << setw(5) << employee[i].getID() << setw(1) << "|";
		cout << setw(15) << employee[i].getname() << setw(1) << "|";
		cout << setw(15) << employee[i].getsurname() << setw(1) << "|";
		cout << setw(15) << employee[i].getcity() << setw(1) << "|";
		cout << setw(15) << employee[i].getdepartment() << setw(1) << "|";
		cout << setw(15) << employee[i].getposition() << setw(1) << "|";
		cout << setw(15) << employee[i].getbranch() << setw(1) << "|";
		cout << setw(15) << employee[i].getexperience() << setw(1) << "|";
		cout << setw(15) << employee[i].getsalary() << setw(1) << "|";

		cout << endl;
	}
}

//searching employers
void Admin::SearchEmployers() {
	string text;
	cout << "Enter text: ";
	cin >> text;
	cout << setw(4) << "ID:  " << setw(1) << "|"
		<< setw(15) << "Firstname" << setw(1) << "|"
		<< setw(15) << "Lastname" << setw(1) << "|"
		<< setw(15) << "City" << setw(1) << "|"
		<< setw(15) << "Department" << setw(1) << "|"
		<< setw(15) << "Position" << setw(1) << "|"
		<< setw(15) << "Branch" << setw(1) << "|"
		<< setw(15) << "Experience" << setw(1) << "|"
		<< setw(15) << "Salary" << setw(1) << "|" << endl;
	for (int i = 0; i < numofemployes; i++)
		if (text == employee[i].getname() || text == employee[i].getsurname() || text == employee[i].getcity()) {
			cout << setw(5) << employee[i].getID() << setw(1) << "|";
			cout << setw(15) << employee[i].getname() << setw(1) << "|";
			cout << setw(15) << employee[i].getsurname() << setw(1) << "|";
			cout << setw(15) << employee[i].getcity() << setw(1) << "|";
			cout << setw(15) << employee[i].getdepartment() << setw(1) << "|";
			cout << setw(15) << employee[i].getposition() << setw(1) << "|";
			cout << setw(15) << employee[i].getbranch() << setw(1) << "|";
			cout << setw(15) << employee[i].getexperience() << setw(1) << "|";
			cout << setw(15) << employee[i].getsalary() << setw(1) << "|";


			cout << endl;
		}

}
//Searching and filtering Employers
void Admin::SortFilterEmployers() {
	Employe hold;
	int ask;
	string txt;
	cout << "Choce what do you want to do" << endl;
	cout << "1.Sort by salary amount 2.Sort by experience 3.Filter by position/departament";
	cin >> ask;
	switch (ask)
	{
	case 1:
		//sorting
		for(int i=0;i<numofemployes;i++)
			for(int j=i+1;j<numofemployes;j++)
				if (employee[i].getsalary() < employee[j].getsalary()) {
					hold = employee[i];
					employee[i] = employee[j];
					employee[j] = hold;
				}
		cout << setw(4) << "ID:  " << setw(1) << "|"
			<< setw(15) << "Firstname" << setw(1) << "|"
			<< setw(15) << "Lastname" << setw(1) << "|"
			<< setw(15) << "City" << setw(1) << "|"
			<< setw(15) << "Department" << setw(1) << "|"
			<< setw(15) << "Position" << setw(1) << "|"
			<< setw(15) << "Branch" << setw(1) << "|"
			<< setw(15) << "Experience" << setw(1) << "|"
			<< setw(15) << "Salary" << setw(1) << "|" << endl;
		for (int i = 0; i < numofemployes; i++) {
			cout << setw(5) << employee[i].getID() << setw(1) << "|";
			cout << setw(15) << employee[i].getname() << setw(1) << "|";
			cout << setw(15) << employee[i].getsurname() << setw(1) << "|";
			cout << setw(15) << employee[i].getcity() << setw(1) << "|";
			cout << setw(15) << employee[i].getdepartment() << setw(1) << "|";
			cout << setw(15) << employee[i].getposition() << setw(1) << "|";
			cout << setw(15) << employee[i].getbranch() << setw(1) << "|";
			cout << setw(15) << employee[i].getexperience() << setw(1) << "|";
			cout << setw(15) << employee[i].getsalary() << setw(1) << "|";


			cout << endl;
		}
		break;
	case 2:
		for (int i = 0; i < numofemployes; i++)
			for (int j = i + 1; j < numofemployes; j++)
				if (employee[i].getexperience() < employee[j].getexperience()) {
					hold = employee[i];
					employee[i] = employee[j];
					employee[j] = hold;
				}
		cout << setw(4) << "ID:  " << setw(1) << "|"
			<< setw(15) << "Firstname" << setw(1) << "|"
			<< setw(15) << "Lastname" << setw(1) << "|"
			<< setw(15) << "City" << setw(1) << "|"
			<< setw(15) << "Department" << setw(1) << "|"
			<< setw(15) << "Position" << setw(1) << "|"
			<< setw(15) << "Branch" << setw(1) << "|"
			<< setw(15) << "Experience" << setw(1) << "|"
			<< setw(15) << "Salary" << setw(1) << "|" << endl;
		for (int i = 0; i < numofemployes; i++) {
			cout << setw(5) << employee[i].getID() << setw(1) << "|";
			cout << setw(15) << employee[i].getname() << setw(1) << "|";
			cout << setw(15) << employee[i].getsurname() << setw(1) << "|";
			cout << setw(15) << employee[i].getcity() << setw(1) << "|";
			cout << setw(15) << employee[i].getdepartment() << setw(1) << "|";
			cout << setw(15) << employee[i].getposition() << setw(1) << "|";
			cout << setw(15) << employee[i].getbranch() << setw(1) << "|";
			cout << setw(15) << employee[i].getexperience() << setw(1) << "|";
			cout << setw(15) << employee[i].getsalary() << setw(1) << "|";


			cout << endl;
		}
		break;
	case 3:
		cout << "Enter position(Intern,Associate,Senior,Head) or department(Finance,Accounting,Loan Office,Executive): ";
		cin >> txt;
		cout << setw(4) << "ID:  " << setw(1) << "|"
			<< setw(15) << "Firstname" << setw(1) << "|"
			<< setw(15) << "Lastname" << setw(1) << "|"
			<< setw(15) << "City" << setw(1) << "|"
			<< setw(15) << "Department" << setw(1) << "|"
			<< setw(15) << "Position" << setw(1) << "|"
			<< setw(15) << "Branch" << setw(1) << "|"
			<< setw(15) << "Experience" << setw(1) << "|"
			<< setw(15) << "Salary" << setw(1) << "|" << endl;
		for(int i=0;i<numofemployes;i++)
			if (txt == employee[i].getposition() || txt == employee[i].getdepartment()) {
				cout << setw(5) << employee[i].getID() << setw(1) << "|";
				cout << setw(15) << employee[i].getname() << setw(1) << "|";
				cout << setw(15) << employee[i].getsurname() << setw(1) << "|";
				cout << setw(15) << employee[i].getcity() << setw(1) << "|";
				cout << setw(15) << employee[i].getdepartment() << setw(1) << "|";
				cout << setw(15) << employee[i].getposition() << setw(1) << "|";
				cout << setw(15) << employee[i].getbranch() << setw(1) << "|";
				cout << setw(15) << employee[i].getexperience() << setw(1) << "|";
				cout << setw(15) << employee[i].getsalary() << setw(1) << "|";


				cout << endl;
			}
		break;

	default:
		break;
	}
}

//sum of deposit function

void Admin::sum() {
	float sum = 0;//storing the sum
	for (int i = 0; i < numofusers; i++)
		sum += user[i].getdeposit();
	cout << "Total value of  moneys deposited to our bank is " << sum << " $" << endl;
}



//overloaded function
//adding users
void Admin::AddFromMain(std::string n, std::string s, std::string c, int id, float inc, float out, float dep) {
	user[numofusers].setname(n);//assign name to setname function

	user[numofusers].setsurname(s); //assign variable to setfunction

	user[numofusers].setcity(c);//assign variable to setfunction

	user[numofusers].setID(id);

	user[numofusers].setincome(inc);

	user[numofusers].setoutcome(out);

	user[numofusers].setdeposit(dep);

	user[numofusers].setinstallments(0);

	user[numofusers].setMonthlyInstallmentRate(0);
	user[numofusers].setvalueofcredit(0);
	
	//increasing the icrement for one
	numofusers += 1;
}

//adding empl
void Admin::AddFromMain(std::string n, std::string s, std::string c, int id, std::string dep, std::string pos, std::string br, int exp,float sl) { 
	employee[numofemployes].setname(n);//assign name to setname function

	employee[numofemployes].setsurname(s);//assign variable to setfunction

	employee[numofemployes].setcity(c);//assign variable to setfunction

	employee[numofemployes].setID(id);//assign variable to setfunction

	employee[numofemployes].getdepartment()=dep;

	employee[numofemployes].getposition() = pos;

	employee[numofemployes].setbranch(br);//assign variable to setfunction

	employee[numofemployes].setexperience(exp);//assign variable to setfunction

	employee[numofemployes].setsalary(sl);
	numofemployes += 1;
} //add employers from script

