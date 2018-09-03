#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINEDLL_API Triangle :public Entity
{
private:
	Renderer * renderer;
public:
	Triangle();
	~Triangle();
	void SetVertices();
	void Draw();
	
};

