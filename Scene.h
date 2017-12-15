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
	Scene( );
	virtual ~Scene( );
public:
	virtual void run( ) { return; };
	virtual NextScene getNext( ) { return _next; };
protected:
	void setNext( NextScene next ) { _next = next; };
private:
	NextScene _next;
};

