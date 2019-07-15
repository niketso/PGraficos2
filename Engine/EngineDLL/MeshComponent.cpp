#include "MeshComponent.h"
#include "ModelImporter.h"


MeshComponent::MeshComponent(ComponentType type, Renderer *render, const char* filename, const char* texturename)
{
	//start(render,filename,texturename);
	
}

MeshComponent::MeshComponent(ComponentType type, Material *mat, Mesh *msh)
{
	material = mat;
	mesh = msh;
}

MeshComponent::~MeshComponent()
{
}

void MeshComponent::Update()
{
}

void MeshComponent::Draw()
{
	//DrawMesh(GL_TRIANGLES);
	mesh->DrawMesh(0);
	mesh->Draw();
}


