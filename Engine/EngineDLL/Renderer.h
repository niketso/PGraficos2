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
	glm::mat4 wvp;

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
	void BindBuffer(unsigned int vtxbuffer, unsigned int name);
	void BindColorBuffer(unsigned int clrbuffer, unsigned int name);
	void BeginDraw(unsigned int name);
	void EndDraw(unsigned int name);
	void DrawBuffer( int size);
	void DestroyBuffer(unsigned int buffer);
	void UpdateWVP();
	glm::mat4&  GetWvp();
	void LoadIdentityMatrix();
	void SetWorldMatrix(glm::mat4 mat);
	void MultiplyWorldMatrix(glm::mat4 mat);
};
