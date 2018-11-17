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
	//unsigned int programID = mat1->LoadShaders("vert.glsl", "frag.glsl");
	/*tr1 = new Triangle(render);
	tr1->SetMaterial(mat1);*/
	
	/*rec1 = new Rectangle(render);
	rec1->SetMaterial(mat1);*/

	/*cir1 = new Circle(render,1,20);
	cir1->SetMaterial(mat1);*/

	spr1 = new Sprite(render);	
	spr2 = new Sprite(render);
	spr1->SetMaterial(mat1);
	spr2->SetMaterial(mat1);
	spr1->LoadTexture("sample2.bmp");
	spr2->LoadTexture("sample2.bmp");
	
	spr1->SetBoundingBox(spr1->GetPos(), 2.0f, 2.0f, false, false);
	spr1->GetBoundingBox();
	spr2->SetBoundingBox( spr2->GetPos(), 2.0f, 2.0f, false, false);
	spr2->GetBoundingBox();
	colManager->AddCollisionEntity(spr1 , player);
	colManager->AddCollisionEntity(spr2 , enemy);

	spr1->Translate(-5, 0, 0);
	spr2->Translate(5, 0, 0);

	
	
	//tr1->SetPos(6, 0, 0);
	//rec1->SetPos(3, 0, 0);
	//cir1->SetPos(0, 0, 0);
	

	cout << "Game::OnStart()" << endl;
	return true;
}
bool Game::OnStop() {

	//delete mat1;
	//delete tr1;
	//delete rec1;
	//delete cir1;
	delete spr1;

	cout << "Game::OnStop()" << endl;
	return false;
}
bool Game::OnUpdate() {
	i++;
	//tr1->SetRot(0.0f, 0.0f, i/5 );
	spr1->Translate(4.0f * deltaTime, 0.0f, 0.0f);
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

