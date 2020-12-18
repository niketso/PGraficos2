#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "Definitions.h"
#include <iostream>
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>

class ENGINEDLL_API BoundingCube
{
private:
	glm::vec3 Cube[CUBE_VERTEX];
	Renderer *render;
public:
	glm::vec3 GetVertex(int index);
	float * getVertex();
	void setVertex(int index, glm::vec3 pos);
	void SetVertex(glm::vec3 _cube[CUBE_VERTEX]);
	BoundingCube(Renderer * render);
	~BoundingCube();
};

