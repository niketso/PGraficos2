#include "Exports.h"
#include "Renderer.h"
#include "Component.h"
#include "BoundingCube.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>

enum Planes {
	TOP = 0,
	BOTTOM,
	LEFT,
	RIGHT,
	NEARP,
	FARP,
	COUNT
};

class ENGINEDLL_API Camera:public Component
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
	glm::vec3 ntl, ntr, nbl, nbr, ftl, ftr, fbl, fbr;

	// camera dist
	float nearD, farD, ratio, angle, tang;
	//width height
	float nw, nh, fw, fh;

public:
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
	int boxInFrustrum(BoundingCube * boundingCube);

};

