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
	
	camera = new Camera(_CameraComponent,render);
	sceneNode = new Node(render);
	cameraNode = new Node(render);
	
	sceneNode->AddChild(cameraNode);
	cameraNode->AddComponent(camera);
	//MeshLoader::GetInstance()->LoadMesh("scenedefault.fbx", "rifle_texture.bmp", render, sceneNode, camera);
	MeshLoader::GetInstance()->LoadMesh("cube.fbx", "rifle_texture.bmp", render, sceneNode, camera);

	Node * node = sceneNode->GetChild(1);
	node->GetTransfrom()->SetScale(1.0f, 1.0f, 1.0f);
	camera->Walk(-20.0f);
	
	//sceneNode->GetChild(1)->Move(-20.0f, 0.0f, 0.0f);
	//sceneNode->GetChild(2)->Move(-20.0f, 0.0f, 0.0f);
	//sceneNode->GetChild(3)->Move(-30.0f, 0.0f, 0.0f);
	//sceneNode->GetChild(4)->Move(10.0f, 0.0f, 0.0f);
	//sceneNode->GetChild(5)->Move(20.0f, 0.0f, 0.0f);
	//sceneNode->GetChild(6)->Move(30.0f, 0.0f, 0.0f);
	

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
		camera->Walk(0.1);
	if (inp->IsKeyPressed(83)) //s
		camera->Walk(-0.1);
	if (inp->IsKeyPressed(65)) //a
		camera->Strafe(0.05); 
	if (inp->IsKeyPressed(68)) //d
		camera->Strafe(-0.05);
	if (inp->IsKeyPressed(265)) //
		camera->Pitch(-0.003);
	if (inp->IsKeyPressed(264)) //
		camera->Pitch(0.003);
	if (inp->IsKeyPressed(263)) //
		camera->yaw(0.003);
	if (inp->IsKeyPressed(262)) //
		camera->yaw(-0.003);
		
	
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

