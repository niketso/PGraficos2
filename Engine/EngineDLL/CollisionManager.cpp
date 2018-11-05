#include "CollisionManager.h"



CollisionManager::CollisionManager()
{
	/*for (int i = 0; i < (int)Layers::count; i++)
	{
		CollisionGroups[i];
	}*/
}


CollisionManager::~CollisionManager()
{
}

void CollisionManager::AddCollisionEntity(Entity* e,Layers lyr)
{
	CollisionGroups[lyr].push_back(e);

}
void CollisionManager::CollisionBoxDetector() 
{
	for (int i = 0; i < (int)Layers::count; i++)
	{
		for (int j = i+1; j < (int)Layers::count; j++)
		{
			CheckCollisionsBetweenLayers(i, j);
		}
	}
}

void CheckCollisionBetweenLayers(int A, int B)
{
	list<Entity*> groupA = CollisionGroups[A];

	
}

void CollisionManager::CollisionCircleDetector() 
{

}
void CollisionManager::CollisionBoxMath() 
{
	
}
void CollisionManager::CollisionCircleMath()
{

}
