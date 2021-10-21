#include <iostream>
#include "DynamicObject.h"
#include "Game.h"
#include "Monster.h"
#include "Object.h"
#include "StaticObject.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;
void* operator new(size_t size)
{
	cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	cout << "freeing " << size << " bytes\n";
	return free(memory);
}

int main(int argc, char** argv) {
	Game* game = new Game();
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
	cout << "Static objects at 0, 2 , 0 , 2"<< endl;
	for (int i = 1; i < fieldDynamicObejcts[0]; i++)
	{
			cout << "Obj Id: " << fieldDynamicObejcts[i] << endl;
	}
	
	delete[] fieldDynamicObejcts;

	DynamicObject** dynamicObj = game->FindDynamicObejctsInArea(2, 2, 2);
	cout << "Static Dynamic Obj at 2, 2 , 2" << endl;
	int i = 0;
	while (dynamicObj[i] != nullptr) {
		cout << "Obj Id: " << dynamicObj[i]->GetId() << endl;
		i++;
	}
	i = 0;

	DynamicObject** dynamicObj2 = game->FindDynamicObejctsInArea(2, 2, 2, 0, 2);
	cout << "Static Dynamic Obj in Area 2, 2, 2, 0, 2" << endl;
	while (dynamicObj2[i] != nullptr) {
		cout << "Obj Id: " << dynamicObj2[i]->GetId() << endl;
		i++;
	}
	
	i = 0;
	while (dynamicObj[i] != nullptr) {
		delete dynamicObj[i];
		i++;
	}
	delete[] dynamicObj;
	delete[] dynamicObj2;

	delete obj;
	delete obj2;
	delete game;
	

	_CrtDumpMemoryLeaks();


	return 0;
}