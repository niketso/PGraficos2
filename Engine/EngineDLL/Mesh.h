#pragma once
#include "Exports.h"
#include "Shape.h"
#include<vector>
using namespace std;

struct MeshData
{
	MeshData *meshinfo;
	vector<float> vertexVec;	
	vector<float> uvVec;
	vector<float> normalVec;
	vector<unsigned int> indexVec;

	 void SetMeshInfo(MeshData *_meshinfo) 
	{
		meshinfo = _meshinfo;
	}
	MeshData GetMeshInfo() 
	{
		return *meshinfo;
	}
};

class ENGINEDLL_API Mesh:public Shape
{

public:
	Mesh(Renderer *render, const char* filename, const char* texturename);
	~Mesh();
	void Draw();
	void DrawMesh(int drawType) override;
};

