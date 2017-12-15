#include "Mouse.h"



Mouse::Mouse( ){
	_b_right = false;
	_b_left = false;
}


Mouse::~Mouse( ){
}

void Mouse::update( ) {
	GetMousePoint(&_x, &_y);

	if ( right_stay( ) ) {
		_r_time++;
		_b_right = true;
	} else if( !right_out() ) {
		_r_time = 0;
		_b_right = false;
	}

	if (left_stay()) {
		_l_time++;
		_b_left = true;
	} else if (!right_out()) {
		_l_time = 0;
		_b_left = false;
	}


}

bool Mouse::right_in( ) {
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT)&& !_b_right ) {
		return true;
	}
	return false;
}
bool Mouse::right_stay() {
	if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
		return true;
	}
	return false;
}
bool Mouse::right_out() {
	if (!(GetMouseInput() & MOUSE_INPUT_RIGHT) && _b_right ) {
		return true;
	}
	return false;
}

bool Mouse::left_in() {
	if ( (GetMouseInput() & MOUSE_INPUT_LEFT) && !_b_right) {
		return true;
	}
	return false;
};
bool Mouse::left_stay() {
	if ( GetMouseInput() & MOUSE_INPUT_LEFT ) {
		return true;
	}
	return false;
}
bool Mouse::left_out() {
	if (!(GetMouseInput() & MOUSE_INPUT_LEFT) && _b_right) {
		return true;
	}
	return false;
}

int Mouse::getTime( ) {
	return 0;
}

