#pragma once
#include "Exports.h"
#include "Shape.h"
class ENGINEDLL_API Mesh:public Shape
{
private:
int * indexVec;

public:
	Mesh(Renderer *render);
	~Mesh();	
	void DrawBuffer();
};

