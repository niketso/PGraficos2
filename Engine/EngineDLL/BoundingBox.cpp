#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec2 pPos, float height, float width, Layers layer, bool isStc, bool isTrggr) :
	isStatic (false),
	isTrigger(false)
{

}
BoundingBox::~BoundingBox()
{
}
unsigned int BoundingBox::GetX() 
{
	return pivotPosition.x;
}
unsigned int BoundingBox::GetY()
{
	return pivotPosition.y;
}
glm::vec2 BoundingBox::GetPivot()
{
	return pivotPosition;
}
unsigned int BoundingBox::GetHeight()
{
	return height;
}
unsigned int BoundingBox::GetWidth()
{
	return width;
}

void BoundingBox::SetStatic(bool enable)
{
	isStatic = enable;
}

bool BoundingBox::GetStatic() 
{
	return isStatic;
}

void BoundingBox::SetTrigger(bool enableTrigger)
{
}

bool BoundingBox::GetTrigger()
{
	return isTrigger;
}




