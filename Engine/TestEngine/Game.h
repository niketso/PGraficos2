#include "../EngineDLL/Gamebase.h"
#include "../EngineDLL/Triangle.h"
#include "../EngineDLL/Rectangle.h"
#include "../EngineDLL/Circle.h"
#include "../EngineDLL/Material.h"
#include "../EngineDLL/Importer.h"
#include <iostream>
class Game : public Gamebase {
private:
	int i;
	Triangle * tr1 ;
	Rectangle *rec1;
	Circle   *cir1;
	Material * mat1;
public:
	Game();
	~Game();
protected:
	bool OnStart() override;
	bool OnStop() override;
	bool OnUpdate() override;
	void OnDraw() override;
};
