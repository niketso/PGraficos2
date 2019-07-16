#pragma once
#include "Exports.h"
#include "Component.h"
#include "Importer.h"
#include "Material.h"
#include "Mesh.h"
#include <vector>
class ENGINEDLL_API MeshComponent : public Component
{
private:
	ComponentType _type;
	Material *_material;
	Renderer *_render;
	BMPheader  _texture;
	
	vector<float> _verticesVec;
	vector<float> _uvVec;
	vector<unsigned int> _indexVec;

	unsigned int ProgramID;
	unsigned int vertexBufferID;
	unsigned int uvBufferID;
	unsigned int indexBufferID;
	unsigned int textureBufferID;
public:
	
	MeshComponent( ComponentType type,Renderer *render);
	~MeshComponent();
	void Update();
	void Draw();

	void SetVertices(vector<float> verticesVec);
	void SetUv(vector<float> uvVec);
	void SetIndex(vector<unsigned int> indexVec);
	void SetTexture(const char *texturename);
	void LoadMaterial();
	
	
	
};

