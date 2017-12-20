#include "ScreenItem.h"
#include "DxLib.h"


ScreenItem::ScreenItem( int hundll, int x_size, int y_size ):
_x_size( x_size ),
_y_size( y_size ),
_hundll( hundll ) {
	_visible = true;
}

ScreenItem::~ScreenItem( ) {
}

void ScreenItem::update( ) {

}
void ScreenItem::draw( ) {
	if ( _visible ) {
		DrawRectGraph( _x - ( _x_size / 2 ),_y - (_y_size / 2 ),0,0,_x_size,_y_size,_hundll, true, false );
	}
}
void ScreenItem::setPos(int x, int y) {
	_x = x;
	_y = y;
}
void ScreenItem::setVisible(bool visible) {
	_visible = visible;
};


