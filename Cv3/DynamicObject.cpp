#include "DynamicObject.h"

DynamicObject::DynamicObject(int id, double angle) :Object(id) {
	this->angle = angle;
}

DynamicObject::~DynamicObject() {
}

double DynamicObject::GetAngle() const {
	return this->angle;
}

void DynamicObject::SetAngle(double angle) {
	this->angle = angle;
}
