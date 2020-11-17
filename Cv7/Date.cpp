#include "Date.h"

Date::Date(){ 
}

Date::Date(int _day, int _month, int _year){ 
	this->_day = _day;
	this->_month = _month;
	this->_year = _year;
}

Date::~Date(){
	
}

ostream& operator<<(ostream& output, const Date& data){
	output << data._day << " " << data._month << " " << data._year;
	return output;
}

istream& operator>>(istream& input, Date& data){
	input >> data._day;
	input >> data._month;
	input >> data._year;
	return input;
}
