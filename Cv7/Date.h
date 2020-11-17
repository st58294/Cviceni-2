#pragma once
#ifndef DATE_H
#include <iostream>
using namespace std;

struct Date
{
private:
	int _day;
	int _month;
	int _year;

public:
	Date();
	Date(int _day, int _month, int _year);
	~Date();
	friend ostream& operator<<(ostream& read, const Date& data);
	friend istream& operator>>(istream& write, Date& data);
};

#endif // !DATE_H
