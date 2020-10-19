#pragma once
#ifndef MONSTRUM_H
#define MONSTRUM_H

#include "DynamicObject.h"

class Monstrum : public DynamicObject {
private:
    int hp;
    int maxHp;
public:
    int GetHp() const;
    int GetMaxHp() const;
    void SetHp(int hp);
    void SetMaxHp(int maxHp);
};

#endif // !MONSTRUM_H
