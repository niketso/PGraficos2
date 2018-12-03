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
	
	tmp1 = new TileMap("Tile.csv",800, 600, render, mat1);
	spr1->SetMaterial(mat1);
		spr1->LoadTexture("Doom.bmp");
	
	
	spr1->SetAnimation(0, 23, 0.5f);
	
	
	spr1->SetBoundingBox(spr1->GetPos(), 2.0f, 2.0f, false, false);
	
	colManager->AddCollisionEntity(spr1 , player);
	

	spr1->SetPos(-5,-5.0f, 0);
	
	
	
	

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
	//movX
	//spr1->Translate(2.0f * deltaTime ,0.0f,0.0f);
	//movY
	spr1->Translate(0.0f,1.0f * deltaTime, 0.0f);
	//spr2->Translate(-4.0f * deltaTime, 0.0f,0.0f);
	render->TranslateCamera(glm::vec3 (deltaTime*0.1f, 0.f, 0.f));
	spr1->UpdateAnimation(deltaTime);
	tmp1->Update();
	CollisionManager::Instance()->CollisionBoxDetector();
	//cout << "Game::OnUpdate(): " << i << endl;
	
	return true;
}

void Game::OnDraw()
{
	tmp1->DrawTileMap();
	spr1->Draw();
		
		
	//cout << "Game::OnDraw(): " << i << endl;
}

