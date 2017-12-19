#include "ScreenItem.h"
#include "DxLib.h"


ScreenItem::ScreenItem( int hundll, int center_x, int center_y ):
_x( center_x ),
_y( center_y ),
_hundll( hundll ) {
	_visible = true;
}

ScreenItem::~ScreenItem( ) {
}

void ScreenItem::update( ) {

}
void ScreenItem::draw( ) {
	if ( _visible ) {
		
	}
}
void ScreenItem::setPos(int x, int y) {
	_x = x;
	_y = y;
}
void ScreenItem::setVisible(bool visible) {
	_visible = visible;
};


