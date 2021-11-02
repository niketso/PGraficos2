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
	meshNode = new Node(render);
	
	cameraNode->AddComponent(camera);
	sceneNode->AddChild(cameraNode);
	sceneNode->AddChild(meshNode);
	//MeshLoader::GetInstance()->LoadMesh("scenedefault.fbx", "rifle_texture.bmp", render, sceneNode, camera);
	MeshLoader::GetInstance()->LoadMesh("Rifle.fbx", "rifle_texture.bmp", render, meshNode, camera);

	node = meshNode->GetChild(1);
	// node2 = meshNode->GetChild(1);
	//node->GetTransfrom()->SetScale(0.1f, 0.1f, 0.1f);	
	//node2->GetTransfrom()->SetScale(1.0f, 1.0f, 1.0f);
	//node2->GetTransfrom()->SetPos(0.0f, 0.0f, 0.0f);
	//node->GetTransfrom()->SetRot(-90.0f, 0.0f, 0.0f);
	
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


	if (inp->IsKeyPressed(73)) //i		
	{
		//node->SetScale(0.5f, 0.5f, 0.5f);
		node->GetTransform()->SetScale(0.5f, 0.5f, 0.5f);
		cout << "A" << endl;
	}
	if (inp->IsKeyPressed(75)) //k
		node->GetTransform()->SetPos(0.0f, -5.0f*deltaTime, 0.0f);
	if (inp->IsKeyPressed(74)) //j
		node->GetTransform()->SetPos(5.0f, 0.0f*deltaTime, 0.0f);
	if (inp->IsKeyPressed(76)) //l
		node->GetTransform()->SetPos(-5.0f, 0.0f*deltaTime, 0.0f);
	
	
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

