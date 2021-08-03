#include "MeshLoader.h"

MeshLoader* MeshLoader::instance = NULL;

MeshLoader::MeshLoader()
{
}


MeshLoader::~MeshLoader()
{
}

Node* MeshLoader::LoadMesh(const char * meshname, const char * texturename, Renderer * render, Node * rootNode, Camera * camera)
{
	
	boundingBoxMin = glm::vec3(INT_MAX, INT_MAX, INT_MAX);
	boundingBoxMax = glm::vec3(INT_MIN, INT_MIN, INT_MIN);
		
	Assimp::Importer Importer;

	const aiScene* Scene = Importer.ReadFile(meshname, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

	if (!Scene || !Scene->HasMeshes())
	{
		printf("Error parsing '%s': '%s'\n", meshname, Importer.GetErrorString());
		return false;
	}
		
	
	InitFromScene(Scene, rootNode, Scene->mRootNode, texturename, render, camera);
	
	return rootNode;

}

void MeshLoader::InitFromScene(const aiScene* scene, Node *root,aiNode* aiNode, const char * texturename, Renderer * render,Camera * camera)
{	
	
	for (int i = 0; i < (int)aiNode->mNumMeshes; i++)
	{
		MeshComponent * mesh = new MeshComponent(ComponentType::_MeshComponent, render,camera);
		mesh->SetTexture(texturename);
		mesh->LoadMaterial();
		InitMesh(scene->mMeshes[aiNode->mMeshes[i]], mesh, render);	
		GenerateBoundingBox(mesh ,render);
		Node * child = new Node(render);
		child->AddComponent((Component*)mesh);
		root->AddChild(child);
		SetNodeTransform(aiNode, child);
		IsBspNode(scene->mMeshes[aiNode->mMeshes[i]], child, mesh);
	}
	for (int i = 0; i < (int)aiNode->mNumChildren; i++) 
	{ 
		InitFromScene(scene, root, aiNode->mChildren[i], texturename, render,camera);
	}

}
void MeshLoader::InitMesh(const aiMesh* mesh, MeshComponent *meshcomponent, Renderer * render)
{
	
	vector<float> vertexVec;
	vector<float> uvVec;
	vector<unsigned int> indexVec;

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		aiVector3D *pos = &(mesh->mVertices[i]);
		vertexVec.push_back(pos->x);
		vertexVec.push_back(pos->y);
		vertexVec.push_back(pos->z);

		if (pos->x < boundingBoxMin.x)
			boundingBoxMin.x = pos->x;

		if (pos->x > boundingBoxMax.x)
			boundingBoxMax.x = pos->x;

		if (pos->y < boundingBoxMin.y)
			boundingBoxMin.y = pos->y;

		if (pos->y > boundingBoxMax.y)
			boundingBoxMax.y = pos->y;

		if (pos->z < boundingBoxMin.z)
			boundingBoxMin.z = pos->z;

		if (pos->z > boundingBoxMax.z)
			boundingBoxMax.z = pos->z;

		meshcomponent->UpdateData(boundingBoxMin, boundingBoxMax);

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

void MeshLoader::GenerateBoundingBox(MeshComponent * mesh, Renderer *render)
{
	glm::vec3 boundingBoxVertices[CUBE_VERTEX] =
	{
		glm::vec3(boundingBoxMin.x, boundingBoxMin.y, boundingBoxMin.z),
		glm::vec3(boundingBoxMin.x, boundingBoxMax.y, boundingBoxMin.z),
		glm::vec3(boundingBoxMin.x, boundingBoxMin.y, boundingBoxMax.z),
		glm::vec3(boundingBoxMin.x, boundingBoxMax.y, boundingBoxMax.z),
		glm::vec3(boundingBoxMax.x, boundingBoxMin.y, boundingBoxMin.z),
		glm::vec3(boundingBoxMax.x, boundingBoxMax.y, boundingBoxMin.z),
		glm::vec3(boundingBoxMax.x, boundingBoxMin.y, boundingBoxMax.z),
		glm::vec3(boundingBoxMax.x, boundingBoxMax.y, boundingBoxMax.z)
	};

		mesh->bCube->SetVertex(boundingBoxVertices);
}

void MeshLoader::SetNodeTransform(aiNode * aiNode, Node * node) {

	aiVector3D aiScaling;
	aiVector3D aiPosition;
	aiQuaternion aiRotation;

	aiNode->mTransformation.Decompose(aiScaling, aiRotation, aiPosition);

	TransformComponent * transform = node->GetTransfrom();

	transform->SetRotationMatrix(aiRotation.x, aiRotation.y, aiRotation.z, aiRotation.w);
	transform->SetPos(aiPosition.x, aiPosition.y, aiPosition.z);
	transform->SetScale(aiScaling.x, aiScaling.y, aiScaling.z);

	

}

bool MeshLoader::IsBspNode(const aiMesh * paiMesh, Node * node, MeshComponent * meshComponent)
{
	string meshName = paiMesh->mName.C_Str();
	if (meshName.compare(0, 5, "Plane") == 0) {
		meshComponent->SetBSP(true, node);
		return true;
	}
	return false;
}
