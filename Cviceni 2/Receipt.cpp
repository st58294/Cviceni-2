#include "Receipt.h"

void Receipt::SetId(int id) {
	this->id = id;
}

int Receipt::GetId()const {
	return this->id;
}
void Receipt::SetPrice(double price){
	this->price = price;
}

double Receipt::GetPrice() const{
	return price;
}
void Receipt::SetDPH(double dph){
	this->dph = dph;
}
double Receipt::GetDPH() const{
	return this->dph;
}



