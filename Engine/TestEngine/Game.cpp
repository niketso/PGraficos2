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
	mat2 = new Material();
	unsigned int programID = mat1->LoadShaders("vertexshader.txt", "fragmentshader.txt");
	unsigned int programID2 = mat2->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	tr1 = new Triangle(render);
	tr1->SetMaterial(mat1);
	
	rec1 = new Rectangle(render);
	rec1->SetMaterial(mat2);
	cout << "Game::OnStart()" << endl;
	return true;
}
bool Game::OnStop() {
	cout << "Game::OnStop()" << endl;
	return false;
}
bool Game::OnUpdate() {
	i++;
	tr1->SetPos(3, 0, 0);
	rec1->SetPos(0, 0, 0);

	cout << "Game::OnUpdate(): " << i << endl;
	//if (i > 5)
	//return false;
	return true;
}

void Game::OnDraw()
{
	tr1->Draw();
	rec1->Draw();
		
	cout << "Game::OnDraw(): " << i << endl;
}

