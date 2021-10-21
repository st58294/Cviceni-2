#include <iostream>
#include "Game.h"
#include <array>
#include "StaticObject.h"

typedef struct Bin {
	int index;
	struct Bin* next;
}Bin;

Game::Game() {
	objects = new Object*[maxObjCount];
}

Game::~Game() {
	delete objects;
}

void Game::AddObeject(Object* object) {
	objects[counter] = object;
	counter++;
}

int* Game::FindIDStaticObejct(double xMin, double xMax, double yMin, double yMax) {
	int* Id_field = new int[counter + 1];
	int index = 1;
	for (size_t i = 0; i < this->counter; i++) {
		double x = objects[i]->GetX();
		double y = objects[i]->GetY();
		bool test = false;

		if (dynamic_cast<StaticObjekt*>(objects[i]) != nullptr &&
			x >= xMin && x <= xMax && y >= yMin && y <= yMax) {
			Id_field[index] = objects[i]->GetId();
			index++;
		}
		Id_field[0] = index;
	}
	return Id_field;
}

DynamicObject** Game::FindDynamicObejctsInArea(double x, double y, double r) {
	Bin* sb_temp = new Bin;
	Bin* sb_acc;
	Bin* sb_head = nullptr;
	int quantity = 0;
	int lastPosition = 1;
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
				sb_temp->next = nullptr;
				quantity++;
			}
		}
	}

	DynamicObject** results = new DynamicObject * [quantity + lastPosition];
	sb_temp = sb_head;
	for (size_t i = 0; i < quantity + lastPosition; i++) {
		if (sb_temp == nullptr) {
			results[i] = nullptr;
		}
		if (sb_temp != nullptr) {
			results[i] = dynamic_cast<DynamicObject*> (objects[sb_temp->index]);
			sb_temp = sb_temp->next;
		}
	}
	
	sb_temp = sb_head;

	while (sb_temp != nullptr)
	{
		sb_acc = sb_temp;
		sb_temp = sb_temp->next;
		delete sb_acc;

	}
	delete sb_temp;
	return results;
}

DynamicObject** Game::FindDynamicObejctsInArea
(double x, double y, double r, double uMin, double uMax) {
	Bin* sb_temp = new Bin;
	Bin* sb_head = NULL;
	Bin* sb_acc;
	int quantity = 0;
	int lastPosition = 1;
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
	DynamicObject** results = new DynamicObject * [quantity + lastPosition];
	sb_temp = sb_head;
	for (size_t i = 0; i < quantity + lastPosition; i++) {
		if (sb_temp == NULL) {
			results[i] = nullptr;
		}
		if (sb_temp != NULL) {
			results[i] = dynamic_cast<DynamicObject*> (objects[sb_temp->index]);
			sb_temp = sb_temp->next;
		}
	}
	sb_temp = sb_head;
	
	while (sb_temp != NULL)
	{
		sb_acc = sb_temp;
		sb_temp = sb_temp->next;
		delete sb_acc;

	}
	delete sb_temp;
	return results;
}
