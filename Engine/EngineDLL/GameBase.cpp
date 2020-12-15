#include "GameBase.h"
#include <GLFW/glfw3.h>

GameBase::GameBase() {

}
GameBase::~GameBase() {
}
bool GameBase::Start() {
	cout << "Gamebase::Start()" << endl;
	lastFrame = 0;
	window = new Window();
	if (!window->Start(800, 600, " "))
		return false;

	render = new Renderer();	
	if (!render->Start(window))
		return false;
	render->ClearColor(0.0f, 0.0f, 4.0f, 0.0f);
	return OnStart();
}
void GameBase::Loop() {
	
	 looping = true;
	while (looping && !window->ShouldClose()) {
		currentFrame = glfwGetTime();
		render->ClearScreen();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		looping = OnUpdate();	
		
		if (SceneNode)
			SceneNode->Update();
		if (SceneNode)
			SceneNode->Draw();
		OnDraw();
		render->SwapBuffers();
		window->PollEvents();
	}
}
bool GameBase::Stop() {
	cout << "Gamebase::Stop()" << endl;
	OnStop();
	render->Stop();
	window->Stop();

	delete render;
	delete window;
	return true;
}

void GameBase::SetScene(Node * _Scene)
{
	SceneNode = _Scene;
	hasScene = true;
	looping = false;
}


