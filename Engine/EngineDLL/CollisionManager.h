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
	void CheckCollisionsBetweenLayers(int A, int B);
	void CollisionBoxDetector();
	void CollisionCircleDetector();
	void CollisionBoxMath();
	void CollisionCircleMath();

};

