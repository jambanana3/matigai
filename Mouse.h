#pragma once
#include "DxLib.h"

class Mouse {
public:
	Mouse();
	virtual ~Mouse();
public:
	void update();
public:
	bool right_in  ( );
	bool right_stay( );
	bool right_out ( );
					 
	bool left_in   ( );
	bool left_stay ( );
	bool left_out  ( );

	int getTime( );

	int _x;
	int _y;

private:
	bool _b_left;
	bool _b_right;

	int _r_time;
	int _l_time;

};

