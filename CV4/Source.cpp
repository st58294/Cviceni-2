#include<iostream>
#include "Time.h"

using namespace std;
void extract(IComparable** field, int sizeOfField) {
	cout << "Field" << endl;
	cout << "" << endl;
	for (size_t i = 0; i < sizeOfField; i++){
		cout << field[i]->toString() << endl;
	}
}

int main(int argc, char** argv) {

	Time* time_1 = new Time(12, 12, 12);
	Time* time_2 = new Time(13, 12, 12);
	Time* time_3 = new Time(12, 13, 12);
	Time* time_4 = new Time(12, 12, 13);
	Time* time_5 = new Time(12, 18, 13);
	Time* time_6 = new Time(12, 12, 13);
	Time* time_7 = new Time(23, 12, 13);
	Time* time_8 = new Time(12, 32, 13);
	Time* time_9 = new Time(18, 00, 13);
	Time* time_10 = new Time(12, 58, 13);

	Time* time_control = new Time(12, 12, 12);


	cout << time_1->compareTo(time_2) << endl;
	cout << time_1->compareTo(time_3) << endl;
	cout << time_1->compareTo(time_4) << endl;

	cout << time_2->compareTo(time_1) << endl;
	cout << time_3->compareTo(time_1) << endl;
	cout << time_4->compareTo(time_1) << endl;


	cout << time_1->compareTo(time_control) << endl;

	int sizeOfField = 10;
	IComparable** field = new IComparable*[sizeOfField];

	field[0] = time_1;
	field[1] = time_2;
	field[2] = time_3;
	field[3] = time_4;
	field[4] = time_5;
	field[5] = time_6;
	field[6] = time_7;
	field[7] = time_8;
	field[8] = time_9;
	field[9] = time_10;

	cout << "" << endl;
	extract(field, sizeOfField);
	time_1->organiseField(field, sizeOfField);
	cout << "" << endl;
	extract(field, sizeOfField);

	delete[] field;
	system("pause");
	return 0;
}