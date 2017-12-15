#include "TouchPoint.h"
#include <math.h>



TouchPoint::TouchPoint(int x_size, int y_size) :
_x_size( x_size ),_y_size( y_size ){
	_if_box = true;
}
TouchPoint::TouchPoint(int r) :
_r_size( r ) {
	_if_box = false;
}

TouchPoint::~TouchPoint( ) {

}

void TouchPoint::update( ) {

}

void TouchPoint::draw( ) {
	if (_if_box) {
		DrawBox(_x, _y, _x + _x_size, _y + _y_size, GetColor(222, 222, 222), false);
	} else {
		DrawCircle(_x, _y, _r_size, GetColor(222, 222, 222), false, true);
	}
}

void TouchPoint::setPos( int x, int y ){ 
	_x = x;
	_y = y;
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
			if ( sqrt( (mousePtr->_x - _x)*(mousePtr->_x - _x)+(mousePtr->_y - _y)*(mousePtr->_y - _y) ) < _r_size ) {
				return true;
			}
		}
	}
	return false;
}

