#pragma once
#include "Component.h"
#include "Renderer.h"
#include "Exports.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
class  ENGINEDLL_API CameraComponent  : public Component
{

	Renderer *r1;	
	glm::vec3 eyePos;
	glm::vec3 camPos;
	glm::vec3 upVec;

	glm::vec4 forward;
	glm::vec4 right;
	glm::vec4 upDir;
public:
	CameraComponent(Renderer *render);
	~CameraComponent();	
	void Update();
	void Walk(float dir);
	void Strafe(float dir);
	void Pitch(float dir);
	void yaw(float dir);
	void Roll(float dir);
};

