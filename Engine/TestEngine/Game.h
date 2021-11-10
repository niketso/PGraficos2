#include "../EngineDLL/Gamebase.h"
#include "../EngineDLL/Material.h"
#include "../EngineDLL/Importer.h"
#include "../EngineDLL/CollisionManager.h"
#include "../EngineDLL/Input.h"
#include "../EngineDLL/Node.h"
//#include"../EngineDLL/Camera.h"
#include"../EngineDLL/MeshComponent.h"
#include"../EngineDLL/MeshLoader.h"
#include <iostream>
#include <vector>
class Game : public GameBase {
private:
	int i;
	float speed;
	Input *inp;	
	Node *sceneNode;
	Node *cameraNode;
	Node *MeshNode;
	Node * node;
	Node * node1;
	Node * node2;
	Node * node3;
	Node * node4;
	Node * node5;
	Camera *camera;

	
	
	

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
