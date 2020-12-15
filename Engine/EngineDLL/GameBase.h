#include "Exports.h"
#include "Renderer.h"
#include "Window.h"
#include "TypeDef.h"
#include "Node.h"

#include <iostream>
using namespace std;
class ENGINEDLL_API GameBase {
private:
	double currentFrame;
	double lastFrame;
	bool looping = false;
	bool hasScene = false;
	Node * SceneNode;
	
public:
	GameBase();
	~GameBase();
	bool Start();
	bool Stop();
	void Loop();
protected:
	Window* window;
	double deltaTime;
	Renderer * render;
	virtual bool OnStart() = 0;
	virtual bool OnStop() = 0;
	virtual bool OnUpdate() = 0;
	virtual void OnDraw() = 0;
	void SetScene(Node * _Scene);
};

