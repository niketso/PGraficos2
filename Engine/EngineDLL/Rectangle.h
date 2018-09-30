#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINEDLL_API Rectangle :public Entity
{
private:
	Material * material;
	bool shouldDispose;
	unsigned int bufferId;
	unsigned int colorBufferId;
	float * vertex;
	float * colorvertex;
	int vtxCount;
	int colorVtxCount;

public:
	Rectangle(Renderer *render);
	~Rectangle();
	void SetVertices(float * vertices, int count);
	void SetColorVertices(float * vertices, int count);
	void Draw() override;
	void SetMaterial(Material* material);
	void Dispose();

};

