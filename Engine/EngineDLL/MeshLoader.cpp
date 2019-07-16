#include "MeshLoader.h"



MeshLoader::MeshLoader()
{

	

	
}


MeshLoader::~MeshLoader()
{
}

void MeshLoader::LoadMesh(const char * meshname, const char * texturename, Renderer * render)
{
	Assimp::Importer Importer;

	const aiScene* pScene = Importer.ReadFile(meshname, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

	

	if (pScene)
	{
		Node * mainNode = new Node();
		InitFromScene(pScene, mainNode, pScene->mRootNode, texturename, render);
	}
	else
	{
		printf("Error parsing '%s': '%s'\n", meshname, Importer.GetErrorString());
	}

}

void MeshLoader::InitFromScene(const aiScene* scene, Node *node, aiNode* root, const char * texturename, Renderer * render)
{
	
	for  (int i = 0; i < root->mNumChildren;i++)
	{
		Node * childNode = new Node();
		if(root->mChildren[i]->mMeshes > 0)
		{
			//creo el componente mesh
			//MeshComponent *meshComp = new MeshComponent(_MeshComponent,material,);
			
		}
	}
}
void InitMesh(unsigned int Index, const aiMesh* Mesh, Renderer * render)
{

}