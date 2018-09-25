#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINEDLL_API Rectangle :public Entity
{
private:
	Material * material;
	bool shouldDispose;
	unsigned int bufferId;
	float * vertex;
	int vtxCount;

public:
	Rectangle(Renderer *render);
	~Rectangle();
	void SetVertices(float * vertices, int count);
	void Draw() override;
	void SetMaterial(Material* material);
	void Dispose();

};

