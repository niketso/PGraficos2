#include "CollisionManager.h"
#include <math.h>


CollisionManager* CollisionManager::instance = NULL;

CollisionManager::CollisionManager()
{	
	for (int i = 0; i < (int)Layers::count; i++) 
	{		
		CollisionGroups.push_back(new list<Entity*>());						
	}			
}


CollisionManager::~CollisionManager()
{
}

void CollisionManager::AddCollisionEntity(Entity* e , Layers lyr)
{
	
	 CollisionGroups[lyr]->push_back(e); 
	 

}

void CollisionManager::CollisionBoxDetector() 
{
	for (int i = 0; i < (int)Layers::count; i++)
	{
		for (int j = i+1; j < (int)Layers::count; j++)
		{
			CheckCollisionsBetweenLayers(CollisionGroups[i] ,CollisionGroups[j]);                                           
		}
	}
}

void CollisionManager::CheckCollisionsBetweenLayers( list<Entity*> *layerA, list<Entity*> *layerB)
{
	
	for (list<Entity*>::iterator i = layerA->begin(); i != layerA->end(); ++i) {
		for (list<Entity*>::iterator j = layerB->begin(); j != layerB->end(); ++j) {
			CollisionBoxResolver(*i, *j); 
			
		}
	}
	
}

void CollisionManager::CollisionBoxResolver(Entity* A, Entity* B)
{
	//calcular la matematica.
	float xDiff = ( A->GetX() + B->GetX());
	//valor absoluto.
	float moduleX = abs(xDiff);	
	float yDiff = (A->GetY() + B->GetY());
	float moduleY = abs(yDiff);

	
	if (moduleX <= (A->GetWidth() / 2.0f + B->GetWidth() / 2.0f ) && moduleY <= (A->GetHeight() / 2.0f + B->GetHeight()/2.0f ))
	{
		//Penetracion
		float xP = (A->GetWidth()/2.0f + B->GetWidth()/ 2.0f) - moduleX;
		float yP = (A->GetHeight()/2.0f + B->GetHeight()/ 2.0f) - moduleY;

		if (xP > yP)
		{
			cout << yP  <<endl;
			//vertical
			if (A->GetBoundingBox()->GetStatic())
			{
				B->SetPos(B->GetX(), B->GetY() - (yP), 0.0f);
			}
			else if (B->GetBoundingBox()->GetStatic())
			{
				A->SetPos(A->GetX(), A->GetY() - (yP), 0.0f);
			}
			else 
			{
				A->SetPos(A->GetX(),A->GetY() - (yP / 2.0f) , 0.0f);
				B->SetPos(B->GetX(), B->GetY() - (yP / 2.0f), 0.0f);
			}
			//falta determinar de que lado viene

		}
		else 
		{
			cout << xP << endl;
			//horizontal
			if (A->GetBoundingBox()->GetStatic())
			{
				B->SetPos(B->GetX() - (xP), B->GetY(), 0.0f);
			}
			else if (B->GetBoundingBox()->GetStatic())
			{
				A->SetPos(A->GetX() - (xP), A->GetY(), 0.0f);
			}
			else
			{
				A->SetPos(A->GetX() - (xP / 2), A->GetY() , 0.0f);
				B->SetPos(B->GetX() - (xP / 2), B->GetY() , 0.0f);
			}
			//falta determinar de que lado viene
		}
		 
	}
}




