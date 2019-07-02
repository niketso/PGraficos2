#pragma once
#include "Component.h"
#include "Material.h"
#include "Mesh.h"
class MeshComponent : public Component
{
private:
	Material *mat1;
	Mesh *msh1;
public:
	MeshComponent(Material *mat,Mesh *msh);
	~MeshComponent();
	void start();
	bool Update();
	void Draw();
	
};

