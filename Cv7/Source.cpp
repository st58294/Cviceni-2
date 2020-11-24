#include "Date.h"
#include "Person.h"
#include <fstream>
#include <iostream>
#include "Address.h"
#pragma warning( disable : 4996)

using namespace std;

static const string path = "./file.txt";
void write() {
	ofstream file_stream;
	file_stream.open(path);
	if (!file_stream.is_open()) {
		throw runtime_error("File not opened");
	}

	Address address1 = Address("Nerudova", "Pardubice", 454741);
	Address address2 = Address("Smilova", "Svitavy", 322100);
	Address address3 = Address("Milheinova", "Praha", 125121);
	Date date1 = Date(27, 5, 1955);
	Date date2 = Date(31, 5, 1999);
	Date date3 = Date(4, 7, 2020);

	Person arr[3]{ {"Petr", "Novak", address1 , date1},
				  {"Tomas", "Black",   address2,  date2 },
				  {"Avneet", "Lacey", address3, date3} };
	file_stream << arr[0] << arr[1] << arr[2];
	file_stream.close();
}

void writeBinary() {
	ofstream file_stream;
	file_stream.open("./file.dat", ios_base::binary);

	if (!file_stream.is_open()) {
		throw runtime_error("File not opened");
	}

	Address address1 = Address("Nerudova", "Pardubice", 454741);
	Address address2 = Address("Smilova", "Svitavy", 322100);
	Address address3 = Address("Milheinova", "Praha", 125121);
	Date date1 = Date(27, 5, 1955);
	Date date2 = Date(31, 5, 1999);
	Date date3 = Date(4, 7, 2020);

	Person arr[3]{ {"Petr", "Novak", address1 , date1},
				  {"Tomas", "Black",   address2,  date2 },
				  {"Avneet", "Lacey", address3, date3} };


	for (int i = 0; i < (sizeof(arr) / sizeof(Person)); i++) {
		file_stream.write((char*)&arr[i], sizeof(Person));
	}

	file_stream.close();
}

int countOfMembers() {
	int counter = 0;
	char buffer[1000];
	FILE* f = fopen("file.txt", "r");
	while (!feof(f)) {
		fgets(buffer, sizeof(buffer), f);
		counter++;
	}
	fclose(f);
	return counter;
}

int countOfMembersBinary() {
	int counter = 1;
	char buffer[1000];
	FILE* f = fopen("file.dat", "rb");
	while (!feof(f)) {
		fgets(buffer, sizeof(buffer), f);
		counter++;
	}
	fclose(f);
	return counter;
}

Person* read() {
	int count = countOfMembers();
	ifstream file_stream;
	file_stream.open("./file.txt");
	if (!file_stream.is_open()) {
		throw runtime_error("File not opened");
	}

	int size = 0;

	while (true) {
		Person person;
		file_stream >> person;
		size++;
		if (size == count) {
			file_stream.clear();
			file_stream.seekg(0, ios::beg);
			break;

		}
		cout << person << endl;
	}
	Person* field = new Person[size];
	for (int i = 0; i < size; ++i) {
		file_stream >> field[i];
	}

	file_stream.close();
	return field;
}

Person* readBinary() {
	ifstream file_stream;
	file_stream.open("./file.dat", ios_base::binary);
	if (!file_stream.is_open()) {
		throw runtime_error("File not opened");
	}
	int count = countOfMembersBinary();

	Person* field = new Person[count];
	if (file_stream.is_open()) {
		for (int i = 0; i < count; i++) {
			file_stream.read((char*)&field[i], sizeof(Person));
			cout << field[i] << endl;
		}
		file_stream.close();
	}

	return field;
}


int main(int argc, char** argv) {
	write();
	writeBinary();
	
	cout << "writing to file was successful" << endl << endl;
	
	cout << "txt file" << endl << endl;
	Person* field = read();
	
	cout << "bin file" << endl << endl;
	Person* field2 = readBinary();


	system("pause");
	return 0;
}

