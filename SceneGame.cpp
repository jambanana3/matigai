#include "SceneGame.h"



SceneGame::SceneGame(){
	setNext( nullptr );
}


SceneGame::~SceneGame()
{
}

//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//


void SceneGame::run( ) {

	while (true) {//  ---------　これメインループ　－－－－・・




		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}

}