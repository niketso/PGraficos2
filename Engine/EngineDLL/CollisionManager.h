#pragma once
#include "Exports.h"
#include "Entity.h"
#include "BoundingBox.h"
#include "Definitions.h"
#include <vector>
#include <list>
using namespace std;

class  ENGINEDLL_API CollisionManager
{
private:
	vector<list<Entity*>> CollisionGroups;
	//vector<list<BoundingCircle>*>* CircleListVector;
public:
	CollisionManager();
	~CollisionManager();
	void AddCollisionEntity(Entity* e, Layers lyr);
	void CollisionBoxDetector();
	void CheckCollisionsBetweenLayers(list<Entity*> *layerA, list<Entity*> *layerB);	
	void CollisionBoxResolver(Entity* A, Entity* B);
	

};

