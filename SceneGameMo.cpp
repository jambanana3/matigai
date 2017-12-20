#include "SceneGameMo.h"
#include "Mouse.h"
#include "Screen.h"
#include "TouchPoint.h"



SceneGameMo::SceneGameMo( ) {
	setNext( nullptr );
}


SceneGameMo::~SceneGameMo( ) {
}

//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//

void SceneGameMo::run() {

	Mouse* mousePtr( new Mouse( ) );

	int scr_g = LoadGraph( "Ahaikei.png" );
	//Screen* screenPtr( new Screen( scr_g,  ) );

	while (true) {//  ---------　これメインループ　－－－－・・






		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}

}
