#include "Camera.h"


Camera::Camera(Renderer *render) 
{
	r1 = render;
	camPos = glm::vec3(0.0f, 0.0f, 0.0f);
	eyePos = glm::vec3(0.0f, 0.0f, 3.0f);
	upVec = glm::vec3(0.0f, 1.0f, 0.0f);

	forward = glm::vec4(0.0f, 0.0f, 1.0f,0.0f);
	right = glm::vec4(1.0f, 0.0f, 0.0f,0.0f);
	upDir = glm::vec4(0.0f, 1.0f, 0.0f,0.0f);

}

Camera::~Camera()
{
}
void Camera::Walk(float dir)
{
	camPos += forward * dir;
	eyePos += forward * dir;
	r1->SetViewMatrix(eyePos, camPos, upVec);
}
void Camera::Strafe(float dir)
{
	camPos += right * dir;
	eyePos += right * dir;
	r1->SetViewMatrix(eyePos, eyePos + forward, upVec);
}
void Camera::Pitch(float dir) 
{
	//multiplicar por una matriz de rotacion a el eje x (right).
	  // forward * glm::rotate(glm::mat4(1.0f), dir, glm::vec3(1, 0, 0));
	  
	glm::rotate(glm::mat4(1.0f), dir, glm::vec3(1, 0, 0));
	
	r1->SetViewMatrix(eyePos, camPos, upVec);
}
void Camera::yaw(float dir) 
{
	camPos+= dir;
	eyePos.y += dir;
	r1->SetViewMatrix(eyePos, camPos, upVec);
}
void Camera::Roll(float dir)
{

}


