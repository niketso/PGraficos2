#include "Game.h"
Game::Game()
{
	i = 0;	
}
Game::~Game()
{
}
bool Game::OnStart() {
	mat1 = new Material();
	unsigned int programID = mat1->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	tr1 = new Triangle(render);
	tr1->SetMaterial(mat1);
	
	rec1 = new Rectangle(render);
	rec1->SetMaterial(mat1);
	cir1 = new Circle(render,1,20);
	cir1->SetMaterial(mat1);

	tr1->SetPos(6, 0, 0);
	rec1->SetPos(3, 0, 0);
	cir1->SetPos(0, 0, 0);

	cout << "Game::OnStart()" << endl;
	return true;
}
bool Game::OnStop() {

	delete mat1;
	delete tr1;
	delete rec1;
	delete cir1;

	cout << "Game::OnStop()" << endl;
	return false;
}
bool Game::OnUpdate() {
	i++;
	tr1->SetRot(0.0f, 0.0f, i/5 );
	cout << "Game::OnUpdate(): " << i << endl;
	
	return true;
}

void Game::OnDraw()
{
	tr1->Draw();
	rec1->Draw();
	cir1->Draw();
		
	cout << "Game::OnDraw(): " << i << endl;
}

