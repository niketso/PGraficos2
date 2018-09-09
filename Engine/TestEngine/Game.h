#include "../EngineDLL/Gamebase.h"
#include "../EngineDLL/Triangle.h"
#include <iostream>
class Game : public Gamebase {
	int i;
public:
	Game();
	~Game();
protected:
	bool OnStart() override;
	bool OnStop() override;
	bool OnUpdate() override;
};
