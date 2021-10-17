#include <iostream>
#include "DynamicObject.h"
#include "Game.h"
#include "Monster.h"
#include "Object.h"
#include "StaticObject.h"

using namespace std;


int main(int argc, char** argv) {
	Game* game = new Game;
	Object* obj = new StaticObjekt(5, ObsticleType::smallFlower);
	Object* obj2 = new StaticObjekt(6, ObsticleType::smallFlower);
	Object* obj3 = new DynamicObject(565, 2.0); 
	Object* obj4 = new DynamicObject(55, 2.0);
	Object* obj5 = new DynamicObject(56, 2.0);

	obj->SetX(2);
	obj->SetY(2);

	obj2->SetX(2);
	obj2->SetY(2);
	
	obj3->SetX(2);
	obj3->SetY(2);

	obj4->SetX(2);
	obj4->SetY(2);

	obj5->SetX(2);
	obj5->SetY(2);

	game->AddObeject(obj);
	game->AddObeject(obj2);
	game->AddObeject(obj3);
	game->AddObeject(obj4);
	game->AddObeject(obj5);
	


	int* fieldDynamicObejcts = game->FindIDStaticObejct(0, 2, 0, 2);
	for (int i = 1; i < fieldDynamicObejcts[0]; i++)
	{
			cout << fieldDynamicObejcts[i] << endl;	
	}

	DynamicObject** dynamicObj = game->FindDynamicObejctsInArea(2, 2, 2);
	for (size_t i = 0; i < sizeof(dynamicObj) / sizeof(int); i++)
	{
		cout << dynamicObj[i]->GetId() << endl;
	}

	DynamicObject** dynamicObj2 = game->FindDynamicObejctsInArea(2, 2, 2, 0, 2);
	for (size_t i = 0; i < sizeof(dynamicObj2) / sizeof(int); i++)
	{
		cout << dynamicObj2[i]->GetId() << endl;
	}

	delete game;

	return 0;
}