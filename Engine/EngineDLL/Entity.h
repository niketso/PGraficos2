#pragma once
#include "Exports.h"
#include "Renderer.h"
#include<iostream>
using namespace std;
class ENGINEDLL_API Entity
{
private:
	glm::vec3 pos;
	glm::vec3 scale;
	glm::vec3 rot;
protected:
	Renderer * render;
	glm::mat4 WorldMatrix;
public:

	Entity(Renderer * renderPTR);	
	virtual void Draw() = 0;
	void SetPos(float x, float y,float z);
	void SetRot(float x, float y,float z);
	void SetScale(float x,float y, float z);
	glm::vec3 GetPos();
	glm::vec3 GetRot();
	glm::vec3 GetScale();
};

