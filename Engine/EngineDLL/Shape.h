#pragma once
#include "Entity.h"
#include "Material.h"

#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006

class  ENGINEDLL_API Shape :public Entity
{
protected:
	Material * material;
	bool shouldDispose;
	bool shouldDisposeColor;
	unsigned int bufferId;
	unsigned int colorBufferId;
	unsigned int indexBufferId;
	float * vertex;
	float * clrvertex;	
	unsigned int * indxvertex;
	int vtxCount;
	int colorVtxCount;
	int idxVtxCount;
	

public:
	Shape(Renderer *render);
	~Shape();
	void SetVertices(float* vertices, int count);
	void SetColorVertices(float* vertices, int count);
	void SetIndexVertices(unsigned int* vertices, int count);
	virtual void Draw() = 0;
	virtual void  DrawMesh(int drawType);
	void SetMaterial(Material* material);
	void Dispose();
	void DisposeColor();
	
};

