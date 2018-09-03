#include "Exports.h"
#include "Window.h"

#include <iostream>
using namespace std;
class ENGINEDLL_API Renderer
{
private:
	Window * window;

public:
	Renderer();
	~Renderer();
	bool Start(Window *windowPTR);
	bool Stop();
	void ClearScreen();
	void ClearColor(float r, float g, float b, float a);
	void SwapBuffers();
	void GenBuffer(float* buffer, int size);
	void DrawBuffer(unsigned int vtxbuffer, int size);
};
