#pragma once

#include "Exports.h"
#include"Importer.h"
#include "Mesh.h"

#include<assimp/Importer.hpp>
#include<assimp/postprocess.h>
#include<assimp/scene.h>

#include"../external/glew-2.1.0/include/GL/glew.h"
#include "../external/glm-0.9.9.0/glm/vec2.hpp"
#include "../external/glm-0.9.9.0/glm/vec3.hpp"

#include <vector>
using namespace std;
using namespace glm;

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
	unsigned int vertexBuffer;
	unsigned int indexBuffer;
	unsigned int uvBuffer;

	
	
	void Init(const vector<Vertex>& Vertices, const vector<unsigned int>& Indices,Renderer *render)
	{
		
		float* meshPos = new float[Vertices.size() * 3];
		float* textPos = new float[Vertices.size() * 2];
		float* normalPos = new float[Vertices.size() * 3];

		for (unsigned int  i = 0; i < Vertices.size(); i++)
		{
			meshPos[i * 3] = Vertices[i].m_pos.x;
			meshPos[i * 3 + 1] = Vertices[i].m_pos.y;
			meshPos[i * 3 + 2] = Vertices[i].m_pos.z;

			textPos[i * 2] = Vertices[i].m_tex.x;
			textPos[i * 2 + 1] = Vertices[i].m_tex.y;

			normalPos[i * 3] = Vertices[i].m_normal.x;
			normalPos[i * 3 + 1] = Vertices[i].m_normal.y;
			normalPos[i * 3 + 2] = Vertices[i].m_normal.z;

			//MeshData::SetMeshInfo(meshinfo);

		}

		vertexBuffer = render->GenBuffer(meshPos, sizeof(float)* Vertices.size() * 3);
		indexBuffer = render->GenIndexBuffer(Indices);
		uvBuffer = render->GenBuffer(textPos, sizeof(float)* Vertices.size() * 2);
	}


	GLuint VB;
	GLuint IB;
	unsigned int NumIndices;
	unsigned int MaterialIndex;
};

 static class ENGINEDLL_API ModelImporter
{


public:
	
	ModelImporter();
	~ModelImporter();
	static void LoadMesh(const char * meshname,const char * texturename, vector<BMPheader*> texture, vector<MeshEntry> entries,Renderer * render);
	static void InitFromScene(const aiScene* pScene, const char* filename, Renderer * render);
	static void InitMesh(unsigned int Index, const aiMesh* paiMesh, Renderer * render);
	static void Clear(vector<BMPheader*> texture);
	
	 static vector<MeshEntry> m_Entries;
	 static vector<BMPheader> m_Textures;
};

