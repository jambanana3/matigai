#pragma once
#include "GameObj.h"
#include "Mouse.h"
#include "DataScore.h"

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
	void getPos(int* x, int *y);
	void setScore( DataScore* score_data,int score );

	bool ifBox( );
	bool ifScore( );

private:
	void initThis( );
	void touchAction( );
private:
	int _x;
	int _y;
	int _x_size;
	int _y_size;
	int _r_size;

	bool _if_box;
	bool _if_score;

	DataScore* _score_data;
	int _score;
};

