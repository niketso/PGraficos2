#pragma once
#include "Exports.h"
#include "Definitions.h"
#include <iostream>
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
using namespace std;

class ENGINEDLL_API BoundingBox
{
private:
 float height;
 float width;
 glm::vec2 pivotPosition;
 Layers layer;

public:
	BoundingBox(glm::vec2 pPos,float height, float width, Layers layer );
	unsigned int GetX();
	unsigned int GetY();
	glm::vec2 GetPivot();
	unsigned int GetHeight();
	unsigned int GetWidth();
	~BoundingBox();
};

