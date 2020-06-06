//klasa me te dhena baze qe do trashegohet ne user dhe employer
#pragma once
#ifndef HUMAN_H
#define HUMAN_H
#include <string>

class Human
{
private://protected pra do kene qasje vetem nga derived class
	std::string name;
	std::string surname;
	std::string city;
	int ID;
public:
	Human();
	void setname(std::string n);
	std::string getname();
	void setsurname(std::string n);
	std::string getsurname();
	void setcity(std::string n);
	std::string getcity();
	void setID(int);
	int getID();
};
#endif // !HUMAN_H

