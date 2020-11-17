#pragma once
#ifndef PERSON_H
#include <iostream>
#include "Date.h"
#include "Adress.h"


struct Person
{
private:
	std::string _name;
	std::string _surname;
	Adress _permanentResidence;
	Date _dateOfBirth;
public:
	Person();
	Person(std::string _name, std::string _surname, Adress _permanentResidence, Date _dateOfBirth);
	~Person();
	friend ostream& operator<<(ostream& read, const Person& data);
	friend istream& operator>>(istream& write, Person& data);
};

#endif // !PERSON_H