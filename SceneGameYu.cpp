#include "SceneGameYu.h"



SceneGameYu::SceneGameYu(){
	setNext( nullptr );
}


SceneGameYu::~SceneGameYu()
{
}


void SceneGameYu::run( ) {

	while (true) {//  ---------　これメインループ　－－－－・・


		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}
}
