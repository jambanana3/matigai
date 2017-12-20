#pragma once
#include "GameObj.h"
#include <list>

#include "TouchPoint.h"
#include "ScreenItem.h"

class Screen : public GameObj {
public:
	Screen( int hundll, int x, int y, int scr_width, int scr_height, int x_end, int speed = 1 );//グラフィックハンドル、かいしｘ、かいしｙ、スクリーンサイズｘ、ｙ、画像ｘさいず、speed。
	virtual ~Screen( );
public:
	void update( );

	void draw( );
	void drawAll( );
	void drawAndItem( );

	bool touch( Mouse* mouse, bool botan );
	bool touchScreen( Mouse* mouse, bool botan );

	void addTouchPoint( TouchPoint* touchPtr, int pos_x, int pos_y );
	void addScreenItem( ScreenItem* item, int x, int y );
private:
	int _hundll;
	int _peke_g;
	std::list< TouchPoint* > _touch_point_list;
	std::list< ScreenItem* > _items;
	int _x;
	int _y;
	int _scr_width;
	int _scr_height;
	int _x_size;
	int _y_add;

	int _speed;
	int _time;
};


