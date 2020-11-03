#include<iostream>
#include "Exception.h"
#include "Person.h"
#include "Phonebook.h"

using namespace Entity;
using namespace Model;
using namespace std;

int main(int argc, char** argv) {
    try {
        Phonebook list{};

       Person p1 = Person{ "Tom", "725 469 142", 0 };
       Person p2 = Person{ "Petr", "723 223 055", 1 };
       Person p3 = Person{ "Jirka", "835 322 014", 2 };
       Person p4 = Person{ "Michal", "901 224 210", 3 };
       Person p5 = Person{ "Natálka", "737 212 212", 4 };
  

        list.addPerson(p1);
        list.addPerson(p2);
        list.addPerson(p3);
        list.addPerson(p4);
        list.addPerson(p5);
      

        cout << "The person number with id 3 is: " << list.FindPhone(3) << endl;
        cout << "The phone number with the name Bartolomej is: " << list.FindPhone("Bartolomìj") << endl;

        list.FindPhone(6);

    }
    catch (WrongInputException& ex) {
        cout << ex.getMessage() << endl;
    }
    catch (NoSuchElementException& ex) {
        cout << ex.getMessage() << endl;
    }

	system("pause");
	return 0;
}