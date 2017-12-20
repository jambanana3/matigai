#pragma once
#include "GameObj.h"
class ScreenItem : public GameObj {
public:
	ScreenItem( int hundll, int size_x, int size_y  );
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
	int _time;
	int _x_size;
	int _y_size;

	bool _visible;
};

