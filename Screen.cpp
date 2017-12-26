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
	_peke_g = LoadGraph( "gazou/64peke.png" );
}

Screen::~Screen( ) {
	std::list<TouchPoint*>::iterator ite = _touch_point_list.begin( );
	int length = (int)_touch_point_list.size( );
	for( int i = 0; i < length; i++ ) {
		delete (*ite);
		ite++;
	}

	std::list<ScreenItem*>::iterator ite2 = _items.begin();
	int length2 = (int)_items.size( );
	for (int i = 0; i < length2; i++) {
		delete (*ite2);
		ite2++;
	}
	DeleteGraph( _peke_g );
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
/*
void Screen::drawAll() {
	int SCR_G = MakeScreen( _scr_width, _scr_height );
	SetDrawScreen( SCR_G );//-----------//

	if (_time < _x_size - _scr_width) {
		DrawRectGraph( 0, 0, _time, _y_add, _scr_width, _scr_height, _hundll, true, false);
	}
	else {
		DrawRectGraph(                   0,     0, _time, _y_add,                _x_size - _time, _scr_height, _hundll, true, false);
		DrawRectGraph( 0 + _x_size - _time,     0,     0, _y_add, (_time + _scr_width - _x_size), _scr_height, _hundll, true, false);
	}

	std::list<TouchPoint*>::iterator ite = _touch_point_list.begin();
	int length = _touch_point_list.size();
	for (int i = 0; i < length; i++) {
		(*ite)->drawDiff( -_time, 0 );
		(*ite)->drawDiff( -_time + _x_size, 0);
		(*ite)->drawDiff( -_time - _x_size, 0);
		ite++;
	}

	SetDrawScreen( DX_SCREEN_BACK );

	DrawGraph( _x, _y, SCR_G, true );
	DeleteGraph(SCR_G);
}*/
void Screen::drawAll() {
	int SCR_G = MakeScreen(_x_size, _scr_height);
	SetDrawScreen(SCR_G);//-----------//

	DrawRectGraph(0, 0, 0, _y_add, _x_size, _scr_height, _hundll, true, false);

	std::list<TouchPoint*>::iterator ite = _touch_point_list.begin();
	int length = _touch_point_list.size( );
	for (int i = 0; i < length; i++) {
		(*ite)->draw( );
		ite++;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	if (_time < _x_size - _scr_width) {
		DrawRectGraph(_x, _y, _time, _y_add, _scr_width, _scr_height, SCR_G, true, false);
	}
	else {
		DrawRectGraph(_x, _y, _time, _y_add, _x_size - _time, _scr_height, SCR_G, true, false);
		DrawRectGraph(_x + _x_size - _time, _y, 0, _y_add, (_time + _scr_width - _x_size), _scr_height, SCR_G, true, false);
	}
	DeleteGraph(SCR_G);
}
void Screen::drawAndItem() {
	int SCR_G = MakeScreen(_x_size, _scr_height);
	SetDrawScreen(SCR_G);//-----------//

	DrawRectGraph(0, 0, 0, _y_add, _x_size, _scr_height, _hundll, true, false);

	std::list<ScreenItem*>::iterator ite = _items.begin();
	int length = _items.size( );//  <-----
	for (int i = 0; i < length; i++) {
		(*ite)->draw();//ここ怪しい
		ite++;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	if (_time < _x_size - _scr_width) {
		DrawRectGraph(_x, _y, _time, _y_add, _scr_width, _scr_height, SCR_G, true, false);
	}
	else {
		DrawRectGraph(_x, _y, _time, _y_add, _x_size - _time, _scr_height, SCR_G, true, false);
		DrawRectGraph(_x + _x_size - _time, _y, 0, _y_add, (_time + _scr_width - _x_size), _scr_height, SCR_G, true, false);
	}
	DeleteGraph(SCR_G);
}

void Screen::update( ){

	_time += _speed;
	if( _time > _x_size ) {
		_time = 0;
	}
}

bool Screen::touch( Mouse* mouse, bool botan ) {
	int i_x;
	int i_y;
	if( botan && touchScreen( mouse, botan ) ) {
		std::list<TouchPoint*>::iterator ite = _touch_point_list.begin( );
		int length = _touch_point_list.size( );
		for( int i = 0; i < length; i++ ) {
			if( (*ite)->touch( mouse->_x + _time           - _x , mouse->_y - _y, botan ) ||
				(*ite)->touch( mouse->_x + _time + _x_size - _x , mouse->_y - _y, botan ) ||
				(*ite)->touch( mouse->_x + _time - _x_size - _x , mouse->_y - _y, botan ) ) {
				(*ite)->getPos( &i_x,  &i_y);
				addScreenItem( new ScreenItem( _peke_g, 64, 64 ), i_x, i_y );
				i_x += 1000;
				i_y += 1000;
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
	_RPT0( _CRT_WARN, "タッチＰ追加。\n" );
}
void Screen::addScreenItem(ScreenItem* item, int x, int y ) {
	item->setPos(x, y);
	_items.push_back(item);
}
