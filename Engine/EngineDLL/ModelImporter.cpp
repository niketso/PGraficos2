#include "ModelImporter.h"


vector<MeshEntry> ModelImporter::m_Entries;
vector<BMPheader> ModelImporter::m_Textures;
unsigned int textureBufferId = NULL;
ModelImporter::ModelImporter()
{
	
}


ModelImporter::~ModelImporter()
{
}

 void ModelImporter::LoadMesh(const char * meshname, const char * texturename, vector<BMPheader> *texture, vector<MeshEntry> *entries, Renderer * render)
{
	 m_Entries = *entries;
		m_Textures = *texture;


	Assimp::Importer Importer;

	  const aiScene* pScene = Importer.ReadFile(meshname, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);
	
	InitFromScene(pScene, texturename,texture,entries,render);
	
	if (!pScene) {
		printf("Error parsing '%s': '%s'\n", meshname, Importer.GetErrorString());
	}

	
}

  void ModelImporter::InitFromScene(const aiScene * pScene, const char* filename, vector<BMPheader> *texture, vector<MeshEntry> *entries, Renderer * render)
{
	m_Entries.resize(pScene->mNumMeshes);
	m_Textures.resize(pScene->mNumMaterials);

	// Initialize the meshes in the scene one by one
	for (unsigned int i = 0; i < m_Entries.size(); i++) {
		const aiMesh* paiMesh = pScene->mMeshes[i];
		InitMesh(i, paiMesh,render);
	}
	
	for (int i = 0; i < pScene->mNumMaterials; i++)
	{
		m_Textures[i] = Importer::LoadBMP(filename);
		textureBufferId = render->GenTextureBuffer(m_Textures[0].width, m_Textures[0].height, m_Textures[0].data);
	}

}

  unsigned int ModelImporter::GetTextureBuffer() 
  {
	  return textureBufferId;
  }
void ModelImporter::InitMesh(unsigned int Index, const aiMesh * paiMesh, Renderer * render)
{	
	vector<Vertex> Vertices;
	vector<unsigned int> Indices;

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

	 m_Entries[Index].Init(Vertices, Indices,render);

}











