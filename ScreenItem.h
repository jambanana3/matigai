#pragma once
#include "GameObj.h"
class ScreenItem : public GameObj {
public:
	ScreenItem( int hundll, int center_x, int center_y );
	virtual ~ScreenItem( );
public:
	void update( );
	void draw( );

	void setPos(int x, int y);
	void setVisible( bool visible );
private:
	int _x;
	int _y;
	int _hundll;
	bool _visible;
};

