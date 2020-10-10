#include "CashRegister.h"
#include <execution>
#include "Receipt.h"
#include <iostream>
#include <stdexcept>

#define ID_COUNTER_INIT_VALUE 1000

CashRegister::CashRegister(){
	receipts  = new Receipt[10];
}

CashRegister::~CashRegister() {
	delete[] receipts;
}
Receipt& CashRegister::CreateReceipt(double cost, double dph) {
	if (receiptsCount == 10) {
	
	}
	else {
		receipts[receiptsCount].SetId(ID_COUNTER_INIT_VALUE + receiptsCount);
		receipts[receiptsCount].SetPrice(cost);
		receipts[receiptsCount].SetDPH(dph);
		receiptsCount++;
		return receipts[receiptsCount - 1];
	}
}
Receipt& CashRegister::GetReceipt(int index){
	for (size_t i = 0; i < receiptsCount; i++)
	{
		if (receipts[i].GetId() == index) {
			return receipts[i];
		}
	}
	return receipts[0];
}
double CashRegister::GetCost() const {
	double cost = 0;
	for (size_t i = 0; i < receiptsCount; i++)
	{
		cost += receipts[i].GetPrice();
	}
	return cost;
}
double CashRegister::GetCostAndDph() const {
	double CostWithDPH = 0;
	for (size_t i = 0; i < receiptsCount; i++)
	{
		CostWithDPH += receipts[i].GetPrice() * (1 + receipts[i].GetDPH());
	}
	return CostWithDPH;
}
