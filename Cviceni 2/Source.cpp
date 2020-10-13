#include <iostream>
#include "Receipt.h"
#include "CashRegister.h"

using namespace std;

int main(int argc, char** argv) {
	Receipt* receipt1 = new Receipt();

	receipt1->SetId(10);
    receipt1->SetPrice(15);
    receipt1->SetDPH(55);
    
    cout << receipt1->GetId() << "\n";
    cout << receipt1->GetPrice() << "\n";
    cout << receipt1->GetDPH() << "\n";
    delete receipt1;
    cout << "\n";

    CashRegister* cashRegister1 = new CashRegister{};

    Receipt receipt2 = cashRegister1->CreateReceipt(21 , 0.25);
    cout << cashRegister1->GetReceipt(receipt2.GetId()).GetPrice() << "\n";
    cout << cashRegister1->GetReceipt(receipt2.GetId()).GetDPH() << "\n";
    cout << cashRegister1->GetCost() << "\n";
    cout << cashRegister1->GetCostAndDph() << "\n";
    
    cout << "\n";

    Receipt receipt3 = cashRegister1->CreateReceipt(45, 0.5);
    cout << cashRegister1->GetReceipt(receipt3.GetId()).GetPrice() << "\n";
    cout << cashRegister1->GetReceipt(receipt3.GetId()).GetDPH() << "\n";
    cout << cashRegister1->GetCost() << "\n";
    cout << cashRegister1->GetCostAndDph() << "\n";
    
    try
    {
    Receipt receipt4 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt5 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt6 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt7 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt8 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt9 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt10 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt11 = cashRegister1->CreateReceipt(45, 0.5);
    Receipt receipt12 = cashRegister1->CreateReceipt(45, 0.5);
    }
    catch (const std::exception&)
    {

    }
    delete cashRegister1;
	system("pause");
	return 0;
}