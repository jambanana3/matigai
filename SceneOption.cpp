#include "SceneOption.h"



SceneOption::SceneOption( ) {
	setNext( nullptr );
}


SceneOption::~SceneOption( ) {
}


//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//

void SceneOption::run( ) {

	while (true) {//  ---------　これメインループ　－－－－・・


		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}

}