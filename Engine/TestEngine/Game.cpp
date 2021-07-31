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
	//MeshLoader::GetInstance()->LoadMesh("scenedefault.fbx", "rifle_texture.bmp", render, sceneNode, camera);
	MeshLoader::GetInstance()->LoadMesh("cube.fbx", "rifle_texture.bmp", render, sceneNode, camera);

	Node * node = sceneNode->GetChild(1);
	node->GetTransfrom()->SetScale(0.5f, 0.5f, 0.5f);
	
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

