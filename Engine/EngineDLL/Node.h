#pragma once
#include "Exports.h"
#include "Component.h"
#include <list>

using namespace std;
class  ENGINEDLL_API Node
{
private:
public:
	list<Node> * childList;
	list<Component> * componentList;
	Node();
	~Node();
	bool start();
	void AddComponent();
	void RemoveComponent();
	void AddChild();
	void RemoveChild();
	bool Update();
	void Draw();
};

