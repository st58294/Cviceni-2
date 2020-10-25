#pragma once
#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "DynamicObject.h"

class Game {
private:
	Object** objects;
	int counter = 0;
	int maxObjCount = 10000;
public:
	Game();
	~Game();

	void AddObeject(Object* o);
	int* FindIDStaticObejct(double xMin, double xMax, double yMin, double yMax);

	DynamicObject** FindDynamicObejctsInArea(double x, double y, double r);
	DynamicObject** FindDynamicObejctsInArea
	(double x, double y, double r, double angleMin, double angleMax);
};
#endif // !GAME.H