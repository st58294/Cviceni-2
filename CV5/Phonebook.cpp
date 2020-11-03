#include "Phonebook.h"
#include "Exception.h"

void Model::Phonebook::addPerson(Entity::Person p){
    listElement* newElement = new listElement{};
    newElement->data = p;
    newElement->next = begin;
    begin = newElement;
}

string Model::Phonebook::FindPhone(string name) const{
    if (name._Equal("")) {
        throw WrongInputException("Parameter NAME is wrong.");
    }
        listElement* element = begin;
        while (element != nullptr) {
            if (element->data.getName() == name){
                return element->data.getPhoneNumber();
            }
            element = element->next;
        }
        throw NoSuchElementException("Person doesn't exist.");

   
}

string Model::Phonebook::FindPhone(int id) const {
    if (id <= 0) {
        throw WrongInputException("ID must be positive number.");
    }
        listElement* newElement = begin;
        while (newElement != nullptr) {
            if (newElement->data.getId() == id) {
                return newElement->data.getPhoneNumber();
            }
            newElement = newElement->next;
        }
        throw NoSuchElementException("Person doesn't exist.");
    
}

Model::Phonebook::Phonebook(){
   

}

Model::Phonebook::~Phonebook(){
    listElement* newElement = new listElement{};
    while (newElement != nullptr) {
        listElement* tmp = newElement->next;
        delete newElement;
        newElement = tmp;
    }
}
