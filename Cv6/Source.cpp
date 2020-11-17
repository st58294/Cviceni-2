#include <iostream>
#include "IncreasingCoefficient.h"
#include <string>
#include<cstdlib>
#include <exception>

using namespace std;

int main(int argc, char** argv) {
    
	IncreasingCoefficient<int, 5> cont = IncreasingCoefficient<int, 5>();
	
	for (int i = 0; i < 12; i++){
		cont.add(i);
	}
	cout << "Number of elements:  " << cont.count() << endl << endl;
	
	for (int i = 0; i < cont.count(); i++) {
		cout << cont[i] << endl;
	}

	cout << "" << endl;
	cout << "Remove from" << endl << endl;
	cont.removeFrom(6);

	for (int i = 0; i < cont.count(); i++) {
		cout << cont[i] << endl;
	}

	cout << "" << endl;
	cout << "Add to index" << endl << endl;

	cont.addTo(5, 666);

	for (int i = 0; i < cont.count(); i++) {
		cout << cont[i] << endl;
	}

    system("pause");
    return 0;
}