#pragma once
#include "Exports.h"
#include <vector>

//#include"../assimp/Importer.hpp"
using namespace std;

struct MeshData
{	
	vector<float> vertexVec;
	vector<unsigned int> indexVec;
	vector<float> uvVec;
};

class ENGINEDLL_API ModelImporter
{
private:
vector<MeshData> aux;
public:
	ModelImporter();
	~ModelImporter();
	static MeshData LoadMesh(const char * MeshName);

};

