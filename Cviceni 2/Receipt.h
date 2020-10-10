#pragma once
#ifndef RECEIP_H
#define RECEIP_H

class Receipt {

private:
	int id;
	double price;
	double dph;
public:
	void SetId(int id);
	int GetId() const;
	
	void SetPrice(double price);
	double GetPrice() const;
	
	void SetDPH(double dph);
	double GetDPH() const;

};

#endif // !RECEIP_H
