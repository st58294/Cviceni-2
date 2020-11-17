#include "Person.h"

using namespace std;

Person::Person()
{
}

Person::Person(string _name, string _surname,
	Adress _permanentResidence, Date _dateOfBirth){

	this->_name = _name;
	this->_surname = _surname;
	this->_permanentResidence = _permanentResidence;
	this->_dateOfBirth = _dateOfBirth;
}

ostream& operator<<(ostream& read, const Person& data){
	read << data._name << " " << data._surname << " " 
		<< data._permanentResidence << " " << data._dateOfBirth << endl;
	return read;

}

istream& operator>>(istream& write, Person& data){
	write >> data._name;
	write >> data._surname;
	write >> data._permanentResidence;
	write >> data._dateOfBirth;
	return write;
}
