#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "Definitions.h"
#include<iostream>
using namespace std;
class ENGINEDLL_API Entity
{
private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
	float height;
	float width;
	glm::vec3 pivotPosition;
	Layers layer;
	
protected:
	Renderer * render;
	glm::mat4 WorldMatrix;
	glm::mat4 TranslateMatrix;
	glm::mat4 RotMatrix;
	glm::mat4 ScaleMatrix;
	void UpdateWorldMatrix();
public:

	Entity(Renderer * renderPTR);	
	virtual void Draw() = 0;
	void SetPos(float x, float y,float z);
	void SetRot(float x, float y,float z);
	void SetScale(float x,float y, float z);
	glm::vec3 GetPos();
	glm::vec3 GetRot();
	glm::vec3 GetScale();

	//BoundingBox
	void SetBoundingBox(glm::vec3 pPos, float height, float width, Layers layer);
	unsigned int GetX();
	unsigned int GetY();
	glm::vec2 GetPivot();
	unsigned int GetHeight();
	unsigned int GetWidth();
};

