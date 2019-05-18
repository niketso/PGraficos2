#pragma once
#define ASSIMP_LOAD_FLAGS (aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices)
#include "Exports.h"
#include <vector>
#include"Importer.h"
#include<assimp/Importer.hpp>
#include<assimp/postprocess.h>
#include<assimp/scene.h>
#include<gl/glew.h>
#include<glm/vec2.hpp>
#include<glm/vec3.hpp>
using namespace std;
using namespace glm;

struct MeshData
{	
	vector<float> vertexVec;
	vector<unsigned int> indexVec;
	vector<float> uvVec;
};

struct Vertex
{
	vec3 m_pos;
	vec2 m_tex;
	vec3 m_normal;

	Vertex() {}

	Vertex(const vec3& pos, const vec2& tex, const vec3& normal)
	{
		m_pos = pos;
		m_tex = tex;
		m_normal = normal;
	}
};
struct MeshEntry {
	MeshEntry() {};

	~MeshEntry() {};

	void Init(const std::vector<Vertex>& Vertices,
		const std::vector<unsigned int>& Indices);

	GLuint VB;
	GLuint IB;
	unsigned int NumIndices;
	unsigned int MaterialIndex;
};

std::vector<MeshEntry> m_Entries;
std::vector<BMPheader*> m_Textures;



class ENGINEDLL_API ModelImporter
{
private:
vector<MeshData> aux;


public:
	ModelImporter();
	~ModelImporter();
	bool LoadMesh(const char * MeshName);
	bool InitFromScene(const aiScene* pScene, const std::string& Filename);
    void InitMesh(unsigned int Index, const aiMesh* paiMesh);
    void Clear(vector<BMPheader*> &texture);

};

