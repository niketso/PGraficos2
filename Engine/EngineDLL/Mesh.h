#pragma once
#include "Exports.h"
#include "Shape.h"
#include<vector>
using namespace std;



class ENGINEDLL_API Mesh:public Shape
{

public:
	Mesh(Renderer *render, const char* filename, const char* texturename);
	~Mesh();
	void Draw();
	void DrawMesh(int drawType) override;
};

