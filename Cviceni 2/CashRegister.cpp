#include "CashRegister.h"
#include <execution>
#include "Receipt.h"
#include <iostream>
#include <stdexcept>

int CashRegister::receiptsCount = 1000;

CashRegister::CashRegister(){
	receipts  = new Receipt[10];
}

CashRegister::~CashRegister() {
	delete[] receipts;
}
Receipt& CashRegister::CreateReceipt(double cost, double dph) {
	if (count == 10) {
		throw std::exception("Register is full ");
	}
	else {
		receipts[count].SetId(receiptsCount + count);
		receipts[count].SetPrice(cost);
		receipts[count].SetDPH(dph);
		count++;
		return receipts[count - 1];
	}
}
Receipt& CashRegister::GetReceipt(int identifier){
	for (size_t i = 0; i < count; i++)
	{
		if (receipts[i].GetId() == identifier) {
			return receipts[i];
		}
	}
	return receipts[0];
}
double CashRegister::GetCost() const {
	double cost = 0;
	for (size_t i = 0; i < count; i++)
	{
		cost += receipts[i].GetPrice();
	}
	return cost;
}
double CashRegister::GetCostAndDph() const {
	double CostWithDPH = 0;
	for (size_t i = 0; i < count; i++)
	{
		CostWithDPH += receipts[i].GetPrice() * (1 + receipts[i].GetDPH());
	}
	return CostWithDPH;
}
