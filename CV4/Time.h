#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"


class Time : public IComparable
{
private:
	int hours;
	int minutes;
	int seconds;

public:
	Time(int hours, int minutes, int seconds);
	~Time();
	void organiseField(IComparable** field, int sizeOfField);
	virtual int compareTo(IComparable* obj) const override;
	virtual std::string toString() const override;
};

#endif // !TIME_H