#pragma once
#include "Exports.h"
#include "Component.h"
#include "Importer.h"
#include "Material.h"
#include "Mesh.h"
#include "Camera.h"
#include "Definitions.h"
#include <vector>
#include "Node.h"

class ENGINEDLL_API MeshComponent : public Component
{

private:
	ComponentType _type;
	Material *_material;
	Renderer *_render;
	BMPheader  _texture;
	Camera * _camera;
	
	vector<float> _verticesVec;
	vector<float> _uvVec;
	vector<unsigned int> _indexVec;

	unsigned int ProgramID;
	unsigned int vertexBufferID;
	unsigned int uvBufferID;
	unsigned int indexBufferID;
	unsigned int textureBufferID;

	bool isBsp = false;
	glm::vec3 bspForward;
public:
	BoundingCube * bCube;
	
	MeshComponent( ComponentType type,Renderer *render,Camera * camera);
	~MeshComponent();
	void Update();
	void Draw();

	void UpdateData(glm::vec3 min, glm::vec3 max);

	void SetVertices(vector<float> verticesVec);
	void SetUv(vector<float> uvVec);
	void SetIndex(vector<unsigned int> indexVec);
	void SetTexture(const char *texturename);
	void LoadMaterial();
	
	void SetBSP(bool _isBSP, Node * node);
	bool GetIsBsp();
	glm::vec3 GetForwardBSP();
	
	
};

