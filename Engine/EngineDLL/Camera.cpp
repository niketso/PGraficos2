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
	camPos += (glm::vec3)forward * dir;
	eyePos += (glm::vec3)forward * dir;
	r1->SetViewMatrix(eyePos, camPos, upVec);
}
void Camera::Strafe(float dir)
{
	camPos += (glm::vec3)right * dir;
	eyePos += (glm::vec3)right * dir;
	r1->SetViewMatrix(eyePos, camPos, upVec);
}
void Camera::Pitch(float dir) 
{
	//multiplicar por una matriz de rotacion a el eje x (right).
	 forward =  glm::rotate(glm::mat4(1.0f), dir, glm::vec3(1, 0, 0)) * forward ;
	 upDir = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(1, 0, 0)) * upDir;
	
	 upVec = (glm::vec3)upDir;
	 camPos = eyePos + (glm::vec3)forward;
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


