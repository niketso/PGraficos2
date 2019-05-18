#include "ModelImporter.h"



ModelImporter::ModelImporter()
{
}


ModelImporter::~ModelImporter()
{
}

bool ModelImporter::LoadMesh(const char* MeshName)
{
	Clear(m_Textures);

	bool Ret = false;
	Assimp::Importer Importer;

	const aiScene* pScene = Importer.ReadFile(MeshName, ASSIMP_LOAD_FLAGS);

	if (pScene) {
		Ret = InitFromScene(pScene, MeshName);
	}
	else {
		printf("Error parsing '%s': '%s'\n", MeshName, Importer.GetErrorString());
	}

	return Ret;
}

bool ModelImporter::InitFromScene(const aiScene * pScene, const std::string & Filename)
{
	m_Entries.resize(pScene->mNumMeshes);
	m_Textures.resize(pScene->mNumMaterials);

	// Initialize the meshes in the scene one by one
	for (unsigned int i = 0; i < m_Entries.size(); i++) {
		const aiMesh* paiMesh = pScene->mMeshes[i];
		InitMesh(i, paiMesh);
	}
	return false;
}

void ModelImporter::InitMesh(unsigned int Index, const aiMesh * paiMesh)
{
	m_Entries[Index].MaterialIndex = paiMesh->mMaterialIndex;

	std::vector<Vertex> Vertices;
	std::vector<unsigned int> Indices;

	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

	for (unsigned int i = 0; i < paiMesh->mNumVertices; i++) {
		const aiVector3D* pPos = &(paiMesh->mVertices[i]);
		const aiVector3D* pNormal = &(paiMesh->mNormals[i]);
		const aiVector3D* pTexCoord = paiMesh->HasTextureCoords(0) ? &(paiMesh->mTextureCoords[0][i]) : &Zero3D;

		Vertex v(vec3(pPos->x, pPos->y, pPos->z),
			vec2(pTexCoord->x, pTexCoord->y),
			vec3(pNormal->x, pNormal->y, pNormal->z));

		Vertices.push_back(v);
	}

	for (unsigned int i = 0; i < paiMesh->mNumFaces; i++) {
		const aiFace& Face = paiMesh->mFaces[i];
		assert(Face.mNumIndices == 3);
		Indices.push_back(Face.mIndices[0]);
		Indices.push_back(Face.mIndices[1]);
		Indices.push_back(Face.mIndices[2]);
	}

	m_Entries[Index].Init(Vertices, Indices);
}

void ModelImporter::Clear(vector<BMPheader*>& texture)
{
	for (unsigned int i = 0; i < m_Textures.size(); i++) {
		if (texture[i] != NULL)
		{
			delete texture[i];
			texture[i] = NULL;
		}
	}
}



