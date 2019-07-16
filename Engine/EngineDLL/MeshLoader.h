#pragma once
#include"Exports.h"
#include"Node.h"
#include"Importer.h"
#include "MeshComponent.h"

#include<assimp/Importer.hpp>
#include<assimp/postprocess.h>
#include<assimp/scene.h>

#include"../external/glew-2.1.0/include/GL/glew.h"
#include "../external/glm-0.9.9.0/glm/vec2.hpp"
#include "../external/glm-0.9.9.0/glm/vec3.hpp"
#include<vector>

class ENGINEDLL_API MeshLoader
{
private:
	vector<float> *VertexVec;
	vector<float> *UvVec;
	vector<float> *facesVec;
	Node* node;
public:
	MeshLoader();
	~MeshLoader();
	void LoadMesh(const char * meshname, const char * texturename, Renderer * render);
	void InitFromScene(const aiScene* scene, Node *node, aiNode* root, const char * texturename, Renderer * render);
	void InitMesh(unsigned int Index, const aiMesh* Mesh, Renderer * render); 
		
};

