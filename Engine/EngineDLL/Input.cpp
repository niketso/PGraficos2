#include "Input.h"
#include <GLFW\glfw3.h>

Input::Input(Window *window) 
{
		win = window;
}


bool Input::IsKeyPressed(int i)
{
	if (glfwGetKey((GLFWwindow*)win->GetWindow(), i) == GLFW_PRESS) //87 w
		return true;
	if (glfwGetKey((GLFWwindow*)win->GetWindow(), i) == GLFW_PRESS)//83 s 
		return true;
	if (glfwGetKey((GLFWwindow*)win->GetWindow(), i) == GLFW_PRESS)//65 a
		return true;
	if (glfwGetKey((GLFWwindow*)win->GetWindow(), i) == GLFW_PRESS)//68 d
		return true;
	return false;
}
