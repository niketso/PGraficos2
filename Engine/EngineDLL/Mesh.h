#pragma once
#include "Exports.h"
#include "Shape.h"
#include "ModelImporter.h"
class ENGINEDLL_API Mesh:public Shape
{
private:
	

public:
	Mesh(Renderer *render);
	~Mesh();
	void Draw();
	void DrawMesh(int drawType) override;
};

