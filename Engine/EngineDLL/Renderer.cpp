#include "Renderer.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>


Renderer::Renderer()
{
}
Renderer::~Renderer()
{
}
bool Renderer::Start(Window * windowPTR) {
	
	if (windowPTR != NULL) 
	{
		window = windowPTR;
		glfwMakeContextCurrent((GLFWwindow*)window->GetWindow());
		cout << "Renderer::Start()" << endl;
		return true;
	}
	
	return false;
	
}
bool Renderer::Stop() {
	cout << "Renderer::Stop()" << endl;
	return false;
}

void Renderer::ClearScreen() 
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::ClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Renderer::SwapBuffers() 
{
	glfwSwapBuffers((GLFWwindow*)window->GetWindow());
}

