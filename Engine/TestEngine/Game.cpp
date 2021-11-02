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
	speed = 300.0f;
	camera = new Camera(_CameraComponent,render);
	sceneNode = new Node(render);
	cameraNode = new Node(render);
	MeshNode = new Node(render);
	
	cameraNode->AddComponent(camera);
	sceneNode->AddChild(cameraNode);
	sceneNode->AddChild(MeshNode);
	
	MeshLoader::GetInstance()->LoadMesh("Rifle.fbx", "rifle_texture.bmp", render, MeshNode, camera);

	 node = MeshNode->GetChild(2);
	 //node = node->GetChild(0);
	 //camera->Walk(500.0f);
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
		//node->GetTransfrom()->Translate(0.0f,0.0f,speed * deltaTime);
		node->GetTransfrom()->SetScale(0.5f, 0.5f, 0.5f);
	if (inp->IsKeyPressed(75)) //k
		//node->GetTransfrom()->Translate(0.0f, 0.0f, -speed * deltaTime);
		node->GetTransfrom()->SetScale(1.0f, 1.0f, 1.0f);


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

