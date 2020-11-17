#pragma once
#ifndef ADRESS_H
#include <iostream>


struct Adress
{
private:
	std::string _street;
	std::string _city;
	int _zipCode;

public:
	Adress();
	Adress(std::string _street, std::string _city, int _zipCode);
	~Adress();
	friend std::ostream& operator<<(std::ostream& read, const Adress& data);
	friend std::istream& operator>>(std::istream& write, Adress& data);
};

#endif // !ADRESS_H