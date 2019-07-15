#pragma once
#include "Exports.h"
#include "Component.h"
#include "Material.h"
#include "Mesh.h"
class ENGINEDLL_API MeshComponent : public Component
{
private:
	ComponentType _type;
	Material *material;
	Mesh *mesh;
	unsigned int programID;
public:
	
	MeshComponent( ComponentType type,Renderer *render, const char* filename, const char* texturename);
	MeshComponent(ComponentType type, Material *mat, Mesh *msh);
	~MeshComponent();
	void Update();
	void Draw();
	
	
	
};

