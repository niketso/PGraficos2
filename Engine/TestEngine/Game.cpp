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
	sceneNode = new Node();
	cameraNode = new Node(); 
	meshNode = new Node();
	sceneNode->AddChild(cameraNode);
	sceneNode->AddChild(meshNode);
	mat1 = new Material();
	unsigned int programID = mat1->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	cam = new Camera(render);
	msh1 = new Mesh(render, "M4A1\\M4A1.fbx", "M4A1\\M4A1Tex.bmp");
	msh1->SetMaterial(mat1);
	mshComp = new MeshComponent(_MeshComponent,mat1, msh1);
	//cameraNode->AddComponent(camComp);
	meshNode->AddComponent(mshComp);
	cout << "Game::OnStart()" << endl;
	return true;
}
bool Game::OnStop() {

	
	delete sceneNode;
	delete cameraNode;
	delete meshNode;
	
	cout << "Game::OnStop()" << endl;
	return false;
}
bool Game::OnUpdate() {
	i++;
	//movX
	
	cam->Update();
	if (inp->IsKeyPressed(87))
		cam->Walk(0.3);
	if (inp->IsKeyPressed(83))
		cam->Walk(-0.3);
	if (inp->IsKeyPressed(65))
		cam->Strafe(0.3);
	if (inp->IsKeyPressed(68))
		cam->Strafe(-0.3);
	if (inp->IsKeyPressed(265))
		cam->Pitch(0.3);
	if (inp->IsKeyPressed(264))
		cam->Pitch(-0.3);
	if (inp->IsKeyPressed(263))
		cam->yaw(0.3);
	if (inp->IsKeyPressed(262))
		cam->yaw(-0.3);
	
	
	
	//msh1->Rotate(0.0f, 0.003f, 0.0f);
	//movY
	
	
	CollisionManager::Instance()->CollisionBoxDetector();
	//cout << "Game::OnUpdate(): " << i << endl;
	
	return true;
}

void Game::OnDraw()
{
		
	msh1->DrawMesh(0);	
	//cout << "Game::OnDraw(): " << i << endl;
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