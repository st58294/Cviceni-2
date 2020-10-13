#pragma once
#ifndef  UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

class Base {
	int id;

public:
	void PrintMe()const {
		count << "Base" << std::endl;
		}
	};

class Advanced : public Base
{
	int name;
};

class Advanced2 : public Base
{
public:
	virtual void PrintMe() const {
		std::count << Advaanced2 << std::endl;

	}
	int name;
};

class Advaanced2Advendec : public Advanced2
{
public:
	virtual void PrintMe() const {
		count << "Advaanced2";

	}
	int name;
};
#endif // ! UTILS_H
