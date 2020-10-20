#include <iostream>
#include "Game.h"
#include "StaticObject.h"

typedef struct Bin {
	int index;
	struct Bin* next;
}Bin;

Game::Game() {
	objects = new Object*[10];
}

Game::~Game() {
	for (size_t i = 0; i < counter; i++)
	{
		delete objects[i];
	}
	delete[] objects;
}

void Game::AddObeject(Object* object) {
	objects[counter] = object;
	counter++;
}

int* Game::FindIDStaticObejct(double xMin, double xMax, double yMin, double yMax) {
	int* Id_field = new int[counter];
	int index = 0;
	for (size_t i = 0; i < this->counter; i++) {
		double x = objects[i]->GetX();
		double y = objects[i]->GetY();
		bool test = false;

		if (dynamic_cast<StaticObjekt*>(objects[i]) != nullptr &&
			x >= xMin && x <= xMax && y >= yMin && y <= yMax) {
			Id_field[index] = objects[i]->GetId();
			index++;
		}
	}
	return Id_field;
}

DynamicObject** Game::FindDynamicObejctsInArea(double x, double y, double r) {
	Bin* sb_temp = new Bin;
	Bin* sb_acc;
	Bin* sb_head = NULL;
	int quantity = 0;
	for (size_t i = 0; i < counter; i++) {
		int distance = sqrt(pow((objects[i]->GetX() - y), 2) + pow((objects[i]->GetX() - y), 2));
		if (dynamic_cast<DynamicObject*>(objects[i]) != nullptr && distance <= r) {
			sb_acc = new Bin;
			if (quantity == 0) {
				quantity++;
				sb_temp->index = i;
				sb_head = sb_temp;
			}
			else {
				sb_acc->index = i;
				sb_temp->next = sb_acc;
				sb_temp = sb_temp->next;
				sb_temp->next = NULL;
				quantity++;
			}
		}
	}

	DynamicObject** results = new DynamicObject * [quantity];
	for (size_t i = 0; i < quantity; i++) {
		if (sb_head != NULL) {
			results[i] = dynamic_cast<DynamicObject*> (objects[sb_head->index]);
			sb_head = sb_head->next;
		}
	}
	return results;
}

DynamicObject** Game::FindDynamicObejctsInArea
(double x, double y, double r, double uMin, double uMax) {
	Bin* sb_temp = new Bin;
	Bin* sb_head = NULL;
	Bin* sb_acc;
	int quantity = 0;
	for (size_t i = 0; i < counter; i++) {
		int distance = sqrt(pow((objects[i]->GetX() - y), 2) + pow((objects[i]->GetX() - y), 2));
		DynamicObject* temp = dynamic_cast<DynamicObject*>(objects[i]);
		if (dynamic_cast<DynamicObject*>(objects[i]) != nullptr && distance <= r
			&& temp->GetAngle() >= uMin && temp->GetAngle() <= uMax) {
			sb_acc = new Bin;
			if (quantity == 0) {
				quantity++;
				sb_temp->index = i;
				sb_head = sb_temp;
			}
			else {
				sb_acc->index = i;
				sb_temp->next = sb_acc;
				sb_temp = sb_temp->next;
				sb_temp->next = NULL;
				quantity++;
			}
		}
	}
	DynamicObject** results = new DynamicObject * [quantity];
	for (size_t i = 0; i < quantity; i++) {
		if (sb_head != NULL) {
			results[i] = dynamic_cast<DynamicObject*> (objects[sb_head->index]);
			sb_head = sb_head->next;
		}
	}

	return results;
}
