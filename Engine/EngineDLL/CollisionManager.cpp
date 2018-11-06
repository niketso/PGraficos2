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

void CollisionManager::AddCollisionEntity(Entity* e , Layers lyr)
{
	CollisionGroups[lyr].push_back(e);                                            // tengo que inicializar el vector??

}

void CollisionManager::CollisionBoxDetector() 
{
	for (int i = 0; i < (int)Layers::count; i++)
	{
		for (int j = i+1; j < (int)Layers::count; j++)
		{
			//CheckCollisionsBetweenLayers(i , j);                                           //Como le paso la layer??
		}
	}
}

void CollisionManager::CheckCollisionsBetweenLayers(list<Entity*> *layerA, list<Entity*> *layerB)
{
	//list<Entity*> groupA = CollisionGroups[A];
	for (list<Entity*>::iterator i = layerA->begin(); i != layerA->end(); ++i) {
		for (list<Entity*>::iterator j = layerB->begin(); j != layerB->end(); ++j) {
			//CollisionBoxResolver(*i, *j);                                                                //Como paso la layer??
		}
	}
	
}

void CollisionManager::CollisionBoxResolver(Entity* A, Entity* B)
{
	//calcular la matematica.
}




