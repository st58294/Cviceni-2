#include "Person.h"

using namespace std;

Person::Person()
{
}

Person::Person(string _name, string _surname,
	Address _permanentResidence, Date _dateOfBirth){

	this->_name = _name;
	this->_surname = _surname;
	this->_permanentResidence = _permanentResidence;
	this->_dateOfBirth = _dateOfBirth;
}

ostream& operator<<(ostream& output, const Person& data){
	output << data._name << " " << data._surname << " " 
		<< data._permanentResidence << " " << data._dateOfBirth << endl;
	return output;

}

istream& operator>>(istream& input, Person& data){
	input >> data._name;
	input >> data._surname;
	input >> data._permanentResidence;
	input >> data._dateOfBirth;
	return input;
}

void toString(Person& data) {
	
	
}
