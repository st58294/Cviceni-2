#pragma once
#ifndef INCREASING_COEFFICIENT_H
#define INCREASING_COEFFICIENT_H
#include<cstdlib>
#include <exception>


using namespace std;

template <typename DataType,
	int initialSize = 5, int increasingCoefficient = 2>

	class IncreasingCoefficient {
private:
	DataType* _field;
	unsigned _fieldSize;
	unsigned _CvalidElement;
	bool isNotFull() const;
public:
	IncreasingCoefficient();
	~IncreasingCoefficient();
	void add(const DataType& o);
	void increaseSize();
	DataType& operator[](int index);
	DataType operator[](int index) const;
	unsigned int count() const;
	void addTo(int index, const DataType& o);
	void removeFrom(int index);
};

template <typename DataType, int initialSize, int increasingCoefficient>
IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::IncreasingCoefficient() {
	_field = new DataType[initialSize];
	_fieldSize = initialSize;
	_CvalidElement = 0;
}

template <typename DataType, int initialSize, int increasingCoefficient>
IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::~IncreasingCoefficient() {
	delete[] _field;
}

template <typename DataType, int initialSize, int increasingCoefficient>
bool IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::isNotFull() const {
	if (_CvalidElement < _fieldSize){
		return true;
	}
	return false;
}

template <typename DataType, int initialSize, int increasingCoefficient>
void IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::increaseSize() {

	int newSize = _fieldSize * increasingCoefficient;
	DataType* newField = new DataType[newSize];

	for (int i = 0; i < _fieldSize; i++) {
		newField[i] = _field[i];
	}

	delete[] _field;
	_fieldSize = newSize;
	_field = newField;
}

template <typename DataType, int initialSize, int increasingCoefficient>
void IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::add(const DataType& o) {

	if (!isNotFull()) {
		increaseSize();
		_field[_CvalidElement] = o;
	}
	else {
		_field[_CvalidElement] = o;
	}
	_CvalidElement++;
}

template <typename DataType, int initialSize, int increasingCoefficient>
DataType& IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::operator[](int index) {
	if (index > _fieldSize) {
		throw invalid_argument("Error");
	}
	return _field[index];
}

template <typename DataType, int initialSize, int increasingCoefficient>
DataType IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::operator[](int index) const {
	if (index > _fieldSize) {
		throw invalid_argument("Error");
	}
	return _field[index];
}

template <typename DataType, int initialSize, int increasingCoefficient>
unsigned int IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::count() const {
			return _CvalidElement;	
}

template <typename DataType, int initialSize, int increasingCoefficient>
void IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::addTo(int index, const DataType& o) {
	
	if (_CvalidElement < index) {
		throw invalid_argument("Error - Coefficient");
	}
	
	if (_CvalidElement <= index) {
		_field[index] = o;
		_CvalidElement++;
		return;
	} 
	else {
		if (!isNotFull()) {
			increaseSize();
		}
		DataType* newField = new DataType[_fieldSize];
		int counter = 0;
		for (int i = index; i < _fieldSize; i++) {
			newField[counter] = _field[i];
			counter++;
		}
		counter = 0;
		_field[index] = o;
		for (int i = index + 1; i < _fieldSize; i++) {
			_field[i] = newField[counter];
			counter++;
		}
		_CvalidElement++;
	}
}

template <typename DataType, int initialSize, int increasingCoefficient>
void IncreasingCoefficient<DataType, initialSize,
	increasingCoefficient>::removeFrom(int index) {
	DataType* newField = new DataType[_fieldSize];
	int counter = 0;

	for (int i = index + 1; i < _fieldSize; i++) {
		newField[counter] = _field[i];
		counter++;
	}
	counter = 0;
	for (int i = index; i < _fieldSize; i++) {
		_field[i] = newField[counter];
		counter++;
	}
	_CvalidElement--;
}

#endif // !INCREASING_COEFFICIENT_H