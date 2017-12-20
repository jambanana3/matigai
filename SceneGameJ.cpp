#include "SceneGameJ.h"



SceneGameJ::SceneGameJ( ) {
	setNext( nullptr );
}


SceneGameJ::~SceneGameJ( ) {
}


//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//

void SceneGameJ::run( ) {

	while (true) {//  ---------　これメインループ　－－－－・・




		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}
}


