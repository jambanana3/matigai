#include "TouchPoint.h"
#include <math.h>



TouchPoint::TouchPoint(int x_size, int y_size) :
_x_size( x_size ),_y_size( y_size ){
	_if_box = true;
	initThis();
}
TouchPoint::TouchPoint(int r) :
_r_size( r ) {
	_if_box = false;
	initThis();
}

TouchPoint::~TouchPoint( ) {

}
void TouchPoint::initThis( ) {
	_score = 0;
	_if_score = 0;
}

void TouchPoint::update( ) {

}

void TouchPoint::draw( ) {
	if (_if_box) {
		DrawBox(_x, _y, _x + _x_size, _y + _y_size, GetColor(250, 100, 100), false);
	} else {
		DrawCircle(_x, _y, _r_size, GetColor(250, 100, 100), false, true);
	}
}
void TouchPoint::drawDiff(int x, int y) {
	if (_if_box) {
		DrawBox(_x + x, _y + y, _x + _x_size, _y + _y_size, GetColor(250, 100, 100), false);
	} else {
		DrawCircle(_x + x, _y + y, _r_size, GetColor(250,100, 100), false, true);
	}
}

void TouchPoint::setPos( int x, int y ) { 
	_x = x;
	_y = y;
}
void TouchPoint::setScore( int score ) {
	_score = score;
}


bool TouchPoint::touch( Mouse* mousePtr, bool klic ) {
	if( _if_box ) {
		if ( klic ) {
			if (_x < mousePtr->_x && mousePtr->_x < _x + _x_size && _y < mousePtr->_y && mousePtr->_y < _y + _y_size) {
				return true;
			}
		}
	} else {
		if ( klic ) {
			if ( ( (mousePtr->_x - _x)*(mousePtr->_x - _x)+(mousePtr->_y - _y)*(mousePtr->_y - _y) ) < _r_size * _r_size ) {
				return true;
			}
		}
	}
	return false;
}
bool TouchPoint::touch( int x, int y, bool klic ) {
	if( _if_box ) {
		if ( klic ) {
			if (_x < x && x < _x + _x_size && _y < y && y < _y + _y_size) {
				return true;
			}
		}
	} else {
		if ( klic ) {
			if (  ( x - _x ) * ( x - _x ) + ( y - _y ) * ( y - _y ) < _r_size * _r_size) {
				return true;
			}
		}
	}
	return false;
}

