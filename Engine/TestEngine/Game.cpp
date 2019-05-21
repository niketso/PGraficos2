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
	//mat2 = new Material();
	unsigned int programID = mat1->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	//unsigned int programID2 = mat2->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");

	//unsigned int programID = mat1->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	cam = new  Camera(render);
	inp = new Input(this->window);
	//spr1 = new Sprite(render,8,4);	
	//spr2 = new Sprite(render, 1, 1);
	//msh2 = new Mesh(render, "Spider\\Spider.obj", "Spider\\SpiderText.bmp");

	msh1 = new Mesh(render,"M4A1\\M4A1.fbx","M4A1\\M4A1Tex.bmp");

	//tmp1 = new TileMap("Tile.csv",800, 600, render, mat1);
	///spr1->SetMaterial(mat1);
	//spr2->SetMaterial(mat1);
	
	msh1->SetMaterial(mat1);
	//msh2->SetMaterial(mat2);

		//spr1->LoadTexture("Doom.bmp");
		//spr2->LoadTexture("sample2.bmp");
	
	
	//spr1->SetAnimation(0, 23, 0.5f);
	
	
	//spr1->SetBoundingBox(spr1->GetPos(), 2.0f, 2.0f, false, false);
	//spr2->SetBoundingBox(spr1->GetPos(), 2.0f, 2.0f, false, false);
	
	//colManager->AddCollisionEntity(spr1 , player);
	//colManager->AddCollisionEntity(spr2, enemy);

	//spr1->SetPos(-5,0,0);
	//spr1->SetPos(5,0,0);
	msh1->SetPos(0, 0, 0);
	//msh2->SetPos(0, 0, 0);
	msh1->Rotate(180.0f,0.0f, 180.0f);
	
	cout << "Game::OnStart()" << endl;
	return true;
}
bool Game::OnStop() {

	//delete spr1;
	//delete spr2;
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

	//spr1->Translate(-0.5f * deltaTime ,0.0f,0.0f);
	//spr2->Translate(0.5f * deltaTime, 0.0f, 0.0f);
	//
	//msh1->Rotate(0.0f, 0.003f, 0.0f);
	//movY
	//spr1->Translate(0.0f,1.0f * deltaTime, 0.0f);
	//spr2->Translate(-4.0f * deltaTime, 0.0f,0.0f);
	//render->TranslateCamera(glm::vec3 (deltaTime*2.0f, 0.f, 0.f));
	//spr1->UpdateAnimation(deltaTime);
	//tmp1->Update();
	CollisionManager::Instance()->CollisionBoxDetector();
	//cout << "Game::OnUpdate(): " << i << endl;
	
	return true;
}

void Game::OnDraw()
{
	//tmp1->DrawTileMap();
	//spr1->Draw();
	//spr2->Draw();
	msh1->DrawMesh(0);
	//cout << "Game::OnDraw(): " << i << endl;
}

