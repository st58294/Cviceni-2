#pragma once
#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"

enum class ObsticleType {
    rock, smallFlower, bigFlower
};

class StaticObjekt : public Object {
private:
    ObsticleType typeOfObsticle;
public:
    StaticObjekt(int id, ObsticleType typeOfObsticle);

    ~StaticObjekt();

    ObsticleType& GetTypyOfObsticle();
};

#endif // !STATICOBJECT_H