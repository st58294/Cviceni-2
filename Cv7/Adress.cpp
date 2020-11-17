#include <string>
#include "Address.h"

using namespace std;

Address::Address()
{
}

Address::Address(string _street, string _city, int _zipCode) {
    this->_city = _city;
    this->_street = _city;
    this->_zipCode = _zipCode;
}

Address::~Address()
{
}

ostream& operator<<(ostream& output, const Address& data) {
    output << data._city << " " << data._street << " " << data._zipCode << " ";
    return output;
}

istream& operator>>(istream& input, Address& data) {
    input >> data._city;
    input >> data._street;
    input >> data._zipCode;

    return input;
}
