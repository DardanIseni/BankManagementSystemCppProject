#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
#include "human.h"
Human::Human() {
	name = "";
	surname = "";
	city = "";
	ID = 0;
}
//set/get name
void Human::setname(string n) {
	name = n;
}
string Human::getname() {
	return name;

}
//set/get surname
void Human::setsurname(string n) {
	surname = n;
}
string Human::getsurname() {
	return surname;

}
//set get city
void Human::setcity(string n) {
	city = n;
}
string Human::getcity() {
	return city;

}
//set get ID
void Human::setID(int _id) {
	ID = _id;
}

int Human::getID()
{
	return ID;
}
