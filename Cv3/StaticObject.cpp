#include "StaticObject.h"

StaticObjekt::StaticObjekt(int id, ObsticleType typeOfObsticle) :Object(id) {
	this->typeOfObsticle = typeOfObsticle;
}

StaticObjekt::~StaticObjekt() {
}

ObsticleType& StaticObjekt::GetTypyOfObsticle() {
	return this->typeOfObsticle;
}
