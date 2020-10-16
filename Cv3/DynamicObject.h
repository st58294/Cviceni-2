#pragma once
#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "Object.h"

class DynamicObject : public Object {
private:
    double angle;
public:
    DynamicObject(int id, double angle);
    ~DynamicObject();

    double GetAngle() const;
    void SetAngle(double angle);
};

#endif // !DYNAMICOBJECT_H
