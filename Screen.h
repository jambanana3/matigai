#pragma once
#include "GameObj.h"
#include <list>

#include "TouchPoint.h"

class Screen : public GameObj {
public:
	Screen( );
	virtual ~Screen( );
public:
	void draw( );
	void update( );
private:
	int _hundll;
	std::list< TouchPoint* > _touch_point_list;

};


