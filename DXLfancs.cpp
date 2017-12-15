#include "DXLfancs.h"


bool FrameEnd() {
	ScreenFlip();
	ClearDrawScreen();
	if (ProcessMessage() != 0) {
		return true;
	}
	return false;
}