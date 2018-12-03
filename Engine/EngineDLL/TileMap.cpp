#include "TileMap.h"


TileMap::TileMap(const char * file, int wdwW, int wdwH , Renderer * render, Material *material) 
{
	LoadTileMap(file);

	
	scrollX = 0;
	scrollY = 0;

	levelH = 0;
	levelW = 0;


	this->render = render;
	this->material = material;

	Instance = CollisionManager::Instance();
	LastCameraPos = CurrentCameraPos = DeltaCameraPos = glm::vec3(0, 0, 0);
	int tileW = 64;
	int tileH = 64;

	viewW = (wdwW / tileW) + 4;
	viewH = (wdwH / tileH) + 4;

	levelX	= viewH;
	levelY = viewW;

	viewMatrix = new vector<vector<int>*>(viewW);
	for (int i = 0; i < viewW; i++)
		viewMatrix->at(i) = new vector<int>(viewH);

	tileMatrix = new vector<vector<Tile*>*>(viewW);
	for (int i = 0; i < viewW; i++)
		tileMatrix->at(i) = new vector<Tile*>(viewH);

	ChargeTile();
	LoadTiles();		
}

TileMap::~TileMap()
{

}

void TileMap::LoadTileMap(const char * file)
{
	string buffer;
	ifstream tileFile(file);
	levelW = 1;
	levelH = 1;

	getline(tileFile, buffer);
	//el tipo de archivo .csv contiene -1 comas y 0.El for saltea la coma. 
	for (int i = 0; i < buffer.length(); i++) {
		if (buffer[i] == ',')
			levelW++;
	}
	while (getline(tileFile, buffer)) {
		levelH++;
	}
		
	tileFile.clear();
	//Esta linea hace que el archivo vuelva al principio
	tileFile.seekg(0, std::ios::beg);

	levelMatrix = new vector<vector<int>*>(levelW);

	for (int i = 0; i < levelW; i++) {
		levelMatrix->at(i) = new vector<int>(levelH);
	}

	if (tileFile.is_open()) {
		for (int i = 0; i < levelW; i++) {

			getline(tileFile, buffer);
			int levelW = 0;

			for (int j = 0; j < buffer.length(); j++) {
				
				switch (buffer[j]) {
				case '0':
					levelMatrix->at(i)->at(levelW) = 1;
					levelW++;
					break;

				case '1':
					levelMatrix->at(i)->at(levelW) = 0;
					levelW++;
					break;
				}
			}
		}
	}
	tileFile.close();
}


void TileMap::DrawTileMap()
{
	for (int w = 0; w < viewW; w++)
	{
		for (int h = 0; h < viewH; h++)
		{
			tileMatrix->at(w)->at(h)->Draw();
		}
	}
}

void TileMap::ChargeTile() 
{
	for (int w = 0; w < viewW; w++)
	{
		for (int h = 0; h < viewH; h++)
		{
			//set de datos.
			tileMatrix->at(w)->at(h) = new Tile(render, 1, 1);
			tileMatrix->at(w)->at(h)->SetMaterial(material);
			tileMatrix->at(w)->at(h)->SetBoundingBox(glm::vec3(0, 0, 0), 2.0f, 2.0f, false, false);
			tileMatrix->at(w)->at(h)->AddTexture("Doom.bmp");
			tileMatrix->at(w)->at(h)->AddTexture("sample2.bmp");
			
		}
	}
}

void TileMap::UpdateTileMap()
{
	int posx;
	int posy = 9;

	//Update X
	for (int i = 0; i < viewW; i++) {
		for (int j = 1; j < viewH; j++) {
			viewMatrix->at(i)->at(j - 1) = viewMatrix->at(i)->at(j);
		}
	}
	for (int i = 0; i < viewW; i++) {
		int pos = levelMatrix->at(i)->at(levelX);
		viewMatrix->at(i)->at(viewH - 1) = pos;
	}
	//volver a dibujar
	posx = 12;
	for (int j = 0; j < viewW; j++) {
		if (viewMatrix->at(j)->at(viewH - 1) == 0) {
			tileMatrix->at(j)->at(lastPosX)->ChangeTexture(0);
			Instance->AddCollisionEntity(tileMatrix->at(j)->at(lastPosX), map);
			
		}
		if (viewMatrix->at(j)->at(viewH - 1) == 1) {
			tileMatrix->at(j)->at(lastPosX)->ChangeTexture(1);
			Instance->AddCollisionEntity(tileMatrix->at(j)->at(lastPosX), collisionTile);
			
		}
		tileMatrix->at(j)->at(lastPosX)->SetPos(posx + render->GetCameraPos().x, posy, 0);
		posy -= 2;
	}
	if (lastPosX < viewH - 1) lastPosX++;
	else lastPosX = 0;
}

void TileMap::LoadTiles() {
	//posiciones iniciales de donde se va empezar a dibujar.
	
	int posx = -10;
	int posy = 9;

	lastPosX = 0;
	lastPosY = 0;

	for (int w = 0; w < viewW; w++) {
		posx = -12;
		for (int h = 0; h < viewH; h++) {										
				viewMatrix->at(w)->at(h) = levelMatrix->at(w)->at(h);
				//Dependiendo del dato que nos llega se determina si es fondo o mapa.
				if (viewMatrix->at(w)->at(h) == 0) {
					tileMatrix->at(w)->at(h)->ChangeTexture(0);
					Instance->AddCollisionEntity(tileMatrix->at(w)->at(h), map);
				}
				if (viewMatrix->at(w)->at(h) == 1) {
					tileMatrix->at(w)->at(h)->ChangeTexture(1);
					Instance->AddCollisionEntity(tileMatrix->at(w)->at(h),collisionTile);
				}			
				posx += 2;
				tileMatrix->at(w)->at(h)->SetPos(posx, posy ,0);
		}
		posy -= 2;
	}
}

void TileMap::Update() 
{
	CurrentCameraPos = render->GetCameraPos();
	DeltaCameraPos = CurrentCameraPos - LastCameraPos;
	LastCameraPos = CurrentCameraPos;
	//UpdateX
	scrollX += DeltaCameraPos.x;
	if (scrollX >= 2) {
		if (levelX < levelW - 1)levelX++;
		UpdateTileMap();
		scrollX = 0;
	}
	else
		if (scrollX <= -2) {
			if (levelX < 0)levelX--;
			UpdateTileMap();
			scrollX = 0;
		}
	//UpdateY
	/*scrollY += DeltaCameraPos.y;
	if (scrollY <= -2) {
		if (Ylvl < 0)Ylvl--;
		UpdateViewY();
		scrollY = 0;
	}
	else
		if (scrollY >= 2) {
			if (Ylvl > lvlH - 1)Ylvl++;
			UpdateViewY();
			scrollY = 0;
		}*/
}



