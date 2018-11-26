#include "SpriteSheet.h"



SpriteSheet::SpriteSheet(int columns, int rows)
{
	uvVector = new vector<float*>();
}


SpriteSheet::~SpriteSheet()
{
	delete uvVector;
}

/*float* SpriteSheet::GetUvArray(int index) 
{
	return ;
}*/
int SpriteSheet::GetSize() 
{
	return uvVector->size();
}
