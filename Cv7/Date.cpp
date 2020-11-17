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

ostream& operator<<(ostream& read, const Date& data){
	read << data._day << " " << data._month << " " << data._year;
	return read;
}

istream& operator>>(istream& write, Date& data){
	write >> data._day;
	write >> data._month;
	write >> data._year;
	return write;
}
