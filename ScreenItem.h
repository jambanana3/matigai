#pragma once
#include "GameObj.h"
class ScreenItem : public GameObj {
public:
	ScreenItem( int center_x, int center_y );
	virtual ~ScreenItem( );
public:
	void update( );
	void draw( );

private:
	int _x;
	int _y;
};

