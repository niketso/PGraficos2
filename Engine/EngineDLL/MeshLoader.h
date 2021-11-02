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
	static MeshLoader *instance;	
	glm::vec3 boundingBoxMin;
	glm::vec3 boundingBoxMax;
public:
	MeshLoader();
	~MeshLoader();
	Node* LoadMesh(const char * meshname, const char * texturename, Renderer * render, Node * roothNode,Camera * camera);	
	void InitFromScene(const aiScene* scene, Node *node,aiNode* root, const char * texturename, Renderer * render,Camera *camera);
	void InitMesh(const aiMesh* mesh,MeshComponent *meshcomponent, Renderer * render);
	void GenerateBoundingBox(MeshComponent * mesh,Renderer * render);
	void SetNodeTransform(aiNode * aiNode, Node * node, Renderer * render);
		
	static MeshLoader* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new MeshLoader();
		}
		return instance;
	}
};

