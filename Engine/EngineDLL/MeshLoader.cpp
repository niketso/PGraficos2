#include "MeshLoader.h"

MeshLoader* MeshLoader::instance = NULL;

MeshLoader::MeshLoader()
{
}


MeshLoader::~MeshLoader()
{
}

Node* MeshLoader::LoadMesh(const char * meshname, const char * texturename, Renderer * render)
{
	Assimp::Importer Importer;

	const aiScene* Scene = Importer.ReadFile(meshname, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

	

	if (!Scene)
	{
		printf("Error parsing '%s': '%s'\n", meshname, Importer.GetErrorString());		
	}
	
	Node * mainNode = new Node(render);
	InitFromScene(Scene, mainNode, Scene->mRootNode, texturename, render);
	
	return mainNode;

}

void MeshLoader::InitFromScene(const aiScene* scene, Node *node,aiNode* root, const char * texturename, Renderer * render)
{
	
	for  (int i = 0; i < root->mNumChildren;i++)
	{
		Node * childNode = new Node(render);
		node->AddChild(childNode);
		if(root->mChildren[i]->mMeshes > 0)
		{
			MeshComponent *meshComp = new MeshComponent(_MeshComponent,render);
			childNode->AddComponent(meshComp);
			unsigned int index = root->mChildren[i]->mMeshes[0];
			InitMesh(scene->mMeshes[index], meshComp, render);
			meshComp->SetTexture(texturename);
			meshComp->LoadMaterial();

		}
	}
}
void MeshLoader::InitMesh(const aiMesh* mesh, MeshComponent *meshcomponent, Renderer * render)
{
	
	vector<float> vertexVec;
	vector<float> uvVec;
	vector<unsigned int> indexVec;

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		aiVector3D pos = mesh->mVertices[i];
		vertexVec.push_back(pos.x);
		vertexVec.push_back(pos.y);
		vertexVec.push_back(pos.z);

		aiVector3D uv = mesh->mTextureCoords[0][i];
		uvVec.push_back(uv.x);
		uvVec.push_back(uv.y);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		indexVec.push_back(mesh->mFaces[i].mIndices[0]);
		indexVec.push_back(mesh->mFaces[i].mIndices[1]);
		indexVec.push_back(mesh->mFaces[i].mIndices[2]);
	}

	meshcomponent->SetVertices(vertexVec);
	meshcomponent->SetUv(uvVec);
	meshcomponent->SetIndex(indexVec);
}
