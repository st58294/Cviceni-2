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
	Object* obj3 = new DynamicObject(565, 2);
	Object* obj4 = new DynamicObject(55, 2);

	obj->SetX(2);
	obj->SetY(2);

	obj3->SetX(2);
	obj3->SetY(2);

	obj4->SetX(2);
	obj4->SetY(2);

	game->AddObeject(obj);
	game->AddObeject(obj3);
	game->AddObeject(obj4);

	cout << game->FindIDStaticObejct(0, 2, 0, 2)[0] << endl;
	cout << game->FindDynamicObejctsInArea(2, 2, 2)[0]->GetId() << endl;
	cout << game->FindDynamicObejctsInArea(2, 2, 2, 0, 2)[1]->GetId() << endl;

	delete[] obj, obj2, obj3, obj4;

	return 0;
}