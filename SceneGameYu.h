#pragma once
#include "Scene.h"
class SceneGameYu : public Scene
{
public:
	SceneGameYu();
	virtual ~SceneGameYu();

public:
	void run( );
	void drawItem(int x, int y, int g_h);
};

