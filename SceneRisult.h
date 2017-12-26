#pragma once
#include "Scene.h"
class SceneRisult : public Scene {
public:
	SceneRisult( DataScore* scorePtr );
	virtual ~SceneRisult( );
public:
	void run( );
private:
	DataScore* _scorePtr;
};

