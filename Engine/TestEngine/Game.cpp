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
	
	mat1 = new Material();
	unsigned int programID = mat1->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");	

	spr1 = new Sprite(render,8,4);	
	spr2 = new Sprite(render,1,1);
	spr1->SetMaterial(mat1);
	spr2->SetMaterial(mat1);
	spr1->LoadTexture("Doom.bmp");
	spr2->LoadTexture("sample2.bmp");
	
	spr1->SetAnimation(0, 23, 0.5f);
	
	
	spr1->SetBoundingBox(spr1->GetPos(), 2.0f, 2.0f, false, false);
	spr2->SetBoundingBox(spr2->GetPos(), 2.0f, 2.0f, true, false);
	colManager->AddCollisionEntity(spr1 , player);
	colManager->AddCollisionEntity(spr2 , enemy);

	spr1->SetPos(-5, 0, 0);
	spr2->SetPos(5,0, 0);

	
	
	

	cout << "Game::OnStart()" << endl;
	return true;
}
bool Game::OnStop() {

	
	delete spr1;

	cout << "Game::OnStop()" << endl;
	return false;
}
bool Game::OnUpdate() {
	i++;
	spr1->Translate(4.0f * deltaTime, 0.0f,0.0f);
	//spr2->Translate(-4.0f * deltaTime, 0.0f,0.0f);
	spr1->UpdateAnimation(deltaTime);
	CollisionManager::Instance()->CollisionBoxDetector();
	//cout << "Game::OnUpdate(): " << i << endl;
	
	return true;
}

void Game::OnDraw()
{
	//tr1->Draw();
	//rec1->Draw();
	//cir1->Draw();
	spr1->Draw();
	spr2->Draw();
		
	//cout << "Game::OnDraw(): " << i << endl;
}

