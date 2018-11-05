#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec2 pPos, float height, float width, Layers layer)
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


