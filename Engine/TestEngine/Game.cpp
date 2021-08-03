#include "Game.h"
Game::Game()
{
	i = 0;	
}
Game::~Game()
{
}
bool Game::OnStart() {
	CollisionManager* colManager = CollisionManager::Instance();
	inp = new Input(window);
	speed = 30.0f;
	camera = new Camera(_CameraComponent,render);
	sceneNode = new Node(render);
	cameraNode = new Node(render);
	
	sceneNode->AddChild(cameraNode);
	cameraNode->AddComponent(camera);
	
	MeshLoader::GetInstance()->LoadMesh("BSP.fbx", "rifle_texture.bmp", render, sceneNode, camera);

	 node = sceneNode->GetChild(1);
	
	SetScene(sceneNode);
	
	cout << "Game::OnStart()" << endl;
	return true;
}
bool Game::OnStop() {
	cout << "Game::OnStop()" << endl;
	return false;
}
bool Game::OnUpdate() {
	i++;
	//movX

	//camera->Update();
	if (inp->IsKeyPressed(87)) //w
		camera->Walk(speed * deltaTime);
	if (inp->IsKeyPressed(83)) //s
		camera->Walk(-speed * deltaTime);
	if (inp->IsKeyPressed(65)) //a
		camera->Strafe(speed * deltaTime);
	if (inp->IsKeyPressed(68)) //d
		camera->Strafe(-speed * deltaTime);
	if (inp->IsKeyPressed(265)) //
		camera->Pitch(-deltaTime);
	if (inp->IsKeyPressed(264)) //
		camera->Pitch(deltaTime);
	if (inp->IsKeyPressed(263)) //
		camera->yaw(deltaTime);
	if (inp->IsKeyPressed(262)) //
		camera->yaw(-deltaTime);
	
	if (inp->IsKeyPressed(74)) //j
		node->GetTransfrom()->Translate(speed * deltaTime,0.0f,0.0f);
	if (inp->IsKeyPressed(76)) //l
		node->GetTransfrom()->Translate(-speed * deltaTime, 0.0f, 0.0f);
	if (inp->IsKeyPressed(73)) //i
		node->GetTransfrom()->Translate(0.0f,0.0f,speed * deltaTime);
	if (inp->IsKeyPressed(75)) //k
		node->GetTransfrom()->Translate(0.0f, 0.0f, -speed * deltaTime);
	//CollisionManager::Instance()->CollisionBoxDetector();
	//cout << "Game::OnUpdate(): " << i << endl;
	
	return true;
}

void Game::OnDraw()
{		
	//msh1->DrawMesh(0);	
	//render->LoadIdentityMatrix();
	//sceneNode->Draw();
	cout << "Game::OnDraw(): + Objects draw " << render->Draws << endl;
	render->Draws = 0;
}

