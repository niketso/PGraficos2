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
	
	cameraComponent = new Camera(_CameraComponent,render);
	sceneNode = new Node(render);
	cameraNode = new Node(render);
	
	//sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("sceneDefault.fbx", "rifle_texture.bmp", render,sceneNode));
	cameraNode->AddComponent(cameraComponent);
	sceneNode->AddChild(cameraNode);
	MeshLoader::GetInstance()->LoadMesh("sceneDefault.fbx", "rifle_texture.bmp", render, sceneNode);
	
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

	cameraComponent->Update();
	if (inp->IsKeyPressed(87))
		cameraComponent->Walk(0.3);
	if (inp->IsKeyPressed(83))
		cameraComponent->Walk(-0.3);
	if (inp->IsKeyPressed(65))
		cameraComponent->Strafe(0.3);
	if (inp->IsKeyPressed(68))
		cameraComponent->Strafe(-0.3);
	if (inp->IsKeyPressed(265))
		cameraComponent->Pitch(0.03);
	if (inp->IsKeyPressed(264))
		cameraComponent->Pitch(-0.03);
	if (inp->IsKeyPressed(263))
		cameraComponent->yaw(0.03);
	if (inp->IsKeyPressed(262))
		cameraComponent->yaw(-0.03);
		
	
	//msh1->Rotate(0.0f, 0.003f, 0.0f);
	//movY
	
	CollisionManager::Instance()->CollisionBoxDetector();
	cout << "Game::OnUpdate(): " << i << endl;
	
	return true;
}

void Game::OnDraw()
{		
	//msh1->DrawMesh(0);	
	//render->LoadIdentityMatrix();
	//sceneNode->Draw();
	cout << "Game::OnDraw(): " << i << endl;
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