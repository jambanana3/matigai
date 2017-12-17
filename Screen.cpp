#include "Screen.h"
#include "DxLib.h"



Screen::Screen( int hundll, int x, int y, int scr_width, int scr_height, int x_size, int speed ):
_hundll( hundll ),
_x( x ),
_y( y ),
_scr_width( scr_width ),
_scr_height( scr_height ),
_x_size( x_size ),
_speed( speed ) {
	_time = 0;
	_y_add = 0;
}

Screen::~Screen( ) {
	std::list<TouchPoint*>::iterator ite = _touch_point_list.begin( );
	int length = _touch_point_list.max_size( );
	for( int i = 0; i < length; i++ ) {
		delete (*ite);
		ite++;
	}
}

bool Screen::touch( Mouse* mouse, bool botan ){
	if( botan ) {
		std::list<TouchPoint*>::iterator ite = _touch_point_list.begin( );
		int length = _touch_point_list.max_size( );
		for( int i = 0; i < length; i++ ) {
			if( (*ite)->touch( mouse->_x + _time, mouse->_y, botan ) ) {
				_touch_point_list.remove( *ite );
				delete ( *ite );
				return true;
			}
			ite++;
		}
	}
	return false;
}

void Screen::draw( ){
	if( _time > _x_size ) {
		_time = 0;
	}
	if( _time < _x_size - _scr_width ) {
		DrawRectGraph( _x,    _y, _time, _y_add, _scr_width   , _scr_height, _hundll, true, false );
	} else {
		DrawRectGraph( _x                  , _y, _time, _y_add,    _x_size - _time             , _scr_height, _hundll, true, false );
		DrawRectGraph( _x + _x_size - _time, _y,     0, _y_add,( _time + _scr_width - _x_size ), _scr_height, _hundll, true, false );
	}
}
void Screen::update( ){

	_time += _speed;
	if( _time > _x_size ) {
		_time = 0;
	}
}