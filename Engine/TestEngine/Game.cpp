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
	
	//sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("sceneDefault.fbx", "rifle_texture.bmp", render,sceneNode));
	MeshLoader::GetInstance()->LoadMesh("cube.fbx", "rifle_texture.bmp", render, sceneNode, camera);
	cameraNode->AddComponent(camera);
	sceneNode->AddChild(cameraNode);

	Node * node = sceneNode->GetChild(0);
	node->GetTransfrom()->SetScale(1.0f, 1.0f, 1.0f);
	//MeshLoader::GetInstance()->LoadMesh("sceneDefault.fbx", "rifle_texture.bmp", render, sceneNode);
	camera->Walk(-50.0f);
	
	//sceneNode->GetChild(1)->Move(-10.0f, 0.0f, 0.0f);
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
	if (inp->IsKeyPressed(87))
		camera->Walk(10.0);
	if (inp->IsKeyPressed(83))
		camera->Walk(-10.0);
	if (inp->IsKeyPressed(65))
		camera->Strafe(10.0);
	if (inp->IsKeyPressed(68))
		camera->Strafe(-10.0);
	if (inp->IsKeyPressed(265))
		camera->Pitch(0.03);
	if (inp->IsKeyPressed(264))
		camera->Pitch(-0.03);
	if (inp->IsKeyPressed(263))
		camera->yaw(0.03);
	if (inp->IsKeyPressed(262))
		camera->yaw(-0.03);
		
	
	//msh1->Rotate(0.0f, 0.003f, 0.0f);
	//movY
	
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

/*
	//spr1->LoadTexture("Doom.bmp");
	//spr2->LoadTexture("sample2.bmp");
	//spr1->SetAnimation(0, 23, 0.5f);
	//spr1->SetBoundingBox(spr1->GetPos(), 2.0f, 2.0f, false, false);
	//spr2->SetBoundingBox(spr1->GetPos(), 2.0f, 2.0f, false, false);
	//colManager->AddCollisionEntity(spr1 , player);
	//colManager->AddCollisionEntity(spr2, enemy);
	//spr1->SetPos(-5,0,0);
	//spr1->SetPos(5,0,0);
	//msh1->SetPos(0, 0, 0);
	//msh2->SetPos(0, 0, 0);
	//msh1->Rotate(180.0f,0.0f, 180.0f);
	*/