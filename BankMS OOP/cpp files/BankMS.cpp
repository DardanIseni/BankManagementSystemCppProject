#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Admin.h"
using namespace std;
int main() {
	system("color f0");//make cmd white
	Admin admin; //Main Object
	
	//for calling the virtual function 
	User* u;  Employe* e;
	u = &admin;//base pointer to derived object
	e = &admin;//base pointer to derived object

	//adding manualy users
	admin.AddFromMain("Dardan", "Iseni", "Bogovine",28489,750,100,1000);
	admin.AddFromMain("Drenas", "Dika", "Diber", 28359, 450, 145, 20000);
	admin.AddFromMain("Enkela", "Bexheti", "Tetove", 28189, 800, 250, 25000);
	admin.AddFromMain("Blerina", "Bexheti", "Tetove", 28594, 750, 240, 3500);
	admin.AddFromMain("Lorik", "Dika", "Diber", 28488, 420, 180, 45000);


	//adding empl manualy 
	admin.AddFromMain("Erion", "Zhuta", "Struge", 12345,"Executive","Intern","Tetovo",1,0);
	admin.AddFromMain("Artan", "Luma", "Tetove", 10000, "Executive", "Head", "Tetovo", 4, 1500);
	admin.AddFromMain("Lejla", "Abazi", "Tetove", 11020, "Finance", "Senior", "Skopje", 2, 1000);
	admin.AddFromMain("Halil", "Snopce", "Gostivar", 14151, "Loan Office", "Associate", "Skopje", 4, 750);
	admin.AddFromMain("Besart", "Sinani", "Kamjan", 21232, "Accounting", "Intern", "Tetovo", 1, 0);

menu:
	cout << setw(80) << "		   Bank Management System" << setw(1) << "  " << setw(7) <<2020 << " " << endl<<endl;
	int menu;
	cout << "                                                                            Menu:" << endl;
	cout << "                                                                    (1)--->Add Users" << endl;
	cout << "                                                                    (2)--->Add Credit" << endl;
	cout << "                                                                    (3)--->Money Transfer" << endl;
	cout << "                                                                    (4)--->Print Users" << endl;
	cout << "                                                                    (5)--->Search for User" << endl;
	cout << "                                                                    (6)--->Sort and Filter Users" << endl;
	cout << "                                                                    (7)--->Add Employers" << endl;
	cout << "                                                                    (8)--->Print Employers" << endl;
	cout << "                                                                    (9)--->Search for Employers" << endl;
	cout << "                                                                    (10)-->Sort and Filter Employers" << endl;
	cout << "                                                                    (0)--->Total Deposit" << endl;
	cout << "                                                                    (99)---Quit" << endl << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		//ADDING USERS
		admin.AddUsers();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 2:
		//adding credit
		admin.AddCredit();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 3:
		//making transactions
		admin.MoneyTransfer();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 4:
		//printing users
		u->PrintUsers();//accesing to the users list od administrator with base pointer
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 5:
		//searcching useerss
		admin.SearchUsers();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 6:
		//searcching useerss
		admin.SortFilterUsers();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 7:
		//adding employers
		admin.AddEmployee();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 8:
		//printing employers
		e->PrintEmploye();//accesing to the employer list od administrator with base pointer
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 9:
		//searching employers
		admin.SearchEmployers();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 10:
		//sort and filter employers
		admin.SortFilterEmployers();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 0:
		//sum of our bank 
		admin.sum();
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	case 99://quiting
		cout << "Bye thank you";
		return 0;
	
	default:
		cout << "You entered a wrong number,please try again" << endl;;
		cout << "Type enter twice to go to the menu:" << endl;

		cin.get(); cin.get(); cin.get();
		system("CLS");  //This comand will clear the console 
		break;
	}
	goto menu; //This comand wiil return us to menu

	cin.get(); cin.get();
	return 0;
}