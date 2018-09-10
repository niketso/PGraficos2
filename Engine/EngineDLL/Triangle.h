#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINEDLL_API Triangle :public Entity
{
private:
	Material * material;
	bool shouldDispose;
	unsigned int bufferId;
	float * vertex;
	int vtxCount;
	
public:
	Triangle(Renderer *render);	
	~Triangle();
	void SetVertices(float * vertices, int count);
	void Draw() override;
	void SetMaterial(Material* material);
	void Dispose();
	
};

