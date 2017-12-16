#pragma once
#include "DXLfancs.h"

enum NextScene {
	END,
	START,
	GAME,
	OPTION,
	RESULT,
	STAGE_SELECT
};

class Scene {
public:
	Scene();
	virtual ~Scene();
public:
	virtual void run();
	Scene* getNext( );
protected:
	void setNext(Scene* scenePtr);
private:
	Scene* _next;
};

