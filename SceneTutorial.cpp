#include "SceneTutorial.h"



SceneTutorial::SceneTutorial( ) {
	setNext( nullptr );
}


SceneTutorial::~SceneTutorial( ) {
}

//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//
\
void SceneTutorial::run( ) {

	while (true) {//  ---------　これメインループ　－－－－・・


		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}
}