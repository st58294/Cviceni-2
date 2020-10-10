#pragma once
#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Receipt.h"

class CashRegister
{
private:
	Receipt* receipt;
	int receiptsCount = 0;
	Receipt* receipts;
public:
	CashRegister();
	~CashRegister();
	Receipt& CreateReceipt(double cost, double dph);
	Receipt& GetReceipt(int);
	double GetCost() const;
	double GetCostAndDph() const;
}

#endif // !Cash_Register_H
;