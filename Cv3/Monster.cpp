#include "Monster.h"

int Monstrum::GetHp() const {
	return this->hp;
}

int Monstrum::GetMaxHp() const {
	return this->maxHp;
}

void Monstrum::SetHp(int aHp) {
	this->hp = hp;
}

void Monstrum::SetMaxHp(int aMaxHp) {
	this->maxHp = maxHp;
}