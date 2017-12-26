#pragma once
#include "Scene.h"
class SceneGameMo2 : public Scene {
public:
	SceneGameMo2( );
	virtual ~SceneGameMo2( );
public:
	void run( );
private:
	void drawItem(int x, int y, int g_h);
};

