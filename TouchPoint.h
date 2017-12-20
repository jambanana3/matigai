#pragma once
#include "GameObj.h"
#include "Mouse.h"

class TouchPoint : public GameObj {
public:
	TouchPoint( int x_size, int y_size );
	TouchPoint( int r_size );
	virtual ~TouchPoint();
public:
	void update( );
	void draw( );
	void drawDiff(int x, int y);
public:
	bool touch( Mouse* mouse, bool klic );
	bool touch( int x, int y, bool klic );
	void setPos(int x, int y);
	void setScore( int Score );

private:
	void initThis( );
private:
	int _x;
	int _y;
	int _x_size;
	int _y_size;
	int _r_size;

	bool _if_box;
	bool _if_score;

	int _score;
};

