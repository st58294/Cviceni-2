#include <string>
#include "Adress.h"

using namespace std;

Adress::Adress()
{
}

Adress::Adress(string _street, string _city, int _zipCode) {
    this->_city = _city;
    this->_street = _city;
    this->_zipCode = _zipCode;
}

Adress::~Adress()
{
}

ostream& operator<<(ostream& read, const Adress& data) {
    read << data._city << " - " << data._street << " - " << data._zipCode << endl;
    return read;
}

istream& operator>>(istream& write, Adress& data) {
    write >> data._city;
    write >> data._street;
    write >> data._zipCode;

    return write;
}
