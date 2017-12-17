#pragma once
#include "GameObj.h"
#include <list>

#include "TouchPoint.h"

class Screen : public GameObj {
public:
	Screen( int hundll, int x, int y, int scr_width, int scr_height, int x_end, int speed = 3 );
	virtual ~Screen( );
public:
	void draw( );
	void update( );
private:
	int _hundll;
	std::list< TouchPoint* > _touch_point_list;
	int _x;
	int _y;
	int _scr_width;
	int _scr_height;
	int _x_size;
	int _y_add;

	int _speed;
	int _time;
};


