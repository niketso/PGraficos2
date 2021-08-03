#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "Component.h"
#include "BoundingCube.h"
#include "Definitions.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>


class MeshComponent;

class ENGINEDLL_API Camera : public Component
{
private:
	Renderer * render;
	ComponentType type;
	glm::vec3 eyePos;
	glm::vec3 camPos;
	glm::vec3 upVec;

	glm::vec4 forward; //z
	glm::vec4 right;	//x
	glm::vec4 upDir;	//y

	glm::vec4 pl[COUNT];

	// camera dist
	float nearD, farD, ratio, angle, tang;
	//width height
	float nw, nh;

	vector<glm::vec4> * bspPlanes;
	vector<glm::vec3> * bspPlanesNormals;


public:
	//Camera * camera;
	Camera(ComponentType type,Renderer * render);
	~Camera();
	void Update();
	void Draw();
	void Walk(float dir);
	void Strafe(float dir);
	void Pitch(float dir);
	void yaw(float dir);
	void Roll(float dir);
	void SetCamInternals();
	void SetCamDef();
	glm::vec4 generatePlane(glm::vec3 normal, glm::vec3 point);

	int BoxInFrustum(BoundingCube * boundingCube);
	void AddBSP(MeshComponent * plane, glm::vec3 nodePos);
	int BoxInBSP(BoundingCube * boundingCube);
	float GetDistanceToPlane(glm::vec3 point, glm::vec4 _plane, glm::vec3 _planeNormal);
	
};

