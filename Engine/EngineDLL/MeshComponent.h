#pragma once
#include "Exports.h"
#include "Component.h"
#include "Material.h"
#include "Mesh.h"
class ENGINEDLL_API MeshComponent : public Component
{
private:
	ComponentType _type;
	unsigned int programID;
public:
	
	MeshComponent( ComponentType type,Renderer *render);
	~MeshComponent();
	void Update();
	void Draw();
	
	unsigned int vertexBufferID;
	unsigned int uvBufferID;
	unsigned int IndexBufferID;
	unsigned int textureBufferID;
	
};

