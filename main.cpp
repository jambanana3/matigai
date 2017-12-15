#include "DxLib.h"
#include "Scene.h"
#include "SceneStart.h"

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int ) {
	ChangeWindowMode( true );
//	SetGraphMode();
	DxLib_Init();
	SetDrawScreen( DX_SCREEN_BACK );

	Scene* scene( new SceneStart() );
	do {
		scene->run( );

		if ( scene->getNext( ) == START ){ 
			delete scene;
			scene = (new SceneStart() );
		}

	} while (scene->getNext() != END);
	delete scene;

	DxLib_End();
}