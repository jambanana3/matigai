#pragma once
#include "DXLfancs.h"
#include "DataScore.h"

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
	void Scene::setScore( );
protected:
	void setNext(Scene* scenePtr);
	void initThis( );

private:
	Scene* _next;
	DataScore* _score;

};

