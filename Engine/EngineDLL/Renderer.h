#pragma once
#include "Exports.h"
#include "Window.h"
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>

#include <iostream>
using namespace std;
class ENGINEDLL_API Renderer
{
private:
	unsigned int VertexArrayID;
	Window * window;
	glm::mat4 worldMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::mat4 othoProjectionMatrix;
	glm::mat4 perspectiveProjectionMatrix;
	glm::mat4 wvp;

	//ortho
	/*const float left;
	const float right;
	const float bottom;
	const float top;
	const float zNear;
	const float zFar;*/

	//Perspective
	/*const float angle;
	const float aspect;
	const float zNear;
	const float zFar;*/

	glm::vec3 camPos;
	glm::vec3 eyePos;
	glm::vec3 upPos;

public:
	Renderer();
	~Renderer();
	bool Start(Window *windowPTR);
	bool Stop();
	void ClearScreen();
	void ClearColor(float r, float g, float b, float a);
	void SwapBuffers();
	unsigned int  GenBuffer(float* buffer, int size);
	unsigned int  GenColorBuffer(float* buffer, int size);
	unsigned int GenTextureBuffer(int width, int height, unsigned char* data);
	void BindBuffer(unsigned int vtxbuffer, unsigned int name);
	void BindColorBuffer(unsigned int clrbuffer, unsigned int name);
	void BindTextureBuffer(unsigned int txtrebuffer, unsigned int name);
	void BeginDraw(unsigned int name);
	void EndDraw(unsigned int name);
	void DrawBuffer( int size,int drawType);
	void DestroyBuffer(unsigned int buffer);
	void UpdateWVP();
	glm::mat4&  GetWvp();
	void TranslateCamera(glm::vec3 pos);
	void LoadIdentityMatrix();
	void SetWorldMatrix(glm::mat4 mat);
	void MultiplyWorldMatrix(glm::mat4 mat);
	void UpdateTexture(unsigned int txt);
	void SetOrthoProjectionMatrix(const float left, const float right, const float bottom, const float top, const float ZNear, const float ZFar);
	void SetPerspectiveProjectionMatrix(const float angle, const float aspect, const float ZNear, const float ZFar);
	void SwitchProjectionMatrix(glm::mat4 ortho, glm::mat4 perspective);
	void SetViewMatrix(glm::vec3 eye, glm::vec3 cam, glm::vec3 up);
	glm::vec3 GetCameraPos();
	
};
