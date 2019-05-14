#pragma once
#include "Exports.h"
#include <vector>
using namespace std;

struct MeshData
{
	//array de vec
	//array de indx
	//array de uvs
	vector<float> vec1;
	
	
};

class ENGINEDLL_API ModelImporter
{
public:
	ModelImporter();
	~ModelImporter();
};

