#include "IComparable.h"
#include "Time.h"
#include "IObject.h"
#include <string>

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::~Time(){
	
}

string Time::toString() const {
	return to_string(this->hours) + ':'
		+ to_string(this->minutes) + ':'
		+ to_string(this->seconds);
}

int Time::compareTo(IComparable* obj) const {
	if (hours == ((Time*)obj)->hours) {
		if (minutes == ((Time*)obj)->minutes) {
			if (seconds == ((Time*)obj)->seconds) {
				return 0;
			}
			else if (seconds > ((Time*)obj)->seconds) {
				return 1;
			}
			return -1;
		}
		else if (minutes > ((Time*)obj)->minutes) {
			return 1;
		}
		return -1;
	}
	else if (hours > ((Time*)obj)->hours) {
		return 1;
	}
	return -1;
}

void Time::organiseField(IComparable** field, int sizeOfField) {
	int i, j;
	for (i = 0; i < sizeOfField - 1; i++) {
		for (j = i + 1 ; j < sizeOfField ; j++) {
			if (field[i]->compareTo(field[j]) == -1) {
				IComparable* temp = field[i];
				field[i] = field[j];
				field[j] = temp;
			}
		}
	}
}