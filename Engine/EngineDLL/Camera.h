#include "Exports.h"
#include "Renderer.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
class ENGINEDLL_API Camera
{
private:
	Renderer * r1;
	glm::vec3 eyePos;
	glm::vec3 camPos;
	glm::vec3 upVec;
	glm::vec3 forward;
	glm::vec3 right;
	glm::vec3 upDir;

public:
	Camera(Renderer * render);
	~Camera();
	void Walk(float dir);
	void Strafe(float dir);
	void Pitch(float dir);
	void yaw(float dir);
	void Roll(float dir);

};

