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
	speed = 100.0f;
	camera = new Camera(_CameraComponent,render);
	sceneNode = new Node(render);
	cameraNode = new Node(render);
	MeshNode = new Node(render);
	
	cameraNode->AddComponent(camera);
	sceneNode->AddChild(cameraNode);
	sceneNode->AddChild(MeshNode);
	
	MeshLoader::GetInstance()->LoadMesh("PG2.fbx", "rifle_texture.bmp", render, MeshNode, camera);

	 node = MeshNode->GetChild(0);
	 node1 = node->GetChild(0);
	 node2 = node->GetChild(1);
	 node3 = node->GetChild(2);
	 node4 = node2->GetChild(0);
	 node5 = node4->GetChild(0);
	 camera->Walk(-500.0f);
	 camera->Strafe(500.0f);
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
	
	if (inp->IsKeyPressed(74)) //j
		node->GetTransfrom()->Translate(speed * deltaTime,0.0f,0.0f);
		
	if (inp->IsKeyPressed(76)) //l
		node->GetTransfrom()->Translate(-speed * deltaTime, 0.0f, 0.0f);		
	if (inp->IsKeyPressed(73)) //i
		//node->GetTransfrom()->Translate(0.0f,0.0f,speed * deltaTime);
		node->GetTransfrom()->SetScale(50.0f, 50.0f, 50.0f);
	if (inp->IsKeyPressed(75)) //k
		//node->GetTransfrom()->Translate(0.0f, 0.0f, -speed * deltaTime);
		node->GetTransfrom()->SetScale(100.0f, 100.0f, 100.0f);

	//node2

	if (inp->IsKeyPressed(84))//t
		node2->GetTransfrom()->SetScale(0.5f, 0.5f, 0.5f);
	if (inp->IsKeyPressed(71))//g
		node2->GetTransfrom()->SetScale(1.0f, 1.0f, 1.0f);
	if (inp->IsKeyPressed(70))//f
		node2->GetTransfrom()->Translate(speed * deltaTime, 0.0f, 0.0f);
	if (inp->IsKeyPressed(72))//h
		node2->GetTransfrom()->Translate(-speed * deltaTime, 0.0f, 0.0f);
	//node4
	if (inp->IsKeyPressed(86))//v
		node4->GetTransfrom()->Translate(speed * deltaTime, 0.0f, 0.0f);
	if (inp->IsKeyPressed(66))//b
		node4->GetTransfrom()->Translate(-speed * deltaTime, 0.0f, 0.0f);
	if (inp->IsKeyPressed(78))//n
		node4->GetTransfrom()->SetScale(0.5f, 0.5f, 0.5f);
	if (inp->IsKeyPressed(77))//m
		node4->GetTransfrom()->SetScale(1.0f, 1.0f, 1.0f);
	//node5
	if (inp->IsKeyPressed(90))//z
		node5->GetTransfrom()->SetScale(0.5f, 0.5f, 0.5f);
	if (inp->IsKeyPressed(88))//x
		node5->GetTransfrom()->SetScale(1.0f, 1.0f, 1.0f);
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

