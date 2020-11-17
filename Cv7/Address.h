#pragma once
#ifndef ADRESS_H
#include <iostream>


struct Address
{
private:
	std::string _street;
	std::string _city;
	int _zipCode;

public:
	Address();
	Address(std::string _street, std::string _city, int _zipCode);
	~Address();
	friend std::ostream& operator<<(std::ostream& read, const Address& data);
	friend std::istream& operator>>(std::istream& write, Address& data);
};

#endif // !ADRESS_H