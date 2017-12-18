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

bool Screen::touch( Mouse* mouse, bool botan ){
	if( botan && touchScreen( mouse, botan ) ) {
		std::list<TouchPoint*>::iterator ite = _touch_point_list.begin( );
		int length = _touch_point_list.size( );
		for( int i = 0; i < length; i++ ) {
			if( (*ite)->touch( mouse->_x + _time           - _x , mouse->_y - _y, botan ) ||
				(*ite)->touch( mouse->_x + _time + _x_size - _x , mouse->_y - _y, botan ) ||
				(*ite)->touch( mouse->_x + _time - _x_size - _x , mouse->_y - _y, botan ) ) {
				delete ( *ite );
				_touch_point_list.remove( *ite );
				return true;
			}
			ite++;
		}
	}
	return false;
}
bool Screen::touchScreen( Mouse* mouse, bool botan ) {
	if( mouse->_x < _x || _x + _scr_width < mouse->_x || mouse->_y < _y || _y + _scr_height < mouse->_y ) {
		return false;
	}
	return true;
}
void Screen::addTouchPoint( TouchPoint* touchPtr, int pos_x, int pos_y ) {
	touchPtr->setPos( pos_x, pos_y );
	_touch_point_list.push_back( touchPtr );
	_RPT0( _CRT_WARN, "タッチＰ追加。" );
}
