#include "../EngineDLL/Gamebase.h"
#include "../EngineDLL/Material.h"
#include "../EngineDLL/Importer.h"
#include "../EngineDLL/CollisionManager.h"
#include "../EngineDLL/Input.h"
#include "../EngineDLL/Node.h"
#include"../EngineDLL/Camera.h"
#include"../EngineDLL/CameraComponent.h"
#include"../EngineDLL/MeshComponent.h"
#include <iostream>
class Game : public Gamebase {
private:
	int i;

	Input *inp;	
	Material * mat1;
	Mesh *msh1;
	Node *sceneNode;
	Node *cameraNode;
	Node *meshNode;
	Camera *cam;
	CameraComponent *camComp;
	MeshComponent *mshComp;
	

	//TileMap *tmp1;
	
public:
	Game();
	~Game();
protected:
	bool OnStart() override;
	bool OnStop() override;
	bool OnUpdate() override;
	void OnDraw() override;
};
