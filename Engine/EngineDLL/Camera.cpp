#include "Camera.h"


Camera::Camera(ComponentType type,Renderer *render)
{
	this->render = render;
	this->type = type;

	eyePos = glm::vec3(0.0f, 0.0f, 10.0f);
	upVec = glm::vec3(0.0f, 1.0f, 0.0f);


	forward = glm::vec4(0.0f, 0.0f, -1.0f,0.0f);
	right = glm::vec4(1.0f, 0.0f, 0.0f,0.0f);
	upDir = glm::vec4(0.0f, 1.0f, 0.0f,0.0f);

	camPos = eyePos + (glm::vec3)forward;
}

Camera::~Camera()
{
}

void Camera::Update() 
{
	render->SetViewMatrix(eyePos, camPos, upVec);
}
void Camera::Draw()
{
}
void Camera::Walk(float dir)
{
	camPos += (glm::vec3)forward * dir;
	eyePos += (glm::vec3)forward * dir;
	Update();
}
void Camera::Strafe(float dir)
{
	camPos += (glm::vec3)right * dir;
	eyePos += (glm::vec3)right * dir;
	Update();
}
void Camera::Pitch(float dir) 
{
	//multiplicar por una matriz de rotacion a el eje x (right).
	 forward =  glm::rotate(glm::mat4(1.0f), dir, glm::vec3(right.x, right.y, right.z)) * forward ;
	 upDir = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(right.x, right.y, right.z)) * upDir;
	
	 upVec = (glm::vec3)upDir;
	 camPos = eyePos + (glm::vec3)forward;
	 Update();
}
void Camera::yaw(float dir) 
{
	//fijo up
	forward = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(upVec.x, upVec.y, upVec.z)) * forward;
	right = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(upVec.x, upVec.y, upVec.z)) * right;

	upVec = (glm::vec3)upDir;
	camPos = eyePos + (glm::vec3)forward;
	Update();
}
void Camera::Roll(float dir)
{
	//fijo forward
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(forward.x, forward.y, forward.z));
	right = rot * right;
	upDir = rot * upDir;

	upVec = (glm::vec3)upDir;
	camPos = eyePos + (glm::vec3)forward;
	Update();
}


