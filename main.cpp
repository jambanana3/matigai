#include "DxLib.h"
#include "Scene.h"
#include "SceneStart.h"
#include "SceneTest.h"

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int ) {
	ChangeWindowMode( true );
//	SetGraphMode();
	DxLib_Init();
	SetDrawScreen( DX_SCREEN_BACK );

	Scene* scene( new SceneTest() );
	do {

		scene->run( );
		Scene* next = scene->getNext( );
		delete scene;
		scene = next;

	} while (scene != nullptr );

	delete scene;



	DxLib_End();

}